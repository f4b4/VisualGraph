#ifndef _INT_GL_4_0_HPP
#define _INT_GL_4_0_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleMinSampleShading)(GLfloat );
extern void (GLE_FUNCPTR *__gleBlendEquationi)(GLuint , GLenum );
extern void (GLE_FUNCPTR *__gleBlendEquationSeparatei)(GLuint , GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleBlendFunci)(GLuint , GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleBlendFuncSeparatei)(GLuint , GLenum , GLenum , GLenum , GLenum );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_4_0
	{
		GL_SAMPLE_SHADING                = 0x8C36,
		GL_MIN_SAMPLE_SHADING_VALUE      = 0x8C37,
		GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E,
		GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F,
		GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS = 0x8F9F,
		GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A,
		GL_PROXY_TEXTURE_CUBE_MAP_ARRAY  = 0x900B,
		GL_SAMPLER_CUBE_MAP_ARRAY        = 0x900C,
		GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D,
		GL_INT_SAMPLER_CUBE_MAP_ARRAY    = 0x900E,
		GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F,
	};

	inline void MinSampleShading(GLfloat value) { ::__gleMinSampleShading(value); }
	inline void BlendEquationi(GLuint buf, GLenum mode) { ::__gleBlendEquationi(buf, mode); }
	inline void BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) { ::__gleBlendEquationSeparatei(buf, modeRGB, modeAlpha); }
	inline void BlendFunci(GLuint buf, GLenum src, GLenum dst) { ::__gleBlendFunci(buf, src, dst); }
	inline void BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) { ::__gleBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha); }

}

#endif //_INT_GL_4_0_HPP

