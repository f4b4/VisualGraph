#ifndef WGL_EXTS_H
#define WGL_EXTS_H


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

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern int wglext_ARB_buffer_region;
extern int wglext_ARB_multisample;
extern int wglext_ARB_extensions_string;
extern int wglext_ARB_pixel_format;
extern int wglext_ARB_make_current_read;
extern int wglext_ARB_pbuffer;
extern int wglext_ARB_render_texture;
extern int wglext_ARB_pixel_format_float;
extern int wglext_ARB_framebuffer_sRGB;
extern int wglext_ARB_create_context;
extern int wglext_ARB_create_context_profile;
extern int wglext_ARB_create_context_robustness;
extern int wglext_EXT_make_current_read;
extern int wglext_EXT_pixel_format;
extern int wglext_EXT_pbuffer;
extern int wglext_EXT_swap_control;
extern int wglext_EXT_depth_float;
extern int wglext_3DFX_multisample;
extern int wglext_EXT_multisample;
extern int wglext_I3D_digital_video_control;
extern int wglext_I3D_gamma;
extern int wglext_I3D_genlock;
extern int wglext_I3D_image_buffer;
extern int wglext_I3D_swap_frame_lock;
extern int wglext_NV_render_depth_texture;
extern int wglext_NV_render_texture_rectangle;
extern int wglext_ATI_pixel_format_float;
extern int wglext_NV_float_buffer;
extern int wglext_3DL_stereo_control;
extern int wglext_EXT_pixel_format_packed_float;
extern int wglext_EXT_framebuffer_sRGB;
extern int wglext_NV_present_video;
extern int wglext_NV_video_output;
extern int wglext_NV_swap_group;
extern int wglext_NV_gpu_affinity;
extern int wglext_AMD_gpu_association;
extern int wglext_NV_video_capture;
extern int wglext_NV_copy_image;
extern int wglext_NV_multisample_coverage;
extern int wglext_EXT_create_context_es2_profile;
extern int wglext_NV_DX_interop;
extern int wglext_NV_DX_interop2;
extern int wglext_EXT_swap_control_tear;




/******************************
* Extension: WGL_3DFX_multisample
******************************/

#define WGL_SAMPLE_BUFFERS_3DFX 0x2060
#define WGL_SAMPLES_3DFX 0x2061


/******************************
* Extension: WGL_3DL_stereo_control
******************************/

#define WGL_STEREO_EMITTER_ENABLE_3DL 0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL 0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL 0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL 0x2058


#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1

typedef BOOL (GLE_FUNCPTR * PFNWGLSETSTEREOEMITTERSTATE3DLPROC)(HDC , UINT );

extern PFNWGLSETSTEREOEMITTERSTATE3DLPROC wglSetStereoEmitterState3DL;
#endif /*WGL_3DL_stereo_control*/

/******************************
* Extension: WGL_AMD_gpu_association
******************************/

#define WGL_GPU_VENDOR_AMD 0x1F00
#define WGL_GPU_RENDERER_STRING_AMD 0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD 0x21A2
#define WGL_GPU_RAM_AMD 0x21A3
#define WGL_GPU_CLOCK_AMD 0x21A4
#define WGL_GPU_NUM_PIPES_AMD 0x21A5
#define WGL_GPU_NUM_SIMD_AMD 0x21A6
#define WGL_GPU_NUM_RB_AMD 0x21A7
#define WGL_GPU_NUM_SPI_AMD 0x21A8


#ifndef WGL_AMD_gpu_association
#define WGL_AMD_gpu_association 1

typedef UINT (GLE_FUNCPTR * PFNWGLGETGPUIDSAMDPROC)(UINT , UINT *);
typedef INT (GLE_FUNCPTR * PFNWGLGETGPUINFOAMDPROC)(UINT , int , GLenum , UINT , void *);
typedef UINT (GLE_FUNCPTR * PFNWGLGETCONTEXTGPUIDAMDPROC)(HGLRC );
typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)(UINT );
typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)(UINT , HGLRC , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)(HGLRC );
typedef BOOL (GLE_FUNCPTR * PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)(HGLRC );
typedef HGLRC (GLE_FUNCPTR * PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)();
typedef VOID (GLE_FUNCPTR * PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)(HGLRC , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );

