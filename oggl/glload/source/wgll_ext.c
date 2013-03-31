#include <stdlib.h>
#include <string.h>
#include "wgll_ext.h"

#ifdef __wglext_h_
#error Attempt to include wgl_exts after including wglext.h
#endif

#define __wglext_h_

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
	#define NOMINMAX
#endif
#include <windows.h>

#ifdef GLE_FUNCPTR
#undef GLE_FUNCPTR
#endif //GLE_FUNCPTR
#define GLE_FUNCPTR WINAPI


#ifndef GLLOAD_BASIC_OPENGL_TYPEDEFS
#define GLLOAD_BASIC_OPENGL_TYPEDEFS

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
#define GLvoid void

#endif //GLLOAD_BASIC_OPENGL_TYPEDEFS

#include <stddef.h>	
	
static int TestPointer(const void *pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

#ifndef WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
DECLARE_HANDLE(HPBUFFEREXT);
#endif
#ifndef WGL_NV_present_video
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#endif
#ifndef WGL_NV_video_output
DECLARE_HANDLE(HPVIDEODEV);
#endif
#ifndef WGL_NV_gpu_affinity
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
typedef struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
} GPU_DEVICE, *PGPU_DEVICE;
#endif
#ifndef WGL_NV_video_capture
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#endif

#if defined(__APPLE__)
#include <mach-o/dyld.h>

static void* AppleGLGetProcAddress (const GLubyte *name)
{
  static const struct mach_header* image = NULL;
  NSSymbol symbol;
  char* symbolName;
  if (NULL == image)
  {
    image = NSAddImage("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", NSADDIMAGE_OPTION_RETURN_ON_ERROR);
  }
  /* prepend a '_' for the Unix C symbol mangling convention */
  symbolName = malloc(strlen((const char*)name) + 2);
  strcpy(symbolName+1, (const char*)name);
  symbolName[0] = '_';
  symbol = NULL;
  /* if (NSIsSymbolNameDefined(symbolName))
	 symbol = NSLookupAndBindSymbol(symbolName); */
  symbol = image ? NSLookupSymbolInImage(image, symbolName, NSLOOKUPSYMBOLINIMAGE_OPTION_BIND | NSLOOKUPSYMBOLINIMAGE_OPTION_RETURN_ON_ERROR) : NULL;
  free(symbolName);
  return symbol ? NSAddressOfSymbol(symbol) : NULL;
}
#endif /* __APPLE__ */

#if defined(__sgi) || defined (__sun)
#include <dlfcn.h>
#include <stdio.h>

static void* SunGetProcAddress (const GLubyte* name)
{
  static void* h = NULL;
  static void* gpa;

  if (h == NULL)
  {
    if ((h = dlopen(NULL, RTLD_LAZY | RTLD_LOCAL)) == NULL) return NULL;
    gpa = dlsym(h, "glXGetProcAddress");
  }

  if (gpa != NULL)
    return ((void*(*)(const GLubyte*))gpa)(name);
  else
    return dlsym(h, (const char*)name);
}
#endif /* __sgi || __sun */

#if defined(_WIN32)

#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
static void *WinGetProcAddress(const char *name)
{
	HMODULE glMod = NULL;
	void *pFunc = (void*)wglGetProcAddress((LPCSTR)name);
	if(TestPointer(pFunc))
	{
		return pFunc;
	}
	glMod = GetModuleHandleA("OpenGL32.dll");
	return (void*)GetProcAddress(glMod, (LPCSTR)name);
}
	
#define gleIntGetProcAddress(name) WinGetProcAddress(name)
#else
	#if defined(__APPLE__)
		#define gleIntGetProcAddress(name) AppleGLGetProcAddress(name)
	#else
		#if defined(__sgi) || defined(__sun)
			#define gleIntGetProcAddress(name) SunGetProcAddress(name)
		#else /* GLX */
		    #include <GL/glx.h>

			#define gleIntGetProcAddress(name) (*glXGetProcAddressARB)(name)
		#endif
	#endif
#endif

int wglext_ARB_buffer_region = 0;
int wglext_ARB_multisample = 0;
int wglext_ARB_extensions_string = 0;
int wglext_ARB_pixel_format = 0;
int wglext_ARB_make_current_read = 0;
int wglext_ARB_pbuffer = 0;
int wglext_ARB_render_texture = 0;
int wglext_ARB_pixel_format_float = 0;
int wglext_ARB_framebuffer_sRGB = 0;
int wglext_ARB_create_context = 0;
int wglext_ARB_create_context_profile = 0;
int wglext_ARB_create_context_robustness = 0;
int wglext_EXT_make_current_read = 0;
int wglext_EXT_pixel_format = 0;
int wglext_EXT_pbuffer = 0;
int wglext_EXT_swap_control = 0;
int wglext_EXT_depth_float = 0;
int wglext_3DFX_multisample = 0;
int wglext_EXT_multisample = 0;
int wglext_I3D_digital_video_control = 0;
int wglext_I3D_gamma = 0;
int wglext_I3D_genlock = 0;
int wglext_I3D_image_buffer = 0;
int wglext_I3D_swap_frame_lock = 0;
int wglext_NV_render_depth_texture = 0;
int wglext_NV_render_texture_rectangle = 0;
int wglext_ATI_pixel_format_float = 0;
int wglext_NV_float_buffer = 0;
int wglext_3DL_stereo_control = 0;
int wglext_EXT_pixel_format_packed_float = 0;
int wglext_EXT_framebuffer_sRGB = 0;
int wglext_NV_present_video = 0;
int wglext_NV_video_output = 0;
int wglext_NV_swap_group = 0;
int wglext_NV_gpu_affinity = 0;
int wglext_AMD_gpu_association = 0;
int wglext_NV_video_capture = 0;
int wglext_NV_copy_image = 0;
int wglext_NV_multisample_coverage = 0;
int wglext_EXT_create_context_es2_profile = 0;
int wglext_NV_DX_interop = 0;
int wglext_NV_DX_interop2 = 0;
int wglext_EXT_swap_control_tear = 0;


