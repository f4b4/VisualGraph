#ifndef _INT_GL_3_1_HPP
#define _INT_GL_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleDrawArraysInstanced)(GLenum , GLint , GLsizei , GLsizei );
extern void (GLE_FUNCPTR *__gleDrawElementsInstanced)(GLenum , GLsizei , GLenum , const GLvoid *, GLsizei );
extern void (GLE_FUNCPTR *__gleTexBuffer)(GLenum , GLenum , GLuint );
extern void (GLE_FUNCPTR *__glePrimitiveRestartIndex)(GLuint );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_3_1
	{
		GL_SAMPLER_2D_RECT               = 0x8B63,
		GL_SAMPLER_2D_RECT_SHADOW        = 0x8B64,
		GL_SAMPLER_BUFFER                = 0x8DC2,
		GL_INT_SAMPLER_2D_RECT           = 0x8DCD,
		GL_INT_SAMPLER_BUFFER            = 0x8DD0,
		GL_UNSIGNED_INT_SAMPLER_2D_RECT  = 0x8DD5,
		GL_UNSIGNED_INT_SAMPLER_BUFFER   = 0x8DD8,
		GL_MAX_TEXTURE_BUFFER_SIZE       = 0x8C2B,
		GL_TEXTURE_BINDING_BUFFER        = 0x8C2C,
		GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D,
		GL_TEXTURE_BUFFER_FORMAT         = 0x8C2E,
		GL_TEXTURE_BINDING_RECTANGLE     = 0x84F6,
		GL_PROXY_TEXTURE_RECTANGLE       = 0x84F7,
		GL_MAX_RECTANGLE_TEXTURE_SIZE    = 0x84F8,
		GL_PRIMITIVE_RESTART             = 0x8F9D,
		GL_PRIMITIVE_RESTART_INDEX       = 0x8F9E,
	};

	inline void DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) { ::__gleDrawArraysInstanced(mode, first, count, instancecount); }
	inline void DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount) { ::__gleDrawElementsInstanced(mode, count, type, indices, instancecount); }
	inline void TexBuffer(GLenum target, GLenum internalformat, GLuint buffer) { ::__gleTexBuffer(target, internalformat, buffer); }
	inline void PrimitiveRestartIndex(GLuint index) { ::__glePrimitiveRestartIndex(index); }

}

#endif //_INT_GL_3_1_HPP

