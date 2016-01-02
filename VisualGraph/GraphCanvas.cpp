#include "GraphCanvas.h"

GraphCanvas::GraphCanvas(QWidget* parent, const std::shared_ptr<oggl::GraphPainter>& graphPainter)
	: QOpenGLWidget(parent)
	, m_graphPainter(graphPainter)
{
}

void GraphCanvas::initializeGL()
{
	m_graphPainter->Initialize();
}

void GraphCanvas::resizeGL(int width, int height)
{
	m_graphPainter->Resize(width, height);
	m_graphPainter->ZoomToFit();
}

void GraphCanvas::paintGL()
{
	m_graphPainter->Paint();
}