extern PFNWGLGETGPUIDSAMDPROC wglGetGPUIDsAMD;
extern PFNWGLGETGPUINFOAMDPROC wglGetGPUInfoAMD;
extern PFNWGLGETCONTEXTGPUIDAMDPROC wglGetContextGPUIDAMD;
extern PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC wglCreateAssociatedContextAMD;
extern PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC wglCreateAssociatedContextAttribsAMD;
extern PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC wglDeleteAssociatedContextAMD;
extern PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC wglMakeAssociatedContextCurrentAMD;
extern PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC wglGetCurrentAssociatedContextAMD;
extern PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC wglBlitContextFramebufferAMD;
#endif /*WGL_AMD_gpu_association*/

/******************************
* Extension: WGL_ARB_buffer_region
******************************/

#define WGL_FRONT_COLOR_BUFFER_BIT_ARB 0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB 0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB 0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB 0x00000008


#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1

typedef HANDLE (GLE_FUNCPTR * PFNWGLCREATEBUFFERREGIONARBPROC)(HDC , int , UINT );
typedef VOID (GLE_FUNCPTR * PFNWGLDELETEBUFFERREGIONARBPROC)(HANDLE );
typedef BOOL (GLE_FUNCPTR * PFNWGLSAVEBUFFERREGIONARBPROC)(HANDLE , int , int , int , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRESTOREBUFFERREGIONARBPROC)(HANDLE , int , int , int , int , int , int );

extern PFNWGLCREATEBUFFERREGIONARBPROC wglCreateBufferRegionARB;
extern PFNWGLDELETEBUFFERREGIONARBPROC wglDeleteBufferRegionARB;
extern PFNWGLSAVEBUFFERREGIONARBPROC wglSaveBufferRegionARB;
extern PFNWGLRESTOREBUFFERREGIONARBPROC wglRestoreBufferRegionARB;
#endif /*WGL_ARB_buffer_region*/

/******************************
* Extension: WGL_ARB_create_context
******************************/

#define WGL_CONTEXT_DEBUG_BIT_ARB 0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define WGL_ERROR_INVALID_VERSION_ARB 0x2095


#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1

typedef HGLRC (GLE_FUNCPTR * PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC , HGLRC , const int *);

extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
#endif /*WGL_ARB_create_context*/

/******************************
* Extension: WGL_ARB_create_context_profile
******************************/

#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define WGL_ERROR_INVALID_PROFILE_ARB 0x2096


/******************************
* Extension: WGL_ARB_create_context_robustness
******************************/

#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB 0x8261


/******************************
* Extension: WGL_ARB_extensions_string
******************************/

#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1

typedef const char * (GLE_FUNCPTR * PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC );

extern PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;
#endif /*WGL_ARB_extensions_string*/

/******************************
* Extension: WGL_ARB_framebuffer_sRGB
******************************/

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20A9


/******************************
* Extension: WGL_ARB_make_current_read
******************************/

#define WGL_ERROR_INVALID_PIXEL_TYPE_ARB 0x2043
#define WGL_ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054


#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1

typedef BOOL (GLE_FUNCPTR * PFNWGLMAKECONTEXTCURRENTARBPROC)(HDC , HDC , HGLRC );
typedef HDC (GLE_FUNCPTR * PFNWGLGETCURRENTREADDCARBPROC)();

extern PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB;
extern PFNWGLGETCURRENTREADDCARBPROC wglGetCurrentReadDCARB;
#endif /*WGL_ARB_make_current_read*/

/******************************
* Extension: WGL_ARB_multisample
******************************/

#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042


/******************************
* Extension: WGL_ARB_pbuffer
******************************/

#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_DRAW_TO_PBUFFER_ARB 0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB 0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB 0x2030
#define WGL_PBUFFER_LARGEST_ARB 0x2033
#define WGL_PBUFFER_WIDTH_ARB 0x2034
#define WGL_PBUFFER_HEIGHT_ARB 0x2035
#define WGL_PBUFFER_LOST_ARB 0x2036


#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1

typedef HPBUFFERARB (GLE_FUNCPTR * PFNWGLCREATEPBUFFERARBPROC)(HDC , int , int , int , const int *);
typedef HDC (GLE_FUNCPTR * PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB );
typedef int (GLE_FUNCPTR * PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB , HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB , int , int *);

