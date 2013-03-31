#ifndef _INT_GL_2_1_HPP
#define _INT_GL_2_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleUniformMatrix2x3fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix3x2fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix2x4fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix4x2fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix3x4fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix4x3fv)(GLint , GLsizei , GLboolean , const GLfloat *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_2_1
	{
		GL_PIXEL_PACK_BUFFER             = 0x88EB,
		GL_PIXEL_UNPACK_BUFFER           = 0x88EC,
		GL_PIXEL_PACK_BUFFER_BINDING     = 0x88ED,
		GL_PIXEL_UNPACK_BUFFER_BINDING   = 0x88EF,
		GL_FLOAT_MAT2x3                  = 0x8B65,
		GL_FLOAT_MAT2x4                  = 0x8B66,
		GL_FLOAT_MAT3x2                  = 0x8B67,
		GL_FLOAT_MAT3x4                  = 0x8B68,
		GL_FLOAT_MAT4x2                  = 0x8B69,
		GL_FLOAT_MAT4x3                  = 0x8B6A,
		GL_SRGB                          = 0x8C40,
		GL_SRGB8                         = 0x8C41,
		GL_SRGB_ALPHA                    = 0x8C42,
		GL_SRGB8_ALPHA8                  = 0x8C43,
		GL_COMPRESSED_SRGB               = 0x8C48,
		GL_COMPRESSED_SRGB_ALPHA         = 0x8C49,
	};

	inline void UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix2x3fv(location, count, transpose, value); }
	inline void UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix3x2fv(location, count, transpose, value); }
	inline void UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix2x4fv(location, count, transpose, value); }
	inline void UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix4x2fv(location, count, transpose, value); }
	inline void UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix3x4fv(location, count, transpose, value); }
	inline void UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix4x3fv(location, count, transpose, value); }

}

#endif //_INT_GL_2_1_HPP

