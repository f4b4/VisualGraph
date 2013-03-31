#pragma once
#include "qwidget.h"
#include "GraphCanvas.h"

#include <memory>

#include <QtGui/qwidget.h>
#include <QtGui/qscrollbar.h>
#include <QtGui/QSlider>

#include <oggl/GraphPainter.h>

class GraphWidget : public QWidget
{
	Q_OBJECT

public:
	GraphWidget(QWidget* parent);
	~GraphWidget();

	void Zoom(bool zoomInto);
	void ZoomToFit();
	void ZoomToOrignalSize();


	void OpenFile(const std::string& filepath);
	void ExecuteLayout();

	void CreateGraph();

	void Scale(float scale);
	void Translate(float dx, float dy);

public slots:
	void OnZoomSliderValueChanged(int value);
	void OnHScrollValueChanged(int value);
	void OnVScrollValueChanged(int value);

protected:
	virtual void showEvent(QShowEvent* event);
	virtual void closeEvent(QCloseEvent* event);
	virtual void resizeEvent(QResizeEvent* event);
	virtual void wheelEvent(QWheelEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);

private:
	void SetScrollValues();

private:
	std::shared_ptr<oggl::GraphPainter> m_graphPainter;

	std::shared_ptr<ogdf::GraphAttributes> m_graphAttributes;
	std::shared_ptr<ogdf::Graph> m_graph;

	std::shared_ptr<GraphCanvas> m_canvas;
	QSlider* m_zoomSlider;
	QScrollBar* m_hScroll;
	QScrollBar* m_vScroll;

	bool m_mouseMoveStarted;
	oggl::V2 m_mouseStart;

	bool m_eventsEnabled;

	class EventDisabler
	{
		GraphWidget* m_graphWidget;
		bool m_oldEventsEnabled;

	public:
		EventDisabler(GraphWidget* graphWidget)
			: m_graphWidget(graphWidget)
		{
			m_oldEventsEnabled = m_graphWidget->m_eventsEnabled;
			m_graphWidget->m_eventsEnabled = false;
		}

		~EventDisabler()
		{
			m_graphWidget->m_eventsEnabled = m_oldEventsEnabled;
		}

	private:
		EventDisabler(const EventDisabler&);
	};
};