extern PFNWGLCREATEPBUFFERARBPROC wglCreatePbufferARB;
extern PFNWGLGETPBUFFERDCARBPROC wglGetPbufferDCARB;
extern PFNWGLRELEASEPBUFFERDCARBPROC wglReleasePbufferDCARB;
extern PFNWGLDESTROYPBUFFERARBPROC wglDestroyPbufferARB;
extern PFNWGLQUERYPBUFFERARBPROC wglQueryPbufferARB;
#endif /*WGL_ARB_pbuffer*/

/******************************
* Extension: WGL_ARB_pixel_format
******************************/

#define WGL_NUMBER_PIXEL_FORMATS_ARB 0x2000
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_DRAW_TO_BITMAP_ARB 0x2002
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_NEED_PALETTE_ARB 0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB 0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB 0x2006
#define WGL_SWAP_METHOD_ARB 0x2007
#define WGL_NUMBER_OVERLAYS_ARB 0x2008
#define WGL_NUMBER_UNDERLAYS_ARB 0x2009
#define WGL_TRANSPARENT_ARB 0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB 0x200C
#define WGL_SHARE_STENCIL_ARB 0x200D
#define WGL_SHARE_ACCUM_ARB 0x200E
#define WGL_SUPPORT_GDI_ARB 0x200F
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_STEREO_ARB 0x2012
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_RED_BITS_ARB 0x2015
#define WGL_RED_SHIFT_ARB 0x2016
#define WGL_GREEN_BITS_ARB 0x2017
#define WGL_GREEN_SHIFT_ARB 0x2018
#define WGL_BLUE_BITS_ARB 0x2019
#define WGL_BLUE_SHIFT_ARB 0x201A
#define WGL_ALPHA_BITS_ARB 0x201B
#define WGL_ALPHA_SHIFT_ARB 0x201C
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_ACCUM_RED_BITS_ARB 0x201E
#define WGL_ACCUM_GREEN_BITS_ARB 0x201F
#define WGL_ACCUM_BLUE_BITS_ARB 0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB 0x2021
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_AUX_BUFFERS_ARB 0x2024
#define WGL_NO_ACCELERATION_ARB 0x2025
#define WGL_GENERIC_ACCELERATION_ARB 0x2026
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_SWAP_EXCHANGE_ARB 0x2028
#define WGL_SWAP_COPY_ARB 0x2029
#define WGL_SWAP_UNDEFINED_ARB 0x202A
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_TYPE_COLORINDEX_ARB 0x202C


#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1

typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC , int , int , UINT , const int *, int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC , int , int , UINT , const int *, FLOAT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC wglGetPixelFormatAttribivARB;
extern PFNWGLGETPIXELFORMATATTRIBFVARBPROC wglGetPixelFormatAttribfvARB;
extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
#endif /*WGL_ARB_pixel_format*/

/******************************
* Extension: WGL_ARB_pixel_format_float
******************************/

#define WGL_TYPE_RGBA_FLOAT_ARB 0x21A0


/******************************
* Extension: WGL_ARB_render_texture
******************************/

#define WGL_BIND_TO_TEXTURE_RGB_ARB 0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB 0x2071
#define WGL_TEXTURE_FORMAT_ARB 0x2072
#define WGL_TEXTURE_TARGET_ARB 0x2073
#define WGL_MIPMAP_TEXTURE_ARB 0x2074
#define WGL_TEXTURE_RGB_ARB 0x2075
#define WGL_TEXTURE_RGBA_ARB 0x2076
#define WGL_NO_TEXTURE_ARB 0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB 0x2078
#define WGL_TEXTURE_1D_ARB 0x2079
#define WGL_TEXTURE_2D_ARB 0x207A
#define WGL_MIPMAP_LEVEL_ARB 0x207B
#define WGL_CUBE_MAP_FACE_ARB 0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB 0x2083
#define WGL_FRONT_RIGHT_ARB 0x2084
#define WGL_BACK_LEFT_ARB 0x2085
#define WGL_BACK_RIGHT_ARB 0x2086
#define WGL_AUX0_ARB 0x2087
#define WGL_AUX1_ARB 0x2088
#define WGL_AUX2_ARB 0x2089
#define WGL_AUX3_ARB 0x208A
#define WGL_AUX4_ARB 0x208B
#define WGL_AUX5_ARB 0x208C
#define WGL_AUX6_ARB 0x208D
#define WGL_AUX7_ARB 0x208E
#define WGL_AUX8_ARB 0x208F
#define WGL_AUX9_ARB 0x2090


#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1

typedef BOOL (GLE_FUNCPTR * PFNWGLBINDTEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASETEXIMAGEARBPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLSETPBUFFERATTRIBARBPROC)(HPBUFFERARB , const int *);

