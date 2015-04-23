// gDebug im Release aussschalten
#ifdef QT_NO_DEBUG
#define QT_NO_DEBUG_OUTPUT
#endif

#include "VisualGraph.h"
#include "Global.h"
#include "WaitCursor.h"

#include <string>
#include <sstream>

#include <QtCore/QtDebug>
#include <QtCore/QFileInfo>
#include <QtGui/QKeyEvent>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>

VisualGraph* g_mainWindow;

VisualGraph::VisualGraph(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	QString path = QCoreApplication::applicationDirPath();
	QIcon icon(path + "/" +  "VisualGraph.png");
	setWindowIcon(icon);

	ui.setupUi(this);

	setWindowTitle(g_applicationName);

	AddAction("Create Graph",
		"Creates graph.",
		Qt::CTRL + Qt::Key_C,
		SLOT(OnCreateGraph()));

	AddAction("Open File",
		"Open an existing file.",
		Qt::CTRL + Qt::Key_O,
		SLOT(OnOpenFile()));

	AddSeparator();

	AddAction("Zoom Into",
		"Increasing the graph presentation.",
		Qt::CTRL + Qt::Key_Plus,
		SLOT(OnZoomInto()));

	AddAction("Zoom Out",
		"Decreasing the graph presentation.",
		Qt::CTRL + Qt::Key_Minus,
		SLOT(OnZoomOut()));

	AddAction("Zoom to Fit",
		"Show the whole graph.",
		Qt::CTRL + Qt::Key_0,
		SLOT(OnZoomToFit()));

	AddAction("1:1",
		"Zoom to original size.",
		Qt::CTRL + Qt::Key_9,
		SLOT(OnZoomToOrignalSize()));

	AddSeparator();

	AddAction("Execute Layout",
		"Execute Layout.",
		Qt::CTRL + Qt::Key_E,
		SLOT(OnExecuteLayout()));
}

VisualGraph::~VisualGraph()
{
}

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
		ui.m_graphWidget->CreateGraph();
		setWindowTitle(g_applicationName);
	});
}

void VisualGraph::OnZoomInto()
{
	RunGuiAction(this, [&]
	{
		ui.m_graphWidget->Zoom(true);
	});
}

void VisualGraph::OnZoomOut()
{
	RunGuiAction(this, [&]
	{
		ui.m_graphWidget->Zoom(false);
	});
}

void VisualGraph::OnZoomToFit()
{
	RunGuiAction(this, [&]
	{
		ui.m_graphWidget->ZoomToFit();
	});
}

void VisualGraph::OnZoomToOrignalSize()
{
	RunGuiAction(this, [&]
	{
		ui.m_graphWidget->ZoomToOrignalSize();
	});
}


void VisualGraph::OnExecuteLayout()
{
	RunGuiAction(this, [&]
	{
		ui.m_graphWidget->ExecuteLayout();
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
    bool success = ui.m_graphWidget->OpenFile(filepath);

    std::stringstream ss;
    if (success) ss << g_applicationName << " - " << filepath;
    else ss << g_applicationName;

    setWindowTitle(ss.str().c_str());
}

void VisualGraph::AddAction(const char* text, const char* toolTip, const QKeySequence& key, const char* method)
{
	auto action = ui.toolBar->addAction(text);
	action->setToolTip(QString("%1 (%2)").arg(toolTip).arg(key.toString()));
	action->setShortcut(key);
	connect(action, SIGNAL(triggered()), this, method);
}

void VisualGraph::AddSeparator()
{
	ui.toolBar->addSeparator();
}

