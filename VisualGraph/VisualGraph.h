#ifndef VISUALGRAPH_H
#define VISUALGRAPH_H

#include "Global.h"

//#include "ui_VisualGraph.h"

#include "WaitCursor.h"

#include <memory>
#include <functional>

#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>

class QVBoxLayout;
class GraphWidget;
class QToolBar;

class VisualGraph : public QMainWindow
{
	Q_OBJECT

public:
	VisualGraph(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VisualGraph();

	void LoadFile(const std::string& filepath);
	void CreateGraph();

protected:
	virtual void keyPressEvent(QKeyEvent * event);

public slots:
	void OnCreateGraph();

private slots:
	void OnOpenFile();

	void OnZoomInto();
	void OnZoomOut();
	void OnZoomToFit();
	void OnZoomToOrignalSize();

	void OnExecuteLayout();

private:
	void OpenFile(const std::string& filepath);
    void AddAction(const char* text, const char* icon, const char* toolTip, const QKeySequence &key, const char* method);
	void AddSeparator();

private:
//	Ui::VisualGraphClass ui;

	QWidget* m_centralWidget;
	QVBoxLayout* m_layout;
	QToolBar* m_toolBar;
	GraphWidget* m_graphWidget;

};


#endif // VISUALGRAPH_H