extern PFNWGLBINDTEXIMAGEARBPROC wglBindTexImageARB;
extern PFNWGLRELEASETEXIMAGEARBPROC wglReleaseTexImageARB;
extern PFNWGLSETPBUFFERATTRIBARBPROC wglSetPbufferAttribARB;
#endif /*WGL_ARB_render_texture*/

/******************************
* Extension: WGL_ATI_pixel_format_float
******************************/

#define WGL_TYPE_RGBA_FLOAT_ATI 0x21A0


/******************************
* Extension: WGL_EXT_create_context_es2_profile
******************************/

#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004


/******************************
* Extension: WGL_EXT_depth_float
******************************/

#define WGL_DEPTH_FLOAT_EXT 0x2040


/******************************
* Extension: WGL_EXT_framebuffer_sRGB
******************************/

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20A9


/******************************
* Extension: WGL_EXT_make_current_read
******************************/

#define WGL_ERROR_INVALID_PIXEL_TYPE_EXT 0x2043


#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1

typedef BOOL (GLE_FUNCPTR * PFNWGLMAKECONTEXTCURRENTEXTPROC)(HDC , HDC , HGLRC );
typedef HDC (GLE_FUNCPTR * PFNWGLGETCURRENTREADDCEXTPROC)();

extern PFNWGLMAKECONTEXTCURRENTEXTPROC wglMakeContextCurrentEXT;
extern PFNWGLGETCURRENTREADDCEXTPROC wglGetCurrentReadDCEXT;
#endif /*WGL_EXT_make_current_read*/

/******************************
* Extension: WGL_EXT_multisample
******************************/

#define WGL_SAMPLE_BUFFERS_EXT 0x2041
#define WGL_SAMPLES_EXT 0x2042


/******************************
* Extension: WGL_EXT_pbuffer
******************************/

#define WGL_DRAW_TO_PBUFFER_EXT 0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT 0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT 0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT 0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT 0x2032
#define WGL_PBUFFER_LARGEST_EXT 0x2033
#define WGL_PBUFFER_WIDTH_EXT 0x2034
#define WGL_PBUFFER_HEIGHT_EXT 0x2035


#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1

typedef HPBUFFEREXT (GLE_FUNCPTR * PFNWGLCREATEPBUFFEREXTPROC)(HDC , int , int , int , const int *);
typedef HDC (GLE_FUNCPTR * PFNWGLGETPBUFFERDCEXTPROC)(HPBUFFEREXT );
typedef int (GLE_FUNCPTR * PFNWGLRELEASEPBUFFERDCEXTPROC)(HPBUFFEREXT , HDC );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYPBUFFEREXTPROC)(HPBUFFEREXT );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYPBUFFEREXTPROC)(HPBUFFEREXT , int , int *);

extern PFNWGLCREATEPBUFFEREXTPROC wglCreatePbufferEXT;
extern PFNWGLGETPBUFFERDCEXTPROC wglGetPbufferDCEXT;
extern PFNWGLRELEASEPBUFFERDCEXTPROC wglReleasePbufferDCEXT;
extern PFNWGLDESTROYPBUFFEREXTPROC wglDestroyPbufferEXT;
extern PFNWGLQUERYPBUFFEREXTPROC wglQueryPbufferEXT;
#endif /*WGL_EXT_pbuffer*/

/******************************
* Extension: WGL_EXT_pixel_format
******************************/

