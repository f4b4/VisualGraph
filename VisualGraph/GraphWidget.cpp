// undefines the macros min and max which are specified in the windows headers
#define NOMINMAX

// qDebug disabled in release build
#ifdef QT_NO_DEBUG
#define QT_NO_DEBUG_OUTPUT
#endif

#include "GraphWidget.h"

#include "Global.h"

#include <QtCore/QtDebug>
#include <QtCore/QFile>
#include <QtCore/QEvent>
#include <QtGui/QApplication>
#include <QtGui/QMessageBox>

#include <limits>
#include <algorithm>
#include <cmath>

#include <oggl/Util.h>
#include <oggl/Math.h>
#include <oggl/GraphCreator.h>
#include <ogdf/energybased/FMMMLayout.h>
#include <ogdf/basic/graph_generators.h>
#include <ogdf/layered/DfsAcyclicSubgraph.h>

const int g_scrollbarWidth = 16;
const int g_scrollbarMinimum = 0;
const int g_scrollbarMaximum = 100000;

const int g_sliderMinimum = 0;
const int g_sliderMaximum = 1600;
const int g_sliderSingleStep = 10;
const int g_sliderPageStep = 100;

const float g_defaultNodeWidth = 10;
const float g_defaultEdgeLength = 40;

// scale-slider:
// slider:     0 - 1600
// scale:  1/256 -  256
float ZoomSliderToScale(int value) { return std::pow(2.f, (value - 800) / 100.f); }
int ScaleToZoomSlider(float scale) { return std::log(scale)/std::log(2.f) * 100 + 800; }

GraphWidget::GraphWidget(QWidget* parent)
	: QWidget(parent)
	, m_eventsEnabled(true)
	, m_mouseMoveStarted(false)
{
	m_graphPainter = std::make_shared<oggl::GraphPainter>();
	m_canvas = std::make_shared<GraphCanvas>(this, m_graphPainter);
	m_zoomSlider = new QSlider(Qt::Horizontal, this);
	m_zoomSlider->setTickPosition(QSlider::TicksBelow);
	m_zoomSlider->setMinimum(g_sliderMinimum);
	m_zoomSlider->setMaximum(g_sliderMaximum);
	m_zoomSlider->setTickInterval(g_sliderPageStep);
	m_zoomSlider->setPageStep(g_sliderPageStep);
	m_zoomSlider->setSingleStep(g_sliderSingleStep);
	m_zoomSlider->setValue(ScaleToZoomSlider(1.f));

	m_hScroll = new QScrollBar(Qt::Horizontal, this);
	m_hScroll->setMinimum(g_scrollbarMinimum);
	m_hScroll->setMaximum(g_scrollbarMaximum);

	m_vScroll = new QScrollBar(Qt::Vertical, this);
	m_vScroll->setMinimum(g_scrollbarMinimum);
	m_vScroll->setMaximum(g_scrollbarMaximum);

	QObject::connect(m_zoomSlider, SIGNAL(valueChanged(int)), this, SLOT(OnZoomSliderValueChanged(int)));
	QObject::connect(m_hScroll, SIGNAL(valueChanged(int)), this, SLOT(OnHScrollValueChanged(int)));
	QObject::connect(m_vScroll, SIGNAL(valueChanged(int)), this, SLOT(OnVScrollValueChanged(int)));
}

GraphWidget::~GraphWidget()
{
	delete m_vScroll;
	delete m_hScroll;
	delete m_zoomSlider;
}

void GraphWidget::Zoom(bool zoomInto)
{
	int oldVal = ScaleToZoomSlider(m_graphPainter->Scale());
	int newVal = oldVal + (zoomInto ? g_sliderSingleStep : -g_sliderSingleStep);
	newVal = std::max(g_sliderMinimum, newVal);
	newVal = std::min(g_sliderMaximum, newVal);

	Scale(ZoomSliderToScale(newVal));
}

