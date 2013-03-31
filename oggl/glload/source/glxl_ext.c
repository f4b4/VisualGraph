#include <stdlib.h>
#include <string.h>
#include "glxl_ext.h"

#ifdef __glxext_h_
#error Attempt to include glx_exts after including glxext.h
#endif

#define __glxext_h_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#define GLE_FUNCPTR


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

#ifndef GLX_ARB_get_proc_address
typedef void (*__GLXextFuncPtr)(void);
#endif
#ifndef GLX_SGIX_video_source
typedef XID GLXVideoSourceSGIX;
#endif
#ifndef GLX_SGIX_fbconfig
typedef XID GLXFBConfigIDSGIX;
typedef struct __GLXFBConfigRec *GLXFBConfigSGIX;
#endif
#ifndef GLX_SGIX_pbuffer
typedef XID GLXPbufferSGIX;
typedef struct {
    int type;
    unsigned long serial;	  /* # of last request processed by server */
    Bool send_event;		  /* true if this came for SendEvent request */
    Display *display;		  /* display the event was read from */
    GLXDrawable drawable;	  /* i.d. of Drawable */
    int event_type;		  /* GLX_DAMAGED_SGIX or GLX_SAVED_SGIX */
    int draw_type;		  /* GLX_WINDOW_SGIX or GLX_PBUFFER_SGIX */
    unsigned int mask;	  /* mask indicating which buffers are affected*/
    int x, y;
    int width, height;
    int count;		  /* if nonzero, at least this many more */
} GLXBufferClobberEventSGIX;
#endif
#ifndef GLX_NV_video_output
typedef unsigned int GLXVideoDeviceNV;
#endif
#ifndef GLX_NV_video_capture
typedef XID GLXVideoCaptureDeviceNV;
#endif
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GLX_OML_sync_control extension). */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#elif defined(__sun__) || defined(__digital__)
#include <inttypes.h>
#if defined(__STDC__)
#if defined(__arch64__) || defined(_LP64)
typedef long int int64_t;
typedef unsigned long int uint64_t;
#else
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#endif /* __arch64__ */
#endif /* __STDC__ */
#elif defined( __VMS ) || defined(__sgi)
#include <inttypes.h>
#elif defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int int32_t;
typedef long long int int64_t;
typedef unsigned long long int uint64_t;
#elif defined(_WIN32) && defined(__GNUC__)
#include <stdint.h>
#elif defined(_WIN32)
typedef __int32 int32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <inttypes.h>     /* Fallback option */
#endif
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

int glXext_ARB_get_proc_address = 0;
int glXext_ARB_multisample = 0;
int glXext_ARB_vertex_buffer_object = 0;
int glXext_ARB_fbconfig_float = 0;
int glXext_ARB_framebuffer_sRGB = 0;
int glXext_ARB_create_context = 0;
int glXext_ARB_create_context_profile = 0;
int glXext_ARB_create_context_robustness = 0;
int glXext_SGIS_multisample = 0;
int glXext_EXT_visual_info = 0;
int glXext_SGI_swap_control = 0;
int glXext_SGI_video_sync = 0;
int glXext_SGI_make_current_read = 0;
int glXext_EXT_visual_rating = 0;
int glXext_EXT_import_context = 0;
int glXext_SGIX_fbconfig = 0;
int glXext_SGIX_pbuffer = 0;
int glXext_SGI_cushion = 0;
int glXext_SGIX_video_resize = 0;
int glXext_SGIX_swap_group = 0;
int glXext_SGIX_swap_barrier = 0;
int glXext_SGIS_blended_overlay = 0;
int glXext_SGIS_shared_multisample = 0;
int glXext_SUN_get_transparent_index = 0;
int glXext_3DFX_multisample = 0;
int glXext_MESA_copy_sub_buffer = 0;
int glXext_MESA_pixmap_colormap = 0;
int glXext_MESA_release_buffers = 0;
int glXext_MESA_set_3dfx_mode = 0;
int glXext_SGIX_visual_select_group = 0;
int glXext_OML_swap_method = 0;
int glXext_OML_sync_control = 0;
int glXext_NV_float_buffer = 0;
int glXext_MESA_agp_offset = 0;
int glXext_EXT_fbconfig_packed_float = 0;
int glXext_EXT_framebuffer_sRGB = 0;
int glXext_EXT_texture_from_pixmap = 0;
int glXext_NV_present_video = 0;
int glXext_NV_video_out = 0;
int glXext_NV_swap_group = 0;
int glXext_NV_video_capture = 0;
int glXext_EXT_swap_control = 0;
int glXext_NV_copy_image = 0;
int glXext_INTEL_swap_event = 0;
int glXext_NV_multisample_coverage = 0;
int glXext_AMD_gpu_association = 0;
int glXext_EXT_create_context_es2_profile = 0;
int glXext_EXT_swap_control_tear = 0;


void glXeIntClear()
{
	glXext_ARB_get_proc_address = 0;
	glXext_ARB_multisample = 0;
	glXext_ARB_vertex_buffer_object = 0;
	glXext_ARB_fbconfig_float = 0;
	glXext_ARB_framebuffer_sRGB = 0;
	glXext_ARB_create_context = 0;
	glXext_ARB_create_context_profile = 0;
	glXext_ARB_create_context_robustness = 0;
	glXext_SGIS_multisample = 0;
	glXext_EXT_visual_info = 0;
	glXext_SGI_swap_control = 0;
	glXext_SGI_video_sync = 0;
	glXext_SGI_make_current_read = 0;
	glXext_EXT_visual_rating = 0;
	glXext_EXT_import_context = 0;
	glXext_SGIX_fbconfig = 0;
	glXext_SGIX_pbuffer = 0;
	glXext_SGI_cushion = 0;
	glXext_SGIX_video_resize = 0;
	glXext_SGIX_swap_group = 0;
	glXext_SGIX_swap_barrier = 0;
	glXext_SGIS_blended_overlay = 0;
	glXext_SGIS_shared_multisample = 0;
	glXext_SUN_get_transparent_index = 0;
	glXext_3DFX_multisample = 0;
	glXext_MESA_copy_sub_buffer = 0;
	glXext_MESA_pixmap_colormap = 0;
	glXext_MESA_release_buffers = 0;
	glXext_MESA_set_3dfx_mode = 0;
	glXext_SGIX_visual_select_group = 0;
	glXext_OML_swap_method = 0;
	glXext_OML_sync_control = 0;
	glXext_NV_float_buffer = 0;
	glXext_MESA_agp_offset = 0;
	glXext_EXT_fbconfig_packed_float = 0;
	glXext_EXT_framebuffer_sRGB = 0;
	glXext_EXT_texture_from_pixmap = 0;
	glXext_NV_present_video = 0;
	glXext_NV_video_out = 0;
	glXext_NV_swap_group = 0;
	glXext_NV_video_capture = 0;
	glXext_EXT_swap_control = 0;
	glXext_NV_copy_image = 0;
	glXext_INTEL_swap_event = 0;
	glXext_NV_multisample_coverage = 0;
	glXext_AMD_gpu_association = 0;
	glXext_EXT_create_context_es2_profile = 0;
	glXext_EXT_swap_control_tear = 0;
}