void wgleIntClear()
{
	wglext_ARB_buffer_region = 0;
	wglext_ARB_multisample = 0;
	wglext_ARB_extensions_string = 0;
	wglext_ARB_pixel_format = 0;
	wglext_ARB_make_current_read = 0;
	wglext_ARB_pbuffer = 0;
	wglext_ARB_render_texture = 0;
	wglext_ARB_pixel_format_float = 0;
	wglext_ARB_framebuffer_sRGB = 0;
	wglext_ARB_create_context = 0;
	wglext_ARB_create_context_profile = 0;
	wglext_ARB_create_context_robustness = 0;
	wglext_EXT_make_current_read = 0;
	wglext_EXT_pixel_format = 0;
	wglext_EXT_pbuffer = 0;
	wglext_EXT_swap_control = 0;
	wglext_EXT_depth_float = 0;
	wglext_3DFX_multisample = 0;
	wglext_EXT_multisample = 0;
	wglext_I3D_digital_video_control = 0;
	wglext_I3D_gamma = 0;
	wglext_I3D_genlock = 0;
	wglext_I3D_image_buffer = 0;
	wglext_I3D_swap_frame_lock = 0;
	wglext_NV_render_depth_texture = 0;
	wglext_NV_render_texture_rectangle = 0;
	wglext_ATI_pixel_format_float = 0;
	wglext_NV_float_buffer = 0;
	wglext_3DL_stereo_control = 0;
	wglext_EXT_pixel_format_packed_float = 0;
	wglext_EXT_framebuffer_sRGB = 0;
	wglext_NV_present_video = 0;
	wglext_NV_video_output = 0;
	wglext_NV_swap_group = 0;
	wglext_NV_gpu_affinity = 0;
	wglext_AMD_gpu_association = 0;
	wglext_NV_video_capture = 0;
	wglext_NV_copy_image = 0;
	wglext_NV_multisample_coverage = 0;
	wglext_EXT_create_context_es2_profile = 0;
	wglext_NV_DX_interop = 0;
	wglext_NV_DX_interop2 = 0;
	wglext_EXT_swap_control_tear = 0;
}



#ifndef WGL_3DL_stereo_control
typedef BOOL (GLE_FUNCPTR * PFNWGLSETSTEREOEMITTERSTATE3DLPROC)(HDC , UINT );

PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL;
#endif /*WGL_3DL_stereo_control*/

static int wgleIntLoad_3DL_stereo_control()
{
	int bIsLoaded = 1;
#ifndef WGL_3DL_stereo_control
	wglSetStereoEmitterState3DL = (PFNWGLSETSTEREOEMITTERSTATE3DLPROC)gleIntGetProcAddress("wglSetStereoEmitterState3DL");
	if(!wglSetStereoEmitterState3DL) bIsLoaded = 0;
#endif /*WGL_3DL_stereo_control*/
	return bIsLoaded;
}
#ifndef WGL_AMD_gpu_association
typedef UINT (GLE_FUNCPTR * PFNWGLGETGPUIDSAMDPROC)(UINT , UINT *);
typedef INT (GLE_FUNCPTR * PFNWGLGETGPUINFOAMDPROC)(UINT , int , GLenum , UINT , void *);
typedef UINT (GLE_FUNCPTR * PFNWGLGETCONTEXTGPUIDAMDPROC)(HGLRC );
typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)(UINT );
typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)(UINT , HGLRC , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)(HGLRC );
typedef BOOL (GLE_FUNCPTR * PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)(HGLRC );
typedef HGLRC (GLE_FUNCPTR * PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)();
typedef VOID (GLE_FUNCPTR * PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)(HGLRC , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );

PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD;
PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD;
PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD;
PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD;
PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD;
PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD;
PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD;
PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD;
PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD;
#endif /*WGL_AMD_gpu_association*/

static int wgleIntLoad_AMD_gpu_association()
{
	int bIsLoaded = 1;
#ifndef WGL_AMD_gpu_association
	wglGetGPUIDsAMD = (PFNWGLGETGPUIDSAMDPROC)gleIntGetProcAddress("wglGetGPUIDsAMD");
	if(!wglGetGPUIDsAMD) bIsLoaded = 0;
	wglGetGPUInfoAMD = (PFNWGLGETGPUINFOAMDPROC)gleIntGetProcAddress("wglGetGPUInfoAMD");
	if(!wglGetGPUInfoAMD) bIsLoaded = 0;
	wglGetContextGPUIDAMD = (PFNWGLGETCONTEXTGPUIDAMDPROC)gleIntGetProcAddress("wglGetContextGPUIDAMD");
	if(!wglGetContextGPUIDAMD) bIsLoaded = 0;
	wglCreateAssociatedContextAMD = (PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)gleIntGetProcAddress("wglCreateAssociatedContextAMD");
	if(!wglCreateAssociatedContextAMD) bIsLoaded = 0;
	wglCreateAssociatedContextAttribsAMD = (PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)gleIntGetProcAddress("wglCreateAssociatedContextAttribsAMD");
	if(!wglCreateAssociatedContextAttribsAMD) bIsLoaded = 0;
	wglDeleteAssociatedContextAMD = (PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)gleIntGetProcAddress("wglDeleteAssociatedContextAMD");
	if(!wglDeleteAssociatedContextAMD) bIsLoaded = 0;
	wglMakeAssociatedContextCurrentAMD = (PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)gleIntGetProcAddress("wglMakeAssociatedContextCurrentAMD");
	if(!wglMakeAssociatedContextCurrentAMD) bIsLoaded = 0;
	wglGetCurrentAssociatedContextAMD = (PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)gleIntGetProcAddress("wglGetCurrentAssociatedContextAMD");
	if(!wglGetCurrentAssociatedContextAMD) bIsLoaded = 0;
	wglBlitContextFramebufferAMD = (PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)gleIntGetProcAddress("wglBlitContextFramebufferAMD");
	if(!wglBlitContextFramebufferAMD) bIsLoaded = 0;
#endif /*WGL_AMD_gpu_association*/
	return bIsLoaded;
}
#ifndef WGL_ARB_buffer_region
typedef HANDLE (GLE_FUNCPTR * PFNWGLCREATEBUFFERREGIONARBPROC)(HDC , int , UINT );
typedef VOID (GLE_FUNCPTR * PFNWGLDELETEBUFFERREGIONARBPROC)(HANDLE );
typedef BOOL (GLE_FUNCPTR * PFNWGLSAVEBUFFERREGIONARBPROC)(HANDLE , int , int , int , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRESTOREBUFFERREGIONARBPROC)(HANDLE , int , int , int , int , int , int );

PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB;
PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB;
PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB;
PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB;
#endif /*WGL_ARB_buffer_region*/

