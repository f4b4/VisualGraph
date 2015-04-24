#
# VisualGraph/CMakeLists.txt
#

cmake_minimum_required (VERSION 2.8.11 FATAL_ERROR) 

project (VisualGraph) 

# OGDF
find_path(OGDF_INCLUDE_DIR ogdf/basic/basic.h
	../ogdf/include
)

message(STATUS "OGDF_INCLUDE_DIR: ${OGDF_INCLUDE_DIR}")

if (WIN32)

	find_library(OGDF_DEBUG_LIBRARY
	  NAME OGDF ogdf
	  PATHS 
	  	../OGDF/Win32/Debug
	)

	find_library(OGDF_RELEASE_LIBRARY
	  NAME OGDF ogdf
	  PATHS 
	  	../OGDF/Win32/Release
	)

	message(STATUS "OGDF_DEBUG_LIBRARY: ${OGDF_DEBUG_LIBRARY}")
	message(STATUS "OGDF_RELEASE_LIBRARY: ${OGDF_RELEASE_LIBRARY}")

	if (NOT OGDF_INCLUDE_DIR OR NOT OGDF_DEBUG_LIBRARY OR NOT OGDF_RELEASE_LIBRARY)
		message (FATAL_ERROR 
			"OGDF not found, please call cmake with "
			"-DOGDF_INCLUDE_DIR:PATH=<full path to OGDF include director> and "
			"-DOGDF_DEBUG_LIBRARY:FILEPATH=<full path to OGDF DEBUG library> "
			"and -DOGDF_RELEASE_LIBRARY:FILEPATH=<full path to OGDF RELEASE "
			"library>")
	endif ()

else ()

	find_library(OGDF_LIBRARY
	  NAME OGDF ogdf
	  PATHS 
	  	../OGDF/_release
	 	../OGDF/_debug
	)

	message(STATUS "OGDF_LIBRARY: ${OGDF_LIBRARY}")

	if (NOT OGDF_INCLUDE_DIR OR NOT OGDF_LIBRARY)
		message (FATAL_ERROR 
			"OGDF not found, please call cmake with "
			"-DOGDF_INCLUDE_DIR:PATH=<full path to OGDF include director>"
			"-DOGDF_LIBRARY:FILEPATH=<full path to OGDF library>")
	endif ()

endif()

if (UNIX)
	if (CMAKE_COMPILER_IS_GNUCC)
		if (CMAKE_BUILD_TYPE MATCHES Debug)
			# #define _DEBUG
			ADD_DEFINITIONS(-D_DEBUG)
		endif ()

		ADD_DEFINITIONS(-Wall)

		# enable C++11, requires gcc 4.7 or higher
		set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
	endif ()
endif ()

add_definitions (-D_UNICODE)
add_definitions (-DUNICODE)

add_subdirectory (oggl) 
add_subdirectory (VisualGraph) 
