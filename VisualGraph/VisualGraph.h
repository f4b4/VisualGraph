#ifndef VISUALGRAPH_H
#define VISUALGRAPH_H

#include "Global.h"

#include "ui_VisualGraph.h"

#include "WaitCursor.h"

#include <memory>
#include <functional>

#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>

class VisualGraph : public QMainWindow
{
	Q_OBJECT

public:
	VisualGraph(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VisualGraph();

	void LoadFile(const std::string& filepath);
	void CreateGraph() { ui.m_graphWidget->CreateGraph(); }

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
	void AddAction(const char* text, const char* toolTip, const QKeySequence &key, const char* method);
	void AddSeparator();

private:
	Ui::VisualGraphClass ui;
};


#endif // VISUALGRAPH_H
