// Main.cpp
#ifdef _WIN32
#define WINDOWS_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif // _WIN32

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <string>
#include <sstream>
#include <memory>

#include <oggl/GraphPainter.h>
#include <oggl/Util.h>

#define WINDOW_WIDTH    1200
#define WINDOW_HEIGHT   1000

int g_window;
oggl::GraphPainter g_graphPainter;

void OnDisplay();
void OnReshape(int width, int height);
void OnKeyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
	try
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
		glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

		g_window = glutCreateWindow("glut_app");

		glutDisplayFunc(OnDisplay);
		glutKeyboardFunc(OnKeyboard);
		glutReshapeFunc(OnReshape);

		g_graphPainter.Initialize();
		g_graphPainter.Resize(WINDOW_WIDTH, WINDOW_HEIGHT);

		auto g = std::make_shared<ogdf::Graph>();
		auto graphAttributes = std::make_shared<ogdf::GraphAttributes>(*g.get());
		graphAttributes->initAttributes(0x2FFFF);
		if (argc > 1)
		{
			graphAttributes->readGML(*g.get(), argv[1]);

			oggl::Dump(graphAttributes);

			std::stringstream ss;
			ss << argv[1] << ".svg";
			graphAttributes->writeSVG(ss.str().c_str());
			g_graphPainter.SetGraphAttributes(graphAttributes);
		}

		glutMainLoop();
		return 0;
	}
	catch (std::exception& ex)
	{
		std::cerr << ex.what();
		return 1;
	}
}

#ifdef _WIN32

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	return main(__argc, __argv);
}

#endif // _WIN32

void OnDisplay()
{
    glClear (GL_COLOR_BUFFER_BIT);

    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  

	g_graphPainter.Paint();

	glFlush();
    glutSwapBuffers();
}

void OnReshape(int width, int height)
{
	g_graphPainter.Resize(width, height);
	g_graphPainter.ZoomToFit();
	OnDisplay();
}

void OnKeyboard(unsigned char key, int x, int y)
{
    glutDestroyWindow(g_window);
    exit (0);
}