void GraphWidget::ZoomToFit()
{
	m_graphPainter->ZoomToFit();

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::ZoomToOrignalSize()
{
	m_graphPainter->ZoomToOrignalSize();

	SetScrollValues();
	m_canvas->update();
}


void GraphWidget::OnZoomSliderValueChanged(int value)
{
#ifdef _DEBUG
	oggl::dout << "GraphWidget::OnZoomSliderValueChanged" << "value=" << value << std::endl;
#endif

	if (!m_eventsEnabled) return;

	RunGuiAction(this, [&]
	{
		Scale(ZoomSliderToScale(value));
	});
}

void GraphWidget::OnHScrollValueChanged(int value)
{
#ifdef _DEBUG
	oggl::dout << "GraphWidget::OnHScrollValueChanged" << "value=" << value << std::endl;
#endif

	if (!m_eventsEnabled) return;

	RunGuiAction(this, [&]
	{
		auto scrollableWorld = m_graphPainter->ScrollableWorld();
		float viewValue = oggl::LinearProjection(value, 
			g_scrollbarMinimum, g_scrollbarMaximum, scrollableWorld.Left(), scrollableWorld.Right());

		// adjust x offset
		oggl::Rect view = m_graphPainter->View();
		float width = view.Width();
		view[0] = viewValue;
		view[2] = viewValue + width;
		m_graphPainter->View(view);

		SetScrollValues();
		m_canvas->update();
	});
}

void GraphWidget::OnVScrollValueChanged(int value)
{
#ifdef _DEBUG
	oggl::dout << "GraphWidget::OnVScrollValueChanged" << "value=" << value << std::endl;
#endif

	if (!m_eventsEnabled) return;

	RunGuiAction(this, [&]
	{
		auto scrollableWorld = m_graphPainter->ScrollableWorld();
		float viewValue = oggl::LinearProjection(value, 
			g_scrollbarMinimum, g_scrollbarMaximum, scrollableWorld.Top(), scrollableWorld.Bottom());

		// adjust y offset
		oggl::Rect view = m_graphPainter->View();
		float height = view.Height();
		view[1] = viewValue;
		view[3] = viewValue + height;
		m_graphPainter->View(view);

		SetScrollValues();
		m_canvas->update();
	});
}

void GraphWidget::Translate(float dx, float dy)
{
	auto view = m_graphPainter->View();

	view[0] += dx;
	view[1] += dy;
	view[2] += dx;
	view[3] += dy;

	m_graphPainter->View(view);

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::Scale(float scale)
{
	m_graphPainter->Scale(scale);

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::showEvent(QShowEvent* event)
{
}

void GraphWidget::closeEvent(QCloseEvent* event)
{
}

void GraphWidget::resizeEvent(QResizeEvent* event)
{
	m_zoomSlider->move(0, height() - m_zoomSlider->height());
	m_zoomSlider->resize(width(), m_zoomSlider->height());

	m_hScroll->move(0, height() - g_scrollbarWidth - m_zoomSlider->height());
	m_hScroll->resize(width() - g_scrollbarWidth, g_scrollbarWidth);

	m_vScroll->move(width() - g_scrollbarWidth, 0);
	m_vScroll->resize(g_scrollbarWidth, height() - g_scrollbarWidth - m_zoomSlider->height());

	m_canvas->move(0, 0);
	m_canvas->resize(width() - g_scrollbarWidth, height() - g_scrollbarWidth - m_zoomSlider->height());

	SetScrollValues();
}

void GraphWidget::SetScrollValues()
{
#ifdef _DEBUG
	oggl::dout << "GraphWidget::SetScrollValues" << std::endl;
#endif
	
	EventDisabler eventDisabler(this);

	auto scrollableWorld = m_graphPainter->ScrollableWorld();
	auto view = m_graphPainter->View();

	int hPageStep = oggl::LinearProjection(view.Width() + scrollableWorld.Left(), 
		scrollableWorld.Left(), scrollableWorld.Right(), g_scrollbarMinimum, g_scrollbarMaximum);
	int hSingleStep = std::max(hPageStep/10, 1);
	int hPos = oggl::LinearProjection(view.Left(), 
		scrollableWorld.Left(), scrollableWorld.Right(), g_scrollbarMinimum, g_scrollbarMaximum);
	int hMaximum = g_scrollbarMaximum - hPageStep;
	bool hEnabled = scrollableWorld.Width() > view.Width();

	if (hEnabled)
	{
		m_hScroll->setEnabled(true);
		m_hScroll->setMaximum(hMaximum);
		m_hScroll->setPageStep(hPageStep);
		m_hScroll->setSingleStep(hSingleStep);
		m_hScroll->setValue(hPos);
	}
	else
	{
		m_hScroll->setEnabled(false);
		m_hScroll->setMaximum(0);
		m_hScroll->setPageStep(0);
		m_hScroll->setSingleStep(0);
		m_hScroll->setValue(0);
	}

	int vPageStep = oggl::LinearProjection(view.Height() + scrollableWorld.Top(), 
		scrollableWorld.Top(), scrollableWorld.Bottom(), g_scrollbarMinimum, g_scrollbarMaximum);
	int vSingleStep = std::max(vPageStep/10, 1);
	int vPos = oggl::LinearProjection(view.Top(), 
		scrollableWorld.Top(), scrollableWorld.Bottom(), g_scrollbarMinimum, g_scrollbarMaximum);
	int vMaximum = g_scrollbarMaximum - vPageStep;
	bool vEnabled = scrollableWorld.Height() > view.Height();

	if (vEnabled)
	{
		m_vScroll->setEnabled(true);
		m_vScroll->setMaximum(vMaximum);
		m_vScroll->setPageStep(vPageStep);
		m_vScroll->setSingleStep(vSingleStep);
		m_vScroll->setValue(vPos);
	}
	else
	{
		m_vScroll->setEnabled(false);
		m_vScroll->setMaximum(0);
		m_vScroll->setPageStep(0);
		m_vScroll->setSingleStep(0);
		m_vScroll->setValue(0);
	}


	m_zoomSlider->setValue(ScaleToZoomSlider(m_graphPainter->Scale()));
}

void GraphWidget::OpenFile(const std::string& filepath)
{
	QFile file(filepath.c_str());
	if (!file.exists()) throw std::runtime_error("File does not exist.");

	auto graph = std::make_shared<ogdf::Graph>();
	auto graphAttributes = std::make_shared<ogdf::GraphAttributes>(*graph.get());

	graphAttributes->initAttributes(0x2FFFF);

	bool ret = graphAttributes->readGML(*graph.get(), filepath.c_str());
	if (!ret) ret = graphAttributes->readRudy(*graph.get(), filepath.c_str());
	if (!ret) ret = graphAttributes->readXML(*graph.get(), filepath.c_str());

	m_graph = graph;
	m_graphAttributes = graphAttributes;

	m_graphPainter->SetGraphAttributes(m_graphAttributes);
	m_graphPainter->ZoomToFit();

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::ExecuteLayout()
{
	auto& graphAttributes = m_graphAttributes;
	if (!graphAttributes) throw std::runtime_error("No graph is loaded.");

	ogdf::FMMMLayout fmmm;



	fmmm.useHighLevelOptions(true);
	fmmm.unitEdgeLength(g_defaultEdgeLength); 
	fmmm.newInitialPlacement(true);
	fmmm.qualityVersusSpeed(ogdf::FMMMLayout::qvsNiceAndIncredibleSpeed);

	fmmm.call(*graphAttributes.get());

#ifdef _DEBUG
	oggl::dout << "numberOfNodes=" << graphAttributes->constGraph().numberOfNodes() << 
		"," << "numberOfEdges=" << graphAttributes->constGraph().numberOfEdges() << std::endl;
	oggl::dout << "bounds=" << graphAttributes->boundingBox().width() << "," << 
		graphAttributes->boundingBox().height() << std::endl;
#endif

	m_graphPainter->SetGraphAttributes(graphAttributes);
	m_graphPainter->ZoomToFit();

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::CreateGraph()
{
	auto graph = std::make_shared<ogdf::Graph>();
	auto graphAttributes = std::make_shared<ogdf::GraphAttributes>(*graph.get());

	int cols = 32;
	int rows = cols;
	oggl::CreateGrid(*graph.get(), *graphAttributes.get(), cols, rows);

	m_graph = graph;
	m_graphAttributes = graphAttributes;

	m_graphPainter->SetGraphAttributes(m_graphAttributes);
	m_graphPainter->ZoomToFit();

	SetScrollValues();
	m_canvas->update();
}

void GraphWidget::wheelEvent(QWheelEvent* event)
{
	bool handled = false;

	if (Qt::Vertical == event->orientation())
	{
#ifdef _DEBUG
		oggl::dout << "GraphWidget::wheelEvent: " << "QWheelEvent::delta=" << event->delta() << std::endl;
#endif

		QPoint ptCanvas = m_canvas->mapFromGlobal(event->globalPos());
		QRect rCanvas = m_canvas->rect();

		if (rCanvas.contains(ptCanvas))
		{
			RunGuiAction(this, [&]
			{
				int numDegrees = event->delta() / 8;
				int numSteps = numDegrees / 15;
				int oldVal = ScaleToZoomSlider(m_graphPainter->Scale());
				int newVal = oldVal + g_sliderSingleStep * numSteps;
				newVal = std::max(g_sliderMinimum, newVal);
				newVal = std::min(g_sliderMaximum, newVal);

				float scale = ZoomSliderToScale(newVal);

				m_graphPainter->Scale(scale, oggl::V2(ptCanvas.x(), ptCanvas.y()));

				SetScrollValues();
				m_canvas->update();

				handled = true;
			});
		}
	}

	if (!handled) event->ignore();
}

void GraphWidget::mousePressEvent(QMouseEvent* event)
{
	bool handled = false;

	if (Qt::LeftButton == event->button() && 
		Qt::LeftButton == event->buttons() &&
		m_canvas->rect().contains(m_canvas->mapFromGlobal(event->globalPos())))
	{
#ifdef _DEBUG
		oggl::dout << "GraphWidget::mousePressEvent: " << 
			"QMouseEvent::button=" << event->button() << ", " <<
			"QMouseEvent::buttons=" << event->buttons() << std::endl;
#endif

		RunGuiAction(this, [&]
		{
			m_mouseMoveStarted = true;
			m_mouseStart[0] = event->x();
			m_mouseStart[1] = event->y();

			handled = true;
		});
	}

	if (!handled) event->ignore();
}

void GraphWidget::mouseMoveEvent(QMouseEvent* event)
{
	bool handled = false;

	if (m_mouseMoveStarted && 
		Qt::LeftButton == event->buttons())
	{
		RunGuiAction(this, [&]
		{
			QPoint pos = event->pos();

			float scale = m_graphPainter->Scale();
			auto view = m_graphPainter->View();

			int idx = m_mouseStart[0] - pos.x();
			int idy = m_mouseStart[1] - pos.y();

			float dx = idx/scale;
			float dy = idy/scale;

			m_mouseStart[0] = event->x();
			m_mouseStart[1] = event->y();

			Translate(dx, dy);

			handled = true;

#ifdef _DEBUG
			oggl::dout << "GraphWidget::mouseMoveEvent: " <<
				"QMouseEvent::buttons=" << event->buttons() << ", " <<
				"event->globalPos=" << event->globalPos().x() << ", " << event->globalPos().y() << ", " <<
				"Translate=" << idx << ", " << idy << std::endl;
#endif
		});
	}

	if (!handled) event->ignore();
}

void GraphWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (m_mouseMoveStarted)
		m_mouseMoveStarted = false;
	event->ignore();
}
