#pragma once

// undefines the macros min and max which are specified in the windows headers
#define NOMINMAX

#include <QOpenGLWidget>
#include <QtGui/QWheelEvent>

#include <oggl/GraphPainter.h>

class GraphCanvas : public QOpenGLWidget
{
	Q_OBJECT

public:
	GraphCanvas(QWidget* parent, const std::shared_ptr<oggl::GraphPainter>& graphPainter);

protected:
	virtual void initializeGL();
	virtual void resizeGL(int width, int height);
	virtual void paintGL();

private:
	std::shared_ptr<oggl::GraphPainter> m_graphPainter;
};