#define WGL_NUMBER_PIXEL_FORMATS_EXT 0x2000
#define WGL_DRAW_TO_WINDOW_EXT 0x2001
#define WGL_DRAW_TO_BITMAP_EXT 0x2002
#define WGL_ACCELERATION_EXT 0x2003
#define WGL_NEED_PALETTE_EXT 0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT 0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT 0x2006
#define WGL_SWAP_METHOD_EXT 0x2007
#define WGL_NUMBER_OVERLAYS_EXT 0x2008
#define WGL_NUMBER_UNDERLAYS_EXT 0x2009
#define WGL_TRANSPARENT_EXT 0x200A
#define WGL_TRANSPARENT_VALUE_EXT 0x200B
#define WGL_SHARE_DEPTH_EXT 0x200C
#define WGL_SHARE_STENCIL_EXT 0x200D
#define WGL_SHARE_ACCUM_EXT 0x200E
#define WGL_SUPPORT_GDI_EXT 0x200F
#define WGL_SUPPORT_OPENGL_EXT 0x2010
#define WGL_DOUBLE_BUFFER_EXT 0x2011
#define WGL_STEREO_EXT 0x2012
#define WGL_PIXEL_TYPE_EXT 0x2013
#define WGL_COLOR_BITS_EXT 0x2014
#define WGL_RED_BITS_EXT 0x2015
#define WGL_RED_SHIFT_EXT 0x2016
#define WGL_GREEN_BITS_EXT 0x2017
#define WGL_GREEN_SHIFT_EXT 0x2018
#define WGL_BLUE_BITS_EXT 0x2019
#define WGL_BLUE_SHIFT_EXT 0x201A
#define WGL_ALPHA_BITS_EXT 0x201B
#define WGL_ALPHA_SHIFT_EXT 0x201C
#define WGL_ACCUM_BITS_EXT 0x201D
#define WGL_ACCUM_RED_BITS_EXT 0x201E
#define WGL_ACCUM_GREEN_BITS_EXT 0x201F
#define WGL_ACCUM_BLUE_BITS_EXT 0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT 0x2021
#define WGL_DEPTH_BITS_EXT 0x2022
#define WGL_STENCIL_BITS_EXT 0x2023
#define WGL_AUX_BUFFERS_EXT 0x2024
#define WGL_NO_ACCELERATION_EXT 0x2025
#define WGL_GENERIC_ACCELERATION_EXT 0x2026
#define WGL_FULL_ACCELERATION_EXT 0x2027
#define WGL_SWAP_EXCHANGE_EXT 0x2028
#define WGL_SWAP_COPY_EXT 0x2029
#define WGL_SWAP_UNDEFINED_EXT 0x202A
#define WGL_TYPE_RGBA_EXT 0x202B
#define WGL_TYPE_COLORINDEX_EXT 0x202C


#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1

typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)(HDC , int , int , UINT , int *, int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)(HDC , int , int , UINT , int *, FLOAT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLCHOOSEPIXELFORMATEXTPROC)(HDC , const int *, const FLOAT *, UINT , int *, UINT *);

extern PFNWGLGETPIXELFORMATATTRIBIVEXTPROC wglGetPixelFormatAttribivEXT;
extern PFNWGLGETPIXELFORMATATTRIBFVEXTPROC wglGetPixelFormatAttribfvEXT;
extern PFNWGLCHOOSEPIXELFORMATEXTPROC wglChoosePixelFormatEXT;
#endif /*WGL_EXT_pixel_format*/

/******************************
* Extension: WGL_EXT_pixel_format_packed_float
******************************/

#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT 0x20A8


/******************************
* Extension: WGL_EXT_swap_control
******************************/

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1

typedef BOOL (GLE_FUNCPTR * PFNWGLSWAPINTERVALEXTPROC)(int );
typedef int (GLE_FUNCPTR * PFNWGLGETSWAPINTERVALEXTPROC)();

extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
extern PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;
#endif /*WGL_EXT_swap_control*/

/******************************
* Extension: WGL_EXT_swap_control_tear
******************************/

/******************************
* Extension: WGL_I3D_digital_video_control
******************************/

#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053


#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1

typedef BOOL (GLE_FUNCPTR * PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)(HDC , int , const int *);

extern PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC wglGetDigitalVideoParametersI3D;
extern PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC wglSetDigitalVideoParametersI3D;
#endif /*WGL_I3D_digital_video_control*/

/******************************
* Extension: WGL_I3D_gamma
******************************/

#define WGL_GAMMA_TABLE_SIZE_I3D 0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D 0x204F


#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1

typedef BOOL (GLE_FUNCPTR * PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)(HDC , int , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLGETGAMMATABLEI3DPROC)(HDC , int , USHORT *, USHORT *, USHORT *);
typedef BOOL (GLE_FUNCPTR * PFNWGLSETGAMMATABLEI3DPROC)(HDC , int , const USHORT *, const USHORT *, const USHORT *);

extern PFNWGLGETGAMMATABLEPARAMETERSI3DPROC wglGetGammaTableParametersI3D;
extern PFNWGLSETGAMMATABLEPARAMETERSI3DPROC wglSetGammaTableParametersI3D;
extern PFNWGLGETGAMMATABLEI3DPROC wglGetGammaTableI3D;
extern PFNWGLSETGAMMATABLEI3DPROC wglSetGammaTableI3D;
#endif /*WGL_I3D_gamma*/

