#ifndef _INT_GL_1_5_HPP
#define _INT_GL_1_5_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleGenQueries)(GLsizei , GLuint *);
extern void (GLE_FUNCPTR *__gleDeleteQueries)(GLsizei , const GLuint *);
extern GLboolean (GLE_FUNCPTR *__gleIsQuery)(GLuint );
extern void (GLE_FUNCPTR *__gleBeginQuery)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleEndQuery)(GLenum );
extern void (GLE_FUNCPTR *__gleGetQueryiv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetQueryObjectiv)(GLuint , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetQueryObjectuiv)(GLuint , GLenum , GLuint *);
extern void (GLE_FUNCPTR *__gleBindBuffer)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleDeleteBuffers)(GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleGenBuffers)(GLsizei , GLuint *);
extern GLboolean (GLE_FUNCPTR *__gleIsBuffer)(GLuint );
extern void (GLE_FUNCPTR *__gleBufferData)(GLenum , GLsizeiptr , const GLvoid *, GLenum );
extern void (GLE_FUNCPTR *__gleBufferSubData)(GLenum , GLintptr , GLsizeiptr , const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetBufferSubData)(GLenum , GLintptr , GLsizeiptr , GLvoid *);
extern GLvoid* (GLE_FUNCPTR *__gleMapBuffer)(GLenum , GLenum );
extern GLboolean (GLE_FUNCPTR *__gleUnmapBuffer)(GLenum );
extern void (GLE_FUNCPTR *__gleGetBufferParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetBufferPointerv)(GLenum , GLenum , GLvoid* *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_5
	{
		GL_BUFFER_SIZE                   = 0x8764,
		GL_BUFFER_USAGE                  = 0x8765,
		GL_QUERY_COUNTER_BITS            = 0x8864,
		GL_CURRENT_QUERY                 = 0x8865,
		GL_QUERY_RESULT                  = 0x8866,
		GL_QUERY_RESULT_AVAILABLE        = 0x8867,
		GL_ARRAY_BUFFER                  = 0x8892,
		GL_ELEMENT_ARRAY_BUFFER          = 0x8893,
		GL_ARRAY_BUFFER_BINDING          = 0x8894,
		GL_ELEMENT_ARRAY_BUFFER_BINDING  = 0x8895,
		GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		GL_READ_ONLY                     = 0x88B8,
		GL_BUFFER_ACCESS                 = 0x88BB,
		GL_BUFFER_MAPPED                 = 0x88BC,
		GL_BUFFER_MAP_POINTER            = 0x88BD,
		GL_STREAM_DRAW                   = 0x88E0,
		GL_STREAM_READ                   = 0x88E1,
		GL_STREAM_COPY                   = 0x88E2,
		GL_STATIC_DRAW                   = 0x88E4,
		GL_STATIC_READ                   = 0x88E5,
		GL_STATIC_COPY                   = 0x88E6,
		GL_DYNAMIC_DRAW                  = 0x88E8,
		GL_DYNAMIC_READ                  = 0x88E9,
		GL_DYNAMIC_COPY                  = 0x88EA,
		GL_SAMPLES_PASSED                = 0x8914,
	};

	inline void GenQueries(GLsizei n, GLuint *ids) { ::__gleGenQueries(n, ids); }
	inline void DeleteQueries(GLsizei n, const GLuint *ids) { ::__gleDeleteQueries(n, ids); }
	inline GLboolean IsQuery(GLuint id) { return ::__gleIsQuery(id); }
	inline void BeginQuery(GLenum target, GLuint id) { ::__gleBeginQuery(target, id); }
	inline void EndQuery(GLenum target) { ::__gleEndQuery(target); }
	inline void GetQueryiv(GLenum target, GLenum pname, GLint *params) { ::__gleGetQueryiv(target, pname, params); }
	inline void GetQueryObjectiv(GLuint id, GLenum pname, GLint *params) { ::__gleGetQueryObjectiv(id, pname, params); }
	inline void GetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params) { ::__gleGetQueryObjectuiv(id, pname, params); }
	inline void BindBuffer(GLenum target, GLuint buffer) { ::__gleBindBuffer(target, buffer); }
	inline void DeleteBuffers(GLsizei n, const GLuint *buffers) { ::__gleDeleteBuffers(n, buffers); }
	inline void GenBuffers(GLsizei n, GLuint *buffers) { ::__gleGenBuffers(n, buffers); }
	inline GLboolean IsBuffer(GLuint buffer) { return ::__gleIsBuffer(buffer); }
	inline void BufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage) { ::__gleBufferData(target, size, data, usage); }
	inline void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data) { ::__gleBufferSubData(target, offset, size, data); }
	inline void GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data) { ::__gleGetBufferSubData(target, offset, size, data); }
	inline GLvoid* MapBuffer(GLenum target, GLenum access) { return ::__gleMapBuffer(target, access); }
	inline GLboolean UnmapBuffer(GLenum target) { return ::__gleUnmapBuffer(target); }
	inline void GetBufferParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetBufferParameteriv(target, pname, params); }
	inline void GetBufferPointerv(GLenum target, GLenum pname, GLvoid* *params) { ::__gleGetBufferPointerv(target, pname, params); }

}

#endif //_INT_GL_1_5_HPP

