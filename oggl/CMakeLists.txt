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
	glload/source/gll_cpp.cpp
	glload/source/gll_gl_ext.c
	glload/source/gll_gl_ext.h
	glload/source/gll_gl_ext_base.h
	glload/source/gll_util.h
)

if (WIN32)
	set (OgglSourceFiles 
		${OgglSourceFiles}
		glload/source/wgll_ext.c
		glload/source/wgll_ext.h
		glload/source/wgll_ext_base.h	
	)
elseif ()
	set (OgglSourceFiles 
		${OgglSourceFiles}
		glload/source/glxl_ext.c
		glload/source/glxl_ext.h
	)
endif ()

add_library (oggl ${OgglSourceFiles})
