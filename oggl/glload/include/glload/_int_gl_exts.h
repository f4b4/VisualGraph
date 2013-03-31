#ifndef _INT_GL_EXTS_H
#define _INT_GL_EXTS_H


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

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern int glext_ARB_imaging;
extern int glext_ARB_multitexture;
extern int glext_ARB_transpose_matrix;
extern int glext_ARB_multisample;
extern int glext_ARB_texture_env_add;
extern int glext_ARB_texture_cube_map;
extern int glext_ARB_texture_compression;
extern int glext_ARB_texture_border_clamp;
extern int glext_ARB_point_parameters;
extern int glext_ARB_vertex_blend;
extern int glext_ARB_matrix_palette;
extern int glext_ARB_texture_env_combine;
extern int glext_ARB_texture_env_crossbar;
extern int glext_ARB_texture_env_dot3;
extern int glext_ARB_texture_mirrored_repeat;
extern int glext_ARB_depth_texture;
extern int glext_ARB_shadow;
extern int glext_ARB_shadow_ambient;
extern int glext_ARB_window_pos;
extern int glext_ARB_vertex_program;
extern int glext_ARB_fragment_program;
extern int glext_ARB_vertex_buffer_object;
extern int glext_ARB_occlusion_query;
extern int glext_ARB_shader_objects;
extern int glext_ARB_vertex_shader;
extern int glext_ARB_fragment_shader;
extern int glext_ARB_shading_language_100;
extern int glext_ARB_texture_non_power_of_two;
extern int glext_ARB_point_sprite;
extern int glext_ARB_fragment_program_shadow;
extern int glext_ARB_draw_buffers;
extern int glext_ARB_texture_rectangle;
extern int glext_ARB_color_buffer_float;
extern int glext_ARB_half_float_pixel;
extern int glext_ARB_texture_float;
extern int glext_ARB_pixel_buffer_object;
extern int glext_ARB_depth_buffer_float;
extern int glext_ARB_draw_instanced;
extern int glext_ARB_framebuffer_object;
extern int glext_ARB_framebuffer_sRGB;
extern int glext_ARB_geometry_shader4;
extern int glext_ARB_half_float_vertex;
extern int glext_ARB_instanced_arrays;
extern int glext_ARB_map_buffer_range;
extern int glext_ARB_texture_buffer_object;
extern int glext_ARB_texture_compression_rgtc;
extern int glext_ARB_texture_rg;
extern int glext_ARB_vertex_array_object;
extern int glext_ARB_uniform_buffer_object;
extern int glext_ARB_compatibility;
extern int glext_ARB_copy_buffer;
extern int glext_ARB_shader_texture_lod;
extern int glext_ARB_depth_clamp;
extern int glext_ARB_draw_elements_base_vertex;
extern int glext_ARB_fragment_coord_conventions;
extern int glext_ARB_provoking_vertex;
extern int glext_ARB_seamless_cube_map;
extern int glext_ARB_sync;
extern int glext_ARB_texture_multisample;
extern int glext_ARB_vertex_array_bgra;
extern int glext_ARB_draw_buffers_blend;
extern int glext_ARB_sample_shading;
extern int glext_ARB_texture_cube_map_array;
extern int glext_ARB_texture_gather;
extern int glext_ARB_texture_query_lod;
extern int glext_ARB_shading_language_include;
extern int glext_ARB_texture_compression_bptc;
extern int glext_ARB_blend_func_extended;
extern int glext_ARB_explicit_attrib_location;
extern int glext_ARB_occlusion_query2;
extern int glext_ARB_sampler_objects;
extern int glext_ARB_shader_bit_encoding;
extern int glext_ARB_texture_rgb10_a2ui;
extern int glext_ARB_texture_swizzle;
extern int glext_ARB_timer_query;
extern int glext_ARB_vertex_type_2_10_10_10_rev;
extern int glext_ARB_draw_indirect;
extern int glext_ARB_gpu_shader5;
extern int glext_ARB_gpu_shader_fp64;
extern int glext_ARB_shader_subroutine;
extern int glext_ARB_tessellation_shader;
extern int glext_ARB_texture_buffer_object_rgb32;
extern int glext_ARB_transform_feedback2;
extern int glext_ARB_transform_feedback3;
extern int glext_ARB_ES2_compatibility;
extern int glext_ARB_get_program_binary;
extern int glext_ARB_separate_shader_objects;
extern int glext_ARB_shader_precision;
extern int glext_ARB_vertex_attrib_64bit;
extern int glext_ARB_viewport_array;
extern int glext_ARB_cl_event;
extern int glext_ARB_debug_output;
extern int glext_ARB_robustness;
extern int glext_ARB_shader_stencil_export;
extern int glext_ARB_base_instance;
extern int glext_ARB_shading_language_420pack;
extern int glext_ARB_transform_feedback_instanced;
extern int glext_ARB_compressed_texture_pixel_storage;
extern int glext_ARB_conservative_depth;
extern int glext_ARB_internalformat_query;
extern int glext_ARB_map_buffer_alignment;
extern int glext_ARB_shader_atomic_counters;
extern int glext_ARB_shader_image_load_store;
extern int glext_ARB_shading_language_packing;
extern int glext_ARB_texture_storage;
extern int glext_KHR_texture_compression_astc_ldr;
extern int glext_KHR_debug;
extern int glext_ARB_arrays_of_arrays;
extern int glext_ARB_clear_buffer_object;
extern int glext_ARB_compute_shader;
extern int glext_ARB_copy_image;
extern int glext_ARB_debug_group;
extern int glext_ARB_debug_label;
extern int glext_ARB_debug_output2;
extern int glext_ARB_ES3_compatibility;
extern int glext_ARB_explicit_uniform_location;
extern int glext_ARB_fragment_layer_viewport;
extern int glext_ARB_framebuffer_no_attachments;
extern int glext_ARB_internalformat_query2;
extern int glext_ARB_invalidate_subdata;
extern int glext_ARB_multi_draw_indirect;
extern int glext_ARB_program_interface_query;
extern int glext_ARB_robust_buffer_access_behavior;
extern int glext_ARB_shader_image_size;
extern int glext_ARB_shader_storage_buffer_object;
extern int glext_ARB_stencil_texturing;
extern int glext_ARB_texture_buffer_range;
extern int glext_ARB_texture_query_levels;
extern int glext_ARB_texture_storage_multisample;
extern int glext_ARB_texture_view;
extern int glext_ARB_vertex_attrib_binding;
extern int glext_ARB_robustness_isolation;
extern int glext_EXT_abgr;
extern int glext_EXT_blend_color;
extern int glext_EXT_polygon_offset;
extern int glext_EXT_texture;
extern int glext_EXT_texture3D;
extern int glext_SGIS_texture_filter4;
extern int glext_EXT_subtexture;
extern int glext_EXT_copy_texture;
extern int glext_EXT_histogram;
extern int glext_EXT_convolution;
extern int glext_SGI_color_matrix;
extern int glext_SGI_color_table;
extern int glext_SGIS_pixel_texture;
extern int glext_SGIX_pixel_texture;
extern int glext_SGIS_texture4D;
extern int glext_SGI_texture_color_table;
extern int glext_EXT_cmyka;
extern int glext_EXT_texture_object;
extern int glext_SGIS_detail_texture;
extern int glext_SGIS_sharpen_texture;
extern int glext_EXT_packed_pixels;
extern int glext_SGIS_texture_lod;
extern int glext_SGIS_multisample;
extern int glext_EXT_rescale_normal;
extern int glext_EXT_vertex_array;
extern int glext_EXT_misc_attribute;
extern int glext_SGIS_generate_mipmap;
extern int glext_SGIX_clipmap;
extern int glext_SGIX_shadow;
extern int glext_SGIS_texture_edge_clamp;
extern int glext_SGIS_texture_border_clamp;
extern int glext_EXT_blend_minmax;
extern int glext_EXT_blend_subtract;
extern int glext_EXT_blend_logic_op;
extern int glext_SGIX_interlace;
extern int glext_SGIX_pixel_tiles;
extern int glext_SGIS_texture_select;
extern int glext_SGIX_sprite;
extern int glext_SGIX_texture_multi_buffer;
extern int glext_EXT_point_parameters;
extern int glext_SGIS_point_parameters;
extern int glext_SGIX_instruments;
extern int glext_SGIX_texture_scale_bias;
extern int glext_SGIX_framezoom;
extern int glext_SGIX_tag_sample_buffer;
extern int glext_FfdMaskSGIX;
extern int glext_SGIX_polynomial_ffd;
extern int glext_SGIX_reference_plane;
extern int glext_SGIX_flush_raster;
extern int glext_SGIX_depth_texture;
extern int glext_SGIS_fog_function;
extern int glext_SGIX_fog_offset;
extern int glext_HP_image_transform;
extern int glext_HP_convolution_border_modes;
extern int glext_INGR_palette_buffer;
extern int glext_SGIX_texture_add_env;
extern int glext_EXT_color_subtable;
extern int glext_PGI_vertex_hints;
extern int glext_PGI_misc_hints;
extern int glext_EXT_paletted_texture;
extern int glext_EXT_clip_volume_hint;
extern int glext_SGIX_list_priority;
extern int glext_SGIX_ir_instrument1;
extern int glext_SGIX_calligraphic_fragment;
extern int glext_SGIX_texture_lod_bias;
extern int glext_SGIX_shadow_ambient;
extern int glext_EXT_index_texture;
extern int glext_EXT_index_material;
extern int glext_EXT_index_func;
extern int glext_EXT_index_array_formats;
extern int glext_EXT_compiled_vertex_array;
extern int glext_EXT_cull_vertex;
extern int glext_SGIX_ycrcb;
extern int glext_SGIX_fragment_lighting;
extern int glext_IBM_rasterpos_clip;
extern int glext_HP_texture_lighting;
extern int glext_EXT_draw_range_elements;
extern int glext_WIN_phong_shading;
extern int glext_WIN_specular_fog;
extern int glext_EXT_light_texture;
extern int glext_SGIX_blend_alpha_minmax;
extern int glext_SGIX_impact_pixel_texture;
extern int glext_EXT_bgra;
extern int glext_SGIX_async;
extern int glext_SGIX_async_pixel;
extern int glext_SGIX_async_histogram;
extern int glext_INTEL_texture_scissor;
extern int glext_INTEL_parallel_arrays;
extern int glext_HP_occlusion_test;
extern int glext_EXT_pixel_transform;
extern int glext_EXT_pixel_transform_color_table;
extern int glext_EXT_shared_texture_palette;
extern int glext_EXT_separate_specular_color;
extern int glext_EXT_secondary_color;
extern int glext_EXT_texture_perturb_normal;
extern int glext_EXT_multi_draw_arrays;
extern int glext_EXT_fog_coord;
extern int glext_REND_screen_coordinates;
extern int glext_EXT_coordinate_frame;
extern int glext_EXT_texture_env_combine;
extern int glext_APPLE_specular_vector;
extern int glext_APPLE_transform_hint;
extern int glext_SGIX_fog_scale;
extern int glext_SUNX_constant_data;
extern int glext_SUN_global_alpha;
extern int glext_SUN_triangle_list;
extern int glext_SUN_vertex;
extern int glext_EXT_blend_func_separate;
extern int glext_INGR_color_clamp;
extern int glext_INGR_interlace_read;
extern int glext_EXT_stencil_wrap;
extern int glext_EXT_422_pixels;
extern int glext_NV_texgen_reflection;
extern int glext_EXT_texture_cube_map;
extern int glext_SUN_convolution_border_modes;
extern int glext_EXT_texture_env_add;
extern int glext_EXT_texture_lod_bias;
extern int glext_EXT_texture_filter_anisotropic;
extern int glext_EXT_vertex_weighting;
extern int glext_NV_light_max_exponent;
extern int glext_NV_vertex_array_range;
extern int glext_NV_register_combiners;
extern int glext_NV_fog_distance;
extern int glext_NV_texgen_emboss;
extern int glext_NV_blend_square;
extern int glext_NV_texture_env_combine4;
extern int glext_MESA_resize_buffers;
extern int glext_MESA_window_pos;
extern int glext_EXT_texture_compression_s3tc;
extern int glext_IBM_cull_vertex;
extern int glext_IBM_multimode_draw_arrays;
extern int glext_IBM_vertex_array_lists;
extern int glext_SGIX_subsample;
extern int glext_SGIX_ycrcb_subsample;
extern int glext_SGIX_ycrcba;
extern int glext_SGI_depth_pass_instrument;
extern int glext_3DFX_texture_compression_FXT1;
extern int glext_3DFX_multisample;
extern int glext_3DFX_tbuffer;
extern int glext_EXT_multisample;
extern int glext_SGIX_vertex_preclip;
extern int glext_SGIX_convolution_accuracy;
extern int glext_SGIX_resample;
extern int glext_SGIS_point_line_texgen;
extern int glext_SGIS_texture_color_mask;
extern int glext_EXT_texture_env_dot3;
extern int glext_ATI_texture_mirror_once;
extern int glext_NV_fence;
extern int glext_IBM_texture_mirrored_repeat;
extern int glext_NV_evaluators;
extern int glext_NV_packed_depth_stencil;
extern int glext_NV_register_combiners2;
extern int glext_NV_texture_compression_vtc;
extern int glext_NV_texture_rectangle;
extern int glext_NV_texture_shader;
extern int glext_NV_texture_shader2;
extern int glext_NV_vertex_array_range2;
extern int glext_NV_vertex_program;
extern int glext_SGIX_texture_coordinate_clamp;
extern int glext_SGIX_scalebias_hint;
extern int glext_OML_interlace;
extern int glext_OML_subsample;
extern int glext_OML_resample;
extern int glext_NV_copy_depth_to_color;
extern int glext_ATI_envmap_bumpmap;
extern int glext_ATI_fragment_shader;
extern int glext_ATI_pn_triangles;
extern int glext_ATI_vertex_array_object;
extern int glext_EXT_vertex_shader;
extern int glext_ATI_vertex_streams;
extern int glext_ATI_element_array;
extern int glext_SUN_mesh_array;
extern int glext_SUN_slice_accum;
extern int glext_NV_multisample_filter_hint;
extern int glext_NV_depth_clamp;
extern int glext_NV_occlusion_query;
extern int glext_NV_point_sprite;
extern int glext_NV_texture_shader3;
extern int glext_NV_vertex_program1_1;
extern int glext_EXT_shadow_funcs;
extern int glext_EXT_stencil_two_side;
extern int glext_ATI_text_fragment_shader;
extern int glext_APPLE_client_storage;
extern int glext_APPLE_element_array;
extern int glext_APPLE_fence;
extern int glext_APPLE_vertex_array_object;
extern int glext_APPLE_vertex_array_range;
extern int glext_APPLE_ycbcr_422;
extern int glext_S3_s3tc;
extern int glext_ATI_draw_buffers;
extern int glext_ATI_pixel_format_float;
extern int glext_ATI_texture_env_combine3;
extern int glext_ATI_texture_float;
extern int glext_NV_float_buffer;
extern int glext_NV_fragment_program;
extern int glext_NV_half_float;
extern int glext_NV_pixel_data_range;
extern int glext_NV_primitive_restart;
extern int glext_NV_texture_expand_normal;
extern int glext_NV_vertex_program2;
extern int glext_ATI_map_object_buffer;
extern int glext_ATI_separate_stencil;
extern int glext_ATI_vertex_attrib_array_object;
extern int glext_OES_read_format;
extern int glext_EXT_depth_bounds_test;
extern int glext_EXT_texture_mirror_clamp;
extern int glext_EXT_blend_equation_separate;
extern int glext_MESA_pack_invert;
extern int glext_MESA_ycbcr_texture;
extern int glext_EXT_pixel_buffer_object;
extern int glext_NV_fragment_program_option;
extern int glext_NV_fragment_program2;
extern int glext_NV_vertex_program2_option;
extern int glext_NV_vertex_program3;
extern int glext_EXT_framebuffer_object;
extern int glext_GREMEDY_string_marker;
extern int glext_EXT_packed_depth_stencil;
extern int glext_EXT_stencil_clear_tag;
extern int glext_EXT_texture_sRGB;
extern int glext_EXT_framebuffer_blit;
extern int glext_EXT_framebuffer_multisample;
extern int glext_MESAX_texture_stack;
extern int glext_EXT_timer_query;
extern int glext_EXT_gpu_program_parameters;
extern int glext_APPLE_flush_buffer_range;
extern int glext_NV_gpu_program4;
extern int glext_NV_geometry_program4;
extern int glext_EXT_geometry_shader4;
extern int glext_NV_vertex_program4;
extern int glext_EXT_gpu_shader4;
extern int glext_EXT_draw_instanced;
extern int glext_EXT_packed_float;
extern int glext_EXT_texture_array;
extern int glext_EXT_texture_buffer_object;
extern int glext_EXT_texture_compression_latc;
extern int glext_EXT_texture_compression_rgtc;
extern int glext_EXT_texture_shared_exponent;
extern int glext_NV_depth_buffer_float;
extern int glext_NV_fragment_program4;
extern int glext_NV_framebuffer_multisample_coverage;
extern int glext_EXT_framebuffer_sRGB;
extern int glext_NV_geometry_shader4;
extern int glext_NV_parameter_buffer_object;
extern int glext_EXT_draw_buffers2;
extern int glext_NV_transform_feedback;
extern int glext_EXT_bindable_uniform;
extern int glext_EXT_texture_integer;
extern int glext_GREMEDY_frame_terminator;
extern int glext_NV_conditional_render;
extern int glext_NV_present_video;
extern int glext_EXT_transform_feedback;
extern int glext_EXT_direct_state_access;
extern int glext_EXT_vertex_array_bgra;
extern int glext_EXT_texture_swizzle;
extern int glext_NV_explicit_multisample;
extern int glext_NV_transform_feedback2;
extern int glext_ATI_meminfo;
extern int glext_AMD_performance_monitor;
extern int glext_AMD_texture_texture4;
extern int glext_AMD_vertex_shader_tessellator;
extern int glext_EXT_provoking_vertex;
extern int glext_EXT_texture_snorm;
extern int glext_AMD_draw_buffers_blend;
extern int glext_APPLE_texture_range;
extern int glext_APPLE_float_pixels;
extern int glext_APPLE_vertex_program_evaluators;
extern int glext_APPLE_aux_depth_stencil;
extern int glext_APPLE_object_purgeable;
extern int glext_APPLE_row_bytes;
extern int glext_APPLE_rgb_422;
extern int glext_NV_video_capture;
extern int glext_NV_copy_image;
extern int glext_EXT_separate_shader_objects;
extern int glext_NV_parameter_buffer_object2;
extern int glext_NV_shader_buffer_load;
extern int glext_NV_vertex_buffer_unified_memory;
extern int glext_NV_texture_barrier;
extern int glext_AMD_shader_stencil_export;
extern int glext_AMD_seamless_cubemap_per_texture;
extern int glext_AMD_conservative_depth;
extern int glext_EXT_shader_image_load_store;
extern int glext_EXT_vertex_attrib_64bit;
extern int glext_NV_gpu_program5;
extern int glext_NV_gpu_shader5;
extern int glext_NV_shader_buffer_store;
extern int glext_NV_tessellation_program5;
extern int glext_NV_vertex_attrib_integer_64bit;
extern int glext_NV_multisample_coverage;
extern int glext_AMD_name_gen_delete;
extern int glext_AMD_debug_output;
extern int glext_NV_vdpau_interop;
extern int glext_AMD_transform_feedback3_lines_triangles;
extern int glext_AMD_depth_clamp_separate;
extern int glext_EXT_texture_sRGB_decode;
extern int glext_NV_texture_multisample;
extern int glext_AMD_blend_minmax_factor;
extern int glext_AMD_sample_positions;
extern int glext_EXT_x11_sync_object;
extern int glext_AMD_multi_draw_indirect;
extern int glext_EXT_framebuffer_multisample_blit_scaled;
extern int glext_NV_path_rendering;
extern int glext_AMD_pinned_memory;
extern int glext_AMD_stencil_operation_extended;
extern int glext_AMD_vertex_shader_viewport_index;
extern int glext_AMD_vertex_shader_layer;
extern int glext_NV_bindless_texture;
extern int glext_NV_shader_atomic_float;
extern int glext_AMD_query_buffer_object;


/******************************
* Extension: GL_3DFX_multisample
******************************/

#define GL_MULTISAMPLE_3DFX 0x86B2
#define GL_SAMPLE_BUFFERS_3DFX 0x86B3
#define GL_SAMPLES_3DFX 0x86B4
#define GL_MULTISAMPLE_BIT_3DFX 0x20000000


/******************************
* Extension: GL_3DFX_tbuffer
******************************/

#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1

typedef void (GLE_FUNCPTR * PFNGLTBUFFERMASK3DFXPROC)(GLuint );

extern PFNGLTBUFFERMASK3DFXPROC glTbufferMask3DFX;
#endif /*GL_3DFX_tbuffer*/

/******************************
* Extension: GL_3DFX_texture_compression_FXT1
******************************/

#define GL_COMPRESSED_RGB_FXT1_3DFX 0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX 0x86B1


/******************************
* Extension: GL_AMD_blend_minmax_factor
******************************/

#define GL_FACTOR_MIN_AMD 0x901C
#define GL_FACTOR_MAX_AMD 0x901D


/******************************
* Extension: GL_AMD_conservative_depth
******************************/

/******************************
* Extension: GL_AMD_debug_output
******************************/

#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD 0x9144
#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD 0x9143
#define GL_DEBUG_LOGGED_MESSAGES_AMD 0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD 0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD 0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD 0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD 0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD 0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD 0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD 0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD 0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD 0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD 0x9150


#ifndef GL_AMD_debug_output
#define GL_AMD_debug_output 1

typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEENABLEAMDPROC)(GLenum , GLenum , GLsizei , const GLuint *, GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEINSERTAMDPROC)(GLenum , GLenum , GLuint , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECALLBACKAMDPROC)(GLDEBUGPROCAMD , GLvoid *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETDEBUGMESSAGELOGAMDPROC)(GLuint , GLsizei , GLenum *, GLuint *, GLuint *, GLsizei *, GLchar *);

extern PFNGLDEBUGMESSAGEENABLEAMDPROC glDebugMessageEnableAMD;
extern PFNGLDEBUGMESSAGEINSERTAMDPROC glDebugMessageInsertAMD;
extern PFNGLDEBUGMESSAGECALLBACKAMDPROC glDebugMessageCallbackAMD;
extern PFNGLGETDEBUGMESSAGELOGAMDPROC glGetDebugMessageLogAMD;
#endif /*GL_AMD_debug_output*/

/******************************
* Extension: GL_AMD_depth_clamp_separate
******************************/

#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E
#define GL_DEPTH_CLAMP_FAR_AMD 0x901F


/******************************
* Extension: GL_AMD_draw_buffers_blend
******************************/

#ifndef GL_AMD_draw_buffers_blend
#define GL_AMD_draw_buffers_blend 1

typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCINDEXEDAMDPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONINDEXEDAMDPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)(GLuint , GLenum , GLenum );

extern PFNGLBLENDFUNCINDEXEDAMDPROC glBlendFuncIndexedAMD;
extern PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC glBlendFuncSeparateIndexedAMD;
extern PFNGLBLENDEQUATIONINDEXEDAMDPROC glBlendEquationIndexedAMD;
extern PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC glBlendEquationSeparateIndexedAMD;
#endif /*GL_AMD_draw_buffers_blend*/

/******************************
* Extension: GL_AMD_multi_draw_indirect
******************************/

#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1

typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)(GLenum , const GLvoid *, GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)(GLenum , GLenum , const GLvoid *, GLsizei , GLsizei );

extern PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC glMultiDrawArraysIndirectAMD;
extern PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC glMultiDrawElementsIndirectAMD;
#endif /*GL_AMD_multi_draw_indirect*/

/******************************
* Extension: GL_AMD_name_gen_delete
******************************/

#define GL_DATA_BUFFER_AMD 0x9151
#define GL_PERFORMANCE_MONITOR_AMD 0x9152
#define GL_QUERY_OBJECT_AMD 0x9153
#define GL_VERTEX_ARRAY_OBJECT_AMD 0x9154
#define GL_SAMPLER_OBJECT_AMD 0x9155


#ifndef GL_AMD_name_gen_delete
#define GL_AMD_name_gen_delete 1

typedef void (GLE_FUNCPTR * PFNGLGENNAMESAMDPROC)(GLenum , GLuint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETENAMESAMDPROC)(GLenum , GLuint , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISNAMEAMDPROC)(GLenum , GLuint );

extern PFNGLGENNAMESAMDPROC glGenNamesAMD;
extern PFNGLDELETENAMESAMDPROC glDeleteNamesAMD;
extern PFNGLISNAMEAMDPROC glIsNameAMD;
#endif /*GL_AMD_name_gen_delete*/

/******************************
* Extension: GL_AMD_performance_monitor
******************************/

#define GL_COUNTER_TYPE_AMD 0x8BC0
#define GL_COUNTER_RANGE_AMD 0x8BC1
#define GL_UNSIGNED_INT64_AMD 0x8BC2
#define GL_PERCENTAGE_AMD 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD 0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD 0x8BC5
#define GL_PERFMON_RESULT_AMD 0x8BC6


#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1

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

extern PFNGLGETPERFMONITORGROUPSAMDPROC glGetPerfMonitorGroupsAMD;
extern PFNGLGETPERFMONITORCOUNTERSAMDPROC glGetPerfMonitorCountersAMD;
extern PFNGLGETPERFMONITORGROUPSTRINGAMDPROC glGetPerfMonitorGroupStringAMD;
extern PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC glGetPerfMonitorCounterStringAMD;
extern PFNGLGETPERFMONITORCOUNTERINFOAMDPROC glGetPerfMonitorCounterInfoAMD;
extern PFNGLGENPERFMONITORSAMDPROC glGenPerfMonitorsAMD;
extern PFNGLDELETEPERFMONITORSAMDPROC glDeletePerfMonitorsAMD;
extern PFNGLSELECTPERFMONITORCOUNTERSAMDPROC glSelectPerfMonitorCountersAMD;
extern PFNGLBEGINPERFMONITORAMDPROC glBeginPerfMonitorAMD;
extern PFNGLENDPERFMONITORAMDPROC glEndPerfMonitorAMD;
extern PFNGLGETPERFMONITORCOUNTERDATAAMDPROC glGetPerfMonitorCounterDataAMD;
#endif /*GL_AMD_performance_monitor*/

/******************************
* Extension: GL_AMD_pinned_memory
******************************/

#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160


/******************************
* Extension: GL_AMD_query_buffer_object
******************************/

#define GL_QUERY_BUFFER_AMD 0x9192
#define GL_QUERY_BUFFER_BINDING_AMD 0x9193
#define GL_QUERY_RESULT_NO_WAIT_AMD 0x9194


/******************************
* Extension: GL_AMD_sample_positions
******************************/

#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F


#ifndef GL_AMD_sample_positions
#define GL_AMD_sample_positions 1

typedef void (GLE_FUNCPTR * PFNGLSETMULTISAMPLEFVAMDPROC)(GLenum , GLuint , const GLfloat *);

extern PFNGLSETMULTISAMPLEFVAMDPROC glSetMultisamplefvAMD;
#endif /*GL_AMD_sample_positions*/

/******************************
* Extension: GL_AMD_seamless_cubemap_per_texture
******************************/

/******************************
* Extension: GL_AMD_shader_stencil_export
******************************/

/******************************
* Extension: GL_AMD_stencil_operation_extended
******************************/

#define GL_SET_AMD 0x874A
#define GL_REPLACE_VALUE_AMD 0x874B
#define GL_STENCIL_OP_VALUE_AMD 0x874C
#define GL_STENCIL_BACK_OP_VALUE_AMD 0x874D


#ifndef GL_AMD_stencil_operation_extended
#define GL_AMD_stencil_operation_extended 1

typedef void (GLE_FUNCPTR * PFNGLSTENCILOPVALUEAMDPROC)(GLenum , GLuint );

extern PFNGLSTENCILOPVALUEAMDPROC glStencilOpValueAMD;
#endif /*GL_AMD_stencil_operation_extended*/

/******************************
* Extension: GL_AMD_texture_texture4
******************************/

/******************************
* Extension: GL_AMD_transform_feedback3_lines_triangles
******************************/

/******************************
* Extension: GL_AMD_vertex_shader_layer
******************************/

/******************************
* Extension: GL_AMD_vertex_shader_tessellator
******************************/

#define GL_SAMPLER_BUFFER_AMD 0x9001
#define GL_INT_SAMPLER_BUFFER_AMD 0x9002
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD 0x9003
#define GL_TESSELLATION_MODE_AMD 0x9004
#define GL_TESSELLATION_FACTOR_AMD 0x9005
#define GL_DISCRETE_AMD 0x9006
#define GL_CONTINUOUS_AMD 0x9007


#ifndef GL_AMD_vertex_shader_tessellator
#define GL_AMD_vertex_shader_tessellator 1

typedef void (GLE_FUNCPTR * PFNGLTESSELLATIONFACTORAMDPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTESSELLATIONMODEAMDPROC)(GLenum );

extern PFNGLTESSELLATIONFACTORAMDPROC glTessellationFactorAMD;
extern PFNGLTESSELLATIONMODEAMDPROC glTessellationModeAMD;
#endif /*GL_AMD_vertex_shader_tessellator*/

/******************************
* Extension: GL_AMD_vertex_shader_viewport_index
******************************/

/******************************
* Extension: GL_APPLE_aux_depth_stencil
******************************/

#define GL_AUX_DEPTH_STENCIL_APPLE 0x8A14


/******************************
* Extension: GL_APPLE_client_storage
******************************/

#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2


/******************************
* Extension: GL_APPLE_element_array
******************************/

#define GL_ELEMENT_ARRAY_APPLE 0x8A0C
#define GL_ELEMENT_ARRAY_TYPE_APPLE 0x8A0D
#define GL_ELEMENT_ARRAY_POINTER_APPLE 0x8A0E


#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1

typedef void (GLE_FUNCPTR * PFNGLELEMENTPOINTERAPPLEPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTARRAYAPPLEPROC)(GLenum , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum , GLuint , GLuint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)(GLenum , GLuint , GLuint , const GLint *, const GLsizei *, GLsizei );

extern PFNGLELEMENTPOINTERAPPLEPROC glElementPointerAPPLE;
extern PFNGLDRAWELEMENTARRAYAPPLEPROC glDrawElementArrayAPPLE;
extern PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC glDrawRangeElementArrayAPPLE;
extern PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC glMultiDrawElementArrayAPPLE;
extern PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC glMultiDrawRangeElementArrayAPPLE;
#endif /*GL_APPLE_element_array*/

/******************************
* Extension: GL_APPLE_fence
******************************/

#define GL_DRAW_PIXELS_APPLE 0x8A0A
#define GL_FENCE_APPLE 0x8A0B


#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1

typedef void (GLE_FUNCPTR * PFNGLGENFENCESAPPLEPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEFENCESAPPLEPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSETFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTFENCEAPPLEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLFINISHFENCEAPPLEPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTOBJECTAPPLEPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLFINISHOBJECTAPPLEPROC)(GLenum , GLint );

extern PFNGLGENFENCESAPPLEPROC glGenFencesAPPLE;
extern PFNGLDELETEFENCESAPPLEPROC glDeleteFencesAPPLE;
extern PFNGLSETFENCEAPPLEPROC glSetFenceAPPLE;
extern PFNGLISFENCEAPPLEPROC glIsFenceAPPLE;
extern PFNGLTESTFENCEAPPLEPROC glTestFenceAPPLE;
extern PFNGLFINISHFENCEAPPLEPROC glFinishFenceAPPLE;
extern PFNGLTESTOBJECTAPPLEPROC glTestObjectAPPLE;
extern PFNGLFINISHOBJECTAPPLEPROC glFinishObjectAPPLE;
#endif /*GL_APPLE_fence*/

/******************************
* Extension: GL_APPLE_float_pixels
******************************/

#define GL_HALF_APPLE 0x140B
#define GL_RGBA_FLOAT32_APPLE 0x8814
#define GL_RGB_FLOAT32_APPLE 0x8815
#define GL_ALPHA_FLOAT32_APPLE 0x8816
#define GL_INTENSITY_FLOAT32_APPLE 0x8817
#define GL_LUMINANCE_FLOAT32_APPLE 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE 0x8819
#define GL_RGBA_FLOAT16_APPLE 0x881A
#define GL_RGB_FLOAT16_APPLE 0x881B
#define GL_ALPHA_FLOAT16_APPLE 0x881C
#define GL_INTENSITY_FLOAT16_APPLE 0x881D
#define GL_LUMINANCE_FLOAT16_APPLE 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE 0x881F
#define GL_COLOR_FLOAT_APPLE 0x8A0F


/******************************
* Extension: GL_APPLE_flush_buffer_range
******************************/

#define GL_BUFFER_SERIALIZED_MODIFY_APPLE 0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE 0x8A13


#ifndef GL_APPLE_flush_buffer_range
#define GL_APPLE_flush_buffer_range 1

typedef void (GLE_FUNCPTR * PFNGLBUFFERPARAMETERIAPPLEPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)(GLenum , GLintptr , GLsizeiptr );

extern PFNGLBUFFERPARAMETERIAPPLEPROC glBufferParameteriAPPLE;
extern PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC glFlushMappedBufferRangeAPPLE;
#endif /*GL_APPLE_flush_buffer_range*/

/******************************
* Extension: GL_APPLE_object_purgeable
******************************/

#define GL_BUFFER_OBJECT_APPLE 0x85B3
#define GL_RELEASED_APPLE 0x8A19
#define GL_VOLATILE_APPLE 0x8A1A
#define GL_RETAINED_APPLE 0x8A1B
#define GL_UNDEFINED_APPLE 0x8A1C
#define GL_PURGEABLE_APPLE 0x8A1D


#ifndef GL_APPLE_object_purgeable
#define GL_APPLE_object_purgeable 1

typedef GLenum (GLE_FUNCPTR * PFNGLOBJECTPURGEABLEAPPLEPROC)(GLenum , GLuint , GLenum );
typedef GLenum (GLE_FUNCPTR * PFNGLOBJECTUNPURGEABLEAPPLEPROC)(GLenum , GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETOBJECTPARAMETERIVAPPLEPROC)(GLenum , GLuint , GLenum , GLint *);

extern PFNGLOBJECTPURGEABLEAPPLEPROC glObjectPurgeableAPPLE;
extern PFNGLOBJECTUNPURGEABLEAPPLEPROC glObjectUnpurgeableAPPLE;
extern PFNGLGETOBJECTPARAMETERIVAPPLEPROC glGetObjectParameterivAPPLE;
#endif /*GL_APPLE_object_purgeable*/

/******************************
* Extension: GL_APPLE_rgb_422
******************************/

#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB
#define GL_RGB_422_APPLE 0x8A1F


/******************************
* Extension: GL_APPLE_row_bytes
******************************/

#define GL_PACK_ROW_BYTES_APPLE 0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE 0x8A16


/******************************
* Extension: GL_APPLE_specular_vector
******************************/

#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE 0x85B0


/******************************
* Extension: GL_APPLE_texture_range
******************************/

#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_STORAGE_SHARED_APPLE 0x85BF
#define GL_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#define GL_STORAGE_PRIVATE_APPLE 0x85BD


#ifndef GL_APPLE_texture_range
#define GL_APPLE_texture_range 1

typedef void (GLE_FUNCPTR * PFNGLTEXTURERANGEAPPLEPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)(GLenum , GLenum , GLvoid* *);

extern PFNGLTEXTURERANGEAPPLEPROC glTextureRangeAPPLE;
extern PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC glGetTexParameterPointervAPPLE;
#endif /*GL_APPLE_texture_range*/

/******************************
* Extension: GL_APPLE_transform_hint
******************************/

#define GL_TRANSFORM_HINT_APPLE 0x85B1


/******************************
* Extension: GL_APPLE_vertex_array_object
******************************/

#define GL_VERTEX_ARRAY_BINDING_APPLE 0x85B5


#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1

typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXARRAYAPPLEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEVERTEXARRAYSAPPLEPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENVERTEXARRAYSAPPLEPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXARRAYAPPLEPROC)(GLuint );

extern PFNGLBINDVERTEXARRAYAPPLEPROC glBindVertexArrayAPPLE;
extern PFNGLDELETEVERTEXARRAYSAPPLEPROC glDeleteVertexArraysAPPLE;
extern PFNGLGENVERTEXARRAYSAPPLEPROC glGenVertexArraysAPPLE;
extern PFNGLISVERTEXARRAYAPPLEPROC glIsVertexArrayAPPLE;
#endif /*GL_APPLE_vertex_array_object*/

/******************************
* Extension: GL_APPLE_vertex_array_range
******************************/

#define GL_VERTEX_ARRAY_RANGE_APPLE 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE 0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE 0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE 0x8521
#define GL_STORAGE_CLIENT_APPLE 0x85B4
#define GL_STORAGE_CACHED_APPLE 0x85BE
#define GL_STORAGE_SHARED_APPLE 0x85BF


#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1

typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYRANGEAPPLEPROC)(GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)(GLsizei , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)(GLenum , GLint );

extern PFNGLVERTEXARRAYRANGEAPPLEPROC glVertexArrayRangeAPPLE;
extern PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC glFlushVertexArrayRangeAPPLE;
extern PFNGLVERTEXARRAYPARAMETERIAPPLEPROC glVertexArrayParameteriAPPLE;
#endif /*GL_APPLE_vertex_array_range*/

/******************************
* Extension: GL_APPLE_vertex_program_evaluators
******************************/

#define GL_VERTEX_ATTRIB_MAP1_APPLE 0x8A00
#define GL_VERTEX_ATTRIB_MAP2_APPLE 0x8A01
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE 0x8A02
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE 0x8A03
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE 0x8A04
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE 0x8A05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE 0x8A06
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE 0x8A07
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE 0x8A08
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE 0x8A09


#ifndef GL_APPLE_vertex_program_evaluators
#define GL_APPLE_vertex_program_evaluators 1

typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXATTRIBAPPLEPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXATTRIBAPPLEPROC)(GLuint , GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB1DAPPLEPROC)(GLuint , GLuint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB1FAPPLEPROC)(GLuint , GLuint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB2DAPPLEPROC)(GLuint , GLuint , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAPVERTEXATTRIB2FAPPLEPROC)(GLuint , GLuint , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);

extern PFNGLENABLEVERTEXATTRIBAPPLEPROC glEnableVertexAttribAPPLE;
extern PFNGLDISABLEVERTEXATTRIBAPPLEPROC glDisableVertexAttribAPPLE;
extern PFNGLISVERTEXATTRIBENABLEDAPPLEPROC glIsVertexAttribEnabledAPPLE;
extern PFNGLMAPVERTEXATTRIB1DAPPLEPROC glMapVertexAttrib1dAPPLE;
extern PFNGLMAPVERTEXATTRIB1FAPPLEPROC glMapVertexAttrib1fAPPLE;
extern PFNGLMAPVERTEXATTRIB2DAPPLEPROC glMapVertexAttrib2dAPPLE;
extern PFNGLMAPVERTEXATTRIB2FAPPLEPROC glMapVertexAttrib2fAPPLE;
#endif /*GL_APPLE_vertex_program_evaluators*/

/******************************
* Extension: GL_APPLE_ycbcr_422
******************************/

#define GL_YCBCR_422_APPLE 0x85B9
#define GL_UNSIGNED_SHORT_8_8_APPLE 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE 0x85BB


/******************************
* Extension: GL_ARB_ES2_compatibility
******************************/

#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_COMPILER 0x8DFA
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_RGB565 0x8D62


#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1

typedef void (GLE_FUNCPTR * PFNGLRELEASESHADERCOMPILERPROC)();
typedef void (GLE_FUNCPTR * PFNGLSHADERBINARYPROC)(GLsizei , const GLuint *, GLenum , const GLvoid *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum , GLenum , GLint *, GLint *);
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEFPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHFPROC)(GLfloat );

extern PFNGLRELEASESHADERCOMPILERPROC __gleReleaseShaderCompiler;
#define glReleaseShaderCompiler __gleReleaseShaderCompiler
extern PFNGLSHADERBINARYPROC __gleShaderBinary;
#define glShaderBinary __gleShaderBinary
extern PFNGLGETSHADERPRECISIONFORMATPROC __gleGetShaderPrecisionFormat;
#define glGetShaderPrecisionFormat __gleGetShaderPrecisionFormat
extern PFNGLDEPTHRANGEFPROC __gleDepthRangef;
#define glDepthRangef __gleDepthRangef
extern PFNGLCLEARDEPTHFPROC __gleClearDepthf;
#define glClearDepthf __gleClearDepthf
#endif /*GL_ARB_ES2_compatibility*/

/******************************
* Extension: GL_ARB_ES3_compatibility
******************************/

#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX 0x8D6B


/******************************
* Extension: GL_ARB_arrays_of_arrays
******************************/

/******************************
* Extension: GL_ARB_base_instance
******************************/

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1

typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)(GLenum , GLint , GLsizei , GLsizei , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)(GLenum , GLsizei , GLenum , const void *, GLsizei , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)(GLenum , GLsizei , GLenum , const void *, GLsizei , GLint , GLuint );

extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC __gleDrawArraysInstancedBaseInstance;
#define glDrawArraysInstancedBaseInstance __gleDrawArraysInstancedBaseInstance
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC __gleDrawElementsInstancedBaseInstance;
#define glDrawElementsInstancedBaseInstance __gleDrawElementsInstancedBaseInstance
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC __gleDrawElementsInstancedBaseVertexBaseInstance;
#define glDrawElementsInstancedBaseVertexBaseInstance __gleDrawElementsInstancedBaseVertexBaseInstance
#endif /*GL_ARB_base_instance*/

/******************************
* Extension: GL_ARB_blend_func_extended
******************************/

#define GL_SRC1_ALPHA 0x8589
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC


#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1

typedef void (GLE_FUNCPTR * PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)(GLuint , GLuint , GLuint , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETFRAGDATAINDEXPROC)(GLuint , const GLchar *);

extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC __gleBindFragDataLocationIndexed;
#define glBindFragDataLocationIndexed __gleBindFragDataLocationIndexed
extern PFNGLGETFRAGDATAINDEXPROC __gleGetFragDataIndex;
#define glGetFragDataIndex __gleGetFragDataIndex
#endif /*GL_ARB_blend_func_extended*/

/******************************
* Extension: GL_ARB_cl_event
******************************/

#define GL_SYNC_CL_EVENT_ARB 0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB 0x8241


#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1

typedef GLsync (GLE_FUNCPTR * PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context * , struct _cl_event * , GLbitfield );

extern PFNGLCREATESYNCFROMCLEVENTARBPROC glCreateSyncFromCLeventARB;
#endif /*GL_ARB_cl_event*/

/******************************
* Extension: GL_ARB_clear_buffer_object
******************************/

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERDATAPROC)(GLenum , GLenum , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERSUBDATAPROC)(GLenum , GLenum , GLintptr , GLsizeiptr , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARNAMEDBUFFERDATAEXTPROC)(GLuint , GLenum , GLenum , GLenum , const void *);
typedef void (GLE_FUNCPTR * PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)(GLuint , GLenum , GLenum , GLenum , GLsizeiptr , GLsizeiptr , const void *);

extern PFNGLCLEARBUFFERDATAPROC __gleClearBufferData;
#define glClearBufferData __gleClearBufferData
extern PFNGLCLEARBUFFERSUBDATAPROC __gleClearBufferSubData;
#define glClearBufferSubData __gleClearBufferSubData
extern PFNGLCLEARNAMEDBUFFERDATAEXTPROC __gleClearNamedBufferDataEXT;
#define glClearNamedBufferDataEXT __gleClearNamedBufferDataEXT
extern PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC __gleClearNamedBufferSubDataEXT;
#define glClearNamedBufferSubDataEXT __gleClearNamedBufferSubDataEXT
#endif /*GL_ARB_clear_buffer_object*/

/******************************
* Extension: GL_ARB_color_buffer_float
******************************/

#define GL_RGBA_FLOAT_MODE_ARB 0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB 0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB 0x891B
#define GL_CLAMP_READ_COLOR_ARB 0x891C
#define GL_FIXED_ONLY_ARB 0x891D


#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1

typedef void (GLE_FUNCPTR * PFNGLCLAMPCOLORARBPROC)(GLenum , GLenum );

extern PFNGLCLAMPCOLORARBPROC glClampColorARB;
#endif /*GL_ARB_color_buffer_float*/

/******************************
* Extension: GL_ARB_compatibility
******************************/

/******************************
* Extension: GL_ARB_compressed_texture_pixel_storage
******************************/

#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E


/******************************
* Extension: GL_ARB_compute_shader
******************************/

#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_LOCAL_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_COMPUTE_LOCAL_WORK_SIZE 0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT 0x00000020


#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1

typedef void (GLE_FUNCPTR * PFNGLDISPATCHCOMPUTEPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr );

extern PFNGLDISPATCHCOMPUTEPROC __gleDispatchCompute;
#define glDispatchCompute __gleDispatchCompute
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC __gleDispatchComputeIndirect;
#define glDispatchComputeIndirect __gleDispatchComputeIndirect
#endif /*GL_ARB_compute_shader*/

/******************************
* Extension: GL_ARB_conservative_depth
******************************/

/******************************
* Extension: GL_ARB_copy_buffer
******************************/

#define GL_COPY_READ_BUFFER 0x8F36 /* GL_COPY_READ_BUFFER_BINDING */
#define GL_COPY_WRITE_BUFFER 0x8F37 /* GL_COPY_WRITE_BUFFER_BINDING */
#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37


#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1

typedef void (GLE_FUNCPTR * PFNGLCOPYBUFFERSUBDATAPROC)(GLenum , GLenum , GLintptr , GLintptr , GLsizeiptr );

extern PFNGLCOPYBUFFERSUBDATAPROC __gleCopyBufferSubData;
#define glCopyBufferSubData __gleCopyBufferSubData
#endif /*GL_ARB_copy_buffer*/

/******************************
* Extension: GL_ARB_copy_image
******************************/

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1

typedef void (GLE_FUNCPTR * PFNGLCOPYIMAGESUBDATAPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

extern PFNGLCOPYIMAGESUBDATAPROC __gleCopyImageSubData;
#define glCopyImageSubData __gleCopyImageSubData
#endif /*GL_ARB_copy_image*/

/******************************
* Extension: GL_ARB_debug_group
******************************/

#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D


/******************************
* Extension: GL_ARB_debug_label
******************************/

#define GL_VERTEX_ARRAY 0x8074
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_SAMPLER 0x82E6
#define GL_DISPLAY_LIST 0x82E7
#define GL_MAX_LABEL_LENGTH 0x82E8


/******************************
* Extension: GL_ARB_debug_output
******************************/

#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB 0x8245
#define GL_DEBUG_SOURCE_API_ARB 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB 0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB 0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB 0x824B
#define GL_DEBUG_TYPE_ERROR_ARB 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB 0x8250
#define GL_DEBUG_TYPE_OTHER_ARB 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB 0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB 0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB 0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB 0x9148


#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1

typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECONTROLARBPROC)(GLenum , GLenum , GLenum , GLsizei , const GLuint *, GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGEINSERTARBPROC)(GLenum , GLenum , GLuint , GLenum , GLsizei , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDEBUGMESSAGECALLBACKARBPROC)(GLDEBUGPROCARB , const GLvoid *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETDEBUGMESSAGELOGARBPROC)(GLuint , GLsizei , GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);

extern PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB;
extern PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB;
extern PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB;
extern PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB;
#endif /*GL_ARB_debug_output*/

/******************************
* Extension: GL_ARB_debug_output2
******************************/

#define GL_DEBUG_OUTPUT 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002


/******************************
* Extension: GL_ARB_depth_buffer_float
******************************/

#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD


/******************************
* Extension: GL_ARB_depth_clamp
******************************/

#define GL_DEPTH_CLAMP 0x864F


/******************************
* Extension: GL_ARB_depth_texture
******************************/

#define GL_DEPTH_COMPONENT16_ARB 0x81A5
#define GL_DEPTH_COMPONENT24_ARB 0x81A6
#define GL_DEPTH_COMPONENT32_ARB 0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB 0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB 0x884B


/******************************
* Extension: GL_ARB_draw_buffers
******************************/

#define GL_MAX_DRAW_BUFFERS_ARB 0x8824
#define GL_DRAW_BUFFER0_ARB 0x8825
#define GL_DRAW_BUFFER1_ARB 0x8826
#define GL_DRAW_BUFFER2_ARB 0x8827
#define GL_DRAW_BUFFER3_ARB 0x8828
#define GL_DRAW_BUFFER4_ARB 0x8829
#define GL_DRAW_BUFFER5_ARB 0x882A
#define GL_DRAW_BUFFER6_ARB 0x882B
#define GL_DRAW_BUFFER7_ARB 0x882C
#define GL_DRAW_BUFFER8_ARB 0x882D
#define GL_DRAW_BUFFER9_ARB 0x882E
#define GL_DRAW_BUFFER10_ARB 0x882F
#define GL_DRAW_BUFFER11_ARB 0x8830
#define GL_DRAW_BUFFER12_ARB 0x8831
#define GL_DRAW_BUFFER13_ARB 0x8832
#define GL_DRAW_BUFFER14_ARB 0x8833
#define GL_DRAW_BUFFER15_ARB 0x8834


#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1

typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSARBPROC)(GLsizei , const GLenum *);

extern PFNGLDRAWBUFFERSARBPROC glDrawBuffersARB;
#endif /*GL_ARB_draw_buffers*/

/******************************
* Extension: GL_ARB_draw_buffers_blend
******************************/

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1

typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONIARBPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEIARBPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCIARBPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEIARBPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );

extern PFNGLBLENDEQUATIONIARBPROC glBlendEquationiARB;
extern PFNGLBLENDEQUATIONSEPARATEIARBPROC glBlendEquationSeparateiARB;
extern PFNGLBLENDFUNCIARBPROC glBlendFunciARB;
extern PFNGLBLENDFUNCSEPARATEIARBPROC glBlendFuncSeparateiARB;
#endif /*GL_ARB_draw_buffers_blend*/

/******************************
* Extension: GL_ARB_draw_elements_base_vertex
******************************/

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1

typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSBASEVERTEXPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLint );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *, GLint );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei , const GLint *);

extern PFNGLDRAWELEMENTSBASEVERTEXPROC __gleDrawElementsBaseVertex;
#define glDrawElementsBaseVertex __gleDrawElementsBaseVertex
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC __gleDrawRangeElementsBaseVertex;
#define glDrawRangeElementsBaseVertex __gleDrawRangeElementsBaseVertex
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC __gleDrawElementsInstancedBaseVertex;
#define glDrawElementsInstancedBaseVertex __gleDrawElementsInstancedBaseVertex
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC __gleMultiDrawElementsBaseVertex;
#define glMultiDrawElementsBaseVertex __gleMultiDrawElementsBaseVertex
#endif /*GL_ARB_draw_elements_base_vertex*/

/******************************
* Extension: GL_ARB_draw_indirect
******************************/

#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43


#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1

typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINDIRECTPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum , GLenum , const GLvoid *);

extern PFNGLDRAWARRAYSINDIRECTPROC __gleDrawArraysIndirect;
#define glDrawArraysIndirect __gleDrawArraysIndirect
extern PFNGLDRAWELEMENTSINDIRECTPROC __gleDrawElementsIndirect;
#define glDrawElementsIndirect __gleDrawElementsIndirect
#endif /*GL_ARB_draw_indirect*/

/******************************
* Extension: GL_ARB_draw_instanced
******************************/

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1

typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDARBPROC)(GLenum , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDARBPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );

extern PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysInstancedARB;
extern PFNGLDRAWELEMENTSINSTANCEDARBPROC glDrawElementsInstancedARB;
#endif /*GL_ARB_draw_instanced*/

/******************************
* Extension: GL_ARB_explicit_attrib_location
******************************/

/******************************
* Extension: GL_ARB_explicit_uniform_location
******************************/

#define GL_MAX_UNIFORM_LOCATIONS 0x826E


/******************************
* Extension: GL_ARB_fragment_coord_conventions
******************************/

/******************************
* Extension: GL_ARB_fragment_layer_viewport
******************************/

/******************************
* Extension: GL_ARB_fragment_program
******************************/

#define GL_FRAGMENT_PROGRAM_ARB 0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB 0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB 0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB 0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_TEXTURE_COORDS_ARB 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB 0x8872


/******************************
* Extension: GL_ARB_fragment_program_shadow
******************************/

/******************************
* Extension: GL_ARB_fragment_shader
******************************/

#define GL_FRAGMENT_SHADER_ARB 0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB 0x8B8B


/******************************
* Extension: GL_ARB_framebuffer_no_attachments
******************************/

#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318


#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1

typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)(GLuint , GLenum , GLint *);

extern PFNGLFRAMEBUFFERPARAMETERIPROC __gleFramebufferParameteri;
#define glFramebufferParameteri __gleFramebufferParameteri
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC __gleGetFramebufferParameteriv;
#define glGetFramebufferParameteriv __gleGetFramebufferParameteriv
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC __gleNamedFramebufferParameteriEXT;
#define glNamedFramebufferParameteriEXT __gleNamedFramebufferParameteriEXT
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC __gleGetNamedFramebufferParameterivEXT;
#define glGetNamedFramebufferParameterivEXT __gleGetNamedFramebufferParameterivEXT
#endif /*GL_ARB_framebuffer_no_attachments*/

/******************************
* Extension: GL_ARB_framebuffer_object
******************************/

#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_INDEX 0x8222
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6 /* GL_FRAMEBUFFER_BINDING */
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
#define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE 0x8C15


#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1

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

extern PFNGLISRENDERBUFFERPROC __gleIsRenderbuffer;
#define glIsRenderbuffer __gleIsRenderbuffer
extern PFNGLBINDRENDERBUFFERPROC __gleBindRenderbuffer;
#define glBindRenderbuffer __gleBindRenderbuffer
extern PFNGLDELETERENDERBUFFERSPROC __gleDeleteRenderbuffers;
#define glDeleteRenderbuffers __gleDeleteRenderbuffers
extern PFNGLGENRENDERBUFFERSPROC __gleGenRenderbuffers;
#define glGenRenderbuffers __gleGenRenderbuffers
extern PFNGLRENDERBUFFERSTORAGEPROC __gleRenderbufferStorage;
#define glRenderbufferStorage __gleRenderbufferStorage
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC __gleGetRenderbufferParameteriv;
#define glGetRenderbufferParameteriv __gleGetRenderbufferParameteriv
extern PFNGLISFRAMEBUFFERPROC __gleIsFramebuffer;
#define glIsFramebuffer __gleIsFramebuffer
extern PFNGLBINDFRAMEBUFFERPROC __gleBindFramebuffer;
#define glBindFramebuffer __gleBindFramebuffer
extern PFNGLDELETEFRAMEBUFFERSPROC __gleDeleteFramebuffers;
#define glDeleteFramebuffers __gleDeleteFramebuffers
extern PFNGLGENFRAMEBUFFERSPROC __gleGenFramebuffers;
#define glGenFramebuffers __gleGenFramebuffers
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC __gleCheckFramebufferStatus;
#define glCheckFramebufferStatus __gleCheckFramebufferStatus
extern PFNGLFRAMEBUFFERTEXTURE1DPROC __gleFramebufferTexture1D;
#define glFramebufferTexture1D __gleFramebufferTexture1D
extern PFNGLFRAMEBUFFERTEXTURE2DPROC __gleFramebufferTexture2D;
#define glFramebufferTexture2D __gleFramebufferTexture2D
extern PFNGLFRAMEBUFFERTEXTURE3DPROC __gleFramebufferTexture3D;
#define glFramebufferTexture3D __gleFramebufferTexture3D
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC __gleFramebufferRenderbuffer;
#define glFramebufferRenderbuffer __gleFramebufferRenderbuffer
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC __gleGetFramebufferAttachmentParameteriv;
#define glGetFramebufferAttachmentParameteriv __gleGetFramebufferAttachmentParameteriv
extern PFNGLGENERATEMIPMAPPROC __gleGenerateMipmap;
#define glGenerateMipmap __gleGenerateMipmap
extern PFNGLBLITFRAMEBUFFERPROC __gleBlitFramebuffer;
#define glBlitFramebuffer __gleBlitFramebuffer
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC __gleRenderbufferStorageMultisample;
#define glRenderbufferStorageMultisample __gleRenderbufferStorageMultisample
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC __gleFramebufferTextureLayer;
#define glFramebufferTextureLayer __gleFramebufferTextureLayer
#endif /*GL_ARB_framebuffer_object*/

/******************************
* Extension: GL_ARB_framebuffer_sRGB
******************************/

#define GL_FRAMEBUFFER_SRGB 0x8DB9


/******************************
* Extension: GL_ARB_geometry_shader4
******************************/

#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_LINES_ADJACENCY_ARB 0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB 0x000B
#define GL_TRIANGLES_ADJACENCY_ARB 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB 0x000D
#define GL_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB 0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1


#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIARBPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREARBPROC)(GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)(GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)(GLenum , GLenum , GLuint , GLint , GLenum );

extern PFNGLPROGRAMPARAMETERIARBPROC glProgramParameteriARB;
extern PFNGLFRAMEBUFFERTEXTUREARBPROC glFramebufferTextureARB;
extern PFNGLFRAMEBUFFERTEXTURELAYERARBPROC glFramebufferTextureLayerARB;
extern PFNGLFRAMEBUFFERTEXTUREFACEARBPROC glFramebufferTextureFaceARB;
#endif /*GL_ARB_geometry_shader4*/

/******************************
* Extension: GL_ARB_get_program_binary
******************************/

#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF


#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1

typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMBINARYPROC)(GLuint , GLsizei , GLsizei *, GLenum *, GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBINARYPROC)(GLuint , GLenum , const GLvoid *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIPROC)(GLuint , GLenum , GLint );

extern PFNGLGETPROGRAMBINARYPROC __gleGetProgramBinary;
#define glGetProgramBinary __gleGetProgramBinary
extern PFNGLPROGRAMBINARYPROC __gleProgramBinary;
#define glProgramBinary __gleProgramBinary
extern PFNGLPROGRAMPARAMETERIPROC __gleProgramParameteri;
#define glProgramParameteri __gleProgramParameteri
#endif /*GL_ARB_get_program_binary*/

/******************************
* Extension: GL_ARB_gpu_shader5
******************************/

#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71


/******************************
* Extension: GL_ARB_gpu_shader_fp64
******************************/

#define GL_DOUBLE 0x140A
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E


#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1

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

extern PFNGLUNIFORM1DPROC __gleUniform1d;
#define glUniform1d __gleUniform1d
extern PFNGLUNIFORM2DPROC __gleUniform2d;
#define glUniform2d __gleUniform2d
extern PFNGLUNIFORM3DPROC __gleUniform3d;
#define glUniform3d __gleUniform3d
extern PFNGLUNIFORM4DPROC __gleUniform4d;
#define glUniform4d __gleUniform4d
extern PFNGLUNIFORM1DVPROC __gleUniform1dv;
#define glUniform1dv __gleUniform1dv
extern PFNGLUNIFORM2DVPROC __gleUniform2dv;
#define glUniform2dv __gleUniform2dv
extern PFNGLUNIFORM3DVPROC __gleUniform3dv;
#define glUniform3dv __gleUniform3dv
extern PFNGLUNIFORM4DVPROC __gleUniform4dv;
#define glUniform4dv __gleUniform4dv
extern PFNGLUNIFORMMATRIX2DVPROC __gleUniformMatrix2dv;
#define glUniformMatrix2dv __gleUniformMatrix2dv
extern PFNGLUNIFORMMATRIX3DVPROC __gleUniformMatrix3dv;
#define glUniformMatrix3dv __gleUniformMatrix3dv
extern PFNGLUNIFORMMATRIX4DVPROC __gleUniformMatrix4dv;
#define glUniformMatrix4dv __gleUniformMatrix4dv
extern PFNGLUNIFORMMATRIX2X3DVPROC __gleUniformMatrix2x3dv;
#define glUniformMatrix2x3dv __gleUniformMatrix2x3dv
extern PFNGLUNIFORMMATRIX2X4DVPROC __gleUniformMatrix2x4dv;
#define glUniformMatrix2x4dv __gleUniformMatrix2x4dv
extern PFNGLUNIFORMMATRIX3X2DVPROC __gleUniformMatrix3x2dv;
#define glUniformMatrix3x2dv __gleUniformMatrix3x2dv
extern PFNGLUNIFORMMATRIX3X4DVPROC __gleUniformMatrix3x4dv;
#define glUniformMatrix3x4dv __gleUniformMatrix3x4dv
extern PFNGLUNIFORMMATRIX4X2DVPROC __gleUniformMatrix4x2dv;
#define glUniformMatrix4x2dv __gleUniformMatrix4x2dv
extern PFNGLUNIFORMMATRIX4X3DVPROC __gleUniformMatrix4x3dv;
#define glUniformMatrix4x3dv __gleUniformMatrix4x3dv
extern PFNGLGETUNIFORMDVPROC __gleGetUniformdv;
#define glGetUniformdv __gleGetUniformdv
#endif /*GL_ARB_gpu_shader_fp64*/

/******************************
* Extension: GL_ARB_half_float_pixel
******************************/

#define GL_HALF_FLOAT_ARB 0x140B


/******************************
* Extension: GL_ARB_half_float_vertex
******************************/

#define GL_HALF_FLOAT 0x140B


/******************************
* Extension: GL_ARB_imaging
******************************/

#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_BLEND_COLOR 0x8005
#define GL_FUNC_ADD 0x8006
#define GL_MIN 0x8007
#define GL_MAX 0x8008
#define GL_BLEND_EQUATION 0x8009
#define GL_FUNC_SUBTRACT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_CONVOLUTION_1D 0x8010
#define GL_CONVOLUTION_2D 0x8011
#define GL_SEPARABLE_2D 0x8012
#define GL_CONVOLUTION_BORDER_MODE 0x8013
#define GL_CONVOLUTION_FILTER_SCALE 0x8014
#define GL_CONVOLUTION_FILTER_BIAS 0x8015
#define GL_REDUCE 0x8016
#define GL_CONVOLUTION_FORMAT 0x8017
#define GL_CONVOLUTION_WIDTH 0x8018
#define GL_CONVOLUTION_HEIGHT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS 0x8023
#define GL_HISTOGRAM 0x8024
#define GL_PROXY_HISTOGRAM 0x8025
#define GL_HISTOGRAM_WIDTH 0x8026
#define GL_HISTOGRAM_FORMAT 0x8027
#define GL_HISTOGRAM_RED_SIZE 0x8028
#define GL_HISTOGRAM_GREEN_SIZE 0x8029
#define GL_HISTOGRAM_BLUE_SIZE 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE 0x802C
#define GL_HISTOGRAM_SINK 0x802D
#define GL_MINMAX 0x802E
#define GL_MINMAX_FORMAT 0x802F
#define GL_MINMAX_SINK 0x8030
#define GL_TABLE_TOO_LARGE 0x8031
#define GL_COLOR_MATRIX 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS 0x80BB
#define GL_COLOR_TABLE 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#define GL_PROXY_COLOR_TABLE 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE 0x80D6
#define GL_COLOR_TABLE_BIAS 0x80D7
#define GL_COLOR_TABLE_FORMAT 0x80D8
#define GL_COLOR_TABLE_WIDTH 0x80D9
#define GL_COLOR_TABLE_RED_SIZE 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE 0x80DF
#define GL_CONSTANT_BORDER 0x8151
#define GL_REPLICATE_BORDER 0x8153
#define GL_CONVOLUTION_BORDER_COLOR 0x8154


/******************************
* Extension: GL_ARB_instanced_arrays
******************************/

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE


#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1

typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBDIVISORARBPROC)(GLuint , GLuint );

extern PFNGLVERTEXATTRIBDIVISORARBPROC glVertexAttribDivisorARB;
#endif /*GL_ARB_instanced_arrays*/

/******************************
* Extension: GL_ARB_internalformat_query
******************************/

#define GL_NUM_SAMPLE_COUNTS 0x9380


#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1

typedef void (GLE_FUNCPTR * PFNGLGETINTERNALFORMATIVPROC)(GLenum , GLenum , GLenum , GLsizei , GLint *);

extern PFNGLGETINTERNALFORMATIVPROC __gleGetInternalformativ;
#define glGetInternalformativ __gleGetInternalformativ
#endif /*GL_ARB_internalformat_query*/

/******************************
* Extension: GL_ARB_internalformat_query2
******************************/

#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_3D 0x806F
#define GL_SAMPLES 0x80A9
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_RENDERBUFFER 0x8D41
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_SRGB_DECODE_ARB 0x8299


#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1

typedef void (GLE_FUNCPTR * PFNGLGETINTERNALFORMATI64VPROC)(GLenum , GLenum , GLenum , GLsizei , GLint64 *);

extern PFNGLGETINTERNALFORMATI64VPROC __gleGetInternalformati64v;
#define glGetInternalformati64v __gleGetInternalformati64v
#endif /*GL_ARB_internalformat_query2*/

/******************************
* Extension: GL_ARB_invalidate_subdata
******************************/

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1

typedef void (GLE_FUNCPTR * PFNGLINVALIDATETEXSUBIMAGEPROC)(GLuint , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATETEXIMAGEPROC)(GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEBUFFERSUBDATAPROC)(GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEBUFFERDATAPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum , GLsizei , const GLenum *);
typedef void (GLE_FUNCPTR * PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum , GLsizei , const GLenum *, GLint , GLint , GLsizei , GLsizei );

extern PFNGLINVALIDATETEXSUBIMAGEPROC __gleInvalidateTexSubImage;
#define glInvalidateTexSubImage __gleInvalidateTexSubImage
extern PFNGLINVALIDATETEXIMAGEPROC __gleInvalidateTexImage;
#define glInvalidateTexImage __gleInvalidateTexImage
extern PFNGLINVALIDATEBUFFERSUBDATAPROC __gleInvalidateBufferSubData;
#define glInvalidateBufferSubData __gleInvalidateBufferSubData
extern PFNGLINVALIDATEBUFFERDATAPROC __gleInvalidateBufferData;
#define glInvalidateBufferData __gleInvalidateBufferData
extern PFNGLINVALIDATEFRAMEBUFFERPROC __gleInvalidateFramebuffer;
#define glInvalidateFramebuffer __gleInvalidateFramebuffer
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC __gleInvalidateSubFramebuffer;
#define glInvalidateSubFramebuffer __gleInvalidateSubFramebuffer
#endif /*GL_ARB_invalidate_subdata*/

/******************************
* Extension: GL_ARB_map_buffer_alignment
******************************/

#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC


/******************************
* Extension: GL_ARB_map_buffer_range
******************************/

#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020


#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1

typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPBUFFERRANGEPROC)(GLenum , GLintptr , GLsizeiptr , GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum , GLintptr , GLsizeiptr );

extern PFNGLMAPBUFFERRANGEPROC __gleMapBufferRange;
#define glMapBufferRange __gleMapBufferRange
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC __gleFlushMappedBufferRange;
#define glFlushMappedBufferRange __gleFlushMappedBufferRange
#endif /*GL_ARB_map_buffer_range*/

/******************************
* Extension: GL_ARB_matrix_palette
******************************/

#define GL_MATRIX_PALETTE_ARB 0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB 0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB 0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB 0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB 0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB 0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB 0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB 0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849


#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1

typedef void (GLE_FUNCPTR * PFNGLCURRENTPALETTEMATRIXARBPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUBVARBPROC)(GLint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUSVARBPROC)(GLint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXUIVARBPROC)(GLint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXINDEXPOINTERARBPROC)(GLint , GLenum , GLsizei , const GLvoid *);

extern PFNGLCURRENTPALETTEMATRIXARBPROC glCurrentPaletteMatrixARB;
extern PFNGLMATRIXINDEXUBVARBPROC glMatrixIndexubvARB;
extern PFNGLMATRIXINDEXUSVARBPROC glMatrixIndexusvARB;
extern PFNGLMATRIXINDEXUIVARBPROC glMatrixIndexuivARB;
extern PFNGLMATRIXINDEXPOINTERARBPROC glMatrixIndexPointerARB;
#endif /*GL_ARB_matrix_palette*/

/******************************
* Extension: GL_ARB_multi_draw_indirect
******************************/

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1

typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSINDIRECTPROC)(GLenum , const void *, GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSINDIRECTPROC)(GLenum , GLenum , const void *, GLsizei , GLsizei );

extern PFNGLMULTIDRAWARRAYSINDIRECTPROC __gleMultiDrawArraysIndirect;
#define glMultiDrawArraysIndirect __gleMultiDrawArraysIndirect
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC __gleMultiDrawElementsIndirect;
#define glMultiDrawElementsIndirect __gleMultiDrawElementsIndirect
#endif /*GL_ARB_multi_draw_indirect*/

/******************************
* Extension: GL_ARB_multisample
******************************/

#define GL_MULTISAMPLE_ARB 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB 0x809F
#define GL_SAMPLE_COVERAGE_ARB 0x80A0
#define GL_SAMPLE_BUFFERS_ARB 0x80A8
#define GL_SAMPLES_ARB 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB 0x80AB
#define GL_MULTISAMPLE_BIT_ARB 0x20000000


#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1

typedef void (GLE_FUNCPTR * PFNGLSAMPLECOVERAGEARBPROC)(GLfloat , GLboolean );

extern PFNGLSAMPLECOVERAGEARBPROC glSampleCoverageARB;
#endif /*GL_ARB_multisample*/

/******************************
* Extension: GL_ARB_multitexture
******************************/

#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_TEXTURE2_ARB 0x84C2
#define GL_TEXTURE3_ARB 0x84C3
#define GL_TEXTURE4_ARB 0x84C4
#define GL_TEXTURE5_ARB 0x84C5
#define GL_TEXTURE6_ARB 0x84C6
#define GL_TEXTURE7_ARB 0x84C7
#define GL_TEXTURE8_ARB 0x84C8
#define GL_TEXTURE9_ARB 0x84C9
#define GL_TEXTURE10_ARB 0x84CA
#define GL_TEXTURE11_ARB 0x84CB
#define GL_TEXTURE12_ARB 0x84CC
#define GL_TEXTURE13_ARB 0x84CD
#define GL_TEXTURE14_ARB 0x84CE
#define GL_TEXTURE15_ARB 0x84CF
#define GL_TEXTURE16_ARB 0x84D0
#define GL_TEXTURE17_ARB 0x84D1
#define GL_TEXTURE18_ARB 0x84D2
#define GL_TEXTURE19_ARB 0x84D3
#define GL_TEXTURE20_ARB 0x84D4
#define GL_TEXTURE21_ARB 0x84D5
#define GL_TEXTURE22_ARB 0x84D6
#define GL_TEXTURE23_ARB 0x84D7
#define GL_TEXTURE24_ARB 0x84D8
#define GL_TEXTURE25_ARB 0x84D9
#define GL_TEXTURE26_ARB 0x84DA
#define GL_TEXTURE27_ARB 0x84DB
#define GL_TEXTURE28_ARB 0x84DC
#define GL_TEXTURE29_ARB 0x84DD
#define GL_TEXTURE30_ARB 0x84DE
#define GL_TEXTURE31_ARB 0x84DF
#define GL_ACTIVE_TEXTURE_ARB 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB 0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB 0x84E2


#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1

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

extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB;
extern PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB;
extern PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB;
extern PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB;
extern PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB;
extern PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB;
extern PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB;
extern PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB;
extern PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB;
extern PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB;
extern PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB;
extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
extern PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;
extern PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB;
extern PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB;
extern PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB;
extern PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB;
extern PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB;
extern PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB;
extern PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB;
extern PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB;
extern PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB;
extern PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB;
extern PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB;
extern PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB;
extern PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB;
extern PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB;
extern PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB;
extern PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB;
extern PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB;
extern PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB;
extern PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB;
extern PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB;
#endif /*GL_ARB_multitexture*/

/******************************
* Extension: GL_ARB_occlusion_query
******************************/

#define GL_QUERY_COUNTER_BITS_ARB 0x8864
#define GL_CURRENT_QUERY_ARB 0x8865
#define GL_QUERY_RESULT_ARB 0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB 0x8867
#define GL_SAMPLES_PASSED_ARB 0x8914


#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1

typedef void (GLE_FUNCPTR * PFNGLGENQUERIESARBPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEQUERIESARBPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISQUERYARBPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYARBPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDQUERYARBPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYIVARBPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTIVARBPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUIVARBPROC)(GLuint , GLenum , GLuint *);

extern PFNGLGENQUERIESARBPROC glGenQueriesARB;
extern PFNGLDELETEQUERIESARBPROC glDeleteQueriesARB;
extern PFNGLISQUERYARBPROC glIsQueryARB;
extern PFNGLBEGINQUERYARBPROC glBeginQueryARB;
extern PFNGLENDQUERYARBPROC glEndQueryARB;
extern PFNGLGETQUERYIVARBPROC glGetQueryivARB;
extern PFNGLGETQUERYOBJECTIVARBPROC glGetQueryObjectivARB;
extern PFNGLGETQUERYOBJECTUIVARBPROC glGetQueryObjectuivARB;
#endif /*GL_ARB_occlusion_query*/

/******************************
* Extension: GL_ARB_occlusion_query2
******************************/

#define GL_ANY_SAMPLES_PASSED 0x8C2F


/******************************
* Extension: GL_ARB_pixel_buffer_object
******************************/

#define GL_PIXEL_PACK_BUFFER_ARB 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF


/******************************
* Extension: GL_ARB_point_parameters
******************************/

#define GL_POINT_SIZE_MIN_ARB 0x8126
#define GL_POINT_SIZE_MAX_ARB 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB 0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129


#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1

typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFARBPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVARBPROC)(GLenum , const GLfloat *);

extern PFNGLPOINTPARAMETERFARBPROC glPointParameterfARB;
extern PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB;
#endif /*GL_ARB_point_parameters*/

/******************************
* Extension: GL_ARB_point_sprite
******************************/

#define GL_POINT_SPRITE_ARB 0x8861
#define GL_COORD_REPLACE_ARB 0x8862


/******************************
* Extension: GL_ARB_program_interface_query
******************************/

#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_IS_PER_PATCH 0x92E7


#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1

typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint , GLenum , GLenum , GLint *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint , GLenum , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint , GLenum , GLuint , GLsizei , const GLenum *, GLsizei , GLsizei *, GLint *);
typedef GLint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint , GLenum , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)(GLuint , GLenum , const GLchar *);

extern PFNGLGETPROGRAMINTERFACEIVPROC __gleGetProgramInterfaceiv;
#define glGetProgramInterfaceiv __gleGetProgramInterfaceiv
extern PFNGLGETPROGRAMRESOURCEINDEXPROC __gleGetProgramResourceIndex;
#define glGetProgramResourceIndex __gleGetProgramResourceIndex
extern PFNGLGETPROGRAMRESOURCENAMEPROC __gleGetProgramResourceName;
#define glGetProgramResourceName __gleGetProgramResourceName
extern PFNGLGETPROGRAMRESOURCEIVPROC __gleGetProgramResourceiv;
#define glGetProgramResourceiv __gleGetProgramResourceiv
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC __gleGetProgramResourceLocation;
#define glGetProgramResourceLocation __gleGetProgramResourceLocation
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC __gleGetProgramResourceLocationIndex;
#define glGetProgramResourceLocationIndex __gleGetProgramResourceLocationIndex
#endif /*GL_ARB_program_interface_query*/

/******************************
* Extension: GL_ARB_provoking_vertex
******************************/

#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F


#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1

typedef void (GLE_FUNCPTR * PFNGLPROVOKINGVERTEXPROC)(GLenum );

extern PFNGLPROVOKINGVERTEXPROC __gleProvokingVertex;
#define glProvokingVertex __gleProvokingVertex
#endif /*GL_ARB_provoking_vertex*/

/******************************
* Extension: GL_ARB_robust_buffer_access_behavior
******************************/

/******************************
* Extension: GL_ARB_robustness
******************************/

#define GL_NO_ERROR 0
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB 0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB 0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB 0x8261


#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1

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

extern PFNGLGETGRAPHICSRESETSTATUSARBPROC glGetGraphicsResetStatusARB;
extern PFNGLGETNMAPDVARBPROC glGetnMapdvARB;
extern PFNGLGETNMAPFVARBPROC glGetnMapfvARB;
extern PFNGLGETNMAPIVARBPROC glGetnMapivARB;
extern PFNGLGETNPIXELMAPFVARBPROC glGetnPixelMapfvARB;
extern PFNGLGETNPIXELMAPUIVARBPROC glGetnPixelMapuivARB;
extern PFNGLGETNPIXELMAPUSVARBPROC glGetnPixelMapusvARB;
extern PFNGLGETNPOLYGONSTIPPLEARBPROC glGetnPolygonStippleARB;
extern PFNGLGETNCOLORTABLEARBPROC glGetnColorTableARB;
extern PFNGLGETNCONVOLUTIONFILTERARBPROC glGetnConvolutionFilterARB;
extern PFNGLGETNSEPARABLEFILTERARBPROC glGetnSeparableFilterARB;
extern PFNGLGETNHISTOGRAMARBPROC glGetnHistogramARB;
extern PFNGLGETNMINMAXARBPROC glGetnMinmaxARB;
extern PFNGLGETNTEXIMAGEARBPROC glGetnTexImageARB;
extern PFNGLREADNPIXELSARBPROC glReadnPixelsARB;
extern PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC glGetnCompressedTexImageARB;
extern PFNGLGETNUNIFORMFVARBPROC glGetnUniformfvARB;
extern PFNGLGETNUNIFORMIVARBPROC glGetnUniformivARB;
extern PFNGLGETNUNIFORMUIVARBPROC glGetnUniformuivARB;
extern PFNGLGETNUNIFORMDVARBPROC glGetnUniformdvARB;
#endif /*GL_ARB_robustness*/

/******************************
* Extension: GL_ARB_robustness_isolation
******************************/

/******************************
* Extension: GL_ARB_sample_shading
******************************/

#define GL_SAMPLE_SHADING_ARB 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB 0x8C37


#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1

typedef void (GLE_FUNCPTR * PFNGLMINSAMPLESHADINGARBPROC)(GLfloat );

extern PFNGLMINSAMPLESHADINGARBPROC glMinSampleShadingARB;
#endif /*GL_ARB_sample_shading*/

/******************************
* Extension: GL_ARB_sampler_objects
******************************/

#define GL_SAMPLER_BINDING 0x8919


#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1

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

extern PFNGLGENSAMPLERSPROC __gleGenSamplers;
#define glGenSamplers __gleGenSamplers
extern PFNGLDELETESAMPLERSPROC __gleDeleteSamplers;
#define glDeleteSamplers __gleDeleteSamplers
extern PFNGLISSAMPLERPROC __gleIsSampler;
#define glIsSampler __gleIsSampler
extern PFNGLBINDSAMPLERPROC __gleBindSampler;
#define glBindSampler __gleBindSampler
extern PFNGLSAMPLERPARAMETERIPROC __gleSamplerParameteri;
#define glSamplerParameteri __gleSamplerParameteri
extern PFNGLSAMPLERPARAMETERIVPROC __gleSamplerParameteriv;
#define glSamplerParameteriv __gleSamplerParameteriv
extern PFNGLSAMPLERPARAMETERFPROC __gleSamplerParameterf;
#define glSamplerParameterf __gleSamplerParameterf
extern PFNGLSAMPLERPARAMETERFVPROC __gleSamplerParameterfv;
#define glSamplerParameterfv __gleSamplerParameterfv
extern PFNGLSAMPLERPARAMETERIIVPROC __gleSamplerParameterIiv;
#define glSamplerParameterIiv __gleSamplerParameterIiv
extern PFNGLSAMPLERPARAMETERIUIVPROC __gleSamplerParameterIuiv;
#define glSamplerParameterIuiv __gleSamplerParameterIuiv
extern PFNGLGETSAMPLERPARAMETERIVPROC __gleGetSamplerParameteriv;
#define glGetSamplerParameteriv __gleGetSamplerParameteriv
extern PFNGLGETSAMPLERPARAMETERIIVPROC __gleGetSamplerParameterIiv;
#define glGetSamplerParameterIiv __gleGetSamplerParameterIiv
extern PFNGLGETSAMPLERPARAMETERFVPROC __gleGetSamplerParameterfv;
#define glGetSamplerParameterfv __gleGetSamplerParameterfv
extern PFNGLGETSAMPLERPARAMETERIUIVPROC __gleGetSamplerParameterIuiv;
#define glGetSamplerParameterIuiv __gleGetSamplerParameterIuiv
#endif /*GL_ARB_sampler_objects*/

/******************************
* Extension: GL_ARB_seamless_cube_map
******************************/

#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F


/******************************
* Extension: GL_ARB_separate_shader_objects
******************************/

#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A


#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1

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

extern PFNGLUSEPROGRAMSTAGESPROC __gleUseProgramStages;
#define glUseProgramStages __gleUseProgramStages
extern PFNGLACTIVESHADERPROGRAMPROC __gleActiveShaderProgram;
#define glActiveShaderProgram __gleActiveShaderProgram
extern PFNGLCREATESHADERPROGRAMVPROC __gleCreateShaderProgramv;
#define glCreateShaderProgramv __gleCreateShaderProgramv
extern PFNGLBINDPROGRAMPIPELINEPROC __gleBindProgramPipeline;
#define glBindProgramPipeline __gleBindProgramPipeline
extern PFNGLDELETEPROGRAMPIPELINESPROC __gleDeleteProgramPipelines;
#define glDeleteProgramPipelines __gleDeleteProgramPipelines
extern PFNGLGENPROGRAMPIPELINESPROC __gleGenProgramPipelines;
#define glGenProgramPipelines __gleGenProgramPipelines
extern PFNGLISPROGRAMPIPELINEPROC __gleIsProgramPipeline;
#define glIsProgramPipeline __gleIsProgramPipeline
extern PFNGLGETPROGRAMPIPELINEIVPROC __gleGetProgramPipelineiv;
#define glGetProgramPipelineiv __gleGetProgramPipelineiv
extern PFNGLPROGRAMUNIFORM1IPROC __gleProgramUniform1i;
#define glProgramUniform1i __gleProgramUniform1i
extern PFNGLPROGRAMUNIFORM1IVPROC __gleProgramUniform1iv;
#define glProgramUniform1iv __gleProgramUniform1iv
extern PFNGLPROGRAMUNIFORM1FPROC __gleProgramUniform1f;
#define glProgramUniform1f __gleProgramUniform1f
extern PFNGLPROGRAMUNIFORM1FVPROC __gleProgramUniform1fv;
#define glProgramUniform1fv __gleProgramUniform1fv
extern PFNGLPROGRAMUNIFORM1DPROC __gleProgramUniform1d;
#define glProgramUniform1d __gleProgramUniform1d
extern PFNGLPROGRAMUNIFORM1DVPROC __gleProgramUniform1dv;
#define glProgramUniform1dv __gleProgramUniform1dv
extern PFNGLPROGRAMUNIFORM1UIPROC __gleProgramUniform1ui;
#define glProgramUniform1ui __gleProgramUniform1ui
extern PFNGLPROGRAMUNIFORM1UIVPROC __gleProgramUniform1uiv;
#define glProgramUniform1uiv __gleProgramUniform1uiv
extern PFNGLPROGRAMUNIFORM2IPROC __gleProgramUniform2i;
#define glProgramUniform2i __gleProgramUniform2i
extern PFNGLPROGRAMUNIFORM2IVPROC __gleProgramUniform2iv;
#define glProgramUniform2iv __gleProgramUniform2iv
extern PFNGLPROGRAMUNIFORM2FPROC __gleProgramUniform2f;
#define glProgramUniform2f __gleProgramUniform2f
extern PFNGLPROGRAMUNIFORM2FVPROC __gleProgramUniform2fv;
#define glProgramUniform2fv __gleProgramUniform2fv
extern PFNGLPROGRAMUNIFORM2DPROC __gleProgramUniform2d;
#define glProgramUniform2d __gleProgramUniform2d
extern PFNGLPROGRAMUNIFORM2DVPROC __gleProgramUniform2dv;
#define glProgramUniform2dv __gleProgramUniform2dv
extern PFNGLPROGRAMUNIFORM2UIPROC __gleProgramUniform2ui;
#define glProgramUniform2ui __gleProgramUniform2ui
extern PFNGLPROGRAMUNIFORM2UIVPROC __gleProgramUniform2uiv;
#define glProgramUniform2uiv __gleProgramUniform2uiv
extern PFNGLPROGRAMUNIFORM3IPROC __gleProgramUniform3i;
#define glProgramUniform3i __gleProgramUniform3i
extern PFNGLPROGRAMUNIFORM3IVPROC __gleProgramUniform3iv;
#define glProgramUniform3iv __gleProgramUniform3iv
extern PFNGLPROGRAMUNIFORM3FPROC __gleProgramUniform3f;
#define glProgramUniform3f __gleProgramUniform3f
extern PFNGLPROGRAMUNIFORM3FVPROC __gleProgramUniform3fv;
#define glProgramUniform3fv __gleProgramUniform3fv
extern PFNGLPROGRAMUNIFORM3DPROC __gleProgramUniform3d;
#define glProgramUniform3d __gleProgramUniform3d
extern PFNGLPROGRAMUNIFORM3DVPROC __gleProgramUniform3dv;
#define glProgramUniform3dv __gleProgramUniform3dv
extern PFNGLPROGRAMUNIFORM3UIPROC __gleProgramUniform3ui;
#define glProgramUniform3ui __gleProgramUniform3ui
extern PFNGLPROGRAMUNIFORM3UIVPROC __gleProgramUniform3uiv;
#define glProgramUniform3uiv __gleProgramUniform3uiv
extern PFNGLPROGRAMUNIFORM4IPROC __gleProgramUniform4i;
#define glProgramUniform4i __gleProgramUniform4i
extern PFNGLPROGRAMUNIFORM4IVPROC __gleProgramUniform4iv;
#define glProgramUniform4iv __gleProgramUniform4iv
extern PFNGLPROGRAMUNIFORM4FPROC __gleProgramUniform4f;
#define glProgramUniform4f __gleProgramUniform4f
extern PFNGLPROGRAMUNIFORM4FVPROC __gleProgramUniform4fv;
#define glProgramUniform4fv __gleProgramUniform4fv
extern PFNGLPROGRAMUNIFORM4DPROC __gleProgramUniform4d;
#define glProgramUniform4d __gleProgramUniform4d
extern PFNGLPROGRAMUNIFORM4DVPROC __gleProgramUniform4dv;
#define glProgramUniform4dv __gleProgramUniform4dv
extern PFNGLPROGRAMUNIFORM4UIPROC __gleProgramUniform4ui;
#define glProgramUniform4ui __gleProgramUniform4ui
extern PFNGLPROGRAMUNIFORM4UIVPROC __gleProgramUniform4uiv;
#define glProgramUniform4uiv __gleProgramUniform4uiv
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC __gleProgramUniformMatrix2fv;
#define glProgramUniformMatrix2fv __gleProgramUniformMatrix2fv
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC __gleProgramUniformMatrix3fv;
#define glProgramUniformMatrix3fv __gleProgramUniformMatrix3fv
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC __gleProgramUniformMatrix4fv;
#define glProgramUniformMatrix4fv __gleProgramUniformMatrix4fv
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC __gleProgramUniformMatrix2dv;
#define glProgramUniformMatrix2dv __gleProgramUniformMatrix2dv
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC __gleProgramUniformMatrix3dv;
#define glProgramUniformMatrix3dv __gleProgramUniformMatrix3dv
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC __gleProgramUniformMatrix4dv;
#define glProgramUniformMatrix4dv __gleProgramUniformMatrix4dv
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC __gleProgramUniformMatrix2x3fv;
#define glProgramUniformMatrix2x3fv __gleProgramUniformMatrix2x3fv
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC __gleProgramUniformMatrix3x2fv;
#define glProgramUniformMatrix3x2fv __gleProgramUniformMatrix3x2fv
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC __gleProgramUniformMatrix2x4fv;
#define glProgramUniformMatrix2x4fv __gleProgramUniformMatrix2x4fv
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC __gleProgramUniformMatrix4x2fv;
#define glProgramUniformMatrix4x2fv __gleProgramUniformMatrix4x2fv
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC __gleProgramUniformMatrix3x4fv;
#define glProgramUniformMatrix3x4fv __gleProgramUniformMatrix3x4fv
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC __gleProgramUniformMatrix4x3fv;
#define glProgramUniformMatrix4x3fv __gleProgramUniformMatrix4x3fv
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC __gleProgramUniformMatrix2x3dv;
#define glProgramUniformMatrix2x3dv __gleProgramUniformMatrix2x3dv
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC __gleProgramUniformMatrix3x2dv;
#define glProgramUniformMatrix3x2dv __gleProgramUniformMatrix3x2dv
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC __gleProgramUniformMatrix2x4dv;
#define glProgramUniformMatrix2x4dv __gleProgramUniformMatrix2x4dv
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC __gleProgramUniformMatrix4x2dv;
#define glProgramUniformMatrix4x2dv __gleProgramUniformMatrix4x2dv
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC __gleProgramUniformMatrix3x4dv;
#define glProgramUniformMatrix3x4dv __gleProgramUniformMatrix3x4dv
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC __gleProgramUniformMatrix4x3dv;
#define glProgramUniformMatrix4x3dv __gleProgramUniformMatrix4x3dv
extern PFNGLVALIDATEPROGRAMPIPELINEPROC __gleValidateProgramPipeline;
#define glValidateProgramPipeline __gleValidateProgramPipeline
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC __gleGetProgramPipelineInfoLog;
#define glGetProgramPipelineInfoLog __gleGetProgramPipelineInfoLog
#endif /*GL_ARB_separate_shader_objects*/

/******************************
* Extension: GL_ARB_shader_atomic_counters
******************************/

#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB


#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1

typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)(GLuint , GLuint , GLenum , GLint *);

extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC __gleGetActiveAtomicCounterBufferiv;
#define glGetActiveAtomicCounterBufferiv __gleGetActiveAtomicCounterBufferiv
#endif /*GL_ARB_shader_atomic_counters*/

/******************************
* Extension: GL_ARB_shader_bit_encoding
******************************/

/******************************
* Extension: GL_ARB_shader_image_load_store
******************************/

#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF


#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1

typedef void (GLE_FUNCPTR * PFNGLBINDIMAGETEXTUREPROC)(GLuint , GLuint , GLint , GLboolean , GLint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMEMORYBARRIERPROC)(GLbitfield );

extern PFNGLBINDIMAGETEXTUREPROC __gleBindImageTexture;
#define glBindImageTexture __gleBindImageTexture
extern PFNGLMEMORYBARRIERPROC __gleMemoryBarrier;
#define glMemoryBarrier __gleMemoryBarrier
#endif /*GL_ARB_shader_image_load_store*/

/******************************
* Extension: GL_ARB_shader_image_size
******************************/

/******************************
* Extension: GL_ARB_shader_objects
******************************/

#define GL_PROGRAM_OBJECT_ARB 0x8B40
#define GL_SHADER_OBJECT_ARB 0x8B48
#define GL_OBJECT_TYPE_ARB 0x8B4E
#define GL_OBJECT_SUBTYPE_ARB 0x8B4F
#define GL_FLOAT_VEC2_ARB 0x8B50
#define GL_FLOAT_VEC3_ARB 0x8B51
#define GL_FLOAT_VEC4_ARB 0x8B52
#define GL_INT_VEC2_ARB 0x8B53
#define GL_INT_VEC3_ARB 0x8B54
#define GL_INT_VEC4_ARB 0x8B55
#define GL_BOOL_ARB 0x8B56
#define GL_BOOL_VEC2_ARB 0x8B57
#define GL_BOOL_VEC3_ARB 0x8B58
#define GL_BOOL_VEC4_ARB 0x8B59
#define GL_FLOAT_MAT2_ARB 0x8B5A
#define GL_FLOAT_MAT3_ARB 0x8B5B
#define GL_FLOAT_MAT4_ARB 0x8B5C
#define GL_SAMPLER_1D_ARB 0x8B5D
#define GL_SAMPLER_2D_ARB 0x8B5E
#define GL_SAMPLER_3D_ARB 0x8B5F
#define GL_SAMPLER_CUBE_ARB 0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB 0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB 0x8B62
#define GL_SAMPLER_2D_RECT_ARB 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB 0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB 0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB 0x8B81
#define GL_OBJECT_LINK_STATUS_ARB 0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB 0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB 0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB 0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB 0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88


#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1

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

extern PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
extern PFNGLGETHANDLEARBPROC glGetHandleARB;
extern PFNGLDETACHOBJECTARBPROC glDetachObjectARB;
extern PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
extern PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
extern PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
extern PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
extern PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
extern PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
extern PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
extern PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;
extern PFNGLUNIFORM1FARBPROC glUniform1fARB;
extern PFNGLUNIFORM2FARBPROC glUniform2fARB;
extern PFNGLUNIFORM3FARBPROC glUniform3fARB;
extern PFNGLUNIFORM4FARBPROC glUniform4fARB;
extern PFNGLUNIFORM1IARBPROC glUniform1iARB;
extern PFNGLUNIFORM2IARBPROC glUniform2iARB;
extern PFNGLUNIFORM3IARBPROC glUniform3iARB;
extern PFNGLUNIFORM4IARBPROC glUniform4iARB;
extern PFNGLUNIFORM1FVARBPROC glUniform1fvARB;
extern PFNGLUNIFORM2FVARBPROC glUniform2fvARB;
extern PFNGLUNIFORM3FVARBPROC glUniform3fvARB;
extern PFNGLUNIFORM4FVARBPROC glUniform4fvARB;
extern PFNGLUNIFORM1IVARBPROC glUniform1ivARB;
extern PFNGLUNIFORM2IVARBPROC glUniform2ivARB;
extern PFNGLUNIFORM3IVARBPROC glUniform3ivARB;
extern PFNGLUNIFORM4IVARBPROC glUniform4ivARB;
extern PFNGLUNIFORMMATRIX2FVARBPROC glUniformMatrix2fvARB;
extern PFNGLUNIFORMMATRIX3FVARBPROC glUniformMatrix3fvARB;
extern PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;
extern PFNGLGETOBJECTPARAMETERFVARBPROC glGetObjectParameterfvARB;
extern PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
extern PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
extern PFNGLGETATTACHEDOBJECTSARBPROC glGetAttachedObjectsARB;
extern PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
extern PFNGLGETACTIVEUNIFORMARBPROC glGetActiveUniformARB;
extern PFNGLGETUNIFORMFVARBPROC glGetUniformfvARB;
extern PFNGLGETUNIFORMIVARBPROC glGetUniformivARB;
extern PFNGLGETSHADERSOURCEARBPROC glGetShaderSourceARB;
#endif /*GL_ARB_shader_objects*/

/******************************
* Extension: GL_ARB_shader_precision
******************************/

/******************************
* Extension: GL_ARB_shader_stencil_export
******************************/

/******************************
* Extension: GL_ARB_shader_storage_buffer_object
******************************/

#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT 0x2000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39 /* GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS */


#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLSHADERSTORAGEBLOCKBINDINGPROC)(GLuint , GLuint , GLuint );

extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC __gleShaderStorageBlockBinding;
#define glShaderStorageBlockBinding __gleShaderStorageBlockBinding
#endif /*GL_ARB_shader_storage_buffer_object*/

/******************************
* Extension: GL_ARB_shader_subroutine
******************************/

#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B


#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1

typedef GLint (GLE_FUNCPTR * PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)(GLuint , GLenum , const GLchar *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETSUBROUTINEINDEXPROC)(GLuint , GLenum , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)(GLuint , GLenum , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVESUBROUTINENAMEPROC)(GLuint , GLenum , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMSUBROUTINESUIVPROC)(GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMSUBROUTINEUIVPROC)(GLenum , GLint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSTAGEIVPROC)(GLuint , GLenum , GLenum , GLint *);

extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC __gleGetSubroutineUniformLocation;
#define glGetSubroutineUniformLocation __gleGetSubroutineUniformLocation
extern PFNGLGETSUBROUTINEINDEXPROC __gleGetSubroutineIndex;
#define glGetSubroutineIndex __gleGetSubroutineIndex
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC __gleGetActiveSubroutineUniformiv;
#define glGetActiveSubroutineUniformiv __gleGetActiveSubroutineUniformiv
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC __gleGetActiveSubroutineUniformName;
#define glGetActiveSubroutineUniformName __gleGetActiveSubroutineUniformName
extern PFNGLGETACTIVESUBROUTINENAMEPROC __gleGetActiveSubroutineName;
#define glGetActiveSubroutineName __gleGetActiveSubroutineName
extern PFNGLUNIFORMSUBROUTINESUIVPROC __gleUniformSubroutinesuiv;
#define glUniformSubroutinesuiv __gleUniformSubroutinesuiv
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC __gleGetUniformSubroutineuiv;
#define glGetUniformSubroutineuiv __gleGetUniformSubroutineuiv
extern PFNGLGETPROGRAMSTAGEIVPROC __gleGetProgramStageiv;
#define glGetProgramStageiv __gleGetProgramStageiv
#endif /*GL_ARB_shader_subroutine*/

/******************************
* Extension: GL_ARB_shader_texture_lod
******************************/

/******************************
* Extension: GL_ARB_shading_language_100
******************************/

#define GL_SHADING_LANGUAGE_VERSION_ARB 0x8B8C


/******************************
* Extension: GL_ARB_shading_language_420pack
******************************/

/******************************
* Extension: GL_ARB_shading_language_include
******************************/

#define GL_SHADER_INCLUDE_ARB 0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB 0x8DE9
#define GL_NAMED_STRING_TYPE_ARB 0x8DEA


#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1

typedef void (GLE_FUNCPTR * PFNGLNAMEDSTRINGARBPROC)(GLenum , GLint , const GLchar *, GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLDELETENAMEDSTRINGARBPROC)(GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint , GLsizei , const GLchar* *, const GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISNAMEDSTRINGARBPROC)(GLint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDSTRINGARBPROC)(GLint , const GLchar *, GLsizei , GLint *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETNAMEDSTRINGIVARBPROC)(GLint , const GLchar *, GLenum , GLint *);

extern PFNGLNAMEDSTRINGARBPROC glNamedStringARB;
extern PFNGLDELETENAMEDSTRINGARBPROC glDeleteNamedStringARB;
extern PFNGLCOMPILESHADERINCLUDEARBPROC glCompileShaderIncludeARB;
extern PFNGLISNAMEDSTRINGARBPROC glIsNamedStringARB;
extern PFNGLGETNAMEDSTRINGARBPROC glGetNamedStringARB;
extern PFNGLGETNAMEDSTRINGIVARBPROC glGetNamedStringivARB;
#endif /*GL_ARB_shading_language_include*/

/******************************
* Extension: GL_ARB_shading_language_packing
******************************/

/******************************
* Extension: GL_ARB_shadow
******************************/

#define GL_TEXTURE_COMPARE_MODE_ARB 0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB 0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB 0x884E


/******************************
* Extension: GL_ARB_shadow_ambient
******************************/

#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF


/******************************
* Extension: GL_ARB_stencil_texturing
******************************/

#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA


/******************************
* Extension: GL_ARB_sync
******************************/

#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001


#ifndef GL_ARB_sync
#define GL_ARB_sync 1

typedef GLsync (GLE_FUNCPTR * PFNGLFENCESYNCPROC)(GLenum , GLbitfield );
typedef GLboolean (GLE_FUNCPTR * PFNGLISSYNCPROC)(GLsync );
typedef void (GLE_FUNCPTR * PFNGLDELETESYNCPROC)(GLsync );
typedef GLenum (GLE_FUNCPTR * PFNGLCLIENTWAITSYNCPROC)(GLsync , GLbitfield , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLWAITSYNCPROC)(GLsync , GLbitfield , GLuint64 );
typedef void (GLE_FUNCPTR * PFNGLGETINTEGER64VPROC)(GLenum , GLint64 *);
typedef void (GLE_FUNCPTR * PFNGLGETSYNCIVPROC)(GLsync , GLenum , GLsizei , GLsizei *, GLint *);

extern PFNGLFENCESYNCPROC __gleFenceSync;
#define glFenceSync __gleFenceSync
extern PFNGLISSYNCPROC __gleIsSync;
#define glIsSync __gleIsSync
extern PFNGLDELETESYNCPROC __gleDeleteSync;
#define glDeleteSync __gleDeleteSync
extern PFNGLCLIENTWAITSYNCPROC __gleClientWaitSync;
#define glClientWaitSync __gleClientWaitSync
extern PFNGLWAITSYNCPROC __gleWaitSync;
#define glWaitSync __gleWaitSync
extern PFNGLGETINTEGER64VPROC __gleGetInteger64v;
#define glGetInteger64v __gleGetInteger64v
extern PFNGLGETSYNCIVPROC __gleGetSynciv;
#define glGetSynciv __gleGetSynciv
#endif /*GL_ARB_sync*/

/******************************
* Extension: GL_ARB_tessellation_shader
******************************/

#define GL_TRIANGLES 0x0004
#define GL_EQUAL 0x0202
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_QUADS 0x0007
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88


#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1

typedef void (GLE_FUNCPTR * PFNGLPATCHPARAMETERIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPATCHPARAMETERFVPROC)(GLenum , const GLfloat *);

extern PFNGLPATCHPARAMETERIPROC __glePatchParameteri;
#define glPatchParameteri __glePatchParameteri
extern PFNGLPATCHPARAMETERFVPROC __glePatchParameterfv;
#define glPatchParameterfv __glePatchParameterfv
#endif /*GL_ARB_tessellation_shader*/

/******************************
* Extension: GL_ARB_texture_border_clamp
******************************/

#define GL_CLAMP_TO_BORDER_ARB 0x812D


/******************************
* Extension: GL_ARB_texture_buffer_object
******************************/

#define GL_TEXTURE_BUFFER_ARB 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB 0x8C2E


#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERARBPROC)(GLenum , GLenum , GLuint );

extern PFNGLTEXBUFFERARBPROC glTexBufferARB;
#endif /*GL_ARB_texture_buffer_object*/

/******************************
* Extension: GL_ARB_texture_buffer_object_rgb32
******************************/

#define GL_RGB32F 0x8815
#define GL_RGB32UI 0x8D71
#define GL_RGB32I 0x8D83


/******************************
* Extension: GL_ARB_texture_buffer_range
******************************/

#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F


#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1

typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERRANGEPROC)(GLenum , GLenum , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREBUFFERRANGEEXTPROC)(GLuint , GLenum , GLenum , GLuint , GLintptr , GLsizeiptr );

extern PFNGLTEXBUFFERRANGEPROC __gleTexBufferRange;
#define glTexBufferRange __gleTexBufferRange
extern PFNGLTEXTUREBUFFERRANGEEXTPROC __gleTextureBufferRangeEXT;
#define glTextureBufferRangeEXT __gleTextureBufferRangeEXT
#endif /*GL_ARB_texture_buffer_range*/

/******************************
* Extension: GL_ARB_texture_compression
******************************/

#define GL_COMPRESSED_ALPHA_ARB 0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB 0x84EC
#define GL_COMPRESSED_RGB_ARB 0x84ED
#define GL_COMPRESSED_RGBA_ARB 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3


#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1

typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)(GLenum , GLint , GLvoid *);

extern PFNGLCOMPRESSEDTEXIMAGE3DARBPROC glCompressedTexImage3DARB;
extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;
extern PFNGLCOMPRESSEDTEXIMAGE1DARBPROC glCompressedTexImage1DARB;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC glCompressedTexSubImage3DARB;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC glCompressedTexSubImage2DARB;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC glCompressedTexSubImage1DARB;
extern PFNGLGETCOMPRESSEDTEXIMAGEARBPROC glGetCompressedTexImageARB;
#endif /*GL_ARB_texture_compression*/

/******************************
* Extension: GL_ARB_texture_compression_bptc
******************************/

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F


/******************************
* Extension: GL_ARB_texture_compression_rgtc
******************************/

#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE


/******************************
* Extension: GL_ARB_texture_cube_map
******************************/

#define GL_NORMAL_MAP_ARB 0x8511
#define GL_REFLECTION_MAP_ARB 0x8512
#define GL_TEXTURE_CUBE_MAP_ARB 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB 0x851C


/******************************
* Extension: GL_ARB_texture_cube_map_array
******************************/

#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F


/******************************
* Extension: GL_ARB_texture_env_add
******************************/

/******************************
* Extension: GL_ARB_texture_env_combine
******************************/

#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_RGB_SCALE_ARB 0x8573
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_INTERPOLATE_ARB 0x8575
#define GL_SUBTRACT_ARB 0x84E7
#define GL_CONSTANT_ARB 0x8576
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_PREVIOUS_ARB 0x8578


/******************************
* Extension: GL_ARB_texture_env_crossbar
******************************/

/******************************
* Extension: GL_ARB_texture_env_dot3
******************************/

#define GL_DOT3_RGB_ARB 0x86AE
#define GL_DOT3_RGBA_ARB 0x86AF


/******************************
* Extension: GL_ARB_texture_float
******************************/

#define GL_TEXTURE_RED_TYPE_ARB 0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB 0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB 0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB 0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB 0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB 0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB 0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB 0x8C17
#define GL_RGBA32F_ARB 0x8814
#define GL_RGB32F_ARB 0x8815
#define GL_ALPHA32F_ARB 0x8816
#define GL_INTENSITY32F_ARB 0x8817
#define GL_LUMINANCE32F_ARB 0x8818
#define GL_LUMINANCE_ALPHA32F_ARB 0x8819
#define GL_RGBA16F_ARB 0x881A
#define GL_RGB16F_ARB 0x881B
#define GL_ALPHA16F_ARB 0x881C
#define GL_INTENSITY16F_ARB 0x881D
#define GL_LUMINANCE16F_ARB 0x881E
#define GL_LUMINANCE_ALPHA16F_ARB 0x881F


/******************************
* Extension: GL_ARB_texture_gather
******************************/

#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F


/******************************
* Extension: GL_ARB_texture_mirrored_repeat
******************************/

#define GL_MIRRORED_REPEAT_ARB 0x8370


/******************************
* Extension: GL_ARB_texture_multisample
******************************/

#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110


#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1

typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DMULTISAMPLEPROC)(GLenum , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DMULTISAMPLEPROC)(GLenum , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLGETMULTISAMPLEFVPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKIPROC)(GLuint , GLbitfield );

extern PFNGLTEXIMAGE2DMULTISAMPLEPROC __gleTexImage2DMultisample;
#define glTexImage2DMultisample __gleTexImage2DMultisample
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC __gleTexImage3DMultisample;
#define glTexImage3DMultisample __gleTexImage3DMultisample
extern PFNGLGETMULTISAMPLEFVPROC __gleGetMultisamplefv;
#define glGetMultisamplefv __gleGetMultisamplefv
extern PFNGLSAMPLEMASKIPROC __gleSampleMaski;
#define glSampleMaski __gleSampleMaski
#endif /*GL_ARB_texture_multisample*/

/******************************
* Extension: GL_ARB_texture_non_power_of_two
******************************/

/******************************
* Extension: GL_ARB_texture_query_levels
******************************/

/******************************
* Extension: GL_ARB_texture_query_lod
******************************/

/******************************
* Extension: GL_ARB_texture_rectangle
******************************/

#define GL_TEXTURE_RECTANGLE_ARB 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8


/******************************
* Extension: GL_ARB_texture_rg
******************************/

#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C


/******************************
* Extension: GL_ARB_texture_rgb10_a2ui
******************************/

#define GL_RGB10_A2UI 0x906F


/******************************
* Extension: GL_ARB_texture_storage
******************************/

#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F


#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1

typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE1DPROC)(GLenum , GLsizei , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE2DPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE3DPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE1DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE2DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE3DEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei );

extern PFNGLTEXSTORAGE1DPROC __gleTexStorage1D;
#define glTexStorage1D __gleTexStorage1D
extern PFNGLTEXSTORAGE2DPROC __gleTexStorage2D;
#define glTexStorage2D __gleTexStorage2D
extern PFNGLTEXSTORAGE3DPROC __gleTexStorage3D;
#define glTexStorage3D __gleTexStorage3D
extern PFNGLTEXTURESTORAGE1DEXTPROC __gleTextureStorage1DEXT;
#define glTextureStorage1DEXT __gleTextureStorage1DEXT
extern PFNGLTEXTURESTORAGE2DEXTPROC __gleTextureStorage2DEXT;
#define glTextureStorage2DEXT __gleTextureStorage2DEXT
extern PFNGLTEXTURESTORAGE3DEXTPROC __gleTextureStorage3DEXT;
#define glTextureStorage3DEXT __gleTextureStorage3DEXT
#endif /*GL_ARB_texture_storage*/

/******************************
* Extension: GL_ARB_texture_storage_multisample
******************************/

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1

typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXSTORAGE3DMULTISAMPLEPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)(GLuint , GLenum , GLsizei , GLenum , GLsizei , GLsizei , GLsizei , GLboolean );

extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC __gleTexStorage2DMultisample;
#define glTexStorage2DMultisample __gleTexStorage2DMultisample
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC __gleTexStorage3DMultisample;
#define glTexStorage3DMultisample __gleTexStorage3DMultisample
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC __gleTextureStorage2DMultisampleEXT;
#define glTextureStorage2DMultisampleEXT __gleTextureStorage2DMultisampleEXT
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC __gleTextureStorage3DMultisampleEXT;
#define glTextureStorage3DMultisampleEXT __gleTextureStorage3DMultisampleEXT
#endif /*GL_ARB_texture_storage_multisample*/

/******************************
* Extension: GL_ARB_texture_swizzle
******************************/

#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46


/******************************
* Extension: GL_ARB_texture_view
******************************/

#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF


#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1

typedef void (GLE_FUNCPTR * PFNGLTEXTUREVIEWPROC)(GLuint , GLenum , GLuint , GLenum , GLuint , GLuint , GLuint , GLuint );

extern PFNGLTEXTUREVIEWPROC __gleTextureView;
#define glTextureView __gleTextureView
#endif /*GL_ARB_texture_view*/

/******************************
* Extension: GL_ARB_timer_query
******************************/

#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28


#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1

typedef void (GLE_FUNCPTR * PFNGLQUERYCOUNTERPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTI64VPROC)(GLuint , GLenum , GLint64 *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUI64VPROC)(GLuint , GLenum , GLuint64 *);

extern PFNGLQUERYCOUNTERPROC __gleQueryCounter;
#define glQueryCounter __gleQueryCounter
extern PFNGLGETQUERYOBJECTI64VPROC __gleGetQueryObjecti64v;
#define glGetQueryObjecti64v __gleGetQueryObjecti64v
extern PFNGLGETQUERYOBJECTUI64VPROC __gleGetQueryObjectui64v;
#define glGetQueryObjectui64v __gleGetQueryObjectui64v
#endif /*GL_ARB_timer_query*/

/******************************
* Extension: GL_ARB_transform_feedback2
******************************/

#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23 /* GL_TRANSFORM_FEEDBACK_PAUSED */
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24 /* GL_TRANSFORM_FEEDBACK_ACTIVE */
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24


#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1

typedef void (GLE_FUNCPTR * PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTRANSFORMFEEDBACKPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPAUSETRANSFORMFEEDBACKPROC)();
typedef void (GLE_FUNCPTR * PFNGLRESUMETRANSFORMFEEDBACKPROC)();
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKPROC)(GLenum , GLuint );

extern PFNGLBINDTRANSFORMFEEDBACKPROC __gleBindTransformFeedback;
#define glBindTransformFeedback __gleBindTransformFeedback
extern PFNGLDELETETRANSFORMFEEDBACKSPROC __gleDeleteTransformFeedbacks;
#define glDeleteTransformFeedbacks __gleDeleteTransformFeedbacks
extern PFNGLGENTRANSFORMFEEDBACKSPROC __gleGenTransformFeedbacks;
#define glGenTransformFeedbacks __gleGenTransformFeedbacks
extern PFNGLISTRANSFORMFEEDBACKPROC __gleIsTransformFeedback;
#define glIsTransformFeedback __gleIsTransformFeedback
extern PFNGLPAUSETRANSFORMFEEDBACKPROC __glePauseTransformFeedback;
#define glPauseTransformFeedback __glePauseTransformFeedback
extern PFNGLRESUMETRANSFORMFEEDBACKPROC __gleResumeTransformFeedback;
#define glResumeTransformFeedback __gleResumeTransformFeedback
extern PFNGLDRAWTRANSFORMFEEDBACKPROC __gleDrawTransformFeedback;
#define glDrawTransformFeedback __gleDrawTransformFeedback
#endif /*GL_ARB_transform_feedback2*/

/******************************
* Extension: GL_ARB_transform_feedback3
******************************/

#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70


#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1

typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYINDEXEDPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDQUERYINDEXEDPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYINDEXEDIVPROC)(GLenum , GLuint , GLenum , GLint *);

extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC __gleDrawTransformFeedbackStream;
#define glDrawTransformFeedbackStream __gleDrawTransformFeedbackStream
extern PFNGLBEGINQUERYINDEXEDPROC __gleBeginQueryIndexed;
#define glBeginQueryIndexed __gleBeginQueryIndexed
extern PFNGLENDQUERYINDEXEDPROC __gleEndQueryIndexed;
#define glEndQueryIndexed __gleEndQueryIndexed
extern PFNGLGETQUERYINDEXEDIVPROC __gleGetQueryIndexediv;
#define glGetQueryIndexediv __gleGetQueryIndexediv
#endif /*GL_ARB_transform_feedback3*/

/******************************
* Extension: GL_ARB_transform_feedback_instanced
******************************/

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1

typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)(GLenum , GLuint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)(GLenum , GLuint , GLuint , GLsizei );

extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC __gleDrawTransformFeedbackInstanced;
#define glDrawTransformFeedbackInstanced __gleDrawTransformFeedbackInstanced
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC __gleDrawTransformFeedbackStreamInstanced;
#define glDrawTransformFeedbackStreamInstanced __gleDrawTransformFeedbackStreamInstanced
#endif /*GL_ARB_transform_feedback_instanced*/

/******************************
* Extension: GL_ARB_transpose_matrix
******************************/

#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB 0x84E6


#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1

typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXFARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXDARBPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXFARBPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXDARBPROC)(const GLdouble *);

extern PFNGLLOADTRANSPOSEMATRIXFARBPROC glLoadTransposeMatrixfARB;
extern PFNGLLOADTRANSPOSEMATRIXDARBPROC glLoadTransposeMatrixdARB;
extern PFNGLMULTTRANSPOSEMATRIXFARBPROC glMultTransposeMatrixfARB;
extern PFNGLMULTTRANSPOSEMATRIXDARBPROC glMultTransposeMatrixdARB;
#endif /*GL_ARB_transpose_matrix*/

/******************************
* Extension: GL_ARB_uniform_buffer_object
******************************/

#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFF
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45


#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMINDICESPROC)(GLuint , GLsizei , const GLchar* const *, GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint , GLsizei , const GLuint *, GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMNAMEPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *);
typedef GLuint (GLE_FUNCPTR * PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint , GLuint , GLuint );

extern PFNGLGETUNIFORMINDICESPROC __gleGetUniformIndices;
#define glGetUniformIndices __gleGetUniformIndices
extern PFNGLGETACTIVEUNIFORMSIVPROC __gleGetActiveUniformsiv;
#define glGetActiveUniformsiv __gleGetActiveUniformsiv
extern PFNGLGETACTIVEUNIFORMNAMEPROC __gleGetActiveUniformName;
#define glGetActiveUniformName __gleGetActiveUniformName
extern PFNGLGETUNIFORMBLOCKINDEXPROC __gleGetUniformBlockIndex;
#define glGetUniformBlockIndex __gleGetUniformBlockIndex
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC __gleGetActiveUniformBlockiv;
#define glGetActiveUniformBlockiv __gleGetActiveUniformBlockiv
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC __gleGetActiveUniformBlockName;
#define glGetActiveUniformBlockName __gleGetActiveUniformBlockName
extern PFNGLUNIFORMBLOCKBINDINGPROC __gleUniformBlockBinding;
#define glUniformBlockBinding __gleUniformBlockBinding
#endif /*GL_ARB_uniform_buffer_object*/

/******************************
* Extension: GL_ARB_vertex_array_bgra
******************************/

#define GL_BGRA 0x80E1


/******************************
* Extension: GL_ARB_vertex_array_object
******************************/

#define GL_VERTEX_ARRAY_BINDING 0x85B5


#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1

typedef void (GLE_FUNCPTR * PFNGLBINDVERTEXARRAYPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEVERTEXARRAYSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENVERTEXARRAYSPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISVERTEXARRAYPROC)(GLuint );

extern PFNGLBINDVERTEXARRAYPROC __gleBindVertexArray;
#define glBindVertexArray __gleBindVertexArray
extern PFNGLDELETEVERTEXARRAYSPROC __gleDeleteVertexArrays;
#define glDeleteVertexArrays __gleDeleteVertexArrays
extern PFNGLGENVERTEXARRAYSPROC __gleGenVertexArrays;
#define glGenVertexArrays __gleGenVertexArrays
extern PFNGLISVERTEXARRAYPROC __gleIsVertexArray;
#define glIsVertexArray __gleIsVertexArray
#endif /*GL_ARB_vertex_array_object*/

/******************************
* Extension: GL_ARB_vertex_attrib_64bit
******************************/

#define GL_RGB32I 0x8D83
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E


#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1

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

extern PFNGLVERTEXATTRIBL1DPROC __gleVertexAttribL1d;
#define glVertexAttribL1d __gleVertexAttribL1d
extern PFNGLVERTEXATTRIBL2DPROC __gleVertexAttribL2d;
#define glVertexAttribL2d __gleVertexAttribL2d
extern PFNGLVERTEXATTRIBL3DPROC __gleVertexAttribL3d;
#define glVertexAttribL3d __gleVertexAttribL3d
extern PFNGLVERTEXATTRIBL4DPROC __gleVertexAttribL4d;
#define glVertexAttribL4d __gleVertexAttribL4d
extern PFNGLVERTEXATTRIBL1DVPROC __gleVertexAttribL1dv;
#define glVertexAttribL1dv __gleVertexAttribL1dv
extern PFNGLVERTEXATTRIBL2DVPROC __gleVertexAttribL2dv;
#define glVertexAttribL2dv __gleVertexAttribL2dv
extern PFNGLVERTEXATTRIBL3DVPROC __gleVertexAttribL3dv;
#define glVertexAttribL3dv __gleVertexAttribL3dv
extern PFNGLVERTEXATTRIBL4DVPROC __gleVertexAttribL4dv;
#define glVertexAttribL4dv __gleVertexAttribL4dv
extern PFNGLVERTEXATTRIBLPOINTERPROC __gleVertexAttribLPointer;
#define glVertexAttribLPointer __gleVertexAttribLPointer
extern PFNGLGETVERTEXATTRIBLDVPROC __gleGetVertexAttribLdv;
#define glGetVertexAttribLdv __gleGetVertexAttribLdv
#endif /*GL_ARB_vertex_attrib_64bit*/

/******************************
* Extension: GL_ARB_vertex_attrib_binding
******************************/

#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA


#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1

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

extern PFNGLBINDVERTEXBUFFERPROC __gleBindVertexBuffer;
#define glBindVertexBuffer __gleBindVertexBuffer
extern PFNGLVERTEXATTRIBFORMATPROC __gleVertexAttribFormat;
#define glVertexAttribFormat __gleVertexAttribFormat
extern PFNGLVERTEXATTRIBIFORMATPROC __gleVertexAttribIFormat;
#define glVertexAttribIFormat __gleVertexAttribIFormat
extern PFNGLVERTEXATTRIBLFORMATPROC __gleVertexAttribLFormat;
#define glVertexAttribLFormat __gleVertexAttribLFormat
extern PFNGLVERTEXATTRIBBINDINGPROC __gleVertexAttribBinding;
#define glVertexAttribBinding __gleVertexAttribBinding
extern PFNGLVERTEXBINDINGDIVISORPROC __gleVertexBindingDivisor;
#define glVertexBindingDivisor __gleVertexBindingDivisor
extern PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC __gleVertexArrayBindVertexBufferEXT;
#define glVertexArrayBindVertexBufferEXT __gleVertexArrayBindVertexBufferEXT
extern PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC __gleVertexArrayVertexAttribFormatEXT;
#define glVertexArrayVertexAttribFormatEXT __gleVertexArrayVertexAttribFormatEXT
extern PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC __gleVertexArrayVertexAttribIFormatEXT;
#define glVertexArrayVertexAttribIFormatEXT __gleVertexArrayVertexAttribIFormatEXT
extern PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC __gleVertexArrayVertexAttribLFormatEXT;
#define glVertexArrayVertexAttribLFormatEXT __gleVertexArrayVertexAttribLFormatEXT
extern PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC __gleVertexArrayVertexAttribBindingEXT;
#define glVertexArrayVertexAttribBindingEXT __gleVertexArrayVertexAttribBindingEXT
extern PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC __gleVertexArrayVertexBindingDivisorEXT;
#define glVertexArrayVertexBindingDivisorEXT __gleVertexArrayVertexBindingDivisorEXT
#endif /*GL_ARB_vertex_attrib_binding*/

/******************************
* Extension: GL_ARB_vertex_blend
******************************/

#define GL_MAX_VERTEX_UNITS_ARB 0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB 0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB 0x86A6
#define GL_VERTEX_BLEND_ARB 0x86A7
#define GL_CURRENT_WEIGHT_ARB 0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB 0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB 0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB 0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB 0x86AC
#define GL_WEIGHT_ARRAY_ARB 0x86AD
#define GL_MODELVIEW0_ARB 0x1700
#define GL_MODELVIEW1_ARB 0x850A
#define GL_MODELVIEW2_ARB 0x8722
#define GL_MODELVIEW3_ARB 0x8723
#define GL_MODELVIEW4_ARB 0x8724
#define GL_MODELVIEW5_ARB 0x8725
#define GL_MODELVIEW6_ARB 0x8726
#define GL_MODELVIEW7_ARB 0x8727
#define GL_MODELVIEW8_ARB 0x8728
#define GL_MODELVIEW9_ARB 0x8729
#define GL_MODELVIEW10_ARB 0x872A
#define GL_MODELVIEW11_ARB 0x872B
#define GL_MODELVIEW12_ARB 0x872C
#define GL_MODELVIEW13_ARB 0x872D
#define GL_MODELVIEW14_ARB 0x872E
#define GL_MODELVIEW15_ARB 0x872F
#define GL_MODELVIEW16_ARB 0x8730
#define GL_MODELVIEW17_ARB 0x8731
#define GL_MODELVIEW18_ARB 0x8732
#define GL_MODELVIEW19_ARB 0x8733
#define GL_MODELVIEW20_ARB 0x8734
#define GL_MODELVIEW21_ARB 0x8735
#define GL_MODELVIEW22_ARB 0x8736
#define GL_MODELVIEW23_ARB 0x8737
#define GL_MODELVIEW24_ARB 0x8738
#define GL_MODELVIEW25_ARB 0x8739
#define GL_MODELVIEW26_ARB 0x873A
#define GL_MODELVIEW27_ARB 0x873B
#define GL_MODELVIEW28_ARB 0x873C
#define GL_MODELVIEW29_ARB 0x873D
#define GL_MODELVIEW30_ARB 0x873E
#define GL_MODELVIEW31_ARB 0x873F


#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1

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

extern PFNGLWEIGHTBVARBPROC glWeightbvARB;
extern PFNGLWEIGHTSVARBPROC glWeightsvARB;
extern PFNGLWEIGHTIVARBPROC glWeightivARB;
extern PFNGLWEIGHTFVARBPROC glWeightfvARB;
extern PFNGLWEIGHTDVARBPROC glWeightdvARB;
extern PFNGLWEIGHTUBVARBPROC glWeightubvARB;
extern PFNGLWEIGHTUSVARBPROC glWeightusvARB;
extern PFNGLWEIGHTUIVARBPROC glWeightuivARB;
extern PFNGLWEIGHTPOINTERARBPROC glWeightPointerARB;
extern PFNGLVERTEXBLENDARBPROC glVertexBlendARB;
#endif /*GL_ARB_vertex_blend*/

/******************************
* Extension: GL_ARB_vertex_buffer_object
******************************/

#define GL_BUFFER_SIZE_ARB 0x8764
#define GL_BUFFER_USAGE_ARB 0x8765
#define GL_ARRAY_BUFFER_ARB 0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB 0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_READ_ONLY_ARB 0x88B8
#define GL_WRITE_ONLY_ARB 0x88B9
#define GL_READ_WRITE_ARB 0x88BA
#define GL_BUFFER_ACCESS_ARB 0x88BB
#define GL_BUFFER_MAPPED_ARB 0x88BC
#define GL_BUFFER_MAP_POINTER_ARB 0x88BD
#define GL_STREAM_DRAW_ARB 0x88E0
#define GL_STREAM_READ_ARB 0x88E1
#define GL_STREAM_COPY_ARB 0x88E2
#define GL_STATIC_DRAW_ARB 0x88E4
#define GL_STATIC_READ_ARB 0x88E5
#define GL_STATIC_COPY_ARB 0x88E6
#define GL_DYNAMIC_DRAW_ARB 0x88E8
#define GL_DYNAMIC_READ_ARB 0x88E9
#define GL_DYNAMIC_COPY_ARB 0x88EA


#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1

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

extern PFNGLBINDBUFFERARBPROC glBindBufferARB;
extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
extern PFNGLGENBUFFERSARBPROC glGenBuffersARB;
extern PFNGLISBUFFERARBPROC glIsBufferARB;
extern PFNGLBUFFERDATAARBPROC glBufferDataARB;
extern PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
extern PFNGLGETBUFFERSUBDATAARBPROC glGetBufferSubDataARB;
extern PFNGLMAPBUFFERARBPROC glMapBufferARB;
extern PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
extern PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;
extern PFNGLGETBUFFERPOINTERVARBPROC glGetBufferPointervARB;
#endif /*GL_ARB_vertex_buffer_object*/

/******************************
* Extension: GL_ARB_vertex_program
******************************/

#define GL_COLOR_SUM_ARB 0x8458
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB 0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB 0x8626
#define GL_PROGRAM_LENGTH_ARB 0x8627
#define GL_PROGRAM_STRING_ARB 0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB 0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_CURRENT_MATRIX_ARB 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB 0x864B
#define GL_PROGRAM_BINDING_ARB 0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_PROGRAM_ERROR_STRING_ARB 0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#define GL_PROGRAM_FORMAT_ARB 0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB 0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB 0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB 0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB 0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB 0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB 0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB 0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB 0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB 0x88B7
#define GL_MATRIX0_ARB 0x88C0
#define GL_MATRIX1_ARB 0x88C1
#define GL_MATRIX2_ARB 0x88C2
#define GL_MATRIX3_ARB 0x88C3
#define GL_MATRIX4_ARB 0x88C4
#define GL_MATRIX5_ARB 0x88C5
#define GL_MATRIX6_ARB 0x88C6
#define GL_MATRIX7_ARB 0x88C7
#define GL_MATRIX8_ARB 0x88C8
#define GL_MATRIX9_ARB 0x88C9
#define GL_MATRIX10_ARB 0x88CA
#define GL_MATRIX11_ARB 0x88CB
#define GL_MATRIX12_ARB 0x88CC
#define GL_MATRIX13_ARB 0x88CD
#define GL_MATRIX14_ARB 0x88CE
#define GL_MATRIX15_ARB 0x88CF
#define GL_MATRIX16_ARB 0x88D0
#define GL_MATRIX17_ARB 0x88D1
#define GL_MATRIX18_ARB 0x88D2
#define GL_MATRIX19_ARB 0x88D3
#define GL_MATRIX20_ARB 0x88D4
#define GL_MATRIX21_ARB 0x88D5
#define GL_MATRIX22_ARB 0x88D6
#define GL_MATRIX23_ARB 0x88D7
#define GL_MATRIX24_ARB 0x88D8
#define GL_MATRIX25_ARB 0x88D9
#define GL_MATRIX26_ARB 0x88DA
#define GL_MATRIX27_ARB 0x88DB
#define GL_MATRIX28_ARB 0x88DC
#define GL_MATRIX29_ARB 0x88DD
#define GL_MATRIX30_ARB 0x88DE
#define GL_MATRIX31_ARB 0x88DF


#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1

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

extern PFNGLVERTEXATTRIB1DARBPROC glVertexAttrib1dARB;
extern PFNGLVERTEXATTRIB1DVARBPROC glVertexAttrib1dvARB;
extern PFNGLVERTEXATTRIB1FARBPROC glVertexAttrib1fARB;
extern PFNGLVERTEXATTRIB1FVARBPROC glVertexAttrib1fvARB;
extern PFNGLVERTEXATTRIB1SARBPROC glVertexAttrib1sARB;
extern PFNGLVERTEXATTRIB1SVARBPROC glVertexAttrib1svARB;
extern PFNGLVERTEXATTRIB2DARBPROC glVertexAttrib2dARB;
extern PFNGLVERTEXATTRIB2DVARBPROC glVertexAttrib2dvARB;
extern PFNGLVERTEXATTRIB2FARBPROC glVertexAttrib2fARB;
extern PFNGLVERTEXATTRIB2FVARBPROC glVertexAttrib2fvARB;
extern PFNGLVERTEXATTRIB2SARBPROC glVertexAttrib2sARB;
extern PFNGLVERTEXATTRIB2SVARBPROC glVertexAttrib2svARB;
extern PFNGLVERTEXATTRIB3DARBPROC glVertexAttrib3dARB;
extern PFNGLVERTEXATTRIB3DVARBPROC glVertexAttrib3dvARB;
extern PFNGLVERTEXATTRIB3FARBPROC glVertexAttrib3fARB;
extern PFNGLVERTEXATTRIB3FVARBPROC glVertexAttrib3fvARB;
extern PFNGLVERTEXATTRIB3SARBPROC glVertexAttrib3sARB;
extern PFNGLVERTEXATTRIB3SVARBPROC glVertexAttrib3svARB;
extern PFNGLVERTEXATTRIB4NBVARBPROC glVertexAttrib4NbvARB;
extern PFNGLVERTEXATTRIB4NIVARBPROC glVertexAttrib4NivARB;
extern PFNGLVERTEXATTRIB4NSVARBPROC glVertexAttrib4NsvARB;
extern PFNGLVERTEXATTRIB4NUBARBPROC glVertexAttrib4NubARB;
extern PFNGLVERTEXATTRIB4NUBVARBPROC glVertexAttrib4NubvARB;
extern PFNGLVERTEXATTRIB4NUIVARBPROC glVertexAttrib4NuivARB;
extern PFNGLVERTEXATTRIB4NUSVARBPROC glVertexAttrib4NusvARB;
extern PFNGLVERTEXATTRIB4BVARBPROC glVertexAttrib4bvARB;
extern PFNGLVERTEXATTRIB4DARBPROC glVertexAttrib4dARB;
extern PFNGLVERTEXATTRIB4DVARBPROC glVertexAttrib4dvARB;
extern PFNGLVERTEXATTRIB4FARBPROC glVertexAttrib4fARB;
extern PFNGLVERTEXATTRIB4FVARBPROC glVertexAttrib4fvARB;
extern PFNGLVERTEXATTRIB4IVARBPROC glVertexAttrib4ivARB;
extern PFNGLVERTEXATTRIB4SARBPROC glVertexAttrib4sARB;
extern PFNGLVERTEXATTRIB4SVARBPROC glVertexAttrib4svARB;
extern PFNGLVERTEXATTRIB4UBVARBPROC glVertexAttrib4ubvARB;
extern PFNGLVERTEXATTRIB4UIVARBPROC glVertexAttrib4uivARB;
extern PFNGLVERTEXATTRIB4USVARBPROC glVertexAttrib4usvARB;
extern PFNGLVERTEXATTRIBPOINTERARBPROC glVertexAttribPointerARB;
extern PFNGLENABLEVERTEXATTRIBARRAYARBPROC glEnableVertexAttribArrayARB;
extern PFNGLDISABLEVERTEXATTRIBARRAYARBPROC glDisableVertexAttribArrayARB;
extern PFNGLPROGRAMSTRINGARBPROC glProgramStringARB;
extern PFNGLBINDPROGRAMARBPROC glBindProgramARB;
extern PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB;
extern PFNGLGENPROGRAMSARBPROC glGenProgramsARB;
extern PFNGLPROGRAMENVPARAMETER4DARBPROC glProgramEnvParameter4dARB;
extern PFNGLPROGRAMENVPARAMETER4DVARBPROC glProgramEnvParameter4dvARB;
extern PFNGLPROGRAMENVPARAMETER4FARBPROC glProgramEnvParameter4fARB;
extern PFNGLPROGRAMENVPARAMETER4FVARBPROC glProgramEnvParameter4fvARB;
extern PFNGLPROGRAMLOCALPARAMETER4DARBPROC glProgramLocalParameter4dARB;
extern PFNGLPROGRAMLOCALPARAMETER4DVARBPROC glProgramLocalParameter4dvARB;
extern PFNGLPROGRAMLOCALPARAMETER4FARBPROC glProgramLocalParameter4fARB;
extern PFNGLPROGRAMLOCALPARAMETER4FVARBPROC glProgramLocalParameter4fvARB;
extern PFNGLGETPROGRAMENVPARAMETERDVARBPROC glGetProgramEnvParameterdvARB;
extern PFNGLGETPROGRAMENVPARAMETERFVARBPROC glGetProgramEnvParameterfvARB;
extern PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC glGetProgramLocalParameterdvARB;
extern PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC glGetProgramLocalParameterfvARB;
extern PFNGLGETPROGRAMIVARBPROC glGetProgramivARB;
extern PFNGLGETPROGRAMSTRINGARBPROC glGetProgramStringARB;
extern PFNGLGETVERTEXATTRIBDVARBPROC glGetVertexAttribdvARB;
extern PFNGLGETVERTEXATTRIBFVARBPROC glGetVertexAttribfvARB;
extern PFNGLGETVERTEXATTRIBIVARBPROC glGetVertexAttribivARB;
extern PFNGLGETVERTEXATTRIBPOINTERVARBPROC glGetVertexAttribPointervARB;
extern PFNGLISPROGRAMARBPROC glIsProgramARB;
#endif /*GL_ARB_vertex_program*/

/******************************
* Extension: GL_ARB_vertex_shader
******************************/

#define GL_VERTEX_SHADER_ARB 0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB 0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A


#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1

typedef void (GLE_FUNCPTR * PFNGLBINDATTRIBLOCATIONARBPROC)(GLhandleARB , GLuint , const GLcharARB *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATTRIBARBPROC)(GLhandleARB , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLcharARB *);
typedef GLint (GLE_FUNCPTR * PFNGLGETATTRIBLOCATIONARBPROC)(GLhandleARB , const GLcharARB *);

extern PFNGLBINDATTRIBLOCATIONARBPROC glBindAttribLocationARB;
extern PFNGLGETACTIVEATTRIBARBPROC glGetActiveAttribARB;
extern PFNGLGETATTRIBLOCATIONARBPROC glGetAttribLocationARB;
#endif /*GL_ARB_vertex_shader*/

/******************************
* Extension: GL_ARB_vertex_type_2_10_10_10_rev
******************************/

#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_INT_2_10_10_10_REV 0x8D9F


#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1

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

extern PFNGLVERTEXP2UIPROC __gleVertexP2ui;
#define glVertexP2ui __gleVertexP2ui
extern PFNGLVERTEXP2UIVPROC __gleVertexP2uiv;
#define glVertexP2uiv __gleVertexP2uiv
extern PFNGLVERTEXP3UIPROC __gleVertexP3ui;
#define glVertexP3ui __gleVertexP3ui
extern PFNGLVERTEXP3UIVPROC __gleVertexP3uiv;
#define glVertexP3uiv __gleVertexP3uiv
extern PFNGLVERTEXP4UIPROC __gleVertexP4ui;
#define glVertexP4ui __gleVertexP4ui
extern PFNGLVERTEXP4UIVPROC __gleVertexP4uiv;
#define glVertexP4uiv __gleVertexP4uiv
extern PFNGLTEXCOORDP1UIPROC __gleTexCoordP1ui;
#define glTexCoordP1ui __gleTexCoordP1ui
extern PFNGLTEXCOORDP1UIVPROC __gleTexCoordP1uiv;
#define glTexCoordP1uiv __gleTexCoordP1uiv
extern PFNGLTEXCOORDP2UIPROC __gleTexCoordP2ui;
#define glTexCoordP2ui __gleTexCoordP2ui
extern PFNGLTEXCOORDP2UIVPROC __gleTexCoordP2uiv;
#define glTexCoordP2uiv __gleTexCoordP2uiv
extern PFNGLTEXCOORDP3UIPROC __gleTexCoordP3ui;
#define glTexCoordP3ui __gleTexCoordP3ui
extern PFNGLTEXCOORDP3UIVPROC __gleTexCoordP3uiv;
#define glTexCoordP3uiv __gleTexCoordP3uiv
extern PFNGLTEXCOORDP4UIPROC __gleTexCoordP4ui;
#define glTexCoordP4ui __gleTexCoordP4ui
extern PFNGLTEXCOORDP4UIVPROC __gleTexCoordP4uiv;
#define glTexCoordP4uiv __gleTexCoordP4uiv
extern PFNGLMULTITEXCOORDP1UIPROC __gleMultiTexCoordP1ui;
#define glMultiTexCoordP1ui __gleMultiTexCoordP1ui
extern PFNGLMULTITEXCOORDP1UIVPROC __gleMultiTexCoordP1uiv;
#define glMultiTexCoordP1uiv __gleMultiTexCoordP1uiv
extern PFNGLMULTITEXCOORDP2UIPROC __gleMultiTexCoordP2ui;
#define glMultiTexCoordP2ui __gleMultiTexCoordP2ui
extern PFNGLMULTITEXCOORDP2UIVPROC __gleMultiTexCoordP2uiv;
#define glMultiTexCoordP2uiv __gleMultiTexCoordP2uiv
extern PFNGLMULTITEXCOORDP3UIPROC __gleMultiTexCoordP3ui;
#define glMultiTexCoordP3ui __gleMultiTexCoordP3ui
extern PFNGLMULTITEXCOORDP3UIVPROC __gleMultiTexCoordP3uiv;
#define glMultiTexCoordP3uiv __gleMultiTexCoordP3uiv
extern PFNGLMULTITEXCOORDP4UIPROC __gleMultiTexCoordP4ui;
#define glMultiTexCoordP4ui __gleMultiTexCoordP4ui
extern PFNGLMULTITEXCOORDP4UIVPROC __gleMultiTexCoordP4uiv;
#define glMultiTexCoordP4uiv __gleMultiTexCoordP4uiv
extern PFNGLNORMALP3UIPROC __gleNormalP3ui;
#define glNormalP3ui __gleNormalP3ui
extern PFNGLNORMALP3UIVPROC __gleNormalP3uiv;
#define glNormalP3uiv __gleNormalP3uiv
extern PFNGLCOLORP3UIPROC __gleColorP3ui;
#define glColorP3ui __gleColorP3ui
extern PFNGLCOLORP3UIVPROC __gleColorP3uiv;
#define glColorP3uiv __gleColorP3uiv
extern PFNGLCOLORP4UIPROC __gleColorP4ui;
#define glColorP4ui __gleColorP4ui
extern PFNGLCOLORP4UIVPROC __gleColorP4uiv;
#define glColorP4uiv __gleColorP4uiv
extern PFNGLSECONDARYCOLORP3UIPROC __gleSecondaryColorP3ui;
#define glSecondaryColorP3ui __gleSecondaryColorP3ui
extern PFNGLSECONDARYCOLORP3UIVPROC __gleSecondaryColorP3uiv;
#define glSecondaryColorP3uiv __gleSecondaryColorP3uiv
extern PFNGLVERTEXATTRIBP1UIPROC __gleVertexAttribP1ui;
#define glVertexAttribP1ui __gleVertexAttribP1ui
extern PFNGLVERTEXATTRIBP1UIVPROC __gleVertexAttribP1uiv;
#define glVertexAttribP1uiv __gleVertexAttribP1uiv
extern PFNGLVERTEXATTRIBP2UIPROC __gleVertexAttribP2ui;
#define glVertexAttribP2ui __gleVertexAttribP2ui
extern PFNGLVERTEXATTRIBP2UIVPROC __gleVertexAttribP2uiv;
#define glVertexAttribP2uiv __gleVertexAttribP2uiv
extern PFNGLVERTEXATTRIBP3UIPROC __gleVertexAttribP3ui;
#define glVertexAttribP3ui __gleVertexAttribP3ui
extern PFNGLVERTEXATTRIBP3UIVPROC __gleVertexAttribP3uiv;
#define glVertexAttribP3uiv __gleVertexAttribP3uiv
extern PFNGLVERTEXATTRIBP4UIPROC __gleVertexAttribP4ui;
#define glVertexAttribP4ui __gleVertexAttribP4ui
extern PFNGLVERTEXATTRIBP4UIVPROC __gleVertexAttribP4uiv;
#define glVertexAttribP4uiv __gleVertexAttribP4uiv
#endif /*GL_ARB_vertex_type_2_10_10_10_rev*/

/******************************
* Extension: GL_ARB_viewport_array
******************************/

#define GL_DEPTH_RANGE 0x0B70
#define GL_VIEWPORT 0x0BA2
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260


#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1

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

extern PFNGLVIEWPORTARRAYVPROC __gleViewportArrayv;
#define glViewportArrayv __gleViewportArrayv
extern PFNGLVIEWPORTINDEXEDFPROC __gleViewportIndexedf;
#define glViewportIndexedf __gleViewportIndexedf
extern PFNGLVIEWPORTINDEXEDFVPROC __gleViewportIndexedfv;
#define glViewportIndexedfv __gleViewportIndexedfv
extern PFNGLSCISSORARRAYVPROC __gleScissorArrayv;
#define glScissorArrayv __gleScissorArrayv
extern PFNGLSCISSORINDEXEDPROC __gleScissorIndexed;
#define glScissorIndexed __gleScissorIndexed
extern PFNGLSCISSORINDEXEDVPROC __gleScissorIndexedv;
#define glScissorIndexedv __gleScissorIndexedv
extern PFNGLDEPTHRANGEARRAYVPROC __gleDepthRangeArrayv;
#define glDepthRangeArrayv __gleDepthRangeArrayv
extern PFNGLDEPTHRANGEINDEXEDPROC __gleDepthRangeIndexed;
#define glDepthRangeIndexed __gleDepthRangeIndexed
extern PFNGLGETFLOATI_VPROC __gleGetFloati_v;
#define glGetFloati_v __gleGetFloati_v
extern PFNGLGETDOUBLEI_VPROC __gleGetDoublei_v;
#define glGetDoublei_v __gleGetDoublei_v
#endif /*GL_ARB_viewport_array*/

/******************************
* Extension: GL_ARB_window_pos
******************************/

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1

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

extern PFNGLWINDOWPOS2DARBPROC glWindowPos2dARB;
extern PFNGLWINDOWPOS2DVARBPROC glWindowPos2dvARB;
extern PFNGLWINDOWPOS2FARBPROC glWindowPos2fARB;
extern PFNGLWINDOWPOS2FVARBPROC glWindowPos2fvARB;
extern PFNGLWINDOWPOS2IARBPROC glWindowPos2iARB;
extern PFNGLWINDOWPOS2IVARBPROC glWindowPos2ivARB;
extern PFNGLWINDOWPOS2SARBPROC glWindowPos2sARB;
extern PFNGLWINDOWPOS2SVARBPROC glWindowPos2svARB;
extern PFNGLWINDOWPOS3DARBPROC glWindowPos3dARB;
extern PFNGLWINDOWPOS3DVARBPROC glWindowPos3dvARB;
extern PFNGLWINDOWPOS3FARBPROC glWindowPos3fARB;
extern PFNGLWINDOWPOS3FVARBPROC glWindowPos3fvARB;
extern PFNGLWINDOWPOS3IARBPROC glWindowPos3iARB;
extern PFNGLWINDOWPOS3IVARBPROC glWindowPos3ivARB;
extern PFNGLWINDOWPOS3SARBPROC glWindowPos3sARB;
extern PFNGLWINDOWPOS3SVARBPROC glWindowPos3svARB;
#endif /*GL_ARB_window_pos*/

/******************************
* Extension: GL_ATI_draw_buffers
******************************/

#define GL_MAX_DRAW_BUFFERS_ATI 0x8824
#define GL_DRAW_BUFFER0_ATI 0x8825
#define GL_DRAW_BUFFER1_ATI 0x8826
#define GL_DRAW_BUFFER2_ATI 0x8827
#define GL_DRAW_BUFFER3_ATI 0x8828
#define GL_DRAW_BUFFER4_ATI 0x8829
#define GL_DRAW_BUFFER5_ATI 0x882A
#define GL_DRAW_BUFFER6_ATI 0x882B
#define GL_DRAW_BUFFER7_ATI 0x882C
#define GL_DRAW_BUFFER8_ATI 0x882D
#define GL_DRAW_BUFFER9_ATI 0x882E
#define GL_DRAW_BUFFER10_ATI 0x882F
#define GL_DRAW_BUFFER11_ATI 0x8830
#define GL_DRAW_BUFFER12_ATI 0x8831
#define GL_DRAW_BUFFER13_ATI 0x8832
#define GL_DRAW_BUFFER14_ATI 0x8833
#define GL_DRAW_BUFFER15_ATI 0x8834


#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1

typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSATIPROC)(GLsizei , const GLenum *);

extern PFNGLDRAWBUFFERSATIPROC glDrawBuffersATI;
#endif /*GL_ATI_draw_buffers*/

/******************************
* Extension: GL_ATI_element_array
******************************/

#define GL_ELEMENT_ARRAY_ATI 0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI 0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI 0x876A


#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1

typedef void (GLE_FUNCPTR * PFNGLELEMENTPOINTERATIPROC)(GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTARRAYATIPROC)(GLenum , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTARRAYATIPROC)(GLenum , GLuint , GLuint , GLsizei );

extern PFNGLELEMENTPOINTERATIPROC glElementPointerATI;
extern PFNGLDRAWELEMENTARRAYATIPROC glDrawElementArrayATI;
extern PFNGLDRAWRANGEELEMENTARRAYATIPROC glDrawRangeElementArrayATI;
#endif /*GL_ATI_element_array*/

/******************************
* Extension: GL_ATI_envmap_bumpmap
******************************/

#define GL_BUMP_ROT_MATRIX_ATI 0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI 0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI 0x8777
#define GL_BUMP_TEX_UNITS_ATI 0x8778
#define GL_DUDV_ATI 0x8779
#define GL_DU8DV8_ATI 0x877A
#define GL_BUMP_ENVMAP_ATI 0x877B
#define GL_BUMP_TARGET_ATI 0x877C


#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1

typedef void (GLE_FUNCPTR * PFNGLTEXBUMPPARAMETERIVATIPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXBUMPPARAMETERFVATIPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXBUMPPARAMETERIVATIPROC)(GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXBUMPPARAMETERFVATIPROC)(GLenum , GLfloat *);

extern PFNGLTEXBUMPPARAMETERIVATIPROC glTexBumpParameterivATI;
extern PFNGLTEXBUMPPARAMETERFVATIPROC glTexBumpParameterfvATI;
extern PFNGLGETTEXBUMPPARAMETERIVATIPROC glGetTexBumpParameterivATI;
extern PFNGLGETTEXBUMPPARAMETERFVATIPROC glGetTexBumpParameterfvATI;
#endif /*GL_ATI_envmap_bumpmap*/

/******************************
* Extension: GL_ATI_fragment_shader
******************************/

#define GL_FRAGMENT_SHADER_ATI 0x8920
#define GL_REG_0_ATI 0x8921
#define GL_REG_1_ATI 0x8922
#define GL_REG_2_ATI 0x8923
#define GL_REG_3_ATI 0x8924
#define GL_REG_4_ATI 0x8925
#define GL_REG_5_ATI 0x8926
#define GL_REG_6_ATI 0x8927
#define GL_REG_7_ATI 0x8928
#define GL_REG_8_ATI 0x8929
#define GL_REG_9_ATI 0x892A
#define GL_REG_10_ATI 0x892B
#define GL_REG_11_ATI 0x892C
#define GL_REG_12_ATI 0x892D
#define GL_REG_13_ATI 0x892E
#define GL_REG_14_ATI 0x892F
#define GL_REG_15_ATI 0x8930
#define GL_REG_16_ATI 0x8931
#define GL_REG_17_ATI 0x8932
#define GL_REG_18_ATI 0x8933
#define GL_REG_19_ATI 0x8934
#define GL_REG_20_ATI 0x8935
#define GL_REG_21_ATI 0x8936
#define GL_REG_22_ATI 0x8937
#define GL_REG_23_ATI 0x8938
#define GL_REG_24_ATI 0x8939
#define GL_REG_25_ATI 0x893A
#define GL_REG_26_ATI 0x893B
#define GL_REG_27_ATI 0x893C
#define GL_REG_28_ATI 0x893D
#define GL_REG_29_ATI 0x893E
#define GL_REG_30_ATI 0x893F
#define GL_REG_31_ATI 0x8940
#define GL_CON_0_ATI 0x8941
#define GL_CON_1_ATI 0x8942
#define GL_CON_2_ATI 0x8943
#define GL_CON_3_ATI 0x8944
#define GL_CON_4_ATI 0x8945
#define GL_CON_5_ATI 0x8946
#define GL_CON_6_ATI 0x8947
#define GL_CON_7_ATI 0x8948
#define GL_CON_8_ATI 0x8949
#define GL_CON_9_ATI 0x894A
#define GL_CON_10_ATI 0x894B
#define GL_CON_11_ATI 0x894C
#define GL_CON_12_ATI 0x894D
#define GL_CON_13_ATI 0x894E
#define GL_CON_14_ATI 0x894F
#define GL_CON_15_ATI 0x8950
#define GL_CON_16_ATI 0x8951
#define GL_CON_17_ATI 0x8952
#define GL_CON_18_ATI 0x8953
#define GL_CON_19_ATI 0x8954
#define GL_CON_20_ATI 0x8955
#define GL_CON_21_ATI 0x8956
#define GL_CON_22_ATI 0x8957
#define GL_CON_23_ATI 0x8958
#define GL_CON_24_ATI 0x8959
#define GL_CON_25_ATI 0x895A
#define GL_CON_26_ATI 0x895B
#define GL_CON_27_ATI 0x895C
#define GL_CON_28_ATI 0x895D
#define GL_CON_29_ATI 0x895E
#define GL_CON_30_ATI 0x895F
#define GL_CON_31_ATI 0x8960
#define GL_MOV_ATI 0x8961
#define GL_ADD_ATI 0x8963
#define GL_MUL_ATI 0x8964
#define GL_SUB_ATI 0x8965
#define GL_DOT3_ATI 0x8966
#define GL_DOT4_ATI 0x8967
#define GL_MAD_ATI 0x8968
#define GL_LERP_ATI 0x8969
#define GL_CND_ATI 0x896A
#define GL_CND0_ATI 0x896B
#define GL_DOT2_ADD_ATI 0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI 0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI 0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI 0x896F
#define GL_NUM_PASSES_ATI 0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI 0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI 0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI 0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI 0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI 0x8975
#define GL_SWIZZLE_STR_ATI 0x8976
#define GL_SWIZZLE_STQ_ATI 0x8977
#define GL_SWIZZLE_STR_DR_ATI 0x8978
#define GL_SWIZZLE_STQ_DQ_ATI 0x8979
#define GL_SWIZZLE_STRQ_ATI 0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI 0x897B
#define GL_RED_BIT_ATI 0x00000001
#define GL_GREEN_BIT_ATI 0x00000002
#define GL_BLUE_BIT_ATI 0x00000004
#define GL_2X_BIT_ATI 0x00000001
#define GL_2X_BIT_ATI 0x00000001
#define GL_4X_BIT_ATI 0x00000002
#define GL_8X_BIT_ATI 0x00000004
#define GL_HALF_BIT_ATI 0x00000008
#define GL_QUARTER_BIT_ATI 0x00000010
#define GL_EIGHTH_BIT_ATI 0x00000020
#define GL_SATURATE_BIT_ATI 0x00000040
#define GL_COMP_BIT_ATI 0x00000002
#define GL_NEGATE_BIT_ATI 0x00000004
#define GL_BIAS_BIT_ATI 0x00000008


#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1

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

extern PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI;
extern PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI;
extern PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI;
extern PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI;
extern PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI;
extern PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI;
extern PFNGLSAMPLEMAPATIPROC glSampleMapATI;
extern PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI;
extern PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI;
extern PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI;
extern PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI;
extern PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI;
extern PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI;
extern PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI;
#endif /*GL_ATI_fragment_shader*/

/******************************
* Extension: GL_ATI_map_object_buffer
******************************/

#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1

typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPOBJECTBUFFERATIPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNMAPOBJECTBUFFERATIPROC)(GLuint );

extern PFNGLMAPOBJECTBUFFERATIPROC glMapObjectBufferATI;
extern PFNGLUNMAPOBJECTBUFFERATIPROC glUnmapObjectBufferATI;
#endif /*GL_ATI_map_object_buffer*/

/******************************
* Extension: GL_ATI_meminfo
******************************/

#define GL_VBO_FREE_MEMORY_ATI 0x87FB
#define GL_TEXTURE_FREE_MEMORY_ATI 0x87FC
#define GL_RENDERBUFFER_FREE_MEMORY_ATI 0x87FD


/******************************
* Extension: GL_ATI_pixel_format_float
******************************/

#define GL_RGBA_FLOAT_MODE_ATI 0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835


/******************************
* Extension: GL_ATI_pn_triangles
******************************/

#define GL_PN_TRIANGLES_ATI 0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI 0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI 0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI 0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI 0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI 0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI 0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI 0x87F8


#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1

typedef void (GLE_FUNCPTR * PFNGLPNTRIANGLESIATIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPNTRIANGLESFATIPROC)(GLenum , GLfloat );

extern PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI;
extern PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI;
#endif /*GL_ATI_pn_triangles*/

/******************************
* Extension: GL_ATI_separate_stencil
******************************/

#define GL_STENCIL_BACK_FUNC_ATI 0x8800
#define GL_STENCIL_BACK_FAIL_ATI 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI 0x8803


#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1

typedef void (GLE_FUNCPTR * PFNGLSTENCILOPSEPARATEATIPROC)(GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCSEPARATEATIPROC)(GLenum , GLenum , GLint , GLuint );

extern PFNGLSTENCILOPSEPARATEATIPROC glStencilOpSeparateATI;
extern PFNGLSTENCILFUNCSEPARATEATIPROC glStencilFuncSeparateATI;
#endif /*GL_ATI_separate_stencil*/

/******************************
* Extension: GL_ATI_text_fragment_shader
******************************/

#define GL_TEXT_FRAGMENT_SHADER_ATI 0x8200


/******************************
* Extension: GL_ATI_texture_env_combine3
******************************/

#define GL_MODULATE_ADD_ATI 0x8744
#define GL_MODULATE_SIGNED_ADD_ATI 0x8745
#define GL_MODULATE_SUBTRACT_ATI 0x8746


/******************************
* Extension: GL_ATI_texture_float
******************************/

#define GL_RGBA_FLOAT32_ATI 0x8814
#define GL_RGB_FLOAT32_ATI 0x8815
#define GL_ALPHA_FLOAT32_ATI 0x8816
#define GL_INTENSITY_FLOAT32_ATI 0x8817
#define GL_LUMINANCE_FLOAT32_ATI 0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI 0x8819
#define GL_RGBA_FLOAT16_ATI 0x881A
#define GL_RGB_FLOAT16_ATI 0x881B
#define GL_ALPHA_FLOAT16_ATI 0x881C
#define GL_INTENSITY_FLOAT16_ATI 0x881D
#define GL_LUMINANCE_FLOAT16_ATI 0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI 0x881F


/******************************
* Extension: GL_ATI_texture_mirror_once
******************************/

#define GL_MIRROR_CLAMP_ATI 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI 0x8743


/******************************
* Extension: GL_ATI_vertex_array_object
******************************/

#define GL_STATIC_ATI 0x8760
#define GL_DYNAMIC_ATI 0x8761
#define GL_PRESERVE_ATI 0x8762
#define GL_DISCARD_ATI 0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI 0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI 0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI 0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI 0x8767


#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1

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

extern PFNGLNEWOBJECTBUFFERATIPROC glNewObjectBufferATI;
extern PFNGLISOBJECTBUFFERATIPROC glIsObjectBufferATI;
extern PFNGLUPDATEOBJECTBUFFERATIPROC glUpdateObjectBufferATI;
extern PFNGLGETOBJECTBUFFERFVATIPROC glGetObjectBufferfvATI;
extern PFNGLGETOBJECTBUFFERIVATIPROC glGetObjectBufferivATI;
extern PFNGLFREEOBJECTBUFFERATIPROC glFreeObjectBufferATI;
extern PFNGLARRAYOBJECTATIPROC glArrayObjectATI;
extern PFNGLGETARRAYOBJECTFVATIPROC glGetArrayObjectfvATI;
extern PFNGLGETARRAYOBJECTIVATIPROC glGetArrayObjectivATI;
extern PFNGLVARIANTARRAYOBJECTATIPROC glVariantArrayObjectATI;
extern PFNGLGETVARIANTARRAYOBJECTFVATIPROC glGetVariantArrayObjectfvATI;
extern PFNGLGETVARIANTARRAYOBJECTIVATIPROC glGetVariantArrayObjectivATI;
#endif /*GL_ATI_vertex_array_object*/

/******************************
* Extension: GL_ATI_vertex_attrib_array_object
******************************/

#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1

typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)(GLuint , GLenum , GLint *);

extern PFNGLVERTEXATTRIBARRAYOBJECTATIPROC glVertexAttribArrayObjectATI;
extern PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC glGetVertexAttribArrayObjectfvATI;
extern PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC glGetVertexAttribArrayObjectivATI;
#endif /*GL_ATI_vertex_attrib_array_object*/

/******************************
* Extension: GL_ATI_vertex_streams
******************************/

#define GL_MAX_VERTEX_STREAMS_ATI 0x876B
#define GL_VERTEX_STREAM0_ATI 0x876C
#define GL_VERTEX_STREAM1_ATI 0x876D
#define GL_VERTEX_STREAM2_ATI 0x876E
#define GL_VERTEX_STREAM3_ATI 0x876F
#define GL_VERTEX_STREAM4_ATI 0x8770
#define GL_VERTEX_STREAM5_ATI 0x8771
#define GL_VERTEX_STREAM6_ATI 0x8772
#define GL_VERTEX_STREAM7_ATI 0x8773
#define GL_VERTEX_SOURCE_ATI 0x8774


#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1

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

extern PFNGLVERTEXSTREAM1SATIPROC glVertexStream1sATI;
extern PFNGLVERTEXSTREAM1SVATIPROC glVertexStream1svATI;
extern PFNGLVERTEXSTREAM1IATIPROC glVertexStream1iATI;
extern PFNGLVERTEXSTREAM1IVATIPROC glVertexStream1ivATI;
extern PFNGLVERTEXSTREAM1FATIPROC glVertexStream1fATI;
extern PFNGLVERTEXSTREAM1FVATIPROC glVertexStream1fvATI;
extern PFNGLVERTEXSTREAM1DATIPROC glVertexStream1dATI;
extern PFNGLVERTEXSTREAM1DVATIPROC glVertexStream1dvATI;
extern PFNGLVERTEXSTREAM2SATIPROC glVertexStream2sATI;
extern PFNGLVERTEXSTREAM2SVATIPROC glVertexStream2svATI;
extern PFNGLVERTEXSTREAM2IATIPROC glVertexStream2iATI;
extern PFNGLVERTEXSTREAM2IVATIPROC glVertexStream2ivATI;
extern PFNGLVERTEXSTREAM2FATIPROC glVertexStream2fATI;
extern PFNGLVERTEXSTREAM2FVATIPROC glVertexStream2fvATI;
extern PFNGLVERTEXSTREAM2DATIPROC glVertexStream2dATI;
extern PFNGLVERTEXSTREAM2DVATIPROC glVertexStream2dvATI;
extern PFNGLVERTEXSTREAM3SATIPROC glVertexStream3sATI;
extern PFNGLVERTEXSTREAM3SVATIPROC glVertexStream3svATI;
extern PFNGLVERTEXSTREAM3IATIPROC glVertexStream3iATI;
extern PFNGLVERTEXSTREAM3IVATIPROC glVertexStream3ivATI;
extern PFNGLVERTEXSTREAM3FATIPROC glVertexStream3fATI;
extern PFNGLVERTEXSTREAM3FVATIPROC glVertexStream3fvATI;
extern PFNGLVERTEXSTREAM3DATIPROC glVertexStream3dATI;
extern PFNGLVERTEXSTREAM3DVATIPROC glVertexStream3dvATI;
extern PFNGLVERTEXSTREAM4SATIPROC glVertexStream4sATI;
extern PFNGLVERTEXSTREAM4SVATIPROC glVertexStream4svATI;
extern PFNGLVERTEXSTREAM4IATIPROC glVertexStream4iATI;
extern PFNGLVERTEXSTREAM4IVATIPROC glVertexStream4ivATI;
extern PFNGLVERTEXSTREAM4FATIPROC glVertexStream4fATI;
extern PFNGLVERTEXSTREAM4FVATIPROC glVertexStream4fvATI;
extern PFNGLVERTEXSTREAM4DATIPROC glVertexStream4dATI;
extern PFNGLVERTEXSTREAM4DVATIPROC glVertexStream4dvATI;
extern PFNGLNORMALSTREAM3BATIPROC glNormalStream3bATI;
extern PFNGLNORMALSTREAM3BVATIPROC glNormalStream3bvATI;
extern PFNGLNORMALSTREAM3SATIPROC glNormalStream3sATI;
extern PFNGLNORMALSTREAM3SVATIPROC glNormalStream3svATI;
extern PFNGLNORMALSTREAM3IATIPROC glNormalStream3iATI;
extern PFNGLNORMALSTREAM3IVATIPROC glNormalStream3ivATI;
extern PFNGLNORMALSTREAM3FATIPROC glNormalStream3fATI;
extern PFNGLNORMALSTREAM3FVATIPROC glNormalStream3fvATI;
extern PFNGLNORMALSTREAM3DATIPROC glNormalStream3dATI;
extern PFNGLNORMALSTREAM3DVATIPROC glNormalStream3dvATI;
extern PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC glClientActiveVertexStreamATI;
extern PFNGLVERTEXBLENDENVIATIPROC glVertexBlendEnviATI;
extern PFNGLVERTEXBLENDENVFATIPROC glVertexBlendEnvfATI;
#endif /*GL_ATI_vertex_streams*/

/******************************
* Extension: GL_EXT_422_pixels
******************************/

#define GL_422_EXT 0x80CC
#define GL_422_REV_EXT 0x80CD
#define GL_422_AVERAGE_EXT 0x80CE
#define GL_422_REV_AVERAGE_EXT 0x80CF


/******************************
* Extension: GL_EXT_abgr
******************************/

#define GL_ABGR_EXT 0x8000


/******************************
* Extension: GL_EXT_bgra
******************************/

#define GL_BGR_EXT 0x80E0
#define GL_BGRA_EXT 0x80E1


/******************************
* Extension: GL_EXT_bindable_uniform
******************************/

#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT 0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT 0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT 0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT 0x8DED
#define GL_UNIFORM_BUFFER_EXT 0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT 0x8DEF


#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1

typedef void (GLE_FUNCPTR * PFNGLUNIFORMBUFFEREXTPROC)(GLuint , GLint , GLuint );
typedef GLint (GLE_FUNCPTR * PFNGLGETUNIFORMBUFFERSIZEEXTPROC)(GLuint , GLint );
typedef GLintptr (GLE_FUNCPTR * PFNGLGETUNIFORMOFFSETEXTPROC)(GLuint , GLint );

extern PFNGLUNIFORMBUFFEREXTPROC glUniformBufferEXT;
extern PFNGLGETUNIFORMBUFFERSIZEEXTPROC glGetUniformBufferSizeEXT;
extern PFNGLGETUNIFORMOFFSETEXTPROC glGetUniformOffsetEXT;
#endif /*GL_EXT_bindable_uniform*/

/******************************
* Extension: GL_EXT_blend_color
******************************/

#define GL_CONSTANT_COLOR_EXT 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT 0x8002
#define GL_CONSTANT_ALPHA_EXT 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT 0x8004
#define GL_BLEND_COLOR_EXT 0x8005


#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1

typedef void (GLE_FUNCPTR * PFNGLBLENDCOLOREXTPROC)(GLfloat , GLfloat , GLfloat , GLfloat );

extern PFNGLBLENDCOLOREXTPROC glBlendColorEXT;
#endif /*GL_EXT_blend_color*/

/******************************
* Extension: GL_EXT_blend_equation_separate
******************************/

#define GL_BLEND_EQUATION_RGB_EXT 0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT 0x883D


#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1

typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEEXTPROC)(GLenum , GLenum );

extern PFNGLBLENDEQUATIONSEPARATEEXTPROC glBlendEquationSeparateEXT;
#endif /*GL_EXT_blend_equation_separate*/

/******************************
* Extension: GL_EXT_blend_func_separate
******************************/

#define GL_BLEND_DST_RGB_EXT 0x80C8
#define GL_BLEND_SRC_RGB_EXT 0x80C9
#define GL_BLEND_DST_ALPHA_EXT 0x80CA
#define GL_BLEND_SRC_ALPHA_EXT 0x80CB


#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1

typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEEXTPROC)(GLenum , GLenum , GLenum , GLenum );

extern PFNGLBLENDFUNCSEPARATEEXTPROC glBlendFuncSeparateEXT;
#endif /*GL_EXT_blend_func_separate*/

/******************************
* Extension: GL_EXT_blend_logic_op
******************************/

/******************************
* Extension: GL_EXT_blend_minmax
******************************/

#define GL_FUNC_ADD_EXT 0x8006
#define GL_MIN_EXT 0x8007
#define GL_MAX_EXT 0x8008
#define GL_BLEND_EQUATION_EXT 0x8009


#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1

typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONEXTPROC)(GLenum );

extern PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT;
#endif /*GL_EXT_blend_minmax*/

/******************************
* Extension: GL_EXT_blend_subtract
******************************/

#define GL_FUNC_SUBTRACT_EXT 0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT 0x800B


/******************************
* Extension: GL_EXT_clip_volume_hint
******************************/

#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT 0x80F0


/******************************
* Extension: GL_EXT_cmyka
******************************/

#define GL_CMYK_EXT 0x800C
#define GL_CMYKA_EXT 0x800D
#define GL_PACK_CMYK_HINT_EXT 0x800E
#define GL_UNPACK_CMYK_HINT_EXT 0x800F


/******************************
* Extension: GL_EXT_color_subtable
******************************/

#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1

typedef void (GLE_FUNCPTR * PFNGLCOLORSUBTABLEEXTPROC)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORSUBTABLEEXTPROC)(GLenum , GLsizei , GLint , GLint , GLsizei );

extern PFNGLCOLORSUBTABLEEXTPROC glColorSubTableEXT;
extern PFNGLCOPYCOLORSUBTABLEEXTPROC glCopyColorSubTableEXT;
#endif /*GL_EXT_color_subtable*/

/******************************
* Extension: GL_EXT_compiled_vertex_array
******************************/

#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT 0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT 0x81A9


#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1

typedef void (GLE_FUNCPTR * PFNGLLOCKARRAYSEXTPROC)(GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLUNLOCKARRAYSEXTPROC)();

extern PFNGLLOCKARRAYSEXTPROC glLockArraysEXT;
extern PFNGLUNLOCKARRAYSEXTPROC glUnlockArraysEXT;
#endif /*GL_EXT_compiled_vertex_array*/

/******************************
* Extension: GL_EXT_convolution
******************************/

#define GL_CONVOLUTION_1D_EXT 0x8010
#define GL_CONVOLUTION_2D_EXT 0x8011
#define GL_SEPARABLE_2D_EXT 0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT 0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT 0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT 0x8015
#define GL_REDUCE_EXT 0x8016
#define GL_CONVOLUTION_FORMAT_EXT 0x8017
#define GL_CONVOLUTION_WIDTH_EXT 0x8018
#define GL_CONVOLUTION_HEIGHT_EXT 0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT 0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT 0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT 0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT 0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT 0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT 0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT 0x8023


#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1

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

extern PFNGLCONVOLUTIONFILTER1DEXTPROC glConvolutionFilter1DEXT;
extern PFNGLCONVOLUTIONFILTER2DEXTPROC glConvolutionFilter2DEXT;
extern PFNGLCONVOLUTIONPARAMETERFEXTPROC glConvolutionParameterfEXT;
extern PFNGLCONVOLUTIONPARAMETERFVEXTPROC glConvolutionParameterfvEXT;
extern PFNGLCONVOLUTIONPARAMETERIEXTPROC glConvolutionParameteriEXT;
extern PFNGLCONVOLUTIONPARAMETERIVEXTPROC glConvolutionParameterivEXT;
extern PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC glCopyConvolutionFilter1DEXT;
extern PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC glCopyConvolutionFilter2DEXT;
extern PFNGLGETCONVOLUTIONFILTEREXTPROC glGetConvolutionFilterEXT;
extern PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC glGetConvolutionParameterfvEXT;
extern PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC glGetConvolutionParameterivEXT;
extern PFNGLGETSEPARABLEFILTEREXTPROC glGetSeparableFilterEXT;
extern PFNGLSEPARABLEFILTER2DEXTPROC glSeparableFilter2DEXT;
#endif /*GL_EXT_convolution*/

/******************************
* Extension: GL_EXT_coordinate_frame
******************************/

#define GL_TANGENT_ARRAY_EXT 0x8439
#define GL_BINORMAL_ARRAY_EXT 0x843A
#define GL_CURRENT_TANGENT_EXT 0x843B
#define GL_CURRENT_BINORMAL_EXT 0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT 0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT 0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT 0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT 0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT 0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT 0x8443
#define GL_MAP1_TANGENT_EXT 0x8444
#define GL_MAP2_TANGENT_EXT 0x8445
#define GL_MAP1_BINORMAL_EXT 0x8446
#define GL_MAP2_BINORMAL_EXT 0x8447


#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1

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

extern PFNGLTANGENT3BEXTPROC glTangent3bEXT;
extern PFNGLTANGENT3BVEXTPROC glTangent3bvEXT;
extern PFNGLTANGENT3DEXTPROC glTangent3dEXT;
extern PFNGLTANGENT3DVEXTPROC glTangent3dvEXT;
extern PFNGLTANGENT3FEXTPROC glTangent3fEXT;
extern PFNGLTANGENT3FVEXTPROC glTangent3fvEXT;
extern PFNGLTANGENT3IEXTPROC glTangent3iEXT;
extern PFNGLTANGENT3IVEXTPROC glTangent3ivEXT;
extern PFNGLTANGENT3SEXTPROC glTangent3sEXT;
extern PFNGLTANGENT3SVEXTPROC glTangent3svEXT;
extern PFNGLBINORMAL3BEXTPROC glBinormal3bEXT;
extern PFNGLBINORMAL3BVEXTPROC glBinormal3bvEXT;
extern PFNGLBINORMAL3DEXTPROC glBinormal3dEXT;
extern PFNGLBINORMAL3DVEXTPROC glBinormal3dvEXT;
extern PFNGLBINORMAL3FEXTPROC glBinormal3fEXT;
extern PFNGLBINORMAL3FVEXTPROC glBinormal3fvEXT;
extern PFNGLBINORMAL3IEXTPROC glBinormal3iEXT;
extern PFNGLBINORMAL3IVEXTPROC glBinormal3ivEXT;
extern PFNGLBINORMAL3SEXTPROC glBinormal3sEXT;
extern PFNGLBINORMAL3SVEXTPROC glBinormal3svEXT;
extern PFNGLTANGENTPOINTEREXTPROC glTangentPointerEXT;
extern PFNGLBINORMALPOINTEREXTPROC glBinormalPointerEXT;
#endif /*GL_EXT_coordinate_frame*/

/******************************
* Extension: GL_EXT_copy_texture
******************************/

#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1

typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE1DEXTPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE2DEXTPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE1DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE2DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE3DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );

extern PFNGLCOPYTEXIMAGE1DEXTPROC glCopyTexImage1DEXT;
extern PFNGLCOPYTEXIMAGE2DEXTPROC glCopyTexImage2DEXT;
extern PFNGLCOPYTEXSUBIMAGE1DEXTPROC glCopyTexSubImage1DEXT;
extern PFNGLCOPYTEXSUBIMAGE2DEXTPROC glCopyTexSubImage2DEXT;
extern PFNGLCOPYTEXSUBIMAGE3DEXTPROC glCopyTexSubImage3DEXT;
#endif /*GL_EXT_copy_texture*/

/******************************
* Extension: GL_EXT_cull_vertex
******************************/

#define GL_CULL_VERTEX_EXT 0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT 0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT 0x81AC


#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1

typedef void (GLE_FUNCPTR * PFNGLCULLPARAMETERDVEXTPROC)(GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCULLPARAMETERFVEXTPROC)(GLenum , GLfloat *);

extern PFNGLCULLPARAMETERDVEXTPROC glCullParameterdvEXT;
extern PFNGLCULLPARAMETERFVEXTPROC glCullParameterfvEXT;
#endif /*GL_EXT_cull_vertex*/

/******************************
* Extension: GL_EXT_depth_bounds_test
******************************/

#define GL_DEPTH_BOUNDS_TEST_EXT 0x8890
#define GL_DEPTH_BOUNDS_EXT 0x8891


#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1

typedef void (GLE_FUNCPTR * PFNGLDEPTHBOUNDSEXTPROC)(GLclampd , GLclampd );

extern PFNGLDEPTHBOUNDSEXTPROC glDepthBoundsEXT;
#endif /*GL_EXT_depth_bounds_test*/

/******************************
* Extension: GL_EXT_direct_state_access
******************************/

#define GL_PROGRAM_MATRIX_EXT 0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT 0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F


#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1

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

extern PFNGLCLIENTATTRIBDEFAULTEXTPROC glClientAttribDefaultEXT;
extern PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC glPushClientAttribDefaultEXT;
extern PFNGLMATRIXLOADFEXTPROC glMatrixLoadfEXT;
extern PFNGLMATRIXLOADDEXTPROC glMatrixLoaddEXT;
extern PFNGLMATRIXMULTFEXTPROC glMatrixMultfEXT;
extern PFNGLMATRIXMULTDEXTPROC glMatrixMultdEXT;
extern PFNGLMATRIXLOADIDENTITYEXTPROC glMatrixLoadIdentityEXT;
extern PFNGLMATRIXROTATEFEXTPROC glMatrixRotatefEXT;
extern PFNGLMATRIXROTATEDEXTPROC glMatrixRotatedEXT;
extern PFNGLMATRIXSCALEFEXTPROC glMatrixScalefEXT;
extern PFNGLMATRIXSCALEDEXTPROC glMatrixScaledEXT;
extern PFNGLMATRIXTRANSLATEFEXTPROC glMatrixTranslatefEXT;
extern PFNGLMATRIXTRANSLATEDEXTPROC glMatrixTranslatedEXT;
extern PFNGLMATRIXFRUSTUMEXTPROC glMatrixFrustumEXT;
extern PFNGLMATRIXORTHOEXTPROC glMatrixOrthoEXT;
extern PFNGLMATRIXPOPEXTPROC glMatrixPopEXT;
extern PFNGLMATRIXPUSHEXTPROC glMatrixPushEXT;
extern PFNGLMATRIXLOADTRANSPOSEFEXTPROC glMatrixLoadTransposefEXT;
extern PFNGLMATRIXLOADTRANSPOSEDEXTPROC glMatrixLoadTransposedEXT;
extern PFNGLMATRIXMULTTRANSPOSEFEXTPROC glMatrixMultTransposefEXT;
extern PFNGLMATRIXMULTTRANSPOSEDEXTPROC glMatrixMultTransposedEXT;
extern PFNGLTEXTUREPARAMETERFEXTPROC glTextureParameterfEXT;
extern PFNGLTEXTUREPARAMETERFVEXTPROC glTextureParameterfvEXT;
extern PFNGLTEXTUREPARAMETERIEXTPROC glTextureParameteriEXT;
extern PFNGLTEXTUREPARAMETERIVEXTPROC glTextureParameterivEXT;
extern PFNGLTEXTUREIMAGE1DEXTPROC glTextureImage1DEXT;
extern PFNGLTEXTUREIMAGE2DEXTPROC glTextureImage2DEXT;
extern PFNGLTEXTURESUBIMAGE1DEXTPROC glTextureSubImage1DEXT;
extern PFNGLTEXTURESUBIMAGE2DEXTPROC glTextureSubImage2DEXT;
extern PFNGLCOPYTEXTUREIMAGE1DEXTPROC glCopyTextureImage1DEXT;
extern PFNGLCOPYTEXTUREIMAGE2DEXTPROC glCopyTextureImage2DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glCopyTextureSubImage1DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glCopyTextureSubImage2DEXT;
extern PFNGLGETTEXTUREIMAGEEXTPROC glGetTextureImageEXT;
extern PFNGLGETTEXTUREPARAMETERFVEXTPROC glGetTextureParameterfvEXT;
extern PFNGLGETTEXTUREPARAMETERIVEXTPROC glGetTextureParameterivEXT;
extern PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glGetTextureLevelParameterfvEXT;
extern PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glGetTextureLevelParameterivEXT;
extern PFNGLTEXTUREIMAGE3DEXTPROC glTextureImage3DEXT;
extern PFNGLTEXTURESUBIMAGE3DEXTPROC glTextureSubImage3DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glCopyTextureSubImage3DEXT;
extern PFNGLMULTITEXPARAMETERFEXTPROC glMultiTexParameterfEXT;
extern PFNGLMULTITEXPARAMETERFVEXTPROC glMultiTexParameterfvEXT;
extern PFNGLMULTITEXPARAMETERIEXTPROC glMultiTexParameteriEXT;
extern PFNGLMULTITEXPARAMETERIVEXTPROC glMultiTexParameterivEXT;
extern PFNGLMULTITEXIMAGE1DEXTPROC glMultiTexImage1DEXT;
extern PFNGLMULTITEXIMAGE2DEXTPROC glMultiTexImage2DEXT;
extern PFNGLMULTITEXSUBIMAGE1DEXTPROC glMultiTexSubImage1DEXT;
extern PFNGLMULTITEXSUBIMAGE2DEXTPROC glMultiTexSubImage2DEXT;
extern PFNGLCOPYMULTITEXIMAGE1DEXTPROC glCopyMultiTexImage1DEXT;
extern PFNGLCOPYMULTITEXIMAGE2DEXTPROC glCopyMultiTexImage2DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC glCopyMultiTexSubImage1DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC glCopyMultiTexSubImage2DEXT;
extern PFNGLGETMULTITEXIMAGEEXTPROC glGetMultiTexImageEXT;
extern PFNGLGETMULTITEXPARAMETERFVEXTPROC glGetMultiTexParameterfvEXT;
extern PFNGLGETMULTITEXPARAMETERIVEXTPROC glGetMultiTexParameterivEXT;
extern PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC glGetMultiTexLevelParameterfvEXT;
extern PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC glGetMultiTexLevelParameterivEXT;
extern PFNGLMULTITEXIMAGE3DEXTPROC glMultiTexImage3DEXT;
extern PFNGLMULTITEXSUBIMAGE3DEXTPROC glMultiTexSubImage3DEXT;
extern PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC glCopyMultiTexSubImage3DEXT;
extern PFNGLBINDMULTITEXTUREEXTPROC glBindMultiTextureEXT;
extern PFNGLENABLECLIENTSTATEINDEXEDEXTPROC glEnableClientStateIndexedEXT;
extern PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC glDisableClientStateIndexedEXT;
extern PFNGLENABLECLIENTSTATEIEXTPROC glEnableClientStateiEXT;
extern PFNGLDISABLECLIENTSTATEIEXTPROC glDisableClientStateiEXT;
extern PFNGLMULTITEXCOORDPOINTEREXTPROC glMultiTexCoordPointerEXT;
extern PFNGLMULTITEXENVFEXTPROC glMultiTexEnvfEXT;
extern PFNGLMULTITEXENVFVEXTPROC glMultiTexEnvfvEXT;
extern PFNGLMULTITEXENVIEXTPROC glMultiTexEnviEXT;
extern PFNGLMULTITEXENVIVEXTPROC glMultiTexEnvivEXT;
extern PFNGLMULTITEXGENDEXTPROC glMultiTexGendEXT;
extern PFNGLMULTITEXGENDVEXTPROC glMultiTexGendvEXT;
extern PFNGLMULTITEXGENFEXTPROC glMultiTexGenfEXT;
extern PFNGLMULTITEXGENFVEXTPROC glMultiTexGenfvEXT;
extern PFNGLMULTITEXGENIEXTPROC glMultiTexGeniEXT;
extern PFNGLMULTITEXGENIVEXTPROC glMultiTexGenivEXT;
extern PFNGLGETMULTITEXENVFVEXTPROC glGetMultiTexEnvfvEXT;
extern PFNGLGETMULTITEXENVIVEXTPROC glGetMultiTexEnvivEXT;
extern PFNGLGETMULTITEXGENDVEXTPROC glGetMultiTexGendvEXT;
extern PFNGLGETMULTITEXGENFVEXTPROC glGetMultiTexGenfvEXT;
extern PFNGLGETMULTITEXGENIVEXTPROC glGetMultiTexGenivEXT;
extern PFNGLGETFLOATINDEXEDVEXTPROC glGetFloatIndexedvEXT;
extern PFNGLGETDOUBLEINDEXEDVEXTPROC glGetDoubleIndexedvEXT;
extern PFNGLGETPOINTERINDEXEDVEXTPROC glGetPointerIndexedvEXT;
extern PFNGLGETFLOATI_VEXTPROC glGetFloati_vEXT;
extern PFNGLGETDOUBLEI_VEXTPROC glGetDoublei_vEXT;
extern PFNGLGETPOINTERI_VEXTPROC glGetPointeri_vEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glCompressedTextureImage3DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glCompressedTextureImage2DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glCompressedTextureImage1DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glCompressedTextureSubImage3DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glCompressedTextureSubImage2DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glCompressedTextureSubImage1DEXT;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glGetCompressedTextureImageEXT;
extern PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC glCompressedMultiTexImage3DEXT;
extern PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC glCompressedMultiTexImage2DEXT;
extern PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC glCompressedMultiTexImage1DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC glCompressedMultiTexSubImage3DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC glCompressedMultiTexSubImage2DEXT;
extern PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC glCompressedMultiTexSubImage1DEXT;
extern PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC glGetCompressedMultiTexImageEXT;
extern PFNGLNAMEDPROGRAMSTRINGEXTPROC glNamedProgramStringEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC glNamedProgramLocalParameter4dEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC glNamedProgramLocalParameter4dvEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC glNamedProgramLocalParameter4fEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC glNamedProgramLocalParameter4fvEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC glGetNamedProgramLocalParameterdvEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC glGetNamedProgramLocalParameterfvEXT;
extern PFNGLGETNAMEDPROGRAMIVEXTPROC glGetNamedProgramivEXT;
extern PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glGetNamedProgramStringEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC glNamedProgramLocalParameters4fvEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC glNamedProgramLocalParameterI4iEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC glNamedProgramLocalParameterI4ivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC glNamedProgramLocalParametersI4ivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC glNamedProgramLocalParameterI4uiEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC glNamedProgramLocalParameterI4uivEXT;
extern PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC glNamedProgramLocalParametersI4uivEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC glGetNamedProgramLocalParameterIivEXT;
extern PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC glGetNamedProgramLocalParameterIuivEXT;
extern PFNGLTEXTUREPARAMETERIIVEXTPROC glTextureParameterIivEXT;
extern PFNGLTEXTUREPARAMETERIUIVEXTPROC glTextureParameterIuivEXT;
extern PFNGLGETTEXTUREPARAMETERIIVEXTPROC glGetTextureParameterIivEXT;
extern PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glGetTextureParameterIuivEXT;
extern PFNGLMULTITEXPARAMETERIIVEXTPROC glMultiTexParameterIivEXT;
extern PFNGLMULTITEXPARAMETERIUIVEXTPROC glMultiTexParameterIuivEXT;
extern PFNGLGETMULTITEXPARAMETERIIVEXTPROC glGetMultiTexParameterIivEXT;
extern PFNGLGETMULTITEXPARAMETERIUIVEXTPROC glGetMultiTexParameterIuivEXT;
extern PFNGLPROGRAMUNIFORM1FEXTPROC glProgramUniform1fEXT;
extern PFNGLPROGRAMUNIFORM2FEXTPROC glProgramUniform2fEXT;
extern PFNGLPROGRAMUNIFORM3FEXTPROC glProgramUniform3fEXT;
extern PFNGLPROGRAMUNIFORM4FEXTPROC glProgramUniform4fEXT;
extern PFNGLPROGRAMUNIFORM1IEXTPROC glProgramUniform1iEXT;
extern PFNGLPROGRAMUNIFORM2IEXTPROC glProgramUniform2iEXT;
extern PFNGLPROGRAMUNIFORM3IEXTPROC glProgramUniform3iEXT;
extern PFNGLPROGRAMUNIFORM4IEXTPROC glProgramUniform4iEXT;
extern PFNGLPROGRAMUNIFORM1FVEXTPROC glProgramUniform1fvEXT;
extern PFNGLPROGRAMUNIFORM2FVEXTPROC glProgramUniform2fvEXT;
extern PFNGLPROGRAMUNIFORM3FVEXTPROC glProgramUniform3fvEXT;
extern PFNGLPROGRAMUNIFORM4FVEXTPROC glProgramUniform4fvEXT;
extern PFNGLPROGRAMUNIFORM1IVEXTPROC glProgramUniform1ivEXT;
extern PFNGLPROGRAMUNIFORM2IVEXTPROC glProgramUniform2ivEXT;
extern PFNGLPROGRAMUNIFORM3IVEXTPROC glProgramUniform3ivEXT;
extern PFNGLPROGRAMUNIFORM4IVEXTPROC glProgramUniform4ivEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glProgramUniformMatrix2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glProgramUniformMatrix3fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glProgramUniformMatrix4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glProgramUniformMatrix2x3fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glProgramUniformMatrix3x2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glProgramUniformMatrix2x4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glProgramUniformMatrix4x2fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glProgramUniformMatrix3x4fvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glProgramUniformMatrix4x3fvEXT;
extern PFNGLPROGRAMUNIFORM1UIEXTPROC glProgramUniform1uiEXT;
extern PFNGLPROGRAMUNIFORM2UIEXTPROC glProgramUniform2uiEXT;
extern PFNGLPROGRAMUNIFORM3UIEXTPROC glProgramUniform3uiEXT;
extern PFNGLPROGRAMUNIFORM4UIEXTPROC glProgramUniform4uiEXT;
extern PFNGLPROGRAMUNIFORM1UIVEXTPROC glProgramUniform1uivEXT;
extern PFNGLPROGRAMUNIFORM2UIVEXTPROC glProgramUniform2uivEXT;
extern PFNGLPROGRAMUNIFORM3UIVEXTPROC glProgramUniform3uivEXT;
extern PFNGLPROGRAMUNIFORM4UIVEXTPROC glProgramUniform4uivEXT;
extern PFNGLNAMEDBUFFERDATAEXTPROC glNamedBufferDataEXT;
extern PFNGLNAMEDBUFFERSUBDATAEXTPROC glNamedBufferSubDataEXT;
extern PFNGLMAPNAMEDBUFFEREXTPROC glMapNamedBufferEXT;
extern PFNGLUNMAPNAMEDBUFFEREXTPROC glUnmapNamedBufferEXT;
extern PFNGLMAPNAMEDBUFFERRANGEEXTPROC glMapNamedBufferRangeEXT;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRangeEXT;
extern PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glNamedCopyBufferSubDataEXT;
extern PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glGetNamedBufferParameterivEXT;
extern PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glGetNamedBufferPointervEXT;
extern PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glGetNamedBufferSubDataEXT;
extern PFNGLTEXTUREBUFFEREXTPROC glTextureBufferEXT;
extern PFNGLMULTITEXBUFFEREXTPROC glMultiTexBufferEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glNamedRenderbufferStorageEXT;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glGetNamedRenderbufferParameterivEXT;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glCheckNamedFramebufferStatusEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glNamedFramebufferTexture1DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glNamedFramebufferTexture2DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glNamedFramebufferTexture3DEXT;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glNamedFramebufferRenderbufferEXT;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetNamedFramebufferAttachmentParameterivEXT;
extern PFNGLGENERATETEXTUREMIPMAPEXTPROC glGenerateTextureMipmapEXT;
extern PFNGLGENERATEMULTITEXMIPMAPEXTPROC glGenerateMultiTexMipmapEXT;
extern PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glFramebufferDrawBufferEXT;
extern PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glFramebufferDrawBuffersEXT;
extern PFNGLFRAMEBUFFERREADBUFFEREXTPROC glFramebufferReadBufferEXT;
extern PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glGetFramebufferParameterivEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glNamedRenderbufferStorageMultisampleEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glNamedRenderbufferStorageMultisampleCoverageEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glNamedFramebufferTextureEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glNamedFramebufferTextureLayerEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glNamedFramebufferTextureFaceEXT;
extern PFNGLTEXTURERENDERBUFFEREXTPROC glTextureRenderbufferEXT;
extern PFNGLMULTITEXRENDERBUFFEREXTPROC glMultiTexRenderbufferEXT;
extern PFNGLPROGRAMUNIFORM1DEXTPROC glProgramUniform1dEXT;
extern PFNGLPROGRAMUNIFORM2DEXTPROC glProgramUniform2dEXT;
extern PFNGLPROGRAMUNIFORM3DEXTPROC glProgramUniform3dEXT;
extern PFNGLPROGRAMUNIFORM4DEXTPROC glProgramUniform4dEXT;
extern PFNGLPROGRAMUNIFORM1DVEXTPROC glProgramUniform1dvEXT;
extern PFNGLPROGRAMUNIFORM2DVEXTPROC glProgramUniform2dvEXT;
extern PFNGLPROGRAMUNIFORM3DVEXTPROC glProgramUniform3dvEXT;
extern PFNGLPROGRAMUNIFORM4DVEXTPROC glProgramUniform4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC glProgramUniformMatrix2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC glProgramUniformMatrix3dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC glProgramUniformMatrix4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC glProgramUniformMatrix2x3dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC glProgramUniformMatrix2x4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC glProgramUniformMatrix3x2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC glProgramUniformMatrix3x4dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC glProgramUniformMatrix4x2dvEXT;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC glProgramUniformMatrix4x3dvEXT;
extern PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glEnableVertexArrayAttribEXT;
extern PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glDisableVertexArrayAttribEXT;
extern PFNGLENABLEVERTEXARRAYEXTPROC glEnableVertexArrayEXT;
extern PFNGLDISABLEVERTEXARRAYEXTPROC glDisableVertexArrayEXT;
extern PFNGLVERTEXARRAYCOLOROFFSETEXTPROC glVertexArrayColorOffsetEXT;
extern PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC glVertexArrayEdgeFlagOffsetEXT;
extern PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC glVertexArrayFogCoordOffsetEXT;
extern PFNGLVERTEXARRAYINDEXOFFSETEXTPROC glVertexArrayIndexOffsetEXT;
extern PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC glVertexArrayMultiTexCoordOffsetEXT;
extern PFNGLVERTEXARRAYNORMALOFFSETEXTPROC glVertexArrayNormalOffsetEXT;
extern PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC glVertexArraySecondaryColorOffsetEXT;
extern PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC glVertexArrayTexCoordOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glVertexArrayVertexOffsetEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glVertexArrayVertexAttribIOffsetEXT;
extern PFNGLGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glglVertexArrayVertexAttribOffsetEXT;
extern PFNGLGETVERTEXARRAYINTEGERVEXTPROC glGetVertexArrayIntegervEXT;
extern PFNGLGETVERTEXARRAYPOINTERVEXTPROC glGetVertexArrayPointervEXT;
extern PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glGetVertexArrayIntegeri_vEXT;
extern PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glGetVertexArrayPointeri_vEXT;
#endif /*GL_EXT_direct_state_access*/

/******************************
* Extension: GL_EXT_draw_buffers2
******************************/

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1

typedef void (GLE_FUNCPTR * PFNGLCOLORMASKINDEXEDEXTPROC)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANINDEXEDVEXTPROC)(GLenum , GLuint , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERINDEXEDVEXTPROC)(GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLENABLEINDEXEDEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEINDEXEDEXTPROC)(GLenum , GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDINDEXEDEXTPROC)(GLenum , GLuint );

extern PFNGLCOLORMASKINDEXEDEXTPROC glColorMaskIndexedEXT;
extern PFNGLGETBOOLEANINDEXEDVEXTPROC glGetBooleanIndexedvEXT;
extern PFNGLGETINTEGERINDEXEDVEXTPROC glGetIntegerIndexedvEXT;
extern PFNGLENABLEINDEXEDEXTPROC glEnableIndexedEXT;
extern PFNGLDISABLEINDEXEDEXTPROC glDisableIndexedEXT;
extern PFNGLISENABLEDINDEXEDEXTPROC glIsEnabledIndexedEXT;
#endif /*GL_EXT_draw_buffers2*/

/******************************
* Extension: GL_EXT_draw_instanced
******************************/

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1

typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDEXTPROC)(GLenum , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDEXTPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );

extern PFNGLDRAWARRAYSINSTANCEDEXTPROC glDrawArraysInstancedEXT;
extern PFNGLDRAWELEMENTSINSTANCEDEXTPROC glDrawElementsInstancedEXT;
#endif /*GL_EXT_draw_instanced*/

/******************************
* Extension: GL_EXT_draw_range_elements
******************************/

#define GL_MAX_ELEMENTS_VERTICES_EXT 0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT 0x80E9


#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1

typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSEXTPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *);

extern PFNGLDRAWRANGEELEMENTSEXTPROC glDrawRangeElementsEXT;
#endif /*GL_EXT_draw_range_elements*/

/******************************
* Extension: GL_EXT_fog_coord
******************************/

#define GL_FRAGMENT_DEPTH_EXT 0x8452
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_CURRENT_FOG_COORDINATE_EXT 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT 0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT 0x8457


#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1

typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFEXTPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDEXTPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDVEXTPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTEREXTPROC)(GLenum , GLsizei , const GLvoid *);

extern PFNGLFOGCOORDFEXTPROC glFogCoordfEXT;
extern PFNGLFOGCOORDFVEXTPROC glFogCoordfvEXT;
extern PFNGLFOGCOORDDEXTPROC glFogCoorddEXT;
extern PFNGLFOGCOORDDVEXTPROC glFogCoorddvEXT;
extern PFNGLFOGCOORDPOINTEREXTPROC glFogCoordPointerEXT;
#endif /*GL_EXT_fog_coord*/

/******************************
* Extension: GL_EXT_framebuffer_blit
******************************/

#define GL_READ_FRAMEBUFFER_EXT 0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT 0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT 0x8CA6 /* GL_FRAMEBUFFER_BINDING_EXT */
#define GL_READ_FRAMEBUFFER_BINDING_EXT 0x8CAA


#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1

typedef void (GLE_FUNCPTR * PFNGLBLITFRAMEBUFFEREXTPROC)(GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum );

extern PFNGLBLITFRAMEBUFFEREXTPROC glBlitFramebufferEXT;
#endif /*GL_EXT_framebuffer_blit*/

/******************************
* Extension: GL_EXT_framebuffer_multisample
******************************/

#define GL_RENDERBUFFER_SAMPLES_EXT 0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT 0x8D56
#define GL_MAX_SAMPLES_EXT 0x8D57


#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1

typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)(GLenum , GLsizei , GLenum , GLsizei , GLsizei );

extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glRenderbufferStorageMultisampleEXT;
#endif /*GL_EXT_framebuffer_multisample*/

/******************************
* Extension: GL_EXT_framebuffer_multisample_blit_scaled
******************************/

#define GL_SCALED_RESOLVE_FASTEST_EXT 0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT 0x90BB


/******************************
* Extension: GL_EXT_framebuffer_object
******************************/

#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT 0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT 0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT 0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT 0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT 0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT 0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT 0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT 0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT 0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT 0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT 0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT 0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT 0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT 0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT 0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT 0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT 0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT 0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT 0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT 0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT 0x8CED
#define GL_COLOR_ATTACHMENT14_EXT 0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT 0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT 0x8D20
#define GL_FRAMEBUFFER_EXT 0x8D40
#define GL_RENDERBUFFER_EXT 0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT 0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT 0x8D44
#define GL_STENCIL_INDEX1_EXT 0x8D46
#define GL_STENCIL_INDEX4_EXT 0x8D47
#define GL_STENCIL_INDEX8_EXT 0x8D48
#define GL_STENCIL_INDEX16_EXT 0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT 0x8D55


#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1

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

extern PFNGLISRENDERBUFFEREXTPROC glIsRenderbufferEXT;
extern PFNGLBINDRENDERBUFFEREXTPROC glBindRenderbufferEXT;
extern PFNGLDELETERENDERBUFFERSEXTPROC glDeleteRenderbuffersEXT;
extern PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
extern PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;
extern PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC glGetRenderbufferParameterivEXT;
extern PFNGLISFRAMEBUFFEREXTPROC glIsFramebufferEXT;
extern PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
extern PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
extern PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC glFramebufferTexture1DEXT;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC glFramebufferTexture3DEXT;
extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetFramebufferAttachmentParameterivEXT;
extern PFNGLGENERATEMIPMAPEXTPROC glGenerateMipmapEXT;
#endif /*GL_EXT_framebuffer_object*/

/******************************
* Extension: GL_EXT_framebuffer_sRGB
******************************/

#define GL_FRAMEBUFFER_SRGB_EXT 0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x8DBA


/******************************
* Extension: GL_EXT_geometry_shader4
******************************/

#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642
#define GL_GEOMETRY_SHADER_EXT 0x8DD9
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT 0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT 0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT 0x8DE1


#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint , GLenum , GLint );

extern PFNGLPROGRAMPARAMETERIEXTPROC glProgramParameteriEXT;
#endif /*GL_EXT_geometry_shader4*/

/******************************
* Extension: GL_EXT_gpu_program_parameters
******************************/

#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)(GLenum , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)(GLenum , GLuint , GLsizei , const GLfloat *);

extern PFNGLPROGRAMENVPARAMETERS4FVEXTPROC glProgramEnvParameters4fvEXT;
extern PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC glProgramLocalParameters4fvEXT;
#endif /*GL_EXT_gpu_program_parameters*/

/******************************
* Extension: GL_EXT_gpu_shader4
******************************/

#define GL_SAMPLER_1D_ARRAY_EXT 0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT 0x8DC1
#define GL_SAMPLER_BUFFER_EXT 0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT 0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT 0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT 0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT 0x8DC8
#define GL_INT_SAMPLER_1D_EXT 0x8DC9
#define GL_INT_SAMPLER_2D_EXT 0x8DCA
#define GL_INT_SAMPLER_3D_EXT 0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT 0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT 0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT 0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT 0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT 0x8DD8


#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1

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

extern PFNGLGETUNIFORMUIVEXTPROC glGetUniformuivEXT;
extern PFNGLBINDFRAGDATALOCATIONEXTPROC glBindFragDataLocationEXT;
extern PFNGLGETFRAGDATALOCATIONEXTPROC glGetFragDataLocationEXT;
extern PFNGLUNIFORM1UIEXTPROC glUniform1uiEXT;
extern PFNGLUNIFORM2UIEXTPROC glUniform2uiEXT;
extern PFNGLUNIFORM3UIEXTPROC glUniform3uiEXT;
extern PFNGLUNIFORM4UIEXTPROC glUniform4uiEXT;
extern PFNGLUNIFORM1UIVEXTPROC glUniform1uivEXT;
extern PFNGLUNIFORM2UIVEXTPROC glUniform2uivEXT;
extern PFNGLUNIFORM3UIVEXTPROC glUniform3uivEXT;
extern PFNGLUNIFORM4UIVEXTPROC glUniform4uivEXT;
#endif /*GL_EXT_gpu_shader4*/

/******************************
* Extension: GL_EXT_histogram
******************************/

#define GL_HISTOGRAM_EXT 0x8024
#define GL_PROXY_HISTOGRAM_EXT 0x8025
#define GL_HISTOGRAM_WIDTH_EXT 0x8026
#define GL_HISTOGRAM_FORMAT_EXT 0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT 0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT 0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT 0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT 0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT 0x802C
#define GL_HISTOGRAM_SINK_EXT 0x802D
#define GL_MINMAX_EXT 0x802E
#define GL_MINMAX_FORMAT_EXT 0x802F
#define GL_MINMAX_SINK_EXT 0x8030
#define GL_TABLE_TOO_LARGE_EXT 0x8031


#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1

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

extern PFNGLGETHISTOGRAMEXTPROC glGetHistogramEXT;
extern PFNGLGETHISTOGRAMPARAMETERFVEXTPROC glGetHistogramParameterfvEXT;
extern PFNGLGETHISTOGRAMPARAMETERIVEXTPROC glGetHistogramParameterivEXT;
extern PFNGLGETMINMAXEXTPROC glGetMinmaxEXT;
extern PFNGLGETMINMAXPARAMETERFVEXTPROC glGetMinmaxParameterfvEXT;
extern PFNGLGETMINMAXPARAMETERIVEXTPROC glGetMinmaxParameterivEXT;
extern PFNGLHISTOGRAMEXTPROC glHistogramEXT;
extern PFNGLMINMAXEXTPROC glMinmaxEXT;
extern PFNGLRESETHISTOGRAMEXTPROC glResetHistogramEXT;
extern PFNGLRESETMINMAXEXTPROC glResetMinmaxEXT;
#endif /*GL_EXT_histogram*/

/******************************
* Extension: GL_EXT_index_array_formats
******************************/

#define GL_IUI_V2F_EXT 0x81AD
#define GL_IUI_V3F_EXT 0x81AE
#define GL_IUI_N3F_V2F_EXT 0x81AF
#define GL_IUI_N3F_V3F_EXT 0x81B0
#define GL_T2F_IUI_V2F_EXT 0x81B1
#define GL_T2F_IUI_V3F_EXT 0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT 0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT 0x81B4


/******************************
* Extension: GL_EXT_index_func
******************************/

#define GL_INDEX_TEST_EXT 0x81B5
#define GL_INDEX_TEST_FUNC_EXT 0x81B6
#define GL_INDEX_TEST_REF_EXT 0x81B7


#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1

typedef void (GLE_FUNCPTR * PFNGLINDEXFUNCEXTPROC)(GLenum , GLclampf );

extern PFNGLINDEXFUNCEXTPROC glIndexFuncEXT;
#endif /*GL_EXT_index_func*/

/******************************
* Extension: GL_EXT_index_material
******************************/

#define GL_INDEX_MATERIAL_EXT 0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT 0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT 0x81BA


#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1

typedef void (GLE_FUNCPTR * PFNGLINDEXMATERIALEXTPROC)(GLenum , GLenum );

extern PFNGLINDEXMATERIALEXTPROC glIndexMaterialEXT;
#endif /*GL_EXT_index_material*/

/******************************
* Extension: GL_EXT_index_texture
******************************/

/******************************
* Extension: GL_EXT_light_texture
******************************/

#define GL_FRAGMENT_MATERIAL_EXT 0x8349
#define GL_FRAGMENT_NORMAL_EXT 0x834A
#define GL_FRAGMENT_COLOR_EXT 0x834C
#define GL_ATTENUATION_EXT 0x834D
#define GL_SHADOW_ATTENUATION_EXT 0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT 0x834F
#define GL_TEXTURE_LIGHT_EXT 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT 0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT 0x8352
#define GL_FRAGMENT_DEPTH_EXT 0x8452


#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1

typedef void (GLE_FUNCPTR * PFNGLAPPLYTEXTUREEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXTURELIGHTEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREMATERIALEXTPROC)(GLenum , GLenum );

extern PFNGLAPPLYTEXTUREEXTPROC glApplyTextureEXT;
extern PFNGLTEXTURELIGHTEXTPROC glTextureLightEXT;
extern PFNGLTEXTUREMATERIALEXTPROC glTextureMaterialEXT;
#endif /*GL_EXT_light_texture*/

/******************************
* Extension: GL_EXT_misc_attribute
******************************/

/******************************
* Extension: GL_EXT_multi_draw_arrays
******************************/

#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1

typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSEXTPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSEXTPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* *, GLsizei );

extern PFNGLMULTIDRAWARRAYSEXTPROC glMultiDrawArraysEXT;
extern PFNGLMULTIDRAWELEMENTSEXTPROC glMultiDrawElementsEXT;
#endif /*GL_EXT_multi_draw_arrays*/

/******************************
* Extension: GL_EXT_multisample
******************************/

#define GL_MULTISAMPLE_EXT 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT 0x809F
#define GL_SAMPLE_MASK_EXT 0x80A0
#define GL_1PASS_EXT 0x80A1
#define GL_2PASS_0_EXT 0x80A2
#define GL_2PASS_1_EXT 0x80A3
#define GL_4PASS_0_EXT 0x80A4
#define GL_4PASS_1_EXT 0x80A5
#define GL_4PASS_2_EXT 0x80A6
#define GL_4PASS_3_EXT 0x80A7
#define GL_SAMPLE_BUFFERS_EXT 0x80A8
#define GL_SAMPLES_EXT 0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT 0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT 0x80AB
#define GL_SAMPLE_PATTERN_EXT 0x80AC
#define GL_MULTISAMPLE_BIT_EXT 0x20000000


#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1

typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKEXTPROC)(GLclampf , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLSAMPLEPATTERNEXTPROC)(GLenum );

extern PFNGLSAMPLEMASKEXTPROC glSampleMaskEXT;
extern PFNGLSAMPLEPATTERNEXTPROC glSamplePatternEXT;
#endif /*GL_EXT_multisample*/

/******************************
* Extension: GL_EXT_packed_depth_stencil
******************************/

#define GL_DEPTH_STENCIL_EXT 0x84F9
#define GL_UNSIGNED_INT_24_8_EXT 0x84FA
#define GL_DEPTH24_STENCIL8_EXT 0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT 0x88F1


/******************************
* Extension: GL_EXT_packed_float
******************************/

#define GL_R11F_G11F_B10F_EXT 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT 0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT 0x8C3C


/******************************
* Extension: GL_EXT_packed_pixels
******************************/

#define GL_UNSIGNED_BYTE_3_3_2_EXT 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT 0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT 0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT 0x8036


/******************************
* Extension: GL_EXT_paletted_texture
******************************/

#define GL_COLOR_INDEX1_EXT 0x80E2
#define GL_COLOR_INDEX2_EXT 0x80E3
#define GL_COLOR_INDEX4_EXT 0x80E4
#define GL_COLOR_INDEX8_EXT 0x80E5
#define GL_COLOR_INDEX12_EXT 0x80E6
#define GL_COLOR_INDEX16_EXT 0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT 0x80ED


#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1

typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEEXTPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEEXTPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);

extern PFNGLCOLORTABLEEXTPROC glColorTableEXT;
extern PFNGLGETCOLORTABLEEXTPROC glGetColorTableEXT;
extern PFNGLGETCOLORTABLEPARAMETERIVEXTPROC glGetColorTableParameterivEXT;
extern PFNGLGETCOLORTABLEPARAMETERFVEXTPROC glGetColorTableParameterfvEXT;
#endif /*GL_EXT_paletted_texture*/

/******************************
* Extension: GL_EXT_pixel_buffer_object
******************************/

#define GL_PIXEL_PACK_BUFFER_EXT 0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT 0x88EF


/******************************
* Extension: GL_EXT_pixel_transform
******************************/

#define GL_PIXEL_TRANSFORM_2D_EXT 0x8330
#define GL_PIXEL_MAG_FILTER_EXT 0x8331
#define GL_PIXEL_MIN_FILTER_EXT 0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT 0x8333
#define GL_CUBIC_EXT 0x8334
#define GL_AVERAGE_EXT 0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT 0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT 0x8338


#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1

typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)(GLenum , GLenum , GLfloat *);

extern PFNGLPIXELTRANSFORMPARAMETERIEXTPROC glPixelTransformParameteriEXT;
extern PFNGLPIXELTRANSFORMPARAMETERFEXTPROC glPixelTransformParameterfEXT;
extern PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC glPixelTransformParameterivEXT;
extern PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC glPixelTransformParameterfvEXT;
extern PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC glGetPixelTransformParameterivEXT;
extern PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC glGetPixelTransformParameterfvEXT;
#endif /*GL_EXT_pixel_transform*/

/******************************
* Extension: GL_EXT_pixel_transform_color_table
******************************/

/******************************
* Extension: GL_EXT_point_parameters
******************************/

#define GL_POINT_SIZE_MIN_EXT 0x8126
#define GL_POINT_SIZE_MAX_EXT 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT 0x8128
#define GL_DISTANCE_ATTENUATION_EXT 0x8129


#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1

typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFEXTPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVEXTPROC)(GLenum , const GLfloat *);

extern PFNGLPOINTPARAMETERFEXTPROC glPointParameterfEXT;
extern PFNGLPOINTPARAMETERFVEXTPROC glPointParameterfvEXT;
#endif /*GL_EXT_point_parameters*/

/******************************
* Extension: GL_EXT_polygon_offset
******************************/

#define GL_POLYGON_OFFSET_EXT 0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT 0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT 0x8039


#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1

typedef void (GLE_FUNCPTR * PFNGLPOLYGONOFFSETEXTPROC)(GLfloat , GLfloat );

extern PFNGLPOLYGONOFFSETEXTPROC glPolygonOffsetEXT;
#endif /*GL_EXT_polygon_offset*/

/******************************
* Extension: GL_EXT_provoking_vertex
******************************/

#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT 0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT 0x8E4E
#define GL_PROVOKING_VERTEX_EXT 0x8E4F


#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1

typedef void (GLE_FUNCPTR * PFNGLPROVOKINGVERTEXEXTPROC)(GLenum );

extern PFNGLPROVOKINGVERTEXEXTPROC glProvokingVertexEXT;
#endif /*GL_EXT_provoking_vertex*/

/******************************
* Extension: GL_EXT_rescale_normal
******************************/

#define GL_RESCALE_NORMAL_EXT 0x803A


/******************************
* Extension: GL_EXT_secondary_color
******************************/

#define GL_COLOR_SUM_EXT 0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT 0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT 0x845E


#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1

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

extern PFNGLSECONDARYCOLOR3BEXTPROC glSecondaryColor3bEXT;
extern PFNGLSECONDARYCOLOR3BVEXTPROC glSecondaryColor3bvEXT;
extern PFNGLSECONDARYCOLOR3DEXTPROC glSecondaryColor3dEXT;
extern PFNGLSECONDARYCOLOR3DVEXTPROC glSecondaryColor3dvEXT;
extern PFNGLSECONDARYCOLOR3FEXTPROC glSecondaryColor3fEXT;
extern PFNGLSECONDARYCOLOR3FVEXTPROC glSecondaryColor3fvEXT;
extern PFNGLSECONDARYCOLOR3IEXTPROC glSecondaryColor3iEXT;
extern PFNGLSECONDARYCOLOR3IVEXTPROC glSecondaryColor3ivEXT;
extern PFNGLSECONDARYCOLOR3SEXTPROC glSecondaryColor3sEXT;
extern PFNGLSECONDARYCOLOR3SVEXTPROC glSecondaryColor3svEXT;
extern PFNGLSECONDARYCOLOR3UBEXTPROC glSecondaryColor3ubEXT;
extern PFNGLSECONDARYCOLOR3UBVEXTPROC glSecondaryColor3ubvEXT;
extern PFNGLSECONDARYCOLOR3UIEXTPROC glSecondaryColor3uiEXT;
extern PFNGLSECONDARYCOLOR3UIVEXTPROC glSecondaryColor3uivEXT;
extern PFNGLSECONDARYCOLOR3USEXTPROC glSecondaryColor3usEXT;
extern PFNGLSECONDARYCOLOR3USVEXTPROC glSecondaryColor3usvEXT;
extern PFNGLSECONDARYCOLORPOINTEREXTPROC glSecondaryColorPointerEXT;
#endif /*GL_EXT_secondary_color*/

/******************************
* Extension: GL_EXT_separate_shader_objects
******************************/

#define GL_ACTIVE_PROGRAM_EXT 0x8B8D


#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1

typedef void (GLE_FUNCPTR * PFNGLUSESHADERPROGRAMEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLACTIVEPROGRAMEXTPROC)(GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum , const GLchar *);

extern PFNGLUSESHADERPROGRAMEXTPROC glUseShaderProgramEXT;
extern PFNGLACTIVEPROGRAMEXTPROC glActiveProgramEXT;
extern PFNGLCREATESHADERPROGRAMEXTPROC glCreateShaderProgramEXT;
#endif /*GL_EXT_separate_shader_objects*/

/******************************
* Extension: GL_EXT_separate_specular_color
******************************/

#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SINGLE_COLOR_EXT 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT 0x81FA


/******************************
* Extension: GL_EXT_shader_image_load_store
******************************/

#define GL_MAX_IMAGE_UNITS_EXT 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT 0x8F39
#define GL_IMAGE_BINDING_NAME_EXT 0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT 0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT 0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT 0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT 0x8F3E
#define GL_IMAGE_1D_EXT 0x904C
#define GL_IMAGE_2D_EXT 0x904D
#define GL_IMAGE_3D_EXT 0x904E
#define GL_IMAGE_2D_RECT_EXT 0x904F
#define GL_IMAGE_CUBE_EXT 0x9050
#define GL_IMAGE_BUFFER_EXT 0x9051
#define GL_IMAGE_1D_ARRAY_EXT 0x9052
#define GL_IMAGE_2D_ARRAY_EXT 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT 0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9056
#define GL_INT_IMAGE_1D_EXT 0x9057
#define GL_INT_IMAGE_2D_EXT 0x9058
#define GL_INT_IMAGE_3D_EXT 0x9059
#define GL_INT_IMAGE_2D_RECT_EXT 0x905A
#define GL_INT_IMAGE_CUBE_EXT 0x905B
#define GL_INT_IMAGE_BUFFER_EXT 0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT 0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT 0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT 0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT 0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT 0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT 0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT 0x00001000
#define GL_ALL_BARRIER_BITS_EXT 0xFFFFFFFF


#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1

typedef void (GLE_FUNCPTR * PFNGLBINDIMAGETEXTUREEXTPROC)(GLuint , GLuint , GLint , GLboolean , GLint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMEMORYBARRIEREXTPROC)(GLbitfield );

extern PFNGLBINDIMAGETEXTUREEXTPROC glBindImageTextureEXT;
extern PFNGLMEMORYBARRIEREXTPROC glMemoryBarrierEXT;
#endif /*GL_EXT_shader_image_load_store*/

/******************************
* Extension: GL_EXT_shadow_funcs
******************************/

/******************************
* Extension: GL_EXT_shared_texture_palette
******************************/

#define GL_SHARED_TEXTURE_PALETTE_EXT 0x81FB


/******************************
* Extension: GL_EXT_stencil_clear_tag
******************************/

#define GL_STENCIL_TAG_BITS_EXT 0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT 0x88F3


#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1

typedef void (GLE_FUNCPTR * PFNGLSTENCILCLEARTAGEXTPROC)(GLsizei , GLuint );

extern PFNGLSTENCILCLEARTAGEXTPROC glStencilClearTagEXT;
#endif /*GL_EXT_stencil_clear_tag*/

/******************************
* Extension: GL_EXT_stencil_two_side
******************************/

#define GL_STENCIL_TEST_TWO_SIDE_EXT 0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT 0x8911


#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1

typedef void (GLE_FUNCPTR * PFNGLACTIVESTENCILFACEEXTPROC)(GLenum );

extern PFNGLACTIVESTENCILFACEEXTPROC glActiveStencilFaceEXT;
#endif /*GL_EXT_stencil_two_side*/

/******************************
* Extension: GL_EXT_stencil_wrap
******************************/

#define GL_INCR_WRAP_EXT 0x8507
#define GL_DECR_WRAP_EXT 0x8508


/******************************
* Extension: GL_EXT_subtexture
******************************/

#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1

typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE1DEXTPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE2DEXTPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

extern PFNGLTEXSUBIMAGE1DEXTPROC glTexSubImage1DEXT;
extern PFNGLTEXSUBIMAGE2DEXTPROC glTexSubImage2DEXT;
#endif /*GL_EXT_subtexture*/

/******************************
* Extension: GL_EXT_texture
******************************/

#define GL_ALPHA4_EXT 0x803B
#define GL_ALPHA8_EXT 0x803C
#define GL_ALPHA12_EXT 0x803D
#define GL_ALPHA16_EXT 0x803E
#define GL_LUMINANCE4_EXT 0x803F
#define GL_LUMINANCE8_EXT 0x8040
#define GL_LUMINANCE12_EXT 0x8041
#define GL_LUMINANCE16_EXT 0x8042
#define GL_LUMINANCE4_ALPHA4_EXT 0x8043
#define GL_LUMINANCE6_ALPHA2_EXT 0x8044
#define GL_LUMINANCE8_ALPHA8_EXT 0x8045
#define GL_LUMINANCE12_ALPHA4_EXT 0x8046
#define GL_LUMINANCE12_ALPHA12_EXT 0x8047
#define GL_LUMINANCE16_ALPHA16_EXT 0x8048
#define GL_INTENSITY_EXT 0x8049
#define GL_INTENSITY4_EXT 0x804A
#define GL_INTENSITY8_EXT 0x804B
#define GL_INTENSITY12_EXT 0x804C
#define GL_INTENSITY16_EXT 0x804D
#define GL_RGB2_EXT 0x804E
#define GL_RGB4_EXT 0x804F
#define GL_RGB5_EXT 0x8050
#define GL_RGB8_EXT 0x8051
#define GL_RGB10_EXT 0x8052
#define GL_RGB12_EXT 0x8053
#define GL_RGB16_EXT 0x8054
#define GL_RGBA2_EXT 0x8055
#define GL_RGBA4_EXT 0x8056
#define GL_RGB5_A1_EXT 0x8057
#define GL_RGBA8_EXT 0x8058
#define GL_RGB10_A2_EXT 0x8059
#define GL_RGBA12_EXT 0x805A
#define GL_RGBA16_EXT 0x805B
#define GL_TEXTURE_RED_SIZE_EXT 0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT 0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT 0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT 0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT 0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT 0x8061
#define GL_REPLACE_EXT 0x8062
#define GL_PROXY_TEXTURE_1D_EXT 0x8063
#define GL_PROXY_TEXTURE_2D_EXT 0x8064
#define GL_TEXTURE_TOO_LARGE_EXT 0x8065


/******************************
* Extension: GL_EXT_texture3D
******************************/

#define GL_PACK_SKIP_IMAGES_EXT 0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT 0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT 0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT 0x806E
#define GL_TEXTURE_3D_EXT 0x806F
#define GL_PROXY_TEXTURE_3D_EXT 0x8070
#define GL_TEXTURE_DEPTH_EXT 0x8071
#define GL_TEXTURE_WRAP_R_EXT 0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT 0x8073


#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1

typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DEXTPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE3DEXTPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

extern PFNGLTEXIMAGE3DEXTPROC glTexImage3DEXT;
extern PFNGLTEXSUBIMAGE3DEXTPROC glTexSubImage3DEXT;
#endif /*GL_EXT_texture3D*/

/******************************
* Extension: GL_EXT_texture_array
******************************/

#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_TEXTURE_1D_ARRAY_EXT 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT 0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT 0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT 0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT 0x884E


/******************************
* Extension: GL_EXT_texture_buffer_object
******************************/

#define GL_TEXTURE_BUFFER_EXT 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT 0x8C2E


#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLTEXBUFFEREXTPROC)(GLenum , GLenum , GLuint );

extern PFNGLTEXBUFFEREXTPROC glTexBufferEXT;
#endif /*GL_EXT_texture_buffer_object*/

/******************************
* Extension: GL_EXT_texture_compression_latc
******************************/

#define GL_COMPRESSED_LUMINANCE_LATC1_EXT 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT 0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT 0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT 0x8C73


/******************************
* Extension: GL_EXT_texture_compression_rgtc
******************************/

#define GL_COMPRESSED_RED_RGTC1_EXT 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT 0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT 0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT 0x8DBE


/******************************
* Extension: GL_EXT_texture_compression_s3tc
******************************/

#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3


/******************************
* Extension: GL_EXT_texture_cube_map
******************************/

#define GL_NORMAL_MAP_EXT 0x8511
#define GL_REFLECTION_MAP_EXT 0x8512
#define GL_TEXTURE_CUBE_MAP_EXT 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT 0x851C


/******************************
* Extension: GL_EXT_texture_env_add
******************************/

/******************************
* Extension: GL_EXT_texture_env_combine
******************************/

#define GL_COMBINE_EXT 0x8570
#define GL_COMBINE_RGB_EXT 0x8571
#define GL_COMBINE_ALPHA_EXT 0x8572
#define GL_RGB_SCALE_EXT 0x8573
#define GL_ADD_SIGNED_EXT 0x8574
#define GL_INTERPOLATE_EXT 0x8575
#define GL_CONSTANT_EXT 0x8576
#define GL_PRIMARY_COLOR_EXT 0x8577
#define GL_PREVIOUS_EXT 0x8578
#define GL_SOURCE0_RGB_EXT 0x8580
#define GL_SOURCE1_RGB_EXT 0x8581
#define GL_SOURCE2_RGB_EXT 0x8582
#define GL_SOURCE0_ALPHA_EXT 0x8588
#define GL_SOURCE1_ALPHA_EXT 0x8589
#define GL_SOURCE2_ALPHA_EXT 0x858A
#define GL_OPERAND0_RGB_EXT 0x8590
#define GL_OPERAND1_RGB_EXT 0x8591
#define GL_OPERAND2_RGB_EXT 0x8592
#define GL_OPERAND0_ALPHA_EXT 0x8598
#define GL_OPERAND1_ALPHA_EXT 0x8599
#define GL_OPERAND2_ALPHA_EXT 0x859A


/******************************
* Extension: GL_EXT_texture_env_dot3
******************************/

#define GL_DOT3_RGB_EXT 0x8740
#define GL_DOT3_RGBA_EXT 0x8741


/******************************
* Extension: GL_EXT_texture_filter_anisotropic
******************************/

#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF


/******************************
* Extension: GL_EXT_texture_integer
******************************/

#define GL_RGBA32UI_EXT 0x8D70
#define GL_RGB32UI_EXT 0x8D71
#define GL_ALPHA32UI_EXT 0x8D72
#define GL_INTENSITY32UI_EXT 0x8D73
#define GL_LUMINANCE32UI_EXT 0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT 0x8D75
#define GL_RGBA16UI_EXT 0x8D76
#define GL_RGB16UI_EXT 0x8D77
#define GL_ALPHA16UI_EXT 0x8D78
#define GL_INTENSITY16UI_EXT 0x8D79
#define GL_LUMINANCE16UI_EXT 0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT 0x8D7B
#define GL_RGBA8UI_EXT 0x8D7C
#define GL_RGB8UI_EXT 0x8D7D
#define GL_ALPHA8UI_EXT 0x8D7E
#define GL_INTENSITY8UI_EXT 0x8D7F
#define GL_LUMINANCE8UI_EXT 0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT 0x8D81
#define GL_RGBA32I_EXT 0x8D82
#define GL_RGB32I_EXT 0x8D83
#define GL_ALPHA32I_EXT 0x8D84
#define GL_INTENSITY32I_EXT 0x8D85
#define GL_LUMINANCE32I_EXT 0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT 0x8D87
#define GL_RGBA16I_EXT 0x8D88
#define GL_RGB16I_EXT 0x8D89
#define GL_ALPHA16I_EXT 0x8D8A
#define GL_INTENSITY16I_EXT 0x8D8B
#define GL_LUMINANCE16I_EXT 0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT 0x8D8D
#define GL_RGBA8I_EXT 0x8D8E
#define GL_RGB8I_EXT 0x8D8F
#define GL_ALPHA8I_EXT 0x8D90
#define GL_INTENSITY8I_EXT 0x8D91
#define GL_LUMINANCE8I_EXT 0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT 0x8D93
#define GL_RED_INTEGER_EXT 0x8D94
#define GL_GREEN_INTEGER_EXT 0x8D95
#define GL_BLUE_INTEGER_EXT 0x8D96
#define GL_ALPHA_INTEGER_EXT 0x8D97
#define GL_RGB_INTEGER_EXT 0x8D98
#define GL_RGBA_INTEGER_EXT 0x8D99
#define GL_BGR_INTEGER_EXT 0x8D9A
#define GL_BGRA_INTEGER_EXT 0x8D9B
#define GL_LUMINANCE_INTEGER_EXT 0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT 0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT 0x8D9E


#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1

typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIIVEXTPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORIIEXTPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORIUIEXTPROC)(GLuint , GLuint , GLuint , GLuint );

extern PFNGLTEXPARAMETERIIVEXTPROC glTexParameterIivEXT;
extern PFNGLTEXPARAMETERIUIVEXTPROC glTexParameterIuivEXT;
extern PFNGLGETTEXPARAMETERIIVEXTPROC glGetTexParameterIivEXT;
extern PFNGLGETTEXPARAMETERIUIVEXTPROC glGetTexParameterIuivEXT;
extern PFNGLCLEARCOLORIIEXTPROC glClearColorIiEXT;
extern PFNGLCLEARCOLORIUIEXTPROC glClearColorIuiEXT;
#endif /*GL_EXT_texture_integer*/

/******************************
* Extension: GL_EXT_texture_lod_bias
******************************/

#define GL_MAX_TEXTURE_LOD_BIAS_EXT 0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT 0x8500
#define GL_TEXTURE_LOD_BIAS_EXT 0x8501


/******************************
* Extension: GL_EXT_texture_mirror_clamp
******************************/

#define GL_MIRROR_CLAMP_EXT 0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT 0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT 0x8912


/******************************
* Extension: GL_EXT_texture_object
******************************/

#define GL_TEXTURE_PRIORITY_EXT 0x8066
#define GL_TEXTURE_RESIDENT_EXT 0x8067
#define GL_TEXTURE_1D_BINDING_EXT 0x8068
#define GL_TEXTURE_2D_BINDING_EXT 0x8069
#define GL_TEXTURE_3D_BINDING_EXT 0x806A


#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1

typedef GLboolean (GLE_FUNCPTR * PFNGLARETEXTURESRESIDENTEXTPROC)(GLsizei , const GLuint *, GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLBINDTEXTUREEXTPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETEXTURESEXTPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTEXTURESEXTPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTEXTUREEXTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPRIORITIZETEXTURESEXTPROC)(GLsizei , const GLuint *, const GLclampf *);

extern PFNGLARETEXTURESRESIDENTEXTPROC glAreTexturesResidentEXT;
extern PFNGLBINDTEXTUREEXTPROC glBindTextureEXT;
extern PFNGLDELETETEXTURESEXTPROC glDeleteTexturesEXT;
extern PFNGLGENTEXTURESEXTPROC glGenTexturesEXT;
extern PFNGLISTEXTUREEXTPROC glIsTextureEXT;
extern PFNGLPRIORITIZETEXTURESEXTPROC glPrioritizeTexturesEXT;
#endif /*GL_EXT_texture_object*/

/******************************
* Extension: GL_EXT_texture_perturb_normal
******************************/

#define GL_PERTURB_EXT 0x85AE
#define GL_TEXTURE_NORMAL_EXT 0x85AF


#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1

typedef void (GLE_FUNCPTR * PFNGLTEXTURENORMALEXTPROC)(GLenum );

extern PFNGLTEXTURENORMALEXTPROC glTextureNormalEXT;
#endif /*GL_EXT_texture_perturb_normal*/

/******************************
* Extension: GL_EXT_texture_sRGB
******************************/

#define GL_SRGB_EXT 0x8C40
#define GL_SRGB8_EXT 0x8C41
#define GL_SRGB_ALPHA_EXT 0x8C42
#define GL_SRGB8_ALPHA8_EXT 0x8C43
#define GL_SLUMINANCE_ALPHA_EXT 0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT 0x8C45
#define GL_SLUMINANCE_EXT 0x8C46
#define GL_SLUMINANCE8_EXT 0x8C47
#define GL_COMPRESSED_SRGB_EXT 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT 0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT 0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT 0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F


/******************************
* Extension: GL_EXT_texture_sRGB_decode
******************************/

#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
#define GL_DECODE_EXT 0x8A49
#define GL_SKIP_DECODE_EXT 0x8A4A


/******************************
* Extension: GL_EXT_texture_shared_exponent
******************************/

#define GL_RGB9_E5_EXT 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT 0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT 0x8C3F


/******************************
* Extension: GL_EXT_texture_snorm
******************************/

#define GL_RED_SNORM 0x8F90
#define GL_RG_SNORM 0x8F91
#define GL_RGB_SNORM 0x8F92
#define GL_RGBA_SNORM 0x8F93
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_ALPHA_SNORM 0x9010
#define GL_LUMINANCE_SNORM 0x9011
#define GL_LUMINANCE_ALPHA_SNORM 0x9012
#define GL_INTENSITY_SNORM 0x9013
#define GL_ALPHA8_SNORM 0x9014
#define GL_LUMINANCE8_SNORM 0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM 0x9016
#define GL_INTENSITY8_SNORM 0x9017
#define GL_ALPHA16_SNORM 0x9018
#define GL_LUMINANCE16_SNORM 0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM 0x901A
#define GL_INTENSITY16_SNORM 0x901B


/******************************
* Extension: GL_EXT_texture_swizzle
******************************/

#define GL_TEXTURE_SWIZZLE_R_EXT 0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT 0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT 0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT 0x8E46


/******************************
* Extension: GL_EXT_timer_query
******************************/

#define GL_TIME_ELAPSED_EXT 0x88BF


#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1

typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTI64VEXTPROC)(GLuint , GLenum , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUI64VEXTPROC)(GLuint , GLenum , GLuint64EXT *);

extern PFNGLGETQUERYOBJECTI64VEXTPROC glGetQueryObjecti64vEXT;
extern PFNGLGETQUERYOBJECTUI64VEXTPROC glGetQueryObjectui64vEXT;
#endif /*GL_EXT_timer_query*/

/******************************
* Extension: GL_EXT_transform_feedback
******************************/

#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT 0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT 0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT 0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT 0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT 0x8C88
#define GL_RASTERIZER_DISCARD_EXT 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT 0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT 0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT 0x8C76


#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1

typedef void (GLE_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKEXTPROC)();
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERRANGEEXTPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFEROFFSETEXTPROC)(GLenum , GLuint , GLuint , GLintptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERBASEEXTPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)(GLuint , GLsizei , const GLchar* *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);

extern PFNGLBEGINTRANSFORMFEEDBACKEXTPROC glBeginTransformFeedbackEXT;
extern PFNGLENDTRANSFORMFEEDBACKEXTPROC glEndTransformFeedbackEXT;
extern PFNGLBINDBUFFERRANGEEXTPROC glBindBufferRangeEXT;
extern PFNGLBINDBUFFEROFFSETEXTPROC glBindBufferOffsetEXT;
extern PFNGLBINDBUFFERBASEEXTPROC glBindBufferBaseEXT;
extern PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC glTransformFeedbackVaryingsEXT;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC glGetTransformFeedbackVaryingEXT;
#endif /*GL_EXT_transform_feedback*/

/******************************
* Extension: GL_EXT_vertex_array
******************************/

#define GL_VERTEX_ARRAY_EXT 0x8074
#define GL_NORMAL_ARRAY_EXT 0x8075
#define GL_COLOR_ARRAY_EXT 0x8076
#define GL_INDEX_ARRAY_EXT 0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT 0x8078
#define GL_EDGE_FLAG_ARRAY_EXT 0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT 0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT 0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT 0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT 0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT 0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT 0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT 0x8080
#define GL_COLOR_ARRAY_SIZE_EXT 0x8081
#define GL_COLOR_ARRAY_TYPE_EXT 0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT 0x8083
#define GL_COLOR_ARRAY_COUNT_EXT 0x8084
#define GL_INDEX_ARRAY_TYPE_EXT 0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT 0x8086
#define GL_INDEX_ARRAY_COUNT_EXT 0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT 0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT 0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT 0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT 0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT 0x808F
#define GL_COLOR_ARRAY_POINTER_EXT 0x8090
#define GL_INDEX_ARRAY_POINTER_EXT 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT 0x8093


#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1

typedef void (GLE_FUNCPTR * PFNGLARRAYELEMENTEXTPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSEXTPROC)(GLenum , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTEREXTPROC)(GLsizei , GLsizei , const GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERVEXTPROC)(GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTEREXTPROC)(GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTEREXTPROC)(GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTEREXTPROC)(GLint , GLenum , GLsizei , GLsizei , const GLvoid *);

extern PFNGLARRAYELEMENTEXTPROC glArrayElementEXT;
extern PFNGLCOLORPOINTEREXTPROC glColorPointerEXT;
extern PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT;
extern PFNGLEDGEFLAGPOINTEREXTPROC glEdgeFlagPointerEXT;
extern PFNGLGETPOINTERVEXTPROC glGetPointervEXT;
extern PFNGLINDEXPOINTEREXTPROC glIndexPointerEXT;
extern PFNGLNORMALPOINTEREXTPROC glNormalPointerEXT;
extern PFNGLTEXCOORDPOINTEREXTPROC glTexCoordPointerEXT;
extern PFNGLVERTEXPOINTEREXTPROC glVertexPointerEXT;
#endif /*GL_EXT_vertex_array*/

/******************************
* Extension: GL_EXT_vertex_array_bgra
******************************/

#define GL_BGRA 0x80E1


/******************************
* Extension: GL_EXT_vertex_attrib_64bit
******************************/

#define GL_DOUBLE 0x140A
#define GL_DOUBLE_VEC2_EXT 0x8FFC
#define GL_DOUBLE_VEC3_EXT 0x8FFD
#define GL_DOUBLE_VEC4_EXT 0x8FFE
#define GL_DOUBLE_MAT2_EXT 0x8F46
#define GL_DOUBLE_MAT3_EXT 0x8F47
#define GL_DOUBLE_MAT4_EXT 0x8F48
#define GL_DOUBLE_MAT2x3_EXT 0x8F49
#define GL_DOUBLE_MAT2x4_EXT 0x8F4A
#define GL_DOUBLE_MAT3x2_EXT 0x8F4B
#define GL_DOUBLE_MAT3x4_EXT 0x8F4C
#define GL_DOUBLE_MAT4x2_EXT 0x8F4D
#define GL_DOUBLE_MAT4x3_EXT 0x8F4E


#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1

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

extern PFNGLVERTEXATTRIBL1DEXTPROC glVertexAttribL1dEXT;
extern PFNGLVERTEXATTRIBL2DEXTPROC glVertexAttribL2dEXT;
extern PFNGLVERTEXATTRIBL3DEXTPROC glVertexAttribL3dEXT;
extern PFNGLVERTEXATTRIBL4DEXTPROC glVertexAttribL4dEXT;
extern PFNGLVERTEXATTRIBL1DVEXTPROC glVertexAttribL1dvEXT;
extern PFNGLVERTEXATTRIBL2DVEXTPROC glVertexAttribL2dvEXT;
extern PFNGLVERTEXATTRIBL3DVEXTPROC glVertexAttribL3dvEXT;
extern PFNGLVERTEXATTRIBL4DVEXTPROC glVertexAttribL4dvEXT;
extern PFNGLVERTEXATTRIBLPOINTEREXTPROC glVertexAttribLPointerEXT;
extern PFNGLGETVERTEXATTRIBLDVEXTPROC glGetVertexAttribLdvEXT;
extern PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC glVertexArrayVertexAttribLOffsetEXT;
#endif /*GL_EXT_vertex_attrib_64bit*/

/******************************
* Extension: GL_EXT_vertex_shader
******************************/

#define GL_VERTEX_SHADER_EXT 0x8780
#define GL_VERTEX_SHADER_BINDING_EXT 0x8781
#define GL_OP_INDEX_EXT 0x8782
#define GL_OP_NEGATE_EXT 0x8783
#define GL_OP_DOT3_EXT 0x8784
#define GL_OP_DOT4_EXT 0x8785
#define GL_OP_MUL_EXT 0x8786
#define GL_OP_ADD_EXT 0x8787
#define GL_OP_MADD_EXT 0x8788
#define GL_OP_FRAC_EXT 0x8789
#define GL_OP_MAX_EXT 0x878A
#define GL_OP_MIN_EXT 0x878B
#define GL_OP_SET_GE_EXT 0x878C
#define GL_OP_SET_LT_EXT 0x878D
#define GL_OP_CLAMP_EXT 0x878E
#define GL_OP_FLOOR_EXT 0x878F
#define GL_OP_ROUND_EXT 0x8790
#define GL_OP_EXP_BASE_2_EXT 0x8791
#define GL_OP_LOG_BASE_2_EXT 0x8792
#define GL_OP_POWER_EXT 0x8793
#define GL_OP_RECIP_EXT 0x8794
#define GL_OP_RECIP_SQRT_EXT 0x8795
#define GL_OP_SUB_EXT 0x8796
#define GL_OP_CROSS_PRODUCT_EXT 0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT 0x8798
#define GL_OP_MOV_EXT 0x8799
#define GL_OUTPUT_VERTEX_EXT 0x879A
#define GL_OUTPUT_COLOR0_EXT 0x879B
#define GL_OUTPUT_COLOR1_EXT 0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT 0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT 0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT 0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT 0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT 0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT 0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT 0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT 0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT 0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT 0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT 0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT 0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT 0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT 0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT 0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT 0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT 0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT 0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT 0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT 0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT 0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT 0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT 0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT 0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT 0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT 0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT 0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT 0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT 0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT 0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT 0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT 0x87BC
#define GL_OUTPUT_FOG_EXT 0x87BD
#define GL_SCALAR_EXT 0x87BE
#define GL_VECTOR_EXT 0x87BF
#define GL_MATRIX_EXT 0x87C0
#define GL_VARIANT_EXT 0x87C1
#define GL_INVARIANT_EXT 0x87C2
#define GL_LOCAL_CONSTANT_EXT 0x87C3
#define GL_LOCAL_EXT 0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT 0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT 0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT 0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT 0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT 0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT 0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT 0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT 0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT 0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT 0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT 0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT 0x87D4
#define GL_X_EXT 0x87D5
#define GL_Y_EXT 0x87D6
#define GL_Z_EXT 0x87D7
#define GL_W_EXT 0x87D8
#define GL_NEGATIVE_X_EXT 0x87D9
#define GL_NEGATIVE_Y_EXT 0x87DA
#define GL_NEGATIVE_Z_EXT 0x87DB
#define GL_NEGATIVE_W_EXT 0x87DC
#define GL_ZERO_EXT 0x87DD
#define GL_ONE_EXT 0x87DE
#define GL_NEGATIVE_ONE_EXT 0x87DF
#define GL_NORMALIZED_RANGE_EXT 0x87E0
#define GL_FULL_RANGE_EXT 0x87E1
#define GL_CURRENT_VERTEX_EXT 0x87E2
#define GL_MVP_MATRIX_EXT 0x87E3
#define GL_VARIANT_VALUE_EXT 0x87E4
#define GL_VARIANT_DATATYPE_EXT 0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT 0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT 0x87E7
#define GL_VARIANT_ARRAY_EXT 0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT 0x87E9
#define GL_INVARIANT_VALUE_EXT 0x87EA
#define GL_INVARIANT_DATATYPE_EXT 0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT 0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT 0x87ED


#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1

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

extern PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT;
extern PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT;
extern PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT;
extern PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT;
extern PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT;
extern PFNGLSHADEROP1EXTPROC glShaderOp1EXT;
extern PFNGLSHADEROP2EXTPROC glShaderOp2EXT;
extern PFNGLSHADEROP3EXTPROC glShaderOp3EXT;
extern PFNGLSWIZZLEEXTPROC glSwizzleEXT;
extern PFNGLWRITEMASKEXTPROC glWriteMaskEXT;
extern PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT;
extern PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT;
extern PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT;
extern PFNGLSETINVARIANTEXTPROC glSetInvariantEXT;
extern PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT;
extern PFNGLVARIANTBVEXTPROC glVariantbvEXT;
extern PFNGLVARIANTSVEXTPROC glVariantsvEXT;
extern PFNGLVARIANTIVEXTPROC glVariantivEXT;
extern PFNGLVARIANTFVEXTPROC glVariantfvEXT;
extern PFNGLVARIANTDVEXTPROC glVariantdvEXT;
extern PFNGLVARIANTUBVEXTPROC glVariantubvEXT;
extern PFNGLVARIANTUSVEXTPROC glVariantusvEXT;
extern PFNGLVARIANTUIVEXTPROC glVariantuivEXT;
extern PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT;
extern PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT;
extern PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT;
extern PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT;
extern PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT;
extern PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT;
extern PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT;
extern PFNGLBINDPARAMETEREXTPROC glBindParameterEXT;
extern PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT;
extern PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT;
extern PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT;
extern PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT;
extern PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT;
extern PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT;
extern PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT;
extern PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT;
extern PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT;
extern PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT;
extern PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT;
#endif /*GL_EXT_vertex_shader*/

/******************************
* Extension: GL_EXT_vertex_weighting
******************************/

#define GL_MODELVIEW0_STACK_DEPTH_EXT 0x0BA3 /* GL_MODELVIEW_STACK_DEPTH */
#define GL_MODELVIEW1_STACK_DEPTH_EXT 0x8502
#define GL_MODELVIEW0_MATRIX_EXT 0x0BA6 /* GL_MODELVIEW_MATRIX */
#define GL_MODELVIEW1_MATRIX_EXT 0x8506
#define GL_VERTEX_WEIGHTING_EXT 0x8509
#define GL_MODELVIEW0_EXT 0x1700 /* GL_MODELVIEW */
#define GL_MODELVIEW1_EXT 0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT 0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT 0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT 0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT 0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT 0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT 0x8510


#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1

typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTFEXTPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTFVEXTPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXWEIGHTPOINTEREXTPROC)(GLint , GLenum , GLsizei , const GLvoid *);

extern PFNGLVERTEXWEIGHTFEXTPROC glVertexWeightfEXT;
extern PFNGLVERTEXWEIGHTFVEXTPROC glVertexWeightfvEXT;
extern PFNGLVERTEXWEIGHTPOINTEREXTPROC glVertexWeightPointerEXT;
#endif /*GL_EXT_vertex_weighting*/

/******************************
* Extension: GL_EXT_x11_sync_object
******************************/

#define GL_SYNC_X11_FENCE_EXT 0x90E1


#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object 1

typedef GLsync (GLE_FUNCPTR * PFNGLIMPORTSYNCEXTPROC)(GLenum , GLintptr , GLbitfield );

extern PFNGLIMPORTSYNCEXTPROC glImportSyncEXT;
#endif /*GL_EXT_x11_sync_object*/

/******************************
* Extension: GL_FfdMaskSGIX
******************************/

#define GL_TEXTURE_DEFORMATION_BIT_SGIX 0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX 0x00000002


/******************************
* Extension: GL_GREMEDY_frame_terminator
******************************/

#ifndef GL_GREMEDY_frame_terminator
#define GL_GREMEDY_frame_terminator 1

typedef void (GLE_FUNCPTR * PFNGLFRAMETERMINATORGREMEDYPROC)();

extern PFNGLFRAMETERMINATORGREMEDYPROC glFrameTerminatorGREMEDY;
#endif /*GL_GREMEDY_frame_terminator*/

/******************************
* Extension: GL_GREMEDY_string_marker
******************************/

#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1

typedef void (GLE_FUNCPTR * PFNGLSTRINGMARKERGREMEDYPROC)(GLsizei , const GLvoid *);

extern PFNGLSTRINGMARKERGREMEDYPROC glStringMarkerGREMEDY;
#endif /*GL_GREMEDY_string_marker*/

/******************************
* Extension: GL_HP_convolution_border_modes
******************************/

#define GL_IGNORE_BORDER_HP 0x8150
#define GL_CONSTANT_BORDER_HP 0x8151
#define GL_REPLICATE_BORDER_HP 0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP 0x8154


/******************************
* Extension: GL_HP_image_transform
******************************/

#define GL_IMAGE_SCALE_X_HP 0x8155
#define GL_IMAGE_SCALE_Y_HP 0x8156
#define GL_IMAGE_TRANSLATE_X_HP 0x8157
#define GL_IMAGE_TRANSLATE_Y_HP 0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP 0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP 0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP 0x815B
#define GL_IMAGE_MAG_FILTER_HP 0x815C
#define GL_IMAGE_MIN_FILTER_HP 0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP 0x815E
#define GL_CUBIC_HP 0x815F
#define GL_AVERAGE_HP 0x8160
#define GL_IMAGE_TRANSFORM_2D_HP 0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP 0x8163


#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1

typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERIHPPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERFHPPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)(GLenum , GLenum , GLfloat *);

extern PFNGLIMAGETRANSFORMPARAMETERIHPPROC glImageTransformParameteriHP;
extern PFNGLIMAGETRANSFORMPARAMETERFHPPROC glImageTransformParameterfHP;
extern PFNGLIMAGETRANSFORMPARAMETERIVHPPROC glImageTransformParameterivHP;
extern PFNGLIMAGETRANSFORMPARAMETERFVHPPROC glImageTransformParameterfvHP;
extern PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC glGetImageTransformParameterivHP;
extern PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC glGetImageTransformParameterfvHP;
#endif /*GL_HP_image_transform*/

/******************************
* Extension: GL_HP_occlusion_test
******************************/

#define GL_OCCLUSION_TEST_HP 0x8165
#define GL_OCCLUSION_TEST_RESULT_HP 0x8166


/******************************
* Extension: GL_HP_texture_lighting
******************************/

#define GL_TEXTURE_LIGHTING_MODE_HP 0x8167
#define GL_TEXTURE_POST_SPECULAR_HP 0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP 0x8169


/******************************
* Extension: GL_IBM_cull_vertex
******************************/

#define GL_CULL_VERTEX_IBM 103050


/******************************
* Extension: GL_IBM_multimode_draw_arrays
******************************/

#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1

typedef void (GLE_FUNCPTR * PFNGLMULTIMODEDRAWARRAYSIBMPROC)(const GLenum *, const GLint *, const GLsizei *, GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTIMODEDRAWELEMENTSIBMPROC)(const GLenum *, const GLsizei *, GLenum , const GLvoid* const *, GLsizei , GLint );

extern PFNGLMULTIMODEDRAWARRAYSIBMPROC glMultiModeDrawArraysIBM;
extern PFNGLMULTIMODEDRAWELEMENTSIBMPROC glMultiModeDrawElementsIBM;
#endif /*GL_IBM_multimode_draw_arrays*/

/******************************
* Extension: GL_IBM_rasterpos_clip
******************************/

#define GL_RASTER_POSITION_UNCLIPPED_IBM 0x19262


/******************************
* Extension: GL_IBM_texture_mirrored_repeat
******************************/

#define GL_MIRRORED_REPEAT_IBM 0x8370


/******************************
* Extension: GL_IBM_vertex_array_lists
******************************/

#define GL_VERTEX_ARRAY_LIST_IBM 103070
#define GL_NORMAL_ARRAY_LIST_IBM 103071
#define GL_COLOR_ARRAY_LIST_IBM 103072
#define GL_INDEX_ARRAY_LIST_IBM 103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM 103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM 103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM 103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM 103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM 103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM 103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM 103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM 103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM 103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM 103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM 103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM 103087


#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1

typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTERLISTIBMPROC)(GLint , const GLboolean* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERLISTIBMPROC)(GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERLISTIBMPROC)(GLint , GLenum , GLint , const GLvoid* *, GLint );

extern PFNGLCOLORPOINTERLISTIBMPROC glColorPointerListIBM;
extern PFNGLSECONDARYCOLORPOINTERLISTIBMPROC glSecondaryColorPointerListIBM;
extern PFNGLEDGEFLAGPOINTERLISTIBMPROC glEdgeFlagPointerListIBM;
extern PFNGLFOGCOORDPOINTERLISTIBMPROC glFogCoordPointerListIBM;
extern PFNGLINDEXPOINTERLISTIBMPROC glIndexPointerListIBM;
extern PFNGLNORMALPOINTERLISTIBMPROC glNormalPointerListIBM;
extern PFNGLTEXCOORDPOINTERLISTIBMPROC glTexCoordPointerListIBM;
extern PFNGLVERTEXPOINTERLISTIBMPROC glVertexPointerListIBM;
#endif /*GL_IBM_vertex_array_lists*/

/******************************
* Extension: GL_INGR_color_clamp
******************************/

#define GL_RED_MIN_CLAMP_INGR 0x8560
#define GL_GREEN_MIN_CLAMP_INGR 0x8561
#define GL_BLUE_MIN_CLAMP_INGR 0x8562
#define GL_ALPHA_MIN_CLAMP_INGR 0x8563
#define GL_RED_MAX_CLAMP_INGR 0x8564
#define GL_GREEN_MAX_CLAMP_INGR 0x8565
#define GL_BLUE_MAX_CLAMP_INGR 0x8566
#define GL_ALPHA_MAX_CLAMP_INGR 0x8567


/******************************
* Extension: GL_INGR_interlace_read
******************************/

#define GL_INTERLACE_READ_INGR 0x8568


/******************************
* Extension: GL_INGR_palette_buffer
******************************/

/******************************
* Extension: GL_INTEL_parallel_arrays
******************************/

#define GL_PARALLEL_ARRAYS_INTEL 0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL 0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL 0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL 0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL 0x83F8


#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1

typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERVINTELPROC)(GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERVINTELPROC)(GLint , GLenum , const GLvoid* *);

extern PFNGLVERTEXPOINTERVINTELPROC glVertexPointervINTEL;
extern PFNGLNORMALPOINTERVINTELPROC glNormalPointervINTEL;
extern PFNGLCOLORPOINTERVINTELPROC glColorPointervINTEL;
extern PFNGLTEXCOORDPOINTERVINTELPROC glTexCoordPointervINTEL;
#endif /*GL_INTEL_parallel_arrays*/

/******************************
* Extension: GL_INTEL_texture_scissor
******************************/

/******************************
* Extension: GL_KHR_debug
******************************/

#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_SAMPLER 0x82E6
#define GL_DISPLAY_LIST 0x82E7
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002


#ifndef GL_KHR_debug
#define GL_KHR_debug 1

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

extern PFNGLDEBUGMESSAGECONTROLPROC __gleDebugMessageControl;
#define glDebugMessageControl __gleDebugMessageControl
extern PFNGLDEBUGMESSAGEINSERTPROC __gleDebugMessageInsert;
#define glDebugMessageInsert __gleDebugMessageInsert
extern PFNGLDEBUGMESSAGECALLBACKPROC __gleDebugMessageCallback;
#define glDebugMessageCallback __gleDebugMessageCallback
extern PFNGLGETDEBUGMESSAGELOGPROC __gleGetDebugMessageLog;
#define glGetDebugMessageLog __gleGetDebugMessageLog
extern PFNGLPUSHDEBUGGROUPPROC __glePushDebugGroup;
#define glPushDebugGroup __glePushDebugGroup
extern PFNGLPOPDEBUGGROUPPROC __glePopDebugGroup;
#define glPopDebugGroup __glePopDebugGroup
extern PFNGLOBJECTLABELPROC __gleObjectLabel;
#define glObjectLabel __gleObjectLabel
extern PFNGLGETOBJECTLABELPROC __gleGetObjectLabel;
#define glGetObjectLabel __gleGetObjectLabel
extern PFNGLOBJECTPTRLABELPROC __gleObjectPtrLabel;
#define glObjectPtrLabel __gleObjectPtrLabel
extern PFNGLGETOBJECTPTRLABELPROC __gleGetObjectPtrLabel;
#define glGetObjectPtrLabel __gleGetObjectPtrLabel
#endif /*GL_KHR_debug*/

/******************************
* Extension: GL_KHR_texture_compression_astc_ldr
******************************/

#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR 0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR 0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR 0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR 0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR 0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR 0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR 0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR 0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR 0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR 0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR 0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD


/******************************
* Extension: GL_MESAX_texture_stack
******************************/

#define GL_TEXTURE_1D_STACK_MESAX 0x8759
#define GL_TEXTURE_2D_STACK_MESAX 0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX 0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX 0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX 0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX 0x875E


/******************************
* Extension: GL_MESA_pack_invert
******************************/

#define GL_PACK_INVERT_MESA 0x8758


/******************************
* Extension: GL_MESA_resize_buffers
******************************/

#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1

typedef void (GLE_FUNCPTR * PFNGLRESIZEBUFFERSMESAPROC)();

extern PFNGLRESIZEBUFFERSMESAPROC glResizeBuffersMESA;
#endif /*GL_MESA_resize_buffers*/

/******************************
* Extension: GL_MESA_window_pos
******************************/

#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1

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

extern PFNGLWINDOWPOS2DMESAPROC glWindowPos2dMESA;
extern PFNGLWINDOWPOS2DVMESAPROC glWindowPos2dvMESA;
extern PFNGLWINDOWPOS2FMESAPROC glWindowPos2fMESA;
extern PFNGLWINDOWPOS2FVMESAPROC glWindowPos2fvMESA;
extern PFNGLWINDOWPOS2IMESAPROC glWindowPos2iMESA;
extern PFNGLWINDOWPOS2IVMESAPROC glWindowPos2ivMESA;
extern PFNGLWINDOWPOS2SMESAPROC glWindowPos2sMESA;
extern PFNGLWINDOWPOS2SVMESAPROC glWindowPos2svMESA;
extern PFNGLWINDOWPOS3DMESAPROC glWindowPos3dMESA;
extern PFNGLWINDOWPOS3DVMESAPROC glWindowPos3dvMESA;
extern PFNGLWINDOWPOS3FMESAPROC glWindowPos3fMESA;
extern PFNGLWINDOWPOS3FVMESAPROC glWindowPos3fvMESA;
extern PFNGLWINDOWPOS3IMESAPROC glWindowPos3iMESA;
extern PFNGLWINDOWPOS3IVMESAPROC glWindowPos3ivMESA;
extern PFNGLWINDOWPOS3SMESAPROC glWindowPos3sMESA;
extern PFNGLWINDOWPOS3SVMESAPROC glWindowPos3svMESA;
extern PFNGLWINDOWPOS4DMESAPROC glWindowPos4dMESA;
extern PFNGLWINDOWPOS4DVMESAPROC glWindowPos4dvMESA;
extern PFNGLWINDOWPOS4FMESAPROC glWindowPos4fMESA;
extern PFNGLWINDOWPOS4FVMESAPROC glWindowPos4fvMESA;
extern PFNGLWINDOWPOS4IMESAPROC glWindowPos4iMESA;
extern PFNGLWINDOWPOS4IVMESAPROC glWindowPos4ivMESA;
extern PFNGLWINDOWPOS4SMESAPROC glWindowPos4sMESA;
extern PFNGLWINDOWPOS4SVMESAPROC glWindowPos4svMESA;
#endif /*GL_MESA_window_pos*/

/******************************
* Extension: GL_MESA_ycbcr_texture
******************************/

#define GL_UNSIGNED_SHORT_8_8_MESA 0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA 0x85BB
#define GL_YCBCR_MESA 0x8757


/******************************
* Extension: GL_NV_bindless_texture
******************************/

#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1

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

extern PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV;
extern PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV;
extern PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV;
extern PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV;
extern PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV;
extern PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV;
extern PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV;
extern PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV;
extern PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV;
extern PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV;
extern PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV;
extern PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV;
extern PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV;
#endif /*GL_NV_bindless_texture*/

/******************************
* Extension: GL_NV_blend_square
******************************/

/******************************
* Extension: GL_NV_conditional_render
******************************/

#define GL_QUERY_WAIT_NV 0x8E13
#define GL_QUERY_NO_WAIT_NV 0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV 0x8E16


#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1

typedef void (GLE_FUNCPTR * PFNGLBEGINCONDITIONALRENDERNVPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDCONDITIONALRENDERNVPROC)();

extern PFNGLBEGINCONDITIONALRENDERNVPROC glBeginConditionalRenderNV;
extern PFNGLENDCONDITIONALRENDERNVPROC glEndConditionalRenderNV;
#endif /*GL_NV_conditional_render*/

/******************************
* Extension: GL_NV_copy_depth_to_color
******************************/

#define GL_DEPTH_STENCIL_TO_RGBA_NV 0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV 0x886F


/******************************
* Extension: GL_NV_copy_image
******************************/

#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1

typedef void (GLE_FUNCPTR * PFNGLCOPYIMAGESUBDATANVPROC)(GLuint , GLenum , GLint , GLint , GLint , GLint , GLuint , GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei );

extern PFNGLCOPYIMAGESUBDATANVPROC glCopyImageSubDataNV;
#endif /*GL_NV_copy_image*/

/******************************
* Extension: GL_NV_depth_buffer_float
******************************/

#define GL_DEPTH_COMPONENT32F_NV 0x8DAB
#define GL_DEPTH32F_STENCIL8_NV 0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV 0x8DAF


#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1

typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEDNVPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHDNVPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLDEPTHBOUNDSDNVPROC)(GLdouble , GLdouble );

extern PFNGLDEPTHRANGEDNVPROC glDepthRangedNV;
extern PFNGLCLEARDEPTHDNVPROC glClearDepthdNV;
extern PFNGLDEPTHBOUNDSDNVPROC glDepthBoundsdNV;
#endif /*GL_NV_depth_buffer_float*/

/******************************
* Extension: GL_NV_depth_clamp
******************************/

#define GL_DEPTH_CLAMP_NV 0x864F


/******************************
* Extension: GL_NV_evaluators
******************************/

#define GL_EVAL_2D_NV 0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV 0x86C1
#define GL_MAP_TESSELLATION_NV 0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV 0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV 0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV 0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV 0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV 0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV 0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV 0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV 0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV 0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV 0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV 0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV 0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV 0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV 0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV 0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV 0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV 0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV 0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV 0x86D5
#define GL_MAX_MAP_TESSELLATION_NV 0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV 0x86D7


#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1

typedef void (GLE_FUNCPTR * PFNGLMAPCONTROLPOINTSNVPROC)(GLenum , GLuint , GLenum , GLsizei , GLsizei , GLint , GLint , GLboolean , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLMAPPARAMETERIVNVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMAPPARAMETERFVNVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPCONTROLPOINTSNVPROC)(GLenum , GLuint , GLenum , GLsizei , GLsizei , GLboolean , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPPARAMETERIVNVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPPARAMETERFVNVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPATTRIBPARAMETERIVNVPROC)(GLenum , GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPATTRIBPARAMETERFVNVPROC)(GLenum , GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLEVALMAPSNVPROC)(GLenum , GLenum );

extern PFNGLMAPCONTROLPOINTSNVPROC glMapControlPointsNV;
extern PFNGLMAPPARAMETERIVNVPROC glMapParameterivNV;
extern PFNGLMAPPARAMETERFVNVPROC glMapParameterfvNV;
extern PFNGLGETMAPCONTROLPOINTSNVPROC glGetMapControlPointsNV;
extern PFNGLGETMAPPARAMETERIVNVPROC glGetMapParameterivNV;
extern PFNGLGETMAPPARAMETERFVNVPROC glGetMapParameterfvNV;
extern PFNGLGETMAPATTRIBPARAMETERIVNVPROC glGetMapAttribParameterivNV;
extern PFNGLGETMAPATTRIBPARAMETERFVNVPROC glGetMapAttribParameterfvNV;
extern PFNGLEVALMAPSNVPROC glEvalMapsNV;
#endif /*GL_NV_evaluators*/

/******************************
* Extension: GL_NV_explicit_multisample
******************************/

#define GL_SAMPLE_POSITION_NV 0x8E50
#define GL_SAMPLE_MASK_NV 0x8E51
#define GL_SAMPLE_MASK_VALUE_NV 0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV 0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV 0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV 0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV 0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV 0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV 0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV 0x8E59


#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1

typedef void (GLE_FUNCPTR * PFNGLGETMULTISAMPLEFVNVPROC)(GLenum , GLuint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKINDEXEDNVPROC)(GLuint , GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLTEXRENDERBUFFERNVPROC)(GLenum , GLuint );

extern PFNGLGETMULTISAMPLEFVNVPROC glGetMultisamplefvNV;
extern PFNGLSAMPLEMASKINDEXEDNVPROC glSampleMaskIndexedNV;
extern PFNGLTEXRENDERBUFFERNVPROC glTexRenderbufferNV;
#endif /*GL_NV_explicit_multisample*/

/******************************
* Extension: GL_NV_fence
******************************/

#define GL_ALL_COMPLETED_NV 0x84F2
#define GL_FENCE_STATUS_NV 0x84F3
#define GL_FENCE_CONDITION_NV 0x84F4


#ifndef GL_NV_fence
#define GL_NV_fence 1

typedef void (GLE_FUNCPTR * PFNGLDELETEFENCESNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENFENCESNVPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISFENCENVPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLTESTFENCENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETFENCEIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLFINISHFENCENVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLSETFENCENVPROC)(GLuint , GLenum );

extern PFNGLDELETEFENCESNVPROC glDeleteFencesNV;
extern PFNGLGENFENCESNVPROC glGenFencesNV;
extern PFNGLISFENCENVPROC glIsFenceNV;
extern PFNGLTESTFENCENVPROC glTestFenceNV;
extern PFNGLGETFENCEIVNVPROC glGetFenceivNV;
extern PFNGLFINISHFENCENVPROC glFinishFenceNV;
extern PFNGLSETFENCENVPROC glSetFenceNV;
#endif /*GL_NV_fence*/

/******************************
* Extension: GL_NV_float_buffer
******************************/

#define GL_FLOAT_R_NV 0x8880
#define GL_FLOAT_RG_NV 0x8881
#define GL_FLOAT_RGB_NV 0x8882
#define GL_FLOAT_RGBA_NV 0x8883
#define GL_FLOAT_R16_NV 0x8884
#define GL_FLOAT_R32_NV 0x8885
#define GL_FLOAT_RG16_NV 0x8886
#define GL_FLOAT_RG32_NV 0x8887
#define GL_FLOAT_RGB16_NV 0x8888
#define GL_FLOAT_RGB32_NV 0x8889
#define GL_FLOAT_RGBA16_NV 0x888A
#define GL_FLOAT_RGBA32_NV 0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV 0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV 0x888D
#define GL_FLOAT_RGBA_MODE_NV 0x888E


/******************************
* Extension: GL_NV_fog_distance
******************************/

#define GL_EYE_PLANE 0x2502
#define GL_FOG_DISTANCE_MODE_NV 0x855A
#define GL_EYE_RADIAL_NV 0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV 0x855C


/******************************
* Extension: GL_NV_fragment_program
******************************/

#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV 0x8868
#define GL_FRAGMENT_PROGRAM_NV 0x8870
#define GL_MAX_TEXTURE_COORDS_NV 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV 0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV 0x8873
#define GL_PROGRAM_ERROR_STRING_NV 0x8874


#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)(GLuint , GLsizei , const GLubyte *, GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)(GLuint , GLsizei , const GLubyte *, GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)(GLuint , GLsizei , const GLubyte *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)(GLuint , GLsizei , const GLubyte *, const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)(GLuint , GLsizei , const GLubyte *, GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)(GLuint , GLsizei , const GLubyte *, GLdouble *);

extern PFNGLPROGRAMNAMEDPARAMETER4FNVPROC glProgramNamedParameter4fNV;
extern PFNGLPROGRAMNAMEDPARAMETER4DNVPROC glProgramNamedParameter4dNV;
extern PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC glProgramNamedParameter4fvNV;
extern PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC glProgramNamedParameter4dvNV;
extern PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC glGetProgramNamedParameterfvNV;
extern PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC glGetProgramNamedParameterdvNV;
#endif /*GL_NV_fragment_program*/

/******************************
* Extension: GL_NV_fragment_program2
******************************/

#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV 0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV 0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV 0x88F8


/******************************
* Extension: GL_NV_fragment_program4
******************************/

/******************************
* Extension: GL_NV_fragment_program_option
******************************/

/******************************
* Extension: GL_NV_framebuffer_multisample_coverage
******************************/

#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV 0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV 0x8E12


#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1

typedef void (GLE_FUNCPTR * PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLenum , GLsizei , GLsizei );

extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC glRenderbufferStorageMultisampleCoverageNV;
#endif /*GL_NV_framebuffer_multisample_coverage*/

/******************************
* Extension: GL_NV_geometry_program4
******************************/

#define GL_LINES_ADJACENCY_EXT 0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT 0x000B
#define GL_TRIANGLES_ADJACENCY_EXT 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT 0x000D
#define GL_GEOMETRY_PROGRAM_NV 0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV 0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV 0x8C28
#define GL_GEOMETRY_VERTICES_OUT_EXT 0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT 0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT 0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT 0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT 0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT 0x8642


#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMVERTEXLIMITNVPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREEXTPROC)(GLenum , GLenum , GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)(GLenum , GLenum , GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)(GLenum , GLenum , GLuint , GLint , GLenum );

extern PFNGLPROGRAMVERTEXLIMITNVPROC glProgramVertexLimitNV;
extern PFNGLFRAMEBUFFERTEXTUREEXTPROC glFramebufferTextureEXT;
extern PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC glFramebufferTextureLayerEXT;
extern PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC glFramebufferTextureFaceEXT;
#endif /*GL_NV_geometry_program4*/

/******************************
* Extension: GL_NV_geometry_shader4
******************************/

/******************************
* Extension: GL_NV_gpu_program4
******************************/

#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV 0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV 0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV 0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV 0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV 0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV 0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV 0x8DA6


#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1

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

extern PFNGLPROGRAMLOCALPARAMETERI4INVPROC glProgramLocalParameterI4iNV;
extern PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC glProgramLocalParameterI4ivNV;
extern PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC glProgramLocalParametersI4ivNV;
extern PFNGLPROGRAMLOCALPARAMETERI4UINVPROC glProgramLocalParameterI4uiNV;
extern PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC glProgramLocalParameterI4uivNV;
extern PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC glProgramLocalParametersI4uivNV;
extern PFNGLPROGRAMENVPARAMETERI4INVPROC glProgramEnvParameterI4iNV;
extern PFNGLPROGRAMENVPARAMETERI4IVNVPROC glProgramEnvParameterI4ivNV;
extern PFNGLPROGRAMENVPARAMETERSI4IVNVPROC glProgramEnvParametersI4ivNV;
extern PFNGLPROGRAMENVPARAMETERI4UINVPROC glProgramEnvParameterI4uiNV;
extern PFNGLPROGRAMENVPARAMETERI4UIVNVPROC glProgramEnvParameterI4uivNV;
extern PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC glProgramEnvParametersI4uivNV;
extern PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC glGetProgramLocalParameterIivNV;
extern PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC glGetProgramLocalParameterIuivNV;
extern PFNGLGETPROGRAMENVPARAMETERIIVNVPROC glGetProgramEnvParameterIivNV;
extern PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC glGetProgramEnvParameterIuivNV;
#endif /*GL_NV_gpu_program4*/

/******************************
* Extension: GL_NV_gpu_program5
******************************/

#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV 0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV 0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV 0x8E5F
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV 0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV 0x8F45


#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)(GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)(GLenum , GLuint , GLuint *);

extern PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC glProgramSubroutineParametersuivNV;
extern PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC glGetProgramSubroutineParameteruivNV;
#endif /*GL_NV_gpu_program5*/

/******************************
* Extension: GL_NV_gpu_shader5
******************************/

#define GL_PATCHES 0x000E
#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F
#define GL_INT8_NV 0x8FE0
#define GL_INT8_VEC2_NV 0x8FE1
#define GL_INT8_VEC3_NV 0x8FE2
#define GL_INT8_VEC4_NV 0x8FE3
#define GL_INT16_NV 0x8FE4
#define GL_INT16_VEC2_NV 0x8FE5
#define GL_INT16_VEC3_NV 0x8FE6
#define GL_INT16_VEC4_NV 0x8FE7
#define GL_INT64_VEC2_NV 0x8FE9
#define GL_INT64_VEC3_NV 0x8FEA
#define GL_INT64_VEC4_NV 0x8FEB
#define GL_UNSIGNED_INT8_NV 0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV 0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV 0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV 0x8FEF
#define GL_UNSIGNED_INT16_NV 0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV 0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV 0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV 0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV 0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV 0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV 0x8FF7
#define GL_FLOAT16_NV 0x8FF8
#define GL_FLOAT16_VEC2_NV 0x8FF9
#define GL_FLOAT16_VEC3_NV 0x8FFA
#define GL_FLOAT16_VEC4_NV 0x8FFB


#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1

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

extern PFNGLUNIFORM1I64NVPROC glUniform1i64NV;
extern PFNGLUNIFORM2I64NVPROC glUniform2i64NV;
extern PFNGLUNIFORM3I64NVPROC glUniform3i64NV;
extern PFNGLUNIFORM4I64NVPROC glUniform4i64NV;
extern PFNGLUNIFORM1I64VNVPROC glUniform1i64vNV;
extern PFNGLUNIFORM2I64VNVPROC glUniform2i64vNV;
extern PFNGLUNIFORM3I64VNVPROC glUniform3i64vNV;
extern PFNGLUNIFORM4I64VNVPROC glUniform4i64vNV;
extern PFNGLUNIFORM1UI64NVPROC glUniform1ui64NV;
extern PFNGLUNIFORM2UI64NVPROC glUniform2ui64NV;
extern PFNGLUNIFORM3UI64NVPROC glUniform3ui64NV;
extern PFNGLUNIFORM4UI64NVPROC glUniform4ui64NV;
extern PFNGLUNIFORM1UI64VNVPROC glUniform1ui64vNV;
extern PFNGLUNIFORM2UI64VNVPROC glUniform2ui64vNV;
extern PFNGLUNIFORM3UI64VNVPROC glUniform3ui64vNV;
extern PFNGLUNIFORM4UI64VNVPROC glUniform4ui64vNV;
extern PFNGLGETUNIFORMI64VNVPROC glGetUniformi64vNV;
extern PFNGLPROGRAMUNIFORM1I64NVPROC glProgramUniform1i64NV;
extern PFNGLPROGRAMUNIFORM2I64NVPROC glProgramUniform2i64NV;
extern PFNGLPROGRAMUNIFORM3I64NVPROC glProgramUniform3i64NV;
extern PFNGLPROGRAMUNIFORM4I64NVPROC glProgramUniform4i64NV;
extern PFNGLPROGRAMUNIFORM1I64VNVPROC glProgramUniform1i64vNV;
extern PFNGLPROGRAMUNIFORM2I64VNVPROC glProgramUniform2i64vNV;
extern PFNGLPROGRAMUNIFORM3I64VNVPROC glProgramUniform3i64vNV;
extern PFNGLPROGRAMUNIFORM4I64VNVPROC glProgramUniform4i64vNV;
extern PFNGLPROGRAMUNIFORM1UI64NVPROC glProgramUniform1ui64NV;
extern PFNGLPROGRAMUNIFORM2UI64NVPROC glProgramUniform2ui64NV;
extern PFNGLPROGRAMUNIFORM3UI64NVPROC glProgramUniform3ui64NV;
extern PFNGLPROGRAMUNIFORM4UI64NVPROC glProgramUniform4ui64NV;
extern PFNGLPROGRAMUNIFORM1UI64VNVPROC glProgramUniform1ui64vNV;
extern PFNGLPROGRAMUNIFORM2UI64VNVPROC glProgramUniform2ui64vNV;
extern PFNGLPROGRAMUNIFORM3UI64VNVPROC glProgramUniform3ui64vNV;
extern PFNGLPROGRAMUNIFORM4UI64VNVPROC glProgramUniform4ui64vNV;
#endif /*GL_NV_gpu_shader5*/

/******************************
* Extension: GL_NV_half_float
******************************/

#define GL_HALF_FLOAT_NV 0x140B


#ifndef GL_NV_half_float
#define GL_NV_half_float 1

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

extern PFNGLVERTEX2HNVPROC glVertex2hNV;
extern PFNGLVERTEX2HVNVPROC glVertex2hvNV;
extern PFNGLVERTEX3HNVPROC glVertex3hNV;
extern PFNGLVERTEX3HVNVPROC glVertex3hvNV;
extern PFNGLVERTEX4HNVPROC glVertex4hNV;
extern PFNGLVERTEX4HVNVPROC glVertex4hvNV;
extern PFNGLNORMAL3HNVPROC glNormal3hNV;
extern PFNGLNORMAL3HVNVPROC glNormal3hvNV;
extern PFNGLCOLOR3HNVPROC glColor3hNV;
extern PFNGLCOLOR3HVNVPROC glColor3hvNV;
extern PFNGLCOLOR4HNVPROC glColor4hNV;
extern PFNGLCOLOR4HVNVPROC glColor4hvNV;
extern PFNGLTEXCOORD1HNVPROC glTexCoord1hNV;
extern PFNGLTEXCOORD1HVNVPROC glTexCoord1hvNV;
extern PFNGLTEXCOORD2HNVPROC glTexCoord2hNV;
extern PFNGLTEXCOORD2HVNVPROC glTexCoord2hvNV;
extern PFNGLTEXCOORD3HNVPROC glTexCoord3hNV;
extern PFNGLTEXCOORD3HVNVPROC glTexCoord3hvNV;
extern PFNGLTEXCOORD4HNVPROC glTexCoord4hNV;
extern PFNGLTEXCOORD4HVNVPROC glTexCoord4hvNV;
extern PFNGLMULTITEXCOORD1HNVPROC glMultiTexCoord1hNV;
extern PFNGLMULTITEXCOORD1HVNVPROC glMultiTexCoord1hvNV;
extern PFNGLMULTITEXCOORD2HNVPROC glMultiTexCoord2hNV;
extern PFNGLMULTITEXCOORD2HVNVPROC glMultiTexCoord2hvNV;
extern PFNGLMULTITEXCOORD3HNVPROC glMultiTexCoord3hNV;
extern PFNGLMULTITEXCOORD3HVNVPROC glMultiTexCoord3hvNV;
extern PFNGLMULTITEXCOORD4HNVPROC glMultiTexCoord4hNV;
extern PFNGLMULTITEXCOORD4HVNVPROC glMultiTexCoord4hvNV;
extern PFNGLFOGCOORDHNVPROC glFogCoordhNV;
extern PFNGLFOGCOORDHVNVPROC glFogCoordhvNV;
extern PFNGLSECONDARYCOLOR3HNVPROC glSecondaryColor3hNV;
extern PFNGLSECONDARYCOLOR3HVNVPROC glSecondaryColor3hvNV;
extern PFNGLVERTEXWEIGHTHNVPROC glVertexWeighthNV;
extern PFNGLVERTEXWEIGHTHVNVPROC glVertexWeighthvNV;
extern PFNGLVERTEXATTRIB1HNVPROC glVertexAttrib1hNV;
extern PFNGLVERTEXATTRIB1HVNVPROC glVertexAttrib1hvNV;
extern PFNGLVERTEXATTRIB2HNVPROC glVertexAttrib2hNV;
extern PFNGLVERTEXATTRIB2HVNVPROC glVertexAttrib2hvNV;
extern PFNGLVERTEXATTRIB3HNVPROC glVertexAttrib3hNV;
extern PFNGLVERTEXATTRIB3HVNVPROC glVertexAttrib3hvNV;
extern PFNGLVERTEXATTRIB4HNVPROC glVertexAttrib4hNV;
extern PFNGLVERTEXATTRIB4HVNVPROC glVertexAttrib4hvNV;
extern PFNGLVERTEXATTRIBS1HVNVPROC glVertexAttribs1hvNV;
extern PFNGLVERTEXATTRIBS2HVNVPROC glVertexAttribs2hvNV;
extern PFNGLVERTEXATTRIBS3HVNVPROC glVertexAttribs3hvNV;
extern PFNGLVERTEXATTRIBS4HVNVPROC glVertexAttribs4hvNV;
#endif /*GL_NV_half_float*/

/******************************
* Extension: GL_NV_light_max_exponent
******************************/

#define GL_MAX_SHININESS_NV 0x8504
#define GL_MAX_SPOT_EXPONENT_NV 0x8505


/******************************
* Extension: GL_NV_multisample_coverage
******************************/

#define GL_COVERAGE_SAMPLES_NV 0x80A9
#define GL_COLOR_SAMPLES_NV 0x8E20


/******************************
* Extension: GL_NV_multisample_filter_hint
******************************/

#define GL_MULTISAMPLE_FILTER_HINT_NV 0x8534


/******************************
* Extension: GL_NV_occlusion_query
******************************/

#define GL_PIXEL_COUNTER_BITS_NV 0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV 0x8865
#define GL_PIXEL_COUNT_NV 0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV 0x8867


#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1

typedef void (GLE_FUNCPTR * PFNGLGENOCCLUSIONQUERIESNVPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEOCCLUSIONQUERIESNVPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISOCCLUSIONQUERYNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINOCCLUSIONQUERYNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDOCCLUSIONQUERYNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLGETOCCLUSIONQUERYIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETOCCLUSIONQUERYUIVNVPROC)(GLuint , GLenum , GLuint *);

extern PFNGLGENOCCLUSIONQUERIESNVPROC glGenOcclusionQueriesNV;
extern PFNGLDELETEOCCLUSIONQUERIESNVPROC glDeleteOcclusionQueriesNV;
extern PFNGLISOCCLUSIONQUERYNVPROC glIsOcclusionQueryNV;
extern PFNGLBEGINOCCLUSIONQUERYNVPROC glBeginOcclusionQueryNV;
extern PFNGLENDOCCLUSIONQUERYNVPROC glEndOcclusionQueryNV;
extern PFNGLGETOCCLUSIONQUERYIVNVPROC glGetOcclusionQueryivNV;
extern PFNGLGETOCCLUSIONQUERYUIVNVPROC glGetOcclusionQueryuivNV;
#endif /*GL_NV_occlusion_query*/

/******************************
* Extension: GL_NV_packed_depth_stencil
******************************/

#define GL_DEPTH_STENCIL_NV 0x84F9
#define GL_UNSIGNED_INT_24_8_NV 0x84FA


/******************************
* Extension: GL_NV_parameter_buffer_object
******************************/

#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV 0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV 0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV 0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV 0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV 0x8DA4


#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1

typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)(GLenum , GLuint , GLuint , GLsizei , const GLuint *);

extern PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC glProgramBufferParametersfvNV;
extern PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC glProgramBufferParametersIivNV;
extern PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC glProgramBufferParametersIuivNV;
#endif /*GL_NV_parameter_buffer_object*/

/******************************
* Extension: GL_NV_parameter_buffer_object2
******************************/

/******************************
* Extension: GL_NV_path_rendering
******************************/

#define GL_PATH_FORMAT_SVG_NV 0x9070
#define GL_PATH_FORMAT_PS_NV 0x9071
#define GL_STANDARD_FONT_NAME_NV 0x9072
#define GL_SYSTEM_FONT_NAME_NV 0x9073
#define GL_FILE_NAME_NV 0x9074
#define GL_PATH_STROKE_WIDTH_NV 0x9075
#define GL_PATH_END_CAPS_NV 0x9076
#define GL_PATH_INITIAL_END_CAP_NV 0x9077
#define GL_PATH_TERMINAL_END_CAP_NV 0x9078
#define GL_PATH_JOIN_STYLE_NV 0x9079
#define GL_PATH_MITER_LIMIT_NV 0x907A
#define GL_PATH_DASH_CAPS_NV 0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV 0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV 0x907D
#define GL_PATH_DASH_OFFSET_NV 0x907E
#define GL_PATH_CLIENT_LENGTH_NV 0x907F
#define GL_PATH_FILL_MODE_NV 0x9080
#define GL_PATH_FILL_MASK_NV 0x9081
#define GL_PATH_FILL_COVER_MODE_NV 0x9082
#define GL_PATH_STROKE_COVER_MODE_NV 0x9083
#define GL_PATH_STROKE_MASK_NV 0x9084
#define GL_PATH_SAMPLE_QUALITY_NV 0x9085
#define GL_PATH_STROKE_BOUND_NV 0x9086
#define GL_PATH_STROKE_OVERSAMPLE_COUNT_NV 0x9087
#define GL_COUNT_UP_NV 0x9088
#define GL_COUNT_DOWN_NV 0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV 0x908A
#define GL_CONVEX_HULL_NV 0x908B
#define GL_MULTI_HULLS_NV 0x908C
#define GL_BOUNDING_BOX_NV 0x908D
#define GL_TRANSLATE_X_NV 0x908E
#define GL_TRANSLATE_Y_NV 0x908F
#define GL_TRANSLATE_2D_NV 0x9090
#define GL_TRANSLATE_3D_NV 0x9091
#define GL_AFFINE_2D_NV 0x9092
#define GL_PROJECTIVE_2D_NV 0x9093
#define GL_AFFINE_3D_NV 0x9094
#define GL_PROJECTIVE_3D_NV 0x9095
#define GL_TRANSPOSE_AFFINE_2D_NV 0x9096
#define GL_TRANSPOSE_PROJECTIVE_2D_NV 0x9097
#define GL_TRANSPOSE_AFFINE_3D_NV 0x9098
#define GL_TRANSPOSE_PROJECTIVE_3D_NV 0x9099
#define GL_UTF8_NV 0x909A
#define GL_UTF16_NV 0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV 0x909D
#define GL_PATH_COORD_COUNT_NV 0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV 0x909F
#define GL_PATH_COMPUTED_LENGTH_NV 0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV 0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV 0x90A2
#define GL_SQUARE_NV 0x90A3
#define GL_ROUND_NV 0x90A4
#define GL_TRIANGULAR_NV 0x90A5
#define GL_BEVEL_NV 0x90A6
#define GL_MITER_REVERT_NV 0x90A7
#define GL_MITER_TRUNCATE_NV 0x90A8
#define GL_SKIP_MISSING_GLYPH_NV 0x90A9
#define GL_USE_MISSING_GLYPH_NV 0x90AA
#define GL_PATH_ERROR_POSITION_NV 0x90AB
#define GL_PATH_FOG_GEN_MODE_NV 0x90AC
#define GL_ACCUM_ADJACENT_PAIRS_NV 0x90AD
#define GL_ADJACENT_PAIRS_NV 0x90AE
#define GL_FIRST_TO_REST_NV 0x90AF
#define GL_PATH_GEN_MODE_NV 0x90B0
#define GL_PATH_GEN_COEFF_NV 0x90B1
#define GL_PATH_GEN_COLOR_FORMAT_NV 0x90B2
#define GL_PATH_GEN_COMPONENTS_NV 0x90B3
#define GL_PATH_STENCIL_FUNC_NV 0x90B7
#define GL_PATH_STENCIL_REF_NV 0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV 0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV 0x90B4
#define GL_MOVE_TO_RESETS_NV 0x90B5
#define GL_MOVE_TO_CONTINUES_NV 0x90B6
#define GL_CLOSE_PATH_NV 0x00
#define GL_MOVE_TO_NV 0x02
#define GL_RELATIVE_MOVE_TO_NV 0x03
#define GL_LINE_TO_NV 0x04
#define GL_RELATIVE_LINE_TO_NV 0x05
#define GL_HORIZONTAL_LINE_TO_NV 0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV 0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV 0x09
#define GL_QUADRATIC_CURVE_TO_NV 0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV 0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV 0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV 0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV 0x13
#define GL_SMALL_CW_ARC_TO_NV 0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV 0x15
#define GL_LARGE_CCW_ARC_TO_NV 0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV 0x17
#define GL_LARGE_CW_ARC_TO_NV 0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV 0x19
#define GL_RESTART_PATH_NV 0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV 0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV 0xF4
#define GL_RECT_NV 0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV 0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV 0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV 0xFC
#define GL_ARC_TO_NV 0xFE
#define GL_RELATIVE_ARC_TO_NV 0xFF
#define GL_BOLD_BIT_NV 0x01
#define GL_ITALIC_BIT_NV 0x02
#define GL_GLYPH_WIDTH_BIT_NV 0x01
#define GL_GLYPH_HEIGHT_BIT_NV 0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_NV 0x100
#define GL_FONT_X_MIN_BOUNDS_NV 0x00010000
#define GL_FONT_Y_MIN_BOUNDS_NV 0x00020000
#define GL_FONT_X_MAX_BOUNDS_NV 0x00040000
#define GL_FONT_Y_MAX_BOUNDS_NV 0x00080000
#define GL_FONT_UNITS_PER_EM_NV 0x00100000
#define GL_FONT_ASCENDER_NV 0x00200000
#define GL_FONT_DESCENDER_NV 0x00400000
#define GL_FONT_HEIGHT_NV 0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_NV 0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_NV 0x08000000
#define GL_FONT_HAS_KERNING_NV 0x10000000


#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1

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

extern PFNGLGENPATHSNVPROC glGenPathsNV;
extern PFNGLDELETEPATHSNVPROC glDeletePathsNV;
extern PFNGLISPATHNVPROC glIsPathNV;
extern PFNGLPATHCOMMANDSNVPROC glPathCommandsNV;
extern PFNGLPATHCOORDSNVPROC glPathCoordsNV;
extern PFNGLPATHSUBCOMMANDSNVPROC glPathSubCommandsNV;
extern PFNGLPATHSUBCOORDSNVPROC glPathSubCoordsNV;
extern PFNGLPATHSTRINGNVPROC glPathStringNV;
extern PFNGLPATHGLYPHSNVPROC glPathGlyphsNV;
extern PFNGLPATHGLYPHRANGENVPROC glPathGlyphRangeNV;
extern PFNGLWEIGHTPATHSNVPROC glWeightPathsNV;
extern PFNGLCOPYPATHNVPROC glCopyPathNV;
extern PFNGLINTERPOLATEPATHSNVPROC glInterpolatePathsNV;
extern PFNGLTRANSFORMPATHNVPROC glTransformPathNV;
extern PFNGLPATHPARAMETERIVNVPROC glPathParameterivNV;
extern PFNGLPATHPARAMETERINVPROC glPathParameteriNV;
extern PFNGLPATHPARAMETERFVNVPROC glPathParameterfvNV;
extern PFNGLPATHPARAMETERFNVPROC glPathParameterfNV;
extern PFNGLPATHDASHARRAYNVPROC glPathDashArrayNV;
extern PFNGLPATHSTENCILFUNCNVPROC glPathStencilFuncNV;
extern PFNGLPATHSTENCILDEPTHOFFSETNVPROC glPathStencilDepthOffsetNV;
extern PFNGLSTENCILFILLPATHNVPROC glStencilFillPathNV;
extern PFNGLSTENCILSTROKEPATHNVPROC glStencilStrokePathNV;
extern PFNGLSTENCILFILLPATHINSTANCEDNVPROC glStencilFillPathInstancedNV;
extern PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC glStencilStrokePathInstancedNV;
extern PFNGLPATHCOVERDEPTHFUNCNVPROC glPathCoverDepthFuncNV;
extern PFNGLPATHCOLORGENNVPROC glPathColorGenNV;
extern PFNGLPATHTEXGENNVPROC glPathTexGenNV;
extern PFNGLPATHFOGGENNVPROC glPathFogGenNV;
extern PFNGLCOVERFILLPATHNVPROC glCoverFillPathNV;
extern PFNGLCOVERSTROKEPATHNVPROC glCoverStrokePathNV;
extern PFNGLCOVERFILLPATHINSTANCEDNVPROC glCoverFillPathInstancedNV;
extern PFNGLCOVERSTROKEPATHINSTANCEDNVPROC glCoverStrokePathInstancedNV;
extern PFNGLGETPATHPARAMETERIVNVPROC glGetPathParameterivNV;
extern PFNGLGETPATHPARAMETERFVNVPROC glGetPathParameterfvNV;
extern PFNGLGETPATHCOMMANDSNVPROC glGetPathCommandsNV;
extern PFNGLGETPATHCOORDSNVPROC glGetPathCoordsNV;
extern PFNGLGETPATHDASHARRAYNVPROC glGetPathDashArrayNV;
extern PFNGLGETPATHMETRICSNVPROC glGetPathMetricsNV;
extern PFNGLGETPATHMETRICRANGENVPROC glGetPathMetricRangeNV;
extern PFNGLGETPATHSPACINGNVPROC glGetPathSpacingNV;
extern PFNGLGETPATHCOLORGENIVNVPROC glGetPathColorGenivNV;
extern PFNGLGETPATHCOLORGENFVNVPROC glGetPathColorGenfvNV;
extern PFNGLGETPATHTEXGENIVNVPROC glGetPathTexGenivNV;
extern PFNGLGETPATHTEXGENFVNVPROC glGetPathTexGenfvNV;
extern PFNGLISPOINTINFILLPATHNVPROC glIsPointInFillPathNV;
extern PFNGLISPOINTINSTROKEPATHNVPROC glIsPointInStrokePathNV;
extern PFNGLGETPATHLENGTHNVPROC glGetPathLengthNV;
extern PFNGLPOINTALONGPATHNVPROC glPointAlongPathNV;
#endif /*GL_NV_path_rendering*/

/******************************
* Extension: GL_NV_pixel_data_range
******************************/

#define GL_WRITE_PIXEL_DATA_RANGE_NV 0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV 0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV 0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV 0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV 0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV 0x887D


#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1

typedef void (GLE_FUNCPTR * PFNGLPIXELDATARANGENVPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLFLUSHPIXELDATARANGENVPROC)(GLenum );

extern PFNGLPIXELDATARANGENVPROC glPixelDataRangeNV;
extern PFNGLFLUSHPIXELDATARANGENVPROC glFlushPixelDataRangeNV;
#endif /*GL_NV_pixel_data_range*/

/******************************
* Extension: GL_NV_point_sprite
******************************/

#define GL_POINT_SPRITE_NV 0x8861
#define GL_COORD_REPLACE_NV 0x8862
#define GL_POINT_SPRITE_R_MODE_NV 0x8863


#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1

typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERINVPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIVNVPROC)(GLenum , const GLint *);

extern PFNGLPOINTPARAMETERINVPROC glPointParameteriNV;
extern PFNGLPOINTPARAMETERIVNVPROC glPointParameterivNV;
#endif /*GL_NV_point_sprite*/

/******************************
* Extension: GL_NV_present_video
******************************/

#define GL_FRAME_NV 0x8E26
#define GL_FIELDS_NV 0x8E27
#define GL_CURRENT_TIME_NV 0x8E28
#define GL_NUM_FILL_STREAMS_NV 0x8E29
#define GL_PRESENT_TIME_NV 0x8E2A
#define GL_PRESENT_DURATION_NV 0x8E2B


#ifndef GL_NV_present_video
#define GL_NV_present_video 1

typedef void (GLE_FUNCPTR * PFNGLPRESENTFRAMEKEYEDNVPROC)(GLuint , GLuint64EXT , GLuint , GLuint , GLenum , GLenum , GLuint , GLuint , GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPRESENTFRAMEDUALFILLNVPROC)(GLuint , GLuint64EXT , GLuint , GLuint , GLenum , GLenum , GLuint , GLenum , GLuint , GLenum , GLuint , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOIVNVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOUIVNVPROC)(GLuint , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOI64VNVPROC)(GLuint , GLenum , GLint64EXT *);
typedef void (GLE_FUNCPTR * PFNGLGETVIDEOUI64VNVPROC)(GLuint , GLenum , GLuint64EXT *);

extern PFNGLPRESENTFRAMEKEYEDNVPROC glPresentFrameKeyedNV;
extern PFNGLPRESENTFRAMEDUALFILLNVPROC glPresentFrameDualFillNV;
extern PFNGLGETVIDEOIVNVPROC glGetVideoivNV;
extern PFNGLGETVIDEOUIVNVPROC glGetVideouivNV;
extern PFNGLGETVIDEOI64VNVPROC glGetVideoi64vNV;
extern PFNGLGETVIDEOUI64VNVPROC glGetVideoui64vNV;
#endif /*GL_NV_present_video*/

/******************************
* Extension: GL_NV_primitive_restart
******************************/

#define GL_PRIMITIVE_RESTART_NV 0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV 0x8559


#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1

typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTINDEXNVPROC)(GLuint );

extern PFNGLPRIMITIVERESTARTNVPROC glPrimitiveRestartNV;
extern PFNGLPRIMITIVERESTARTINDEXNVPROC glPrimitiveRestartIndexNV;
#endif /*GL_NV_primitive_restart*/

/******************************
* Extension: GL_NV_register_combiners
******************************/

#define GL_ZERO 0
#define GL_NONE 0
#define GL_FOG 0x0B60
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1
#define GL_REGISTER_COMBINERS_NV 0x8522
#define GL_VARIABLE_A_NV 0x8523
#define GL_VARIABLE_B_NV 0x8524
#define GL_VARIABLE_C_NV 0x8525
#define GL_VARIABLE_D_NV 0x8526
#define GL_VARIABLE_E_NV 0x8527
#define GL_VARIABLE_F_NV 0x8528
#define GL_VARIABLE_G_NV 0x8529
#define GL_CONSTANT_COLOR0_NV 0x852A
#define GL_CONSTANT_COLOR1_NV 0x852B
#define GL_PRIMARY_COLOR_NV 0x852C
#define GL_SECONDARY_COLOR_NV 0x852D
#define GL_SPARE0_NV 0x852E
#define GL_SPARE1_NV 0x852F
#define GL_DISCARD_NV 0x8530
#define GL_E_TIMES_F_NV 0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV 0x8532
#define GL_UNSIGNED_IDENTITY_NV 0x8536
#define GL_UNSIGNED_INVERT_NV 0x8537
#define GL_EXPAND_NORMAL_NV 0x8538
#define GL_EXPAND_NEGATE_NV 0x8539
#define GL_HALF_BIAS_NORMAL_NV 0x853A
#define GL_HALF_BIAS_NEGATE_NV 0x853B
#define GL_SIGNED_IDENTITY_NV 0x853C
#define GL_SIGNED_NEGATE_NV 0x853D
#define GL_SCALE_BY_TWO_NV 0x853E
#define GL_SCALE_BY_FOUR_NV 0x853F
#define GL_SCALE_BY_ONE_HALF_NV 0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV 0x8541
#define GL_COMBINER_INPUT_NV 0x8542
#define GL_COMBINER_MAPPING_NV 0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV 0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV 0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV 0x8546
#define GL_COMBINER_MUX_SUM_NV 0x8547
#define GL_COMBINER_SCALE_NV 0x8548
#define GL_COMBINER_BIAS_NV 0x8549
#define GL_COMBINER_AB_OUTPUT_NV 0x854A
#define GL_COMBINER_CD_OUTPUT_NV 0x854B
#define GL_COMBINER_SUM_OUTPUT_NV 0x854C
#define GL_MAX_GENERAL_COMBINERS_NV 0x854D
#define GL_NUM_GENERAL_COMBINERS_NV 0x854E
#define GL_COLOR_SUM_CLAMP_NV 0x854F
#define GL_COMBINER0_NV 0x8550
#define GL_COMBINER1_NV 0x8551
#define GL_COMBINER2_NV 0x8552
#define GL_COMBINER3_NV 0x8553
#define GL_COMBINER4_NV 0x8554
#define GL_COMBINER5_NV 0x8555
#define GL_COMBINER6_NV 0x8556
#define GL_COMBINER7_NV 0x8557


#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1

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

extern PFNGLCOMBINERPARAMETERFVNVPROC glCombinerParameterfvNV;
extern PFNGLCOMBINERPARAMETERFNVPROC glCombinerParameterfNV;
extern PFNGLCOMBINERPARAMETERIVNVPROC glCombinerParameterivNV;
extern PFNGLCOMBINERPARAMETERINVPROC glCombinerParameteriNV;
extern PFNGLCOMBINERINPUTNVPROC glCombinerInputNV;
extern PFNGLCOMBINEROUTPUTNVPROC glCombinerOutputNV;
extern PFNGLFINALCOMBINERINPUTNVPROC glFinalCombinerInputNV;
extern PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC glGetCombinerInputParameterfvNV;
extern PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC glGetCombinerInputParameterivNV;
extern PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC glGetCombinerOutputParameterfvNV;
extern PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC glGetCombinerOutputParameterivNV;
extern PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC glGetFinalCombinerInputParameterfvNV;
extern PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC glGetFinalCombinerInputParameterivNV;
#endif /*GL_NV_register_combiners*/

/******************************
* Extension: GL_NV_register_combiners2
******************************/

#define GL_PER_STAGE_CONSTANTS_NV 0x8535


#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1

typedef void (GLE_FUNCPTR * PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)(GLenum , GLenum , GLfloat *);

extern PFNGLCOMBINERSTAGEPARAMETERFVNVPROC glCombinerStageParameterfvNV;
extern PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC glGetCombinerStageParameterfvNV;
#endif /*GL_NV_register_combiners2*/

/******************************
* Extension: GL_NV_shader_atomic_float
******************************/

/******************************
* Extension: GL_NV_shader_buffer_load
******************************/

#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
#define GL_GPU_ADDRESS_NV 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35


#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1

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

extern PFNGLMAKEBUFFERRESIDENTNVPROC glMakeBufferResidentNV;
extern PFNGLMAKEBUFFERNONRESIDENTNVPROC glMakeBufferNonResidentNV;
extern PFNGLISBUFFERRESIDENTNVPROC glIsBufferResidentNV;
extern PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glMakeNamedBufferResidentNV;
extern PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glMakeNamedBufferNonResidentNV;
extern PFNGLISNAMEDBUFFERRESIDENTNVPROC glIsNamedBufferResidentNV;
extern PFNGLGETBUFFERPARAMETERUI64VNVPROC glGetBufferParameterui64vNV;
extern PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glGetNamedBufferParameterui64vNV;
extern PFNGLGETINTEGERUI64VNVPROC glGetIntegerui64vNV;
extern PFNGLUNIFORMUI64NVPROC glUniformui64NV;
extern PFNGLUNIFORMUI64VNVPROC glUniformui64vNV;
extern PFNGLGETUNIFORMUI64VNVPROC glGetUniformui64vNV;
extern PFNGLPROGRAMUNIFORMUI64NVPROC glProgramUniformui64NV;
extern PFNGLPROGRAMUNIFORMUI64VNVPROC glProgramUniformui64vNV;
#endif /*GL_NV_shader_buffer_load*/

/******************************
* Extension: GL_NV_shader_buffer_store
******************************/

#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010


/******************************
* Extension: GL_NV_tessellation_program5
******************************/

#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV 0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV 0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV 0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV 0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV 0x8C75


/******************************
* Extension: GL_NV_texgen_emboss
******************************/

#define GL_EMBOSS_LIGHT_NV 0x855D
#define GL_EMBOSS_CONSTANT_NV 0x855E
#define GL_EMBOSS_MAP_NV 0x855F


/******************************
* Extension: GL_NV_texgen_reflection
******************************/

#define GL_NORMAL_MAP_NV 0x8511
#define GL_REFLECTION_MAP_NV 0x8512


/******************************
* Extension: GL_NV_texture_barrier
******************************/

#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1

typedef void (GLE_FUNCPTR * PFNGLTEXTUREBARRIERNVPROC)();

extern PFNGLTEXTUREBARRIERNVPROC glTextureBarrierNV;
#endif /*GL_NV_texture_barrier*/

/******************************
* Extension: GL_NV_texture_compression_vtc
******************************/

/******************************
* Extension: GL_NV_texture_env_combine4
******************************/

#define GL_COMBINE4_NV 0x8503
#define GL_SOURCE3_RGB_NV 0x8583
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_OPERAND3_ALPHA_NV 0x859B


/******************************
* Extension: GL_NV_texture_expand_normal
******************************/

#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV 0x888F


/******************************
* Extension: GL_NV_texture_multisample
******************************/

#define GL_TEXTURE_COVERAGE_SAMPLES_NV 0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV 0x9046


#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1

typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)(GLuint , GLenum , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)(GLuint , GLenum , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)(GLuint , GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)(GLuint , GLenum , GLsizei , GLsizei , GLint , GLsizei , GLsizei , GLsizei , GLboolean );

extern PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC glTexImage2DMultisampleCoverageNV;
extern PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC glTexImage3DMultisampleCoverageNV;
extern PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC glTextureImage2DMultisampleNV;
extern PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC glTextureImage3DMultisampleNV;
extern PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC glTextureImage2DMultisampleCoverageNV;
extern PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC glTextureImage3DMultisampleCoverageNV;
#endif /*GL_NV_texture_multisample*/

/******************************
* Extension: GL_NV_texture_rectangle
******************************/

#define GL_TEXTURE_RECTANGLE_NV 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV 0x84F8


/******************************
* Extension: GL_NV_texture_shader
******************************/

#define GL_OFFSET_TEXTURE_RECTANGLE_NV 0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV 0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV 0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV 0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV 0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV 0x86DB
#define GL_DSDT_MAG_INTENSITY_NV 0x86DC
#define GL_SHADER_CONSISTENT_NV 0x86DD
#define GL_TEXTURE_SHADER_NV 0x86DE
#define GL_SHADER_OPERATION_NV 0x86DF
#define GL_CULL_MODES_NV 0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV 0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV 0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV 0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV 0x86E1 /* GL_OFFSET_TEXTURE_MATRIX_NV */
#define GL_OFFSET_TEXTURE_2D_SCALE_NV 0x86E2 /* GL_OFFSET_TEXTURE_SCALE_NV */
#define GL_OFFSET_TEXTURE_2D_BIAS_NV 0x86E3 /* GL_OFFSET_TEXTURE_BIAS_NV */
#define GL_PREVIOUS_TEXTURE_INPUT_NV 0x86E4
#define GL_CONST_EYE_NV 0x86E5
#define GL_PASS_THROUGH_NV 0x86E6
#define GL_CULL_FRAGMENT_NV 0x86E7
#define GL_OFFSET_TEXTURE_2D_NV 0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV 0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV 0x86EA
#define GL_DOT_PRODUCT_NV 0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV 0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV 0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV 0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV 0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV 0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV 0x86F3
#define GL_HILO_NV 0x86F4
#define GL_DSDT_NV 0x86F5
#define GL_DSDT_MAG_NV 0x86F6
#define GL_DSDT_MAG_VIB_NV 0x86F7
#define GL_HILO16_NV 0x86F8
#define GL_SIGNED_HILO_NV 0x86F9
#define GL_SIGNED_HILO16_NV 0x86FA
#define GL_SIGNED_RGBA_NV 0x86FB
#define GL_SIGNED_RGBA8_NV 0x86FC
#define GL_SIGNED_RGB_NV 0x86FE
#define GL_SIGNED_RGB8_NV 0x86FF
#define GL_SIGNED_LUMINANCE_NV 0x8701
#define GL_SIGNED_LUMINANCE8_NV 0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV 0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV 0x8704
#define GL_SIGNED_ALPHA_NV 0x8705
#define GL_SIGNED_ALPHA8_NV 0x8706
#define GL_SIGNED_INTENSITY_NV 0x8707
#define GL_SIGNED_INTENSITY8_NV 0x8708
#define GL_DSDT8_NV 0x8709
#define GL_DSDT8_MAG8_NV 0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV 0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV 0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV 0x870D
#define GL_HI_SCALE_NV 0x870E
#define GL_LO_SCALE_NV 0x870F
#define GL_DS_SCALE_NV 0x8710
#define GL_DT_SCALE_NV 0x8711
#define GL_MAGNITUDE_SCALE_NV 0x8712
#define GL_VIBRANCE_SCALE_NV 0x8713
#define GL_HI_BIAS_NV 0x8714
#define GL_LO_BIAS_NV 0x8715
#define GL_DS_BIAS_NV 0x8716
#define GL_DT_BIAS_NV 0x8717
#define GL_MAGNITUDE_BIAS_NV 0x8718
#define GL_VIBRANCE_BIAS_NV 0x8719
#define GL_TEXTURE_BORDER_VALUES_NV 0x871A
#define GL_TEXTURE_HI_SIZE_NV 0x871B
#define GL_TEXTURE_LO_SIZE_NV 0x871C
#define GL_TEXTURE_DS_SIZE_NV 0x871D
#define GL_TEXTURE_DT_SIZE_NV 0x871E
#define GL_TEXTURE_MAG_SIZE_NV 0x871F


/******************************
* Extension: GL_NV_texture_shader2
******************************/

#define GL_DOT_PRODUCT_TEXTURE_3D_NV 0x86EF


/******************************
* Extension: GL_NV_texture_shader3
******************************/

#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV 0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV 0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV 0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV 0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV 0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV 0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV 0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV 0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV 0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV 0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV 0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV 0x885D
#define GL_HILO8_NV 0x885E
#define GL_SIGNED_HILO8_NV 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV 0x8860


/******************************
* Extension: GL_NV_transform_feedback
******************************/

#define GL_BACK_PRIMARY_COLOR_NV 0x8C77
#define GL_BACK_SECONDARY_COLOR_NV 0x8C78
#define GL_TEXTURE_COORD_NV 0x8C79
#define GL_CLIP_DISTANCE_NV 0x8C7A
#define GL_VERTEX_ID_NV 0x8C7B
#define GL_PRIMITIVE_ID_NV 0x8C7C
#define GL_GENERIC_ATTRIB_NV 0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV 0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV 0x8C80
#define GL_ACTIVE_VARYINGS_NV 0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV 0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV 0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV 0x8C86
#define GL_PRIMITIVES_GENERATED_NV 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV 0x8C88
#define GL_RASTERIZER_DISCARD_NV 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV 0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV 0x8C8C
#define GL_SEPARATE_ATTRIBS_NV 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV 0x8C8F
#define GL_LAYER_NV 0x8DAA


#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1

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

extern PFNGLBEGINTRANSFORMFEEDBACKNVPROC glBeginTransformFeedbackNV;
extern PFNGLENDTRANSFORMFEEDBACKNVPROC glEndTransformFeedbackNV;
extern PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC glTransformFeedbackAttribsNV;
extern PFNGLBINDBUFFERRANGENVPROC glBindBufferRangeNV;
extern PFNGLBINDBUFFEROFFSETNVPROC glBindBufferOffsetNV;
extern PFNGLBINDBUFFERBASENVPROC glBindBufferBaseNV;
extern PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC glTransformFeedbackVaryingsNV;
extern PFNGLACTIVEVARYINGNVPROC glActiveVaryingNV;
extern PFNGLGETVARYINGLOCATIONNVPROC glGetVaryingLocationNV;
extern PFNGLGETACTIVEVARYINGNVPROC glGetActiveVaryingNV;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC glGetTransformFeedbackVaryingNV;
extern PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC glTransformFeedbackStreamAttribsNV;
#endif /*GL_NV_transform_feedback*/

/******************************
* Extension: GL_NV_transform_feedback2
******************************/

#define GL_TRANSFORM_FEEDBACK_NV 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV 0x8E25


#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1

typedef void (GLE_FUNCPTR * PFNGLBINDTRANSFORMFEEDBACKNVPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETRANSFORMFEEDBACKSNVPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTRANSFORMFEEDBACKSNVPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTRANSFORMFEEDBACKNVPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPAUSETRANSFORMFEEDBACKNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLRESUMETRANSFORMFEEDBACKNVPROC)();
typedef void (GLE_FUNCPTR * PFNGLDRAWTRANSFORMFEEDBACKNVPROC)(GLenum , GLuint );

extern PFNGLBINDTRANSFORMFEEDBACKNVPROC glBindTransformFeedbackNV;
extern PFNGLDELETETRANSFORMFEEDBACKSNVPROC glDeleteTransformFeedbacksNV;
extern PFNGLGENTRANSFORMFEEDBACKSNVPROC glGenTransformFeedbacksNV;
extern PFNGLISTRANSFORMFEEDBACKNVPROC glIsTransformFeedbackNV;
extern PFNGLPAUSETRANSFORMFEEDBACKNVPROC glPauseTransformFeedbackNV;
extern PFNGLRESUMETRANSFORMFEEDBACKNVPROC glResumeTransformFeedbackNV;
extern PFNGLDRAWTRANSFORMFEEDBACKNVPROC glDrawTransformFeedbackNV;
#endif /*GL_NV_transform_feedback2*/

/******************************
* Extension: GL_NV_vdpau_interop
******************************/

#define GL_SURFACE_STATE_NV 0x86EB
#define GL_SURFACE_REGISTERED_NV 0x86FD
#define GL_SURFACE_MAPPED_NV 0x8700
#define GL_WRITE_DISCARD_NV 0x88BE


#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop 1

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

extern PFNGLVDPAUINITNVPROC glVDPAUInitNV;
extern PFNGLVDPAUFININVPROC glVDPAUFiniNV;
extern PFNGLVDPAUREGISTERVIDEOSURFACENVPROC glVDPAURegisterVideoSurfaceNV;
extern PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC glVDPAURegisterOutputSurfaceNV;
extern PFNGLVDPAUISSURFACENVPROC glVDPAUIsSurfaceNV;
extern PFNGLVDPAUUNREGISTERSURFACENVPROC glVDPAUUnregisterSurfaceNV;
extern PFNGLVDPAUGETSURFACEIVNVPROC glVDPAUGetSurfaceivNV;
extern PFNGLVDPAUSURFACEACCESSNVPROC glVDPAUSurfaceAccessNV;
extern PFNGLVDPAUMAPSURFACESNVPROC glVDPAUMapSurfacesNV;
extern PFNGLVDPAUUNMAPSURFACESNVPROC glVDPAUUnmapSurfacesNV;
#endif /*GL_NV_vdpau_interop*/

/******************************
* Extension: GL_NV_vertex_array_range
******************************/

#define GL_VERTEX_ARRAY_RANGE_NV 0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV 0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV 0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV 0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV 0x8521


#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1

typedef void (GLE_FUNCPTR * PFNGLFLUSHVERTEXARRAYRANGENVPROC)();
typedef void (GLE_FUNCPTR * PFNGLVERTEXARRAYRANGENVPROC)(GLsizei , const GLvoid *);

extern PFNGLFLUSHVERTEXARRAYRANGENVPROC glFlushVertexArrayRangeNV;
extern PFNGLVERTEXARRAYRANGENVPROC glVertexArrayRangeNV;
#endif /*GL_NV_vertex_array_range*/

/******************************
* Extension: GL_NV_vertex_array_range2
******************************/

#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV 0x8533


/******************************
* Extension: GL_NV_vertex_attrib_integer_64bit
******************************/

#define GL_INT64_NV 0x140E
#define GL_UNSIGNED_INT64_NV 0x140F


#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1

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

extern PFNGLVERTEXATTRIBL1I64NVPROC glVertexAttribL1i64NV;
extern PFNGLVERTEXATTRIBL2I64NVPROC glVertexAttribL2i64NV;
extern PFNGLVERTEXATTRIBL3I64NVPROC glVertexAttribL3i64NV;
extern PFNGLVERTEXATTRIBL4I64NVPROC glVertexAttribL4i64NV;
extern PFNGLVERTEXATTRIBL1I64VNVPROC glVertexAttribL1i64vNV;
extern PFNGLVERTEXATTRIBL2I64VNVPROC glVertexAttribL2i64vNV;
extern PFNGLVERTEXATTRIBL3I64VNVPROC glVertexAttribL3i64vNV;
extern PFNGLVERTEXATTRIBL4I64VNVPROC glVertexAttribL4i64vNV;
extern PFNGLVERTEXATTRIBL1UI64NVPROC glVertexAttribL1ui64NV;
extern PFNGLVERTEXATTRIBL2UI64NVPROC glVertexAttribL2ui64NV;
extern PFNGLVERTEXATTRIBL3UI64NVPROC glVertexAttribL3ui64NV;
extern PFNGLVERTEXATTRIBL4UI64NVPROC glVertexAttribL4ui64NV;
extern PFNGLVERTEXATTRIBL1UI64VNVPROC glVertexAttribL1ui64vNV;
extern PFNGLVERTEXATTRIBL2UI64VNVPROC glVertexAttribL2ui64vNV;
extern PFNGLVERTEXATTRIBL3UI64VNVPROC glVertexAttribL3ui64vNV;
extern PFNGLVERTEXATTRIBL4UI64VNVPROC glVertexAttribL4ui64vNV;
extern PFNGLGETVERTEXATTRIBLI64VNVPROC glGetVertexAttribLi64vNV;
extern PFNGLGETVERTEXATTRIBLUI64VNVPROC glGetVertexAttribLui64vNV;
extern PFNGLVERTEXATTRIBLFORMATNVPROC glVertexAttribLFormatNV;
#endif /*GL_NV_vertex_attrib_integer_64bit*/

/******************************
* Extension: GL_NV_vertex_buffer_unified_memory
******************************/

#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV 0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV 0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV 0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV 0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV 0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV 0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV 0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV 0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV 0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV 0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV 0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV 0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV 0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42


#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1

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

extern PFNGLBUFFERADDRESSRANGENVPROC glBufferAddressRangeNV;
extern PFNGLVERTEXFORMATNVPROC glVertexFormatNV;
extern PFNGLNORMALFORMATNVPROC glNormalFormatNV;
extern PFNGLCOLORFORMATNVPROC glColorFormatNV;
extern PFNGLINDEXFORMATNVPROC glIndexFormatNV;
extern PFNGLTEXCOORDFORMATNVPROC glTexCoordFormatNV;
extern PFNGLEDGEFLAGFORMATNVPROC glEdgeFlagFormatNV;
extern PFNGLSECONDARYCOLORFORMATNVPROC glSecondaryColorFormatNV;
extern PFNGLFOGCOORDFORMATNVPROC glFogCoordFormatNV;
extern PFNGLVERTEXATTRIBFORMATNVPROC glVertexAttribFormatNV;
extern PFNGLVERTEXATTRIBIFORMATNVPROC glVertexAttribIFormatNV;
extern PFNGLGETINTEGERUI64I_VNVPROC glGetIntegerui64i_vNV;
#endif /*GL_NV_vertex_buffer_unified_memory*/

/******************************
* Extension: GL_NV_vertex_program
******************************/

#define GL_VERTEX_PROGRAM_NV 0x8620
#define GL_VERTEX_STATE_PROGRAM_NV 0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV 0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV 0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV 0x8625
#define GL_CURRENT_ATTRIB_NV 0x8626
#define GL_PROGRAM_LENGTH_NV 0x8627
#define GL_PROGRAM_STRING_NV 0x8628
#define GL_MODELVIEW_PROJECTION_NV 0x8629
#define GL_IDENTITY_NV 0x862A
#define GL_INVERSE_NV 0x862B
#define GL_TRANSPOSE_NV 0x862C
#define GL_INVERSE_TRANSPOSE_NV 0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 0x862E
#define GL_MAX_TRACK_MATRICES_NV 0x862F
#define GL_MATRIX0_NV 0x8630
#define GL_MATRIX1_NV 0x8631
#define GL_MATRIX2_NV 0x8632
#define GL_MATRIX3_NV 0x8633
#define GL_MATRIX4_NV 0x8634
#define GL_MATRIX5_NV 0x8635
#define GL_MATRIX6_NV 0x8636
#define GL_MATRIX7_NV 0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV 0x8640
#define GL_CURRENT_MATRIX_NV 0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV 0x8643
#define GL_PROGRAM_PARAMETER_NV 0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV 0x8645
#define GL_PROGRAM_TARGET_NV 0x8646
#define GL_PROGRAM_RESIDENT_NV 0x8647
#define GL_TRACK_MATRIX_NV 0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV 0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV 0x864A
#define GL_PROGRAM_ERROR_POSITION_NV 0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV 0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV 0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV 0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV 0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV 0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV 0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV 0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV 0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV 0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV 0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV 0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV 0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV 0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV 0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV 0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV 0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV 0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV 0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV 0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV 0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV 0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV 0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV 0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV 0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV 0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV 0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV 0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV 0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV 0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV 0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV 0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV 0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV 0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV 0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV 0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV 0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV 0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV 0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV 0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV 0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV 0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV 0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV 0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV 0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV 0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV 0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV 0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV 0x867F


#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1

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

extern PFNGLAREPROGRAMSRESIDENTNVPROC glAreProgramsResidentNV;
extern PFNGLBINDPROGRAMNVPROC glBindProgramNV;
extern PFNGLDELETEPROGRAMSNVPROC glDeleteProgramsNV;
extern PFNGLEXECUTEPROGRAMNVPROC glExecuteProgramNV;
extern PFNGLGENPROGRAMSNVPROC glGenProgramsNV;
extern PFNGLGETPROGRAMPARAMETERDVNVPROC glGetProgramParameterdvNV;
extern PFNGLGETPROGRAMPARAMETERFVNVPROC glGetProgramParameterfvNV;
extern PFNGLGETPROGRAMIVNVPROC glGetProgramivNV;
extern PFNGLGETPROGRAMSTRINGNVPROC glGetProgramStringNV;
extern PFNGLGETTRACKMATRIXIVNVPROC glGetTrackMatrixivNV;
extern PFNGLGETVERTEXATTRIBDVNVPROC glGetVertexAttribdvNV;
extern PFNGLGETVERTEXATTRIBFVNVPROC glGetVertexAttribfvNV;
extern PFNGLGETVERTEXATTRIBIVNVPROC glGetVertexAttribivNV;
extern PFNGLGETVERTEXATTRIBPOINTERVNVPROC glGetVertexAttribPointervNV;
extern PFNGLISPROGRAMNVPROC glIsProgramNV;
extern PFNGLLOADPROGRAMNVPROC glLoadProgramNV;
extern PFNGLPROGRAMPARAMETER4DNVPROC glProgramParameter4dNV;
extern PFNGLPROGRAMPARAMETER4DVNVPROC glProgramParameter4dvNV;
extern PFNGLPROGRAMPARAMETER4FNVPROC glProgramParameter4fNV;
extern PFNGLPROGRAMPARAMETER4FVNVPROC glProgramParameter4fvNV;
extern PFNGLPROGRAMPARAMETERS4DVNVPROC glProgramParameters4dvNV;
extern PFNGLPROGRAMPARAMETERS4FVNVPROC glProgramParameters4fvNV;
extern PFNGLREQUESTRESIDENTPROGRAMSNVPROC glRequestResidentProgramsNV;
extern PFNGLTRACKMATRIXNVPROC glTrackMatrixNV;
extern PFNGLVERTEXATTRIBPOINTERNVPROC glVertexAttribPointerNV;
extern PFNGLVERTEXATTRIB1DNVPROC glVertexAttrib1dNV;
extern PFNGLVERTEXATTRIB1DVNVPROC glVertexAttrib1dvNV;
extern PFNGLVERTEXATTRIB1FNVPROC glVertexAttrib1fNV;
extern PFNGLVERTEXATTRIB1FVNVPROC glVertexAttrib1fvNV;
extern PFNGLVERTEXATTRIB1SNVPROC glVertexAttrib1sNV;
extern PFNGLVERTEXATTRIB1SVNVPROC glVertexAttrib1svNV;
extern PFNGLVERTEXATTRIB2DNVPROC glVertexAttrib2dNV;
extern PFNGLVERTEXATTRIB2DVNVPROC glVertexAttrib2dvNV;
extern PFNGLVERTEXATTRIB2FNVPROC glVertexAttrib2fNV;
extern PFNGLVERTEXATTRIB2FVNVPROC glVertexAttrib2fvNV;
extern PFNGLVERTEXATTRIB2SNVPROC glVertexAttrib2sNV;
extern PFNGLVERTEXATTRIB2SVNVPROC glVertexAttrib2svNV;
extern PFNGLVERTEXATTRIB3DNVPROC glVertexAttrib3dNV;
extern PFNGLVERTEXATTRIB3DVNVPROC glVertexAttrib3dvNV;
extern PFNGLVERTEXATTRIB3FNVPROC glVertexAttrib3fNV;
extern PFNGLVERTEXATTRIB3FVNVPROC glVertexAttrib3fvNV;
extern PFNGLVERTEXATTRIB3SNVPROC glVertexAttrib3sNV;
extern PFNGLVERTEXATTRIB3SVNVPROC glVertexAttrib3svNV;
extern PFNGLVERTEXATTRIB4DNVPROC glVertexAttrib4dNV;
extern PFNGLVERTEXATTRIB4DVNVPROC glVertexAttrib4dvNV;
extern PFNGLVERTEXATTRIB4FNVPROC glVertexAttrib4fNV;
extern PFNGLVERTEXATTRIB4FVNVPROC glVertexAttrib4fvNV;
extern PFNGLVERTEXATTRIB4SNVPROC glVertexAttrib4sNV;
extern PFNGLVERTEXATTRIB4SVNVPROC glVertexAttrib4svNV;
extern PFNGLVERTEXATTRIB4UBNVPROC glVertexAttrib4ubNV;
extern PFNGLVERTEXATTRIB4UBVNVPROC glVertexAttrib4ubvNV;
extern PFNGLVERTEXATTRIBS1DVNVPROC glVertexAttribs1dvNV;
extern PFNGLVERTEXATTRIBS1FVNVPROC glVertexAttribs1fvNV;
extern PFNGLVERTEXATTRIBS1SVNVPROC glVertexAttribs1svNV;
extern PFNGLVERTEXATTRIBS2DVNVPROC glVertexAttribs2dvNV;
extern PFNGLVERTEXATTRIBS2FVNVPROC glVertexAttribs2fvNV;
extern PFNGLVERTEXATTRIBS2SVNVPROC glVertexAttribs2svNV;
extern PFNGLVERTEXATTRIBS3DVNVPROC glVertexAttribs3dvNV;
extern PFNGLVERTEXATTRIBS3FVNVPROC glVertexAttribs3fvNV;
extern PFNGLVERTEXATTRIBS3SVNVPROC glVertexAttribs3svNV;
extern PFNGLVERTEXATTRIBS4DVNVPROC glVertexAttribs4dvNV;
extern PFNGLVERTEXATTRIBS4FVNVPROC glVertexAttribs4fvNV;
extern PFNGLVERTEXATTRIBS4SVNVPROC glVertexAttribs4svNV;
extern PFNGLVERTEXATTRIBS4UBVNVPROC glVertexAttribs4ubvNV;
#endif /*GL_NV_vertex_program*/

/******************************
* Extension: GL_NV_vertex_program1_1
******************************/

/******************************
* Extension: GL_NV_vertex_program2
******************************/

/******************************
* Extension: GL_NV_vertex_program2_option
******************************/

#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV 0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV 0x88F5


/******************************
* Extension: GL_NV_vertex_program3
******************************/

#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C


/******************************
* Extension: GL_NV_vertex_program4
******************************/

#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV 0x88FD


#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1

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

extern PFNGLVERTEXATTRIBI1IEXTPROC glVertexAttribI1iEXT;
extern PFNGLVERTEXATTRIBI2IEXTPROC glVertexAttribI2iEXT;
extern PFNGLVERTEXATTRIBI3IEXTPROC glVertexAttribI3iEXT;
extern PFNGLVERTEXATTRIBI4IEXTPROC glVertexAttribI4iEXT;
extern PFNGLVERTEXATTRIBI1UIEXTPROC glVertexAttribI1uiEXT;
extern PFNGLVERTEXATTRIBI2UIEXTPROC glVertexAttribI2uiEXT;
extern PFNGLVERTEXATTRIBI3UIEXTPROC glVertexAttribI3uiEXT;
extern PFNGLVERTEXATTRIBI4UIEXTPROC glVertexAttribI4uiEXT;
extern PFNGLVERTEXATTRIBI1IVEXTPROC glVertexAttribI1ivEXT;
extern PFNGLVERTEXATTRIBI2IVEXTPROC glVertexAttribI2ivEXT;
extern PFNGLVERTEXATTRIBI3IVEXTPROC glVertexAttribI3ivEXT;
extern PFNGLVERTEXATTRIBI4IVEXTPROC glVertexAttribI4ivEXT;
extern PFNGLVERTEXATTRIBI1UIVEXTPROC glVertexAttribI1uivEXT;
extern PFNGLVERTEXATTRIBI2UIVEXTPROC glVertexAttribI2uivEXT;
extern PFNGLVERTEXATTRIBI3UIVEXTPROC glVertexAttribI3uivEXT;
extern PFNGLVERTEXATTRIBI4UIVEXTPROC glVertexAttribI4uivEXT;
extern PFNGLVERTEXATTRIBI4BVEXTPROC glVertexAttribI4bvEXT;
extern PFNGLVERTEXATTRIBI4SVEXTPROC glVertexAttribI4svEXT;
extern PFNGLVERTEXATTRIBI4UBVEXTPROC glVertexAttribI4ubvEXT;
extern PFNGLVERTEXATTRIBI4USVEXTPROC glVertexAttribI4usvEXT;
extern PFNGLVERTEXATTRIBIPOINTEREXTPROC glVertexAttribIPointerEXT;
extern PFNGLGETVERTEXATTRIBIIVEXTPROC glGetVertexAttribIivEXT;
extern PFNGLGETVERTEXATTRIBIUIVEXTPROC glGetVertexAttribIuivEXT;
#endif /*GL_NV_vertex_program4*/

/******************************
* Extension: GL_NV_video_capture
******************************/

#define GL_VIDEO_BUFFER_NV 0x9020
#define GL_VIDEO_BUFFER_BINDING_NV 0x9021
#define GL_FIELD_UPPER_NV 0x9022
#define GL_FIELD_LOWER_NV 0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV 0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV 0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV 0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV 0x9027
#define GL_VIDEO_BUFFER_PITCH_NV 0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV 0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV 0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV 0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV 0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV 0x902D
#define GL_PARTIAL_SUCCESS_NV 0x902E
#define GL_SUCCESS_NV 0x902F
#define GL_FAILURE_NV 0x9030
#define GL_YCBYCR8_422_NV 0x9031
#define GL_YCBAYCR8A_4224_NV 0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV 0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV 0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV 0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV 0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV 0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV 0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV 0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV 0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV 0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV 0x903C


#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1

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

extern PFNGLBEGINVIDEOCAPTURENVPROC glBeginVideoCaptureNV;
extern PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC glBindVideoCaptureStreamBufferNV;
extern PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC glBindVideoCaptureStreamTextureNV;
extern PFNGLENDVIDEOCAPTURENVPROC glEndVideoCaptureNV;
extern PFNGLGETVIDEOCAPTUREIVNVPROC glGetVideoCaptureivNV;
extern PFNGLGETVIDEOCAPTURESTREAMIVNVPROC glGetVideoCaptureStreamivNV;
extern PFNGLGETVIDEOCAPTURESTREAMFVNVPROC glGetVideoCaptureStreamfvNV;
extern PFNGLGETVIDEOCAPTURESTREAMDVNVPROC glGetVideoCaptureStreamdvNV;
extern PFNGLVIDEOCAPTURENVPROC glVideoCaptureNV;
extern PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC glVideoCaptureStreamParameterivNV;
extern PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC glVideoCaptureStreamParameterfvNV;
extern PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC glVideoCaptureStreamParameterdvNV;
#endif /*GL_NV_video_capture*/

/******************************
* Extension: GL_OES_read_format
******************************/

#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES 0x8B9B


/******************************
* Extension: GL_OML_interlace
******************************/

#define GL_INTERLACE_OML 0x8980
#define GL_INTERLACE_READ_OML 0x8981


/******************************
* Extension: GL_OML_resample
******************************/

#define GL_PACK_RESAMPLE_OML 0x8984
#define GL_UNPACK_RESAMPLE_OML 0x8985
#define GL_RESAMPLE_REPLICATE_OML 0x8986
#define GL_RESAMPLE_ZERO_FILL_OML 0x8987
#define GL_RESAMPLE_AVERAGE_OML 0x8988
#define GL_RESAMPLE_DECIMATE_OML 0x8989


/******************************
* Extension: GL_OML_subsample
******************************/

#define GL_FORMAT_SUBSAMPLE_24_24_OML 0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML 0x8983


/******************************
* Extension: GL_PGI_misc_hints
******************************/

#define GL_PREFER_DOUBLEBUFFER_HINT_PGI 0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI 0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI 0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI 0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI 0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI 0x1A204
#define GL_ALWAYS_FAST_HINT_PGI 0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI 0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI 0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI 0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI 0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI 0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI 0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI 0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI 0x1A218
#define GL_FULL_STIPPLE_HINT_PGI 0x1A219
#define GL_CLIP_NEAR_HINT_PGI 0x1A220
#define GL_CLIP_FAR_HINT_PGI 0x1A221
#define GL_WIDE_LINE_HINT_PGI 0x1A222
#define GL_BACK_NORMALS_HINT_PGI 0x1A223


#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1

typedef void (GLE_FUNCPTR * PFNGLHINTPGIPROC)(GLenum , GLint );

extern PFNGLHINTPGIPROC glHintPGI;
#endif /*GL_PGI_misc_hints*/

/******************************
* Extension: GL_PGI_vertex_hints
******************************/

#define GL_VERTEX_DATA_HINT_PGI 0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI 0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI 0x1A22C
#define GL_MAX_VERTEX_HINT_PGI 0x1A22D
#define GL_COLOR3_BIT_PGI 0x00010000
#define GL_COLOR4_BIT_PGI 0x00020000
#define GL_EDGEFLAG_BIT_PGI 0x00040000
#define GL_INDEX_BIT_PGI 0x00080000
#define GL_MAT_AMBIENT_BIT_PGI 0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI 0x00400000
#define GL_MAT_EMISSION_BIT_PGI 0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI 0x01000000
#define GL_MAT_SHININESS_BIT_PGI 0x02000000
#define GL_MAT_SPECULAR_BIT_PGI 0x04000000
#define GL_NORMAL_BIT_PGI 0x08000000
#define GL_TEXCOORD1_BIT_PGI 0x10000000
#define GL_TEXCOORD2_BIT_PGI 0x20000000
#define GL_TEXCOORD3_BIT_PGI 0x40000000
#define GL_TEXCOORD4_BIT_PGI 0x80000000
#define GL_VERTEX23_BIT_PGI 0x00000004
#define GL_VERTEX4_BIT_PGI 0x00000008


/******************************
* Extension: GL_REND_screen_coordinates
******************************/

#define GL_SCREEN_COORDINATES_REND 0x8490
#define GL_INVERTED_SCREEN_W_REND 0x8491


/******************************
* Extension: GL_S3_s3tc
******************************/

#define GL_RGB_S3TC 0x83A0
#define GL_RGB4_S3TC 0x83A1
#define GL_RGBA_S3TC 0x83A2
#define GL_RGBA4_S3TC 0x83A3
#define GL_RGBA_DXT5_S3TC 0x83A4
#define GL_RGBA4_DXT5_S3TC 0x83A5


/******************************
* Extension: GL_SGIS_detail_texture
******************************/

#define GL_DETAIL_TEXTURE_2D_SGIS 0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS 0x8096
#define GL_LINEAR_DETAIL_SGIS 0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS 0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS 0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS 0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS 0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS 0x809C


#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1

typedef void (GLE_FUNCPTR * PFNGLDETAILTEXFUNCSGISPROC)(GLenum , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETDETAILTEXFUNCSGISPROC)(GLenum , GLfloat *);

extern PFNGLDETAILTEXFUNCSGISPROC glDetailTexFuncSGIS;
extern PFNGLGETDETAILTEXFUNCSGISPROC glGetDetailTexFuncSGIS;
#endif /*GL_SGIS_detail_texture*/

/******************************
* Extension: GL_SGIS_fog_function
******************************/

#define GL_FOG_FUNC_SGIS 0x812A
#define GL_FOG_FUNC_POINTS_SGIS 0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS 0x812C


#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1

typedef void (GLE_FUNCPTR * PFNGLFOGFUNCSGISPROC)(GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETFOGFUNCSGISPROC)(GLfloat *);

extern PFNGLFOGFUNCSGISPROC glFogFuncSGIS;
extern PFNGLGETFOGFUNCSGISPROC glGetFogFuncSGIS;
#endif /*GL_SGIS_fog_function*/

/******************************
* Extension: GL_SGIS_generate_mipmap
******************************/

#define GL_GENERATE_MIPMAP_SGIS 0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS 0x8192


/******************************
* Extension: GL_SGIS_multisample
******************************/

#define GL_MULTISAMPLE_SGIS 0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS 0x809F
#define GL_SAMPLE_MASK_SGIS 0x80A0
#define GL_1PASS_SGIS 0x80A1
#define GL_2PASS_0_SGIS 0x80A2
#define GL_2PASS_1_SGIS 0x80A3
#define GL_4PASS_0_SGIS 0x80A4
#define GL_4PASS_1_SGIS 0x80A5
#define GL_4PASS_2_SGIS 0x80A6
#define GL_4PASS_3_SGIS 0x80A7
#define GL_SAMPLE_BUFFERS_SGIS 0x80A8
#define GL_SAMPLES_SGIS 0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS 0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS 0x80AB
#define GL_SAMPLE_PATTERN_SGIS 0x80AC


#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1

typedef void (GLE_FUNCPTR * PFNGLSAMPLEMASKSGISPROC)(GLclampf , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLSAMPLEPATTERNSGISPROC)(GLenum );

extern PFNGLSAMPLEMASKSGISPROC glSampleMaskSGIS;
extern PFNGLSAMPLEPATTERNSGISPROC glSamplePatternSGIS;
#endif /*GL_SGIS_multisample*/

/******************************
* Extension: GL_SGIS_pixel_texture
******************************/

#define GL_PIXEL_TEXTURE_SGIS 0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS 0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS 0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS 0x8356


#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1

typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERISGISPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERIVSGISPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERFSGISPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENPARAMETERFVSGISPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)(GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)(GLenum , GLfloat *);

extern PFNGLPIXELTEXGENPARAMETERISGISPROC glPixelTexGenParameteriSGIS;
extern PFNGLPIXELTEXGENPARAMETERIVSGISPROC glPixelTexGenParameterivSGIS;
extern PFNGLPIXELTEXGENPARAMETERFSGISPROC glPixelTexGenParameterfSGIS;
extern PFNGLPIXELTEXGENPARAMETERFVSGISPROC glPixelTexGenParameterfvSGIS;
extern PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC glGetPixelTexGenParameterivSGIS;
extern PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC glGetPixelTexGenParameterfvSGIS;
#endif /*GL_SGIS_pixel_texture*/

/******************************
* Extension: GL_SGIS_point_line_texgen
******************************/

#define GL_EYE_DISTANCE_TO_POINT_SGIS 0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS 0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS 0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS 0x81F3
#define GL_EYE_POINT_SGIS 0x81F4
#define GL_OBJECT_POINT_SGIS 0x81F5
#define GL_EYE_LINE_SGIS 0x81F6
#define GL_OBJECT_LINE_SGIS 0x81F7


/******************************
* Extension: GL_SGIS_point_parameters
******************************/

#define GL_POINT_SIZE_MIN_SGIS 0x8126
#define GL_POINT_SIZE_MAX_SGIS 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS 0x8128
#define GL_DISTANCE_ATTENUATION_SGIS 0x8129


#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1

typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFSGISPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVSGISPROC)(GLenum , const GLfloat *);

extern PFNGLPOINTPARAMETERFSGISPROC glPointParameterfSGIS;
extern PFNGLPOINTPARAMETERFVSGISPROC glPointParameterfvSGIS;
#endif /*GL_SGIS_point_parameters*/

/******************************
* Extension: GL_SGIS_sharpen_texture
******************************/

#define GL_LINEAR_SHARPEN_SGIS 0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS 0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS 0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS 0x80B0


#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1

typedef void (GLE_FUNCPTR * PFNGLSHARPENTEXFUNCSGISPROC)(GLenum , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETSHARPENTEXFUNCSGISPROC)(GLenum , GLfloat *);

extern PFNGLSHARPENTEXFUNCSGISPROC glSharpenTexFuncSGIS;
extern PFNGLGETSHARPENTEXFUNCSGISPROC glGetSharpenTexFuncSGIS;
#endif /*GL_SGIS_sharpen_texture*/

/******************************
* Extension: GL_SGIS_texture4D
******************************/

#define GL_PACK_SKIP_VOLUMES_SGIS 0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS 0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS 0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS 0x8133
#define GL_TEXTURE_4D_SGIS 0x8134
#define GL_PROXY_TEXTURE_4D_SGIS 0x8135
#define GL_TEXTURE_4DSIZE_SGIS 0x8136
#define GL_TEXTURE_WRAP_Q_SGIS 0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS 0x8138
#define GL_TEXTURE_4D_BINDING_SGIS 0x814F


#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1

typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE4DSGISPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE4DSGISPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);

extern PFNGLTEXIMAGE4DSGISPROC glTexImage4DSGIS;
extern PFNGLTEXSUBIMAGE4DSGISPROC glTexSubImage4DSGIS;
#endif /*GL_SGIS_texture4D*/

/******************************
* Extension: GL_SGIS_texture_border_clamp
******************************/

#define GL_CLAMP_TO_BORDER_SGIS 0x812D


/******************************
* Extension: GL_SGIS_texture_color_mask
******************************/

#define GL_TEXTURE_COLOR_WRITEMASK_SGIS 0x81EF


#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1

typedef void (GLE_FUNCPTR * PFNGLTEXTURECOLORMASKSGISPROC)(GLboolean , GLboolean , GLboolean , GLboolean );

extern PFNGLTEXTURECOLORMASKSGISPROC glTextureColorMaskSGIS;
#endif /*GL_SGIS_texture_color_mask*/

/******************************
* Extension: GL_SGIS_texture_edge_clamp
******************************/

#define GL_CLAMP_TO_EDGE_SGIS 0x812F


/******************************
* Extension: GL_SGIS_texture_filter4
******************************/

#define GL_FILTER4_SGIS 0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS 0x8147


#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1

typedef void (GLE_FUNCPTR * PFNGLGETTEXFILTERFUNCSGISPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXFILTERFUNCSGISPROC)(GLenum , GLenum , GLsizei , const GLfloat *);

extern PFNGLGETTEXFILTERFUNCSGISPROC glGetTexFilterFuncSGIS;
extern PFNGLTEXFILTERFUNCSGISPROC glTexFilterFuncSGIS;
#endif /*GL_SGIS_texture_filter4*/

/******************************
* Extension: GL_SGIS_texture_lod
******************************/

#define GL_TEXTURE_MIN_LOD_SGIS 0x813A
#define GL_TEXTURE_MAX_LOD_SGIS 0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS 0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS 0x813D


/******************************
* Extension: GL_SGIS_texture_select
******************************/

#define GL_DUAL_ALPHA4_SGIS 0x8110
#define GL_DUAL_ALPHA8_SGIS 0x8111
#define GL_DUAL_ALPHA12_SGIS 0x8112
#define GL_DUAL_ALPHA16_SGIS 0x8113
#define GL_DUAL_LUMINANCE4_SGIS 0x8114
#define GL_DUAL_LUMINANCE8_SGIS 0x8115
#define GL_DUAL_LUMINANCE12_SGIS 0x8116
#define GL_DUAL_LUMINANCE16_SGIS 0x8117
#define GL_DUAL_INTENSITY4_SGIS 0x8118
#define GL_DUAL_INTENSITY8_SGIS 0x8119
#define GL_DUAL_INTENSITY12_SGIS 0x811A
#define GL_DUAL_INTENSITY16_SGIS 0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS 0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS 0x811D
#define GL_QUAD_ALPHA4_SGIS 0x811E
#define GL_QUAD_ALPHA8_SGIS 0x811F
#define GL_QUAD_LUMINANCE4_SGIS 0x8120
#define GL_QUAD_LUMINANCE8_SGIS 0x8121
#define GL_QUAD_INTENSITY4_SGIS 0x8122
#define GL_QUAD_INTENSITY8_SGIS 0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS 0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS 0x8125


/******************************
* Extension: GL_SGIX_async
******************************/

#define GL_ASYNC_MARKER_SGIX 0x8329


#ifndef GL_SGIX_async
#define GL_SGIX_async 1

typedef void (GLE_FUNCPTR * PFNGLASYNCMARKERSGIXPROC)(GLuint );
typedef GLint (GLE_FUNCPTR * PFNGLFINISHASYNCSGIXPROC)(GLuint *);
typedef GLint (GLE_FUNCPTR * PFNGLPOLLASYNCSGIXPROC)(GLuint *);
typedef GLuint (GLE_FUNCPTR * PFNGLGENASYNCMARKERSSGIXPROC)(GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDELETEASYNCMARKERSSGIXPROC)(GLuint , GLsizei );
typedef GLboolean (GLE_FUNCPTR * PFNGLISASYNCMARKERSGIXPROC)(GLuint );

extern PFNGLASYNCMARKERSGIXPROC glAsyncMarkerSGIX;
extern PFNGLFINISHASYNCSGIXPROC glFinishAsyncSGIX;
extern PFNGLPOLLASYNCSGIXPROC glPollAsyncSGIX;
extern PFNGLGENASYNCMARKERSSGIXPROC glGenAsyncMarkersSGIX;
extern PFNGLDELETEASYNCMARKERSSGIXPROC glDeleteAsyncMarkersSGIX;
extern PFNGLISASYNCMARKERSGIXPROC glIsAsyncMarkerSGIX;
#endif /*GL_SGIX_async*/

/******************************
* Extension: GL_SGIX_async_histogram
******************************/

#define GL_ASYNC_HISTOGRAM_SGIX 0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX 0x832D


/******************************
* Extension: GL_SGIX_async_pixel
******************************/

#define GL_ASYNC_TEX_IMAGE_SGIX 0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX 0x835D
#define GL_ASYNC_READ_PIXELS_SGIX 0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX 0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX 0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX 0x8361


/******************************
* Extension: GL_SGIX_blend_alpha_minmax
******************************/

#define GL_ALPHA_MIN_SGIX 0x8320
#define GL_ALPHA_MAX_SGIX 0x8321


/******************************
* Extension: GL_SGIX_calligraphic_fragment
******************************/

#define GL_CALLIGRAPHIC_FRAGMENT_SGIX 0x8183


/******************************
* Extension: GL_SGIX_clipmap
******************************/

#define GL_LINEAR_CLIPMAP_LINEAR_SGIX 0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX 0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX 0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX 0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX 0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX 0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX 0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX 0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX 0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX 0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX 0x844F


/******************************
* Extension: GL_SGIX_convolution_accuracy
******************************/

#define GL_CONVOLUTION_HINT_SGIX 0x8316


/******************************
* Extension: GL_SGIX_depth_texture
******************************/

#define GL_DEPTH_COMPONENT16_SGIX 0x81A5
#define GL_DEPTH_COMPONENT24_SGIX 0x81A6
#define GL_DEPTH_COMPONENT32_SGIX 0x81A7


/******************************
* Extension: GL_SGIX_flush_raster
******************************/

#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1

typedef void (GLE_FUNCPTR * PFNGLFLUSHRASTERSGIXPROC)();

extern PFNGLFLUSHRASTERSGIXPROC glFlushRasterSGIX;
#endif /*GL_SGIX_flush_raster*/

/******************************
* Extension: GL_SGIX_fog_offset
******************************/

#define GL_FOG_OFFSET_SGIX 0x8198
#define GL_FOG_OFFSET_VALUE_SGIX 0x8199


/******************************
* Extension: GL_SGIX_fog_scale
******************************/

#define GL_FOG_SCALE_SGIX 0x81FC
#define GL_FOG_SCALE_VALUE_SGIX 0x81FD


/******************************
* Extension: GL_SGIX_fragment_lighting
******************************/

#define GL_FRAGMENT_LIGHTING_SGIX 0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX 0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX 0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX 0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX 0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX 0x8406
#define GL_LIGHT_ENV_MODE_SGIX 0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX 0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX 0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX 0x840B
#define GL_FRAGMENT_LIGHT0_SGIX 0x840C
#define GL_FRAGMENT_LIGHT1_SGIX 0x840D
#define GL_FRAGMENT_LIGHT2_SGIX 0x840E
#define GL_FRAGMENT_LIGHT3_SGIX 0x840F
#define GL_FRAGMENT_LIGHT4_SGIX 0x8410
#define GL_FRAGMENT_LIGHT5_SGIX 0x8411
#define GL_FRAGMENT_LIGHT6_SGIX 0x8412
#define GL_FRAGMENT_LIGHT7_SGIX 0x8413


#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1

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

extern PFNGLFRAGMENTCOLORMATERIALSGIXPROC glFragmentColorMaterialSGIX;
extern PFNGLFRAGMENTLIGHTFSGIXPROC glFragmentLightfSGIX;
extern PFNGLFRAGMENTLIGHTFVSGIXPROC glFragmentLightfvSGIX;
extern PFNGLFRAGMENTLIGHTISGIXPROC glFragmentLightiSGIX;
extern PFNGLFRAGMENTLIGHTIVSGIXPROC glFragmentLightivSGIX;
extern PFNGLFRAGMENTLIGHTMODELFSGIXPROC glFragmentLightModelfSGIX;
extern PFNGLFRAGMENTLIGHTMODELFVSGIXPROC glFragmentLightModelfvSGIX;
extern PFNGLFRAGMENTLIGHTMODELISGIXPROC glFragmentLightModeliSGIX;
extern PFNGLFRAGMENTLIGHTMODELIVSGIXPROC glFragmentLightModelivSGIX;
extern PFNGLFRAGMENTMATERIALFSGIXPROC glFragmentMaterialfSGIX;
extern PFNGLFRAGMENTMATERIALFVSGIXPROC glFragmentMaterialfvSGIX;
extern PFNGLFRAGMENTMATERIALISGIXPROC glFragmentMaterialiSGIX;
extern PFNGLFRAGMENTMATERIALIVSGIXPROC glFragmentMaterialivSGIX;
extern PFNGLGETFRAGMENTLIGHTFVSGIXPROC glGetFragmentLightfvSGIX;
extern PFNGLGETFRAGMENTLIGHTIVSGIXPROC glGetFragmentLightivSGIX;
extern PFNGLGETFRAGMENTMATERIALFVSGIXPROC glGetFragmentMaterialfvSGIX;
extern PFNGLGETFRAGMENTMATERIALIVSGIXPROC glGetFragmentMaterialivSGIX;
extern PFNGLLIGHTENVISGIXPROC glLightEnviSGIX;
#endif /*GL_SGIX_fragment_lighting*/

/******************************
* Extension: GL_SGIX_framezoom
******************************/

#define GL_FRAMEZOOM_SGIX 0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX 0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX 0x818D


#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1

typedef void (GLE_FUNCPTR * PFNGLFRAMEZOOMSGIXPROC)(GLint );

extern PFNGLFRAMEZOOMSGIXPROC glFrameZoomSGIX;
#endif /*GL_SGIX_framezoom*/

/******************************
* Extension: GL_SGIX_impact_pixel_texture
******************************/

#define GL_PIXEL_TEX_GEN_Q_CEILING_SGIX 0x8184
#define GL_PIXEL_TEX_GEN_Q_ROUND_SGIX 0x8185
#define GL_PIXEL_TEX_GEN_Q_FLOOR_SGIX 0x8186
#define GL_PIXEL_TEX_GEN_ALPHA_REPLACE_SGIX 0x8187
#define GL_PIXEL_TEX_GEN_ALPHA_NO_REPLACE_SGIX 0x8188
#define GL_PIXEL_TEX_GEN_ALPHA_LS_SGIX 0x8189
#define GL_PIXEL_TEX_GEN_ALPHA_MS_SGIX 0x818A


/******************************
* Extension: GL_SGIX_instruments
******************************/

#define GL_INSTRUMENT_BUFFER_POINTER_SGIX 0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX 0x8181


#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1

typedef GLint (GLE_FUNCPTR * PFNGLGETINSTRUMENTSSGIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLINSTRUMENTSBUFFERSGIXPROC)(GLsizei , GLint *);
typedef GLint (GLE_FUNCPTR * PFNGLPOLLINSTRUMENTSSGIXPROC)(GLint *);
typedef void (GLE_FUNCPTR * PFNGLREADINSTRUMENTSSGIXPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLSTARTINSTRUMENTSSGIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLSTOPINSTRUMENTSSGIXPROC)(GLint );

extern PFNGLGETINSTRUMENTSSGIXPROC glGetInstrumentsSGIX;
extern PFNGLINSTRUMENTSBUFFERSGIXPROC glInstrumentsBufferSGIX;
extern PFNGLPOLLINSTRUMENTSSGIXPROC glPollInstrumentsSGIX;
extern PFNGLREADINSTRUMENTSSGIXPROC glReadInstrumentsSGIX;
extern PFNGLSTARTINSTRUMENTSSGIXPROC glStartInstrumentsSGIX;
extern PFNGLSTOPINSTRUMENTSSGIXPROC glStopInstrumentsSGIX;
#endif /*GL_SGIX_instruments*/

/******************************
* Extension: GL_SGIX_interlace
******************************/

#define GL_INTERLACE_SGIX 0x8094


/******************************
* Extension: GL_SGIX_ir_instrument1
******************************/

#define GL_IR_INSTRUMENT1_SGIX 0x817F


/******************************
* Extension: GL_SGIX_list_priority
******************************/

#define GL_LIST_PRIORITY_SGIX 0x8182


#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1

typedef void (GLE_FUNCPTR * PFNGLGETLISTPARAMETERFVSGIXPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETLISTPARAMETERIVSGIXPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERFSGIXPROC)(GLuint , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERFVSGIXPROC)(GLuint , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERISGIXPROC)(GLuint , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLLISTPARAMETERIVSGIXPROC)(GLuint , GLenum , const GLint *);

extern PFNGLGETLISTPARAMETERFVSGIXPROC glGetListParameterfvSGIX;
extern PFNGLGETLISTPARAMETERIVSGIXPROC glGetListParameterivSGIX;
extern PFNGLLISTPARAMETERFSGIXPROC glListParameterfSGIX;
extern PFNGLLISTPARAMETERFVSGIXPROC glListParameterfvSGIX;
extern PFNGLLISTPARAMETERISGIXPROC glListParameteriSGIX;
extern PFNGLLISTPARAMETERIVSGIXPROC glListParameterivSGIX;
#endif /*GL_SGIX_list_priority*/

/******************************
* Extension: GL_SGIX_pixel_texture
******************************/

#define GL_PIXEL_TEX_GEN_SGIX 0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX 0x832B


#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1

typedef void (GLE_FUNCPTR * PFNGLPIXELTEXGENSGIXPROC)(GLenum );

extern PFNGLPIXELTEXGENSGIXPROC glPixelTexGenSGIX;
#endif /*GL_SGIX_pixel_texture*/

/******************************
* Extension: GL_SGIX_pixel_tiles
******************************/

#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX 0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX 0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX 0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX 0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX 0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX 0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX 0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX 0x8145


/******************************
* Extension: GL_SGIX_polynomial_ffd
******************************/

#define GL_GEOMETRY_DEFORMATION_SGIX 0x8194
#define GL_TEXTURE_DEFORMATION_SGIX 0x8195
#define GL_DEFORMATIONS_MASK_SGIX 0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX 0x8197


#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1

typedef void (GLE_FUNCPTR * PFNGLDEFORMATIONMAP3DSGIXPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLDEFORMATIONMAP3FSGIXPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLDEFORMSGIXPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)(GLbitfield );

extern PFNGLDEFORMATIONMAP3DSGIXPROC glDeformationMap3dSGIX;
extern PFNGLDEFORMATIONMAP3FSGIXPROC glDeformationMap3fSGIX;
extern PFNGLDEFORMSGIXPROC glDeformSGIX;
extern PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC glLoadIdentityDeformationMapSGIX;
#endif /*GL_SGIX_polynomial_ffd*/

/******************************
* Extension: GL_SGIX_reference_plane
******************************/

#define GL_REFERENCE_PLANE_SGIX 0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX 0x817E


#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1

typedef void (GLE_FUNCPTR * PFNGLREFERENCEPLANESGIXPROC)(const GLdouble *);

extern PFNGLREFERENCEPLANESGIXPROC glReferencePlaneSGIX;
#endif /*GL_SGIX_reference_plane*/

/******************************
* Extension: GL_SGIX_resample
******************************/

#define GL_PACK_RESAMPLE_SGIX 0x842C
#define GL_UNPACK_RESAMPLE_SGIX 0x842D
#define GL_RESAMPLE_REPLICATE_SGIX 0x842E
#define GL_RESAMPLE_ZERO_FILL_SGIX 0x842F
#define GL_RESAMPLE_DECIMATE_SGIX 0x8430


/******************************
* Extension: GL_SGIX_scalebias_hint
******************************/

#define GL_SCALEBIAS_HINT_SGIX 0x8322


/******************************
* Extension: GL_SGIX_shadow
******************************/

#define GL_TEXTURE_COMPARE_SGIX 0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX 0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX 0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX 0x819D


/******************************
* Extension: GL_SGIX_shadow_ambient
******************************/

#define GL_SHADOW_AMBIENT_SGIX 0x80BF


/******************************
* Extension: GL_SGIX_sprite
******************************/

#define GL_SPRITE_SGIX 0x8148
#define GL_SPRITE_MODE_SGIX 0x8149
#define GL_SPRITE_AXIS_SGIX 0x814A
#define GL_SPRITE_TRANSLATION_SGIX 0x814B
#define GL_SPRITE_AXIAL_SGIX 0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX 0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX 0x814E


#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1

typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERFSGIXPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERFVSGIXPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERISGIXPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLSPRITEPARAMETERIVSGIXPROC)(GLenum , const GLint *);

extern PFNGLSPRITEPARAMETERFSGIXPROC glSpriteParameterfSGIX;
extern PFNGLSPRITEPARAMETERFVSGIXPROC glSpriteParameterfvSGIX;
extern PFNGLSPRITEPARAMETERISGIXPROC glSpriteParameteriSGIX;
extern PFNGLSPRITEPARAMETERIVSGIXPROC glSpriteParameterivSGIX;
#endif /*GL_SGIX_sprite*/

/******************************
* Extension: GL_SGIX_subsample
******************************/

#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4


/******************************
* Extension: GL_SGIX_tag_sample_buffer
******************************/

#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1

typedef void (GLE_FUNCPTR * PFNGLTAGSAMPLEBUFFERSGIXPROC)();

extern PFNGLTAGSAMPLEBUFFERSGIXPROC glTagSampleBufferSGIX;
#endif /*GL_SGIX_tag_sample_buffer*/

/******************************
* Extension: GL_SGIX_texture_add_env
******************************/

#define GL_TEXTURE_ENV_BIAS_SGIX 0x80BE


/******************************
* Extension: GL_SGIX_texture_coordinate_clamp
******************************/

#define GL_TEXTURE_MAX_CLAMP_S_SGIX 0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX 0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX 0x836B


/******************************
* Extension: GL_SGIX_texture_lod_bias
******************************/

#define GL_TEXTURE_LOD_BIAS_S_SGIX 0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX 0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX 0x8190


/******************************
* Extension: GL_SGIX_texture_multi_buffer
******************************/

#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX 0x812E


/******************************
* Extension: GL_SGIX_texture_scale_bias
******************************/

#define GL_POST_TEXTURE_FILTER_BIAS_SGIX 0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX 0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX 0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX 0x817C


/******************************
* Extension: GL_SGIX_vertex_preclip
******************************/

#define GL_VERTEX_PRECLIP_SGIX 0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX 0x83EF


/******************************
* Extension: GL_SGIX_ycrcb
******************************/

#define GL_YCRCB_422_SGIX 0x81BB
#define GL_YCRCB_444_SGIX 0x81BC


/******************************
* Extension: GL_SGIX_ycrcb_subsample
******************************/

#define GL_PACK_SUBSAMPLE_RATE_SGIX 0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX 0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX 0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX 0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX 0x85A4


/******************************
* Extension: GL_SGIX_ycrcba
******************************/

#define GL_YCRCB_SGIX 0x8318
#define GL_YCRCBA_SGIX 0x8319


/******************************
* Extension: GL_SGI_color_matrix
******************************/

#define GL_COLOR_MATRIX_SGI 0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI 0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI 0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI 0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI 0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI 0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI 0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI 0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI 0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI 0x80BB


/******************************
* Extension: GL_SGI_color_table
******************************/

#define GL_COLOR_TABLE_SGI 0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D2
#define GL_PROXY_COLOR_TABLE_SGI 0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI 0x80D5
#define GL_COLOR_TABLE_SCALE_SGI 0x80D6
#define GL_COLOR_TABLE_BIAS_SGI 0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI 0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI 0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI 0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI 0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI 0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI 0x80DF


#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1

typedef void (GLE_FUNCPTR * PFNGLCOLORTABLESGIPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVSGIPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVSGIPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORTABLESGIPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLESGIPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)(GLenum , GLenum , GLint *);

extern PFNGLCOLORTABLESGIPROC glColorTableSGI;
extern PFNGLCOLORTABLEPARAMETERFVSGIPROC glColorTableParameterfvSGI;
extern PFNGLCOLORTABLEPARAMETERIVSGIPROC glColorTableParameterivSGI;
extern PFNGLCOPYCOLORTABLESGIPROC glCopyColorTableSGI;
extern PFNGLGETCOLORTABLESGIPROC glGetColorTableSGI;
extern PFNGLGETCOLORTABLEPARAMETERFVSGIPROC glGetColorTableParameterfvSGI;
extern PFNGLGETCOLORTABLEPARAMETERIVSGIPROC glGetColorTableParameterivSGI;
#endif /*GL_SGI_color_table*/

/******************************
* Extension: GL_SGI_depth_pass_instrument
******************************/

#define GL_DEPTH_PASS_INSTRUMENT_SGIX 0x8310
#define GL_DEPTH_PASS_INSTRUMENT_COUNTERS_SGIX 0x8311
#define GL_DEPTH_PASS_INSTRUMENT_MAX_SGIX 0x8312


/******************************
* Extension: GL_SGI_texture_color_table
******************************/

#define GL_TEXTURE_COLOR_TABLE_SGI 0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI 0x80BD


/******************************
* Extension: GL_SUNX_constant_data
******************************/

#define GL_UNPACK_CONSTANT_DATA_SUNX 0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX 0x81D6


#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1

typedef void (GLE_FUNCPTR * PFNGLFINISHTEXTURESUNXPROC)();

extern PFNGLFINISHTEXTURESUNXPROC glFinishTextureSUNX;
#endif /*GL_SUNX_constant_data*/

/******************************
* Extension: GL_SUN_convolution_border_modes
******************************/

#define GL_WRAP_BORDER_SUN 0x81D4


/******************************
* Extension: GL_SUN_global_alpha
******************************/

#define GL_GLOBAL_ALPHA_SUN 0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN 0x81DA


#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1

typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORBSUNPROC)(GLbyte );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORSSUNPROC)(GLshort );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORISUNPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORFSUNPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORDSUNPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUBSUNPROC)(GLubyte );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUSSUNPROC)(GLushort );
typedef void (GLE_FUNCPTR * PFNGLGLOBALALPHAFACTORUISUNPROC)(GLuint );

extern PFNGLGLOBALALPHAFACTORBSUNPROC glGlobalAlphaFactorbSUN;
extern PFNGLGLOBALALPHAFACTORSSUNPROC glGlobalAlphaFactorsSUN;
extern PFNGLGLOBALALPHAFACTORISUNPROC glGlobalAlphaFactoriSUN;
extern PFNGLGLOBALALPHAFACTORFSUNPROC glGlobalAlphaFactorfSUN;
extern PFNGLGLOBALALPHAFACTORDSUNPROC glGlobalAlphaFactordSUN;
extern PFNGLGLOBALALPHAFACTORUBSUNPROC glGlobalAlphaFactorubSUN;
extern PFNGLGLOBALALPHAFACTORUSSUNPROC glGlobalAlphaFactorusSUN;
extern PFNGLGLOBALALPHAFACTORUISUNPROC glGlobalAlphaFactoruiSUN;
#endif /*GL_SUN_global_alpha*/

/******************************
* Extension: GL_SUN_mesh_array
******************************/

#define GL_QUAD_MESH_SUN 0x8614
#define GL_TRIANGLE_MESH_SUN 0x8615


#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1

typedef void (GLE_FUNCPTR * PFNGLDRAWMESHARRAYSSUNPROC)(GLenum , GLint , GLsizei , GLsizei );

extern PFNGLDRAWMESHARRAYSSUNPROC glDrawMeshArraysSUN;
#endif /*GL_SUN_mesh_array*/

/******************************
* Extension: GL_SUN_slice_accum
******************************/

#define GL_SLICE_ACCUM_SUN 0x85CC


/******************************
* Extension: GL_SUN_triangle_list
******************************/

#define GL_RESTART_SUN 0x0001
#define GL_REPLACE_MIDDLE_SUN 0x0002
#define GL_REPLACE_OLDEST_SUN 0x0003
#define GL_TRIANGLE_LIST_SUN 0x81D7
#define GL_REPLACEMENT_CODE_SUN 0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN 0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN 0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN 0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN 0x85C3
#define GL_R1UI_V3F_SUN 0x85C4
#define GL_R1UI_C4UB_V3F_SUN 0x85C5
#define GL_R1UI_C3F_V3F_SUN 0x85C6
#define GL_R1UI_N3F_V3F_SUN 0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN 0x85C8
#define GL_R1UI_T2F_V3F_SUN 0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN 0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN 0x85CB


#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1

typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUISUNPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUSSUNPROC)(GLushort );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUBSUNPROC)(GLubyte );
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUIVSUNPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUSVSUNPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEUBVSUNPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLREPLACEMENTCODEPOINTERSUNPROC)(GLenum , GLsizei , const GLvoid* *);

extern PFNGLREPLACEMENTCODEUISUNPROC glReplacementCodeuiSUN;
extern PFNGLREPLACEMENTCODEUSSUNPROC glReplacementCodeusSUN;
extern PFNGLREPLACEMENTCODEUBSUNPROC glReplacementCodeubSUN;
extern PFNGLREPLACEMENTCODEUIVSUNPROC glReplacementCodeuivSUN;
extern PFNGLREPLACEMENTCODEUSVSUNPROC glReplacementCodeusvSUN;
extern PFNGLREPLACEMENTCODEUBVSUNPROC glReplacementCodeubvSUN;
extern PFNGLREPLACEMENTCODEPOINTERSUNPROC glReplacementCodePointerSUN;
#endif /*GL_SUN_triangle_list*/

/******************************
* Extension: GL_SUN_vertex
******************************/

#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1

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

extern PFNGLCOLOR4UBVERTEX2FSUNPROC glColor4ubVertex2fSUN;
extern PFNGLCOLOR4UBVERTEX2FVSUNPROC glColor4ubVertex2fvSUN;
extern PFNGLCOLOR4UBVERTEX3FSUNPROC glColor4ubVertex3fSUN;
extern PFNGLCOLOR4UBVERTEX3FVSUNPROC glColor4ubVertex3fvSUN;
extern PFNGLCOLOR3FVERTEX3FSUNPROC glColor3fVertex3fSUN;
extern PFNGLCOLOR3FVERTEX3FVSUNPROC glColor3fVertex3fvSUN;
extern PFNGLNORMAL3FVERTEX3FSUNPROC glNormal3fVertex3fSUN;
extern PFNGLNORMAL3FVERTEX3FVSUNPROC glNormal3fVertex3fvSUN;
extern PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC glColor4fNormal3fVertex3fSUN;
extern PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC glColor4fNormal3fVertex3fvSUN;
extern PFNGLTEXCOORD2FVERTEX3FSUNPROC glTexCoord2fVertex3fSUN;
extern PFNGLTEXCOORD2FVERTEX3FVSUNPROC glTexCoord2fVertex3fvSUN;
extern PFNGLTEXCOORD4FVERTEX4FSUNPROC glTexCoord4fVertex4fSUN;
extern PFNGLTEXCOORD4FVERTEX4FVSUNPROC glTexCoord4fVertex4fvSUN;
extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC glTexCoord2fColor4ubVertex3fSUN;
extern PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC glTexCoord2fColor4ubVertex3fvSUN;
extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC glTexCoord2fColor3fVertex3fSUN;
extern PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC glTexCoord2fColor3fVertex3fvSUN;
extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC glTexCoord2fNormal3fVertex3fSUN;
extern PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fNormal3fVertex3fvSUN;
extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glTexCoord2fColor4fNormal3fVertex3fSUN;
extern PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glTexCoord2fColor4fNormal3fVertex3fvSUN;
extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC glTexCoord4fColor4fNormal3fVertex4fSUN;
extern PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC glTexCoord4fColor4fNormal3fVertex4fvSUN;
extern PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC glReplacementCodeuiVertex3fSUN;
extern PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC glReplacementCodeuiVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC glReplacementCodeuiColor4ubVertex3fSUN;
extern PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC glReplacementCodeuiColor4ubVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC glReplacementCodeuiColor3fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC glReplacementCodeuiColor3fVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC glReplacementCodeuiNormal3fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiNormal3fVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiColor4fNormal3fVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN;
extern PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN;
#endif /*GL_SUN_vertex*/

/******************************
* Extension: GL_WIN_phong_shading
******************************/

#define GL_PHONG_WIN 0x80EA
#define GL_PHONG_HINT_WIN 0x80EB


/******************************
* Extension: GL_WIN_specular_fog
******************************/

#define GL_FOG_SPECULAR_TEXTURE_WIN 0x80EC


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_EXTS_H