static int wgleIntLoad_ARB_buffer_region()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_buffer_region
	wglCreateBufferRegionARB = (PFNWGLCREATEBUFFERREGIONARBPROC)gleIntGetProcAddress("wglCreateBufferRegionARB");
	if(!wglCreateBufferRegionARB) bIsLoaded = 0;
	wglDeleteBufferRegionARB = (PFNWGLDELETEBUFFERREGIONARBPROC)gleIntGetProcAddress("wglDeleteBufferRegionARB");
	if(!wglDeleteBufferRegionARB) bIsLoaded = 0;
	wglSaveBufferRegionARB = (PFNWGLSAVEBUFFERREGIONARBPROC)gleIntGetProcAddress("wglSaveBufferRegionARB");
	if(!wglSaveBufferRegionARB) bIsLoaded = 0;
	wglRestoreBufferRegionARB = (PFNWGLRESTOREBUFFERREGIONARBPROC)gleIntGetProcAddress("wglRestoreBufferRegionARB");
	if(!wglRestoreBufferRegionARB) bIsLoaded = 0;
#endif /*WGL_ARB_buffer_region*/
	return bIsLoaded;
}
#ifndef WGL_ARB_create_context
typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC , HGLRC , const int *);

PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
#endif /*WGL_ARB_create_context*/

static int wgleIntLoad_ARB_create_context()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_create_context
	wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)gleIntGetProcAddress("wglCreateContextAttribsARB");
	if(!wglCreateContextAttribsARB) bIsLoaded = 0;
#endif /*WGL_ARB_create_context*/
	return bIsLoaded;
}


#ifndef WGL_ARB_extensions_string
typedef const char * (GLE_FUNCPTR * PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC );

PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;
#endif /*WGL_ARB_extensions_string*/

static int wgleIntLoad_ARB_extensions_string()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_extensions_string
	wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)gleIntGetProcAddress("wglGetExtensionsStringARB");
	if(!wglGetExtensionsStringARB) bIsLoaded = 0;
#endif /*WGL_ARB_extensions_string*/
	return bIsLoaded;
}

#ifndef WGL_ARB_make_current_read
typedef BOOL (GLE_FUNCPTR * PFNWGLMAKECONTEXTCURRENTARBPROC)(HDC , HDC , HGLRC );
typedef HDC (GLE_FUNCPTR * PFNWGLGETCURRENTREADDCARBPROC)();

PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB;
PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB;
#endif /*WGL_ARB_make_current_read*/

static int wgleIntLoad_ARB_make_current_read()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_make_current_read
	wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC)gleIntGetProcAddress("wglMakeContextCurrentARB");
	if(!wglMakeContextCurrentARB) bIsLoaded = 0;
	wglGetCurrentReadDCARB = (PFNWGLGETCURRENTREADDCARBPROC)gleIntGetProcAddress("wglGetCurrentReadDCARB");
	if(!wglGetCurrentReadDCARB) bIsLoaded = 0;
#endif /*WGL_ARB_make_current_read*/
	return bIsLoaded;
}

#ifndef WGL_ARB_pbuffer
typedef HPBUFFERARB (GLE_FUNCPTR * PFNWGLCREATEPBUFFERARBPROC)(HDC , int , int , int , const int *);
typedef HDC (GLE_FUNCPTR * PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB );
typedef int (GLE_FUNCPTR * PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB , HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB , int , int *);

PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB;
PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB;
PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB;
PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB;
PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB;
#endif /*WGL_ARB_pbuffer*/

static int wgleIntLoad_ARB_pbuffer()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_pbuffer
	wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC)gleIntGetProcAddress("wglCreatePbufferARB");
	if(!wglCreatePbufferARB) bIsLoaded = 0;
	wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC)gleIntGetProcAddress("wglGetPbufferDCARB");
	if(!wglGetPbufferDCARB) bIsLoaded = 0;
	wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC)gleIntGetProcAddress("wglReleasePbufferDCARB");
	if(!wglReleasePbufferDCARB) bIsLoaded = 0;
	wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC)gleIntGetProcAddress("wglDestroyPbufferARB");
	if(!wglDestroyPbufferARB) bIsLoaded = 0;
	wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC)gleIntGetProcAddress("wglQueryPbufferARB");
	if(!wglQueryPbufferARB) bIsLoaded = 0;
#endif /*WGL_ARB_pbuffer*/
	return bIsLoaded;
}
#ifndef WGL_ARB_pixel_format
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC , int , int , UINT , const int *, int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC , int , int , UINT , const int *, FLOAT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB;
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
#endif /*WGL_ARB_pixel_format*/

static int wgleIntLoad_ARB_pixel_format()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_pixel_format
	wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC)gleIntGetProcAddress("wglGetPixelFormatAttribivARB");
	if(!wglGetPixelFormatAttribivARB) bIsLoaded = 0;
	wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC)gleIntGetProcAddress("wglGetPixelFormatAttribfvARB");
	if(!wglGetPixelFormatAttribfvARB) bIsLoaded = 0;
	wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)gleIntGetProcAddress("wglChoosePixelFormatARB");
	if(!wglChoosePixelFormatARB) bIsLoaded = 0;
#endif /*WGL_ARB_pixel_format*/
	return bIsLoaded;
}

#ifndef WGL_ARB_render_texture
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDTEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASETEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLSETPBUFFERATTRIBARBPROC)(HPBUFFERARB , const int *);

PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB;
PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB;
PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB;
#endif /*WGL_ARB_render_texture*/

static int wgleIntLoad_ARB_render_texture()
{
	int bIsLoaded = 1;
#ifndef WGL_ARB_render_texture
	wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC)gleIntGetProcAddress("wglBindTexImageARB");
	if(!wglBindTexImageARB) bIsLoaded = 0;
	wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC)gleIntGetProcAddress("wglReleaseTexImageARB");
	if(!wglReleaseTexImageARB) bIsLoaded = 0;
	wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC)gleIntGetProcAddress("wglSetPbufferAttribARB");
	if(!wglSetPbufferAttribARB) bIsLoaded = 0;
#endif /*WGL_ARB_render_texture*/
	return bIsLoaded;
}




#ifndef WGL_EXT_make_current_read
typedef BOOL (GLE_FUNCPTR * PFNWGLMAKECONTEXTCURRENTEXTPROC)(HDC , HDC , HGLRC );
typedef HDC (GLE_FUNCPTR * PFNWGLGETCURRENTREADDCEXTPROC)();

PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT;
PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT;
#endif /*WGL_EXT_make_current_read*/

static int wgleIntLoad_EXT_make_current_read()
{
	int bIsLoaded = 1;
#ifndef WGL_EXT_make_current_read
	wglMakeContextCurrentEXT = (PFNWGLMAKECONTEXTCURRENTEXTPROC)gleIntGetProcAddress("wglMakeContextCurrentEXT");
	if(!wglMakeContextCurrentEXT) bIsLoaded = 0;
	wglGetCurrentReadDCEXT = (PFNWGLGETCURRENTREADDCEXTPROC)gleIntGetProcAddress("wglGetCurrentReadDCEXT");
	if(!wglGetCurrentReadDCEXT) bIsLoaded = 0;
#endif /*WGL_EXT_make_current_read*/
	return bIsLoaded;
}

