#
# VisualGraph/oggl/CMakeLists.txt
#

include_directories (
	${VisualGraph_SOURCE_DIR}
	${VisualGraph_SOURCE_DIR}/oggl/glload/include
	${OGDF_INCLUDE_DIR}
) 

link_directories (${VisualGraph_BINARY_DIR})

set (OgglSourceFiles 
	${OgglSourceFiles}
	DebugStream.cpp
	GraphCreator.cpp
	GraphPainter.cpp
	Shader.cpp
	Util.cpp
	DebugStream.h
	GraphCreator.h
	GraphPainter.h
	Math.h
	Shader.h
	ShaderCode.h
	Types.h
	Util.h
	glload/source/gll_c.c
	glload/source/gll_gl_ext.c
	glload/source/gll_cpp.cpp
	glload/include/glload/gl_3_3_comp.hpp
	glload/include/glload/gll.hpp
)

if (WIN32)
	set (OgglSourceFiles 
		${OgglSourceFiles}
		glload/source/wgll_ext.c
	)
	set_source_files_properties(wgll_ext.c PROPERTIES COMPILE_FLAGS -w)
elseif ()
	set (OgglSourceFiles 
		${OgglSourceFiles}
		glload/source/glxl_ext.c
	)
	set_source_files_properties(glload/source/glxl_ext.c PROPERTIES COMPILE_FLAGS -w)
endif ()

# disable warnings for glload files
set_source_files_properties(glload/source/gll_c.c      PROPERTIES COMPILE_FLAGS -w)
set_source_files_properties(glload/source/gll_gl_ext.c PROPERTIES COMPILE_FLAGS -w)
set_source_files_properties(glload/source/gll_cpp.cpp  PROPERTIES COMPILE_FLAGS -w)

add_library (oggl ${OgglSourceFiles})
