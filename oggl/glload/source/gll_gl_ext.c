#include <stdlib.h>
#include <string.h>
#include "gll_gl_ext.h"

#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include gle after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include gle after including glext.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include gle after including glATI.h
#endif

#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gl_ATI_h_



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

#ifndef APIENTRY
	#if defined(__MINGW32__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#else
		#define APIENTRY
	#endif
#endif //APIENTRY

#ifndef GLE_FUNCPTR
	#define GLE_REMOVE_FUNCPTR
	#if defined(_WIN32)
		#define GLE_FUNCPTR APIENTRY
	#else
		#define GLE_FUNCPTR
	#endif
#endif //GLE_FUNCPTR

#ifndef GLAPI
	#define GLAPI extern
#endif

#include <stddef.h>	
	
static int TestPointer(const void *pTest)
{
	ptrdiff_t iTest;
	if(!pTest) return 0;
	iTest = (ptrdiff_t)pTest;
	
	if(iTest == 1 || iTest == 2 || iTest == 3 || iTest == -1) return 0;
	
	return 1;
}

#include <stddef.h>
#ifndef GL_VERSION_2_0
/* GL type for program/shader text */
typedef char GLchar;
#endif
#ifndef GL_VERSION_1_5
/* GL types for handling large vertex buffer objects */
typedef ptrdiff_t GLintptr;
typedef ptrdiff_t GLsizeiptr;
#endif
#ifndef GL_ARB_vertex_buffer_object
/* GL types for handling large vertex buffer objects */
typedef ptrdiff_t GLintptrARB;
typedef ptrdiff_t GLsizeiptrARB;
#endif
#ifndef GL_ARB_shader_objects
/* GL types for program/shader text and shader object handles */
typedef char GLcharARB;
typedef unsigned int GLhandleARB;
#endif
/* GL type for "half" precision (s10e5) float data in host memory */
#ifndef GL_ARB_half_float_pixel
typedef unsigned short GLhalfARB;
#endif
#ifndef GL_NV_half_float
typedef unsigned short GLhalfNV;
#endif
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
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
/* Fallback if nothing above works */
#include <inttypes.h>
#endif
#endif
#ifndef GL_EXT_timer_query
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64EXT;
#endif
#ifndef GL_ARB_sync
typedef int64_t GLint64;
typedef uint64_t GLuint64;
typedef struct __GLsync *GLsync;
#endif
#ifndef GL_ARB_cl_event
/* These incomplete types let us declare types compatible with OpenCL's cl_context and cl_event */
struct _cl_context;
struct _cl_event;
#endif
#ifndef GL_ARB_debug_output
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_AMD_debug_output
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_KHR_debug
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_NV_vdpau_interop
typedef GLintptr GLvdpauSurfaceNV;
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

int glext_ARB_imaging = 0;
int glext_ARB_multitexture = 0;
int glext_ARB_transpose_matrix = 0;
int glext_ARB_multisample = 0;
int glext_ARB_texture_env_add = 0;
int glext_ARB_texture_cube_map = 0;
int glext_ARB_texture_compression = 0;
int glext_ARB_texture_border_clamp = 0;
int glext_ARB_point_parameters = 0;
int glext_ARB_vertex_blend = 0;
int glext_ARB_matrix_palette = 0;
int glext_ARB_texture_env_combine = 0;
int glext_ARB_texture_env_crossbar = 0;
int glext_ARB_texture_env_dot3 = 0;
int glext_ARB_texture_mirrored_repeat = 0;
int glext_ARB_depth_texture = 0;
int glext_ARB_shadow = 0;
int glext_ARB_shadow_ambient = 0;
int glext_ARB_window_pos = 0;
int glext_ARB_vertex_program = 0;
int glext_ARB_fragment_program = 0;
int glext_ARB_vertex_buffer_object = 0;
int glext_ARB_occlusion_query = 0;
int glext_ARB_shader_objects = 0;
int glext_ARB_vertex_shader = 0;
int glext_ARB_fragment_shader = 0;
int glext_ARB_shading_language_100 = 0;
int glext_ARB_texture_non_power_of_two = 0;
int glext_ARB_point_sprite = 0;
int glext_ARB_fragment_program_shadow = 0;
int glext_ARB_draw_buffers = 0;
int glext_ARB_texture_rectangle = 0;
int glext_ARB_color_buffer_float = 0;
int glext_ARB_half_float_pixel = 0;
int glext_ARB_texture_float = 0;
int glext_ARB_pixel_buffer_object = 0;
int glext_ARB_depth_buffer_float = 0;
int glext_ARB_draw_instanced = 0;
int glext_ARB_framebuffer_object = 0;
int glext_ARB_framebuffer_sRGB = 0;
int glext_ARB_geometry_shader4 = 0;
int glext_ARB_half_float_vertex = 0;
int glext_ARB_instanced_arrays = 0;
int glext_ARB_map_buffer_range = 0;
int glext_ARB_texture_buffer_object = 0;
int glext_ARB_texture_compression_rgtc = 0;
int glext_ARB_texture_rg = 0;
int glext_ARB_vertex_array_object = 0;
int glext_ARB_uniform_buffer_object = 0;
int glext_ARB_compatibility = 0;
int glext_ARB_copy_buffer = 0;
int glext_ARB_shader_texture_lod = 0;
int glext_ARB_depth_clamp = 0;
int glext_ARB_draw_elements_base_vertex = 0;
int glext_ARB_fragment_coord_conventions = 0;
int glext_ARB_provoking_vertex = 0;
int glext_ARB_seamless_cube_map = 0;
int glext_ARB_sync = 0;
int glext_ARB_texture_multisample = 0;
int glext_ARB_vertex_array_bgra = 0;
int glext_ARB_draw_buffers_blend = 0;
int glext_ARB_sample_shading = 0;
int glext_ARB_texture_cube_map_array = 0;
int glext_ARB_texture_gather = 0;
int glext_ARB_texture_query_lod = 0;
int glext_ARB_shading_language_include = 0;
int glext_ARB_texture_compression_bptc = 0;
int glext_ARB_blend_func_extended = 0;
int glext_ARB_explicit_attrib_location = 0;
int glext_ARB_occlusion_query2 = 0;
int glext_ARB_sampler_objects = 0;
int glext_ARB_shader_bit_encoding = 0;
int glext_ARB_texture_rgb10_a2ui = 0;
int glext_ARB_texture_swizzle = 0;
int glext_ARB_timer_query = 0;
int glext_ARB_vertex_type_2_10_10_10_rev = 0;
int glext_ARB_draw_indirect = 0;
int glext_ARB_gpu_shader5 = 0;
int glext_ARB_gpu_shader_fp64 = 0;
int glext_ARB_shader_subroutine = 0;
int glext_ARB_tessellation_shader = 0;
int glext_ARB_texture_buffer_object_rgb32 = 0;
int glext_ARB_transform_feedback2 = 0;
int glext_ARB_transform_feedback3 = 0;
int glext_ARB_ES2_compatibility = 0;
int glext_ARB_get_program_binary = 0;
int glext_ARB_separate_shader_objects = 0;
int glext_ARB_shader_precision = 0;
int glext_ARB_vertex_attrib_64bit = 0;
int glext_ARB_viewport_array = 0;
int glext_ARB_cl_event = 0;
int glext_ARB_debug_output = 0;
int glext_ARB_robustness = 0;
int glext_ARB_shader_stencil_export = 0;
int glext_ARB_base_instance = 0;
int glext_ARB_shading_language_420pack = 0;
int glext_ARB_transform_feedback_instanced = 0;
int glext_ARB_compressed_texture_pixel_storage = 0;
int glext_ARB_conservative_depth = 0;
int glext_ARB_internalformat_query = 0;
int glext_ARB_map_buffer_alignment = 0;
int glext_ARB_shader_atomic_counters = 0;
int glext_ARB_shader_image_load_store = 0;
int glext_ARB_shading_language_packing = 0;
int glext_ARB_texture_storage = 0;
int glext_KHR_texture_compression_astc_ldr = 0;
int glext_KHR_debug = 0;
int glext_ARB_arrays_of_arrays = 0;
int glext_ARB_clear_buffer_object = 0;
int glext_ARB_compute_shader = 0;
int glext_ARB_copy_image = 0;
int glext_ARB_debug_group = 0;
int glext_ARB_debug_label = 0;
int glext_ARB_debug_output2 = 0;
int glext_ARB_ES3_compatibility = 0;
int glext_ARB_explicit_uniform_location = 0;
int glext_ARB_fragment_layer_viewport = 0;
int glext_ARB_framebuffer_no_attachments = 0;
int glext_ARB_internalformat_query2 = 0;
int glext_ARB_invalidate_subdata = 0;
int glext_ARB_multi_draw_indirect = 0;
int glext_ARB_program_interface_query = 0;
int glext_ARB_robust_buffer_access_behavior = 0;
int glext_ARB_shader_image_size = 0;
int glext_ARB_shader_storage_buffer_object = 0;
int glext_ARB_stencil_texturing = 0;
int glext_ARB_texture_buffer_range = 0;
int glext_ARB_texture_query_levels = 0;
int glext_ARB_texture_storage_multisample = 0;
int glext_ARB_texture_view = 0;
int glext_ARB_vertex_attrib_binding = 0;
int glext_ARB_robustness_isolation = 0;
int glext_EXT_abgr = 0;
int glext_EXT_blend_color = 0;
int glext_EXT_polygon_offset = 0;
int glext_EXT_texture = 0;
int glext_EXT_texture3D = 0;
int glext_SGIS_texture_filter4 = 0;
int glext_EXT_subtexture = 0;
int glext_EXT_copy_texture = 0;
int glext_EXT_histogram = 0;
int glext_EXT_convolution = 0;
int glext_SGI_color_matrix = 0;
int glext_SGI_color_table = 0;
int glext_SGIS_pixel_texture = 0;
int glext_SGIX_pixel_texture = 0;
int glext_SGIS_texture4D = 0;
int glext_SGI_texture_color_table = 0;
int glext_EXT_cmyka = 0;
int glext_EXT_texture_object = 0;
int glext_SGIS_detail_texture = 0;
int glext_SGIS_sharpen_texture = 0;
int glext_EXT_packed_pixels = 0;
int glext_SGIS_texture_lod = 0;
int glext_SGIS_multisample = 0;
int glext_EXT_rescale_normal = 0;
int glext_EXT_vertex_array = 0;
int glext_EXT_misc_attribute = 0;
int glext_SGIS_generate_mipmap = 0;
int glext_SGIX_clipmap = 0;
int glext_SGIX_shadow = 0;
int glext_SGIS_texture_edge_clamp = 0;
int glext_SGIS_texture_border_clamp = 0;
int glext_EXT_blend_minmax = 0;
int glext_EXT_blend_subtract = 0;
int glext_EXT_blend_logic_op = 0;
int glext_SGIX_interlace = 0;
int glext_SGIX_pixel_tiles = 0;
int glext_SGIS_texture_select = 0;
int glext_SGIX_sprite = 0;
int glext_SGIX_texture_multi_buffer = 0;
int glext_EXT_point_parameters = 0;
int glext_SGIS_point_parameters = 0;
int glext_SGIX_instruments = 0;
int glext_SGIX_texture_scale_bias = 0;
int glext_SGIX_framezoom = 0;
int glext_SGIX_tag_sample_buffer = 0;
int glext_FfdMaskSGIX = 0;
int glext_SGIX_polynomial_ffd = 0;
int glext_SGIX_reference_plane = 0;
int glext_SGIX_flush_raster = 0;
int glext_SGIX_depth_texture = 0;
int glext_SGIS_fog_function = 0;
int glext_SGIX_fog_offset = 0;
int glext_HP_image_transform = 0;
int glext_HP_convolution_border_modes = 0;
int glext_INGR_palette_buffer = 0;
int glext_SGIX_texture_add_env = 0;
int glext_EXT_color_subtable = 0;
int glext_PGI_vertex_hints = 0;
int glext_PGI_misc_hints = 0;
int glext_EXT_paletted_texture = 0;
int glext_EXT_clip_volume_hint = 0;
int glext_SGIX_list_priority = 0;
int glext_SGIX_ir_instrument1 = 0;
int glext_SGIX_calligraphic_fragment = 0;
int glext_SGIX_texture_lod_bias = 0;
int glext_SGIX_shadow_ambient = 0;
int glext_EXT_index_texture = 0;
int glext_EXT_index_material = 0;
int glext_EXT_index_func = 0;
int glext_EXT_index_array_formats = 0;
int glext_EXT_compiled_vertex_array = 0;
int glext_EXT_cull_vertex = 0;
int glext_SGIX_ycrcb = 0;
int glext_SGIX_fragment_lighting = 0;
int glext_IBM_rasterpos_clip = 0;
int glext_HP_texture_lighting = 0;
int glext_EXT_draw_range_elements = 0;
int glext_WIN_phong_shading = 0;
int glext_WIN_specular_fog = 0;
int glext_EXT_light_texture = 0;
int glext_SGIX_blend_alpha_minmax = 0;
int glext_SGIX_impact_pixel_texture = 0;
int glext_EXT_bgra = 0;
int glext_SGIX_async = 0;
int glext_SGIX_async_pixel = 0;
int glext_SGIX_async_histogram = 0;
int glext_INTEL_texture_scissor = 0;
int glext_INTEL_parallel_arrays = 0;
int glext_HP_occlusion_test = 0;
int glext_EXT_pixel_transform = 0;
int glext_EXT_pixel_transform_color_table = 0;
int glext_EXT_shared_texture_palette = 0;
int glext_EXT_separate_specular_color = 0;
int glext_EXT_secondary_color = 0;
int glext_EXT_texture_perturb_normal = 0;
int glext_EXT_multi_draw_arrays = 0;
int glext_EXT_fog_coord = 0;
int glext_REND_screen_coordinates = 0;
int glext_EXT_coordinate_frame = 0;
int glext_EXT_texture_env_combine = 0;
int glext_APPLE_specular_vector = 0;
int glext_APPLE_transform_hint = 0;
int glext_SGIX_fog_scale = 0;
int glext_SUNX_constant_data = 0;
int glext_SUN_global_alpha = 0;
int glext_SUN_triangle_list = 0;
int glext_SUN_vertex = 0;
int glext_EXT_blend_func_separate = 0;
int glext_INGR_color_clamp = 0;
int glext_INGR_interlace_read = 0;
int glext_EXT_stencil_wrap = 0;
int glext_EXT_422_pixels = 0;
int glext_NV_texgen_reflection = 0;
int glext_EXT_texture_cube_map = 0;
int glext_SUN_convolution_border_modes = 0;
int glext_EXT_texture_env_add = 0;
int glext_EXT_texture_lod_bias = 0;
int glext_EXT_texture_filter_anisotropic = 0;
int glext_EXT_vertex_weighting = 0;
int glext_NV_light_max_exponent = 0;
int glext_NV_vertex_array_range = 0;
int glext_NV_register_combiners = 0;
int glext_NV_fog_distance = 0;
int glext_NV_texgen_emboss = 0;
int glext_NV_blend_square = 0;
int glext_NV_texture_env_combine4 = 0;
int glext_MESA_resize_buffers = 0;
int glext_MESA_window_pos = 0;
int glext_EXT_texture_compression_s3tc = 0;
int glext_IBM_cull_vertex = 0;
int glext_IBM_multimode_draw_arrays = 0;
int glext_IBM_vertex_array_lists = 0;
int glext_SGIX_subsample = 0;
int glext_SGIX_ycrcb_subsample = 0;
int glext_SGIX_ycrcba = 0;
int glext_SGI_depth_pass_instrument = 0;
int glext_3DFX_texture_compression_FXT1 = 0;
int glext_3DFX_multisample = 0;
int glext_3DFX_tbuffer = 0;
int glext_EXT_multisample = 0;
int glext_SGIX_vertex_preclip = 0;
int glext_SGIX_convolution_accuracy = 0;
int glext_SGIX_resample = 0;
int glext_SGIS_point_line_texgen = 0;
int glext_SGIS_texture_color_mask = 0;
int glext_EXT_texture_env_dot3 = 0;
int glext_ATI_texture_mirror_once = 0;
int glext_NV_fence = 0;
int glext_IBM_texture_mirrored_repeat = 0;
int glext_NV_evaluators = 0;
int glext_NV_packed_depth_stencil = 0;
int glext_NV_register_combiners2 = 0;
int glext_NV_texture_compression_vtc = 0;
int glext_NV_texture_rectangle = 0;
int glext_NV_texture_shader = 0;
int glext_NV_texture_shader2 = 0;
int glext_NV_vertex_array_range2 = 0;
int glext_NV_vertex_program = 0;
int glext_SGIX_texture_coordinate_clamp = 0;
int glext_SGIX_scalebias_hint = 0;
int glext_OML_interlace = 0;
int glext_OML_subsample = 0;
int glext_OML_resample = 0;
int glext_NV_copy_depth_to_color = 0;
int glext_ATI_envmap_bumpmap = 0;
int glext_ATI_fragment_shader = 0;
int glext_ATI_pn_triangles = 0;
int glext_ATI_vertex_array_object = 0;
int glext_EXT_vertex_shader = 0;
int glext_ATI_vertex_streams = 0;
int glext_ATI_element_array = 0;
int glext_SUN_mesh_array = 0;
int glext_SUN_slice_accum = 0;
int glext_NV_multisample_filter_hint = 0;
int glext_NV_depth_clamp = 0;
int glext_NV_occlusion_query = 0;
int glext_NV_point_sprite = 0;
int glext_NV_texture_shader3 = 0;
int glext_NV_vertex_program1_1 = 0;
int glext_EXT_shadow_funcs = 0;
int glext_EXT_stencil_two_side = 0;
int glext_ATI_text_fragment_shader = 0;
int glext_APPLE_client_storage = 0;
int glext_APPLE_element_array = 0;
int glext_APPLE_fence = 0;
int glext_APPLE_vertex_array_object = 0;
int glext_APPLE_vertex_array_range = 0;
int glext_APPLE_ycbcr_422 = 0;
int glext_S3_s3tc = 0;
int glext_ATI_draw_buffers = 0;
int glext_ATI_pixel_format_float = 0;
int glext_ATI_texture_env_combine3 = 0;
int glext_ATI_texture_float = 0;
int glext_NV_float_buffer = 0;
int glext_NV_fragment_program = 0;
int glext_NV_half_float = 0;
int glext_NV_pixel_data_range = 0;
int glext_NV_primitive_restart = 0;
int glext_NV_texture_expand_normal = 0;
int glext_NV_vertex_program2 = 0;
int glext_ATI_map_object_buffer = 0;
int glext_ATI_separate_stencil = 0;
int glext_ATI_vertex_attrib_array_object = 0;
int glext_OES_read_format = 0;
int glext_EXT_depth_bounds_test = 0;
int glext_EXT_texture_mirror_clamp = 0;
int glext_EXT_blend_equation_separate = 0;
int glext_MESA_pack_invert = 0;
int glext_MESA_ycbcr_texture = 0;
int glext_EXT_pixel_buffer_object = 0;
int glext_NV_fragment_program_option = 0;
int glext_NV_fragment_program2 = 0;
int glext_NV_vertex_program2_option = 0;
int glext_NV_vertex_program3 = 0;
int glext_EXT_framebuffer_object = 0;
int glext_GREMEDY_string_marker = 0;
int glext_EXT_packed_depth_stencil = 0;
int glext_EXT_stencil_clear_tag = 0;
int glext_EXT_texture_sRGB = 0;
int glext_EXT_framebuffer_blit = 0;
int glext_EXT_framebuffer_multisample = 0;
int glext_MESAX_texture_stack = 0;
int glext_EXT_timer_query = 0;
int glext_EXT_gpu_program_parameters = 0;
int glext_APPLE_flush_buffer_range = 0;
int glext_NV_gpu_program4 = 0;
int glext_NV_geometry_program4 = 0;
int glext_EXT_geometry_shader4 = 0;
int glext_NV_vertex_program4 = 0;
int glext_EXT_gpu_shader4 = 0;
int glext_EXT_draw_instanced = 0;
int glext_EXT_packed_float = 0;
int glext_EXT_texture_array = 0;
int glext_EXT_texture_buffer_object = 0;
int glext_EXT_texture_compression_latc = 0;
int glext_EXT_texture_compression_rgtc = 0;
int glext_EXT_texture_shared_exponent = 0;
int glext_NV_depth_buffer_float = 0;
int glext_NV_fragment_program4 = 0;
int glext_NV_framebuffer_multisample_coverage = 0;
int glext_EXT_framebuffer_sRGB = 0;
int glext_NV_geometry_shader4 = 0;
int glext_NV_parameter_buffer_object = 0;
int glext_EXT_draw_buffers2 = 0;
int glext_NV_transform_feedback = 0;
int glext_EXT_bindable_uniform = 0;
int glext_EXT_texture_integer = 0;
int glext_GREMEDY_frame_terminator = 0;
int glext_NV_conditional_render = 0;
int glext_NV_present_video = 0;
int glext_EXT_transform_feedback = 0;
int glext_EXT_direct_state_access = 0;
int glext_EXT_vertex_array_bgra = 0;
int glext_EXT_texture_swizzle = 0;
int glext_NV_explicit_multisample = 0;
int glext_NV_transform_feedback2 = 0;
int glext_ATI_meminfo = 0;
int glext_AMD_performance_monitor = 0;
int glext_AMD_texture_texture4 = 0;
int glext_AMD_vertex_shader_tessellator = 0;
int glext_EXT_provoking_vertex = 0;
int glext_EXT_texture_snorm = 0;
int glext_AMD_draw_buffers_blend = 0;
int glext_APPLE_texture_range = 0;
int glext_APPLE_float_pixels = 0;
int glext_APPLE_vertex_program_evaluators = 0;
int glext_APPLE_aux_depth_stencil = 0;
int glext_APPLE_object_purgeable = 0;
int glext_APPLE_row_bytes = 0;
int glext_APPLE_rgb_422 = 0;
int glext_NV_video_capture = 0;
int glext_NV_copy_image = 0;
int glext_EXT_separate_shader_objects = 0;
int glext_NV_parameter_buffer_object2 = 0;
int glext_NV_shader_buffer_load = 0;
int glext_NV_vertex_buffer_unified_memory = 0;
int glext_NV_texture_barrier = 0;
int glext_AMD_shader_stencil_export = 0;
int glext_AMD_seamless_cubemap_per_texture = 0;
int glext_AMD_conservative_depth = 0;
int glext_EXT_shader_image_load_store = 0;
int glext_EXT_vertex_attrib_64bit = 0;
int glext_NV_gpu_program5 = 0;
int glext_NV_gpu_shader5 = 0;
int glext_NV_shader_buffer_store = 0;
int glext_NV_tessellation_program5 = 0;
int glext_NV_vertex_attrib_integer_64bit = 0;
int glext_NV_multisample_coverage = 0;
int glext_AMD_name_gen_delete = 0;
int glext_AMD_debug_output = 0;
int glext_NV_vdpau_interop = 0;
int glext_AMD_transform_feedback3_lines_triangles = 0;
int glext_AMD_depth_clamp_separate = 0;
int glext_EXT_texture_sRGB_decode = 0;
int glext_NV_texture_multisample = 0;
int glext_AMD_blend_minmax_factor = 0;
int glext_AMD_sample_positions = 0;
int glext_EXT_x11_sync_object = 0;
int glext_AMD_multi_draw_indirect = 0;
int glext_EXT_framebuffer_multisample_blit_scaled = 0;
int glext_NV_path_rendering = 0;
int glext_AMD_pinned_memory = 0;
int glext_AMD_stencil_operation_extended = 0;
int glext_AMD_vertex_shader_viewport_index = 0;
int glext_AMD_vertex_shader_layer = 0;
int glext_NV_bindless_texture = 0;
int glext_NV_shader_atomic_float = 0;
int glext_AMD_query_buffer_object = 0;


void gleIntClear()
{
	glext_ARB_imaging = 0;
	glext_ARB_multitexture = 0;
	glext_ARB_transpose_matrix = 0;
	glext_ARB_multisample = 0;
	glext_ARB_texture_env_add = 0;
	glext_ARB_texture_cube_map = 0;
	glext_ARB_texture_compression = 0;
	glext_ARB_texture_border_clamp = 0;
	glext_ARB_point_parameters = 0;
	glext_ARB_vertex_blend = 0;
	glext_ARB_matrix_palette = 0;
	glext_ARB_texture_env_combine = 0;
	glext_ARB_texture_env_crossbar = 0;
	glext_ARB_texture_env_dot3 = 0;
	glext_ARB_texture_mirrored_repeat = 0;
	glext_ARB_depth_texture = 0;
	glext_ARB_shadow = 0;
	glext_ARB_shadow_ambient = 0;
	glext_ARB_window_pos = 0;
	glext_ARB_vertex_program = 0;
	glext_ARB_fragment_program = 0;
	glext_ARB_vertex_buffer_object = 0;
	glext_ARB_occlusion_query = 0;
	glext_ARB_shader_objects = 0;
	glext_ARB_vertex_shader = 0;
	glext_ARB_fragment_shader = 0;
	glext_ARB_shading_language_100 = 0;
	glext_ARB_texture_non_power_of_two = 0;
	glext_ARB_point_sprite = 0;
	glext_ARB_fragment_program_shadow = 0;
	glext_ARB_draw_buffers = 0;
	glext_ARB_texture_rectangle = 0;
	glext_ARB_color_buffer_float = 0;
	glext_ARB_half_float_pixel = 0;
	glext_ARB_texture_float = 0;
	glext_ARB_pixel_buffer_object = 0;
	glext_ARB_depth_buffer_float = 0;
	glext_ARB_draw_instanced = 0;
	glext_ARB_framebuffer_object = 0;
	glext_ARB_framebuffer_sRGB = 0;
	glext_ARB_geometry_shader4 = 0;
	glext_ARB_half_float_vertex = 0;
	glext_ARB_instanced_arrays = 0;
	glext_ARB_map_buffer_range = 0;
	glext_ARB_texture_buffer_object = 0;
	glext_ARB_texture_compression_rgtc = 0;
	glext_ARB_texture_rg = 0;
	glext_ARB_vertex_array_object = 0;
	glext_ARB_uniform_buffer_object = 0;
	glext_ARB_compatibility = 0;
	glext_ARB_copy_buffer = 0;
	glext_ARB_shader_texture_lod = 0;
	glext_ARB_depth_clamp = 0;
	glext_ARB_draw_elements_base_vertex = 0;
	glext_ARB_fragment_coord_conventions = 0;
	glext_ARB_provoking_vertex = 0;
	glext_ARB_seamless_cube_map = 0;
	glext_ARB_sync = 0;
	glext_ARB_texture_multisample = 0;
	glext_ARB_vertex_array_bgra = 0;
	glext_ARB_draw_buffers_blend = 0;
	glext_ARB_sample_shading = 0;
	glext_ARB_texture_cube_map_array = 0;
	glext_ARB_texture_gather = 0;
	glext_ARB_texture_query_lod = 0;
	glext_ARB_shading_language_include = 0;
	glext_ARB_texture_compression_bptc = 0;
	glext_ARB_blend_func_extended = 0;
	glext_ARB_explicit_attrib_location = 0;
	glext_ARB_occlusion_query2 = 0;
	glext_ARB_sampler_objects = 0;
	glext_ARB_shader_bit_encoding = 0;
	glext_ARB_texture_rgb10_a2ui = 0;
	glext_ARB_texture_swizzle = 0;
	glext_ARB_timer_query = 0;
	glext_ARB_vertex_type_2_10_10_10_rev = 0;
	glext_ARB_draw_indirect = 0;
	glext_ARB_gpu_shader5 = 0;
	glext_ARB_gpu_shader_fp64 = 0;
	glext_ARB_shader_subroutine = 0;
	glext_ARB_tessellation_shader = 0;
	glext_ARB_texture_buffer_object_rgb32 = 0;
	glext_ARB_transform_feedback2 = 0;
	glext_ARB_transform_feedback3 = 0;
	glext_ARB_ES2_compatibility = 0;
	glext_ARB_get_program_binary = 0;
	glext_ARB_separate_shader_objects = 0;
	glext_ARB_shader_precision = 0;
	glext_ARB_vertex_attrib_64bit = 0;
	glext_ARB_viewport_array = 0;
	glext_ARB_cl_event = 0;
	glext_ARB_debug_output = 0;
	glext_ARB_robustness = 0;
	glext_ARB_shader_stencil_export = 0;
	glext_ARB_base_instance = 0;
	glext_ARB_shading_language_420pack = 0;
	glext_ARB_transform_feedback_instanced = 0;
	glext_ARB_compressed_texture_pixel_storage = 0;
	glext_ARB_conservative_depth = 0;
	glext_ARB_internalformat_query = 0;
	glext_ARB_map_buffer_alignment = 0;
	glext_ARB_shader_atomic_counters = 0;
	glext_ARB_shader_image_load_store = 0;
	glext_ARB_shading_language_packing = 0;
	glext_ARB_texture_storage = 0;
	glext_KHR_texture_compression_astc_ldr = 0;
	glext_KHR_debug = 0;
	glext_ARB_arrays_of_arrays = 0;
	glext_ARB_clear_buffer_object = 0;
	glext_ARB_compute_shader = 0;
	glext_ARB_copy_image = 0;
	glext_ARB_debug_group = 0;
	glext_ARB_debug_label = 0;
	glext_ARB_debug_output2 = 0;
	glext_ARB_ES3_compatibility = 0;
	glext_ARB_explicit_uniform_location = 0;
	glext_ARB_fragment_layer_viewport = 0;
	glext_ARB_framebuffer_no_attachments = 0;
	glext_ARB_internalformat_query2 = 0;
	glext_ARB_invalidate_subdata = 0;
	glext_ARB_multi_draw_indirect = 0;
	glext_ARB_program_interface_query = 0;
	glext_ARB_robust_buffer_access_behavior = 0;
	glext_ARB_shader_image_size = 0;
	glext_ARB_shader_storage_buffer_object = 0;
	glext_ARB_stencil_texturing = 0;
	glext_ARB_texture_buffer_range = 0;
	glext_ARB_texture_query_levels = 0;
	glext_ARB_texture_storage_multisample = 0;
	glext_ARB_texture_view = 0;
	glext_ARB_vertex_attrib_binding = 0;
	glext_ARB_robustness_isolation = 0;
	glext_EXT_abgr = 0;
	glext_EXT_blend_color = 0;
	glext_EXT_polygon_offset = 0;
	glext_EXT_texture = 0;
	glext_EXT_texture3D = 0;
	glext_SGIS_texture_filter4 = 0;
	glext_EXT_subtexture = 0;
	glext_EXT_copy_texture = 0;
	glext_EXT_histogram = 0;
	glext_EXT_convolution = 0;
	glext_SGI_color_matrix = 0;
	glext_SGI_color_table = 0;
	glext_SGIS_pixel_texture = 0;
	glext_SGIX_pixel_texture = 0;
	glext_SGIS_texture4D = 0;
	glext_SGI_texture_color_table = 0;
	glext_EXT_cmyka = 0;
	glext_EXT_texture_object = 0;
	glext_SGIS_detail_texture = 0;
	glext_SGIS_sharpen_texture = 0;
	glext_EXT_packed_pixels = 0;
	glext_SGIS_texture_lod = 0;
	glext_SGIS_multisample = 0;
	glext_EXT_rescale_normal = 0;
	glext_EXT_vertex_array = 0;
	glext_EXT_misc_attribute = 0;
	glext_SGIS_generate_mipmap = 0;
	glext_SGIX_clipmap = 0;
	glext_SGIX_shadow = 0;
	glext_SGIS_texture_edge_clamp = 0;
	glext_SGIS_texture_border_clamp = 0;
	glext_EXT_blend_minmax = 0;
	glext_EXT_blend_subtract = 0;
	glext_EXT_blend_logic_op = 0;
	glext_SGIX_interlace = 0;
	glext_SGIX_pixel_tiles = 0;
	glext_SGIS_texture_select = 0;
	glext_SGIX_sprite = 0;
	glext_SGIX_texture_multi_buffer = 0;
	glext_EXT_point_parameters = 0;
	glext_SGIS_point_parameters = 0;
	glext_SGIX_instruments = 0;
	glext_SGIX_texture_scale_bias = 0;
	glext_SGIX_framezoom = 0;
	glext_SGIX_tag_sample_buffer = 0;
	glext_FfdMaskSGIX = 0;
	glext_SGIX_polynomial_ffd = 0;
	glext_SGIX_reference_plane = 0;
	glext_SGIX_flush_raster = 0;
	glext_SGIX_depth_texture = 0;
	glext_SGIS_fog_function = 0;
	glext_SGIX_fog_offset = 0;
	glext_HP_image_transform = 0;
	glext_HP_convolution_border_modes = 0;
	glext_INGR_palette_buffer = 0;
	glext_SGIX_texture_add_env = 0;
	glext_EXT_color_subtable = 0;
	glext_PGI_vertex_hints = 0;
	glext_PGI_misc_hints = 0;
	glext_EXT_paletted_texture = 0;
	glext_EXT_clip_volume_hint = 0;
	glext_SGIX_list_priority = 0;
	glext_SGIX_ir_instrument1 = 0;
	glext_SGIX_calligraphic_fragment = 0;
	glext_SGIX_texture_lod_bias = 0;
	glext_SGIX_shadow_ambient = 0;
	glext_EXT_index_texture = 0;
	glext_EXT_index_material = 0;
	glext_EXT_index_func = 0;
	glext_EXT_index_array_formats = 0;
	glext_EXT_compiled_vertex_array = 0;
	glext_EXT_cull_vertex = 0;
	glext_SGIX_ycrcb = 0;
	glext_SGIX_fragment_lighting = 0;
	glext_IBM_rasterpos_clip = 0;
	glext_HP_texture_lighting = 0;
	glext_EXT_draw_range_elements = 0;
	glext_WIN_phong_shading = 0;
	glext_WIN_specular_fog = 0;
	glext_EXT_light_texture = 0;
	glext_SGIX_blend_alpha_minmax = 0;
	glext_SGIX_impact_pixel_texture = 0;
	glext_EXT_bgra = 0;
	glext_SGIX_async = 0;
	glext_SGIX_async_pixel = 0;
	glext_SGIX_async_histogram = 0;
	glext_INTEL_texture_scissor = 0;
	glext_INTEL_parallel_arrays = 0;
	glext_HP_occlusion_test = 0;
	glext_EXT_pixel_transform = 0;
	glext_EXT_pixel_transform_color_table = 0;
	glext_EXT_shared_texture_palette = 0;
	glext_EXT_separate_specular_color = 0;
	glext_EXT_secondary_color = 0;
	glext_EXT_texture_perturb_normal = 0;
	glext_EXT_multi_draw_arrays = 0;
	glext_EXT_fog_coord = 0;
	glext_REND_screen_coordinates = 0;
	glext_EXT_coordinate_frame = 0;
	glext_EXT_texture_env_combine = 0;
	glext_APPLE_specular_vector = 0;
	glext_APPLE_transform_hint = 0;
	glext_SGIX_fog_scale = 0;
	glext_SUNX_constant_data = 0;
	glext_SUN_global_alpha = 0;
	glext_SUN_triangle_list = 0;
	glext_SUN_vertex = 0;
	glext_EXT_blend_func_separate = 0;
	glext_INGR_color_clamp = 0;
	glext_INGR_interlace_read = 0;
	glext_EXT_stencil_wrap = 0;
	glext_EXT_422_pixels = 0;
	glext_NV_texgen_reflection = 0;
	glext_EXT_texture_cube_map = 0;
	glext_SUN_convolution_border_modes = 0;
	glext_EXT_texture_env_add = 0;
	glext_EXT_texture_lod_bias = 0;
	glext_EXT_texture_filter_anisotropic = 0;
	glext_EXT_vertex_weighting = 0;
	glext_NV_light_max_exponent = 0;
	glext_NV_vertex_array_range = 0;
	glext_NV_register_combiners = 0;
	glext_NV_fog_distance = 0;
	glext_NV_texgen_emboss = 0;
	glext_NV_blend_square = 0;
	glext_NV_texture_env_combine4 = 0;
	glext_MESA_resize_buffers = 0;
	glext_MESA_window_pos = 0;
	glext_EXT_texture_compression_s3tc = 0;
	glext_IBM_cull_vertex = 0;
	glext_IBM_multimode_draw_arrays = 0;
	glext_IBM_vertex_array_lists = 0;
	glext_SGIX_subsample = 0;
	glext_SGIX_ycrcb_subsample = 0;
	glext_SGIX_ycrcba = 0;
	glext_SGI_depth_pass_instrument = 0;
	glext_3DFX_texture_compression_FXT1 = 0;
	glext_3DFX_multisample = 0;
	glext_3DFX_tbuffer = 0;
	glext_EXT_multisample = 0;
	glext_SGIX_vertex_preclip = 0;
	glext_SGIX_convolution_accuracy = 0;
	glext_SGIX_resample = 0;
	glext_SGIS_point_line_texgen = 0;
	glext_SGIS_texture_color_mask = 0;
	glext_EXT_texture_env_dot3 = 0;
	glext_ATI_texture_mirror_once = 0;
	glext_NV_fence = 0;
	glext_IBM_texture_mirrored_repeat = 0;
	glext_NV_evaluators = 0;
	glext_NV_packed_depth_stencil = 0;
	glext_NV_register_combiners2 = 0;
	glext_NV_texture_compression_vtc = 0;
	glext_NV_texture_rectangle = 0;
	glext_NV_texture_shader = 0;
	glext_NV_texture_shader2 = 0;
	glext_NV_vertex_array_range2 = 0;
	glext_NV_vertex_program = 0;
	glext_SGIX_texture_coordinate_clamp = 0;
	glext_SGIX_scalebias_hint = 0;
	glext_OML_interlace = 0;
	glext_OML_subsample = 0;
	glext_OML_resample = 0;
	glext_NV_copy_depth_to_color = 0;
	glext_ATI_envmap_bumpmap = 0;
	glext_ATI_fragment_shader = 0;
	glext_ATI_pn_triangles = 0;
	glext_ATI_vertex_array_object = 0;
	glext_EXT_vertex_shader = 0;
	glext_ATI_vertex_streams = 0;
	glext_ATI_element_array = 0;
	glext_SUN_mesh_array = 0;
	glext_SUN_slice_accum = 0;
	glext_NV_multisample_filter_hint = 0;
	glext_NV_depth_clamp = 0;
	glext_NV_occlusion_query = 0;
	glext_NV_point_sprite = 0;
	glext_NV_texture_shader3 = 0;
	glext_NV_vertex_program1_1 = 0;
	glext_EXT_shadow_funcs = 0;
	glext_EXT_stencil_two_side = 0;
	glext_ATI_text_fragment_shader = 0;
	glext_APPLE_client_storage = 0;
	glext_APPLE_element_array = 0;
	glext_APPLE_fence = 0;
	glext_APPLE_vertex_array_object = 0;
	glext_APPLE_vertex_array_range = 0;
	glext_APPLE_ycbcr_422 = 0;
	glext_S3_s3tc = 0;
	glext_ATI_draw_buffers = 0;
	glext_ATI_pixel_format_float = 0;
	glext_ATI_texture_env_combine3 = 0;
	glext_ATI_texture_float = 0;
	glext_NV_float_buffer = 0;
	glext_NV_fragment_program = 0;
	glext_NV_half_float = 0;
	glext_NV_pixel_data_range = 0;
	glext_NV_primitive_restart = 0;
	glext_NV_texture_expand_normal = 0;
	glext_NV_vertex_program2 = 0;
	glext_ATI_map_object_buffer = 0;
	glext_ATI_separate_stencil = 0;
	glext_ATI_vertex_attrib_array_object = 0;
	glext_OES_read_format = 0;
	glext_EXT_depth_bounds_test = 0;
	glext_EXT_texture_mirror_clamp = 0;
	glext_EXT_blend_equation_separate = 0;
	glext_MESA_pack_invert = 0;
	glext_MESA_ycbcr_texture = 0;
	glext_EXT_pixel_buffer_object = 0;
	glext_NV_fragment_program_option = 0;
	glext_NV_fragment_program2 = 0;
	glext_NV_vertex_program2_option = 0;
	glext_NV_vertex_program3 = 0;
	glext_EXT_framebuffer_object = 0;
	glext_GREMEDY_string_marker = 0;
	glext_EXT_packed_depth_stencil = 0;
	glext_EXT_stencil_clear_tag = 0;
	glext_EXT_texture_sRGB = 0;
	glext_EXT_framebuffer_blit = 0;
	glext_EXT_framebuffer_multisample = 0;
	glext_MESAX_texture_stack = 0;
	glext_EXT_timer_query = 0;
	glext_EXT_gpu_program_parameters = 0;
	glext_APPLE_flush_buffer_range = 0;
	glext_NV_gpu_program4 = 0;
	glext_NV_geometry_program4 = 0;
	glext_EXT_geometry_shader4 = 0;
	glext_NV_vertex_program4 = 0;
	glext_EXT_gpu_shader4 = 0;
	glext_EXT_draw_instanced = 0;
	glext_EXT_packed_float = 0;
	glext_EXT_texture_array = 0;
	glext_EXT_texture_buffer_object = 0;
	glext_EXT_texture_compression_latc = 0;
	glext_EXT_texture_compression_rgtc = 0;
	glext_EXT_texture_shared_exponent = 0;
	glext_NV_depth_buffer_float = 0;
	glext_NV_fragment_program4 = 0;
	glext_NV_framebuffer_multisample_coverage = 0;
	glext_EXT_framebuffer_sRGB = 0;
	glext_NV_geometry_shader4 = 0;
	glext_NV_parameter_buffer_object = 0;
	glext_EXT_draw_buffers2 = 0;
	glext_NV_transform_feedback = 0;
	glext_EXT_bindable_uniform = 0;
	glext_EXT_texture_integer = 0;
	glext_GREMEDY_frame_terminator = 0;
	glext_NV_conditional_render = 0;
	glext_NV_present_video = 0;
	glext_EXT_transform_feedback = 0;
	glext_EXT_direct_state_access = 0;
	glext_EXT_vertex_array_bgra = 0;
	glext_EXT_texture_swizzle = 0;
	glext_NV_explicit_multisample = 0;
	glext_NV_transform_feedback2 = 0;
	glext_ATI_meminfo = 0;
	glext_AMD_performance_monitor = 0;
	glext_AMD_texture_texture4 = 0;
	glext_AMD_vertex_shader_tessellator = 0;
	glext_EXT_provoking_vertex = 0;
	glext_EXT_texture_snorm = 0;
	glext_AMD_draw_buffers_blend = 0;
	glext_APPLE_texture_range = 0;
	glext_APPLE_float_pixels = 0;
	glext_APPLE_vertex_program_evaluators = 0;
	glext_APPLE_aux_depth_stencil = 0;
	glext_APPLE_object_purgeable = 0;
	glext_APPLE_row_bytes = 0;
	glext_APPLE_rgb_422 = 0;
	glext_NV_video_capture = 0;
	glext_NV_copy_image = 0;
	glext_EXT_separate_shader_objects = 0;
	glext_NV_parameter_buffer_object2 = 0;
	glext_NV_shader_buffer_load = 0;
	glext_NV_vertex_buffer_unified_memory = 0;
	glext_NV_texture_barrier = 0;
	glext_AMD_shader_stencil_export = 0;
	glext_AMD_seamless_cubemap_per_texture = 0;
	glext_AMD_conservative_depth = 0;
	glext_EXT_shader_image_load_store = 0;
	glext_EXT_vertex_attrib_64bit = 0;
	glext_NV_gpu_program5 = 0;
	glext_NV_gpu_shader5 = 0;
	glext_NV_shader_buffer_store = 0;
	glext_NV_tessellation_program5 = 0;
	glext_NV_vertex_attrib_integer_64bit = 0;
	glext_NV_multisample_coverage = 0;
	glext_AMD_name_gen_delete = 0;
	glext_AMD_debug_output = 0;
	glext_NV_vdpau_interop = 0;
	glext_AMD_transform_feedback3_lines_triangles = 0;
	glext_AMD_depth_clamp_separate = 0;
	glext_EXT_texture_sRGB_decode = 0;
	glext_NV_texture_multisample = 0;
	glext_AMD_blend_minmax_factor = 0;
	glext_AMD_sample_positions = 0;
	glext_EXT_x11_sync_object = 0;
	glext_AMD_multi_draw_indirect = 0;
	glext_EXT_framebuffer_multisample_blit_scaled = 0;
	glext_NV_path_rendering = 0;
	glext_AMD_pinned_memory = 0;
	glext_AMD_stencil_operation_extended = 0;
	glext_AMD_vertex_shader_viewport_index = 0;
	glext_AMD_vertex_shader_layer = 0;
	glext_NV_bindless_texture = 0;
	glext_NV_shader_atomic_float = 0;
	glext_AMD_query_buffer_object = 0;
}



#ifndef GL_3DFX_tbuffer
typedef void (GLE_FUNCPTR * PFNGLTBUFFERMASK3DFXPROC)(GLuint );

PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFX;
#endif /*GL_3DFX_tbuffer*/

static int gleIntLoad_3DFX_tbuffer()
{
	int bIsLoaded = 1;
#ifndef GL_3DFX_tbuffer
	glTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC)gleIntGetProcAddress("glTbufferMask3DFX");
	if(!glTbufferMask3DFX) bIsLoaded = 0;
#endif /*GL_3DFX_tbuffer*/
	return bIsLoaded;
}



#ifndef GL_AMD_debug_output
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEENABLEAMDPROC)(GLenum , GLenum , GLsizei , const GLuint *, GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEINSERTAMDPROC)(GLenum , GLenum , GLuint , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECALLBACKAMDPROC)(GLDEBUGPROCAMD , GLvoid *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETDEBUGMESSAGELOGAMDPROC)(GLuint , GLsizei , GLenum *, GLuint *, GLuint *, GLsizei *, GLchar *);

PFNGLDEBUGMESSAGEENABLEAMDPROC glDebugMessageEnableAMD;
PFNGLDEBUGMESSAGEINSERTAMDPROC glDebugMessageInsertAMD;
PFNGLDEBUGMESSAGECALLBACKAMDPROC glDebugMessageCallbackAMD;
PFNGLGETDEBUGMESSAGELOGAMDPROC glGetDebugMessageLogAMD;
#endif /*GL_AMD_debug_output*/

static int gleIntLoad_AMD_debug_output()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_debug_output
	glDebugMessageEnableAMD = (PFNGLDEBUGMESSAGEENABLEAMDPROC)gleIntGetProcAddress("glDebugMessageEnableAMD");
	if(!glDebugMessageEnableAMD) bIsLoaded = 0;
	glDebugMessageInsertAMD = (PFNGLDEBUGMESSAGEINSERTAMDPROC)gleIntGetProcAddress("glDebugMessageInsertAMD");
	if(!glDebugMessageInsertAMD) bIsLoaded = 0;
	glDebugMessageCallbackAMD = (PFNGLDEBUGMESSAGECALLBACKAMDPROC)gleIntGetProcAddress("glDebugMessageCallbackAMD");
	if(!glDebugMessageCallbackAMD) bIsLoaded = 0;
	glGetDebugMessageLogAMD = (PFNGLGETDEBUGMESSAGELOGAMDPROC)gleIntGetProcAddress("glGetDebugMessageLogAMD");
	if(!glGetDebugMessageLogAMD) bIsLoaded = 0;
#endif /*GL_AMD_debug_output*/
	return bIsLoaded;
}

#ifndef GL_AMD_draw_buffers_blend
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCINDEXEDAMDPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONINDEXEDAMDPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)(GLuint , GLenum , GLenum );

PFNGLBLENDFUNCINDEXEDAMDPROC glBlendFuncIndexedAMD;
PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC glBlendFuncSeparateIndexedAMD;
PFNGLBLENDEQUATIONINDEXEDAMDPROC glBlendEquationIndexedAMD;
PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC glBlendEquationSeparateIndexedAMD;
#endif /*GL_AMD_draw_buffers_blend*/

static int gleIntLoad_AMD_draw_buffers_blend()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_draw_buffers_blend
	glBlendFuncIndexedAMD = (PFNGLBLENDFUNCINDEXEDAMDPROC)gleIntGetProcAddress("glBlendFuncIndexedAMD");
	if(!glBlendFuncIndexedAMD) bIsLoaded = 0;
	glBlendFuncSeparateIndexedAMD = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)gleIntGetProcAddress("glBlendFuncSeparateIndexedAMD");
	if(!glBlendFuncSeparateIndexedAMD) bIsLoaded = 0;
	glBlendEquationIndexedAMD = (PFNGLBLENDEQUATIONINDEXEDAMDPROC)gleIntGetProcAddress("glBlendEquationIndexedAMD");
	if(!glBlendEquationIndexedAMD) bIsLoaded = 0;
	glBlendEquationSeparateIndexedAMD = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)gleIntGetProcAddress("glBlendEquationSeparateIndexedAMD");
	if(!glBlendEquationSeparateIndexedAMD) bIsLoaded = 0;
#endif /*GL_AMD_draw_buffers_blend*/
	return bIsLoaded;
}
#ifndef GL_AMD_multi_draw_indirect
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)(GLenum , const GLvoid *, GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)(GLenum , GLenum , const GLvoid *, GLsizei , GLsizei );

PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glMultiDrawArraysIndirectAMD;
PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glMultiDrawElementsIndirectAMD;
#endif /*GL_AMD_multi_draw_indirect*/

static int gleIntLoad_AMD_multi_draw_indirect()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_multi_draw_indirect
	glMultiDrawArraysIndirectAMD = (PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)gleIntGetProcAddress("glMultiDrawArraysIndirectAMD");
	if(!glMultiDrawArraysIndirectAMD) bIsLoaded = 0;
	glMultiDrawElementsIndirectAMD = (PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)gleIntGetProcAddress("glMultiDrawElementsIndirectAMD");
	if(!glMultiDrawElementsIndirectAMD) bIsLoaded = 0;
#endif /*GL_AMD_multi_draw_indirect*/
	return bIsLoaded;
}
#ifndef GL_AMD_name_gen_delete
typedef void (GLE_FUNCPTR * PFNGLGENNAMESAMDPROC)(GLenum , GLuint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETENAMESAMDPROC)(GLenum , GLuint , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISNAMEAMDPROC)(GLenum , GLuint );

PFNGLGENNAMESAMDPROC glGenNamesAMD;
PFNGLDELETENAMESAMDPROC glDeleteNamesAMD;
PFNGLISNAMEAMDPROC glIsNameAMD;
#endif /*GL_AMD_name_gen_delete*/

static int gleIntLoad_AMD_name_gen_delete()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_name_gen_delete
	glGenNamesAMD = (PFNGLGENNAMESAMDPROC)gleIntGetProcAddress("glGenNamesAMD");
	if(!glGenNamesAMD) bIsLoaded = 0;
	glDeleteNamesAMD = (PFNGLDELETENAMESAMDPROC)gleIntGetProcAddress("glDeleteNamesAMD");
	if(!glDeleteNamesAMD) bIsLoaded = 0;
	glIsNameAMD = (PFNGLISNAMEAMDPROC)gleIntGetProcAddress("glIsNameAMD");
	if(!glIsNameAMD) bIsLoaded = 0;
#endif /*GL_AMD_name_gen_delete*/
	return bIsLoaded;
}
#ifndef GL_AMD_performance_monitor
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORGROUPSAMDPROC)(GLint *, GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORCOUNTERSAMDPROC)(GLuint , GLint *, GLint *, GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)(GLuint , GLuint , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGENPERFMONITORSAMDPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEPERFMONITORSAMDPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)(GLuint , GLboolean , GLuint , GLint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLBEGINPERFMONITORAMDPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDPERFMONITORAMDPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)(GLuint , GLenum , GLsizei , GLuint *, GLint *);

PFNGLGETPERFMONITORGROUPSAMDPROC glGetPerfMonitorGroupsAMD;
PFNGLGETPERFMONITORCOUNTERSAMDPROC glGetPerfMonitorCountersAMD;
PFNGLGETPERFMONITORGROUPSTRINGAMDPROC glGetPerfMonitorGroupStringAMD;
PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC glGetPerfMonitorCounterStringAMD;
PFNGLGETPERFMONITORCOUNTERINFOAMDPROC glGetPerfMonitorCounterInfoAMD;
PFNGLGENPERFMONITORSAMDPROC glGenPerfMonitorsAMD;
PFNGLDELETEPERFMONITORSAMDPROC glDeletePerfMonitorsAMD;
PFNGLSELECTPERFMONITORCOUNTERSAMDPROC glSelectPerfMonitorCountersAMD;
PFNGLBEGINPERFMONITORAMDPROC glBeginPerfMonitorAMD;
PFNGLENDPERFMONITORAMDPROC glEndPerfMonitorAMD;
PFNGLGETPERFMONITORCOUNTERDATAAMDPROC glGetPerfMonitorCounterDataAMD;
#endif /*GL_AMD_performance_monitor*/

static int gleIntLoad_AMD_performance_monitor()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_performance_monitor
	glGetPerfMonitorGroupsAMD = (PFNGLGETPERFMONITORGROUPSAMDPROC)gleIntGetProcAddress("glGetPerfMonitorGroupsAMD");
	if(!glGetPerfMonitorGroupsAMD) bIsLoaded = 0;
	glGetPerfMonitorCountersAMD = (PFNGLGETPERFMONITORCOUNTERSAMDPROC)gleIntGetProcAddress("glGetPerfMonitorCountersAMD");
	if(!glGetPerfMonitorCountersAMD) bIsLoaded = 0;
	glGetPerfMonitorGroupStringAMD = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)gleIntGetProcAddress("glGetPerfMonitorGroupStringAMD");
	if(!glGetPerfMonitorGroupStringAMD) bIsLoaded = 0;
	glGetPerfMonitorCounterStringAMD = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)gleIntGetProcAddress("glGetPerfMonitorCounterStringAMD");
	if(!glGetPerfMonitorCounterStringAMD) bIsLoaded = 0;
	glGetPerfMonitorCounterInfoAMD = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)gleIntGetProcAddress("glGetPerfMonitorCounterInfoAMD");
	if(!glGetPerfMonitorCounterInfoAMD) bIsLoaded = 0;
	glGenPerfMonitorsAMD = (PFNGLGENPERFMONITORSAMDPROC)gleIntGetProcAddress("glGenPerfMonitorsAMD");
	if(!glGenPerfMonitorsAMD) bIsLoaded = 0;
	glDeletePerfMonitorsAMD = (PFNGLDELETEPERFMONITORSAMDPROC)gleIntGetProcAddress("glDeletePerfMonitorsAMD");
	if(!glDeletePerfMonitorsAMD) bIsLoaded = 0;
	glSelectPerfMonitorCountersAMD = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)gleIntGetProcAddress("glSelectPerfMonitorCountersAMD");
	if(!glSelectPerfMonitorCountersAMD) bIsLoaded = 0;
	glBeginPerfMonitorAMD = (PFNGLBEGINPERFMONITORAMDPROC)gleIntGetProcAddress("glBeginPerfMonitorAMD");
	if(!glBeginPerfMonitorAMD) bIsLoaded = 0;
	glEndPerfMonitorAMD = (PFNGLENDPERFMONITORAMDPROC)gleIntGetProcAddress("glEndPerfMonitorAMD");
	if(!glEndPerfMonitorAMD) bIsLoaded = 0;
	glGetPerfMonitorCounterDataAMD = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)gleIntGetProcAddress("glGetPerfMonitorCounterDataAMD");
	if(!glGetPerfMonitorCounterDataAMD) bIsLoaded = 0;
#endif /*GL_AMD_performance_monitor*/
	return bIsLoaded;
}


#ifndef GL_AMD_sample_positions
typedef void (GLE_FUNCPTR * PFNGLSETMULTISAMPLEFVAMDPROC)(GLenum , GLuint , const GLfloat *);

PFNGLSETMULTISAMPLEFVAMDPROC glSetMultisamplefvAMD;
#endif /*GL_AMD_sample_positions*/

static int gleIntLoad_AMD_sample_positions()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_sample_positions
	glSetMultisamplefvAMD = (PFNGLSETMULTISAMPLEFVAMDPROC)gleIntGetProcAddress("glSetMultisamplefvAMD");
	if(!glSetMultisamplefvAMD) bIsLoaded = 0;
#endif /*GL_AMD_sample_positions*/
	return bIsLoaded;
}


#ifndef GL_AMD_stencil_operation_extended
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPVALUEAMDPROC)(GLenum , GLuint );

PFNGLSTENCILOPVALUEAMDPROC glStencilOpValueAMD;
#endif /*GL_AMD_stencil_operation_extended*/

static int gleIntLoad_AMD_stencil_operation_extended()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_stencil_operation_extended
	glStencilOpValueAMD = (PFNGLSTENCILOPVALUEAMDPROC)gleIntGetProcAddress("glStencilOpValueAMD");
	if(!glStencilOpValueAMD) bIsLoaded = 0;
#endif /*GL_AMD_stencil_operation_extended*/
	return bIsLoaded;
}



#ifndef GL_AMD_vertex_shader_tessellator
typedef void (GLE_FUNCPTR * PFNGLTESSELLATIONFACTORAMDPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTESSELLATIONMODEAMDPROC)(GLenum );

PFNGLTESSELLATIONFACTORAMDPROC glTessellationFactorAMD;
PFNGLTESSELLATIONMODEAMDPROC glTessellationModeAMD;
#endif /*GL_AMD_vertex_shader_tessellator*/

static int gleIntLoad_AMD_vertex_shader_tessellator()
{
	int bIsLoaded = 1;
#ifndef GL_AMD_vertex_shader_tessellator
	glTessellationFactorAMD = (PFNGLTESSELLATIONFACTORAMDPROC)gleIntGetProcAddress("glTessellationFactorAMD");
	if(!glTessellationFactorAMD) bIsLoaded = 0;
	glTessellationModeAMD = (PFNGLTESSELLATIONMODEAMDPROC)gleIntGetProcAddress("glTessellationModeAMD");
	if(!glTessellationModeAMD) bIsLoaded = 0;
#endif /*GL_AMD_vertex_shader_tessellator*/
	return bIsLoaded;
}



#ifndef GL_APPLE_element_array
typedef void (GLE_FUNCPTR * PFNGLELEMENTPOINTERAPPLEPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum , GLuint , GLuint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum , GLuint , GLuint , const GLint *, const GLsizei *, GLsizei );

PFNGLELEMENTPOINTERAPPLEPROC glElementPointerAPPLE;
PFNGLDRAWELEMENTARRAYAPPLEPROC glDrawElementArrayAPPLE;
PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glDrawRangeElementArrayAPPLE;
PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glMultiDrawElementArrayAPPLE;
PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glMultiDrawRangeElementArrayAPPLE;
#endif /*GL_APPLE_element_array*/

static int gleIntLoad_APPLE_element_array()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_element_array
	glElementPointerAPPLE = (PFNGLELEMENTPOINTERAPPLEPROC)gleIntGetProcAddress("glElementPointerAPPLE");
	if(!glElementPointerAPPLE) bIsLoaded = 0;
	glDrawElementArrayAPPLE = (PFNGLDRAWELEMENTARRAYAPPLEPROC)gleIntGetProcAddress("glDrawElementArrayAPPLE");
	if(!glDrawElementArrayAPPLE) bIsLoaded = 0;
	glDrawRangeElementArrayAPPLE = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)gleIntGetProcAddress("glDrawRangeElementArrayAPPLE");
	if(!glDrawRangeElementArrayAPPLE) bIsLoaded = 0;
	glMultiDrawElementArrayAPPLE = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)gleIntGetProcAddress("glMultiDrawElementArrayAPPLE");
	if(!glMultiDrawElementArrayAPPLE) bIsLoaded = 0;
	glMultiDrawRangeElementArrayAPPLE = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)gleIntGetProcAddress("glMultiDrawRangeElementArrayAPPLE");
	if(!glMultiDrawRangeElementArrayAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_element_array*/
	return bIsLoaded;
}
#ifndef GL_APPLE_fence
typedef void (GLE_FUNCPTR * PFNGLGENFENCESAPPLEPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEFENCESAPPLEPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSETFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTFENCEAPPLEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLFINISHFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTOBJECTAPPLEPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLFINISHOBJECTAPPLEPROC)(GLenum , GLint );

PFNGLGENFENCESAPPLEPROC glGenFencesAPPLE;
PFNGLDELETEFENCESAPPLEPROC glDeleteFencesAPPLE;
PFNGLSETFENCEAPPLEPROC glSetFenceAPPLE;
PFNGLISFENCEAPPLEPROC glIsFenceAPPLE;
PFNGLTESTFENCEAPPLEPROC glTestFenceAPPLE;
PFNGLFINISHFENCEAPPLEPROC glFinishFenceAPPLE;
PFNGLTESTOBJECTAPPLEPROC glTestObjectAPPLE;
PFNGLFINISHOBJECTAPPLEPROC glFinishObjectAPPLE;
#endif /*GL_APPLE_fence*/

static int gleIntLoad_APPLE_fence()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_fence
	glGenFencesAPPLE = (PFNGLGENFENCESAPPLEPROC)gleIntGetProcAddress("glGenFencesAPPLE");
	if(!glGenFencesAPPLE) bIsLoaded = 0;
	glDeleteFencesAPPLE = (PFNGLDELETEFENCESAPPLEPROC)gleIntGetProcAddress("glDeleteFencesAPPLE");
	if(!glDeleteFencesAPPLE) bIsLoaded = 0;
	glSetFenceAPPLE = (PFNGLSETFENCEAPPLEPROC)gleIntGetProcAddress("glSetFenceAPPLE");
	if(!glSetFenceAPPLE) bIsLoaded = 0;
	glIsFenceAPPLE = (PFNGLISFENCEAPPLEPROC)gleIntGetProcAddress("glIsFenceAPPLE");
	if(!glIsFenceAPPLE) bIsLoaded = 0;
	glTestFenceAPPLE = (PFNGLTESTFENCEAPPLEPROC)gleIntGetProcAddress("glTestFenceAPPLE");
	if(!glTestFenceAPPLE) bIsLoaded = 0;
	glFinishFenceAPPLE = (PFNGLFINISHFENCEAPPLEPROC)gleIntGetProcAddress("glFinishFenceAPPLE");
	if(!glFinishFenceAPPLE) bIsLoaded = 0;
	glTestObjectAPPLE = (PFNGLTESTOBJECTAPPLEPROC)gleIntGetProcAddress("glTestObjectAPPLE");
	if(!glTestObjectAPPLE) bIsLoaded = 0;
	glFinishObjectAPPLE = (PFNGLFINISHOBJECTAPPLEPROC)gleIntGetProcAddress("glFinishObjectAPPLE");
	if(!glFinishObjectAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_fence*/
	return bIsLoaded;
}

#ifndef GL_APPLE_flush_buffer_range
typedef void (GLE_FUNCPTR * PFNGLBUFFERPARAMETERIAPPLEPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)(GLenum , GLintptr , GLsizeiptr );

PFNGLBUFFERPARAMETERIAPPLEPROC glBufferParameteriAPPLE;
PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC glFlushMappedBufferRangeAPPLE;
#endif /*GL_APPLE_flush_buffer_range*/

static int gleIntLoad_APPLE_flush_buffer_range()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_flush_buffer_range
	glBufferParameteriAPPLE = (PFNGLBUFFERPARAMETERIAPPLEPROC)gleIntGetProcAddress("glBufferParameteriAPPLE");
	if(!glBufferParameteriAPPLE) bIsLoaded = 0;
	glFlushMappedBufferRangeAPPLE = (PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)gleIntGetProcAddress("glFlushMappedBufferRangeAPPLE");
	if(!glFlushMappedBufferRangeAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_flush_buffer_range*/
	return bIsLoaded;
}
#ifndef GL_APPLE_object_purgeable
typedef GLenum (GLE_FUNCPTR * PFNGLOBJECTPURGEABLEAPPLEPROC)(GLenum , GLuint , GLenum );
typedef GLenum (GLE_FUNCPTR * PFNGLOBJECTUNPURGEABLEAPPLEPROC)(GLenum , GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTPARAMETERIVAPPLEPROC)(GLenum , GLuint , GLenum , GLint *);

PFNGLOBJECTPURGEABLEAPPLEPROC glObjectPurgeableAPPLE;
PFNGLOBJECTUNPURGEABLEAPPLEPROC glObjectUnpurgeableAPPLE;
PFNGLGETOBJECTPARAMETERIVAPPLEPROC glGetObjectParameterivAPPLE;
#endif /*GL_APPLE_object_purgeable*/

static int gleIntLoad_APPLE_object_purgeable()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_object_purgeable
	glObjectPurgeableAPPLE = (PFNGLOBJECTPURGEABLEAPPLEPROC)gleIntGetProcAddress("glObjectPurgeableAPPLE");
	if(!glObjectPurgeableAPPLE) bIsLoaded = 0;
	glObjectUnpurgeableAPPLE = (PFNGLOBJECTUNPURGEABLEAPPLEPROC)gleIntGetProcAddress("glObjectUnpurgeableAPPLE");
	if(!glObjectUnpurgeableAPPLE) bIsLoaded = 0;
	glGetObjectParameterivAPPLE = (PFNGLGETOBJECTPARAMETERIVAPPLEPROC)gleIntGetProcAddress("glGetObjectParameterivAPPLE");
	if(!glGetObjectParameterivAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_object_purgeable*/
	return bIsLoaded;
}



#ifndef GL_APPLE_texture_range
typedef void (GLE_FUNCPTR * PFNGLTEXTURERANGEAPPLEPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)(GLenum , GLenum , GLvoid* *);

PFNGLTEXTURERANGEAPPLEPROC glTextureRangeAPPLE;
PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC glGetTexParameterPointervAPPLE;
#endif /*GL_APPLE_texture_range*/

static int gleIntLoad_APPLE_texture_range()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_texture_range
	glTextureRangeAPPLE = (PFNGLTEXTURERANGEAPPLEPROC)gleIntGetProcAddress("glTextureRangeAPPLE");
	if(!glTextureRangeAPPLE) bIsLoaded = 0;
	glGetTexParameterPointervAPPLE = (PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)gleIntGetProcAddress("glGetTexParameterPointervAPPLE");
	if(!glGetTexParameterPointervAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_texture_range*/
	return bIsLoaded;
}

#ifndef GL_APPLE_vertex_array_object
typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXARRAYAPPLEPROC)(GLuint );

PFNGLBINDVERTEXARRAYAPPLEPROC glBindVertexArrayAPPLE;
PFNGLDELETEVERTEXARRAYSAPPLEPROC glDeleteVertexArraysAPPLE;
PFNGLGENVERTEXARRAYSAPPLEPROC glGenVertexArraysAPPLE;
PFNGLISVERTEXARRAYAPPLEPROC glIsVertexArrayAPPLE;
#endif /*GL_APPLE_vertex_array_object*/

static int gleIntLoad_APPLE_vertex_array_object()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_vertex_array_object
	glBindVertexArrayAPPLE = (PFNGLBINDVERTEXARRAYAPPLEPROC)gleIntGetProcAddress("glBindVertexArrayAPPLE");
	if(!glBindVertexArrayAPPLE) bIsLoaded = 0;
	glDeleteVertexArraysAPPLE = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)gleIntGetProcAddress("glDeleteVertexArraysAPPLE");
	if(!glDeleteVertexArraysAPPLE) bIsLoaded = 0;
	glGenVertexArraysAPPLE = (PFNGLGENVERTEXARRAYSAPPLEPROC)gleIntGetProcAddress("glGenVertexArraysAPPLE");
	if(!glGenVertexArraysAPPLE) bIsLoaded = 0;
	glIsVertexArrayAPPLE = (PFNGLISVERTEXARRAYAPPLEPROC)gleIntGetProcAddress("glIsVertexArrayAPPLE");
	if(!glIsVertexArrayAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_vertex_array_object*/
	return bIsLoaded;
}
#ifndef GL_APPLE_vertex_array_range
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum , GLint );

PFNGLVERTEXARRAYRANGEAPPLEPROC glVertexArrayRangeAPPLE;
PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glFlushVertexArrayRangeAPPLE;
PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glVertexArrayParameteriAPPLE;
#endif /*GL_APPLE_vertex_array_range*/

static int gleIntLoad_APPLE_vertex_array_range()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_vertex_array_range
	glVertexArrayRangeAPPLE = (PFNGLVERTEXARRAYRANGEAPPLEPROC)gleIntGetProcAddress("glVertexArrayRangeAPPLE");
	if(!glVertexArrayRangeAPPLE) bIsLoaded = 0;
	glFlushVertexArrayRangeAPPLE = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)gleIntGetProcAddress("glFlushVertexArrayRangeAPPLE");
	if(!glFlushVertexArrayRangeAPPLE) bIsLoaded = 0;
	glVertexArrayParameteriAPPLE = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)gleIntGetProcAddress("glVertexArrayParameteriAPPLE");
	if(!glVertexArrayParameteriAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_vertex_array_range*/
	return bIsLoaded;
}
#ifndef GL_APPLE_vertex_program_evaluators
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXATTRIBAPPLEPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXATTRIBAPPLEPROC)(GLuint , GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB1DAPPLEPROC)(GLuint , GLuint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB1FAPPLEPROC)(GLuint , GLuint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB2DAPPLEPROC)(GLuint , GLuint , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB2FAPPLEPROC)(GLuint , GLuint , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);

PFNGLENABLEVERTEXATTRIBAPPLEPROC glEnableVertexAttribAPPLE;
PFNGLDISABLEVERTEXATTRIBAPPLEPROC glDisableVertexAttribAPPLE;
PFNGLISVERTEXATTRIBENABLEDAPPLEPROC glIsVertexAttribEnabledAPPLE;
PFNGLMAPVERTEXATTRIB1DAPPLEPROC glMapVertexAttrib1dAPPLE;
PFNGLMAPVERTEXATTRIB1FAPPLEPROC glMapVertexAttrib1fAPPLE;
PFNGLMAPVERTEXATTRIB2DAPPLEPROC glMapVertexAttrib2dAPPLE;
PFNGLMAPVERTEXATTRIB2FAPPLEPROC glMapVertexAttrib2fAPPLE;
#endif /*GL_APPLE_vertex_program_evaluators*/

static int gleIntLoad_APPLE_vertex_program_evaluators()
{
	int bIsLoaded = 1;
#ifndef GL_APPLE_vertex_program_evaluators
	glEnableVertexAttribAPPLE = (PFNGLENABLEVERTEXATTRIBAPPLEPROC)gleIntGetProcAddress("glEnableVertexAttribAPPLE");
	if(!glEnableVertexAttribAPPLE) bIsLoaded = 0;
	glDisableVertexAttribAPPLE = (PFNGLDISABLEVERTEXATTRIBAPPLEPROC)gleIntGetProcAddress("glDisableVertexAttribAPPLE");
	if(!glDisableVertexAttribAPPLE) bIsLoaded = 0;
	glIsVertexAttribEnabledAPPLE = (PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)gleIntGetProcAddress("glIsVertexAttribEnabledAPPLE");
	if(!glIsVertexAttribEnabledAPPLE) bIsLoaded = 0;
	glMapVertexAttrib1dAPPLE = (PFNGLMAPVERTEXATTRIB1DAPPLEPROC)gleIntGetProcAddress("glMapVertexAttrib1dAPPLE");
	if(!glMapVertexAttrib1dAPPLE) bIsLoaded = 0;
	glMapVertexAttrib1fAPPLE = (PFNGLMAPVERTEXATTRIB1FAPPLEPROC)gleIntGetProcAddress("glMapVertexAttrib1fAPPLE");
	if(!glMapVertexAttrib1fAPPLE) bIsLoaded = 0;
	glMapVertexAttrib2dAPPLE = (PFNGLMAPVERTEXATTRIB2DAPPLEPROC)gleIntGetProcAddress("glMapVertexAttrib2dAPPLE");
	if(!glMapVertexAttrib2dAPPLE) bIsLoaded = 0;
	glMapVertexAttrib2fAPPLE = (PFNGLMAPVERTEXATTRIB2FAPPLEPROC)gleIntGetProcAddress("glMapVertexAttrib2fAPPLE");
	if(!glMapVertexAttrib2fAPPLE) bIsLoaded = 0;
#endif /*GL_APPLE_vertex_program_evaluators*/
	return bIsLoaded;
}

#ifndef GL_ARB_ES2_compatibility
typedef void (GLE_FUNCPTR * PFNGLRELEASESHADERCOMPILERPROC)();
typedef void (GLE_FUNCPTR * PFNGLSHADERBINARYPROC)(GLsizei , const GLuint *, GLenum , const GLvoid *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum , GLenum , GLint *, GLint *);
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEFPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHFPROC)(GLfloat );

PFNGLRELEASESHADERCOMPILERPROC __gleReleaseShaderCompiler;
PFNGLSHADERBINARYPROC __gleShaderBinary;
PFNGLGETSHADERPRECISIONFORMATPROC __gleGetShaderPrecisionFormat;
PFNGLDEPTHRANGEFPROC __gleDepthRangef;
PFNGLCLEARDEPTHFPROC __gleClearDepthf;
#endif /*GL_ARB_ES2_compatibility*/

static int gleIntLoad_ARB_ES2_compatibility()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_ES2_compatibility
	__gleReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)gleIntGetProcAddress("glReleaseShaderCompiler");
	if(!__gleReleaseShaderCompiler) bIsLoaded = 0;
	__gleShaderBinary = (PFNGLSHADERBINARYPROC)gleIntGetProcAddress("glShaderBinary");
	if(!__gleShaderBinary) bIsLoaded = 0;
	__gleGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)gleIntGetProcAddress("glGetShaderPrecisionFormat");
	if(!__gleGetShaderPrecisionFormat) bIsLoaded = 0;
	__gleDepthRangef = (PFNGLDEPTHRANGEFPROC)gleIntGetProcAddress("glDepthRangef");
	if(!__gleDepthRangef) bIsLoaded = 0;
	__gleClearDepthf = (PFNGLCLEARDEPTHFPROC)gleIntGetProcAddress("glClearDepthf");
	if(!__gleClearDepthf) bIsLoaded = 0;
#endif /*GL_ARB_ES2_compatibility*/
	return bIsLoaded;
}


#ifndef GL_ARB_base_instance
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum , GLint , GLsizei , GLsizei , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum , GLsizei , GLenum , const void *, GLsizei , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum , GLsizei , GLenum , const void *, GLsizei , GLint , GLuint );

PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC __gleDrawArraysInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC __gleDrawElementsInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC __gleDrawElementsInstancedBaseVertexBaseInstance;
#endif /*GL_ARB_base_instance*/

static int gleIntLoad_ARB_base_instance()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_base_instance
	__gleDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)gleIntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!__gleDrawArraysInstancedBaseInstance) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!__gleDrawElementsInstancedBaseInstance) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!__gleDrawElementsInstancedBaseVertexBaseInstance) bIsLoaded = 0;
#endif /*GL_ARB_base_instance*/
	return bIsLoaded;
}
#ifndef GL_ARB_blend_func_extended
typedef void (GLE_FUNCPTR * PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint , GLuint , GLuint , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETFRAGDATAINDEXPROC)(GLuint , const GLchar *);

PFNGLBINDFRAGDATALOCATIONINDEXEDPROC __gleBindFragDataLocationIndexed;
PFNGLGETFRAGDATAINDEXPROC __gleGetFragDataIndex;
#endif /*GL_ARB_blend_func_extended*/

static int gleIntLoad_ARB_blend_func_extended()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_blend_func_extended
	__gleBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)gleIntGetProcAddress("glBindFragDataLocationIndexed");
	if(!__gleBindFragDataLocationIndexed) bIsLoaded = 0;
	__gleGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)gleIntGetProcAddress("glGetFragDataIndex");
	if(!__gleGetFragDataIndex) bIsLoaded = 0;
#endif /*GL_ARB_blend_func_extended*/
	return bIsLoaded;
}
#ifndef GL_ARB_cl_event
typedef GLsync (GLE_FUNCPTR * PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context * , struct _cl_event * , GLbitfield );

PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB;
#endif /*GL_ARB_cl_event*/

static int gleIntLoad_ARB_cl_event()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_cl_event
	glCreateSyncFromCLeventARB = (PFNGLCREATESYNCFROMCLEVENTARBPROC)gleIntGetProcAddress("glCreateSyncFromCLeventARB");
	if(!glCreateSyncFromCLeventARB) bIsLoaded = 0;
#endif /*GL_ARB_cl_event*/
	return bIsLoaded;
}
#ifndef GL_ARB_clear_buffer_object
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERDATAPROC)(GLenum , GLenum , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERSUBDATAPROC)(GLenum , GLenum , GLintptr , GLsizeiptr , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint , GLenum , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint , GLenum , GLenum , GLenum , GLsizeiptr , GLsizeiptr , const void *);

PFNGLCLEARBUFFERDATAPROC __gleClearBufferData;
PFNGLCLEARBUFFERSUBDATAPROC __gleClearBufferSubData;
PFNGLCLEARNAMEDBUFFERDATAEXTPROC __gleClearNamedBufferDataEXT;
PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC __gleClearNamedBufferSubDataEXT;
#endif /*GL_ARB_clear_buffer_object*/

static int gleIntLoad_ARB_clear_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_clear_buffer_object
	__gleClearBufferData = (PFNGLCLEARBUFFERDATAPROC)gleIntGetProcAddress("glClearBufferData");
	if(!__gleClearBufferData) bIsLoaded = 0;
	__gleClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)gleIntGetProcAddress("glClearBufferSubData");
	if(!__gleClearBufferSubData) bIsLoaded = 0;
	__gleClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)gleIntGetProcAddress("glClearNamedBufferDataEXT");
	if(!__gleClearNamedBufferDataEXT) bIsLoaded = 0;
	__gleClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)gleIntGetProcAddress("glClearNamedBufferSubDataEXT");
	if(!__gleClearNamedBufferSubDataEXT) bIsLoaded = 0;
#endif /*GL_ARB_clear_buffer_object*/
	return bIsLoaded;
}
#ifndef GL_ARB_color_buffer_float
typedef void (GLE_FUNCPTR * PFNGLCLAMPCOLORARBPROC)(GLenum , GLenum );

PFNGLCLAMPCOLORARBPROC glClampColorARB;
#endif /*GL_ARB_color_buffer_float*/

static int gleIntLoad_ARB_color_buffer_float()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_color_buffer_float
	glClampColorARB = (PFNGLCLAMPCOLORARBPROC)gleIntGetProcAddress("glClampColorARB");
	if(!glClampColorARB) bIsLoaded = 0;
#endif /*GL_ARB_color_buffer_float*/
	return bIsLoaded;
}


#ifndef GL_ARB_compute_shader
typedef void (GLE_FUNCPTR * PFNGLDISPATCHCOMPUTEPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr );

PFNGLDISPATCHCOMPUTEPROC __gleDispatchCompute;
PFNGLDISPATCHCOMPUTEINDIRECTPROC __gleDispatchComputeIndirect;
#endif /*GL_ARB_compute_shader*/

static int gleIntLoad_ARB_compute_shader()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_compute_shader
	__gleDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)gleIntGetProcAddress("glDispatchCompute");
	if(!__gleDispatchCompute) bIsLoaded = 0;
	__gleDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)gleIntGetProcAddress("glDispatchComputeIndirect");
	if(!__gleDispatchComputeIndirect) bIsLoaded = 0;
#endif /*GL_ARB_compute_shader*/
	return bIsLoaded;
}

#ifndef GL_ARB_copy_buffer
typedef void (GLE_FUNCPTR * PFNGLCOPYBUFFERSUBDATAPROC)(GLenum , GLenum , GLintptr , GLintptr , GLsizeiptr );

PFNGLCOPYBUFFERSUBDATAPROC __gleCopyBufferSubData;
#endif /*GL_ARB_copy_buffer*/

static int gleIntLoad_ARB_copy_buffer()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_copy_buffer
	__gleCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)gleIntGetProcAddress("glCopyBufferSubData");
	if(!__gleCopyBufferSubData) bIsLoaded = 0;
#endif /*GL_ARB_copy_buffer*/
	return bIsLoaded;
}
#ifndef GL_ARB_copy_image
typedef void (GLE_FUNCPTR * PFNGLCOPYIMAGESUBDATAPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

PFNGLCOPYIMAGESUBDATAPROC __gleCopyImageSubData;
#endif /*GL_ARB_copy_image*/

static int gleIntLoad_ARB_copy_image()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_copy_image
	__gleCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)gleIntGetProcAddress("glCopyImageSubData");
	if(!__gleCopyImageSubData) bIsLoaded = 0;
#endif /*GL_ARB_copy_image*/
	return bIsLoaded;
}


#ifndef GL_ARB_debug_output
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum , GLenum , GLenum , GLsizei , const GLuint *, GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum , GLenum , GLuint , GLenum , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB , const GLvoid *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint , GLsizei , GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);

PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB;
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB;
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB;
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB;
#endif /*GL_ARB_debug_output*/

static int gleIntLoad_ARB_debug_output()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_debug_output
	glDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLARBPROC)gleIntGetProcAddress("glDebugMessageControlARB");
	if(!glDebugMessageControlARB) bIsLoaded = 0;
	glDebugMessageInsertARB = (PFNGLDEBUGMESSAGEINSERTARBPROC)gleIntGetProcAddress("glDebugMessageInsertARB");
	if(!glDebugMessageInsertARB) bIsLoaded = 0;
	glDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKARBPROC)gleIntGetProcAddress("glDebugMessageCallbackARB");
	if(!glDebugMessageCallbackARB) bIsLoaded = 0;
	glGetDebugMessageLogARB = (PFNGLGETDEBUGMESSAGELOGARBPROC)gleIntGetProcAddress("glGetDebugMessageLogARB");
	if(!glGetDebugMessageLogARB) bIsLoaded = 0;
#endif /*GL_ARB_debug_output*/
	return bIsLoaded;
}




#ifndef GL_ARB_draw_buffers
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSARBPROC)(GLsizei , const GLenum *);

PFNGLDRAWBUFFERSARBPROC glDrawBuffersARB;
#endif /*GL_ARB_draw_buffers*/

static int gleIntLoad_ARB_draw_buffers()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_draw_buffers
	glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC)gleIntGetProcAddress("glDrawBuffersARB");
	if(!glDrawBuffersARB) bIsLoaded = 0;
#endif /*GL_ARB_draw_buffers*/
	return bIsLoaded;
}
#ifndef GL_ARB_draw_buffers_blend
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONIARBPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCIARBPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );

PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB;
PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB;
PFNGLBLENDFUNCIARBPROC glBlendFunciARB;
PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB;
#endif /*GL_ARB_draw_buffers_blend*/

static int gleIntLoad_ARB_draw_buffers_blend()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_draw_buffers_blend
	glBlendEquationiARB = (PFNGLBLENDEQUATIONIARBPROC)gleIntGetProcAddress("glBlendEquationiARB");
	if(!glBlendEquationiARB) bIsLoaded = 0;
	glBlendEquationSeparateiARB = (PFNGLBLENDEQUATIONSEPARATEIARBPROC)gleIntGetProcAddress("glBlendEquationSeparateiARB");
	if(!glBlendEquationSeparateiARB) bIsLoaded = 0;
	glBlendFunciARB = (PFNGLBLENDFUNCIARBPROC)gleIntGetProcAddress("glBlendFunciARB");
	if(!glBlendFunciARB) bIsLoaded = 0;
	glBlendFuncSeparateiARB = (PFNGLBLENDFUNCSEPARATEIARBPROC)gleIntGetProcAddress("glBlendFuncSeparateiARB");
	if(!glBlendFuncSeparateiARB) bIsLoaded = 0;
#endif /*GL_ARB_draw_buffers_blend*/
	return bIsLoaded;
}
#ifndef GL_ARB_draw_elements_base_vertex
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLint );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *, GLint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei , const GLint *);

PFNGLDRAWELEMENTSBASEVERTEXPROC __gleDrawElementsBaseVertex;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC __gleDrawRangeElementsBaseVertex;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC __gleDrawElementsInstancedBaseVertex;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC __gleMultiDrawElementsBaseVertex;
#endif /*GL_ARB_draw_elements_base_vertex*/

static int gleIntLoad_ARB_draw_elements_base_vertex()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_draw_elements_base_vertex
	__gleDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glDrawElementsBaseVertex");
	if(!__gleDrawElementsBaseVertex) bIsLoaded = 0;
	__gleDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!__gleDrawRangeElementsBaseVertex) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!__gleDrawElementsInstancedBaseVertex) bIsLoaded = 0;
	__gleMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!__gleMultiDrawElementsBaseVertex) bIsLoaded = 0;
#endif /*GL_ARB_draw_elements_base_vertex*/
	return bIsLoaded;
}
#ifndef GL_ARB_draw_indirect
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINDIRECTPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum , GLenum , const GLvoid *);

PFNGLDRAWARRAYSINDIRECTPROC __gleDrawArraysIndirect;
PFNGLDRAWELEMENTSINDIRECTPROC __gleDrawElementsIndirect;
#endif /*GL_ARB_draw_indirect*/

static int gleIntLoad_ARB_draw_indirect()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_draw_indirect
	__gleDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)gleIntGetProcAddress("glDrawArraysIndirect");
	if(!__gleDrawArraysIndirect) bIsLoaded = 0;
	__gleDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)gleIntGetProcAddress("glDrawElementsIndirect");
	if(!__gleDrawElementsIndirect) bIsLoaded = 0;
#endif /*GL_ARB_draw_indirect*/
	return bIsLoaded;
}
#ifndef GL_ARB_draw_instanced
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );

PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARB;
PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARB;
#endif /*GL_ARB_draw_instanced*/

static int gleIntLoad_ARB_draw_instanced()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_draw_instanced
	glDrawArraysInstancedARB = (PFNGLDRAWARRAYSINSTANCEDARBPROC)gleIntGetProcAddress("glDrawArraysInstancedARB");
	if(!glDrawArraysInstancedARB) bIsLoaded = 0;
	glDrawElementsInstancedARB = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)gleIntGetProcAddress("glDrawElementsInstancedARB");
	if(!glDrawElementsInstancedARB) bIsLoaded = 0;
#endif /*GL_ARB_draw_instanced*/
	return bIsLoaded;
}







#ifndef GL_ARB_framebuffer_no_attachments
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint , GLenum , GLint *);

PFNGLFRAMEBUFFERPARAMETERIPROC __gleFramebufferParameteri;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC __gleGetFramebufferParameteriv;
PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC __gleNamedFramebufferParameteriEXT;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC __gleGetNamedFramebufferParameterivEXT;
#endif /*GL_ARB_framebuffer_no_attachments*/

static int gleIntLoad_ARB_framebuffer_no_attachments()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_framebuffer_no_attachments
	__gleFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)gleIntGetProcAddress("glFramebufferParameteri");
	if(!__gleFramebufferParameteri) bIsLoaded = 0;
	__gleGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)gleIntGetProcAddress("glGetFramebufferParameteriv");
	if(!__gleGetFramebufferParameteriv) bIsLoaded = 0;
	__gleNamedFramebufferParameteriEXT = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)gleIntGetProcAddress("glNamedFramebufferParameteriEXT");
	if(!__gleNamedFramebufferParameteriEXT) bIsLoaded = 0;
	__gleGetNamedFramebufferParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetNamedFramebufferParameterivEXT");
	if(!__gleGetNamedFramebufferParameterivEXT) bIsLoaded = 0;
#endif /*GL_ARB_framebuffer_no_attachments*/
	return bIsLoaded;
}
#ifndef GL_ARB_framebuffer_object
typedef GLboolean (GLE_FUNCPTR * PFNGLISRENDERBUFFERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDRENDERBUFFERPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETERENDERBUFFERSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENRENDERBUFFERSPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEPROC)(GLenum , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISFRAMEBUFFERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDFRAMEBUFFERPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENFRAMEBUFFERSPROC)(GLsizei , GLuint *);
typedef GLenum (GLE_FUNCPTR * PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE1DPROC)(GLenum , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE3DPROC)(GLenum , GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGENERATEMIPMAPPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLITFRAMEBUFFERPROC)(GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );
typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum , GLenum , GLuint , GLint , GLint );

PFNGLISRENDERBUFFERPROC __gleIsRenderbuffer;
PFNGLBINDRENDERBUFFERPROC __gleBindRenderbuffer;
PFNGLDELETERENDERBUFFERSPROC __gleDeleteRenderbuffers;
PFNGLGENRENDERBUFFERSPROC __gleGenRenderbuffers;
PFNGLRENDERBUFFERSTORAGEPROC __gleRenderbufferStorage;
PFNGLGETRENDERBUFFERPARAMETERIVPROC __gleGetRenderbufferParameteriv;
PFNGLISFRAMEBUFFERPROC __gleIsFramebuffer;
PFNGLBINDFRAMEBUFFERPROC __gleBindFramebuffer;
PFNGLDELETEFRAMEBUFFERSPROC __gleDeleteFramebuffers;
PFNGLGENFRAMEBUFFERSPROC __gleGenFramebuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC __gleCheckFramebufferStatus;
PFNGLFRAMEBUFFERTEXTURE1DPROC __gleFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC __gleFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC __gleFramebufferTexture3D;
PFNGLFRAMEBUFFERRENDERBUFFERPROC __gleFramebufferRenderbuffer;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC __gleGetFramebufferAttachmentParameteriv;
PFNGLGENERATEMIPMAPPROC __gleGenerateMipmap;
PFNGLBLITFRAMEBUFFERPROC __gleBlitFramebuffer;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC __gleRenderbufferStorageMultisample;
PFNGLFRAMEBUFFERTEXTURELAYERPROC __gleFramebufferTextureLayer;
#endif /*GL_ARB_framebuffer_object*/

static int gleIntLoad_ARB_framebuffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_framebuffer_object
	__gleIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)gleIntGetProcAddress("glIsRenderbuffer");
	if(!__gleIsRenderbuffer) bIsLoaded = 0;
	__gleBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)gleIntGetProcAddress("glBindRenderbuffer");
	if(!__gleBindRenderbuffer) bIsLoaded = 0;
	__gleDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)gleIntGetProcAddress("glDeleteRenderbuffers");
	if(!__gleDeleteRenderbuffers) bIsLoaded = 0;
	__gleGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)gleIntGetProcAddress("glGenRenderbuffers");
	if(!__gleGenRenderbuffers) bIsLoaded = 0;
	__gleRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)gleIntGetProcAddress("glRenderbufferStorage");
	if(!__gleRenderbufferStorage) bIsLoaded = 0;
	__gleGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)gleIntGetProcAddress("glGetRenderbufferParameteriv");
	if(!__gleGetRenderbufferParameteriv) bIsLoaded = 0;
	__gleIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)gleIntGetProcAddress("glIsFramebuffer");
	if(!__gleIsFramebuffer) bIsLoaded = 0;
	__gleBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)gleIntGetProcAddress("glBindFramebuffer");
	if(!__gleBindFramebuffer) bIsLoaded = 0;
	__gleDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)gleIntGetProcAddress("glDeleteFramebuffers");
	if(!__gleDeleteFramebuffers) bIsLoaded = 0;
	__gleGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)gleIntGetProcAddress("glGenFramebuffers");
	if(!__gleGenFramebuffers) bIsLoaded = 0;
	__gleCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)gleIntGetProcAddress("glCheckFramebufferStatus");
	if(!__gleCheckFramebufferStatus) bIsLoaded = 0;
	__gleFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)gleIntGetProcAddress("glFramebufferTexture1D");
	if(!__gleFramebufferTexture1D) bIsLoaded = 0;
	__gleFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)gleIntGetProcAddress("glFramebufferTexture2D");
	if(!__gleFramebufferTexture2D) bIsLoaded = 0;
	__gleFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)gleIntGetProcAddress("glFramebufferTexture3D");
	if(!__gleFramebufferTexture3D) bIsLoaded = 0;
	__gleFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)gleIntGetProcAddress("glFramebufferRenderbuffer");
	if(!__gleFramebufferRenderbuffer) bIsLoaded = 0;
	__gleGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)gleIntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!__gleGetFramebufferAttachmentParameteriv) bIsLoaded = 0;
	__gleGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)gleIntGetProcAddress("glGenerateMipmap");
	if(!__gleGenerateMipmap) bIsLoaded = 0;
	__gleBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)gleIntGetProcAddress("glBlitFramebuffer");
	if(!__gleBlitFramebuffer) bIsLoaded = 0;
	__gleRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)gleIntGetProcAddress("glRenderbufferStorageMultisample");
	if(!__gleRenderbufferStorageMultisample) bIsLoaded = 0;
	__gleFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)gleIntGetProcAddress("glFramebufferTextureLayer");
	if(!__gleFramebufferTextureLayer) bIsLoaded = 0;
#endif /*GL_ARB_framebuffer_object*/
	return bIsLoaded;
}

#ifndef GL_ARB_geometry_shader4
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIARBPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum , GLenum , GLuint , GLint , GLenum );

PFNGLPROGRAMPARAMETERIARBPROC glProgramParameteriARB;
PFNGLFRAMEBUFFERTEXTUREARBPROC glFramebufferTextureARB;
PFNGLFRAMEBUFFERTEXTURELAYERARBPROC glFramebufferTextureLayerARB;
PFNGLFRAMEBUFFERTEXTUREFACEARBPROC glFramebufferTextureFaceARB;
#endif /*GL_ARB_geometry_shader4*/

static int gleIntLoad_ARB_geometry_shader4()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_geometry_shader4
	glProgramParameteriARB = (PFNGLPROGRAMPARAMETERIARBPROC)gleIntGetProcAddress("glProgramParameteriARB");
	if(!glProgramParameteriARB) bIsLoaded = 0;
	glFramebufferTextureARB = (PFNGLFRAMEBUFFERTEXTUREARBPROC)gleIntGetProcAddress("glFramebufferTextureARB");
	if(!glFramebufferTextureARB) bIsLoaded = 0;
	glFramebufferTextureLayerARB = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)gleIntGetProcAddress("glFramebufferTextureLayerARB");
	if(!glFramebufferTextureLayerARB) bIsLoaded = 0;
	glFramebufferTextureFaceARB = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)gleIntGetProcAddress("glFramebufferTextureFaceARB");
	if(!glFramebufferTextureFaceARB) bIsLoaded = 0;
#endif /*GL_ARB_geometry_shader4*/
	return bIsLoaded;
}
#ifndef GL_ARB_get_program_binary
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMBINARYPROC)(GLuint , GLsizei , GLsizei *, GLenum *, GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBINARYPROC)(GLuint , GLenum , const GLvoid *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIPROC)(GLuint , GLenum , GLint );

PFNGLGETPROGRAMBINARYPROC __gleGetProgramBinary;
PFNGLPROGRAMBINARYPROC __gleProgramBinary;
PFNGLPROGRAMPARAMETERIPROC __gleProgramParameteri;
#endif /*GL_ARB_get_program_binary*/

static int gleIntLoad_ARB_get_program_binary()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_get_program_binary
	__gleGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)gleIntGetProcAddress("glGetProgramBinary");
	if(!__gleGetProgramBinary) bIsLoaded = 0;
	__gleProgramBinary = (PFNGLPROGRAMBINARYPROC)gleIntGetProcAddress("glProgramBinary");
	if(!__gleProgramBinary) bIsLoaded = 0;
	__gleProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)gleIntGetProcAddress("glProgramParameteri");
	if(!__gleProgramParameteri) bIsLoaded = 0;
#endif /*GL_ARB_get_program_binary*/
	return bIsLoaded;
}

#ifndef GL_ARB_gpu_shader_fp64
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1DPROC)(GLint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2DPROC)(GLint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3DPROC)(GLint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4DPROC)(GLint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1DVPROC)(GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2DVPROC)(GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3DVPROC)(GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4DVPROC)(GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2X3DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2X4DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3X2DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3X4DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4X2DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4X3DVPROC)(GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMDVPROC)(GLuint , GLint , GLdouble *);

PFNGLUNIFORM1DPROC __gleUniform1d;
PFNGLUNIFORM2DPROC __gleUniform2d;
PFNGLUNIFORM3DPROC __gleUniform3d;
PFNGLUNIFORM4DPROC __gleUniform4d;
PFNGLUNIFORM1DVPROC __gleUniform1dv;
PFNGLUNIFORM2DVPROC __gleUniform2dv;
PFNGLUNIFORM3DVPROC __gleUniform3dv;
PFNGLUNIFORM4DVPROC __gleUniform4dv;
PFNGLUNIFORMMATRIX2DVPROC __gleUniformMatrix2dv;
PFNGLUNIFORMMATRIX3DVPROC __gleUniformMatrix3dv;
PFNGLUNIFORMMATRIX4DVPROC __gleUniformMatrix4dv;
PFNGLUNIFORMMATRIX2X3DVPROC __gleUniformMatrix2x3dv;
PFNGLUNIFORMMATRIX2X4DVPROC __gleUniformMatrix2x4dv;
PFNGLUNIFORMMATRIX3X2DVPROC __gleUniformMatrix3x2dv;
PFNGLUNIFORMMATRIX3X4DVPROC __gleUniformMatrix3x4dv;
PFNGLUNIFORMMATRIX4X2DVPROC __gleUniformMatrix4x2dv;
PFNGLUNIFORMMATRIX4X3DVPROC __gleUniformMatrix4x3dv;
PFNGLGETUNIFORMDVPROC __gleGetUniformdv;
#endif /*GL_ARB_gpu_shader_fp64*/

static int gleIntLoad_ARB_gpu_shader_fp64()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_gpu_shader_fp64
	__gleUniform1d = (PFNGLUNIFORM1DPROC)gleIntGetProcAddress("glUniform1d");
	if(!__gleUniform1d) bIsLoaded = 0;
	__gleUniform2d = (PFNGLUNIFORM2DPROC)gleIntGetProcAddress("glUniform2d");
	if(!__gleUniform2d) bIsLoaded = 0;
	__gleUniform3d = (PFNGLUNIFORM3DPROC)gleIntGetProcAddress("glUniform3d");
	if(!__gleUniform3d) bIsLoaded = 0;
	__gleUniform4d = (PFNGLUNIFORM4DPROC)gleIntGetProcAddress("glUniform4d");
	if(!__gleUniform4d) bIsLoaded = 0;
	__gleUniform1dv = (PFNGLUNIFORM1DVPROC)gleIntGetProcAddress("glUniform1dv");
	if(!__gleUniform1dv) bIsLoaded = 0;
	__gleUniform2dv = (PFNGLUNIFORM2DVPROC)gleIntGetProcAddress("glUniform2dv");
	if(!__gleUniform2dv) bIsLoaded = 0;
	__gleUniform3dv = (PFNGLUNIFORM3DVPROC)gleIntGetProcAddress("glUniform3dv");
	if(!__gleUniform3dv) bIsLoaded = 0;
	__gleUniform4dv = (PFNGLUNIFORM4DVPROC)gleIntGetProcAddress("glUniform4dv");
	if(!__gleUniform4dv) bIsLoaded = 0;
	__gleUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)gleIntGetProcAddress("glUniformMatrix2dv");
	if(!__gleUniformMatrix2dv) bIsLoaded = 0;
	__gleUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)gleIntGetProcAddress("glUniformMatrix3dv");
	if(!__gleUniformMatrix3dv) bIsLoaded = 0;
	__gleUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)gleIntGetProcAddress("glUniformMatrix4dv");
	if(!__gleUniformMatrix4dv) bIsLoaded = 0;
	__gleUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)gleIntGetProcAddress("glUniformMatrix2x3dv");
	if(!__gleUniformMatrix2x3dv) bIsLoaded = 0;
	__gleUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)gleIntGetProcAddress("glUniformMatrix2x4dv");
	if(!__gleUniformMatrix2x4dv) bIsLoaded = 0;
	__gleUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)gleIntGetProcAddress("glUniformMatrix3x2dv");
	if(!__gleUniformMatrix3x2dv) bIsLoaded = 0;
	__gleUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)gleIntGetProcAddress("glUniformMatrix3x4dv");
	if(!__gleUniformMatrix3x4dv) bIsLoaded = 0;
	__gleUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)gleIntGetProcAddress("glUniformMatrix4x2dv");
	if(!__gleUniformMatrix4x2dv) bIsLoaded = 0;
	__gleUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)gleIntGetProcAddress("glUniformMatrix4x3dv");
	if(!__gleUniformMatrix4x3dv) bIsLoaded = 0;
	__gleGetUniformdv = (PFNGLGETUNIFORMDVPROC)gleIntGetProcAddress("glGetUniformdv");
	if(!__gleGetUniformdv) bIsLoaded = 0;
#endif /*GL_ARB_gpu_shader_fp64*/
	return bIsLoaded;
}



#ifndef GL_ARB_instanced_arrays
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint , GLuint );

PFNGLVERTEXATTRIBDIVISORARBPROC glVertexAttribDivisorARB;
#endif /*GL_ARB_instanced_arrays*/

static int gleIntLoad_ARB_instanced_arrays()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_instanced_arrays
	glVertexAttribDivisorARB = (PFNGLVERTEXATTRIBDIVISORARBPROC)gleIntGetProcAddress("glVertexAttribDivisorARB");
	if(!glVertexAttribDivisorARB) bIsLoaded = 0;
#endif /*GL_ARB_instanced_arrays*/
	return bIsLoaded;
}
#ifndef GL_ARB_internalformat_query
typedef void (GLE_FUNCPTR * PFNGLGETINTERNALFORMATIVPROC)(GLenum , GLenum , GLenum , GLsizei , GLint *);

PFNGLGETINTERNALFORMATIVPROC __gleGetInternalformativ;
#endif /*GL_ARB_internalformat_query*/

static int gleIntLoad_ARB_internalformat_query()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_internalformat_query
	__gleGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)gleIntGetProcAddress("glGetInternalformativ");
	if(!__gleGetInternalformativ) bIsLoaded = 0;
#endif /*GL_ARB_internalformat_query*/
	return bIsLoaded;
}
#ifndef GL_ARB_internalformat_query2
typedef void (GLE_FUNCPTR * PFNGLGETINTERNALFORMATI64VPROC)(GLenum , GLenum , GLenum , GLsizei , GLint64 *);

PFNGLGETINTERNALFORMATI64VPROC __gleGetInternalformati64v;
#endif /*GL_ARB_internalformat_query2*/

static int gleIntLoad_ARB_internalformat_query2()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_internalformat_query2
	__gleGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)gleIntGetProcAddress("glGetInternalformati64v");
	if(!__gleGetInternalformati64v) bIsLoaded = 0;
#endif /*GL_ARB_internalformat_query2*/
	return bIsLoaded;
}
#ifndef GL_ARB_invalidate_subdata
typedef void (GLE_FUNCPTR * PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATETEXIMAGEPROC)(GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEBUFFERDATAPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum , GLsizei , const GLenum *);
typedef void (GLE_FUNCPTR * PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum , GLsizei , const GLenum *, GLint , GLint , GLsizei , GLsizei );

PFNGLINVALIDATETEXSUBIMAGEPROC __gleInvalidateTexSubImage;
PFNGLINVALIDATETEXIMAGEPROC __gleInvalidateTexImage;
PFNGLINVALIDATEBUFFERSUBDATAPROC __gleInvalidateBufferSubData;
PFNGLINVALIDATEBUFFERDATAPROC __gleInvalidateBufferData;
PFNGLINVALIDATEFRAMEBUFFERPROC __gleInvalidateFramebuffer;
PFNGLINVALIDATESUBFRAMEBUFFERPROC __gleInvalidateSubFramebuffer;
#endif /*GL_ARB_invalidate_subdata*/

static int gleIntLoad_ARB_invalidate_subdata()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_invalidate_subdata
	__gleInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)gleIntGetProcAddress("glInvalidateTexSubImage");
	if(!__gleInvalidateTexSubImage) bIsLoaded = 0;
	__gleInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)gleIntGetProcAddress("glInvalidateTexImage");
	if(!__gleInvalidateTexImage) bIsLoaded = 0;
	__gleInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)gleIntGetProcAddress("glInvalidateBufferSubData");
	if(!__gleInvalidateBufferSubData) bIsLoaded = 0;
	__gleInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)gleIntGetProcAddress("glInvalidateBufferData");
	if(!__gleInvalidateBufferData) bIsLoaded = 0;
	__gleInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)gleIntGetProcAddress("glInvalidateFramebuffer");
	if(!__gleInvalidateFramebuffer) bIsLoaded = 0;
	__gleInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)gleIntGetProcAddress("glInvalidateSubFramebuffer");
	if(!__gleInvalidateSubFramebuffer) bIsLoaded = 0;
#endif /*GL_ARB_invalidate_subdata*/
	return bIsLoaded;
}

#ifndef GL_ARB_map_buffer_range
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPBUFFERRANGEPROC)(GLenum , GLintptr , GLsizeiptr , GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum , GLintptr , GLsizeiptr );

PFNGLMAPBUFFERRANGEPROC __gleMapBufferRange;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC __gleFlushMappedBufferRange;
#endif /*GL_ARB_map_buffer_range*/

static int gleIntLoad_ARB_map_buffer_range()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_map_buffer_range
	__gleMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)gleIntGetProcAddress("glMapBufferRange");
	if(!__gleMapBufferRange) bIsLoaded = 0;
	__gleFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)gleIntGetProcAddress("glFlushMappedBufferRange");
	if(!__gleFlushMappedBufferRange) bIsLoaded = 0;
#endif /*GL_ARB_map_buffer_range*/
	return bIsLoaded;
}
#ifndef GL_ARB_matrix_palette
typedef void (GLE_FUNCPTR * PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUBVARBPROC)(GLint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUSVARBPROC)(GLint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUIVARBPROC)(GLint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXPOINTERARBPROC)(GLint , GLenum , GLsizei , const GLvoid *);

PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARB;
PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARB;
PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARB;
PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARB;
PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARB;
#endif /*GL_ARB_matrix_palette*/

static int gleIntLoad_ARB_matrix_palette()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_matrix_palette
	glCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC)gleIntGetProcAddress("glCurrentPaletteMatrixARB");
	if(!glCurrentPaletteMatrixARB) bIsLoaded = 0;
	glMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC)gleIntGetProcAddress("glMatrixIndexubvARB");
	if(!glMatrixIndexubvARB) bIsLoaded = 0;
	glMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC)gleIntGetProcAddress("glMatrixIndexusvARB");
	if(!glMatrixIndexusvARB) bIsLoaded = 0;
	glMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC)gleIntGetProcAddress("glMatrixIndexuivARB");
	if(!glMatrixIndexuivARB) bIsLoaded = 0;
	glMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC)gleIntGetProcAddress("glMatrixIndexPointerARB");
	if(!glMatrixIndexPointerARB) bIsLoaded = 0;
#endif /*GL_ARB_matrix_palette*/
	return bIsLoaded;
}
#ifndef GL_ARB_multi_draw_indirect
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum , const void *, GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum , GLenum , const void *, GLsizei , GLsizei );

PFNGLMULTIDRAWARRAYSINDIRECTPROC __gleMultiDrawArraysIndirect;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC __gleMultiDrawElementsIndirect;
#endif /*GL_ARB_multi_draw_indirect*/

static int gleIntLoad_ARB_multi_draw_indirect()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_multi_draw_indirect
	__gleMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)gleIntGetProcAddress("glMultiDrawArraysIndirect");
	if(!__gleMultiDrawArraysIndirect) bIsLoaded = 0;
	__gleMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)gleIntGetProcAddress("glMultiDrawElementsIndirect");
	if(!__gleMultiDrawElementsIndirect) bIsLoaded = 0;
#endif /*GL_ARB_multi_draw_indirect*/
	return bIsLoaded;
}
#ifndef GL_ARB_multisample
typedef void (GLE_FUNCPTR * PFNGLSAMPLECOVERAGEARBPROC)(GLfloat , GLboolean );

PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARB;
#endif /*GL_ARB_multisample*/

static int gleIntLoad_ARB_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_multisample
	glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)gleIntGetProcAddress("glSampleCoverageARB");
	if(!glSampleCoverageARB) bIsLoaded = 0;
#endif /*GL_ARB_multisample*/
	return bIsLoaded;
}
#ifndef GL_ARB_multitexture
typedef void (GLE_FUNCPTR * PFNGLACTIVETEXTUREARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DARBPROC)(GLenum , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DVARBPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FARBPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FVARBPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IARBPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IVARBPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SARBPROC)(GLenum , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SVARBPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DARBPROC)(GLenum , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DVARBPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FARBPROC)(GLenum , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FVARBPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IARBPROC)(GLenum , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IVARBPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SARBPROC)(GLenum , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SVARBPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DARBPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DVARBPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FARBPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FVARBPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IARBPROC)(GLenum , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IVARBPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SARBPROC)(GLenum , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SVARBPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DARBPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DVARBPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FARBPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FVARBPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IARBPROC)(GLenum , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IVARBPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SARBPROC)(GLenum , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SVARBPROC)(GLenum , const GLshort *);

PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB;
PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB;
PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB;
PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB;
PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB;
PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB;
PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB;
PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB;
PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB;
PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB;
PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB;
PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;
PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB;
PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB;
PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB;
PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB;
PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB;
PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB;
PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB;
PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB;
PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB;
PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB;
PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB;
PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB;
PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB;
PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB;
PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB;
PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB;
PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB;
PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB;
PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB;
PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB;
#endif /*GL_ARB_multitexture*/

static int gleIntLoad_ARB_multitexture()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_multitexture
	glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)gleIntGetProcAddress("glActiveTextureARB");
	if(!glActiveTextureARB) bIsLoaded = 0;
	glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)gleIntGetProcAddress("glClientActiveTextureARB");
	if(!glClientActiveTextureARB) bIsLoaded = 0;
	glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)gleIntGetProcAddress("glMultiTexCoord1dARB");
	if(!glMultiTexCoord1dARB) bIsLoaded = 0;
	glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)gleIntGetProcAddress("glMultiTexCoord1dvARB");
	if(!glMultiTexCoord1dvARB) bIsLoaded = 0;
	glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)gleIntGetProcAddress("glMultiTexCoord1fARB");
	if(!glMultiTexCoord1fARB) bIsLoaded = 0;
	glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)gleIntGetProcAddress("glMultiTexCoord1fvARB");
	if(!glMultiTexCoord1fvARB) bIsLoaded = 0;
	glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)gleIntGetProcAddress("glMultiTexCoord1iARB");
	if(!glMultiTexCoord1iARB) bIsLoaded = 0;
	glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)gleIntGetProcAddress("glMultiTexCoord1ivARB");
	if(!glMultiTexCoord1ivARB) bIsLoaded = 0;
	glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)gleIntGetProcAddress("glMultiTexCoord1sARB");
	if(!glMultiTexCoord1sARB) bIsLoaded = 0;
	glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)gleIntGetProcAddress("glMultiTexCoord1svARB");
	if(!glMultiTexCoord1svARB) bIsLoaded = 0;
	glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)gleIntGetProcAddress("glMultiTexCoord2dARB");
	if(!glMultiTexCoord2dARB) bIsLoaded = 0;
	glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)gleIntGetProcAddress("glMultiTexCoord2dvARB");
	if(!glMultiTexCoord2dvARB) bIsLoaded = 0;
	glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)gleIntGetProcAddress("glMultiTexCoord2fARB");
	if(!glMultiTexCoord2fARB) bIsLoaded = 0;
	glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)gleIntGetProcAddress("glMultiTexCoord2fvARB");
	if(!glMultiTexCoord2fvARB) bIsLoaded = 0;
	glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)gleIntGetProcAddress("glMultiTexCoord2iARB");
	if(!glMultiTexCoord2iARB) bIsLoaded = 0;
	glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)gleIntGetProcAddress("glMultiTexCoord2ivARB");
	if(!glMultiTexCoord2ivARB) bIsLoaded = 0;
	glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)gleIntGetProcAddress("glMultiTexCoord2sARB");
	if(!glMultiTexCoord2sARB) bIsLoaded = 0;
	glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)gleIntGetProcAddress("glMultiTexCoord2svARB");
	if(!glMultiTexCoord2svARB) bIsLoaded = 0;
	glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)gleIntGetProcAddress("glMultiTexCoord3dARB");
	if(!glMultiTexCoord3dARB) bIsLoaded = 0;
	glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)gleIntGetProcAddress("glMultiTexCoord3dvARB");
	if(!glMultiTexCoord3dvARB) bIsLoaded = 0;
	glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)gleIntGetProcAddress("glMultiTexCoord3fARB");
	if(!glMultiTexCoord3fARB) bIsLoaded = 0;
	glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)gleIntGetProcAddress("glMultiTexCoord3fvARB");
	if(!glMultiTexCoord3fvARB) bIsLoaded = 0;
	glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)gleIntGetProcAddress("glMultiTexCoord3iARB");
	if(!glMultiTexCoord3iARB) bIsLoaded = 0;
	glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)gleIntGetProcAddress("glMultiTexCoord3ivARB");
	if(!glMultiTexCoord3ivARB) bIsLoaded = 0;
	glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)gleIntGetProcAddress("glMultiTexCoord3sARB");
	if(!glMultiTexCoord3sARB) bIsLoaded = 0;
	glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)gleIntGetProcAddress("glMultiTexCoord3svARB");
	if(!glMultiTexCoord3svARB) bIsLoaded = 0;
	glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)gleIntGetProcAddress("glMultiTexCoord4dARB");
	if(!glMultiTexCoord4dARB) bIsLoaded = 0;
	glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)gleIntGetProcAddress("glMultiTexCoord4dvARB");
	if(!glMultiTexCoord4dvARB) bIsLoaded = 0;
	glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)gleIntGetProcAddress("glMultiTexCoord4fARB");
	if(!glMultiTexCoord4fARB) bIsLoaded = 0;
	glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)gleIntGetProcAddress("glMultiTexCoord4fvARB");
	if(!glMultiTexCoord4fvARB) bIsLoaded = 0;
	glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)gleIntGetProcAddress("glMultiTexCoord4iARB");
	if(!glMultiTexCoord4iARB) bIsLoaded = 0;
	glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)gleIntGetProcAddress("glMultiTexCoord4ivARB");
	if(!glMultiTexCoord4ivARB) bIsLoaded = 0;
	glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)gleIntGetProcAddress("glMultiTexCoord4sARB");
	if(!glMultiTexCoord4sARB) bIsLoaded = 0;
	glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)gleIntGetProcAddress("glMultiTexCoord4svARB");
	if(!glMultiTexCoord4svARB) bIsLoaded = 0;
#endif /*GL_ARB_multitexture*/
	return bIsLoaded;
}
#ifndef GL_ARB_occlusion_query
typedef void (GLE_FUNCPTR * PFNGLGENQUERIESARBPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEQUERIESARBPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISQUERYARBPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYARBPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDQUERYARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYIVARBPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTIVARBPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint , GLenum , GLuint *);

PFNGLGENQUERIESARBPROC glGenQueriesARB;
PFNGLDELETEQUERIESARBPROC glDeleteQueriesARB;
PFNGLISQUERYARBPROC glIsQueryARB;
PFNGLBEGINQUERYARBPROC glBeginQueryARB;
PFNGLENDQUERYARBPROC glEndQueryARB;
PFNGLGETQUERYIVARBPROC glGetQueryivARB;
PFNGLGETQUERYOBJECTIVARBPROC glGetQueryObjectivARB;
PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARB;
#endif /*GL_ARB_occlusion_query*/

static int gleIntLoad_ARB_occlusion_query()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_occlusion_query
	glGenQueriesARB = (PFNGLGENQUERIESARBPROC)gleIntGetProcAddress("glGenQueriesARB");
	if(!glGenQueriesARB) bIsLoaded = 0;
	glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC)gleIntGetProcAddress("glDeleteQueriesARB");
	if(!glDeleteQueriesARB) bIsLoaded = 0;
	glIsQueryARB = (PFNGLISQUERYARBPROC)gleIntGetProcAddress("glIsQueryARB");
	if(!glIsQueryARB) bIsLoaded = 0;
	glBeginQueryARB = (PFNGLBEGINQUERYARBPROC)gleIntGetProcAddress("glBeginQueryARB");
	if(!glBeginQueryARB) bIsLoaded = 0;
	glEndQueryARB = (PFNGLENDQUERYARBPROC)gleIntGetProcAddress("glEndQueryARB");
	if(!glEndQueryARB) bIsLoaded = 0;
	glGetQueryivARB = (PFNGLGETQUERYIVARBPROC)gleIntGetProcAddress("glGetQueryivARB");
	if(!glGetQueryivARB) bIsLoaded = 0;
	glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC)gleIntGetProcAddress("glGetQueryObjectivARB");
	if(!glGetQueryObjectivARB) bIsLoaded = 0;
	glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC)gleIntGetProcAddress("glGetQueryObjectuivARB");
	if(!glGetQueryObjectuivARB) bIsLoaded = 0;
#endif /*GL_ARB_occlusion_query*/
	return bIsLoaded;
}


#ifndef GL_ARB_point_parameters
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFARBPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVARBPROC)(GLenum , const GLfloat *);

PFNGLPOINTPARAMETERFARBPROC glPointParameterfARB;
PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB;
#endif /*GL_ARB_point_parameters*/

static int gleIntLoad_ARB_point_parameters()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_point_parameters
	glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)gleIntGetProcAddress("glPointParameterfARB");
	if(!glPointParameterfARB) bIsLoaded = 0;
	glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)gleIntGetProcAddress("glPointParameterfvARB");
	if(!glPointParameterfvARB) bIsLoaded = 0;
#endif /*GL_ARB_point_parameters*/
	return bIsLoaded;
}

#ifndef GL_ARB_program_interface_query
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint , GLenum , GLenum , GLint *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint , GLenum , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint , GLenum , GLuint , GLsizei , const GLenum *, GLsizei , GLsizei *, GLint *);
typedef GLint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint , GLenum , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint , GLenum , const GLchar *);

PFNGLGETPROGRAMINTERFACEIVPROC __gleGetProgramInterfaceiv;
PFNGLGETPROGRAMRESOURCEINDEXPROC __gleGetProgramResourceIndex;
PFNGLGETPROGRAMRESOURCENAMEPROC __gleGetProgramResourceName;
PFNGLGETPROGRAMRESOURCEIVPROC __gleGetProgramResourceiv;
PFNGLGETPROGRAMRESOURCELOCATIONPROC __gleGetProgramResourceLocation;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC __gleGetProgramResourceLocationIndex;
#endif /*GL_ARB_program_interface_query*/

static int gleIntLoad_ARB_program_interface_query()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_program_interface_query
	__gleGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)gleIntGetProcAddress("glGetProgramInterfaceiv");
	if(!__gleGetProgramInterfaceiv) bIsLoaded = 0;
	__gleGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)gleIntGetProcAddress("glGetProgramResourceIndex");
	if(!__gleGetProgramResourceIndex) bIsLoaded = 0;
	__gleGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)gleIntGetProcAddress("glGetProgramResourceName");
	if(!__gleGetProgramResourceName) bIsLoaded = 0;
	__gleGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)gleIntGetProcAddress("glGetProgramResourceiv");
	if(!__gleGetProgramResourceiv) bIsLoaded = 0;
	__gleGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)gleIntGetProcAddress("glGetProgramResourceLocation");
	if(!__gleGetProgramResourceLocation) bIsLoaded = 0;
	__gleGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)gleIntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!__gleGetProgramResourceLocationIndex) bIsLoaded = 0;
#endif /*GL_ARB_program_interface_query*/
	return bIsLoaded;
}
#ifndef GL_ARB_provoking_vertex
typedef void (GLE_FUNCPTR * PFNGLPROVOKINGVERTEXPROC)(GLenum );

PFNGLPROVOKINGVERTEXPROC __gleProvokingVertex;
#endif /*GL_ARB_provoking_vertex*/

static int gleIntLoad_ARB_provoking_vertex()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_provoking_vertex
	__gleProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)gleIntGetProcAddress("glProvokingVertex");
	if(!__gleProvokingVertex) bIsLoaded = 0;
#endif /*GL_ARB_provoking_vertex*/
	return bIsLoaded;
}

#ifndef GL_ARB_robustness
typedef GLenum (GLE_FUNCPTR * PFNGLGETGRAPHICSRESETSTATUSARBPROC)();
typedef void (GLE_FUNCPTR * PFNGLGETNMAPDVARBPROC)(GLenum , GLenum , GLsizei , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETNMAPFVARBPROC)(GLenum , GLenum , GLsizei , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETNMAPIVARBPROC)(GLenum , GLenum , GLsizei , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETNPIXELMAPFVARBPROC)(GLenum , GLsizei , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETNPIXELMAPUIVARBPROC)(GLenum , GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETNPIXELMAPUSVARBPROC)(GLenum , GLsizei , GLushort *);
typedef void (GLE_FUNCPTR * PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei , GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLGETNCOLORTABLEARBPROC)(GLenum , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum , GLenum , GLenum , GLsizei , GLvoid *, GLsizei , GLvoid *, GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNHISTOGRAMARBPROC)(GLenum , GLboolean , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNMINMAXARBPROC)(GLenum , GLboolean , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNTEXIMAGEARBPROC)(GLenum , GLint , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLREADNPIXELSARBPROC)(GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum , GLint , GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETNUNIFORMFVARBPROC)(GLuint , GLint , GLsizei , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETNUNIFORMIVARBPROC)(GLuint , GLint , GLsizei , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETNUNIFORMUIVARBPROC)(GLuint , GLint , GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETNUNIFORMDVARBPROC)(GLuint , GLint , GLsizei , GLdouble *);

PFNGLGETGRAPHICSRESETSTATUSARBPROC glGetGraphicsResetStatusARB;
PFNGLGETNMAPDVARBPROC glGetnMapdvARB;
PFNGLGETNMAPFVARBPROC glGetnMapfvARB;
PFNGLGETNMAPIVARBPROC glGetnMapivARB;
PFNGLGETNPIXELMAPFVARBPROC glGetnPixelMapfvARB;
PFNGLGETNPIXELMAPUIVARBPROC glGetnPixelMapuivARB;
PFNGLGETNPIXELMAPUSVARBPROC glGetnPixelMapusvARB;
PFNGLGETNPOLYGONSTIPPLEARBPROC glGetnPolygonStippleARB;
PFNGLGETNCOLORTABLEARBPROC glGetnColorTableARB;
PFNGLGETNCONVOLUTIONFILTERARBPROC glGetnConvolutionFilterARB;
PFNGLGETNSEPARABLEFILTERARBPROC glGetnSeparableFilterARB;
PFNGLGETNHISTOGRAMARBPROC glGetnHistogramARB;
PFNGLGETNMINMAXARBPROC glGetnMinmaxARB;
PFNGLGETNTEXIMAGEARBPROC glGetnTexImageARB;
PFNGLREADNPIXELSARBPROC glReadnPixelsARB;
PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glGetnCompressedTexImageARB;
PFNGLGETNUNIFORMFVARBPROC glGetnUniformfvARB;
PFNGLGETNUNIFORMIVARBPROC glGetnUniformivARB;
PFNGLGETNUNIFORMUIVARBPROC glGetnUniformuivARB;
PFNGLGETNUNIFORMDVARBPROC glGetnUniformdvARB;
#endif /*GL_ARB_robustness*/

static int gleIntLoad_ARB_robustness()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_robustness
	glGetGraphicsResetStatusARB = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)gleIntGetProcAddress("glGetGraphicsResetStatusARB");
	if(!glGetGraphicsResetStatusARB) bIsLoaded = 0;
	glGetnMapdvARB = (PFNGLGETNMAPDVARBPROC)gleIntGetProcAddress("glGetnMapdvARB");
	if(!glGetnMapdvARB) bIsLoaded = 0;
	glGetnMapfvARB = (PFNGLGETNMAPFVARBPROC)gleIntGetProcAddress("glGetnMapfvARB");
	if(!glGetnMapfvARB) bIsLoaded = 0;
	glGetnMapivARB = (PFNGLGETNMAPIVARBPROC)gleIntGetProcAddress("glGetnMapivARB");
	if(!glGetnMapivARB) bIsLoaded = 0;
	glGetnPixelMapfvARB = (PFNGLGETNPIXELMAPFVARBPROC)gleIntGetProcAddress("glGetnPixelMapfvARB");
	if(!glGetnPixelMapfvARB) bIsLoaded = 0;
	glGetnPixelMapuivARB = (PFNGLGETNPIXELMAPUIVARBPROC)gleIntGetProcAddress("glGetnPixelMapuivARB");
	if(!glGetnPixelMapuivARB) bIsLoaded = 0;
	glGetnPixelMapusvARB = (PFNGLGETNPIXELMAPUSVARBPROC)gleIntGetProcAddress("glGetnPixelMapusvARB");
	if(!glGetnPixelMapusvARB) bIsLoaded = 0;
	glGetnPolygonStippleARB = (PFNGLGETNPOLYGONSTIPPLEARBPROC)gleIntGetProcAddress("glGetnPolygonStippleARB");
	if(!glGetnPolygonStippleARB) bIsLoaded = 0;
	glGetnColorTableARB = (PFNGLGETNCOLORTABLEARBPROC)gleIntGetProcAddress("glGetnColorTableARB");
	if(!glGetnColorTableARB) bIsLoaded = 0;
	glGetnConvolutionFilterARB = (PFNGLGETNCONVOLUTIONFILTERARBPROC)gleIntGetProcAddress("glGetnConvolutionFilterARB");
	if(!glGetnConvolutionFilterARB) bIsLoaded = 0;
	glGetnSeparableFilterARB = (PFNGLGETNSEPARABLEFILTERARBPROC)gleIntGetProcAddress("glGetnSeparableFilterARB");
	if(!glGetnSeparableFilterARB) bIsLoaded = 0;
	glGetnHistogramARB = (PFNGLGETNHISTOGRAMARBPROC)gleIntGetProcAddress("glGetnHistogramARB");
	if(!glGetnHistogramARB) bIsLoaded = 0;
	glGetnMinmaxARB = (PFNGLGETNMINMAXARBPROC)gleIntGetProcAddress("glGetnMinmaxARB");
	if(!glGetnMinmaxARB) bIsLoaded = 0;
	glGetnTexImageARB = (PFNGLGETNTEXIMAGEARBPROC)gleIntGetProcAddress("glGetnTexImageARB");
	if(!glGetnTexImageARB) bIsLoaded = 0;
	glReadnPixelsARB = (PFNGLREADNPIXELSARBPROC)gleIntGetProcAddress("glReadnPixelsARB");
	if(!glReadnPixelsARB) bIsLoaded = 0;
	glGetnCompressedTexImageARB = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)gleIntGetProcAddress("glGetnCompressedTexImageARB");
	if(!glGetnCompressedTexImageARB) bIsLoaded = 0;
	glGetnUniformfvARB = (PFNGLGETNUNIFORMFVARBPROC)gleIntGetProcAddress("glGetnUniformfvARB");
	if(!glGetnUniformfvARB) bIsLoaded = 0;
	glGetnUniformivARB = (PFNGLGETNUNIFORMIVARBPROC)gleIntGetProcAddress("glGetnUniformivARB");
	if(!glGetnUniformivARB) bIsLoaded = 0;
	glGetnUniformuivARB = (PFNGLGETNUNIFORMUIVARBPROC)gleIntGetProcAddress("glGetnUniformuivARB");
	if(!glGetnUniformuivARB) bIsLoaded = 0;
	glGetnUniformdvARB = (PFNGLGETNUNIFORMDVARBPROC)gleIntGetProcAddress("glGetnUniformdvARB");
	if(!glGetnUniformdvARB) bIsLoaded = 0;
#endif /*GL_ARB_robustness*/
	return bIsLoaded;
}

#ifndef GL_ARB_sample_shading
typedef void (GLE_FUNCPTR * PFNGLMINSAMPLESHADINGARBPROC)(GLfloat );

PFNGLMINSAMPLESHADINGARBPROC glMinSampleShadingARB;
#endif /*GL_ARB_sample_shading*/

static int gleIntLoad_ARB_sample_shading()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_sample_shading
	glMinSampleShadingARB = (PFNGLMINSAMPLESHADINGARBPROC)gleIntGetProcAddress("glMinSampleShadingARB");
	if(!glMinSampleShadingARB) bIsLoaded = 0;
#endif /*GL_ARB_sample_shading*/
	return bIsLoaded;
}
#ifndef GL_ARB_sampler_objects
typedef void (GLE_FUNCPTR * PFNGLGENSAMPLERSPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETESAMPLERSPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISSAMPLERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDSAMPLERPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERIPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERIVPROC)(GLuint , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERFPROC)(GLuint , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERFVPROC)(GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERIIVPROC)(GLuint , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLERPARAMETERIUIVPROC)(GLuint , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSAMPLERPARAMETERIIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETSAMPLERPARAMETERIUIVPROC)(GLuint , GLenum , GLuint *);

PFNGLGENSAMPLERSPROC __gleGenSamplers;
PFNGLDELETESAMPLERSPROC __gleDeleteSamplers;
PFNGLISSAMPLERPROC __gleIsSampler;
PFNGLBINDSAMPLERPROC __gleBindSampler;
PFNGLSAMPLERPARAMETERIPROC __gleSamplerParameteri;
PFNGLSAMPLERPARAMETERIVPROC __gleSamplerParameteriv;
PFNGLSAMPLERPARAMETERFPROC __gleSamplerParameterf;
PFNGLSAMPLERPARAMETERFVPROC __gleSamplerParameterfv;
PFNGLSAMPLERPARAMETERIIVPROC __gleSamplerParameterIiv;
PFNGLSAMPLERPARAMETERIUIVPROC __gleSamplerParameterIuiv;
PFNGLGETSAMPLERPARAMETERIVPROC __gleGetSamplerParameteriv;
PFNGLGETSAMPLERPARAMETERIIVPROC __gleGetSamplerParameterIiv;
PFNGLGETSAMPLERPARAMETERFVPROC __gleGetSamplerParameterfv;
PFNGLGETSAMPLERPARAMETERIUIVPROC __gleGetSamplerParameterIuiv;
#endif /*GL_ARB_sampler_objects*/

static int gleIntLoad_ARB_sampler_objects()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_sampler_objects
	__gleGenSamplers = (PFNGLGENSAMPLERSPROC)gleIntGetProcAddress("glGenSamplers");
	if(!__gleGenSamplers) bIsLoaded = 0;
	__gleDeleteSamplers = (PFNGLDELETESAMPLERSPROC)gleIntGetProcAddress("glDeleteSamplers");
	if(!__gleDeleteSamplers) bIsLoaded = 0;
	__gleIsSampler = (PFNGLISSAMPLERPROC)gleIntGetProcAddress("glIsSampler");
	if(!__gleIsSampler) bIsLoaded = 0;
	__gleBindSampler = (PFNGLBINDSAMPLERPROC)gleIntGetProcAddress("glBindSampler");
	if(!__gleBindSampler) bIsLoaded = 0;
	__gleSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)gleIntGetProcAddress("glSamplerParameteri");
	if(!__gleSamplerParameteri) bIsLoaded = 0;
	__gleSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)gleIntGetProcAddress("glSamplerParameteriv");
	if(!__gleSamplerParameteriv) bIsLoaded = 0;
	__gleSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)gleIntGetProcAddress("glSamplerParameterf");
	if(!__gleSamplerParameterf) bIsLoaded = 0;
	__gleSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)gleIntGetProcAddress("glSamplerParameterfv");
	if(!__gleSamplerParameterfv) bIsLoaded = 0;
	__gleSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)gleIntGetProcAddress("glSamplerParameterIiv");
	if(!__gleSamplerParameterIiv) bIsLoaded = 0;
	__gleSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)gleIntGetProcAddress("glSamplerParameterIuiv");
	if(!__gleSamplerParameterIuiv) bIsLoaded = 0;
	__gleGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)gleIntGetProcAddress("glGetSamplerParameteriv");
	if(!__gleGetSamplerParameteriv) bIsLoaded = 0;
	__gleGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)gleIntGetProcAddress("glGetSamplerParameterIiv");
	if(!__gleGetSamplerParameterIiv) bIsLoaded = 0;
	__gleGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)gleIntGetProcAddress("glGetSamplerParameterfv");
	if(!__gleGetSamplerParameterfv) bIsLoaded = 0;
	__gleGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)gleIntGetProcAddress("glGetSamplerParameterIuiv");
	if(!__gleGetSamplerParameterIuiv) bIsLoaded = 0;
#endif /*GL_ARB_sampler_objects*/
	return bIsLoaded;
}

#ifndef GL_ARB_separate_shader_objects
typedef void (GLE_FUNCPTR * PFNGLUSEPROGRAMSTAGESPROC)(GLuint , GLbitfield , GLuint );
typedef void (GLE_FUNCPTR * PFNGLACTIVESHADERPROGRAMPROC)(GLuint , GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLCREATESHADERPROGRAMVPROC)(GLenum , GLsizei , const GLchar* const *);
typedef void (GLE_FUNCPTR * PFNGLBINDPROGRAMPIPELINEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENPROGRAMPIPELINESPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISPROGRAMPIPELINEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1IPROC)(GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1IVPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1FPROC)(GLuint , GLint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1FVPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1DPROC)(GLuint , GLint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1DVPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UIPROC)(GLuint , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2IPROC)(GLuint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2IVPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2FPROC)(GLuint , GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2FVPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2DPROC)(GLuint , GLint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2DVPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UIPROC)(GLuint , GLint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3IPROC)(GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3IVPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3FPROC)(GLuint , GLint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3FVPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3DPROC)(GLuint , GLint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3DVPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UIPROC)(GLuint , GLint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4IPROC)(GLuint , GLint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4IVPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4FPROC)(GLuint , GLint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4FVPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4DPROC)(GLuint , GLint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4DVPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UIPROC)(GLuint , GLint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint , GLsizei , GLsizei *, GLchar *);

PFNGLUSEPROGRAMSTAGESPROC __gleUseProgramStages;
PFNGLACTIVESHADERPROGRAMPROC __gleActiveShaderProgram;
PFNGLCREATESHADERPROGRAMVPROC __gleCreateShaderProgramv;
PFNGLBINDPROGRAMPIPELINEPROC __gleBindProgramPipeline;
PFNGLDELETEPROGRAMPIPELINESPROC __gleDeleteProgramPipelines;
PFNGLGENPROGRAMPIPELINESPROC __gleGenProgramPipelines;
PFNGLISPROGRAMPIPELINEPROC __gleIsProgramPipeline;
PFNGLGETPROGRAMPIPELINEIVPROC __gleGetProgramPipelineiv;
PFNGLPROGRAMUNIFORM1IPROC __gleProgramUniform1i;
PFNGLPROGRAMUNIFORM1IVPROC __gleProgramUniform1iv;
PFNGLPROGRAMUNIFORM1FPROC __gleProgramUniform1f;
PFNGLPROGRAMUNIFORM1FVPROC __gleProgramUniform1fv;
PFNGLPROGRAMUNIFORM1DPROC __gleProgramUniform1d;
PFNGLPROGRAMUNIFORM1DVPROC __gleProgramUniform1dv;
PFNGLPROGRAMUNIFORM1UIPROC __gleProgramUniform1ui;
PFNGLPROGRAMUNIFORM1UIVPROC __gleProgramUniform1uiv;
PFNGLPROGRAMUNIFORM2IPROC __gleProgramUniform2i;
PFNGLPROGRAMUNIFORM2IVPROC __gleProgramUniform2iv;
PFNGLPROGRAMUNIFORM2FPROC __gleProgramUniform2f;
PFNGLPROGRAMUNIFORM2FVPROC __gleProgramUniform2fv;
PFNGLPROGRAMUNIFORM2DPROC __gleProgramUniform2d;
PFNGLPROGRAMUNIFORM2DVPROC __gleProgramUniform2dv;
PFNGLPROGRAMUNIFORM2UIPROC __gleProgramUniform2ui;
PFNGLPROGRAMUNIFORM2UIVPROC __gleProgramUniform2uiv;
PFNGLPROGRAMUNIFORM3IPROC __gleProgramUniform3i;
PFNGLPROGRAMUNIFORM3IVPROC __gleProgramUniform3iv;
PFNGLPROGRAMUNIFORM3FPROC __gleProgramUniform3f;
PFNGLPROGRAMUNIFORM3FVPROC __gleProgramUniform3fv;
PFNGLPROGRAMUNIFORM3DPROC __gleProgramUniform3d;
PFNGLPROGRAMUNIFORM3DVPROC __gleProgramUniform3dv;
PFNGLPROGRAMUNIFORM3UIPROC __gleProgramUniform3ui;
PFNGLPROGRAMUNIFORM3UIVPROC __gleProgramUniform3uiv;
PFNGLPROGRAMUNIFORM4IPROC __gleProgramUniform4i;
PFNGLPROGRAMUNIFORM4IVPROC __gleProgramUniform4iv;
PFNGLPROGRAMUNIFORM4FPROC __gleProgramUniform4f;
PFNGLPROGRAMUNIFORM4FVPROC __gleProgramUniform4fv;
PFNGLPROGRAMUNIFORM4DPROC __gleProgramUniform4d;
PFNGLPROGRAMUNIFORM4DVPROC __gleProgramUniform4dv;
PFNGLPROGRAMUNIFORM4UIPROC __gleProgramUniform4ui;
PFNGLPROGRAMUNIFORM4UIVPROC __gleProgramUniform4uiv;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC __gleProgramUniformMatrix2fv;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC __gleProgramUniformMatrix3fv;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC __gleProgramUniformMatrix4fv;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC __gleProgramUniformMatrix2dv;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC __gleProgramUniformMatrix3dv;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC __gleProgramUniformMatrix4dv;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC __gleProgramUniformMatrix2x3fv;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC __gleProgramUniformMatrix3x2fv;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC __gleProgramUniformMatrix2x4fv;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC __gleProgramUniformMatrix4x2fv;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC __gleProgramUniformMatrix3x4fv;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC __gleProgramUniformMatrix4x3fv;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC __gleProgramUniformMatrix2x3dv;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC __gleProgramUniformMatrix3x2dv;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC __gleProgramUniformMatrix2x4dv;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC __gleProgramUniformMatrix4x2dv;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC __gleProgramUniformMatrix3x4dv;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC __gleProgramUniformMatrix4x3dv;
PFNGLVALIDATEPROGRAMPIPELINEPROC __gleValidateProgramPipeline;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC __gleGetProgramPipelineInfoLog;
#endif /*GL_ARB_separate_shader_objects*/

static int gleIntLoad_ARB_separate_shader_objects()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_separate_shader_objects
	__gleUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)gleIntGetProcAddress("glUseProgramStages");
	if(!__gleUseProgramStages) bIsLoaded = 0;
	__gleActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)gleIntGetProcAddress("glActiveShaderProgram");
	if(!__gleActiveShaderProgram) bIsLoaded = 0;
	__gleCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)gleIntGetProcAddress("glCreateShaderProgramv");
	if(!__gleCreateShaderProgramv) bIsLoaded = 0;
	__gleBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)gleIntGetProcAddress("glBindProgramPipeline");
	if(!__gleBindProgramPipeline) bIsLoaded = 0;
	__gleDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)gleIntGetProcAddress("glDeleteProgramPipelines");
	if(!__gleDeleteProgramPipelines) bIsLoaded = 0;
	__gleGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)gleIntGetProcAddress("glGenProgramPipelines");
	if(!__gleGenProgramPipelines) bIsLoaded = 0;
	__gleIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)gleIntGetProcAddress("glIsProgramPipeline");
	if(!__gleIsProgramPipeline) bIsLoaded = 0;
	__gleGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)gleIntGetProcAddress("glGetProgramPipelineiv");
	if(!__gleGetProgramPipelineiv) bIsLoaded = 0;
	__gleProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)gleIntGetProcAddress("glProgramUniform1i");
	if(!__gleProgramUniform1i) bIsLoaded = 0;
	__gleProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)gleIntGetProcAddress("glProgramUniform1iv");
	if(!__gleProgramUniform1iv) bIsLoaded = 0;
	__gleProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)gleIntGetProcAddress("glProgramUniform1f");
	if(!__gleProgramUniform1f) bIsLoaded = 0;
	__gleProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)gleIntGetProcAddress("glProgramUniform1fv");
	if(!__gleProgramUniform1fv) bIsLoaded = 0;
	__gleProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)gleIntGetProcAddress("glProgramUniform1d");
	if(!__gleProgramUniform1d) bIsLoaded = 0;
	__gleProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)gleIntGetProcAddress("glProgramUniform1dv");
	if(!__gleProgramUniform1dv) bIsLoaded = 0;
	__gleProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)gleIntGetProcAddress("glProgramUniform1ui");
	if(!__gleProgramUniform1ui) bIsLoaded = 0;
	__gleProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)gleIntGetProcAddress("glProgramUniform1uiv");
	if(!__gleProgramUniform1uiv) bIsLoaded = 0;
	__gleProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)gleIntGetProcAddress("glProgramUniform2i");
	if(!__gleProgramUniform2i) bIsLoaded = 0;
	__gleProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)gleIntGetProcAddress("glProgramUniform2iv");
	if(!__gleProgramUniform2iv) bIsLoaded = 0;
	__gleProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)gleIntGetProcAddress("glProgramUniform2f");
	if(!__gleProgramUniform2f) bIsLoaded = 0;
	__gleProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)gleIntGetProcAddress("glProgramUniform2fv");
	if(!__gleProgramUniform2fv) bIsLoaded = 0;
	__gleProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)gleIntGetProcAddress("glProgramUniform2d");
	if(!__gleProgramUniform2d) bIsLoaded = 0;
	__gleProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)gleIntGetProcAddress("glProgramUniform2dv");
	if(!__gleProgramUniform2dv) bIsLoaded = 0;
	__gleProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)gleIntGetProcAddress("glProgramUniform2ui");
	if(!__gleProgramUniform2ui) bIsLoaded = 0;
	__gleProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)gleIntGetProcAddress("glProgramUniform2uiv");
	if(!__gleProgramUniform2uiv) bIsLoaded = 0;
	__gleProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)gleIntGetProcAddress("glProgramUniform3i");
	if(!__gleProgramUniform3i) bIsLoaded = 0;
	__gleProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)gleIntGetProcAddress("glProgramUniform3iv");
	if(!__gleProgramUniform3iv) bIsLoaded = 0;
	__gleProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)gleIntGetProcAddress("glProgramUniform3f");
	if(!__gleProgramUniform3f) bIsLoaded = 0;
	__gleProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)gleIntGetProcAddress("glProgramUniform3fv");
	if(!__gleProgramUniform3fv) bIsLoaded = 0;
	__gleProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)gleIntGetProcAddress("glProgramUniform3d");
	if(!__gleProgramUniform3d) bIsLoaded = 0;
	__gleProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)gleIntGetProcAddress("glProgramUniform3dv");
	if(!__gleProgramUniform3dv) bIsLoaded = 0;
	__gleProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)gleIntGetProcAddress("glProgramUniform3ui");
	if(!__gleProgramUniform3ui) bIsLoaded = 0;
	__gleProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)gleIntGetProcAddress("glProgramUniform3uiv");
	if(!__gleProgramUniform3uiv) bIsLoaded = 0;
	__gleProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)gleIntGetProcAddress("glProgramUniform4i");
	if(!__gleProgramUniform4i) bIsLoaded = 0;
	__gleProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)gleIntGetProcAddress("glProgramUniform4iv");
	if(!__gleProgramUniform4iv) bIsLoaded = 0;
	__gleProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)gleIntGetProcAddress("glProgramUniform4f");
	if(!__gleProgramUniform4f) bIsLoaded = 0;
	__gleProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)gleIntGetProcAddress("glProgramUniform4fv");
	if(!__gleProgramUniform4fv) bIsLoaded = 0;
	__gleProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)gleIntGetProcAddress("glProgramUniform4d");
	if(!__gleProgramUniform4d) bIsLoaded = 0;
	__gleProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)gleIntGetProcAddress("glProgramUniform4dv");
	if(!__gleProgramUniform4dv) bIsLoaded = 0;
	__gleProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)gleIntGetProcAddress("glProgramUniform4ui");
	if(!__gleProgramUniform4ui) bIsLoaded = 0;
	__gleProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)gleIntGetProcAddress("glProgramUniform4uiv");
	if(!__gleProgramUniform4uiv) bIsLoaded = 0;
	__gleProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2fv");
	if(!__gleProgramUniformMatrix2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3fv");
	if(!__gleProgramUniformMatrix3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4fv");
	if(!__gleProgramUniformMatrix4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2dv");
	if(!__gleProgramUniformMatrix2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3dv");
	if(!__gleProgramUniformMatrix3dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4dv");
	if(!__gleProgramUniformMatrix4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!__gleProgramUniformMatrix2x3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!__gleProgramUniformMatrix3x2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!__gleProgramUniformMatrix2x4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!__gleProgramUniformMatrix4x2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!__gleProgramUniformMatrix3x4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!__gleProgramUniformMatrix4x3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!__gleProgramUniformMatrix2x3dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!__gleProgramUniformMatrix3x2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!__gleProgramUniformMatrix2x4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!__gleProgramUniformMatrix4x2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!__gleProgramUniformMatrix3x4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!__gleProgramUniformMatrix4x3dv) bIsLoaded = 0;
	__gleValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)gleIntGetProcAddress("glValidateProgramPipeline");
	if(!__gleValidateProgramPipeline) bIsLoaded = 0;
	__gleGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)gleIntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!__gleGetProgramPipelineInfoLog) bIsLoaded = 0;
#endif /*GL_ARB_separate_shader_objects*/
	return bIsLoaded;
}
#ifndef GL_ARB_shader_atomic_counters
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint , GLuint , GLenum , GLint *);

PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC __gleGetActiveAtomicCounterBufferiv;
#endif /*GL_ARB_shader_atomic_counters*/

static int gleIntLoad_ARB_shader_atomic_counters()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shader_atomic_counters
	__gleGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)gleIntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!__gleGetActiveAtomicCounterBufferiv) bIsLoaded = 0;
#endif /*GL_ARB_shader_atomic_counters*/
	return bIsLoaded;
}

#ifndef GL_ARB_shader_image_load_store
typedef void (GLE_FUNCPTR * PFNGLBINDIMAGETEXTUREPROC)(GLuint , GLuint , GLint , GLboolean , GLint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMEMORYBARRIERPROC)(GLbitfield );

PFNGLBINDIMAGETEXTUREPROC __gleBindImageTexture;
PFNGLMEMORYBARRIERPROC __gleMemoryBarrier;
#endif /*GL_ARB_shader_image_load_store*/

static int gleIntLoad_ARB_shader_image_load_store()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shader_image_load_store
	__gleBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)gleIntGetProcAddress("glBindImageTexture");
	if(!__gleBindImageTexture) bIsLoaded = 0;
	__gleMemoryBarrier = (PFNGLMEMORYBARRIERPROC)gleIntGetProcAddress("glMemoryBarrier");
	if(!__gleMemoryBarrier) bIsLoaded = 0;
#endif /*GL_ARB_shader_image_load_store*/
	return bIsLoaded;
}

#ifndef GL_ARB_shader_objects
typedef void (GLE_FUNCPTR * PFNGLDELETEOBJECTARBPROC)(GLhandleARB );
typedef GLhandleARB (GLE_FUNCPTR * PFNGLGETHANDLEARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLDETACHOBJECTARBPROC)(GLhandleARB , GLhandleARB );
typedef GLhandleARB (GLE_FUNCPTR * PFNGLCREATESHADEROBJECTARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLSHADERSOURCEARBPROC)(GLhandleARB , GLsizei , const GLcharARB* *, const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOMPILESHADERARBPROC)(GLhandleARB );
typedef GLhandleARB (GLE_FUNCPTR * PFNGLCREATEPROGRAMOBJECTARBPROC)();
typedef void (GLE_FUNCPTR * PFNGLATTACHOBJECTARBPROC)(GLhandleARB , GLhandleARB );
typedef void (GLE_FUNCPTR * PFNGLLINKPROGRAMARBPROC)(GLhandleARB );
typedef void (GLE_FUNCPTR * PFNGLUSEPROGRAMOBJECTARBPROC)(GLhandleARB );
typedef void (GLE_FUNCPTR * PFNGLVALIDATEPROGRAMARBPROC)(GLhandleARB );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FARBPROC)(GLint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FARBPROC)(GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FARBPROC)(GLint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FARBPROC)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IARBPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IARBPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IARBPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IARBPROC)(GLint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FVARBPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FVARBPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FVARBPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FVARBPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IVARBPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IVARBPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IVARBPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IVARBPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2FVARBPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3FVARBPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4FVARBPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTPARAMETERFVARBPROC)(GLhandleARB , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTPARAMETERIVARBPROC)(GLhandleARB , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETINFOLOGARBPROC)(GLhandleARB , GLsizei , GLsizei *, GLcharARB *);
typedef void (GLE_FUNCPTR * PFNGLGETATTACHEDOBJECTSARBPROC)(GLhandleARB , GLsizei , GLsizei *, GLhandleARB *);
typedef GLint (GLE_FUNCPTR * PFNGLGETUNIFORMLOCATIONARBPROC)(GLhandleARB , const GLcharARB *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMARBPROC)(GLhandleARB , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLcharARB *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMFVARBPROC)(GLhandleARB , GLint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMIVARBPROC)(GLhandleARB , GLint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSHADERSOURCEARBPROC)(GLhandleARB , GLsizei , GLsizei *, GLcharARB *);

PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
PFNGLGETHANDLEARBPROC glGetHandleARB;
PFNGLDETACHOBJECTARBPROC glDetachObjectARB;
PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;
PFNGLUNIFORM1FARBPROC glUniform1fARB;
PFNGLUNIFORM2FARBPROC glUniform2fARB;
PFNGLUNIFORM3FARBPROC glUniform3fARB;
PFNGLUNIFORM4FARBPROC glUniform4fARB;
PFNGLUNIFORM1IARBPROC glUniform1iARB;
PFNGLUNIFORM2IARBPROC glUniform2iARB;
PFNGLUNIFORM3IARBPROC glUniform3iARB;
PFNGLUNIFORM4IARBPROC glUniform4iARB;
PFNGLUNIFORM1FVARBPROC glUniform1fvARB;
PFNGLUNIFORM2FVARBPROC glUniform2fvARB;
PFNGLUNIFORM3FVARBPROC glUniform3fvARB;
PFNGLUNIFORM4FVARBPROC glUniform4fvARB;
PFNGLUNIFORM1IVARBPROC glUniform1ivARB;
PFNGLUNIFORM2IVARBPROC glUniform2ivARB;
PFNGLUNIFORM3IVARBPROC glUniform3ivARB;
PFNGLUNIFORM4IVARBPROC glUniform4ivARB;
PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB;
PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB;
PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;
PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB;
PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB;
PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB;
PFNGLGETUNIFORMIVARBPROC glGetUniformivARB;
PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB;
#endif /*GL_ARB_shader_objects*/

static int gleIntLoad_ARB_shader_objects()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shader_objects
	glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)gleIntGetProcAddress("glDeleteObjectARB");
	if(!glDeleteObjectARB) bIsLoaded = 0;
	glGetHandleARB = (PFNGLGETHANDLEARBPROC)gleIntGetProcAddress("glGetHandleARB");
	if(!glGetHandleARB) bIsLoaded = 0;
	glDetachObjectARB = (PFNGLDETACHOBJECTARBPROC)gleIntGetProcAddress("glDetachObjectARB");
	if(!glDetachObjectARB) bIsLoaded = 0;
	glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)gleIntGetProcAddress("glCreateShaderObjectARB");
	if(!glCreateShaderObjectARB) bIsLoaded = 0;
	glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)gleIntGetProcAddress("glShaderSourceARB");
	if(!glShaderSourceARB) bIsLoaded = 0;
	glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)gleIntGetProcAddress("glCompileShaderARB");
	if(!glCompileShaderARB) bIsLoaded = 0;
	glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)gleIntGetProcAddress("glCreateProgramObjectARB");
	if(!glCreateProgramObjectARB) bIsLoaded = 0;
	glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)gleIntGetProcAddress("glAttachObjectARB");
	if(!glAttachObjectARB) bIsLoaded = 0;
	glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)gleIntGetProcAddress("glLinkProgramARB");
	if(!glLinkProgramARB) bIsLoaded = 0;
	glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)gleIntGetProcAddress("glUseProgramObjectARB");
	if(!glUseProgramObjectARB) bIsLoaded = 0;
	glValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC)gleIntGetProcAddress("glValidateProgramARB");
	if(!glValidateProgramARB) bIsLoaded = 0;
	glUniform1fARB = (PFNGLUNIFORM1FARBPROC)gleIntGetProcAddress("glUniform1fARB");
	if(!glUniform1fARB) bIsLoaded = 0;
	glUniform2fARB = (PFNGLUNIFORM2FARBPROC)gleIntGetProcAddress("glUniform2fARB");
	if(!glUniform2fARB) bIsLoaded = 0;
	glUniform3fARB = (PFNGLUNIFORM3FARBPROC)gleIntGetProcAddress("glUniform3fARB");
	if(!glUniform3fARB) bIsLoaded = 0;
	glUniform4fARB = (PFNGLUNIFORM4FARBPROC)gleIntGetProcAddress("glUniform4fARB");
	if(!glUniform4fARB) bIsLoaded = 0;
	glUniform1iARB = (PFNGLUNIFORM1IARBPROC)gleIntGetProcAddress("glUniform1iARB");
	if(!glUniform1iARB) bIsLoaded = 0;
	glUniform2iARB = (PFNGLUNIFORM2IARBPROC)gleIntGetProcAddress("glUniform2iARB");
	if(!glUniform2iARB) bIsLoaded = 0;
	glUniform3iARB = (PFNGLUNIFORM3IARBPROC)gleIntGetProcAddress("glUniform3iARB");
	if(!glUniform3iARB) bIsLoaded = 0;
	glUniform4iARB = (PFNGLUNIFORM4IARBPROC)gleIntGetProcAddress("glUniform4iARB");
	if(!glUniform4iARB) bIsLoaded = 0;
	glUniform1fvARB = (PFNGLUNIFORM1FVARBPROC)gleIntGetProcAddress("glUniform1fvARB");
	if(!glUniform1fvARB) bIsLoaded = 0;
	glUniform2fvARB = (PFNGLUNIFORM2FVARBPROC)gleIntGetProcAddress("glUniform2fvARB");
	if(!glUniform2fvARB) bIsLoaded = 0;
	glUniform3fvARB = (PFNGLUNIFORM3FVARBPROC)gleIntGetProcAddress("glUniform3fvARB");
	if(!glUniform3fvARB) bIsLoaded = 0;
	glUniform4fvARB = (PFNGLUNIFORM4FVARBPROC)gleIntGetProcAddress("glUniform4fvARB");
	if(!glUniform4fvARB) bIsLoaded = 0;
	glUniform1ivARB = (PFNGLUNIFORM1IVARBPROC)gleIntGetProcAddress("glUniform1ivARB");
	if(!glUniform1ivARB) bIsLoaded = 0;
	glUniform2ivARB = (PFNGLUNIFORM2IVARBPROC)gleIntGetProcAddress("glUniform2ivARB");
	if(!glUniform2ivARB) bIsLoaded = 0;
	glUniform3ivARB = (PFNGLUNIFORM3IVARBPROC)gleIntGetProcAddress("glUniform3ivARB");
	if(!glUniform3ivARB) bIsLoaded = 0;
	glUniform4ivARB = (PFNGLUNIFORM4IVARBPROC)gleIntGetProcAddress("glUniform4ivARB");
	if(!glUniform4ivARB) bIsLoaded = 0;
	glUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC)gleIntGetProcAddress("glUniformMatrix2fvARB");
	if(!glUniformMatrix2fvARB) bIsLoaded = 0;
	glUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC)gleIntGetProcAddress("glUniformMatrix3fvARB");
	if(!glUniformMatrix3fvARB) bIsLoaded = 0;
	glUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC)gleIntGetProcAddress("glUniformMatrix4fvARB");
	if(!glUniformMatrix4fvARB) bIsLoaded = 0;
	glGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC)gleIntGetProcAddress("glGetObjectParameterfvARB");
	if(!glGetObjectParameterfvARB) bIsLoaded = 0;
	glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)gleIntGetProcAddress("glGetObjectParameterivARB");
	if(!glGetObjectParameterivARB) bIsLoaded = 0;
	glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)gleIntGetProcAddress("glGetInfoLogARB");
	if(!glGetInfoLogARB) bIsLoaded = 0;
	glGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC)gleIntGetProcAddress("glGetAttachedObjectsARB");
	if(!glGetAttachedObjectsARB) bIsLoaded = 0;
	glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)gleIntGetProcAddress("glGetUniformLocationARB");
	if(!glGetUniformLocationARB) bIsLoaded = 0;
	glGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC)gleIntGetProcAddress("glGetActiveUniformARB");
	if(!glGetActiveUniformARB) bIsLoaded = 0;
	glGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC)gleIntGetProcAddress("glGetUniformfvARB");
	if(!glGetUniformfvARB) bIsLoaded = 0;
	glGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC)gleIntGetProcAddress("glGetUniformivARB");
	if(!glGetUniformivARB) bIsLoaded = 0;
	glGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC)gleIntGetProcAddress("glGetShaderSourceARB");
	if(!glGetShaderSourceARB) bIsLoaded = 0;
#endif /*GL_ARB_shader_objects*/
	return bIsLoaded;
}


#ifndef GL_ARB_shader_storage_buffer_object
typedef void (GLE_FUNCPTR * PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint , GLuint , GLuint );

PFNGLSHADERSTORAGEBLOCKBINDINGPROC __gleShaderStorageBlockBinding;
#endif /*GL_ARB_shader_storage_buffer_object*/

static int gleIntLoad_ARB_shader_storage_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shader_storage_buffer_object
	__gleShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)gleIntGetProcAddress("glShaderStorageBlockBinding");
	if(!__gleShaderStorageBlockBinding) bIsLoaded = 0;
#endif /*GL_ARB_shader_storage_buffer_object*/
	return bIsLoaded;
}
#ifndef GL_ARB_shader_subroutine
typedef GLint (GLE_FUNCPTR * PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint , GLenum , const GLchar *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETSUBROUTINEINDEXPROC)(GLuint , GLenum , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint , GLenum , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum , GLint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSTAGEIVPROC)(GLuint , GLenum , GLenum , GLint *);

PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC __gleGetSubroutineUniformLocation;
PFNGLGETSUBROUTINEINDEXPROC __gleGetSubroutineIndex;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC __gleGetActiveSubroutineUniformiv;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC __gleGetActiveSubroutineUniformName;
PFNGLGETACTIVESUBROUTINENAMEPROC __gleGetActiveSubroutineName;
PFNGLUNIFORMSUBROUTINESUIVPROC __gleUniformSubroutinesuiv;
PFNGLGETUNIFORMSUBROUTINEUIVPROC __gleGetUniformSubroutineuiv;
PFNGLGETPROGRAMSTAGEIVPROC __gleGetProgramStageiv;
#endif /*GL_ARB_shader_subroutine*/

static int gleIntLoad_ARB_shader_subroutine()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shader_subroutine
	__gleGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)gleIntGetProcAddress("glGetSubroutineUniformLocation");
	if(!__gleGetSubroutineUniformLocation) bIsLoaded = 0;
	__gleGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)gleIntGetProcAddress("glGetSubroutineIndex");
	if(!__gleGetSubroutineIndex) bIsLoaded = 0;
	__gleGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)gleIntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!__gleGetActiveSubroutineUniformiv) bIsLoaded = 0;
	__gleGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)gleIntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!__gleGetActiveSubroutineUniformName) bIsLoaded = 0;
	__gleGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)gleIntGetProcAddress("glGetActiveSubroutineName");
	if(!__gleGetActiveSubroutineName) bIsLoaded = 0;
	__gleUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)gleIntGetProcAddress("glUniformSubroutinesuiv");
	if(!__gleUniformSubroutinesuiv) bIsLoaded = 0;
	__gleGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)gleIntGetProcAddress("glGetUniformSubroutineuiv");
	if(!__gleGetUniformSubroutineuiv) bIsLoaded = 0;
	__gleGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)gleIntGetProcAddress("glGetProgramStageiv");
	if(!__gleGetProgramStageiv) bIsLoaded = 0;
#endif /*GL_ARB_shader_subroutine*/
	return bIsLoaded;
}



#ifndef GL_ARB_shading_language_include
typedef void (GLE_FUNCPTR * PFNGLNAMEDSTRINGARBPROC)(GLenum , GLint , const GLchar *, GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDELETENAMEDSTRINGARBPROC)(GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint , GLsizei , const GLchar* *, const GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISNAMEDSTRINGARBPROC)(GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDSTRINGARBPROC)(GLint , const GLchar *, GLsizei , GLint *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDSTRINGIVARBPROC)(GLint , const GLchar *, GLenum , GLint *);

PFNGLNAMEDSTRINGARBPROC glNamedStringARB;
PFNGLDELETENAMEDSTRINGARBPROC glDeleteNamedStringARB;
PFNGLCOMPILESHADERINCLUDEARBPROC glCompileShaderIncludeARB;
PFNGLISNAMEDSTRINGARBPROC glIsNamedStringARB;
PFNGLGETNAMEDSTRINGARBPROC glGetNamedStringARB;
PFNGLGETNAMEDSTRINGIVARBPROC glGetNamedStringivARB;
#endif /*GL_ARB_shading_language_include*/

static int gleIntLoad_ARB_shading_language_include()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_shading_language_include
	glNamedStringARB = (PFNGLNAMEDSTRINGARBPROC)gleIntGetProcAddress("glNamedStringARB");
	if(!glNamedStringARB) bIsLoaded = 0;
	glDeleteNamedStringARB = (PFNGLDELETENAMEDSTRINGARBPROC)gleIntGetProcAddress("glDeleteNamedStringARB");
	if(!glDeleteNamedStringARB) bIsLoaded = 0;
	glCompileShaderIncludeARB = (PFNGLCOMPILESHADERINCLUDEARBPROC)gleIntGetProcAddress("glCompileShaderIncludeARB");
	if(!glCompileShaderIncludeARB) bIsLoaded = 0;
	glIsNamedStringARB = (PFNGLISNAMEDSTRINGARBPROC)gleIntGetProcAddress("glIsNamedStringARB");
	if(!glIsNamedStringARB) bIsLoaded = 0;
	glGetNamedStringARB = (PFNGLGETNAMEDSTRINGARBPROC)gleIntGetProcAddress("glGetNamedStringARB");
	if(!glGetNamedStringARB) bIsLoaded = 0;
	glGetNamedStringivARB = (PFNGLGETNAMEDSTRINGIVARBPROC)gleIntGetProcAddress("glGetNamedStringivARB");
	if(!glGetNamedStringivARB) bIsLoaded = 0;
#endif /*GL_ARB_shading_language_include*/
	return bIsLoaded;
}




#ifndef GL_ARB_sync
typedef GLsync (GLE_FUNCPTR * PFNGLFENCESYNCPROC)(GLenum , GLbitfield );
typedef GLboolean (GLE_FUNCPTR * PFNGLISSYNCPROC)(GLsync );
typedef void (GLE_FUNCPTR * PFNGLDELETESYNCPROC)(GLsync );
typedef GLenum (GLE_FUNCPTR * PFNGLCLIENTWAITSYNCPROC)(GLsync , GLbitfield , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLWAITSYNCPROC)(GLsync , GLbitfield , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLGETINTEGER64VPROC)(GLenum , GLint64 *);
typedef void (GLE_FUNCPTR * PFNGLGETSYNCIVPROC)(GLsync , GLenum , GLsizei , GLsizei *, GLint *);

PFNGLFENCESYNCPROC __gleFenceSync;
PFNGLISSYNCPROC __gleIsSync;
PFNGLDELETESYNCPROC __gleDeleteSync;
PFNGLCLIENTWAITSYNCPROC __gleClientWaitSync;
PFNGLWAITSYNCPROC __gleWaitSync;
PFNGLGETINTEGER64VPROC __gleGetInteger64v;
PFNGLGETSYNCIVPROC __gleGetSynciv;
#endif /*GL_ARB_sync*/

static int gleIntLoad_ARB_sync()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_sync
	__gleFenceSync = (PFNGLFENCESYNCPROC)gleIntGetProcAddress("glFenceSync");
	if(!__gleFenceSync) bIsLoaded = 0;
	__gleIsSync = (PFNGLISSYNCPROC)gleIntGetProcAddress("glIsSync");
	if(!__gleIsSync) bIsLoaded = 0;
	__gleDeleteSync = (PFNGLDELETESYNCPROC)gleIntGetProcAddress("glDeleteSync");
	if(!__gleDeleteSync) bIsLoaded = 0;
	__gleClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)gleIntGetProcAddress("glClientWaitSync");
	if(!__gleClientWaitSync) bIsLoaded = 0;
	__gleWaitSync = (PFNGLWAITSYNCPROC)gleIntGetProcAddress("glWaitSync");
	if(!__gleWaitSync) bIsLoaded = 0;
	__gleGetInteger64v = (PFNGLGETINTEGER64VPROC)gleIntGetProcAddress("glGetInteger64v");
	if(!__gleGetInteger64v) bIsLoaded = 0;
	__gleGetSynciv = (PFNGLGETSYNCIVPROC)gleIntGetProcAddress("glGetSynciv");
	if(!__gleGetSynciv) bIsLoaded = 0;
#endif /*GL_ARB_sync*/
	return bIsLoaded;
}
#ifndef GL_ARB_tessellation_shader
typedef void (GLE_FUNCPTR * PFNGLPATCHPARAMETERIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPATCHPARAMETERFVPROC)(GLenum , const GLfloat *);

PFNGLPATCHPARAMETERIPROC __glePatchParameteri;
PFNGLPATCHPARAMETERFVPROC __glePatchParameterfv;
#endif /*GL_ARB_tessellation_shader*/

static int gleIntLoad_ARB_tessellation_shader()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_tessellation_shader
	__glePatchParameteri = (PFNGLPATCHPARAMETERIPROC)gleIntGetProcAddress("glPatchParameteri");
	if(!__glePatchParameteri) bIsLoaded = 0;
	__glePatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)gleIntGetProcAddress("glPatchParameterfv");
	if(!__glePatchParameterfv) bIsLoaded = 0;
#endif /*GL_ARB_tessellation_shader*/
	return bIsLoaded;
}

#ifndef GL_ARB_texture_buffer_object
typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERARBPROC)(GLenum , GLenum , GLuint );

PFNGLTEXBUFFERARBPROC glTexBufferARB;
#endif /*GL_ARB_texture_buffer_object*/

static int gleIntLoad_ARB_texture_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_buffer_object
	glTexBufferARB = (PFNGLTEXBUFFERARBPROC)gleIntGetProcAddress("glTexBufferARB");
	if(!glTexBufferARB) bIsLoaded = 0;
#endif /*GL_ARB_texture_buffer_object*/
	return bIsLoaded;
}

#ifndef GL_ARB_texture_buffer_range
typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERRANGEPROC)(GLenum , GLenum , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint , GLenum , GLenum , GLuint , GLintptr , GLsizeiptr );

PFNGLTEXBUFFERRANGEPROC __gleTexBufferRange;
PFNGLTEXTUREBUFFERRANGEEXTPROC __gleTextureBufferRangeEXT;
#endif /*GL_ARB_texture_buffer_range*/

static int gleIntLoad_ARB_texture_buffer_range()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_buffer_range
	__gleTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)gleIntGetProcAddress("glTexBufferRange");
	if(!__gleTexBufferRange) bIsLoaded = 0;
	__gleTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC)gleIntGetProcAddress("glTextureBufferRangeEXT");
	if(!__gleTextureBufferRangeEXT) bIsLoaded = 0;
#endif /*GL_ARB_texture_buffer_range*/
	return bIsLoaded;
}
#ifndef GL_ARB_texture_compression
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum , GLint , GLvoid *);

PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB;
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;
PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB;
PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB;
PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB;
#endif /*GL_ARB_texture_compression*/

static int gleIntLoad_ARB_texture_compression()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_compression
	glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)gleIntGetProcAddress("glCompressedTexImage3DARB");
	if(!glCompressedTexImage3DARB) bIsLoaded = 0;
	glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)gleIntGetProcAddress("glCompressedTexImage2DARB");
	if(!glCompressedTexImage2DARB) bIsLoaded = 0;
	glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)gleIntGetProcAddress("glCompressedTexImage1DARB");
	if(!glCompressedTexImage1DARB) bIsLoaded = 0;
	glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)gleIntGetProcAddress("glCompressedTexSubImage3DARB");
	if(!glCompressedTexSubImage3DARB) bIsLoaded = 0;
	glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)gleIntGetProcAddress("glCompressedTexSubImage2DARB");
	if(!glCompressedTexSubImage2DARB) bIsLoaded = 0;
	glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)gleIntGetProcAddress("glCompressedTexSubImage1DARB");
	if(!glCompressedTexSubImage1DARB) bIsLoaded = 0;
	glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)gleIntGetProcAddress("glGetCompressedTexImageARB");
	if(!glGetCompressedTexImageARB) bIsLoaded = 0;
#endif /*GL_ARB_texture_compression*/
	return bIsLoaded;
}











#ifndef GL_ARB_texture_multisample
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLGETMULTISAMPLEFVPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKIPROC)(GLuint , GLbitfield );

PFNGLTEXIMAGE2DMULTISAMPLEPROC __gleTexImage2DMultisample;
PFNGLTEXIMAGE3DMULTISAMPLEPROC __gleTexImage3DMultisample;
PFNGLGETMULTISAMPLEFVPROC __gleGetMultisamplefv;
PFNGLSAMPLEMASKIPROC __gleSampleMaski;
#endif /*GL_ARB_texture_multisample*/

static int gleIntLoad_ARB_texture_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_multisample
	__gleTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)gleIntGetProcAddress("glTexImage2DMultisample");
	if(!__gleTexImage2DMultisample) bIsLoaded = 0;
	__gleTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)gleIntGetProcAddress("glTexImage3DMultisample");
	if(!__gleTexImage3DMultisample) bIsLoaded = 0;
	__gleGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)gleIntGetProcAddress("glGetMultisamplefv");
	if(!__gleGetMultisamplefv) bIsLoaded = 0;
	__gleSampleMaski = (PFNGLSAMPLEMASKIPROC)gleIntGetProcAddress("glSampleMaski");
	if(!__gleSampleMaski) bIsLoaded = 0;
#endif /*GL_ARB_texture_multisample*/
	return bIsLoaded;
}






#ifndef GL_ARB_texture_storage
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE1DPROC)(GLenum , GLsizei , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE2DPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE3DPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei );

PFNGLTEXSTORAGE1DPROC __gleTexStorage1D;
PFNGLTEXSTORAGE2DPROC __gleTexStorage2D;
PFNGLTEXSTORAGE3DPROC __gleTexStorage3D;
PFNGLTEXTURESTORAGE1DEXTPROC __gleTextureStorage1DEXT;
PFNGLTEXTURESTORAGE2DEXTPROC __gleTextureStorage2DEXT;
PFNGLTEXTURESTORAGE3DEXTPROC __gleTextureStorage3DEXT;
#endif /*GL_ARB_texture_storage*/

static int gleIntLoad_ARB_texture_storage()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_storage
	__gleTexStorage1D = (PFNGLTEXSTORAGE1DPROC)gleIntGetProcAddress("glTexStorage1D");
	if(!__gleTexStorage1D) bIsLoaded = 0;
	__gleTexStorage2D = (PFNGLTEXSTORAGE2DPROC)gleIntGetProcAddress("glTexStorage2D");
	if(!__gleTexStorage2D) bIsLoaded = 0;
	__gleTexStorage3D = (PFNGLTEXSTORAGE3DPROC)gleIntGetProcAddress("glTexStorage3D");
	if(!__gleTexStorage3D) bIsLoaded = 0;
	__gleTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)gleIntGetProcAddress("glTextureStorage1DEXT");
	if(!__gleTextureStorage1DEXT) bIsLoaded = 0;
	__gleTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)gleIntGetProcAddress("glTextureStorage2DEXT");
	if(!__gleTextureStorage2DEXT) bIsLoaded = 0;
	__gleTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)gleIntGetProcAddress("glTextureStorage3DEXT");
	if(!__gleTextureStorage3DEXT) bIsLoaded = 0;
#endif /*GL_ARB_texture_storage*/
	return bIsLoaded;
}
#ifndef GL_ARB_texture_storage_multisample
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei , GLboolean );

PFNGLTEXSTORAGE2DMULTISAMPLEPROC __gleTexStorage2DMultisample;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC __gleTexStorage3DMultisample;
PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC __gleTextureStorage2DMultisampleEXT;
PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC __gleTextureStorage3DMultisampleEXT;
#endif /*GL_ARB_texture_storage_multisample*/

static int gleIntLoad_ARB_texture_storage_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_storage_multisample
	__gleTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)gleIntGetProcAddress("glTexStorage2DMultisample");
	if(!__gleTexStorage2DMultisample) bIsLoaded = 0;
	__gleTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)gleIntGetProcAddress("glTexStorage3DMultisample");
	if(!__gleTexStorage3DMultisample) bIsLoaded = 0;
	__gleTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)gleIntGetProcAddress("glTextureStorage2DMultisampleEXT");
	if(!__gleTextureStorage2DMultisampleEXT) bIsLoaded = 0;
	__gleTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)gleIntGetProcAddress("glTextureStorage3DMultisampleEXT");
	if(!__gleTextureStorage3DMultisampleEXT) bIsLoaded = 0;
#endif /*GL_ARB_texture_storage_multisample*/
	return bIsLoaded;
}

#ifndef GL_ARB_texture_view
typedef void (GLE_FUNCPTR * PFNGLTEXTUREVIEWPROC)(GLuint , GLenum , GLuint , GLenum , GLuint , GLuint , GLuint , GLuint );

PFNGLTEXTUREVIEWPROC __gleTextureView;
#endif /*GL_ARB_texture_view*/

static int gleIntLoad_ARB_texture_view()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_texture_view
	__gleTextureView = (PFNGLTEXTUREVIEWPROC)gleIntGetProcAddress("glTextureView");
	if(!__gleTextureView) bIsLoaded = 0;
#endif /*GL_ARB_texture_view*/
	return bIsLoaded;
}
#ifndef GL_ARB_timer_query
typedef void (GLE_FUNCPTR * PFNGLQUERYCOUNTERPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTI64VPROC)(GLuint , GLenum , GLint64 *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUI64VPROC)(GLuint , GLenum , GLuint64 *);

PFNGLQUERYCOUNTERPROC __gleQueryCounter;
PFNGLGETQUERYOBJECTI64VPROC __gleGetQueryObjecti64v;
PFNGLGETQUERYOBJECTUI64VPROC __gleGetQueryObjectui64v;
#endif /*GL_ARB_timer_query*/

static int gleIntLoad_ARB_timer_query()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_timer_query
	__gleQueryCounter = (PFNGLQUERYCOUNTERPROC)gleIntGetProcAddress("glQueryCounter");
	if(!__gleQueryCounter) bIsLoaded = 0;
	__gleGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)gleIntGetProcAddress("glGetQueryObjecti64v");
	if(!__gleGetQueryObjecti64v) bIsLoaded = 0;
	__gleGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)gleIntGetProcAddress("glGetQueryObjectui64v");
	if(!__gleGetQueryObjectui64v) bIsLoaded = 0;
#endif /*GL_ARB_timer_query*/
	return bIsLoaded;
}
#ifndef GL_ARB_transform_feedback2
typedef void (GLE_FUNCPTR * PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTRANSFORMFEEDBACKPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPAUSETRANSFORMFEEDBACKPROC)();
typedef void (GLE_FUNCPTR * PFNGLRESUMETRANSFORMFEEDBACKPROC)();
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum , GLuint );

PFNGLBINDTRANSFORMFEEDBACKPROC __gleBindTransformFeedback;
PFNGLDELETETRANSFORMFEEDBACKSPROC __gleDeleteTransformFeedbacks;
PFNGLGENTRANSFORMFEEDBACKSPROC __gleGenTransformFeedbacks;
PFNGLISTRANSFORMFEEDBACKPROC __gleIsTransformFeedback;
PFNGLPAUSETRANSFORMFEEDBACKPROC __glePauseTransformFeedback;
PFNGLRESUMETRANSFORMFEEDBACKPROC __gleResumeTransformFeedback;
PFNGLDRAWTRANSFORMFEEDBACKPROC __gleDrawTransformFeedback;
#endif /*GL_ARB_transform_feedback2*/

static int gleIntLoad_ARB_transform_feedback2()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_transform_feedback2
	__gleBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glBindTransformFeedback");
	if(!__gleBindTransformFeedback) bIsLoaded = 0;
	__gleDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)gleIntGetProcAddress("glDeleteTransformFeedbacks");
	if(!__gleDeleteTransformFeedbacks) bIsLoaded = 0;
	__gleGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)gleIntGetProcAddress("glGenTransformFeedbacks");
	if(!__gleGenTransformFeedbacks) bIsLoaded = 0;
	__gleIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glIsTransformFeedback");
	if(!__gleIsTransformFeedback) bIsLoaded = 0;
	__glePauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glPauseTransformFeedback");
	if(!__glePauseTransformFeedback) bIsLoaded = 0;
	__gleResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glResumeTransformFeedback");
	if(!__gleResumeTransformFeedback) bIsLoaded = 0;
	__gleDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glDrawTransformFeedback");
	if(!__gleDrawTransformFeedback) bIsLoaded = 0;
#endif /*GL_ARB_transform_feedback2*/
	return bIsLoaded;
}
#ifndef GL_ARB_transform_feedback3
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYINDEXEDPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDQUERYINDEXEDPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYINDEXEDIVPROC)(GLenum , GLuint , GLenum , GLint *);

PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC __gleDrawTransformFeedbackStream;
PFNGLBEGINQUERYINDEXEDPROC __gleBeginQueryIndexed;
PFNGLENDQUERYINDEXEDPROC __gleEndQueryIndexed;
PFNGLGETQUERYINDEXEDIVPROC __gleGetQueryIndexediv;
#endif /*GL_ARB_transform_feedback3*/

static int gleIntLoad_ARB_transform_feedback3()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_transform_feedback3
	__gleDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)gleIntGetProcAddress("glDrawTransformFeedbackStream");
	if(!__gleDrawTransformFeedbackStream) bIsLoaded = 0;
	__gleBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)gleIntGetProcAddress("glBeginQueryIndexed");
	if(!__gleBeginQueryIndexed) bIsLoaded = 0;
	__gleEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)gleIntGetProcAddress("glEndQueryIndexed");
	if(!__gleEndQueryIndexed) bIsLoaded = 0;
	__gleGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)gleIntGetProcAddress("glGetQueryIndexediv");
	if(!__gleGetQueryIndexediv) bIsLoaded = 0;
#endif /*GL_ARB_transform_feedback3*/
	return bIsLoaded;
}
#ifndef GL_ARB_transform_feedback_instanced
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum , GLuint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum , GLuint , GLuint , GLsizei );

PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC __gleDrawTransformFeedbackInstanced;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC __gleDrawTransformFeedbackStreamInstanced;
#endif /*GL_ARB_transform_feedback_instanced*/

static int gleIntLoad_ARB_transform_feedback_instanced()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_transform_feedback_instanced
	__gleDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)gleIntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!__gleDrawTransformFeedbackInstanced) bIsLoaded = 0;
	__gleDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)gleIntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!__gleDrawTransformFeedbackStreamInstanced) bIsLoaded = 0;
#endif /*GL_ARB_transform_feedback_instanced*/
	return bIsLoaded;
}
#ifndef GL_ARB_transpose_matrix
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *);

PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARB;
PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARB;
PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARB;
PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARB;
#endif /*GL_ARB_transpose_matrix*/

static int gleIntLoad_ARB_transpose_matrix()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_transpose_matrix
	glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)gleIntGetProcAddress("glLoadTransposeMatrixfARB");
	if(!glLoadTransposeMatrixfARB) bIsLoaded = 0;
	glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)gleIntGetProcAddress("glLoadTransposeMatrixdARB");
	if(!glLoadTransposeMatrixdARB) bIsLoaded = 0;
	glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)gleIntGetProcAddress("glMultTransposeMatrixfARB");
	if(!glMultTransposeMatrixfARB) bIsLoaded = 0;
	glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)gleIntGetProcAddress("glMultTransposeMatrixdARB");
	if(!glMultTransposeMatrixdARB) bIsLoaded = 0;
#endif /*GL_ARB_transpose_matrix*/
	return bIsLoaded;
}
#ifndef GL_ARB_uniform_buffer_object
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMINDICESPROC)(GLuint , GLsizei , const GLchar* const *, GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint , GLsizei , const GLuint *, GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint , GLuint , GLuint );

PFNGLGETUNIFORMINDICESPROC __gleGetUniformIndices;
PFNGLGETACTIVEUNIFORMSIVPROC __gleGetActiveUniformsiv;
PFNGLGETACTIVEUNIFORMNAMEPROC __gleGetActiveUniformName;
PFNGLGETUNIFORMBLOCKINDEXPROC __gleGetUniformBlockIndex;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC __gleGetActiveUniformBlockiv;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC __gleGetActiveUniformBlockName;
PFNGLUNIFORMBLOCKBINDINGPROC __gleUniformBlockBinding;
#endif /*GL_ARB_uniform_buffer_object*/

static int gleIntLoad_ARB_uniform_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_uniform_buffer_object
	__gleGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)gleIntGetProcAddress("glGetUniformIndices");
	if(!__gleGetUniformIndices) bIsLoaded = 0;
	__gleGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)gleIntGetProcAddress("glGetActiveUniformsiv");
	if(!__gleGetActiveUniformsiv) bIsLoaded = 0;
	__gleGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)gleIntGetProcAddress("glGetActiveUniformName");
	if(!__gleGetActiveUniformName) bIsLoaded = 0;
	__gleGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)gleIntGetProcAddress("glGetUniformBlockIndex");
	if(!__gleGetUniformBlockIndex) bIsLoaded = 0;
	__gleGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)gleIntGetProcAddress("glGetActiveUniformBlockiv");
	if(!__gleGetActiveUniformBlockiv) bIsLoaded = 0;
	__gleGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)gleIntGetProcAddress("glGetActiveUniformBlockName");
	if(!__gleGetActiveUniformBlockName) bIsLoaded = 0;
	__gleUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)gleIntGetProcAddress("glUniformBlockBinding");
	if(!__gleUniformBlockBinding) bIsLoaded = 0;
#endif /*GL_ARB_uniform_buffer_object*/
	return bIsLoaded;
}

#ifndef GL_ARB_vertex_array_object
typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXARRAYPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEVERTEXARRAYSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENVERTEXARRAYSPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXARRAYPROC)(GLuint );

PFNGLBINDVERTEXARRAYPROC __gleBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC __gleDeleteVertexArrays;
PFNGLGENVERTEXARRAYSPROC __gleGenVertexArrays;
PFNGLISVERTEXARRAYPROC __gleIsVertexArray;
#endif /*GL_ARB_vertex_array_object*/

static int gleIntLoad_ARB_vertex_array_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_array_object
	__gleBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)gleIntGetProcAddress("glBindVertexArray");
	if(!__gleBindVertexArray) bIsLoaded = 0;
	__gleDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)gleIntGetProcAddress("glDeleteVertexArrays");
	if(!__gleDeleteVertexArrays) bIsLoaded = 0;
	__gleGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)gleIntGetProcAddress("glGenVertexArrays");
	if(!__gleGenVertexArrays) bIsLoaded = 0;
	__gleIsVertexArray = (PFNGLISVERTEXARRAYPROC)gleIntGetProcAddress("glIsVertexArray");
	if(!__gleIsVertexArray) bIsLoaded = 0;
#endif /*GL_ARB_vertex_array_object*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_attrib_64bit
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1DPROC)(GLuint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2DPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3DPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4DPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBLPOINTERPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBLDVPROC)(GLuint , GLenum , GLdouble *);

PFNGLVERTEXATTRIBL1DPROC __gleVertexAttribL1d;
PFNGLVERTEXATTRIBL2DPROC __gleVertexAttribL2d;
PFNGLVERTEXATTRIBL3DPROC __gleVertexAttribL3d;
PFNGLVERTEXATTRIBL4DPROC __gleVertexAttribL4d;
PFNGLVERTEXATTRIBL1DVPROC __gleVertexAttribL1dv;
PFNGLVERTEXATTRIBL2DVPROC __gleVertexAttribL2dv;
PFNGLVERTEXATTRIBL3DVPROC __gleVertexAttribL3dv;
PFNGLVERTEXATTRIBL4DVPROC __gleVertexAttribL4dv;
PFNGLVERTEXATTRIBLPOINTERPROC __gleVertexAttribLPointer;
PFNGLGETVERTEXATTRIBLDVPROC __gleGetVertexAttribLdv;
#endif /*GL_ARB_vertex_attrib_64bit*/

static int gleIntLoad_ARB_vertex_attrib_64bit()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_attrib_64bit
	__gleVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)gleIntGetProcAddress("glVertexAttribL1d");
	if(!__gleVertexAttribL1d) bIsLoaded = 0;
	__gleVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)gleIntGetProcAddress("glVertexAttribL2d");
	if(!__gleVertexAttribL2d) bIsLoaded = 0;
	__gleVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)gleIntGetProcAddress("glVertexAttribL3d");
	if(!__gleVertexAttribL3d) bIsLoaded = 0;
	__gleVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)gleIntGetProcAddress("glVertexAttribL4d");
	if(!__gleVertexAttribL4d) bIsLoaded = 0;
	__gleVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)gleIntGetProcAddress("glVertexAttribL1dv");
	if(!__gleVertexAttribL1dv) bIsLoaded = 0;
	__gleVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)gleIntGetProcAddress("glVertexAttribL2dv");
	if(!__gleVertexAttribL2dv) bIsLoaded = 0;
	__gleVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)gleIntGetProcAddress("glVertexAttribL3dv");
	if(!__gleVertexAttribL3dv) bIsLoaded = 0;
	__gleVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)gleIntGetProcAddress("glVertexAttribL4dv");
	if(!__gleVertexAttribL4dv) bIsLoaded = 0;
	__gleVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)gleIntGetProcAddress("glVertexAttribLPointer");
	if(!__gleVertexAttribLPointer) bIsLoaded = 0;
	__gleGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)gleIntGetProcAddress("glGetVertexAttribLdv");
	if(!__gleGetVertexAttribLdv) bIsLoaded = 0;
#endif /*GL_ARB_vertex_attrib_64bit*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_attrib_binding
typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXBUFFERPROC)(GLuint , GLuint , GLintptr , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBFORMATPROC)(GLuint , GLint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBIFORMATPROC)(GLuint , GLint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBLFORMATPROC)(GLuint , GLint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBBINDINGPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXBINDINGDIVISORPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)(GLuint , GLuint , GLuint , GLintptr , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)(GLuint , GLuint , GLint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)(GLuint , GLuint , GLint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)(GLuint , GLuint , GLint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)(GLuint , GLuint , GLuint );

PFNGLBINDVERTEXBUFFERPROC __gleBindVertexBuffer;
PFNGLVERTEXATTRIBFORMATPROC __gleVertexAttribFormat;
PFNGLVERTEXATTRIBIFORMATPROC __gleVertexAttribIFormat;
PFNGLVERTEXATTRIBLFORMATPROC __gleVertexAttribLFormat;
PFNGLVERTEXATTRIBBINDINGPROC __gleVertexAttribBinding;
PFNGLVERTEXBINDINGDIVISORPROC __gleVertexBindingDivisor;
PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC __gleVertexArrayBindVertexBufferEXT;
PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC __gleVertexArrayVertexAttribFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC __gleVertexArrayVertexAttribIFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC __gleVertexArrayVertexAttribLFormatEXT;
PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC __gleVertexArrayVertexAttribBindingEXT;
PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC __gleVertexArrayVertexBindingDivisorEXT;
#endif /*GL_ARB_vertex_attrib_binding*/

static int gleIntLoad_ARB_vertex_attrib_binding()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_attrib_binding
	__gleBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)gleIntGetProcAddress("glBindVertexBuffer");
	if(!__gleBindVertexBuffer) bIsLoaded = 0;
	__gleVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)gleIntGetProcAddress("glVertexAttribFormat");
	if(!__gleVertexAttribFormat) bIsLoaded = 0;
	__gleVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)gleIntGetProcAddress("glVertexAttribIFormat");
	if(!__gleVertexAttribIFormat) bIsLoaded = 0;
	__gleVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)gleIntGetProcAddress("glVertexAttribLFormat");
	if(!__gleVertexAttribLFormat) bIsLoaded = 0;
	__gleVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)gleIntGetProcAddress("glVertexAttribBinding");
	if(!__gleVertexAttribBinding) bIsLoaded = 0;
	__gleVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)gleIntGetProcAddress("glVertexBindingDivisor");
	if(!__gleVertexBindingDivisor) bIsLoaded = 0;
	__gleVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)gleIntGetProcAddress("glVertexArrayBindVertexBufferEXT");
	if(!__gleVertexArrayBindVertexBufferEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	if(!__gleVertexArrayVertexAttribFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	if(!__gleVertexArrayVertexAttribIFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	if(!__gleVertexArrayVertexAttribLFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	if(!__gleVertexArrayVertexAttribBindingEXT) bIsLoaded = 0;
	__gleVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)gleIntGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	if(!__gleVertexArrayVertexBindingDivisorEXT) bIsLoaded = 0;
#endif /*GL_ARB_vertex_attrib_binding*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_blend
typedef void (GLE_FUNCPTR * PFNGLWEIGHTBVARBPROC)(GLint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTSVARBPROC)(GLint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTIVARBPROC)(GLint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTFVARBPROC)(GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTDVARBPROC)(GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTUBVARBPROC)(GLint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTUSVARBPROC)(GLint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTUIVARBPROC)(GLint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLWEIGHTPOINTERARBPROC)(GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXBLENDARBPROC)(GLint );

PFNGLWEIGHTBVARBPROC glWeightbvARB;
PFNGLWEIGHTSVARBPROC glWeightsvARB;
PFNGLWEIGHTIVARBPROC glWeightivARB;
PFNGLWEIGHTFVARBPROC glWeightfvARB;
PFNGLWEIGHTDVARBPROC glWeightdvARB;
PFNGLWEIGHTUBVARBPROC glWeightubvARB;
PFNGLWEIGHTUSVARBPROC glWeightusvARB;
PFNGLWEIGHTUIVARBPROC glWeightuivARB;
PFNGLWEIGHTPOINTERARBPROC glWeightPointerARB;
PFNGLVERTEXBLENDARBPROC glVertexBlendARB;
#endif /*GL_ARB_vertex_blend*/

static int gleIntLoad_ARB_vertex_blend()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_blend
	glWeightbvARB = (PFNGLWEIGHTBVARBPROC)gleIntGetProcAddress("glWeightbvARB");
	if(!glWeightbvARB) bIsLoaded = 0;
	glWeightsvARB = (PFNGLWEIGHTSVARBPROC)gleIntGetProcAddress("glWeightsvARB");
	if(!glWeightsvARB) bIsLoaded = 0;
	glWeightivARB = (PFNGLWEIGHTIVARBPROC)gleIntGetProcAddress("glWeightivARB");
	if(!glWeightivARB) bIsLoaded = 0;
	glWeightfvARB = (PFNGLWEIGHTFVARBPROC)gleIntGetProcAddress("glWeightfvARB");
	if(!glWeightfvARB) bIsLoaded = 0;
	glWeightdvARB = (PFNGLWEIGHTDVARBPROC)gleIntGetProcAddress("glWeightdvARB");
	if(!glWeightdvARB) bIsLoaded = 0;
	glWeightubvARB = (PFNGLWEIGHTUBVARBPROC)gleIntGetProcAddress("glWeightubvARB");
	if(!glWeightubvARB) bIsLoaded = 0;
	glWeightusvARB = (PFNGLWEIGHTUSVARBPROC)gleIntGetProcAddress("glWeightusvARB");
	if(!glWeightusvARB) bIsLoaded = 0;
	glWeightuivARB = (PFNGLWEIGHTUIVARBPROC)gleIntGetProcAddress("glWeightuivARB");
	if(!glWeightuivARB) bIsLoaded = 0;
	glWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC)gleIntGetProcAddress("glWeightPointerARB");
	if(!glWeightPointerARB) bIsLoaded = 0;
	glVertexBlendARB = (PFNGLVERTEXBLENDARBPROC)gleIntGetProcAddress("glVertexBlendARB");
	if(!glVertexBlendARB) bIsLoaded = 0;
#endif /*GL_ARB_vertex_blend*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_buffer_object
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERARBPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEBUFFERSARBPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENBUFFERSARBPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISBUFFERARBPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBUFFERDATAARBPROC)(GLenum , GLsizeiptrARB , const GLvoid *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLBUFFERSUBDATAARBPROC)(GLenum , GLintptrARB , GLsizeiptrARB , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERSUBDATAARBPROC)(GLenum , GLintptrARB , GLsizeiptrARB , GLvoid *);
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPBUFFERARBPROC)(GLenum , GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLUNMAPBUFFERARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPARAMETERIVARBPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPOINTERVARBPROC)(GLenum , GLenum , GLvoid* *);

PFNGLBINDBUFFERARBPROC glBindBufferARB;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
PFNGLGENBUFFERSARBPROC glGenBuffersARB;
PFNGLISBUFFERARBPROC glIsBufferARB;
PFNGLBUFFERDATAARBPROC glBufferDataARB;
PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB;
PFNGLMAPBUFFERARBPROC glMapBufferARB;
PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;
PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB;
#endif /*GL_ARB_vertex_buffer_object*/

static int gleIntLoad_ARB_vertex_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_buffer_object
	glBindBufferARB = (PFNGLBINDBUFFERARBPROC)gleIntGetProcAddress("glBindBufferARB");
	if(!glBindBufferARB) bIsLoaded = 0;
	glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)gleIntGetProcAddress("glDeleteBuffersARB");
	if(!glDeleteBuffersARB) bIsLoaded = 0;
	glGenBuffersARB = (PFNGLGENBUFFERSARBPROC)gleIntGetProcAddress("glGenBuffersARB");
	if(!glGenBuffersARB) bIsLoaded = 0;
	glIsBufferARB = (PFNGLISBUFFERARBPROC)gleIntGetProcAddress("glIsBufferARB");
	if(!glIsBufferARB) bIsLoaded = 0;
	glBufferDataARB = (PFNGLBUFFERDATAARBPROC)gleIntGetProcAddress("glBufferDataARB");
	if(!glBufferDataARB) bIsLoaded = 0;
	glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)gleIntGetProcAddress("glBufferSubDataARB");
	if(!glBufferSubDataARB) bIsLoaded = 0;
	glGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC)gleIntGetProcAddress("glGetBufferSubDataARB");
	if(!glGetBufferSubDataARB) bIsLoaded = 0;
	glMapBufferARB = (PFNGLMAPBUFFERARBPROC)gleIntGetProcAddress("glMapBufferARB");
	if(!glMapBufferARB) bIsLoaded = 0;
	glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC)gleIntGetProcAddress("glUnmapBufferARB");
	if(!glUnmapBufferARB) bIsLoaded = 0;
	glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC)gleIntGetProcAddress("glGetBufferParameterivARB");
	if(!glGetBufferParameterivARB) bIsLoaded = 0;
	glGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC)gleIntGetProcAddress("glGetBufferPointervARB");
	if(!glGetBufferPointervARB) bIsLoaded = 0;
#endif /*GL_ARB_vertex_buffer_object*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_program
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DARBPROC)(GLuint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DVARBPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FARBPROC)(GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FVARBPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SARBPROC)(GLuint , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SVARBPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DARBPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DVARBPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FARBPROC)(GLuint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FVARBPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SARBPROC)(GLuint , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SVARBPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DARBPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DVARBPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FARBPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FVARBPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SARBPROC)(GLuint , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SVARBPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NBVARBPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NIVARBPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NSVARBPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBARBPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBVARBPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUIVARBPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUSVARBPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4BVARBPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DARBPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DVARBPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FARBPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FVARBPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4IVARBPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SARBPROC)(GLuint , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SVARBPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UBVARBPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UIVARBPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4USVARBPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBPOINTERARBPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXATTRIBARRAYARBPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMSTRINGARBPROC)(GLenum , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLBINDPROGRAMARBPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEPROGRAMSARBPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENPROGRAMSARBPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETER4DARBPROC)(GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETER4DVARBPROC)(GLenum , GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETER4FARBPROC)(GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETER4FVARBPROC)(GLenum , GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETER4DARBPROC)(GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)(GLenum , GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETER4FARBPROC)(GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)(GLenum , GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMENVPARAMETERDVARBPROC)(GLenum , GLuint , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMENVPARAMETERFVARBPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)(GLenum , GLuint , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMIVARBPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSTRINGARBPROC)(GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBDVARBPROC)(GLuint , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBFVARBPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIVARBPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBPOINTERVARBPROC)(GLuint , GLenum , GLvoid* *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISPROGRAMARBPROC)(GLuint );

PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB;
PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB;
PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB;
PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB;
PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB;
PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB;
PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB;
PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB;
PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB;
PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB;
PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB;
PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB;
PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB;
PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB;
PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB;
PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB;
PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB;
PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB;
PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB;
PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB;
PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB;
PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB;
PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB;
PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB;
PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB;
PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB;
PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB;
PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB;
PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB;
PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB;
PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB;
PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB;
PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB;
PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB;
PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB;
PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB;
PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB;
PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB;
PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB;
PFNGLPROGRAMSTRINGARBPROC glProgramStringARB;
PFNGLBINDPROGRAMARBPROC glBindProgramARB;
PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB;
PFNGLGENPROGRAMSARBPROC glGenProgramsARB;
PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB;
PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB;
PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB;
PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB;
PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB;
PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB;
PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB;
PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB;
PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB;
PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB;
PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB;
PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB;
PFNGLGETPROGRAMIVARBPROC glGetProgramivARB;
PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB;
PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB;
PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB;
PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB;
PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB;
PFNGLISPROGRAMARBPROC glIsProgramARB;
#endif /*GL_ARB_vertex_program*/

static int gleIntLoad_ARB_vertex_program()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_program
	glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)gleIntGetProcAddress("glVertexAttrib1dARB");
	if(!glVertexAttrib1dARB) bIsLoaded = 0;
	glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)gleIntGetProcAddress("glVertexAttrib1dvARB");
	if(!glVertexAttrib1dvARB) bIsLoaded = 0;
	glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)gleIntGetProcAddress("glVertexAttrib1fARB");
	if(!glVertexAttrib1fARB) bIsLoaded = 0;
	glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)gleIntGetProcAddress("glVertexAttrib1fvARB");
	if(!glVertexAttrib1fvARB) bIsLoaded = 0;
	glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)gleIntGetProcAddress("glVertexAttrib1sARB");
	if(!glVertexAttrib1sARB) bIsLoaded = 0;
	glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)gleIntGetProcAddress("glVertexAttrib1svARB");
	if(!glVertexAttrib1svARB) bIsLoaded = 0;
	glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)gleIntGetProcAddress("glVertexAttrib2dARB");
	if(!glVertexAttrib2dARB) bIsLoaded = 0;
	glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)gleIntGetProcAddress("glVertexAttrib2dvARB");
	if(!glVertexAttrib2dvARB) bIsLoaded = 0;
	glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)gleIntGetProcAddress("glVertexAttrib2fARB");
	if(!glVertexAttrib2fARB) bIsLoaded = 0;
	glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)gleIntGetProcAddress("glVertexAttrib2fvARB");
	if(!glVertexAttrib2fvARB) bIsLoaded = 0;
	glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)gleIntGetProcAddress("glVertexAttrib2sARB");
	if(!glVertexAttrib2sARB) bIsLoaded = 0;
	glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)gleIntGetProcAddress("glVertexAttrib2svARB");
	if(!glVertexAttrib2svARB) bIsLoaded = 0;
	glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)gleIntGetProcAddress("glVertexAttrib3dARB");
	if(!glVertexAttrib3dARB) bIsLoaded = 0;
	glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)gleIntGetProcAddress("glVertexAttrib3dvARB");
	if(!glVertexAttrib3dvARB) bIsLoaded = 0;
	glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)gleIntGetProcAddress("glVertexAttrib3fARB");
	if(!glVertexAttrib3fARB) bIsLoaded = 0;
	glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)gleIntGetProcAddress("glVertexAttrib3fvARB");
	if(!glVertexAttrib3fvARB) bIsLoaded = 0;
	glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)gleIntGetProcAddress("glVertexAttrib3sARB");
	if(!glVertexAttrib3sARB) bIsLoaded = 0;
	glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)gleIntGetProcAddress("glVertexAttrib3svARB");
	if(!glVertexAttrib3svARB) bIsLoaded = 0;
	glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)gleIntGetProcAddress("glVertexAttrib4NbvARB");
	if(!glVertexAttrib4NbvARB) bIsLoaded = 0;
	glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)gleIntGetProcAddress("glVertexAttrib4NivARB");
	if(!glVertexAttrib4NivARB) bIsLoaded = 0;
	glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)gleIntGetProcAddress("glVertexAttrib4NsvARB");
	if(!glVertexAttrib4NsvARB) bIsLoaded = 0;
	glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)gleIntGetProcAddress("glVertexAttrib4NubARB");
	if(!glVertexAttrib4NubARB) bIsLoaded = 0;
	glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)gleIntGetProcAddress("glVertexAttrib4NubvARB");
	if(!glVertexAttrib4NubvARB) bIsLoaded = 0;
	glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)gleIntGetProcAddress("glVertexAttrib4NuivARB");
	if(!glVertexAttrib4NuivARB) bIsLoaded = 0;
	glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)gleIntGetProcAddress("glVertexAttrib4NusvARB");
	if(!glVertexAttrib4NusvARB) bIsLoaded = 0;
	glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)gleIntGetProcAddress("glVertexAttrib4bvARB");
	if(!glVertexAttrib4bvARB) bIsLoaded = 0;
	glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)gleIntGetProcAddress("glVertexAttrib4dARB");
	if(!glVertexAttrib4dARB) bIsLoaded = 0;
	glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)gleIntGetProcAddress("glVertexAttrib4dvARB");
	if(!glVertexAttrib4dvARB) bIsLoaded = 0;
	glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)gleIntGetProcAddress("glVertexAttrib4fARB");
	if(!glVertexAttrib4fARB) bIsLoaded = 0;
	glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)gleIntGetProcAddress("glVertexAttrib4fvARB");
	if(!glVertexAttrib4fvARB) bIsLoaded = 0;
	glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)gleIntGetProcAddress("glVertexAttrib4ivARB");
	if(!glVertexAttrib4ivARB) bIsLoaded = 0;
	glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)gleIntGetProcAddress("glVertexAttrib4sARB");
	if(!glVertexAttrib4sARB) bIsLoaded = 0;
	glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)gleIntGetProcAddress("glVertexAttrib4svARB");
	if(!glVertexAttrib4svARB) bIsLoaded = 0;
	glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)gleIntGetProcAddress("glVertexAttrib4ubvARB");
	if(!glVertexAttrib4ubvARB) bIsLoaded = 0;
	glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)gleIntGetProcAddress("glVertexAttrib4uivARB");
	if(!glVertexAttrib4uivARB) bIsLoaded = 0;
	glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)gleIntGetProcAddress("glVertexAttrib4usvARB");
	if(!glVertexAttrib4usvARB) bIsLoaded = 0;
	glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)gleIntGetProcAddress("glVertexAttribPointerARB");
	if(!glVertexAttribPointerARB) bIsLoaded = 0;
	glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)gleIntGetProcAddress("glEnableVertexAttribArrayARB");
	if(!glEnableVertexAttribArrayARB) bIsLoaded = 0;
	glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)gleIntGetProcAddress("glDisableVertexAttribArrayARB");
	if(!glDisableVertexAttribArrayARB) bIsLoaded = 0;
	glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)gleIntGetProcAddress("glProgramStringARB");
	if(!glProgramStringARB) bIsLoaded = 0;
	glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)gleIntGetProcAddress("glBindProgramARB");
	if(!glBindProgramARB) bIsLoaded = 0;
	glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)gleIntGetProcAddress("glDeleteProgramsARB");
	if(!glDeleteProgramsARB) bIsLoaded = 0;
	glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)gleIntGetProcAddress("glGenProgramsARB");
	if(!glGenProgramsARB) bIsLoaded = 0;
	glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)gleIntGetProcAddress("glProgramEnvParameter4dARB");
	if(!glProgramEnvParameter4dARB) bIsLoaded = 0;
	glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)gleIntGetProcAddress("glProgramEnvParameter4dvARB");
	if(!glProgramEnvParameter4dvARB) bIsLoaded = 0;
	glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)gleIntGetProcAddress("glProgramEnvParameter4fARB");
	if(!glProgramEnvParameter4fARB) bIsLoaded = 0;
	glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)gleIntGetProcAddress("glProgramEnvParameter4fvARB");
	if(!glProgramEnvParameter4fvARB) bIsLoaded = 0;
	glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)gleIntGetProcAddress("glProgramLocalParameter4dARB");
	if(!glProgramLocalParameter4dARB) bIsLoaded = 0;
	glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)gleIntGetProcAddress("glProgramLocalParameter4dvARB");
	if(!glProgramLocalParameter4dvARB) bIsLoaded = 0;
	glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)gleIntGetProcAddress("glProgramLocalParameter4fARB");
	if(!glProgramLocalParameter4fARB) bIsLoaded = 0;
	glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)gleIntGetProcAddress("glProgramLocalParameter4fvARB");
	if(!glProgramLocalParameter4fvARB) bIsLoaded = 0;
	glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)gleIntGetProcAddress("glGetProgramEnvParameterdvARB");
	if(!glGetProgramEnvParameterdvARB) bIsLoaded = 0;
	glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)gleIntGetProcAddress("glGetProgramEnvParameterfvARB");
	if(!glGetProgramEnvParameterfvARB) bIsLoaded = 0;
	glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)gleIntGetProcAddress("glGetProgramLocalParameterdvARB");
	if(!glGetProgramLocalParameterdvARB) bIsLoaded = 0;
	glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)gleIntGetProcAddress("glGetProgramLocalParameterfvARB");
	if(!glGetProgramLocalParameterfvARB) bIsLoaded = 0;
	glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)gleIntGetProcAddress("glGetProgramivARB");
	if(!glGetProgramivARB) bIsLoaded = 0;
	glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)gleIntGetProcAddress("glGetProgramStringARB");
	if(!glGetProgramStringARB) bIsLoaded = 0;
	glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)gleIntGetProcAddress("glGetVertexAttribdvARB");
	if(!glGetVertexAttribdvARB) bIsLoaded = 0;
	glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)gleIntGetProcAddress("glGetVertexAttribfvARB");
	if(!glGetVertexAttribfvARB) bIsLoaded = 0;
	glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)gleIntGetProcAddress("glGetVertexAttribivARB");
	if(!glGetVertexAttribivARB) bIsLoaded = 0;
	glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)gleIntGetProcAddress("glGetVertexAttribPointervARB");
	if(!glGetVertexAttribPointervARB) bIsLoaded = 0;
	glIsProgramARB = (PFNGLISPROGRAMARBPROC)gleIntGetProcAddress("glIsProgramARB");
	if(!glIsProgramARB) bIsLoaded = 0;
#endif /*GL_ARB_vertex_program*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_shader
typedef void (GLE_FUNCPTR * PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB , GLuint , const GLcharARB *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLcharARB *);
typedef GLint (GLE_FUNCPTR * PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB , const GLcharARB *);

PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB;
PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB;
PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB;
#endif /*GL_ARB_vertex_shader*/

static int gleIntLoad_ARB_vertex_shader()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_shader
	glBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC)gleIntGetProcAddress("glBindAttribLocationARB");
	if(!glBindAttribLocationARB) bIsLoaded = 0;
	glGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC)gleIntGetProcAddress("glGetActiveAttribARB");
	if(!glGetActiveAttribARB) bIsLoaded = 0;
	glGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC)gleIntGetProcAddress("glGetAttribLocationARB");
	if(!glGetAttribLocationARB) bIsLoaded = 0;
#endif /*GL_ARB_vertex_shader*/
	return bIsLoaded;
}
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
typedef void (GLE_FUNCPTR * PFNGLVERTEXP2UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXP2UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXP3UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXP3UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXP4UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXP4UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP1UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP1UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP2UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP2UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP3UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP3UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP4UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDP4UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP1UIPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP1UIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP2UIPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP2UIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP3UIPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP3UIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP4UIPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDP4UIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLNORMALP3UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLNORMALP3UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCOLORP3UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLORP3UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCOLORP4UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLORP4UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORP3UIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORP3UIVPROC)(GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP1UIPROC)(GLuint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP1UIVPROC)(GLuint , GLenum , GLboolean , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP2UIPROC)(GLuint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP2UIVPROC)(GLuint , GLenum , GLboolean , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP3UIPROC)(GLuint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP3UIVPROC)(GLuint , GLenum , GLboolean , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP4UIPROC)(GLuint , GLenum , GLboolean , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBP4UIVPROC)(GLuint , GLenum , GLboolean , const GLuint *);

PFNGLVERTEXP2UIPROC __gleVertexP2ui;
PFNGLVERTEXP2UIVPROC __gleVertexP2uiv;
PFNGLVERTEXP3UIPROC __gleVertexP3ui;
PFNGLVERTEXP3UIVPROC __gleVertexP3uiv;
PFNGLVERTEXP4UIPROC __gleVertexP4ui;
PFNGLVERTEXP4UIVPROC __gleVertexP4uiv;
PFNGLTEXCOORDP1UIPROC __gleTexCoordP1ui;
PFNGLTEXCOORDP1UIVPROC __gleTexCoordP1uiv;
PFNGLTEXCOORDP2UIPROC __gleTexCoordP2ui;
PFNGLTEXCOORDP2UIVPROC __gleTexCoordP2uiv;
PFNGLTEXCOORDP3UIPROC __gleTexCoordP3ui;
PFNGLTEXCOORDP3UIVPROC __gleTexCoordP3uiv;
PFNGLTEXCOORDP4UIPROC __gleTexCoordP4ui;
PFNGLTEXCOORDP4UIVPROC __gleTexCoordP4uiv;
PFNGLMULTITEXCOORDP1UIPROC __gleMultiTexCoordP1ui;
PFNGLMULTITEXCOORDP1UIVPROC __gleMultiTexCoordP1uiv;
PFNGLMULTITEXCOORDP2UIPROC __gleMultiTexCoordP2ui;
PFNGLMULTITEXCOORDP2UIVPROC __gleMultiTexCoordP2uiv;
PFNGLMULTITEXCOORDP3UIPROC __gleMultiTexCoordP3ui;
PFNGLMULTITEXCOORDP3UIVPROC __gleMultiTexCoordP3uiv;
PFNGLMULTITEXCOORDP4UIPROC __gleMultiTexCoordP4ui;
PFNGLMULTITEXCOORDP4UIVPROC __gleMultiTexCoordP4uiv;
PFNGLNORMALP3UIPROC __gleNormalP3ui;
PFNGLNORMALP3UIVPROC __gleNormalP3uiv;
PFNGLCOLORP3UIPROC __gleColorP3ui;
PFNGLCOLORP3UIVPROC __gleColorP3uiv;
PFNGLCOLORP4UIPROC __gleColorP4ui;
PFNGLCOLORP4UIVPROC __gleColorP4uiv;
PFNGLSECONDARYCOLORP3UIPROC __gleSecondaryColorP3ui;
PFNGLSECONDARYCOLORP3UIVPROC __gleSecondaryColorP3uiv;
PFNGLVERTEXATTRIBP1UIPROC __gleVertexAttribP1ui;
PFNGLVERTEXATTRIBP1UIVPROC __gleVertexAttribP1uiv;
PFNGLVERTEXATTRIBP2UIPROC __gleVertexAttribP2ui;
PFNGLVERTEXATTRIBP2UIVPROC __gleVertexAttribP2uiv;
PFNGLVERTEXATTRIBP3UIPROC __gleVertexAttribP3ui;
PFNGLVERTEXATTRIBP3UIVPROC __gleVertexAttribP3uiv;
PFNGLVERTEXATTRIBP4UIPROC __gleVertexAttribP4ui;
PFNGLVERTEXATTRIBP4UIVPROC __gleVertexAttribP4uiv;
#endif /*GL_ARB_vertex_type_2_10_10_10_rev*/

static int gleIntLoad_ARB_vertex_type_2_10_10_10_rev()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_vertex_type_2_10_10_10_rev
	__gleVertexP2ui = (PFNGLVERTEXP2UIPROC)gleIntGetProcAddress("glVertexP2ui");
	if(!__gleVertexP2ui) bIsLoaded = 0;
	__gleVertexP2uiv = (PFNGLVERTEXP2UIVPROC)gleIntGetProcAddress("glVertexP2uiv");
	if(!__gleVertexP2uiv) bIsLoaded = 0;
	__gleVertexP3ui = (PFNGLVERTEXP3UIPROC)gleIntGetProcAddress("glVertexP3ui");
	if(!__gleVertexP3ui) bIsLoaded = 0;
	__gleVertexP3uiv = (PFNGLVERTEXP3UIVPROC)gleIntGetProcAddress("glVertexP3uiv");
	if(!__gleVertexP3uiv) bIsLoaded = 0;
	__gleVertexP4ui = (PFNGLVERTEXP4UIPROC)gleIntGetProcAddress("glVertexP4ui");
	if(!__gleVertexP4ui) bIsLoaded = 0;
	__gleVertexP4uiv = (PFNGLVERTEXP4UIVPROC)gleIntGetProcAddress("glVertexP4uiv");
	if(!__gleVertexP4uiv) bIsLoaded = 0;
	__gleTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)gleIntGetProcAddress("glTexCoordP1ui");
	if(!__gleTexCoordP1ui) bIsLoaded = 0;
	__gleTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)gleIntGetProcAddress("glTexCoordP1uiv");
	if(!__gleTexCoordP1uiv) bIsLoaded = 0;
	__gleTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)gleIntGetProcAddress("glTexCoordP2ui");
	if(!__gleTexCoordP2ui) bIsLoaded = 0;
	__gleTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)gleIntGetProcAddress("glTexCoordP2uiv");
	if(!__gleTexCoordP2uiv) bIsLoaded = 0;
	__gleTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)gleIntGetProcAddress("glTexCoordP3ui");
	if(!__gleTexCoordP3ui) bIsLoaded = 0;
	__gleTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)gleIntGetProcAddress("glTexCoordP3uiv");
	if(!__gleTexCoordP3uiv) bIsLoaded = 0;
	__gleTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)gleIntGetProcAddress("glTexCoordP4ui");
	if(!__gleTexCoordP4ui) bIsLoaded = 0;
	__gleTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)gleIntGetProcAddress("glTexCoordP4uiv");
	if(!__gleTexCoordP4uiv) bIsLoaded = 0;
	__gleMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)gleIntGetProcAddress("glMultiTexCoordP1ui");
	if(!__gleMultiTexCoordP1ui) bIsLoaded = 0;
	__gleMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)gleIntGetProcAddress("glMultiTexCoordP1uiv");
	if(!__gleMultiTexCoordP1uiv) bIsLoaded = 0;
	__gleMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)gleIntGetProcAddress("glMultiTexCoordP2ui");
	if(!__gleMultiTexCoordP2ui) bIsLoaded = 0;
	__gleMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)gleIntGetProcAddress("glMultiTexCoordP2uiv");
	if(!__gleMultiTexCoordP2uiv) bIsLoaded = 0;
	__gleMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)gleIntGetProcAddress("glMultiTexCoordP3ui");
	if(!__gleMultiTexCoordP3ui) bIsLoaded = 0;
	__gleMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)gleIntGetProcAddress("glMultiTexCoordP3uiv");
	if(!__gleMultiTexCoordP3uiv) bIsLoaded = 0;
	__gleMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)gleIntGetProcAddress("glMultiTexCoordP4ui");
	if(!__gleMultiTexCoordP4ui) bIsLoaded = 0;
	__gleMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)gleIntGetProcAddress("glMultiTexCoordP4uiv");
	if(!__gleMultiTexCoordP4uiv) bIsLoaded = 0;
	__gleNormalP3ui = (PFNGLNORMALP3UIPROC)gleIntGetProcAddress("glNormalP3ui");
	if(!__gleNormalP3ui) bIsLoaded = 0;
	__gleNormalP3uiv = (PFNGLNORMALP3UIVPROC)gleIntGetProcAddress("glNormalP3uiv");
	if(!__gleNormalP3uiv) bIsLoaded = 0;
	__gleColorP3ui = (PFNGLCOLORP3UIPROC)gleIntGetProcAddress("glColorP3ui");
	if(!__gleColorP3ui) bIsLoaded = 0;
	__gleColorP3uiv = (PFNGLCOLORP3UIVPROC)gleIntGetProcAddress("glColorP3uiv");
	if(!__gleColorP3uiv) bIsLoaded = 0;
	__gleColorP4ui = (PFNGLCOLORP4UIPROC)gleIntGetProcAddress("glColorP4ui");
	if(!__gleColorP4ui) bIsLoaded = 0;
	__gleColorP4uiv = (PFNGLCOLORP4UIVPROC)gleIntGetProcAddress("glColorP4uiv");
	if(!__gleColorP4uiv) bIsLoaded = 0;
	__gleSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)gleIntGetProcAddress("glSecondaryColorP3ui");
	if(!__gleSecondaryColorP3ui) bIsLoaded = 0;
	__gleSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)gleIntGetProcAddress("glSecondaryColorP3uiv");
	if(!__gleSecondaryColorP3uiv) bIsLoaded = 0;
	__gleVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)gleIntGetProcAddress("glVertexAttribP1ui");
	if(!__gleVertexAttribP1ui) bIsLoaded = 0;
	__gleVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)gleIntGetProcAddress("glVertexAttribP1uiv");
	if(!__gleVertexAttribP1uiv) bIsLoaded = 0;
	__gleVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)gleIntGetProcAddress("glVertexAttribP2ui");
	if(!__gleVertexAttribP2ui) bIsLoaded = 0;
	__gleVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)gleIntGetProcAddress("glVertexAttribP2uiv");
	if(!__gleVertexAttribP2uiv) bIsLoaded = 0;
	__gleVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)gleIntGetProcAddress("glVertexAttribP3ui");
	if(!__gleVertexAttribP3ui) bIsLoaded = 0;
	__gleVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)gleIntGetProcAddress("glVertexAttribP3uiv");
	if(!__gleVertexAttribP3uiv) bIsLoaded = 0;
	__gleVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)gleIntGetProcAddress("glVertexAttribP4ui");
	if(!__gleVertexAttribP4ui) bIsLoaded = 0;
	__gleVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)gleIntGetProcAddress("glVertexAttribP4uiv");
	if(!__gleVertexAttribP4uiv) bIsLoaded = 0;
#endif /*GL_ARB_vertex_type_2_10_10_10_rev*/
	return bIsLoaded;
}
#ifndef GL_ARB_viewport_array
typedef void (GLE_FUNCPTR * PFNGLVIEWPORTARRAYVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVIEWPORTINDEXEDFPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVIEWPORTINDEXEDFVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSCISSORARRAYVPROC)(GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLSCISSORINDEXEDPROC)(GLuint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLSCISSORINDEXEDVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEARRAYVPROC)(GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEINDEXEDPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLGETFLOATI_VPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETDOUBLEI_VPROC)(GLenum , GLuint , GLdouble *);

PFNGLVIEWPORTARRAYVPROC __gleViewportArrayv;
PFNGLVIEWPORTINDEXEDFPROC __gleViewportIndexedf;
PFNGLVIEWPORTINDEXEDFVPROC __gleViewportIndexedfv;
PFNGLSCISSORARRAYVPROC __gleScissorArrayv;
PFNGLSCISSORINDEXEDPROC __gleScissorIndexed;
PFNGLSCISSORINDEXEDVPROC __gleScissorIndexedv;
PFNGLDEPTHRANGEARRAYVPROC __gleDepthRangeArrayv;
PFNGLDEPTHRANGEINDEXEDPROC __gleDepthRangeIndexed;
PFNGLGETFLOATI_VPROC __gleGetFloati_v;
PFNGLGETDOUBLEI_VPROC __gleGetDoublei_v;
#endif /*GL_ARB_viewport_array*/

static int gleIntLoad_ARB_viewport_array()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_viewport_array
	__gleViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)gleIntGetProcAddress("glViewportArrayv");
	if(!__gleViewportArrayv) bIsLoaded = 0;
	__gleViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)gleIntGetProcAddress("glViewportIndexedf");
	if(!__gleViewportIndexedf) bIsLoaded = 0;
	__gleViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)gleIntGetProcAddress("glViewportIndexedfv");
	if(!__gleViewportIndexedfv) bIsLoaded = 0;
	__gleScissorArrayv = (PFNGLSCISSORARRAYVPROC)gleIntGetProcAddress("glScissorArrayv");
	if(!__gleScissorArrayv) bIsLoaded = 0;
	__gleScissorIndexed = (PFNGLSCISSORINDEXEDPROC)gleIntGetProcAddress("glScissorIndexed");
	if(!__gleScissorIndexed) bIsLoaded = 0;
	__gleScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)gleIntGetProcAddress("glScissorIndexedv");
	if(!__gleScissorIndexedv) bIsLoaded = 0;
	__gleDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)gleIntGetProcAddress("glDepthRangeArrayv");
	if(!__gleDepthRangeArrayv) bIsLoaded = 0;
	__gleDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)gleIntGetProcAddress("glDepthRangeIndexed");
	if(!__gleDepthRangeIndexed) bIsLoaded = 0;
	__gleGetFloati_v = (PFNGLGETFLOATI_VPROC)gleIntGetProcAddress("glGetFloati_v");
	if(!__gleGetFloati_v) bIsLoaded = 0;
	__gleGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)gleIntGetProcAddress("glGetDoublei_v");
	if(!__gleGetDoublei_v) bIsLoaded = 0;
#endif /*GL_ARB_viewport_array*/
	return bIsLoaded;
}
#ifndef GL_ARB_window_pos
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DARBPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DVARBPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FARBPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FVARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IARBPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IVARBPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SARBPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SVARBPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DARBPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DVARBPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FARBPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FVARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IARBPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IVARBPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SARBPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SVARBPROC)(const GLshort *);

PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB;
PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB;
PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB;
PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB;
PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB;
PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB;
PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB;
PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB;
PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB;
PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB;
PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB;
PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB;
PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB;
PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB;
PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB;
PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB;
#endif /*GL_ARB_window_pos*/

static int gleIntLoad_ARB_window_pos()
{
	int bIsLoaded = 1;
#ifndef GL_ARB_window_pos
	glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)gleIntGetProcAddress("glWindowPos2dARB");
	if(!glWindowPos2dARB) bIsLoaded = 0;
	glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)gleIntGetProcAddress("glWindowPos2dvARB");
	if(!glWindowPos2dvARB) bIsLoaded = 0;
	glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)gleIntGetProcAddress("glWindowPos2fARB");
	if(!glWindowPos2fARB) bIsLoaded = 0;
	glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)gleIntGetProcAddress("glWindowPos2fvARB");
	if(!glWindowPos2fvARB) bIsLoaded = 0;
	glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)gleIntGetProcAddress("glWindowPos2iARB");
	if(!glWindowPos2iARB) bIsLoaded = 0;
	glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)gleIntGetProcAddress("glWindowPos2ivARB");
	if(!glWindowPos2ivARB) bIsLoaded = 0;
	glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)gleIntGetProcAddress("glWindowPos2sARB");
	if(!glWindowPos2sARB) bIsLoaded = 0;
	glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)gleIntGetProcAddress("glWindowPos2svARB");
	if(!glWindowPos2svARB) bIsLoaded = 0;
	glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)gleIntGetProcAddress("glWindowPos3dARB");
	if(!glWindowPos3dARB) bIsLoaded = 0;
	glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)gleIntGetProcAddress("glWindowPos3dvARB");
	if(!glWindowPos3dvARB) bIsLoaded = 0;
	glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)gleIntGetProcAddress("glWindowPos3fARB");
	if(!glWindowPos3fARB) bIsLoaded = 0;
	glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)gleIntGetProcAddress("glWindowPos3fvARB");
	if(!glWindowPos3fvARB) bIsLoaded = 0;
	glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)gleIntGetProcAddress("glWindowPos3iARB");
	if(!glWindowPos3iARB) bIsLoaded = 0;
	glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)gleIntGetProcAddress("glWindowPos3ivARB");
	if(!glWindowPos3ivARB) bIsLoaded = 0;
	glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)gleIntGetProcAddress("glWindowPos3sARB");
	if(!glWindowPos3sARB) bIsLoaded = 0;
	glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)gleIntGetProcAddress("glWindowPos3svARB");
	if(!glWindowPos3svARB) bIsLoaded = 0;
#endif /*GL_ARB_window_pos*/
	return bIsLoaded;
}
#ifndef GL_ATI_draw_buffers
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSATIPROC)(GLsizei , const GLenum *);

PFNGLDRAWBUFFERSATIPROC glDrawBuffersATI;
#endif /*GL_ATI_draw_buffers*/

static int gleIntLoad_ATI_draw_buffers()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_draw_buffers
	glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)gleIntGetProcAddress("glDrawBuffersATI");
	if(!glDrawBuffersATI) bIsLoaded = 0;
#endif /*GL_ATI_draw_buffers*/
	return bIsLoaded;
}
#ifndef GL_ATI_element_array
typedef void (GLE_FUNCPTR * PFNGLELEMENTPOINTERATIPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTARRAYATIPROC)(GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum , GLuint , GLuint , GLsizei );

PFNGLELEMENTPOINTERATIPROC glElementPointerATI;
PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATI;
PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATI;
#endif /*GL_ATI_element_array*/

static int gleIntLoad_ATI_element_array()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_element_array
	glElementPointerATI = (PFNGLELEMENTPOINTERATIPROC)gleIntGetProcAddress("glElementPointerATI");
	if(!glElementPointerATI) bIsLoaded = 0;
	glDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC)gleIntGetProcAddress("glDrawElementArrayATI");
	if(!glDrawElementArrayATI) bIsLoaded = 0;
	glDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)gleIntGetProcAddress("glDrawRangeElementArrayATI");
	if(!glDrawRangeElementArrayATI) bIsLoaded = 0;
#endif /*GL_ATI_element_array*/
	return bIsLoaded;
}
#ifndef GL_ATI_envmap_bumpmap
typedef void (GLE_FUNCPTR * PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum , GLfloat *);

PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATI;
PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATI;
PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATI;
PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATI;
#endif /*GL_ATI_envmap_bumpmap*/

static int gleIntLoad_ATI_envmap_bumpmap()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_envmap_bumpmap
	glTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC)gleIntGetProcAddress("glTexBumpParameterivATI");
	if(!glTexBumpParameterivATI) bIsLoaded = 0;
	glTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC)gleIntGetProcAddress("glTexBumpParameterfvATI");
	if(!glTexBumpParameterfvATI) bIsLoaded = 0;
	glGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)gleIntGetProcAddress("glGetTexBumpParameterivATI");
	if(!glGetTexBumpParameterivATI) bIsLoaded = 0;
	glGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)gleIntGetProcAddress("glGetTexBumpParameterfvATI");
	if(!glGetTexBumpParameterfvATI) bIsLoaded = 0;
#endif /*GL_ATI_envmap_bumpmap*/
	return bIsLoaded;
}
#ifndef GL_ATI_fragment_shader
typedef GLuint (GLE_FUNCPTR * PFNGLGENFRAGMENTSHADERSATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDFRAGMENTSHADERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEFRAGMENTSHADERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINFRAGMENTSHADERATIPROC)();
typedef void (GLE_FUNCPTR * PFNGLENDFRAGMENTSHADERATIPROC)();
typedef void (GLE_FUNCPTR * PFNGLPASSTEXCOORDATIPROC)(GLuint , GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMAPATIPROC)(GLuint , GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLCOLORFRAGMENTOP1ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLORFRAGMENTOP2ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLORFRAGMENTOP3ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLALPHAFRAGMENTOP1ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLALPHAFRAGMENTOP2ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLALPHAFRAGMENTOP3ATIPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)(GLuint , const GLfloat *);

PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI;
PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI;
PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI;
PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI;
PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI;
PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI;
PFNGLSAMPLEMAPATIPROC glSampleMapATI;
PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI;
PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI;
PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI;
PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI;
PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI;
PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI;
PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI;
#endif /*GL_ATI_fragment_shader*/

static int gleIntLoad_ATI_fragment_shader()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_fragment_shader
	glGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC)gleIntGetProcAddress("glGenFragmentShadersATI");
	if(!glGenFragmentShadersATI) bIsLoaded = 0;
	glBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC)gleIntGetProcAddress("glBindFragmentShaderATI");
	if(!glBindFragmentShaderATI) bIsLoaded = 0;
	glDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC)gleIntGetProcAddress("glDeleteFragmentShaderATI");
	if(!glDeleteFragmentShaderATI) bIsLoaded = 0;
	glBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC)gleIntGetProcAddress("glBeginFragmentShaderATI");
	if(!glBeginFragmentShaderATI) bIsLoaded = 0;
	glEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC)gleIntGetProcAddress("glEndFragmentShaderATI");
	if(!glEndFragmentShaderATI) bIsLoaded = 0;
	glPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC)gleIntGetProcAddress("glPassTexCoordATI");
	if(!glPassTexCoordATI) bIsLoaded = 0;
	glSampleMapATI = (PFNGLSAMPLEMAPATIPROC)gleIntGetProcAddress("glSampleMapATI");
	if(!glSampleMapATI) bIsLoaded = 0;
	glColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC)gleIntGetProcAddress("glColorFragmentOp1ATI");
	if(!glColorFragmentOp1ATI) bIsLoaded = 0;
	glColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC)gleIntGetProcAddress("glColorFragmentOp2ATI");
	if(!glColorFragmentOp2ATI) bIsLoaded = 0;
	glColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC)gleIntGetProcAddress("glColorFragmentOp3ATI");
	if(!glColorFragmentOp3ATI) bIsLoaded = 0;
	glAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC)gleIntGetProcAddress("glAlphaFragmentOp1ATI");
	if(!glAlphaFragmentOp1ATI) bIsLoaded = 0;
	glAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC)gleIntGetProcAddress("glAlphaFragmentOp2ATI");
	if(!glAlphaFragmentOp2ATI) bIsLoaded = 0;
	glAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC)gleIntGetProcAddress("glAlphaFragmentOp3ATI");
	if(!glAlphaFragmentOp3ATI) bIsLoaded = 0;
	glSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)gleIntGetProcAddress("glSetFragmentShaderConstantATI");
	if(!glSetFragmentShaderConstantATI) bIsLoaded = 0;
#endif /*GL_ATI_fragment_shader*/
	return bIsLoaded;
}
#ifndef GL_ATI_map_object_buffer
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPOBJECTBUFFERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint );

PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI;
PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI;
#endif /*GL_ATI_map_object_buffer*/

static int gleIntLoad_ATI_map_object_buffer()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_map_object_buffer
	glMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC)gleIntGetProcAddress("glMapObjectBufferATI");
	if(!glMapObjectBufferATI) bIsLoaded = 0;
	glUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC)gleIntGetProcAddress("glUnmapObjectBufferATI");
	if(!glUnmapObjectBufferATI) bIsLoaded = 0;
#endif /*GL_ATI_map_object_buffer*/
	return bIsLoaded;
}


#ifndef GL_ATI_pn_triangles
typedef void (GLE_FUNCPTR * PFNGLPNTRIANGLESIATIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPNTRIANGLESFATIPROC)(GLenum , GLfloat );

PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI;
PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI;
#endif /*GL_ATI_pn_triangles*/

static int gleIntLoad_ATI_pn_triangles()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_pn_triangles
	glPNTrianglesiATI = (PFNGLPNTRIANGLESIATIPROC)gleIntGetProcAddress("glPNTrianglesiATI");
	if(!glPNTrianglesiATI) bIsLoaded = 0;
	glPNTrianglesfATI = (PFNGLPNTRIANGLESFATIPROC)gleIntGetProcAddress("glPNTrianglesfATI");
	if(!glPNTrianglesfATI) bIsLoaded = 0;
#endif /*GL_ATI_pn_triangles*/
	return bIsLoaded;
}
#ifndef GL_ATI_separate_stencil
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPSEPARATEATIPROC)(GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum , GLenum , GLint , GLuint );

PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATI;
PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATI;
#endif /*GL_ATI_separate_stencil*/

static int gleIntLoad_ATI_separate_stencil()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_separate_stencil
	glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)gleIntGetProcAddress("glStencilOpSeparateATI");
	if(!glStencilOpSeparateATI) bIsLoaded = 0;
	glStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC)gleIntGetProcAddress("glStencilFuncSeparateATI");
	if(!glStencilFuncSeparateATI) bIsLoaded = 0;
#endif /*GL_ATI_separate_stencil*/
	return bIsLoaded;
}




#ifndef GL_ATI_vertex_array_object
typedef GLuint (GLE_FUNCPTR * PFNGLNEWOBJECTBUFFERATIPROC)(GLsizei , const GLvoid *, GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLISOBJECTBUFFERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLUPDATEOBJECTBUFFERATIPROC)(GLuint , GLuint , GLsizei , const GLvoid *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTBUFFERFVATIPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTBUFFERIVATIPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLFREEOBJECTBUFFERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLARRAYOBJECTATIPROC)(GLenum , GLint , GLenum , GLsizei , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETARRAYOBJECTFVATIPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETARRAYOBJECTIVATIPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTARRAYOBJECTATIPROC)(GLuint , GLenum , GLsizei , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTARRAYOBJECTFVATIPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTARRAYOBJECTIVATIPROC)(GLuint , GLenum , GLint *);

PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATI;
PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATI;
PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATI;
PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATI;
PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATI;
PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATI;
PFNGLARRAYOBJECTATIPROC glArrayObjectATI;
PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATI;
PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATI;
PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATI;
PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATI;
PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATI;
#endif /*GL_ATI_vertex_array_object*/

static int gleIntLoad_ATI_vertex_array_object()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_vertex_array_object
	glNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC)gleIntGetProcAddress("glNewObjectBufferATI");
	if(!glNewObjectBufferATI) bIsLoaded = 0;
	glIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC)gleIntGetProcAddress("glIsObjectBufferATI");
	if(!glIsObjectBufferATI) bIsLoaded = 0;
	glUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC)gleIntGetProcAddress("glUpdateObjectBufferATI");
	if(!glUpdateObjectBufferATI) bIsLoaded = 0;
	glGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC)gleIntGetProcAddress("glGetObjectBufferfvATI");
	if(!glGetObjectBufferfvATI) bIsLoaded = 0;
	glGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC)gleIntGetProcAddress("glGetObjectBufferivATI");
	if(!glGetObjectBufferivATI) bIsLoaded = 0;
	glFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC)gleIntGetProcAddress("glFreeObjectBufferATI");
	if(!glFreeObjectBufferATI) bIsLoaded = 0;
	glArrayObjectATI = (PFNGLARRAYOBJECTATIPROC)gleIntGetProcAddress("glArrayObjectATI");
	if(!glArrayObjectATI) bIsLoaded = 0;
	glGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC)gleIntGetProcAddress("glGetArrayObjectfvATI");
	if(!glGetArrayObjectfvATI) bIsLoaded = 0;
	glGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC)gleIntGetProcAddress("glGetArrayObjectivATI");
	if(!glGetArrayObjectivATI) bIsLoaded = 0;
	glVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC)gleIntGetProcAddress("glVariantArrayObjectATI");
	if(!glVariantArrayObjectATI) bIsLoaded = 0;
	glGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)gleIntGetProcAddress("glGetVariantArrayObjectfvATI");
	if(!glGetVariantArrayObjectfvATI) bIsLoaded = 0;
	glGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)gleIntGetProcAddress("glGetVariantArrayObjectivATI");
	if(!glGetVariantArrayObjectivATI) bIsLoaded = 0;
#endif /*GL_ATI_vertex_array_object*/
	return bIsLoaded;
}
#ifndef GL_ATI_vertex_attrib_array_object
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint , GLenum , GLint *);

PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI;
PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI;
#endif /*GL_ATI_vertex_attrib_array_object*/

static int gleIntLoad_ATI_vertex_attrib_array_object()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_vertex_attrib_array_object
	glVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)gleIntGetProcAddress("glVertexAttribArrayObjectATI");
	if(!glVertexAttribArrayObjectATI) bIsLoaded = 0;
	glGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)gleIntGetProcAddress("glGetVertexAttribArrayObjectfvATI");
	if(!glGetVertexAttribArrayObjectfvATI) bIsLoaded = 0;
	glGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)gleIntGetProcAddress("glGetVertexAttribArrayObjectivATI");
	if(!glGetVertexAttribArrayObjectivATI) bIsLoaded = 0;
#endif /*GL_ATI_vertex_attrib_array_object*/
	return bIsLoaded;
}
#ifndef GL_ATI_vertex_streams
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1SATIPROC)(GLenum , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1SVATIPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1IATIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1IVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1FATIPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1FVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1DATIPROC)(GLenum , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM1DVATIPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2SATIPROC)(GLenum , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2SVATIPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2IATIPROC)(GLenum , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2IVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2FATIPROC)(GLenum , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2FVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2DATIPROC)(GLenum , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM2DVATIPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3SATIPROC)(GLenum , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3SVATIPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3IATIPROC)(GLenum , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3IVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3FATIPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3FVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3DATIPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM3DVATIPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4SATIPROC)(GLenum , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4SVATIPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4IATIPROC)(GLenum , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4IVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4FATIPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4FVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4DATIPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXSTREAM4DVATIPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3BATIPROC)(GLenum , GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3BVATIPROC)(GLenum , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3SATIPROC)(GLenum , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3SVATIPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3IATIPROC)(GLenum , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3IVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3FATIPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3FVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3DATIPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLNORMALSTREAM3DVATIPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLVERTEXBLENDENVIATIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXBLENDENVFATIPROC)(GLenum , GLfloat );

PFNGLVERTEXSTREAM1SATIPROC glVertexStream1sATI;
PFNGLVERTEXSTREAM1SVATIPROC glVertexStream1svATI;
PFNGLVERTEXSTREAM1IATIPROC glVertexStream1iATI;
PFNGLVERTEXSTREAM1IVATIPROC glVertexStream1ivATI;
PFNGLVERTEXSTREAM1FATIPROC glVertexStream1fATI;
PFNGLVERTEXSTREAM1FVATIPROC glVertexStream1fvATI;
PFNGLVERTEXSTREAM1DATIPROC glVertexStream1dATI;
PFNGLVERTEXSTREAM1DVATIPROC glVertexStream1dvATI;
PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATI;
PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATI;
PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATI;
PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATI;
PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATI;
PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATI;
PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATI;
PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATI;
PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATI;
PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATI;
PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATI;
PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATI;
PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATI;
PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATI;
PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATI;
PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATI;
PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATI;
PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATI;
PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATI;
PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATI;
PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATI;
PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATI;
PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATI;
PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATI;
PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATI;
PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATI;
PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATI;
PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATI;
PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATI;
PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATI;
PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATI;
PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATI;
PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATI;
PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATI;
PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATI;
PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATI;
PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATI;
#endif /*GL_ATI_vertex_streams*/

static int gleIntLoad_ATI_vertex_streams()
{
	int bIsLoaded = 1;
#ifndef GL_ATI_vertex_streams
	glVertexStream1sATI = (PFNGLVERTEXSTREAM1SATIPROC)gleIntGetProcAddress("glVertexStream1sATI");
	if(!glVertexStream1sATI) bIsLoaded = 0;
	glVertexStream1svATI = (PFNGLVERTEXSTREAM1SVATIPROC)gleIntGetProcAddress("glVertexStream1svATI");
	if(!glVertexStream1svATI) bIsLoaded = 0;
	glVertexStream1iATI = (PFNGLVERTEXSTREAM1IATIPROC)gleIntGetProcAddress("glVertexStream1iATI");
	if(!glVertexStream1iATI) bIsLoaded = 0;
	glVertexStream1ivATI = (PFNGLVERTEXSTREAM1IVATIPROC)gleIntGetProcAddress("glVertexStream1ivATI");
	if(!glVertexStream1ivATI) bIsLoaded = 0;
	glVertexStream1fATI = (PFNGLVERTEXSTREAM1FATIPROC)gleIntGetProcAddress("glVertexStream1fATI");
	if(!glVertexStream1fATI) bIsLoaded = 0;
	glVertexStream1fvATI = (PFNGLVERTEXSTREAM1FVATIPROC)gleIntGetProcAddress("glVertexStream1fvATI");
	if(!glVertexStream1fvATI) bIsLoaded = 0;
	glVertexStream1dATI = (PFNGLVERTEXSTREAM1DATIPROC)gleIntGetProcAddress("glVertexStream1dATI");
	if(!glVertexStream1dATI) bIsLoaded = 0;
	glVertexStream1dvATI = (PFNGLVERTEXSTREAM1DVATIPROC)gleIntGetProcAddress("glVertexStream1dvATI");
	if(!glVertexStream1dvATI) bIsLoaded = 0;
	glVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC)gleIntGetProcAddress("glVertexStream2sATI");
	if(!glVertexStream2sATI) bIsLoaded = 0;
	glVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC)gleIntGetProcAddress("glVertexStream2svATI");
	if(!glVertexStream2svATI) bIsLoaded = 0;
	glVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC)gleIntGetProcAddress("glVertexStream2iATI");
	if(!glVertexStream2iATI) bIsLoaded = 0;
	glVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC)gleIntGetProcAddress("glVertexStream2ivATI");
	if(!glVertexStream2ivATI) bIsLoaded = 0;
	glVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC)gleIntGetProcAddress("glVertexStream2fATI");
	if(!glVertexStream2fATI) bIsLoaded = 0;
	glVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC)gleIntGetProcAddress("glVertexStream2fvATI");
	if(!glVertexStream2fvATI) bIsLoaded = 0;
	glVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC)gleIntGetProcAddress("glVertexStream2dATI");
	if(!glVertexStream2dATI) bIsLoaded = 0;
	glVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC)gleIntGetProcAddress("glVertexStream2dvATI");
	if(!glVertexStream2dvATI) bIsLoaded = 0;
	glVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC)gleIntGetProcAddress("glVertexStream3sATI");
	if(!glVertexStream3sATI) bIsLoaded = 0;
	glVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC)gleIntGetProcAddress("glVertexStream3svATI");
	if(!glVertexStream3svATI) bIsLoaded = 0;
	glVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC)gleIntGetProcAddress("glVertexStream3iATI");
	if(!glVertexStream3iATI) bIsLoaded = 0;
	glVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC)gleIntGetProcAddress("glVertexStream3ivATI");
	if(!glVertexStream3ivATI) bIsLoaded = 0;
	glVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC)gleIntGetProcAddress("glVertexStream3fATI");
	if(!glVertexStream3fATI) bIsLoaded = 0;
	glVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC)gleIntGetProcAddress("glVertexStream3fvATI");
	if(!glVertexStream3fvATI) bIsLoaded = 0;
	glVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC)gleIntGetProcAddress("glVertexStream3dATI");
	if(!glVertexStream3dATI) bIsLoaded = 0;
	glVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC)gleIntGetProcAddress("glVertexStream3dvATI");
	if(!glVertexStream3dvATI) bIsLoaded = 0;
	glVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC)gleIntGetProcAddress("glVertexStream4sATI");
	if(!glVertexStream4sATI) bIsLoaded = 0;
	glVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC)gleIntGetProcAddress("glVertexStream4svATI");
	if(!glVertexStream4svATI) bIsLoaded = 0;
	glVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC)gleIntGetProcAddress("glVertexStream4iATI");
	if(!glVertexStream4iATI) bIsLoaded = 0;
	glVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC)gleIntGetProcAddress("glVertexStream4ivATI");
	if(!glVertexStream4ivATI) bIsLoaded = 0;
	glVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC)gleIntGetProcAddress("glVertexStream4fATI");
	if(!glVertexStream4fATI) bIsLoaded = 0;
	glVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC)gleIntGetProcAddress("glVertexStream4fvATI");
	if(!glVertexStream4fvATI) bIsLoaded = 0;
	glVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC)gleIntGetProcAddress("glVertexStream4dATI");
	if(!glVertexStream4dATI) bIsLoaded = 0;
	glVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC)gleIntGetProcAddress("glVertexStream4dvATI");
	if(!glVertexStream4dvATI) bIsLoaded = 0;
	glNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC)gleIntGetProcAddress("glNormalStream3bATI");
	if(!glNormalStream3bATI) bIsLoaded = 0;
	glNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC)gleIntGetProcAddress("glNormalStream3bvATI");
	if(!glNormalStream3bvATI) bIsLoaded = 0;
	glNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC)gleIntGetProcAddress("glNormalStream3sATI");
	if(!glNormalStream3sATI) bIsLoaded = 0;
	glNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC)gleIntGetProcAddress("glNormalStream3svATI");
	if(!glNormalStream3svATI) bIsLoaded = 0;
	glNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC)gleIntGetProcAddress("glNormalStream3iATI");
	if(!glNormalStream3iATI) bIsLoaded = 0;
	glNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC)gleIntGetProcAddress("glNormalStream3ivATI");
	if(!glNormalStream3ivATI) bIsLoaded = 0;
	glNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC)gleIntGetProcAddress("glNormalStream3fATI");
	if(!glNormalStream3fATI) bIsLoaded = 0;
	glNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC)gleIntGetProcAddress("glNormalStream3fvATI");
	if(!glNormalStream3fvATI) bIsLoaded = 0;
	glNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC)gleIntGetProcAddress("glNormalStream3dATI");
	if(!glNormalStream3dATI) bIsLoaded = 0;
	glNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC)gleIntGetProcAddress("glNormalStream3dvATI");
	if(!glNormalStream3dvATI) bIsLoaded = 0;
	glClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)gleIntGetProcAddress("glClientActiveVertexStreamATI");
	if(!glClientActiveVertexStreamATI) bIsLoaded = 0;
	glVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC)gleIntGetProcAddress("glVertexBlendEnviATI");
	if(!glVertexBlendEnviATI) bIsLoaded = 0;
	glVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC)gleIntGetProcAddress("glVertexBlendEnvfATI");
	if(!glVertexBlendEnvfATI) bIsLoaded = 0;
#endif /*GL_ATI_vertex_streams*/
	return bIsLoaded;
}



#ifndef GL_EXT_bindable_uniform
typedef void (GLE_FUNCPTR * PFNGLUNIFORMBUFFEREXTPROC)(GLuint , GLint , GLuint );
typedef GLint (GLE_FUNCPTR * PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint , GLint );
typedef GLintptr (GLE_FUNCPTR * PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint , GLint );

PFNGLUNIFORMBUFFEREXTPROC glUniformBufferEXT;
PFNGLGETUNIFORMBUFFERSIZEEXTPROC glGetUniformBufferSizeEXT;
PFNGLGETUNIFORMOFFSETEXTPROC glGetUniformOffsetEXT;
#endif /*GL_EXT_bindable_uniform*/

static int gleIntLoad_EXT_bindable_uniform()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_bindable_uniform
	glUniformBufferEXT = (PFNGLUNIFORMBUFFEREXTPROC)gleIntGetProcAddress("glUniformBufferEXT");
	if(!glUniformBufferEXT) bIsLoaded = 0;
	glGetUniformBufferSizeEXT = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC)gleIntGetProcAddress("glGetUniformBufferSizeEXT");
	if(!glGetUniformBufferSizeEXT) bIsLoaded = 0;
	glGetUniformOffsetEXT = (PFNGLGETUNIFORMOFFSETEXTPROC)gleIntGetProcAddress("glGetUniformOffsetEXT");
	if(!glGetUniformOffsetEXT) bIsLoaded = 0;
#endif /*GL_EXT_bindable_uniform*/
	return bIsLoaded;
}
#ifndef GL_EXT_blend_color
typedef void (GLE_FUNCPTR * PFNGLBLENDCOLOREXTPROC)(GLfloat , GLfloat , GLfloat , GLfloat );

PFNGLBLENDCOLOREXTPROC glBlendColorEXT;
#endif /*GL_EXT_blend_color*/

static int gleIntLoad_EXT_blend_color()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_blend_color
	glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)gleIntGetProcAddress("glBlendColorEXT");
	if(!glBlendColorEXT) bIsLoaded = 0;
#endif /*GL_EXT_blend_color*/
	return bIsLoaded;
}
#ifndef GL_EXT_blend_equation_separate
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum , GLenum );

PFNGLBLENDEQUATIONSEPARATEEXTPROC glBlendEquationSeparateEXT;
#endif /*GL_EXT_blend_equation_separate*/

static int gleIntLoad_EXT_blend_equation_separate()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_blend_equation_separate
	glBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)gleIntGetProcAddress("glBlendEquationSeparateEXT");
	if(!glBlendEquationSeparateEXT) bIsLoaded = 0;
#endif /*GL_EXT_blend_equation_separate*/
	return bIsLoaded;
}
#ifndef GL_EXT_blend_func_separate
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum , GLenum , GLenum , GLenum );

PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT;
#endif /*GL_EXT_blend_func_separate*/

static int gleIntLoad_EXT_blend_func_separate()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_blend_func_separate
	glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)gleIntGetProcAddress("glBlendFuncSeparateEXT");
	if(!glBlendFuncSeparateEXT) bIsLoaded = 0;
#endif /*GL_EXT_blend_func_separate*/
	return bIsLoaded;
}

#ifndef GL_EXT_blend_minmax
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONEXTPROC)(GLenum );

PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT;
#endif /*GL_EXT_blend_minmax*/

static int gleIntLoad_EXT_blend_minmax()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_blend_minmax
	glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)gleIntGetProcAddress("glBlendEquationEXT");
	if(!glBlendEquationEXT) bIsLoaded = 0;
#endif /*GL_EXT_blend_minmax*/
	return bIsLoaded;
}



#ifndef GL_EXT_color_subtable
typedef void (GLE_FUNCPTR * PFNGLCOLORSUBTABLEEXTPROC)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum , GLsizei , GLint , GLint , GLsizei );

PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT;
PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXT;
#endif /*GL_EXT_color_subtable*/

static int gleIntLoad_EXT_color_subtable()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_color_subtable
	glColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC)gleIntGetProcAddress("glColorSubTableEXT");
	if(!glColorSubTableEXT) bIsLoaded = 0;
	glCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC)gleIntGetProcAddress("glCopyColorSubTableEXT");
	if(!glCopyColorSubTableEXT) bIsLoaded = 0;
#endif /*GL_EXT_color_subtable*/
	return bIsLoaded;
}
#ifndef GL_EXT_compiled_vertex_array
typedef void (GLE_FUNCPTR * PFNGLLOCKARRAYSEXTPROC)(GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLUNLOCKARRAYSEXTPROC)();

PFNGLLOCKARRAYSEXTPROC glLockArraysEXT;
PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT;
#endif /*GL_EXT_compiled_vertex_array*/

static int gleIntLoad_EXT_compiled_vertex_array()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_compiled_vertex_array
	glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)gleIntGetProcAddress("glLockArraysEXT");
	if(!glLockArraysEXT) bIsLoaded = 0;
	glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)gleIntGetProcAddress("glUnlockArraysEXT");
	if(!glUnlockArraysEXT) bIsLoaded = 0;
#endif /*GL_EXT_compiled_vertex_array*/
	return bIsLoaded;
}
#ifndef GL_EXT_convolution
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER1DEXTPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER2DEXTPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFEXTPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFVEXTPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIEXTPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIVEXTPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONFILTEREXTPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSEPARABLEFILTEREXTPROC)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLSEPARABLEFILTER2DEXTPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);

PFNGLCONVOLUTIONFILTER1DEXTPROC glConvolutionFilter1DEXT;
PFNGLCONVOLUTIONFILTER2DEXTPROC glConvolutionFilter2DEXT;
PFNGLCONVOLUTIONPARAMETERFEXTPROC glConvolutionParameterfEXT;
PFNGLCONVOLUTIONPARAMETERFVEXTPROC glConvolutionParameterfvEXT;
PFNGLCONVOLUTIONPARAMETERIEXTPROC glConvolutionParameteriEXT;
PFNGLCONVOLUTIONPARAMETERIVEXTPROC glConvolutionParameterivEXT;
PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glCopyConvolutionFilter1DEXT;
PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glCopyConvolutionFilter2DEXT;
PFNGLGETCONVOLUTIONFILTEREXTPROC glGetConvolutionFilterEXT;
PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glGetConvolutionParameterfvEXT;
PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glGetConvolutionParameterivEXT;
PFNGLGETSEPARABLEFILTEREXTPROC glGetSeparableFilterEXT;
PFNGLSEPARABLEFILTER2DEXTPROC glSeparableFilter2DEXT;
#endif /*GL_EXT_convolution*/

static int gleIntLoad_EXT_convolution()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_convolution
	glConvolutionFilter1DEXT = (PFNGLCONVOLUTIONFILTER1DEXTPROC)gleIntGetProcAddress("glConvolutionFilter1DEXT");
	if(!glConvolutionFilter1DEXT) bIsLoaded = 0;
	glConvolutionFilter2DEXT = (PFNGLCONVOLUTIONFILTER2DEXTPROC)gleIntGetProcAddress("glConvolutionFilter2DEXT");
	if(!glConvolutionFilter2DEXT) bIsLoaded = 0;
	glConvolutionParameterfEXT = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)gleIntGetProcAddress("glConvolutionParameterfEXT");
	if(!glConvolutionParameterfEXT) bIsLoaded = 0;
	glConvolutionParameterfvEXT = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)gleIntGetProcAddress("glConvolutionParameterfvEXT");
	if(!glConvolutionParameterfvEXT) bIsLoaded = 0;
	glConvolutionParameteriEXT = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)gleIntGetProcAddress("glConvolutionParameteriEXT");
	if(!glConvolutionParameteriEXT) bIsLoaded = 0;
	glConvolutionParameterivEXT = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)gleIntGetProcAddress("glConvolutionParameterivEXT");
	if(!glConvolutionParameterivEXT) bIsLoaded = 0;
	glCopyConvolutionFilter1DEXT = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)gleIntGetProcAddress("glCopyConvolutionFilter1DEXT");
	if(!glCopyConvolutionFilter1DEXT) bIsLoaded = 0;
	glCopyConvolutionFilter2DEXT = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)gleIntGetProcAddress("glCopyConvolutionFilter2DEXT");
	if(!glCopyConvolutionFilter2DEXT) bIsLoaded = 0;
	glGetConvolutionFilterEXT = (PFNGLGETCONVOLUTIONFILTEREXTPROC)gleIntGetProcAddress("glGetConvolutionFilterEXT");
	if(!glGetConvolutionFilterEXT) bIsLoaded = 0;
	glGetConvolutionParameterfvEXT = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetConvolutionParameterfvEXT");
	if(!glGetConvolutionParameterfvEXT) bIsLoaded = 0;
	glGetConvolutionParameterivEXT = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetConvolutionParameterivEXT");
	if(!glGetConvolutionParameterivEXT) bIsLoaded = 0;
	glGetSeparableFilterEXT = (PFNGLGETSEPARABLEFILTEREXTPROC)gleIntGetProcAddress("glGetSeparableFilterEXT");
	if(!glGetSeparableFilterEXT) bIsLoaded = 0;
	glSeparableFilter2DEXT = (PFNGLSEPARABLEFILTER2DEXTPROC)gleIntGetProcAddress("glSeparableFilter2DEXT");
	if(!glSeparableFilter2DEXT) bIsLoaded = 0;
#endif /*GL_EXT_convolution*/
	return bIsLoaded;
}
#ifndef GL_EXT_coordinate_frame
typedef void (GLE_FUNCPTR * PFNGLTANGENT3BEXTPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLTANGENT3BVEXTPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLTANGENT3DEXTPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTANGENT3DVEXTPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTANGENT3FEXTPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTANGENT3FVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTANGENT3IEXTPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLTANGENT3IVEXTPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTANGENT3SEXTPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLTANGENT3SVEXTPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3BEXTPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3BVEXTPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3DEXTPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3DVEXTPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3FEXTPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3FVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3IEXTPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3IVEXTPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3SEXTPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLBINORMAL3SVEXTPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLTANGENTPOINTEREXTPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLBINORMALPOINTEREXTPROC)(GLenum , GLsizei , const GLvoid *);

PFNGLTANGENT3BEXTPROC glTangent3bEXT;
PFNGLTANGENT3BVEXTPROC glTangent3bvEXT;
PFNGLTANGENT3DEXTPROC glTangent3dEXT;
PFNGLTANGENT3DVEXTPROC glTangent3dvEXT;
PFNGLTANGENT3FEXTPROC glTangent3fEXT;
PFNGLTANGENT3FVEXTPROC glTangent3fvEXT;
PFNGLTANGENT3IEXTPROC glTangent3iEXT;
PFNGLTANGENT3IVEXTPROC glTangent3ivEXT;
PFNGLTANGENT3SEXTPROC glTangent3sEXT;
PFNGLTANGENT3SVEXTPROC glTangent3svEXT;
PFNGLBINORMAL3BEXTPROC glBinormal3bEXT;
PFNGLBINORMAL3BVEXTPROC glBinormal3bvEXT;
PFNGLBINORMAL3DEXTPROC glBinormal3dEXT;
PFNGLBINORMAL3DVEXTPROC glBinormal3dvEXT;
PFNGLBINORMAL3FEXTPROC glBinormal3fEXT;
PFNGLBINORMAL3FVEXTPROC glBinormal3fvEXT;
PFNGLBINORMAL3IEXTPROC glBinormal3iEXT;
PFNGLBINORMAL3IVEXTPROC glBinormal3ivEXT;
PFNGLBINORMAL3SEXTPROC glBinormal3sEXT;
PFNGLBINORMAL3SVEXTPROC glBinormal3svEXT;
PFNGLTANGENTPOINTEREXTPROC glTangentPointerEXT;
PFNGLBINORMALPOINTEREXTPROC glBinormalPointerEXT;
#endif /*GL_EXT_coordinate_frame*/

static int gleIntLoad_EXT_coordinate_frame()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_coordinate_frame
	glTangent3bEXT = (PFNGLTANGENT3BEXTPROC)gleIntGetProcAddress("glTangent3bEXT");
	if(!glTangent3bEXT) bIsLoaded = 0;
	glTangent3bvEXT = (PFNGLTANGENT3BVEXTPROC)gleIntGetProcAddress("glTangent3bvEXT");
	if(!glTangent3bvEXT) bIsLoaded = 0;
	glTangent3dEXT = (PFNGLTANGENT3DEXTPROC)gleIntGetProcAddress("glTangent3dEXT");
	if(!glTangent3dEXT) bIsLoaded = 0;
	glTangent3dvEXT = (PFNGLTANGENT3DVEXTPROC)gleIntGetProcAddress("glTangent3dvEXT");
	if(!glTangent3dvEXT) bIsLoaded = 0;
	glTangent3fEXT = (PFNGLTANGENT3FEXTPROC)gleIntGetProcAddress("glTangent3fEXT");
	if(!glTangent3fEXT) bIsLoaded = 0;
	glTangent3fvEXT = (PFNGLTANGENT3FVEXTPROC)gleIntGetProcAddress("glTangent3fvEXT");
	if(!glTangent3fvEXT) bIsLoaded = 0;
	glTangent3iEXT = (PFNGLTANGENT3IEXTPROC)gleIntGetProcAddress("glTangent3iEXT");
	if(!glTangent3iEXT) bIsLoaded = 0;
	glTangent3ivEXT = (PFNGLTANGENT3IVEXTPROC)gleIntGetProcAddress("glTangent3ivEXT");
	if(!glTangent3ivEXT) bIsLoaded = 0;
	glTangent3sEXT = (PFNGLTANGENT3SEXTPROC)gleIntGetProcAddress("glTangent3sEXT");
	if(!glTangent3sEXT) bIsLoaded = 0;
	glTangent3svEXT = (PFNGLTANGENT3SVEXTPROC)gleIntGetProcAddress("glTangent3svEXT");
	if(!glTangent3svEXT) bIsLoaded = 0;
	glBinormal3bEXT = (PFNGLBINORMAL3BEXTPROC)gleIntGetProcAddress("glBinormal3bEXT");
	if(!glBinormal3bEXT) bIsLoaded = 0;
	glBinormal3bvEXT = (PFNGLBINORMAL3BVEXTPROC)gleIntGetProcAddress("glBinormal3bvEXT");
	if(!glBinormal3bvEXT) bIsLoaded = 0;
	glBinormal3dEXT = (PFNGLBINORMAL3DEXTPROC)gleIntGetProcAddress("glBinormal3dEXT");
	if(!glBinormal3dEXT) bIsLoaded = 0;
	glBinormal3dvEXT = (PFNGLBINORMAL3DVEXTPROC)gleIntGetProcAddress("glBinormal3dvEXT");
	if(!glBinormal3dvEXT) bIsLoaded = 0;
	glBinormal3fEXT = (PFNGLBINORMAL3FEXTPROC)gleIntGetProcAddress("glBinormal3fEXT");
	if(!glBinormal3fEXT) bIsLoaded = 0;
	glBinormal3fvEXT = (PFNGLBINORMAL3FVEXTPROC)gleIntGetProcAddress("glBinormal3fvEXT");
	if(!glBinormal3fvEXT) bIsLoaded = 0;
	glBinormal3iEXT = (PFNGLBINORMAL3IEXTPROC)gleIntGetProcAddress("glBinormal3iEXT");
	if(!glBinormal3iEXT) bIsLoaded = 0;
	glBinormal3ivEXT = (PFNGLBINORMAL3IVEXTPROC)gleIntGetProcAddress("glBinormal3ivEXT");
	if(!glBinormal3ivEXT) bIsLoaded = 0;
	glBinormal3sEXT = (PFNGLBINORMAL3SEXTPROC)gleIntGetProcAddress("glBinormal3sEXT");
	if(!glBinormal3sEXT) bIsLoaded = 0;
	glBinormal3svEXT = (PFNGLBINORMAL3SVEXTPROC)gleIntGetProcAddress("glBinormal3svEXT");
	if(!glBinormal3svEXT) bIsLoaded = 0;
	glTangentPointerEXT = (PFNGLTANGENTPOINTEREXTPROC)gleIntGetProcAddress("glTangentPointerEXT");
	if(!glTangentPointerEXT) bIsLoaded = 0;
	glBinormalPointerEXT = (PFNGLBINORMALPOINTEREXTPROC)gleIntGetProcAddress("glBinormalPointerEXT");
	if(!glBinormalPointerEXT) bIsLoaded = 0;
#endif /*GL_EXT_coordinate_frame*/
	return bIsLoaded;
}
#ifndef GL_EXT_copy_texture
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );

PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXT;
PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXT;
PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXT;
PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXT;
PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXT;
#endif /*GL_EXT_copy_texture*/

static int gleIntLoad_EXT_copy_texture()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_copy_texture
	glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyTexImage1DEXT");
	if(!glCopyTexImage1DEXT) bIsLoaded = 0;
	glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyTexImage2DEXT");
	if(!glCopyTexImage2DEXT) bIsLoaded = 0;
	glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyTexSubImage1DEXT");
	if(!glCopyTexSubImage1DEXT) bIsLoaded = 0;
	glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyTexSubImage2DEXT");
	if(!glCopyTexSubImage2DEXT) bIsLoaded = 0;
	glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)gleIntGetProcAddress("glCopyTexSubImage3DEXT");
	if(!glCopyTexSubImage3DEXT) bIsLoaded = 0;
#endif /*GL_EXT_copy_texture*/
	return bIsLoaded;
}
#ifndef GL_EXT_cull_vertex
typedef void (GLE_FUNCPTR * PFNGLCULLPARAMETERDVEXTPROC)(GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCULLPARAMETERFVEXTPROC)(GLenum , GLfloat *);

PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXT;
PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXT;
#endif /*GL_EXT_cull_vertex*/

static int gleIntLoad_EXT_cull_vertex()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_cull_vertex
	glCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC)gleIntGetProcAddress("glCullParameterdvEXT");
	if(!glCullParameterdvEXT) bIsLoaded = 0;
	glCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC)gleIntGetProcAddress("glCullParameterfvEXT");
	if(!glCullParameterfvEXT) bIsLoaded = 0;
#endif /*GL_EXT_cull_vertex*/
	return bIsLoaded;
}
#ifndef GL_EXT_depth_bounds_test
typedef void (GLE_FUNCPTR * PFNGLDEPTHBOUNDSEXTPROC)(GLclampd , GLclampd );

PFNGLDEPTHBOUNDSEXTPROC glDepthBoundsEXT;
#endif /*GL_EXT_depth_bounds_test*/

static int gleIntLoad_EXT_depth_bounds_test()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_depth_bounds_test
	glDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC)gleIntGetProcAddress("glDepthBoundsEXT");
	if(!glDepthBoundsEXT) bIsLoaded = 0;
#endif /*GL_EXT_depth_bounds_test*/
	return bIsLoaded;
}
#ifndef GL_EXT_direct_state_access
typedef void (GLE_FUNCPTR * PFNGLCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLMATRIXLOADFEXTPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXLOADDEXTPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXMULTFEXTPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXMULTDEXTPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMATRIXROTATEFEXTPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMATRIXROTATEDEXTPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMATRIXSCALEFEXTPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMATRIXSCALEDEXTPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMATRIXTRANSLATEFEXTPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMATRIXTRANSLATEDEXTPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMATRIXFRUSTUMEXTPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMATRIXORTHOEXTPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMATRIXPOPEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMATRIXPUSHEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMATRIXLOADTRANSPOSEFEXTPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXLOADTRANSPOSEDEXTPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXMULTTRANSPOSEFEXTPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXMULTTRANSPOSEDEXTPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERFEXTPROC)(GLuint , GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERFVEXTPROC)(GLuint , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERIEXTPROC)(GLuint , GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERIVEXTPROC)(GLuint , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXTURESUBIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXTURESUBIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXTUREIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXTUREIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETTEXTUREIMAGEEXTPROC)(GLuint , GLenum , GLint , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTUREPARAMETERFVEXTPROC)(GLuint , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTUREPARAMETERIVEXTPROC)(GLuint , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)(GLuint , GLenum , GLint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)(GLuint , GLenum , GLint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE3DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXTURESUBIMAGE3DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERFEXTPROC)(GLenum , GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERFVEXTPROC)(GLenum , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERIEXTPROC)(GLenum , GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERIVEXTPROC)(GLenum , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXSUBIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXSUBIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYMULTITEXIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYMULTITEXIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXIMAGEEXTPROC)(GLenum , GLenum , GLint , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXPARAMETERFVEXTPROC)(GLenum , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXPARAMETERIVEXTPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)(GLenum , GLenum , GLint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)(GLenum , GLenum , GLint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXIMAGE3DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXSUBIMAGE3DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLBINDMULTITEXTUREEXTPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENABLECLIENTSTATEIEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLECLIENTSTATEIEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORDPOINTEREXTPROC)(GLenum , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXENVFEXTPROC)(GLenum , GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXENVFVEXTPROC)(GLenum , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXENVIEXTPROC)(GLenum , GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXENVIVEXTPROC)(GLenum , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENDEXTPROC)(GLenum , GLenum , GLenum , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENDVEXTPROC)(GLenum , GLenum , GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENFEXTPROC)(GLenum , GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENFVEXTPROC)(GLenum , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENIEXTPROC)(GLenum , GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXGENIVEXTPROC)(GLenum , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXENVFVEXTPROC)(GLenum , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXENVIVEXTPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXGENDVEXTPROC)(GLenum , GLenum , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXGENFVEXTPROC)(GLenum , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXGENIVEXTPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETFLOATINDEXEDVEXTPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETDOUBLEINDEXEDVEXTPROC)(GLenum , GLuint , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERINDEXEDVEXTPROC)(GLenum , GLuint , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLGETFLOATI_VEXTPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETDOUBLEI_VEXTPROC)(GLenum , GLuint , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERI_VEXTPROC)(GLenum , GLuint , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)(GLuint , GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)(GLuint , GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)(GLuint , GLenum , GLint , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)(GLenum , GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)(GLenum , GLenum , GLint , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMSTRINGEXTPROC)(GLuint , GLenum , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)(GLuint , GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)(GLuint , GLenum , GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)(GLuint , GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)(GLuint , GLenum , GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)(GLuint , GLenum , GLuint , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)(GLuint , GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMIVEXTPROC)(GLuint , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)(GLuint , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLuint , GLenum , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)(GLuint , GLenum , GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)(GLuint , GLenum , GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)(GLuint , GLenum , GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)(GLuint , GLenum , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)(GLuint , GLenum , GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)(GLuint , GLenum , GLuint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)(GLuint , GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)(GLuint , GLenum , GLuint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERIIVEXTPROC)(GLuint , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREPARAMETERIUIVEXTPROC)(GLuint , GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTUREPARAMETERIIVEXTPROC)(GLuint , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)(GLuint , GLenum , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERIIVEXTPROC)(GLenum , GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXPARAMETERIIVEXTPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint , GLint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint , GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint , GLint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint , GLint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint , GLint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint , GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint , GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint , GLint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint , GLint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint , GLint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint , GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDBUFFERDATAEXTPROC)(GLuint , GLsizeiptr , const GLvoid *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLNAMEDBUFFERSUBDATAEXTPROC)(GLuint , GLintptr , GLsizeiptr , const GLvoid *);
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPNAMEDBUFFEREXTPROC)(GLuint , GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLUNMAPNAMEDBUFFEREXTPROC)(GLuint );
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPNAMEDBUFFERRANGEEXTPROC)(GLuint , GLintptr , GLsizeiptr , GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)(GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)(GLuint , GLuint , GLintptr , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)(GLuint , GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)(GLuint , GLintptr , GLsizeiptr , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXTUREBUFFEREXTPROC)(GLuint , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXBUFFEREXTPROC)(GLenum , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)(GLuint , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)(GLuint , GLenum , GLint *);
typedef GLenum (GLE_FUNCPTR * PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)(GLuint , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)(GLuint , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)(GLuint , GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)(GLuint , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLuint , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGENERATETEXTUREMIPMAPEXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGENERATEMULTITEXMIPMAPEXTPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)(GLuint , GLsizei , const GLenum *);
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERREADBUFFEREXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLuint , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)(GLuint , GLsizei , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)(GLuint , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)(GLuint , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)(GLuint , GLenum , GLuint , GLint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXTURERENDERBUFFEREXTPROC)(GLuint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXRENDERBUFFEREXTPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1DEXTPROC)(GLuint , GLint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2DEXTPROC)(GLuint , GLint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3DEXTPROC)(GLuint , GLint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4DEXTPROC)(GLuint , GLint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1DVEXTPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2DVEXTPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3DVEXTPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4DVEXTPROC)(GLuint , GLint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)(GLuint , GLint , GLsizei , GLboolean , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXARRAYEXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXARRAYEXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)(GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)(GLuint , GLuint , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)(GLuint , GLuint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)(GLuint , GLuint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)(GLuint , GLuint , GLenum , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)(GLuint , GLuint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)(GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)(GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)(GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)(GLuint , GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)(GLuint , GLuint , GLuint , GLint , GLenum , GLboolean , GLsizei , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXARRAYINTEGERVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXARRAYPOINTERVEXTPROC)(GLuint , GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)(GLuint , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)(GLuint , GLuint , GLenum , GLvoid* *);

PFNGLCLIENTATTRIBDEFAULTEXTPROC glClientAttribDefaultEXT;
PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC glPushClientAttribDefaultEXT;
PFNGLMATRIXLOADFEXTPROC glMatrixLoadfEXT;
PFNGLMATRIXLOADDEXTPROC glMatrixLoaddEXT;
PFNGLMATRIXMULTFEXTPROC glMatrixMultfEXT;
PFNGLMATRIXMULTDEXTPROC glMatrixMultdEXT;
PFNGLMATRIXLOADIDENTITYEXTPROC glMatrixLoadIdentityEXT;
PFNGLMATRIXROTATEFEXTPROC glMatrixRotatefEXT;
PFNGLMATRIXROTATEDEXTPROC glMatrixRotatedEXT;
PFNGLMATRIXSCALEFEXTPROC glMatrixScalefEXT;
PFNGLMATRIXSCALEDEXTPROC glMatrixScaledEXT;
PFNGLMATRIXTRANSLATEFEXTPROC glMatrixTranslatefEXT;
PFNGLMATRIXTRANSLATEDEXTPROC glMatrixTranslatedEXT;
PFNGLMATRIXFRUSTUMEXTPROC glMatrixFrustumEXT;
PFNGLMATRIXORTHOEXTPROC glMatrixOrthoEXT;
PFNGLMATRIXPOPEXTPROC glMatrixPopEXT;
PFNGLMATRIXPUSHEXTPROC glMatrixPushEXT;
PFNGLMATRIXLOADTRANSPOSEFEXTPROC glMatrixLoadTransposefEXT;
PFNGLMATRIXLOADTRANSPOSEDEXTPROC glMatrixLoadTransposedEXT;
PFNGLMATRIXMULTTRANSPOSEFEXTPROC glMatrixMultTransposefEXT;
PFNGLMATRIXMULTTRANSPOSEDEXTPROC glMatrixMultTransposedEXT;
PFNGLTEXTUREPARAMETERFEXTPROC glTextureParameterfEXT;
PFNGLTEXTUREPARAMETERFVEXTPROC glTextureParameterfvEXT;
PFNGLTEXTUREPARAMETERIEXTPROC glTextureParameteriEXT;
PFNGLTEXTUREPARAMETERIVEXTPROC glTextureParameterivEXT;
PFNGLTEXTUREIMAGE1DEXTPROC glTextureImage1DEXT;
PFNGLTEXTUREIMAGE2DEXTPROC glTextureImage2DEXT;
PFNGLTEXTURESUBIMAGE1DEXTPROC glTextureSubImage1DEXT;
PFNGLTEXTURESUBIMAGE2DEXTPROC glTextureSubImage2DEXT;
PFNGLCOPYTEXTUREIMAGE1DEXTPROC glCopyTextureImage1DEXT;
PFNGLCOPYTEXTUREIMAGE2DEXTPROC glCopyTextureImage2DEXT;
PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glCopyTextureSubImage1DEXT;
PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glCopyTextureSubImage2DEXT;
PFNGLGETTEXTUREIMAGEEXTPROC glGetTextureImageEXT;
PFNGLGETTEXTUREPARAMETERFVEXTPROC glGetTextureParameterfvEXT;
PFNGLGETTEXTUREPARAMETERIVEXTPROC glGetTextureParameterivEXT;
PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glGetTextureLevelParameterfvEXT;
PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glGetTextureLevelParameterivEXT;
PFNGLTEXTUREIMAGE3DEXTPROC glTextureImage3DEXT;
PFNGLTEXTURESUBIMAGE3DEXTPROC glTextureSubImage3DEXT;
PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glCopyTextureSubImage3DEXT;
PFNGLMULTITEXPARAMETERFEXTPROC glMultiTexParameterfEXT;
PFNGLMULTITEXPARAMETERFVEXTPROC glMultiTexParameterfvEXT;
PFNGLMULTITEXPARAMETERIEXTPROC glMultiTexParameteriEXT;
PFNGLMULTITEXPARAMETERIVEXTPROC glMultiTexParameterivEXT;
PFNGLMULTITEXIMAGE1DEXTPROC glMultiTexImage1DEXT;
PFNGLMULTITEXIMAGE2DEXTPROC glMultiTexImage2DEXT;
PFNGLMULTITEXSUBIMAGE1DEXTPROC glMultiTexSubImage1DEXT;
PFNGLMULTITEXSUBIMAGE2DEXTPROC glMultiTexSubImage2DEXT;
PFNGLCOPYMULTITEXIMAGE1DEXTPROC glCopyMultiTexImage1DEXT;
PFNGLCOPYMULTITEXIMAGE2DEXTPROC glCopyMultiTexImage2DEXT;
PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC glCopyMultiTexSubImage1DEXT;
PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC glCopyMultiTexSubImage2DEXT;
PFNGLGETMULTITEXIMAGEEXTPROC glGetMultiTexImageEXT;
PFNGLGETMULTITEXPARAMETERFVEXTPROC glGetMultiTexParameterfvEXT;
PFNGLGETMULTITEXPARAMETERIVEXTPROC glGetMultiTexParameterivEXT;
PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC glGetMultiTexLevelParameterfvEXT;
PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC glGetMultiTexLevelParameterivEXT;
PFNGLMULTITEXIMAGE3DEXTPROC glMultiTexImage3DEXT;
PFNGLMULTITEXSUBIMAGE3DEXTPROC glMultiTexSubImage3DEXT;
PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC glCopyMultiTexSubImage3DEXT;
PFNGLBINDMULTITEXTUREEXTPROC glBindMultiTextureEXT;
PFNGLENABLECLIENTSTATEINDEXEDEXTPROC glEnableClientStateIndexedEXT;
PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC glDisableClientStateIndexedEXT;
PFNGLENABLECLIENTSTATEIEXTPROC glEnableClientStateiEXT;
PFNGLDISABLECLIENTSTATEIEXTPROC glDisableClientStateiEXT;
PFNGLMULTITEXCOORDPOINTEREXTPROC glMultiTexCoordPointerEXT;
PFNGLMULTITEXENVFEXTPROC glMultiTexEnvfEXT;
PFNGLMULTITEXENVFVEXTPROC glMultiTexEnvfvEXT;
PFNGLMULTITEXENVIEXTPROC glMultiTexEnviEXT;
PFNGLMULTITEXENVIVEXTPROC glMultiTexEnvivEXT;
PFNGLMULTITEXGENDEXTPROC glMultiTexGendEXT;
PFNGLMULTITEXGENDVEXTPROC glMultiTexGendvEXT;
PFNGLMULTITEXGENFEXTPROC glMultiTexGenfEXT;
PFNGLMULTITEXGENFVEXTPROC glMultiTexGenfvEXT;
PFNGLMULTITEXGENIEXTPROC glMultiTexGeniEXT;
PFNGLMULTITEXGENIVEXTPROC glMultiTexGenivEXT;
PFNGLGETMULTITEXENVFVEXTPROC glGetMultiTexEnvfvEXT;
PFNGLGETMULTITEXENVIVEXTPROC glGetMultiTexEnvivEXT;
PFNGLGETMULTITEXGENDVEXTPROC glGetMultiTexGendvEXT;
PFNGLGETMULTITEXGENFVEXTPROC glGetMultiTexGenfvEXT;
PFNGLGETMULTITEXGENIVEXTPROC glGetMultiTexGenivEXT;
PFNGLGETFLOATINDEXEDVEXTPROC glGetFloatIndexedvEXT;
PFNGLGETDOUBLEINDEXEDVEXTPROC glGetDoubleIndexedvEXT;
PFNGLGETPOINTERINDEXEDVEXTPROC glGetPointerIndexedvEXT;
PFNGLGETFLOATI_VEXTPROC glGetFloati_vEXT;
PFNGLGETDOUBLEI_VEXTPROC glGetDoublei_vEXT;
PFNGLGETPOINTERI_VEXTPROC glGetPointeri_vEXT;
PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glCompressedTextureImage3DEXT;
PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glCompressedTextureImage2DEXT;
PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glCompressedTextureImage1DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glCompressedTextureSubImage3DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glCompressedTextureSubImage2DEXT;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glCompressedTextureSubImage1DEXT;
PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glGetCompressedTextureImageEXT;
PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC glCompressedMultiTexImage3DEXT;
PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC glCompressedMultiTexImage2DEXT;
PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC glCompressedMultiTexImage1DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC glCompressedMultiTexSubImage3DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC glCompressedMultiTexSubImage2DEXT;
PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC glCompressedMultiTexSubImage1DEXT;
PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC glGetCompressedMultiTexImageEXT;
PFNGLNAMEDPROGRAMSTRINGEXTPROC glNamedProgramStringEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC glNamedProgramLocalParameter4dEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC glNamedProgramLocalParameter4dvEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC glNamedProgramLocalParameter4fEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC glNamedProgramLocalParameter4fvEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC glGetNamedProgramLocalParameterdvEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC glGetNamedProgramLocalParameterfvEXT;
PFNGLGETNAMEDPROGRAMIVEXTPROC glGetNamedProgramivEXT;
PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glGetNamedProgramStringEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC glNamedProgramLocalParameters4fvEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC glNamedProgramLocalParameterI4iEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC glNamedProgramLocalParameterI4ivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC glNamedProgramLocalParametersI4ivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC glNamedProgramLocalParameterI4uiEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC glNamedProgramLocalParameterI4uivEXT;
PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC glNamedProgramLocalParametersI4uivEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC glGetNamedProgramLocalParameterIivEXT;
PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC glGetNamedProgramLocalParameterIuivEXT;
PFNGLTEXTUREPARAMETERIIVEXTPROC glTextureParameterIivEXT;
PFNGLTEXTUREPARAMETERIUIVEXTPROC glTextureParameterIuivEXT;
PFNGLGETTEXTUREPARAMETERIIVEXTPROC glGetTextureParameterIivEXT;
PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glGetTextureParameterIuivEXT;
PFNGLMULTITEXPARAMETERIIVEXTPROC glMultiTexParameterIivEXT;
PFNGLMULTITEXPARAMETERIUIVEXTPROC glMultiTexParameterIuivEXT;
PFNGLGETMULTITEXPARAMETERIIVEXTPROC glGetMultiTexParameterIivEXT;
PFNGLGETMULTITEXPARAMETERIUIVEXTPROC glGetMultiTexParameterIuivEXT;
PFNGLPROGRAMUNIFORM1FEXTPROC glProgramUniform1fEXT;
PFNGLPROGRAMUNIFORM2FEXTPROC glProgramUniform2fEXT;
PFNGLPROGRAMUNIFORM3FEXTPROC glProgramUniform3fEXT;
PFNGLPROGRAMUNIFORM4FEXTPROC glProgramUniform4fEXT;
PFNGLPROGRAMUNIFORM1IEXTPROC glProgramUniform1iEXT;
PFNGLPROGRAMUNIFORM2IEXTPROC glProgramUniform2iEXT;
PFNGLPROGRAMUNIFORM3IEXTPROC glProgramUniform3iEXT;
PFNGLPROGRAMUNIFORM4IEXTPROC glProgramUniform4iEXT;
PFNGLPROGRAMUNIFORM1FVEXTPROC glProgramUniform1fvEXT;
PFNGLPROGRAMUNIFORM2FVEXTPROC glProgramUniform2fvEXT;
PFNGLPROGRAMUNIFORM3FVEXTPROC glProgramUniform3fvEXT;
PFNGLPROGRAMUNIFORM4FVEXTPROC glProgramUniform4fvEXT;
PFNGLPROGRAMUNIFORM1IVEXTPROC glProgramUniform1ivEXT;
PFNGLPROGRAMUNIFORM2IVEXTPROC glProgramUniform2ivEXT;
PFNGLPROGRAMUNIFORM3IVEXTPROC glProgramUniform3ivEXT;
PFNGLPROGRAMUNIFORM4IVEXTPROC glProgramUniform4ivEXT;
PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glProgramUniformMatrix2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glProgramUniformMatrix3fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glProgramUniformMatrix4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glProgramUniformMatrix2x3fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glProgramUniformMatrix3x2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glProgramUniformMatrix2x4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glProgramUniformMatrix4x2fvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glProgramUniformMatrix3x4fvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glProgramUniformMatrix4x3fvEXT;
PFNGLPROGRAMUNIFORM1UIEXTPROC glProgramUniform1uiEXT;
PFNGLPROGRAMUNIFORM2UIEXTPROC glProgramUniform2uiEXT;
PFNGLPROGRAMUNIFORM3UIEXTPROC glProgramUniform3uiEXT;
PFNGLPROGRAMUNIFORM4UIEXTPROC glProgramUniform4uiEXT;
PFNGLPROGRAMUNIFORM1UIVEXTPROC glProgramUniform1uivEXT;
PFNGLPROGRAMUNIFORM2UIVEXTPROC glProgramUniform2uivEXT;
PFNGLPROGRAMUNIFORM3UIVEXTPROC glProgramUniform3uivEXT;
PFNGLPROGRAMUNIFORM4UIVEXTPROC glProgramUniform4uivEXT;
PFNGLNAMEDBUFFERDATAEXTPROC glNamedBufferDataEXT;
PFNGLNAMEDBUFFERSUBDATAEXTPROC glNamedBufferSubDataEXT;
PFNGLMAPNAMEDBUFFEREXTPROC glMapNamedBufferEXT;
PFNGLUNMAPNAMEDBUFFEREXTPROC glUnmapNamedBufferEXT;
PFNGLMAPNAMEDBUFFERRANGEEXTPROC glMapNamedBufferRangeEXT;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRangeEXT;
PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glNamedCopyBufferSubDataEXT;
PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glGetNamedBufferParameterivEXT;
PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glGetNamedBufferPointervEXT;
PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glGetNamedBufferSubDataEXT;
PFNGLTEXTUREBUFFEREXTPROC glTextureBufferEXT;
PFNGLMULTITEXBUFFEREXTPROC glMultiTexBufferEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glNamedRenderbufferStorageEXT;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glGetNamedRenderbufferParameterivEXT;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glCheckNamedFramebufferStatusEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glNamedFramebufferTexture1DEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glNamedFramebufferTexture2DEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glNamedFramebufferTexture3DEXT;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glNamedFramebufferRenderbufferEXT;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetNamedFramebufferAttachmentParameterivEXT;
PFNGLGENERATETEXTUREMIPMAPEXTPROC glGenerateTextureMipmapEXT;
PFNGLGENERATEMULTITEXMIPMAPEXTPROC glGenerateMultiTexMipmapEXT;
PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glFramebufferDrawBufferEXT;
PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glFramebufferDrawBuffersEXT;
PFNGLFRAMEBUFFERREADBUFFEREXTPROC glFramebufferReadBufferEXT;
PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glGetFramebufferParameterivEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glNamedRenderbufferStorageMultisampleEXT;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glNamedRenderbufferStorageMultisampleCoverageEXT;
PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glNamedFramebufferTextureEXT;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glNamedFramebufferTextureLayerEXT;
PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glNamedFramebufferTextureFaceEXT;
PFNGLTEXTURERENDERBUFFEREXTPROC glTextureRenderbufferEXT;
PFNGLMULTITEXRENDERBUFFEREXTPROC glMultiTexRenderbufferEXT;
PFNGLPROGRAMUNIFORM1DEXTPROC glProgramUniform1dEXT;
PFNGLPROGRAMUNIFORM2DEXTPROC glProgramUniform2dEXT;
PFNGLPROGRAMUNIFORM3DEXTPROC glProgramUniform3dEXT;
PFNGLPROGRAMUNIFORM4DEXTPROC glProgramUniform4dEXT;
PFNGLPROGRAMUNIFORM1DVEXTPROC glProgramUniform1dvEXT;
PFNGLPROGRAMUNIFORM2DVEXTPROC glProgramUniform2dvEXT;
PFNGLPROGRAMUNIFORM3DVEXTPROC glProgramUniform3dvEXT;
PFNGLPROGRAMUNIFORM4DVEXTPROC glProgramUniform4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC glProgramUniformMatrix2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC glProgramUniformMatrix3dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC glProgramUniformMatrix4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC glProgramUniformMatrix2x3dvEXT;
PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC glProgramUniformMatrix2x4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC glProgramUniformMatrix3x2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC glProgramUniformMatrix3x4dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC glProgramUniformMatrix4x2dvEXT;
PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC glProgramUniformMatrix4x3dvEXT;
PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glEnableVertexArrayAttribEXT;
PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glDisableVertexArrayAttribEXT;
PFNGLENABLEVERTEXARRAYEXTPROC glEnableVertexArrayEXT;
PFNGLDISABLEVERTEXARRAYEXTPROC glDisableVertexArrayEXT;
PFNGLVERTEXARRAYCOLOROFFSETEXTPROC glVertexArrayColorOffsetEXT;
PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC glVertexArrayEdgeFlagOffsetEXT;
PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC glVertexArrayFogCoordOffsetEXT;
PFNGLVERTEXARRAYINDEXOFFSETEXTPROC glVertexArrayIndexOffsetEXT;
PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC glVertexArrayMultiTexCoordOffsetEXT;
PFNGLVERTEXARRAYNORMALOFFSETEXTPROC glVertexArrayNormalOffsetEXT;
PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC glVertexArraySecondaryColorOffsetEXT;
PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC glVertexArrayTexCoordOffsetEXT;
PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glVertexArrayVertexOffsetEXT;
PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glVertexArrayVertexAttribIOffsetEXT;
PFNGLGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glglVertexArrayVertexAttribOffsetEXT;
PFNGLGETVERTEXARRAYINTEGERVEXTPROC glGetVertexArrayIntegervEXT;
PFNGLGETVERTEXARRAYPOINTERVEXTPROC glGetVertexArrayPointervEXT;
PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glGetVertexArrayIntegeri_vEXT;
PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glGetVertexArrayPointeri_vEXT;
#endif /*GL_EXT_direct_state_access*/

static int gleIntLoad_EXT_direct_state_access()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_direct_state_access
	glClientAttribDefaultEXT = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)gleIntGetProcAddress("glClientAttribDefaultEXT");
	if(!glClientAttribDefaultEXT) bIsLoaded = 0;
	glPushClientAttribDefaultEXT = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)gleIntGetProcAddress("glPushClientAttribDefaultEXT");
	if(!glPushClientAttribDefaultEXT) bIsLoaded = 0;
	glMatrixLoadfEXT = (PFNGLMATRIXLOADFEXTPROC)gleIntGetProcAddress("glMatrixLoadfEXT");
	if(!glMatrixLoadfEXT) bIsLoaded = 0;
	glMatrixLoaddEXT = (PFNGLMATRIXLOADDEXTPROC)gleIntGetProcAddress("glMatrixLoaddEXT");
	if(!glMatrixLoaddEXT) bIsLoaded = 0;
	glMatrixMultfEXT = (PFNGLMATRIXMULTFEXTPROC)gleIntGetProcAddress("glMatrixMultfEXT");
	if(!glMatrixMultfEXT) bIsLoaded = 0;
	glMatrixMultdEXT = (PFNGLMATRIXMULTDEXTPROC)gleIntGetProcAddress("glMatrixMultdEXT");
	if(!glMatrixMultdEXT) bIsLoaded = 0;
	glMatrixLoadIdentityEXT = (PFNGLMATRIXLOADIDENTITYEXTPROC)gleIntGetProcAddress("glMatrixLoadIdentityEXT");
	if(!glMatrixLoadIdentityEXT) bIsLoaded = 0;
	glMatrixRotatefEXT = (PFNGLMATRIXROTATEFEXTPROC)gleIntGetProcAddress("glMatrixRotatefEXT");
	if(!glMatrixRotatefEXT) bIsLoaded = 0;
	glMatrixRotatedEXT = (PFNGLMATRIXROTATEDEXTPROC)gleIntGetProcAddress("glMatrixRotatedEXT");
	if(!glMatrixRotatedEXT) bIsLoaded = 0;
	glMatrixScalefEXT = (PFNGLMATRIXSCALEFEXTPROC)gleIntGetProcAddress("glMatrixScalefEXT");
	if(!glMatrixScalefEXT) bIsLoaded = 0;
	glMatrixScaledEXT = (PFNGLMATRIXSCALEDEXTPROC)gleIntGetProcAddress("glMatrixScaledEXT");
	if(!glMatrixScaledEXT) bIsLoaded = 0;
	glMatrixTranslatefEXT = (PFNGLMATRIXTRANSLATEFEXTPROC)gleIntGetProcAddress("glMatrixTranslatefEXT");
	if(!glMatrixTranslatefEXT) bIsLoaded = 0;
	glMatrixTranslatedEXT = (PFNGLMATRIXTRANSLATEDEXTPROC)gleIntGetProcAddress("glMatrixTranslatedEXT");
	if(!glMatrixTranslatedEXT) bIsLoaded = 0;
	glMatrixFrustumEXT = (PFNGLMATRIXFRUSTUMEXTPROC)gleIntGetProcAddress("glMatrixFrustumEXT");
	if(!glMatrixFrustumEXT) bIsLoaded = 0;
	glMatrixOrthoEXT = (PFNGLMATRIXORTHOEXTPROC)gleIntGetProcAddress("glMatrixOrthoEXT");
	if(!glMatrixOrthoEXT) bIsLoaded = 0;
	glMatrixPopEXT = (PFNGLMATRIXPOPEXTPROC)gleIntGetProcAddress("glMatrixPopEXT");
	if(!glMatrixPopEXT) bIsLoaded = 0;
	glMatrixPushEXT = (PFNGLMATRIXPUSHEXTPROC)gleIntGetProcAddress("glMatrixPushEXT");
	if(!glMatrixPushEXT) bIsLoaded = 0;
	glMatrixLoadTransposefEXT = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC)gleIntGetProcAddress("glMatrixLoadTransposefEXT");
	if(!glMatrixLoadTransposefEXT) bIsLoaded = 0;
	glMatrixLoadTransposedEXT = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC)gleIntGetProcAddress("glMatrixLoadTransposedEXT");
	if(!glMatrixLoadTransposedEXT) bIsLoaded = 0;
	glMatrixMultTransposefEXT = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC)gleIntGetProcAddress("glMatrixMultTransposefEXT");
	if(!glMatrixMultTransposefEXT) bIsLoaded = 0;
	glMatrixMultTransposedEXT = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC)gleIntGetProcAddress("glMatrixMultTransposedEXT");
	if(!glMatrixMultTransposedEXT) bIsLoaded = 0;
	glTextureParameterfEXT = (PFNGLTEXTUREPARAMETERFEXTPROC)gleIntGetProcAddress("glTextureParameterfEXT");
	if(!glTextureParameterfEXT) bIsLoaded = 0;
	glTextureParameterfvEXT = (PFNGLTEXTUREPARAMETERFVEXTPROC)gleIntGetProcAddress("glTextureParameterfvEXT");
	if(!glTextureParameterfvEXT) bIsLoaded = 0;
	glTextureParameteriEXT = (PFNGLTEXTUREPARAMETERIEXTPROC)gleIntGetProcAddress("glTextureParameteriEXT");
	if(!glTextureParameteriEXT) bIsLoaded = 0;
	glTextureParameterivEXT = (PFNGLTEXTUREPARAMETERIVEXTPROC)gleIntGetProcAddress("glTextureParameterivEXT");
	if(!glTextureParameterivEXT) bIsLoaded = 0;
	glTextureImage1DEXT = (PFNGLTEXTUREIMAGE1DEXTPROC)gleIntGetProcAddress("glTextureImage1DEXT");
	if(!glTextureImage1DEXT) bIsLoaded = 0;
	glTextureImage2DEXT = (PFNGLTEXTUREIMAGE2DEXTPROC)gleIntGetProcAddress("glTextureImage2DEXT");
	if(!glTextureImage2DEXT) bIsLoaded = 0;
	glTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXTPROC)gleIntGetProcAddress("glTextureSubImage1DEXT");
	if(!glTextureSubImage1DEXT) bIsLoaded = 0;
	glTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC)gleIntGetProcAddress("glTextureSubImage2DEXT");
	if(!glTextureSubImage2DEXT) bIsLoaded = 0;
	glCopyTextureImage1DEXT = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyTextureImage1DEXT");
	if(!glCopyTextureImage1DEXT) bIsLoaded = 0;
	glCopyTextureImage2DEXT = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyTextureImage2DEXT");
	if(!glCopyTextureImage2DEXT) bIsLoaded = 0;
	glCopyTextureSubImage1DEXT = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyTextureSubImage1DEXT");
	if(!glCopyTextureSubImage1DEXT) bIsLoaded = 0;
	glCopyTextureSubImage2DEXT = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyTextureSubImage2DEXT");
	if(!glCopyTextureSubImage2DEXT) bIsLoaded = 0;
	glGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC)gleIntGetProcAddress("glGetTextureImageEXT");
	if(!glGetTextureImageEXT) bIsLoaded = 0;
	glGetTextureParameterfvEXT = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetTextureParameterfvEXT");
	if(!glGetTextureParameterfvEXT) bIsLoaded = 0;
	glGetTextureParameterivEXT = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetTextureParameterivEXT");
	if(!glGetTextureParameterivEXT) bIsLoaded = 0;
	glGetTextureLevelParameterfvEXT = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetTextureLevelParameterfvEXT");
	if(!glGetTextureLevelParameterfvEXT) bIsLoaded = 0;
	glGetTextureLevelParameterivEXT = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetTextureLevelParameterivEXT");
	if(!glGetTextureLevelParameterivEXT) bIsLoaded = 0;
	glTextureImage3DEXT = (PFNGLTEXTUREIMAGE3DEXTPROC)gleIntGetProcAddress("glTextureImage3DEXT");
	if(!glTextureImage3DEXT) bIsLoaded = 0;
	glTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXTPROC)gleIntGetProcAddress("glTextureSubImage3DEXT");
	if(!glTextureSubImage3DEXT) bIsLoaded = 0;
	glCopyTextureSubImage3DEXT = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)gleIntGetProcAddress("glCopyTextureSubImage3DEXT");
	if(!glCopyTextureSubImage3DEXT) bIsLoaded = 0;
	glMultiTexParameterfEXT = (PFNGLMULTITEXPARAMETERFEXTPROC)gleIntGetProcAddress("glMultiTexParameterfEXT");
	if(!glMultiTexParameterfEXT) bIsLoaded = 0;
	glMultiTexParameterfvEXT = (PFNGLMULTITEXPARAMETERFVEXTPROC)gleIntGetProcAddress("glMultiTexParameterfvEXT");
	if(!glMultiTexParameterfvEXT) bIsLoaded = 0;
	glMultiTexParameteriEXT = (PFNGLMULTITEXPARAMETERIEXTPROC)gleIntGetProcAddress("glMultiTexParameteriEXT");
	if(!glMultiTexParameteriEXT) bIsLoaded = 0;
	glMultiTexParameterivEXT = (PFNGLMULTITEXPARAMETERIVEXTPROC)gleIntGetProcAddress("glMultiTexParameterivEXT");
	if(!glMultiTexParameterivEXT) bIsLoaded = 0;
	glMultiTexImage1DEXT = (PFNGLMULTITEXIMAGE1DEXTPROC)gleIntGetProcAddress("glMultiTexImage1DEXT");
	if(!glMultiTexImage1DEXT) bIsLoaded = 0;
	glMultiTexImage2DEXT = (PFNGLMULTITEXIMAGE2DEXTPROC)gleIntGetProcAddress("glMultiTexImage2DEXT");
	if(!glMultiTexImage2DEXT) bIsLoaded = 0;
	glMultiTexSubImage1DEXT = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)gleIntGetProcAddress("glMultiTexSubImage1DEXT");
	if(!glMultiTexSubImage1DEXT) bIsLoaded = 0;
	glMultiTexSubImage2DEXT = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)gleIntGetProcAddress("glMultiTexSubImage2DEXT");
	if(!glMultiTexSubImage2DEXT) bIsLoaded = 0;
	glCopyMultiTexImage1DEXT = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyMultiTexImage1DEXT");
	if(!glCopyMultiTexImage1DEXT) bIsLoaded = 0;
	glCopyMultiTexImage2DEXT = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyMultiTexImage2DEXT");
	if(!glCopyMultiTexImage2DEXT) bIsLoaded = 0;
	glCopyMultiTexSubImage1DEXT = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)gleIntGetProcAddress("glCopyMultiTexSubImage1DEXT");
	if(!glCopyMultiTexSubImage1DEXT) bIsLoaded = 0;
	glCopyMultiTexSubImage2DEXT = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)gleIntGetProcAddress("glCopyMultiTexSubImage2DEXT");
	if(!glCopyMultiTexSubImage2DEXT) bIsLoaded = 0;
	glGetMultiTexImageEXT = (PFNGLGETMULTITEXIMAGEEXTPROC)gleIntGetProcAddress("glGetMultiTexImageEXT");
	if(!glGetMultiTexImageEXT) bIsLoaded = 0;
	glGetMultiTexParameterfvEXT = (PFNGLGETMULTITEXPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetMultiTexParameterfvEXT");
	if(!glGetMultiTexParameterfvEXT) bIsLoaded = 0;
	glGetMultiTexParameterivEXT = (PFNGLGETMULTITEXPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetMultiTexParameterivEXT");
	if(!glGetMultiTexParameterivEXT) bIsLoaded = 0;
	glGetMultiTexLevelParameterfvEXT = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetMultiTexLevelParameterfvEXT");
	if(!glGetMultiTexLevelParameterfvEXT) bIsLoaded = 0;
	glGetMultiTexLevelParameterivEXT = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetMultiTexLevelParameterivEXT");
	if(!glGetMultiTexLevelParameterivEXT) bIsLoaded = 0;
	glMultiTexImage3DEXT = (PFNGLMULTITEXIMAGE3DEXTPROC)gleIntGetProcAddress("glMultiTexImage3DEXT");
	if(!glMultiTexImage3DEXT) bIsLoaded = 0;
	glMultiTexSubImage3DEXT = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)gleIntGetProcAddress("glMultiTexSubImage3DEXT");
	if(!glMultiTexSubImage3DEXT) bIsLoaded = 0;
	glCopyMultiTexSubImage3DEXT = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)gleIntGetProcAddress("glCopyMultiTexSubImage3DEXT");
	if(!glCopyMultiTexSubImage3DEXT) bIsLoaded = 0;
	glBindMultiTextureEXT = (PFNGLBINDMULTITEXTUREEXTPROC)gleIntGetProcAddress("glBindMultiTextureEXT");
	if(!glBindMultiTextureEXT) bIsLoaded = 0;
	glEnableClientStateIndexedEXT = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)gleIntGetProcAddress("glEnableClientStateIndexedEXT");
	if(!glEnableClientStateIndexedEXT) bIsLoaded = 0;
	glDisableClientStateIndexedEXT = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)gleIntGetProcAddress("glDisableClientStateIndexedEXT");
	if(!glDisableClientStateIndexedEXT) bIsLoaded = 0;
	glEnableClientStateiEXT = (PFNGLENABLECLIENTSTATEIEXTPROC)gleIntGetProcAddress("glEnableClientStateiEXT");
	if(!glEnableClientStateiEXT) bIsLoaded = 0;
	glDisableClientStateiEXT = (PFNGLDISABLECLIENTSTATEIEXTPROC)gleIntGetProcAddress("glDisableClientStateiEXT");
	if(!glDisableClientStateiEXT) bIsLoaded = 0;
	glMultiTexCoordPointerEXT = (PFNGLMULTITEXCOORDPOINTEREXTPROC)gleIntGetProcAddress("glMultiTexCoordPointerEXT");
	if(!glMultiTexCoordPointerEXT) bIsLoaded = 0;
	glMultiTexEnvfEXT = (PFNGLMULTITEXENVFEXTPROC)gleIntGetProcAddress("glMultiTexEnvfEXT");
	if(!glMultiTexEnvfEXT) bIsLoaded = 0;
	glMultiTexEnvfvEXT = (PFNGLMULTITEXENVFVEXTPROC)gleIntGetProcAddress("glMultiTexEnvfvEXT");
	if(!glMultiTexEnvfvEXT) bIsLoaded = 0;
	glMultiTexEnviEXT = (PFNGLMULTITEXENVIEXTPROC)gleIntGetProcAddress("glMultiTexEnviEXT");
	if(!glMultiTexEnviEXT) bIsLoaded = 0;
	glMultiTexEnvivEXT = (PFNGLMULTITEXENVIVEXTPROC)gleIntGetProcAddress("glMultiTexEnvivEXT");
	if(!glMultiTexEnvivEXT) bIsLoaded = 0;
	glMultiTexGendEXT = (PFNGLMULTITEXGENDEXTPROC)gleIntGetProcAddress("glMultiTexGendEXT");
	if(!glMultiTexGendEXT) bIsLoaded = 0;
	glMultiTexGendvEXT = (PFNGLMULTITEXGENDVEXTPROC)gleIntGetProcAddress("glMultiTexGendvEXT");
	if(!glMultiTexGendvEXT) bIsLoaded = 0;
	glMultiTexGenfEXT = (PFNGLMULTITEXGENFEXTPROC)gleIntGetProcAddress("glMultiTexGenfEXT");
	if(!glMultiTexGenfEXT) bIsLoaded = 0;
	glMultiTexGenfvEXT = (PFNGLMULTITEXGENFVEXTPROC)gleIntGetProcAddress("glMultiTexGenfvEXT");
	if(!glMultiTexGenfvEXT) bIsLoaded = 0;
	glMultiTexGeniEXT = (PFNGLMULTITEXGENIEXTPROC)gleIntGetProcAddress("glMultiTexGeniEXT");
	if(!glMultiTexGeniEXT) bIsLoaded = 0;
	glMultiTexGenivEXT = (PFNGLMULTITEXGENIVEXTPROC)gleIntGetProcAddress("glMultiTexGenivEXT");
	if(!glMultiTexGenivEXT) bIsLoaded = 0;
	glGetMultiTexEnvfvEXT = (PFNGLGETMULTITEXENVFVEXTPROC)gleIntGetProcAddress("glGetMultiTexEnvfvEXT");
	if(!glGetMultiTexEnvfvEXT) bIsLoaded = 0;
	glGetMultiTexEnvivEXT = (PFNGLGETMULTITEXENVIVEXTPROC)gleIntGetProcAddress("glGetMultiTexEnvivEXT");
	if(!glGetMultiTexEnvivEXT) bIsLoaded = 0;
	glGetMultiTexGendvEXT = (PFNGLGETMULTITEXGENDVEXTPROC)gleIntGetProcAddress("glGetMultiTexGendvEXT");
	if(!glGetMultiTexGendvEXT) bIsLoaded = 0;
	glGetMultiTexGenfvEXT = (PFNGLGETMULTITEXGENFVEXTPROC)gleIntGetProcAddress("glGetMultiTexGenfvEXT");
	if(!glGetMultiTexGenfvEXT) bIsLoaded = 0;
	glGetMultiTexGenivEXT = (PFNGLGETMULTITEXGENIVEXTPROC)gleIntGetProcAddress("glGetMultiTexGenivEXT");
	if(!glGetMultiTexGenivEXT) bIsLoaded = 0;
	glGetFloatIndexedvEXT = (PFNGLGETFLOATINDEXEDVEXTPROC)gleIntGetProcAddress("glGetFloatIndexedvEXT");
	if(!glGetFloatIndexedvEXT) bIsLoaded = 0;
	glGetDoubleIndexedvEXT = (PFNGLGETDOUBLEINDEXEDVEXTPROC)gleIntGetProcAddress("glGetDoubleIndexedvEXT");
	if(!glGetDoubleIndexedvEXT) bIsLoaded = 0;
	glGetPointerIndexedvEXT = (PFNGLGETPOINTERINDEXEDVEXTPROC)gleIntGetProcAddress("glGetPointerIndexedvEXT");
	if(!glGetPointerIndexedvEXT) bIsLoaded = 0;
	glGetFloati_vEXT = (PFNGLGETFLOATI_VEXTPROC)gleIntGetProcAddress("glGetFloati_vEXT");
	if(!glGetFloati_vEXT) bIsLoaded = 0;
	glGetDoublei_vEXT = (PFNGLGETDOUBLEI_VEXTPROC)gleIntGetProcAddress("glGetDoublei_vEXT");
	if(!glGetDoublei_vEXT) bIsLoaded = 0;
	glGetPointeri_vEXT = (PFNGLGETPOINTERI_VEXTPROC)gleIntGetProcAddress("glGetPointeri_vEXT");
	if(!glGetPointeri_vEXT) bIsLoaded = 0;
	glCompressedTextureImage3DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)gleIntGetProcAddress("glCompressedTextureImage3DEXT");
	if(!glCompressedTextureImage3DEXT) bIsLoaded = 0;
	glCompressedTextureImage2DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)gleIntGetProcAddress("glCompressedTextureImage2DEXT");
	if(!glCompressedTextureImage2DEXT) bIsLoaded = 0;
	glCompressedTextureImage1DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)gleIntGetProcAddress("glCompressedTextureImage1DEXT");
	if(!glCompressedTextureImage1DEXT) bIsLoaded = 0;
	glCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)gleIntGetProcAddress("glCompressedTextureSubImage3DEXT");
	if(!glCompressedTextureSubImage3DEXT) bIsLoaded = 0;
	glCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)gleIntGetProcAddress("glCompressedTextureSubImage2DEXT");
	if(!glCompressedTextureSubImage2DEXT) bIsLoaded = 0;
	glCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)gleIntGetProcAddress("glCompressedTextureSubImage1DEXT");
	if(!glCompressedTextureSubImage1DEXT) bIsLoaded = 0;
	glGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)gleIntGetProcAddress("glGetCompressedTextureImageEXT");
	if(!glGetCompressedTextureImageEXT) bIsLoaded = 0;
	glCompressedMultiTexImage3DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexImage3DEXT");
	if(!glCompressedMultiTexImage3DEXT) bIsLoaded = 0;
	glCompressedMultiTexImage2DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexImage2DEXT");
	if(!glCompressedMultiTexImage2DEXT) bIsLoaded = 0;
	glCompressedMultiTexImage1DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexImage1DEXT");
	if(!glCompressedMultiTexImage1DEXT) bIsLoaded = 0;
	glCompressedMultiTexSubImage3DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexSubImage3DEXT");
	if(!glCompressedMultiTexSubImage3DEXT) bIsLoaded = 0;
	glCompressedMultiTexSubImage2DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexSubImage2DEXT");
	if(!glCompressedMultiTexSubImage2DEXT) bIsLoaded = 0;
	glCompressedMultiTexSubImage1DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)gleIntGetProcAddress("glCompressedMultiTexSubImage1DEXT");
	if(!glCompressedMultiTexSubImage1DEXT) bIsLoaded = 0;
	glGetCompressedMultiTexImageEXT = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)gleIntGetProcAddress("glGetCompressedMultiTexImageEXT");
	if(!glGetCompressedMultiTexImageEXT) bIsLoaded = 0;
	glNamedProgramStringEXT = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)gleIntGetProcAddress("glNamedProgramStringEXT");
	if(!glNamedProgramStringEXT) bIsLoaded = 0;
	glNamedProgramLocalParameter4dEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameter4dEXT");
	if(!glNamedProgramLocalParameter4dEXT) bIsLoaded = 0;
	glNamedProgramLocalParameter4dvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameter4dvEXT");
	if(!glNamedProgramLocalParameter4dvEXT) bIsLoaded = 0;
	glNamedProgramLocalParameter4fEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameter4fEXT");
	if(!glNamedProgramLocalParameter4fEXT) bIsLoaded = 0;
	glNamedProgramLocalParameter4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameter4fvEXT");
	if(!glNamedProgramLocalParameter4fvEXT) bIsLoaded = 0;
	glGetNamedProgramLocalParameterdvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)gleIntGetProcAddress("glGetNamedProgramLocalParameterdvEXT");
	if(!glGetNamedProgramLocalParameterdvEXT) bIsLoaded = 0;
	glGetNamedProgramLocalParameterfvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetNamedProgramLocalParameterfvEXT");
	if(!glGetNamedProgramLocalParameterfvEXT) bIsLoaded = 0;
	glGetNamedProgramivEXT = (PFNGLGETNAMEDPROGRAMIVEXTPROC)gleIntGetProcAddress("glGetNamedProgramivEXT");
	if(!glGetNamedProgramivEXT) bIsLoaded = 0;
	glGetNamedProgramStringEXT = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)gleIntGetProcAddress("glGetNamedProgramStringEXT");
	if(!glGetNamedProgramStringEXT) bIsLoaded = 0;
	glNamedProgramLocalParameters4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameters4fvEXT");
	if(!glNamedProgramLocalParameters4fvEXT) bIsLoaded = 0;
	glNamedProgramLocalParameterI4iEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameterI4iEXT");
	if(!glNamedProgramLocalParameterI4iEXT) bIsLoaded = 0;
	glNamedProgramLocalParameterI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameterI4ivEXT");
	if(!glNamedProgramLocalParameterI4ivEXT) bIsLoaded = 0;
	glNamedProgramLocalParametersI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParametersI4ivEXT");
	if(!glNamedProgramLocalParametersI4ivEXT) bIsLoaded = 0;
	glNamedProgramLocalParameterI4uiEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameterI4uiEXT");
	if(!glNamedProgramLocalParameterI4uiEXT) bIsLoaded = 0;
	glNamedProgramLocalParameterI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParameterI4uivEXT");
	if(!glNamedProgramLocalParameterI4uivEXT) bIsLoaded = 0;
	glNamedProgramLocalParametersI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)gleIntGetProcAddress("glNamedProgramLocalParametersI4uivEXT");
	if(!glNamedProgramLocalParametersI4uivEXT) bIsLoaded = 0;
	glGetNamedProgramLocalParameterIivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)gleIntGetProcAddress("glGetNamedProgramLocalParameterIivEXT");
	if(!glGetNamedProgramLocalParameterIivEXT) bIsLoaded = 0;
	glGetNamedProgramLocalParameterIuivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glGetNamedProgramLocalParameterIuivEXT");
	if(!glGetNamedProgramLocalParameterIuivEXT) bIsLoaded = 0;
	glTextureParameterIivEXT = (PFNGLTEXTUREPARAMETERIIVEXTPROC)gleIntGetProcAddress("glTextureParameterIivEXT");
	if(!glTextureParameterIivEXT) bIsLoaded = 0;
	glTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glTextureParameterIuivEXT");
	if(!glTextureParameterIuivEXT) bIsLoaded = 0;
	glGetTextureParameterIivEXT = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)gleIntGetProcAddress("glGetTextureParameterIivEXT");
	if(!glGetTextureParameterIivEXT) bIsLoaded = 0;
	glGetTextureParameterIuivEXT = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glGetTextureParameterIuivEXT");
	if(!glGetTextureParameterIuivEXT) bIsLoaded = 0;
	glMultiTexParameterIivEXT = (PFNGLMULTITEXPARAMETERIIVEXTPROC)gleIntGetProcAddress("glMultiTexParameterIivEXT");
	if(!glMultiTexParameterIivEXT) bIsLoaded = 0;
	glMultiTexParameterIuivEXT = (PFNGLMULTITEXPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glMultiTexParameterIuivEXT");
	if(!glMultiTexParameterIuivEXT) bIsLoaded = 0;
	glGetMultiTexParameterIivEXT = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC)gleIntGetProcAddress("glGetMultiTexParameterIivEXT");
	if(!glGetMultiTexParameterIivEXT) bIsLoaded = 0;
	glGetMultiTexParameterIuivEXT = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glGetMultiTexParameterIuivEXT");
	if(!glGetMultiTexParameterIuivEXT) bIsLoaded = 0;
	glProgramUniform1fEXT = (PFNGLPROGRAMUNIFORM1FEXTPROC)gleIntGetProcAddress("glProgramUniform1fEXT");
	if(!glProgramUniform1fEXT) bIsLoaded = 0;
	glProgramUniform2fEXT = (PFNGLPROGRAMUNIFORM2FEXTPROC)gleIntGetProcAddress("glProgramUniform2fEXT");
	if(!glProgramUniform2fEXT) bIsLoaded = 0;
	glProgramUniform3fEXT = (PFNGLPROGRAMUNIFORM3FEXTPROC)gleIntGetProcAddress("glProgramUniform3fEXT");
	if(!glProgramUniform3fEXT) bIsLoaded = 0;
	glProgramUniform4fEXT = (PFNGLPROGRAMUNIFORM4FEXTPROC)gleIntGetProcAddress("glProgramUniform4fEXT");
	if(!glProgramUniform4fEXT) bIsLoaded = 0;
	glProgramUniform1iEXT = (PFNGLPROGRAMUNIFORM1IEXTPROC)gleIntGetProcAddress("glProgramUniform1iEXT");
	if(!glProgramUniform1iEXT) bIsLoaded = 0;
	glProgramUniform2iEXT = (PFNGLPROGRAMUNIFORM2IEXTPROC)gleIntGetProcAddress("glProgramUniform2iEXT");
	if(!glProgramUniform2iEXT) bIsLoaded = 0;
	glProgramUniform3iEXT = (PFNGLPROGRAMUNIFORM3IEXTPROC)gleIntGetProcAddress("glProgramUniform3iEXT");
	if(!glProgramUniform3iEXT) bIsLoaded = 0;
	glProgramUniform4iEXT = (PFNGLPROGRAMUNIFORM4IEXTPROC)gleIntGetProcAddress("glProgramUniform4iEXT");
	if(!glProgramUniform4iEXT) bIsLoaded = 0;
	glProgramUniform1fvEXT = (PFNGLPROGRAMUNIFORM1FVEXTPROC)gleIntGetProcAddress("glProgramUniform1fvEXT");
	if(!glProgramUniform1fvEXT) bIsLoaded = 0;
	glProgramUniform2fvEXT = (PFNGLPROGRAMUNIFORM2FVEXTPROC)gleIntGetProcAddress("glProgramUniform2fvEXT");
	if(!glProgramUniform2fvEXT) bIsLoaded = 0;
	glProgramUniform3fvEXT = (PFNGLPROGRAMUNIFORM3FVEXTPROC)gleIntGetProcAddress("glProgramUniform3fvEXT");
	if(!glProgramUniform3fvEXT) bIsLoaded = 0;
	glProgramUniform4fvEXT = (PFNGLPROGRAMUNIFORM4FVEXTPROC)gleIntGetProcAddress("glProgramUniform4fvEXT");
	if(!glProgramUniform4fvEXT) bIsLoaded = 0;
	glProgramUniform1ivEXT = (PFNGLPROGRAMUNIFORM1IVEXTPROC)gleIntGetProcAddress("glProgramUniform1ivEXT");
	if(!glProgramUniform1ivEXT) bIsLoaded = 0;
	glProgramUniform2ivEXT = (PFNGLPROGRAMUNIFORM2IVEXTPROC)gleIntGetProcAddress("glProgramUniform2ivEXT");
	if(!glProgramUniform2ivEXT) bIsLoaded = 0;
	glProgramUniform3ivEXT = (PFNGLPROGRAMUNIFORM3IVEXTPROC)gleIntGetProcAddress("glProgramUniform3ivEXT");
	if(!glProgramUniform3ivEXT) bIsLoaded = 0;
	glProgramUniform4ivEXT = (PFNGLPROGRAMUNIFORM4IVEXTPROC)gleIntGetProcAddress("glProgramUniform4ivEXT");
	if(!glProgramUniform4ivEXT) bIsLoaded = 0;
	glProgramUniformMatrix2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2fvEXT");
	if(!glProgramUniformMatrix2fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3fvEXT");
	if(!glProgramUniformMatrix3fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4fvEXT");
	if(!glProgramUniformMatrix4fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix2x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3fvEXT");
	if(!glProgramUniformMatrix2x3fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2fvEXT");
	if(!glProgramUniformMatrix3x2fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix2x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4fvEXT");
	if(!glProgramUniformMatrix2x4fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2fvEXT");
	if(!glProgramUniformMatrix4x2fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4fvEXT");
	if(!glProgramUniformMatrix3x4fvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3fvEXT");
	if(!glProgramUniformMatrix4x3fvEXT) bIsLoaded = 0;
	glProgramUniform1uiEXT = (PFNGLPROGRAMUNIFORM1UIEXTPROC)gleIntGetProcAddress("glProgramUniform1uiEXT");
	if(!glProgramUniform1uiEXT) bIsLoaded = 0;
	glProgramUniform2uiEXT = (PFNGLPROGRAMUNIFORM2UIEXTPROC)gleIntGetProcAddress("glProgramUniform2uiEXT");
	if(!glProgramUniform2uiEXT) bIsLoaded = 0;
	glProgramUniform3uiEXT = (PFNGLPROGRAMUNIFORM3UIEXTPROC)gleIntGetProcAddress("glProgramUniform3uiEXT");
	if(!glProgramUniform3uiEXT) bIsLoaded = 0;
	glProgramUniform4uiEXT = (PFNGLPROGRAMUNIFORM4UIEXTPROC)gleIntGetProcAddress("glProgramUniform4uiEXT");
	if(!glProgramUniform4uiEXT) bIsLoaded = 0;
	glProgramUniform1uivEXT = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)gleIntGetProcAddress("glProgramUniform1uivEXT");
	if(!glProgramUniform1uivEXT) bIsLoaded = 0;
	glProgramUniform2uivEXT = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)gleIntGetProcAddress("glProgramUniform2uivEXT");
	if(!glProgramUniform2uivEXT) bIsLoaded = 0;
	glProgramUniform3uivEXT = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)gleIntGetProcAddress("glProgramUniform3uivEXT");
	if(!glProgramUniform3uivEXT) bIsLoaded = 0;
	glProgramUniform4uivEXT = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)gleIntGetProcAddress("glProgramUniform4uivEXT");
	if(!glProgramUniform4uivEXT) bIsLoaded = 0;
	glNamedBufferDataEXT = (PFNGLNAMEDBUFFERDATAEXTPROC)gleIntGetProcAddress("glNamedBufferDataEXT");
	if(!glNamedBufferDataEXT) bIsLoaded = 0;
	glNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)gleIntGetProcAddress("glNamedBufferSubDataEXT");
	if(!glNamedBufferSubDataEXT) bIsLoaded = 0;
	glMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXTPROC)gleIntGetProcAddress("glMapNamedBufferEXT");
	if(!glMapNamedBufferEXT) bIsLoaded = 0;
	glUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXTPROC)gleIntGetProcAddress("glUnmapNamedBufferEXT");
	if(!glUnmapNamedBufferEXT) bIsLoaded = 0;
	glMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)gleIntGetProcAddress("glMapNamedBufferRangeEXT");
	if(!glMapNamedBufferRangeEXT) bIsLoaded = 0;
	glFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)gleIntGetProcAddress("glFlushMappedNamedBufferRangeEXT");
	if(!glFlushMappedNamedBufferRangeEXT) bIsLoaded = 0;
	glNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)gleIntGetProcAddress("glNamedCopyBufferSubDataEXT");
	if(!glNamedCopyBufferSubDataEXT) bIsLoaded = 0;
	glGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetNamedBufferParameterivEXT");
	if(!glGetNamedBufferParameterivEXT) bIsLoaded = 0;
	glGetNamedBufferPointervEXT = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)gleIntGetProcAddress("glGetNamedBufferPointervEXT");
	if(!glGetNamedBufferPointervEXT) bIsLoaded = 0;
	glGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)gleIntGetProcAddress("glGetNamedBufferSubDataEXT");
	if(!glGetNamedBufferSubDataEXT) bIsLoaded = 0;
	glTextureBufferEXT = (PFNGLTEXTUREBUFFEREXTPROC)gleIntGetProcAddress("glTextureBufferEXT");
	if(!glTextureBufferEXT) bIsLoaded = 0;
	glMultiTexBufferEXT = (PFNGLMULTITEXBUFFEREXTPROC)gleIntGetProcAddress("glMultiTexBufferEXT");
	if(!glMultiTexBufferEXT) bIsLoaded = 0;
	glNamedRenderbufferStorageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)gleIntGetProcAddress("glNamedRenderbufferStorageEXT");
	if(!glNamedRenderbufferStorageEXT) bIsLoaded = 0;
	glGetNamedRenderbufferParameterivEXT = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetNamedRenderbufferParameterivEXT");
	if(!glGetNamedRenderbufferParameterivEXT) bIsLoaded = 0;
	glCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)gleIntGetProcAddress("glCheckNamedFramebufferStatusEXT");
	if(!glCheckNamedFramebufferStatusEXT) bIsLoaded = 0;
	glNamedFramebufferTexture1DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)gleIntGetProcAddress("glNamedFramebufferTexture1DEXT");
	if(!glNamedFramebufferTexture1DEXT) bIsLoaded = 0;
	glNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)gleIntGetProcAddress("glNamedFramebufferTexture2DEXT");
	if(!glNamedFramebufferTexture2DEXT) bIsLoaded = 0;
	glNamedFramebufferTexture3DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)gleIntGetProcAddress("glNamedFramebufferTexture3DEXT");
	if(!glNamedFramebufferTexture3DEXT) bIsLoaded = 0;
	glNamedFramebufferRenderbufferEXT = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)gleIntGetProcAddress("glNamedFramebufferRenderbufferEXT");
	if(!glNamedFramebufferRenderbufferEXT) bIsLoaded = 0;
	glGetNamedFramebufferAttachmentParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
	if(!glGetNamedFramebufferAttachmentParameterivEXT) bIsLoaded = 0;
	glGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)gleIntGetProcAddress("glGenerateTextureMipmapEXT");
	if(!glGenerateTextureMipmapEXT) bIsLoaded = 0;
	glGenerateMultiTexMipmapEXT = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC)gleIntGetProcAddress("glGenerateMultiTexMipmapEXT");
	if(!glGenerateMultiTexMipmapEXT) bIsLoaded = 0;
	glFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)gleIntGetProcAddress("glFramebufferDrawBufferEXT");
	if(!glFramebufferDrawBufferEXT) bIsLoaded = 0;
	glFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)gleIntGetProcAddress("glFramebufferDrawBuffersEXT");
	if(!glFramebufferDrawBuffersEXT) bIsLoaded = 0;
	glFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)gleIntGetProcAddress("glFramebufferReadBufferEXT");
	if(!glFramebufferReadBufferEXT) bIsLoaded = 0;
	glGetFramebufferParameterivEXT = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetFramebufferParameterivEXT");
	if(!glGetFramebufferParameterivEXT) bIsLoaded = 0;
	glNamedRenderbufferStorageMultisampleEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)gleIntGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
	if(!glNamedRenderbufferStorageMultisampleEXT) bIsLoaded = 0;
	glNamedRenderbufferStorageMultisampleCoverageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)gleIntGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
	if(!glNamedRenderbufferStorageMultisampleCoverageEXT) bIsLoaded = 0;
	glNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)gleIntGetProcAddress("glNamedFramebufferTextureEXT");
	if(!glNamedFramebufferTextureEXT) bIsLoaded = 0;
	glNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)gleIntGetProcAddress("glNamedFramebufferTextureLayerEXT");
	if(!glNamedFramebufferTextureLayerEXT) bIsLoaded = 0;
	glNamedFramebufferTextureFaceEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)gleIntGetProcAddress("glNamedFramebufferTextureFaceEXT");
	if(!glNamedFramebufferTextureFaceEXT) bIsLoaded = 0;
	glTextureRenderbufferEXT = (PFNGLTEXTURERENDERBUFFEREXTPROC)gleIntGetProcAddress("glTextureRenderbufferEXT");
	if(!glTextureRenderbufferEXT) bIsLoaded = 0;
	glMultiTexRenderbufferEXT = (PFNGLMULTITEXRENDERBUFFEREXTPROC)gleIntGetProcAddress("glMultiTexRenderbufferEXT");
	if(!glMultiTexRenderbufferEXT) bIsLoaded = 0;
	glProgramUniform1dEXT = (PFNGLPROGRAMUNIFORM1DEXTPROC)gleIntGetProcAddress("glProgramUniform1dEXT");
	if(!glProgramUniform1dEXT) bIsLoaded = 0;
	glProgramUniform2dEXT = (PFNGLPROGRAMUNIFORM2DEXTPROC)gleIntGetProcAddress("glProgramUniform2dEXT");
	if(!glProgramUniform2dEXT) bIsLoaded = 0;
	glProgramUniform3dEXT = (PFNGLPROGRAMUNIFORM3DEXTPROC)gleIntGetProcAddress("glProgramUniform3dEXT");
	if(!glProgramUniform3dEXT) bIsLoaded = 0;
	glProgramUniform4dEXT = (PFNGLPROGRAMUNIFORM4DEXTPROC)gleIntGetProcAddress("glProgramUniform4dEXT");
	if(!glProgramUniform4dEXT) bIsLoaded = 0;
	glProgramUniform1dvEXT = (PFNGLPROGRAMUNIFORM1DVEXTPROC)gleIntGetProcAddress("glProgramUniform1dvEXT");
	if(!glProgramUniform1dvEXT) bIsLoaded = 0;
	glProgramUniform2dvEXT = (PFNGLPROGRAMUNIFORM2DVEXTPROC)gleIntGetProcAddress("glProgramUniform2dvEXT");
	if(!glProgramUniform2dvEXT) bIsLoaded = 0;
	glProgramUniform3dvEXT = (PFNGLPROGRAMUNIFORM3DVEXTPROC)gleIntGetProcAddress("glProgramUniform3dvEXT");
	if(!glProgramUniform3dvEXT) bIsLoaded = 0;
	glProgramUniform4dvEXT = (PFNGLPROGRAMUNIFORM4DVEXTPROC)gleIntGetProcAddress("glProgramUniform4dvEXT");
	if(!glProgramUniform4dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2dvEXT");
	if(!glProgramUniformMatrix2dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3dvEXT");
	if(!glProgramUniformMatrix3dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4dvEXT");
	if(!glProgramUniformMatrix4dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix2x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3dvEXT");
	if(!glProgramUniformMatrix2x3dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix2x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4dvEXT");
	if(!glProgramUniformMatrix2x4dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2dvEXT");
	if(!glProgramUniformMatrix3x2dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix3x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4dvEXT");
	if(!glProgramUniformMatrix3x4dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2dvEXT");
	if(!glProgramUniformMatrix4x2dvEXT) bIsLoaded = 0;
	glProgramUniformMatrix4x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3dvEXT");
	if(!glProgramUniformMatrix4x3dvEXT) bIsLoaded = 0;
	glEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)gleIntGetProcAddress("glEnableVertexArrayAttribEXT");
	if(!glEnableVertexArrayAttribEXT) bIsLoaded = 0;
	glDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)gleIntGetProcAddress("glDisableVertexArrayAttribEXT");
	if(!glDisableVertexArrayAttribEXT) bIsLoaded = 0;
	glEnableVertexArrayEXT = (PFNGLENABLEVERTEXARRAYEXTPROC)gleIntGetProcAddress("glEnableVertexArrayEXT");
	if(!glEnableVertexArrayEXT) bIsLoaded = 0;
	glDisableVertexArrayEXT = (PFNGLDISABLEVERTEXARRAYEXTPROC)gleIntGetProcAddress("glDisableVertexArrayEXT");
	if(!glDisableVertexArrayEXT) bIsLoaded = 0;
	glVertexArrayColorOffsetEXT = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayColorOffsetEXT");
	if(!glVertexArrayColorOffsetEXT) bIsLoaded = 0;
	glVertexArrayEdgeFlagOffsetEXT = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayEdgeFlagOffsetEXT");
	if(!glVertexArrayEdgeFlagOffsetEXT) bIsLoaded = 0;
	glVertexArrayFogCoordOffsetEXT = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayFogCoordOffsetEXT");
	if(!glVertexArrayFogCoordOffsetEXT) bIsLoaded = 0;
	glVertexArrayIndexOffsetEXT = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayIndexOffsetEXT");
	if(!glVertexArrayIndexOffsetEXT) bIsLoaded = 0;
	glVertexArrayMultiTexCoordOffsetEXT = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayMultiTexCoordOffsetEXT");
	if(!glVertexArrayMultiTexCoordOffsetEXT) bIsLoaded = 0;
	glVertexArrayNormalOffsetEXT = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayNormalOffsetEXT");
	if(!glVertexArrayNormalOffsetEXT) bIsLoaded = 0;
	glVertexArraySecondaryColorOffsetEXT = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)gleIntGetProcAddress("glVertexArraySecondaryColorOffsetEXT");
	if(!glVertexArraySecondaryColorOffsetEXT) bIsLoaded = 0;
	glVertexArrayTexCoordOffsetEXT = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayTexCoordOffsetEXT");
	if(!glVertexArrayTexCoordOffsetEXT) bIsLoaded = 0;
	glVertexArrayVertexOffsetEXT = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayVertexOffsetEXT");
	if(!glVertexArrayVertexOffsetEXT) bIsLoaded = 0;
	glVertexArrayVertexAttribIOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
	if(!glVertexArrayVertexAttribIOffsetEXT) bIsLoaded = 0;
	glglVertexArrayVertexAttribOffsetEXT = (PFNGLGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)gleIntGetProcAddress("glglVertexArrayVertexAttribOffsetEXT");
	if(!glglVertexArrayVertexAttribOffsetEXT) bIsLoaded = 0;
	glGetVertexArrayIntegervEXT = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)gleIntGetProcAddress("glGetVertexArrayIntegervEXT");
	if(!glGetVertexArrayIntegervEXT) bIsLoaded = 0;
	glGetVertexArrayPointervEXT = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)gleIntGetProcAddress("glGetVertexArrayPointervEXT");
	if(!glGetVertexArrayPointervEXT) bIsLoaded = 0;
	glGetVertexArrayIntegeri_vEXT = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)gleIntGetProcAddress("glGetVertexArrayIntegeri_vEXT");
	if(!glGetVertexArrayIntegeri_vEXT) bIsLoaded = 0;
	glGetVertexArrayPointeri_vEXT = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)gleIntGetProcAddress("glGetVertexArrayPointeri_vEXT");
	if(!glGetVertexArrayPointeri_vEXT) bIsLoaded = 0;
#endif /*GL_EXT_direct_state_access*/
	return bIsLoaded;
}
#ifndef GL_EXT_draw_buffers2
typedef void (GLE_FUNCPTR * PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum , GLuint , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLENABLEINDEXEDEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEINDEXEDEXTPROC)(GLenum , GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDINDEXEDEXTPROC)(GLenum , GLuint );

PFNGLCOLORMASKINDEXEDEXTPROC glColorMaskIndexedEXT;
PFNGLGETBOOLEANINDEXEDVEXTPROC glGetBooleanIndexedvEXT;
PFNGLGETINTEGERINDEXEDVEXTPROC glGetIntegerIndexedvEXT;
PFNGLENABLEINDEXEDEXTPROC glEnableIndexedEXT;
PFNGLDISABLEINDEXEDEXTPROC glDisableIndexedEXT;
PFNGLISENABLEDINDEXEDEXTPROC glIsEnabledIndexedEXT;
#endif /*GL_EXT_draw_buffers2*/

static int gleIntLoad_EXT_draw_buffers2()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_draw_buffers2
	glColorMaskIndexedEXT = (PFNGLCOLORMASKINDEXEDEXTPROC)gleIntGetProcAddress("glColorMaskIndexedEXT");
	if(!glColorMaskIndexedEXT) bIsLoaded = 0;
	glGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC)gleIntGetProcAddress("glGetBooleanIndexedvEXT");
	if(!glGetBooleanIndexedvEXT) bIsLoaded = 0;
	glGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC)gleIntGetProcAddress("glGetIntegerIndexedvEXT");
	if(!glGetIntegerIndexedvEXT) bIsLoaded = 0;
	glEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC)gleIntGetProcAddress("glEnableIndexedEXT");
	if(!glEnableIndexedEXT) bIsLoaded = 0;
	glDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC)gleIntGetProcAddress("glDisableIndexedEXT");
	if(!glDisableIndexedEXT) bIsLoaded = 0;
	glIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXTPROC)gleIntGetProcAddress("glIsEnabledIndexedEXT");
	if(!glIsEnabledIndexedEXT) bIsLoaded = 0;
#endif /*GL_EXT_draw_buffers2*/
	return bIsLoaded;
}
#ifndef GL_EXT_draw_instanced
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );

PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXT;
PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXT;
#endif /*GL_EXT_draw_instanced*/

static int gleIntLoad_EXT_draw_instanced()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_draw_instanced
	glDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)gleIntGetProcAddress("glDrawArraysInstancedEXT");
	if(!glDrawArraysInstancedEXT) bIsLoaded = 0;
	glDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)gleIntGetProcAddress("glDrawElementsInstancedEXT");
	if(!glDrawElementsInstancedEXT) bIsLoaded = 0;
#endif /*GL_EXT_draw_instanced*/
	return bIsLoaded;
}
#ifndef GL_EXT_draw_range_elements
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *);

PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXT;
#endif /*GL_EXT_draw_range_elements*/

static int gleIntLoad_EXT_draw_range_elements()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_draw_range_elements
	glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC)gleIntGetProcAddress("glDrawRangeElementsEXT");
	if(!glDrawRangeElementsEXT) bIsLoaded = 0;
#endif /*GL_EXT_draw_range_elements*/
	return bIsLoaded;
}
#ifndef GL_EXT_fog_coord
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFEXTPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDEXTPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDVEXTPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTEREXTPROC)(GLenum , GLsizei , const GLvoid *);

PFNGLFOGCOORDFEXTPROC glFogCoordfEXT;
PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT;
PFNGLFOGCOORDDEXTPROC glFogCoorddEXT;
PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT;
PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXT;
#endif /*GL_EXT_fog_coord*/

static int gleIntLoad_EXT_fog_coord()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_fog_coord
	glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)gleIntGetProcAddress("glFogCoordfEXT");
	if(!glFogCoordfEXT) bIsLoaded = 0;
	glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)gleIntGetProcAddress("glFogCoordfvEXT");
	if(!glFogCoordfvEXT) bIsLoaded = 0;
	glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)gleIntGetProcAddress("glFogCoorddEXT");
	if(!glFogCoorddEXT) bIsLoaded = 0;
	glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)gleIntGetProcAddress("glFogCoorddvEXT");
	if(!glFogCoorddvEXT) bIsLoaded = 0;
	glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)gleIntGetProcAddress("glFogCoordPointerEXT");
	if(!glFogCoordPointerEXT) bIsLoaded = 0;
#endif /*GL_EXT_fog_coord*/
	return bIsLoaded;
}
#ifndef GL_EXT_framebuffer_blit
typedef void (GLE_FUNCPTR * PFNGLBLITFRAMEBUFFEREXTPROC)(GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );

PFNGLBLITFRAMEBUFFEREXTPROC glBlitFramebufferEXT;
#endif /*GL_EXT_framebuffer_blit*/

static int gleIntLoad_EXT_framebuffer_blit()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_framebuffer_blit
	glBlitFramebufferEXT = (PFNGLBLITFRAMEBUFFEREXTPROC)gleIntGetProcAddress("glBlitFramebufferEXT");
	if(!glBlitFramebufferEXT) bIsLoaded = 0;
#endif /*GL_EXT_framebuffer_blit*/
	return bIsLoaded;
}
#ifndef GL_EXT_framebuffer_multisample
typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei );

PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glRenderbufferStorageMultisampleEXT;
#endif /*GL_EXT_framebuffer_multisample*/

static int gleIntLoad_EXT_framebuffer_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_framebuffer_multisample
	glRenderbufferStorageMultisampleEXT = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)gleIntGetProcAddress("glRenderbufferStorageMultisampleEXT");
	if(!glRenderbufferStorageMultisampleEXT) bIsLoaded = 0;
#endif /*GL_EXT_framebuffer_multisample*/
	return bIsLoaded;
}

#ifndef GL_EXT_framebuffer_object
typedef GLboolean (GLE_FUNCPTR * PFNGLISRENDERBUFFEREXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDRENDERBUFFEREXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETERENDERBUFFERSEXTPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENRENDERBUFFERSEXTPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEEXTPROC)(GLenum , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISFRAMEBUFFEREXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDFRAMEBUFFEREXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEFRAMEBUFFERSEXTPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENFRAMEBUFFERSEXTPROC)(GLsizei , GLuint *);
typedef GLenum (GLE_FUNCPTR * PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)(GLenum , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)(GLenum , GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)(GLenum , GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)(GLenum , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGENERATEMIPMAPEXTPROC)(GLenum );

PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXT;
PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT;
PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT;
PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;
PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXT;
PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXT;
PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXT;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXT;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXT;
PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXT;
#endif /*GL_EXT_framebuffer_object*/

static int gleIntLoad_EXT_framebuffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_framebuffer_object
	glIsRenderbufferEXT = (PFNGLISRENDERBUFFEREXTPROC)gleIntGetProcAddress("glIsRenderbufferEXT");
	if(!glIsRenderbufferEXT) bIsLoaded = 0;
	glBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC)gleIntGetProcAddress("glBindRenderbufferEXT");
	if(!glBindRenderbufferEXT) bIsLoaded = 0;
	glDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC)gleIntGetProcAddress("glDeleteRenderbuffersEXT");
	if(!glDeleteRenderbuffersEXT) bIsLoaded = 0;
	glGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC)gleIntGetProcAddress("glGenRenderbuffersEXT");
	if(!glGenRenderbuffersEXT) bIsLoaded = 0;
	glRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC)gleIntGetProcAddress("glRenderbufferStorageEXT");
	if(!glRenderbufferStorageEXT) bIsLoaded = 0;
	glGetRenderbufferParameterivEXT = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetRenderbufferParameterivEXT");
	if(!glGetRenderbufferParameterivEXT) bIsLoaded = 0;
	glIsFramebufferEXT = (PFNGLISFRAMEBUFFEREXTPROC)gleIntGetProcAddress("glIsFramebufferEXT");
	if(!glIsFramebufferEXT) bIsLoaded = 0;
	glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)gleIntGetProcAddress("glBindFramebufferEXT");
	if(!glBindFramebufferEXT) bIsLoaded = 0;
	glDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC)gleIntGetProcAddress("glDeleteFramebuffersEXT");
	if(!glDeleteFramebuffersEXT) bIsLoaded = 0;
	glGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC)gleIntGetProcAddress("glGenFramebuffersEXT");
	if(!glGenFramebuffersEXT) bIsLoaded = 0;
	glCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)gleIntGetProcAddress("glCheckFramebufferStatusEXT");
	if(!glCheckFramebufferStatusEXT) bIsLoaded = 0;
	glFramebufferTexture1DEXT = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)gleIntGetProcAddress("glFramebufferTexture1DEXT");
	if(!glFramebufferTexture1DEXT) bIsLoaded = 0;
	glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)gleIntGetProcAddress("glFramebufferTexture2DEXT");
	if(!glFramebufferTexture2DEXT) bIsLoaded = 0;
	glFramebufferTexture3DEXT = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)gleIntGetProcAddress("glFramebufferTexture3DEXT");
	if(!glFramebufferTexture3DEXT) bIsLoaded = 0;
	glFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)gleIntGetProcAddress("glFramebufferRenderbufferEXT");
	if(!glFramebufferRenderbufferEXT) bIsLoaded = 0;
	glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetFramebufferAttachmentParameterivEXT");
	if(!glGetFramebufferAttachmentParameterivEXT) bIsLoaded = 0;
	glGenerateMipmapEXT = (PFNGLGENERATEMIPMAPEXTPROC)gleIntGetProcAddress("glGenerateMipmapEXT");
	if(!glGenerateMipmapEXT) bIsLoaded = 0;
#endif /*GL_EXT_framebuffer_object*/
	return bIsLoaded;
}

#ifndef GL_EXT_geometry_shader4
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint , GLenum , GLint );

PFNGLPROGRAMPARAMETERIEXTPROC glProgramParameteriEXT;
#endif /*GL_EXT_geometry_shader4*/

static int gleIntLoad_EXT_geometry_shader4()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_geometry_shader4
	glProgramParameteriEXT = (PFNGLPROGRAMPARAMETERIEXTPROC)gleIntGetProcAddress("glProgramParameteriEXT");
	if(!glProgramParameteriEXT) bIsLoaded = 0;
#endif /*GL_EXT_geometry_shader4*/
	return bIsLoaded;
}
#ifndef GL_EXT_gpu_program_parameters
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum , GLuint , GLsizei , const GLfloat *);

PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glProgramEnvParameters4fvEXT;
PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glProgramLocalParameters4fvEXT;
#endif /*GL_EXT_gpu_program_parameters*/

static int gleIntLoad_EXT_gpu_program_parameters()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_gpu_program_parameters
	glProgramEnvParameters4fvEXT = (PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)gleIntGetProcAddress("glProgramEnvParameters4fvEXT");
	if(!glProgramEnvParameters4fvEXT) bIsLoaded = 0;
	glProgramLocalParameters4fvEXT = (PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)gleIntGetProcAddress("glProgramLocalParameters4fvEXT");
	if(!glProgramLocalParameters4fvEXT) bIsLoaded = 0;
#endif /*GL_EXT_gpu_program_parameters*/
	return bIsLoaded;
}
#ifndef GL_EXT_gpu_shader4
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMUIVEXTPROC)(GLuint , GLint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLBINDFRAGDATALOCATIONEXTPROC)(GLuint , GLuint , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETFRAGDATALOCATIONEXTPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIEXTPROC)(GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIEXTPROC)(GLint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIEXTPROC)(GLint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIEXTPROC)(GLint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIVEXTPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIVEXTPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIVEXTPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIVEXTPROC)(GLint , GLsizei , const GLuint *);

PFNGLGETUNIFORMUIVEXTPROC glGetUniformuivEXT;
PFNGLBINDFRAGDATALOCATIONEXTPROC glBindFragDataLocationEXT;
PFNGLGETFRAGDATALOCATIONEXTPROC glGetFragDataLocationEXT;
PFNGLUNIFORM1UIEXTPROC glUniform1uiEXT;
PFNGLUNIFORM2UIEXTPROC glUniform2uiEXT;
PFNGLUNIFORM3UIEXTPROC glUniform3uiEXT;
PFNGLUNIFORM4UIEXTPROC glUniform4uiEXT;
PFNGLUNIFORM1UIVEXTPROC glUniform1uivEXT;
PFNGLUNIFORM2UIVEXTPROC glUniform2uivEXT;
PFNGLUNIFORM3UIVEXTPROC glUniform3uivEXT;
PFNGLUNIFORM4UIVEXTPROC glUniform4uivEXT;
#endif /*GL_EXT_gpu_shader4*/

static int gleIntLoad_EXT_gpu_shader4()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_gpu_shader4
	glGetUniformuivEXT = (PFNGLGETUNIFORMUIVEXTPROC)gleIntGetProcAddress("glGetUniformuivEXT");
	if(!glGetUniformuivEXT) bIsLoaded = 0;
	glBindFragDataLocationEXT = (PFNGLBINDFRAGDATALOCATIONEXTPROC)gleIntGetProcAddress("glBindFragDataLocationEXT");
	if(!glBindFragDataLocationEXT) bIsLoaded = 0;
	glGetFragDataLocationEXT = (PFNGLGETFRAGDATALOCATIONEXTPROC)gleIntGetProcAddress("glGetFragDataLocationEXT");
	if(!glGetFragDataLocationEXT) bIsLoaded = 0;
	glUniform1uiEXT = (PFNGLUNIFORM1UIEXTPROC)gleIntGetProcAddress("glUniform1uiEXT");
	if(!glUniform1uiEXT) bIsLoaded = 0;
	glUniform2uiEXT = (PFNGLUNIFORM2UIEXTPROC)gleIntGetProcAddress("glUniform2uiEXT");
	if(!glUniform2uiEXT) bIsLoaded = 0;
	glUniform3uiEXT = (PFNGLUNIFORM3UIEXTPROC)gleIntGetProcAddress("glUniform3uiEXT");
	if(!glUniform3uiEXT) bIsLoaded = 0;
	glUniform4uiEXT = (PFNGLUNIFORM4UIEXTPROC)gleIntGetProcAddress("glUniform4uiEXT");
	if(!glUniform4uiEXT) bIsLoaded = 0;
	glUniform1uivEXT = (PFNGLUNIFORM1UIVEXTPROC)gleIntGetProcAddress("glUniform1uivEXT");
	if(!glUniform1uivEXT) bIsLoaded = 0;
	glUniform2uivEXT = (PFNGLUNIFORM2UIVEXTPROC)gleIntGetProcAddress("glUniform2uivEXT");
	if(!glUniform2uivEXT) bIsLoaded = 0;
	glUniform3uivEXT = (PFNGLUNIFORM3UIVEXTPROC)gleIntGetProcAddress("glUniform3uivEXT");
	if(!glUniform3uivEXT) bIsLoaded = 0;
	glUniform4uivEXT = (PFNGLUNIFORM4UIVEXTPROC)gleIntGetProcAddress("glUniform4uivEXT");
	if(!glUniform4uivEXT) bIsLoaded = 0;
#endif /*GL_EXT_gpu_shader4*/
	return bIsLoaded;
}
#ifndef GL_EXT_histogram
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMEXTPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXEXTPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLHISTOGRAMEXTPROC)(GLenum , GLsizei , GLenum , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLMINMAXEXTPROC)(GLenum , GLenum , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLRESETHISTOGRAMEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLRESETMINMAXEXTPROC)(GLenum );

PFNGLGETHISTOGRAMEXTPROC glGetHistogramEXT;
PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glGetHistogramParameterfvEXT;
PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glGetHistogramParameterivEXT;
PFNGLGETMINMAXEXTPROC glGetMinmaxEXT;
PFNGLGETMINMAXPARAMETERFVEXTPROC glGetMinmaxParameterfvEXT;
PFNGLGETMINMAXPARAMETERIVEXTPROC glGetMinmaxParameterivEXT;
PFNGLHISTOGRAMEXTPROC glHistogramEXT;
PFNGLMINMAXEXTPROC glMinmaxEXT;
PFNGLRESETHISTOGRAMEXTPROC glResetHistogramEXT;
PFNGLRESETMINMAXEXTPROC glResetMinmaxEXT;
#endif /*GL_EXT_histogram*/

static int gleIntLoad_EXT_histogram()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_histogram
	glGetHistogramEXT = (PFNGLGETHISTOGRAMEXTPROC)gleIntGetProcAddress("glGetHistogramEXT");
	if(!glGetHistogramEXT) bIsLoaded = 0;
	glGetHistogramParameterfvEXT = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetHistogramParameterfvEXT");
	if(!glGetHistogramParameterfvEXT) bIsLoaded = 0;
	glGetHistogramParameterivEXT = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetHistogramParameterivEXT");
	if(!glGetHistogramParameterivEXT) bIsLoaded = 0;
	glGetMinmaxEXT = (PFNGLGETMINMAXEXTPROC)gleIntGetProcAddress("glGetMinmaxEXT");
	if(!glGetMinmaxEXT) bIsLoaded = 0;
	glGetMinmaxParameterfvEXT = (PFNGLGETMINMAXPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetMinmaxParameterfvEXT");
	if(!glGetMinmaxParameterfvEXT) bIsLoaded = 0;
	glGetMinmaxParameterivEXT = (PFNGLGETMINMAXPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetMinmaxParameterivEXT");
	if(!glGetMinmaxParameterivEXT) bIsLoaded = 0;
	glHistogramEXT = (PFNGLHISTOGRAMEXTPROC)gleIntGetProcAddress("glHistogramEXT");
	if(!glHistogramEXT) bIsLoaded = 0;
	glMinmaxEXT = (PFNGLMINMAXEXTPROC)gleIntGetProcAddress("glMinmaxEXT");
	if(!glMinmaxEXT) bIsLoaded = 0;
	glResetHistogramEXT = (PFNGLRESETHISTOGRAMEXTPROC)gleIntGetProcAddress("glResetHistogramEXT");
	if(!glResetHistogramEXT) bIsLoaded = 0;
	glResetMinmaxEXT = (PFNGLRESETMINMAXEXTPROC)gleIntGetProcAddress("glResetMinmaxEXT");
	if(!glResetMinmaxEXT) bIsLoaded = 0;
#endif /*GL_EXT_histogram*/
	return bIsLoaded;
}

#ifndef GL_EXT_index_func
typedef void (GLE_FUNCPTR * PFNGLINDEXFUNCEXTPROC)(GLenum , GLclampf );

PFNGLINDEXFUNCEXTPROC glIndexFuncEXT;
#endif /*GL_EXT_index_func*/

static int gleIntLoad_EXT_index_func()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_index_func
	glIndexFuncEXT = (PFNGLINDEXFUNCEXTPROC)gleIntGetProcAddress("glIndexFuncEXT");
	if(!glIndexFuncEXT) bIsLoaded = 0;
#endif /*GL_EXT_index_func*/
	return bIsLoaded;
}
#ifndef GL_EXT_index_material
typedef void (GLE_FUNCPTR * PFNGLINDEXMATERIALEXTPROC)(GLenum , GLenum );

PFNGLINDEXMATERIALEXTPROC glIndexMaterialEXT;
#endif /*GL_EXT_index_material*/

static int gleIntLoad_EXT_index_material()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_index_material
	glIndexMaterialEXT = (PFNGLINDEXMATERIALEXTPROC)gleIntGetProcAddress("glIndexMaterialEXT");
	if(!glIndexMaterialEXT) bIsLoaded = 0;
#endif /*GL_EXT_index_material*/
	return bIsLoaded;
}

#ifndef GL_EXT_light_texture
typedef void (GLE_FUNCPTR * PFNGLAPPLYTEXTUREEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXTURELIGHTEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREMATERIALEXTPROC)(GLenum , GLenum );

PFNGLAPPLYTEXTUREEXTPROC glApplyTextureEXT;
PFNGLTEXTURELIGHTEXTPROC glTextureLightEXT;
PFNGLTEXTUREMATERIALEXTPROC glTextureMaterialEXT;
#endif /*GL_EXT_light_texture*/

static int gleIntLoad_EXT_light_texture()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_light_texture
	glApplyTextureEXT = (PFNGLAPPLYTEXTUREEXTPROC)gleIntGetProcAddress("glApplyTextureEXT");
	if(!glApplyTextureEXT) bIsLoaded = 0;
	glTextureLightEXT = (PFNGLTEXTURELIGHTEXTPROC)gleIntGetProcAddress("glTextureLightEXT");
	if(!glTextureLightEXT) bIsLoaded = 0;
	glTextureMaterialEXT = (PFNGLTEXTUREMATERIALEXTPROC)gleIntGetProcAddress("glTextureMaterialEXT");
	if(!glTextureMaterialEXT) bIsLoaded = 0;
#endif /*GL_EXT_light_texture*/
	return bIsLoaded;
}

#ifndef GL_EXT_multi_draw_arrays
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* *, GLsizei );

PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT;
#endif /*GL_EXT_multi_draw_arrays*/

static int gleIntLoad_EXT_multi_draw_arrays()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_multi_draw_arrays
	glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC)gleIntGetProcAddress("glMultiDrawArraysEXT");
	if(!glMultiDrawArraysEXT) bIsLoaded = 0;
	glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC)gleIntGetProcAddress("glMultiDrawElementsEXT");
	if(!glMultiDrawElementsEXT) bIsLoaded = 0;
#endif /*GL_EXT_multi_draw_arrays*/
	return bIsLoaded;
}
#ifndef GL_EXT_multisample
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKEXTPROC)(GLclampf , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLSAMPLEPATTERNEXTPROC)(GLenum );

PFNGLSAMPLEMASKEXTPROC glSampleMaskEXT;
PFNGLSAMPLEPATTERNEXTPROC glSamplePatternEXT;
#endif /*GL_EXT_multisample*/

static int gleIntLoad_EXT_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_multisample
	glSampleMaskEXT = (PFNGLSAMPLEMASKEXTPROC)gleIntGetProcAddress("glSampleMaskEXT");
	if(!glSampleMaskEXT) bIsLoaded = 0;
	glSamplePatternEXT = (PFNGLSAMPLEPATTERNEXTPROC)gleIntGetProcAddress("glSamplePatternEXT");
	if(!glSamplePatternEXT) bIsLoaded = 0;
#endif /*GL_EXT_multisample*/
	return bIsLoaded;
}



#ifndef GL_EXT_paletted_texture
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEEXTPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEEXTPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);

PFNGLCOLORTABLEEXTPROC glColorTableEXT;
PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT;
PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glGetColorTableParameterivEXT;
PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glGetColorTableParameterfvEXT;
#endif /*GL_EXT_paletted_texture*/

static int gleIntLoad_EXT_paletted_texture()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_paletted_texture
	glColorTableEXT = (PFNGLCOLORTABLEEXTPROC)gleIntGetProcAddress("glColorTableEXT");
	if(!glColorTableEXT) bIsLoaded = 0;
	glGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC)gleIntGetProcAddress("glGetColorTableEXT");
	if(!glGetColorTableEXT) bIsLoaded = 0;
	glGetColorTableParameterivEXT = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetColorTableParameterivEXT");
	if(!glGetColorTableParameterivEXT) bIsLoaded = 0;
	glGetColorTableParameterfvEXT = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetColorTableParameterfvEXT");
	if(!glGetColorTableParameterfvEXT) bIsLoaded = 0;
#endif /*GL_EXT_paletted_texture*/
	return bIsLoaded;
}

#ifndef GL_EXT_pixel_transform
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);

PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glPixelTransformParameteriEXT;
PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glPixelTransformParameterfEXT;
PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glPixelTransformParameterivEXT;
PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glPixelTransformParameterfvEXT;
PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC glGetPixelTransformParameterivEXT;
PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC glGetPixelTransformParameterfvEXT;
#endif /*GL_EXT_pixel_transform*/

static int gleIntLoad_EXT_pixel_transform()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_pixel_transform
	glPixelTransformParameteriEXT = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)gleIntGetProcAddress("glPixelTransformParameteriEXT");
	if(!glPixelTransformParameteriEXT) bIsLoaded = 0;
	glPixelTransformParameterfEXT = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)gleIntGetProcAddress("glPixelTransformParameterfEXT");
	if(!glPixelTransformParameterfEXT) bIsLoaded = 0;
	glPixelTransformParameterivEXT = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)gleIntGetProcAddress("glPixelTransformParameterivEXT");
	if(!glPixelTransformParameterivEXT) bIsLoaded = 0;
	glPixelTransformParameterfvEXT = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)gleIntGetProcAddress("glPixelTransformParameterfvEXT");
	if(!glPixelTransformParameterfvEXT) bIsLoaded = 0;
	glGetPixelTransformParameterivEXT = (PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetPixelTransformParameterivEXT");
	if(!glGetPixelTransformParameterivEXT) bIsLoaded = 0;
	glGetPixelTransformParameterfvEXT = (PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)gleIntGetProcAddress("glGetPixelTransformParameterfvEXT");
	if(!glGetPixelTransformParameterfvEXT) bIsLoaded = 0;
#endif /*GL_EXT_pixel_transform*/
	return bIsLoaded;
}

#ifndef GL_EXT_point_parameters
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFEXTPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVEXTPROC)(GLenum , const GLfloat *);

PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXT;
PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXT;
#endif /*GL_EXT_point_parameters*/

static int gleIntLoad_EXT_point_parameters()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_point_parameters
	glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)gleIntGetProcAddress("glPointParameterfEXT");
	if(!glPointParameterfEXT) bIsLoaded = 0;
	glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)gleIntGetProcAddress("glPointParameterfvEXT");
	if(!glPointParameterfvEXT) bIsLoaded = 0;
#endif /*GL_EXT_point_parameters*/
	return bIsLoaded;
}
#ifndef GL_EXT_polygon_offset
typedef void (GLE_FUNCPTR * PFNGLPOLYGONOFFSETEXTPROC)(GLfloat , GLfloat );

PFNGLPOLYGONOFFSETEXTPROC glPolygonOffsetEXT;
#endif /*GL_EXT_polygon_offset*/

static int gleIntLoad_EXT_polygon_offset()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_polygon_offset
	glPolygonOffsetEXT = (PFNGLPOLYGONOFFSETEXTPROC)gleIntGetProcAddress("glPolygonOffsetEXT");
	if(!glPolygonOffsetEXT) bIsLoaded = 0;
#endif /*GL_EXT_polygon_offset*/
	return bIsLoaded;
}
#ifndef GL_EXT_provoking_vertex
typedef void (GLE_FUNCPTR * PFNGLPROVOKINGVERTEXEXTPROC)(GLenum );

PFNGLPROVOKINGVERTEXEXTPROC glProvokingVertexEXT;
#endif /*GL_EXT_provoking_vertex*/

static int gleIntLoad_EXT_provoking_vertex()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_provoking_vertex
	glProvokingVertexEXT = (PFNGLPROVOKINGVERTEXEXTPROC)gleIntGetProcAddress("glProvokingVertexEXT");
	if(!glProvokingVertexEXT) bIsLoaded = 0;
#endif /*GL_EXT_provoking_vertex*/
	return bIsLoaded;
}

#ifndef GL_EXT_secondary_color
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BEXTPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BVEXTPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DEXTPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DVEXTPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FEXTPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IEXTPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IVEXTPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SEXTPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SVEXTPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBEXTPROC)(GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBVEXTPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIEXTPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIVEXTPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USEXTPROC)(GLushort , GLushort , GLushort );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USVEXTPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORPOINTEREXTPROC)(GLint , GLenum , GLsizei , const GLvoid *);

PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXT;
PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXT;
PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXT;
PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXT;
PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXT;
PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXT;
PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXT;
PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXT;
PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXT;
PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXT;
PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXT;
PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXT;
PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXT;
PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXT;
PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXT;
PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXT;
PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXT;
#endif /*GL_EXT_secondary_color*/

static int gleIntLoad_EXT_secondary_color()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_secondary_color
	glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)gleIntGetProcAddress("glSecondaryColor3bEXT");
	if(!glSecondaryColor3bEXT) bIsLoaded = 0;
	glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)gleIntGetProcAddress("glSecondaryColor3bvEXT");
	if(!glSecondaryColor3bvEXT) bIsLoaded = 0;
	glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)gleIntGetProcAddress("glSecondaryColor3dEXT");
	if(!glSecondaryColor3dEXT) bIsLoaded = 0;
	glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)gleIntGetProcAddress("glSecondaryColor3dvEXT");
	if(!glSecondaryColor3dvEXT) bIsLoaded = 0;
	glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)gleIntGetProcAddress("glSecondaryColor3fEXT");
	if(!glSecondaryColor3fEXT) bIsLoaded = 0;
	glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)gleIntGetProcAddress("glSecondaryColor3fvEXT");
	if(!glSecondaryColor3fvEXT) bIsLoaded = 0;
	glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)gleIntGetProcAddress("glSecondaryColor3iEXT");
	if(!glSecondaryColor3iEXT) bIsLoaded = 0;
	glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)gleIntGetProcAddress("glSecondaryColor3ivEXT");
	if(!glSecondaryColor3ivEXT) bIsLoaded = 0;
	glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)gleIntGetProcAddress("glSecondaryColor3sEXT");
	if(!glSecondaryColor3sEXT) bIsLoaded = 0;
	glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)gleIntGetProcAddress("glSecondaryColor3svEXT");
	if(!glSecondaryColor3svEXT) bIsLoaded = 0;
	glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)gleIntGetProcAddress("glSecondaryColor3ubEXT");
	if(!glSecondaryColor3ubEXT) bIsLoaded = 0;
	glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)gleIntGetProcAddress("glSecondaryColor3ubvEXT");
	if(!glSecondaryColor3ubvEXT) bIsLoaded = 0;
	glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)gleIntGetProcAddress("glSecondaryColor3uiEXT");
	if(!glSecondaryColor3uiEXT) bIsLoaded = 0;
	glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)gleIntGetProcAddress("glSecondaryColor3uivEXT");
	if(!glSecondaryColor3uivEXT) bIsLoaded = 0;
	glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)gleIntGetProcAddress("glSecondaryColor3usEXT");
	if(!glSecondaryColor3usEXT) bIsLoaded = 0;
	glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)gleIntGetProcAddress("glSecondaryColor3usvEXT");
	if(!glSecondaryColor3usvEXT) bIsLoaded = 0;
	glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)gleIntGetProcAddress("glSecondaryColorPointerEXT");
	if(!glSecondaryColorPointerEXT) bIsLoaded = 0;
#endif /*GL_EXT_secondary_color*/
	return bIsLoaded;
}
#ifndef GL_EXT_separate_shader_objects
typedef void (GLE_FUNCPTR * PFNGLUSESHADERPROGRAMEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLACTIVEPROGRAMEXTPROC)(GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum , const GLchar *);

PFNGLUSESHADERPROGRAMEXTPROC glUseShaderProgramEXT;
PFNGLACTIVEPROGRAMEXTPROC glActiveProgramEXT;
PFNGLCREATESHADERPROGRAMEXTPROC glCreateShaderProgramEXT;
#endif /*GL_EXT_separate_shader_objects*/

static int gleIntLoad_EXT_separate_shader_objects()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_separate_shader_objects
	glUseShaderProgramEXT = (PFNGLUSESHADERPROGRAMEXTPROC)gleIntGetProcAddress("glUseShaderProgramEXT");
	if(!glUseShaderProgramEXT) bIsLoaded = 0;
	glActiveProgramEXT = (PFNGLACTIVEPROGRAMEXTPROC)gleIntGetProcAddress("glActiveProgramEXT");
	if(!glActiveProgramEXT) bIsLoaded = 0;
	glCreateShaderProgramEXT = (PFNGLCREATESHADERPROGRAMEXTPROC)gleIntGetProcAddress("glCreateShaderProgramEXT");
	if(!glCreateShaderProgramEXT) bIsLoaded = 0;
#endif /*GL_EXT_separate_shader_objects*/
	return bIsLoaded;
}

#ifndef GL_EXT_shader_image_load_store
typedef void (GLE_FUNCPTR * PFNGLBINDIMAGETEXTUREEXTPROC)(GLuint , GLuint , GLint , GLboolean , GLint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMEMORYBARRIEREXTPROC)(GLbitfield );

PFNGLBINDIMAGETEXTUREEXTPROC glBindImageTextureEXT;
PFNGLMEMORYBARRIEREXTPROC glMemoryBarrierEXT;
#endif /*GL_EXT_shader_image_load_store*/

static int gleIntLoad_EXT_shader_image_load_store()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_shader_image_load_store
	glBindImageTextureEXT = (PFNGLBINDIMAGETEXTUREEXTPROC)gleIntGetProcAddress("glBindImageTextureEXT");
	if(!glBindImageTextureEXT) bIsLoaded = 0;
	glMemoryBarrierEXT = (PFNGLMEMORYBARRIEREXTPROC)gleIntGetProcAddress("glMemoryBarrierEXT");
	if(!glMemoryBarrierEXT) bIsLoaded = 0;
#endif /*GL_EXT_shader_image_load_store*/
	return bIsLoaded;
}


#ifndef GL_EXT_stencil_clear_tag
typedef void (GLE_FUNCPTR * PFNGLSTENCILCLEARTAGEXTPROC)(GLsizei , GLuint );

PFNGLSTENCILCLEARTAGEXTPROC glStencilClearTagEXT;
#endif /*GL_EXT_stencil_clear_tag*/

static int gleIntLoad_EXT_stencil_clear_tag()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_stencil_clear_tag
	glStencilClearTagEXT = (PFNGLSTENCILCLEARTAGEXTPROC)gleIntGetProcAddress("glStencilClearTagEXT");
	if(!glStencilClearTagEXT) bIsLoaded = 0;
#endif /*GL_EXT_stencil_clear_tag*/
	return bIsLoaded;
}
#ifndef GL_EXT_stencil_two_side
typedef void (GLE_FUNCPTR * PFNGLACTIVESTENCILFACEEXTPROC)(GLenum );

PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXT;
#endif /*GL_EXT_stencil_two_side*/

static int gleIntLoad_EXT_stencil_two_side()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_stencil_two_side
	glActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)gleIntGetProcAddress("glActiveStencilFaceEXT");
	if(!glActiveStencilFaceEXT) bIsLoaded = 0;
#endif /*GL_EXT_stencil_two_side*/
	return bIsLoaded;
}

#ifndef GL_EXT_subtexture
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXT;
PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXT;
#endif /*GL_EXT_subtexture*/

static int gleIntLoad_EXT_subtexture()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_subtexture
	glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC)gleIntGetProcAddress("glTexSubImage1DEXT");
	if(!glTexSubImage1DEXT) bIsLoaded = 0;
	glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC)gleIntGetProcAddress("glTexSubImage2DEXT");
	if(!glTexSubImage2DEXT) bIsLoaded = 0;
#endif /*GL_EXT_subtexture*/
	return bIsLoaded;
}

#ifndef GL_EXT_texture3D
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DEXTPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXT;
PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXT;
#endif /*GL_EXT_texture3D*/

static int gleIntLoad_EXT_texture3D()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_texture3D
	glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)gleIntGetProcAddress("glTexImage3DEXT");
	if(!glTexImage3DEXT) bIsLoaded = 0;
	glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)gleIntGetProcAddress("glTexSubImage3DEXT");
	if(!glTexSubImage3DEXT) bIsLoaded = 0;
#endif /*GL_EXT_texture3D*/
	return bIsLoaded;
}

#ifndef GL_EXT_texture_buffer_object
typedef void (GLE_FUNCPTR * PFNGLTEXBUFFEREXTPROC)(GLenum , GLenum , GLuint );

PFNGLTEXBUFFEREXTPROC glTexBufferEXT;
#endif /*GL_EXT_texture_buffer_object*/

static int gleIntLoad_EXT_texture_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_texture_buffer_object
	glTexBufferEXT = (PFNGLTEXBUFFEREXTPROC)gleIntGetProcAddress("glTexBufferEXT");
	if(!glTexBufferEXT) bIsLoaded = 0;
#endif /*GL_EXT_texture_buffer_object*/
	return bIsLoaded;
}








#ifndef GL_EXT_texture_integer
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIIVEXTPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORIIEXTPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORIUIEXTPROC)(GLuint , GLuint , GLuint , GLuint );

PFNGLTEXPARAMETERIIVEXTPROC glTexParameterIivEXT;
PFNGLTEXPARAMETERIUIVEXTPROC glTexParameterIuivEXT;
PFNGLGETTEXPARAMETERIIVEXTPROC glGetTexParameterIivEXT;
PFNGLGETTEXPARAMETERIUIVEXTPROC glGetTexParameterIuivEXT;
PFNGLCLEARCOLORIIEXTPROC glClearColorIiEXT;
PFNGLCLEARCOLORIUIEXTPROC glClearColorIuiEXT;
#endif /*GL_EXT_texture_integer*/

static int gleIntLoad_EXT_texture_integer()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_texture_integer
	glTexParameterIivEXT = (PFNGLTEXPARAMETERIIVEXTPROC)gleIntGetProcAddress("glTexParameterIivEXT");
	if(!glTexParameterIivEXT) bIsLoaded = 0;
	glTexParameterIuivEXT = (PFNGLTEXPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glTexParameterIuivEXT");
	if(!glTexParameterIuivEXT) bIsLoaded = 0;
	glGetTexParameterIivEXT = (PFNGLGETTEXPARAMETERIIVEXTPROC)gleIntGetProcAddress("glGetTexParameterIivEXT");
	if(!glGetTexParameterIivEXT) bIsLoaded = 0;
	glGetTexParameterIuivEXT = (PFNGLGETTEXPARAMETERIUIVEXTPROC)gleIntGetProcAddress("glGetTexParameterIuivEXT");
	if(!glGetTexParameterIuivEXT) bIsLoaded = 0;
	glClearColorIiEXT = (PFNGLCLEARCOLORIIEXTPROC)gleIntGetProcAddress("glClearColorIiEXT");
	if(!glClearColorIiEXT) bIsLoaded = 0;
	glClearColorIuiEXT = (PFNGLCLEARCOLORIUIEXTPROC)gleIntGetProcAddress("glClearColorIuiEXT");
	if(!glClearColorIuiEXT) bIsLoaded = 0;
#endif /*GL_EXT_texture_integer*/
	return bIsLoaded;
}


#ifndef GL_EXT_texture_object
typedef GLboolean (GLE_FUNCPTR * PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei , const GLuint *, GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLBINDTEXTUREEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETEXTURESEXTPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTEXTURESEXTPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTEXTUREEXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei , const GLuint *, const GLclampf *);

PFNGLARETEXTURESRESIDENTEXTPROC glAreTexturesResidentEXT;
PFNGLBINDTEXTUREEXTPROC glBindTextureEXT;
PFNGLDELETETEXTURESEXTPROC glDeleteTexturesEXT;
PFNGLGENTEXTURESEXTPROC glGenTexturesEXT;
PFNGLISTEXTUREEXTPROC glIsTextureEXT;
PFNGLPRIORITIZETEXTURESEXTPROC glPrioritizeTexturesEXT;
#endif /*GL_EXT_texture_object*/

static int gleIntLoad_EXT_texture_object()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_texture_object
	glAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC)gleIntGetProcAddress("glAreTexturesResidentEXT");
	if(!glAreTexturesResidentEXT) bIsLoaded = 0;
	glBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC)gleIntGetProcAddress("glBindTextureEXT");
	if(!glBindTextureEXT) bIsLoaded = 0;
	glDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC)gleIntGetProcAddress("glDeleteTexturesEXT");
	if(!glDeleteTexturesEXT) bIsLoaded = 0;
	glGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC)gleIntGetProcAddress("glGenTexturesEXT");
	if(!glGenTexturesEXT) bIsLoaded = 0;
	glIsTextureEXT = (PFNGLISTEXTUREEXTPROC)gleIntGetProcAddress("glIsTextureEXT");
	if(!glIsTextureEXT) bIsLoaded = 0;
	glPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC)gleIntGetProcAddress("glPrioritizeTexturesEXT");
	if(!glPrioritizeTexturesEXT) bIsLoaded = 0;
#endif /*GL_EXT_texture_object*/
	return bIsLoaded;
}
#ifndef GL_EXT_texture_perturb_normal
typedef void (GLE_FUNCPTR * PFNGLTEXTURENORMALEXTPROC)(GLenum );

PFNGLTEXTURENORMALEXTPROC glTextureNormalEXT;
#endif /*GL_EXT_texture_perturb_normal*/

static int gleIntLoad_EXT_texture_perturb_normal()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_texture_perturb_normal
	glTextureNormalEXT = (PFNGLTEXTURENORMALEXTPROC)gleIntGetProcAddress("glTextureNormalEXT");
	if(!glTextureNormalEXT) bIsLoaded = 0;
#endif /*GL_EXT_texture_perturb_normal*/
	return bIsLoaded;
}





#ifndef GL_EXT_timer_query
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint , GLenum , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint , GLenum , GLuint64EXT *);

PFNGLGETQUERYOBJECTI64VEXTPROC glGetQueryObjecti64vEXT;
PFNGLGETQUERYOBJECTUI64VEXTPROC glGetQueryObjectui64vEXT;
#endif /*GL_EXT_timer_query*/

static int gleIntLoad_EXT_timer_query()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_timer_query
	glGetQueryObjecti64vEXT = (PFNGLGETQUERYOBJECTI64VEXTPROC)gleIntGetProcAddress("glGetQueryObjecti64vEXT");
	if(!glGetQueryObjecti64vEXT) bIsLoaded = 0;
	glGetQueryObjectui64vEXT = (PFNGLGETQUERYOBJECTUI64VEXTPROC)gleIntGetProcAddress("glGetQueryObjectui64vEXT");
	if(!glGetQueryObjectui64vEXT) bIsLoaded = 0;
#endif /*GL_EXT_timer_query*/
	return bIsLoaded;
}
#ifndef GL_EXT_transform_feedback
typedef void (GLE_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKEXTPROC)();
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERRANGEEXTPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFEROFFSETEXTPROC)(GLenum , GLuint , GLuint , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERBASEEXTPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(GLuint , GLsizei , const GLchar* *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);

PFNGLBEGINTRANSFORMFEEDBACKEXTPROC glBeginTransformFeedbackEXT;
PFNGLENDTRANSFORMFEEDBACKEXTPROC glEndTransformFeedbackEXT;
PFNGLBINDBUFFERRANGEEXTPROC glBindBufferRangeEXT;
PFNGLBINDBUFFEROFFSETEXTPROC glBindBufferOffsetEXT;
PFNGLBINDBUFFERBASEEXTPROC glBindBufferBaseEXT;
PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC glTransformFeedbackVaryingsEXT;
PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC glGetTransformFeedbackVaryingEXT;
#endif /*GL_EXT_transform_feedback*/

static int gleIntLoad_EXT_transform_feedback()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_transform_feedback
	glBeginTransformFeedbackEXT = (PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)gleIntGetProcAddress("glBeginTransformFeedbackEXT");
	if(!glBeginTransformFeedbackEXT) bIsLoaded = 0;
	glEndTransformFeedbackEXT = (PFNGLENDTRANSFORMFEEDBACKEXTPROC)gleIntGetProcAddress("glEndTransformFeedbackEXT");
	if(!glEndTransformFeedbackEXT) bIsLoaded = 0;
	glBindBufferRangeEXT = (PFNGLBINDBUFFERRANGEEXTPROC)gleIntGetProcAddress("glBindBufferRangeEXT");
	if(!glBindBufferRangeEXT) bIsLoaded = 0;
	glBindBufferOffsetEXT = (PFNGLBINDBUFFEROFFSETEXTPROC)gleIntGetProcAddress("glBindBufferOffsetEXT");
	if(!glBindBufferOffsetEXT) bIsLoaded = 0;
	glBindBufferBaseEXT = (PFNGLBINDBUFFERBASEEXTPROC)gleIntGetProcAddress("glBindBufferBaseEXT");
	if(!glBindBufferBaseEXT) bIsLoaded = 0;
	glTransformFeedbackVaryingsEXT = (PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)gleIntGetProcAddress("glTransformFeedbackVaryingsEXT");
	if(!glTransformFeedbackVaryingsEXT) bIsLoaded = 0;
	glGetTransformFeedbackVaryingEXT = (PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)gleIntGetProcAddress("glGetTransformFeedbackVaryingEXT");
	if(!glGetTransformFeedbackVaryingEXT) bIsLoaded = 0;
#endif /*GL_EXT_transform_feedback*/
	return bIsLoaded;
}
#ifndef GL_EXT_vertex_array
typedef void (GLE_FUNCPTR * PFNGLARRAYELEMENTEXTPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSEXTPROC)(GLenum , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei , GLsizei , const GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERVEXTPROC)(GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTEREXTPROC)(GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTEREXTPROC)(GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);

PFNGLARRAYELEMENTEXTPROC glArrayElementEXT;
PFNGLCOLORPOINTEREXTPROC glColorPointerEXT;
PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT;
PFNGLEDGEFLAGPOINTEREXTPROC glEdgeFlagPointerEXT;
PFNGLGETPOINTERVEXTPROC glGetPointervEXT;
PFNGLINDEXPOINTEREXTPROC glIndexPointerEXT;
PFNGLNORMALPOINTEREXTPROC glNormalPointerEXT;
PFNGLTEXCOORDPOINTEREXTPROC glTexCoordPointerEXT;
PFNGLVERTEXPOINTEREXTPROC glVertexPointerEXT;
#endif /*GL_EXT_vertex_array*/

static int gleIntLoad_EXT_vertex_array()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_vertex_array
	glArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC)gleIntGetProcAddress("glArrayElementEXT");
	if(!glArrayElementEXT) bIsLoaded = 0;
	glColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC)gleIntGetProcAddress("glColorPointerEXT");
	if(!glColorPointerEXT) bIsLoaded = 0;
	glDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC)gleIntGetProcAddress("glDrawArraysEXT");
	if(!glDrawArraysEXT) bIsLoaded = 0;
	glEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC)gleIntGetProcAddress("glEdgeFlagPointerEXT");
	if(!glEdgeFlagPointerEXT) bIsLoaded = 0;
	glGetPointervEXT = (PFNGLGETPOINTERVEXTPROC)gleIntGetProcAddress("glGetPointervEXT");
	if(!glGetPointervEXT) bIsLoaded = 0;
	glIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC)gleIntGetProcAddress("glIndexPointerEXT");
	if(!glIndexPointerEXT) bIsLoaded = 0;
	glNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC)gleIntGetProcAddress("glNormalPointerEXT");
	if(!glNormalPointerEXT) bIsLoaded = 0;
	glTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC)gleIntGetProcAddress("glTexCoordPointerEXT");
	if(!glTexCoordPointerEXT) bIsLoaded = 0;
	glVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC)gleIntGetProcAddress("glVertexPointerEXT");
	if(!glVertexPointerEXT) bIsLoaded = 0;
#endif /*GL_EXT_vertex_array*/
	return bIsLoaded;
}

#ifndef GL_EXT_vertex_attrib_64bit
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1DEXTPROC)(GLuint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2DEXTPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3DEXTPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4DEXTPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1DVEXTPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2DVEXTPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3DVEXTPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4DVEXTPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBLPOINTEREXTPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBLDVEXTPROC)(GLuint , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)(GLuint , GLuint , GLuint , GLint , GLenum , GLsizei , GLintptr );

PFNGLVERTEXATTRIBL1DEXTPROC glVertexAttribL1dEXT;
PFNGLVERTEXATTRIBL2DEXTPROC glVertexAttribL2dEXT;
PFNGLVERTEXATTRIBL3DEXTPROC glVertexAttribL3dEXT;
PFNGLVERTEXATTRIBL4DEXTPROC glVertexAttribL4dEXT;
PFNGLVERTEXATTRIBL1DVEXTPROC glVertexAttribL1dvEXT;
PFNGLVERTEXATTRIBL2DVEXTPROC glVertexAttribL2dvEXT;
PFNGLVERTEXATTRIBL3DVEXTPROC glVertexAttribL3dvEXT;
PFNGLVERTEXATTRIBL4DVEXTPROC glVertexAttribL4dvEXT;
PFNGLVERTEXATTRIBLPOINTEREXTPROC glVertexAttribLPointerEXT;
PFNGLGETVERTEXATTRIBLDVEXTPROC glGetVertexAttribLdvEXT;
PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC glVertexArrayVertexAttribLOffsetEXT;
#endif /*GL_EXT_vertex_attrib_64bit*/

static int gleIntLoad_EXT_vertex_attrib_64bit()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_vertex_attrib_64bit
	glVertexAttribL1dEXT = (PFNGLVERTEXATTRIBL1DEXTPROC)gleIntGetProcAddress("glVertexAttribL1dEXT");
	if(!glVertexAttribL1dEXT) bIsLoaded = 0;
	glVertexAttribL2dEXT = (PFNGLVERTEXATTRIBL2DEXTPROC)gleIntGetProcAddress("glVertexAttribL2dEXT");
	if(!glVertexAttribL2dEXT) bIsLoaded = 0;
	glVertexAttribL3dEXT = (PFNGLVERTEXATTRIBL3DEXTPROC)gleIntGetProcAddress("glVertexAttribL3dEXT");
	if(!glVertexAttribL3dEXT) bIsLoaded = 0;
	glVertexAttribL4dEXT = (PFNGLVERTEXATTRIBL4DEXTPROC)gleIntGetProcAddress("glVertexAttribL4dEXT");
	if(!glVertexAttribL4dEXT) bIsLoaded = 0;
	glVertexAttribL1dvEXT = (PFNGLVERTEXATTRIBL1DVEXTPROC)gleIntGetProcAddress("glVertexAttribL1dvEXT");
	if(!glVertexAttribL1dvEXT) bIsLoaded = 0;
	glVertexAttribL2dvEXT = (PFNGLVERTEXATTRIBL2DVEXTPROC)gleIntGetProcAddress("glVertexAttribL2dvEXT");
	if(!glVertexAttribL2dvEXT) bIsLoaded = 0;
	glVertexAttribL3dvEXT = (PFNGLVERTEXATTRIBL3DVEXTPROC)gleIntGetProcAddress("glVertexAttribL3dvEXT");
	if(!glVertexAttribL3dvEXT) bIsLoaded = 0;
	glVertexAttribL4dvEXT = (PFNGLVERTEXATTRIBL4DVEXTPROC)gleIntGetProcAddress("glVertexAttribL4dvEXT");
	if(!glVertexAttribL4dvEXT) bIsLoaded = 0;
	glVertexAttribLPointerEXT = (PFNGLVERTEXATTRIBLPOINTEREXTPROC)gleIntGetProcAddress("glVertexAttribLPointerEXT");
	if(!glVertexAttribLPointerEXT) bIsLoaded = 0;
	glGetVertexAttribLdvEXT = (PFNGLGETVERTEXATTRIBLDVEXTPROC)gleIntGetProcAddress("glGetVertexAttribLdvEXT");
	if(!glGetVertexAttribLdvEXT) bIsLoaded = 0;
	glVertexArrayVertexAttribLOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribLOffsetEXT");
	if(!glVertexArrayVertexAttribLOffsetEXT) bIsLoaded = 0;
#endif /*GL_EXT_vertex_attrib_64bit*/
	return bIsLoaded;
}
#ifndef GL_EXT_vertex_shader
typedef void (GLE_FUNCPTR * PFNGLBEGINVERTEXSHADEREXTPROC)();
typedef void (GLE_FUNCPTR * PFNGLENDVERTEXSHADEREXTPROC)();
typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXSHADEREXTPROC)(GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLGENVERTEXSHADERSEXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEVERTEXSHADEREXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLSHADEROP1EXTPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSHADEROP2EXTPROC)(GLenum , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSHADEROP3EXTPROC)(GLenum , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSWIZZLEEXTPROC)(GLuint , GLuint , GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLWRITEMASKEXTPROC)(GLuint , GLuint , GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLINSERTCOMPONENTEXTPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLEXTRACTCOMPONENTEXTPROC)(GLuint , GLuint , GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLGENSYMBOLSEXTPROC)(GLenum , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSETINVARIANTEXTPROC)(GLuint , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLSETLOCALCONSTANTEXTPROC)(GLuint , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTBVEXTPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTSVEXTPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTIVEXTPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTFVEXTPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTDVEXTPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTUBVEXTPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTUSVEXTPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTUIVEXTPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVARIANTPOINTEREXTPROC)(GLuint , GLenum , GLuint , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)(GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLBINDLIGHTPARAMETEREXTPROC)(GLenum , GLenum );
typedef GLuint (GLE_FUNCPTR * PFNGLBINDMATERIALPARAMETEREXTPROC)(GLenum , GLenum );
typedef GLuint (GLE_FUNCPTR * PFNGLBINDTEXGENPARAMETEREXTPROC)(GLenum , GLenum , GLenum );
typedef GLuint (GLE_FUNCPTR * PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)(GLenum , GLenum );
typedef GLuint (GLE_FUNCPTR * PFNGLBINDPARAMETEREXTPROC)(GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLISVARIANTENABLEDEXTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTBOOLEANVEXTPROC)(GLuint , GLenum , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTINTEGERVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTFLOATVEXTPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVARIANTPOINTERVEXTPROC)(GLuint , GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLGETINVARIANTBOOLEANVEXTPROC)(GLuint , GLenum , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETINVARIANTINTEGERVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETINVARIANTFLOATVEXTPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)(GLuint , GLenum , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETLOCALCONSTANTFLOATVEXTPROC)(GLuint , GLenum , GLfloat *);

PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT;
PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT;
PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT;
PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT;
PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT;
PFNGLSHADEROP1EXTPROC glShaderOp1EXT;
PFNGLSHADEROP2EXTPROC glShaderOp2EXT;
PFNGLSHADEROP3EXTPROC glShaderOp3EXT;
PFNGLSWIZZLEEXTPROC glSwizzleEXT;
PFNGLWRITEMASKEXTPROC glWriteMaskEXT;
PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT;
PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT;
PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT;
PFNGLSETINVARIANTEXTPROC glSetInvariantEXT;
PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT;
PFNGLVARIANTBVEXTPROC glVariantbvEXT;
PFNGLVARIANTSVEXTPROC glVariantsvEXT;
PFNGLVARIANTIVEXTPROC glVariantivEXT;
PFNGLVARIANTFVEXTPROC glVariantfvEXT;
PFNGLVARIANTDVEXTPROC glVariantdvEXT;
PFNGLVARIANTUBVEXTPROC glVariantubvEXT;
PFNGLVARIANTUSVEXTPROC glVariantusvEXT;
PFNGLVARIANTUIVEXTPROC glVariantuivEXT;
PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT;
PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT;
PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT;
PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT;
PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT;
PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT;
PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT;
PFNGLBINDPARAMETEREXTPROC glBindParameterEXT;
PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT;
PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT;
PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT;
PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT;
PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT;
PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT;
PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT;
PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT;
PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT;
PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT;
PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT;
#endif /*GL_EXT_vertex_shader*/

static int gleIntLoad_EXT_vertex_shader()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_vertex_shader
	glBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC)gleIntGetProcAddress("glBeginVertexShaderEXT");
	if(!glBeginVertexShaderEXT) bIsLoaded = 0;
	glEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC)gleIntGetProcAddress("glEndVertexShaderEXT");
	if(!glEndVertexShaderEXT) bIsLoaded = 0;
	glBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC)gleIntGetProcAddress("glBindVertexShaderEXT");
	if(!glBindVertexShaderEXT) bIsLoaded = 0;
	glGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC)gleIntGetProcAddress("glGenVertexShadersEXT");
	if(!glGenVertexShadersEXT) bIsLoaded = 0;
	glDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC)gleIntGetProcAddress("glDeleteVertexShaderEXT");
	if(!glDeleteVertexShaderEXT) bIsLoaded = 0;
	glShaderOp1EXT = (PFNGLSHADEROP1EXTPROC)gleIntGetProcAddress("glShaderOp1EXT");
	if(!glShaderOp1EXT) bIsLoaded = 0;
	glShaderOp2EXT = (PFNGLSHADEROP2EXTPROC)gleIntGetProcAddress("glShaderOp2EXT");
	if(!glShaderOp2EXT) bIsLoaded = 0;
	glShaderOp3EXT = (PFNGLSHADEROP3EXTPROC)gleIntGetProcAddress("glShaderOp3EXT");
	if(!glShaderOp3EXT) bIsLoaded = 0;
	glSwizzleEXT = (PFNGLSWIZZLEEXTPROC)gleIntGetProcAddress("glSwizzleEXT");
	if(!glSwizzleEXT) bIsLoaded = 0;
	glWriteMaskEXT = (PFNGLWRITEMASKEXTPROC)gleIntGetProcAddress("glWriteMaskEXT");
	if(!glWriteMaskEXT) bIsLoaded = 0;
	glInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC)gleIntGetProcAddress("glInsertComponentEXT");
	if(!glInsertComponentEXT) bIsLoaded = 0;
	glExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC)gleIntGetProcAddress("glExtractComponentEXT");
	if(!glExtractComponentEXT) bIsLoaded = 0;
	glGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC)gleIntGetProcAddress("glGenSymbolsEXT");
	if(!glGenSymbolsEXT) bIsLoaded = 0;
	glSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC)gleIntGetProcAddress("glSetInvariantEXT");
	if(!glSetInvariantEXT) bIsLoaded = 0;
	glSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC)gleIntGetProcAddress("glSetLocalConstantEXT");
	if(!glSetLocalConstantEXT) bIsLoaded = 0;
	glVariantbvEXT = (PFNGLVARIANTBVEXTPROC)gleIntGetProcAddress("glVariantbvEXT");
	if(!glVariantbvEXT) bIsLoaded = 0;
	glVariantsvEXT = (PFNGLVARIANTSVEXTPROC)gleIntGetProcAddress("glVariantsvEXT");
	if(!glVariantsvEXT) bIsLoaded = 0;
	glVariantivEXT = (PFNGLVARIANTIVEXTPROC)gleIntGetProcAddress("glVariantivEXT");
	if(!glVariantivEXT) bIsLoaded = 0;
	glVariantfvEXT = (PFNGLVARIANTFVEXTPROC)gleIntGetProcAddress("glVariantfvEXT");
	if(!glVariantfvEXT) bIsLoaded = 0;
	glVariantdvEXT = (PFNGLVARIANTDVEXTPROC)gleIntGetProcAddress("glVariantdvEXT");
	if(!glVariantdvEXT) bIsLoaded = 0;
	glVariantubvEXT = (PFNGLVARIANTUBVEXTPROC)gleIntGetProcAddress("glVariantubvEXT");
	if(!glVariantubvEXT) bIsLoaded = 0;
	glVariantusvEXT = (PFNGLVARIANTUSVEXTPROC)gleIntGetProcAddress("glVariantusvEXT");
	if(!glVariantusvEXT) bIsLoaded = 0;
	glVariantuivEXT = (PFNGLVARIANTUIVEXTPROC)gleIntGetProcAddress("glVariantuivEXT");
	if(!glVariantuivEXT) bIsLoaded = 0;
	glVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC)gleIntGetProcAddress("glVariantPointerEXT");
	if(!glVariantPointerEXT) bIsLoaded = 0;
	glEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)gleIntGetProcAddress("glEnableVariantClientStateEXT");
	if(!glEnableVariantClientStateEXT) bIsLoaded = 0;
	glDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)gleIntGetProcAddress("glDisableVariantClientStateEXT");
	if(!glDisableVariantClientStateEXT) bIsLoaded = 0;
	glBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC)gleIntGetProcAddress("glBindLightParameterEXT");
	if(!glBindLightParameterEXT) bIsLoaded = 0;
	glBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC)gleIntGetProcAddress("glBindMaterialParameterEXT");
	if(!glBindMaterialParameterEXT) bIsLoaded = 0;
	glBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC)gleIntGetProcAddress("glBindTexGenParameterEXT");
	if(!glBindTexGenParameterEXT) bIsLoaded = 0;
	glBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)gleIntGetProcAddress("glBindTextureUnitParameterEXT");
	if(!glBindTextureUnitParameterEXT) bIsLoaded = 0;
	glBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC)gleIntGetProcAddress("glBindParameterEXT");
	if(!glBindParameterEXT) bIsLoaded = 0;
	glIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC)gleIntGetProcAddress("glIsVariantEnabledEXT");
	if(!glIsVariantEnabledEXT) bIsLoaded = 0;
	glGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC)gleIntGetProcAddress("glGetVariantBooleanvEXT");
	if(!glGetVariantBooleanvEXT) bIsLoaded = 0;
	glGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC)gleIntGetProcAddress("glGetVariantIntegervEXT");
	if(!glGetVariantIntegervEXT) bIsLoaded = 0;
	glGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC)gleIntGetProcAddress("glGetVariantFloatvEXT");
	if(!glGetVariantFloatvEXT) bIsLoaded = 0;
	glGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC)gleIntGetProcAddress("glGetVariantPointervEXT");
	if(!glGetVariantPointervEXT) bIsLoaded = 0;
	glGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC)gleIntGetProcAddress("glGetInvariantBooleanvEXT");
	if(!glGetInvariantBooleanvEXT) bIsLoaded = 0;
	glGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC)gleIntGetProcAddress("glGetInvariantIntegervEXT");
	if(!glGetInvariantIntegervEXT) bIsLoaded = 0;
	glGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC)gleIntGetProcAddress("glGetInvariantFloatvEXT");
	if(!glGetInvariantFloatvEXT) bIsLoaded = 0;
	glGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)gleIntGetProcAddress("glGetLocalConstantBooleanvEXT");
	if(!glGetLocalConstantBooleanvEXT) bIsLoaded = 0;
	glGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)gleIntGetProcAddress("glGetLocalConstantIntegervEXT");
	if(!glGetLocalConstantIntegervEXT) bIsLoaded = 0;
	glGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)gleIntGetProcAddress("glGetLocalConstantFloatvEXT");
	if(!glGetLocalConstantFloatvEXT) bIsLoaded = 0;
#endif /*GL_EXT_vertex_shader*/
	return bIsLoaded;
}
#ifndef GL_EXT_vertex_weighting
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLint , GLenum , GLsizei , const GLvoid *);

PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXT;
PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXT;
PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXT;
#endif /*GL_EXT_vertex_weighting*/

static int gleIntLoad_EXT_vertex_weighting()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_vertex_weighting
	glVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC)gleIntGetProcAddress("glVertexWeightfEXT");
	if(!glVertexWeightfEXT) bIsLoaded = 0;
	glVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC)gleIntGetProcAddress("glVertexWeightfvEXT");
	if(!glVertexWeightfvEXT) bIsLoaded = 0;
	glVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)gleIntGetProcAddress("glVertexWeightPointerEXT");
	if(!glVertexWeightPointerEXT) bIsLoaded = 0;
#endif /*GL_EXT_vertex_weighting*/
	return bIsLoaded;
}
#ifndef GL_EXT_x11_sync_object
typedef GLsync (GLE_FUNCPTR * PFNGLIMPORTSYNCEXTPROC)(GLenum , GLintptr , GLbitfield );

PFNGLIMPORTSYNCEXTPROC glImportSyncEXT;
#endif /*GL_EXT_x11_sync_object*/

static int gleIntLoad_EXT_x11_sync_object()
{
	int bIsLoaded = 1;
#ifndef GL_EXT_x11_sync_object
	glImportSyncEXT = (PFNGLIMPORTSYNCEXTPROC)gleIntGetProcAddress("glImportSyncEXT");
	if(!glImportSyncEXT) bIsLoaded = 0;
#endif /*GL_EXT_x11_sync_object*/
	return bIsLoaded;
}

#ifndef GL_GREMEDY_frame_terminator
typedef void (GLE_FUNCPTR * PFNGLFRAMETERMINATORGREMEDYPROC)();

PFNGLFRAMETERMINATORGREMEDYPROC glFrameTerminatorGREMEDY;
#endif /*GL_GREMEDY_frame_terminator*/

static int gleIntLoad_GREMEDY_frame_terminator()
{
	int bIsLoaded = 1;
#ifndef GL_GREMEDY_frame_terminator
	glFrameTerminatorGREMEDY = (PFNGLFRAMETERMINATORGREMEDYPROC)gleIntGetProcAddress("glFrameTerminatorGREMEDY");
	if(!glFrameTerminatorGREMEDY) bIsLoaded = 0;
#endif /*GL_GREMEDY_frame_terminator*/
	return bIsLoaded;
}
#ifndef GL_GREMEDY_string_marker
typedef void (GLE_FUNCPTR * PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei , const GLvoid *);

PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDY;
#endif /*GL_GREMEDY_string_marker*/

static int gleIntLoad_GREMEDY_string_marker()
{
	int bIsLoaded = 1;
#ifndef GL_GREMEDY_string_marker
	glStringMarkerGREMEDY = (PFNGLSTRINGMARKERGREMEDYPROC)gleIntGetProcAddress("glStringMarkerGREMEDY");
	if(!glStringMarkerGREMEDY) bIsLoaded = 0;
#endif /*GL_GREMEDY_string_marker*/
	return bIsLoaded;
}

#ifndef GL_HP_image_transform
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum , GLenum , GLfloat *);

PFNGLIMAGETRANSFORMPARAMETERIHPPROC glImageTransformParameteriHP;
PFNGLIMAGETRANSFORMPARAMETERFHPPROC glImageTransformParameterfHP;
PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glImageTransformParameterivHP;
PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glImageTransformParameterfvHP;
PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glGetImageTransformParameterivHP;
PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glGetImageTransformParameterfvHP;
#endif /*GL_HP_image_transform*/

static int gleIntLoad_HP_image_transform()
{
	int bIsLoaded = 1;
#ifndef GL_HP_image_transform
	glImageTransformParameteriHP = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)gleIntGetProcAddress("glImageTransformParameteriHP");
	if(!glImageTransformParameteriHP) bIsLoaded = 0;
	glImageTransformParameterfHP = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)gleIntGetProcAddress("glImageTransformParameterfHP");
	if(!glImageTransformParameterfHP) bIsLoaded = 0;
	glImageTransformParameterivHP = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)gleIntGetProcAddress("glImageTransformParameterivHP");
	if(!glImageTransformParameterivHP) bIsLoaded = 0;
	glImageTransformParameterfvHP = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)gleIntGetProcAddress("glImageTransformParameterfvHP");
	if(!glImageTransformParameterfvHP) bIsLoaded = 0;
	glGetImageTransformParameterivHP = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)gleIntGetProcAddress("glGetImageTransformParameterivHP");
	if(!glGetImageTransformParameterivHP) bIsLoaded = 0;
	glGetImageTransformParameterfvHP = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)gleIntGetProcAddress("glGetImageTransformParameterfvHP");
	if(!glGetImageTransformParameterfvHP) bIsLoaded = 0;
#endif /*GL_HP_image_transform*/
	return bIsLoaded;
}



#ifndef GL_IBM_multimode_draw_arrays
typedef void (GLE_FUNCPTR * PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *, const GLint *, const GLsizei *, GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *, const GLsizei *, GLenum , const GLvoid* const *, GLsizei , GLint );

PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBM;
PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBM;
#endif /*GL_IBM_multimode_draw_arrays*/

static int gleIntLoad_IBM_multimode_draw_arrays()
{
	int bIsLoaded = 1;
#ifndef GL_IBM_multimode_draw_arrays
	glMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)gleIntGetProcAddress("glMultiModeDrawArraysIBM");
	if(!glMultiModeDrawArraysIBM) bIsLoaded = 0;
	glMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)gleIntGetProcAddress("glMultiModeDrawElementsIBM");
	if(!glMultiModeDrawElementsIBM) bIsLoaded = 0;
#endif /*GL_IBM_multimode_draw_arrays*/
	return bIsLoaded;
}


#ifndef GL_IBM_vertex_array_lists
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint , const GLboolean* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );

PFNGLCOLORPOINTERLISTIBMPROC glColorPointerListIBM;
PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glSecondaryColorPointerListIBM;
PFNGLEDGEFLAGPOINTERLISTIBMPROC glEdgeFlagPointerListIBM;
PFNGLFOGCOORDPOINTERLISTIBMPROC glFogCoordPointerListIBM;
PFNGLINDEXPOINTERLISTIBMPROC glIndexPointerListIBM;
PFNGLNORMALPOINTERLISTIBMPROC glNormalPointerListIBM;
PFNGLTEXCOORDPOINTERLISTIBMPROC glTexCoordPointerListIBM;
PFNGLVERTEXPOINTERLISTIBMPROC glVertexPointerListIBM;
#endif /*GL_IBM_vertex_array_lists*/

static int gleIntLoad_IBM_vertex_array_lists()
{
	int bIsLoaded = 1;
#ifndef GL_IBM_vertex_array_lists
	glColorPointerListIBM = (PFNGLCOLORPOINTERLISTIBMPROC)gleIntGetProcAddress("glColorPointerListIBM");
	if(!glColorPointerListIBM) bIsLoaded = 0;
	glSecondaryColorPointerListIBM = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)gleIntGetProcAddress("glSecondaryColorPointerListIBM");
	if(!glSecondaryColorPointerListIBM) bIsLoaded = 0;
	glEdgeFlagPointerListIBM = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)gleIntGetProcAddress("glEdgeFlagPointerListIBM");
	if(!glEdgeFlagPointerListIBM) bIsLoaded = 0;
	glFogCoordPointerListIBM = (PFNGLFOGCOORDPOINTERLISTIBMPROC)gleIntGetProcAddress("glFogCoordPointerListIBM");
	if(!glFogCoordPointerListIBM) bIsLoaded = 0;
	glIndexPointerListIBM = (PFNGLINDEXPOINTERLISTIBMPROC)gleIntGetProcAddress("glIndexPointerListIBM");
	if(!glIndexPointerListIBM) bIsLoaded = 0;
	glNormalPointerListIBM = (PFNGLNORMALPOINTERLISTIBMPROC)gleIntGetProcAddress("glNormalPointerListIBM");
	if(!glNormalPointerListIBM) bIsLoaded = 0;
	glTexCoordPointerListIBM = (PFNGLTEXCOORDPOINTERLISTIBMPROC)gleIntGetProcAddress("glTexCoordPointerListIBM");
	if(!glTexCoordPointerListIBM) bIsLoaded = 0;
	glVertexPointerListIBM = (PFNGLVERTEXPOINTERLISTIBMPROC)gleIntGetProcAddress("glVertexPointerListIBM");
	if(!glVertexPointerListIBM) bIsLoaded = 0;
#endif /*GL_IBM_vertex_array_lists*/
	return bIsLoaded;
}



#ifndef GL_INTEL_parallel_arrays
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERVINTELPROC)(GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);

PFNGLVERTEXPOINTERVINTELPROC glVertexPointervINTEL;
PFNGLNORMALPOINTERVINTELPROC glNormalPointervINTEL;
PFNGLCOLORPOINTERVINTELPROC glColorPointervINTEL;
PFNGLTEXCOORDPOINTERVINTELPROC glTexCoordPointervINTEL;
#endif /*GL_INTEL_parallel_arrays*/

static int gleIntLoad_INTEL_parallel_arrays()
{
	int bIsLoaded = 1;
#ifndef GL_INTEL_parallel_arrays
	glVertexPointervINTEL = (PFNGLVERTEXPOINTERVINTELPROC)gleIntGetProcAddress("glVertexPointervINTEL");
	if(!glVertexPointervINTEL) bIsLoaded = 0;
	glNormalPointervINTEL = (PFNGLNORMALPOINTERVINTELPROC)gleIntGetProcAddress("glNormalPointervINTEL");
	if(!glNormalPointervINTEL) bIsLoaded = 0;
	glColorPointervINTEL = (PFNGLCOLORPOINTERVINTELPROC)gleIntGetProcAddress("glColorPointervINTEL");
	if(!glColorPointervINTEL) bIsLoaded = 0;
	glTexCoordPointervINTEL = (PFNGLTEXCOORDPOINTERVINTELPROC)gleIntGetProcAddress("glTexCoordPointervINTEL");
	if(!glTexCoordPointervINTEL) bIsLoaded = 0;
#endif /*GL_INTEL_parallel_arrays*/
	return bIsLoaded;
}

#ifndef GL_KHR_debug
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECONTROLPROC)(GLenum , GLenum , GLenum , GLsizei , const GLuint *, GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEINSERTPROC)(GLenum , GLenum , GLuint , GLenum , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC , const void *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETDEBUGMESSAGELOGPROC)(GLuint , GLsizei , GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLPUSHDEBUGGROUPPROC)(GLenum , GLuint , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLPOPDEBUGGROUPPROC)();
typedef void (GLE_FUNCPTR * PFNGLOBJECTLABELPROC)(GLenum , GLuint , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTLABELPROC)(GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLOBJECTPTRLABELPROC)(const void *, GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTPTRLABELPROC)(const void *, GLsizei , GLsizei *, GLchar *);

PFNGLDEBUGMESSAGECONTROLPROC __gleDebugMessageControl;
PFNGLDEBUGMESSAGEINSERTPROC __gleDebugMessageInsert;
PFNGLDEBUGMESSAGECALLBACKPROC __gleDebugMessageCallback;
PFNGLGETDEBUGMESSAGELOGPROC __gleGetDebugMessageLog;
PFNGLPUSHDEBUGGROUPPROC __glePushDebugGroup;
PFNGLPOPDEBUGGROUPPROC __glePopDebugGroup;
PFNGLOBJECTLABELPROC __gleObjectLabel;
PFNGLGETOBJECTLABELPROC __gleGetObjectLabel;
PFNGLOBJECTPTRLABELPROC __gleObjectPtrLabel;
PFNGLGETOBJECTPTRLABELPROC __gleGetObjectPtrLabel;
#endif /*GL_KHR_debug*/

static int gleIntLoad_KHR_debug()
{
	int bIsLoaded = 1;
#ifndef GL_KHR_debug
	__gleDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)gleIntGetProcAddress("glDebugMessageControl");
	if(!__gleDebugMessageControl) bIsLoaded = 0;
	__gleDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)gleIntGetProcAddress("glDebugMessageInsert");
	if(!__gleDebugMessageInsert) bIsLoaded = 0;
	__gleDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)gleIntGetProcAddress("glDebugMessageCallback");
	if(!__gleDebugMessageCallback) bIsLoaded = 0;
	__gleGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)gleIntGetProcAddress("glGetDebugMessageLog");
	if(!__gleGetDebugMessageLog) bIsLoaded = 0;
	__glePushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)gleIntGetProcAddress("glPushDebugGroup");
	if(!__glePushDebugGroup) bIsLoaded = 0;
	__glePopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)gleIntGetProcAddress("glPopDebugGroup");
	if(!__glePopDebugGroup) bIsLoaded = 0;
	__gleObjectLabel = (PFNGLOBJECTLABELPROC)gleIntGetProcAddress("glObjectLabel");
	if(!__gleObjectLabel) bIsLoaded = 0;
	__gleGetObjectLabel = (PFNGLGETOBJECTLABELPROC)gleIntGetProcAddress("glGetObjectLabel");
	if(!__gleGetObjectLabel) bIsLoaded = 0;
	__gleObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)gleIntGetProcAddress("glObjectPtrLabel");
	if(!__gleObjectPtrLabel) bIsLoaded = 0;
	__gleGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)gleIntGetProcAddress("glGetObjectPtrLabel");
	if(!__gleGetObjectPtrLabel) bIsLoaded = 0;
#endif /*GL_KHR_debug*/
	return bIsLoaded;
}



#ifndef GL_MESA_resize_buffers
typedef void (GLE_FUNCPTR * PFNGLRESIZEBUFFERSMESAPROC)();

PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESA;
#endif /*GL_MESA_resize_buffers*/

static int gleIntLoad_MESA_resize_buffers()
{
	int bIsLoaded = 1;
#ifndef GL_MESA_resize_buffers
	glResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC)gleIntGetProcAddress("glResizeBuffersMESA");
	if(!glResizeBuffersMESA) bIsLoaded = 0;
#endif /*GL_MESA_resize_buffers*/
	return bIsLoaded;
}
#ifndef GL_MESA_window_pos
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DMESAPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DVMESAPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FMESAPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FVMESAPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IMESAPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IVMESAPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SMESAPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SVMESAPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DMESAPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DVMESAPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FMESAPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FVMESAPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IMESAPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IVMESAPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SMESAPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SVMESAPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4DMESAPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4DVMESAPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4FMESAPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4FVMESAPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4IMESAPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4IVMESAPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4SMESAPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS4SVMESAPROC)(const GLshort *);

PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESA;
PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESA;
PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESA;
PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESA;
PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESA;
PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESA;
PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESA;
PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESA;
PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESA;
PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESA;
PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESA;
PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESA;
PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESA;
PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESA;
PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESA;
PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESA;
PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESA;
PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESA;
PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESA;
PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESA;
PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESA;
PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESA;
PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESA;
PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESA;
#endif /*GL_MESA_window_pos*/

static int gleIntLoad_MESA_window_pos()
{
	int bIsLoaded = 1;
#ifndef GL_MESA_window_pos
	glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)gleIntGetProcAddress("glWindowPos2dMESA");
	if(!glWindowPos2dMESA) bIsLoaded = 0;
	glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)gleIntGetProcAddress("glWindowPos2dvMESA");
	if(!glWindowPos2dvMESA) bIsLoaded = 0;
	glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)gleIntGetProcAddress("glWindowPos2fMESA");
	if(!glWindowPos2fMESA) bIsLoaded = 0;
	glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)gleIntGetProcAddress("glWindowPos2fvMESA");
	if(!glWindowPos2fvMESA) bIsLoaded = 0;
	glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)gleIntGetProcAddress("glWindowPos2iMESA");
	if(!glWindowPos2iMESA) bIsLoaded = 0;
	glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)gleIntGetProcAddress("glWindowPos2ivMESA");
	if(!glWindowPos2ivMESA) bIsLoaded = 0;
	glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)gleIntGetProcAddress("glWindowPos2sMESA");
	if(!glWindowPos2sMESA) bIsLoaded = 0;
	glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)gleIntGetProcAddress("glWindowPos2svMESA");
	if(!glWindowPos2svMESA) bIsLoaded = 0;
	glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)gleIntGetProcAddress("glWindowPos3dMESA");
	if(!glWindowPos3dMESA) bIsLoaded = 0;
	glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)gleIntGetProcAddress("glWindowPos3dvMESA");
	if(!glWindowPos3dvMESA) bIsLoaded = 0;
	glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)gleIntGetProcAddress("glWindowPos3fMESA");
	if(!glWindowPos3fMESA) bIsLoaded = 0;
	glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)gleIntGetProcAddress("glWindowPos3fvMESA");
	if(!glWindowPos3fvMESA) bIsLoaded = 0;
	glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)gleIntGetProcAddress("glWindowPos3iMESA");
	if(!glWindowPos3iMESA) bIsLoaded = 0;
	glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)gleIntGetProcAddress("glWindowPos3ivMESA");
	if(!glWindowPos3ivMESA) bIsLoaded = 0;
	glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)gleIntGetProcAddress("glWindowPos3sMESA");
	if(!glWindowPos3sMESA) bIsLoaded = 0;
	glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)gleIntGetProcAddress("glWindowPos3svMESA");
	if(!glWindowPos3svMESA) bIsLoaded = 0;
	glWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC)gleIntGetProcAddress("glWindowPos4dMESA");
	if(!glWindowPos4dMESA) bIsLoaded = 0;
	glWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC)gleIntGetProcAddress("glWindowPos4dvMESA");
	if(!glWindowPos4dvMESA) bIsLoaded = 0;
	glWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC)gleIntGetProcAddress("glWindowPos4fMESA");
	if(!glWindowPos4fMESA) bIsLoaded = 0;
	glWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC)gleIntGetProcAddress("glWindowPos4fvMESA");
	if(!glWindowPos4fvMESA) bIsLoaded = 0;
	glWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC)gleIntGetProcAddress("glWindowPos4iMESA");
	if(!glWindowPos4iMESA) bIsLoaded = 0;
	glWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC)gleIntGetProcAddress("glWindowPos4ivMESA");
	if(!glWindowPos4ivMESA) bIsLoaded = 0;
	glWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC)gleIntGetProcAddress("glWindowPos4sMESA");
	if(!glWindowPos4sMESA) bIsLoaded = 0;
	glWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC)gleIntGetProcAddress("glWindowPos4svMESA");
	if(!glWindowPos4svMESA) bIsLoaded = 0;
#endif /*GL_MESA_window_pos*/
	return bIsLoaded;
}

#ifndef GL_NV_bindless_texture
typedef GLuint64 (GLE_FUNCPTR * PFNGLGETTEXTUREHANDLENVPROC)(GLuint );
typedef GLuint64 (GLE_FUNCPTR * PFNGLGETTEXTURESAMPLERHANDLENVPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)(GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)(GLuint64 );
typedef GLuint64 (GLE_FUNCPTR * PFNGLGETIMAGEHANDLENVPROC)(GLuint , GLint , GLboolean , GLint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)(GLuint64 , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)(GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLUNIFORMHANDLEUI64NVPROC)(GLint , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLUNIFORMHANDLEUI64VNVPROC)(GLint , GLsizei , const GLuint64 *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)(GLuint , GLint , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64 *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTEXTUREHANDLERESIDENTNVPROC)(GLuint64 );
typedef GLboolean (GLE_FUNCPTR * PFNGLISIMAGEHANDLERESIDENTNVPROC)(GLuint64 );

PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV;
PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV;
PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV;
PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV;
PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV;
PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV;
PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV;
PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV;
PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV;
PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV;
PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV;
PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV;
PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV;
#endif /*GL_NV_bindless_texture*/

static int gleIntLoad_NV_bindless_texture()
{
	int bIsLoaded = 1;
#ifndef GL_NV_bindless_texture
	glGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC)gleIntGetProcAddress("glGetTextureHandleNV");
	if(!glGetTextureHandleNV) bIsLoaded = 0;
	glGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)gleIntGetProcAddress("glGetTextureSamplerHandleNV");
	if(!glGetTextureSamplerHandleNV) bIsLoaded = 0;
	glMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)gleIntGetProcAddress("glMakeTextureHandleResidentNV");
	if(!glMakeTextureHandleResidentNV) bIsLoaded = 0;
	glMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)gleIntGetProcAddress("glMakeTextureHandleNonResidentNV");
	if(!glMakeTextureHandleNonResidentNV) bIsLoaded = 0;
	glGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC)gleIntGetProcAddress("glGetImageHandleNV");
	if(!glGetImageHandleNV) bIsLoaded = 0;
	glMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)gleIntGetProcAddress("glMakeImageHandleResidentNV");
	if(!glMakeImageHandleResidentNV) bIsLoaded = 0;
	glMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)gleIntGetProcAddress("glMakeImageHandleNonResidentNV");
	if(!glMakeImageHandleNonResidentNV) bIsLoaded = 0;
	glUniformHandleui64NV = (PFNGLUNIFORMHANDLEUI64NVPROC)gleIntGetProcAddress("glUniformHandleui64NV");
	if(!glUniformHandleui64NV) bIsLoaded = 0;
	glUniformHandleui64vNV = (PFNGLUNIFORMHANDLEUI64VNVPROC)gleIntGetProcAddress("glUniformHandleui64vNV");
	if(!glUniformHandleui64vNV) bIsLoaded = 0;
	glProgramUniformHandleui64NV = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)gleIntGetProcAddress("glProgramUniformHandleui64NV");
	if(!glProgramUniformHandleui64NV) bIsLoaded = 0;
	glProgramUniformHandleui64vNV = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)gleIntGetProcAddress("glProgramUniformHandleui64vNV");
	if(!glProgramUniformHandleui64vNV) bIsLoaded = 0;
	glIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)gleIntGetProcAddress("glIsTextureHandleResidentNV");
	if(!glIsTextureHandleResidentNV) bIsLoaded = 0;
	glIsImageHandleResidentNV = (PFNGLISIMAGEHANDLERESIDENTNVPROC)gleIntGetProcAddress("glIsImageHandleResidentNV");
	if(!glIsImageHandleResidentNV) bIsLoaded = 0;
#endif /*GL_NV_bindless_texture*/
	return bIsLoaded;
}

#ifndef GL_NV_conditional_render
typedef void (GLE_FUNCPTR * PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDCONDITIONALRENDERNVPROC)();

PFNGLBEGINCONDITIONALRENDERNVPROC glBeginConditionalRenderNV;
PFNGLENDCONDITIONALRENDERNVPROC glEndConditionalRenderNV;
#endif /*GL_NV_conditional_render*/

static int gleIntLoad_NV_conditional_render()
{
	int bIsLoaded = 1;
#ifndef GL_NV_conditional_render
	glBeginConditionalRenderNV = (PFNGLBEGINCONDITIONALRENDERNVPROC)gleIntGetProcAddress("glBeginConditionalRenderNV");
	if(!glBeginConditionalRenderNV) bIsLoaded = 0;
	glEndConditionalRenderNV = (PFNGLENDCONDITIONALRENDERNVPROC)gleIntGetProcAddress("glEndConditionalRenderNV");
	if(!glEndConditionalRenderNV) bIsLoaded = 0;
#endif /*GL_NV_conditional_render*/
	return bIsLoaded;
}

#ifndef GL_NV_copy_image
typedef void (GLE_FUNCPTR * PFNGLCOPYIMAGESUBDATANVPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

PFNGLCOPYIMAGESUBDATANVPROC glCopyImageSubDataNV;
#endif /*GL_NV_copy_image*/

static int gleIntLoad_NV_copy_image()
{
	int bIsLoaded = 1;
#ifndef GL_NV_copy_image
	glCopyImageSubDataNV = (PFNGLCOPYIMAGESUBDATANVPROC)gleIntGetProcAddress("glCopyImageSubDataNV");
	if(!glCopyImageSubDataNV) bIsLoaded = 0;
#endif /*GL_NV_copy_image*/
	return bIsLoaded;
}
#ifndef GL_NV_depth_buffer_float
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEDNVPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHDNVPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLDEPTHBOUNDSDNVPROC)(GLdouble , GLdouble );

PFNGLDEPTHRANGEDNVPROC glDepthRangedNV;
PFNGLCLEARDEPTHDNVPROC glClearDepthdNV;
PFNGLDEPTHBOUNDSDNVPROC glDepthBoundsdNV;
#endif /*GL_NV_depth_buffer_float*/

static int gleIntLoad_NV_depth_buffer_float()
{
	int bIsLoaded = 1;
#ifndef GL_NV_depth_buffer_float
	glDepthRangedNV = (PFNGLDEPTHRANGEDNVPROC)gleIntGetProcAddress("glDepthRangedNV");
	if(!glDepthRangedNV) bIsLoaded = 0;
	glClearDepthdNV = (PFNGLCLEARDEPTHDNVPROC)gleIntGetProcAddress("glClearDepthdNV");
	if(!glClearDepthdNV) bIsLoaded = 0;
	glDepthBoundsdNV = (PFNGLDEPTHBOUNDSDNVPROC)gleIntGetProcAddress("glDepthBoundsdNV");
	if(!glDepthBoundsdNV) bIsLoaded = 0;
#endif /*GL_NV_depth_buffer_float*/
	return bIsLoaded;
}

#ifndef GL_NV_evaluators
typedef void (GLE_FUNCPTR * PFNGLMAPCONTROLPOINTSNVPROC)(GLenum , GLuint , GLenum , GLsizei , GLsizei , GLint , GLint , GLboolean , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMAPPARAMETERIVNVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMAPPARAMETERFVNVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum , GLuint , GLenum , GLsizei , GLsizei , GLboolean , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPPARAMETERIVNVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPPARAMETERFVNVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum , GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLEVALMAPSNVPROC)(GLenum , GLenum );

PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNV;
PFNGLMAPPARAMETERIVNVPROC glMapParameterivNV;
PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNV;
PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNV;
PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNV;
PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNV;
PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNV;
PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNV;
PFNGLEVALMAPSNVPROC glEvalMapsNV;
#endif /*GL_NV_evaluators*/

static int gleIntLoad_NV_evaluators()
{
	int bIsLoaded = 1;
#ifndef GL_NV_evaluators
	glMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC)gleIntGetProcAddress("glMapControlPointsNV");
	if(!glMapControlPointsNV) bIsLoaded = 0;
	glMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC)gleIntGetProcAddress("glMapParameterivNV");
	if(!glMapParameterivNV) bIsLoaded = 0;
	glMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC)gleIntGetProcAddress("glMapParameterfvNV");
	if(!glMapParameterfvNV) bIsLoaded = 0;
	glGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC)gleIntGetProcAddress("glGetMapControlPointsNV");
	if(!glGetMapControlPointsNV) bIsLoaded = 0;
	glGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC)gleIntGetProcAddress("glGetMapParameterivNV");
	if(!glGetMapParameterivNV) bIsLoaded = 0;
	glGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC)gleIntGetProcAddress("glGetMapParameterfvNV");
	if(!glGetMapParameterfvNV) bIsLoaded = 0;
	glGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)gleIntGetProcAddress("glGetMapAttribParameterivNV");
	if(!glGetMapAttribParameterivNV) bIsLoaded = 0;
	glGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)gleIntGetProcAddress("glGetMapAttribParameterfvNV");
	if(!glGetMapAttribParameterfvNV) bIsLoaded = 0;
	glEvalMapsNV = (PFNGLEVALMAPSNVPROC)gleIntGetProcAddress("glEvalMapsNV");
	if(!glEvalMapsNV) bIsLoaded = 0;
#endif /*GL_NV_evaluators*/
	return bIsLoaded;
}
#ifndef GL_NV_explicit_multisample
typedef void (GLE_FUNCPTR * PFNGLGETMULTISAMPLEFVNVPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint , GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLTEXRENDERBUFFERNVPROC)(GLenum , GLuint );

PFNGLGETMULTISAMPLEFVNVPROC glGetMultisamplefvNV;
PFNGLSAMPLEMASKINDEXEDNVPROC glSampleMaskIndexedNV;
PFNGLTEXRENDERBUFFERNVPROC glTexRenderbufferNV;
#endif /*GL_NV_explicit_multisample*/

static int gleIntLoad_NV_explicit_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_NV_explicit_multisample
	glGetMultisamplefvNV = (PFNGLGETMULTISAMPLEFVNVPROC)gleIntGetProcAddress("glGetMultisamplefvNV");
	if(!glGetMultisamplefvNV) bIsLoaded = 0;
	glSampleMaskIndexedNV = (PFNGLSAMPLEMASKINDEXEDNVPROC)gleIntGetProcAddress("glSampleMaskIndexedNV");
	if(!glSampleMaskIndexedNV) bIsLoaded = 0;
	glTexRenderbufferNV = (PFNGLTEXRENDERBUFFERNVPROC)gleIntGetProcAddress("glTexRenderbufferNV");
	if(!glTexRenderbufferNV) bIsLoaded = 0;
#endif /*GL_NV_explicit_multisample*/
	return bIsLoaded;
}
#ifndef GL_NV_fence
typedef void (GLE_FUNCPTR * PFNGLDELETEFENCESNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENFENCESNVPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISFENCENVPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTFENCENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETFENCEIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLFINISHFENCENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLSETFENCENVPROC)(GLuint , GLenum );

PFNGLDELETEFENCESNVPROC glDeleteFencesNV;
PFNGLGENFENCESNVPROC glGenFencesNV;
PFNGLISFENCENVPROC glIsFenceNV;
PFNGLTESTFENCENVPROC glTestFenceNV;
PFNGLGETFENCEIVNVPROC glGetFenceivNV;
PFNGLFINISHFENCENVPROC glFinishFenceNV;
PFNGLSETFENCENVPROC glSetFenceNV;
#endif /*GL_NV_fence*/

static int gleIntLoad_NV_fence()
{
	int bIsLoaded = 1;
#ifndef GL_NV_fence
	glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)gleIntGetProcAddress("glDeleteFencesNV");
	if(!glDeleteFencesNV) bIsLoaded = 0;
	glGenFencesNV = (PFNGLGENFENCESNVPROC)gleIntGetProcAddress("glGenFencesNV");
	if(!glGenFencesNV) bIsLoaded = 0;
	glIsFenceNV = (PFNGLISFENCENVPROC)gleIntGetProcAddress("glIsFenceNV");
	if(!glIsFenceNV) bIsLoaded = 0;
	glTestFenceNV = (PFNGLTESTFENCENVPROC)gleIntGetProcAddress("glTestFenceNV");
	if(!glTestFenceNV) bIsLoaded = 0;
	glGetFenceivNV = (PFNGLGETFENCEIVNVPROC)gleIntGetProcAddress("glGetFenceivNV");
	if(!glGetFenceivNV) bIsLoaded = 0;
	glFinishFenceNV = (PFNGLFINISHFENCENVPROC)gleIntGetProcAddress("glFinishFenceNV");
	if(!glFinishFenceNV) bIsLoaded = 0;
	glSetFenceNV = (PFNGLSETFENCENVPROC)gleIntGetProcAddress("glSetFenceNV");
	if(!glSetFenceNV) bIsLoaded = 0;
#endif /*GL_NV_fence*/
	return bIsLoaded;
}


#ifndef GL_NV_fragment_program
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint , GLsizei , const GLubyte *, GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint , GLsizei , const GLubyte *, GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint , GLsizei , const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint , GLsizei , const GLubyte *, const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint , GLsizei , const GLubyte *, GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint , GLsizei , const GLubyte *, GLdouble *);

PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNV;
PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNV;
PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNV;
PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNV;
PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNV;
PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNV;
#endif /*GL_NV_fragment_program*/

static int gleIntLoad_NV_fragment_program()
{
	int bIsLoaded = 1;
#ifndef GL_NV_fragment_program
	glProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)gleIntGetProcAddress("glProgramNamedParameter4fNV");
	if(!glProgramNamedParameter4fNV) bIsLoaded = 0;
	glProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)gleIntGetProcAddress("glProgramNamedParameter4dNV");
	if(!glProgramNamedParameter4dNV) bIsLoaded = 0;
	glProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)gleIntGetProcAddress("glProgramNamedParameter4fvNV");
	if(!glProgramNamedParameter4fvNV) bIsLoaded = 0;
	glProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)gleIntGetProcAddress("glProgramNamedParameter4dvNV");
	if(!glProgramNamedParameter4dvNV) bIsLoaded = 0;
	glGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)gleIntGetProcAddress("glGetProgramNamedParameterfvNV");
	if(!glGetProgramNamedParameterfvNV) bIsLoaded = 0;
	glGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)gleIntGetProcAddress("glGetProgramNamedParameterdvNV");
	if(!glGetProgramNamedParameterdvNV) bIsLoaded = 0;
#endif /*GL_NV_fragment_program*/
	return bIsLoaded;
}



#ifndef GL_NV_framebuffer_multisample_coverage
typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLenum , GLsizei , GLsizei );

PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glRenderbufferStorageMultisampleCoverageNV;
#endif /*GL_NV_framebuffer_multisample_coverage*/

static int gleIntLoad_NV_framebuffer_multisample_coverage()
{
	int bIsLoaded = 1;
#ifndef GL_NV_framebuffer_multisample_coverage
	glRenderbufferStorageMultisampleCoverageNV = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)gleIntGetProcAddress("glRenderbufferStorageMultisampleCoverageNV");
	if(!glRenderbufferStorageMultisampleCoverageNV) bIsLoaded = 0;
#endif /*GL_NV_framebuffer_multisample_coverage*/
	return bIsLoaded;
}
#ifndef GL_NV_geometry_program4
typedef void (GLE_FUNCPTR * PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum , GLenum , GLuint , GLint , GLenum );

PFNGLPROGRAMVERTEXLIMITNVPROC glProgramVertexLimitNV;
PFNGLFRAMEBUFFERTEXTUREEXTPROC glFramebufferTextureEXT;
PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC glFramebufferTextureLayerEXT;
PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC glFramebufferTextureFaceEXT;
#endif /*GL_NV_geometry_program4*/

static int gleIntLoad_NV_geometry_program4()
{
	int bIsLoaded = 1;
#ifndef GL_NV_geometry_program4
	glProgramVertexLimitNV = (PFNGLPROGRAMVERTEXLIMITNVPROC)gleIntGetProcAddress("glProgramVertexLimitNV");
	if(!glProgramVertexLimitNV) bIsLoaded = 0;
	glFramebufferTextureEXT = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)gleIntGetProcAddress("glFramebufferTextureEXT");
	if(!glFramebufferTextureEXT) bIsLoaded = 0;
	glFramebufferTextureLayerEXT = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)gleIntGetProcAddress("glFramebufferTextureLayerEXT");
	if(!glFramebufferTextureLayerEXT) bIsLoaded = 0;
	glFramebufferTextureFaceEXT = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)gleIntGetProcAddress("glFramebufferTextureFaceEXT");
	if(!glFramebufferTextureFaceEXT) bIsLoaded = 0;
#endif /*GL_NV_geometry_program4*/
	return bIsLoaded;
}

#ifndef GL_NV_gpu_program4
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERI4INVPROC)(GLenum , GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)(GLenum , GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)(GLenum , GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)(GLenum , GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)(GLenum , GLuint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERI4INVPROC)(GLenum , GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERI4IVNVPROC)(GLenum , GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)(GLenum , GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERI4UINVPROC)(GLenum , GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)(GLenum , GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)(GLenum , GLuint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)(GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)(GLenum , GLuint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)(GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)(GLenum , GLuint , GLuint *);

PFNGLPROGRAMLOCALPARAMETERI4INVPROC glProgramLocalParameterI4iNV;
PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC glProgramLocalParameterI4ivNV;
PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC glProgramLocalParametersI4ivNV;
PFNGLPROGRAMLOCALPARAMETERI4UINVPROC glProgramLocalParameterI4uiNV;
PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC glProgramLocalParameterI4uivNV;
PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC glProgramLocalParametersI4uivNV;
PFNGLPROGRAMENVPARAMETERI4INVPROC glProgramEnvParameterI4iNV;
PFNGLPROGRAMENVPARAMETERI4IVNVPROC glProgramEnvParameterI4ivNV;
PFNGLPROGRAMENVPARAMETERSI4IVNVPROC glProgramEnvParametersI4ivNV;
PFNGLPROGRAMENVPARAMETERI4UINVPROC glProgramEnvParameterI4uiNV;
PFNGLPROGRAMENVPARAMETERI4UIVNVPROC glProgramEnvParameterI4uivNV;
PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC glProgramEnvParametersI4uivNV;
PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC glGetProgramLocalParameterIivNV;
PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC glGetProgramLocalParameterIuivNV;
PFNGLGETPROGRAMENVPARAMETERIIVNVPROC glGetProgramEnvParameterIivNV;
PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC glGetProgramEnvParameterIuivNV;
#endif /*GL_NV_gpu_program4*/

static int gleIntLoad_NV_gpu_program4()
{
	int bIsLoaded = 1;
#ifndef GL_NV_gpu_program4
	glProgramLocalParameterI4iNV = (PFNGLPROGRAMLOCALPARAMETERI4INVPROC)gleIntGetProcAddress("glProgramLocalParameterI4iNV");
	if(!glProgramLocalParameterI4iNV) bIsLoaded = 0;
	glProgramLocalParameterI4ivNV = (PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)gleIntGetProcAddress("glProgramLocalParameterI4ivNV");
	if(!glProgramLocalParameterI4ivNV) bIsLoaded = 0;
	glProgramLocalParametersI4ivNV = (PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)gleIntGetProcAddress("glProgramLocalParametersI4ivNV");
	if(!glProgramLocalParametersI4ivNV) bIsLoaded = 0;
	glProgramLocalParameterI4uiNV = (PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)gleIntGetProcAddress("glProgramLocalParameterI4uiNV");
	if(!glProgramLocalParameterI4uiNV) bIsLoaded = 0;
	glProgramLocalParameterI4uivNV = (PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)gleIntGetProcAddress("glProgramLocalParameterI4uivNV");
	if(!glProgramLocalParameterI4uivNV) bIsLoaded = 0;
	glProgramLocalParametersI4uivNV = (PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)gleIntGetProcAddress("glProgramLocalParametersI4uivNV");
	if(!glProgramLocalParametersI4uivNV) bIsLoaded = 0;
	glProgramEnvParameterI4iNV = (PFNGLPROGRAMENVPARAMETERI4INVPROC)gleIntGetProcAddress("glProgramEnvParameterI4iNV");
	if(!glProgramEnvParameterI4iNV) bIsLoaded = 0;
	glProgramEnvParameterI4ivNV = (PFNGLPROGRAMENVPARAMETERI4IVNVPROC)gleIntGetProcAddress("glProgramEnvParameterI4ivNV");
	if(!glProgramEnvParameterI4ivNV) bIsLoaded = 0;
	glProgramEnvParametersI4ivNV = (PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)gleIntGetProcAddress("glProgramEnvParametersI4ivNV");
	if(!glProgramEnvParametersI4ivNV) bIsLoaded = 0;
	glProgramEnvParameterI4uiNV = (PFNGLPROGRAMENVPARAMETERI4UINVPROC)gleIntGetProcAddress("glProgramEnvParameterI4uiNV");
	if(!glProgramEnvParameterI4uiNV) bIsLoaded = 0;
	glProgramEnvParameterI4uivNV = (PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)gleIntGetProcAddress("glProgramEnvParameterI4uivNV");
	if(!glProgramEnvParameterI4uivNV) bIsLoaded = 0;
	glProgramEnvParametersI4uivNV = (PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)gleIntGetProcAddress("glProgramEnvParametersI4uivNV");
	if(!glProgramEnvParametersI4uivNV) bIsLoaded = 0;
	glGetProgramLocalParameterIivNV = (PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)gleIntGetProcAddress("glGetProgramLocalParameterIivNV");
	if(!glGetProgramLocalParameterIivNV) bIsLoaded = 0;
	glGetProgramLocalParameterIuivNV = (PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)gleIntGetProcAddress("glGetProgramLocalParameterIuivNV");
	if(!glGetProgramLocalParameterIuivNV) bIsLoaded = 0;
	glGetProgramEnvParameterIivNV = (PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)gleIntGetProcAddress("glGetProgramEnvParameterIivNV");
	if(!glGetProgramEnvParameterIivNV) bIsLoaded = 0;
	glGetProgramEnvParameterIuivNV = (PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)gleIntGetProcAddress("glGetProgramEnvParameterIuivNV");
	if(!glGetProgramEnvParameterIuivNV) bIsLoaded = 0;
#endif /*GL_NV_gpu_program4*/
	return bIsLoaded;
}
#ifndef GL_NV_gpu_program5
typedef void (GLE_FUNCPTR * PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)(GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)(GLenum , GLuint , GLuint *);

PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC glProgramSubroutineParametersuivNV;
PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC glGetProgramSubroutineParameteruivNV;
#endif /*GL_NV_gpu_program5*/

static int gleIntLoad_NV_gpu_program5()
{
	int bIsLoaded = 1;
#ifndef GL_NV_gpu_program5
	glProgramSubroutineParametersuivNV = (PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)gleIntGetProcAddress("glProgramSubroutineParametersuivNV");
	if(!glProgramSubroutineParametersuivNV) bIsLoaded = 0;
	glGetProgramSubroutineParameteruivNV = (PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)gleIntGetProcAddress("glGetProgramSubroutineParameteruivNV");
	if(!glGetProgramSubroutineParameteruivNV) bIsLoaded = 0;
#endif /*GL_NV_gpu_program5*/
	return bIsLoaded;
}
#ifndef GL_NV_gpu_shader5
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1I64NVPROC)(GLint , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2I64NVPROC)(GLint , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3I64NVPROC)(GLint , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4I64NVPROC)(GLint , GLint64EXT , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1I64VNVPROC)(GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2I64VNVPROC)(GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3I64VNVPROC)(GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4I64VNVPROC)(GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UI64NVPROC)(GLint , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UI64NVPROC)(GLint , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UI64NVPROC)(GLint , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UI64NVPROC)(GLint , GLuint64EXT , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UI64VNVPROC)(GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UI64VNVPROC)(GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UI64VNVPROC)(GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UI64VNVPROC)(GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMI64VNVPROC)(GLuint , GLint , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1I64NVPROC)(GLuint , GLint , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2I64NVPROC)(GLuint , GLint , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3I64NVPROC)(GLuint , GLint , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4I64NVPROC)(GLuint , GLint , GLint64EXT , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1I64VNVPROC)(GLuint , GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2I64VNVPROC)(GLuint , GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3I64VNVPROC)(GLuint , GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4I64VNVPROC)(GLuint , GLint , GLsizei , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UI64NVPROC)(GLuint , GLint , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UI64NVPROC)(GLuint , GLint , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UI64NVPROC)(GLuint , GLint , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UI64NVPROC)(GLuint , GLint , GLuint64EXT , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM1UI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM2UI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM3UI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORM4UI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64EXT *);

PFNGLUNIFORM1I64NVPROC glUniform1i64NV;
PFNGLUNIFORM2I64NVPROC glUniform2i64NV;
PFNGLUNIFORM3I64NVPROC glUniform3i64NV;
PFNGLUNIFORM4I64NVPROC glUniform4i64NV;
PFNGLUNIFORM1I64VNVPROC glUniform1i64vNV;
PFNGLUNIFORM2I64VNVPROC glUniform2i64vNV;
PFNGLUNIFORM3I64VNVPROC glUniform3i64vNV;
PFNGLUNIFORM4I64VNVPROC glUniform4i64vNV;
PFNGLUNIFORM1UI64NVPROC glUniform1ui64NV;
PFNGLUNIFORM2UI64NVPROC glUniform2ui64NV;
PFNGLUNIFORM3UI64NVPROC glUniform3ui64NV;
PFNGLUNIFORM4UI64NVPROC glUniform4ui64NV;
PFNGLUNIFORM1UI64VNVPROC glUniform1ui64vNV;
PFNGLUNIFORM2UI64VNVPROC glUniform2ui64vNV;
PFNGLUNIFORM3UI64VNVPROC glUniform3ui64vNV;
PFNGLUNIFORM4UI64VNVPROC glUniform4ui64vNV;
PFNGLGETUNIFORMI64VNVPROC glGetUniformi64vNV;
PFNGLPROGRAMUNIFORM1I64NVPROC glProgramUniform1i64NV;
PFNGLPROGRAMUNIFORM2I64NVPROC glProgramUniform2i64NV;
PFNGLPROGRAMUNIFORM3I64NVPROC glProgramUniform3i64NV;
PFNGLPROGRAMUNIFORM4I64NVPROC glProgramUniform4i64NV;
PFNGLPROGRAMUNIFORM1I64VNVPROC glProgramUniform1i64vNV;
PFNGLPROGRAMUNIFORM2I64VNVPROC glProgramUniform2i64vNV;
PFNGLPROGRAMUNIFORM3I64VNVPROC glProgramUniform3i64vNV;
PFNGLPROGRAMUNIFORM4I64VNVPROC glProgramUniform4i64vNV;
PFNGLPROGRAMUNIFORM1UI64NVPROC glProgramUniform1ui64NV;
PFNGLPROGRAMUNIFORM2UI64NVPROC glProgramUniform2ui64NV;
PFNGLPROGRAMUNIFORM3UI64NVPROC glProgramUniform3ui64NV;
PFNGLPROGRAMUNIFORM4UI64NVPROC glProgramUniform4ui64NV;
PFNGLPROGRAMUNIFORM1UI64VNVPROC glProgramUniform1ui64vNV;
PFNGLPROGRAMUNIFORM2UI64VNVPROC glProgramUniform2ui64vNV;
PFNGLPROGRAMUNIFORM3UI64VNVPROC glProgramUniform3ui64vNV;
PFNGLPROGRAMUNIFORM4UI64VNVPROC glProgramUniform4ui64vNV;
#endif /*GL_NV_gpu_shader5*/

static int gleIntLoad_NV_gpu_shader5()
{
	int bIsLoaded = 1;
#ifndef GL_NV_gpu_shader5
	glUniform1i64NV = (PFNGLUNIFORM1I64NVPROC)gleIntGetProcAddress("glUniform1i64NV");
	if(!glUniform1i64NV) bIsLoaded = 0;
	glUniform2i64NV = (PFNGLUNIFORM2I64NVPROC)gleIntGetProcAddress("glUniform2i64NV");
	if(!glUniform2i64NV) bIsLoaded = 0;
	glUniform3i64NV = (PFNGLUNIFORM3I64NVPROC)gleIntGetProcAddress("glUniform3i64NV");
	if(!glUniform3i64NV) bIsLoaded = 0;
	glUniform4i64NV = (PFNGLUNIFORM4I64NVPROC)gleIntGetProcAddress("glUniform4i64NV");
	if(!glUniform4i64NV) bIsLoaded = 0;
	glUniform1i64vNV = (PFNGLUNIFORM1I64VNVPROC)gleIntGetProcAddress("glUniform1i64vNV");
	if(!glUniform1i64vNV) bIsLoaded = 0;
	glUniform2i64vNV = (PFNGLUNIFORM2I64VNVPROC)gleIntGetProcAddress("glUniform2i64vNV");
	if(!glUniform2i64vNV) bIsLoaded = 0;
	glUniform3i64vNV = (PFNGLUNIFORM3I64VNVPROC)gleIntGetProcAddress("glUniform3i64vNV");
	if(!glUniform3i64vNV) bIsLoaded = 0;
	glUniform4i64vNV = (PFNGLUNIFORM4I64VNVPROC)gleIntGetProcAddress("glUniform4i64vNV");
	if(!glUniform4i64vNV) bIsLoaded = 0;
	glUniform1ui64NV = (PFNGLUNIFORM1UI64NVPROC)gleIntGetProcAddress("glUniform1ui64NV");
	if(!glUniform1ui64NV) bIsLoaded = 0;
	glUniform2ui64NV = (PFNGLUNIFORM2UI64NVPROC)gleIntGetProcAddress("glUniform2ui64NV");
	if(!glUniform2ui64NV) bIsLoaded = 0;
	glUniform3ui64NV = (PFNGLUNIFORM3UI64NVPROC)gleIntGetProcAddress("glUniform3ui64NV");
	if(!glUniform3ui64NV) bIsLoaded = 0;
	glUniform4ui64NV = (PFNGLUNIFORM4UI64NVPROC)gleIntGetProcAddress("glUniform4ui64NV");
	if(!glUniform4ui64NV) bIsLoaded = 0;
	glUniform1ui64vNV = (PFNGLUNIFORM1UI64VNVPROC)gleIntGetProcAddress("glUniform1ui64vNV");
	if(!glUniform1ui64vNV) bIsLoaded = 0;
	glUniform2ui64vNV = (PFNGLUNIFORM2UI64VNVPROC)gleIntGetProcAddress("glUniform2ui64vNV");
	if(!glUniform2ui64vNV) bIsLoaded = 0;
	glUniform3ui64vNV = (PFNGLUNIFORM3UI64VNVPROC)gleIntGetProcAddress("glUniform3ui64vNV");
	if(!glUniform3ui64vNV) bIsLoaded = 0;
	glUniform4ui64vNV = (PFNGLUNIFORM4UI64VNVPROC)gleIntGetProcAddress("glUniform4ui64vNV");
	if(!glUniform4ui64vNV) bIsLoaded = 0;
	glGetUniformi64vNV = (PFNGLGETUNIFORMI64VNVPROC)gleIntGetProcAddress("glGetUniformi64vNV");
	if(!glGetUniformi64vNV) bIsLoaded = 0;
	glProgramUniform1i64NV = (PFNGLPROGRAMUNIFORM1I64NVPROC)gleIntGetProcAddress("glProgramUniform1i64NV");
	if(!glProgramUniform1i64NV) bIsLoaded = 0;
	glProgramUniform2i64NV = (PFNGLPROGRAMUNIFORM2I64NVPROC)gleIntGetProcAddress("glProgramUniform2i64NV");
	if(!glProgramUniform2i64NV) bIsLoaded = 0;
	glProgramUniform3i64NV = (PFNGLPROGRAMUNIFORM3I64NVPROC)gleIntGetProcAddress("glProgramUniform3i64NV");
	if(!glProgramUniform3i64NV) bIsLoaded = 0;
	glProgramUniform4i64NV = (PFNGLPROGRAMUNIFORM4I64NVPROC)gleIntGetProcAddress("glProgramUniform4i64NV");
	if(!glProgramUniform4i64NV) bIsLoaded = 0;
	glProgramUniform1i64vNV = (PFNGLPROGRAMUNIFORM1I64VNVPROC)gleIntGetProcAddress("glProgramUniform1i64vNV");
	if(!glProgramUniform1i64vNV) bIsLoaded = 0;
	glProgramUniform2i64vNV = (PFNGLPROGRAMUNIFORM2I64VNVPROC)gleIntGetProcAddress("glProgramUniform2i64vNV");
	if(!glProgramUniform2i64vNV) bIsLoaded = 0;
	glProgramUniform3i64vNV = (PFNGLPROGRAMUNIFORM3I64VNVPROC)gleIntGetProcAddress("glProgramUniform3i64vNV");
	if(!glProgramUniform3i64vNV) bIsLoaded = 0;
	glProgramUniform4i64vNV = (PFNGLPROGRAMUNIFORM4I64VNVPROC)gleIntGetProcAddress("glProgramUniform4i64vNV");
	if(!glProgramUniform4i64vNV) bIsLoaded = 0;
	glProgramUniform1ui64NV = (PFNGLPROGRAMUNIFORM1UI64NVPROC)gleIntGetProcAddress("glProgramUniform1ui64NV");
	if(!glProgramUniform1ui64NV) bIsLoaded = 0;
	glProgramUniform2ui64NV = (PFNGLPROGRAMUNIFORM2UI64NVPROC)gleIntGetProcAddress("glProgramUniform2ui64NV");
	if(!glProgramUniform2ui64NV) bIsLoaded = 0;
	glProgramUniform3ui64NV = (PFNGLPROGRAMUNIFORM3UI64NVPROC)gleIntGetProcAddress("glProgramUniform3ui64NV");
	if(!glProgramUniform3ui64NV) bIsLoaded = 0;
	glProgramUniform4ui64NV = (PFNGLPROGRAMUNIFORM4UI64NVPROC)gleIntGetProcAddress("glProgramUniform4ui64NV");
	if(!glProgramUniform4ui64NV) bIsLoaded = 0;
	glProgramUniform1ui64vNV = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)gleIntGetProcAddress("glProgramUniform1ui64vNV");
	if(!glProgramUniform1ui64vNV) bIsLoaded = 0;
	glProgramUniform2ui64vNV = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)gleIntGetProcAddress("glProgramUniform2ui64vNV");
	if(!glProgramUniform2ui64vNV) bIsLoaded = 0;
	glProgramUniform3ui64vNV = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)gleIntGetProcAddress("glProgramUniform3ui64vNV");
	if(!glProgramUniform3ui64vNV) bIsLoaded = 0;
	glProgramUniform4ui64vNV = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)gleIntGetProcAddress("glProgramUniform4ui64vNV");
	if(!glProgramUniform4ui64vNV) bIsLoaded = 0;
#endif /*GL_NV_gpu_shader5*/
	return bIsLoaded;
}
#ifndef GL_NV_half_float
typedef void (GLE_FUNCPTR * PFNGLVERTEX2HNVPROC)(GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEX2HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX3HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEX3HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX4HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEX4HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1HNVPROC)(GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2HNVPROC)(GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1HNVPROC)(GLenum , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1HVNVPROC)(GLenum , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2HNVPROC)(GLenum , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2HVNVPROC)(GLenum , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3HNVPROC)(GLenum , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3HVNVPROC)(GLenum , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4HNVPROC)(GLenum , GLhalfNV , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4HVNVPROC)(GLenum , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDHNVPROC)(GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDHVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3HNVPROC)(GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3HVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTHNVPROC)(GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTHVNVPROC)(const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1HNVPROC)(GLuint , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1HVNVPROC)(GLuint , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2HNVPROC)(GLuint , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2HVNVPROC)(GLuint , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3HNVPROC)(GLuint , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3HVNVPROC)(GLuint , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4HNVPROC)(GLuint , GLhalfNV , GLhalfNV , GLhalfNV , GLhalfNV );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4HVNVPROC)(GLuint , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS1HVNVPROC)(GLuint , GLsizei , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS2HVNVPROC)(GLuint , GLsizei , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS3HVNVPROC)(GLuint , GLsizei , const GLhalfNV *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS4HVNVPROC)(GLuint , GLsizei , const GLhalfNV *);

PFNGLVERTEX2HNVPROC glVertex2hNV;
PFNGLVERTEX2HVNVPROC glVertex2hvNV;
PFNGLVERTEX3HNVPROC glVertex3hNV;
PFNGLVERTEX3HVNVPROC glVertex3hvNV;
PFNGLVERTEX4HNVPROC glVertex4hNV;
PFNGLVERTEX4HVNVPROC glVertex4hvNV;
PFNGLNORMAL3HNVPROC glNormal3hNV;
PFNGLNORMAL3HVNVPROC glNormal3hvNV;
PFNGLCOLOR3HNVPROC glColor3hNV;
PFNGLCOLOR3HVNVPROC glColor3hvNV;
PFNGLCOLOR4HNVPROC glColor4hNV;
PFNGLCOLOR4HVNVPROC glColor4hvNV;
PFNGLTEXCOORD1HNVPROC glTexCoord1hNV;
PFNGLTEXCOORD1HVNVPROC glTexCoord1hvNV;
PFNGLTEXCOORD2HNVPROC glTexCoord2hNV;
PFNGLTEXCOORD2HVNVPROC glTexCoord2hvNV;
PFNGLTEXCOORD3HNVPROC glTexCoord3hNV;
PFNGLTEXCOORD3HVNVPROC glTexCoord3hvNV;
PFNGLTEXCOORD4HNVPROC glTexCoord4hNV;
PFNGLTEXCOORD4HVNVPROC glTexCoord4hvNV;
PFNGLMULTITEXCOORD1HNVPROC glMultiTexCoord1hNV;
PFNGLMULTITEXCOORD1HVNVPROC glMultiTexCoord1hvNV;
PFNGLMULTITEXCOORD2HNVPROC glMultiTexCoord2hNV;
PFNGLMULTITEXCOORD2HVNVPROC glMultiTexCoord2hvNV;
PFNGLMULTITEXCOORD3HNVPROC glMultiTexCoord3hNV;
PFNGLMULTITEXCOORD3HVNVPROC glMultiTexCoord3hvNV;
PFNGLMULTITEXCOORD4HNVPROC glMultiTexCoord4hNV;
PFNGLMULTITEXCOORD4HVNVPROC glMultiTexCoord4hvNV;
PFNGLFOGCOORDHNVPROC glFogCoordhNV;
PFNGLFOGCOORDHVNVPROC glFogCoordhvNV;
PFNGLSECONDARYCOLOR3HNVPROC glSecondaryColor3hNV;
PFNGLSECONDARYCOLOR3HVNVPROC glSecondaryColor3hvNV;
PFNGLVERTEXWEIGHTHNVPROC glVertexWeighthNV;
PFNGLVERTEXWEIGHTHVNVPROC glVertexWeighthvNV;
PFNGLVERTEXATTRIB1HNVPROC glVertexAttrib1hNV;
PFNGLVERTEXATTRIB1HVNVPROC glVertexAttrib1hvNV;
PFNGLVERTEXATTRIB2HNVPROC glVertexAttrib2hNV;
PFNGLVERTEXATTRIB2HVNVPROC glVertexAttrib2hvNV;
PFNGLVERTEXATTRIB3HNVPROC glVertexAttrib3hNV;
PFNGLVERTEXATTRIB3HVNVPROC glVertexAttrib3hvNV;
PFNGLVERTEXATTRIB4HNVPROC glVertexAttrib4hNV;
PFNGLVERTEXATTRIB4HVNVPROC glVertexAttrib4hvNV;
PFNGLVERTEXATTRIBS1HVNVPROC glVertexAttribs1hvNV;
PFNGLVERTEXATTRIBS2HVNVPROC glVertexAttribs2hvNV;
PFNGLVERTEXATTRIBS3HVNVPROC glVertexAttribs3hvNV;
PFNGLVERTEXATTRIBS4HVNVPROC glVertexAttribs4hvNV;
#endif /*GL_NV_half_float*/

static int gleIntLoad_NV_half_float()
{
	int bIsLoaded = 1;
#ifndef GL_NV_half_float
	glVertex2hNV = (PFNGLVERTEX2HNVPROC)gleIntGetProcAddress("glVertex2hNV");
	if(!glVertex2hNV) bIsLoaded = 0;
	glVertex2hvNV = (PFNGLVERTEX2HVNVPROC)gleIntGetProcAddress("glVertex2hvNV");
	if(!glVertex2hvNV) bIsLoaded = 0;
	glVertex3hNV = (PFNGLVERTEX3HNVPROC)gleIntGetProcAddress("glVertex3hNV");
	if(!glVertex3hNV) bIsLoaded = 0;
	glVertex3hvNV = (PFNGLVERTEX3HVNVPROC)gleIntGetProcAddress("glVertex3hvNV");
	if(!glVertex3hvNV) bIsLoaded = 0;
	glVertex4hNV = (PFNGLVERTEX4HNVPROC)gleIntGetProcAddress("glVertex4hNV");
	if(!glVertex4hNV) bIsLoaded = 0;
	glVertex4hvNV = (PFNGLVERTEX4HVNVPROC)gleIntGetProcAddress("glVertex4hvNV");
	if(!glVertex4hvNV) bIsLoaded = 0;
	glNormal3hNV = (PFNGLNORMAL3HNVPROC)gleIntGetProcAddress("glNormal3hNV");
	if(!glNormal3hNV) bIsLoaded = 0;
	glNormal3hvNV = (PFNGLNORMAL3HVNVPROC)gleIntGetProcAddress("glNormal3hvNV");
	if(!glNormal3hvNV) bIsLoaded = 0;
	glColor3hNV = (PFNGLCOLOR3HNVPROC)gleIntGetProcAddress("glColor3hNV");
	if(!glColor3hNV) bIsLoaded = 0;
	glColor3hvNV = (PFNGLCOLOR3HVNVPROC)gleIntGetProcAddress("glColor3hvNV");
	if(!glColor3hvNV) bIsLoaded = 0;
	glColor4hNV = (PFNGLCOLOR4HNVPROC)gleIntGetProcAddress("glColor4hNV");
	if(!glColor4hNV) bIsLoaded = 0;
	glColor4hvNV = (PFNGLCOLOR4HVNVPROC)gleIntGetProcAddress("glColor4hvNV");
	if(!glColor4hvNV) bIsLoaded = 0;
	glTexCoord1hNV = (PFNGLTEXCOORD1HNVPROC)gleIntGetProcAddress("glTexCoord1hNV");
	if(!glTexCoord1hNV) bIsLoaded = 0;
	glTexCoord1hvNV = (PFNGLTEXCOORD1HVNVPROC)gleIntGetProcAddress("glTexCoord1hvNV");
	if(!glTexCoord1hvNV) bIsLoaded = 0;
	glTexCoord2hNV = (PFNGLTEXCOORD2HNVPROC)gleIntGetProcAddress("glTexCoord2hNV");
	if(!glTexCoord2hNV) bIsLoaded = 0;
	glTexCoord2hvNV = (PFNGLTEXCOORD2HVNVPROC)gleIntGetProcAddress("glTexCoord2hvNV");
	if(!glTexCoord2hvNV) bIsLoaded = 0;
	glTexCoord3hNV = (PFNGLTEXCOORD3HNVPROC)gleIntGetProcAddress("glTexCoord3hNV");
	if(!glTexCoord3hNV) bIsLoaded = 0;
	glTexCoord3hvNV = (PFNGLTEXCOORD3HVNVPROC)gleIntGetProcAddress("glTexCoord3hvNV");
	if(!glTexCoord3hvNV) bIsLoaded = 0;
	glTexCoord4hNV = (PFNGLTEXCOORD4HNVPROC)gleIntGetProcAddress("glTexCoord4hNV");
	if(!glTexCoord4hNV) bIsLoaded = 0;
	glTexCoord4hvNV = (PFNGLTEXCOORD4HVNVPROC)gleIntGetProcAddress("glTexCoord4hvNV");
	if(!glTexCoord4hvNV) bIsLoaded = 0;
	glMultiTexCoord1hNV = (PFNGLMULTITEXCOORD1HNVPROC)gleIntGetProcAddress("glMultiTexCoord1hNV");
	if(!glMultiTexCoord1hNV) bIsLoaded = 0;
	glMultiTexCoord1hvNV = (PFNGLMULTITEXCOORD1HVNVPROC)gleIntGetProcAddress("glMultiTexCoord1hvNV");
	if(!glMultiTexCoord1hvNV) bIsLoaded = 0;
	glMultiTexCoord2hNV = (PFNGLMULTITEXCOORD2HNVPROC)gleIntGetProcAddress("glMultiTexCoord2hNV");
	if(!glMultiTexCoord2hNV) bIsLoaded = 0;
	glMultiTexCoord2hvNV = (PFNGLMULTITEXCOORD2HVNVPROC)gleIntGetProcAddress("glMultiTexCoord2hvNV");
	if(!glMultiTexCoord2hvNV) bIsLoaded = 0;
	glMultiTexCoord3hNV = (PFNGLMULTITEXCOORD3HNVPROC)gleIntGetProcAddress("glMultiTexCoord3hNV");
	if(!glMultiTexCoord3hNV) bIsLoaded = 0;
	glMultiTexCoord3hvNV = (PFNGLMULTITEXCOORD3HVNVPROC)gleIntGetProcAddress("glMultiTexCoord3hvNV");
	if(!glMultiTexCoord3hvNV) bIsLoaded = 0;
	glMultiTexCoord4hNV = (PFNGLMULTITEXCOORD4HNVPROC)gleIntGetProcAddress("glMultiTexCoord4hNV");
	if(!glMultiTexCoord4hNV) bIsLoaded = 0;
	glMultiTexCoord4hvNV = (PFNGLMULTITEXCOORD4HVNVPROC)gleIntGetProcAddress("glMultiTexCoord4hvNV");
	if(!glMultiTexCoord4hvNV) bIsLoaded = 0;
	glFogCoordhNV = (PFNGLFOGCOORDHNVPROC)gleIntGetProcAddress("glFogCoordhNV");
	if(!glFogCoordhNV) bIsLoaded = 0;
	glFogCoordhvNV = (PFNGLFOGCOORDHVNVPROC)gleIntGetProcAddress("glFogCoordhvNV");
	if(!glFogCoordhvNV) bIsLoaded = 0;
	glSecondaryColor3hNV = (PFNGLSECONDARYCOLOR3HNVPROC)gleIntGetProcAddress("glSecondaryColor3hNV");
	if(!glSecondaryColor3hNV) bIsLoaded = 0;
	glSecondaryColor3hvNV = (PFNGLSECONDARYCOLOR3HVNVPROC)gleIntGetProcAddress("glSecondaryColor3hvNV");
	if(!glSecondaryColor3hvNV) bIsLoaded = 0;
	glVertexWeighthNV = (PFNGLVERTEXWEIGHTHNVPROC)gleIntGetProcAddress("glVertexWeighthNV");
	if(!glVertexWeighthNV) bIsLoaded = 0;
	glVertexWeighthvNV = (PFNGLVERTEXWEIGHTHVNVPROC)gleIntGetProcAddress("glVertexWeighthvNV");
	if(!glVertexWeighthvNV) bIsLoaded = 0;
	glVertexAttrib1hNV = (PFNGLVERTEXATTRIB1HNVPROC)gleIntGetProcAddress("glVertexAttrib1hNV");
	if(!glVertexAttrib1hNV) bIsLoaded = 0;
	glVertexAttrib1hvNV = (PFNGLVERTEXATTRIB1HVNVPROC)gleIntGetProcAddress("glVertexAttrib1hvNV");
	if(!glVertexAttrib1hvNV) bIsLoaded = 0;
	glVertexAttrib2hNV = (PFNGLVERTEXATTRIB2HNVPROC)gleIntGetProcAddress("glVertexAttrib2hNV");
	if(!glVertexAttrib2hNV) bIsLoaded = 0;
	glVertexAttrib2hvNV = (PFNGLVERTEXATTRIB2HVNVPROC)gleIntGetProcAddress("glVertexAttrib2hvNV");
	if(!glVertexAttrib2hvNV) bIsLoaded = 0;
	glVertexAttrib3hNV = (PFNGLVERTEXATTRIB3HNVPROC)gleIntGetProcAddress("glVertexAttrib3hNV");
	if(!glVertexAttrib3hNV) bIsLoaded = 0;
	glVertexAttrib3hvNV = (PFNGLVERTEXATTRIB3HVNVPROC)gleIntGetProcAddress("glVertexAttrib3hvNV");
	if(!glVertexAttrib3hvNV) bIsLoaded = 0;
	glVertexAttrib4hNV = (PFNGLVERTEXATTRIB4HNVPROC)gleIntGetProcAddress("glVertexAttrib4hNV");
	if(!glVertexAttrib4hNV) bIsLoaded = 0;
	glVertexAttrib4hvNV = (PFNGLVERTEXATTRIB4HVNVPROC)gleIntGetProcAddress("glVertexAttrib4hvNV");
	if(!glVertexAttrib4hvNV) bIsLoaded = 0;
	glVertexAttribs1hvNV = (PFNGLVERTEXATTRIBS1HVNVPROC)gleIntGetProcAddress("glVertexAttribs1hvNV");
	if(!glVertexAttribs1hvNV) bIsLoaded = 0;
	glVertexAttribs2hvNV = (PFNGLVERTEXATTRIBS2HVNVPROC)gleIntGetProcAddress("glVertexAttribs2hvNV");
	if(!glVertexAttribs2hvNV) bIsLoaded = 0;
	glVertexAttribs3hvNV = (PFNGLVERTEXATTRIBS3HVNVPROC)gleIntGetProcAddress("glVertexAttribs3hvNV");
	if(!glVertexAttribs3hvNV) bIsLoaded = 0;
	glVertexAttribs4hvNV = (PFNGLVERTEXATTRIBS4HVNVPROC)gleIntGetProcAddress("glVertexAttribs4hvNV");
	if(!glVertexAttribs4hvNV) bIsLoaded = 0;
#endif /*GL_NV_half_float*/
	return bIsLoaded;
}



#ifndef GL_NV_occlusion_query
typedef void (GLE_FUNCPTR * PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISOCCLUSIONQUERYNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDOCCLUSIONQUERYNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint , GLenum , GLuint *);

PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNV;
PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNV;
PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNV;
PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNV;
PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNV;
PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNV;
PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNV;
#endif /*GL_NV_occlusion_query*/

static int gleIntLoad_NV_occlusion_query()
{
	int bIsLoaded = 1;
#ifndef GL_NV_occlusion_query
	glGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC)gleIntGetProcAddress("glGenOcclusionQueriesNV");
	if(!glGenOcclusionQueriesNV) bIsLoaded = 0;
	glDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)gleIntGetProcAddress("glDeleteOcclusionQueriesNV");
	if(!glDeleteOcclusionQueriesNV) bIsLoaded = 0;
	glIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC)gleIntGetProcAddress("glIsOcclusionQueryNV");
	if(!glIsOcclusionQueryNV) bIsLoaded = 0;
	glBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC)gleIntGetProcAddress("glBeginOcclusionQueryNV");
	if(!glBeginOcclusionQueryNV) bIsLoaded = 0;
	glEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC)gleIntGetProcAddress("glEndOcclusionQueryNV");
	if(!glEndOcclusionQueryNV) bIsLoaded = 0;
	glGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC)gleIntGetProcAddress("glGetOcclusionQueryivNV");
	if(!glGetOcclusionQueryivNV) bIsLoaded = 0;
	glGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)gleIntGetProcAddress("glGetOcclusionQueryuivNV");
	if(!glGetOcclusionQueryuivNV) bIsLoaded = 0;
#endif /*GL_NV_occlusion_query*/
	return bIsLoaded;
}

#ifndef GL_NV_parameter_buffer_object
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLuint *);

PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC glProgramBufferParametersfvNV;
PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC glProgramBufferParametersIivNV;
PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC glProgramBufferParametersIuivNV;
#endif /*GL_NV_parameter_buffer_object*/

static int gleIntLoad_NV_parameter_buffer_object()
{
	int bIsLoaded = 1;
#ifndef GL_NV_parameter_buffer_object
	glProgramBufferParametersfvNV = (PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)gleIntGetProcAddress("glProgramBufferParametersfvNV");
	if(!glProgramBufferParametersfvNV) bIsLoaded = 0;
	glProgramBufferParametersIivNV = (PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)gleIntGetProcAddress("glProgramBufferParametersIivNV");
	if(!glProgramBufferParametersIivNV) bIsLoaded = 0;
	glProgramBufferParametersIuivNV = (PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)gleIntGetProcAddress("glProgramBufferParametersIuivNV");
	if(!glProgramBufferParametersIuivNV) bIsLoaded = 0;
#endif /*GL_NV_parameter_buffer_object*/
	return bIsLoaded;
}

#ifndef GL_NV_path_rendering
typedef GLuint (GLE_FUNCPTR * PFNGLGENPATHSNVPROC)(GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDELETEPATHSNVPROC)(GLuint , GLsizei );
typedef GLboolean (GLE_FUNCPTR * PFNGLISPATHNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPATHCOMMANDSNVPROC)(GLuint , GLsizei , const GLubyte *, GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPATHCOORDSNVPROC)(GLuint , GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPATHSUBCOMMANDSNVPROC)(GLuint , GLsizei , GLsizei , GLsizei , const GLubyte *, GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPATHSUBCOORDSNVPROC)(GLuint , GLsizei , GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPATHSTRINGNVPROC)(GLuint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPATHGLYPHSNVPROC)(GLuint , GLenum , const GLvoid *, GLbitfield , GLsizei , GLenum , const GLvoid *, GLenum , GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPATHGLYPHRANGENVPROC)(GLuint , GLenum , const GLvoid *, GLbitfield , GLuint , GLsizei , GLenum , GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWEIGHTPATHSNVPROC)(GLuint , GLsizei , const GLuint *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOPYPATHNVPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLINTERPOLATEPATHSNVPROC)(GLuint , GLuint , GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMPATHNVPROC)(GLuint , GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHPARAMETERIVNVPROC)(GLuint , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPATHPARAMETERINVPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPATHPARAMETERFVNVPROC)(GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHPARAMETERFNVPROC)(GLuint , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPATHDASHARRAYNVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHSTENCILFUNCNVPROC)(GLenum , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPATHSTENCILDEPTHOFFSETNVPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFILLPATHNVPROC)(GLuint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSTENCILSTROKEPATHNVPROC)(GLuint , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFILLPATHINSTANCEDNVPROC)(GLsizei , GLenum , const GLvoid *, GLuint , GLenum , GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)(GLsizei , GLenum , const GLvoid *, GLuint , GLint , GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHCOVERDEPTHFUNCNVPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLPATHCOLORGENNVPROC)(GLenum , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHTEXGENNVPROC)(GLenum , GLenum , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPATHFOGGENNVPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLCOVERFILLPATHNVPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLCOVERSTROKEPATHNVPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLCOVERFILLPATHINSTANCEDNVPROC)(GLsizei , GLenum , const GLvoid *, GLuint , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)(GLsizei , GLenum , const GLvoid *, GLuint , GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHPARAMETERIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHPARAMETERFVNVPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHCOMMANDSNVPROC)(GLuint , GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHCOORDSNVPROC)(GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHDASHARRAYNVPROC)(GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHMETRICSNVPROC)(GLbitfield , GLsizei , GLenum , const GLvoid *, GLuint , GLsizei , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHMETRICRANGENVPROC)(GLbitfield , GLuint , GLsizei , GLsizei , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHSPACINGNVPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLuint , GLfloat , GLfloat , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHCOLORGENIVNVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHCOLORGENFVNVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHTEXGENIVNVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPATHTEXGENFVNVPROC)(GLenum , GLenum , GLfloat *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISPOINTINFILLPATHNVPROC)(GLuint , GLuint , GLfloat , GLfloat );
typedef GLboolean (GLE_FUNCPTR * PFNGLISPOINTINSTROKEPATHNVPROC)(GLuint , GLfloat , GLfloat );
typedef GLfloat (GLE_FUNCPTR * PFNGLGETPATHLENGTHNVPROC)(GLuint , GLsizei , GLsizei );
typedef GLboolean (GLE_FUNCPTR * PFNGLPOINTALONGPATHNVPROC)(GLuint , GLsizei , GLsizei , GLfloat , GLfloat *, GLfloat *, GLfloat *, GLfloat *);

PFNGLGENPATHSNVPROC glGenPathsNV;
PFNGLDELETEPATHSNVPROC glDeletePathsNV;
PFNGLISPATHNVPROC glIsPathNV;
PFNGLPATHCOMMANDSNVPROC glPathCommandsNV;
PFNGLPATHCOORDSNVPROC glPathCoordsNV;
PFNGLPATHSUBCOMMANDSNVPROC glPathSubCommandsNV;
PFNGLPATHSUBCOORDSNVPROC glPathSubCoordsNV;
PFNGLPATHSTRINGNVPROC glPathStringNV;
PFNGLPATHGLYPHSNVPROC glPathGlyphsNV;
PFNGLPATHGLYPHRANGENVPROC glPathGlyphRangeNV;
PFNGLWEIGHTPATHSNVPROC glWeightPathsNV;
PFNGLCOPYPATHNVPROC glCopyPathNV;
PFNGLINTERPOLATEPATHSNVPROC glInterpolatePathsNV;
PFNGLTRANSFORMPATHNVPROC glTransformPathNV;
PFNGLPATHPARAMETERIVNVPROC glPathParameterivNV;
PFNGLPATHPARAMETERINVPROC glPathParameteriNV;
PFNGLPATHPARAMETERFVNVPROC glPathParameterfvNV;
PFNGLPATHPARAMETERFNVPROC glPathParameterfNV;
PFNGLPATHDASHARRAYNVPROC glPathDashArrayNV;
PFNGLPATHSTENCILFUNCNVPROC glPathStencilFuncNV;
PFNGLPATHSTENCILDEPTHOFFSETNVPROC glPathStencilDepthOffsetNV;
PFNGLSTENCILFILLPATHNVPROC glStencilFillPathNV;
PFNGLSTENCILSTROKEPATHNVPROC glStencilStrokePathNV;
PFNGLSTENCILFILLPATHINSTANCEDNVPROC glStencilFillPathInstancedNV;
PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC glStencilStrokePathInstancedNV;
PFNGLPATHCOVERDEPTHFUNCNVPROC glPathCoverDepthFuncNV;
PFNGLPATHCOLORGENNVPROC glPathColorGenNV;
PFNGLPATHTEXGENNVPROC glPathTexGenNV;
PFNGLPATHFOGGENNVPROC glPathFogGenNV;
PFNGLCOVERFILLPATHNVPROC glCoverFillPathNV;
PFNGLCOVERSTROKEPATHNVPROC glCoverStrokePathNV;
PFNGLCOVERFILLPATHINSTANCEDNVPROC glCoverFillPathInstancedNV;
PFNGLCOVERSTROKEPATHINSTANCEDNVPROC glCoverStrokePathInstancedNV;
PFNGLGETPATHPARAMETERIVNVPROC glGetPathParameterivNV;
PFNGLGETPATHPARAMETERFVNVPROC glGetPathParameterfvNV;
PFNGLGETPATHCOMMANDSNVPROC glGetPathCommandsNV;
PFNGLGETPATHCOORDSNVPROC glGetPathCoordsNV;
PFNGLGETPATHDASHARRAYNVPROC glGetPathDashArrayNV;
PFNGLGETPATHMETRICSNVPROC glGetPathMetricsNV;
PFNGLGETPATHMETRICRANGENVPROC glGetPathMetricRangeNV;
PFNGLGETPATHSPACINGNVPROC glGetPathSpacingNV;
PFNGLGETPATHCOLORGENIVNVPROC glGetPathColorGenivNV;
PFNGLGETPATHCOLORGENFVNVPROC glGetPathColorGenfvNV;
PFNGLGETPATHTEXGENIVNVPROC glGetPathTexGenivNV;
PFNGLGETPATHTEXGENFVNVPROC glGetPathTexGenfvNV;
PFNGLISPOINTINFILLPATHNVPROC glIsPointInFillPathNV;
PFNGLISPOINTINSTROKEPATHNVPROC glIsPointInStrokePathNV;
PFNGLGETPATHLENGTHNVPROC glGetPathLengthNV;
PFNGLPOINTALONGPATHNVPROC glPointAlongPathNV;
#endif /*GL_NV_path_rendering*/

static int gleIntLoad_NV_path_rendering()
{
	int bIsLoaded = 1;
#ifndef GL_NV_path_rendering
	glGenPathsNV = (PFNGLGENPATHSNVPROC)gleIntGetProcAddress("glGenPathsNV");
	if(!glGenPathsNV) bIsLoaded = 0;
	glDeletePathsNV = (PFNGLDELETEPATHSNVPROC)gleIntGetProcAddress("glDeletePathsNV");
	if(!glDeletePathsNV) bIsLoaded = 0;
	glIsPathNV = (PFNGLISPATHNVPROC)gleIntGetProcAddress("glIsPathNV");
	if(!glIsPathNV) bIsLoaded = 0;
	glPathCommandsNV = (PFNGLPATHCOMMANDSNVPROC)gleIntGetProcAddress("glPathCommandsNV");
	if(!glPathCommandsNV) bIsLoaded = 0;
	glPathCoordsNV = (PFNGLPATHCOORDSNVPROC)gleIntGetProcAddress("glPathCoordsNV");
	if(!glPathCoordsNV) bIsLoaded = 0;
	glPathSubCommandsNV = (PFNGLPATHSUBCOMMANDSNVPROC)gleIntGetProcAddress("glPathSubCommandsNV");
	if(!glPathSubCommandsNV) bIsLoaded = 0;
	glPathSubCoordsNV = (PFNGLPATHSUBCOORDSNVPROC)gleIntGetProcAddress("glPathSubCoordsNV");
	if(!glPathSubCoordsNV) bIsLoaded = 0;
	glPathStringNV = (PFNGLPATHSTRINGNVPROC)gleIntGetProcAddress("glPathStringNV");
	if(!glPathStringNV) bIsLoaded = 0;
	glPathGlyphsNV = (PFNGLPATHGLYPHSNVPROC)gleIntGetProcAddress("glPathGlyphsNV");
	if(!glPathGlyphsNV) bIsLoaded = 0;
	glPathGlyphRangeNV = (PFNGLPATHGLYPHRANGENVPROC)gleIntGetProcAddress("glPathGlyphRangeNV");
	if(!glPathGlyphRangeNV) bIsLoaded = 0;
	glWeightPathsNV = (PFNGLWEIGHTPATHSNVPROC)gleIntGetProcAddress("glWeightPathsNV");
	if(!glWeightPathsNV) bIsLoaded = 0;
	glCopyPathNV = (PFNGLCOPYPATHNVPROC)gleIntGetProcAddress("glCopyPathNV");
	if(!glCopyPathNV) bIsLoaded = 0;
	glInterpolatePathsNV = (PFNGLINTERPOLATEPATHSNVPROC)gleIntGetProcAddress("glInterpolatePathsNV");
	if(!glInterpolatePathsNV) bIsLoaded = 0;
	glTransformPathNV = (PFNGLTRANSFORMPATHNVPROC)gleIntGetProcAddress("glTransformPathNV");
	if(!glTransformPathNV) bIsLoaded = 0;
	glPathParameterivNV = (PFNGLPATHPARAMETERIVNVPROC)gleIntGetProcAddress("glPathParameterivNV");
	if(!glPathParameterivNV) bIsLoaded = 0;
	glPathParameteriNV = (PFNGLPATHPARAMETERINVPROC)gleIntGetProcAddress("glPathParameteriNV");
	if(!glPathParameteriNV) bIsLoaded = 0;
	glPathParameterfvNV = (PFNGLPATHPARAMETERFVNVPROC)gleIntGetProcAddress("glPathParameterfvNV");
	if(!glPathParameterfvNV) bIsLoaded = 0;
	glPathParameterfNV = (PFNGLPATHPARAMETERFNVPROC)gleIntGetProcAddress("glPathParameterfNV");
	if(!glPathParameterfNV) bIsLoaded = 0;
	glPathDashArrayNV = (PFNGLPATHDASHARRAYNVPROC)gleIntGetProcAddress("glPathDashArrayNV");
	if(!glPathDashArrayNV) bIsLoaded = 0;
	glPathStencilFuncNV = (PFNGLPATHSTENCILFUNCNVPROC)gleIntGetProcAddress("glPathStencilFuncNV");
	if(!glPathStencilFuncNV) bIsLoaded = 0;
	glPathStencilDepthOffsetNV = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC)gleIntGetProcAddress("glPathStencilDepthOffsetNV");
	if(!glPathStencilDepthOffsetNV) bIsLoaded = 0;
	glStencilFillPathNV = (PFNGLSTENCILFILLPATHNVPROC)gleIntGetProcAddress("glStencilFillPathNV");
	if(!glStencilFillPathNV) bIsLoaded = 0;
	glStencilStrokePathNV = (PFNGLSTENCILSTROKEPATHNVPROC)gleIntGetProcAddress("glStencilStrokePathNV");
	if(!glStencilStrokePathNV) bIsLoaded = 0;
	glStencilFillPathInstancedNV = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC)gleIntGetProcAddress("glStencilFillPathInstancedNV");
	if(!glStencilFillPathInstancedNV) bIsLoaded = 0;
	glStencilStrokePathInstancedNV = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)gleIntGetProcAddress("glStencilStrokePathInstancedNV");
	if(!glStencilStrokePathInstancedNV) bIsLoaded = 0;
	glPathCoverDepthFuncNV = (PFNGLPATHCOVERDEPTHFUNCNVPROC)gleIntGetProcAddress("glPathCoverDepthFuncNV");
	if(!glPathCoverDepthFuncNV) bIsLoaded = 0;
	glPathColorGenNV = (PFNGLPATHCOLORGENNVPROC)gleIntGetProcAddress("glPathColorGenNV");
	if(!glPathColorGenNV) bIsLoaded = 0;
	glPathTexGenNV = (PFNGLPATHTEXGENNVPROC)gleIntGetProcAddress("glPathTexGenNV");
	if(!glPathTexGenNV) bIsLoaded = 0;
	glPathFogGenNV = (PFNGLPATHFOGGENNVPROC)gleIntGetProcAddress("glPathFogGenNV");
	if(!glPathFogGenNV) bIsLoaded = 0;
	glCoverFillPathNV = (PFNGLCOVERFILLPATHNVPROC)gleIntGetProcAddress("glCoverFillPathNV");
	if(!glCoverFillPathNV) bIsLoaded = 0;
	glCoverStrokePathNV = (PFNGLCOVERSTROKEPATHNVPROC)gleIntGetProcAddress("glCoverStrokePathNV");
	if(!glCoverStrokePathNV) bIsLoaded = 0;
	glCoverFillPathInstancedNV = (PFNGLCOVERFILLPATHINSTANCEDNVPROC)gleIntGetProcAddress("glCoverFillPathInstancedNV");
	if(!glCoverFillPathInstancedNV) bIsLoaded = 0;
	glCoverStrokePathInstancedNV = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)gleIntGetProcAddress("glCoverStrokePathInstancedNV");
	if(!glCoverStrokePathInstancedNV) bIsLoaded = 0;
	glGetPathParameterivNV = (PFNGLGETPATHPARAMETERIVNVPROC)gleIntGetProcAddress("glGetPathParameterivNV");
	if(!glGetPathParameterivNV) bIsLoaded = 0;
	glGetPathParameterfvNV = (PFNGLGETPATHPARAMETERFVNVPROC)gleIntGetProcAddress("glGetPathParameterfvNV");
	if(!glGetPathParameterfvNV) bIsLoaded = 0;
	glGetPathCommandsNV = (PFNGLGETPATHCOMMANDSNVPROC)gleIntGetProcAddress("glGetPathCommandsNV");
	if(!glGetPathCommandsNV) bIsLoaded = 0;
	glGetPathCoordsNV = (PFNGLGETPATHCOORDSNVPROC)gleIntGetProcAddress("glGetPathCoordsNV");
	if(!glGetPathCoordsNV) bIsLoaded = 0;
	glGetPathDashArrayNV = (PFNGLGETPATHDASHARRAYNVPROC)gleIntGetProcAddress("glGetPathDashArrayNV");
	if(!glGetPathDashArrayNV) bIsLoaded = 0;
	glGetPathMetricsNV = (PFNGLGETPATHMETRICSNVPROC)gleIntGetProcAddress("glGetPathMetricsNV");
	if(!glGetPathMetricsNV) bIsLoaded = 0;
	glGetPathMetricRangeNV = (PFNGLGETPATHMETRICRANGENVPROC)gleIntGetProcAddress("glGetPathMetricRangeNV");
	if(!glGetPathMetricRangeNV) bIsLoaded = 0;
	glGetPathSpacingNV = (PFNGLGETPATHSPACINGNVPROC)gleIntGetProcAddress("glGetPathSpacingNV");
	if(!glGetPathSpacingNV) bIsLoaded = 0;
	glGetPathColorGenivNV = (PFNGLGETPATHCOLORGENIVNVPROC)gleIntGetProcAddress("glGetPathColorGenivNV");
	if(!glGetPathColorGenivNV) bIsLoaded = 0;
	glGetPathColorGenfvNV = (PFNGLGETPATHCOLORGENFVNVPROC)gleIntGetProcAddress("glGetPathColorGenfvNV");
	if(!glGetPathColorGenfvNV) bIsLoaded = 0;
	glGetPathTexGenivNV = (PFNGLGETPATHTEXGENIVNVPROC)gleIntGetProcAddress("glGetPathTexGenivNV");
	if(!glGetPathTexGenivNV) bIsLoaded = 0;
	glGetPathTexGenfvNV = (PFNGLGETPATHTEXGENFVNVPROC)gleIntGetProcAddress("glGetPathTexGenfvNV");
	if(!glGetPathTexGenfvNV) bIsLoaded = 0;
	glIsPointInFillPathNV = (PFNGLISPOINTINFILLPATHNVPROC)gleIntGetProcAddress("glIsPointInFillPathNV");
	if(!glIsPointInFillPathNV) bIsLoaded = 0;
	glIsPointInStrokePathNV = (PFNGLISPOINTINSTROKEPATHNVPROC)gleIntGetProcAddress("glIsPointInStrokePathNV");
	if(!glIsPointInStrokePathNV) bIsLoaded = 0;
	glGetPathLengthNV = (PFNGLGETPATHLENGTHNVPROC)gleIntGetProcAddress("glGetPathLengthNV");
	if(!glGetPathLengthNV) bIsLoaded = 0;
	glPointAlongPathNV = (PFNGLPOINTALONGPATHNVPROC)gleIntGetProcAddress("glPointAlongPathNV");
	if(!glPointAlongPathNV) bIsLoaded = 0;
#endif /*GL_NV_path_rendering*/
	return bIsLoaded;
}
#ifndef GL_NV_pixel_data_range
typedef void (GLE_FUNCPTR * PFNGLPIXELDATARANGENVPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum );

PFNGLPIXELDATARANGENVPROC glPixelDataRangeNV;
PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNV;
#endif /*GL_NV_pixel_data_range*/

static int gleIntLoad_NV_pixel_data_range()
{
	int bIsLoaded = 1;
#ifndef GL_NV_pixel_data_range
	glPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC)gleIntGetProcAddress("glPixelDataRangeNV");
	if(!glPixelDataRangeNV) bIsLoaded = 0;
	glFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC)gleIntGetProcAddress("glFlushPixelDataRangeNV");
	if(!glFlushPixelDataRangeNV) bIsLoaded = 0;
#endif /*GL_NV_pixel_data_range*/
	return bIsLoaded;
}
#ifndef GL_NV_point_sprite
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERINVPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIVNVPROC)(GLenum , const GLint *);

PFNGLPOINTPARAMETERINVPROC glPointParameteriNV;
PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNV;
#endif /*GL_NV_point_sprite*/

static int gleIntLoad_NV_point_sprite()
{
	int bIsLoaded = 1;
#ifndef GL_NV_point_sprite
	glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)gleIntGetProcAddress("glPointParameteriNV");
	if(!glPointParameteriNV) bIsLoaded = 0;
	glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)gleIntGetProcAddress("glPointParameterivNV");
	if(!glPointParameterivNV) bIsLoaded = 0;
#endif /*GL_NV_point_sprite*/
	return bIsLoaded;
}
#ifndef GL_NV_present_video
typedef void (GLE_FUNCPTR * PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint , GLuint64EXT , GLuint , GLuint , GLenum , GLenum , GLuint , GLuint , GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint , GLuint64EXT , GLuint , GLuint , GLenum , GLenum , GLuint , GLenum , GLuint , GLenum , GLuint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOUIVNVPROC)(GLuint , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOI64VNVPROC)(GLuint , GLenum , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOUI64VNVPROC)(GLuint , GLenum , GLuint64EXT *);

PFNGLPRESENTFRAMEKEYEDNVPROC glPresentFrameKeyedNV;
PFNGLPRESENTFRAMEDUALFILLNVPROC glPresentFrameDualFillNV;
PFNGLGETVIDEOIVNVPROC glGetVideoivNV;
PFNGLGETVIDEOUIVNVPROC glGetVideouivNV;
PFNGLGETVIDEOI64VNVPROC glGetVideoi64vNV;
PFNGLGETVIDEOUI64VNVPROC glGetVideoui64vNV;
#endif /*GL_NV_present_video*/

static int gleIntLoad_NV_present_video()
{
	int bIsLoaded = 1;
#ifndef GL_NV_present_video
	glPresentFrameKeyedNV = (PFNGLPRESENTFRAMEKEYEDNVPROC)gleIntGetProcAddress("glPresentFrameKeyedNV");
	if(!glPresentFrameKeyedNV) bIsLoaded = 0;
	glPresentFrameDualFillNV = (PFNGLPRESENTFRAMEDUALFILLNVPROC)gleIntGetProcAddress("glPresentFrameDualFillNV");
	if(!glPresentFrameDualFillNV) bIsLoaded = 0;
	glGetVideoivNV = (PFNGLGETVIDEOIVNVPROC)gleIntGetProcAddress("glGetVideoivNV");
	if(!glGetVideoivNV) bIsLoaded = 0;
	glGetVideouivNV = (PFNGLGETVIDEOUIVNVPROC)gleIntGetProcAddress("glGetVideouivNV");
	if(!glGetVideouivNV) bIsLoaded = 0;
	glGetVideoi64vNV = (PFNGLGETVIDEOI64VNVPROC)gleIntGetProcAddress("glGetVideoi64vNV");
	if(!glGetVideoi64vNV) bIsLoaded = 0;
	glGetVideoui64vNV = (PFNGLGETVIDEOUI64VNVPROC)gleIntGetProcAddress("glGetVideoui64vNV");
	if(!glGetVideoui64vNV) bIsLoaded = 0;
#endif /*GL_NV_present_video*/
	return bIsLoaded;
}
#ifndef GL_NV_primitive_restart
typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint );

PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNV;
PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNV;
#endif /*GL_NV_primitive_restart*/

static int gleIntLoad_NV_primitive_restart()
{
	int bIsLoaded = 1;
#ifndef GL_NV_primitive_restart
	glPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC)gleIntGetProcAddress("glPrimitiveRestartNV");
	if(!glPrimitiveRestartNV) bIsLoaded = 0;
	glPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC)gleIntGetProcAddress("glPrimitiveRestartIndexNV");
	if(!glPrimitiveRestartIndexNV) bIsLoaded = 0;
#endif /*GL_NV_primitive_restart*/
	return bIsLoaded;
}
#ifndef GL_NV_register_combiners
typedef void (GLE_FUNCPTR * PFNGLCOMBINERPARAMETERFVNVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOMBINERPARAMETERFNVPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOMBINERPARAMETERIVNVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOMBINERPARAMETERINVPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOMBINERINPUTNVPROC)(GLenum , GLenum , GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLCOMBINEROUTPUTNVPROC)(GLenum , GLenum , GLenum , GLenum , GLenum , GLenum , GLenum , GLboolean , GLboolean , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLFINALCOMBINERINPUTNVPROC)(GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)(GLenum , GLenum , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)(GLenum , GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)(GLenum , GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)(GLenum , GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)(GLenum , GLenum , GLint *);

PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV;
PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNV;
PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV;
PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV;
PFNGLCOMBINERINPUTNVPROC glCombinerInputNV;
PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV;
PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV;
PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV;
PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV;
PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV;
PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV;
PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNV;
PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNV;
#endif /*GL_NV_register_combiners*/

static int gleIntLoad_NV_register_combiners()
{
	int bIsLoaded = 1;
#ifndef GL_NV_register_combiners
	glCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)gleIntGetProcAddress("glCombinerParameterfvNV");
	if(!glCombinerParameterfvNV) bIsLoaded = 0;
	glCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)gleIntGetProcAddress("glCombinerParameterfNV");
	if(!glCombinerParameterfNV) bIsLoaded = 0;
	glCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)gleIntGetProcAddress("glCombinerParameterivNV");
	if(!glCombinerParameterivNV) bIsLoaded = 0;
	glCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)gleIntGetProcAddress("glCombinerParameteriNV");
	if(!glCombinerParameteriNV) bIsLoaded = 0;
	glCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)gleIntGetProcAddress("glCombinerInputNV");
	if(!glCombinerInputNV) bIsLoaded = 0;
	glCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)gleIntGetProcAddress("glCombinerOutputNV");
	if(!glCombinerOutputNV) bIsLoaded = 0;
	glFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)gleIntGetProcAddress("glFinalCombinerInputNV");
	if(!glFinalCombinerInputNV) bIsLoaded = 0;
	glGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)gleIntGetProcAddress("glGetCombinerInputParameterfvNV");
	if(!glGetCombinerInputParameterfvNV) bIsLoaded = 0;
	glGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)gleIntGetProcAddress("glGetCombinerInputParameterivNV");
	if(!glGetCombinerInputParameterivNV) bIsLoaded = 0;
	glGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)gleIntGetProcAddress("glGetCombinerOutputParameterfvNV");
	if(!glGetCombinerOutputParameterfvNV) bIsLoaded = 0;
	glGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)gleIntGetProcAddress("glGetCombinerOutputParameterivNV");
	if(!glGetCombinerOutputParameterivNV) bIsLoaded = 0;
	glGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)gleIntGetProcAddress("glGetFinalCombinerInputParameterfvNV");
	if(!glGetFinalCombinerInputParameterfvNV) bIsLoaded = 0;
	glGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)gleIntGetProcAddress("glGetFinalCombinerInputParameterivNV");
	if(!glGetFinalCombinerInputParameterivNV) bIsLoaded = 0;
#endif /*GL_NV_register_combiners*/
	return bIsLoaded;
}
#ifndef GL_NV_register_combiners2
typedef void (GLE_FUNCPTR * PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum , GLenum , GLfloat *);

PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNV;
PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNV;
#endif /*GL_NV_register_combiners2*/

static int gleIntLoad_NV_register_combiners2()
{
	int bIsLoaded = 1;
#ifndef GL_NV_register_combiners2
	glCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)gleIntGetProcAddress("glCombinerStageParameterfvNV");
	if(!glCombinerStageParameterfvNV) bIsLoaded = 0;
	glGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)gleIntGetProcAddress("glGetCombinerStageParameterfvNV");
	if(!glGetCombinerStageParameterfvNV) bIsLoaded = 0;
#endif /*GL_NV_register_combiners2*/
	return bIsLoaded;
}

#ifndef GL_NV_shader_buffer_load
typedef void (GLE_FUNCPTR * PFNGLMAKEBUFFERRESIDENTNVPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAKEBUFFERNONRESIDENTNVPROC)(GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLISBUFFERRESIDENTNVPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISNAMEDBUFFERRESIDENTNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPARAMETERUI64VNVPROC)(GLenum , GLenum , GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)(GLuint , GLenum , GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERUI64VNVPROC)(GLenum , GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMUI64NVPROC)(GLint , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLUNIFORMUI64VNVPROC)(GLint , GLsizei , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMUI64VNVPROC)(GLuint , GLint , GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMUI64NVPROC)(GLuint , GLint , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMUNIFORMUI64VNVPROC)(GLuint , GLint , GLsizei , const GLuint64EXT *);

PFNGLMAKEBUFFERRESIDENTNVPROC glMakeBufferResidentNV;
PFNGLMAKEBUFFERNONRESIDENTNVPROC glMakeBufferNonResidentNV;
PFNGLISBUFFERRESIDENTNVPROC glIsBufferResidentNV;
PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glMakeNamedBufferResidentNV;
PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glMakeNamedBufferNonResidentNV;
PFNGLISNAMEDBUFFERRESIDENTNVPROC glIsNamedBufferResidentNV;
PFNGLGETBUFFERPARAMETERUI64VNVPROC glGetBufferParameterui64vNV;
PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glGetNamedBufferParameterui64vNV;
PFNGLGETINTEGERUI64VNVPROC glGetIntegerui64vNV;
PFNGLUNIFORMUI64NVPROC glUniformui64NV;
PFNGLUNIFORMUI64VNVPROC glUniformui64vNV;
PFNGLGETUNIFORMUI64VNVPROC glGetUniformui64vNV;
PFNGLPROGRAMUNIFORMUI64NVPROC glProgramUniformui64NV;
PFNGLPROGRAMUNIFORMUI64VNVPROC glProgramUniformui64vNV;
#endif /*GL_NV_shader_buffer_load*/

static int gleIntLoad_NV_shader_buffer_load()
{
	int bIsLoaded = 1;
#ifndef GL_NV_shader_buffer_load
	glMakeBufferResidentNV = (PFNGLMAKEBUFFERRESIDENTNVPROC)gleIntGetProcAddress("glMakeBufferResidentNV");
	if(!glMakeBufferResidentNV) bIsLoaded = 0;
	glMakeBufferNonResidentNV = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)gleIntGetProcAddress("glMakeBufferNonResidentNV");
	if(!glMakeBufferNonResidentNV) bIsLoaded = 0;
	glIsBufferResidentNV = (PFNGLISBUFFERRESIDENTNVPROC)gleIntGetProcAddress("glIsBufferResidentNV");
	if(!glIsBufferResidentNV) bIsLoaded = 0;
	glMakeNamedBufferResidentNV = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)gleIntGetProcAddress("glMakeNamedBufferResidentNV");
	if(!glMakeNamedBufferResidentNV) bIsLoaded = 0;
	glMakeNamedBufferNonResidentNV = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)gleIntGetProcAddress("glMakeNamedBufferNonResidentNV");
	if(!glMakeNamedBufferNonResidentNV) bIsLoaded = 0;
	glIsNamedBufferResidentNV = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)gleIntGetProcAddress("glIsNamedBufferResidentNV");
	if(!glIsNamedBufferResidentNV) bIsLoaded = 0;
	glGetBufferParameterui64vNV = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)gleIntGetProcAddress("glGetBufferParameterui64vNV");
	if(!glGetBufferParameterui64vNV) bIsLoaded = 0;
	glGetNamedBufferParameterui64vNV = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)gleIntGetProcAddress("glGetNamedBufferParameterui64vNV");
	if(!glGetNamedBufferParameterui64vNV) bIsLoaded = 0;
	glGetIntegerui64vNV = (PFNGLGETINTEGERUI64VNVPROC)gleIntGetProcAddress("glGetIntegerui64vNV");
	if(!glGetIntegerui64vNV) bIsLoaded = 0;
	glUniformui64NV = (PFNGLUNIFORMUI64NVPROC)gleIntGetProcAddress("glUniformui64NV");
	if(!glUniformui64NV) bIsLoaded = 0;
	glUniformui64vNV = (PFNGLUNIFORMUI64VNVPROC)gleIntGetProcAddress("glUniformui64vNV");
	if(!glUniformui64vNV) bIsLoaded = 0;
	glGetUniformui64vNV = (PFNGLGETUNIFORMUI64VNVPROC)gleIntGetProcAddress("glGetUniformui64vNV");
	if(!glGetUniformui64vNV) bIsLoaded = 0;
	glProgramUniformui64NV = (PFNGLPROGRAMUNIFORMUI64NVPROC)gleIntGetProcAddress("glProgramUniformui64NV");
	if(!glProgramUniformui64NV) bIsLoaded = 0;
	glProgramUniformui64vNV = (PFNGLPROGRAMUNIFORMUI64VNVPROC)gleIntGetProcAddress("glProgramUniformui64vNV");
	if(!glProgramUniformui64vNV) bIsLoaded = 0;
#endif /*GL_NV_shader_buffer_load*/
	return bIsLoaded;
}




#ifndef GL_NV_texture_barrier
typedef void (GLE_FUNCPTR * PFNGLTEXTUREBARRIERNVPROC)();

PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNV;
#endif /*GL_NV_texture_barrier*/

static int gleIntLoad_NV_texture_barrier()
{
	int bIsLoaded = 1;
#ifndef GL_NV_texture_barrier
	glTextureBarrierNV = (PFNGLTEXTUREBARRIERNVPROC)gleIntGetProcAddress("glTextureBarrierNV");
	if(!glTextureBarrierNV) bIsLoaded = 0;
#endif /*GL_NV_texture_barrier*/
	return bIsLoaded;
}



#ifndef GL_NV_texture_multisample
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)(GLuint , GLenum , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)(GLuint , GLenum , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLuint , GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLuint , GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );

PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC glTexImage2DMultisampleCoverageNV;
PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC glTexImage3DMultisampleCoverageNV;
PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC glTextureImage2DMultisampleNV;
PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC glTextureImage3DMultisampleNV;
PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC glTextureImage2DMultisampleCoverageNV;
PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC glTextureImage3DMultisampleCoverageNV;
#endif /*GL_NV_texture_multisample*/

static int gleIntLoad_NV_texture_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_NV_texture_multisample
	glTexImage2DMultisampleCoverageNV = (PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)gleIntGetProcAddress("glTexImage2DMultisampleCoverageNV");
	if(!glTexImage2DMultisampleCoverageNV) bIsLoaded = 0;
	glTexImage3DMultisampleCoverageNV = (PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)gleIntGetProcAddress("glTexImage3DMultisampleCoverageNV");
	if(!glTexImage3DMultisampleCoverageNV) bIsLoaded = 0;
	glTextureImage2DMultisampleNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)gleIntGetProcAddress("glTextureImage2DMultisampleNV");
	if(!glTextureImage2DMultisampleNV) bIsLoaded = 0;
	glTextureImage3DMultisampleNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)gleIntGetProcAddress("glTextureImage3DMultisampleNV");
	if(!glTextureImage3DMultisampleNV) bIsLoaded = 0;
	glTextureImage2DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)gleIntGetProcAddress("glTextureImage2DMultisampleCoverageNV");
	if(!glTextureImage2DMultisampleCoverageNV) bIsLoaded = 0;
	glTextureImage3DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)gleIntGetProcAddress("glTextureImage3DMultisampleCoverageNV");
	if(!glTextureImage3DMultisampleCoverageNV) bIsLoaded = 0;
#endif /*GL_NV_texture_multisample*/
	return bIsLoaded;
}




#ifndef GL_NV_transform_feedback
typedef void (GLE_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKNVPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)(GLsizei , const GLint *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERRANGENVPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFEROFFSETNVPROC)(GLenum , GLuint , GLuint , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERBASENVPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)(GLuint , GLsizei , const GLint *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLACTIVEVARYINGNVPROC)(GLuint , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETVARYINGLOCATIONNVPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEVARYINGNVPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)(GLuint , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)(GLsizei , const GLint *, GLsizei , const GLint *, GLenum );

PFNGLBEGINTRANSFORMFEEDBACKNVPROC glBeginTransformFeedbackNV;
PFNGLENDTRANSFORMFEEDBACKNVPROC glEndTransformFeedbackNV;
PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC glTransformFeedbackAttribsNV;
PFNGLBINDBUFFERRANGENVPROC glBindBufferRangeNV;
PFNGLBINDBUFFEROFFSETNVPROC glBindBufferOffsetNV;
PFNGLBINDBUFFERBASENVPROC glBindBufferBaseNV;
PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC glTransformFeedbackVaryingsNV;
PFNGLACTIVEVARYINGNVPROC glActiveVaryingNV;
PFNGLGETVARYINGLOCATIONNVPROC glGetVaryingLocationNV;
PFNGLGETACTIVEVARYINGNVPROC glGetActiveVaryingNV;
PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC glGetTransformFeedbackVaryingNV;
PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC glTransformFeedbackStreamAttribsNV;
#endif /*GL_NV_transform_feedback*/

static int gleIntLoad_NV_transform_feedback()
{
	int bIsLoaded = 1;
#ifndef GL_NV_transform_feedback
	glBeginTransformFeedbackNV = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glBeginTransformFeedbackNV");
	if(!glBeginTransformFeedbackNV) bIsLoaded = 0;
	glEndTransformFeedbackNV = (PFNGLENDTRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glEndTransformFeedbackNV");
	if(!glEndTransformFeedbackNV) bIsLoaded = 0;
	glTransformFeedbackAttribsNV = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)gleIntGetProcAddress("glTransformFeedbackAttribsNV");
	if(!glTransformFeedbackAttribsNV) bIsLoaded = 0;
	glBindBufferRangeNV = (PFNGLBINDBUFFERRANGENVPROC)gleIntGetProcAddress("glBindBufferRangeNV");
	if(!glBindBufferRangeNV) bIsLoaded = 0;
	glBindBufferOffsetNV = (PFNGLBINDBUFFEROFFSETNVPROC)gleIntGetProcAddress("glBindBufferOffsetNV");
	if(!glBindBufferOffsetNV) bIsLoaded = 0;
	glBindBufferBaseNV = (PFNGLBINDBUFFERBASENVPROC)gleIntGetProcAddress("glBindBufferBaseNV");
	if(!glBindBufferBaseNV) bIsLoaded = 0;
	glTransformFeedbackVaryingsNV = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)gleIntGetProcAddress("glTransformFeedbackVaryingsNV");
	if(!glTransformFeedbackVaryingsNV) bIsLoaded = 0;
	glActiveVaryingNV = (PFNGLACTIVEVARYINGNVPROC)gleIntGetProcAddress("glActiveVaryingNV");
	if(!glActiveVaryingNV) bIsLoaded = 0;
	glGetVaryingLocationNV = (PFNGLGETVARYINGLOCATIONNVPROC)gleIntGetProcAddress("glGetVaryingLocationNV");
	if(!glGetVaryingLocationNV) bIsLoaded = 0;
	glGetActiveVaryingNV = (PFNGLGETACTIVEVARYINGNVPROC)gleIntGetProcAddress("glGetActiveVaryingNV");
	if(!glGetActiveVaryingNV) bIsLoaded = 0;
	glGetTransformFeedbackVaryingNV = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)gleIntGetProcAddress("glGetTransformFeedbackVaryingNV");
	if(!glGetTransformFeedbackVaryingNV) bIsLoaded = 0;
	glTransformFeedbackStreamAttribsNV = (PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)gleIntGetProcAddress("glTransformFeedbackStreamAttribsNV");
	if(!glTransformFeedbackStreamAttribsNV) bIsLoaded = 0;
#endif /*GL_NV_transform_feedback*/
	return bIsLoaded;
}
#ifndef GL_NV_transform_feedback2
typedef void (GLE_FUNCPTR * PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPAUSETRANSFORMFEEDBACKNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLRESUMETRANSFORMFEEDBACKNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum , GLuint );

PFNGLBINDTRANSFORMFEEDBACKNVPROC glBindTransformFeedbackNV;
PFNGLDELETETRANSFORMFEEDBACKSNVPROC glDeleteTransformFeedbacksNV;
PFNGLGENTRANSFORMFEEDBACKSNVPROC glGenTransformFeedbacksNV;
PFNGLISTRANSFORMFEEDBACKNVPROC glIsTransformFeedbackNV;
PFNGLPAUSETRANSFORMFEEDBACKNVPROC glPauseTransformFeedbackNV;
PFNGLRESUMETRANSFORMFEEDBACKNVPROC glResumeTransformFeedbackNV;
PFNGLDRAWTRANSFORMFEEDBACKNVPROC glDrawTransformFeedbackNV;
#endif /*GL_NV_transform_feedback2*/

static int gleIntLoad_NV_transform_feedback2()
{
	int bIsLoaded = 1;
#ifndef GL_NV_transform_feedback2
	glBindTransformFeedbackNV = (PFNGLBINDTRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glBindTransformFeedbackNV");
	if(!glBindTransformFeedbackNV) bIsLoaded = 0;
	glDeleteTransformFeedbacksNV = (PFNGLDELETETRANSFORMFEEDBACKSNVPROC)gleIntGetProcAddress("glDeleteTransformFeedbacksNV");
	if(!glDeleteTransformFeedbacksNV) bIsLoaded = 0;
	glGenTransformFeedbacksNV = (PFNGLGENTRANSFORMFEEDBACKSNVPROC)gleIntGetProcAddress("glGenTransformFeedbacksNV");
	if(!glGenTransformFeedbacksNV) bIsLoaded = 0;
	glIsTransformFeedbackNV = (PFNGLISTRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glIsTransformFeedbackNV");
	if(!glIsTransformFeedbackNV) bIsLoaded = 0;
	glPauseTransformFeedbackNV = (PFNGLPAUSETRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glPauseTransformFeedbackNV");
	if(!glPauseTransformFeedbackNV) bIsLoaded = 0;
	glResumeTransformFeedbackNV = (PFNGLRESUMETRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glResumeTransformFeedbackNV");
	if(!glResumeTransformFeedbackNV) bIsLoaded = 0;
	glDrawTransformFeedbackNV = (PFNGLDRAWTRANSFORMFEEDBACKNVPROC)gleIntGetProcAddress("glDrawTransformFeedbackNV");
	if(!glDrawTransformFeedbackNV) bIsLoaded = 0;
#endif /*GL_NV_transform_feedback2*/
	return bIsLoaded;
}
#ifndef GL_NV_vdpau_interop
typedef void (GLE_FUNCPTR * PFNGLVDPAUINITNVPROC)(const GLvoid *, const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVDPAUFININVPROC)();
typedef GLvdpauSurfaceNV (GLE_FUNCPTR * PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)(GLvoid* , GLenum , GLsizei , const GLuint *);
typedef GLvdpauSurfaceNV (GLE_FUNCPTR * PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)(GLvoid* , GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVDPAUISSURFACENVPROC)(GLvdpauSurfaceNV );
typedef void (GLE_FUNCPTR * PFNGLVDPAUUNREGISTERSURFACENVPROC)(GLvdpauSurfaceNV );
typedef void (GLE_FUNCPTR * PFNGLVDPAUGETSURFACEIVNVPROC)(GLvdpauSurfaceNV , GLenum , GLsizei , GLsizei *, GLint *);
typedef void (GLE_FUNCPTR * PFNGLVDPAUSURFACEACCESSNVPROC)(GLvdpauSurfaceNV , GLenum );
typedef void (GLE_FUNCPTR * PFNGLVDPAUMAPSURFACESNVPROC)(GLsizei , const GLvdpauSurfaceNV *);
typedef void (GLE_FUNCPTR * PFNGLVDPAUUNMAPSURFACESNVPROC)(GLsizei , const GLvdpauSurfaceNV *);

PFNGLVDPAUINITNVPROC glVDPAUInitNV;
PFNGLVDPAUFININVPROC glVDPAUFiniNV;
PFNGLVDPAUREGISTERVIDEOSURFACENVPROC glVDPAURegisterVideoSurfaceNV;
PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC glVDPAURegisterOutputSurfaceNV;
PFNGLVDPAUISSURFACENVPROC glVDPAUIsSurfaceNV;
PFNGLVDPAUUNREGISTERSURFACENVPROC glVDPAUUnregisterSurfaceNV;
PFNGLVDPAUGETSURFACEIVNVPROC glVDPAUGetSurfaceivNV;
PFNGLVDPAUSURFACEACCESSNVPROC glVDPAUSurfaceAccessNV;
PFNGLVDPAUMAPSURFACESNVPROC glVDPAUMapSurfacesNV;
PFNGLVDPAUUNMAPSURFACESNVPROC glVDPAUUnmapSurfacesNV;
#endif /*GL_NV_vdpau_interop*/

static int gleIntLoad_NV_vdpau_interop()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vdpau_interop
	glVDPAUInitNV = (PFNGLVDPAUINITNVPROC)gleIntGetProcAddress("glVDPAUInitNV");
	if(!glVDPAUInitNV) bIsLoaded = 0;
	glVDPAUFiniNV = (PFNGLVDPAUFININVPROC)gleIntGetProcAddress("glVDPAUFiniNV");
	if(!glVDPAUFiniNV) bIsLoaded = 0;
	glVDPAURegisterVideoSurfaceNV = (PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)gleIntGetProcAddress("glVDPAURegisterVideoSurfaceNV");
	if(!glVDPAURegisterVideoSurfaceNV) bIsLoaded = 0;
	glVDPAURegisterOutputSurfaceNV = (PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)gleIntGetProcAddress("glVDPAURegisterOutputSurfaceNV");
	if(!glVDPAURegisterOutputSurfaceNV) bIsLoaded = 0;
	glVDPAUIsSurfaceNV = (PFNGLVDPAUISSURFACENVPROC)gleIntGetProcAddress("glVDPAUIsSurfaceNV");
	if(!glVDPAUIsSurfaceNV) bIsLoaded = 0;
	glVDPAUUnregisterSurfaceNV = (PFNGLVDPAUUNREGISTERSURFACENVPROC)gleIntGetProcAddress("glVDPAUUnregisterSurfaceNV");
	if(!glVDPAUUnregisterSurfaceNV) bIsLoaded = 0;
	glVDPAUGetSurfaceivNV = (PFNGLVDPAUGETSURFACEIVNVPROC)gleIntGetProcAddress("glVDPAUGetSurfaceivNV");
	if(!glVDPAUGetSurfaceivNV) bIsLoaded = 0;
	glVDPAUSurfaceAccessNV = (PFNGLVDPAUSURFACEACCESSNVPROC)gleIntGetProcAddress("glVDPAUSurfaceAccessNV");
	if(!glVDPAUSurfaceAccessNV) bIsLoaded = 0;
	glVDPAUMapSurfacesNV = (PFNGLVDPAUMAPSURFACESNVPROC)gleIntGetProcAddress("glVDPAUMapSurfacesNV");
	if(!glVDPAUMapSurfacesNV) bIsLoaded = 0;
	glVDPAUUnmapSurfacesNV = (PFNGLVDPAUUNMAPSURFACESNVPROC)gleIntGetProcAddress("glVDPAUUnmapSurfacesNV");
	if(!glVDPAUUnmapSurfacesNV) bIsLoaded = 0;
#endif /*GL_NV_vdpau_interop*/
	return bIsLoaded;
}
#ifndef GL_NV_vertex_array_range
typedef void (GLE_FUNCPTR * PFNGLFLUSHVERTEXARRAYRANGENVPROC)();
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYRANGENVPROC)(GLsizei , const GLvoid *);

PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNV;
PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNV;
#endif /*GL_NV_vertex_array_range*/

static int gleIntLoad_NV_vertex_array_range()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vertex_array_range
	glFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)gleIntGetProcAddress("glFlushVertexArrayRangeNV");
	if(!glFlushVertexArrayRangeNV) bIsLoaded = 0;
	glVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC)gleIntGetProcAddress("glVertexArrayRangeNV");
	if(!glVertexArrayRangeNV) bIsLoaded = 0;
#endif /*GL_NV_vertex_array_range*/
	return bIsLoaded;
}

#ifndef GL_NV_vertex_attrib_integer_64bit
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1I64NVPROC)(GLuint , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2I64NVPROC)(GLuint , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3I64NVPROC)(GLuint , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4I64NVPROC)(GLuint , GLint64EXT , GLint64EXT , GLint64EXT , GLint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1I64VNVPROC)(GLuint , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2I64VNVPROC)(GLuint , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3I64VNVPROC)(GLuint , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4I64VNVPROC)(GLuint , const GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1UI64NVPROC)(GLuint , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2UI64NVPROC)(GLuint , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3UI64NVPROC)(GLuint , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4UI64NVPROC)(GLuint , GLuint64EXT , GLuint64EXT , GLuint64EXT , GLuint64EXT );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL1UI64VNVPROC)(GLuint , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL2UI64VNVPROC)(GLuint , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL3UI64VNVPROC)(GLuint , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBL4UI64VNVPROC)(GLuint , const GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBLI64VNVPROC)(GLuint , GLenum , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBLUI64VNVPROC)(GLuint , GLenum , GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBLFORMATNVPROC)(GLuint , GLint , GLenum , GLsizei );

PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NV;
PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NV;
PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NV;
PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NV;
PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNV;
PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNV;
PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNV;
PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNV;
PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NV;
PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NV;
PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NV;
PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NV;
PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNV;
PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNV;
PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNV;
PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNV;
PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNV;
PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNV;
PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNV;
#endif /*GL_NV_vertex_attrib_integer_64bit*/

static int gleIntLoad_NV_vertex_attrib_integer_64bit()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vertex_attrib_integer_64bit
	glVertexAttribL1i64NV = (PFNGLVERTEXATTRIBL1I64NVPROC)gleIntGetProcAddress("glVertexAttribL1i64NV");
	if(!glVertexAttribL1i64NV) bIsLoaded = 0;
	glVertexAttribL2i64NV = (PFNGLVERTEXATTRIBL2I64NVPROC)gleIntGetProcAddress("glVertexAttribL2i64NV");
	if(!glVertexAttribL2i64NV) bIsLoaded = 0;
	glVertexAttribL3i64NV = (PFNGLVERTEXATTRIBL3I64NVPROC)gleIntGetProcAddress("glVertexAttribL3i64NV");
	if(!glVertexAttribL3i64NV) bIsLoaded = 0;
	glVertexAttribL4i64NV = (PFNGLVERTEXATTRIBL4I64NVPROC)gleIntGetProcAddress("glVertexAttribL4i64NV");
	if(!glVertexAttribL4i64NV) bIsLoaded = 0;
	glVertexAttribL1i64vNV = (PFNGLVERTEXATTRIBL1I64VNVPROC)gleIntGetProcAddress("glVertexAttribL1i64vNV");
	if(!glVertexAttribL1i64vNV) bIsLoaded = 0;
	glVertexAttribL2i64vNV = (PFNGLVERTEXATTRIBL2I64VNVPROC)gleIntGetProcAddress("glVertexAttribL2i64vNV");
	if(!glVertexAttribL2i64vNV) bIsLoaded = 0;
	glVertexAttribL3i64vNV = (PFNGLVERTEXATTRIBL3I64VNVPROC)gleIntGetProcAddress("glVertexAttribL3i64vNV");
	if(!glVertexAttribL3i64vNV) bIsLoaded = 0;
	glVertexAttribL4i64vNV = (PFNGLVERTEXATTRIBL4I64VNVPROC)gleIntGetProcAddress("glVertexAttribL4i64vNV");
	if(!glVertexAttribL4i64vNV) bIsLoaded = 0;
	glVertexAttribL1ui64NV = (PFNGLVERTEXATTRIBL1UI64NVPROC)gleIntGetProcAddress("glVertexAttribL1ui64NV");
	if(!glVertexAttribL1ui64NV) bIsLoaded = 0;
	glVertexAttribL2ui64NV = (PFNGLVERTEXATTRIBL2UI64NVPROC)gleIntGetProcAddress("glVertexAttribL2ui64NV");
	if(!glVertexAttribL2ui64NV) bIsLoaded = 0;
	glVertexAttribL3ui64NV = (PFNGLVERTEXATTRIBL3UI64NVPROC)gleIntGetProcAddress("glVertexAttribL3ui64NV");
	if(!glVertexAttribL3ui64NV) bIsLoaded = 0;
	glVertexAttribL4ui64NV = (PFNGLVERTEXATTRIBL4UI64NVPROC)gleIntGetProcAddress("glVertexAttribL4ui64NV");
	if(!glVertexAttribL4ui64NV) bIsLoaded = 0;
	glVertexAttribL1ui64vNV = (PFNGLVERTEXATTRIBL1UI64VNVPROC)gleIntGetProcAddress("glVertexAttribL1ui64vNV");
	if(!glVertexAttribL1ui64vNV) bIsLoaded = 0;
	glVertexAttribL2ui64vNV = (PFNGLVERTEXATTRIBL2UI64VNVPROC)gleIntGetProcAddress("glVertexAttribL2ui64vNV");
	if(!glVertexAttribL2ui64vNV) bIsLoaded = 0;
	glVertexAttribL3ui64vNV = (PFNGLVERTEXATTRIBL3UI64VNVPROC)gleIntGetProcAddress("glVertexAttribL3ui64vNV");
	if(!glVertexAttribL3ui64vNV) bIsLoaded = 0;
	glVertexAttribL4ui64vNV = (PFNGLVERTEXATTRIBL4UI64VNVPROC)gleIntGetProcAddress("glVertexAttribL4ui64vNV");
	if(!glVertexAttribL4ui64vNV) bIsLoaded = 0;
	glGetVertexAttribLi64vNV = (PFNGLGETVERTEXATTRIBLI64VNVPROC)gleIntGetProcAddress("glGetVertexAttribLi64vNV");
	if(!glGetVertexAttribLi64vNV) bIsLoaded = 0;
	glGetVertexAttribLui64vNV = (PFNGLGETVERTEXATTRIBLUI64VNVPROC)gleIntGetProcAddress("glGetVertexAttribLui64vNV");
	if(!glGetVertexAttribLui64vNV) bIsLoaded = 0;
	glVertexAttribLFormatNV = (PFNGLVERTEXATTRIBLFORMATNVPROC)gleIntGetProcAddress("glVertexAttribLFormatNV");
	if(!glVertexAttribLFormatNV) bIsLoaded = 0;
#endif /*GL_NV_vertex_attrib_integer_64bit*/
	return bIsLoaded;
}
#ifndef GL_NV_vertex_buffer_unified_memory
typedef void (GLE_FUNCPTR * PFNGLBUFFERADDRESSRANGENVPROC)(GLenum , GLuint , GLuint64EXT , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLVERTEXFORMATNVPROC)(GLint , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLNORMALFORMATNVPROC)(GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOLORFORMATNVPROC)(GLint , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLINDEXFORMATNVPROC)(GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDFORMATNVPROC)(GLint , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGFORMATNVPROC)(GLsizei );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORFORMATNVPROC)(GLint , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFORMATNVPROC)(GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBFORMATNVPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBIFORMATNVPROC)(GLuint , GLint , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERUI64I_VNVPROC)(GLenum , GLuint , GLuint64EXT *);

PFNGLBUFFERADDRESSRANGENVPROC glBufferAddressRangeNV;
PFNGLVERTEXFORMATNVPROC glVertexFormatNV;
PFNGLNORMALFORMATNVPROC glNormalFormatNV;
PFNGLCOLORFORMATNVPROC glColorFormatNV;
PFNGLINDEXFORMATNVPROC glIndexFormatNV;
PFNGLTEXCOORDFORMATNVPROC glTexCoordFormatNV;
PFNGLEDGEFLAGFORMATNVPROC glEdgeFlagFormatNV;
PFNGLSECONDARYCOLORFORMATNVPROC glSecondaryColorFormatNV;
PFNGLFOGCOORDFORMATNVPROC glFogCoordFormatNV;
PFNGLVERTEXATTRIBFORMATNVPROC glVertexAttribFormatNV;
PFNGLVERTEXATTRIBIFORMATNVPROC glVertexAttribIFormatNV;
PFNGLGETINTEGERUI64I_VNVPROC glGetIntegerui64i_vNV;
#endif /*GL_NV_vertex_buffer_unified_memory*/

static int gleIntLoad_NV_vertex_buffer_unified_memory()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vertex_buffer_unified_memory
	glBufferAddressRangeNV = (PFNGLBUFFERADDRESSRANGENVPROC)gleIntGetProcAddress("glBufferAddressRangeNV");
	if(!glBufferAddressRangeNV) bIsLoaded = 0;
	glVertexFormatNV = (PFNGLVERTEXFORMATNVPROC)gleIntGetProcAddress("glVertexFormatNV");
	if(!glVertexFormatNV) bIsLoaded = 0;
	glNormalFormatNV = (PFNGLNORMALFORMATNVPROC)gleIntGetProcAddress("glNormalFormatNV");
	if(!glNormalFormatNV) bIsLoaded = 0;
	glColorFormatNV = (PFNGLCOLORFORMATNVPROC)gleIntGetProcAddress("glColorFormatNV");
	if(!glColorFormatNV) bIsLoaded = 0;
	glIndexFormatNV = (PFNGLINDEXFORMATNVPROC)gleIntGetProcAddress("glIndexFormatNV");
	if(!glIndexFormatNV) bIsLoaded = 0;
	glTexCoordFormatNV = (PFNGLTEXCOORDFORMATNVPROC)gleIntGetProcAddress("glTexCoordFormatNV");
	if(!glTexCoordFormatNV) bIsLoaded = 0;
	glEdgeFlagFormatNV = (PFNGLEDGEFLAGFORMATNVPROC)gleIntGetProcAddress("glEdgeFlagFormatNV");
	if(!glEdgeFlagFormatNV) bIsLoaded = 0;
	glSecondaryColorFormatNV = (PFNGLSECONDARYCOLORFORMATNVPROC)gleIntGetProcAddress("glSecondaryColorFormatNV");
	if(!glSecondaryColorFormatNV) bIsLoaded = 0;
	glFogCoordFormatNV = (PFNGLFOGCOORDFORMATNVPROC)gleIntGetProcAddress("glFogCoordFormatNV");
	if(!glFogCoordFormatNV) bIsLoaded = 0;
	glVertexAttribFormatNV = (PFNGLVERTEXATTRIBFORMATNVPROC)gleIntGetProcAddress("glVertexAttribFormatNV");
	if(!glVertexAttribFormatNV) bIsLoaded = 0;
	glVertexAttribIFormatNV = (PFNGLVERTEXATTRIBIFORMATNVPROC)gleIntGetProcAddress("glVertexAttribIFormatNV");
	if(!glVertexAttribIFormatNV) bIsLoaded = 0;
	glGetIntegerui64i_vNV = (PFNGLGETINTEGERUI64I_VNVPROC)gleIntGetProcAddress("glGetIntegerui64i_vNV");
	if(!glGetIntegerui64i_vNV) bIsLoaded = 0;
#endif /*GL_NV_vertex_buffer_unified_memory*/
	return bIsLoaded;
}
#ifndef GL_NV_vertex_program
typedef GLboolean (GLE_FUNCPTR * PFNGLAREPROGRAMSRESIDENTNVPROC)(GLsizei , const GLuint *, GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLBINDPROGRAMNVPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEPROGRAMSNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLEXECUTEPROGRAMNVPROC)(GLenum , GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGENPROGRAMSNVPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMPARAMETERDVNVPROC)(GLenum , GLuint , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMPARAMETERFVNVPROC)(GLenum , GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSTRINGNVPROC)(GLuint , GLenum , GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLGETTRACKMATRIXIVNVPROC)(GLenum , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBDVNVPROC)(GLuint , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBFVNVPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBPOINTERVNVPROC)(GLuint , GLenum , GLvoid* *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISPROGRAMNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLLOADPROGRAMNVPROC)(GLenum , GLuint , GLsizei , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETER4DNVPROC)(GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETER4DVNVPROC)(GLenum , GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETER4FNVPROC)(GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETER4FVNVPROC)(GLenum , GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERS4DVNVPROC)(GLenum , GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERS4FVNVPROC)(GLenum , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREQUESTRESIDENTPROGRAMSNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTRACKMATRIXNVPROC)(GLenum , GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBPOINTERNVPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DNVPROC)(GLuint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DVNVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FNVPROC)(GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FVNVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SNVPROC)(GLuint , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SVNVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DNVPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DVNVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FNVPROC)(GLuint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FVNVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SNVPROC)(GLuint , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SVNVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DNVPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DVNVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FNVPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FVNVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SNVPROC)(GLuint , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SVNVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DNVPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DVNVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FNVPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FVNVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SNVPROC)(GLuint , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SVNVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UBNVPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UBVNVPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS1DVNVPROC)(GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS1FVNVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS1SVNVPROC)(GLuint , GLsizei , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS2DVNVPROC)(GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS2FVNVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS2SVNVPROC)(GLuint , GLsizei , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS3DVNVPROC)(GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS3FVNVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS3SVNVPROC)(GLuint , GLsizei , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS4DVNVPROC)(GLuint , GLsizei , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS4FVNVPROC)(GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS4SVNVPROC)(GLuint , GLsizei , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBS4UBVNVPROC)(GLuint , GLsizei , const GLubyte *);

PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNV;
PFNGLBINDPROGRAMNVPROC glBindProgramNV;
PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNV;
PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNV;
PFNGLGENPROGRAMSNVPROC glGenProgramsNV;
PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNV;
PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNV;
PFNGLGETPROGRAMIVNVPROC glGetProgramivNV;
PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNV;
PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNV;
PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNV;
PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNV;
PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNV;
PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNV;
PFNGLISPROGRAMNVPROC glIsProgramNV;
PFNGLLOADPROGRAMNVPROC glLoadProgramNV;
PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNV;
PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNV;
PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNV;
PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNV;
PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNV;
PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNV;
PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNV;
PFNGLTRACKMATRIXNVPROC glTrackMatrixNV;
PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNV;
PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNV;
PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNV;
PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNV;
PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNV;
PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNV;
PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNV;
PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNV;
PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNV;
PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNV;
PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNV;
PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNV;
PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNV;
PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNV;
PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNV;
PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNV;
PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNV;
PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNV;
PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNV;
PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNV;
PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNV;
PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNV;
PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNV;
PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNV;
PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNV;
PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNV;
PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNV;
PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNV;
PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNV;
PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNV;
PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNV;
PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNV;
PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNV;
PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNV;
PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNV;
PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNV;
PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNV;
PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNV;
PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNV;
PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNV;
#endif /*GL_NV_vertex_program*/

static int gleIntLoad_NV_vertex_program()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vertex_program
	glAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC)gleIntGetProcAddress("glAreProgramsResidentNV");
	if(!glAreProgramsResidentNV) bIsLoaded = 0;
	glBindProgramNV = (PFNGLBINDPROGRAMNVPROC)gleIntGetProcAddress("glBindProgramNV");
	if(!glBindProgramNV) bIsLoaded = 0;
	glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)gleIntGetProcAddress("glDeleteProgramsNV");
	if(!glDeleteProgramsNV) bIsLoaded = 0;
	glExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC)gleIntGetProcAddress("glExecuteProgramNV");
	if(!glExecuteProgramNV) bIsLoaded = 0;
	glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)gleIntGetProcAddress("glGenProgramsNV");
	if(!glGenProgramsNV) bIsLoaded = 0;
	glGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC)gleIntGetProcAddress("glGetProgramParameterdvNV");
	if(!glGetProgramParameterdvNV) bIsLoaded = 0;
	glGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC)gleIntGetProcAddress("glGetProgramParameterfvNV");
	if(!glGetProgramParameterfvNV) bIsLoaded = 0;
	glGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC)gleIntGetProcAddress("glGetProgramivNV");
	if(!glGetProgramivNV) bIsLoaded = 0;
	glGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC)gleIntGetProcAddress("glGetProgramStringNV");
	if(!glGetProgramStringNV) bIsLoaded = 0;
	glGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC)gleIntGetProcAddress("glGetTrackMatrixivNV");
	if(!glGetTrackMatrixivNV) bIsLoaded = 0;
	glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)gleIntGetProcAddress("glGetVertexAttribdvNV");
	if(!glGetVertexAttribdvNV) bIsLoaded = 0;
	glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)gleIntGetProcAddress("glGetVertexAttribfvNV");
	if(!glGetVertexAttribfvNV) bIsLoaded = 0;
	glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)gleIntGetProcAddress("glGetVertexAttribivNV");
	if(!glGetVertexAttribivNV) bIsLoaded = 0;
	glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)gleIntGetProcAddress("glGetVertexAttribPointervNV");
	if(!glGetVertexAttribPointervNV) bIsLoaded = 0;
	glIsProgramNV = (PFNGLISPROGRAMNVPROC)gleIntGetProcAddress("glIsProgramNV");
	if(!glIsProgramNV) bIsLoaded = 0;
	glLoadProgramNV = (PFNGLLOADPROGRAMNVPROC)gleIntGetProcAddress("glLoadProgramNV");
	if(!glLoadProgramNV) bIsLoaded = 0;
	glProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC)gleIntGetProcAddress("glProgramParameter4dNV");
	if(!glProgramParameter4dNV) bIsLoaded = 0;
	glProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC)gleIntGetProcAddress("glProgramParameter4dvNV");
	if(!glProgramParameter4dvNV) bIsLoaded = 0;
	glProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC)gleIntGetProcAddress("glProgramParameter4fNV");
	if(!glProgramParameter4fNV) bIsLoaded = 0;
	glProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC)gleIntGetProcAddress("glProgramParameter4fvNV");
	if(!glProgramParameter4fvNV) bIsLoaded = 0;
	glProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC)gleIntGetProcAddress("glProgramParameters4dvNV");
	if(!glProgramParameters4dvNV) bIsLoaded = 0;
	glProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC)gleIntGetProcAddress("glProgramParameters4fvNV");
	if(!glProgramParameters4fvNV) bIsLoaded = 0;
	glRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)gleIntGetProcAddress("glRequestResidentProgramsNV");
	if(!glRequestResidentProgramsNV) bIsLoaded = 0;
	glTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC)gleIntGetProcAddress("glTrackMatrixNV");
	if(!glTrackMatrixNV) bIsLoaded = 0;
	glVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC)gleIntGetProcAddress("glVertexAttribPointerNV");
	if(!glVertexAttribPointerNV) bIsLoaded = 0;
	glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)gleIntGetProcAddress("glVertexAttrib1dNV");
	if(!glVertexAttrib1dNV) bIsLoaded = 0;
	glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)gleIntGetProcAddress("glVertexAttrib1dvNV");
	if(!glVertexAttrib1dvNV) bIsLoaded = 0;
	glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)gleIntGetProcAddress("glVertexAttrib1fNV");
	if(!glVertexAttrib1fNV) bIsLoaded = 0;
	glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)gleIntGetProcAddress("glVertexAttrib1fvNV");
	if(!glVertexAttrib1fvNV) bIsLoaded = 0;
	glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)gleIntGetProcAddress("glVertexAttrib1sNV");
	if(!glVertexAttrib1sNV) bIsLoaded = 0;
	glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)gleIntGetProcAddress("glVertexAttrib1svNV");
	if(!glVertexAttrib1svNV) bIsLoaded = 0;
	glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)gleIntGetProcAddress("glVertexAttrib2dNV");
	if(!glVertexAttrib2dNV) bIsLoaded = 0;
	glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)gleIntGetProcAddress("glVertexAttrib2dvNV");
	if(!glVertexAttrib2dvNV) bIsLoaded = 0;
	glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)gleIntGetProcAddress("glVertexAttrib2fNV");
	if(!glVertexAttrib2fNV) bIsLoaded = 0;
	glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)gleIntGetProcAddress("glVertexAttrib2fvNV");
	if(!glVertexAttrib2fvNV) bIsLoaded = 0;
	glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)gleIntGetProcAddress("glVertexAttrib2sNV");
	if(!glVertexAttrib2sNV) bIsLoaded = 0;
	glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)gleIntGetProcAddress("glVertexAttrib2svNV");
	if(!glVertexAttrib2svNV) bIsLoaded = 0;
	glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)gleIntGetProcAddress("glVertexAttrib3dNV");
	if(!glVertexAttrib3dNV) bIsLoaded = 0;
	glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)gleIntGetProcAddress("glVertexAttrib3dvNV");
	if(!glVertexAttrib3dvNV) bIsLoaded = 0;
	glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)gleIntGetProcAddress("glVertexAttrib3fNV");
	if(!glVertexAttrib3fNV) bIsLoaded = 0;
	glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)gleIntGetProcAddress("glVertexAttrib3fvNV");
	if(!glVertexAttrib3fvNV) bIsLoaded = 0;
	glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)gleIntGetProcAddress("glVertexAttrib3sNV");
	if(!glVertexAttrib3sNV) bIsLoaded = 0;
	glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)gleIntGetProcAddress("glVertexAttrib3svNV");
	if(!glVertexAttrib3svNV) bIsLoaded = 0;
	glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)gleIntGetProcAddress("glVertexAttrib4dNV");
	if(!glVertexAttrib4dNV) bIsLoaded = 0;
	glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)gleIntGetProcAddress("glVertexAttrib4dvNV");
	if(!glVertexAttrib4dvNV) bIsLoaded = 0;
	glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)gleIntGetProcAddress("glVertexAttrib4fNV");
	if(!glVertexAttrib4fNV) bIsLoaded = 0;
	glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)gleIntGetProcAddress("glVertexAttrib4fvNV");
	if(!glVertexAttrib4fvNV) bIsLoaded = 0;
	glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)gleIntGetProcAddress("glVertexAttrib4sNV");
	if(!glVertexAttrib4sNV) bIsLoaded = 0;
	glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)gleIntGetProcAddress("glVertexAttrib4svNV");
	if(!glVertexAttrib4svNV) bIsLoaded = 0;
	glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)gleIntGetProcAddress("glVertexAttrib4ubNV");
	if(!glVertexAttrib4ubNV) bIsLoaded = 0;
	glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)gleIntGetProcAddress("glVertexAttrib4ubvNV");
	if(!glVertexAttrib4ubvNV) bIsLoaded = 0;
	glVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC)gleIntGetProcAddress("glVertexAttribs1dvNV");
	if(!glVertexAttribs1dvNV) bIsLoaded = 0;
	glVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC)gleIntGetProcAddress("glVertexAttribs1fvNV");
	if(!glVertexAttribs1fvNV) bIsLoaded = 0;
	glVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC)gleIntGetProcAddress("glVertexAttribs1svNV");
	if(!glVertexAttribs1svNV) bIsLoaded = 0;
	glVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC)gleIntGetProcAddress("glVertexAttribs2dvNV");
	if(!glVertexAttribs2dvNV) bIsLoaded = 0;
	glVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC)gleIntGetProcAddress("glVertexAttribs2fvNV");
	if(!glVertexAttribs2fvNV) bIsLoaded = 0;
	glVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC)gleIntGetProcAddress("glVertexAttribs2svNV");
	if(!glVertexAttribs2svNV) bIsLoaded = 0;
	glVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC)gleIntGetProcAddress("glVertexAttribs3dvNV");
	if(!glVertexAttribs3dvNV) bIsLoaded = 0;
	glVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC)gleIntGetProcAddress("glVertexAttribs3fvNV");
	if(!glVertexAttribs3fvNV) bIsLoaded = 0;
	glVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC)gleIntGetProcAddress("glVertexAttribs3svNV");
	if(!glVertexAttribs3svNV) bIsLoaded = 0;
	glVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC)gleIntGetProcAddress("glVertexAttribs4dvNV");
	if(!glVertexAttribs4dvNV) bIsLoaded = 0;
	glVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC)gleIntGetProcAddress("glVertexAttribs4fvNV");
	if(!glVertexAttribs4fvNV) bIsLoaded = 0;
	glVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC)gleIntGetProcAddress("glVertexAttribs4svNV");
	if(!glVertexAttribs4svNV) bIsLoaded = 0;
	glVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC)gleIntGetProcAddress("glVertexAttribs4ubvNV");
	if(!glVertexAttribs4ubvNV) bIsLoaded = 0;
#endif /*GL_NV_vertex_program*/
	return bIsLoaded;
}




#ifndef GL_NV_vertex_program4
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IEXTPROC)(GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IEXTPROC)(GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IEXTPROC)(GLuint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IEXTPROC)(GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIEXTPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIEXTPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIEXTPROC)(GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIEXTPROC)(GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IVEXTPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IVEXTPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IVEXTPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IVEXTPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIVEXTPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIVEXTPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIVEXTPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIVEXTPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4BVEXTPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4SVEXTPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UBVEXTPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4USVEXTPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBIPOINTEREXTPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIIVEXTPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIUIVEXTPROC)(GLuint , GLenum , GLuint *);

PFNGLVERTEXATTRIBI1IEXTPROC glVertexAttribI1iEXT;
PFNGLVERTEXATTRIBI2IEXTPROC glVertexAttribI2iEXT;
PFNGLVERTEXATTRIBI3IEXTPROC glVertexAttribI3iEXT;
PFNGLVERTEXATTRIBI4IEXTPROC glVertexAttribI4iEXT;
PFNGLVERTEXATTRIBI1UIEXTPROC glVertexAttribI1uiEXT;
PFNGLVERTEXATTRIBI2UIEXTPROC glVertexAttribI2uiEXT;
PFNGLVERTEXATTRIBI3UIEXTPROC glVertexAttribI3uiEXT;
PFNGLVERTEXATTRIBI4UIEXTPROC glVertexAttribI4uiEXT;
PFNGLVERTEXATTRIBI1IVEXTPROC glVertexAttribI1ivEXT;
PFNGLVERTEXATTRIBI2IVEXTPROC glVertexAttribI2ivEXT;
PFNGLVERTEXATTRIBI3IVEXTPROC glVertexAttribI3ivEXT;
PFNGLVERTEXATTRIBI4IVEXTPROC glVertexAttribI4ivEXT;
PFNGLVERTEXATTRIBI1UIVEXTPROC glVertexAttribI1uivEXT;
PFNGLVERTEXATTRIBI2UIVEXTPROC glVertexAttribI2uivEXT;
PFNGLVERTEXATTRIBI3UIVEXTPROC glVertexAttribI3uivEXT;
PFNGLVERTEXATTRIBI4UIVEXTPROC glVertexAttribI4uivEXT;
PFNGLVERTEXATTRIBI4BVEXTPROC glVertexAttribI4bvEXT;
PFNGLVERTEXATTRIBI4SVEXTPROC glVertexAttribI4svEXT;
PFNGLVERTEXATTRIBI4UBVEXTPROC glVertexAttribI4ubvEXT;
PFNGLVERTEXATTRIBI4USVEXTPROC glVertexAttribI4usvEXT;
PFNGLVERTEXATTRIBIPOINTEREXTPROC glVertexAttribIPointerEXT;
PFNGLGETVERTEXATTRIBIIVEXTPROC glGetVertexAttribIivEXT;
PFNGLGETVERTEXATTRIBIUIVEXTPROC glGetVertexAttribIuivEXT;
#endif /*GL_NV_vertex_program4*/

static int gleIntLoad_NV_vertex_program4()
{
	int bIsLoaded = 1;
#ifndef GL_NV_vertex_program4
	glVertexAttribI1iEXT = (PFNGLVERTEXATTRIBI1IEXTPROC)gleIntGetProcAddress("glVertexAttribI1iEXT");
	if(!glVertexAttribI1iEXT) bIsLoaded = 0;
	glVertexAttribI2iEXT = (PFNGLVERTEXATTRIBI2IEXTPROC)gleIntGetProcAddress("glVertexAttribI2iEXT");
	if(!glVertexAttribI2iEXT) bIsLoaded = 0;
	glVertexAttribI3iEXT = (PFNGLVERTEXATTRIBI3IEXTPROC)gleIntGetProcAddress("glVertexAttribI3iEXT");
	if(!glVertexAttribI3iEXT) bIsLoaded = 0;
	glVertexAttribI4iEXT = (PFNGLVERTEXATTRIBI4IEXTPROC)gleIntGetProcAddress("glVertexAttribI4iEXT");
	if(!glVertexAttribI4iEXT) bIsLoaded = 0;
	glVertexAttribI1uiEXT = (PFNGLVERTEXATTRIBI1UIEXTPROC)gleIntGetProcAddress("glVertexAttribI1uiEXT");
	if(!glVertexAttribI1uiEXT) bIsLoaded = 0;
	glVertexAttribI2uiEXT = (PFNGLVERTEXATTRIBI2UIEXTPROC)gleIntGetProcAddress("glVertexAttribI2uiEXT");
	if(!glVertexAttribI2uiEXT) bIsLoaded = 0;
	glVertexAttribI3uiEXT = (PFNGLVERTEXATTRIBI3UIEXTPROC)gleIntGetProcAddress("glVertexAttribI3uiEXT");
	if(!glVertexAttribI3uiEXT) bIsLoaded = 0;
	glVertexAttribI4uiEXT = (PFNGLVERTEXATTRIBI4UIEXTPROC)gleIntGetProcAddress("glVertexAttribI4uiEXT");
	if(!glVertexAttribI4uiEXT) bIsLoaded = 0;
	glVertexAttribI1ivEXT = (PFNGLVERTEXATTRIBI1IVEXTPROC)gleIntGetProcAddress("glVertexAttribI1ivEXT");
	if(!glVertexAttribI1ivEXT) bIsLoaded = 0;
	glVertexAttribI2ivEXT = (PFNGLVERTEXATTRIBI2IVEXTPROC)gleIntGetProcAddress("glVertexAttribI2ivEXT");
	if(!glVertexAttribI2ivEXT) bIsLoaded = 0;
	glVertexAttribI3ivEXT = (PFNGLVERTEXATTRIBI3IVEXTPROC)gleIntGetProcAddress("glVertexAttribI3ivEXT");
	if(!glVertexAttribI3ivEXT) bIsLoaded = 0;
	glVertexAttribI4ivEXT = (PFNGLVERTEXATTRIBI4IVEXTPROC)gleIntGetProcAddress("glVertexAttribI4ivEXT");
	if(!glVertexAttribI4ivEXT) bIsLoaded = 0;
	glVertexAttribI1uivEXT = (PFNGLVERTEXATTRIBI1UIVEXTPROC)gleIntGetProcAddress("glVertexAttribI1uivEXT");
	if(!glVertexAttribI1uivEXT) bIsLoaded = 0;
	glVertexAttribI2uivEXT = (PFNGLVERTEXATTRIBI2UIVEXTPROC)gleIntGetProcAddress("glVertexAttribI2uivEXT");
	if(!glVertexAttribI2uivEXT) bIsLoaded = 0;
	glVertexAttribI3uivEXT = (PFNGLVERTEXATTRIBI3UIVEXTPROC)gleIntGetProcAddress("glVertexAttribI3uivEXT");
	if(!glVertexAttribI3uivEXT) bIsLoaded = 0;
	glVertexAttribI4uivEXT = (PFNGLVERTEXATTRIBI4UIVEXTPROC)gleIntGetProcAddress("glVertexAttribI4uivEXT");
	if(!glVertexAttribI4uivEXT) bIsLoaded = 0;
	glVertexAttribI4bvEXT = (PFNGLVERTEXATTRIBI4BVEXTPROC)gleIntGetProcAddress("glVertexAttribI4bvEXT");
	if(!glVertexAttribI4bvEXT) bIsLoaded = 0;
	glVertexAttribI4svEXT = (PFNGLVERTEXATTRIBI4SVEXTPROC)gleIntGetProcAddress("glVertexAttribI4svEXT");
	if(!glVertexAttribI4svEXT) bIsLoaded = 0;
	glVertexAttribI4ubvEXT = (PFNGLVERTEXATTRIBI4UBVEXTPROC)gleIntGetProcAddress("glVertexAttribI4ubvEXT");
	if(!glVertexAttribI4ubvEXT) bIsLoaded = 0;
	glVertexAttribI4usvEXT = (PFNGLVERTEXATTRIBI4USVEXTPROC)gleIntGetProcAddress("glVertexAttribI4usvEXT");
	if(!glVertexAttribI4usvEXT) bIsLoaded = 0;
	glVertexAttribIPointerEXT = (PFNGLVERTEXATTRIBIPOINTEREXTPROC)gleIntGetProcAddress("glVertexAttribIPointerEXT");
	if(!glVertexAttribIPointerEXT) bIsLoaded = 0;
	glGetVertexAttribIivEXT = (PFNGLGETVERTEXATTRIBIIVEXTPROC)gleIntGetProcAddress("glGetVertexAttribIivEXT");
	if(!glGetVertexAttribIivEXT) bIsLoaded = 0;
	glGetVertexAttribIuivEXT = (PFNGLGETVERTEXATTRIBIUIVEXTPROC)gleIntGetProcAddress("glGetVertexAttribIuivEXT");
	if(!glGetVertexAttribIuivEXT) bIsLoaded = 0;
#endif /*GL_NV_vertex_program4*/
	return bIsLoaded;
}
#ifndef GL_NV_video_capture
typedef void (GLE_FUNCPTR * PFNGLBEGINVIDEOCAPTURENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)(GLuint , GLuint , GLenum , GLintptrARB );
typedef void (GLE_FUNCPTR * PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)(GLuint , GLuint , GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDVIDEOCAPTURENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOCAPTUREIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)(GLuint , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)(GLuint , GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)(GLuint , GLuint , GLenum , GLdouble *);
typedef GLenum (GLE_FUNCPTR * PFNGLVIDEOCAPTURENVPROC)(GLuint , GLuint *, GLuint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)(GLuint , GLuint , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)(GLuint , GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)(GLuint , GLuint , GLenum , const GLdouble *);

PFNGLBEGINVIDEOCAPTURENVPROC glBeginVideoCaptureNV;
PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC glBindVideoCaptureStreamBufferNV;
PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC glBindVideoCaptureStreamTextureNV;
PFNGLENDVIDEOCAPTURENVPROC glEndVideoCaptureNV;
PFNGLGETVIDEOCAPTUREIVNVPROC glGetVideoCaptureivNV;
PFNGLGETVIDEOCAPTURESTREAMIVNVPROC glGetVideoCaptureStreamivNV;
PFNGLGETVIDEOCAPTURESTREAMFVNVPROC glGetVideoCaptureStreamfvNV;
PFNGLGETVIDEOCAPTURESTREAMDVNVPROC glGetVideoCaptureStreamdvNV;
PFNGLVIDEOCAPTURENVPROC glVideoCaptureNV;
PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC glVideoCaptureStreamParameterivNV;
PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC glVideoCaptureStreamParameterfvNV;
PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC glVideoCaptureStreamParameterdvNV;
#endif /*GL_NV_video_capture*/

static int gleIntLoad_NV_video_capture()
{
	int bIsLoaded = 1;
#ifndef GL_NV_video_capture
	glBeginVideoCaptureNV = (PFNGLBEGINVIDEOCAPTURENVPROC)gleIntGetProcAddress("glBeginVideoCaptureNV");
	if(!glBeginVideoCaptureNV) bIsLoaded = 0;
	glBindVideoCaptureStreamBufferNV = (PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)gleIntGetProcAddress("glBindVideoCaptureStreamBufferNV");
	if(!glBindVideoCaptureStreamBufferNV) bIsLoaded = 0;
	glBindVideoCaptureStreamTextureNV = (PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)gleIntGetProcAddress("glBindVideoCaptureStreamTextureNV");
	if(!glBindVideoCaptureStreamTextureNV) bIsLoaded = 0;
	glEndVideoCaptureNV = (PFNGLENDVIDEOCAPTURENVPROC)gleIntGetProcAddress("glEndVideoCaptureNV");
	if(!glEndVideoCaptureNV) bIsLoaded = 0;
	glGetVideoCaptureivNV = (PFNGLGETVIDEOCAPTUREIVNVPROC)gleIntGetProcAddress("glGetVideoCaptureivNV");
	if(!glGetVideoCaptureivNV) bIsLoaded = 0;
	glGetVideoCaptureStreamivNV = (PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)gleIntGetProcAddress("glGetVideoCaptureStreamivNV");
	if(!glGetVideoCaptureStreamivNV) bIsLoaded = 0;
	glGetVideoCaptureStreamfvNV = (PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)gleIntGetProcAddress("glGetVideoCaptureStreamfvNV");
	if(!glGetVideoCaptureStreamfvNV) bIsLoaded = 0;
	glGetVideoCaptureStreamdvNV = (PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)gleIntGetProcAddress("glGetVideoCaptureStreamdvNV");
	if(!glGetVideoCaptureStreamdvNV) bIsLoaded = 0;
	glVideoCaptureNV = (PFNGLVIDEOCAPTURENVPROC)gleIntGetProcAddress("glVideoCaptureNV");
	if(!glVideoCaptureNV) bIsLoaded = 0;
	glVideoCaptureStreamParameterivNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)gleIntGetProcAddress("glVideoCaptureStreamParameterivNV");
	if(!glVideoCaptureStreamParameterivNV) bIsLoaded = 0;
	glVideoCaptureStreamParameterfvNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)gleIntGetProcAddress("glVideoCaptureStreamParameterfvNV");
	if(!glVideoCaptureStreamParameterfvNV) bIsLoaded = 0;
	glVideoCaptureStreamParameterdvNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)gleIntGetProcAddress("glVideoCaptureStreamParameterdvNV");
	if(!glVideoCaptureStreamParameterdvNV) bIsLoaded = 0;
#endif /*GL_NV_video_capture*/
	return bIsLoaded;
}




#ifndef GL_PGI_misc_hints
typedef void (GLE_FUNCPTR * PFNGLHINTPGIPROC)(GLenum , GLint );

PFNGLHINTPGIPROC glHintPGI;
#endif /*GL_PGI_misc_hints*/

static int gleIntLoad_PGI_misc_hints()
{
	int bIsLoaded = 1;
#ifndef GL_PGI_misc_hints
	glHintPGI = (PFNGLHINTPGIPROC)gleIntGetProcAddress("glHintPGI");
	if(!glHintPGI) bIsLoaded = 0;
#endif /*GL_PGI_misc_hints*/
	return bIsLoaded;
}



#ifndef GL_SGIS_detail_texture
typedef void (GLE_FUNCPTR * PFNGLDETAILTEXFUNCSGISPROC)(GLenum , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum , GLfloat *);

PFNGLDETAILTEXFUNCSGISPROC glDetailTexFuncSGIS;
PFNGLGETDETAILTEXFUNCSGISPROC glGetDetailTexFuncSGIS;
#endif /*GL_SGIS_detail_texture*/

static int gleIntLoad_SGIS_detail_texture()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_detail_texture
	glDetailTexFuncSGIS = (PFNGLDETAILTEXFUNCSGISPROC)gleIntGetProcAddress("glDetailTexFuncSGIS");
	if(!glDetailTexFuncSGIS) bIsLoaded = 0;
	glGetDetailTexFuncSGIS = (PFNGLGETDETAILTEXFUNCSGISPROC)gleIntGetProcAddress("glGetDetailTexFuncSGIS");
	if(!glGetDetailTexFuncSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_detail_texture*/
	return bIsLoaded;
}
#ifndef GL_SGIS_fog_function
typedef void (GLE_FUNCPTR * PFNGLFOGFUNCSGISPROC)(GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETFOGFUNCSGISPROC)(GLfloat *);

PFNGLFOGFUNCSGISPROC glFogFuncSGIS;
PFNGLGETFOGFUNCSGISPROC glGetFogFuncSGIS;
#endif /*GL_SGIS_fog_function*/

static int gleIntLoad_SGIS_fog_function()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_fog_function
	glFogFuncSGIS = (PFNGLFOGFUNCSGISPROC)gleIntGetProcAddress("glFogFuncSGIS");
	if(!glFogFuncSGIS) bIsLoaded = 0;
	glGetFogFuncSGIS = (PFNGLGETFOGFUNCSGISPROC)gleIntGetProcAddress("glGetFogFuncSGIS");
	if(!glGetFogFuncSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_fog_function*/
	return bIsLoaded;
}

#ifndef GL_SGIS_multisample
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKSGISPROC)(GLclampf , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLSAMPLEPATTERNSGISPROC)(GLenum );

PFNGLSAMPLEMASKSGISPROC glSampleMaskSGIS;
PFNGLSAMPLEPATTERNSGISPROC glSamplePatternSGIS;
#endif /*GL_SGIS_multisample*/

static int gleIntLoad_SGIS_multisample()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_multisample
	glSampleMaskSGIS = (PFNGLSAMPLEMASKSGISPROC)gleIntGetProcAddress("glSampleMaskSGIS");
	if(!glSampleMaskSGIS) bIsLoaded = 0;
	glSamplePatternSGIS = (PFNGLSAMPLEPATTERNSGISPROC)gleIntGetProcAddress("glSamplePatternSGIS");
	if(!glSamplePatternSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_multisample*/
	return bIsLoaded;
}
#ifndef GL_SGIS_pixel_texture
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum , GLfloat *);

PFNGLPIXELTEXGENPARAMETERISGISPROC glPixelTexGenParameteriSGIS;
PFNGLPIXELTEXGENPARAMETERIVSGISPROC glPixelTexGenParameterivSGIS;
PFNGLPIXELTEXGENPARAMETERFSGISPROC glPixelTexGenParameterfSGIS;
PFNGLPIXELTEXGENPARAMETERFVSGISPROC glPixelTexGenParameterfvSGIS;
PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glGetPixelTexGenParameterivSGIS;
PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glGetPixelTexGenParameterfvSGIS;
#endif /*GL_SGIS_pixel_texture*/

static int gleIntLoad_SGIS_pixel_texture()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_pixel_texture
	glPixelTexGenParameteriSGIS = (PFNGLPIXELTEXGENPARAMETERISGISPROC)gleIntGetProcAddress("glPixelTexGenParameteriSGIS");
	if(!glPixelTexGenParameteriSGIS) bIsLoaded = 0;
	glPixelTexGenParameterivSGIS = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC)gleIntGetProcAddress("glPixelTexGenParameterivSGIS");
	if(!glPixelTexGenParameterivSGIS) bIsLoaded = 0;
	glPixelTexGenParameterfSGIS = (PFNGLPIXELTEXGENPARAMETERFSGISPROC)gleIntGetProcAddress("glPixelTexGenParameterfSGIS");
	if(!glPixelTexGenParameterfSGIS) bIsLoaded = 0;
	glPixelTexGenParameterfvSGIS = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC)gleIntGetProcAddress("glPixelTexGenParameterfvSGIS");
	if(!glPixelTexGenParameterfvSGIS) bIsLoaded = 0;
	glGetPixelTexGenParameterivSGIS = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)gleIntGetProcAddress("glGetPixelTexGenParameterivSGIS");
	if(!glGetPixelTexGenParameterivSGIS) bIsLoaded = 0;
	glGetPixelTexGenParameterfvSGIS = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)gleIntGetProcAddress("glGetPixelTexGenParameterfvSGIS");
	if(!glGetPixelTexGenParameterfvSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_pixel_texture*/
	return bIsLoaded;
}

#ifndef GL_SGIS_point_parameters
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFSGISPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVSGISPROC)(GLenum , const GLfloat *);

PFNGLPOINTPARAMETERFSGISPROC glPointParameterfSGIS;
PFNGLPOINTPARAMETERFVSGISPROC glPointParameterfvSGIS;
#endif /*GL_SGIS_point_parameters*/

static int gleIntLoad_SGIS_point_parameters()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_point_parameters
	glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)gleIntGetProcAddress("glPointParameterfSGIS");
	if(!glPointParameterfSGIS) bIsLoaded = 0;
	glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)gleIntGetProcAddress("glPointParameterfvSGIS");
	if(!glPointParameterfvSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_point_parameters*/
	return bIsLoaded;
}
#ifndef GL_SGIS_sharpen_texture
typedef void (GLE_FUNCPTR * PFNGLSHARPENTEXFUNCSGISPROC)(GLenum , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum , GLfloat *);

PFNGLSHARPENTEXFUNCSGISPROC glSharpenTexFuncSGIS;
PFNGLGETSHARPENTEXFUNCSGISPROC glGetSharpenTexFuncSGIS;
#endif /*GL_SGIS_sharpen_texture*/

static int gleIntLoad_SGIS_sharpen_texture()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_sharpen_texture
	glSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC)gleIntGetProcAddress("glSharpenTexFuncSGIS");
	if(!glSharpenTexFuncSGIS) bIsLoaded = 0;
	glGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC)gleIntGetProcAddress("glGetSharpenTexFuncSGIS");
	if(!glGetSharpenTexFuncSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_sharpen_texture*/
	return bIsLoaded;
}
#ifndef GL_SGIS_texture4D
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE4DSGISPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

PFNGLTEXIMAGE4DSGISPROC glTexImage4DSGIS;
PFNGLTEXSUBIMAGE4DSGISPROC glTexSubImage4DSGIS;
#endif /*GL_SGIS_texture4D*/

static int gleIntLoad_SGIS_texture4D()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_texture4D
	glTexImage4DSGIS = (PFNGLTEXIMAGE4DSGISPROC)gleIntGetProcAddress("glTexImage4DSGIS");
	if(!glTexImage4DSGIS) bIsLoaded = 0;
	glTexSubImage4DSGIS = (PFNGLTEXSUBIMAGE4DSGISPROC)gleIntGetProcAddress("glTexSubImage4DSGIS");
	if(!glTexSubImage4DSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_texture4D*/
	return bIsLoaded;
}

#ifndef GL_SGIS_texture_color_mask
typedef void (GLE_FUNCPTR * PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean , GLboolean , GLboolean , GLboolean );

PFNGLTEXTURECOLORMASKSGISPROC glTextureColorMaskSGIS;
#endif /*GL_SGIS_texture_color_mask*/

static int gleIntLoad_SGIS_texture_color_mask()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_texture_color_mask
	glTextureColorMaskSGIS = (PFNGLTEXTURECOLORMASKSGISPROC)gleIntGetProcAddress("glTextureColorMaskSGIS");
	if(!glTextureColorMaskSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_texture_color_mask*/
	return bIsLoaded;
}

#ifndef GL_SGIS_texture_filter4
typedef void (GLE_FUNCPTR * PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXFILTERFUNCSGISPROC)(GLenum , GLenum , GLsizei , const GLfloat *);

PFNGLGETTEXFILTERFUNCSGISPROC glGetTexFilterFuncSGIS;
PFNGLTEXFILTERFUNCSGISPROC glTexFilterFuncSGIS;
#endif /*GL_SGIS_texture_filter4*/

static int gleIntLoad_SGIS_texture_filter4()
{
	int bIsLoaded = 1;
#ifndef GL_SGIS_texture_filter4
	glGetTexFilterFuncSGIS = (PFNGLGETTEXFILTERFUNCSGISPROC)gleIntGetProcAddress("glGetTexFilterFuncSGIS");
	if(!glGetTexFilterFuncSGIS) bIsLoaded = 0;
	glTexFilterFuncSGIS = (PFNGLTEXFILTERFUNCSGISPROC)gleIntGetProcAddress("glTexFilterFuncSGIS");
	if(!glTexFilterFuncSGIS) bIsLoaded = 0;
#endif /*GL_SGIS_texture_filter4*/
	return bIsLoaded;
}


#ifndef GL_SGIX_async
typedef void (GLE_FUNCPTR * PFNGLASYNCMARKERSGIXPROC)(GLuint );
typedef GLint (GLE_FUNCPTR * PFNGLFINISHASYNCSGIXPROC)(GLuint *);
typedef GLint (GLE_FUNCPTR * PFNGLPOLLASYNCSGIXPROC)(GLuint *);
typedef GLuint (GLE_FUNCPTR * PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint , GLsizei );
typedef GLboolean (GLE_FUNCPTR * PFNGLISASYNCMARKERSGIXPROC)(GLuint );

PFNGLASYNCMARKERSGIXPROC glAsyncMarkerSGIX;
PFNGLFINISHASYNCSGIXPROC glFinishAsyncSGIX;
PFNGLPOLLASYNCSGIXPROC glPollAsyncSGIX;
PFNGLGENASYNCMARKERSSGIXPROC glGenAsyncMarkersSGIX;
PFNGLDELETEASYNCMARKERSSGIXPROC glDeleteAsyncMarkersSGIX;
PFNGLISASYNCMARKERSGIXPROC glIsAsyncMarkerSGIX;
#endif /*GL_SGIX_async*/

static int gleIntLoad_SGIX_async()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_async
	glAsyncMarkerSGIX = (PFNGLASYNCMARKERSGIXPROC)gleIntGetProcAddress("glAsyncMarkerSGIX");
	if(!glAsyncMarkerSGIX) bIsLoaded = 0;
	glFinishAsyncSGIX = (PFNGLFINISHASYNCSGIXPROC)gleIntGetProcAddress("glFinishAsyncSGIX");
	if(!glFinishAsyncSGIX) bIsLoaded = 0;
	glPollAsyncSGIX = (PFNGLPOLLASYNCSGIXPROC)gleIntGetProcAddress("glPollAsyncSGIX");
	if(!glPollAsyncSGIX) bIsLoaded = 0;
	glGenAsyncMarkersSGIX = (PFNGLGENASYNCMARKERSSGIXPROC)gleIntGetProcAddress("glGenAsyncMarkersSGIX");
	if(!glGenAsyncMarkersSGIX) bIsLoaded = 0;
	glDeleteAsyncMarkersSGIX = (PFNGLDELETEASYNCMARKERSSGIXPROC)gleIntGetProcAddress("glDeleteAsyncMarkersSGIX");
	if(!glDeleteAsyncMarkersSGIX) bIsLoaded = 0;
	glIsAsyncMarkerSGIX = (PFNGLISASYNCMARKERSGIXPROC)gleIntGetProcAddress("glIsAsyncMarkerSGIX");
	if(!glIsAsyncMarkerSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_async*/
	return bIsLoaded;
}







#ifndef GL_SGIX_flush_raster
typedef void (GLE_FUNCPTR * PFNGLFLUSHRASTERSGIXPROC)();

PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIX;
#endif /*GL_SGIX_flush_raster*/

static int gleIntLoad_SGIX_flush_raster()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_flush_raster
	glFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC)gleIntGetProcAddress("glFlushRasterSGIX");
	if(!glFlushRasterSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_flush_raster*/
	return bIsLoaded;
}


#ifndef GL_SGIX_fragment_lighting
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTCOLORMATERIALSGIXPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTFSGIXPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTFVSGIXPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTISGIXPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTIVSGIXPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTMODELFSGIXPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTMODELISGIXPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTMATERIALFSGIXPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTMATERIALFVSGIXPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTMATERIALISGIXPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAGMENTMATERIALIVSGIXPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETFRAGMENTLIGHTFVSGIXPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETFRAGMENTLIGHTIVSGIXPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETFRAGMENTMATERIALFVSGIXPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETFRAGMENTMATERIALIVSGIXPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLLIGHTENVISGIXPROC)(GLenum , GLint );

PFNGLFRAGMENTCOLORMATERIALSGIXPROC glFragmentColorMaterialSGIX;
PFNGLFRAGMENTLIGHTFSGIXPROC glFragmentLightfSGIX;
PFNGLFRAGMENTLIGHTFVSGIXPROC glFragmentLightfvSGIX;
PFNGLFRAGMENTLIGHTISGIXPROC glFragmentLightiSGIX;
PFNGLFRAGMENTLIGHTIVSGIXPROC glFragmentLightivSGIX;
PFNGLFRAGMENTLIGHTMODELFSGIXPROC glFragmentLightModelfSGIX;
PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glFragmentLightModelfvSGIX;
PFNGLFRAGMENTLIGHTMODELISGIXPROC glFragmentLightModeliSGIX;
PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glFragmentLightModelivSGIX;
PFNGLFRAGMENTMATERIALFSGIXPROC glFragmentMaterialfSGIX;
PFNGLFRAGMENTMATERIALFVSGIXPROC glFragmentMaterialfvSGIX;
PFNGLFRAGMENTMATERIALISGIXPROC glFragmentMaterialiSGIX;
PFNGLFRAGMENTMATERIALIVSGIXPROC glFragmentMaterialivSGIX;
PFNGLGETFRAGMENTLIGHTFVSGIXPROC glGetFragmentLightfvSGIX;
PFNGLGETFRAGMENTLIGHTIVSGIXPROC glGetFragmentLightivSGIX;
PFNGLGETFRAGMENTMATERIALFVSGIXPROC glGetFragmentMaterialfvSGIX;
PFNGLGETFRAGMENTMATERIALIVSGIXPROC glGetFragmentMaterialivSGIX;
PFNGLLIGHTENVISGIXPROC glLightEnviSGIX;
#endif /*GL_SGIX_fragment_lighting*/

static int gleIntLoad_SGIX_fragment_lighting()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_fragment_lighting
	glFragmentColorMaterialSGIX = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)gleIntGetProcAddress("glFragmentColorMaterialSGIX");
	if(!glFragmentColorMaterialSGIX) bIsLoaded = 0;
	glFragmentLightfSGIX = (PFNGLFRAGMENTLIGHTFSGIXPROC)gleIntGetProcAddress("glFragmentLightfSGIX");
	if(!glFragmentLightfSGIX) bIsLoaded = 0;
	glFragmentLightfvSGIX = (PFNGLFRAGMENTLIGHTFVSGIXPROC)gleIntGetProcAddress("glFragmentLightfvSGIX");
	if(!glFragmentLightfvSGIX) bIsLoaded = 0;
	glFragmentLightiSGIX = (PFNGLFRAGMENTLIGHTISGIXPROC)gleIntGetProcAddress("glFragmentLightiSGIX");
	if(!glFragmentLightiSGIX) bIsLoaded = 0;
	glFragmentLightivSGIX = (PFNGLFRAGMENTLIGHTIVSGIXPROC)gleIntGetProcAddress("glFragmentLightivSGIX");
	if(!glFragmentLightivSGIX) bIsLoaded = 0;
	glFragmentLightModelfSGIX = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)gleIntGetProcAddress("glFragmentLightModelfSGIX");
	if(!glFragmentLightModelfSGIX) bIsLoaded = 0;
	glFragmentLightModelfvSGIX = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)gleIntGetProcAddress("glFragmentLightModelfvSGIX");
	if(!glFragmentLightModelfvSGIX) bIsLoaded = 0;
	glFragmentLightModeliSGIX = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)gleIntGetProcAddress("glFragmentLightModeliSGIX");
	if(!glFragmentLightModeliSGIX) bIsLoaded = 0;
	glFragmentLightModelivSGIX = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)gleIntGetProcAddress("glFragmentLightModelivSGIX");
	if(!glFragmentLightModelivSGIX) bIsLoaded = 0;
	glFragmentMaterialfSGIX = (PFNGLFRAGMENTMATERIALFSGIXPROC)gleIntGetProcAddress("glFragmentMaterialfSGIX");
	if(!glFragmentMaterialfSGIX) bIsLoaded = 0;
	glFragmentMaterialfvSGIX = (PFNGLFRAGMENTMATERIALFVSGIXPROC)gleIntGetProcAddress("glFragmentMaterialfvSGIX");
	if(!glFragmentMaterialfvSGIX) bIsLoaded = 0;
	glFragmentMaterialiSGIX = (PFNGLFRAGMENTMATERIALISGIXPROC)gleIntGetProcAddress("glFragmentMaterialiSGIX");
	if(!glFragmentMaterialiSGIX) bIsLoaded = 0;
	glFragmentMaterialivSGIX = (PFNGLFRAGMENTMATERIALIVSGIXPROC)gleIntGetProcAddress("glFragmentMaterialivSGIX");
	if(!glFragmentMaterialivSGIX) bIsLoaded = 0;
	glGetFragmentLightfvSGIX = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)gleIntGetProcAddress("glGetFragmentLightfvSGIX");
	if(!glGetFragmentLightfvSGIX) bIsLoaded = 0;
	glGetFragmentLightivSGIX = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)gleIntGetProcAddress("glGetFragmentLightivSGIX");
	if(!glGetFragmentLightivSGIX) bIsLoaded = 0;
	glGetFragmentMaterialfvSGIX = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)gleIntGetProcAddress("glGetFragmentMaterialfvSGIX");
	if(!glGetFragmentMaterialfvSGIX) bIsLoaded = 0;
	glGetFragmentMaterialivSGIX = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)gleIntGetProcAddress("glGetFragmentMaterialivSGIX");
	if(!glGetFragmentMaterialivSGIX) bIsLoaded = 0;
	glLightEnviSGIX = (PFNGLLIGHTENVISGIXPROC)gleIntGetProcAddress("glLightEnviSGIX");
	if(!glLightEnviSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_fragment_lighting*/
	return bIsLoaded;
}
#ifndef GL_SGIX_framezoom
typedef void (GLE_FUNCPTR * PFNGLFRAMEZOOMSGIXPROC)(GLint );

PFNGLFRAMEZOOMSGIXPROC glFrameZoomSGIX;
#endif /*GL_SGIX_framezoom*/

static int gleIntLoad_SGIX_framezoom()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_framezoom
	glFrameZoomSGIX = (PFNGLFRAMEZOOMSGIXPROC)gleIntGetProcAddress("glFrameZoomSGIX");
	if(!glFrameZoomSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_framezoom*/
	return bIsLoaded;
}

#ifndef GL_SGIX_instruments
typedef GLint (GLE_FUNCPTR * PFNGLGETINSTRUMENTSSGIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei , GLint *);
typedef GLint (GLE_FUNCPTR * PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *);
typedef void (GLE_FUNCPTR * PFNGLREADINSTRUMENTSSGIXPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLSTARTINSTRUMENTSSGIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint );

PFNGLGETINSTRUMENTSSGIXPROC glGetInstrumentsSGIX;
PFNGLINSTRUMENTSBUFFERSGIXPROC glInstrumentsBufferSGIX;
PFNGLPOLLINSTRUMENTSSGIXPROC glPollInstrumentsSGIX;
PFNGLREADINSTRUMENTSSGIXPROC glReadInstrumentsSGIX;
PFNGLSTARTINSTRUMENTSSGIXPROC glStartInstrumentsSGIX;
PFNGLSTOPINSTRUMENTSSGIXPROC glStopInstrumentsSGIX;
#endif /*GL_SGIX_instruments*/

static int gleIntLoad_SGIX_instruments()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_instruments
	glGetInstrumentsSGIX = (PFNGLGETINSTRUMENTSSGIXPROC)gleIntGetProcAddress("glGetInstrumentsSGIX");
	if(!glGetInstrumentsSGIX) bIsLoaded = 0;
	glInstrumentsBufferSGIX = (PFNGLINSTRUMENTSBUFFERSGIXPROC)gleIntGetProcAddress("glInstrumentsBufferSGIX");
	if(!glInstrumentsBufferSGIX) bIsLoaded = 0;
	glPollInstrumentsSGIX = (PFNGLPOLLINSTRUMENTSSGIXPROC)gleIntGetProcAddress("glPollInstrumentsSGIX");
	if(!glPollInstrumentsSGIX) bIsLoaded = 0;
	glReadInstrumentsSGIX = (PFNGLREADINSTRUMENTSSGIXPROC)gleIntGetProcAddress("glReadInstrumentsSGIX");
	if(!glReadInstrumentsSGIX) bIsLoaded = 0;
	glStartInstrumentsSGIX = (PFNGLSTARTINSTRUMENTSSGIXPROC)gleIntGetProcAddress("glStartInstrumentsSGIX");
	if(!glStartInstrumentsSGIX) bIsLoaded = 0;
	glStopInstrumentsSGIX = (PFNGLSTOPINSTRUMENTSSGIXPROC)gleIntGetProcAddress("glStopInstrumentsSGIX");
	if(!glStopInstrumentsSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_instruments*/
	return bIsLoaded;
}


#ifndef GL_SGIX_list_priority
typedef void (GLE_FUNCPTR * PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERFSGIXPROC)(GLuint , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERFVSGIXPROC)(GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERISGIXPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERIVSGIXPROC)(GLuint , GLenum , const GLint *);

PFNGLGETLISTPARAMETERFVSGIXPROC glGetListParameterfvSGIX;
PFNGLGETLISTPARAMETERIVSGIXPROC glGetListParameterivSGIX;
PFNGLLISTPARAMETERFSGIXPROC glListParameterfSGIX;
PFNGLLISTPARAMETERFVSGIXPROC glListParameterfvSGIX;
PFNGLLISTPARAMETERISGIXPROC glListParameteriSGIX;
PFNGLLISTPARAMETERIVSGIXPROC glListParameterivSGIX;
#endif /*GL_SGIX_list_priority*/

static int gleIntLoad_SGIX_list_priority()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_list_priority
	glGetListParameterfvSGIX = (PFNGLGETLISTPARAMETERFVSGIXPROC)gleIntGetProcAddress("glGetListParameterfvSGIX");
	if(!glGetListParameterfvSGIX) bIsLoaded = 0;
	glGetListParameterivSGIX = (PFNGLGETLISTPARAMETERIVSGIXPROC)gleIntGetProcAddress("glGetListParameterivSGIX");
	if(!glGetListParameterivSGIX) bIsLoaded = 0;
	glListParameterfSGIX = (PFNGLLISTPARAMETERFSGIXPROC)gleIntGetProcAddress("glListParameterfSGIX");
	if(!glListParameterfSGIX) bIsLoaded = 0;
	glListParameterfvSGIX = (PFNGLLISTPARAMETERFVSGIXPROC)gleIntGetProcAddress("glListParameterfvSGIX");
	if(!glListParameterfvSGIX) bIsLoaded = 0;
	glListParameteriSGIX = (PFNGLLISTPARAMETERISGIXPROC)gleIntGetProcAddress("glListParameteriSGIX");
	if(!glListParameteriSGIX) bIsLoaded = 0;
	glListParameterivSGIX = (PFNGLLISTPARAMETERIVSGIXPROC)gleIntGetProcAddress("glListParameterivSGIX");
	if(!glListParameterivSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_list_priority*/
	return bIsLoaded;
}
#ifndef GL_SGIX_pixel_texture
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENSGIXPROC)(GLenum );

PFNGLPIXELTEXGENSGIXPROC glPixelTexGenSGIX;
#endif /*GL_SGIX_pixel_texture*/

static int gleIntLoad_SGIX_pixel_texture()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_pixel_texture
	glPixelTexGenSGIX = (PFNGLPIXELTEXGENSGIXPROC)gleIntGetProcAddress("glPixelTexGenSGIX");
	if(!glPixelTexGenSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_pixel_texture*/
	return bIsLoaded;
}

#ifndef GL_SGIX_polynomial_ffd
typedef void (GLE_FUNCPTR * PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLDEFORMSGIXPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield );

PFNGLDEFORMATIONMAP3DSGIXPROC glDeformationMap3dSGIX;
PFNGLDEFORMATIONMAP3FSGIXPROC glDeformationMap3fSGIX;
PFNGLDEFORMSGIXPROC glDeformSGIX;
PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glLoadIdentityDeformationMapSGIX;
#endif /*GL_SGIX_polynomial_ffd*/

static int gleIntLoad_SGIX_polynomial_ffd()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_polynomial_ffd
	glDeformationMap3dSGIX = (PFNGLDEFORMATIONMAP3DSGIXPROC)gleIntGetProcAddress("glDeformationMap3dSGIX");
	if(!glDeformationMap3dSGIX) bIsLoaded = 0;
	glDeformationMap3fSGIX = (PFNGLDEFORMATIONMAP3FSGIXPROC)gleIntGetProcAddress("glDeformationMap3fSGIX");
	if(!glDeformationMap3fSGIX) bIsLoaded = 0;
	glDeformSGIX = (PFNGLDEFORMSGIXPROC)gleIntGetProcAddress("glDeformSGIX");
	if(!glDeformSGIX) bIsLoaded = 0;
	glLoadIdentityDeformationMapSGIX = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)gleIntGetProcAddress("glLoadIdentityDeformationMapSGIX");
	if(!glLoadIdentityDeformationMapSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_polynomial_ffd*/
	return bIsLoaded;
}
#ifndef GL_SGIX_reference_plane
typedef void (GLE_FUNCPTR * PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *);

PFNGLREFERENCEPLANESGIXPROC glReferencePlaneSGIX;
#endif /*GL_SGIX_reference_plane*/

static int gleIntLoad_SGIX_reference_plane()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_reference_plane
	glReferencePlaneSGIX = (PFNGLREFERENCEPLANESGIXPROC)gleIntGetProcAddress("glReferencePlaneSGIX");
	if(!glReferencePlaneSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_reference_plane*/
	return bIsLoaded;
}




#ifndef GL_SGIX_sprite
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERISGIXPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum , const GLint *);

PFNGLSPRITEPARAMETERFSGIXPROC glSpriteParameterfSGIX;
PFNGLSPRITEPARAMETERFVSGIXPROC glSpriteParameterfvSGIX;
PFNGLSPRITEPARAMETERISGIXPROC glSpriteParameteriSGIX;
PFNGLSPRITEPARAMETERIVSGIXPROC glSpriteParameterivSGIX;
#endif /*GL_SGIX_sprite*/

static int gleIntLoad_SGIX_sprite()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_sprite
	glSpriteParameterfSGIX = (PFNGLSPRITEPARAMETERFSGIXPROC)gleIntGetProcAddress("glSpriteParameterfSGIX");
	if(!glSpriteParameterfSGIX) bIsLoaded = 0;
	glSpriteParameterfvSGIX = (PFNGLSPRITEPARAMETERFVSGIXPROC)gleIntGetProcAddress("glSpriteParameterfvSGIX");
	if(!glSpriteParameterfvSGIX) bIsLoaded = 0;
	glSpriteParameteriSGIX = (PFNGLSPRITEPARAMETERISGIXPROC)gleIntGetProcAddress("glSpriteParameteriSGIX");
	if(!glSpriteParameteriSGIX) bIsLoaded = 0;
	glSpriteParameterivSGIX = (PFNGLSPRITEPARAMETERIVSGIXPROC)gleIntGetProcAddress("glSpriteParameterivSGIX");
	if(!glSpriteParameterivSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_sprite*/
	return bIsLoaded;
}

#ifndef GL_SGIX_tag_sample_buffer
typedef void (GLE_FUNCPTR * PFNGLTAGSAMPLEBUFFERSGIXPROC)();

PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIX;
#endif /*GL_SGIX_tag_sample_buffer*/

static int gleIntLoad_SGIX_tag_sample_buffer()
{
	int bIsLoaded = 1;
#ifndef GL_SGIX_tag_sample_buffer
	glTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC)gleIntGetProcAddress("glTagSampleBufferSGIX");
	if(!glTagSampleBufferSGIX) bIsLoaded = 0;
#endif /*GL_SGIX_tag_sample_buffer*/
	return bIsLoaded;
}










#ifndef GL_SGI_color_table
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLESGIPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORTABLESGIPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLESGIPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum , GLenum , GLint *);

PFNGLCOLORTABLESGIPROC glColorTableSGI;
PFNGLCOLORTABLEPARAMETERFVSGIPROC glColorTableParameterfvSGI;
PFNGLCOLORTABLEPARAMETERIVSGIPROC glColorTableParameterivSGI;
PFNGLCOPYCOLORTABLESGIPROC glCopyColorTableSGI;
PFNGLGETCOLORTABLESGIPROC glGetColorTableSGI;
PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glGetColorTableParameterfvSGI;
PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glGetColorTableParameterivSGI;
#endif /*GL_SGI_color_table*/

static int gleIntLoad_SGI_color_table()
{
	int bIsLoaded = 1;
#ifndef GL_SGI_color_table
	glColorTableSGI = (PFNGLCOLORTABLESGIPROC)gleIntGetProcAddress("glColorTableSGI");
	if(!glColorTableSGI) bIsLoaded = 0;
	glColorTableParameterfvSGI = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)gleIntGetProcAddress("glColorTableParameterfvSGI");
	if(!glColorTableParameterfvSGI) bIsLoaded = 0;
	glColorTableParameterivSGI = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)gleIntGetProcAddress("glColorTableParameterivSGI");
	if(!glColorTableParameterivSGI) bIsLoaded = 0;
	glCopyColorTableSGI = (PFNGLCOPYCOLORTABLESGIPROC)gleIntGetProcAddress("glCopyColorTableSGI");
	if(!glCopyColorTableSGI) bIsLoaded = 0;
	glGetColorTableSGI = (PFNGLGETCOLORTABLESGIPROC)gleIntGetProcAddress("glGetColorTableSGI");
	if(!glGetColorTableSGI) bIsLoaded = 0;
	glGetColorTableParameterfvSGI = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)gleIntGetProcAddress("glGetColorTableParameterfvSGI");
	if(!glGetColorTableParameterfvSGI) bIsLoaded = 0;
	glGetColorTableParameterivSGI = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)gleIntGetProcAddress("glGetColorTableParameterivSGI");
	if(!glGetColorTableParameterivSGI) bIsLoaded = 0;
#endif /*GL_SGI_color_table*/
	return bIsLoaded;
}


#ifndef GL_SUNX_constant_data
typedef void (GLE_FUNCPTR * PFNGLFINISHTEXTURESUNXPROC)();

PFNGLFINISHTEXTURESUNXPROC glFinishTextureSUNX;
#endif /*GL_SUNX_constant_data*/

static int gleIntLoad_SUNX_constant_data()
{
	int bIsLoaded = 1;
#ifndef GL_SUNX_constant_data
	glFinishTextureSUNX = (PFNGLFINISHTEXTURESUNXPROC)gleIntGetProcAddress("glFinishTextureSUNX");
	if(!glFinishTextureSUNX) bIsLoaded = 0;
#endif /*GL_SUNX_constant_data*/
	return bIsLoaded;
}

#ifndef GL_SUN_global_alpha
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORISUNPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint );

PFNGLGLOBALALPHAFACTORBSUNPROC glGlobalAlphaFactorbSUN;
PFNGLGLOBALALPHAFACTORSSUNPROC glGlobalAlphaFactorsSUN;
PFNGLGLOBALALPHAFACTORISUNPROC glGlobalAlphaFactoriSUN;
PFNGLGLOBALALPHAFACTORFSUNPROC glGlobalAlphaFactorfSUN;
PFNGLGLOBALALPHAFACTORDSUNPROC glGlobalAlphaFactordSUN;
PFNGLGLOBALALPHAFACTORUBSUNPROC glGlobalAlphaFactorubSUN;
PFNGLGLOBALALPHAFACTORUSSUNPROC glGlobalAlphaFactorusSUN;
PFNGLGLOBALALPHAFACTORUISUNPROC glGlobalAlphaFactoruiSUN;
#endif /*GL_SUN_global_alpha*/

static int gleIntLoad_SUN_global_alpha()
{
	int bIsLoaded = 1;
#ifndef GL_SUN_global_alpha
	glGlobalAlphaFactorbSUN = (PFNGLGLOBALALPHAFACTORBSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactorbSUN");
	if(!glGlobalAlphaFactorbSUN) bIsLoaded = 0;
	glGlobalAlphaFactorsSUN = (PFNGLGLOBALALPHAFACTORSSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactorsSUN");
	if(!glGlobalAlphaFactorsSUN) bIsLoaded = 0;
	glGlobalAlphaFactoriSUN = (PFNGLGLOBALALPHAFACTORISUNPROC)gleIntGetProcAddress("glGlobalAlphaFactoriSUN");
	if(!glGlobalAlphaFactoriSUN) bIsLoaded = 0;
	glGlobalAlphaFactorfSUN = (PFNGLGLOBALALPHAFACTORFSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactorfSUN");
	if(!glGlobalAlphaFactorfSUN) bIsLoaded = 0;
	glGlobalAlphaFactordSUN = (PFNGLGLOBALALPHAFACTORDSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactordSUN");
	if(!glGlobalAlphaFactordSUN) bIsLoaded = 0;
	glGlobalAlphaFactorubSUN = (PFNGLGLOBALALPHAFACTORUBSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactorubSUN");
	if(!glGlobalAlphaFactorubSUN) bIsLoaded = 0;
	glGlobalAlphaFactorusSUN = (PFNGLGLOBALALPHAFACTORUSSUNPROC)gleIntGetProcAddress("glGlobalAlphaFactorusSUN");
	if(!glGlobalAlphaFactorusSUN) bIsLoaded = 0;
	glGlobalAlphaFactoruiSUN = (PFNGLGLOBALALPHAFACTORUISUNPROC)gleIntGetProcAddress("glGlobalAlphaFactoruiSUN");
	if(!glGlobalAlphaFactoruiSUN) bIsLoaded = 0;
#endif /*GL_SUN_global_alpha*/
	return bIsLoaded;
}
#ifndef GL_SUN_mesh_array
typedef void (GLE_FUNCPTR * PFNGLDRAWMESHARRAYSSUNPROC)(GLenum , GLint , GLsizei , GLsizei );

PFNGLDRAWMESHARRAYSSUNPROC glDrawMeshArraysSUN;
#endif /*GL_SUN_mesh_array*/

static int gleIntLoad_SUN_mesh_array()
{
	int bIsLoaded = 1;
#ifndef GL_SUN_mesh_array
	glDrawMeshArraysSUN = (PFNGLDRAWMESHARRAYSSUNPROC)gleIntGetProcAddress("glDrawMeshArraysSUN");
	if(!glDrawMeshArraysSUN) bIsLoaded = 0;
#endif /*GL_SUN_mesh_array*/
	return bIsLoaded;
}

#ifndef GL_SUN_triangle_list
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUISUNPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum , GLsizei , const GLvoid* *);

PFNGLREPLACEMENTCODEUISUNPROC glReplacementCodeuiSUN;
PFNGLREPLACEMENTCODEUSSUNPROC glReplacementCodeusSUN;
PFNGLREPLACEMENTCODEUBSUNPROC glReplacementCodeubSUN;
PFNGLREPLACEMENTCODEUIVSUNPROC glReplacementCodeuivSUN;
PFNGLREPLACEMENTCODEUSVSUNPROC glReplacementCodeusvSUN;
PFNGLREPLACEMENTCODEUBVSUNPROC glReplacementCodeubvSUN;
PFNGLREPLACEMENTCODEPOINTERSUNPROC glReplacementCodePointerSUN;
#endif /*GL_SUN_triangle_list*/

static int gleIntLoad_SUN_triangle_list()
{
	int bIsLoaded = 1;
#ifndef GL_SUN_triangle_list
	glReplacementCodeuiSUN = (PFNGLREPLACEMENTCODEUISUNPROC)gleIntGetProcAddress("glReplacementCodeuiSUN");
	if(!glReplacementCodeuiSUN) bIsLoaded = 0;
	glReplacementCodeusSUN = (PFNGLREPLACEMENTCODEUSSUNPROC)gleIntGetProcAddress("glReplacementCodeusSUN");
	if(!glReplacementCodeusSUN) bIsLoaded = 0;
	glReplacementCodeubSUN = (PFNGLREPLACEMENTCODEUBSUNPROC)gleIntGetProcAddress("glReplacementCodeubSUN");
	if(!glReplacementCodeubSUN) bIsLoaded = 0;
	glReplacementCodeuivSUN = (PFNGLREPLACEMENTCODEUIVSUNPROC)gleIntGetProcAddress("glReplacementCodeuivSUN");
	if(!glReplacementCodeuivSUN) bIsLoaded = 0;
	glReplacementCodeusvSUN = (PFNGLREPLACEMENTCODEUSVSUNPROC)gleIntGetProcAddress("glReplacementCodeusvSUN");
	if(!glReplacementCodeusvSUN) bIsLoaded = 0;
	glReplacementCodeubvSUN = (PFNGLREPLACEMENTCODEUBVSUNPROC)gleIntGetProcAddress("glReplacementCodeubvSUN");
	if(!glReplacementCodeubvSUN) bIsLoaded = 0;
	glReplacementCodePointerSUN = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)gleIntGetProcAddress("glReplacementCodePointerSUN");
	if(!glReplacementCodePointerSUN) bIsLoaded = 0;
#endif /*GL_SUN_triangle_list*/
	return bIsLoaded;
}
#ifndef GL_SUN_vertex
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVERTEX2FSUNPROC)(GLubyte , GLubyte , GLubyte , GLubyte , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVERTEX2FVSUNPROC)(const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVERTEX3FSUNPROC)(GLubyte , GLubyte , GLubyte , GLubyte , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVERTEX3FVSUNPROC)(const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FVERTEX4FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)(GLfloat , GLfloat , GLubyte , GLubyte , GLubyte , GLubyte , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)(const GLfloat *, const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)(GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)(const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)(const GLuint *, const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)(const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *);

PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUN;
PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUN;
PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUN;
PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUN;
PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUN;
PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUN;
PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUN;
PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUN;
PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUN;
PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUN;
PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUN;
PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUN;
PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUN;
PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#endif /*GL_SUN_vertex*/

static int gleIntLoad_SUN_vertex()
{
	int bIsLoaded = 1;
#ifndef GL_SUN_vertex
	glColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC)gleIntGetProcAddress("glColor4ubVertex2fSUN");
	if(!glColor4ubVertex2fSUN) bIsLoaded = 0;
	glColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)gleIntGetProcAddress("glColor4ubVertex2fvSUN");
	if(!glColor4ubVertex2fvSUN) bIsLoaded = 0;
	glColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC)gleIntGetProcAddress("glColor4ubVertex3fSUN");
	if(!glColor4ubVertex3fSUN) bIsLoaded = 0;
	glColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)gleIntGetProcAddress("glColor4ubVertex3fvSUN");
	if(!glColor4ubVertex3fvSUN) bIsLoaded = 0;
	glColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC)gleIntGetProcAddress("glColor3fVertex3fSUN");
	if(!glColor3fVertex3fSUN) bIsLoaded = 0;
	glColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glColor3fVertex3fvSUN");
	if(!glColor3fVertex3fvSUN) bIsLoaded = 0;
	glNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glNormal3fVertex3fSUN");
	if(!glNormal3fVertex3fSUN) bIsLoaded = 0;
	glNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glNormal3fVertex3fvSUN");
	if(!glNormal3fVertex3fvSUN) bIsLoaded = 0;
	glColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glColor4fNormal3fVertex3fSUN");
	if(!glColor4fNormal3fVertex3fSUN) bIsLoaded = 0;
	glColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glColor4fNormal3fVertex3fvSUN");
	if(!glColor4fNormal3fVertex3fvSUN) bIsLoaded = 0;
	glTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)gleIntGetProcAddress("glTexCoord2fVertex3fSUN");
	if(!glTexCoord2fVertex3fSUN) bIsLoaded = 0;
	glTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)gleIntGetProcAddress("glTexCoord2fVertex3fvSUN");
	if(!glTexCoord2fVertex3fvSUN) bIsLoaded = 0;
	glTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)gleIntGetProcAddress("glTexCoord4fVertex4fSUN");
	if(!glTexCoord4fVertex4fSUN) bIsLoaded = 0;
	glTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)gleIntGetProcAddress("glTexCoord4fVertex4fvSUN");
	if(!glTexCoord4fVertex4fvSUN) bIsLoaded = 0;
	glTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)gleIntGetProcAddress("glTexCoord2fColor4ubVertex3fSUN");
	if(!glTexCoord2fColor4ubVertex3fSUN) bIsLoaded = 0;
	glTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)gleIntGetProcAddress("glTexCoord2fColor4ubVertex3fvSUN");
	if(!glTexCoord2fColor4ubVertex3fvSUN) bIsLoaded = 0;
	glTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)gleIntGetProcAddress("glTexCoord2fColor3fVertex3fSUN");
	if(!glTexCoord2fColor3fVertex3fSUN) bIsLoaded = 0;
	glTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glTexCoord2fColor3fVertex3fvSUN");
	if(!glTexCoord2fColor3fVertex3fvSUN) bIsLoaded = 0;
	glTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glTexCoord2fNormal3fVertex3fSUN");
	if(!glTexCoord2fNormal3fVertex3fSUN) bIsLoaded = 0;
	glTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glTexCoord2fNormal3fVertex3fvSUN");
	if(!glTexCoord2fNormal3fVertex3fvSUN) bIsLoaded = 0;
	glTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fSUN");
	if(!glTexCoord2fColor4fNormal3fVertex3fSUN) bIsLoaded = 0;
	glTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glTexCoord2fColor4fNormal3fVertex3fvSUN");
	if(!glTexCoord2fColor4fNormal3fVertex3fvSUN) bIsLoaded = 0;
	glTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)gleIntGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fSUN");
	if(!glTexCoord4fColor4fNormal3fVertex4fSUN) bIsLoaded = 0;
	glTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)gleIntGetProcAddress("glTexCoord4fColor4fNormal3fVertex4fvSUN");
	if(!glTexCoord4fColor4fNormal3fVertex4fvSUN) bIsLoaded = 0;
	glReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiVertex3fSUN");
	if(!glReplacementCodeuiVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiVertex3fvSUN");
	if(!glReplacementCodeuiVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor4ubVertex3fSUN");
	if(!glReplacementCodeuiColor4ubVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor4ubVertex3fvSUN");
	if(!glReplacementCodeuiColor4ubVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor3fVertex3fSUN");
	if(!glReplacementCodeuiColor3fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor3fVertex3fvSUN");
	if(!glReplacementCodeuiColor3fVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiNormal3fVertex3fSUN");
	if(!glReplacementCodeuiNormal3fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiNormal3fVertex3fvSUN");
	if(!glReplacementCodeuiNormal3fVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
	if(!glReplacementCodeuiColor4fNormal3fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
	if(!glReplacementCodeuiColor4fNormal3fVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fSUN");
	if(!glReplacementCodeuiTexCoord2fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fVertex3fvSUN");
	if(!glReplacementCodeuiTexCoord2fVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
	if(!glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
	if(!glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
	if(!glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN) bIsLoaded = 0;
	glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)gleIntGetProcAddress("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
	if(!glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN) bIsLoaded = 0;
#endif /*GL_SUN_vertex*/
	return bIsLoaded;
}


StrToExtMap gleIntExtensionMap[] = {
	{"GL_3DFX_multisample", &glext_3DFX_multisample, NULL},
	{"GL_3DFX_tbuffer", &glext_3DFX_tbuffer, gleIntLoad_3DFX_tbuffer},
	{"GL_3DFX_texture_compression_FXT1", &glext_3DFX_texture_compression_FXT1, NULL},
	{"GL_AMD_blend_minmax_factor", &glext_AMD_blend_minmax_factor, NULL},
	{"GL_AMD_conservative_depth", &glext_AMD_conservative_depth, NULL},
	{"GL_AMD_debug_output", &glext_AMD_debug_output, gleIntLoad_AMD_debug_output},
	{"GL_AMD_depth_clamp_separate", &glext_AMD_depth_clamp_separate, NULL},
	{"GL_AMD_draw_buffers_blend", &glext_AMD_draw_buffers_blend, gleIntLoad_AMD_draw_buffers_blend},
	{"GL_AMD_multi_draw_indirect", &glext_AMD_multi_draw_indirect, gleIntLoad_AMD_multi_draw_indirect},
	{"GL_AMD_name_gen_delete", &glext_AMD_name_gen_delete, gleIntLoad_AMD_name_gen_delete},
	{"GL_AMD_performance_monitor", &glext_AMD_performance_monitor, gleIntLoad_AMD_performance_monitor},
	{"GL_AMD_pinned_memory", &glext_AMD_pinned_memory, NULL},
	{"GL_AMD_query_buffer_object", &glext_AMD_query_buffer_object, NULL},
	{"GL_AMD_sample_positions", &glext_AMD_sample_positions, gleIntLoad_AMD_sample_positions},
	{"GL_AMD_seamless_cubemap_per_texture", &glext_AMD_seamless_cubemap_per_texture, NULL},
	{"GL_AMD_shader_stencil_export", &glext_AMD_shader_stencil_export, NULL},
	{"GL_AMD_stencil_operation_extended", &glext_AMD_stencil_operation_extended, gleIntLoad_AMD_stencil_operation_extended},
	{"GL_AMD_texture_texture4", &glext_AMD_texture_texture4, NULL},
	{"GL_AMD_transform_feedback3_lines_triangles", &glext_AMD_transform_feedback3_lines_triangles, NULL},
	{"GL_AMD_vertex_shader_layer", &glext_AMD_vertex_shader_layer, NULL},
	{"GL_AMD_vertex_shader_tessellator", &glext_AMD_vertex_shader_tessellator, gleIntLoad_AMD_vertex_shader_tessellator},
	{"GL_AMD_vertex_shader_viewport_index", &glext_AMD_vertex_shader_viewport_index, NULL},
	{"GL_APPLE_aux_depth_stencil", &glext_APPLE_aux_depth_stencil, NULL},
	{"GL_APPLE_client_storage", &glext_APPLE_client_storage, NULL},
	{"GL_APPLE_element_array", &glext_APPLE_element_array, gleIntLoad_APPLE_element_array},
	{"GL_APPLE_fence", &glext_APPLE_fence, gleIntLoad_APPLE_fence},
	{"GL_APPLE_float_pixels", &glext_APPLE_float_pixels, NULL},
	{"GL_APPLE_flush_buffer_range", &glext_APPLE_flush_buffer_range, gleIntLoad_APPLE_flush_buffer_range},
	{"GL_APPLE_object_purgeable", &glext_APPLE_object_purgeable, gleIntLoad_APPLE_object_purgeable},
	{"GL_APPLE_rgb_422", &glext_APPLE_rgb_422, NULL},
	{"GL_APPLE_row_bytes", &glext_APPLE_row_bytes, NULL},
	{"GL_APPLE_specular_vector", &glext_APPLE_specular_vector, NULL},
	{"GL_APPLE_texture_range", &glext_APPLE_texture_range, gleIntLoad_APPLE_texture_range},
	{"GL_APPLE_transform_hint", &glext_APPLE_transform_hint, NULL},
	{"GL_APPLE_vertex_array_object", &glext_APPLE_vertex_array_object, gleIntLoad_APPLE_vertex_array_object},
	{"GL_APPLE_vertex_array_range", &glext_APPLE_vertex_array_range, gleIntLoad_APPLE_vertex_array_range},
	{"GL_APPLE_vertex_program_evaluators", &glext_APPLE_vertex_program_evaluators, gleIntLoad_APPLE_vertex_program_evaluators},
	{"GL_APPLE_ycbcr_422", &glext_APPLE_ycbcr_422, NULL},
	{"GL_ARB_ES2_compatibility", &glext_ARB_ES2_compatibility, gleIntLoad_ARB_ES2_compatibility},
	{"GL_ARB_ES3_compatibility", &glext_ARB_ES3_compatibility, NULL},
	{"GL_ARB_arrays_of_arrays", &glext_ARB_arrays_of_arrays, NULL},
	{"GL_ARB_base_instance", &glext_ARB_base_instance, gleIntLoad_ARB_base_instance},
	{"GL_ARB_blend_func_extended", &glext_ARB_blend_func_extended, gleIntLoad_ARB_blend_func_extended},
	{"GL_ARB_cl_event", &glext_ARB_cl_event, gleIntLoad_ARB_cl_event},
	{"GL_ARB_clear_buffer_object", &glext_ARB_clear_buffer_object, gleIntLoad_ARB_clear_buffer_object},
	{"GL_ARB_color_buffer_float", &glext_ARB_color_buffer_float, gleIntLoad_ARB_color_buffer_float},
	{"GL_ARB_compatibility", &glext_ARB_compatibility, NULL},
	{"GL_ARB_compressed_texture_pixel_storage", &glext_ARB_compressed_texture_pixel_storage, NULL},
	{"GL_ARB_compute_shader", &glext_ARB_compute_shader, gleIntLoad_ARB_compute_shader},
	{"GL_ARB_conservative_depth", &glext_ARB_conservative_depth, NULL},
	{"GL_ARB_copy_buffer", &glext_ARB_copy_buffer, gleIntLoad_ARB_copy_buffer},
	{"GL_ARB_copy_image", &glext_ARB_copy_image, gleIntLoad_ARB_copy_image},
	{"GL_ARB_debug_group", &glext_ARB_debug_group, NULL},
	{"GL_ARB_debug_label", &glext_ARB_debug_label, NULL},
	{"GL_ARB_debug_output", &glext_ARB_debug_output, gleIntLoad_ARB_debug_output},
	{"GL_ARB_debug_output2", &glext_ARB_debug_output2, NULL},
	{"GL_ARB_depth_buffer_float", &glext_ARB_depth_buffer_float, NULL},
	{"GL_ARB_depth_clamp", &glext_ARB_depth_clamp, NULL},
	{"GL_ARB_depth_texture", &glext_ARB_depth_texture, NULL},
	{"GL_ARB_draw_buffers", &glext_ARB_draw_buffers, gleIntLoad_ARB_draw_buffers},
	{"GL_ARB_draw_buffers_blend", &glext_ARB_draw_buffers_blend, gleIntLoad_ARB_draw_buffers_blend},
	{"GL_ARB_draw_elements_base_vertex", &glext_ARB_draw_elements_base_vertex, gleIntLoad_ARB_draw_elements_base_vertex},
	{"GL_ARB_draw_indirect", &glext_ARB_draw_indirect, gleIntLoad_ARB_draw_indirect},
	{"GL_ARB_draw_instanced", &glext_ARB_draw_instanced, gleIntLoad_ARB_draw_instanced},
	{"GL_ARB_explicit_attrib_location", &glext_ARB_explicit_attrib_location, NULL},
	{"GL_ARB_explicit_uniform_location", &glext_ARB_explicit_uniform_location, NULL},
	{"GL_ARB_fragment_coord_conventions", &glext_ARB_fragment_coord_conventions, NULL},
	{"GL_ARB_fragment_layer_viewport", &glext_ARB_fragment_layer_viewport, NULL},
	{"GL_ARB_fragment_program", &glext_ARB_fragment_program, NULL},
	{"GL_ARB_fragment_program_shadow", &glext_ARB_fragment_program_shadow, NULL},
	{"GL_ARB_fragment_shader", &glext_ARB_fragment_shader, NULL},
	{"GL_ARB_framebuffer_no_attachments", &glext_ARB_framebuffer_no_attachments, gleIntLoad_ARB_framebuffer_no_attachments},
	{"GL_ARB_framebuffer_object", &glext_ARB_framebuffer_object, gleIntLoad_ARB_framebuffer_object},
	{"GL_ARB_framebuffer_sRGB", &glext_ARB_framebuffer_sRGB, NULL},
	{"GL_ARB_geometry_shader4", &glext_ARB_geometry_shader4, gleIntLoad_ARB_geometry_shader4},
	{"GL_ARB_get_program_binary", &glext_ARB_get_program_binary, gleIntLoad_ARB_get_program_binary},
	{"GL_ARB_gpu_shader5", &glext_ARB_gpu_shader5, NULL},
	{"GL_ARB_gpu_shader_fp64", &glext_ARB_gpu_shader_fp64, gleIntLoad_ARB_gpu_shader_fp64},
	{"GL_ARB_half_float_pixel", &glext_ARB_half_float_pixel, NULL},
	{"GL_ARB_half_float_vertex", &glext_ARB_half_float_vertex, NULL},
	{"GL_ARB_imaging", &glext_ARB_imaging, NULL},
	{"GL_ARB_instanced_arrays", &glext_ARB_instanced_arrays, gleIntLoad_ARB_instanced_arrays},
	{"GL_ARB_internalformat_query", &glext_ARB_internalformat_query, gleIntLoad_ARB_internalformat_query},
	{"GL_ARB_internalformat_query2", &glext_ARB_internalformat_query2, gleIntLoad_ARB_internalformat_query2},
	{"GL_ARB_invalidate_subdata", &glext_ARB_invalidate_subdata, gleIntLoad_ARB_invalidate_subdata},
	{"GL_ARB_map_buffer_alignment", &glext_ARB_map_buffer_alignment, NULL},
	{"GL_ARB_map_buffer_range", &glext_ARB_map_buffer_range, gleIntLoad_ARB_map_buffer_range},
	{"GL_ARB_matrix_palette", &glext_ARB_matrix_palette, gleIntLoad_ARB_matrix_palette},
	{"GL_ARB_multi_draw_indirect", &glext_ARB_multi_draw_indirect, gleIntLoad_ARB_multi_draw_indirect},
	{"GL_ARB_multisample", &glext_ARB_multisample, gleIntLoad_ARB_multisample},
	{"GL_ARB_multitexture", &glext_ARB_multitexture, gleIntLoad_ARB_multitexture},
	{"GL_ARB_occlusion_query", &glext_ARB_occlusion_query, gleIntLoad_ARB_occlusion_query},
	{"GL_ARB_occlusion_query2", &glext_ARB_occlusion_query2, NULL},
	{"GL_ARB_pixel_buffer_object", &glext_ARB_pixel_buffer_object, NULL},
	{"GL_ARB_point_parameters", &glext_ARB_point_parameters, gleIntLoad_ARB_point_parameters},
	{"GL_ARB_point_sprite", &glext_ARB_point_sprite, NULL},
	{"GL_ARB_program_interface_query", &glext_ARB_program_interface_query, gleIntLoad_ARB_program_interface_query},
	{"GL_ARB_provoking_vertex", &glext_ARB_provoking_vertex, gleIntLoad_ARB_provoking_vertex},
	{"GL_ARB_robust_buffer_access_behavior", &glext_ARB_robust_buffer_access_behavior, NULL},
	{"GL_ARB_robustness", &glext_ARB_robustness, gleIntLoad_ARB_robustness},
	{"GL_ARB_robustness_isolation", &glext_ARB_robustness_isolation, NULL},
	{"GL_ARB_sample_shading", &glext_ARB_sample_shading, gleIntLoad_ARB_sample_shading},
	{"GL_ARB_sampler_objects", &glext_ARB_sampler_objects, gleIntLoad_ARB_sampler_objects},
	{"GL_ARB_seamless_cube_map", &glext_ARB_seamless_cube_map, NULL},
	{"GL_ARB_separate_shader_objects", &glext_ARB_separate_shader_objects, gleIntLoad_ARB_separate_shader_objects},
	{"GL_ARB_shader_atomic_counters", &glext_ARB_shader_atomic_counters, gleIntLoad_ARB_shader_atomic_counters},
	{"GL_ARB_shader_bit_encoding", &glext_ARB_shader_bit_encoding, NULL},
	{"GL_ARB_shader_image_load_store", &glext_ARB_shader_image_load_store, gleIntLoad_ARB_shader_image_load_store},
	{"GL_ARB_shader_image_size", &glext_ARB_shader_image_size, NULL},
	{"GL_ARB_shader_objects", &glext_ARB_shader_objects, gleIntLoad_ARB_shader_objects},
	{"GL_ARB_shader_precision", &glext_ARB_shader_precision, NULL},
	{"GL_ARB_shader_stencil_export", &glext_ARB_shader_stencil_export, NULL},
	{"GL_ARB_shader_storage_buffer_object", &glext_ARB_shader_storage_buffer_object, gleIntLoad_ARB_shader_storage_buffer_object},
	{"GL_ARB_shader_subroutine", &glext_ARB_shader_subroutine, gleIntLoad_ARB_shader_subroutine},
	{"GL_ARB_shader_texture_lod", &glext_ARB_shader_texture_lod, NULL},
	{"GL_ARB_shading_language_100", &glext_ARB_shading_language_100, NULL},
	{"GL_ARB_shading_language_420pack", &glext_ARB_shading_language_420pack, NULL},
	{"GL_ARB_shading_language_include", &glext_ARB_shading_language_include, gleIntLoad_ARB_shading_language_include},
	{"GL_ARB_shading_language_packing", &glext_ARB_shading_language_packing, NULL},
	{"GL_ARB_shadow", &glext_ARB_shadow, NULL},
	{"GL_ARB_shadow_ambient", &glext_ARB_shadow_ambient, NULL},
	{"GL_ARB_stencil_texturing", &glext_ARB_stencil_texturing, NULL},
	{"GL_ARB_sync", &glext_ARB_sync, gleIntLoad_ARB_sync},
	{"GL_ARB_tessellation_shader", &glext_ARB_tessellation_shader, gleIntLoad_ARB_tessellation_shader},
	{"GL_ARB_texture_border_clamp", &glext_ARB_texture_border_clamp, NULL},
	{"GL_ARB_texture_buffer_object", &glext_ARB_texture_buffer_object, gleIntLoad_ARB_texture_buffer_object},
	{"GL_ARB_texture_buffer_object_rgb32", &glext_ARB_texture_buffer_object_rgb32, NULL},
	{"GL_ARB_texture_buffer_range", &glext_ARB_texture_buffer_range, gleIntLoad_ARB_texture_buffer_range},
	{"GL_ARB_texture_compression", &glext_ARB_texture_compression, gleIntLoad_ARB_texture_compression},
	{"GL_ARB_texture_compression_bptc", &glext_ARB_texture_compression_bptc, NULL},
	{"GL_ARB_texture_compression_rgtc", &glext_ARB_texture_compression_rgtc, NULL},
	{"GL_ARB_texture_cube_map", &glext_ARB_texture_cube_map, NULL},
	{"GL_ARB_texture_cube_map_array", &glext_ARB_texture_cube_map_array, NULL},
	{"GL_ARB_texture_env_add", &glext_ARB_texture_env_add, NULL},
	{"GL_ARB_texture_env_combine", &glext_ARB_texture_env_combine, NULL},
	{"GL_ARB_texture_env_crossbar", &glext_ARB_texture_env_crossbar, NULL},
	{"GL_ARB_texture_env_dot3", &glext_ARB_texture_env_dot3, NULL},
	{"GL_ARB_texture_float", &glext_ARB_texture_float, NULL},
	{"GL_ARB_texture_gather", &glext_ARB_texture_gather, NULL},
	{"GL_ARB_texture_mirrored_repeat", &glext_ARB_texture_mirrored_repeat, NULL},
	{"GL_ARB_texture_multisample", &glext_ARB_texture_multisample, gleIntLoad_ARB_texture_multisample},
	{"GL_ARB_texture_non_power_of_two", &glext_ARB_texture_non_power_of_two, NULL},
	{"GL_ARB_texture_query_levels", &glext_ARB_texture_query_levels, NULL},
	{"GL_ARB_texture_query_lod", &glext_ARB_texture_query_lod, NULL},
	{"GL_ARB_texture_rectangle", &glext_ARB_texture_rectangle, NULL},
	{"GL_ARB_texture_rg", &glext_ARB_texture_rg, NULL},
	{"GL_ARB_texture_rgb10_a2ui", &glext_ARB_texture_rgb10_a2ui, NULL},
	{"GL_ARB_texture_storage", &glext_ARB_texture_storage, gleIntLoad_ARB_texture_storage},
	{"GL_ARB_texture_storage_multisample", &glext_ARB_texture_storage_multisample, gleIntLoad_ARB_texture_storage_multisample},
	{"GL_ARB_texture_swizzle", &glext_ARB_texture_swizzle, NULL},
	{"GL_ARB_texture_view", &glext_ARB_texture_view, gleIntLoad_ARB_texture_view},
	{"GL_ARB_timer_query", &glext_ARB_timer_query, gleIntLoad_ARB_timer_query},
	{"GL_ARB_transform_feedback2", &glext_ARB_transform_feedback2, gleIntLoad_ARB_transform_feedback2},
	{"GL_ARB_transform_feedback3", &glext_ARB_transform_feedback3, gleIntLoad_ARB_transform_feedback3},
	{"GL_ARB_transform_feedback_instanced", &glext_ARB_transform_feedback_instanced, gleIntLoad_ARB_transform_feedback_instanced},
	{"GL_ARB_transpose_matrix", &glext_ARB_transpose_matrix, gleIntLoad_ARB_transpose_matrix},
	{"GL_ARB_uniform_buffer_object", &glext_ARB_uniform_buffer_object, gleIntLoad_ARB_uniform_buffer_object},
	{"GL_ARB_vertex_array_bgra", &glext_ARB_vertex_array_bgra, NULL},
	{"GL_ARB_vertex_array_object", &glext_ARB_vertex_array_object, gleIntLoad_ARB_vertex_array_object},
	{"GL_ARB_vertex_attrib_64bit", &glext_ARB_vertex_attrib_64bit, gleIntLoad_ARB_vertex_attrib_64bit},
	{"GL_ARB_vertex_attrib_binding", &glext_ARB_vertex_attrib_binding, gleIntLoad_ARB_vertex_attrib_binding},
	{"GL_ARB_vertex_blend", &glext_ARB_vertex_blend, gleIntLoad_ARB_vertex_blend},
	{"GL_ARB_vertex_buffer_object", &glext_ARB_vertex_buffer_object, gleIntLoad_ARB_vertex_buffer_object},
	{"GL_ARB_vertex_program", &glext_ARB_vertex_program, gleIntLoad_ARB_vertex_program},
	{"GL_ARB_vertex_shader", &glext_ARB_vertex_shader, gleIntLoad_ARB_vertex_shader},
	{"GL_ARB_vertex_type_2_10_10_10_rev", &glext_ARB_vertex_type_2_10_10_10_rev, gleIntLoad_ARB_vertex_type_2_10_10_10_rev},
	{"GL_ARB_viewport_array", &glext_ARB_viewport_array, gleIntLoad_ARB_viewport_array},
	{"GL_ARB_window_pos", &glext_ARB_window_pos, gleIntLoad_ARB_window_pos},
	{"GL_ATI_draw_buffers", &glext_ATI_draw_buffers, gleIntLoad_ATI_draw_buffers},
	{"GL_ATI_element_array", &glext_ATI_element_array, gleIntLoad_ATI_element_array},
	{"GL_ATI_envmap_bumpmap", &glext_ATI_envmap_bumpmap, gleIntLoad_ATI_envmap_bumpmap},
	{"GL_ATI_fragment_shader", &glext_ATI_fragment_shader, gleIntLoad_ATI_fragment_shader},
	{"GL_ATI_map_object_buffer", &glext_ATI_map_object_buffer, gleIntLoad_ATI_map_object_buffer},
	{"GL_ATI_meminfo", &glext_ATI_meminfo, NULL},
	{"GL_ATI_pixel_format_float", &glext_ATI_pixel_format_float, NULL},
	{"GL_ATI_pn_triangles", &glext_ATI_pn_triangles, gleIntLoad_ATI_pn_triangles},
	{"GL_ATI_separate_stencil", &glext_ATI_separate_stencil, gleIntLoad_ATI_separate_stencil},
	{"GL_ATI_text_fragment_shader", &glext_ATI_text_fragment_shader, NULL},
	{"GL_ATI_texture_env_combine3", &glext_ATI_texture_env_combine3, NULL},
	{"GL_ATI_texture_float", &glext_ATI_texture_float, NULL},
	{"GL_ATI_texture_mirror_once", &glext_ATI_texture_mirror_once, NULL},
	{"GL_ATI_vertex_array_object", &glext_ATI_vertex_array_object, gleIntLoad_ATI_vertex_array_object},
	{"GL_ATI_vertex_attrib_array_object", &glext_ATI_vertex_attrib_array_object, gleIntLoad_ATI_vertex_attrib_array_object},
	{"GL_ATI_vertex_streams", &glext_ATI_vertex_streams, gleIntLoad_ATI_vertex_streams},
	{"GL_EXT_422_pixels", &glext_EXT_422_pixels, NULL},
	{"GL_EXT_abgr", &glext_EXT_abgr, NULL},
	{"GL_EXT_bgra", &glext_EXT_bgra, NULL},
	{"GL_EXT_bindable_uniform", &glext_EXT_bindable_uniform, gleIntLoad_EXT_bindable_uniform},
	{"GL_EXT_blend_color", &glext_EXT_blend_color, gleIntLoad_EXT_blend_color},
	{"GL_EXT_blend_equation_separate", &glext_EXT_blend_equation_separate, gleIntLoad_EXT_blend_equation_separate},
	{"GL_EXT_blend_func_separate", &glext_EXT_blend_func_separate, gleIntLoad_EXT_blend_func_separate},
	{"GL_EXT_blend_logic_op", &glext_EXT_blend_logic_op, NULL},
	{"GL_EXT_blend_minmax", &glext_EXT_blend_minmax, gleIntLoad_EXT_blend_minmax},
	{"GL_EXT_blend_subtract", &glext_EXT_blend_subtract, NULL},
	{"GL_EXT_clip_volume_hint", &glext_EXT_clip_volume_hint, NULL},
	{"GL_EXT_cmyka", &glext_EXT_cmyka, NULL},
	{"GL_EXT_color_subtable", &glext_EXT_color_subtable, gleIntLoad_EXT_color_subtable},
	{"GL_EXT_compiled_vertex_array", &glext_EXT_compiled_vertex_array, gleIntLoad_EXT_compiled_vertex_array},
	{"GL_EXT_convolution", &glext_EXT_convolution, gleIntLoad_EXT_convolution},
	{"GL_EXT_coordinate_frame", &glext_EXT_coordinate_frame, gleIntLoad_EXT_coordinate_frame},
	{"GL_EXT_copy_texture", &glext_EXT_copy_texture, gleIntLoad_EXT_copy_texture},
	{"GL_EXT_cull_vertex", &glext_EXT_cull_vertex, gleIntLoad_EXT_cull_vertex},
	{"GL_EXT_depth_bounds_test", &glext_EXT_depth_bounds_test, gleIntLoad_EXT_depth_bounds_test},
	{"GL_EXT_direct_state_access", &glext_EXT_direct_state_access, gleIntLoad_EXT_direct_state_access},
	{"GL_EXT_draw_buffers2", &glext_EXT_draw_buffers2, gleIntLoad_EXT_draw_buffers2},
	{"GL_EXT_draw_instanced", &glext_EXT_draw_instanced, gleIntLoad_EXT_draw_instanced},
	{"GL_EXT_draw_range_elements", &glext_EXT_draw_range_elements, gleIntLoad_EXT_draw_range_elements},
	{"GL_EXT_fog_coord", &glext_EXT_fog_coord, gleIntLoad_EXT_fog_coord},
	{"GL_EXT_framebuffer_blit", &glext_EXT_framebuffer_blit, gleIntLoad_EXT_framebuffer_blit},
	{"GL_EXT_framebuffer_multisample", &glext_EXT_framebuffer_multisample, gleIntLoad_EXT_framebuffer_multisample},
	{"GL_EXT_framebuffer_multisample_blit_scaled", &glext_EXT_framebuffer_multisample_blit_scaled, NULL},
	{"GL_EXT_framebuffer_object", &glext_EXT_framebuffer_object, gleIntLoad_EXT_framebuffer_object},
	{"GL_EXT_framebuffer_sRGB", &glext_EXT_framebuffer_sRGB, NULL},
	{"GL_EXT_geometry_shader4", &glext_EXT_geometry_shader4, gleIntLoad_EXT_geometry_shader4},
	{"GL_EXT_gpu_program_parameters", &glext_EXT_gpu_program_parameters, gleIntLoad_EXT_gpu_program_parameters},
	{"GL_EXT_gpu_shader4", &glext_EXT_gpu_shader4, gleIntLoad_EXT_gpu_shader4},
	{"GL_EXT_histogram", &glext_EXT_histogram, gleIntLoad_EXT_histogram},
	{"GL_EXT_index_array_formats", &glext_EXT_index_array_formats, NULL},
	{"GL_EXT_index_func", &glext_EXT_index_func, gleIntLoad_EXT_index_func},
	{"GL_EXT_index_material", &glext_EXT_index_material, gleIntLoad_EXT_index_material},
	{"GL_EXT_index_texture", &glext_EXT_index_texture, NULL},
	{"GL_EXT_light_texture", &glext_EXT_light_texture, gleIntLoad_EXT_light_texture},
	{"GL_EXT_misc_attribute", &glext_EXT_misc_attribute, NULL},
	{"GL_EXT_multi_draw_arrays", &glext_EXT_multi_draw_arrays, gleIntLoad_EXT_multi_draw_arrays},
	{"GL_EXT_multisample", &glext_EXT_multisample, gleIntLoad_EXT_multisample},
	{"GL_EXT_packed_depth_stencil", &glext_EXT_packed_depth_stencil, NULL},
	{"GL_EXT_packed_float", &glext_EXT_packed_float, NULL},
	{"GL_EXT_packed_pixels", &glext_EXT_packed_pixels, NULL},
	{"GL_EXT_paletted_texture", &glext_EXT_paletted_texture, gleIntLoad_EXT_paletted_texture},
	{"GL_EXT_pixel_buffer_object", &glext_EXT_pixel_buffer_object, NULL},
	{"GL_EXT_pixel_transform", &glext_EXT_pixel_transform, gleIntLoad_EXT_pixel_transform},
	{"GL_EXT_pixel_transform_color_table", &glext_EXT_pixel_transform_color_table, NULL},
	{"GL_EXT_point_parameters", &glext_EXT_point_parameters, gleIntLoad_EXT_point_parameters},
	{"GL_EXT_polygon_offset", &glext_EXT_polygon_offset, gleIntLoad_EXT_polygon_offset},
	{"GL_EXT_provoking_vertex", &glext_EXT_provoking_vertex, gleIntLoad_EXT_provoking_vertex},
	{"GL_EXT_rescale_normal", &glext_EXT_rescale_normal, NULL},
	{"GL_EXT_secondary_color", &glext_EXT_secondary_color, gleIntLoad_EXT_secondary_color},
	{"GL_EXT_separate_shader_objects", &glext_EXT_separate_shader_objects, gleIntLoad_EXT_separate_shader_objects},
	{"GL_EXT_separate_specular_color", &glext_EXT_separate_specular_color, NULL},
	{"GL_EXT_shader_image_load_store", &glext_EXT_shader_image_load_store, gleIntLoad_EXT_shader_image_load_store},
	{"GL_EXT_shadow_funcs", &glext_EXT_shadow_funcs, NULL},
	{"GL_EXT_shared_texture_palette", &glext_EXT_shared_texture_palette, NULL},
	{"GL_EXT_stencil_clear_tag", &glext_EXT_stencil_clear_tag, gleIntLoad_EXT_stencil_clear_tag},
	{"GL_EXT_stencil_two_side", &glext_EXT_stencil_two_side, gleIntLoad_EXT_stencil_two_side},
	{"GL_EXT_stencil_wrap", &glext_EXT_stencil_wrap, NULL},
	{"GL_EXT_subtexture", &glext_EXT_subtexture, gleIntLoad_EXT_subtexture},
	{"GL_EXT_texture", &glext_EXT_texture, NULL},
	{"GL_EXT_texture3D", &glext_EXT_texture3D, gleIntLoad_EXT_texture3D},
	{"GL_EXT_texture_array", &glext_EXT_texture_array, NULL},
	{"GL_EXT_texture_buffer_object", &glext_EXT_texture_buffer_object, gleIntLoad_EXT_texture_buffer_object},
	{"GL_EXT_texture_compression_latc", &glext_EXT_texture_compression_latc, NULL},
	{"GL_EXT_texture_compression_rgtc", &glext_EXT_texture_compression_rgtc, NULL},
	{"GL_EXT_texture_compression_s3tc", &glext_EXT_texture_compression_s3tc, NULL},
	{"GL_EXT_texture_cube_map", &glext_EXT_texture_cube_map, NULL},
	{"GL_EXT_texture_env_add", &glext_EXT_texture_env_add, NULL},
	{"GL_EXT_texture_env_combine", &glext_EXT_texture_env_combine, NULL},
	{"GL_EXT_texture_env_dot3", &glext_EXT_texture_env_dot3, NULL},
	{"GL_EXT_texture_filter_anisotropic", &glext_EXT_texture_filter_anisotropic, NULL},
	{"GL_EXT_texture_integer", &glext_EXT_texture_integer, gleIntLoad_EXT_texture_integer},
	{"GL_EXT_texture_lod_bias", &glext_EXT_texture_lod_bias, NULL},
	{"GL_EXT_texture_mirror_clamp", &glext_EXT_texture_mirror_clamp, NULL},
	{"GL_EXT_texture_object", &glext_EXT_texture_object, gleIntLoad_EXT_texture_object},
	{"GL_EXT_texture_perturb_normal", &glext_EXT_texture_perturb_normal, gleIntLoad_EXT_texture_perturb_normal},
	{"GL_EXT_texture_sRGB", &glext_EXT_texture_sRGB, NULL},
	{"GL_EXT_texture_sRGB_decode", &glext_EXT_texture_sRGB_decode, NULL},
	{"GL_EXT_texture_shared_exponent", &glext_EXT_texture_shared_exponent, NULL},
	{"GL_EXT_texture_snorm", &glext_EXT_texture_snorm, NULL},
	{"GL_EXT_texture_swizzle", &glext_EXT_texture_swizzle, NULL},
	{"GL_EXT_timer_query", &glext_EXT_timer_query, gleIntLoad_EXT_timer_query},
	{"GL_EXT_transform_feedback", &glext_EXT_transform_feedback, gleIntLoad_EXT_transform_feedback},
	{"GL_EXT_vertex_array", &glext_EXT_vertex_array, gleIntLoad_EXT_vertex_array},
	{"GL_EXT_vertex_array_bgra", &glext_EXT_vertex_array_bgra, NULL},
	{"GL_EXT_vertex_attrib_64bit", &glext_EXT_vertex_attrib_64bit, gleIntLoad_EXT_vertex_attrib_64bit},
	{"GL_EXT_vertex_shader", &glext_EXT_vertex_shader, gleIntLoad_EXT_vertex_shader},
	{"GL_EXT_vertex_weighting", &glext_EXT_vertex_weighting, gleIntLoad_EXT_vertex_weighting},
	{"GL_EXT_x11_sync_object", &glext_EXT_x11_sync_object, gleIntLoad_EXT_x11_sync_object},
	{"GL_FfdMaskSGIX", &glext_FfdMaskSGIX, NULL},
	{"GL_GREMEDY_frame_terminator", &glext_GREMEDY_frame_terminator, gleIntLoad_GREMEDY_frame_terminator},
	{"GL_GREMEDY_string_marker", &glext_GREMEDY_string_marker, gleIntLoad_GREMEDY_string_marker},
	{"GL_HP_convolution_border_modes", &glext_HP_convolution_border_modes, NULL},
	{"GL_HP_image_transform", &glext_HP_image_transform, gleIntLoad_HP_image_transform},
	{"GL_HP_occlusion_test", &glext_HP_occlusion_test, NULL},
	{"GL_HP_texture_lighting", &glext_HP_texture_lighting, NULL},
	{"GL_IBM_cull_vertex", &glext_IBM_cull_vertex, NULL},
	{"GL_IBM_multimode_draw_arrays", &glext_IBM_multimode_draw_arrays, gleIntLoad_IBM_multimode_draw_arrays},
	{"GL_IBM_rasterpos_clip", &glext_IBM_rasterpos_clip, NULL},
	{"GL_IBM_texture_mirrored_repeat", &glext_IBM_texture_mirrored_repeat, NULL},
	{"GL_IBM_vertex_array_lists", &glext_IBM_vertex_array_lists, gleIntLoad_IBM_vertex_array_lists},
	{"GL_INGR_color_clamp", &glext_INGR_color_clamp, NULL},
	{"GL_INGR_interlace_read", &glext_INGR_interlace_read, NULL},
	{"GL_INGR_palette_buffer", &glext_INGR_palette_buffer, NULL},
	{"GL_INTEL_parallel_arrays", &glext_INTEL_parallel_arrays, gleIntLoad_INTEL_parallel_arrays},
	{"GL_INTEL_texture_scissor", &glext_INTEL_texture_scissor, NULL},
	{"GL_KHR_debug", &glext_KHR_debug, gleIntLoad_KHR_debug},
	{"GL_KHR_texture_compression_astc_ldr", &glext_KHR_texture_compression_astc_ldr, NULL},
	{"GL_MESAX_texture_stack", &glext_MESAX_texture_stack, NULL},
	{"GL_MESA_pack_invert", &glext_MESA_pack_invert, NULL},
	{"GL_MESA_resize_buffers", &glext_MESA_resize_buffers, gleIntLoad_MESA_resize_buffers},
	{"GL_MESA_window_pos", &glext_MESA_window_pos, gleIntLoad_MESA_window_pos},
	{"GL_MESA_ycbcr_texture", &glext_MESA_ycbcr_texture, NULL},
	{"GL_NV_bindless_texture", &glext_NV_bindless_texture, gleIntLoad_NV_bindless_texture},
	{"GL_NV_blend_square", &glext_NV_blend_square, NULL},
	{"GL_NV_conditional_render", &glext_NV_conditional_render, gleIntLoad_NV_conditional_render},
	{"GL_NV_copy_depth_to_color", &glext_NV_copy_depth_to_color, NULL},
	{"GL_NV_copy_image", &glext_NV_copy_image, gleIntLoad_NV_copy_image},
	{"GL_NV_depth_buffer_float", &glext_NV_depth_buffer_float, gleIntLoad_NV_depth_buffer_float},
	{"GL_NV_depth_clamp", &glext_NV_depth_clamp, NULL},
	{"GL_NV_evaluators", &glext_NV_evaluators, gleIntLoad_NV_evaluators},
	{"GL_NV_explicit_multisample", &glext_NV_explicit_multisample, gleIntLoad_NV_explicit_multisample},
	{"GL_NV_fence", &glext_NV_fence, gleIntLoad_NV_fence},
	{"GL_NV_float_buffer", &glext_NV_float_buffer, NULL},
	{"GL_NV_fog_distance", &glext_NV_fog_distance, NULL},
	{"GL_NV_fragment_program", &glext_NV_fragment_program, gleIntLoad_NV_fragment_program},
	{"GL_NV_fragment_program2", &glext_NV_fragment_program2, NULL},
	{"GL_NV_fragment_program4", &glext_NV_fragment_program4, NULL},
	{"GL_NV_fragment_program_option", &glext_NV_fragment_program_option, NULL},
	{"GL_NV_framebuffer_multisample_coverage", &glext_NV_framebuffer_multisample_coverage, gleIntLoad_NV_framebuffer_multisample_coverage},
	{"GL_NV_geometry_program4", &glext_NV_geometry_program4, gleIntLoad_NV_geometry_program4},
	{"GL_NV_geometry_shader4", &glext_NV_geometry_shader4, NULL},
	{"GL_NV_gpu_program4", &glext_NV_gpu_program4, gleIntLoad_NV_gpu_program4},
	{"GL_NV_gpu_program5", &glext_NV_gpu_program5, gleIntLoad_NV_gpu_program5},
	{"GL_NV_gpu_shader5", &glext_NV_gpu_shader5, gleIntLoad_NV_gpu_shader5},
	{"GL_NV_half_float", &glext_NV_half_float, gleIntLoad_NV_half_float},
	{"GL_NV_light_max_exponent", &glext_NV_light_max_exponent, NULL},
	{"GL_NV_multisample_coverage", &glext_NV_multisample_coverage, NULL},
	{"GL_NV_multisample_filter_hint", &glext_NV_multisample_filter_hint, NULL},
	{"GL_NV_occlusion_query", &glext_NV_occlusion_query, gleIntLoad_NV_occlusion_query},
	{"GL_NV_packed_depth_stencil", &glext_NV_packed_depth_stencil, NULL},
	{"GL_NV_parameter_buffer_object", &glext_NV_parameter_buffer_object, gleIntLoad_NV_parameter_buffer_object},
	{"GL_NV_parameter_buffer_object2", &glext_NV_parameter_buffer_object2, NULL},
	{"GL_NV_path_rendering", &glext_NV_path_rendering, gleIntLoad_NV_path_rendering},
	{"GL_NV_pixel_data_range", &glext_NV_pixel_data_range, gleIntLoad_NV_pixel_data_range},
	{"GL_NV_point_sprite", &glext_NV_point_sprite, gleIntLoad_NV_point_sprite},
	{"GL_NV_present_video", &glext_NV_present_video, gleIntLoad_NV_present_video},
	{"GL_NV_primitive_restart", &glext_NV_primitive_restart, gleIntLoad_NV_primitive_restart},
	{"GL_NV_register_combiners", &glext_NV_register_combiners, gleIntLoad_NV_register_combiners},
	{"GL_NV_register_combiners2", &glext_NV_register_combiners2, gleIntLoad_NV_register_combiners2},
	{"GL_NV_shader_atomic_float", &glext_NV_shader_atomic_float, NULL},
	{"GL_NV_shader_buffer_load", &glext_NV_shader_buffer_load, gleIntLoad_NV_shader_buffer_load},
	{"GL_NV_shader_buffer_store", &glext_NV_shader_buffer_store, NULL},
	{"GL_NV_tessellation_program5", &glext_NV_tessellation_program5, NULL},
	{"GL_NV_texgen_emboss", &glext_NV_texgen_emboss, NULL},
	{"GL_NV_texgen_reflection", &glext_NV_texgen_reflection, NULL},
	{"GL_NV_texture_barrier", &glext_NV_texture_barrier, gleIntLoad_NV_texture_barrier},
	{"GL_NV_texture_compression_vtc", &glext_NV_texture_compression_vtc, NULL},
	{"GL_NV_texture_env_combine4", &glext_NV_texture_env_combine4, NULL},
	{"GL_NV_texture_expand_normal", &glext_NV_texture_expand_normal, NULL},
	{"GL_NV_texture_multisample", &glext_NV_texture_multisample, gleIntLoad_NV_texture_multisample},
	{"GL_NV_texture_rectangle", &glext_NV_texture_rectangle, NULL},
	{"GL_NV_texture_shader", &glext_NV_texture_shader, NULL},
	{"GL_NV_texture_shader2", &glext_NV_texture_shader2, NULL},
	{"GL_NV_texture_shader3", &glext_NV_texture_shader3, NULL},
	{"GL_NV_transform_feedback", &glext_NV_transform_feedback, gleIntLoad_NV_transform_feedback},
	{"GL_NV_transform_feedback2", &glext_NV_transform_feedback2, gleIntLoad_NV_transform_feedback2},
	{"GL_NV_vdpau_interop", &glext_NV_vdpau_interop, gleIntLoad_NV_vdpau_interop},
	{"GL_NV_vertex_array_range", &glext_NV_vertex_array_range, gleIntLoad_NV_vertex_array_range},
	{"GL_NV_vertex_array_range2", &glext_NV_vertex_array_range2, NULL},
	{"GL_NV_vertex_attrib_integer_64bit", &glext_NV_vertex_attrib_integer_64bit, gleIntLoad_NV_vertex_attrib_integer_64bit},
	{"GL_NV_vertex_buffer_unified_memory", &glext_NV_vertex_buffer_unified_memory, gleIntLoad_NV_vertex_buffer_unified_memory},
	{"GL_NV_vertex_program", &glext_NV_vertex_program, gleIntLoad_NV_vertex_program},
	{"GL_NV_vertex_program1_1", &glext_NV_vertex_program1_1, NULL},
	{"GL_NV_vertex_program2", &glext_NV_vertex_program2, NULL},
	{"GL_NV_vertex_program2_option", &glext_NV_vertex_program2_option, NULL},
	{"GL_NV_vertex_program3", &glext_NV_vertex_program3, NULL},
	{"GL_NV_vertex_program4", &glext_NV_vertex_program4, gleIntLoad_NV_vertex_program4},
	{"GL_NV_video_capture", &glext_NV_video_capture, gleIntLoad_NV_video_capture},
	{"GL_OES_read_format", &glext_OES_read_format, NULL},
	{"GL_OML_interlace", &glext_OML_interlace, NULL},
	{"GL_OML_resample", &glext_OML_resample, NULL},
	{"GL_OML_subsample", &glext_OML_subsample, NULL},
	{"GL_PGI_misc_hints", &glext_PGI_misc_hints, gleIntLoad_PGI_misc_hints},
	{"GL_PGI_vertex_hints", &glext_PGI_vertex_hints, NULL},
	{"GL_REND_screen_coordinates", &glext_REND_screen_coordinates, NULL},
	{"GL_S3_s3tc", &glext_S3_s3tc, NULL},
	{"GL_SGIS_detail_texture", &glext_SGIS_detail_texture, gleIntLoad_SGIS_detail_texture},
	{"GL_SGIS_fog_function", &glext_SGIS_fog_function, gleIntLoad_SGIS_fog_function},
	{"GL_SGIS_generate_mipmap", &glext_SGIS_generate_mipmap, NULL},
	{"GL_SGIS_multisample", &glext_SGIS_multisample, gleIntLoad_SGIS_multisample},
	{"GL_SGIS_pixel_texture", &glext_SGIS_pixel_texture, gleIntLoad_SGIS_pixel_texture},
	{"GL_SGIS_point_line_texgen", &glext_SGIS_point_line_texgen, NULL},
	{"GL_SGIS_point_parameters", &glext_SGIS_point_parameters, gleIntLoad_SGIS_point_parameters},
	{"GL_SGIS_sharpen_texture", &glext_SGIS_sharpen_texture, gleIntLoad_SGIS_sharpen_texture},
	{"GL_SGIS_texture4D", &glext_SGIS_texture4D, gleIntLoad_SGIS_texture4D},
	{"GL_SGIS_texture_border_clamp", &glext_SGIS_texture_border_clamp, NULL},
	{"GL_SGIS_texture_color_mask", &glext_SGIS_texture_color_mask, gleIntLoad_SGIS_texture_color_mask},
	{"GL_SGIS_texture_edge_clamp", &glext_SGIS_texture_edge_clamp, NULL},
	{"GL_SGIS_texture_filter4", &glext_SGIS_texture_filter4, gleIntLoad_SGIS_texture_filter4},
	{"GL_SGIS_texture_lod", &glext_SGIS_texture_lod, NULL},
	{"GL_SGIS_texture_select", &glext_SGIS_texture_select, NULL},
	{"GL_SGIX_async", &glext_SGIX_async, gleIntLoad_SGIX_async},
	{"GL_SGIX_async_histogram", &glext_SGIX_async_histogram, NULL},
	{"GL_SGIX_async_pixel", &glext_SGIX_async_pixel, NULL},
	{"GL_SGIX_blend_alpha_minmax", &glext_SGIX_blend_alpha_minmax, NULL},
	{"GL_SGIX_calligraphic_fragment", &glext_SGIX_calligraphic_fragment, NULL},
	{"GL_SGIX_clipmap", &glext_SGIX_clipmap, NULL},
	{"GL_SGIX_convolution_accuracy", &glext_SGIX_convolution_accuracy, NULL},
	{"GL_SGIX_depth_texture", &glext_SGIX_depth_texture, NULL},
	{"GL_SGIX_flush_raster", &glext_SGIX_flush_raster, gleIntLoad_SGIX_flush_raster},
	{"GL_SGIX_fog_offset", &glext_SGIX_fog_offset, NULL},
	{"GL_SGIX_fog_scale", &glext_SGIX_fog_scale, NULL},
	{"GL_SGIX_fragment_lighting", &glext_SGIX_fragment_lighting, gleIntLoad_SGIX_fragment_lighting},
	{"GL_SGIX_framezoom", &glext_SGIX_framezoom, gleIntLoad_SGIX_framezoom},
	{"GL_SGIX_impact_pixel_texture", &glext_SGIX_impact_pixel_texture, NULL},
	{"GL_SGIX_instruments", &glext_SGIX_instruments, gleIntLoad_SGIX_instruments},
	{"GL_SGIX_interlace", &glext_SGIX_interlace, NULL},
	{"GL_SGIX_ir_instrument1", &glext_SGIX_ir_instrument1, NULL},
	{"GL_SGIX_list_priority", &glext_SGIX_list_priority, gleIntLoad_SGIX_list_priority},
	{"GL_SGIX_pixel_texture", &glext_SGIX_pixel_texture, gleIntLoad_SGIX_pixel_texture},
	{"GL_SGIX_pixel_tiles", &glext_SGIX_pixel_tiles, NULL},
	{"GL_SGIX_polynomial_ffd", &glext_SGIX_polynomial_ffd, gleIntLoad_SGIX_polynomial_ffd},
	{"GL_SGIX_reference_plane", &glext_SGIX_reference_plane, gleIntLoad_SGIX_reference_plane},
	{"GL_SGIX_resample", &glext_SGIX_resample, NULL},
	{"GL_SGIX_scalebias_hint", &glext_SGIX_scalebias_hint, NULL},
	{"GL_SGIX_shadow", &glext_SGIX_shadow, NULL},
	{"GL_SGIX_shadow_ambient", &glext_SGIX_shadow_ambient, NULL},
	{"GL_SGIX_sprite", &glext_SGIX_sprite, gleIntLoad_SGIX_sprite},
	{"GL_SGIX_subsample", &glext_SGIX_subsample, NULL},
	{"GL_SGIX_tag_sample_buffer", &glext_SGIX_tag_sample_buffer, gleIntLoad_SGIX_tag_sample_buffer},
	{"GL_SGIX_texture_add_env", &glext_SGIX_texture_add_env, NULL},
	{"GL_SGIX_texture_coordinate_clamp", &glext_SGIX_texture_coordinate_clamp, NULL},
	{"GL_SGIX_texture_lod_bias", &glext_SGIX_texture_lod_bias, NULL},
	{"GL_SGIX_texture_multi_buffer", &glext_SGIX_texture_multi_buffer, NULL},
	{"GL_SGIX_texture_scale_bias", &glext_SGIX_texture_scale_bias, NULL},
	{"GL_SGIX_vertex_preclip", &glext_SGIX_vertex_preclip, NULL},
	{"GL_SGIX_ycrcb", &glext_SGIX_ycrcb, NULL},
	{"GL_SGIX_ycrcb_subsample", &glext_SGIX_ycrcb_subsample, NULL},
	{"GL_SGIX_ycrcba", &glext_SGIX_ycrcba, NULL},
	{"GL_SGI_color_matrix", &glext_SGI_color_matrix, NULL},
	{"GL_SGI_color_table", &glext_SGI_color_table, gleIntLoad_SGI_color_table},
	{"GL_SGI_depth_pass_instrument", &glext_SGI_depth_pass_instrument, NULL},
	{"GL_SGI_texture_color_table", &glext_SGI_texture_color_table, NULL},
	{"GL_SUNX_constant_data", &glext_SUNX_constant_data, gleIntLoad_SUNX_constant_data},
	{"GL_SUN_convolution_border_modes", &glext_SUN_convolution_border_modes, NULL},
	{"GL_SUN_global_alpha", &glext_SUN_global_alpha, gleIntLoad_SUN_global_alpha},
	{"GL_SUN_mesh_array", &glext_SUN_mesh_array, gleIntLoad_SUN_mesh_array},
	{"GL_SUN_slice_accum", &glext_SUN_slice_accum, NULL},
	{"GL_SUN_triangle_list", &glext_SUN_triangle_list, gleIntLoad_SUN_triangle_list},
	{"GL_SUN_vertex", &glext_SUN_vertex, gleIntLoad_SUN_vertex},
	{"GL_WIN_phong_shading", &glext_WIN_phong_shading, NULL},
	{"GL_WIN_specular_fog", &glext_WIN_specular_fog, NULL},
};

int gleIntExtensionMapSize = 440;

typedef void (GLE_FUNCPTR * PFNGLCULLFACEPROC)(GLenum );
PFNGLCULLFACEPROC __gleCullFace;
typedef void (GLE_FUNCPTR * PFNGLFRONTFACEPROC)(GLenum );
PFNGLFRONTFACEPROC __gleFrontFace;
typedef void (GLE_FUNCPTR * PFNGLHINTPROC)(GLenum , GLenum );
PFNGLHINTPROC __gleHint;
typedef void (GLE_FUNCPTR * PFNGLLINEWIDTHPROC)(GLfloat );
PFNGLLINEWIDTHPROC __gleLineWidth;
typedef void (GLE_FUNCPTR * PFNGLPOINTSIZEPROC)(GLfloat );
PFNGLPOINTSIZEPROC __glePointSize;
typedef void (GLE_FUNCPTR * PFNGLPOLYGONMODEPROC)(GLenum , GLenum );
PFNGLPOLYGONMODEPROC __glePolygonMode;
typedef void (GLE_FUNCPTR * PFNGLSCISSORPROC)(GLint , GLint , GLsizei , GLsizei );
PFNGLSCISSORPROC __gleScissor;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERFPROC)(GLenum , GLenum , GLfloat );
PFNGLTEXPARAMETERFPROC __gleTexParameterf;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLTEXPARAMETERFVPROC __gleTexParameterfv;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIPROC)(GLenum , GLenum , GLint );
PFNGLTEXPARAMETERIPROC __gleTexParameteri;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
PFNGLTEXPARAMETERIVPROC __gleTexParameteriv;
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
PFNGLTEXIMAGE1DPROC __gleTexImage1D;
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DPROC)(GLenum , GLint , GLint , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
PFNGLTEXIMAGE2DPROC __gleTexImage2D;
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERPROC)(GLenum );
PFNGLDRAWBUFFERPROC __gleDrawBuffer;
typedef void (GLE_FUNCPTR * PFNGLCLEARPROC)(GLbitfield );
PFNGLCLEARPROC __gleClear;
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLCLEARCOLORPROC __gleClearColor;
typedef void (GLE_FUNCPTR * PFNGLCLEARSTENCILPROC)(GLint );
PFNGLCLEARSTENCILPROC __gleClearStencil;
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHPROC)(GLdouble );
PFNGLCLEARDEPTHPROC __gleClearDepth;
typedef void (GLE_FUNCPTR * PFNGLSTENCILMASKPROC)(GLuint );
PFNGLSTENCILMASKPROC __gleStencilMask;
typedef void (GLE_FUNCPTR * PFNGLCOLORMASKPROC)(GLboolean , GLboolean , GLboolean , GLboolean );
PFNGLCOLORMASKPROC __gleColorMask;
typedef void (GLE_FUNCPTR * PFNGLDEPTHMASKPROC)(GLboolean );
PFNGLDEPTHMASKPROC __gleDepthMask;
typedef void (GLE_FUNCPTR * PFNGLDISABLEPROC)(GLenum );
PFNGLDISABLEPROC __gleDisable;
typedef void (GLE_FUNCPTR * PFNGLENABLEPROC)(GLenum );
PFNGLENABLEPROC __gleEnable;
typedef void (GLE_FUNCPTR * PFNGLFINISHPROC)();
PFNGLFINISHPROC __gleFinish;
typedef void (GLE_FUNCPTR * PFNGLFLUSHPROC)();
PFNGLFLUSHPROC __gleFlush;
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCPROC)(GLenum , GLenum );
PFNGLBLENDFUNCPROC __gleBlendFunc;
typedef void (GLE_FUNCPTR * PFNGLLOGICOPPROC)(GLenum );
PFNGLLOGICOPPROC __gleLogicOp;
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCPROC)(GLenum , GLint , GLuint );
PFNGLSTENCILFUNCPROC __gleStencilFunc;
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPPROC)(GLenum , GLenum , GLenum );
PFNGLSTENCILOPPROC __gleStencilOp;
typedef void (GLE_FUNCPTR * PFNGLDEPTHFUNCPROC)(GLenum );
PFNGLDEPTHFUNCPROC __gleDepthFunc;
typedef void (GLE_FUNCPTR * PFNGLPIXELSTOREFPROC)(GLenum , GLfloat );
PFNGLPIXELSTOREFPROC __glePixelStoref;
typedef void (GLE_FUNCPTR * PFNGLPIXELSTOREIPROC)(GLenum , GLint );
PFNGLPIXELSTOREIPROC __glePixelStorei;
typedef void (GLE_FUNCPTR * PFNGLREADBUFFERPROC)(GLenum );
PFNGLREADBUFFERPROC __gleReadBuffer;
typedef void (GLE_FUNCPTR * PFNGLREADPIXELSPROC)(GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLvoid *);
PFNGLREADPIXELSPROC __gleReadPixels;
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANVPROC)(GLenum , GLboolean *);
PFNGLGETBOOLEANVPROC __gleGetBooleanv;
typedef void (GLE_FUNCPTR * PFNGLGETDOUBLEVPROC)(GLenum , GLdouble *);
PFNGLGETDOUBLEVPROC __gleGetDoublev;
typedef GLenum (GLE_FUNCPTR * PFNGLGETERRORPROC)();
PFNGLGETERRORPROC __gleGetError;
typedef void (GLE_FUNCPTR * PFNGLGETFLOATVPROC)(GLenum , GLfloat *);
PFNGLGETFLOATVPROC __gleGetFloatv;
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERVPROC)(GLenum , GLint *);
PFNGLGETINTEGERVPROC __gleGetIntegerv;
typedef const GLubyte * (GLE_FUNCPTR * PFNGLGETSTRINGPROC)(GLenum );
PFNGLGETSTRINGPROC __gleGetString;
typedef void (GLE_FUNCPTR * PFNGLGETTEXIMAGEPROC)(GLenum , GLint , GLenum , GLenum , GLvoid *);
PFNGLGETTEXIMAGEPROC __gleGetTexImage;
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETTEXPARAMETERFVPROC __gleGetTexParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETTEXPARAMETERIVPROC __gleGetTexParameteriv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum , GLint , GLenum , GLfloat *);
PFNGLGETTEXLEVELPARAMETERFVPROC __gleGetTexLevelParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum , GLint , GLenum , GLint *);
PFNGLGETTEXLEVELPARAMETERIVPROC __gleGetTexLevelParameteriv;
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDPROC)(GLenum );
PFNGLISENABLEDPROC __gleIsEnabled;
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEPROC)(GLdouble , GLdouble );
PFNGLDEPTHRANGEPROC __gleDepthRange;
typedef void (GLE_FUNCPTR * PFNGLVIEWPORTPROC)(GLint , GLint , GLsizei , GLsizei );
PFNGLVIEWPORTPROC __gleViewport;
typedef void (GLE_FUNCPTR * PFNGLNEWLISTPROC)(GLuint , GLenum );
PFNGLNEWLISTPROC __gleNewList;
typedef void (GLE_FUNCPTR * PFNGLENDLISTPROC)();
PFNGLENDLISTPROC __gleEndList;
typedef void (GLE_FUNCPTR * PFNGLCALLLISTPROC)(GLuint );
PFNGLCALLLISTPROC __gleCallList;
typedef void (GLE_FUNCPTR * PFNGLCALLLISTSPROC)(GLsizei , GLenum , const GLvoid *);
PFNGLCALLLISTSPROC __gleCallLists;
typedef void (GLE_FUNCPTR * PFNGLDELETELISTSPROC)(GLuint , GLsizei );
PFNGLDELETELISTSPROC __gleDeleteLists;
typedef GLuint (GLE_FUNCPTR * PFNGLGENLISTSPROC)(GLsizei );
PFNGLGENLISTSPROC __gleGenLists;
typedef void (GLE_FUNCPTR * PFNGLLISTBASEPROC)(GLuint );
PFNGLLISTBASEPROC __gleListBase;
typedef void (GLE_FUNCPTR * PFNGLBEGINPROC)(GLenum );
PFNGLBEGINPROC __gleBegin;
typedef void (GLE_FUNCPTR * PFNGLBITMAPPROC)(GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *);
PFNGLBITMAPPROC __gleBitmap;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3BPROC)(GLbyte , GLbyte , GLbyte );
PFNGLCOLOR3BPROC __gleColor3b;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3BVPROC)(const GLbyte *);
PFNGLCOLOR3BVPROC __gleColor3bv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLCOLOR3DPROC __gleColor3d;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3DVPROC)(const GLdouble *);
PFNGLCOLOR3DVPROC __gleColor3dv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLCOLOR3FPROC __gleColor3f;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FVPROC)(const GLfloat *);
PFNGLCOLOR3FVPROC __gleColor3fv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3IPROC)(GLint , GLint , GLint );
PFNGLCOLOR3IPROC __gleColor3i;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3IVPROC)(const GLint *);
PFNGLCOLOR3IVPROC __gleColor3iv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3SPROC)(GLshort , GLshort , GLshort );
PFNGLCOLOR3SPROC __gleColor3s;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3SVPROC)(const GLshort *);
PFNGLCOLOR3SVPROC __gleColor3sv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UBPROC)(GLubyte , GLubyte , GLubyte );
PFNGLCOLOR3UBPROC __gleColor3ub;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UBVPROC)(const GLubyte *);
PFNGLCOLOR3UBVPROC __gleColor3ubv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UIPROC)(GLuint , GLuint , GLuint );
PFNGLCOLOR3UIPROC __gleColor3ui;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UIVPROC)(const GLuint *);
PFNGLCOLOR3UIVPROC __gleColor3uiv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3USPROC)(GLushort , GLushort , GLushort );
PFNGLCOLOR3USPROC __gleColor3us;
typedef void (GLE_FUNCPTR * PFNGLCOLOR3USVPROC)(const GLushort *);
PFNGLCOLOR3USVPROC __gleColor3usv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4BPROC)(GLbyte , GLbyte , GLbyte , GLbyte );
PFNGLCOLOR4BPROC __gleColor4b;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4BVPROC)(const GLbyte *);
PFNGLCOLOR4BVPROC __gleColor4bv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLCOLOR4DPROC __gleColor4d;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4DVPROC)(const GLdouble *);
PFNGLCOLOR4DVPROC __gleColor4dv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLCOLOR4FPROC __gleColor4f;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FVPROC)(const GLfloat *);
PFNGLCOLOR4FVPROC __gleColor4fv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4IPROC)(GLint , GLint , GLint , GLint );
PFNGLCOLOR4IPROC __gleColor4i;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4IVPROC)(const GLint *);
PFNGLCOLOR4IVPROC __gleColor4iv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4SPROC)(GLshort , GLshort , GLshort , GLshort );
PFNGLCOLOR4SPROC __gleColor4s;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4SVPROC)(const GLshort *);
PFNGLCOLOR4SVPROC __gleColor4sv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBPROC)(GLubyte , GLubyte , GLubyte , GLubyte );
PFNGLCOLOR4UBPROC __gleColor4ub;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVPROC)(const GLubyte *);
PFNGLCOLOR4UBVPROC __gleColor4ubv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UIPROC)(GLuint , GLuint , GLuint , GLuint );
PFNGLCOLOR4UIPROC __gleColor4ui;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UIVPROC)(const GLuint *);
PFNGLCOLOR4UIVPROC __gleColor4uiv;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4USPROC)(GLushort , GLushort , GLushort , GLushort );
PFNGLCOLOR4USPROC __gleColor4us;
typedef void (GLE_FUNCPTR * PFNGLCOLOR4USVPROC)(const GLushort *);
PFNGLCOLOR4USVPROC __gleColor4usv;
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPROC)(GLboolean );
PFNGLEDGEFLAGPROC __gleEdgeFlag;
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGVPROC)(const GLboolean *);
PFNGLEDGEFLAGVPROC __gleEdgeFlagv;
typedef void (GLE_FUNCPTR * PFNGLENDPROC)();
PFNGLENDPROC __gleEnd;
typedef void (GLE_FUNCPTR * PFNGLINDEXDPROC)(GLdouble );
PFNGLINDEXDPROC __gleIndexd;
typedef void (GLE_FUNCPTR * PFNGLINDEXDVPROC)(const GLdouble *);
PFNGLINDEXDVPROC __gleIndexdv;
typedef void (GLE_FUNCPTR * PFNGLINDEXFPROC)(GLfloat );
PFNGLINDEXFPROC __gleIndexf;
typedef void (GLE_FUNCPTR * PFNGLINDEXFVPROC)(const GLfloat *);
PFNGLINDEXFVPROC __gleIndexfv;
typedef void (GLE_FUNCPTR * PFNGLINDEXIPROC)(GLint );
PFNGLINDEXIPROC __gleIndexi;
typedef void (GLE_FUNCPTR * PFNGLINDEXIVPROC)(const GLint *);
PFNGLINDEXIVPROC __gleIndexiv;
typedef void (GLE_FUNCPTR * PFNGLINDEXSPROC)(GLshort );
PFNGLINDEXSPROC __gleIndexs;
typedef void (GLE_FUNCPTR * PFNGLINDEXSVPROC)(const GLshort *);
PFNGLINDEXSVPROC __gleIndexsv;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3BPROC)(GLbyte , GLbyte , GLbyte );
PFNGLNORMAL3BPROC __gleNormal3b;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3BVPROC)(const GLbyte *);
PFNGLNORMAL3BVPROC __gleNormal3bv;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLNORMAL3DPROC __gleNormal3d;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3DVPROC)(const GLdouble *);
PFNGLNORMAL3DVPROC __gleNormal3dv;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLNORMAL3FPROC __gleNormal3f;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FVPROC)(const GLfloat *);
PFNGLNORMAL3FVPROC __gleNormal3fv;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3IPROC)(GLint , GLint , GLint );
PFNGLNORMAL3IPROC __gleNormal3i;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3IVPROC)(const GLint *);
PFNGLNORMAL3IVPROC __gleNormal3iv;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3SPROC)(GLshort , GLshort , GLshort );
PFNGLNORMAL3SPROC __gleNormal3s;
typedef void (GLE_FUNCPTR * PFNGLNORMAL3SVPROC)(const GLshort *);
PFNGLNORMAL3SVPROC __gleNormal3sv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2DPROC)(GLdouble , GLdouble );
PFNGLRASTERPOS2DPROC __gleRasterPos2d;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2DVPROC)(const GLdouble *);
PFNGLRASTERPOS2DVPROC __gleRasterPos2dv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2FPROC)(GLfloat , GLfloat );
PFNGLRASTERPOS2FPROC __gleRasterPos2f;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2FVPROC)(const GLfloat *);
PFNGLRASTERPOS2FVPROC __gleRasterPos2fv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2IPROC)(GLint , GLint );
PFNGLRASTERPOS2IPROC __gleRasterPos2i;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2IVPROC)(const GLint *);
PFNGLRASTERPOS2IVPROC __gleRasterPos2iv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2SPROC)(GLshort , GLshort );
PFNGLRASTERPOS2SPROC __gleRasterPos2s;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2SVPROC)(const GLshort *);
PFNGLRASTERPOS2SVPROC __gleRasterPos2sv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLRASTERPOS3DPROC __gleRasterPos3d;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3DVPROC)(const GLdouble *);
PFNGLRASTERPOS3DVPROC __gleRasterPos3dv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLRASTERPOS3FPROC __gleRasterPos3f;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3FVPROC)(const GLfloat *);
PFNGLRASTERPOS3FVPROC __gleRasterPos3fv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3IPROC)(GLint , GLint , GLint );
PFNGLRASTERPOS3IPROC __gleRasterPos3i;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3IVPROC)(const GLint *);
PFNGLRASTERPOS3IVPROC __gleRasterPos3iv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3SPROC)(GLshort , GLshort , GLshort );
PFNGLRASTERPOS3SPROC __gleRasterPos3s;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3SVPROC)(const GLshort *);
PFNGLRASTERPOS3SVPROC __gleRasterPos3sv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLRASTERPOS4DPROC __gleRasterPos4d;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4DVPROC)(const GLdouble *);
PFNGLRASTERPOS4DVPROC __gleRasterPos4dv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLRASTERPOS4FPROC __gleRasterPos4f;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4FVPROC)(const GLfloat *);
PFNGLRASTERPOS4FVPROC __gleRasterPos4fv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4IPROC)(GLint , GLint , GLint , GLint );
PFNGLRASTERPOS4IPROC __gleRasterPos4i;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4IVPROC)(const GLint *);
PFNGLRASTERPOS4IVPROC __gleRasterPos4iv;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4SPROC)(GLshort , GLshort , GLshort , GLshort );
PFNGLRASTERPOS4SPROC __gleRasterPos4s;
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4SVPROC)(const GLshort *);
PFNGLRASTERPOS4SVPROC __gleRasterPos4sv;
typedef void (GLE_FUNCPTR * PFNGLRECTDPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLRECTDPROC __gleRectd;
typedef void (GLE_FUNCPTR * PFNGLRECTDVPROC)(const GLdouble *, const GLdouble *);
PFNGLRECTDVPROC __gleRectdv;
typedef void (GLE_FUNCPTR * PFNGLRECTFPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLRECTFPROC __gleRectf;
typedef void (GLE_FUNCPTR * PFNGLRECTFVPROC)(const GLfloat *, const GLfloat *);
PFNGLRECTFVPROC __gleRectfv;
typedef void (GLE_FUNCPTR * PFNGLRECTIPROC)(GLint , GLint , GLint , GLint );
PFNGLRECTIPROC __gleRecti;
typedef void (GLE_FUNCPTR * PFNGLRECTIVPROC)(const GLint *, const GLint *);
PFNGLRECTIVPROC __gleRectiv;
typedef void (GLE_FUNCPTR * PFNGLRECTSPROC)(GLshort , GLshort , GLshort , GLshort );
PFNGLRECTSPROC __gleRects;
typedef void (GLE_FUNCPTR * PFNGLRECTSVPROC)(const GLshort *, const GLshort *);
PFNGLRECTSVPROC __gleRectsv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1DPROC)(GLdouble );
PFNGLTEXCOORD1DPROC __gleTexCoord1d;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1DVPROC)(const GLdouble *);
PFNGLTEXCOORD1DVPROC __gleTexCoord1dv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1FPROC)(GLfloat );
PFNGLTEXCOORD1FPROC __gleTexCoord1f;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1FVPROC)(const GLfloat *);
PFNGLTEXCOORD1FVPROC __gleTexCoord1fv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1IPROC)(GLint );
PFNGLTEXCOORD1IPROC __gleTexCoord1i;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1IVPROC)(const GLint *);
PFNGLTEXCOORD1IVPROC __gleTexCoord1iv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1SPROC)(GLshort );
PFNGLTEXCOORD1SPROC __gleTexCoord1s;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1SVPROC)(const GLshort *);
PFNGLTEXCOORD1SVPROC __gleTexCoord1sv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2DPROC)(GLdouble , GLdouble );
PFNGLTEXCOORD2DPROC __gleTexCoord2d;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2DVPROC)(const GLdouble *);
PFNGLTEXCOORD2DVPROC __gleTexCoord2dv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FPROC)(GLfloat , GLfloat );
PFNGLTEXCOORD2FPROC __gleTexCoord2f;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FVPROC)(const GLfloat *);
PFNGLTEXCOORD2FVPROC __gleTexCoord2fv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2IPROC)(GLint , GLint );
PFNGLTEXCOORD2IPROC __gleTexCoord2i;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2IVPROC)(const GLint *);
PFNGLTEXCOORD2IVPROC __gleTexCoord2iv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2SPROC)(GLshort , GLshort );
PFNGLTEXCOORD2SPROC __gleTexCoord2s;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2SVPROC)(const GLshort *);
PFNGLTEXCOORD2SVPROC __gleTexCoord2sv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLTEXCOORD3DPROC __gleTexCoord3d;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3DVPROC)(const GLdouble *);
PFNGLTEXCOORD3DVPROC __gleTexCoord3dv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLTEXCOORD3FPROC __gleTexCoord3f;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3FVPROC)(const GLfloat *);
PFNGLTEXCOORD3FVPROC __gleTexCoord3fv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3IPROC)(GLint , GLint , GLint );
PFNGLTEXCOORD3IPROC __gleTexCoord3i;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3IVPROC)(const GLint *);
PFNGLTEXCOORD3IVPROC __gleTexCoord3iv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3SPROC)(GLshort , GLshort , GLshort );
PFNGLTEXCOORD3SPROC __gleTexCoord3s;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3SVPROC)(const GLshort *);
PFNGLTEXCOORD3SVPROC __gleTexCoord3sv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLTEXCOORD4DPROC __gleTexCoord4d;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4DVPROC)(const GLdouble *);
PFNGLTEXCOORD4DVPROC __gleTexCoord4dv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLTEXCOORD4FPROC __gleTexCoord4f;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FVPROC)(const GLfloat *);
PFNGLTEXCOORD4FVPROC __gleTexCoord4fv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4IPROC)(GLint , GLint , GLint , GLint );
PFNGLTEXCOORD4IPROC __gleTexCoord4i;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4IVPROC)(const GLint *);
PFNGLTEXCOORD4IVPROC __gleTexCoord4iv;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4SPROC)(GLshort , GLshort , GLshort , GLshort );
PFNGLTEXCOORD4SPROC __gleTexCoord4s;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4SVPROC)(const GLshort *);
PFNGLTEXCOORD4SVPROC __gleTexCoord4sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2DPROC)(GLdouble , GLdouble );
PFNGLVERTEX2DPROC __gleVertex2d;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2DVPROC)(const GLdouble *);
PFNGLVERTEX2DVPROC __gleVertex2dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2FPROC)(GLfloat , GLfloat );
PFNGLVERTEX2FPROC __gleVertex2f;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2FVPROC)(const GLfloat *);
PFNGLVERTEX2FVPROC __gleVertex2fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2IPROC)(GLint , GLint );
PFNGLVERTEX2IPROC __gleVertex2i;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2IVPROC)(const GLint *);
PFNGLVERTEX2IVPROC __gleVertex2iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2SPROC)(GLshort , GLshort );
PFNGLVERTEX2SPROC __gleVertex2s;
typedef void (GLE_FUNCPTR * PFNGLVERTEX2SVPROC)(const GLshort *);
PFNGLVERTEX2SVPROC __gleVertex2sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLVERTEX3DPROC __gleVertex3d;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3DVPROC)(const GLdouble *);
PFNGLVERTEX3DVPROC __gleVertex3dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLVERTEX3FPROC __gleVertex3f;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3FVPROC)(const GLfloat *);
PFNGLVERTEX3FVPROC __gleVertex3fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3IPROC)(GLint , GLint , GLint );
PFNGLVERTEX3IPROC __gleVertex3i;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3IVPROC)(const GLint *);
PFNGLVERTEX3IVPROC __gleVertex3iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3SPROC)(GLshort , GLshort , GLshort );
PFNGLVERTEX3SPROC __gleVertex3s;
typedef void (GLE_FUNCPTR * PFNGLVERTEX3SVPROC)(const GLshort *);
PFNGLVERTEX3SVPROC __gleVertex3sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLVERTEX4DPROC __gleVertex4d;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4DVPROC)(const GLdouble *);
PFNGLVERTEX4DVPROC __gleVertex4dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLVERTEX4FPROC __gleVertex4f;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4FVPROC)(const GLfloat *);
PFNGLVERTEX4FVPROC __gleVertex4fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4IPROC)(GLint , GLint , GLint , GLint );
PFNGLVERTEX4IPROC __gleVertex4i;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4IVPROC)(const GLint *);
PFNGLVERTEX4IVPROC __gleVertex4iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4SPROC)(GLshort , GLshort , GLshort , GLshort );
PFNGLVERTEX4SPROC __gleVertex4s;
typedef void (GLE_FUNCPTR * PFNGLVERTEX4SVPROC)(const GLshort *);
PFNGLVERTEX4SVPROC __gleVertex4sv;
typedef void (GLE_FUNCPTR * PFNGLCLIPPLANEPROC)(GLenum , const GLdouble *);
PFNGLCLIPPLANEPROC __gleClipPlane;
typedef void (GLE_FUNCPTR * PFNGLCOLORMATERIALPROC)(GLenum , GLenum );
PFNGLCOLORMATERIALPROC __gleColorMaterial;
typedef void (GLE_FUNCPTR * PFNGLFOGFPROC)(GLenum , GLfloat );
PFNGLFOGFPROC __gleFogf;
typedef void (GLE_FUNCPTR * PFNGLFOGFVPROC)(GLenum , const GLfloat *);
PFNGLFOGFVPROC __gleFogfv;
typedef void (GLE_FUNCPTR * PFNGLFOGIPROC)(GLenum , GLint );
PFNGLFOGIPROC __gleFogi;
typedef void (GLE_FUNCPTR * PFNGLFOGIVPROC)(GLenum , const GLint *);
PFNGLFOGIVPROC __gleFogiv;
typedef void (GLE_FUNCPTR * PFNGLLIGHTFPROC)(GLenum , GLenum , GLfloat );
PFNGLLIGHTFPROC __gleLightf;
typedef void (GLE_FUNCPTR * PFNGLLIGHTFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLLIGHTFVPROC __gleLightfv;
typedef void (GLE_FUNCPTR * PFNGLLIGHTIPROC)(GLenum , GLenum , GLint );
PFNGLLIGHTIPROC __gleLighti;
typedef void (GLE_FUNCPTR * PFNGLLIGHTIVPROC)(GLenum , GLenum , const GLint *);
PFNGLLIGHTIVPROC __gleLightiv;
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELFPROC)(GLenum , GLfloat );
PFNGLLIGHTMODELFPROC __gleLightModelf;
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELFVPROC)(GLenum , const GLfloat *);
PFNGLLIGHTMODELFVPROC __gleLightModelfv;
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELIPROC)(GLenum , GLint );
PFNGLLIGHTMODELIPROC __gleLightModeli;
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELIVPROC)(GLenum , const GLint *);
PFNGLLIGHTMODELIVPROC __gleLightModeliv;
typedef void (GLE_FUNCPTR * PFNGLLINESTIPPLEPROC)(GLint , GLushort );
PFNGLLINESTIPPLEPROC __gleLineStipple;
typedef void (GLE_FUNCPTR * PFNGLMATERIALFPROC)(GLenum , GLenum , GLfloat );
PFNGLMATERIALFPROC __gleMaterialf;
typedef void (GLE_FUNCPTR * PFNGLMATERIALFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLMATERIALFVPROC __gleMaterialfv;
typedef void (GLE_FUNCPTR * PFNGLMATERIALIPROC)(GLenum , GLenum , GLint );
PFNGLMATERIALIPROC __gleMateriali;
typedef void (GLE_FUNCPTR * PFNGLMATERIALIVPROC)(GLenum , GLenum , const GLint *);
PFNGLMATERIALIVPROC __gleMaterialiv;
typedef void (GLE_FUNCPTR * PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *);
PFNGLPOLYGONSTIPPLEPROC __glePolygonStipple;
typedef void (GLE_FUNCPTR * PFNGLSHADEMODELPROC)(GLenum );
PFNGLSHADEMODELPROC __gleShadeModel;
typedef void (GLE_FUNCPTR * PFNGLTEXENVFPROC)(GLenum , GLenum , GLfloat );
PFNGLTEXENVFPROC __gleTexEnvf;
typedef void (GLE_FUNCPTR * PFNGLTEXENVFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLTEXENVFVPROC __gleTexEnvfv;
typedef void (GLE_FUNCPTR * PFNGLTEXENVIPROC)(GLenum , GLenum , GLint );
PFNGLTEXENVIPROC __gleTexEnvi;
typedef void (GLE_FUNCPTR * PFNGLTEXENVIVPROC)(GLenum , GLenum , const GLint *);
PFNGLTEXENVIVPROC __gleTexEnviv;
typedef void (GLE_FUNCPTR * PFNGLTEXGENDPROC)(GLenum , GLenum , GLdouble );
PFNGLTEXGENDPROC __gleTexGend;
typedef void (GLE_FUNCPTR * PFNGLTEXGENDVPROC)(GLenum , GLenum , const GLdouble *);
PFNGLTEXGENDVPROC __gleTexGendv;
typedef void (GLE_FUNCPTR * PFNGLTEXGENFPROC)(GLenum , GLenum , GLfloat );
PFNGLTEXGENFPROC __gleTexGenf;
typedef void (GLE_FUNCPTR * PFNGLTEXGENFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLTEXGENFVPROC __gleTexGenfv;
typedef void (GLE_FUNCPTR * PFNGLTEXGENIPROC)(GLenum , GLenum , GLint );
PFNGLTEXGENIPROC __gleTexGeni;
typedef void (GLE_FUNCPTR * PFNGLTEXGENIVPROC)(GLenum , GLenum , const GLint *);
PFNGLTEXGENIVPROC __gleTexGeniv;
typedef void (GLE_FUNCPTR * PFNGLFEEDBACKBUFFERPROC)(GLsizei , GLenum , GLfloat *);
PFNGLFEEDBACKBUFFERPROC __gleFeedbackBuffer;
typedef void (GLE_FUNCPTR * PFNGLSELECTBUFFERPROC)(GLsizei , GLuint *);
PFNGLSELECTBUFFERPROC __gleSelectBuffer;
typedef GLint (GLE_FUNCPTR * PFNGLRENDERMODEPROC)(GLenum );
PFNGLRENDERMODEPROC __gleRenderMode;
typedef void (GLE_FUNCPTR * PFNGLINITNAMESPROC)();
PFNGLINITNAMESPROC __gleInitNames;
typedef void (GLE_FUNCPTR * PFNGLLOADNAMEPROC)(GLuint );
PFNGLLOADNAMEPROC __gleLoadName;
typedef void (GLE_FUNCPTR * PFNGLPASSTHROUGHPROC)(GLfloat );
PFNGLPASSTHROUGHPROC __glePassThrough;
typedef void (GLE_FUNCPTR * PFNGLPOPNAMEPROC)();
PFNGLPOPNAMEPROC __glePopName;
typedef void (GLE_FUNCPTR * PFNGLPUSHNAMEPROC)(GLuint );
PFNGLPUSHNAMEPROC __glePushName;
typedef void (GLE_FUNCPTR * PFNGLCLEARACCUMPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLCLEARACCUMPROC __gleClearAccum;
typedef void (GLE_FUNCPTR * PFNGLCLEARINDEXPROC)(GLfloat );
PFNGLCLEARINDEXPROC __gleClearIndex;
typedef void (GLE_FUNCPTR * PFNGLINDEXMASKPROC)(GLuint );
PFNGLINDEXMASKPROC __gleIndexMask;
typedef void (GLE_FUNCPTR * PFNGLACCUMPROC)(GLenum , GLfloat );
PFNGLACCUMPROC __gleAccum;
typedef void (GLE_FUNCPTR * PFNGLPOPATTRIBPROC)();
PFNGLPOPATTRIBPROC __glePopAttrib;
typedef void (GLE_FUNCPTR * PFNGLPUSHATTRIBPROC)(GLbitfield );
PFNGLPUSHATTRIBPROC __glePushAttrib;
typedef void (GLE_FUNCPTR * PFNGLMAP1DPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
PFNGLMAP1DPROC __gleMap1d;
typedef void (GLE_FUNCPTR * PFNGLMAP1FPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
PFNGLMAP1FPROC __gleMap1f;
typedef void (GLE_FUNCPTR * PFNGLMAP2DPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
PFNGLMAP2DPROC __gleMap2d;
typedef void (GLE_FUNCPTR * PFNGLMAP2FPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
PFNGLMAP2FPROC __gleMap2f;
typedef void (GLE_FUNCPTR * PFNGLMAPGRID1DPROC)(GLint , GLdouble , GLdouble );
PFNGLMAPGRID1DPROC __gleMapGrid1d;
typedef void (GLE_FUNCPTR * PFNGLMAPGRID1FPROC)(GLint , GLfloat , GLfloat );
PFNGLMAPGRID1FPROC __gleMapGrid1f;
typedef void (GLE_FUNCPTR * PFNGLMAPGRID2DPROC)(GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble );
PFNGLMAPGRID2DPROC __gleMapGrid2d;
typedef void (GLE_FUNCPTR * PFNGLMAPGRID2FPROC)(GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat );
PFNGLMAPGRID2FPROC __gleMapGrid2f;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1DPROC)(GLdouble );
PFNGLEVALCOORD1DPROC __gleEvalCoord1d;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1DVPROC)(const GLdouble *);
PFNGLEVALCOORD1DVPROC __gleEvalCoord1dv;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1FPROC)(GLfloat );
PFNGLEVALCOORD1FPROC __gleEvalCoord1f;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1FVPROC)(const GLfloat *);
PFNGLEVALCOORD1FVPROC __gleEvalCoord1fv;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2DPROC)(GLdouble , GLdouble );
PFNGLEVALCOORD2DPROC __gleEvalCoord2d;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2DVPROC)(const GLdouble *);
PFNGLEVALCOORD2DVPROC __gleEvalCoord2dv;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2FPROC)(GLfloat , GLfloat );
PFNGLEVALCOORD2FPROC __gleEvalCoord2f;
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2FVPROC)(const GLfloat *);
PFNGLEVALCOORD2FVPROC __gleEvalCoord2fv;
typedef void (GLE_FUNCPTR * PFNGLEVALMESH1PROC)(GLenum , GLint , GLint );
PFNGLEVALMESH1PROC __gleEvalMesh1;
typedef void (GLE_FUNCPTR * PFNGLEVALPOINT1PROC)(GLint );
PFNGLEVALPOINT1PROC __gleEvalPoint1;
typedef void (GLE_FUNCPTR * PFNGLEVALMESH2PROC)(GLenum , GLint , GLint , GLint , GLint );
PFNGLEVALMESH2PROC __gleEvalMesh2;
typedef void (GLE_FUNCPTR * PFNGLEVALPOINT2PROC)(GLint , GLint );
PFNGLEVALPOINT2PROC __gleEvalPoint2;
typedef void (GLE_FUNCPTR * PFNGLALPHAFUNCPROC)(GLenum , GLfloat );
PFNGLALPHAFUNCPROC __gleAlphaFunc;
typedef void (GLE_FUNCPTR * PFNGLPIXELZOOMPROC)(GLfloat , GLfloat );
PFNGLPIXELZOOMPROC __glePixelZoom;
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFERFPROC)(GLenum , GLfloat );
PFNGLPIXELTRANSFERFPROC __glePixelTransferf;
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFERIPROC)(GLenum , GLint );
PFNGLPIXELTRANSFERIPROC __glePixelTransferi;
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPFVPROC)(GLenum , GLsizei , const GLfloat *);
PFNGLPIXELMAPFVPROC __glePixelMapfv;
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPUIVPROC)(GLenum , GLsizei , const GLuint *);
PFNGLPIXELMAPUIVPROC __glePixelMapuiv;
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPUSVPROC)(GLenum , GLsizei , const GLushort *);
PFNGLPIXELMAPUSVPROC __glePixelMapusv;
typedef void (GLE_FUNCPTR * PFNGLCOPYPIXELSPROC)(GLint , GLint , GLsizei , GLsizei , GLenum );
PFNGLCOPYPIXELSPROC __gleCopyPixels;
typedef void (GLE_FUNCPTR * PFNGLDRAWPIXELSPROC)(GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLDRAWPIXELSPROC __gleDrawPixels;
typedef void (GLE_FUNCPTR * PFNGLGETCLIPPLANEPROC)(GLenum , GLdouble *);
PFNGLGETCLIPPLANEPROC __gleGetClipPlane;
typedef void (GLE_FUNCPTR * PFNGLGETLIGHTFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETLIGHTFVPROC __gleGetLightfv;
typedef void (GLE_FUNCPTR * PFNGLGETLIGHTIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETLIGHTIVPROC __gleGetLightiv;
typedef void (GLE_FUNCPTR * PFNGLGETMAPDVPROC)(GLenum , GLenum , GLdouble *);
PFNGLGETMAPDVPROC __gleGetMapdv;
typedef void (GLE_FUNCPTR * PFNGLGETMAPFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETMAPFVPROC __gleGetMapfv;
typedef void (GLE_FUNCPTR * PFNGLGETMAPIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETMAPIVPROC __gleGetMapiv;
typedef void (GLE_FUNCPTR * PFNGLGETMATERIALFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETMATERIALFVPROC __gleGetMaterialfv;
typedef void (GLE_FUNCPTR * PFNGLGETMATERIALIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETMATERIALIVPROC __gleGetMaterialiv;
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPFVPROC)(GLenum , GLfloat *);
PFNGLGETPIXELMAPFVPROC __gleGetPixelMapfv;
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPUIVPROC)(GLenum , GLuint *);
PFNGLGETPIXELMAPUIVPROC __gleGetPixelMapuiv;
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPUSVPROC)(GLenum , GLushort *);
PFNGLGETPIXELMAPUSVPROC __gleGetPixelMapusv;
typedef void (GLE_FUNCPTR * PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *);
PFNGLGETPOLYGONSTIPPLEPROC __gleGetPolygonStipple;
typedef void (GLE_FUNCPTR * PFNGLGETTEXENVFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETTEXENVFVPROC __gleGetTexEnvfv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXENVIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETTEXENVIVPROC __gleGetTexEnviv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENDVPROC)(GLenum , GLenum , GLdouble *);
PFNGLGETTEXGENDVPROC __gleGetTexGendv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETTEXGENFVPROC __gleGetTexGenfv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETTEXGENIVPROC __gleGetTexGeniv;
typedef GLboolean (GLE_FUNCPTR * PFNGLISLISTPROC)(GLuint );
PFNGLISLISTPROC __gleIsList;
typedef void (GLE_FUNCPTR * PFNGLFRUSTUMPROC)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLFRUSTUMPROC __gleFrustum;
typedef void (GLE_FUNCPTR * PFNGLLOADIDENTITYPROC)();
PFNGLLOADIDENTITYPROC __gleLoadIdentity;
typedef void (GLE_FUNCPTR * PFNGLLOADMATRIXFPROC)(const GLfloat *);
PFNGLLOADMATRIXFPROC __gleLoadMatrixf;
typedef void (GLE_FUNCPTR * PFNGLLOADMATRIXDPROC)(const GLdouble *);
PFNGLLOADMATRIXDPROC __gleLoadMatrixd;
typedef void (GLE_FUNCPTR * PFNGLMATRIXMODEPROC)(GLenum );
PFNGLMATRIXMODEPROC __gleMatrixMode;
typedef void (GLE_FUNCPTR * PFNGLMULTMATRIXFPROC)(const GLfloat *);
PFNGLMULTMATRIXFPROC __gleMultMatrixf;
typedef void (GLE_FUNCPTR * PFNGLMULTMATRIXDPROC)(const GLdouble *);
PFNGLMULTMATRIXDPROC __gleMultMatrixd;
typedef void (GLE_FUNCPTR * PFNGLORTHOPROC)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLORTHOPROC __gleOrtho;
typedef void (GLE_FUNCPTR * PFNGLPOPMATRIXPROC)();
PFNGLPOPMATRIXPROC __glePopMatrix;
typedef void (GLE_FUNCPTR * PFNGLPUSHMATRIXPROC)();
PFNGLPUSHMATRIXPROC __glePushMatrix;
typedef void (GLE_FUNCPTR * PFNGLROTATEDPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLROTATEDPROC __gleRotated;
typedef void (GLE_FUNCPTR * PFNGLROTATEFPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLROTATEFPROC __gleRotatef;
typedef void (GLE_FUNCPTR * PFNGLSCALEDPROC)(GLdouble , GLdouble , GLdouble );
PFNGLSCALEDPROC __gleScaled;
typedef void (GLE_FUNCPTR * PFNGLSCALEFPROC)(GLfloat , GLfloat , GLfloat );
PFNGLSCALEFPROC __gleScalef;
typedef void (GLE_FUNCPTR * PFNGLTRANSLATEDPROC)(GLdouble , GLdouble , GLdouble );
PFNGLTRANSLATEDPROC __gleTranslated;
typedef void (GLE_FUNCPTR * PFNGLTRANSLATEFPROC)(GLfloat , GLfloat , GLfloat );
PFNGLTRANSLATEFPROC __gleTranslatef;
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSPROC)(GLenum , GLint , GLsizei );
PFNGLDRAWARRAYSPROC __gleDrawArrays;
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSPROC)(GLenum , GLsizei , GLenum , const GLvoid *);
PFNGLDRAWELEMENTSPROC __gleDrawElements;
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERVPROC)(GLenum , GLvoid* *);
PFNGLGETPOINTERVPROC __gleGetPointerv;
typedef void (GLE_FUNCPTR * PFNGLPOLYGONOFFSETPROC)(GLfloat , GLfloat );
PFNGLPOLYGONOFFSETPROC __glePolygonOffset;
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE1DPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
PFNGLCOPYTEXIMAGE1DPROC __gleCopyTexImage1D;
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE2DPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
PFNGLCOPYTEXIMAGE2DPROC __gleCopyTexImage2D;
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei );
PFNGLCOPYTEXSUBIMAGE1DPROC __gleCopyTexSubImage1D;
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
PFNGLCOPYTEXSUBIMAGE2DPROC __gleCopyTexSubImage2D;
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLTEXSUBIMAGE1DPROC __gleTexSubImage1D;
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLTEXSUBIMAGE2DPROC __gleTexSubImage2D;
typedef void (GLE_FUNCPTR * PFNGLBINDTEXTUREPROC)(GLenum , GLuint );
PFNGLBINDTEXTUREPROC __gleBindTexture;
typedef void (GLE_FUNCPTR * PFNGLDELETETEXTURESPROC)(GLsizei , const GLuint *);
PFNGLDELETETEXTURESPROC __gleDeleteTextures;
typedef void (GLE_FUNCPTR * PFNGLGENTEXTURESPROC)(GLsizei , GLuint *);
PFNGLGENTEXTURESPROC __gleGenTextures;
typedef GLboolean (GLE_FUNCPTR * PFNGLISTEXTUREPROC)(GLuint );
PFNGLISTEXTUREPROC __gleIsTexture;
typedef void (GLE_FUNCPTR * PFNGLARRAYELEMENTPROC)(GLint );
PFNGLARRAYELEMENTPROC __gleArrayElement;
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
PFNGLCOLORPOINTERPROC __gleColorPointer;
typedef void (GLE_FUNCPTR * PFNGLDISABLECLIENTSTATEPROC)(GLenum );
PFNGLDISABLECLIENTSTATEPROC __gleDisableClientState;
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTERPROC)(GLsizei , const GLvoid *);
PFNGLEDGEFLAGPOINTERPROC __gleEdgeFlagPointer;
typedef void (GLE_FUNCPTR * PFNGLENABLECLIENTSTATEPROC)(GLenum );
PFNGLENABLECLIENTSTATEPROC __gleEnableClientState;
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
PFNGLINDEXPOINTERPROC __gleIndexPointer;
typedef void (GLE_FUNCPTR * PFNGLINTERLEAVEDARRAYSPROC)(GLenum , GLsizei , const GLvoid *);
PFNGLINTERLEAVEDARRAYSPROC __gleInterleavedArrays;
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
PFNGLNORMALPOINTERPROC __gleNormalPointer;
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
PFNGLTEXCOORDPOINTERPROC __gleTexCoordPointer;
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
PFNGLVERTEXPOINTERPROC __gleVertexPointer;
typedef GLboolean (GLE_FUNCPTR * PFNGLARETEXTURESRESIDENTPROC)(GLsizei , const GLuint *, GLboolean *);
PFNGLARETEXTURESRESIDENTPROC __gleAreTexturesResident;
typedef void (GLE_FUNCPTR * PFNGLPRIORITIZETEXTURESPROC)(GLsizei , const GLuint *, const GLfloat *);
PFNGLPRIORITIZETEXTURESPROC __glePrioritizeTextures;
typedef void (GLE_FUNCPTR * PFNGLINDEXUBPROC)(GLubyte );
PFNGLINDEXUBPROC __gleIndexub;
typedef void (GLE_FUNCPTR * PFNGLINDEXUBVPROC)(const GLubyte *);
PFNGLINDEXUBVPROC __gleIndexubv;
typedef void (GLE_FUNCPTR * PFNGLPOPCLIENTATTRIBPROC)();
PFNGLPOPCLIENTATTRIBPROC __glePopClientAttrib;
typedef void (GLE_FUNCPTR * PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield );
PFNGLPUSHCLIENTATTRIBPROC __glePushClientAttrib;
typedef void (GLE_FUNCPTR * PFNGLBLENDCOLORPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLBLENDCOLORPROC __gleBlendColor;
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONPROC)(GLenum );
PFNGLBLENDEQUATIONPROC __gleBlendEquation;
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *);
PFNGLDRAWRANGEELEMENTSPROC __gleDrawRangeElements;
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DPROC)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
PFNGLTEXIMAGE3DPROC __gleTexImage3D;
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLTEXSUBIMAGE3DPROC __gleTexSubImage3D;
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
PFNGLCOPYTEXSUBIMAGE3DPROC __gleCopyTexSubImage3D;
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLCOLORTABLEPROC __gleColorTable;
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLCOLORTABLEPARAMETERFVPROC __gleColorTableParameterfv;
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
PFNGLCOLORTABLEPARAMETERIVPROC __gleColorTableParameteriv;
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORTABLEPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
PFNGLCOPYCOLORTABLEPROC __gleCopyColorTable;
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPROC)(GLenum , GLenum , GLenum , GLvoid *);
PFNGLGETCOLORTABLEPROC __gleGetColorTable;
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETCOLORTABLEPARAMETERFVPROC __gleGetColorTableParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETCOLORTABLEPARAMETERIVPROC __gleGetColorTableParameteriv;
typedef void (GLE_FUNCPTR * PFNGLCOLORSUBTABLEPROC)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLCOLORSUBTABLEPROC __gleColorSubTable;
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORSUBTABLEPROC)(GLenum , GLsizei , GLint , GLint , GLsizei );
PFNGLCOPYCOLORSUBTABLEPROC __gleCopyColorSubTable;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLCONVOLUTIONFILTER1DPROC __gleConvolutionFilter1D;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
PFNGLCONVOLUTIONFILTER2DPROC __gleConvolutionFilter2D;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum , GLenum , GLfloat );
PFNGLCONVOLUTIONPARAMETERFPROC __gleConvolutionParameterf;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
PFNGLCONVOLUTIONPARAMETERFVPROC __gleConvolutionParameterfv;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum , GLenum , GLint );
PFNGLCONVOLUTIONPARAMETERIPROC __gleConvolutionParameteri;
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
PFNGLCONVOLUTIONPARAMETERIVPROC __gleConvolutionParameteriv;
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
PFNGLCOPYCONVOLUTIONFILTER1DPROC __gleCopyConvolutionFilter1D;
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
PFNGLCOPYCONVOLUTIONFILTER2DPROC __gleCopyConvolutionFilter2D;
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *);
PFNGLGETCONVOLUTIONFILTERPROC __gleGetConvolutionFilter;
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETCONVOLUTIONPARAMETERFVPROC __gleGetConvolutionParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETCONVOLUTIONPARAMETERIVPROC __gleGetConvolutionParameteriv;
typedef void (GLE_FUNCPTR * PFNGLGETSEPARABLEFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
PFNGLGETSEPARABLEFILTERPROC __gleGetSeparableFilter;
typedef void (GLE_FUNCPTR * PFNGLSEPARABLEFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);
PFNGLSEPARABLEFILTER2DPROC __gleSeparableFilter2D;
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
PFNGLGETHISTOGRAMPROC __gleGetHistogram;
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETHISTOGRAMPARAMETERFVPROC __gleGetHistogramParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETHISTOGRAMPARAMETERIVPROC __gleGetHistogramParameteriv;
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
PFNGLGETMINMAXPROC __gleGetMinmax;
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
PFNGLGETMINMAXPARAMETERFVPROC __gleGetMinmaxParameterfv;
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETMINMAXPARAMETERIVPROC __gleGetMinmaxParameteriv;
typedef void (GLE_FUNCPTR * PFNGLHISTOGRAMPROC)(GLenum , GLsizei , GLenum , GLboolean );
PFNGLHISTOGRAMPROC __gleHistogram;
typedef void (GLE_FUNCPTR * PFNGLMINMAXPROC)(GLenum , GLenum , GLboolean );
PFNGLMINMAXPROC __gleMinmax;
typedef void (GLE_FUNCPTR * PFNGLRESETHISTOGRAMPROC)(GLenum );
PFNGLRESETHISTOGRAMPROC __gleResetHistogram;
typedef void (GLE_FUNCPTR * PFNGLRESETMINMAXPROC)(GLenum );
PFNGLRESETMINMAXPROC __gleResetMinmax;
typedef void (GLE_FUNCPTR * PFNGLACTIVETEXTUREPROC)(GLenum );
PFNGLACTIVETEXTUREPROC __gleActiveTexture;
typedef void (GLE_FUNCPTR * PFNGLSAMPLECOVERAGEPROC)(GLfloat , GLboolean );
PFNGLSAMPLECOVERAGEPROC __gleSampleCoverage;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXIMAGE3DPROC __gleCompressedTexImage3D;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXIMAGE2DPROC __gleCompressedTexImage2D;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXIMAGE1DPROC __gleCompressedTexImage1D;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC __gleCompressedTexSubImage3D;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC __gleCompressedTexSubImage2D;
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC __gleCompressedTexSubImage1D;
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum , GLint , GLvoid *);
PFNGLGETCOMPRESSEDTEXIMAGEPROC __gleGetCompressedTexImage;
typedef void (GLE_FUNCPTR * PFNGLCLIENTACTIVETEXTUREPROC)(GLenum );
PFNGLCLIENTACTIVETEXTUREPROC __gleClientActiveTexture;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DPROC)(GLenum , GLdouble );
PFNGLMULTITEXCOORD1DPROC __gleMultiTexCoord1d;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DVPROC)(GLenum , const GLdouble *);
PFNGLMULTITEXCOORD1DVPROC __gleMultiTexCoord1dv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FPROC)(GLenum , GLfloat );
PFNGLMULTITEXCOORD1FPROC __gleMultiTexCoord1f;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FVPROC)(GLenum , const GLfloat *);
PFNGLMULTITEXCOORD1FVPROC __gleMultiTexCoord1fv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IPROC)(GLenum , GLint );
PFNGLMULTITEXCOORD1IPROC __gleMultiTexCoord1i;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IVPROC)(GLenum , const GLint *);
PFNGLMULTITEXCOORD1IVPROC __gleMultiTexCoord1iv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SPROC)(GLenum , GLshort );
PFNGLMULTITEXCOORD1SPROC __gleMultiTexCoord1s;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SVPROC)(GLenum , const GLshort *);
PFNGLMULTITEXCOORD1SVPROC __gleMultiTexCoord1sv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DPROC)(GLenum , GLdouble , GLdouble );
PFNGLMULTITEXCOORD2DPROC __gleMultiTexCoord2d;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DVPROC)(GLenum , const GLdouble *);
PFNGLMULTITEXCOORD2DVPROC __gleMultiTexCoord2dv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FPROC)(GLenum , GLfloat , GLfloat );
PFNGLMULTITEXCOORD2FPROC __gleMultiTexCoord2f;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FVPROC)(GLenum , const GLfloat *);
PFNGLMULTITEXCOORD2FVPROC __gleMultiTexCoord2fv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IPROC)(GLenum , GLint , GLint );
PFNGLMULTITEXCOORD2IPROC __gleMultiTexCoord2i;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IVPROC)(GLenum , const GLint *);
PFNGLMULTITEXCOORD2IVPROC __gleMultiTexCoord2iv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SPROC)(GLenum , GLshort , GLshort );
PFNGLMULTITEXCOORD2SPROC __gleMultiTexCoord2s;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SVPROC)(GLenum , const GLshort *);
PFNGLMULTITEXCOORD2SVPROC __gleMultiTexCoord2sv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DPROC)(GLenum , GLdouble , GLdouble , GLdouble );
PFNGLMULTITEXCOORD3DPROC __gleMultiTexCoord3d;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DVPROC)(GLenum , const GLdouble *);
PFNGLMULTITEXCOORD3DVPROC __gleMultiTexCoord3dv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FPROC)(GLenum , GLfloat , GLfloat , GLfloat );
PFNGLMULTITEXCOORD3FPROC __gleMultiTexCoord3f;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FVPROC)(GLenum , const GLfloat *);
PFNGLMULTITEXCOORD3FVPROC __gleMultiTexCoord3fv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IPROC)(GLenum , GLint , GLint , GLint );
PFNGLMULTITEXCOORD3IPROC __gleMultiTexCoord3i;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IVPROC)(GLenum , const GLint *);
PFNGLMULTITEXCOORD3IVPROC __gleMultiTexCoord3iv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SPROC)(GLenum , GLshort , GLshort , GLshort );
PFNGLMULTITEXCOORD3SPROC __gleMultiTexCoord3s;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SVPROC)(GLenum , const GLshort *);
PFNGLMULTITEXCOORD3SVPROC __gleMultiTexCoord3sv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLMULTITEXCOORD4DPROC __gleMultiTexCoord4d;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DVPROC)(GLenum , const GLdouble *);
PFNGLMULTITEXCOORD4DVPROC __gleMultiTexCoord4dv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLMULTITEXCOORD4FPROC __gleMultiTexCoord4f;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FVPROC)(GLenum , const GLfloat *);
PFNGLMULTITEXCOORD4FVPROC __gleMultiTexCoord4fv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IPROC)(GLenum , GLint , GLint , GLint , GLint );
PFNGLMULTITEXCOORD4IPROC __gleMultiTexCoord4i;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IVPROC)(GLenum , const GLint *);
PFNGLMULTITEXCOORD4IVPROC __gleMultiTexCoord4iv;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SPROC)(GLenum , GLshort , GLshort , GLshort , GLshort );
PFNGLMULTITEXCOORD4SPROC __gleMultiTexCoord4s;
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SVPROC)(GLenum , const GLshort *);
PFNGLMULTITEXCOORD4SVPROC __gleMultiTexCoord4sv;
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *);
PFNGLLOADTRANSPOSEMATRIXFPROC __gleLoadTransposeMatrixf;
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *);
PFNGLLOADTRANSPOSEMATRIXDPROC __gleLoadTransposeMatrixd;
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *);
PFNGLMULTTRANSPOSEMATRIXFPROC __gleMultTransposeMatrixf;
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *);
PFNGLMULTTRANSPOSEMATRIXDPROC __gleMultTransposeMatrixd;
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEPROC)(GLenum , GLenum , GLenum , GLenum );
PFNGLBLENDFUNCSEPARATEPROC __gleBlendFuncSeparate;
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
PFNGLMULTIDRAWARRAYSPROC __gleMultiDrawArrays;
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei );
PFNGLMULTIDRAWELEMENTSPROC __gleMultiDrawElements;
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFPROC)(GLenum , GLfloat );
PFNGLPOINTPARAMETERFPROC __glePointParameterf;
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVPROC)(GLenum , const GLfloat *);
PFNGLPOINTPARAMETERFVPROC __glePointParameterfv;
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIPROC)(GLenum , GLint );
PFNGLPOINTPARAMETERIPROC __glePointParameteri;
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIVPROC)(GLenum , const GLint *);
PFNGLPOINTPARAMETERIVPROC __glePointParameteriv;
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFPROC)(GLfloat );
PFNGLFOGCOORDFPROC __gleFogCoordf;
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFVPROC)(const GLfloat *);
PFNGLFOGCOORDFVPROC __gleFogCoordfv;
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDPROC)(GLdouble );
PFNGLFOGCOORDDPROC __gleFogCoordd;
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDVPROC)(const GLdouble *);
PFNGLFOGCOORDDVPROC __gleFogCoorddv;
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
PFNGLFOGCOORDPOINTERPROC __gleFogCoordPointer;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BPROC)(GLbyte , GLbyte , GLbyte );
PFNGLSECONDARYCOLOR3BPROC __gleSecondaryColor3b;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *);
PFNGLSECONDARYCOLOR3BVPROC __gleSecondaryColor3bv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLSECONDARYCOLOR3DPROC __gleSecondaryColor3d;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *);
PFNGLSECONDARYCOLOR3DVPROC __gleSecondaryColor3dv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLSECONDARYCOLOR3FPROC __gleSecondaryColor3f;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *);
PFNGLSECONDARYCOLOR3FVPROC __gleSecondaryColor3fv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IPROC)(GLint , GLint , GLint );
PFNGLSECONDARYCOLOR3IPROC __gleSecondaryColor3i;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IVPROC)(const GLint *);
PFNGLSECONDARYCOLOR3IVPROC __gleSecondaryColor3iv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SPROC)(GLshort , GLshort , GLshort );
PFNGLSECONDARYCOLOR3SPROC __gleSecondaryColor3s;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *);
PFNGLSECONDARYCOLOR3SVPROC __gleSecondaryColor3sv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBPROC)(GLubyte , GLubyte , GLubyte );
PFNGLSECONDARYCOLOR3UBPROC __gleSecondaryColor3ub;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *);
PFNGLSECONDARYCOLOR3UBVPROC __gleSecondaryColor3ubv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIPROC)(GLuint , GLuint , GLuint );
PFNGLSECONDARYCOLOR3UIPROC __gleSecondaryColor3ui;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *);
PFNGLSECONDARYCOLOR3UIVPROC __gleSecondaryColor3uiv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USPROC)(GLushort , GLushort , GLushort );
PFNGLSECONDARYCOLOR3USPROC __gleSecondaryColor3us;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *);
PFNGLSECONDARYCOLOR3USVPROC __gleSecondaryColor3usv;
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
PFNGLSECONDARYCOLORPOINTERPROC __gleSecondaryColorPointer;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DPROC)(GLdouble , GLdouble );
PFNGLWINDOWPOS2DPROC __gleWindowPos2d;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DVPROC)(const GLdouble *);
PFNGLWINDOWPOS2DVPROC __gleWindowPos2dv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FPROC)(GLfloat , GLfloat );
PFNGLWINDOWPOS2FPROC __gleWindowPos2f;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FVPROC)(const GLfloat *);
PFNGLWINDOWPOS2FVPROC __gleWindowPos2fv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IPROC)(GLint , GLint );
PFNGLWINDOWPOS2IPROC __gleWindowPos2i;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IVPROC)(const GLint *);
PFNGLWINDOWPOS2IVPROC __gleWindowPos2iv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SPROC)(GLshort , GLshort );
PFNGLWINDOWPOS2SPROC __gleWindowPos2s;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SVPROC)(const GLshort *);
PFNGLWINDOWPOS2SVPROC __gleWindowPos2sv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DPROC)(GLdouble , GLdouble , GLdouble );
PFNGLWINDOWPOS3DPROC __gleWindowPos3d;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DVPROC)(const GLdouble *);
PFNGLWINDOWPOS3DVPROC __gleWindowPos3dv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FPROC)(GLfloat , GLfloat , GLfloat );
PFNGLWINDOWPOS3FPROC __gleWindowPos3f;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FVPROC)(const GLfloat *);
PFNGLWINDOWPOS3FVPROC __gleWindowPos3fv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IPROC)(GLint , GLint , GLint );
PFNGLWINDOWPOS3IPROC __gleWindowPos3i;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IVPROC)(const GLint *);
PFNGLWINDOWPOS3IVPROC __gleWindowPos3iv;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SPROC)(GLshort , GLshort , GLshort );
PFNGLWINDOWPOS3SPROC __gleWindowPos3s;
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SVPROC)(const GLshort *);
PFNGLWINDOWPOS3SVPROC __gleWindowPos3sv;
typedef void (GLE_FUNCPTR * PFNGLGENQUERIESPROC)(GLsizei , GLuint *);
PFNGLGENQUERIESPROC __gleGenQueries;
typedef void (GLE_FUNCPTR * PFNGLDELETEQUERIESPROC)(GLsizei , const GLuint *);
PFNGLDELETEQUERIESPROC __gleDeleteQueries;
typedef GLboolean (GLE_FUNCPTR * PFNGLISQUERYPROC)(GLuint );
PFNGLISQUERYPROC __gleIsQuery;
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYPROC)(GLenum , GLuint );
PFNGLBEGINQUERYPROC __gleBeginQuery;
typedef void (GLE_FUNCPTR * PFNGLENDQUERYPROC)(GLenum );
PFNGLENDQUERYPROC __gleEndQuery;
typedef void (GLE_FUNCPTR * PFNGLGETQUERYIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETQUERYIVPROC __gleGetQueryiv;
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTIVPROC)(GLuint , GLenum , GLint *);
PFNGLGETQUERYOBJECTIVPROC __gleGetQueryObjectiv;
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUIVPROC)(GLuint , GLenum , GLuint *);
PFNGLGETQUERYOBJECTUIVPROC __gleGetQueryObjectuiv;
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERPROC)(GLenum , GLuint );
PFNGLBINDBUFFERPROC __gleBindBuffer;
typedef void (GLE_FUNCPTR * PFNGLDELETEBUFFERSPROC)(GLsizei , const GLuint *);
PFNGLDELETEBUFFERSPROC __gleDeleteBuffers;
typedef void (GLE_FUNCPTR * PFNGLGENBUFFERSPROC)(GLsizei , GLuint *);
PFNGLGENBUFFERSPROC __gleGenBuffers;
typedef GLboolean (GLE_FUNCPTR * PFNGLISBUFFERPROC)(GLuint );
PFNGLISBUFFERPROC __gleIsBuffer;
typedef void (GLE_FUNCPTR * PFNGLBUFFERDATAPROC)(GLenum , GLsizeiptr , const GLvoid *, GLenum );
PFNGLBUFFERDATAPROC __gleBufferData;
typedef void (GLE_FUNCPTR * PFNGLBUFFERSUBDATAPROC)(GLenum , GLintptr , GLsizeiptr , const GLvoid *);
PFNGLBUFFERSUBDATAPROC __gleBufferSubData;
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERSUBDATAPROC)(GLenum , GLintptr , GLsizeiptr , GLvoid *);
PFNGLGETBUFFERSUBDATAPROC __gleGetBufferSubData;
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPBUFFERPROC)(GLenum , GLenum );
PFNGLMAPBUFFERPROC __gleMapBuffer;
typedef GLboolean (GLE_FUNCPTR * PFNGLUNMAPBUFFERPROC)(GLenum );
PFNGLUNMAPBUFFERPROC __gleUnmapBuffer;
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPARAMETERIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETBUFFERPARAMETERIVPROC __gleGetBufferParameteriv;
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPOINTERVPROC)(GLenum , GLenum , GLvoid* *);
PFNGLGETBUFFERPOINTERVPROC __gleGetBufferPointerv;
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum , GLenum );
PFNGLBLENDEQUATIONSEPARATEPROC __gleBlendEquationSeparate;
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSPROC)(GLsizei , const GLenum *);
PFNGLDRAWBUFFERSPROC __gleDrawBuffers;
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPSEPARATEPROC)(GLenum , GLenum , GLenum , GLenum );
PFNGLSTENCILOPSEPARATEPROC __gleStencilOpSeparate;
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCSEPARATEPROC)(GLenum , GLenum , GLint , GLuint );
PFNGLSTENCILFUNCSEPARATEPROC __gleStencilFuncSeparate;
typedef void (GLE_FUNCPTR * PFNGLSTENCILMASKSEPARATEPROC)(GLenum , GLuint );
PFNGLSTENCILMASKSEPARATEPROC __gleStencilMaskSeparate;
typedef void (GLE_FUNCPTR * PFNGLATTACHSHADERPROC)(GLuint , GLuint );
PFNGLATTACHSHADERPROC __gleAttachShader;
typedef void (GLE_FUNCPTR * PFNGLBINDATTRIBLOCATIONPROC)(GLuint , GLuint , const GLchar *);
PFNGLBINDATTRIBLOCATIONPROC __gleBindAttribLocation;
typedef void (GLE_FUNCPTR * PFNGLCOMPILESHADERPROC)(GLuint );
PFNGLCOMPILESHADERPROC __gleCompileShader;
typedef GLuint (GLE_FUNCPTR * PFNGLCREATEPROGRAMPROC)();
PFNGLCREATEPROGRAMPROC __gleCreateProgram;
typedef GLuint (GLE_FUNCPTR * PFNGLCREATESHADERPROC)(GLenum );
PFNGLCREATESHADERPROC __gleCreateShader;
typedef void (GLE_FUNCPTR * PFNGLDELETEPROGRAMPROC)(GLuint );
PFNGLDELETEPROGRAMPROC __gleDeleteProgram;
typedef void (GLE_FUNCPTR * PFNGLDELETESHADERPROC)(GLuint );
PFNGLDELETESHADERPROC __gleDeleteShader;
typedef void (GLE_FUNCPTR * PFNGLDETACHSHADERPROC)(GLuint , GLuint );
PFNGLDETACHSHADERPROC __gleDetachShader;
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint );
PFNGLDISABLEVERTEXATTRIBARRAYPROC __gleDisableVertexAttribArray;
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint );
PFNGLENABLEVERTEXATTRIBARRAYPROC __gleEnableVertexAttribArray;
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATTRIBPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
PFNGLGETACTIVEATTRIBPROC __gleGetActiveAttrib;
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
PFNGLGETACTIVEUNIFORMPROC __gleGetActiveUniform;
typedef void (GLE_FUNCPTR * PFNGLGETATTACHEDSHADERSPROC)(GLuint , GLsizei , GLsizei *, GLuint *);
PFNGLGETATTACHEDSHADERSPROC __gleGetAttachedShaders;
typedef GLint (GLE_FUNCPTR * PFNGLGETATTRIBLOCATIONPROC)(GLuint , const GLchar *);
PFNGLGETATTRIBLOCATIONPROC __gleGetAttribLocation;
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMIVPROC)(GLuint , GLenum , GLint *);
PFNGLGETPROGRAMIVPROC __gleGetProgramiv;
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMINFOLOGPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
PFNGLGETPROGRAMINFOLOGPROC __gleGetProgramInfoLog;
typedef void (GLE_FUNCPTR * PFNGLGETSHADERIVPROC)(GLuint , GLenum , GLint *);
PFNGLGETSHADERIVPROC __gleGetShaderiv;
typedef void (GLE_FUNCPTR * PFNGLGETSHADERINFOLOGPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
PFNGLGETSHADERINFOLOGPROC __gleGetShaderInfoLog;
typedef void (GLE_FUNCPTR * PFNGLGETSHADERSOURCEPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
PFNGLGETSHADERSOURCEPROC __gleGetShaderSource;
typedef GLint (GLE_FUNCPTR * PFNGLGETUNIFORMLOCATIONPROC)(GLuint , const GLchar *);
PFNGLGETUNIFORMLOCATIONPROC __gleGetUniformLocation;
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMFVPROC)(GLuint , GLint , GLfloat *);
PFNGLGETUNIFORMFVPROC __gleGetUniformfv;
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMIVPROC)(GLuint , GLint , GLint *);
PFNGLGETUNIFORMIVPROC __gleGetUniformiv;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBDVPROC)(GLuint , GLenum , GLdouble *);
PFNGLGETVERTEXATTRIBDVPROC __gleGetVertexAttribdv;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBFVPROC)(GLuint , GLenum , GLfloat *);
PFNGLGETVERTEXATTRIBFVPROC __gleGetVertexAttribfv;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIVPROC)(GLuint , GLenum , GLint *);
PFNGLGETVERTEXATTRIBIVPROC __gleGetVertexAttribiv;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint , GLenum , GLvoid* *);
PFNGLGETVERTEXATTRIBPOINTERVPROC __gleGetVertexAttribPointerv;
typedef GLboolean (GLE_FUNCPTR * PFNGLISPROGRAMPROC)(GLuint );
PFNGLISPROGRAMPROC __gleIsProgram;
typedef GLboolean (GLE_FUNCPTR * PFNGLISSHADERPROC)(GLuint );
PFNGLISSHADERPROC __gleIsShader;
typedef void (GLE_FUNCPTR * PFNGLLINKPROGRAMPROC)(GLuint );
PFNGLLINKPROGRAMPROC __gleLinkProgram;
typedef void (GLE_FUNCPTR * PFNGLSHADERSOURCEPROC)(GLuint , GLsizei , const GLchar* const *, const GLint *);
PFNGLSHADERSOURCEPROC __gleShaderSource;
typedef void (GLE_FUNCPTR * PFNGLUSEPROGRAMPROC)(GLuint );
PFNGLUSEPROGRAMPROC __gleUseProgram;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FPROC)(GLint , GLfloat );
PFNGLUNIFORM1FPROC __gleUniform1f;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FPROC)(GLint , GLfloat , GLfloat );
PFNGLUNIFORM2FPROC __gleUniform2f;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FPROC)(GLint , GLfloat , GLfloat , GLfloat );
PFNGLUNIFORM3FPROC __gleUniform3f;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FPROC)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLUNIFORM4FPROC __gleUniform4f;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IPROC)(GLint , GLint );
PFNGLUNIFORM1IPROC __gleUniform1i;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IPROC)(GLint , GLint , GLint );
PFNGLUNIFORM2IPROC __gleUniform2i;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IPROC)(GLint , GLint , GLint , GLint );
PFNGLUNIFORM3IPROC __gleUniform3i;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IPROC)(GLint , GLint , GLint , GLint , GLint );
PFNGLUNIFORM4IPROC __gleUniform4i;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FVPROC)(GLint , GLsizei , const GLfloat *);
PFNGLUNIFORM1FVPROC __gleUniform1fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FVPROC)(GLint , GLsizei , const GLfloat *);
PFNGLUNIFORM2FVPROC __gleUniform2fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FVPROC)(GLint , GLsizei , const GLfloat *);
PFNGLUNIFORM3FVPROC __gleUniform3fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FVPROC)(GLint , GLsizei , const GLfloat *);
PFNGLUNIFORM4FVPROC __gleUniform4fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IVPROC)(GLint , GLsizei , const GLint *);
PFNGLUNIFORM1IVPROC __gleUniform1iv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IVPROC)(GLint , GLsizei , const GLint *);
PFNGLUNIFORM2IVPROC __gleUniform2iv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IVPROC)(GLint , GLsizei , const GLint *);
PFNGLUNIFORM3IVPROC __gleUniform3iv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IVPROC)(GLint , GLsizei , const GLint *);
PFNGLUNIFORM4IVPROC __gleUniform4iv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX2FVPROC __gleUniformMatrix2fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX3FVPROC __gleUniformMatrix3fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX4FVPROC __gleUniformMatrix4fv;
typedef void (GLE_FUNCPTR * PFNGLVALIDATEPROGRAMPROC)(GLuint );
PFNGLVALIDATEPROGRAMPROC __gleValidateProgram;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DPROC)(GLuint , GLdouble );
PFNGLVERTEXATTRIB1DPROC __gleVertexAttrib1d;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DVPROC)(GLuint , const GLdouble *);
PFNGLVERTEXATTRIB1DVPROC __gleVertexAttrib1dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FPROC)(GLuint , GLfloat );
PFNGLVERTEXATTRIB1FPROC __gleVertexAttrib1f;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FVPROC)(GLuint , const GLfloat *);
PFNGLVERTEXATTRIB1FVPROC __gleVertexAttrib1fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SPROC)(GLuint , GLshort );
PFNGLVERTEXATTRIB1SPROC __gleVertexAttrib1s;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIB1SVPROC __gleVertexAttrib1sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DPROC)(GLuint , GLdouble , GLdouble );
PFNGLVERTEXATTRIB2DPROC __gleVertexAttrib2d;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DVPROC)(GLuint , const GLdouble *);
PFNGLVERTEXATTRIB2DVPROC __gleVertexAttrib2dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FPROC)(GLuint , GLfloat , GLfloat );
PFNGLVERTEXATTRIB2FPROC __gleVertexAttrib2f;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FVPROC)(GLuint , const GLfloat *);
PFNGLVERTEXATTRIB2FVPROC __gleVertexAttrib2fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SPROC)(GLuint , GLshort , GLshort );
PFNGLVERTEXATTRIB2SPROC __gleVertexAttrib2s;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIB2SVPROC __gleVertexAttrib2sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DPROC)(GLuint , GLdouble , GLdouble , GLdouble );
PFNGLVERTEXATTRIB3DPROC __gleVertexAttrib3d;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DVPROC)(GLuint , const GLdouble *);
PFNGLVERTEXATTRIB3DVPROC __gleVertexAttrib3dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FPROC)(GLuint , GLfloat , GLfloat , GLfloat );
PFNGLVERTEXATTRIB3FPROC __gleVertexAttrib3f;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FVPROC)(GLuint , const GLfloat *);
PFNGLVERTEXATTRIB3FVPROC __gleVertexAttrib3fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SPROC)(GLuint , GLshort , GLshort , GLshort );
PFNGLVERTEXATTRIB3SPROC __gleVertexAttrib3s;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIB3SVPROC __gleVertexAttrib3sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NBVPROC)(GLuint , const GLbyte *);
PFNGLVERTEXATTRIB4NBVPROC __gleVertexAttrib4Nbv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NIVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIB4NIVPROC __gleVertexAttrib4Niv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NSVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIB4NSVPROC __gleVertexAttrib4Nsv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
PFNGLVERTEXATTRIB4NUBPROC __gleVertexAttrib4Nub;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBVPROC)(GLuint , const GLubyte *);
PFNGLVERTEXATTRIB4NUBVPROC __gleVertexAttrib4Nubv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIB4NUIVPROC __gleVertexAttrib4Nuiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUSVPROC)(GLuint , const GLushort *);
PFNGLVERTEXATTRIB4NUSVPROC __gleVertexAttrib4Nusv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4BVPROC)(GLuint , const GLbyte *);
PFNGLVERTEXATTRIB4BVPROC __gleVertexAttrib4bv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
PFNGLVERTEXATTRIB4DPROC __gleVertexAttrib4d;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DVPROC)(GLuint , const GLdouble *);
PFNGLVERTEXATTRIB4DVPROC __gleVertexAttrib4dv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
PFNGLVERTEXATTRIB4FPROC __gleVertexAttrib4f;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FVPROC)(GLuint , const GLfloat *);
PFNGLVERTEXATTRIB4FVPROC __gleVertexAttrib4fv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4IVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIB4IVPROC __gleVertexAttrib4iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SPROC)(GLuint , GLshort , GLshort , GLshort , GLshort );
PFNGLVERTEXATTRIB4SPROC __gleVertexAttrib4s;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIB4SVPROC __gleVertexAttrib4sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UBVPROC)(GLuint , const GLubyte *);
PFNGLVERTEXATTRIB4UBVPROC __gleVertexAttrib4ubv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIB4UIVPROC __gleVertexAttrib4uiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4USVPROC)(GLuint , const GLushort *);
PFNGLVERTEXATTRIB4USVPROC __gleVertexAttrib4usv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBPOINTERPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *);
PFNGLVERTEXATTRIBPOINTERPROC __gleVertexAttribPointer;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2X3FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX2X3FVPROC __gleUniformMatrix2x3fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3X2FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX3X2FVPROC __gleUniformMatrix3x2fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2X4FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX2X4FVPROC __gleUniformMatrix2x4fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4X2FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX4X2FVPROC __gleUniformMatrix4x2fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3X4FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX3X4FVPROC __gleUniformMatrix3x4fv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4X3FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
PFNGLUNIFORMMATRIX4X3FVPROC __gleUniformMatrix4x3fv;
typedef void (GLE_FUNCPTR * PFNGLCOLORMASKIPROC)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
PFNGLCOLORMASKIPROC __gleColorMaski;
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANI_VPROC)(GLenum , GLuint , GLboolean *);
PFNGLGETBOOLEANI_VPROC __gleGetBooleani_v;
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERI_VPROC)(GLenum , GLuint , GLint *);
PFNGLGETINTEGERI_VPROC __gleGetIntegeri_v;
typedef void (GLE_FUNCPTR * PFNGLENABLEIPROC)(GLenum , GLuint );
PFNGLENABLEIPROC __gleEnablei;
typedef void (GLE_FUNCPTR * PFNGLDISABLEIPROC)(GLenum , GLuint );
PFNGLDISABLEIPROC __gleDisablei;
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDIPROC)(GLenum , GLuint );
PFNGLISENABLEDIPROC __gleIsEnabledi;
typedef void (GLE_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum );
PFNGLBEGINTRANSFORMFEEDBACKPROC __gleBeginTransformFeedback;
typedef void (GLE_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKPROC)();
PFNGLENDTRANSFORMFEEDBACKPROC __gleEndTransformFeedback;
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERRANGEPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
PFNGLBINDBUFFERRANGEPROC __gleBindBufferRange;
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERBASEPROC)(GLenum , GLuint , GLuint );
PFNGLBINDBUFFERBASEPROC __gleBindBufferBase;
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint , GLsizei , const GLchar* const *, GLenum );
PFNGLTRANSFORMFEEDBACKVARYINGSPROC __gleTransformFeedbackVaryings;
typedef void (GLE_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC __gleGetTransformFeedbackVarying;
typedef void (GLE_FUNCPTR * PFNGLCLAMPCOLORPROC)(GLenum , GLenum );
PFNGLCLAMPCOLORPROC __gleClampColor;
typedef void (GLE_FUNCPTR * PFNGLBEGINCONDITIONALRENDERPROC)(GLuint , GLenum );
PFNGLBEGINCONDITIONALRENDERPROC __gleBeginConditionalRender;
typedef void (GLE_FUNCPTR * PFNGLENDCONDITIONALRENDERPROC)();
PFNGLENDCONDITIONALRENDERPROC __gleEndConditionalRender;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
PFNGLVERTEXATTRIBIPOINTERPROC __gleVertexAttribIPointer;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIIVPROC)(GLuint , GLenum , GLint *);
PFNGLGETVERTEXATTRIBIIVPROC __gleGetVertexAttribIiv;
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint , GLenum , GLuint *);
PFNGLGETVERTEXATTRIBIUIVPROC __gleGetVertexAttribIuiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IPROC)(GLuint , GLint );
PFNGLVERTEXATTRIBI1IPROC __gleVertexAttribI1i;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IPROC)(GLuint , GLint , GLint );
PFNGLVERTEXATTRIBI2IPROC __gleVertexAttribI2i;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IPROC)(GLuint , GLint , GLint , GLint );
PFNGLVERTEXATTRIBI3IPROC __gleVertexAttribI3i;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IPROC)(GLuint , GLint , GLint , GLint , GLint );
PFNGLVERTEXATTRIBI4IPROC __gleVertexAttribI4i;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIPROC)(GLuint , GLuint );
PFNGLVERTEXATTRIBI1UIPROC __gleVertexAttribI1ui;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIPROC)(GLuint , GLuint , GLuint );
PFNGLVERTEXATTRIBI2UIPROC __gleVertexAttribI2ui;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIPROC)(GLuint , GLuint , GLuint , GLuint );
PFNGLVERTEXATTRIBI3UIPROC __gleVertexAttribI3ui;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIPROC)(GLuint , GLuint , GLuint , GLuint , GLuint );
PFNGLVERTEXATTRIBI4UIPROC __gleVertexAttribI4ui;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIBI1IVPROC __gleVertexAttribI1iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIBI2IVPROC __gleVertexAttribI2iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIBI3IVPROC __gleVertexAttribI3iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IVPROC)(GLuint , const GLint *);
PFNGLVERTEXATTRIBI4IVPROC __gleVertexAttribI4iv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIBI1UIVPROC __gleVertexAttribI1uiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIBI2UIVPROC __gleVertexAttribI2uiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIBI3UIVPROC __gleVertexAttribI3uiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIVPROC)(GLuint , const GLuint *);
PFNGLVERTEXATTRIBI4UIVPROC __gleVertexAttribI4uiv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4BVPROC)(GLuint , const GLbyte *);
PFNGLVERTEXATTRIBI4BVPROC __gleVertexAttribI4bv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4SVPROC)(GLuint , const GLshort *);
PFNGLVERTEXATTRIBI4SVPROC __gleVertexAttribI4sv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UBVPROC)(GLuint , const GLubyte *);
PFNGLVERTEXATTRIBI4UBVPROC __gleVertexAttribI4ubv;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4USVPROC)(GLuint , const GLushort *);
PFNGLVERTEXATTRIBI4USVPROC __gleVertexAttribI4usv;
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMUIVPROC)(GLuint , GLint , GLuint *);
PFNGLGETUNIFORMUIVPROC __gleGetUniformuiv;
typedef void (GLE_FUNCPTR * PFNGLBINDFRAGDATALOCATIONPROC)(GLuint , GLuint , const GLchar *);
PFNGLBINDFRAGDATALOCATIONPROC __gleBindFragDataLocation;
typedef GLint (GLE_FUNCPTR * PFNGLGETFRAGDATALOCATIONPROC)(GLuint , const GLchar *);
PFNGLGETFRAGDATALOCATIONPROC __gleGetFragDataLocation;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIPROC)(GLint , GLuint );
PFNGLUNIFORM1UIPROC __gleUniform1ui;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIPROC)(GLint , GLuint , GLuint );
PFNGLUNIFORM2UIPROC __gleUniform2ui;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIPROC)(GLint , GLuint , GLuint , GLuint );
PFNGLUNIFORM3UIPROC __gleUniform3ui;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIPROC)(GLint , GLuint , GLuint , GLuint , GLuint );
PFNGLUNIFORM4UIPROC __gleUniform4ui;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIVPROC)(GLint , GLsizei , const GLuint *);
PFNGLUNIFORM1UIVPROC __gleUniform1uiv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIVPROC)(GLint , GLsizei , const GLuint *);
PFNGLUNIFORM2UIVPROC __gleUniform2uiv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIVPROC)(GLint , GLsizei , const GLuint *);
PFNGLUNIFORM3UIVPROC __gleUniform3uiv;
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIVPROC)(GLint , GLsizei , const GLuint *);
PFNGLUNIFORM4UIVPROC __gleUniform4uiv;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIIVPROC)(GLenum , GLenum , const GLint *);
PFNGLTEXPARAMETERIIVPROC __gleTexParameterIiv;
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIUIVPROC)(GLenum , GLenum , const GLuint *);
PFNGLTEXPARAMETERIUIVPROC __gleTexParameterIuiv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIIVPROC)(GLenum , GLenum , GLint *);
PFNGLGETTEXPARAMETERIIVPROC __gleGetTexParameterIiv;
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIUIVPROC)(GLenum , GLenum , GLuint *);
PFNGLGETTEXPARAMETERIUIVPROC __gleGetTexParameterIuiv;
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERIVPROC)(GLenum , GLint , const GLint *);
PFNGLCLEARBUFFERIVPROC __gleClearBufferiv;
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERUIVPROC)(GLenum , GLint , const GLuint *);
PFNGLCLEARBUFFERUIVPROC __gleClearBufferuiv;
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERFVPROC)(GLenum , GLint , const GLfloat *);
PFNGLCLEARBUFFERFVPROC __gleClearBufferfv;
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERFIPROC)(GLenum , GLint , GLfloat , GLint );
PFNGLCLEARBUFFERFIPROC __gleClearBufferfi;
typedef const GLubyte * (GLE_FUNCPTR * PFNGLGETSTRINGIPROC)(GLenum , GLuint );
PFNGLGETSTRINGIPROC __gleGetStringi;
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum , GLint , GLsizei , GLsizei );
PFNGLDRAWARRAYSINSTANCEDPROC __gleDrawArraysInstanced;
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );
PFNGLDRAWELEMENTSINSTANCEDPROC __gleDrawElementsInstanced;
typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERPROC)(GLenum , GLenum , GLuint );
PFNGLTEXBUFFERPROC __gleTexBuffer;
typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint );
PFNGLPRIMITIVERESTARTINDEXPROC __glePrimitiveRestartIndex;
typedef void (GLE_FUNCPTR * PFNGLGETINTEGER64I_VPROC)(GLenum , GLuint , GLint64 *);
PFNGLGETINTEGER64I_VPROC __gleGetInteger64i_v;
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum , GLenum , GLint64 *);
PFNGLGETBUFFERPARAMETERI64VPROC __gleGetBufferParameteri64v;
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREPROC)(GLenum , GLenum , GLuint , GLint );
PFNGLFRAMEBUFFERTEXTUREPROC __gleFramebufferTexture;
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBDIVISORPROC)(GLuint , GLuint );
PFNGLVERTEXATTRIBDIVISORPROC __gleVertexAttribDivisor;
typedef void (GLE_FUNCPTR * PFNGLMINSAMPLESHADINGPROC)(GLfloat );
PFNGLMINSAMPLESHADINGPROC __gleMinSampleShading;
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONIPROC)(GLuint , GLenum );
PFNGLBLENDEQUATIONIPROC __gleBlendEquationi;
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint , GLenum , GLenum );
PFNGLBLENDEQUATIONSEPARATEIPROC __gleBlendEquationSeparatei;
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCIPROC)(GLuint , GLenum , GLenum );
PFNGLBLENDFUNCIPROC __gleBlendFunci;
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEIPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );
PFNGLBLENDFUNCSEPARATEIPROC __gleBlendFuncSeparatei;

static int gleIntLoadCore_1_1_Version_3_1()
{
	int bIsLoaded = 1;
	__gleCullFace = (PFNGLCULLFACEPROC)gleIntGetProcAddress("glCullFace");
	if(!__gleCullFace) bIsLoaded = 0;
	__gleFrontFace = (PFNGLFRONTFACEPROC)gleIntGetProcAddress("glFrontFace");
	if(!__gleFrontFace) bIsLoaded = 0;
	__gleHint = (PFNGLHINTPROC)gleIntGetProcAddress("glHint");
	if(!__gleHint) bIsLoaded = 0;
	__gleLineWidth = (PFNGLLINEWIDTHPROC)gleIntGetProcAddress("glLineWidth");
	if(!__gleLineWidth) bIsLoaded = 0;
	__glePointSize = (PFNGLPOINTSIZEPROC)gleIntGetProcAddress("glPointSize");
	if(!__glePointSize) bIsLoaded = 0;
	__glePolygonMode = (PFNGLPOLYGONMODEPROC)gleIntGetProcAddress("glPolygonMode");
	if(!__glePolygonMode) bIsLoaded = 0;
	__gleScissor = (PFNGLSCISSORPROC)gleIntGetProcAddress("glScissor");
	if(!__gleScissor) bIsLoaded = 0;
	__gleTexParameterf = (PFNGLTEXPARAMETERFPROC)gleIntGetProcAddress("glTexParameterf");
	if(!__gleTexParameterf) bIsLoaded = 0;
	__gleTexParameterfv = (PFNGLTEXPARAMETERFVPROC)gleIntGetProcAddress("glTexParameterfv");
	if(!__gleTexParameterfv) bIsLoaded = 0;
	__gleTexParameteri = (PFNGLTEXPARAMETERIPROC)gleIntGetProcAddress("glTexParameteri");
	if(!__gleTexParameteri) bIsLoaded = 0;
	__gleTexParameteriv = (PFNGLTEXPARAMETERIVPROC)gleIntGetProcAddress("glTexParameteriv");
	if(!__gleTexParameteriv) bIsLoaded = 0;
	__gleTexImage1D = (PFNGLTEXIMAGE1DPROC)gleIntGetProcAddress("glTexImage1D");
	if(!__gleTexImage1D) bIsLoaded = 0;
	__gleTexImage2D = (PFNGLTEXIMAGE2DPROC)gleIntGetProcAddress("glTexImage2D");
	if(!__gleTexImage2D) bIsLoaded = 0;
	__gleDrawBuffer = (PFNGLDRAWBUFFERPROC)gleIntGetProcAddress("glDrawBuffer");
	if(!__gleDrawBuffer) bIsLoaded = 0;
	__gleClear = (PFNGLCLEARPROC)gleIntGetProcAddress("glClear");
	if(!__gleClear) bIsLoaded = 0;
	__gleClearColor = (PFNGLCLEARCOLORPROC)gleIntGetProcAddress("glClearColor");
	if(!__gleClearColor) bIsLoaded = 0;
	__gleClearStencil = (PFNGLCLEARSTENCILPROC)gleIntGetProcAddress("glClearStencil");
	if(!__gleClearStencil) bIsLoaded = 0;
	__gleClearDepth = (PFNGLCLEARDEPTHPROC)gleIntGetProcAddress("glClearDepth");
	if(!__gleClearDepth) bIsLoaded = 0;
	__gleStencilMask = (PFNGLSTENCILMASKPROC)gleIntGetProcAddress("glStencilMask");
	if(!__gleStencilMask) bIsLoaded = 0;
	__gleColorMask = (PFNGLCOLORMASKPROC)gleIntGetProcAddress("glColorMask");
	if(!__gleColorMask) bIsLoaded = 0;
	__gleDepthMask = (PFNGLDEPTHMASKPROC)gleIntGetProcAddress("glDepthMask");
	if(!__gleDepthMask) bIsLoaded = 0;
	__gleDisable = (PFNGLDISABLEPROC)gleIntGetProcAddress("glDisable");
	if(!__gleDisable) bIsLoaded = 0;
	__gleEnable = (PFNGLENABLEPROC)gleIntGetProcAddress("glEnable");
	if(!__gleEnable) bIsLoaded = 0;
	__gleFinish = (PFNGLFINISHPROC)gleIntGetProcAddress("glFinish");
	if(!__gleFinish) bIsLoaded = 0;
	__gleFlush = (PFNGLFLUSHPROC)gleIntGetProcAddress("glFlush");
	if(!__gleFlush) bIsLoaded = 0;
	__gleBlendFunc = (PFNGLBLENDFUNCPROC)gleIntGetProcAddress("glBlendFunc");
	if(!__gleBlendFunc) bIsLoaded = 0;
	__gleLogicOp = (PFNGLLOGICOPPROC)gleIntGetProcAddress("glLogicOp");
	if(!__gleLogicOp) bIsLoaded = 0;
	__gleStencilFunc = (PFNGLSTENCILFUNCPROC)gleIntGetProcAddress("glStencilFunc");
	if(!__gleStencilFunc) bIsLoaded = 0;
	__gleStencilOp = (PFNGLSTENCILOPPROC)gleIntGetProcAddress("glStencilOp");
	if(!__gleStencilOp) bIsLoaded = 0;
	__gleDepthFunc = (PFNGLDEPTHFUNCPROC)gleIntGetProcAddress("glDepthFunc");
	if(!__gleDepthFunc) bIsLoaded = 0;
	__glePixelStoref = (PFNGLPIXELSTOREFPROC)gleIntGetProcAddress("glPixelStoref");
	if(!__glePixelStoref) bIsLoaded = 0;
	__glePixelStorei = (PFNGLPIXELSTOREIPROC)gleIntGetProcAddress("glPixelStorei");
	if(!__glePixelStorei) bIsLoaded = 0;
	__gleReadBuffer = (PFNGLREADBUFFERPROC)gleIntGetProcAddress("glReadBuffer");
	if(!__gleReadBuffer) bIsLoaded = 0;
	__gleReadPixels = (PFNGLREADPIXELSPROC)gleIntGetProcAddress("glReadPixels");
	if(!__gleReadPixels) bIsLoaded = 0;
	__gleGetBooleanv = (PFNGLGETBOOLEANVPROC)gleIntGetProcAddress("glGetBooleanv");
	if(!__gleGetBooleanv) bIsLoaded = 0;
	__gleGetDoublev = (PFNGLGETDOUBLEVPROC)gleIntGetProcAddress("glGetDoublev");
	if(!__gleGetDoublev) bIsLoaded = 0;
	__gleGetError = (PFNGLGETERRORPROC)gleIntGetProcAddress("glGetError");
	if(!__gleGetError) bIsLoaded = 0;
	__gleGetFloatv = (PFNGLGETFLOATVPROC)gleIntGetProcAddress("glGetFloatv");
	if(!__gleGetFloatv) bIsLoaded = 0;
	__gleGetIntegerv = (PFNGLGETINTEGERVPROC)gleIntGetProcAddress("glGetIntegerv");
	if(!__gleGetIntegerv) bIsLoaded = 0;
	__gleGetString = (PFNGLGETSTRINGPROC)gleIntGetProcAddress("glGetString");
	if(!__gleGetString) bIsLoaded = 0;
	__gleGetTexImage = (PFNGLGETTEXIMAGEPROC)gleIntGetProcAddress("glGetTexImage");
	if(!__gleGetTexImage) bIsLoaded = 0;
	__gleGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)gleIntGetProcAddress("glGetTexParameterfv");
	if(!__gleGetTexParameterfv) bIsLoaded = 0;
	__gleGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)gleIntGetProcAddress("glGetTexParameteriv");
	if(!__gleGetTexParameteriv) bIsLoaded = 0;
	__gleGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)gleIntGetProcAddress("glGetTexLevelParameterfv");
	if(!__gleGetTexLevelParameterfv) bIsLoaded = 0;
	__gleGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)gleIntGetProcAddress("glGetTexLevelParameteriv");
	if(!__gleGetTexLevelParameteriv) bIsLoaded = 0;
	__gleIsEnabled = (PFNGLISENABLEDPROC)gleIntGetProcAddress("glIsEnabled");
	if(!__gleIsEnabled) bIsLoaded = 0;
	__gleDepthRange = (PFNGLDEPTHRANGEPROC)gleIntGetProcAddress("glDepthRange");
	if(!__gleDepthRange) bIsLoaded = 0;
	__gleViewport = (PFNGLVIEWPORTPROC)gleIntGetProcAddress("glViewport");
	if(!__gleViewport) bIsLoaded = 0;
	__gleDrawArrays = (PFNGLDRAWARRAYSPROC)gleIntGetProcAddress("glDrawArrays");
	if(!__gleDrawArrays) bIsLoaded = 0;
	__gleDrawElements = (PFNGLDRAWELEMENTSPROC)gleIntGetProcAddress("glDrawElements");
	if(!__gleDrawElements) bIsLoaded = 0;
	__gleGetPointerv = (PFNGLGETPOINTERVPROC)gleIntGetProcAddress("glGetPointerv");
	if(!__gleGetPointerv) bIsLoaded = 0;
	__glePolygonOffset = (PFNGLPOLYGONOFFSETPROC)gleIntGetProcAddress("glPolygonOffset");
	if(!__glePolygonOffset) bIsLoaded = 0;
	__gleCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)gleIntGetProcAddress("glCopyTexImage1D");
	if(!__gleCopyTexImage1D) bIsLoaded = 0;
	__gleCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)gleIntGetProcAddress("glCopyTexImage2D");
	if(!__gleCopyTexImage2D) bIsLoaded = 0;
	__gleCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)gleIntGetProcAddress("glCopyTexSubImage1D");
	if(!__gleCopyTexSubImage1D) bIsLoaded = 0;
	__gleCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)gleIntGetProcAddress("glCopyTexSubImage2D");
	if(!__gleCopyTexSubImage2D) bIsLoaded = 0;
	__gleTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)gleIntGetProcAddress("glTexSubImage1D");
	if(!__gleTexSubImage1D) bIsLoaded = 0;
	__gleTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)gleIntGetProcAddress("glTexSubImage2D");
	if(!__gleTexSubImage2D) bIsLoaded = 0;
	__gleBindTexture = (PFNGLBINDTEXTUREPROC)gleIntGetProcAddress("glBindTexture");
	if(!__gleBindTexture) bIsLoaded = 0;
	__gleDeleteTextures = (PFNGLDELETETEXTURESPROC)gleIntGetProcAddress("glDeleteTextures");
	if(!__gleDeleteTextures) bIsLoaded = 0;
	__gleGenTextures = (PFNGLGENTEXTURESPROC)gleIntGetProcAddress("glGenTextures");
	if(!__gleGenTextures) bIsLoaded = 0;
	__gleIsTexture = (PFNGLISTEXTUREPROC)gleIntGetProcAddress("glIsTexture");
	if(!__gleIsTexture) bIsLoaded = 0;
	__gleIndexub = (PFNGLINDEXUBPROC)gleIntGetProcAddress("glIndexub");
	if(!__gleIndexub) bIsLoaded = 0;
	__gleIndexubv = (PFNGLINDEXUBVPROC)gleIntGetProcAddress("glIndexubv");
	if(!__gleIndexubv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_2_Version_3_1()
{
	int bIsLoaded = 1;
	__gleBlendColor = (PFNGLBLENDCOLORPROC)gleIntGetProcAddress("glBlendColor");
	if(!__gleBlendColor) bIsLoaded = 0;
	__gleBlendEquation = (PFNGLBLENDEQUATIONPROC)gleIntGetProcAddress("glBlendEquation");
	if(!__gleBlendEquation) bIsLoaded = 0;
	__gleDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)gleIntGetProcAddress("glDrawRangeElements");
	if(!__gleDrawRangeElements) bIsLoaded = 0;
	__gleTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)gleIntGetProcAddress("glTexSubImage3D");
	if(!__gleTexSubImage3D) bIsLoaded = 0;
	__gleCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)gleIntGetProcAddress("glCopyTexSubImage3D");
	if(!__gleCopyTexSubImage3D) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_3_Version_3_1()
{
	int bIsLoaded = 1;
	__gleActiveTexture = (PFNGLACTIVETEXTUREPROC)gleIntGetProcAddress("glActiveTexture");
	if(!__gleActiveTexture) bIsLoaded = 0;
	__gleSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)gleIntGetProcAddress("glSampleCoverage");
	if(!__gleSampleCoverage) bIsLoaded = 0;
	__gleCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)gleIntGetProcAddress("glCompressedTexImage3D");
	if(!__gleCompressedTexImage3D) bIsLoaded = 0;
	__gleCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)gleIntGetProcAddress("glCompressedTexImage2D");
	if(!__gleCompressedTexImage2D) bIsLoaded = 0;
	__gleCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)gleIntGetProcAddress("glCompressedTexImage1D");
	if(!__gleCompressedTexImage1D) bIsLoaded = 0;
	__gleCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)gleIntGetProcAddress("glCompressedTexSubImage3D");
	if(!__gleCompressedTexSubImage3D) bIsLoaded = 0;
	__gleCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)gleIntGetProcAddress("glCompressedTexSubImage2D");
	if(!__gleCompressedTexSubImage2D) bIsLoaded = 0;
	__gleCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)gleIntGetProcAddress("glCompressedTexSubImage1D");
	if(!__gleCompressedTexSubImage1D) bIsLoaded = 0;
	__gleGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)gleIntGetProcAddress("glGetCompressedTexImage");
	if(!__gleGetCompressedTexImage) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_4_Version_3_1()
{
	int bIsLoaded = 1;
	__gleBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)gleIntGetProcAddress("glBlendFuncSeparate");
	if(!__gleBlendFuncSeparate) bIsLoaded = 0;
	__gleMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)gleIntGetProcAddress("glMultiDrawArrays");
	if(!__gleMultiDrawArrays) bIsLoaded = 0;
	__gleMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)gleIntGetProcAddress("glMultiDrawElements");
	if(!__gleMultiDrawElements) bIsLoaded = 0;
	__glePointParameterf = (PFNGLPOINTPARAMETERFPROC)gleIntGetProcAddress("glPointParameterf");
	if(!__glePointParameterf) bIsLoaded = 0;
	__glePointParameterfv = (PFNGLPOINTPARAMETERFVPROC)gleIntGetProcAddress("glPointParameterfv");
	if(!__glePointParameterfv) bIsLoaded = 0;
	__glePointParameteri = (PFNGLPOINTPARAMETERIPROC)gleIntGetProcAddress("glPointParameteri");
	if(!__glePointParameteri) bIsLoaded = 0;
	__glePointParameteriv = (PFNGLPOINTPARAMETERIVPROC)gleIntGetProcAddress("glPointParameteriv");
	if(!__glePointParameteriv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_5_Version_3_1()
{
	int bIsLoaded = 1;
	__gleGenQueries = (PFNGLGENQUERIESPROC)gleIntGetProcAddress("glGenQueries");
	if(!__gleGenQueries) bIsLoaded = 0;
	__gleDeleteQueries = (PFNGLDELETEQUERIESPROC)gleIntGetProcAddress("glDeleteQueries");
	if(!__gleDeleteQueries) bIsLoaded = 0;
	__gleIsQuery = (PFNGLISQUERYPROC)gleIntGetProcAddress("glIsQuery");
	if(!__gleIsQuery) bIsLoaded = 0;
	__gleBeginQuery = (PFNGLBEGINQUERYPROC)gleIntGetProcAddress("glBeginQuery");
	if(!__gleBeginQuery) bIsLoaded = 0;
	__gleEndQuery = (PFNGLENDQUERYPROC)gleIntGetProcAddress("glEndQuery");
	if(!__gleEndQuery) bIsLoaded = 0;
	__gleGetQueryiv = (PFNGLGETQUERYIVPROC)gleIntGetProcAddress("glGetQueryiv");
	if(!__gleGetQueryiv) bIsLoaded = 0;
	__gleGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)gleIntGetProcAddress("glGetQueryObjectiv");
	if(!__gleGetQueryObjectiv) bIsLoaded = 0;
	__gleGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)gleIntGetProcAddress("glGetQueryObjectuiv");
	if(!__gleGetQueryObjectuiv) bIsLoaded = 0;
	__gleBindBuffer = (PFNGLBINDBUFFERPROC)gleIntGetProcAddress("glBindBuffer");
	if(!__gleBindBuffer) bIsLoaded = 0;
	__gleDeleteBuffers = (PFNGLDELETEBUFFERSPROC)gleIntGetProcAddress("glDeleteBuffers");
	if(!__gleDeleteBuffers) bIsLoaded = 0;
	__gleGenBuffers = (PFNGLGENBUFFERSPROC)gleIntGetProcAddress("glGenBuffers");
	if(!__gleGenBuffers) bIsLoaded = 0;
	__gleIsBuffer = (PFNGLISBUFFERPROC)gleIntGetProcAddress("glIsBuffer");
	if(!__gleIsBuffer) bIsLoaded = 0;
	__gleBufferData = (PFNGLBUFFERDATAPROC)gleIntGetProcAddress("glBufferData");
	if(!__gleBufferData) bIsLoaded = 0;
	__gleBufferSubData = (PFNGLBUFFERSUBDATAPROC)gleIntGetProcAddress("glBufferSubData");
	if(!__gleBufferSubData) bIsLoaded = 0;
	__gleGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)gleIntGetProcAddress("glGetBufferSubData");
	if(!__gleGetBufferSubData) bIsLoaded = 0;
	__gleMapBuffer = (PFNGLMAPBUFFERPROC)gleIntGetProcAddress("glMapBuffer");
	if(!__gleMapBuffer) bIsLoaded = 0;
	__gleUnmapBuffer = (PFNGLUNMAPBUFFERPROC)gleIntGetProcAddress("glUnmapBuffer");
	if(!__gleUnmapBuffer) bIsLoaded = 0;
	__gleGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)gleIntGetProcAddress("glGetBufferParameteriv");
	if(!__gleGetBufferParameteriv) bIsLoaded = 0;
	__gleGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)gleIntGetProcAddress("glGetBufferPointerv");
	if(!__gleGetBufferPointerv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_2_0_Version_3_1()
{
	int bIsLoaded = 1;
	__gleBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)gleIntGetProcAddress("glBlendEquationSeparate");
	if(!__gleBlendEquationSeparate) bIsLoaded = 0;
	__gleDrawBuffers = (PFNGLDRAWBUFFERSPROC)gleIntGetProcAddress("glDrawBuffers");
	if(!__gleDrawBuffers) bIsLoaded = 0;
	__gleStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)gleIntGetProcAddress("glStencilOpSeparate");
	if(!__gleStencilOpSeparate) bIsLoaded = 0;
	__gleStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)gleIntGetProcAddress("glStencilFuncSeparate");
	if(!__gleStencilFuncSeparate) bIsLoaded = 0;
	__gleStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)gleIntGetProcAddress("glStencilMaskSeparate");
	if(!__gleStencilMaskSeparate) bIsLoaded = 0;
	__gleAttachShader = (PFNGLATTACHSHADERPROC)gleIntGetProcAddress("glAttachShader");
	if(!__gleAttachShader) bIsLoaded = 0;
	__gleBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)gleIntGetProcAddress("glBindAttribLocation");
	if(!__gleBindAttribLocation) bIsLoaded = 0;
	__gleCompileShader = (PFNGLCOMPILESHADERPROC)gleIntGetProcAddress("glCompileShader");
	if(!__gleCompileShader) bIsLoaded = 0;
	__gleCreateProgram = (PFNGLCREATEPROGRAMPROC)gleIntGetProcAddress("glCreateProgram");
	if(!__gleCreateProgram) bIsLoaded = 0;
	__gleCreateShader = (PFNGLCREATESHADERPROC)gleIntGetProcAddress("glCreateShader");
	if(!__gleCreateShader) bIsLoaded = 0;
	__gleDeleteProgram = (PFNGLDELETEPROGRAMPROC)gleIntGetProcAddress("glDeleteProgram");
	if(!__gleDeleteProgram) bIsLoaded = 0;
	__gleDeleteShader = (PFNGLDELETESHADERPROC)gleIntGetProcAddress("glDeleteShader");
	if(!__gleDeleteShader) bIsLoaded = 0;
	__gleDetachShader = (PFNGLDETACHSHADERPROC)gleIntGetProcAddress("glDetachShader");
	if(!__gleDetachShader) bIsLoaded = 0;
	__gleDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)gleIntGetProcAddress("glDisableVertexAttribArray");
	if(!__gleDisableVertexAttribArray) bIsLoaded = 0;
	__gleEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)gleIntGetProcAddress("glEnableVertexAttribArray");
	if(!__gleEnableVertexAttribArray) bIsLoaded = 0;
	__gleGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)gleIntGetProcAddress("glGetActiveAttrib");
	if(!__gleGetActiveAttrib) bIsLoaded = 0;
	__gleGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)gleIntGetProcAddress("glGetActiveUniform");
	if(!__gleGetActiveUniform) bIsLoaded = 0;
	__gleGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)gleIntGetProcAddress("glGetAttachedShaders");
	if(!__gleGetAttachedShaders) bIsLoaded = 0;
	__gleGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)gleIntGetProcAddress("glGetAttribLocation");
	if(!__gleGetAttribLocation) bIsLoaded = 0;
	__gleGetProgramiv = (PFNGLGETPROGRAMIVPROC)gleIntGetProcAddress("glGetProgramiv");
	if(!__gleGetProgramiv) bIsLoaded = 0;
	__gleGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)gleIntGetProcAddress("glGetProgramInfoLog");
	if(!__gleGetProgramInfoLog) bIsLoaded = 0;
	__gleGetShaderiv = (PFNGLGETSHADERIVPROC)gleIntGetProcAddress("glGetShaderiv");
	if(!__gleGetShaderiv) bIsLoaded = 0;
	__gleGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)gleIntGetProcAddress("glGetShaderInfoLog");
	if(!__gleGetShaderInfoLog) bIsLoaded = 0;
	__gleGetShaderSource = (PFNGLGETSHADERSOURCEPROC)gleIntGetProcAddress("glGetShaderSource");
	if(!__gleGetShaderSource) bIsLoaded = 0;
	__gleGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)gleIntGetProcAddress("glGetUniformLocation");
	if(!__gleGetUniformLocation) bIsLoaded = 0;
	__gleGetUniformfv = (PFNGLGETUNIFORMFVPROC)gleIntGetProcAddress("glGetUniformfv");
	if(!__gleGetUniformfv) bIsLoaded = 0;
	__gleGetUniformiv = (PFNGLGETUNIFORMIVPROC)gleIntGetProcAddress("glGetUniformiv");
	if(!__gleGetUniformiv) bIsLoaded = 0;
	__gleGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)gleIntGetProcAddress("glGetVertexAttribdv");
	if(!__gleGetVertexAttribdv) bIsLoaded = 0;
	__gleGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)gleIntGetProcAddress("glGetVertexAttribfv");
	if(!__gleGetVertexAttribfv) bIsLoaded = 0;
	__gleGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)gleIntGetProcAddress("glGetVertexAttribiv");
	if(!__gleGetVertexAttribiv) bIsLoaded = 0;
	__gleGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)gleIntGetProcAddress("glGetVertexAttribPointerv");
	if(!__gleGetVertexAttribPointerv) bIsLoaded = 0;
	__gleIsProgram = (PFNGLISPROGRAMPROC)gleIntGetProcAddress("glIsProgram");
	if(!__gleIsProgram) bIsLoaded = 0;
	__gleIsShader = (PFNGLISSHADERPROC)gleIntGetProcAddress("glIsShader");
	if(!__gleIsShader) bIsLoaded = 0;
	__gleLinkProgram = (PFNGLLINKPROGRAMPROC)gleIntGetProcAddress("glLinkProgram");
	if(!__gleLinkProgram) bIsLoaded = 0;
	__gleShaderSource = (PFNGLSHADERSOURCEPROC)gleIntGetProcAddress("glShaderSource");
	if(!__gleShaderSource) bIsLoaded = 0;
	__gleUseProgram = (PFNGLUSEPROGRAMPROC)gleIntGetProcAddress("glUseProgram");
	if(!__gleUseProgram) bIsLoaded = 0;
	__gleUniform1f = (PFNGLUNIFORM1FPROC)gleIntGetProcAddress("glUniform1f");
	if(!__gleUniform1f) bIsLoaded = 0;
	__gleUniform2f = (PFNGLUNIFORM2FPROC)gleIntGetProcAddress("glUniform2f");
	if(!__gleUniform2f) bIsLoaded = 0;
	__gleUniform3f = (PFNGLUNIFORM3FPROC)gleIntGetProcAddress("glUniform3f");
	if(!__gleUniform3f) bIsLoaded = 0;
	__gleUniform4f = (PFNGLUNIFORM4FPROC)gleIntGetProcAddress("glUniform4f");
	if(!__gleUniform4f) bIsLoaded = 0;
	__gleUniform1i = (PFNGLUNIFORM1IPROC)gleIntGetProcAddress("glUniform1i");
	if(!__gleUniform1i) bIsLoaded = 0;
	__gleUniform2i = (PFNGLUNIFORM2IPROC)gleIntGetProcAddress("glUniform2i");
	if(!__gleUniform2i) bIsLoaded = 0;
	__gleUniform3i = (PFNGLUNIFORM3IPROC)gleIntGetProcAddress("glUniform3i");
	if(!__gleUniform3i) bIsLoaded = 0;
	__gleUniform4i = (PFNGLUNIFORM4IPROC)gleIntGetProcAddress("glUniform4i");
	if(!__gleUniform4i) bIsLoaded = 0;
	__gleUniform1fv = (PFNGLUNIFORM1FVPROC)gleIntGetProcAddress("glUniform1fv");
	if(!__gleUniform1fv) bIsLoaded = 0;
	__gleUniform2fv = (PFNGLUNIFORM2FVPROC)gleIntGetProcAddress("glUniform2fv");
	if(!__gleUniform2fv) bIsLoaded = 0;
	__gleUniform3fv = (PFNGLUNIFORM3FVPROC)gleIntGetProcAddress("glUniform3fv");
	if(!__gleUniform3fv) bIsLoaded = 0;
	__gleUniform4fv = (PFNGLUNIFORM4FVPROC)gleIntGetProcAddress("glUniform4fv");
	if(!__gleUniform4fv) bIsLoaded = 0;
	__gleUniform1iv = (PFNGLUNIFORM1IVPROC)gleIntGetProcAddress("glUniform1iv");
	if(!__gleUniform1iv) bIsLoaded = 0;
	__gleUniform2iv = (PFNGLUNIFORM2IVPROC)gleIntGetProcAddress("glUniform2iv");
	if(!__gleUniform2iv) bIsLoaded = 0;
	__gleUniform3iv = (PFNGLUNIFORM3IVPROC)gleIntGetProcAddress("glUniform3iv");
	if(!__gleUniform3iv) bIsLoaded = 0;
	__gleUniform4iv = (PFNGLUNIFORM4IVPROC)gleIntGetProcAddress("glUniform4iv");
	if(!__gleUniform4iv) bIsLoaded = 0;
	__gleUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)gleIntGetProcAddress("glUniformMatrix2fv");
	if(!__gleUniformMatrix2fv) bIsLoaded = 0;
	__gleUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)gleIntGetProcAddress("glUniformMatrix3fv");
	if(!__gleUniformMatrix3fv) bIsLoaded = 0;
	__gleUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)gleIntGetProcAddress("glUniformMatrix4fv");
	if(!__gleUniformMatrix4fv) bIsLoaded = 0;
	__gleValidateProgram = (PFNGLVALIDATEPROGRAMPROC)gleIntGetProcAddress("glValidateProgram");
	if(!__gleValidateProgram) bIsLoaded = 0;
	__gleVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)gleIntGetProcAddress("glVertexAttribPointer");
	if(!__gleVertexAttribPointer) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_2_1_Version_3_1()
{
	int bIsLoaded = 1;
	__gleUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)gleIntGetProcAddress("glUniformMatrix2x3fv");
	if(!__gleUniformMatrix2x3fv) bIsLoaded = 0;
	__gleUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)gleIntGetProcAddress("glUniformMatrix3x2fv");
	if(!__gleUniformMatrix3x2fv) bIsLoaded = 0;
	__gleUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)gleIntGetProcAddress("glUniformMatrix2x4fv");
	if(!__gleUniformMatrix2x4fv) bIsLoaded = 0;
	__gleUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)gleIntGetProcAddress("glUniformMatrix4x2fv");
	if(!__gleUniformMatrix4x2fv) bIsLoaded = 0;
	__gleUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)gleIntGetProcAddress("glUniformMatrix3x4fv");
	if(!__gleUniformMatrix3x4fv) bIsLoaded = 0;
	__gleUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)gleIntGetProcAddress("glUniformMatrix4x3fv");
	if(!__gleUniformMatrix4x3fv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_3_0_Version_3_1()
{
	int bIsLoaded = 1;
	__gleColorMaski = (PFNGLCOLORMASKIPROC)gleIntGetProcAddress("glColorMaski");
	if(!__gleColorMaski) bIsLoaded = 0;
	__gleGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)gleIntGetProcAddress("glGetBooleani_v");
	if(!__gleGetBooleani_v) bIsLoaded = 0;
	__gleGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)gleIntGetProcAddress("glGetIntegeri_v");
	if(!__gleGetIntegeri_v) bIsLoaded = 0;
	__gleEnablei = (PFNGLENABLEIPROC)gleIntGetProcAddress("glEnablei");
	if(!__gleEnablei) bIsLoaded = 0;
	__gleDisablei = (PFNGLDISABLEIPROC)gleIntGetProcAddress("glDisablei");
	if(!__gleDisablei) bIsLoaded = 0;
	__gleIsEnabledi = (PFNGLISENABLEDIPROC)gleIntGetProcAddress("glIsEnabledi");
	if(!__gleIsEnabledi) bIsLoaded = 0;
	__gleBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glBeginTransformFeedback");
	if(!__gleBeginTransformFeedback) bIsLoaded = 0;
	__gleEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glEndTransformFeedback");
	if(!__gleEndTransformFeedback) bIsLoaded = 0;
	__gleBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)gleIntGetProcAddress("glBindBufferRange");
	if(!__gleBindBufferRange) bIsLoaded = 0;
	__gleBindBufferBase = (PFNGLBINDBUFFERBASEPROC)gleIntGetProcAddress("glBindBufferBase");
	if(!__gleBindBufferBase) bIsLoaded = 0;
	__gleTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)gleIntGetProcAddress("glTransformFeedbackVaryings");
	if(!__gleTransformFeedbackVaryings) bIsLoaded = 0;
	__gleGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)gleIntGetProcAddress("glGetTransformFeedbackVarying");
	if(!__gleGetTransformFeedbackVarying) bIsLoaded = 0;
	__gleClampColor = (PFNGLCLAMPCOLORPROC)gleIntGetProcAddress("glClampColor");
	if(!__gleClampColor) bIsLoaded = 0;
	__gleBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)gleIntGetProcAddress("glBeginConditionalRender");
	if(!__gleBeginConditionalRender) bIsLoaded = 0;
	__gleEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)gleIntGetProcAddress("glEndConditionalRender");
	if(!__gleEndConditionalRender) bIsLoaded = 0;
	__gleVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)gleIntGetProcAddress("glVertexAttribIPointer");
	if(!__gleVertexAttribIPointer) bIsLoaded = 0;
	__gleGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)gleIntGetProcAddress("glGetVertexAttribIiv");
	if(!__gleGetVertexAttribIiv) bIsLoaded = 0;
	__gleGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)gleIntGetProcAddress("glGetVertexAttribIuiv");
	if(!__gleGetVertexAttribIuiv) bIsLoaded = 0;
	__gleVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)gleIntGetProcAddress("glVertexAttribI1i");
	if(!__gleVertexAttribI1i) bIsLoaded = 0;
	__gleVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)gleIntGetProcAddress("glVertexAttribI2i");
	if(!__gleVertexAttribI2i) bIsLoaded = 0;
	__gleVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)gleIntGetProcAddress("glVertexAttribI3i");
	if(!__gleVertexAttribI3i) bIsLoaded = 0;
	__gleVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)gleIntGetProcAddress("glVertexAttribI4i");
	if(!__gleVertexAttribI4i) bIsLoaded = 0;
	__gleVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)gleIntGetProcAddress("glVertexAttribI1ui");
	if(!__gleVertexAttribI1ui) bIsLoaded = 0;
	__gleVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)gleIntGetProcAddress("glVertexAttribI2ui");
	if(!__gleVertexAttribI2ui) bIsLoaded = 0;
	__gleVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)gleIntGetProcAddress("glVertexAttribI3ui");
	if(!__gleVertexAttribI3ui) bIsLoaded = 0;
	__gleVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)gleIntGetProcAddress("glVertexAttribI4ui");
	if(!__gleVertexAttribI4ui) bIsLoaded = 0;
	__gleVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)gleIntGetProcAddress("glVertexAttribI1iv");
	if(!__gleVertexAttribI1iv) bIsLoaded = 0;
	__gleVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)gleIntGetProcAddress("glVertexAttribI2iv");
	if(!__gleVertexAttribI2iv) bIsLoaded = 0;
	__gleVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)gleIntGetProcAddress("glVertexAttribI3iv");
	if(!__gleVertexAttribI3iv) bIsLoaded = 0;
	__gleVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)gleIntGetProcAddress("glVertexAttribI4iv");
	if(!__gleVertexAttribI4iv) bIsLoaded = 0;
	__gleVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)gleIntGetProcAddress("glVertexAttribI1uiv");
	if(!__gleVertexAttribI1uiv) bIsLoaded = 0;
	__gleVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)gleIntGetProcAddress("glVertexAttribI2uiv");
	if(!__gleVertexAttribI2uiv) bIsLoaded = 0;
	__gleVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)gleIntGetProcAddress("glVertexAttribI3uiv");
	if(!__gleVertexAttribI3uiv) bIsLoaded = 0;
	__gleVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)gleIntGetProcAddress("glVertexAttribI4uiv");
	if(!__gleVertexAttribI4uiv) bIsLoaded = 0;
	__gleVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)gleIntGetProcAddress("glVertexAttribI4bv");
	if(!__gleVertexAttribI4bv) bIsLoaded = 0;
	__gleVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)gleIntGetProcAddress("glVertexAttribI4sv");
	if(!__gleVertexAttribI4sv) bIsLoaded = 0;
	__gleVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)gleIntGetProcAddress("glVertexAttribI4ubv");
	if(!__gleVertexAttribI4ubv) bIsLoaded = 0;
	__gleVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)gleIntGetProcAddress("glVertexAttribI4usv");
	if(!__gleVertexAttribI4usv) bIsLoaded = 0;
	__gleGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)gleIntGetProcAddress("glGetUniformuiv");
	if(!__gleGetUniformuiv) bIsLoaded = 0;
	__gleBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)gleIntGetProcAddress("glBindFragDataLocation");
	if(!__gleBindFragDataLocation) bIsLoaded = 0;
	__gleGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)gleIntGetProcAddress("glGetFragDataLocation");
	if(!__gleGetFragDataLocation) bIsLoaded = 0;
	__gleUniform1ui = (PFNGLUNIFORM1UIPROC)gleIntGetProcAddress("glUniform1ui");
	if(!__gleUniform1ui) bIsLoaded = 0;
	__gleUniform2ui = (PFNGLUNIFORM2UIPROC)gleIntGetProcAddress("glUniform2ui");
	if(!__gleUniform2ui) bIsLoaded = 0;
	__gleUniform3ui = (PFNGLUNIFORM3UIPROC)gleIntGetProcAddress("glUniform3ui");
	if(!__gleUniform3ui) bIsLoaded = 0;
	__gleUniform4ui = (PFNGLUNIFORM4UIPROC)gleIntGetProcAddress("glUniform4ui");
	if(!__gleUniform4ui) bIsLoaded = 0;
	__gleUniform1uiv = (PFNGLUNIFORM1UIVPROC)gleIntGetProcAddress("glUniform1uiv");
	if(!__gleUniform1uiv) bIsLoaded = 0;
	__gleUniform2uiv = (PFNGLUNIFORM2UIVPROC)gleIntGetProcAddress("glUniform2uiv");
	if(!__gleUniform2uiv) bIsLoaded = 0;
	__gleUniform3uiv = (PFNGLUNIFORM3UIVPROC)gleIntGetProcAddress("glUniform3uiv");
	if(!__gleUniform3uiv) bIsLoaded = 0;
	__gleUniform4uiv = (PFNGLUNIFORM4UIVPROC)gleIntGetProcAddress("glUniform4uiv");
	if(!__gleUniform4uiv) bIsLoaded = 0;
	__gleTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)gleIntGetProcAddress("glTexParameterIiv");
	if(!__gleTexParameterIiv) bIsLoaded = 0;
	__gleTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)gleIntGetProcAddress("glTexParameterIuiv");
	if(!__gleTexParameterIuiv) bIsLoaded = 0;
	__gleGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)gleIntGetProcAddress("glGetTexParameterIiv");
	if(!__gleGetTexParameterIiv) bIsLoaded = 0;
	__gleGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)gleIntGetProcAddress("glGetTexParameterIuiv");
	if(!__gleGetTexParameterIuiv) bIsLoaded = 0;
	__gleClearBufferiv = (PFNGLCLEARBUFFERIVPROC)gleIntGetProcAddress("glClearBufferiv");
	if(!__gleClearBufferiv) bIsLoaded = 0;
	__gleClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)gleIntGetProcAddress("glClearBufferuiv");
	if(!__gleClearBufferuiv) bIsLoaded = 0;
	__gleClearBufferfv = (PFNGLCLEARBUFFERFVPROC)gleIntGetProcAddress("glClearBufferfv");
	if(!__gleClearBufferfv) bIsLoaded = 0;
	__gleClearBufferfi = (PFNGLCLEARBUFFERFIPROC)gleIntGetProcAddress("glClearBufferfi");
	if(!__gleClearBufferfi) bIsLoaded = 0;
	__gleGetStringi = (PFNGLGETSTRINGIPROC)gleIntGetProcAddress("glGetStringi");
	if(!__gleGetStringi) bIsLoaded = 0;
	__gleIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)gleIntGetProcAddress("glIsRenderbuffer");
	if(!__gleIsRenderbuffer) bIsLoaded = 0;
	__gleBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)gleIntGetProcAddress("glBindRenderbuffer");
	if(!__gleBindRenderbuffer) bIsLoaded = 0;
	__gleDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)gleIntGetProcAddress("glDeleteRenderbuffers");
	if(!__gleDeleteRenderbuffers) bIsLoaded = 0;
	__gleGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)gleIntGetProcAddress("glGenRenderbuffers");
	if(!__gleGenRenderbuffers) bIsLoaded = 0;
	__gleRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)gleIntGetProcAddress("glRenderbufferStorage");
	if(!__gleRenderbufferStorage) bIsLoaded = 0;
	__gleGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)gleIntGetProcAddress("glGetRenderbufferParameteriv");
	if(!__gleGetRenderbufferParameteriv) bIsLoaded = 0;
	__gleIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)gleIntGetProcAddress("glIsFramebuffer");
	if(!__gleIsFramebuffer) bIsLoaded = 0;
	__gleBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)gleIntGetProcAddress("glBindFramebuffer");
	if(!__gleBindFramebuffer) bIsLoaded = 0;
	__gleDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)gleIntGetProcAddress("glDeleteFramebuffers");
	if(!__gleDeleteFramebuffers) bIsLoaded = 0;
	__gleGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)gleIntGetProcAddress("glGenFramebuffers");
	if(!__gleGenFramebuffers) bIsLoaded = 0;
	__gleCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)gleIntGetProcAddress("glCheckFramebufferStatus");
	if(!__gleCheckFramebufferStatus) bIsLoaded = 0;
	__gleFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)gleIntGetProcAddress("glFramebufferTexture1D");
	if(!__gleFramebufferTexture1D) bIsLoaded = 0;
	__gleFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)gleIntGetProcAddress("glFramebufferTexture2D");
	if(!__gleFramebufferTexture2D) bIsLoaded = 0;
	__gleFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)gleIntGetProcAddress("glFramebufferTexture3D");
	if(!__gleFramebufferTexture3D) bIsLoaded = 0;
	__gleFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)gleIntGetProcAddress("glFramebufferRenderbuffer");
	if(!__gleFramebufferRenderbuffer) bIsLoaded = 0;
	__gleGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)gleIntGetProcAddress("glGetFramebufferAttachmentParameteriv");
	if(!__gleGetFramebufferAttachmentParameteriv) bIsLoaded = 0;
	__gleGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)gleIntGetProcAddress("glGenerateMipmap");
	if(!__gleGenerateMipmap) bIsLoaded = 0;
	__gleBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)gleIntGetProcAddress("glBlitFramebuffer");
	if(!__gleBlitFramebuffer) bIsLoaded = 0;
	__gleRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)gleIntGetProcAddress("glRenderbufferStorageMultisample");
	if(!__gleRenderbufferStorageMultisample) bIsLoaded = 0;
	__gleFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)gleIntGetProcAddress("glFramebufferTextureLayer");
	if(!__gleFramebufferTextureLayer) bIsLoaded = 0;
	glext_ARB_framebuffer_object = 1;
	__gleMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)gleIntGetProcAddress("glMapBufferRange");
	if(!__gleMapBufferRange) bIsLoaded = 0;
	__gleFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)gleIntGetProcAddress("glFlushMappedBufferRange");
	if(!__gleFlushMappedBufferRange) bIsLoaded = 0;
	glext_ARB_map_buffer_range = 1;
	__gleBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)gleIntGetProcAddress("glBindVertexArray");
	if(!__gleBindVertexArray) bIsLoaded = 0;
	__gleDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)gleIntGetProcAddress("glDeleteVertexArrays");
	if(!__gleDeleteVertexArrays) bIsLoaded = 0;
	__gleGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)gleIntGetProcAddress("glGenVertexArrays");
	if(!__gleGenVertexArrays) bIsLoaded = 0;
	__gleIsVertexArray = (PFNGLISVERTEXARRAYPROC)gleIntGetProcAddress("glIsVertexArray");
	if(!__gleIsVertexArray) bIsLoaded = 0;
	glext_ARB_vertex_array_object = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_1_1_Base()
{
	int bIsLoaded = gleIntLoadCore_1_1_Version_3_1();
	__gleNewList = (PFNGLNEWLISTPROC)gleIntGetProcAddress("glNewList");
	if(!__gleNewList) bIsLoaded = 0;
	__gleEndList = (PFNGLENDLISTPROC)gleIntGetProcAddress("glEndList");
	if(!__gleEndList) bIsLoaded = 0;
	__gleCallList = (PFNGLCALLLISTPROC)gleIntGetProcAddress("glCallList");
	if(!__gleCallList) bIsLoaded = 0;
	__gleCallLists = (PFNGLCALLLISTSPROC)gleIntGetProcAddress("glCallLists");
	if(!__gleCallLists) bIsLoaded = 0;
	__gleDeleteLists = (PFNGLDELETELISTSPROC)gleIntGetProcAddress("glDeleteLists");
	if(!__gleDeleteLists) bIsLoaded = 0;
	__gleGenLists = (PFNGLGENLISTSPROC)gleIntGetProcAddress("glGenLists");
	if(!__gleGenLists) bIsLoaded = 0;
	__gleListBase = (PFNGLLISTBASEPROC)gleIntGetProcAddress("glListBase");
	if(!__gleListBase) bIsLoaded = 0;
	__gleBegin = (PFNGLBEGINPROC)gleIntGetProcAddress("glBegin");
	if(!__gleBegin) bIsLoaded = 0;
	__gleBitmap = (PFNGLBITMAPPROC)gleIntGetProcAddress("glBitmap");
	if(!__gleBitmap) bIsLoaded = 0;
	__gleColor3b = (PFNGLCOLOR3BPROC)gleIntGetProcAddress("glColor3b");
	if(!__gleColor3b) bIsLoaded = 0;
	__gleColor3bv = (PFNGLCOLOR3BVPROC)gleIntGetProcAddress("glColor3bv");
	if(!__gleColor3bv) bIsLoaded = 0;
	__gleColor3d = (PFNGLCOLOR3DPROC)gleIntGetProcAddress("glColor3d");
	if(!__gleColor3d) bIsLoaded = 0;
	__gleColor3dv = (PFNGLCOLOR3DVPROC)gleIntGetProcAddress("glColor3dv");
	if(!__gleColor3dv) bIsLoaded = 0;
	__gleColor3f = (PFNGLCOLOR3FPROC)gleIntGetProcAddress("glColor3f");
	if(!__gleColor3f) bIsLoaded = 0;
	__gleColor3fv = (PFNGLCOLOR3FVPROC)gleIntGetProcAddress("glColor3fv");
	if(!__gleColor3fv) bIsLoaded = 0;
	__gleColor3i = (PFNGLCOLOR3IPROC)gleIntGetProcAddress("glColor3i");
	if(!__gleColor3i) bIsLoaded = 0;
	__gleColor3iv = (PFNGLCOLOR3IVPROC)gleIntGetProcAddress("glColor3iv");
	if(!__gleColor3iv) bIsLoaded = 0;
	__gleColor3s = (PFNGLCOLOR3SPROC)gleIntGetProcAddress("glColor3s");
	if(!__gleColor3s) bIsLoaded = 0;
	__gleColor3sv = (PFNGLCOLOR3SVPROC)gleIntGetProcAddress("glColor3sv");
	if(!__gleColor3sv) bIsLoaded = 0;
	__gleColor3ub = (PFNGLCOLOR3UBPROC)gleIntGetProcAddress("glColor3ub");
	if(!__gleColor3ub) bIsLoaded = 0;
	__gleColor3ubv = (PFNGLCOLOR3UBVPROC)gleIntGetProcAddress("glColor3ubv");
	if(!__gleColor3ubv) bIsLoaded = 0;
	__gleColor3ui = (PFNGLCOLOR3UIPROC)gleIntGetProcAddress("glColor3ui");
	if(!__gleColor3ui) bIsLoaded = 0;
	__gleColor3uiv = (PFNGLCOLOR3UIVPROC)gleIntGetProcAddress("glColor3uiv");
	if(!__gleColor3uiv) bIsLoaded = 0;
	__gleColor3us = (PFNGLCOLOR3USPROC)gleIntGetProcAddress("glColor3us");
	if(!__gleColor3us) bIsLoaded = 0;
	__gleColor3usv = (PFNGLCOLOR3USVPROC)gleIntGetProcAddress("glColor3usv");
	if(!__gleColor3usv) bIsLoaded = 0;
	__gleColor4b = (PFNGLCOLOR4BPROC)gleIntGetProcAddress("glColor4b");
	if(!__gleColor4b) bIsLoaded = 0;
	__gleColor4bv = (PFNGLCOLOR4BVPROC)gleIntGetProcAddress("glColor4bv");
	if(!__gleColor4bv) bIsLoaded = 0;
	__gleColor4d = (PFNGLCOLOR4DPROC)gleIntGetProcAddress("glColor4d");
	if(!__gleColor4d) bIsLoaded = 0;
	__gleColor4dv = (PFNGLCOLOR4DVPROC)gleIntGetProcAddress("glColor4dv");
	if(!__gleColor4dv) bIsLoaded = 0;
	__gleColor4f = (PFNGLCOLOR4FPROC)gleIntGetProcAddress("glColor4f");
	if(!__gleColor4f) bIsLoaded = 0;
	__gleColor4fv = (PFNGLCOLOR4FVPROC)gleIntGetProcAddress("glColor4fv");
	if(!__gleColor4fv) bIsLoaded = 0;
	__gleColor4i = (PFNGLCOLOR4IPROC)gleIntGetProcAddress("glColor4i");
	if(!__gleColor4i) bIsLoaded = 0;
	__gleColor4iv = (PFNGLCOLOR4IVPROC)gleIntGetProcAddress("glColor4iv");
	if(!__gleColor4iv) bIsLoaded = 0;
	__gleColor4s = (PFNGLCOLOR4SPROC)gleIntGetProcAddress("glColor4s");
	if(!__gleColor4s) bIsLoaded = 0;
	__gleColor4sv = (PFNGLCOLOR4SVPROC)gleIntGetProcAddress("glColor4sv");
	if(!__gleColor4sv) bIsLoaded = 0;
	__gleColor4ub = (PFNGLCOLOR4UBPROC)gleIntGetProcAddress("glColor4ub");
	if(!__gleColor4ub) bIsLoaded = 0;
	__gleColor4ubv = (PFNGLCOLOR4UBVPROC)gleIntGetProcAddress("glColor4ubv");
	if(!__gleColor4ubv) bIsLoaded = 0;
	__gleColor4ui = (PFNGLCOLOR4UIPROC)gleIntGetProcAddress("glColor4ui");
	if(!__gleColor4ui) bIsLoaded = 0;
	__gleColor4uiv = (PFNGLCOLOR4UIVPROC)gleIntGetProcAddress("glColor4uiv");
	if(!__gleColor4uiv) bIsLoaded = 0;
	__gleColor4us = (PFNGLCOLOR4USPROC)gleIntGetProcAddress("glColor4us");
	if(!__gleColor4us) bIsLoaded = 0;
	__gleColor4usv = (PFNGLCOLOR4USVPROC)gleIntGetProcAddress("glColor4usv");
	if(!__gleColor4usv) bIsLoaded = 0;
	__gleEdgeFlag = (PFNGLEDGEFLAGPROC)gleIntGetProcAddress("glEdgeFlag");
	if(!__gleEdgeFlag) bIsLoaded = 0;
	__gleEdgeFlagv = (PFNGLEDGEFLAGVPROC)gleIntGetProcAddress("glEdgeFlagv");
	if(!__gleEdgeFlagv) bIsLoaded = 0;
	__gleEnd = (PFNGLENDPROC)gleIntGetProcAddress("glEnd");
	if(!__gleEnd) bIsLoaded = 0;
	__gleIndexd = (PFNGLINDEXDPROC)gleIntGetProcAddress("glIndexd");
	if(!__gleIndexd) bIsLoaded = 0;
	__gleIndexdv = (PFNGLINDEXDVPROC)gleIntGetProcAddress("glIndexdv");
	if(!__gleIndexdv) bIsLoaded = 0;
	__gleIndexf = (PFNGLINDEXFPROC)gleIntGetProcAddress("glIndexf");
	if(!__gleIndexf) bIsLoaded = 0;
	__gleIndexfv = (PFNGLINDEXFVPROC)gleIntGetProcAddress("glIndexfv");
	if(!__gleIndexfv) bIsLoaded = 0;
	__gleIndexi = (PFNGLINDEXIPROC)gleIntGetProcAddress("glIndexi");
	if(!__gleIndexi) bIsLoaded = 0;
	__gleIndexiv = (PFNGLINDEXIVPROC)gleIntGetProcAddress("glIndexiv");
	if(!__gleIndexiv) bIsLoaded = 0;
	__gleIndexs = (PFNGLINDEXSPROC)gleIntGetProcAddress("glIndexs");
	if(!__gleIndexs) bIsLoaded = 0;
	__gleIndexsv = (PFNGLINDEXSVPROC)gleIntGetProcAddress("glIndexsv");
	if(!__gleIndexsv) bIsLoaded = 0;
	__gleNormal3b = (PFNGLNORMAL3BPROC)gleIntGetProcAddress("glNormal3b");
	if(!__gleNormal3b) bIsLoaded = 0;
	__gleNormal3bv = (PFNGLNORMAL3BVPROC)gleIntGetProcAddress("glNormal3bv");
	if(!__gleNormal3bv) bIsLoaded = 0;
	__gleNormal3d = (PFNGLNORMAL3DPROC)gleIntGetProcAddress("glNormal3d");
	if(!__gleNormal3d) bIsLoaded = 0;
	__gleNormal3dv = (PFNGLNORMAL3DVPROC)gleIntGetProcAddress("glNormal3dv");
	if(!__gleNormal3dv) bIsLoaded = 0;
	__gleNormal3f = (PFNGLNORMAL3FPROC)gleIntGetProcAddress("glNormal3f");
	if(!__gleNormal3f) bIsLoaded = 0;
	__gleNormal3fv = (PFNGLNORMAL3FVPROC)gleIntGetProcAddress("glNormal3fv");
	if(!__gleNormal3fv) bIsLoaded = 0;
	__gleNormal3i = (PFNGLNORMAL3IPROC)gleIntGetProcAddress("glNormal3i");
	if(!__gleNormal3i) bIsLoaded = 0;
	__gleNormal3iv = (PFNGLNORMAL3IVPROC)gleIntGetProcAddress("glNormal3iv");
	if(!__gleNormal3iv) bIsLoaded = 0;
	__gleNormal3s = (PFNGLNORMAL3SPROC)gleIntGetProcAddress("glNormal3s");
	if(!__gleNormal3s) bIsLoaded = 0;
	__gleNormal3sv = (PFNGLNORMAL3SVPROC)gleIntGetProcAddress("glNormal3sv");
	if(!__gleNormal3sv) bIsLoaded = 0;
	__gleRasterPos2d = (PFNGLRASTERPOS2DPROC)gleIntGetProcAddress("glRasterPos2d");
	if(!__gleRasterPos2d) bIsLoaded = 0;
	__gleRasterPos2dv = (PFNGLRASTERPOS2DVPROC)gleIntGetProcAddress("glRasterPos2dv");
	if(!__gleRasterPos2dv) bIsLoaded = 0;
	__gleRasterPos2f = (PFNGLRASTERPOS2FPROC)gleIntGetProcAddress("glRasterPos2f");
	if(!__gleRasterPos2f) bIsLoaded = 0;
	__gleRasterPos2fv = (PFNGLRASTERPOS2FVPROC)gleIntGetProcAddress("glRasterPos2fv");
	if(!__gleRasterPos2fv) bIsLoaded = 0;
	__gleRasterPos2i = (PFNGLRASTERPOS2IPROC)gleIntGetProcAddress("glRasterPos2i");
	if(!__gleRasterPos2i) bIsLoaded = 0;
	__gleRasterPos2iv = (PFNGLRASTERPOS2IVPROC)gleIntGetProcAddress("glRasterPos2iv");
	if(!__gleRasterPos2iv) bIsLoaded = 0;
	__gleRasterPos2s = (PFNGLRASTERPOS2SPROC)gleIntGetProcAddress("glRasterPos2s");
	if(!__gleRasterPos2s) bIsLoaded = 0;
	__gleRasterPos2sv = (PFNGLRASTERPOS2SVPROC)gleIntGetProcAddress("glRasterPos2sv");
	if(!__gleRasterPos2sv) bIsLoaded = 0;
	__gleRasterPos3d = (PFNGLRASTERPOS3DPROC)gleIntGetProcAddress("glRasterPos3d");
	if(!__gleRasterPos3d) bIsLoaded = 0;
	__gleRasterPos3dv = (PFNGLRASTERPOS3DVPROC)gleIntGetProcAddress("glRasterPos3dv");
	if(!__gleRasterPos3dv) bIsLoaded = 0;
	__gleRasterPos3f = (PFNGLRASTERPOS3FPROC)gleIntGetProcAddress("glRasterPos3f");
	if(!__gleRasterPos3f) bIsLoaded = 0;
	__gleRasterPos3fv = (PFNGLRASTERPOS3FVPROC)gleIntGetProcAddress("glRasterPos3fv");
	if(!__gleRasterPos3fv) bIsLoaded = 0;
	__gleRasterPos3i = (PFNGLRASTERPOS3IPROC)gleIntGetProcAddress("glRasterPos3i");
	if(!__gleRasterPos3i) bIsLoaded = 0;
	__gleRasterPos3iv = (PFNGLRASTERPOS3IVPROC)gleIntGetProcAddress("glRasterPos3iv");
	if(!__gleRasterPos3iv) bIsLoaded = 0;
	__gleRasterPos3s = (PFNGLRASTERPOS3SPROC)gleIntGetProcAddress("glRasterPos3s");
	if(!__gleRasterPos3s) bIsLoaded = 0;
	__gleRasterPos3sv = (PFNGLRASTERPOS3SVPROC)gleIntGetProcAddress("glRasterPos3sv");
	if(!__gleRasterPos3sv) bIsLoaded = 0;
	__gleRasterPos4d = (PFNGLRASTERPOS4DPROC)gleIntGetProcAddress("glRasterPos4d");
	if(!__gleRasterPos4d) bIsLoaded = 0;
	__gleRasterPos4dv = (PFNGLRASTERPOS4DVPROC)gleIntGetProcAddress("glRasterPos4dv");
	if(!__gleRasterPos4dv) bIsLoaded = 0;
	__gleRasterPos4f = (PFNGLRASTERPOS4FPROC)gleIntGetProcAddress("glRasterPos4f");
	if(!__gleRasterPos4f) bIsLoaded = 0;
	__gleRasterPos4fv = (PFNGLRASTERPOS4FVPROC)gleIntGetProcAddress("glRasterPos4fv");
	if(!__gleRasterPos4fv) bIsLoaded = 0;
	__gleRasterPos4i = (PFNGLRASTERPOS4IPROC)gleIntGetProcAddress("glRasterPos4i");
	if(!__gleRasterPos4i) bIsLoaded = 0;
	__gleRasterPos4iv = (PFNGLRASTERPOS4IVPROC)gleIntGetProcAddress("glRasterPos4iv");
	if(!__gleRasterPos4iv) bIsLoaded = 0;
	__gleRasterPos4s = (PFNGLRASTERPOS4SPROC)gleIntGetProcAddress("glRasterPos4s");
	if(!__gleRasterPos4s) bIsLoaded = 0;
	__gleRasterPos4sv = (PFNGLRASTERPOS4SVPROC)gleIntGetProcAddress("glRasterPos4sv");
	if(!__gleRasterPos4sv) bIsLoaded = 0;
	__gleRectd = (PFNGLRECTDPROC)gleIntGetProcAddress("glRectd");
	if(!__gleRectd) bIsLoaded = 0;
	__gleRectdv = (PFNGLRECTDVPROC)gleIntGetProcAddress("glRectdv");
	if(!__gleRectdv) bIsLoaded = 0;
	__gleRectf = (PFNGLRECTFPROC)gleIntGetProcAddress("glRectf");
	if(!__gleRectf) bIsLoaded = 0;
	__gleRectfv = (PFNGLRECTFVPROC)gleIntGetProcAddress("glRectfv");
	if(!__gleRectfv) bIsLoaded = 0;
	__gleRecti = (PFNGLRECTIPROC)gleIntGetProcAddress("glRecti");
	if(!__gleRecti) bIsLoaded = 0;
	__gleRectiv = (PFNGLRECTIVPROC)gleIntGetProcAddress("glRectiv");
	if(!__gleRectiv) bIsLoaded = 0;
	__gleRects = (PFNGLRECTSPROC)gleIntGetProcAddress("glRects");
	if(!__gleRects) bIsLoaded = 0;
	__gleRectsv = (PFNGLRECTSVPROC)gleIntGetProcAddress("glRectsv");
	if(!__gleRectsv) bIsLoaded = 0;
	__gleTexCoord1d = (PFNGLTEXCOORD1DPROC)gleIntGetProcAddress("glTexCoord1d");
	if(!__gleTexCoord1d) bIsLoaded = 0;
	__gleTexCoord1dv = (PFNGLTEXCOORD1DVPROC)gleIntGetProcAddress("glTexCoord1dv");
	if(!__gleTexCoord1dv) bIsLoaded = 0;
	__gleTexCoord1f = (PFNGLTEXCOORD1FPROC)gleIntGetProcAddress("glTexCoord1f");
	if(!__gleTexCoord1f) bIsLoaded = 0;
	__gleTexCoord1fv = (PFNGLTEXCOORD1FVPROC)gleIntGetProcAddress("glTexCoord1fv");
	if(!__gleTexCoord1fv) bIsLoaded = 0;
	__gleTexCoord1i = (PFNGLTEXCOORD1IPROC)gleIntGetProcAddress("glTexCoord1i");
	if(!__gleTexCoord1i) bIsLoaded = 0;
	__gleTexCoord1iv = (PFNGLTEXCOORD1IVPROC)gleIntGetProcAddress("glTexCoord1iv");
	if(!__gleTexCoord1iv) bIsLoaded = 0;
	__gleTexCoord1s = (PFNGLTEXCOORD1SPROC)gleIntGetProcAddress("glTexCoord1s");
	if(!__gleTexCoord1s) bIsLoaded = 0;
	__gleTexCoord1sv = (PFNGLTEXCOORD1SVPROC)gleIntGetProcAddress("glTexCoord1sv");
	if(!__gleTexCoord1sv) bIsLoaded = 0;
	__gleTexCoord2d = (PFNGLTEXCOORD2DPROC)gleIntGetProcAddress("glTexCoord2d");
	if(!__gleTexCoord2d) bIsLoaded = 0;
	__gleTexCoord2dv = (PFNGLTEXCOORD2DVPROC)gleIntGetProcAddress("glTexCoord2dv");
	if(!__gleTexCoord2dv) bIsLoaded = 0;
	__gleTexCoord2f = (PFNGLTEXCOORD2FPROC)gleIntGetProcAddress("glTexCoord2f");
	if(!__gleTexCoord2f) bIsLoaded = 0;
	__gleTexCoord2fv = (PFNGLTEXCOORD2FVPROC)gleIntGetProcAddress("glTexCoord2fv");
	if(!__gleTexCoord2fv) bIsLoaded = 0;
	__gleTexCoord2i = (PFNGLTEXCOORD2IPROC)gleIntGetProcAddress("glTexCoord2i");
	if(!__gleTexCoord2i) bIsLoaded = 0;
	__gleTexCoord2iv = (PFNGLTEXCOORD2IVPROC)gleIntGetProcAddress("glTexCoord2iv");
	if(!__gleTexCoord2iv) bIsLoaded = 0;
	__gleTexCoord2s = (PFNGLTEXCOORD2SPROC)gleIntGetProcAddress("glTexCoord2s");
	if(!__gleTexCoord2s) bIsLoaded = 0;
	__gleTexCoord2sv = (PFNGLTEXCOORD2SVPROC)gleIntGetProcAddress("glTexCoord2sv");
	if(!__gleTexCoord2sv) bIsLoaded = 0;
	__gleTexCoord3d = (PFNGLTEXCOORD3DPROC)gleIntGetProcAddress("glTexCoord3d");
	if(!__gleTexCoord3d) bIsLoaded = 0;
	__gleTexCoord3dv = (PFNGLTEXCOORD3DVPROC)gleIntGetProcAddress("glTexCoord3dv");
	if(!__gleTexCoord3dv) bIsLoaded = 0;
	__gleTexCoord3f = (PFNGLTEXCOORD3FPROC)gleIntGetProcAddress("glTexCoord3f");
	if(!__gleTexCoord3f) bIsLoaded = 0;
	__gleTexCoord3fv = (PFNGLTEXCOORD3FVPROC)gleIntGetProcAddress("glTexCoord3fv");
	if(!__gleTexCoord3fv) bIsLoaded = 0;
	__gleTexCoord3i = (PFNGLTEXCOORD3IPROC)gleIntGetProcAddress("glTexCoord3i");
	if(!__gleTexCoord3i) bIsLoaded = 0;
	__gleTexCoord3iv = (PFNGLTEXCOORD3IVPROC)gleIntGetProcAddress("glTexCoord3iv");
	if(!__gleTexCoord3iv) bIsLoaded = 0;
	__gleTexCoord3s = (PFNGLTEXCOORD3SPROC)gleIntGetProcAddress("glTexCoord3s");
	if(!__gleTexCoord3s) bIsLoaded = 0;
	__gleTexCoord3sv = (PFNGLTEXCOORD3SVPROC)gleIntGetProcAddress("glTexCoord3sv");
	if(!__gleTexCoord3sv) bIsLoaded = 0;
	__gleTexCoord4d = (PFNGLTEXCOORD4DPROC)gleIntGetProcAddress("glTexCoord4d");
	if(!__gleTexCoord4d) bIsLoaded = 0;
	__gleTexCoord4dv = (PFNGLTEXCOORD4DVPROC)gleIntGetProcAddress("glTexCoord4dv");
	if(!__gleTexCoord4dv) bIsLoaded = 0;
	__gleTexCoord4f = (PFNGLTEXCOORD4FPROC)gleIntGetProcAddress("glTexCoord4f");
	if(!__gleTexCoord4f) bIsLoaded = 0;
	__gleTexCoord4fv = (PFNGLTEXCOORD4FVPROC)gleIntGetProcAddress("glTexCoord4fv");
	if(!__gleTexCoord4fv) bIsLoaded = 0;
	__gleTexCoord4i = (PFNGLTEXCOORD4IPROC)gleIntGetProcAddress("glTexCoord4i");
	if(!__gleTexCoord4i) bIsLoaded = 0;
	__gleTexCoord4iv = (PFNGLTEXCOORD4IVPROC)gleIntGetProcAddress("glTexCoord4iv");
	if(!__gleTexCoord4iv) bIsLoaded = 0;
	__gleTexCoord4s = (PFNGLTEXCOORD4SPROC)gleIntGetProcAddress("glTexCoord4s");
	if(!__gleTexCoord4s) bIsLoaded = 0;
	__gleTexCoord4sv = (PFNGLTEXCOORD4SVPROC)gleIntGetProcAddress("glTexCoord4sv");
	if(!__gleTexCoord4sv) bIsLoaded = 0;
	__gleVertex2d = (PFNGLVERTEX2DPROC)gleIntGetProcAddress("glVertex2d");
	if(!__gleVertex2d) bIsLoaded = 0;
	__gleVertex2dv = (PFNGLVERTEX2DVPROC)gleIntGetProcAddress("glVertex2dv");
	if(!__gleVertex2dv) bIsLoaded = 0;
	__gleVertex2f = (PFNGLVERTEX2FPROC)gleIntGetProcAddress("glVertex2f");
	if(!__gleVertex2f) bIsLoaded = 0;
	__gleVertex2fv = (PFNGLVERTEX2FVPROC)gleIntGetProcAddress("glVertex2fv");
	if(!__gleVertex2fv) bIsLoaded = 0;
	__gleVertex2i = (PFNGLVERTEX2IPROC)gleIntGetProcAddress("glVertex2i");
	if(!__gleVertex2i) bIsLoaded = 0;
	__gleVertex2iv = (PFNGLVERTEX2IVPROC)gleIntGetProcAddress("glVertex2iv");
	if(!__gleVertex2iv) bIsLoaded = 0;
	__gleVertex2s = (PFNGLVERTEX2SPROC)gleIntGetProcAddress("glVertex2s");
	if(!__gleVertex2s) bIsLoaded = 0;
	__gleVertex2sv = (PFNGLVERTEX2SVPROC)gleIntGetProcAddress("glVertex2sv");
	if(!__gleVertex2sv) bIsLoaded = 0;
	__gleVertex3d = (PFNGLVERTEX3DPROC)gleIntGetProcAddress("glVertex3d");
	if(!__gleVertex3d) bIsLoaded = 0;
	__gleVertex3dv = (PFNGLVERTEX3DVPROC)gleIntGetProcAddress("glVertex3dv");
	if(!__gleVertex3dv) bIsLoaded = 0;
	__gleVertex3f = (PFNGLVERTEX3FPROC)gleIntGetProcAddress("glVertex3f");
	if(!__gleVertex3f) bIsLoaded = 0;
	__gleVertex3fv = (PFNGLVERTEX3FVPROC)gleIntGetProcAddress("glVertex3fv");
	if(!__gleVertex3fv) bIsLoaded = 0;
	__gleVertex3i = (PFNGLVERTEX3IPROC)gleIntGetProcAddress("glVertex3i");
	if(!__gleVertex3i) bIsLoaded = 0;
	__gleVertex3iv = (PFNGLVERTEX3IVPROC)gleIntGetProcAddress("glVertex3iv");
	if(!__gleVertex3iv) bIsLoaded = 0;
	__gleVertex3s = (PFNGLVERTEX3SPROC)gleIntGetProcAddress("glVertex3s");
	if(!__gleVertex3s) bIsLoaded = 0;
	__gleVertex3sv = (PFNGLVERTEX3SVPROC)gleIntGetProcAddress("glVertex3sv");
	if(!__gleVertex3sv) bIsLoaded = 0;
	__gleVertex4d = (PFNGLVERTEX4DPROC)gleIntGetProcAddress("glVertex4d");
	if(!__gleVertex4d) bIsLoaded = 0;
	__gleVertex4dv = (PFNGLVERTEX4DVPROC)gleIntGetProcAddress("glVertex4dv");
	if(!__gleVertex4dv) bIsLoaded = 0;
	__gleVertex4f = (PFNGLVERTEX4FPROC)gleIntGetProcAddress("glVertex4f");
	if(!__gleVertex4f) bIsLoaded = 0;
	__gleVertex4fv = (PFNGLVERTEX4FVPROC)gleIntGetProcAddress("glVertex4fv");
	if(!__gleVertex4fv) bIsLoaded = 0;
	__gleVertex4i = (PFNGLVERTEX4IPROC)gleIntGetProcAddress("glVertex4i");
	if(!__gleVertex4i) bIsLoaded = 0;
	__gleVertex4iv = (PFNGLVERTEX4IVPROC)gleIntGetProcAddress("glVertex4iv");
	if(!__gleVertex4iv) bIsLoaded = 0;
	__gleVertex4s = (PFNGLVERTEX4SPROC)gleIntGetProcAddress("glVertex4s");
	if(!__gleVertex4s) bIsLoaded = 0;
	__gleVertex4sv = (PFNGLVERTEX4SVPROC)gleIntGetProcAddress("glVertex4sv");
	if(!__gleVertex4sv) bIsLoaded = 0;
	__gleClipPlane = (PFNGLCLIPPLANEPROC)gleIntGetProcAddress("glClipPlane");
	if(!__gleClipPlane) bIsLoaded = 0;
	__gleColorMaterial = (PFNGLCOLORMATERIALPROC)gleIntGetProcAddress("glColorMaterial");
	if(!__gleColorMaterial) bIsLoaded = 0;
	__gleFogf = (PFNGLFOGFPROC)gleIntGetProcAddress("glFogf");
	if(!__gleFogf) bIsLoaded = 0;
	__gleFogfv = (PFNGLFOGFVPROC)gleIntGetProcAddress("glFogfv");
	if(!__gleFogfv) bIsLoaded = 0;
	__gleFogi = (PFNGLFOGIPROC)gleIntGetProcAddress("glFogi");
	if(!__gleFogi) bIsLoaded = 0;
	__gleFogiv = (PFNGLFOGIVPROC)gleIntGetProcAddress("glFogiv");
	if(!__gleFogiv) bIsLoaded = 0;
	__gleLightf = (PFNGLLIGHTFPROC)gleIntGetProcAddress("glLightf");
	if(!__gleLightf) bIsLoaded = 0;
	__gleLightfv = (PFNGLLIGHTFVPROC)gleIntGetProcAddress("glLightfv");
	if(!__gleLightfv) bIsLoaded = 0;
	__gleLighti = (PFNGLLIGHTIPROC)gleIntGetProcAddress("glLighti");
	if(!__gleLighti) bIsLoaded = 0;
	__gleLightiv = (PFNGLLIGHTIVPROC)gleIntGetProcAddress("glLightiv");
	if(!__gleLightiv) bIsLoaded = 0;
	__gleLightModelf = (PFNGLLIGHTMODELFPROC)gleIntGetProcAddress("glLightModelf");
	if(!__gleLightModelf) bIsLoaded = 0;
	__gleLightModelfv = (PFNGLLIGHTMODELFVPROC)gleIntGetProcAddress("glLightModelfv");
	if(!__gleLightModelfv) bIsLoaded = 0;
	__gleLightModeli = (PFNGLLIGHTMODELIPROC)gleIntGetProcAddress("glLightModeli");
	if(!__gleLightModeli) bIsLoaded = 0;
	__gleLightModeliv = (PFNGLLIGHTMODELIVPROC)gleIntGetProcAddress("glLightModeliv");
	if(!__gleLightModeliv) bIsLoaded = 0;
	__gleLineStipple = (PFNGLLINESTIPPLEPROC)gleIntGetProcAddress("glLineStipple");
	if(!__gleLineStipple) bIsLoaded = 0;
	__gleMaterialf = (PFNGLMATERIALFPROC)gleIntGetProcAddress("glMaterialf");
	if(!__gleMaterialf) bIsLoaded = 0;
	__gleMaterialfv = (PFNGLMATERIALFVPROC)gleIntGetProcAddress("glMaterialfv");
	if(!__gleMaterialfv) bIsLoaded = 0;
	__gleMateriali = (PFNGLMATERIALIPROC)gleIntGetProcAddress("glMateriali");
	if(!__gleMateriali) bIsLoaded = 0;
	__gleMaterialiv = (PFNGLMATERIALIVPROC)gleIntGetProcAddress("glMaterialiv");
	if(!__gleMaterialiv) bIsLoaded = 0;
	__glePolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)gleIntGetProcAddress("glPolygonStipple");
	if(!__glePolygonStipple) bIsLoaded = 0;
	__gleShadeModel = (PFNGLSHADEMODELPROC)gleIntGetProcAddress("glShadeModel");
	if(!__gleShadeModel) bIsLoaded = 0;
	__gleTexEnvf = (PFNGLTEXENVFPROC)gleIntGetProcAddress("glTexEnvf");
	if(!__gleTexEnvf) bIsLoaded = 0;
	__gleTexEnvfv = (PFNGLTEXENVFVPROC)gleIntGetProcAddress("glTexEnvfv");
	if(!__gleTexEnvfv) bIsLoaded = 0;
	__gleTexEnvi = (PFNGLTEXENVIPROC)gleIntGetProcAddress("glTexEnvi");
	if(!__gleTexEnvi) bIsLoaded = 0;
	__gleTexEnviv = (PFNGLTEXENVIVPROC)gleIntGetProcAddress("glTexEnviv");
	if(!__gleTexEnviv) bIsLoaded = 0;
	__gleTexGend = (PFNGLTEXGENDPROC)gleIntGetProcAddress("glTexGend");
	if(!__gleTexGend) bIsLoaded = 0;
	__gleTexGendv = (PFNGLTEXGENDVPROC)gleIntGetProcAddress("glTexGendv");
	if(!__gleTexGendv) bIsLoaded = 0;
	__gleTexGenf = (PFNGLTEXGENFPROC)gleIntGetProcAddress("glTexGenf");
	if(!__gleTexGenf) bIsLoaded = 0;
	__gleTexGenfv = (PFNGLTEXGENFVPROC)gleIntGetProcAddress("glTexGenfv");
	if(!__gleTexGenfv) bIsLoaded = 0;
	__gleTexGeni = (PFNGLTEXGENIPROC)gleIntGetProcAddress("glTexGeni");
	if(!__gleTexGeni) bIsLoaded = 0;
	__gleTexGeniv = (PFNGLTEXGENIVPROC)gleIntGetProcAddress("glTexGeniv");
	if(!__gleTexGeniv) bIsLoaded = 0;
	__gleFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)gleIntGetProcAddress("glFeedbackBuffer");
	if(!__gleFeedbackBuffer) bIsLoaded = 0;
	__gleSelectBuffer = (PFNGLSELECTBUFFERPROC)gleIntGetProcAddress("glSelectBuffer");
	if(!__gleSelectBuffer) bIsLoaded = 0;
	__gleRenderMode = (PFNGLRENDERMODEPROC)gleIntGetProcAddress("glRenderMode");
	if(!__gleRenderMode) bIsLoaded = 0;
	__gleInitNames = (PFNGLINITNAMESPROC)gleIntGetProcAddress("glInitNames");
	if(!__gleInitNames) bIsLoaded = 0;
	__gleLoadName = (PFNGLLOADNAMEPROC)gleIntGetProcAddress("glLoadName");
	if(!__gleLoadName) bIsLoaded = 0;
	__glePassThrough = (PFNGLPASSTHROUGHPROC)gleIntGetProcAddress("glPassThrough");
	if(!__glePassThrough) bIsLoaded = 0;
	__glePopName = (PFNGLPOPNAMEPROC)gleIntGetProcAddress("glPopName");
	if(!__glePopName) bIsLoaded = 0;
	__glePushName = (PFNGLPUSHNAMEPROC)gleIntGetProcAddress("glPushName");
	if(!__glePushName) bIsLoaded = 0;
	__gleClearAccum = (PFNGLCLEARACCUMPROC)gleIntGetProcAddress("glClearAccum");
	if(!__gleClearAccum) bIsLoaded = 0;
	__gleClearIndex = (PFNGLCLEARINDEXPROC)gleIntGetProcAddress("glClearIndex");
	if(!__gleClearIndex) bIsLoaded = 0;
	__gleIndexMask = (PFNGLINDEXMASKPROC)gleIntGetProcAddress("glIndexMask");
	if(!__gleIndexMask) bIsLoaded = 0;
	__gleAccum = (PFNGLACCUMPROC)gleIntGetProcAddress("glAccum");
	if(!__gleAccum) bIsLoaded = 0;
	__glePopAttrib = (PFNGLPOPATTRIBPROC)gleIntGetProcAddress("glPopAttrib");
	if(!__glePopAttrib) bIsLoaded = 0;
	__glePushAttrib = (PFNGLPUSHATTRIBPROC)gleIntGetProcAddress("glPushAttrib");
	if(!__glePushAttrib) bIsLoaded = 0;
	__gleMap1d = (PFNGLMAP1DPROC)gleIntGetProcAddress("glMap1d");
	if(!__gleMap1d) bIsLoaded = 0;
	__gleMap1f = (PFNGLMAP1FPROC)gleIntGetProcAddress("glMap1f");
	if(!__gleMap1f) bIsLoaded = 0;
	__gleMap2d = (PFNGLMAP2DPROC)gleIntGetProcAddress("glMap2d");
	if(!__gleMap2d) bIsLoaded = 0;
	__gleMap2f = (PFNGLMAP2FPROC)gleIntGetProcAddress("glMap2f");
	if(!__gleMap2f) bIsLoaded = 0;
	__gleMapGrid1d = (PFNGLMAPGRID1DPROC)gleIntGetProcAddress("glMapGrid1d");
	if(!__gleMapGrid1d) bIsLoaded = 0;
	__gleMapGrid1f = (PFNGLMAPGRID1FPROC)gleIntGetProcAddress("glMapGrid1f");
	if(!__gleMapGrid1f) bIsLoaded = 0;
	__gleMapGrid2d = (PFNGLMAPGRID2DPROC)gleIntGetProcAddress("glMapGrid2d");
	if(!__gleMapGrid2d) bIsLoaded = 0;
	__gleMapGrid2f = (PFNGLMAPGRID2FPROC)gleIntGetProcAddress("glMapGrid2f");
	if(!__gleMapGrid2f) bIsLoaded = 0;
	__gleEvalCoord1d = (PFNGLEVALCOORD1DPROC)gleIntGetProcAddress("glEvalCoord1d");
	if(!__gleEvalCoord1d) bIsLoaded = 0;
	__gleEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)gleIntGetProcAddress("glEvalCoord1dv");
	if(!__gleEvalCoord1dv) bIsLoaded = 0;
	__gleEvalCoord1f = (PFNGLEVALCOORD1FPROC)gleIntGetProcAddress("glEvalCoord1f");
	if(!__gleEvalCoord1f) bIsLoaded = 0;
	__gleEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)gleIntGetProcAddress("glEvalCoord1fv");
	if(!__gleEvalCoord1fv) bIsLoaded = 0;
	__gleEvalCoord2d = (PFNGLEVALCOORD2DPROC)gleIntGetProcAddress("glEvalCoord2d");
	if(!__gleEvalCoord2d) bIsLoaded = 0;
	__gleEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)gleIntGetProcAddress("glEvalCoord2dv");
	if(!__gleEvalCoord2dv) bIsLoaded = 0;
	__gleEvalCoord2f = (PFNGLEVALCOORD2FPROC)gleIntGetProcAddress("glEvalCoord2f");
	if(!__gleEvalCoord2f) bIsLoaded = 0;
	__gleEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)gleIntGetProcAddress("glEvalCoord2fv");
	if(!__gleEvalCoord2fv) bIsLoaded = 0;
	__gleEvalMesh1 = (PFNGLEVALMESH1PROC)gleIntGetProcAddress("glEvalMesh1");
	if(!__gleEvalMesh1) bIsLoaded = 0;
	__gleEvalPoint1 = (PFNGLEVALPOINT1PROC)gleIntGetProcAddress("glEvalPoint1");
	if(!__gleEvalPoint1) bIsLoaded = 0;
	__gleEvalMesh2 = (PFNGLEVALMESH2PROC)gleIntGetProcAddress("glEvalMesh2");
	if(!__gleEvalMesh2) bIsLoaded = 0;
	__gleEvalPoint2 = (PFNGLEVALPOINT2PROC)gleIntGetProcAddress("glEvalPoint2");
	if(!__gleEvalPoint2) bIsLoaded = 0;
	__gleAlphaFunc = (PFNGLALPHAFUNCPROC)gleIntGetProcAddress("glAlphaFunc");
	if(!__gleAlphaFunc) bIsLoaded = 0;
	__glePixelZoom = (PFNGLPIXELZOOMPROC)gleIntGetProcAddress("glPixelZoom");
	if(!__glePixelZoom) bIsLoaded = 0;
	__glePixelTransferf = (PFNGLPIXELTRANSFERFPROC)gleIntGetProcAddress("glPixelTransferf");
	if(!__glePixelTransferf) bIsLoaded = 0;
	__glePixelTransferi = (PFNGLPIXELTRANSFERIPROC)gleIntGetProcAddress("glPixelTransferi");
	if(!__glePixelTransferi) bIsLoaded = 0;
	__glePixelMapfv = (PFNGLPIXELMAPFVPROC)gleIntGetProcAddress("glPixelMapfv");
	if(!__glePixelMapfv) bIsLoaded = 0;
	__glePixelMapuiv = (PFNGLPIXELMAPUIVPROC)gleIntGetProcAddress("glPixelMapuiv");
	if(!__glePixelMapuiv) bIsLoaded = 0;
	__glePixelMapusv = (PFNGLPIXELMAPUSVPROC)gleIntGetProcAddress("glPixelMapusv");
	if(!__glePixelMapusv) bIsLoaded = 0;
	__gleCopyPixels = (PFNGLCOPYPIXELSPROC)gleIntGetProcAddress("glCopyPixels");
	if(!__gleCopyPixels) bIsLoaded = 0;
	__gleDrawPixels = (PFNGLDRAWPIXELSPROC)gleIntGetProcAddress("glDrawPixels");
	if(!__gleDrawPixels) bIsLoaded = 0;
	__gleGetClipPlane = (PFNGLGETCLIPPLANEPROC)gleIntGetProcAddress("glGetClipPlane");
	if(!__gleGetClipPlane) bIsLoaded = 0;
	__gleGetLightfv = (PFNGLGETLIGHTFVPROC)gleIntGetProcAddress("glGetLightfv");
	if(!__gleGetLightfv) bIsLoaded = 0;
	__gleGetLightiv = (PFNGLGETLIGHTIVPROC)gleIntGetProcAddress("glGetLightiv");
	if(!__gleGetLightiv) bIsLoaded = 0;
	__gleGetMapdv = (PFNGLGETMAPDVPROC)gleIntGetProcAddress("glGetMapdv");
	if(!__gleGetMapdv) bIsLoaded = 0;
	__gleGetMapfv = (PFNGLGETMAPFVPROC)gleIntGetProcAddress("glGetMapfv");
	if(!__gleGetMapfv) bIsLoaded = 0;
	__gleGetMapiv = (PFNGLGETMAPIVPROC)gleIntGetProcAddress("glGetMapiv");
	if(!__gleGetMapiv) bIsLoaded = 0;
	__gleGetMaterialfv = (PFNGLGETMATERIALFVPROC)gleIntGetProcAddress("glGetMaterialfv");
	if(!__gleGetMaterialfv) bIsLoaded = 0;
	__gleGetMaterialiv = (PFNGLGETMATERIALIVPROC)gleIntGetProcAddress("glGetMaterialiv");
	if(!__gleGetMaterialiv) bIsLoaded = 0;
	__gleGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)gleIntGetProcAddress("glGetPixelMapfv");
	if(!__gleGetPixelMapfv) bIsLoaded = 0;
	__gleGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)gleIntGetProcAddress("glGetPixelMapuiv");
	if(!__gleGetPixelMapuiv) bIsLoaded = 0;
	__gleGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)gleIntGetProcAddress("glGetPixelMapusv");
	if(!__gleGetPixelMapusv) bIsLoaded = 0;
	__gleGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)gleIntGetProcAddress("glGetPolygonStipple");
	if(!__gleGetPolygonStipple) bIsLoaded = 0;
	__gleGetTexEnvfv = (PFNGLGETTEXENVFVPROC)gleIntGetProcAddress("glGetTexEnvfv");
	if(!__gleGetTexEnvfv) bIsLoaded = 0;
	__gleGetTexEnviv = (PFNGLGETTEXENVIVPROC)gleIntGetProcAddress("glGetTexEnviv");
	if(!__gleGetTexEnviv) bIsLoaded = 0;
	__gleGetTexGendv = (PFNGLGETTEXGENDVPROC)gleIntGetProcAddress("glGetTexGendv");
	if(!__gleGetTexGendv) bIsLoaded = 0;
	__gleGetTexGenfv = (PFNGLGETTEXGENFVPROC)gleIntGetProcAddress("glGetTexGenfv");
	if(!__gleGetTexGenfv) bIsLoaded = 0;
	__gleGetTexGeniv = (PFNGLGETTEXGENIVPROC)gleIntGetProcAddress("glGetTexGeniv");
	if(!__gleGetTexGeniv) bIsLoaded = 0;
	__gleIsList = (PFNGLISLISTPROC)gleIntGetProcAddress("glIsList");
	if(!__gleIsList) bIsLoaded = 0;
	__gleFrustum = (PFNGLFRUSTUMPROC)gleIntGetProcAddress("glFrustum");
	if(!__gleFrustum) bIsLoaded = 0;
	__gleLoadIdentity = (PFNGLLOADIDENTITYPROC)gleIntGetProcAddress("glLoadIdentity");
	if(!__gleLoadIdentity) bIsLoaded = 0;
	__gleLoadMatrixf = (PFNGLLOADMATRIXFPROC)gleIntGetProcAddress("glLoadMatrixf");
	if(!__gleLoadMatrixf) bIsLoaded = 0;
	__gleLoadMatrixd = (PFNGLLOADMATRIXDPROC)gleIntGetProcAddress("glLoadMatrixd");
	if(!__gleLoadMatrixd) bIsLoaded = 0;
	__gleMatrixMode = (PFNGLMATRIXMODEPROC)gleIntGetProcAddress("glMatrixMode");
	if(!__gleMatrixMode) bIsLoaded = 0;
	__gleMultMatrixf = (PFNGLMULTMATRIXFPROC)gleIntGetProcAddress("glMultMatrixf");
	if(!__gleMultMatrixf) bIsLoaded = 0;
	__gleMultMatrixd = (PFNGLMULTMATRIXDPROC)gleIntGetProcAddress("glMultMatrixd");
	if(!__gleMultMatrixd) bIsLoaded = 0;
	__gleOrtho = (PFNGLORTHOPROC)gleIntGetProcAddress("glOrtho");
	if(!__gleOrtho) bIsLoaded = 0;
	__glePopMatrix = (PFNGLPOPMATRIXPROC)gleIntGetProcAddress("glPopMatrix");
	if(!__glePopMatrix) bIsLoaded = 0;
	__glePushMatrix = (PFNGLPUSHMATRIXPROC)gleIntGetProcAddress("glPushMatrix");
	if(!__glePushMatrix) bIsLoaded = 0;
	__gleRotated = (PFNGLROTATEDPROC)gleIntGetProcAddress("glRotated");
	if(!__gleRotated) bIsLoaded = 0;
	__gleRotatef = (PFNGLROTATEFPROC)gleIntGetProcAddress("glRotatef");
	if(!__gleRotatef) bIsLoaded = 0;
	__gleScaled = (PFNGLSCALEDPROC)gleIntGetProcAddress("glScaled");
	if(!__gleScaled) bIsLoaded = 0;
	__gleScalef = (PFNGLSCALEFPROC)gleIntGetProcAddress("glScalef");
	if(!__gleScalef) bIsLoaded = 0;
	__gleTranslated = (PFNGLTRANSLATEDPROC)gleIntGetProcAddress("glTranslated");
	if(!__gleTranslated) bIsLoaded = 0;
	__gleTranslatef = (PFNGLTRANSLATEFPROC)gleIntGetProcAddress("glTranslatef");
	if(!__gleTranslatef) bIsLoaded = 0;
	__gleArrayElement = (PFNGLARRAYELEMENTPROC)gleIntGetProcAddress("glArrayElement");
	if(!__gleArrayElement) bIsLoaded = 0;
	__gleColorPointer = (PFNGLCOLORPOINTERPROC)gleIntGetProcAddress("glColorPointer");
	if(!__gleColorPointer) bIsLoaded = 0;
	__gleDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)gleIntGetProcAddress("glDisableClientState");
	if(!__gleDisableClientState) bIsLoaded = 0;
	__gleEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)gleIntGetProcAddress("glEdgeFlagPointer");
	if(!__gleEdgeFlagPointer) bIsLoaded = 0;
	__gleEnableClientState = (PFNGLENABLECLIENTSTATEPROC)gleIntGetProcAddress("glEnableClientState");
	if(!__gleEnableClientState) bIsLoaded = 0;
	__gleIndexPointer = (PFNGLINDEXPOINTERPROC)gleIntGetProcAddress("glIndexPointer");
	if(!__gleIndexPointer) bIsLoaded = 0;
	__gleInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)gleIntGetProcAddress("glInterleavedArrays");
	if(!__gleInterleavedArrays) bIsLoaded = 0;
	__gleNormalPointer = (PFNGLNORMALPOINTERPROC)gleIntGetProcAddress("glNormalPointer");
	if(!__gleNormalPointer) bIsLoaded = 0;
	__gleTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)gleIntGetProcAddress("glTexCoordPointer");
	if(!__gleTexCoordPointer) bIsLoaded = 0;
	__gleVertexPointer = (PFNGLVERTEXPOINTERPROC)gleIntGetProcAddress("glVertexPointer");
	if(!__gleVertexPointer) bIsLoaded = 0;
	__gleAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)gleIntGetProcAddress("glAreTexturesResident");
	if(!__gleAreTexturesResident) bIsLoaded = 0;
	__glePrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)gleIntGetProcAddress("glPrioritizeTextures");
	if(!__glePrioritizeTextures) bIsLoaded = 0;
	__glePopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)gleIntGetProcAddress("glPopClientAttrib");
	if(!__glePopClientAttrib) bIsLoaded = 0;
	__glePushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)gleIntGetProcAddress("glPushClientAttrib");
	if(!__glePushClientAttrib) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_2_Base()
{
	int bIsLoaded = gleIntLoadCore_1_2_Version_3_1();
	__gleTexImage3D = (PFNGLTEXIMAGE3DPROC)gleIntGetProcAddress("glTexImage3D");
	if(!__gleTexImage3D) bIsLoaded = 0;
	__gleColorTable = (PFNGLCOLORTABLEPROC)gleIntGetProcAddress("glColorTable");
	if(!__gleColorTable) bIsLoaded = 0;
	__gleColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC)gleIntGetProcAddress("glColorTableParameterfv");
	if(!__gleColorTableParameterfv) bIsLoaded = 0;
	__gleColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC)gleIntGetProcAddress("glColorTableParameteriv");
	if(!__gleColorTableParameteriv) bIsLoaded = 0;
	__gleCopyColorTable = (PFNGLCOPYCOLORTABLEPROC)gleIntGetProcAddress("glCopyColorTable");
	if(!__gleCopyColorTable) bIsLoaded = 0;
	__gleGetColorTable = (PFNGLGETCOLORTABLEPROC)gleIntGetProcAddress("glGetColorTable");
	if(!__gleGetColorTable) bIsLoaded = 0;
	__gleGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC)gleIntGetProcAddress("glGetColorTableParameterfv");
	if(!__gleGetColorTableParameterfv) bIsLoaded = 0;
	__gleGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC)gleIntGetProcAddress("glGetColorTableParameteriv");
	if(!__gleGetColorTableParameteriv) bIsLoaded = 0;
	__gleColorSubTable = (PFNGLCOLORSUBTABLEPROC)gleIntGetProcAddress("glColorSubTable");
	if(!__gleColorSubTable) bIsLoaded = 0;
	__gleCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC)gleIntGetProcAddress("glCopyColorSubTable");
	if(!__gleCopyColorSubTable) bIsLoaded = 0;
	__gleConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC)gleIntGetProcAddress("glConvolutionFilter1D");
	if(!__gleConvolutionFilter1D) bIsLoaded = 0;
	__gleConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC)gleIntGetProcAddress("glConvolutionFilter2D");
	if(!__gleConvolutionFilter2D) bIsLoaded = 0;
	__gleConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC)gleIntGetProcAddress("glConvolutionParameterf");
	if(!__gleConvolutionParameterf) bIsLoaded = 0;
	__gleConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC)gleIntGetProcAddress("glConvolutionParameterfv");
	if(!__gleConvolutionParameterfv) bIsLoaded = 0;
	__gleConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC)gleIntGetProcAddress("glConvolutionParameteri");
	if(!__gleConvolutionParameteri) bIsLoaded = 0;
	__gleConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC)gleIntGetProcAddress("glConvolutionParameteriv");
	if(!__gleConvolutionParameteriv) bIsLoaded = 0;
	__gleCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)gleIntGetProcAddress("glCopyConvolutionFilter1D");
	if(!__gleCopyConvolutionFilter1D) bIsLoaded = 0;
	__gleCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)gleIntGetProcAddress("glCopyConvolutionFilter2D");
	if(!__gleCopyConvolutionFilter2D) bIsLoaded = 0;
	__gleGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC)gleIntGetProcAddress("glGetConvolutionFilter");
	if(!__gleGetConvolutionFilter) bIsLoaded = 0;
	__gleGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)gleIntGetProcAddress("glGetConvolutionParameterfv");
	if(!__gleGetConvolutionParameterfv) bIsLoaded = 0;
	__gleGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)gleIntGetProcAddress("glGetConvolutionParameteriv");
	if(!__gleGetConvolutionParameteriv) bIsLoaded = 0;
	__gleGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC)gleIntGetProcAddress("glGetSeparableFilter");
	if(!__gleGetSeparableFilter) bIsLoaded = 0;
	__gleSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC)gleIntGetProcAddress("glSeparableFilter2D");
	if(!__gleSeparableFilter2D) bIsLoaded = 0;
	__gleGetHistogram = (PFNGLGETHISTOGRAMPROC)gleIntGetProcAddress("glGetHistogram");
	if(!__gleGetHistogram) bIsLoaded = 0;
	__gleGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC)gleIntGetProcAddress("glGetHistogramParameterfv");
	if(!__gleGetHistogramParameterfv) bIsLoaded = 0;
	__gleGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC)gleIntGetProcAddress("glGetHistogramParameteriv");
	if(!__gleGetHistogramParameteriv) bIsLoaded = 0;
	__gleGetMinmax = (PFNGLGETMINMAXPROC)gleIntGetProcAddress("glGetMinmax");
	if(!__gleGetMinmax) bIsLoaded = 0;
	__gleGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC)gleIntGetProcAddress("glGetMinmaxParameterfv");
	if(!__gleGetMinmaxParameterfv) bIsLoaded = 0;
	__gleGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC)gleIntGetProcAddress("glGetMinmaxParameteriv");
	if(!__gleGetMinmaxParameteriv) bIsLoaded = 0;
	__gleHistogram = (PFNGLHISTOGRAMPROC)gleIntGetProcAddress("glHistogram");
	if(!__gleHistogram) bIsLoaded = 0;
	__gleMinmax = (PFNGLMINMAXPROC)gleIntGetProcAddress("glMinmax");
	if(!__gleMinmax) bIsLoaded = 0;
	__gleResetHistogram = (PFNGLRESETHISTOGRAMPROC)gleIntGetProcAddress("glResetHistogram");
	if(!__gleResetHistogram) bIsLoaded = 0;
	__gleResetMinmax = (PFNGLRESETMINMAXPROC)gleIntGetProcAddress("glResetMinmax");
	if(!__gleResetMinmax) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_3_Base()
{
	int bIsLoaded = gleIntLoadCore_1_3_Version_3_1();
	__gleClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)gleIntGetProcAddress("glClientActiveTexture");
	if(!__gleClientActiveTexture) bIsLoaded = 0;
	__gleMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)gleIntGetProcAddress("glMultiTexCoord1d");
	if(!__gleMultiTexCoord1d) bIsLoaded = 0;
	__gleMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)gleIntGetProcAddress("glMultiTexCoord1dv");
	if(!__gleMultiTexCoord1dv) bIsLoaded = 0;
	__gleMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)gleIntGetProcAddress("glMultiTexCoord1f");
	if(!__gleMultiTexCoord1f) bIsLoaded = 0;
	__gleMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)gleIntGetProcAddress("glMultiTexCoord1fv");
	if(!__gleMultiTexCoord1fv) bIsLoaded = 0;
	__gleMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)gleIntGetProcAddress("glMultiTexCoord1i");
	if(!__gleMultiTexCoord1i) bIsLoaded = 0;
	__gleMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)gleIntGetProcAddress("glMultiTexCoord1iv");
	if(!__gleMultiTexCoord1iv) bIsLoaded = 0;
	__gleMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)gleIntGetProcAddress("glMultiTexCoord1s");
	if(!__gleMultiTexCoord1s) bIsLoaded = 0;
	__gleMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)gleIntGetProcAddress("glMultiTexCoord1sv");
	if(!__gleMultiTexCoord1sv) bIsLoaded = 0;
	__gleMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)gleIntGetProcAddress("glMultiTexCoord2d");
	if(!__gleMultiTexCoord2d) bIsLoaded = 0;
	__gleMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)gleIntGetProcAddress("glMultiTexCoord2dv");
	if(!__gleMultiTexCoord2dv) bIsLoaded = 0;
	__gleMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)gleIntGetProcAddress("glMultiTexCoord2f");
	if(!__gleMultiTexCoord2f) bIsLoaded = 0;
	__gleMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)gleIntGetProcAddress("glMultiTexCoord2fv");
	if(!__gleMultiTexCoord2fv) bIsLoaded = 0;
	__gleMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)gleIntGetProcAddress("glMultiTexCoord2i");
	if(!__gleMultiTexCoord2i) bIsLoaded = 0;
	__gleMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)gleIntGetProcAddress("glMultiTexCoord2iv");
	if(!__gleMultiTexCoord2iv) bIsLoaded = 0;
	__gleMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)gleIntGetProcAddress("glMultiTexCoord2s");
	if(!__gleMultiTexCoord2s) bIsLoaded = 0;
	__gleMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)gleIntGetProcAddress("glMultiTexCoord2sv");
	if(!__gleMultiTexCoord2sv) bIsLoaded = 0;
	__gleMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)gleIntGetProcAddress("glMultiTexCoord3d");
	if(!__gleMultiTexCoord3d) bIsLoaded = 0;
	__gleMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)gleIntGetProcAddress("glMultiTexCoord3dv");
	if(!__gleMultiTexCoord3dv) bIsLoaded = 0;
	__gleMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)gleIntGetProcAddress("glMultiTexCoord3f");
	if(!__gleMultiTexCoord3f) bIsLoaded = 0;
	__gleMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)gleIntGetProcAddress("glMultiTexCoord3fv");
	if(!__gleMultiTexCoord3fv) bIsLoaded = 0;
	__gleMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)gleIntGetProcAddress("glMultiTexCoord3i");
	if(!__gleMultiTexCoord3i) bIsLoaded = 0;
	__gleMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)gleIntGetProcAddress("glMultiTexCoord3iv");
	if(!__gleMultiTexCoord3iv) bIsLoaded = 0;
	__gleMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)gleIntGetProcAddress("glMultiTexCoord3s");
	if(!__gleMultiTexCoord3s) bIsLoaded = 0;
	__gleMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)gleIntGetProcAddress("glMultiTexCoord3sv");
	if(!__gleMultiTexCoord3sv) bIsLoaded = 0;
	__gleMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)gleIntGetProcAddress("glMultiTexCoord4d");
	if(!__gleMultiTexCoord4d) bIsLoaded = 0;
	__gleMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)gleIntGetProcAddress("glMultiTexCoord4dv");
	if(!__gleMultiTexCoord4dv) bIsLoaded = 0;
	__gleMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)gleIntGetProcAddress("glMultiTexCoord4f");
	if(!__gleMultiTexCoord4f) bIsLoaded = 0;
	__gleMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)gleIntGetProcAddress("glMultiTexCoord4fv");
	if(!__gleMultiTexCoord4fv) bIsLoaded = 0;
	__gleMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)gleIntGetProcAddress("glMultiTexCoord4i");
	if(!__gleMultiTexCoord4i) bIsLoaded = 0;
	__gleMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)gleIntGetProcAddress("glMultiTexCoord4iv");
	if(!__gleMultiTexCoord4iv) bIsLoaded = 0;
	__gleMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)gleIntGetProcAddress("glMultiTexCoord4s");
	if(!__gleMultiTexCoord4s) bIsLoaded = 0;
	__gleMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)gleIntGetProcAddress("glMultiTexCoord4sv");
	if(!__gleMultiTexCoord4sv) bIsLoaded = 0;
	__gleLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)gleIntGetProcAddress("glLoadTransposeMatrixf");
	if(!__gleLoadTransposeMatrixf) bIsLoaded = 0;
	__gleLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)gleIntGetProcAddress("glLoadTransposeMatrixd");
	if(!__gleLoadTransposeMatrixd) bIsLoaded = 0;
	__gleMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)gleIntGetProcAddress("glMultTransposeMatrixf");
	if(!__gleMultTransposeMatrixf) bIsLoaded = 0;
	__gleMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)gleIntGetProcAddress("glMultTransposeMatrixd");
	if(!__gleMultTransposeMatrixd) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_4_Base()
{
	int bIsLoaded = gleIntLoadCore_1_4_Version_3_1();
	__gleFogCoordf = (PFNGLFOGCOORDFPROC)gleIntGetProcAddress("glFogCoordf");
	if(!__gleFogCoordf) bIsLoaded = 0;
	__gleFogCoordfv = (PFNGLFOGCOORDFVPROC)gleIntGetProcAddress("glFogCoordfv");
	if(!__gleFogCoordfv) bIsLoaded = 0;
	__gleFogCoordd = (PFNGLFOGCOORDDPROC)gleIntGetProcAddress("glFogCoordd");
	if(!__gleFogCoordd) bIsLoaded = 0;
	__gleFogCoorddv = (PFNGLFOGCOORDDVPROC)gleIntGetProcAddress("glFogCoorddv");
	if(!__gleFogCoorddv) bIsLoaded = 0;
	__gleFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)gleIntGetProcAddress("glFogCoordPointer");
	if(!__gleFogCoordPointer) bIsLoaded = 0;
	__gleSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)gleIntGetProcAddress("glSecondaryColor3b");
	if(!__gleSecondaryColor3b) bIsLoaded = 0;
	__gleSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)gleIntGetProcAddress("glSecondaryColor3bv");
	if(!__gleSecondaryColor3bv) bIsLoaded = 0;
	__gleSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)gleIntGetProcAddress("glSecondaryColor3d");
	if(!__gleSecondaryColor3d) bIsLoaded = 0;
	__gleSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)gleIntGetProcAddress("glSecondaryColor3dv");
	if(!__gleSecondaryColor3dv) bIsLoaded = 0;
	__gleSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)gleIntGetProcAddress("glSecondaryColor3f");
	if(!__gleSecondaryColor3f) bIsLoaded = 0;
	__gleSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)gleIntGetProcAddress("glSecondaryColor3fv");
	if(!__gleSecondaryColor3fv) bIsLoaded = 0;
	__gleSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)gleIntGetProcAddress("glSecondaryColor3i");
	if(!__gleSecondaryColor3i) bIsLoaded = 0;
	__gleSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)gleIntGetProcAddress("glSecondaryColor3iv");
	if(!__gleSecondaryColor3iv) bIsLoaded = 0;
	__gleSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)gleIntGetProcAddress("glSecondaryColor3s");
	if(!__gleSecondaryColor3s) bIsLoaded = 0;
	__gleSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)gleIntGetProcAddress("glSecondaryColor3sv");
	if(!__gleSecondaryColor3sv) bIsLoaded = 0;
	__gleSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)gleIntGetProcAddress("glSecondaryColor3ub");
	if(!__gleSecondaryColor3ub) bIsLoaded = 0;
	__gleSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)gleIntGetProcAddress("glSecondaryColor3ubv");
	if(!__gleSecondaryColor3ubv) bIsLoaded = 0;
	__gleSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)gleIntGetProcAddress("glSecondaryColor3ui");
	if(!__gleSecondaryColor3ui) bIsLoaded = 0;
	__gleSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)gleIntGetProcAddress("glSecondaryColor3uiv");
	if(!__gleSecondaryColor3uiv) bIsLoaded = 0;
	__gleSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)gleIntGetProcAddress("glSecondaryColor3us");
	if(!__gleSecondaryColor3us) bIsLoaded = 0;
	__gleSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)gleIntGetProcAddress("glSecondaryColor3usv");
	if(!__gleSecondaryColor3usv) bIsLoaded = 0;
	__gleSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)gleIntGetProcAddress("glSecondaryColorPointer");
	if(!__gleSecondaryColorPointer) bIsLoaded = 0;
	__gleWindowPos2d = (PFNGLWINDOWPOS2DPROC)gleIntGetProcAddress("glWindowPos2d");
	if(!__gleWindowPos2d) bIsLoaded = 0;
	__gleWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)gleIntGetProcAddress("glWindowPos2dv");
	if(!__gleWindowPos2dv) bIsLoaded = 0;
	__gleWindowPos2f = (PFNGLWINDOWPOS2FPROC)gleIntGetProcAddress("glWindowPos2f");
	if(!__gleWindowPos2f) bIsLoaded = 0;
	__gleWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)gleIntGetProcAddress("glWindowPos2fv");
	if(!__gleWindowPos2fv) bIsLoaded = 0;
	__gleWindowPos2i = (PFNGLWINDOWPOS2IPROC)gleIntGetProcAddress("glWindowPos2i");
	if(!__gleWindowPos2i) bIsLoaded = 0;
	__gleWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)gleIntGetProcAddress("glWindowPos2iv");
	if(!__gleWindowPos2iv) bIsLoaded = 0;
	__gleWindowPos2s = (PFNGLWINDOWPOS2SPROC)gleIntGetProcAddress("glWindowPos2s");
	if(!__gleWindowPos2s) bIsLoaded = 0;
	__gleWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)gleIntGetProcAddress("glWindowPos2sv");
	if(!__gleWindowPos2sv) bIsLoaded = 0;
	__gleWindowPos3d = (PFNGLWINDOWPOS3DPROC)gleIntGetProcAddress("glWindowPos3d");
	if(!__gleWindowPos3d) bIsLoaded = 0;
	__gleWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)gleIntGetProcAddress("glWindowPos3dv");
	if(!__gleWindowPos3dv) bIsLoaded = 0;
	__gleWindowPos3f = (PFNGLWINDOWPOS3FPROC)gleIntGetProcAddress("glWindowPos3f");
	if(!__gleWindowPos3f) bIsLoaded = 0;
	__gleWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)gleIntGetProcAddress("glWindowPos3fv");
	if(!__gleWindowPos3fv) bIsLoaded = 0;
	__gleWindowPos3i = (PFNGLWINDOWPOS3IPROC)gleIntGetProcAddress("glWindowPos3i");
	if(!__gleWindowPos3i) bIsLoaded = 0;
	__gleWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)gleIntGetProcAddress("glWindowPos3iv");
	if(!__gleWindowPos3iv) bIsLoaded = 0;
	__gleWindowPos3s = (PFNGLWINDOWPOS3SPROC)gleIntGetProcAddress("glWindowPos3s");
	if(!__gleWindowPos3s) bIsLoaded = 0;
	__gleWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)gleIntGetProcAddress("glWindowPos3sv");
	if(!__gleWindowPos3sv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_1_5_Base()
{
	int bIsLoaded = gleIntLoadCore_1_5_Version_3_1();
	return bIsLoaded;
}

static int gleIntLoadCore_2_0_Base()
{
	int bIsLoaded = gleIntLoadCore_2_0_Version_3_1();
	__gleVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)gleIntGetProcAddress("glVertexAttrib1d");
	if(!__gleVertexAttrib1d) bIsLoaded = 0;
	__gleVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)gleIntGetProcAddress("glVertexAttrib1dv");
	if(!__gleVertexAttrib1dv) bIsLoaded = 0;
	__gleVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)gleIntGetProcAddress("glVertexAttrib1f");
	if(!__gleVertexAttrib1f) bIsLoaded = 0;
	__gleVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)gleIntGetProcAddress("glVertexAttrib1fv");
	if(!__gleVertexAttrib1fv) bIsLoaded = 0;
	__gleVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)gleIntGetProcAddress("glVertexAttrib1s");
	if(!__gleVertexAttrib1s) bIsLoaded = 0;
	__gleVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)gleIntGetProcAddress("glVertexAttrib1sv");
	if(!__gleVertexAttrib1sv) bIsLoaded = 0;
	__gleVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)gleIntGetProcAddress("glVertexAttrib2d");
	if(!__gleVertexAttrib2d) bIsLoaded = 0;
	__gleVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)gleIntGetProcAddress("glVertexAttrib2dv");
	if(!__gleVertexAttrib2dv) bIsLoaded = 0;
	__gleVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)gleIntGetProcAddress("glVertexAttrib2f");
	if(!__gleVertexAttrib2f) bIsLoaded = 0;
	__gleVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)gleIntGetProcAddress("glVertexAttrib2fv");
	if(!__gleVertexAttrib2fv) bIsLoaded = 0;
	__gleVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)gleIntGetProcAddress("glVertexAttrib2s");
	if(!__gleVertexAttrib2s) bIsLoaded = 0;
	__gleVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)gleIntGetProcAddress("glVertexAttrib2sv");
	if(!__gleVertexAttrib2sv) bIsLoaded = 0;
	__gleVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)gleIntGetProcAddress("glVertexAttrib3d");
	if(!__gleVertexAttrib3d) bIsLoaded = 0;
	__gleVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)gleIntGetProcAddress("glVertexAttrib3dv");
	if(!__gleVertexAttrib3dv) bIsLoaded = 0;
	__gleVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)gleIntGetProcAddress("glVertexAttrib3f");
	if(!__gleVertexAttrib3f) bIsLoaded = 0;
	__gleVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)gleIntGetProcAddress("glVertexAttrib3fv");
	if(!__gleVertexAttrib3fv) bIsLoaded = 0;
	__gleVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)gleIntGetProcAddress("glVertexAttrib3s");
	if(!__gleVertexAttrib3s) bIsLoaded = 0;
	__gleVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)gleIntGetProcAddress("glVertexAttrib3sv");
	if(!__gleVertexAttrib3sv) bIsLoaded = 0;
	__gleVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)gleIntGetProcAddress("glVertexAttrib4Nbv");
	if(!__gleVertexAttrib4Nbv) bIsLoaded = 0;
	__gleVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)gleIntGetProcAddress("glVertexAttrib4Niv");
	if(!__gleVertexAttrib4Niv) bIsLoaded = 0;
	__gleVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)gleIntGetProcAddress("glVertexAttrib4Nsv");
	if(!__gleVertexAttrib4Nsv) bIsLoaded = 0;
	__gleVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)gleIntGetProcAddress("glVertexAttrib4Nub");
	if(!__gleVertexAttrib4Nub) bIsLoaded = 0;
	__gleVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)gleIntGetProcAddress("glVertexAttrib4Nubv");
	if(!__gleVertexAttrib4Nubv) bIsLoaded = 0;
	__gleVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)gleIntGetProcAddress("glVertexAttrib4Nuiv");
	if(!__gleVertexAttrib4Nuiv) bIsLoaded = 0;
	__gleVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)gleIntGetProcAddress("glVertexAttrib4Nusv");
	if(!__gleVertexAttrib4Nusv) bIsLoaded = 0;
	__gleVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)gleIntGetProcAddress("glVertexAttrib4bv");
	if(!__gleVertexAttrib4bv) bIsLoaded = 0;
	__gleVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)gleIntGetProcAddress("glVertexAttrib4d");
	if(!__gleVertexAttrib4d) bIsLoaded = 0;
	__gleVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)gleIntGetProcAddress("glVertexAttrib4dv");
	if(!__gleVertexAttrib4dv) bIsLoaded = 0;
	__gleVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)gleIntGetProcAddress("glVertexAttrib4f");
	if(!__gleVertexAttrib4f) bIsLoaded = 0;
	__gleVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)gleIntGetProcAddress("glVertexAttrib4fv");
	if(!__gleVertexAttrib4fv) bIsLoaded = 0;
	__gleVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)gleIntGetProcAddress("glVertexAttrib4iv");
	if(!__gleVertexAttrib4iv) bIsLoaded = 0;
	__gleVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)gleIntGetProcAddress("glVertexAttrib4s");
	if(!__gleVertexAttrib4s) bIsLoaded = 0;
	__gleVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)gleIntGetProcAddress("glVertexAttrib4sv");
	if(!__gleVertexAttrib4sv) bIsLoaded = 0;
	__gleVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)gleIntGetProcAddress("glVertexAttrib4ubv");
	if(!__gleVertexAttrib4ubv) bIsLoaded = 0;
	__gleVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)gleIntGetProcAddress("glVertexAttrib4uiv");
	if(!__gleVertexAttrib4uiv) bIsLoaded = 0;
	__gleVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)gleIntGetProcAddress("glVertexAttrib4usv");
	if(!__gleVertexAttrib4usv) bIsLoaded = 0;
	return bIsLoaded;
}

static int gleIntLoadCore_2_1_Base()
{
	int bIsLoaded = gleIntLoadCore_2_1_Version_3_1();
	return bIsLoaded;
}

static int gleIntLoadCore_3_0_Base()
{
	int bIsLoaded = gleIntLoadCore_3_0_Version_3_1();
	return bIsLoaded;
}

static int gleIntLoadCore_3_1_Base()
{
	int bIsLoaded = 1;
	__gleDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)gleIntGetProcAddress("glDrawArraysInstanced");
	if(!__gleDrawArraysInstanced) bIsLoaded = 0;
	__gleDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)gleIntGetProcAddress("glDrawElementsInstanced");
	if(!__gleDrawElementsInstanced) bIsLoaded = 0;
	__gleTexBuffer = (PFNGLTEXBUFFERPROC)gleIntGetProcAddress("glTexBuffer");
	if(!__gleTexBuffer) bIsLoaded = 0;
	__glePrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)gleIntGetProcAddress("glPrimitiveRestartIndex");
	if(!__glePrimitiveRestartIndex) bIsLoaded = 0;
	__gleGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)gleIntGetProcAddress("glGetUniformIndices");
	if(!__gleGetUniformIndices) bIsLoaded = 0;
	__gleGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)gleIntGetProcAddress("glGetActiveUniformsiv");
	if(!__gleGetActiveUniformsiv) bIsLoaded = 0;
	__gleGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)gleIntGetProcAddress("glGetActiveUniformName");
	if(!__gleGetActiveUniformName) bIsLoaded = 0;
	__gleGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)gleIntGetProcAddress("glGetUniformBlockIndex");
	if(!__gleGetUniformBlockIndex) bIsLoaded = 0;
	__gleGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)gleIntGetProcAddress("glGetActiveUniformBlockiv");
	if(!__gleGetActiveUniformBlockiv) bIsLoaded = 0;
	__gleGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)gleIntGetProcAddress("glGetActiveUniformBlockName");
	if(!__gleGetActiveUniformBlockName) bIsLoaded = 0;
	__gleUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)gleIntGetProcAddress("glUniformBlockBinding");
	if(!__gleUniformBlockBinding) bIsLoaded = 0;
	glext_ARB_uniform_buffer_object = 1;
	__gleCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)gleIntGetProcAddress("glCopyBufferSubData");
	if(!__gleCopyBufferSubData) bIsLoaded = 0;
	glext_ARB_copy_buffer = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_3_2_Base()
{
	int bIsLoaded = 1;
	__gleGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)gleIntGetProcAddress("glGetInteger64i_v");
	if(!__gleGetInteger64i_v) bIsLoaded = 0;
	__gleGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)gleIntGetProcAddress("glGetBufferParameteri64v");
	if(!__gleGetBufferParameteri64v) bIsLoaded = 0;
	__gleFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)gleIntGetProcAddress("glFramebufferTexture");
	if(!__gleFramebufferTexture) bIsLoaded = 0;
	__gleTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)gleIntGetProcAddress("glTexImage2DMultisample");
	if(!__gleTexImage2DMultisample) bIsLoaded = 0;
	__gleTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)gleIntGetProcAddress("glTexImage3DMultisample");
	if(!__gleTexImage3DMultisample) bIsLoaded = 0;
	__gleGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)gleIntGetProcAddress("glGetMultisamplefv");
	if(!__gleGetMultisamplefv) bIsLoaded = 0;
	__gleSampleMaski = (PFNGLSAMPLEMASKIPROC)gleIntGetProcAddress("glSampleMaski");
	if(!__gleSampleMaski) bIsLoaded = 0;
	glext_ARB_texture_multisample = 1;
	__gleDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glDrawElementsBaseVertex");
	if(!__gleDrawElementsBaseVertex) bIsLoaded = 0;
	__gleDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glDrawRangeElementsBaseVertex");
	if(!__gleDrawRangeElementsBaseVertex) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseVertex");
	if(!__gleDrawElementsInstancedBaseVertex) bIsLoaded = 0;
	__gleMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)gleIntGetProcAddress("glMultiDrawElementsBaseVertex");
	if(!__gleMultiDrawElementsBaseVertex) bIsLoaded = 0;
	glext_ARB_draw_elements_base_vertex = 1;
	__gleProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)gleIntGetProcAddress("glProvokingVertex");
	if(!__gleProvokingVertex) bIsLoaded = 0;
	glext_ARB_provoking_vertex = 1;
	__gleFenceSync = (PFNGLFENCESYNCPROC)gleIntGetProcAddress("glFenceSync");
	if(!__gleFenceSync) bIsLoaded = 0;
	__gleIsSync = (PFNGLISSYNCPROC)gleIntGetProcAddress("glIsSync");
	if(!__gleIsSync) bIsLoaded = 0;
	__gleDeleteSync = (PFNGLDELETESYNCPROC)gleIntGetProcAddress("glDeleteSync");
	if(!__gleDeleteSync) bIsLoaded = 0;
	__gleClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)gleIntGetProcAddress("glClientWaitSync");
	if(!__gleClientWaitSync) bIsLoaded = 0;
	__gleWaitSync = (PFNGLWAITSYNCPROC)gleIntGetProcAddress("glWaitSync");
	if(!__gleWaitSync) bIsLoaded = 0;
	__gleGetInteger64v = (PFNGLGETINTEGER64VPROC)gleIntGetProcAddress("glGetInteger64v");
	if(!__gleGetInteger64v) bIsLoaded = 0;
	__gleGetSynciv = (PFNGLGETSYNCIVPROC)gleIntGetProcAddress("glGetSynciv");
	if(!__gleGetSynciv) bIsLoaded = 0;
	glext_ARB_sync = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_3_3_Base()
{
	int bIsLoaded = 1;
	__gleVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)gleIntGetProcAddress("glVertexAttribDivisor");
	if(!__gleVertexAttribDivisor) bIsLoaded = 0;
	__gleBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)gleIntGetProcAddress("glBindFragDataLocationIndexed");
	if(!__gleBindFragDataLocationIndexed) bIsLoaded = 0;
	__gleGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)gleIntGetProcAddress("glGetFragDataIndex");
	if(!__gleGetFragDataIndex) bIsLoaded = 0;
	glext_ARB_blend_func_extended = 1;
	__gleQueryCounter = (PFNGLQUERYCOUNTERPROC)gleIntGetProcAddress("glQueryCounter");
	if(!__gleQueryCounter) bIsLoaded = 0;
	__gleGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)gleIntGetProcAddress("glGetQueryObjecti64v");
	if(!__gleGetQueryObjecti64v) bIsLoaded = 0;
	__gleGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)gleIntGetProcAddress("glGetQueryObjectui64v");
	if(!__gleGetQueryObjectui64v) bIsLoaded = 0;
	glext_ARB_timer_query = 1;
	__gleVertexP2ui = (PFNGLVERTEXP2UIPROC)gleIntGetProcAddress("glVertexP2ui");
	if(!__gleVertexP2ui) bIsLoaded = 0;
	__gleVertexP2uiv = (PFNGLVERTEXP2UIVPROC)gleIntGetProcAddress("glVertexP2uiv");
	if(!__gleVertexP2uiv) bIsLoaded = 0;
	__gleVertexP3ui = (PFNGLVERTEXP3UIPROC)gleIntGetProcAddress("glVertexP3ui");
	if(!__gleVertexP3ui) bIsLoaded = 0;
	__gleVertexP3uiv = (PFNGLVERTEXP3UIVPROC)gleIntGetProcAddress("glVertexP3uiv");
	if(!__gleVertexP3uiv) bIsLoaded = 0;
	__gleVertexP4ui = (PFNGLVERTEXP4UIPROC)gleIntGetProcAddress("glVertexP4ui");
	if(!__gleVertexP4ui) bIsLoaded = 0;
	__gleVertexP4uiv = (PFNGLVERTEXP4UIVPROC)gleIntGetProcAddress("glVertexP4uiv");
	if(!__gleVertexP4uiv) bIsLoaded = 0;
	__gleTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)gleIntGetProcAddress("glTexCoordP1ui");
	if(!__gleTexCoordP1ui) bIsLoaded = 0;
	__gleTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)gleIntGetProcAddress("glTexCoordP1uiv");
	if(!__gleTexCoordP1uiv) bIsLoaded = 0;
	__gleTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)gleIntGetProcAddress("glTexCoordP2ui");
	if(!__gleTexCoordP2ui) bIsLoaded = 0;
	__gleTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)gleIntGetProcAddress("glTexCoordP2uiv");
	if(!__gleTexCoordP2uiv) bIsLoaded = 0;
	__gleTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)gleIntGetProcAddress("glTexCoordP3ui");
	if(!__gleTexCoordP3ui) bIsLoaded = 0;
	__gleTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)gleIntGetProcAddress("glTexCoordP3uiv");
	if(!__gleTexCoordP3uiv) bIsLoaded = 0;
	__gleTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)gleIntGetProcAddress("glTexCoordP4ui");
	if(!__gleTexCoordP4ui) bIsLoaded = 0;
	__gleTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)gleIntGetProcAddress("glTexCoordP4uiv");
	if(!__gleTexCoordP4uiv) bIsLoaded = 0;
	__gleMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)gleIntGetProcAddress("glMultiTexCoordP1ui");
	if(!__gleMultiTexCoordP1ui) bIsLoaded = 0;
	__gleMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)gleIntGetProcAddress("glMultiTexCoordP1uiv");
	if(!__gleMultiTexCoordP1uiv) bIsLoaded = 0;
	__gleMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)gleIntGetProcAddress("glMultiTexCoordP2ui");
	if(!__gleMultiTexCoordP2ui) bIsLoaded = 0;
	__gleMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)gleIntGetProcAddress("glMultiTexCoordP2uiv");
	if(!__gleMultiTexCoordP2uiv) bIsLoaded = 0;
	__gleMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)gleIntGetProcAddress("glMultiTexCoordP3ui");
	if(!__gleMultiTexCoordP3ui) bIsLoaded = 0;
	__gleMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)gleIntGetProcAddress("glMultiTexCoordP3uiv");
	if(!__gleMultiTexCoordP3uiv) bIsLoaded = 0;
	__gleMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)gleIntGetProcAddress("glMultiTexCoordP4ui");
	if(!__gleMultiTexCoordP4ui) bIsLoaded = 0;
	__gleMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)gleIntGetProcAddress("glMultiTexCoordP4uiv");
	if(!__gleMultiTexCoordP4uiv) bIsLoaded = 0;
	__gleNormalP3ui = (PFNGLNORMALP3UIPROC)gleIntGetProcAddress("glNormalP3ui");
	if(!__gleNormalP3ui) bIsLoaded = 0;
	__gleNormalP3uiv = (PFNGLNORMALP3UIVPROC)gleIntGetProcAddress("glNormalP3uiv");
	if(!__gleNormalP3uiv) bIsLoaded = 0;
	__gleColorP3ui = (PFNGLCOLORP3UIPROC)gleIntGetProcAddress("glColorP3ui");
	if(!__gleColorP3ui) bIsLoaded = 0;
	__gleColorP3uiv = (PFNGLCOLORP3UIVPROC)gleIntGetProcAddress("glColorP3uiv");
	if(!__gleColorP3uiv) bIsLoaded = 0;
	__gleColorP4ui = (PFNGLCOLORP4UIPROC)gleIntGetProcAddress("glColorP4ui");
	if(!__gleColorP4ui) bIsLoaded = 0;
	__gleColorP4uiv = (PFNGLCOLORP4UIVPROC)gleIntGetProcAddress("glColorP4uiv");
	if(!__gleColorP4uiv) bIsLoaded = 0;
	__gleSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)gleIntGetProcAddress("glSecondaryColorP3ui");
	if(!__gleSecondaryColorP3ui) bIsLoaded = 0;
	__gleSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)gleIntGetProcAddress("glSecondaryColorP3uiv");
	if(!__gleSecondaryColorP3uiv) bIsLoaded = 0;
	__gleVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)gleIntGetProcAddress("glVertexAttribP1ui");
	if(!__gleVertexAttribP1ui) bIsLoaded = 0;
	__gleVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)gleIntGetProcAddress("glVertexAttribP1uiv");
	if(!__gleVertexAttribP1uiv) bIsLoaded = 0;
	__gleVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)gleIntGetProcAddress("glVertexAttribP2ui");
	if(!__gleVertexAttribP2ui) bIsLoaded = 0;
	__gleVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)gleIntGetProcAddress("glVertexAttribP2uiv");
	if(!__gleVertexAttribP2uiv) bIsLoaded = 0;
	__gleVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)gleIntGetProcAddress("glVertexAttribP3ui");
	if(!__gleVertexAttribP3ui) bIsLoaded = 0;
	__gleVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)gleIntGetProcAddress("glVertexAttribP3uiv");
	if(!__gleVertexAttribP3uiv) bIsLoaded = 0;
	__gleVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)gleIntGetProcAddress("glVertexAttribP4ui");
	if(!__gleVertexAttribP4ui) bIsLoaded = 0;
	__gleVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)gleIntGetProcAddress("glVertexAttribP4uiv");
	if(!__gleVertexAttribP4uiv) bIsLoaded = 0;
	glext_ARB_vertex_type_2_10_10_10_rev = 1;
	__gleGenSamplers = (PFNGLGENSAMPLERSPROC)gleIntGetProcAddress("glGenSamplers");
	if(!__gleGenSamplers) bIsLoaded = 0;
	__gleDeleteSamplers = (PFNGLDELETESAMPLERSPROC)gleIntGetProcAddress("glDeleteSamplers");
	if(!__gleDeleteSamplers) bIsLoaded = 0;
	__gleIsSampler = (PFNGLISSAMPLERPROC)gleIntGetProcAddress("glIsSampler");
	if(!__gleIsSampler) bIsLoaded = 0;
	__gleBindSampler = (PFNGLBINDSAMPLERPROC)gleIntGetProcAddress("glBindSampler");
	if(!__gleBindSampler) bIsLoaded = 0;
	__gleSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)gleIntGetProcAddress("glSamplerParameteri");
	if(!__gleSamplerParameteri) bIsLoaded = 0;
	__gleSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)gleIntGetProcAddress("glSamplerParameteriv");
	if(!__gleSamplerParameteriv) bIsLoaded = 0;
	__gleSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)gleIntGetProcAddress("glSamplerParameterf");
	if(!__gleSamplerParameterf) bIsLoaded = 0;
	__gleSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)gleIntGetProcAddress("glSamplerParameterfv");
	if(!__gleSamplerParameterfv) bIsLoaded = 0;
	__gleSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)gleIntGetProcAddress("glSamplerParameterIiv");
	if(!__gleSamplerParameterIiv) bIsLoaded = 0;
	__gleSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)gleIntGetProcAddress("glSamplerParameterIuiv");
	if(!__gleSamplerParameterIuiv) bIsLoaded = 0;
	__gleGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)gleIntGetProcAddress("glGetSamplerParameteriv");
	if(!__gleGetSamplerParameteriv) bIsLoaded = 0;
	__gleGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)gleIntGetProcAddress("glGetSamplerParameterIiv");
	if(!__gleGetSamplerParameterIiv) bIsLoaded = 0;
	__gleGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)gleIntGetProcAddress("glGetSamplerParameterfv");
	if(!__gleGetSamplerParameterfv) bIsLoaded = 0;
	__gleGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)gleIntGetProcAddress("glGetSamplerParameterIuiv");
	if(!__gleGetSamplerParameterIuiv) bIsLoaded = 0;
	glext_ARB_sampler_objects = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_4_0_Base()
{
	int bIsLoaded = 1;
	__gleMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)gleIntGetProcAddress("glMinSampleShading");
	if(!__gleMinSampleShading) bIsLoaded = 0;
	__gleBlendEquationi = (PFNGLBLENDEQUATIONIPROC)gleIntGetProcAddress("glBlendEquationi");
	if(!__gleBlendEquationi) bIsLoaded = 0;
	__gleBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)gleIntGetProcAddress("glBlendEquationSeparatei");
	if(!__gleBlendEquationSeparatei) bIsLoaded = 0;
	__gleBlendFunci = (PFNGLBLENDFUNCIPROC)gleIntGetProcAddress("glBlendFunci");
	if(!__gleBlendFunci) bIsLoaded = 0;
	__gleBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)gleIntGetProcAddress("glBlendFuncSeparatei");
	if(!__gleBlendFuncSeparatei) bIsLoaded = 0;
	__gleBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glBindTransformFeedback");
	if(!__gleBindTransformFeedback) bIsLoaded = 0;
	__gleDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)gleIntGetProcAddress("glDeleteTransformFeedbacks");
	if(!__gleDeleteTransformFeedbacks) bIsLoaded = 0;
	__gleGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)gleIntGetProcAddress("glGenTransformFeedbacks");
	if(!__gleGenTransformFeedbacks) bIsLoaded = 0;
	__gleIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glIsTransformFeedback");
	if(!__gleIsTransformFeedback) bIsLoaded = 0;
	__glePauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glPauseTransformFeedback");
	if(!__glePauseTransformFeedback) bIsLoaded = 0;
	__gleResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glResumeTransformFeedback");
	if(!__gleResumeTransformFeedback) bIsLoaded = 0;
	__gleDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)gleIntGetProcAddress("glDrawTransformFeedback");
	if(!__gleDrawTransformFeedback) bIsLoaded = 0;
	glext_ARB_transform_feedback2 = 1;
	__glePatchParameteri = (PFNGLPATCHPARAMETERIPROC)gleIntGetProcAddress("glPatchParameteri");
	if(!__glePatchParameteri) bIsLoaded = 0;
	__glePatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)gleIntGetProcAddress("glPatchParameterfv");
	if(!__glePatchParameterfv) bIsLoaded = 0;
	glext_ARB_tessellation_shader = 1;
	__gleDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)gleIntGetProcAddress("glDrawArraysIndirect");
	if(!__gleDrawArraysIndirect) bIsLoaded = 0;
	__gleDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)gleIntGetProcAddress("glDrawElementsIndirect");
	if(!__gleDrawElementsIndirect) bIsLoaded = 0;
	glext_ARB_draw_indirect = 1;
	__gleDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)gleIntGetProcAddress("glDrawTransformFeedbackStream");
	if(!__gleDrawTransformFeedbackStream) bIsLoaded = 0;
	__gleBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)gleIntGetProcAddress("glBeginQueryIndexed");
	if(!__gleBeginQueryIndexed) bIsLoaded = 0;
	__gleEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)gleIntGetProcAddress("glEndQueryIndexed");
	if(!__gleEndQueryIndexed) bIsLoaded = 0;
	__gleGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)gleIntGetProcAddress("glGetQueryIndexediv");
	if(!__gleGetQueryIndexediv) bIsLoaded = 0;
	glext_ARB_transform_feedback3 = 1;
	__gleUniform1d = (PFNGLUNIFORM1DPROC)gleIntGetProcAddress("glUniform1d");
	if(!__gleUniform1d) bIsLoaded = 0;
	__gleUniform2d = (PFNGLUNIFORM2DPROC)gleIntGetProcAddress("glUniform2d");
	if(!__gleUniform2d) bIsLoaded = 0;
	__gleUniform3d = (PFNGLUNIFORM3DPROC)gleIntGetProcAddress("glUniform3d");
	if(!__gleUniform3d) bIsLoaded = 0;
	__gleUniform4d = (PFNGLUNIFORM4DPROC)gleIntGetProcAddress("glUniform4d");
	if(!__gleUniform4d) bIsLoaded = 0;
	__gleUniform1dv = (PFNGLUNIFORM1DVPROC)gleIntGetProcAddress("glUniform1dv");
	if(!__gleUniform1dv) bIsLoaded = 0;
	__gleUniform2dv = (PFNGLUNIFORM2DVPROC)gleIntGetProcAddress("glUniform2dv");
	if(!__gleUniform2dv) bIsLoaded = 0;
	__gleUniform3dv = (PFNGLUNIFORM3DVPROC)gleIntGetProcAddress("glUniform3dv");
	if(!__gleUniform3dv) bIsLoaded = 0;
	__gleUniform4dv = (PFNGLUNIFORM4DVPROC)gleIntGetProcAddress("glUniform4dv");
	if(!__gleUniform4dv) bIsLoaded = 0;
	__gleUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)gleIntGetProcAddress("glUniformMatrix2dv");
	if(!__gleUniformMatrix2dv) bIsLoaded = 0;
	__gleUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)gleIntGetProcAddress("glUniformMatrix3dv");
	if(!__gleUniformMatrix3dv) bIsLoaded = 0;
	__gleUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)gleIntGetProcAddress("glUniformMatrix4dv");
	if(!__gleUniformMatrix4dv) bIsLoaded = 0;
	__gleUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)gleIntGetProcAddress("glUniformMatrix2x3dv");
	if(!__gleUniformMatrix2x3dv) bIsLoaded = 0;
	__gleUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)gleIntGetProcAddress("glUniformMatrix2x4dv");
	if(!__gleUniformMatrix2x4dv) bIsLoaded = 0;
	__gleUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)gleIntGetProcAddress("glUniformMatrix3x2dv");
	if(!__gleUniformMatrix3x2dv) bIsLoaded = 0;
	__gleUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)gleIntGetProcAddress("glUniformMatrix3x4dv");
	if(!__gleUniformMatrix3x4dv) bIsLoaded = 0;
	__gleUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)gleIntGetProcAddress("glUniformMatrix4x2dv");
	if(!__gleUniformMatrix4x2dv) bIsLoaded = 0;
	__gleUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)gleIntGetProcAddress("glUniformMatrix4x3dv");
	if(!__gleUniformMatrix4x3dv) bIsLoaded = 0;
	__gleGetUniformdv = (PFNGLGETUNIFORMDVPROC)gleIntGetProcAddress("glGetUniformdv");
	if(!__gleGetUniformdv) bIsLoaded = 0;
	glext_ARB_gpu_shader_fp64 = 1;
	__gleGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)gleIntGetProcAddress("glGetSubroutineUniformLocation");
	if(!__gleGetSubroutineUniformLocation) bIsLoaded = 0;
	__gleGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)gleIntGetProcAddress("glGetSubroutineIndex");
	if(!__gleGetSubroutineIndex) bIsLoaded = 0;
	__gleGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)gleIntGetProcAddress("glGetActiveSubroutineUniformiv");
	if(!__gleGetActiveSubroutineUniformiv) bIsLoaded = 0;
	__gleGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)gleIntGetProcAddress("glGetActiveSubroutineUniformName");
	if(!__gleGetActiveSubroutineUniformName) bIsLoaded = 0;
	__gleGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)gleIntGetProcAddress("glGetActiveSubroutineName");
	if(!__gleGetActiveSubroutineName) bIsLoaded = 0;
	__gleUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)gleIntGetProcAddress("glUniformSubroutinesuiv");
	if(!__gleUniformSubroutinesuiv) bIsLoaded = 0;
	__gleGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)gleIntGetProcAddress("glGetUniformSubroutineuiv");
	if(!__gleGetUniformSubroutineuiv) bIsLoaded = 0;
	__gleGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)gleIntGetProcAddress("glGetProgramStageiv");
	if(!__gleGetProgramStageiv) bIsLoaded = 0;
	glext_ARB_shader_subroutine = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_4_1_Base()
{
	int bIsLoaded = 1;
	__gleVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)gleIntGetProcAddress("glVertexAttribL1d");
	if(!__gleVertexAttribL1d) bIsLoaded = 0;
	__gleVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)gleIntGetProcAddress("glVertexAttribL2d");
	if(!__gleVertexAttribL2d) bIsLoaded = 0;
	__gleVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)gleIntGetProcAddress("glVertexAttribL3d");
	if(!__gleVertexAttribL3d) bIsLoaded = 0;
	__gleVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)gleIntGetProcAddress("glVertexAttribL4d");
	if(!__gleVertexAttribL4d) bIsLoaded = 0;
	__gleVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)gleIntGetProcAddress("glVertexAttribL1dv");
	if(!__gleVertexAttribL1dv) bIsLoaded = 0;
	__gleVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)gleIntGetProcAddress("glVertexAttribL2dv");
	if(!__gleVertexAttribL2dv) bIsLoaded = 0;
	__gleVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)gleIntGetProcAddress("glVertexAttribL3dv");
	if(!__gleVertexAttribL3dv) bIsLoaded = 0;
	__gleVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)gleIntGetProcAddress("glVertexAttribL4dv");
	if(!__gleVertexAttribL4dv) bIsLoaded = 0;
	__gleVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)gleIntGetProcAddress("glVertexAttribLPointer");
	if(!__gleVertexAttribLPointer) bIsLoaded = 0;
	__gleGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)gleIntGetProcAddress("glGetVertexAttribLdv");
	if(!__gleGetVertexAttribLdv) bIsLoaded = 0;
	glext_ARB_vertex_attrib_64bit = 1;
	__gleUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)gleIntGetProcAddress("glUseProgramStages");
	if(!__gleUseProgramStages) bIsLoaded = 0;
	__gleActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)gleIntGetProcAddress("glActiveShaderProgram");
	if(!__gleActiveShaderProgram) bIsLoaded = 0;
	__gleCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)gleIntGetProcAddress("glCreateShaderProgramv");
	if(!__gleCreateShaderProgramv) bIsLoaded = 0;
	__gleBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)gleIntGetProcAddress("glBindProgramPipeline");
	if(!__gleBindProgramPipeline) bIsLoaded = 0;
	__gleDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)gleIntGetProcAddress("glDeleteProgramPipelines");
	if(!__gleDeleteProgramPipelines) bIsLoaded = 0;
	__gleGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)gleIntGetProcAddress("glGenProgramPipelines");
	if(!__gleGenProgramPipelines) bIsLoaded = 0;
	__gleIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)gleIntGetProcAddress("glIsProgramPipeline");
	if(!__gleIsProgramPipeline) bIsLoaded = 0;
	__gleGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)gleIntGetProcAddress("glGetProgramPipelineiv");
	if(!__gleGetProgramPipelineiv) bIsLoaded = 0;
	__gleProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)gleIntGetProcAddress("glProgramUniform1i");
	if(!__gleProgramUniform1i) bIsLoaded = 0;
	__gleProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)gleIntGetProcAddress("glProgramUniform1iv");
	if(!__gleProgramUniform1iv) bIsLoaded = 0;
	__gleProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)gleIntGetProcAddress("glProgramUniform1f");
	if(!__gleProgramUniform1f) bIsLoaded = 0;
	__gleProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)gleIntGetProcAddress("glProgramUniform1fv");
	if(!__gleProgramUniform1fv) bIsLoaded = 0;
	__gleProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)gleIntGetProcAddress("glProgramUniform1d");
	if(!__gleProgramUniform1d) bIsLoaded = 0;
	__gleProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)gleIntGetProcAddress("glProgramUniform1dv");
	if(!__gleProgramUniform1dv) bIsLoaded = 0;
	__gleProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)gleIntGetProcAddress("glProgramUniform1ui");
	if(!__gleProgramUniform1ui) bIsLoaded = 0;
	__gleProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)gleIntGetProcAddress("glProgramUniform1uiv");
	if(!__gleProgramUniform1uiv) bIsLoaded = 0;
	__gleProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)gleIntGetProcAddress("glProgramUniform2i");
	if(!__gleProgramUniform2i) bIsLoaded = 0;
	__gleProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)gleIntGetProcAddress("glProgramUniform2iv");
	if(!__gleProgramUniform2iv) bIsLoaded = 0;
	__gleProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)gleIntGetProcAddress("glProgramUniform2f");
	if(!__gleProgramUniform2f) bIsLoaded = 0;
	__gleProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)gleIntGetProcAddress("glProgramUniform2fv");
	if(!__gleProgramUniform2fv) bIsLoaded = 0;
	__gleProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)gleIntGetProcAddress("glProgramUniform2d");
	if(!__gleProgramUniform2d) bIsLoaded = 0;
	__gleProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)gleIntGetProcAddress("glProgramUniform2dv");
	if(!__gleProgramUniform2dv) bIsLoaded = 0;
	__gleProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)gleIntGetProcAddress("glProgramUniform2ui");
	if(!__gleProgramUniform2ui) bIsLoaded = 0;
	__gleProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)gleIntGetProcAddress("glProgramUniform2uiv");
	if(!__gleProgramUniform2uiv) bIsLoaded = 0;
	__gleProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)gleIntGetProcAddress("glProgramUniform3i");
	if(!__gleProgramUniform3i) bIsLoaded = 0;
	__gleProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)gleIntGetProcAddress("glProgramUniform3iv");
	if(!__gleProgramUniform3iv) bIsLoaded = 0;
	__gleProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)gleIntGetProcAddress("glProgramUniform3f");
	if(!__gleProgramUniform3f) bIsLoaded = 0;
	__gleProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)gleIntGetProcAddress("glProgramUniform3fv");
	if(!__gleProgramUniform3fv) bIsLoaded = 0;
	__gleProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)gleIntGetProcAddress("glProgramUniform3d");
	if(!__gleProgramUniform3d) bIsLoaded = 0;
	__gleProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)gleIntGetProcAddress("glProgramUniform3dv");
	if(!__gleProgramUniform3dv) bIsLoaded = 0;
	__gleProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)gleIntGetProcAddress("glProgramUniform3ui");
	if(!__gleProgramUniform3ui) bIsLoaded = 0;
	__gleProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)gleIntGetProcAddress("glProgramUniform3uiv");
	if(!__gleProgramUniform3uiv) bIsLoaded = 0;
	__gleProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)gleIntGetProcAddress("glProgramUniform4i");
	if(!__gleProgramUniform4i) bIsLoaded = 0;
	__gleProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)gleIntGetProcAddress("glProgramUniform4iv");
	if(!__gleProgramUniform4iv) bIsLoaded = 0;
	__gleProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)gleIntGetProcAddress("glProgramUniform4f");
	if(!__gleProgramUniform4f) bIsLoaded = 0;
	__gleProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)gleIntGetProcAddress("glProgramUniform4fv");
	if(!__gleProgramUniform4fv) bIsLoaded = 0;
	__gleProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)gleIntGetProcAddress("glProgramUniform4d");
	if(!__gleProgramUniform4d) bIsLoaded = 0;
	__gleProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)gleIntGetProcAddress("glProgramUniform4dv");
	if(!__gleProgramUniform4dv) bIsLoaded = 0;
	__gleProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)gleIntGetProcAddress("glProgramUniform4ui");
	if(!__gleProgramUniform4ui) bIsLoaded = 0;
	__gleProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)gleIntGetProcAddress("glProgramUniform4uiv");
	if(!__gleProgramUniform4uiv) bIsLoaded = 0;
	__gleProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2fv");
	if(!__gleProgramUniformMatrix2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3fv");
	if(!__gleProgramUniformMatrix3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4fv");
	if(!__gleProgramUniformMatrix4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2dv");
	if(!__gleProgramUniformMatrix2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3dv");
	if(!__gleProgramUniformMatrix3dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4dv");
	if(!__gleProgramUniformMatrix4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3fv");
	if(!__gleProgramUniformMatrix2x3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2fv");
	if(!__gleProgramUniformMatrix3x2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4fv");
	if(!__gleProgramUniformMatrix2x4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2fv");
	if(!__gleProgramUniformMatrix4x2fv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4fv");
	if(!__gleProgramUniformMatrix3x4fv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3fv");
	if(!__gleProgramUniformMatrix4x3fv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x3dv");
	if(!__gleProgramUniformMatrix2x3dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x2dv");
	if(!__gleProgramUniformMatrix3x2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix2x4dv");
	if(!__gleProgramUniformMatrix2x4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x2dv");
	if(!__gleProgramUniformMatrix4x2dv) bIsLoaded = 0;
	__gleProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)gleIntGetProcAddress("glProgramUniformMatrix3x4dv");
	if(!__gleProgramUniformMatrix3x4dv) bIsLoaded = 0;
	__gleProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)gleIntGetProcAddress("glProgramUniformMatrix4x3dv");
	if(!__gleProgramUniformMatrix4x3dv) bIsLoaded = 0;
	__gleValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)gleIntGetProcAddress("glValidateProgramPipeline");
	if(!__gleValidateProgramPipeline) bIsLoaded = 0;
	__gleGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)gleIntGetProcAddress("glGetProgramPipelineInfoLog");
	if(!__gleGetProgramPipelineInfoLog) bIsLoaded = 0;
	glext_ARB_separate_shader_objects = 1;
	__gleGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)gleIntGetProcAddress("glGetProgramBinary");
	if(!__gleGetProgramBinary) bIsLoaded = 0;
	__gleProgramBinary = (PFNGLPROGRAMBINARYPROC)gleIntGetProcAddress("glProgramBinary");
	if(!__gleProgramBinary) bIsLoaded = 0;
	__gleProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)gleIntGetProcAddress("glProgramParameteri");
	if(!__gleProgramParameteri) bIsLoaded = 0;
	glext_ARB_get_program_binary = 1;
	__gleViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)gleIntGetProcAddress("glViewportArrayv");
	if(!__gleViewportArrayv) bIsLoaded = 0;
	__gleViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)gleIntGetProcAddress("glViewportIndexedf");
	if(!__gleViewportIndexedf) bIsLoaded = 0;
	__gleViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)gleIntGetProcAddress("glViewportIndexedfv");
	if(!__gleViewportIndexedfv) bIsLoaded = 0;
	__gleScissorArrayv = (PFNGLSCISSORARRAYVPROC)gleIntGetProcAddress("glScissorArrayv");
	if(!__gleScissorArrayv) bIsLoaded = 0;
	__gleScissorIndexed = (PFNGLSCISSORINDEXEDPROC)gleIntGetProcAddress("glScissorIndexed");
	if(!__gleScissorIndexed) bIsLoaded = 0;
	__gleScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)gleIntGetProcAddress("glScissorIndexedv");
	if(!__gleScissorIndexedv) bIsLoaded = 0;
	__gleDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)gleIntGetProcAddress("glDepthRangeArrayv");
	if(!__gleDepthRangeArrayv) bIsLoaded = 0;
	__gleDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)gleIntGetProcAddress("glDepthRangeIndexed");
	if(!__gleDepthRangeIndexed) bIsLoaded = 0;
	__gleGetFloati_v = (PFNGLGETFLOATI_VPROC)gleIntGetProcAddress("glGetFloati_v");
	if(!__gleGetFloati_v) bIsLoaded = 0;
	__gleGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)gleIntGetProcAddress("glGetDoublei_v");
	if(!__gleGetDoublei_v) bIsLoaded = 0;
	glext_ARB_viewport_array = 1;
	__gleReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)gleIntGetProcAddress("glReleaseShaderCompiler");
	if(!__gleReleaseShaderCompiler) bIsLoaded = 0;
	__gleShaderBinary = (PFNGLSHADERBINARYPROC)gleIntGetProcAddress("glShaderBinary");
	if(!__gleShaderBinary) bIsLoaded = 0;
	__gleGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)gleIntGetProcAddress("glGetShaderPrecisionFormat");
	if(!__gleGetShaderPrecisionFormat) bIsLoaded = 0;
	__gleDepthRangef = (PFNGLDEPTHRANGEFPROC)gleIntGetProcAddress("glDepthRangef");
	if(!__gleDepthRangef) bIsLoaded = 0;
	__gleClearDepthf = (PFNGLCLEARDEPTHFPROC)gleIntGetProcAddress("glClearDepthf");
	if(!__gleClearDepthf) bIsLoaded = 0;
	glext_ARB_ES2_compatibility = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_4_2_Base()
{
	int bIsLoaded = 1;
	__gleDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)gleIntGetProcAddress("glDrawArraysInstancedBaseInstance");
	if(!__gleDrawArraysInstancedBaseInstance) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseInstance");
	if(!__gleDrawElementsInstancedBaseInstance) bIsLoaded = 0;
	__gleDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)gleIntGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");
	if(!__gleDrawElementsInstancedBaseVertexBaseInstance) bIsLoaded = 0;
	glext_ARB_base_instance = 1;
	__gleGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)gleIntGetProcAddress("glGetActiveAtomicCounterBufferiv");
	if(!__gleGetActiveAtomicCounterBufferiv) bIsLoaded = 0;
	glext_ARB_shader_atomic_counters = 1;
	__gleTexStorage1D = (PFNGLTEXSTORAGE1DPROC)gleIntGetProcAddress("glTexStorage1D");
	if(!__gleTexStorage1D) bIsLoaded = 0;
	__gleTexStorage2D = (PFNGLTEXSTORAGE2DPROC)gleIntGetProcAddress("glTexStorage2D");
	if(!__gleTexStorage2D) bIsLoaded = 0;
	__gleTexStorage3D = (PFNGLTEXSTORAGE3DPROC)gleIntGetProcAddress("glTexStorage3D");
	if(!__gleTexStorage3D) bIsLoaded = 0;
	__gleTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)gleIntGetProcAddress("glTextureStorage1DEXT");
	if(!__gleTextureStorage1DEXT) bIsLoaded = 0;
	__gleTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)gleIntGetProcAddress("glTextureStorage2DEXT");
	if(!__gleTextureStorage2DEXT) bIsLoaded = 0;
	__gleTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)gleIntGetProcAddress("glTextureStorage3DEXT");
	if(!__gleTextureStorage3DEXT) bIsLoaded = 0;
	glext_ARB_texture_storage = 1;
	__gleBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)gleIntGetProcAddress("glBindImageTexture");
	if(!__gleBindImageTexture) bIsLoaded = 0;
	__gleMemoryBarrier = (PFNGLMEMORYBARRIERPROC)gleIntGetProcAddress("glMemoryBarrier");
	if(!__gleMemoryBarrier) bIsLoaded = 0;
	glext_ARB_shader_image_load_store = 1;
	__gleGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)gleIntGetProcAddress("glGetInternalformativ");
	if(!__gleGetInternalformativ) bIsLoaded = 0;
	glext_ARB_internalformat_query = 1;
	__gleDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)gleIntGetProcAddress("glDrawTransformFeedbackInstanced");
	if(!__gleDrawTransformFeedbackInstanced) bIsLoaded = 0;
	__gleDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)gleIntGetProcAddress("glDrawTransformFeedbackStreamInstanced");
	if(!__gleDrawTransformFeedbackStreamInstanced) bIsLoaded = 0;
	glext_ARB_transform_feedback_instanced = 1;
	return bIsLoaded;
}

static int gleIntLoadCore_4_3_Base()
{
	int bIsLoaded = 1;
	__gleCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)gleIntGetProcAddress("glCopyImageSubData");
	if(!__gleCopyImageSubData) bIsLoaded = 0;
	glext_ARB_copy_image = 1;
	__gleGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)gleIntGetProcAddress("glGetProgramInterfaceiv");
	if(!__gleGetProgramInterfaceiv) bIsLoaded = 0;
	__gleGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)gleIntGetProcAddress("glGetProgramResourceIndex");
	if(!__gleGetProgramResourceIndex) bIsLoaded = 0;
	__gleGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)gleIntGetProcAddress("glGetProgramResourceName");
	if(!__gleGetProgramResourceName) bIsLoaded = 0;
	__gleGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)gleIntGetProcAddress("glGetProgramResourceiv");
	if(!__gleGetProgramResourceiv) bIsLoaded = 0;
	__gleGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)gleIntGetProcAddress("glGetProgramResourceLocation");
	if(!__gleGetProgramResourceLocation) bIsLoaded = 0;
	__gleGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)gleIntGetProcAddress("glGetProgramResourceLocationIndex");
	if(!__gleGetProgramResourceLocationIndex) bIsLoaded = 0;
	glext_ARB_program_interface_query = 1;
	__gleTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)gleIntGetProcAddress("glTexBufferRange");
	if(!__gleTexBufferRange) bIsLoaded = 0;
	__gleTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC)gleIntGetProcAddress("glTextureBufferRangeEXT");
	if(!__gleTextureBufferRangeEXT) bIsLoaded = 0;
	glext_ARB_texture_buffer_range = 1;
	__gleDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)gleIntGetProcAddress("glDispatchCompute");
	if(!__gleDispatchCompute) bIsLoaded = 0;
	__gleDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)gleIntGetProcAddress("glDispatchComputeIndirect");
	if(!__gleDispatchComputeIndirect) bIsLoaded = 0;
	glext_ARB_compute_shader = 1;
	__gleTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)gleIntGetProcAddress("glTexStorage2DMultisample");
	if(!__gleTexStorage2DMultisample) bIsLoaded = 0;
	__gleTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)gleIntGetProcAddress("glTexStorage3DMultisample");
	if(!__gleTexStorage3DMultisample) bIsLoaded = 0;
	__gleTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)gleIntGetProcAddress("glTextureStorage2DMultisampleEXT");
	if(!__gleTextureStorage2DMultisampleEXT) bIsLoaded = 0;
	__gleTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)gleIntGetProcAddress("glTextureStorage3DMultisampleEXT");
	if(!__gleTextureStorage3DMultisampleEXT) bIsLoaded = 0;
	glext_ARB_texture_storage_multisample = 1;
	__gleInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)gleIntGetProcAddress("glInvalidateTexSubImage");
	if(!__gleInvalidateTexSubImage) bIsLoaded = 0;
	__gleInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)gleIntGetProcAddress("glInvalidateTexImage");
	if(!__gleInvalidateTexImage) bIsLoaded = 0;
	__gleInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)gleIntGetProcAddress("glInvalidateBufferSubData");
	if(!__gleInvalidateBufferSubData) bIsLoaded = 0;
	__gleInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)gleIntGetProcAddress("glInvalidateBufferData");
	if(!__gleInvalidateBufferData) bIsLoaded = 0;
	__gleInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)gleIntGetProcAddress("glInvalidateFramebuffer");
	if(!__gleInvalidateFramebuffer) bIsLoaded = 0;
	__gleInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)gleIntGetProcAddress("glInvalidateSubFramebuffer");
	if(!__gleInvalidateSubFramebuffer) bIsLoaded = 0;
	glext_ARB_invalidate_subdata = 1;
	__gleClearBufferData = (PFNGLCLEARBUFFERDATAPROC)gleIntGetProcAddress("glClearBufferData");
	if(!__gleClearBufferData) bIsLoaded = 0;
	__gleClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)gleIntGetProcAddress("glClearBufferSubData");
	if(!__gleClearBufferSubData) bIsLoaded = 0;
	__gleClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)gleIntGetProcAddress("glClearNamedBufferDataEXT");
	if(!__gleClearNamedBufferDataEXT) bIsLoaded = 0;
	__gleClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)gleIntGetProcAddress("glClearNamedBufferSubDataEXT");
	if(!__gleClearNamedBufferSubDataEXT) bIsLoaded = 0;
	glext_ARB_clear_buffer_object = 1;
	__gleDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)gleIntGetProcAddress("glDebugMessageControl");
	if(!__gleDebugMessageControl) bIsLoaded = 0;
	__gleDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)gleIntGetProcAddress("glDebugMessageInsert");
	if(!__gleDebugMessageInsert) bIsLoaded = 0;
	__gleDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)gleIntGetProcAddress("glDebugMessageCallback");
	if(!__gleDebugMessageCallback) bIsLoaded = 0;
	__gleGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)gleIntGetProcAddress("glGetDebugMessageLog");
	if(!__gleGetDebugMessageLog) bIsLoaded = 0;
	__glePushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)gleIntGetProcAddress("glPushDebugGroup");
	if(!__glePushDebugGroup) bIsLoaded = 0;
	__glePopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)gleIntGetProcAddress("glPopDebugGroup");
	if(!__glePopDebugGroup) bIsLoaded = 0;
	__gleObjectLabel = (PFNGLOBJECTLABELPROC)gleIntGetProcAddress("glObjectLabel");
	if(!__gleObjectLabel) bIsLoaded = 0;
	__gleGetObjectLabel = (PFNGLGETOBJECTLABELPROC)gleIntGetProcAddress("glGetObjectLabel");
	if(!__gleGetObjectLabel) bIsLoaded = 0;
	__gleObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)gleIntGetProcAddress("glObjectPtrLabel");
	if(!__gleObjectPtrLabel) bIsLoaded = 0;
	__gleGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)gleIntGetProcAddress("glGetObjectPtrLabel");
	if(!__gleGetObjectPtrLabel) bIsLoaded = 0;
	glext_KHR_debug = 1;
	__gleFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)gleIntGetProcAddress("glFramebufferParameteri");
	if(!__gleFramebufferParameteri) bIsLoaded = 0;
	__gleGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)gleIntGetProcAddress("glGetFramebufferParameteriv");
	if(!__gleGetFramebufferParameteriv) bIsLoaded = 0;
	__gleNamedFramebufferParameteriEXT = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)gleIntGetProcAddress("glNamedFramebufferParameteriEXT");
	if(!__gleNamedFramebufferParameteriEXT) bIsLoaded = 0;
	__gleGetNamedFramebufferParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)gleIntGetProcAddress("glGetNamedFramebufferParameterivEXT");
	if(!__gleGetNamedFramebufferParameterivEXT) bIsLoaded = 0;
	glext_ARB_framebuffer_no_attachments = 1;
	__gleShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)gleIntGetProcAddress("glShaderStorageBlockBinding");
	if(!__gleShaderStorageBlockBinding) bIsLoaded = 0;
	glext_ARB_shader_storage_buffer_object = 1;
	__gleBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)gleIntGetProcAddress("glBindVertexBuffer");
	if(!__gleBindVertexBuffer) bIsLoaded = 0;
	__gleVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)gleIntGetProcAddress("glVertexAttribFormat");
	if(!__gleVertexAttribFormat) bIsLoaded = 0;
	__gleVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)gleIntGetProcAddress("glVertexAttribIFormat");
	if(!__gleVertexAttribIFormat) bIsLoaded = 0;
	__gleVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)gleIntGetProcAddress("glVertexAttribLFormat");
	if(!__gleVertexAttribLFormat) bIsLoaded = 0;
	__gleVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)gleIntGetProcAddress("glVertexAttribBinding");
	if(!__gleVertexAttribBinding) bIsLoaded = 0;
	__gleVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)gleIntGetProcAddress("glVertexBindingDivisor");
	if(!__gleVertexBindingDivisor) bIsLoaded = 0;
	__gleVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)gleIntGetProcAddress("glVertexArrayBindVertexBufferEXT");
	if(!__gleVertexArrayBindVertexBufferEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribFormatEXT");
	if(!__gleVertexArrayVertexAttribFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
	if(!__gleVertexArrayVertexAttribIFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
	if(!__gleVertexArrayVertexAttribLFormatEXT) bIsLoaded = 0;
	__gleVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)gleIntGetProcAddress("glVertexArrayVertexAttribBindingEXT");
	if(!__gleVertexArrayVertexAttribBindingEXT) bIsLoaded = 0;
	__gleVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)gleIntGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
	if(!__gleVertexArrayVertexBindingDivisorEXT) bIsLoaded = 0;
	glext_ARB_vertex_attrib_binding = 1;
	__gleTextureView = (PFNGLTEXTUREVIEWPROC)gleIntGetProcAddress("glTextureView");
	if(!__gleTextureView) bIsLoaded = 0;
	glext_ARB_texture_view = 1;
	__gleGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)gleIntGetProcAddress("glGetInternalformati64v");
	if(!__gleGetInternalformati64v) bIsLoaded = 0;
	glext_ARB_internalformat_query2 = 1;
	__gleMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)gleIntGetProcAddress("glMultiDrawArraysIndirect");
	if(!__gleMultiDrawArraysIndirect) bIsLoaded = 0;
	__gleMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)gleIntGetProcAddress("glMultiDrawElementsIndirect");
	if(!__gleMultiDrawElementsIndirect) bIsLoaded = 0;
	glext_ARB_multi_draw_indirect = 1;
	return bIsLoaded;
}

int gleIntLoad_Version_2_1()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_0()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_1()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_1_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_2()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_2_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_3()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_3_3_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_0()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_0_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_1()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_1_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_2()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_2_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_2_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_2_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_3()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Version_3_1()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_3_Base()) bIsLoaded = 0;

	return bIsLoaded;
}

int gleIntLoad_Version_4_3_Comp()
{
	int bIsLoaded = 1;
	gleIntClear();
	if(!gleIntLoadCore_1_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_4_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_1_5_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_2_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_3_3_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_0_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_1_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_2_Base()) bIsLoaded = 0;
	if(!gleIntLoadCore_4_3_Base()) bIsLoaded = 0;

	return bIsLoaded;
}


void gleIntLoadBaseFuncs()
{
	int bIsLoaded = 1; //Unimportant here.
	__gleGetString = (PFNGLGETSTRINGPROC)gleIntGetProcAddress("glGetString");
	if(!__gleGetString) bIsLoaded = 0;
	__gleGetStringi = (PFNGLGETSTRINGIPROC)gleIntGetProcAddress("glGetStringi");
	if(!__gleGetStringi) bIsLoaded = 0;
	__gleGetIntegerv = (PFNGLGETINTEGERVPROC)gleIntGetProcAddress("glGetIntegerv");
	if(!__gleGetIntegerv) bIsLoaded = 0;
}
