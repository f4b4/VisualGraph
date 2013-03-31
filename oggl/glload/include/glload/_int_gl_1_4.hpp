#ifndef _INT_GL_1_4_HPP
#define _INT_GL_1_4_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleBlendFuncSeparate)(GLenum , GLenum , GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleMultiDrawArrays)(GLenum , const GLint *, const GLsizei *, GLsizei );
extern void (GLE_FUNCPTR *__gleMultiDrawElements)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei );
extern void (GLE_FUNCPTR *__glePointParameterf)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__glePointParameterfv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__glePointParameteri)(GLenum , GLint );
extern void (GLE_FUNCPTR *__glePointParameteriv)(GLenum , const GLint *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_4
	{
		GL_BLEND_DST_RGB                 = 0x80C8,
		GL_BLEND_SRC_RGB                 = 0x80C9,
		GL_BLEND_DST_ALPHA               = 0x80CA,
		GL_BLEND_SRC_ALPHA               = 0x80CB,
		GL_POINT_FADE_THRESHOLD_SIZE     = 0x8128,
		GL_DEPTH_COMPONENT16             = 0x81A5,
		GL_DEPTH_COMPONENT24             = 0x81A6,
		GL_DEPTH_COMPONENT32             = 0x81A7,
		GL_MIRRORED_REPEAT               = 0x8370,
		GL_MAX_TEXTURE_LOD_BIAS          = 0x84FD,
		GL_TEXTURE_LOD_BIAS              = 0x8501,
		GL_INCR_WRAP                     = 0x8507,
		GL_DECR_WRAP                     = 0x8508,
		GL_TEXTURE_DEPTH_SIZE            = 0x884A,
		GL_TEXTURE_COMPARE_MODE          = 0x884C,
		GL_TEXTURE_COMPARE_FUNC          = 0x884D,
	};

	inline void BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) { ::__gleBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha); }
	inline void MultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) { ::__gleMultiDrawArrays(mode, first, count, drawcount); }
	inline void MultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount) { ::__gleMultiDrawElements(mode, count, type, indices, drawcount); }
	inline void PointParameterf(GLenum pname, GLfloat param) { ::__glePointParameterf(pname, param); }
	inline void PointParameterfv(GLenum pname, const GLfloat *params) { ::__glePointParameterfv(pname, params); }
	inline void PointParameteri(GLenum pname, GLint param) { ::__glePointParameteri(pname, param); }
	inline void PointParameteriv(GLenum pname, const GLint *params) { ::__glePointParameteriv(pname, params); }

}

#endif //_INT_GL_1_4_HPP

