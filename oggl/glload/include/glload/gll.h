/** Copyright (C) 2011 by Jason L. McKesson **/
/** This file is licensed by the MIT License. **/



#ifndef GLSDL_LOAD_H
#define GLSDL_LOAD_H

/**
\file
\brief The C header to include if you want to initialize the OpenGL functions.

**/

///\addtogroup module_glload_cinter
///@{

/**
\brief The loading status returned by the GL loading functions.

**/
enum LoadSucceeded
{
	LS_LOAD_FUNCTIONS_ALL,		///<All function pointers defined for each extension have been loaded.
	LS_LOAD_FUNCTIONS_SOME,		///<Only some of the function pointers defined for each extension have been loaded.
	LS_LOAD_FAILED,				///<Function loading failed. Things were reset to nothing being loaded.
};

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
\brief Loads all of the OpenGL function pointers for the current version and extensions.

This function will respect the core/compatibility flags that the context was created under
(if the version is 3.2 or better and thus has those flags available). Similarly, if ARB_compatibility
is defined for a 3.1 context, it will load the compatibility profile; otherwise, it will load the core.
For 3.0 and below, it loads everything available.

\return Of the type ::LoadSucceeded.
**/
int LoadFunctions();

#ifdef WIN32
/**
\brief Loads all of the function pointers associated with WGL.

\return Of the type ::LoadSucceeded.
**/
int LoadWinFunctions(void *hdc);
#endif //WIN32
#ifdef GLX_H
/**
\brief Loads all of the function pointers associated with GLX.

\return Of the type ::LoadSucceeded.
**/
int LoadGLXFunctions(void *display, int screen);
#endif

/**
This function retrieves the major GL version number. Only works after LoadFunctions has been called.
**/
int GetMajorVersion();

/**
This function retrieves the minor GL version number. Only works after LoadFunctions has been called.
**/
int GetMinorVersion();

///Returns non-zero if the current GL version is greater than or equal to the given version.
int IsVersionGEQ(int iMajorVersion, int iMinorVersion);
///@}

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //GLSDL_LOAD_H

