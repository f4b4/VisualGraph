#ifndef _INT_GL_1_5_H
#define _INT_GL_1_5_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914
typedef void (GLE_FUNCPTR * PFNGLGENQUERIESPROC)(GLsizei , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLDELETEQUERIESPROC)(GLsizei , const GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISQUERYPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINQUERYPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLENDQUERYPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETQUERYIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETQUERYOBJECTUIVPROC)(GLuint , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETEBUFFERSPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENBUFFERSPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISBUFFERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBUFFERDATAPROC)(GLenum , GLsizeiptr , const GLvoid *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLBUFFERSUBDATAPROC)(GLenum , GLintptr , GLsizeiptr , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERSUBDATAPROC)(GLenum , GLintptr , GLsizeiptr , GLvoid *);
typedef GLvoid* (GLE_FUNCPTR * PFNGLMAPBUFFERPROC)(GLenum , GLenum );
typedef GLboolean (GLE_FUNCPTR * PFNGLUNMAPBUFFERPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETBUFFERPOINTERVPROC)(GLenum , GLenum , GLvoid* *);

extern PFNGLGENQUERIESPROC __gleGenQueries;
#define glGenQueries __gleGenQueries
extern PFNGLDELETEQUERIESPROC __gleDeleteQueries;
#define glDeleteQueries __gleDeleteQueries
extern PFNGLISQUERYPROC __gleIsQuery;
#define glIsQuery __gleIsQuery
extern PFNGLBEGINQUERYPROC __gleBeginQuery;
#define glBeginQuery __gleBeginQuery
extern PFNGLENDQUERYPROC __gleEndQuery;
#define glEndQuery __gleEndQuery
extern PFNGLGETQUERYIVPROC __gleGetQueryiv;
#define glGetQueryiv __gleGetQueryiv
extern PFNGLGETQUERYOBJECTIVPROC __gleGetQueryObjectiv;
#define glGetQueryObjectiv __gleGetQueryObjectiv
extern PFNGLGETQUERYOBJECTUIVPROC __gleGetQueryObjectuiv;
#define glGetQueryObjectuiv __gleGetQueryObjectuiv
extern PFNGLBINDBUFFERPROC __gleBindBuffer;
#define glBindBuffer __gleBindBuffer
extern PFNGLDELETEBUFFERSPROC __gleDeleteBuffers;
#define glDeleteBuffers __gleDeleteBuffers
extern PFNGLGENBUFFERSPROC __gleGenBuffers;
#define glGenBuffers __gleGenBuffers
extern PFNGLISBUFFERPROC __gleIsBuffer;
#define glIsBuffer __gleIsBuffer
extern PFNGLBUFFERDATAPROC __gleBufferData;
#define glBufferData __gleBufferData
extern PFNGLBUFFERSUBDATAPROC __gleBufferSubData;
#define glBufferSubData __gleBufferSubData
extern PFNGLGETBUFFERSUBDATAPROC __gleGetBufferSubData;
#define glGetBufferSubData __gleGetBufferSubData
extern PFNGLMAPBUFFERPROC __gleMapBuffer;
#define glMapBuffer __gleMapBuffer
extern PFNGLUNMAPBUFFERPROC __gleUnmapBuffer;
#define glUnmapBuffer __gleUnmapBuffer
extern PFNGLGETBUFFERPARAMETERIVPROC __gleGetBufferParameteriv;
#define glGetBufferParameteriv __gleGetBufferParameteriv
extern PFNGLGETBUFFERPOINTERVPROC __gleGetBufferPointerv;
#define glGetBufferPointerv __gleGetBufferPointerv


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_5_H