#ifndef WGL_EXT_pbuffer
typedef HPBUFFEREXT (GLE_FUNCPTR * PFNWGLCREATEPBUFFEREXTPROC)(HDC , int , int , int , const int *);
typedef HDC (GLE_FUNCPTR * PFNWGLGETPBUFFERDCEXTPROC)(HPBUFFEREXT );
typedef int (GLE_FUNCPTR * PFNWGLRELEASEPBUFFERDCEXTPROC)(HPBUFFEREXT , HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYPBUFFEREXTPROC)(HPBUFFEREXT );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYPBUFFEREXTPROC)(HPBUFFEREXT , int , int *);

PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT;
PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT;
PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT;
PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT;
PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT;
#endif /*WGL_EXT_pbuffer*/

static int wgleIntLoad_EXT_pbuffer()
{
	int bIsLoaded = 1;
#ifndef WGL_EXT_pbuffer
	wglCreatePbufferEXT = (PFNWGLCREATEPBUFFEREXTPROC)gleIntGetProcAddress("wglCreatePbufferEXT");
	if(!wglCreatePbufferEXT) bIsLoaded = 0;
	wglGetPbufferDCEXT = (PFNWGLGETPBUFFERDCEXTPROC)gleIntGetProcAddress("wglGetPbufferDCEXT");
	if(!wglGetPbufferDCEXT) bIsLoaded = 0;
	wglReleasePbufferDCEXT = (PFNWGLRELEASEPBUFFERDCEXTPROC)gleIntGetProcAddress("wglReleasePbufferDCEXT");
	if(!wglReleasePbufferDCEXT) bIsLoaded = 0;
	wglDestroyPbufferEXT = (PFNWGLDESTROYPBUFFEREXTPROC)gleIntGetProcAddress("wglDestroyPbufferEXT");
	if(!wglDestroyPbufferEXT) bIsLoaded = 0;
	wglQueryPbufferEXT = (PFNWGLQUERYPBUFFEREXTPROC)gleIntGetProcAddress("wglQueryPbufferEXT");
	if(!wglQueryPbufferEXT) bIsLoaded = 0;
#endif /*WGL_EXT_pbuffer*/
	return bIsLoaded;
}
#ifndef WGL_EXT_pixel_format
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)(HDC , int , int , UINT , int *, int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)(HDC , int , int , UINT , int *, FLOAT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLCHOOSEPIXELFORMATEXTPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT;
PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT;
PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT;
#endif /*WGL_EXT_pixel_format*/

static int wgleIntLoad_EXT_pixel_format()
{
	int bIsLoaded = 1;
#ifndef WGL_EXT_pixel_format
	wglGetPixelFormatAttribivEXT = (PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)gleIntGetProcAddress("wglGetPixelFormatAttribivEXT");
	if(!wglGetPixelFormatAttribivEXT) bIsLoaded = 0;
	wglGetPixelFormatAttribfvEXT = (PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)gleIntGetProcAddress("wglGetPixelFormatAttribfvEXT");
	if(!wglGetPixelFormatAttribfvEXT) bIsLoaded = 0;
	wglChoosePixelFormatEXT = (PFNWGLCHOOSEPIXELFORMATEXTPROC)gleIntGetProcAddress("wglChoosePixelFormatEXT");
	if(!wglChoosePixelFormatEXT) bIsLoaded = 0;
#endif /*WGL_EXT_pixel_format*/
	return bIsLoaded;
}

#ifndef WGL_EXT_swap_control
typedef BOOL (GLE_FUNCPTR * PFNWGLSWAPINTERVALEXTPROC)(int );
typedef int (GLE_FUNCPTR * PFNWGLGETSWAPINTERVALEXTPROC)();

PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;
#endif /*WGL_EXT_swap_control*/

static int wgleIntLoad_EXT_swap_control()
{
	int bIsLoaded = 1;
#ifndef WGL_EXT_swap_control
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)gleIntGetProcAddress("wglSwapIntervalEXT");
	if(!wglSwapIntervalEXT) bIsLoaded = 0;
	wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)gleIntGetProcAddress("wglGetSwapIntervalEXT");
	if(!wglGetSwapIntervalEXT) bIsLoaded = 0;
#endif /*WGL_EXT_swap_control*/
	return bIsLoaded;
}

#ifndef WGL_I3D_digital_video_control
typedef BOOL (GLE_FUNCPTR * PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , const int *);

PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D;
PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D;
#endif /*WGL_I3D_digital_video_control*/

static int wgleIntLoad_I3D_digital_video_control()
{
	int bIsLoaded = 1;
#ifndef WGL_I3D_digital_video_control
	wglGetDigitalVideoParametersI3D = (PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)gleIntGetProcAddress("wglGetDigitalVideoParametersI3D");
	if(!wglGetDigitalVideoParametersI3D) bIsLoaded = 0;
	wglSetDigitalVideoParametersI3D = (PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)gleIntGetProcAddress("wglSetDigitalVideoParametersI3D");
	if(!wglSetDigitalVideoParametersI3D) bIsLoaded = 0;
#endif /*WGL_I3D_digital_video_control*/
	return bIsLoaded;
}
#ifndef WGL_I3D_gamma
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGAMMATABLEI3DPROC)(HDC , int , USHORT *, USHORT *, USHORT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETGAMMATABLEI3DPROC)(HDC , int , const USHORT *, const USHORT *, const USHORT *);

PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D;
PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D;
PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D;
PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D;
#endif /*WGL_I3D_gamma*/

