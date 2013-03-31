#ifndef _INT_GL_3_3_H
#define _INT_GL_3_3_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBDIVISORPROC)(GLuint , GLuint );

extern PFNGLVERTEXATTRIBDIVISORPROC __gleVertexAttribDivisor;
#define glVertexAttribDivisor __gleVertexAttribDivisor


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_3_3_H