#ifndef GLX_ARB_create_context
typedef GLXContext (GLE_FUNCPTR * PFNGLXCREATECONTEXTATTRIBSARBPROC)(Display *, GLXFBConfig , GLXContext , Bool , const int *);

PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB;
#endif /*GLX_ARB_create_context*/

static int glXeIntLoad_ARB_create_context()
{
	int bIsLoaded = 1;
#ifndef GLX_ARB_create_context
	glXCreateContextAttribsARB = (PFNGLXCREATECONTEXTATTRIBSARBPROC)gleIntGetProcAddress("glXCreateContextAttribsARB");
	if(!glXCreateContextAttribsARB) bIsLoaded = 0;
#endif /*GLX_ARB_create_context*/
	return bIsLoaded;
}




#ifndef GLX_ARB_get_proc_address
typedef __GLXextFuncPtr (GLE_FUNCPTR * PFNGLXGETPROCADDRESSARBPROC)(const GLubyte *);

PFNGLXGETPROCADDRESSARBPROC glXGetProcAddressARB;
#endif /*GLX_ARB_get_proc_address*/

static int glXeIntLoad_ARB_get_proc_address()
{
	int bIsLoaded = 1;
#ifndef GLX_ARB_get_proc_address
	glXGetProcAddressARB = (PFNGLXGETPROCADDRESSARBPROC)gleIntGetProcAddress("glXGetProcAddressARB");
	if(!glXGetProcAddressARB) bIsLoaded = 0;
#endif /*GLX_ARB_get_proc_address*/
	return bIsLoaded;
}





#ifndef GLX_EXT_import_context
typedef Display * (GLE_FUNCPTR * PFNGLXGETCURRENTDISPLAYEXTPROC)();
typedef int (GLE_FUNCPTR * PFNGLXQUERYCONTEXTINFOEXTPROC)(Display *, GLXContext , int , int *);
typedef GLXContextID (GLE_FUNCPTR * PFNGLXGETCONTEXTIDEXTPROC)(const GLXContext );
typedef GLXContext (GLE_FUNCPTR * PFNGLXIMPORTCONTEXTEXTPROC)(Display *, GLXContextID );
typedef void (GLE_FUNCPTR * PFNGLXFREECONTEXTEXTPROC)(Display *, GLXContext );

PFNGLXGETCURRENTDISPLAYEXTPROC glXGetCurrentDisplayEXT;
PFNGLXQUERYCONTEXTINFOEXTPROC glXQueryContextInfoEXT;
PFNGLXGETCONTEXTIDEXTPROC glXGetContextIDEXT;
PFNGLXIMPORTCONTEXTEXTPROC glXImportContextEXT;
PFNGLXFREECONTEXTEXTPROC glXFreeContextEXT;
#endif /*GLX_EXT_import_context*/

static int glXeIntLoad_EXT_import_context()
{
	int bIsLoaded = 1;
#ifndef GLX_EXT_import_context
	glXGetCurrentDisplayEXT = (PFNGLXGETCURRENTDISPLAYEXTPROC)gleIntGetProcAddress("glXGetCurrentDisplayEXT");
	if(!glXGetCurrentDisplayEXT) bIsLoaded = 0;
	glXQueryContextInfoEXT = (PFNGLXQUERYCONTEXTINFOEXTPROC)gleIntGetProcAddress("glXQueryContextInfoEXT");
	if(!glXQueryContextInfoEXT) bIsLoaded = 0;
	glXGetContextIDEXT = (PFNGLXGETCONTEXTIDEXTPROC)gleIntGetProcAddress("glXGetContextIDEXT");
	if(!glXGetContextIDEXT) bIsLoaded = 0;
	glXImportContextEXT = (PFNGLXIMPORTCONTEXTEXTPROC)gleIntGetProcAddress("glXImportContextEXT");
	if(!glXImportContextEXT) bIsLoaded = 0;
	glXFreeContextEXT = (PFNGLXFREECONTEXTEXTPROC)gleIntGetProcAddress("glXFreeContextEXT");
	if(!glXFreeContextEXT) bIsLoaded = 0;
#endif /*GLX_EXT_import_context*/
	return bIsLoaded;
}
#ifndef GLX_EXT_swap_control
typedef void (GLE_FUNCPTR * PFNGLXSWAPINTERVALEXTPROC)(Display *, GLXDrawable , int );

PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT;
#endif /*GLX_EXT_swap_control*/

static int glXeIntLoad_EXT_swap_control()
{
	int bIsLoaded = 1;
#ifndef GLX_EXT_swap_control
	glXSwapIntervalEXT = (PFNGLXSWAPINTERVALEXTPROC)gleIntGetProcAddress("glXSwapIntervalEXT");
	if(!glXSwapIntervalEXT) bIsLoaded = 0;
#endif /*GLX_EXT_swap_control*/
	return bIsLoaded;
}

#ifndef GLX_EXT_texture_from_pixmap
typedef void (GLE_FUNCPTR * PFNGLXBINDTEXIMAGEEXTPROC)(Display *, GLXDrawable , int , const int *);
typedef void (GLE_FUNCPTR * PFNGLXRELEASETEXIMAGEEXTPROC)(Display *, GLXDrawable , int );

PFNGLXBINDTEXIMAGEEXTPROC glXBindTexImageEXT;
PFNGLXRELEASETEXIMAGEEXTPROC glXReleaseTexImageEXT;
#endif /*GLX_EXT_texture_from_pixmap*/