static int wgleIntLoad_I3D_gamma()
{
	int bIsLoaded = 1;
#ifndef WGL_I3D_gamma
	wglGetGammaTableParametersI3D = (PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)gleIntGetProcAddress("wglGetGammaTableParametersI3D");
	if(!wglGetGammaTableParametersI3D) bIsLoaded = 0;
	wglSetGammaTableParametersI3D = (PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)gleIntGetProcAddress("wglSetGammaTableParametersI3D");
	if(!wglSetGammaTableParametersI3D) bIsLoaded = 0;
	wglGetGammaTableI3D = (PFNWGLGETGAMMATABLEI3DPROC)gleIntGetProcAddress("wglGetGammaTableI3D");
	if(!wglGetGammaTableI3D) bIsLoaded = 0;
	wglSetGammaTableI3D = (PFNWGLSETGAMMATABLEI3DPROC)gleIntGetProcAddress("wglSetGammaTableI3D");
	if(!wglSetGammaTableI3D) bIsLoaded = 0;
#endif /*WGL_I3D_gamma*/
	return bIsLoaded;
}
#ifndef WGL_I3D_genlock
typedef BOOL (GLE_FUNCPTR * PFNWGLENABLEGENLOCKI3DPROC)(HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLDISABLEGENLOCKI3DPROC)(HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLISENABLEDGENLOCKI3DPROC)(HDC , BOOL *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGENLOCKSOURCEI3DPROC)(HDC , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGENLOCKSOURCEI3DPROC)(HDC , UINT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGENLOCKSOURCEEDGEI3DPROC)(HDC , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)(HDC , UINT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGENLOCKSAMPLERATEI3DPROC)(HDC , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGENLOCKSAMPLERATEI3DPROC)(HDC , UINT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGENLOCKSOURCEDELAYI3DPROC)(HDC , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)(HDC , UINT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)(HDC , UINT *, UINT *);

PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D;
PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D;
PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D;
PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D;
PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D;
PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D;
PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D;
PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D;
PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D;
PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D;
PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D;
PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D;
#endif /*WGL_I3D_genlock*/

static int wgleIntLoad_I3D_genlock()
{
	int bIsLoaded = 1;
#ifndef WGL_I3D_genlock
	wglEnableGenlockI3D = (PFNWGLENABLEGENLOCKI3DPROC)gleIntGetProcAddress("wglEnableGenlockI3D");
	if(!wglEnableGenlockI3D) bIsLoaded = 0;
	wglDisableGenlockI3D = (PFNWGLDISABLEGENLOCKI3DPROC)gleIntGetProcAddress("wglDisableGenlockI3D");
	if(!wglDisableGenlockI3D) bIsLoaded = 0;
	wglIsEnabledGenlockI3D = (PFNWGLISENABLEDGENLOCKI3DPROC)gleIntGetProcAddress("wglIsEnabledGenlockI3D");
	if(!wglIsEnabledGenlockI3D) bIsLoaded = 0;
	wglGenlockSourceI3D = (PFNWGLGENLOCKSOURCEI3DPROC)gleIntGetProcAddress("wglGenlockSourceI3D");
	if(!wglGenlockSourceI3D) bIsLoaded = 0;
	wglGetGenlockSourceI3D = (PFNWGLGETGENLOCKSOURCEI3DPROC)gleIntGetProcAddress("wglGetGenlockSourceI3D");
	if(!wglGetGenlockSourceI3D) bIsLoaded = 0;
	wglGenlockSourceEdgeI3D = (PFNWGLGENLOCKSOURCEEDGEI3DPROC)gleIntGetProcAddress("wglGenlockSourceEdgeI3D");
	if(!wglGenlockSourceEdgeI3D) bIsLoaded = 0;
	wglGetGenlockSourceEdgeI3D = (PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)gleIntGetProcAddress("wglGetGenlockSourceEdgeI3D");
	if(!wglGetGenlockSourceEdgeI3D) bIsLoaded = 0;
	wglGenlockSampleRateI3D = (PFNWGLGENLOCKSAMPLERATEI3DPROC)gleIntGetProcAddress("wglGenlockSampleRateI3D");
	if(!wglGenlockSampleRateI3D) bIsLoaded = 0;
	wglGetGenlockSampleRateI3D = (PFNWGLGETGENLOCKSAMPLERATEI3DPROC)gleIntGetProcAddress("wglGetGenlockSampleRateI3D");
	if(!wglGetGenlockSampleRateI3D) bIsLoaded = 0;
	wglGenlockSourceDelayI3D = (PFNWGLGENLOCKSOURCEDELAYI3DPROC)gleIntGetProcAddress("wglGenlockSourceDelayI3D");
	if(!wglGenlockSourceDelayI3D) bIsLoaded = 0;
	wglGetGenlockSourceDelayI3D = (PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)gleIntGetProcAddress("wglGetGenlockSourceDelayI3D");
	if(!wglGetGenlockSourceDelayI3D) bIsLoaded = 0;
	wglQueryGenlockMaxSourceDelayI3D = (PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)gleIntGetProcAddress("wglQueryGenlockMaxSourceDelayI3D");
	if(!wglQueryGenlockMaxSourceDelayI3D) bIsLoaded = 0;
#endif /*WGL_I3D_genlock*/
	return bIsLoaded;
}
#ifndef WGL_I3D_image_buffer
typedef LPVOID (GLE_FUNCPTR * PFNWGLCREATEIMAGEBUFFERI3DPROC)(HDC , DWORD , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYIMAGEBUFFERI3DPROC)(HDC , LPVOID );
typedef BOOL (GLE_FUNCPTR * PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)(HDC , const HANDLE *, const LPVOID *, const DWORD *, UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)(HDC , const LPVOID *, UINT );

PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D;
PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D;
PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D;
PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D;
#endif /*WGL_I3D_image_buffer*/

static int wgleIntLoad_I3D_image_buffer()
{
	int bIsLoaded = 1;
#ifndef WGL_I3D_image_buffer
	wglCreateImageBufferI3D = (PFNWGLCREATEIMAGEBUFFERI3DPROC)gleIntGetProcAddress("wglCreateImageBufferI3D");
	if(!wglCreateImageBufferI3D) bIsLoaded = 0;
	wglDestroyImageBufferI3D = (PFNWGLDESTROYIMAGEBUFFERI3DPROC)gleIntGetProcAddress("wglDestroyImageBufferI3D");
	if(!wglDestroyImageBufferI3D) bIsLoaded = 0;
	wglAssociateImageBufferEventsI3D = (PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)gleIntGetProcAddress("wglAssociateImageBufferEventsI3D");
	if(!wglAssociateImageBufferEventsI3D) bIsLoaded = 0;
	wglReleaseImageBufferEventsI3D = (PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)gleIntGetProcAddress("wglReleaseImageBufferEventsI3D");
	if(!wglReleaseImageBufferEventsI3D) bIsLoaded = 0;
#endif /*WGL_I3D_image_buffer*/
	return bIsLoaded;
}
#ifndef WGL_I3D_swap_frame_lock
typedef BOOL (GLE_FUNCPTR * PFNWGLENABLEFRAMELOCKI3DPROC)();
typedef BOOL (GLE_FUNCPTR * PFNWGLDISABLEFRAMELOCKI3DPROC)();
typedef BOOL (GLE_FUNCPTR * PFNWGLISENABLEDFRAMELOCKI3DPROC)(BOOL *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYFRAMELOCKMASTERI3DPROC)(BOOL *);

PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D;
PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D;
PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D;
PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D;
#endif /*WGL_I3D_swap_frame_lock*/

static int wgleIntLoad_I3D_swap_frame_lock()
{
	int bIsLoaded = 1;
#ifndef WGL_I3D_swap_frame_lock
	wglEnableFrameLockI3D = (PFNWGLENABLEFRAMELOCKI3DPROC)gleIntGetProcAddress("wglEnableFrameLockI3D");
	if(!wglEnableFrameLockI3D) bIsLoaded = 0;
	wglDisableFrameLockI3D = (PFNWGLDISABLEFRAMELOCKI3DPROC)gleIntGetProcAddress("wglDisableFrameLockI3D");
	if(!wglDisableFrameLockI3D) bIsLoaded = 0;
	wglIsEnabledFrameLockI3D = (PFNWGLISENABLEDFRAMELOCKI3DPROC)gleIntGetProcAddress("wglIsEnabledFrameLockI3D");
	if(!wglIsEnabledFrameLockI3D) bIsLoaded = 0;
	wglQueryFrameLockMasterI3D = (PFNWGLQUERYFRAMELOCKMASTERI3DPROC)gleIntGetProcAddress("wglQueryFrameLockMasterI3D");
	if(!wglQueryFrameLockMasterI3D) bIsLoaded = 0;
#endif /*WGL_I3D_swap_frame_lock*/
	return bIsLoaded;
}
#ifndef WGL_NV_DX_interop
typedef BOOL (GLE_FUNCPTR * PFNWGLDXSETRESOURCESHAREHANDLENVPROC)(void *, HANDLE );
typedef HANDLE (GLE_FUNCPTR * PFNWGLDXOPENDEVICENVPROC)(void *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDXCLOSEDEVICENVPROC)(HANDLE );
typedef HANDLE (GLE_FUNCPTR * PFNWGLDXREGISTEROBJECTNVPROC)(HANDLE , void *, GLuint , GLenum , GLenum );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXUNREGISTEROBJECTNVPROC)(HANDLE , HANDLE );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXOBJECTACCESSNVPROC)(HANDLE , GLenum );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDXUNLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);

PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV;
PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV;
PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV;
PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV;
PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV;
PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV;
PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV;
PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV;
#endif /*WGL_NV_DX_interop*/

static int wgleIntLoad_NV_DX_interop()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_DX_interop
	wglDXSetResourceShareHandleNV = (PFNWGLDXSETRESOURCESHAREHANDLENVPROC)gleIntGetProcAddress("wglDXSetResourceShareHandleNV");
	if(!wglDXSetResourceShareHandleNV) bIsLoaded = 0;
	wglDXOpenDeviceNV = (PFNWGLDXOPENDEVICENVPROC)gleIntGetProcAddress("wglDXOpenDeviceNV");
	if(!wglDXOpenDeviceNV) bIsLoaded = 0;
	wglDXCloseDeviceNV = (PFNWGLDXCLOSEDEVICENVPROC)gleIntGetProcAddress("wglDXCloseDeviceNV");
	if(!wglDXCloseDeviceNV) bIsLoaded = 0;
	wglDXRegisterObjectNV = (PFNWGLDXREGISTEROBJECTNVPROC)gleIntGetProcAddress("wglDXRegisterObjectNV");
	if(!wglDXRegisterObjectNV) bIsLoaded = 0;
	wglDXUnregisterObjectNV = (PFNWGLDXUNREGISTEROBJECTNVPROC)gleIntGetProcAddress("wglDXUnregisterObjectNV");
	if(!wglDXUnregisterObjectNV) bIsLoaded = 0;
	wglDXObjectAccessNV = (PFNWGLDXOBJECTACCESSNVPROC)gleIntGetProcAddress("wglDXObjectAccessNV");
	if(!wglDXObjectAccessNV) bIsLoaded = 0;
	wglDXLockObjectsNV = (PFNWGLDXLOCKOBJECTSNVPROC)gleIntGetProcAddress("wglDXLockObjectsNV");
	if(!wglDXLockObjectsNV) bIsLoaded = 0;
	wglDXUnlockObjectsNV = (PFNWGLDXUNLOCKOBJECTSNVPROC)gleIntGetProcAddress("wglDXUnlockObjectsNV");
	if(!wglDXUnlockObjectsNV) bIsLoaded = 0;
#endif /*WGL_NV_DX_interop*/
	return bIsLoaded;
}

#ifndef WGL_NV_copy_image
typedef BOOL (GLE_FUNCPTR * PFNWGLCOPYIMAGESUBDATANVPROC)(HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV;
#endif /*WGL_NV_copy_image*/

static int wgleIntLoad_NV_copy_image()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_copy_image
	wglCopyImageSubDataNV = (PFNWGLCOPYIMAGESUBDATANVPROC)gleIntGetProcAddress("wglCopyImageSubDataNV");
	if(!wglCopyImageSubDataNV) bIsLoaded = 0;
#endif /*WGL_NV_copy_image*/
	return bIsLoaded;
}

#ifndef WGL_NV_gpu_affinity
typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUSNVPROC)(UINT , HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUDEVICESNVPROC)(HGPUNV , UINT , PGPU_DEVICE );
typedef HDC (GLE_FUNCPTR * PFNWGLCREATEAFFINITYDCNVPROC)(const HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)(HDC , UINT , HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDELETEDCNVPROC)(HDC );

PFNWGLENUMGPUSNVPROC wglEnumGpusNV;
PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV;
PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV;
PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV;
PFNWGLDELETEDCNVPROC wglDeleteDCNV;
#endif /*WGL_NV_gpu_affinity*/

static int wgleIntLoad_NV_gpu_affinity()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_gpu_affinity
	wglEnumGpusNV = (PFNWGLENUMGPUSNVPROC)gleIntGetProcAddress("wglEnumGpusNV");
	if(!wglEnumGpusNV) bIsLoaded = 0;
	wglEnumGpuDevicesNV = (PFNWGLENUMGPUDEVICESNVPROC)gleIntGetProcAddress("wglEnumGpuDevicesNV");
	if(!wglEnumGpuDevicesNV) bIsLoaded = 0;
	wglCreateAffinityDCNV = (PFNWGLCREATEAFFINITYDCNVPROC)gleIntGetProcAddress("wglCreateAffinityDCNV");
	if(!wglCreateAffinityDCNV) bIsLoaded = 0;
	wglEnumGpusFromAffinityDCNV = (PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)gleIntGetProcAddress("wglEnumGpusFromAffinityDCNV");
	if(!wglEnumGpusFromAffinityDCNV) bIsLoaded = 0;
	wglDeleteDCNV = (PFNWGLDELETEDCNVPROC)gleIntGetProcAddress("wglDeleteDCNV");
	if(!wglDeleteDCNV) bIsLoaded = 0;
