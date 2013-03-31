#ifndef _INT_GL_1_2_H
#define _INT_GL_1_2_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_BGR 0x80E0
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
typedef void (GLE_FUNCPTR * PFNGLBLENDCOLORPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLDRAWRANGEELEMENTSPROC)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );

extern PFNGLBLENDCOLORPROC __gleBlendColor;
#define glBlendColor __gleBlendColor
extern PFNGLBLENDEQUATIONPROC __gleBlendEquation;
#define glBlendEquation __gleBlendEquation
extern PFNGLDRAWRANGEELEMENTSPROC __gleDrawRangeElements;
#define glDrawRangeElements __gleDrawRangeElements
extern PFNGLTEXSUBIMAGE3DPROC __gleTexSubImage3D;
#define glTexSubImage3D __gleTexSubImage3D
extern PFNGLCOPYTEXSUBIMAGE3DPROC __gleCopyTexSubImage3D;
#define glCopyTexSubImage3D __gleCopyTexSubImage3D


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_2_H

