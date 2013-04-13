// gDebug im Release aussschalten
#ifdef QT_NO_DEBUG
#define QT_NO_DEBUG_OUTPUT
#endif

#include "VisualGraph.h"
#include "Global.h"
#include "WaitCursor.h"
#include "GraphWidget.h"

#include <string>
#include <sstream>

#include <QtCore/QtDebug>
#include <QtCore/QFileInfo>
#include <QtGui/QKeyEvent>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include <QtGui/QToolBar>
#include <QtGui/QBoxLayout>
#include <QAction>
#include <QToolButton>

VisualGraph* g_mainWindow;

VisualGraph::VisualGraph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	m_toolBar = new QToolBar(this);
	m_centralWidget = new QWidget(this);
	m_layout = new QVBoxLayout(m_centralWidget);
	m_graphWidget = new GraphWidget(m_centralWidget);

	addToolBar(Qt::TopToolBarArea, m_toolBar);
	m_toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	m_toolBar->setIconSize(QSize(16, 16));

	setGeometry(0, 0, 820, 940);

	setCentralWidget(m_centralWidget);

	m_layout->addWidget(m_graphWidget);

	setWindowIcon(QIcon(":/VisualGraph/Icons/graph_16x16.png"));

	//ui.setupUi(this);

	setWindowTitle(g_applicationName);


	AddAction("Create Graph",
		"Creates graph.",
		nullptr,
		Qt::CTRL + Qt::Key_C,
		SLOT(OnCreateGraph()));

	AddAction(nullptr,
		":/VisualGraph/Icons/open_16x16.png",
		"Open an existing file.",
		Qt::CTRL + Qt::Key_O,
		SLOT(OnOpenFile()));

	AddSeparator();

	AddAction(nullptr,
		":/VisualGraph/Icons/zoom-in_16x16.png",
		"Increasing the graph presentation.",
		Qt::CTRL + Qt::Key_Plus,
		SLOT(OnZoomInto()));

	AddAction(nullptr,
		":/VisualGraph/Icons/zoom-out_16x16.png",
		"Decreasing the graph presentation.",
		Qt::CTRL + Qt::Key_Minus,
		SLOT(OnZoomOut()));

	AddAction(nullptr,
		":/VisualGraph/Icons/zoom-to-fit_16x16.png",
		"Show the whole graph.",
		Qt::CTRL + Qt::Key_0,
		SLOT(OnZoomToFit()));

	AddAction(nullptr,
		":/VisualGraph/Icons/zoom-1to1_16x16.png",
		"Zoom to original size.",
		Qt::CTRL + Qt::Key_9,
		SLOT(OnZoomToOrignalSize()));

	AddSeparator();

	AddAction(nullptr,
		":/VisualGraph/Icons/execute_16x16.png",
		"Execute Layout.",
		Qt::CTRL + Qt::Key_E,
		SLOT(OnExecuteLayout()));
}

VisualGraph::~VisualGraph()
{
}

void VisualGraph::CreateGraph() { m_graphWidget->CreateGraph(); }

void VisualGraph::LoadFile(const std::string& filepath)
{
	RunGuiAction(this, [&]
	{
		this->OpenFile(filepath);
	});
}

void VisualGraph::OnOpenFile()
{
	RunGuiAction(this, [&]
	{
		 QString fileName = QFileDialog::getOpenFileName(
			 this,
			tr("Open Image"), 
			"..\\samples", 
			tr("Graph Files (*.gml *.g *.src)"));

		 if (!fileName.isEmpty())
			 this->OpenFile(fileName.toStdString());
	});
}

void VisualGraph::OnCreateGraph()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->CreateGraph();
		setWindowTitle(g_applicationName);
	});
}

void VisualGraph::OnZoomInto()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->Zoom(true);
	});
}

void VisualGraph::OnZoomOut()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->Zoom(false);
	});
}

void VisualGraph::OnZoomToFit()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->ZoomToFit();
	});
}

void VisualGraph::OnZoomToOrignalSize()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->ZoomToOrignalSize();
	});
}


void VisualGraph::OnExecuteLayout()
{
	RunGuiAction(this, [&]
	{
		m_graphWidget->ExecuteLayout();
	});
}

void VisualGraph::keyPressEvent(QKeyEvent* event)
{
	int key = event->key();
	Qt::KeyboardModifiers mod = event->modifiers();

	if (Qt::Key_Equal == key && Qt::ControlModifier == mod)
	{
		OnZoomInto();
		event->ignore();
	}
}

void VisualGraph::OpenFile(const std::string& filepath)
{
	bool success = m_graphWidget->OpenFile(filepath);

    std::stringstream ss;
    if (success) ss << g_applicationName << " - " << filepath;
    else ss << g_applicationName;

    setWindowTitle(ss.str().c_str());
}

void VisualGraph::AddAction(const char* text, const char* icon, const char* toolTip, const QKeySequence& key, const char* method)
{
	auto action = new QAction(m_toolBar);
	//m_toolBar->addAction(action);
	if (text) action->setText(text);
	if (icon) action->setIcon(QIcon(icon));
	action->setToolTip(QString("%1 (%2)").arg(toolTip).arg(key.toString()));
	action->setShortcut(key);
	connect(action, SIGNAL(triggered()), this, method);

	auto button = new QToolButton(m_toolBar);
	button->setDefaultAction(action);
	if (text && icon) button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	else if (text) button->setToolButtonStyle(Qt::ToolButtonTextOnly);
	else if (icon) button->setToolButtonStyle(Qt::ToolButtonIconOnly);

	m_toolBar->addWidget(button);
}

void VisualGraph::AddSeparator()
{
	m_toolBar->addSeparator();
}