#endif /*WGL_NV_gpu_affinity*/
	return bIsLoaded;
}

#ifndef WGL_NV_present_video
typedef int (GLE_FUNCPTR * PFNWGLENUMERATEVIDEODEVICESNVPROC)(HDC , HVIDEOOUTPUTDEVICENV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEODEVICENVPROC)(HDC , unsigned int , HVIDEOOUTPUTDEVICENV , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYCURRENTCONTEXTNVPROC)(int , int *);

PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV;
PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV;
PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV;
#endif /*WGL_NV_present_video*/

static int wgleIntLoad_NV_present_video()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_present_video
	wglEnumerateVideoDevicesNV = (PFNWGLENUMERATEVIDEODEVICESNVPROC)gleIntGetProcAddress("wglEnumerateVideoDevicesNV");
	if(!wglEnumerateVideoDevicesNV) bIsLoaded = 0;
	wglBindVideoDeviceNV = (PFNWGLBINDVIDEODEVICENVPROC)gleIntGetProcAddress("wglBindVideoDeviceNV");
	if(!wglBindVideoDeviceNV) bIsLoaded = 0;
	wglQueryCurrentContextNV = (PFNWGLQUERYCURRENTCONTEXTNVPROC)gleIntGetProcAddress("wglQueryCurrentContextNV");
	if(!wglQueryCurrentContextNV) bIsLoaded = 0;
#endif /*WGL_NV_present_video*/
	return bIsLoaded;
}


#ifndef WGL_NV_swap_group
typedef BOOL (GLE_FUNCPTR * PFNWGLJOINSWAPGROUPNVPROC)(HDC , GLuint );
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDSWAPBARRIERNVPROC)(GLuint , GLuint );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYSWAPGROUPNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYMAXSWAPGROUPSNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYFRAMECOUNTNVPROC)(HDC , GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRESETFRAMECOUNTNVPROC)(HDC );

PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV;
PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV;
PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV;
PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV;
PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV;
PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV;
#endif /*WGL_NV_swap_group*/

static int wgleIntLoad_NV_swap_group()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_swap_group
	wglJoinSwapGroupNV = (PFNWGLJOINSWAPGROUPNVPROC)gleIntGetProcAddress("wglJoinSwapGroupNV");
	if(!wglJoinSwapGroupNV) bIsLoaded = 0;
	wglBindSwapBarrierNV = (PFNWGLBINDSWAPBARRIERNVPROC)gleIntGetProcAddress("wglBindSwapBarrierNV");
	if(!wglBindSwapBarrierNV) bIsLoaded = 0;
	wglQuerySwapGroupNV = (PFNWGLQUERYSWAPGROUPNVPROC)gleIntGetProcAddress("wglQuerySwapGroupNV");
	if(!wglQuerySwapGroupNV) bIsLoaded = 0;
	wglQueryMaxSwapGroupsNV = (PFNWGLQUERYMAXSWAPGROUPSNVPROC)gleIntGetProcAddress("wglQueryMaxSwapGroupsNV");
	if(!wglQueryMaxSwapGroupsNV) bIsLoaded = 0;
	wglQueryFrameCountNV = (PFNWGLQUERYFRAMECOUNTNVPROC)gleIntGetProcAddress("wglQueryFrameCountNV");
	if(!wglQueryFrameCountNV) bIsLoaded = 0;
	wglResetFrameCountNV = (PFNWGLRESETFRAMECOUNTNVPROC)gleIntGetProcAddress("wglResetFrameCountNV");
	if(!wglResetFrameCountNV) bIsLoaded = 0;
#endif /*WGL_NV_swap_group*/
	return bIsLoaded;
}
#ifndef WGL_NV_video_capture
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)(UINT , HVIDEOINPUTDEVICENV );
typedef UINT (GLE_FUNCPTR * PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)(HDC , HVIDEOINPUTDEVICENV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );

PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV;
PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV;
PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV;
PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV;
PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV;
#endif /*WGL_NV_video_capture*/

