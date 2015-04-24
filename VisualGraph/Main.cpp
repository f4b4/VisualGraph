#include "VisualGraph.h"

#include <stdexcept>
#include <QMessageBox>
#include <QtWidgets/QApplication>

#ifdef _WIN32

#include <crtdbg.h>

class MemDiff
{
	_CrtMemState m_memState;

public:
	MemDiff()
	{
		_CrtMemCheckpoint(&m_memState);
	}

	~MemDiff()
	{
		_CrtMemState newMemState, diffMemState;
		_CrtMemCheckpoint(&newMemState);
		_CrtMemDifference(&diffMemState, &m_memState, &newMemState); 
		_CrtMemDumpStatistics(&diffMemState);
	}
};
#endif // _WIN32

int main(int argc, char *argv[])
{
#ifdef _WIN32
	MemDiff memDiff;
	{
#endif

	QApplication a(argc, argv);
	a.setStyle("Cleanlooks");
	VisualGraph w;
	g_mainWindow = &w;

	try
	{
		w.show();
		if (argc > 1)
			w.LoadFile(argv[1]);
		else
			w.OnCreateGraph();

		return a.exec();
	}
	catch (std::exception &e)
	{
		QMessageBox::critical(nullptr, g_applicationName, e.what());
	}


#ifdef _WIN32
	}
#endif
}

#ifdef _WIN32

#include <Windows.h>

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	return main(__argc, __argv);
}

#endif // _WIN32
