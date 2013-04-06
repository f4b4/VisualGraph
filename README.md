VisualGraph
================================================================================

Welcome to VisualGraph, a viewer for the Open Graph Drawing Framework (OGDF).

![Visual Graph Screenshot](VisualGraph.png)

Modules
--------------------------------------------------------------------------------

### VisualGraph

Viewer for Linux and Windows using the QT-Library.

### oggl

Library for displaying very big OGDF graphs with OpenGL, it does render 
1,000,000 nodes smoothly.

### oggl-test

Test project for oggl.

### glut_app

Lightweight graph viewer using GLUT.


Prerequisites
--------------------------------------------------------------------------------

* OGDF
* QT4
* OpenGL 3.3
* cmake 2.6 or higher

Linux

* gcc 4.7 or higher

Windows

* Visual Studio 2010 or higher

Build
--------------------------------------------------------------------------------

VisualGraph uses cmake as meta build system, cmake generates on Linux a 
Makefile and on Windows a Visual Studio solution. 

OGDF and VisualGraph directories should be in the same parent directory, so that
cmake can find the OGDF include directoy and the library automatically.

Build on Linux:

	$ cd <VisualGraph root directory>
	$ mkdir build
	$ cd build
	$ cmake ..
	$ make

Build on Windows:

	> cd <VisualGraph root directory>
	> mkdir build
	> cd build
	> cmake ..

	The solution VisualGraph.sln should now be in the build directory.

If the OGDF library is not found by cmake, issue the following commandline with 
the full paths to your OGDF:

On Linux:

	$ cmake -DOGDF_INCLUDE_DIR:PATH=<full path to OGDF include director> \
		-DOGDF_LIBRARY:FILEPATH=<full path to OGDF library> ..

On Windows:

	> cmake -DOGDF_INCLUDE_DIR:PATH=<full path to OGDF include director> \
		-DOGDF_DEBUG_LIBRARY:FILEPATH=<full path to OGDF DEBUG library> \
		-DOGDF_RELEASE_LIBRARY:FILEPATH=<full path to OGDF RELEASE library> \
		..

LICENSE
--------------------------------------------------------------------------------

The GL Load library in the directory VisualGraph/oggl/glload is distributed 
under the MIT License.

The other parts of the software are distributed under the terms of the 
[GPLv3](<http://www.gnu.org/licenses/gpl-3.0.html>), in addition all special 
exceptions of the OGDF are allowed, see 
OGDF License <http://www.ogdf.net/doku.php/tech:license>. By using this 
software you agree to these license terms.

COPYRIGHT
--------------------------------------------------------------------------------

All files in the VisualGraph distribution are copyrighted.

All files with the exception of the GL Load library:

Copyright (C) 2013 The VisualGraph Authors


