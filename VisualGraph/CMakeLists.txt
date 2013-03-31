#
# VisualGraph/VisualGraph/CMakeLists.txt
#

# Set up QT4 and required components
find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
include(${QT_USE_FILE})

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
#list
qt4_wrap_ui(GENERATED_SOURCES ${UIS})
qt4_add_resources(GENERATED_SOURCES ${RESOURCES})
qt4_wrap_cpp(GENERATED_SOURCES ${MOCS})

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
	# source files that are actually built direclty
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
	${QT_LIBRARIES} 
)

if(WIN32)
	target_link_libraries(
		VisualGraph 
		# Debug version for Debug builds in Visual Studio
		debug ${OGDF_DEBUG_LIBRARY}
		# Release version for all other builds in Visual Studio
		optimized ${OGDF_RELEASE_LIBRARY}
		# OGDF needs Psapi.lib
		Psapi
	)
else ()
	target_link_libraries(
		VisualGraph 
		${OGDF_LIBRARY}
	)
endif()