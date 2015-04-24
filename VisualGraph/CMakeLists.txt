#
# VisualGraph/VisualGraph/CMakeLists.txt
#

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Set up QT5 and required components
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)

# OpenGL
find_package(OpenGL REQUIRED)

###
# All the project files
set(SOURCES
	Global.cpp
	Main.cpp
	VisualGraph.cpp
	GraphWidget.cpp
	GraphCanvas.cpp
 )

set(HEADERS
	Global.h
	WaitCursor.h
)

set(MOCS
	VisualGraph.h
	GraphWidget.h
	GraphCanvas.h
)

set(UIS 
	VisualGraph.ui
)

set(RESOURCES 
	VisualGraph.qrc
)

###
# Build and link the project

# Let QT pre-process the files and add the generated files to the source 
# list
qt5_wrap_ui(GENERATED_SOURCES ${UIS})

source_group("Generated Sources - Do Not Edit" FILES ${GENERATED_SOURCES})

# Make sure the compiler can find include files from our Hello library. 
include_directories (
	${VisualGraph_SOURCE_DIR}
	${VisualGraph_SOURCE_DIR}/oggl/glload/include
	${VisualGraph_SOURCE_DIR}/VisualGraph
	${VisualGraph_BINARY_DIR}/VisualGraph
	${OGDF_INCLUDE_DIR}
	${OPENGL_INCLUDE_DIR}
)

link_directories (
	"${VisualGraph_BINARY_DIR}"
)

add_executable (VisualGraph
	MACOSX_BUNDLE
	WIN32
	# source files that are actually built directly
	${SOURCES}
	${GENERATED_SOURCES}

	# items included so they show up in your IDE
	${HEADERS}
	${UIS}
	${MOCS}
	${RESOURCES}
)

target_link_libraries(
	VisualGraph 
	oggl
	${OPENGL_LIBRARIES}
	Qt5::Core
	Qt5::Widgets
	Qt5::Gui
	Qt5::OpenGL
)

if(WIN32)
	target_link_libraries(
		VisualGraph 
		# Debug version for Debug builds in Visual Studio
		debug ${OGDF_DEBUG_LIBRARY}
		# Release version for all other builds in Visual Studio
		optimized ${OGDF_RELEASE_LIBRARY}
		# OGDF needs Psapi.lib
		#Psapi
	)
else ()
	target_link_libraries(
		VisualGraph 
		${OGDF_LIBRARY}
	)
endif()