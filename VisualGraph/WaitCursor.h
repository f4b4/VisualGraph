#pragma once

#include "VisualGraph.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

class WaitCursor
{
	QWidget* m_mainWindow;
	QCursor m_oldCursor;

public:

	WaitCursor(QWidget* mainWindow)
		: m_mainWindow(mainWindow)
	{
		m_oldCursor = m_mainWindow->cursor();
		m_mainWindow->setCursor(Qt::WaitCursor);
		QApplication::processEvents();
	}

	~WaitCursor()
	{
		m_mainWindow->setCursor(m_oldCursor);
	}
};

