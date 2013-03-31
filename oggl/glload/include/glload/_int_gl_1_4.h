#ifndef _INT_GL_1_4_H
#define _INT_GL_1_4_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEPROC)(GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWARRAYSPROC)(GLenum , const GLint *, const GLsizei *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLMULTIDRAWELEMENTSPROC)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERFVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPOINTPARAMETERIVPROC)(GLenum , const GLint *);

extern PFNGLBLENDFUNCSEPARATEPROC __gleBlendFuncSeparate;
#define glBlendFuncSeparate __gleBlendFuncSeparate
extern PFNGLMULTIDRAWARRAYSPROC __gleMultiDrawArrays;
#define glMultiDrawArrays __gleMultiDrawArrays
extern PFNGLMULTIDRAWELEMENTSPROC __gleMultiDrawElements;
#define glMultiDrawElements __gleMultiDrawElements
extern PFNGLPOINTPARAMETERFPROC __glePointParameterf;
#define glPointParameterf __glePointParameterf
extern PFNGLPOINTPARAMETERFVPROC __glePointParameterfv;
#define glPointParameterfv __glePointParameterfv
extern PFNGLPOINTPARAMETERIPROC __glePointParameteri;
#define glPointParameteri __glePointParameteri
extern PFNGLPOINTPARAMETERIVPROC __glePointParameteriv;
#define glPointParameteriv __glePointParameteriv


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_4_H

