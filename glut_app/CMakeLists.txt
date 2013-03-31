#
# VisualGraph/glut_app/CMakeLists.txt
#

include_directories (
	${VisualGraph_SOURCE_DIR}
	${VisualGraph_SOURCE_DIR}/oggl/glload/include
	${OGDF_INCLUDE_DIRS}
) 

link_directories (
	${VisualGraph_BINARY_DIR}
)

if (WIN32)
	set (GUI_TYPE WIN32)
endif ()

add_executable (glut_app ${GUI_TYPE} Main.cpp)

set (GlutAppLibs oggl)

find_package (GLUT)

if (NOT GLUT_FOUND)
	message (FATAL_ERROR 
		"GLUT not found.")
elseif ()
	message (STATUS "GlUT found.")
endif ()

if (WIN32)
	set (GlutAppLibs ${GlutAppLibs} Psapi glut32)
elseif ()
	set (GlutAppLibs ${GlutAppLibs} @{GLUT_LIBRARIES})
endif ()

target_link_libraries (glut_app ${GlutAppLibs} ${OGDF_LIBRARY})
