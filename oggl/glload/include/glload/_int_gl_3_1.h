#ifndef _INT_GL_3_1_H
#define _INT_GL_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT 0x8C2E
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXBUFFERPROC)(GLenum , GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint );

extern PFNGLDRAWARRAYSINSTANCEDPROC __gleDrawArraysInstanced;
#define glDrawArraysInstanced __gleDrawArraysInstanced
extern PFNGLDRAWELEMENTSINSTANCEDPROC __gleDrawElementsInstanced;
#define glDrawElementsInstanced __gleDrawElementsInstanced
extern PFNGLTEXBUFFERPROC __gleTexBuffer;
#define glTexBuffer __gleTexBuffer
extern PFNGLPRIMITIVERESTARTINDEXPROC __glePrimitiveRestartIndex;
#define glPrimitiveRestartIndex __glePrimitiveRestartIndex


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_3_1_H