static int glXeIntLoad_EXT_texture_from_pixmap()
{
	int bIsLoaded = 1;
#ifndef GLX_EXT_texture_from_pixmap
	glXBindTexImageEXT = (PFNGLXBINDTEXIMAGEEXTPROC)gleIntGetProcAddress("glXBindTexImageEXT");
	if(!glXBindTexImageEXT) bIsLoaded = 0;
	glXReleaseTexImageEXT = (PFNGLXRELEASETEXIMAGEEXTPROC)gleIntGetProcAddress("glXReleaseTexImageEXT");
	if(!glXReleaseTexImageEXT) bIsLoaded = 0;
#endif /*GLX_EXT_texture_from_pixmap*/
	return bIsLoaded;
}



#ifndef GLX_MESA_agp_offset
typedef unsigned int (GLE_FUNCPTR * PFNGLXGETAGPOFFSETMESAPROC)(const void *);

PFNGLXGETAGPOFFSETMESAPROC glXGetAGPOffsetMESA;
#endif /*GLX_MESA_agp_offset*/

static int glXeIntLoad_MESA_agp_offset()
{
	int bIsLoaded = 1;
#ifndef GLX_MESA_agp_offset
	glXGetAGPOffsetMESA = (PFNGLXGETAGPOFFSETMESAPROC)gleIntGetProcAddress("glXGetAGPOffsetMESA");
	if(!glXGetAGPOffsetMESA) bIsLoaded = 0;
#endif /*GLX_MESA_agp_offset*/
	return bIsLoaded;
}
#ifndef GLX_MESA_copy_sub_buffer
typedef void (GLE_FUNCPTR * PFNGLXCOPYSUBBUFFERMESAPROC)(Display *, GLXDrawable , int , int , int , int );

PFNGLXCOPYSUBBUFFERMESAPROC glXCopySubBufferMESA;
#endif /*GLX_MESA_copy_sub_buffer*/

static int glXeIntLoad_MESA_copy_sub_buffer()
{
	int bIsLoaded = 1;
#ifndef GLX_MESA_copy_sub_buffer
	glXCopySubBufferMESA = (PFNGLXCOPYSUBBUFFERMESAPROC)gleIntGetProcAddress("glXCopySubBufferMESA");
	if(!glXCopySubBufferMESA) bIsLoaded = 0;
#endif /*GLX_MESA_copy_sub_buffer*/
	return bIsLoaded;
}
#ifndef GLX_MESA_pixmap_colormap
typedef GLXPixmap (GLE_FUNCPTR * PFNGLXCREATEGLXPIXMAPMESAPROC)(Display *, XVisualInfo *, Pixmap , Colormap );

PFNGLXCREATEGLXPIXMAPMESAPROC glXCreateGLXPixmapMESA;
#endif /*GLX_MESA_pixmap_colormap*/

static int glXeIntLoad_MESA_pixmap_colormap()
{
	int bIsLoaded = 1;
#ifndef GLX_MESA_pixmap_colormap
	glXCreateGLXPixmapMESA = (PFNGLXCREATEGLXPIXMAPMESAPROC)gleIntGetProcAddress("glXCreateGLXPixmapMESA");
	if(!glXCreateGLXPixmapMESA) bIsLoaded = 0;
#endif /*GLX_MESA_pixmap_colormap*/
	return bIsLoaded;
}
#ifndef GLX_MESA_release_buffers
typedef Bool (GLE_FUNCPTR * PFNGLXRELEASEBUFFERSMESAPROC)(Display *, GLXDrawable );

PFNGLXRELEASEBUFFERSMESAPROC glXReleaseBuffersMESA;
#endif /*GLX_MESA_release_buffers*/

static int glXeIntLoad_MESA_release_buffers()
{
	int bIsLoaded = 1;
#ifndef GLX_MESA_release_buffers
	glXReleaseBuffersMESA = (PFNGLXRELEASEBUFFERSMESAPROC)gleIntGetProcAddress("glXReleaseBuffersMESA");
	if(!glXReleaseBuffersMESA) bIsLoaded = 0;
#endif /*GLX_MESA_release_buffers*/
	return bIsLoaded;
}
#ifndef GLX_MESA_set_3dfx_mode
typedef Bool (GLE_FUNCPTR * PFNGLXSET3DFXMODEMESAPROC)(int );

PFNGLXSET3DFXMODEMESAPROC glXSet3DfxModeMESA;
#endif /*GLX_MESA_set_3dfx_mode*/