/******************************
* Extension: WGL_I3D_genlock
******************************/

#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D 0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D 0x204C


#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1

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

extern PFNWGLENABLEGENLOCKI3DPROC wglEnableGenlockI3D;
extern PFNWGLDISABLEGENLOCKI3DPROC wglDisableGenlockI3D;
extern PFNWGLISENABLEDGENLOCKI3DPROC wglIsEnabledGenlockI3D;
extern PFNWGLGENLOCKSOURCEI3DPROC wglGenlockSourceI3D;
extern PFNWGLGETGENLOCKSOURCEI3DPROC wglGetGenlockSourceI3D;
extern PFNWGLGENLOCKSOURCEEDGEI3DPROC wglGenlockSourceEdgeI3D;
extern PFNWGLGETGENLOCKSOURCEEDGEI3DPROC wglGetGenlockSourceEdgeI3D;
extern PFNWGLGENLOCKSAMPLERATEI3DPROC wglGenlockSampleRateI3D;
extern PFNWGLGETGENLOCKSAMPLERATEI3DPROC wglGetGenlockSampleRateI3D;
extern PFNWGLGENLOCKSOURCEDELAYI3DPROC wglGenlockSourceDelayI3D;
extern PFNWGLGETGENLOCKSOURCEDELAYI3DPROC wglGetGenlockSourceDelayI3D;
extern PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC wglQueryGenlockMaxSourceDelayI3D;
#endif /*WGL_I3D_genlock*/

/******************************
* Extension: WGL_I3D_image_buffer
******************************/

#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D 0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D 0x00000002


#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1

typedef LPVOID (GLE_FUNCPTR * PFNWGLCREATEIMAGEBUFFERI3DPROC)(HDC , DWORD , UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLDESTROYIMAGEBUFFERI3DPROC)(HDC , LPVOID );
typedef BOOL (GLE_FUNCPTR * PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)(HDC , const HANDLE *, const LPVOID *, const DWORD *, UINT );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)(HDC , const LPVOID *, UINT );

extern PFNWGLCREATEIMAGEBUFFERI3DPROC wglCreateImageBufferI3D;
extern PFNWGLDESTROYIMAGEBUFFERI3DPROC wglDestroyImageBufferI3D;
extern PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC wglAssociateImageBufferEventsI3D;
extern PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC wglReleaseImageBufferEventsI3D;
#endif /*WGL_I3D_image_buffer*/

/******************************
* Extension: WGL_I3D_swap_frame_lock
******************************/

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1

typedef BOOL (GLE_FUNCPTR * PFNWGLENABLEFRAMELOCKI3DPROC)();
typedef BOOL (GLE_FUNCPTR * PFNWGLDISABLEFRAMELOCKI3DPROC)();
typedef BOOL (GLE_FUNCPTR * PFNWGLISENABLEDFRAMELOCKI3DPROC)(BOOL *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYFRAMELOCKMASTERI3DPROC)(BOOL *);

extern PFNWGLENABLEFRAMELOCKI3DPROC wglEnableFrameLockI3D;
extern PFNWGLDISABLEFRAMELOCKI3DPROC wglDisableFrameLockI3D;
extern PFNWGLISENABLEDFRAMELOCKI3DPROC wglIsEnabledFrameLockI3D;
extern PFNWGLQUERYFRAMELOCKMASTERI3DPROC wglQueryFrameLockMasterI3D;
#endif /*WGL_I3D_swap_frame_lock*/

/******************************
* Extension: WGL_NV_DX_interop
******************************/

#define WGL_ACCESS_READ_ONLY_NV 0x00000000
#define WGL_ACCESS_READ_WRITE_NV 0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV 0x00000002


#ifndef WGL_NV_DX_interop
#define WGL_NV_DX_interop 1

typedef BOOL (GLE_FUNCPTR * PFNWGLDXSETRESOURCESHAREHANDLENVPROC)(void *, HANDLE );
typedef HANDLE (GLE_FUNCPTR * PFNWGLDXOPENDEVICENVPROC)(void *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDXCLOSEDEVICENVPROC)(HANDLE );
typedef HANDLE (GLE_FUNCPTR * PFNWGLDXREGISTEROBJECTNVPROC)(HANDLE , void *, GLuint , GLenum , GLenum );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXUNREGISTEROBJECTNVPROC)(HANDLE , HANDLE );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXOBJECTACCESSNVPROC)(HANDLE , GLenum );
typedef BOOL (GLE_FUNCPTR * PFNWGLDXLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDXUNLOCKOBJECTSNVPROC)(HANDLE , GLint , HANDLE *);

