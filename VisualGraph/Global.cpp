// Global.cpp
#include "Global.h"

#include "WaitCursor.h"

#include <QtGui/QWidget>
#include <QtGui/QMessageBox>

const char g_applicationName[] = "Visual Graph";

void RunGuiAction(QWidget* widget, std::function<void()> func)
{
	static bool running = false;

	if (!running)
	{
		running = true;

		WaitCursor wait(g_mainWindow);

		try
		{
			func();
		}
        catch (std::exception& e)
		{
            QMessageBox::critical(widget, g_applicationName, e.what());
		}

		running = false;
	}
}