static int glXeIntLoad_MESA_set_3dfx_mode()
{
	int bIsLoaded = 1;
#ifndef GLX_MESA_set_3dfx_mode
	glXSet3DfxModeMESA = (PFNGLXSET3DFXMODEMESAPROC)gleIntGetProcAddress("glXSet3DfxModeMESA");
	if(!glXSet3DfxModeMESA) bIsLoaded = 0;
#endif /*GLX_MESA_set_3dfx_mode*/
	return bIsLoaded;
}
#ifndef GLX_NV_copy_image
typedef void (GLE_FUNCPTR * PFNGLXCOPYIMAGESUBDATANVPROC)(Display *, GLXContext , GLuint , GLenum , GLint , GLint , GLint , GLint , GLXContext , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

PFNGLXCOPYIMAGESUBDATANVPROC glXCopyImageSubDataNV;
#endif /*GLX_NV_copy_image*/

static int glXeIntLoad_NV_copy_image()
{
	int bIsLoaded = 1;
#ifndef GLX_NV_copy_image
	glXCopyImageSubDataNV = (PFNGLXCOPYIMAGESUBDATANVPROC)gleIntGetProcAddress("glXCopyImageSubDataNV");
	if(!glXCopyImageSubDataNV) bIsLoaded = 0;
#endif /*GLX_NV_copy_image*/
	return bIsLoaded;
}


#ifndef GLX_NV_present_video
typedef unsigned int * (GLE_FUNCPTR * PFNGLXENUMERATEVIDEODEVICESNVPROC)(Display *, int , int *);
typedef int (GLE_FUNCPTR * PFNGLXBINDVIDEODEVICENVPROC)(Display *, unsigned int , unsigned int , const int *);

PFNGLXENUMERATEVIDEODEVICESNVPROC glXEnumerateVideoDevicesNV;
PFNGLXBINDVIDEODEVICENVPROC glXBindVideoDeviceNV;
#endif /*GLX_NV_present_video*/

static int glXeIntLoad_NV_present_video()
{
	int bIsLoaded = 1;
#ifndef GLX_NV_present_video
	glXEnumerateVideoDevicesNV = (PFNGLXENUMERATEVIDEODEVICESNVPROC)gleIntGetProcAddress("glXEnumerateVideoDevicesNV");
	if(!glXEnumerateVideoDevicesNV) bIsLoaded = 0;
	glXBindVideoDeviceNV = (PFNGLXBINDVIDEODEVICENVPROC)gleIntGetProcAddress("glXBindVideoDeviceNV");
	if(!glXBindVideoDeviceNV) bIsLoaded = 0;
#endif /*GLX_NV_present_video*/
	return bIsLoaded;
}
#ifndef GLX_NV_swap_group
typedef Bool (GLE_FUNCPTR * PFNGLXJOINSWAPGROUPNVPROC)(Display *, GLXDrawable , GLuint );
typedef Bool (GLE_FUNCPTR * PFNGLXBINDSWAPBARRIERNVPROC)(Display *, GLuint , GLuint );
typedef Bool (GLE_FUNCPTR * PFNGLXQUERYSWAPGROUPNVPROC)(Display *, GLXDrawable , GLuint *, GLuint *);
typedef Bool (GLE_FUNCPTR * PFNGLXQUERYMAXSWAPGROUPSNVPROC)(Display *, int , GLuint *, GLuint *);
typedef Bool (GLE_FUNCPTR * PFNGLXQUERYFRAMECOUNTNVPROC)(Display *, int , GLuint *);
typedef Bool (GLE_FUNCPTR * PFNGLXRESETFRAMECOUNTNVPROC)(Display *, int );

PFNGLXJOINSWAPGROUPNVPROC glXJoinSwapGroupNV;
PFNGLXBINDSWAPBARRIERNVPROC glXBindSwapBarrierNV;
PFNGLXQUERYSWAPGROUPNVPROC glXQuerySwapGroupNV;
PFNGLXQUERYMAXSWAPGROUPSNVPROC glXQueryMaxSwapGroupsNV;
PFNGLXQUERYFRAMECOUNTNVPROC glXQueryFrameCountNV;
PFNGLXRESETFRAMECOUNTNVPROC glXResetFrameCountNV;
#endif /*GLX_NV_swap_group*/

static int glXeIntLoad_NV_swap_group()
{
	int bIsLoaded = 1;
#ifndef GLX_NV_swap_group
	glXJoinSwapGroupNV = (PFNGLXJOINSWAPGROUPNVPROC)gleIntGetProcAddress("glXJoinSwapGroupNV");
	if(!glXJoinSwapGroupNV) bIsLoaded = 0;
	glXBindSwapBarrierNV = (PFNGLXBINDSWAPBARRIERNVPROC)gleIntGetProcAddress("glXBindSwapBarrierNV");
	if(!glXBindSwapBarrierNV) bIsLoaded = 0;
	glXQuerySwapGroupNV = (PFNGLXQUERYSWAPGROUPNVPROC)gleIntGetProcAddress("glXQuerySwapGroupNV");
	if(!glXQuerySwapGroupNV) bIsLoaded = 0;
	glXQueryMaxSwapGroupsNV = (PFNGLXQUERYMAXSWAPGROUPSNVPROC)gleIntGetProcAddress("glXQueryMaxSwapGroupsNV");
	if(!glXQueryMaxSwapGroupsNV) bIsLoaded = 0;
	glXQueryFrameCountNV = (PFNGLXQUERYFRAMECOUNTNVPROC)gleIntGetProcAddress("glXQueryFrameCountNV");
	if(!glXQueryFrameCountNV) bIsLoaded = 0;
	glXResetFrameCountNV = (PFNGLXRESETFRAMECOUNTNVPROC)gleIntGetProcAddress("glXResetFrameCountNV");
	if(!glXResetFrameCountNV) bIsLoaded = 0;
#endif /*GLX_NV_swap_group*/
	return bIsLoaded;
}
#ifndef GLX_NV_video_capture
typedef int (GLE_FUNCPTR * PFNGLXBINDVIDEOCAPTUREDEVICENVPROC)(Display *, unsigned int , GLXVideoCaptureDeviceNV );
typedef GLXVideoCaptureDeviceNV * (GLE_FUNCPTR * PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC)(Display *, int , int *);
typedef void (GLE_FUNCPTR * PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC)(Display *, GLXVideoCaptureDeviceNV );
typedef int (GLE_FUNCPTR * PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC)(Display *, GLXVideoCaptureDeviceNV , int , int *);
typedef void (GLE_FUNCPTR * PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC)(Display *, GLXVideoCaptureDeviceNV );

PFNGLXBINDVIDEOCAPTUREDEVICENVPROC glXBindVideoCaptureDeviceNV;
PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC glXEnumerateVideoCaptureDevicesNV;
PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC glXLockVideoCaptureDeviceNV;
PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC glXQueryVideoCaptureDeviceNV;
PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC glXReleaseVideoCaptureDeviceNV;
#endif /*GLX_NV_video_capture*/

static int glXeIntLoad_NV_video_capture()
{
	int bIsLoaded = 1;
#ifndef GLX_NV_video_capture
	glXBindVideoCaptureDeviceNV = (PFNGLXBINDVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("glXBindVideoCaptureDeviceNV");
	if(!glXBindVideoCaptureDeviceNV) bIsLoaded = 0;
	glXEnumerateVideoCaptureDevicesNV = (PFNGLXENUMERATEVIDEOCAPTUREDEVICESNVPROC)gleIntGetProcAddress("glXEnumerateVideoCaptureDevicesNV");
	if(!glXEnumerateVideoCaptureDevicesNV) bIsLoaded = 0;
	glXLockVideoCaptureDeviceNV = (PFNGLXLOCKVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("glXLockVideoCaptureDeviceNV");
	if(!glXLockVideoCaptureDeviceNV) bIsLoaded = 0;
	glXQueryVideoCaptureDeviceNV = (PFNGLXQUERYVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("glXQueryVideoCaptureDeviceNV");
	if(!glXQueryVideoCaptureDeviceNV) bIsLoaded = 0;
	glXReleaseVideoCaptureDeviceNV = (PFNGLXRELEASEVIDEOCAPTUREDEVICENVPROC)gleIntGetProcAddress("glXReleaseVideoCaptureDeviceNV");
	if(!glXReleaseVideoCaptureDeviceNV) bIsLoaded = 0;
#endif /*GLX_NV_video_capture*/
	return bIsLoaded;
}


#ifndef GLX_OML_sync_control
typedef Bool (GLE_FUNCPTR * PFNGLXGETSYNCVALUESOMLPROC)(Display *, GLXDrawable , int64_t *, int64_t *, int64_t *);
typedef Bool (GLE_FUNCPTR * PFNGLXGETMSCRATEOMLPROC)(Display *, GLXDrawable , int32_t *, int32_t *);
typedef int64_t (GLE_FUNCPTR * PFNGLXSWAPBUFFERSMSCOMLPROC)(Display *, GLXDrawable , int64_t , int64_t , int64_t );
typedef Bool (GLE_FUNCPTR * PFNGLXWAITFORMSCOMLPROC)(Display *, GLXDrawable , int64_t , int64_t , int64_t , int64_t *, int64_t *, int64_t *);
typedef Bool (GLE_FUNCPTR * PFNGLXWAITFORSBCOMLPROC)(Display *, GLXDrawable , int64_t , int64_t *, int64_t *, int64_t *);

PFNGLXGETSYNCVALUESOMLPROC glXGetSyncValuesOML;
PFNGLXGETMSCRATEOMLPROC glXGetMscRateOML;
PFNGLXSWAPBUFFERSMSCOMLPROC glXSwapBuffersMscOML;
PFNGLXWAITFORMSCOMLPROC glXWaitForMscOML;
PFNGLXWAITFORSBCOMLPROC glXWaitForSbcOML;
#endif /*GLX_OML_sync_control*/

static int glXeIntLoad_OML_sync_control()
{
	int bIsLoaded = 1;
#ifndef GLX_OML_sync_control
	glXGetSyncValuesOML = (PFNGLXGETSYNCVALUESOMLPROC)gleIntGetProcAddress("glXGetSyncValuesOML");
	if(!glXGetSyncValuesOML) bIsLoaded = 0;
	glXGetMscRateOML = (PFNGLXGETMSCRATEOMLPROC)gleIntGetProcAddress("glXGetMscRateOML");
	if(!glXGetMscRateOML) bIsLoaded = 0;
	glXSwapBuffersMscOML = (PFNGLXSWAPBUFFERSMSCOMLPROC)gleIntGetProcAddress("glXSwapBuffersMscOML");
	if(!glXSwapBuffersMscOML) bIsLoaded = 0;
	glXWaitForMscOML = (PFNGLXWAITFORMSCOMLPROC)gleIntGetProcAddress("glXWaitForMscOML");
	if(!glXWaitForMscOML) bIsLoaded = 0;
	glXWaitForSbcOML = (PFNGLXWAITFORSBCOMLPROC)gleIntGetProcAddress("glXWaitForSbcOML");
	if(!glXWaitForSbcOML) bIsLoaded = 0;
#endif /*GLX_OML_sync_control*/
	return bIsLoaded;
}



#ifndef GLX_SGIX_fbconfig
typedef int (GLE_FUNCPTR * PFNGLXGETFBCONFIGATTRIBSGIXPROC)(Display *, GLXFBConfigSGIX , int , int *);
typedef GLXFBConfigSGIX * (GLE_FUNCPTR * PFNGLXCHOOSEFBCONFIGSGIXPROC)(Display *, int , int *, int *);
typedef GLXPixmap (GLE_FUNCPTR * PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC)(Display *, GLXFBConfigSGIX , Pixmap );
typedef GLXContext (GLE_FUNCPTR * PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC)(Display *, GLXFBConfigSGIX , int , GLXContext , Bool );
typedef XVisualInfo * (GLE_FUNCPTR * PFNGLXGETVISUALFROMFBCONFIGSGIXPROC)(Display *, GLXFBConfigSGIX );
typedef GLXFBConfigSGIX (GLE_FUNCPTR * PFNGLXGETFBCONFIGFROMVISUALSGIXPROC)(Display *, XVisualInfo *);

PFNGLXGETFBCONFIGATTRIBSGIXPROC glXGetFBConfigAttribSGIX;
PFNGLXCHOOSEFBCONFIGSGIXPROC glXChooseFBConfigSGIX;
PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC glXCreateGLXPixmapWithConfigSGIX;
PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC glXCreateContextWithConfigSGIX;
PFNGLXGETVISUALFROMFBCONFIGSGIXPROC glXGetVisualFromFBConfigSGIX;
PFNGLXGETFBCONFIGFROMVISUALSGIXPROC glXGetFBConfigFromVisualSGIX;
#endif /*GLX_SGIX_fbconfig*/

static int glXeIntLoad_SGIX_fbconfig()
{
	int bIsLoaded = 1;
#ifndef GLX_SGIX_fbconfig
	glXGetFBConfigAttribSGIX = (PFNGLXGETFBCONFIGATTRIBSGIXPROC)gleIntGetProcAddress("glXGetFBConfigAttribSGIX");
	if(!glXGetFBConfigAttribSGIX) bIsLoaded = 0;
	glXChooseFBConfigSGIX = (PFNGLXCHOOSEFBCONFIGSGIXPROC)gleIntGetProcAddress("glXChooseFBConfigSGIX");
	if(!glXChooseFBConfigSGIX) bIsLoaded = 0;
	glXCreateGLXPixmapWithConfigSGIX = (PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC)gleIntGetProcAddress("glXCreateGLXPixmapWithConfigSGIX");
	if(!glXCreateGLXPixmapWithConfigSGIX) bIsLoaded = 0;
	glXCreateContextWithConfigSGIX = (PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC)gleIntGetProcAddress("glXCreateContextWithConfigSGIX");
	if(!glXCreateContextWithConfigSGIX) bIsLoaded = 0;
	glXGetVisualFromFBConfigSGIX = (PFNGLXGETVISUALFROMFBCONFIGSGIXPROC)gleIntGetProcAddress("glXGetVisualFromFBConfigSGIX");
	if(!glXGetVisualFromFBConfigSGIX) bIsLoaded = 0;
	glXGetFBConfigFromVisualSGIX = (PFNGLXGETFBCONFIGFROMVISUALSGIXPROC)gleIntGetProcAddress("glXGetFBConfigFromVisualSGIX");
	if(!glXGetFBConfigFromVisualSGIX) bIsLoaded = 0;
#endif /*GLX_SGIX_fbconfig*/
	return bIsLoaded;
}
#ifndef GLX_SGIX_pbuffer
typedef GLXPbufferSGIX (GLE_FUNCPTR * PFNGLXCREATEGLXPBUFFERSGIXPROC)(Display *, GLXFBConfigSGIX , unsigned int , unsigned int , int *);
typedef void (GLE_FUNCPTR * PFNGLXDESTROYGLXPBUFFERSGIXPROC)(Display *, GLXPbufferSGIX );
typedef int (GLE_FUNCPTR * PFNGLXQUERYGLXPBUFFERSGIXPROC)(Display *, GLXPbufferSGIX , int , unsigned int *);
typedef void (GLE_FUNCPTR * PFNGLXSELECTEVENTSGIXPROC)(Display *, GLXDrawable , unsigned long );
typedef void (GLE_FUNCPTR * PFNGLXGETSELECTEDEVENTSGIXPROC)(Display *, GLXDrawable , unsigned long *);

PFNGLXCREATEGLXPBUFFERSGIXPROC glXCreateGLXPbufferSGIX;
PFNGLXDESTROYGLXPBUFFERSGIXPROC glXDestroyGLXPbufferSGIX;
PFNGLXQUERYGLXPBUFFERSGIXPROC glXQueryGLXPbufferSGIX;
PFNGLXSELECTEVENTSGIXPROC glXSelectEventSGIX;
PFNGLXGETSELECTEDEVENTSGIXPROC glXGetSelectedEventSGIX;
#endif /*GLX_SGIX_pbuffer*/

static int glXeIntLoad_SGIX_pbuffer()
{
	int bIsLoaded = 1;
#ifndef GLX_SGIX_pbuffer
	glXCreateGLXPbufferSGIX = (PFNGLXCREATEGLXPBUFFERSGIXPROC)gleIntGetProcAddress("glXCreateGLXPbufferSGIX");
	if(!glXCreateGLXPbufferSGIX) bIsLoaded = 0;
	glXDestroyGLXPbufferSGIX = (PFNGLXDESTROYGLXPBUFFERSGIXPROC)gleIntGetProcAddress("glXDestroyGLXPbufferSGIX");
	if(!glXDestroyGLXPbufferSGIX) bIsLoaded = 0;
	glXQueryGLXPbufferSGIX = (PFNGLXQUERYGLXPBUFFERSGIXPROC)gleIntGetProcAddress("glXQueryGLXPbufferSGIX");
	if(!glXQueryGLXPbufferSGIX) bIsLoaded = 0;
	glXSelectEventSGIX = (PFNGLXSELECTEVENTSGIXPROC)gleIntGetProcAddress("glXSelectEventSGIX");
	if(!glXSelectEventSGIX) bIsLoaded = 0;
	glXGetSelectedEventSGIX = (PFNGLXGETSELECTEDEVENTSGIXPROC)gleIntGetProcAddress("glXGetSelectedEventSGIX");
	if(!glXGetSelectedEventSGIX) bIsLoaded = 0;
#endif /*GLX_SGIX_pbuffer*/
	return bIsLoaded;
}
#ifndef GLX_SGIX_swap_barrier
typedef void (GLE_FUNCPTR * PFNGLXBINDSWAPBARRIERSGIXPROC)(Display *, GLXDrawable , int );
typedef Bool (GLE_FUNCPTR * PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC)(Display *, int , int *);

PFNGLXBINDSWAPBARRIERSGIXPROC glXBindSwapBarrierSGIX;
PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC glXQueryMaxSwapBarriersSGIX;
#endif /*GLX_SGIX_swap_barrier*/

static int glXeIntLoad_SGIX_swap_barrier()
{
	int bIsLoaded = 1;
#ifndef GLX_SGIX_swap_barrier
	glXBindSwapBarrierSGIX = (PFNGLXBINDSWAPBARRIERSGIXPROC)gleIntGetProcAddress("glXBindSwapBarrierSGIX");
	if(!glXBindSwapBarrierSGIX) bIsLoaded = 0;
	glXQueryMaxSwapBarriersSGIX = (PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC)gleIntGetProcAddress("glXQueryMaxSwapBarriersSGIX");
	if(!glXQueryMaxSwapBarriersSGIX) bIsLoaded = 0;
#endif /*GLX_SGIX_swap_barrier*/
	return bIsLoaded;
}
#ifndef GLX_SGIX_swap_group
typedef void (GLE_FUNCPTR * PFNGLXJOINSWAPGROUPSGIXPROC)(Display *, GLXDrawable , GLXDrawable );

PFNGLXJOINSWAPGROUPSGIXPROC glXJoinSwapGroupSGIX;
#endif /*GLX_SGIX_swap_group*/

static int glXeIntLoad_SGIX_swap_group()
{
	int bIsLoaded = 1;
#ifndef GLX_SGIX_swap_group
	glXJoinSwapGroupSGIX = (PFNGLXJOINSWAPGROUPSGIXPROC)gleIntGetProcAddress("glXJoinSwapGroupSGIX");
	if(!glXJoinSwapGroupSGIX) bIsLoaded = 0;
#endif /*GLX_SGIX_swap_group*/
	return bIsLoaded;
}
#ifndef GLX_SGIX_video_resize
typedef int (GLE_FUNCPTR * PFNGLXBINDCHANNELTOWINDOWSGIXPROC)(Display *, int , int , Window );
typedef int (GLE_FUNCPTR * PFNGLXCHANNELRECTSGIXPROC)(Display *, int , int , int , int , int , int );
typedef int (GLE_FUNCPTR * PFNGLXQUERYCHANNELRECTSGIXPROC)(Display *, int , int , int *, int *, int *, int *);
typedef int (GLE_FUNCPTR * PFNGLXQUERYCHANNELDELTASSGIXPROC)(Display *, int , int , int *, int *, int *, int *);
typedef int (GLE_FUNCPTR * PFNGLXCHANNELRECTSYNCSGIXPROC)(Display *, int , int , GLenum );

PFNGLXBINDCHANNELTOWINDOWSGIXPROC glXBindChannelToWindowSGIX;
PFNGLXCHANNELRECTSGIXPROC glXChannelRectSGIX;
PFNGLXQUERYCHANNELRECTSGIXPROC glXQueryChannelRectSGIX;
PFNGLXQUERYCHANNELDELTASSGIXPROC glXQueryChannelDeltasSGIX;
PFNGLXCHANNELRECTSYNCSGIXPROC glXChannelRectSyncSGIX;
#endif /*GLX_SGIX_video_resize*/

static int glXeIntLoad_SGIX_video_resize()
{
	int bIsLoaded = 1;
#ifndef GLX_SGIX_video_resize
	glXBindChannelToWindowSGIX = (PFNGLXBINDCHANNELTOWINDOWSGIXPROC)gleIntGetProcAddress("glXBindChannelToWindowSGIX");
	if(!glXBindChannelToWindowSGIX) bIsLoaded = 0;
	glXChannelRectSGIX = (PFNGLXCHANNELRECTSGIXPROC)gleIntGetProcAddress("glXChannelRectSGIX");
	if(!glXChannelRectSGIX) bIsLoaded = 0;
	glXQueryChannelRectSGIX = (PFNGLXQUERYCHANNELRECTSGIXPROC)gleIntGetProcAddress("glXQueryChannelRectSGIX");
	if(!glXQueryChannelRectSGIX) bIsLoaded = 0;
	glXQueryChannelDeltasSGIX = (PFNGLXQUERYCHANNELDELTASSGIXPROC)gleIntGetProcAddress("glXQueryChannelDeltasSGIX");
	if(!glXQueryChannelDeltasSGIX) bIsLoaded = 0;
	glXChannelRectSyncSGIX = (PFNGLXCHANNELRECTSYNCSGIXPROC)gleIntGetProcAddress("glXChannelRectSyncSGIX");
	if(!glXChannelRectSyncSGIX) bIsLoaded = 0;
#endif /*GLX_SGIX_video_resize*/
	return bIsLoaded;
}

#ifndef GLX_SGI_cushion
typedef void (GLE_FUNCPTR * PFNGLXCUSHIONSGIPROC)(Display *, Window , float );

PFNGLXCUSHIONSGIPROC glXCushionSGI;
#endif /*GLX_SGI_cushion*/

static int glXeIntLoad_SGI_cushion()
{
	int bIsLoaded = 1;
#ifndef GLX_SGI_cushion
	glXCushionSGI = (PFNGLXCUSHIONSGIPROC)gleIntGetProcAddress("glXCushionSGI");
	if(!glXCushionSGI) bIsLoaded = 0;
#endif /*GLX_SGI_cushion*/
	return bIsLoaded;
}
#ifndef GLX_SGI_make_current_read
typedef Bool (GLE_FUNCPTR * PFNGLXMAKECURRENTREADSGIPROC)(Display *, GLXDrawable , GLXDrawable , GLXContext );
typedef GLXDrawable (GLE_FUNCPTR * PFNGLXGETCURRENTREADDRAWABLESGIPROC)();

PFNGLXMAKECURRENTREADSGIPROC glXMakeCurrentReadSGI;
PFNGLXGETCURRENTREADDRAWABLESGIPROC glXGetCurrentReadDrawableSGI;
#endif /*GLX_SGI_make_current_read*/

static int glXeIntLoad_SGI_make_current_read()
{
	int bIsLoaded = 1;
#ifndef GLX_SGI_make_current_read
	glXMakeCurrentReadSGI = (PFNGLXMAKECURRENTREADSGIPROC)gleIntGetProcAddress("glXMakeCurrentReadSGI");
	if(!glXMakeCurrentReadSGI) bIsLoaded = 0;
	glXGetCurrentReadDrawableSGI = (PFNGLXGETCURRENTREADDRAWABLESGIPROC)gleIntGetProcAddress("glXGetCurrentReadDrawableSGI");
	if(!glXGetCurrentReadDrawableSGI) bIsLoaded = 0;
#endif /*GLX_SGI_make_current_read*/
	return bIsLoaded;
}
#ifndef GLX_SGI_swap_control
typedef int (GLE_FUNCPTR * PFNGLXSWAPINTERVALSGIPROC)(int );

PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI;
#endif /*GLX_SGI_swap_control*/

static int glXeIntLoad_SGI_swap_control()
{
	int bIsLoaded = 1;
#ifndef GLX_SGI_swap_control
	glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)gleIntGetProcAddress("glXSwapIntervalSGI");
	if(!glXSwapIntervalSGI) bIsLoaded = 0;
#endif /*GLX_SGI_swap_control*/
	return bIsLoaded;
}
#ifndef GLX_SGI_video_sync
typedef int (GLE_FUNCPTR * PFNGLXGETVIDEOSYNCSGIPROC)(unsigned int *);
typedef int (GLE_FUNCPTR * PFNGLXWAITVIDEOSYNCSGIPROC)(int , int , unsigned int *);

PFNGLXGETVIDEOSYNCSGIPROC glXGetVideoSyncSGI;
PFNGLXWAITVIDEOSYNCSGIPROC glXWaitVideoSyncSGI;
#endif /*GLX_SGI_video_sync*/

static int glXeIntLoad_SGI_video_sync()
{
	int bIsLoaded = 1;
#ifndef GLX_SGI_video_sync
	glXGetVideoSyncSGI = (PFNGLXGETVIDEOSYNCSGIPROC)gleIntGetProcAddress("glXGetVideoSyncSGI");
	if(!glXGetVideoSyncSGI) bIsLoaded = 0;
	glXWaitVideoSyncSGI = (PFNGLXWAITVIDEOSYNCSGIPROC)gleIntGetProcAddress("glXWaitVideoSyncSGI");
	if(!glXWaitVideoSyncSGI) bIsLoaded = 0;
#endif /*GLX_SGI_video_sync*/
	return bIsLoaded;
}
#ifndef GLX_SUN_get_transparent_index
typedef Status (GLE_FUNCPTR * PFNGLXGETTRANSPARENTINDEXSUNPROC)(Display *, Window , Window , long *);

PFNGLXGETTRANSPARENTINDEXSUNPROC glXGetTransparentIndexSUN;
#endif /*GLX_SUN_get_transparent_index*/

static int glXeIntLoad_SUN_get_transparent_index()
{
	int bIsLoaded = 1;
#ifndef GLX_SUN_get_transparent_index
	glXGetTransparentIndexSUN = (PFNGLXGETTRANSPARENTINDEXSUNPROC)gleIntGetProcAddress("glXGetTransparentIndexSUN");
	if(!glXGetTransparentIndexSUN) bIsLoaded = 0;
#endif /*GLX_SUN_get_transparent_index*/
	return bIsLoaded;
}
StrToExtMap glXeIntExtensionMap[] = {
	{"GLX_3DFX_multisample", &glXext_3DFX_multisample, NULL},
	{"GLX_AMD_gpu_association", &glXext_AMD_gpu_association, NULL},
	{"GLX_ARB_create_context", &glXext_ARB_create_context, glXeIntLoad_ARB_create_context},
	{"GLX_ARB_create_context_profile", &glXext_ARB_create_context_profile, NULL},
	{"GLX_ARB_create_context_robustness", &glXext_ARB_create_context_robustness, NULL},
	{"GLX_ARB_fbconfig_float", &glXext_ARB_fbconfig_float, NULL},
	{"GLX_ARB_framebuffer_sRGB", &glXext_ARB_framebuffer_sRGB, NULL},
	{"GLX_ARB_get_proc_address", &glXext_ARB_get_proc_address, glXeIntLoad_ARB_get_proc_address},
	{"GLX_ARB_multisample", &glXext_ARB_multisample, NULL},
	{"GLX_ARB_vertex_buffer_object", &glXext_ARB_vertex_buffer_object, NULL},
	{"GLX_EXT_create_context_es2_profile", &glXext_EXT_create_context_es2_profile, NULL},
	{"GLX_EXT_fbconfig_packed_float", &glXext_EXT_fbconfig_packed_float, NULL},
	{"GLX_EXT_framebuffer_sRGB", &glXext_EXT_framebuffer_sRGB, NULL},
	{"GLX_EXT_import_context", &glXext_EXT_import_context, glXeIntLoad_EXT_import_context},
	{"GLX_EXT_swap_control", &glXext_EXT_swap_control, glXeIntLoad_EXT_swap_control},
	{"GLX_EXT_swap_control_tear", &glXext_EXT_swap_control_tear, NULL},
	{"GLX_EXT_texture_from_pixmap", &glXext_EXT_texture_from_pixmap, glXeIntLoad_EXT_texture_from_pixmap},
	{"GLX_EXT_visual_info", &glXext_EXT_visual_info, NULL},
	{"GLX_EXT_visual_rating", &glXext_EXT_visual_rating, NULL},
	{"GLX_INTEL_swap_event", &glXext_INTEL_swap_event, NULL},
	{"GLX_MESA_agp_offset", &glXext_MESA_agp_offset, glXeIntLoad_MESA_agp_offset},
	{"GLX_MESA_copy_sub_buffer", &glXext_MESA_copy_sub_buffer, glXeIntLoad_MESA_copy_sub_buffer},
	{"GLX_MESA_pixmap_colormap", &glXext_MESA_pixmap_colormap, glXeIntLoad_MESA_pixmap_colormap},
	{"GLX_MESA_release_buffers", &glXext_MESA_release_buffers, glXeIntLoad_MESA_release_buffers},
	{"GLX_MESA_set_3dfx_mode", &glXext_MESA_set_3dfx_mode, glXeIntLoad_MESA_set_3dfx_mode},
	{"GLX_NV_copy_image", &glXext_NV_copy_image, glXeIntLoad_NV_copy_image},
	{"GLX_NV_float_buffer", &glXext_NV_float_buffer, NULL},
	{"GLX_NV_multisample_coverage", &glXext_NV_multisample_coverage, NULL},
	{"GLX_NV_present_video", &glXext_NV_present_video, glXeIntLoad_NV_present_video},
	{"GLX_NV_swap_group", &glXext_NV_swap_group, glXeIntLoad_NV_swap_group},
	{"GLX_NV_video_capture", &glXext_NV_video_capture, glXeIntLoad_NV_video_capture},
	{"GLX_NV_video_out", &glXext_NV_video_out, NULL},
	{"GLX_OML_swap_method", &glXext_OML_swap_method, NULL},
	{"GLX_OML_sync_control", &glXext_OML_sync_control, glXeIntLoad_OML_sync_control},
	{"GLX_SGIS_blended_overlay", &glXext_SGIS_blended_overlay, NULL},
	{"GLX_SGIS_multisample", &glXext_SGIS_multisample, NULL},
	{"GLX_SGIS_shared_multisample", &glXext_SGIS_shared_multisample, NULL},
	{"GLX_SGIX_fbconfig", &glXext_SGIX_fbconfig, glXeIntLoad_SGIX_fbconfig},
	{"GLX_SGIX_pbuffer", &glXext_SGIX_pbuffer, glXeIntLoad_SGIX_pbuffer},
	{"GLX_SGIX_swap_barrier", &glXext_SGIX_swap_barrier, glXeIntLoad_SGIX_swap_barrier},
	{"GLX_SGIX_swap_group", &glXext_SGIX_swap_group, glXeIntLoad_SGIX_swap_group},
	{"GLX_SGIX_video_resize", &glXext_SGIX_video_resize, glXeIntLoad_SGIX_video_resize},
	{"GLX_SGIX_visual_select_group", &glXext_SGIX_visual_select_group, NULL},
	{"GLX_SGI_cushion", &glXext_SGI_cushion, glXeIntLoad_SGI_cushion},
	{"GLX_SGI_make_current_read", &glXext_SGI_make_current_read, glXeIntLoad_SGI_make_current_read},
	{"GLX_SGI_swap_control", &glXext_SGI_swap_control, glXeIntLoad_SGI_swap_control},
	{"GLX_SGI_video_sync", &glXext_SGI_video_sync, glXeIntLoad_SGI_video_sync},
	{"GLX_SUN_get_transparent_index", &glXext_SUN_get_transparent_index, glXeIntLoad_SUN_get_transparent_index},
};

int glXeIntExtensionMapSize = 48;