extern PFNWGLDXSETRESOURCESHAREHANDLENVPROC wglDXSetResourceShareHandleNV;
extern PFNWGLDXOPENDEVICENVPROC wglDXOpenDeviceNV;
extern PFNWGLDXCLOSEDEVICENVPROC wglDXCloseDeviceNV;
extern PFNWGLDXREGISTEROBJECTNVPROC wglDXRegisterObjectNV;
extern PFNWGLDXUNREGISTEROBJECTNVPROC wglDXUnregisterObjectNV;
extern PFNWGLDXOBJECTACCESSNVPROC wglDXObjectAccessNV;
extern PFNWGLDXLOCKOBJECTSNVPROC wglDXLockObjectsNV;
extern PFNWGLDXUNLOCKOBJECTSNVPROC wglDXUnlockObjectsNV;
#endif /*WGL_NV_DX_interop*/

/******************************
* Extension: WGL_NV_DX_interop2
******************************/

/******************************
* Extension: WGL_NV_copy_image
******************************/

#ifndef WGL_NV_copy_image
#define WGL_NV_copy_image 1

typedef BOOL (GLE_FUNCPTR * PFNWGLCOPYIMAGESUBDATANVPROC)(HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , HGLRC , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

extern PFNWGLCOPYIMAGESUBDATANVPROC wglCopyImageSubDataNV;
#endif /*WGL_NV_copy_image*/

/******************************
* Extension: WGL_NV_float_buffer
******************************/

#define WGL_FLOAT_COMPONENTS_NV 0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV 0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV 0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV 0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV 0x20B8


/******************************
* Extension: WGL_NV_gpu_affinity
******************************/

#define WGL_ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define WGL_ERROR_MISSING_AFFINITY_MASK_NV 0x20D1


#ifndef WGL_NV_gpu_affinity
#define WGL_NV_gpu_affinity 1

typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUSNVPROC)(UINT , HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUDEVICESNVPROC)(HGPUNV , UINT , PGPU_DEVICE );
typedef HDC (GLE_FUNCPTR * PFNWGLCREATEAFFINITYDCNVPROC)(const HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)(HDC , UINT , HGPUNV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLDELETEDCNVPROC)(HDC );

extern PFNWGLENUMGPUSNVPROC wglEnumGpusNV;
extern PFNWGLENUMGPUDEVICESNVPROC wglEnumGpuDevicesNV;
extern PFNWGLCREATEAFFINITYDCNVPROC wglCreateAffinityDCNV;
extern PFNWGLENUMGPUSFROMAFFINITYDCNVPROC wglEnumGpusFromAffinityDCNV;
extern PFNWGLDELETEDCNVPROC wglDeleteDCNV;
#endif /*WGL_NV_gpu_affinity*/

/******************************
* Extension: WGL_NV_multisample_coverage
******************************/

#define WGL_COVERAGE_SAMPLES_NV 0x2042
#define WGL_COLOR_SAMPLES_NV 0x20B9


/******************************
* Extension: WGL_NV_present_video
******************************/

#define WGL_NUM_VIDEO_SLOTS_NV 0x20F0


#ifndef WGL_NV_present_video
#define WGL_NV_present_video 1

typedef int (GLE_FUNCPTR * PFNWGLENUMERATEVIDEODEVICESNVPROC)(HDC , HVIDEOOUTPUTDEVICENV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEODEVICENVPROC)(HDC , unsigned int , HVIDEOOUTPUTDEVICENV , const int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYCURRENTCONTEXTNVPROC)(int , int *);

extern PFNWGLENUMERATEVIDEODEVICESNVPROC wglEnumerateVideoDevicesNV;
extern PFNWGLBINDVIDEODEVICENVPROC wglBindVideoDeviceNV;
extern PFNWGLQUERYCURRENTCONTEXTNVPROC wglQueryCurrentContextNV;
#endif /*WGL_NV_present_video*/

/******************************
* Extension: WGL_NV_render_depth_texture
******************************/

#define WGL_BIND_TO_TEXTURE_DEPTH_NV 0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV 0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV 0x20A6
#define WGL_DEPTH_COMPONENT_NV 0x20A7