static int wgleIntLoad_NV_video_capture()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_video_capture
	wglBindVideoCaptureDeviceNV = (PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("wglBindVideoCaptureDeviceNV");
	if(!wglBindVideoCaptureDeviceNV) bIsLoaded = 0;
	wglEnumerateVideoCaptureDevicesNV = (PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)gleIntGetProcAddress("wglEnumerateVideoCaptureDevicesNV");
	if(!wglEnumerateVideoCaptureDevicesNV) bIsLoaded = 0;
	wglLockVideoCaptureDeviceNV = (PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("wglLockVideoCaptureDeviceNV");
	if(!wglLockVideoCaptureDeviceNV) bIsLoaded = 0;
	wglQueryVideoCaptureDeviceNV = (PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("wglQueryVideoCaptureDeviceNV");
	if(!wglQueryVideoCaptureDeviceNV) bIsLoaded = 0;
	wglReleaseVideoCaptureDeviceNV = (PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("wglReleaseVideoCaptureDeviceNV");
	if(!wglReleaseVideoCaptureDeviceNV) bIsLoaded = 0;
#endif /*WGL_NV_video_capture*/
	return bIsLoaded;
}
#ifndef WGL_NV_video_output
typedef BOOL (GLE_FUNCPTR * PFNWGLGETVIDEODEVICENVPROC)(HDC , int , HPVIDEODEV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEODEVICENVPROC)(HPVIDEODEV );
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEOIMAGENVPROC)(HPVIDEODEV , HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEOIMAGENVPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLSENDPBUFFERTOVIDEONVPROC)(HPBUFFERARB , int , unsigned long *, BOOL );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETVIDEOINFONVPROC)(HPVIDEODEV , unsigned long *, unsigned long *);

PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV;
PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV;
PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV;
PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV;
PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV;
PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV;
#endif /*WGL_NV_video_output*/

static int wgleIntLoad_NV_video_output()
{
	int bIsLoaded = 1;
#ifndef WGL_NV_video_output
	wglGetVideoDeviceNV = (PFNWGLGETVIDEODEVICENVPROC)gleIntGetProcAddress("wglGetVideoDeviceNV");
	if(!wglGetVideoDeviceNV) bIsLoaded = 0;
	wglReleaseVideoDeviceNV = (PFNWGLRELEASEVIDEODEVICENVPROC)gleIntGetProcAddress("wglReleaseVideoDeviceNV");
	if(!wglReleaseVideoDeviceNV) bIsLoaded = 0;
	wglBindVideoImageNV = (PFNWGLBINDVIDEOIMAGENVPROC)gleIntGetProcAddress("wglBindVideoImageNV");
	if(!wglBindVideoImageNV) bIsLoaded = 0;
	wglReleaseVideoImageNV = (PFNWGLRELEASEVIDEOIMAGENVPROC)gleIntGetProcAddress("wglReleaseVideoImageNV");
	if(!wglReleaseVideoImageNV) bIsLoaded = 0;
	wglSendPbufferToVideoNV = (PFNWGLSENDPBUFFERTOVIDEONVPROC)gleIntGetProcAddress("wglSendPbufferToVideoNV");
	if(!wglSendPbufferToVideoNV) bIsLoaded = 0;
	wglGetVideoInfoNV = (PFNWGLGETVIDEOINFONVPROC)gleIntGetProcAddress("wglGetVideoInfoNV");
	if(!wglGetVideoInfoNV) bIsLoaded = 0;
#endif /*WGL_NV_video_output*/
	return bIsLoaded;
}
StrToExtMap wgleIntExtensionMap[] = {
	{"WGL_3DFX_multisample", &wglext_3DFX_multisample, NULL},
	{"WGL_3DL_stereo_control", &wglext_3DL_stereo_control, wgleIntLoad_3DL_stereo_control},
	{"WGL_AMD_gpu_association", &wglext_AMD_gpu_association, wgleIntLoad_AMD_gpu_association},
	{"WGL_ARB_buffer_region", &wglext_ARB_buffer_region, wgleIntLoad_ARB_buffer_region},
	{"WGL_ARB_create_context", &wglext_ARB_create_context, wgleIntLoad_ARB_create_context},
	{"WGL_ARB_create_context_profile", &wglext_ARB_create_context_profile, NULL},
	{"WGL_ARB_create_context_robustness", &wglext_ARB_create_context_robustness, NULL},
	{"WGL_ARB_extensions_string", &wglext_ARB_extensions_string, wgleIntLoad_ARB_extensions_string},
	{"WGL_ARB_framebuffer_sRGB", &wglext_ARB_framebuffer_sRGB, NULL},
	{"WGL_ARB_make_current_read", &wglext_ARB_make_current_read, wgleIntLoad_ARB_make_current_read},
	{"WGL_ARB_multisample", &wglext_ARB_multisample, NULL},
	{"WGL_ARB_pbuffer", &wglext_ARB_pbuffer, wgleIntLoad_ARB_pbuffer},
	{"WGL_ARB_pixel_format", &wglext_ARB_pixel_format, wgleIntLoad_ARB_pixel_format},
	{"WGL_ARB_pixel_format_float", &wglext_ARB_pixel_format_float, NULL},
	{"WGL_ARB_render_texture", &wglext_ARB_render_texture, wgleIntLoad_ARB_render_texture},
	{"WGL_ATI_pixel_format_float", &wglext_ATI_pixel_format_float, NULL},
	{"WGL_EXT_create_context_es2_profile", &wglext_EXT_create_context_es2_profile, NULL},
	{"WGL_EXT_depth_float", &wglext_EXT_depth_float, NULL},
	{"WGL_EXT_framebuffer_sRGB", &wglext_EXT_framebuffer_sRGB, NULL},
	{"WGL_EXT_make_current_read", &wglext_EXT_make_current_read, wgleIntLoad_EXT_make_current_read},
	{"WGL_EXT_multisample", &wglext_EXT_multisample, NULL},
	{"WGL_EXT_pbuffer", &wglext_EXT_pbuffer, wgleIntLoad_EXT_pbuffer},
	{"WGL_EXT_pixel_format", &wglext_EXT_pixel_format, wgleIntLoad_EXT_pixel_format},
	{"WGL_EXT_pixel_format_packed_float", &wglext_EXT_pixel_format_packed_float, NULL},
	{"WGL_EXT_swap_control", &wglext_EXT_swap_control, wgleIntLoad_EXT_swap_control},
	{"WGL_EXT_swap_control_tear", &wglext_EXT_swap_control_tear, NULL},
	{"WGL_I3D_digital_video_control", &wglext_I3D_digital_video_control, wgleIntLoad_I3D_digital_video_control},
	{"WGL_I3D_gamma", &wglext_I3D_gamma, wgleIntLoad_I3D_gamma},
	{"WGL_I3D_genlock", &wglext_I3D_genlock, wgleIntLoad_I3D_genlock},
	{"WGL_I3D_image_buffer", &wglext_I3D_image_buffer, wgleIntLoad_I3D_image_buffer},
	{"WGL_I3D_swap_frame_lock", &wglext_I3D_swap_frame_lock, wgleIntLoad_I3D_swap_frame_lock},
	{"WGL_NV_DX_interop", &wglext_NV_DX_interop, wgleIntLoad_NV_DX_interop},
	{"WGL_NV_DX_interop2", &wglext_NV_DX_interop2, NULL},
	{"WGL_NV_copy_image", &wglext_NV_copy_image, wgleIntLoad_NV_copy_image},
	{"WGL_NV_float_buffer", &wglext_NV_float_buffer, NULL},
	{"WGL_NV_gpu_affinity", &wglext_NV_gpu_affinity, wgleIntLoad_NV_gpu_affinity},
	{"WGL_NV_multisample_coverage", &wglext_NV_multisample_coverage, NULL},
	{"WGL_NV_present_video", &wglext_NV_present_video, wgleIntLoad_NV_present_video},
	{"WGL_NV_render_depth_texture", &wglext_NV_render_depth_texture, NULL},
	{"WGL_NV_render_texture_rectangle", &wglext_NV_render_texture_rectangle, NULL},
	{"WGL_NV_swap_group", &wglext_NV_swap_group, wgleIntLoad_NV_swap_group},
	{"WGL_NV_video_capture", &wglext_NV_video_capture, wgleIntLoad_NV_video_capture},
	{"WGL_NV_video_output", &wglext_NV_video_output, wgleIntLoad_NV_video_output},
};

int wgleIntExtensionMapSize = 43;



void wgleIntLoadBaseFuncs()
{
	int bIsLoaded = 1; //Unimportant here.
	wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC)gleIntGetProcAddress("wglGetExtensionsStringARB");
	if(!wglGetExtensionsStringARB) bIsLoaded = 0;
}