/******************************
* Extension: WGL_NV_render_texture_rectangle
******************************/

#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV 0x20A2


/******************************
* Extension: WGL_NV_swap_group
******************************/

#ifndef WGL_NV_swap_group
#define WGL_NV_swap_group 1

typedef BOOL (GLE_FUNCPTR * PFNWGLJOINSWAPGROUPNVPROC)(HDC , GLuint );
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDSWAPBARRIERNVPROC)(GLuint , GLuint );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYSWAPGROUPNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYMAXSWAPGROUPSNVPROC)(HDC , GLuint *, GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYFRAMECOUNTNVPROC)(HDC , GLuint *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRESETFRAMECOUNTNVPROC)(HDC );

extern PFNWGLJOINSWAPGROUPNVPROC wglJoinSwapGroupNV;
extern PFNWGLBINDSWAPBARRIERNVPROC wglBindSwapBarrierNV;
extern PFNWGLQUERYSWAPGROUPNVPROC wglQuerySwapGroupNV;
extern PFNWGLQUERYMAXSWAPGROUPSNVPROC wglQueryMaxSwapGroupsNV;
extern PFNWGLQUERYFRAMECOUNTNVPROC wglQueryFrameCountNV;
extern PFNWGLRESETFRAMECOUNTNVPROC wglResetFrameCountNV;
#endif /*WGL_NV_swap_group*/

/******************************
* Extension: WGL_NV_video_capture
******************************/

#define WGL_UNIQUE_ID_NV 0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV 0x20CF


#ifndef WGL_NV_video_capture
#define WGL_NV_video_capture 1

typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)(UINT , HVIDEOINPUTDEVICENV );
typedef UINT (GLE_FUNCPTR * PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)(HDC , HVIDEOINPUTDEVICENV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );
typedef BOOL (GLE_FUNCPTR * PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV , int , int *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)(HDC , HVIDEOINPUTDEVICENV );

extern PFNWGLBINDVIDEOCAPTUREDEVICENVPROC wglBindVideoCaptureDeviceNV;
extern PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC wglEnumerateVideoCaptureDevicesNV;
extern PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC wglLockVideoCaptureDeviceNV;
extern PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC wglQueryVideoCaptureDeviceNV;
extern PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC wglReleaseVideoCaptureDeviceNV;
#endif /*WGL_NV_video_capture*/

/******************************
* Extension: WGL_NV_video_output
******************************/

#define WGL_BIND_TO_VIDEO_RGB_NV 0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV 0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV 0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV 0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV 0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV 0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV 0x20C7
#define WGL_VIDEO_OUT_FRAME 0x20C8
#define WGL_VIDEO_OUT_FIELD_1 0x20C9
#define WGL_VIDEO_OUT_FIELD_2 0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2 0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1 0x20CC


#ifndef WGL_NV_video_output
#define WGL_NV_video_output 1

typedef BOOL (GLE_FUNCPTR * PFNWGLGETVIDEODEVICENVPROC)(HDC , int , HPVIDEODEV *);
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEODEVICENVPROC)(HPVIDEODEV );
typedef BOOL (GLE_FUNCPTR * PFNWGLBINDVIDEOIMAGENVPROC)(HPVIDEODEV , HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLRELEASEVIDEOIMAGENVPROC)(HPBUFFERARB , int );
typedef BOOL (GLE_FUNCPTR * PFNWGLSENDPBUFFERTOVIDEONVPROC)(HPBUFFERARB , int , unsigned long *, BOOL );
typedef BOOL (GLE_FUNCPTR * PFNWGLGETVIDEOINFONVPROC)(HPVIDEODEV , unsigned long *, unsigned long *);

extern PFNWGLGETVIDEODEVICENVPROC wglGetVideoDeviceNV;
extern PFNWGLRELEASEVIDEODEVICENVPROC wglReleaseVideoDeviceNV;
extern PFNWGLBINDVIDEOIMAGENVPROC wglBindVideoImageNV;
extern PFNWGLRELEASEVIDEOIMAGENVPROC wglReleaseVideoImageNV;
extern PFNWGLSENDPBUFFERTOVIDEONVPROC wglSendPbufferToVideoNV;
extern PFNWGLGETVIDEOINFONVPROC wglGetVideoInfoNV;
#endif /*WGL_NV_video_output*/

#ifdef __cplusplus
}
#endif //__cplusplus


#endif //WGL_EXTS_H

