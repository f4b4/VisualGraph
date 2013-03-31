#ifndef _INT_GL_1_2_HPP
#define _INT_GL_1_2_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleBlendColor)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleBlendEquation)(GLenum );
extern void (GLE_FUNCPTR *__gleDrawRangeElements)(GLenum , GLuint , GLuint , GLsizei , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleTexSubImage3D)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCopyTexSubImage3D)(GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_2
	{
		GL_UNSIGNED_BYTE_3_3_2           = 0x8032,
		GL_UNSIGNED_SHORT_4_4_4_4        = 0x8033,
		GL_UNSIGNED_SHORT_5_5_5_1        = 0x8034,
		GL_UNSIGNED_INT_8_8_8_8          = 0x8035,
		GL_UNSIGNED_INT_10_10_10_2       = 0x8036,
		GL_TEXTURE_BINDING_3D            = 0x806A,
		GL_PACK_SKIP_IMAGES              = 0x806B,
		GL_PACK_IMAGE_HEIGHT             = 0x806C,
		GL_UNPACK_SKIP_IMAGES            = 0x806D,
		GL_UNPACK_IMAGE_HEIGHT           = 0x806E,
		GL_PROXY_TEXTURE_3D              = 0x8070,
		GL_TEXTURE_DEPTH                 = 0x8071,
		GL_TEXTURE_WRAP_R                = 0x8072,
		GL_MAX_3D_TEXTURE_SIZE           = 0x8073,
		GL_UNSIGNED_BYTE_2_3_3_REV       = 0x8362,
		GL_UNSIGNED_SHORT_5_6_5          = 0x8363,
		GL_UNSIGNED_SHORT_5_6_5_REV      = 0x8364,
		GL_UNSIGNED_SHORT_4_4_4_4_REV    = 0x8365,
		GL_UNSIGNED_SHORT_1_5_5_5_REV    = 0x8366,
		GL_UNSIGNED_INT_8_8_8_8_REV      = 0x8367,
		GL_BGR                           = 0x80E0,
		GL_MAX_ELEMENTS_VERTICES         = 0x80E8,
		GL_MAX_ELEMENTS_INDICES          = 0x80E9,
		GL_CLAMP_TO_EDGE                 = 0x812F,
		GL_TEXTURE_MIN_LOD               = 0x813A,
		GL_TEXTURE_MAX_LOD               = 0x813B,
		GL_TEXTURE_BASE_LEVEL            = 0x813C,
		GL_TEXTURE_MAX_LEVEL             = 0x813D,
		GL_SMOOTH_POINT_SIZE_RANGE       = 0x0B12,
		GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13,
		GL_SMOOTH_LINE_WIDTH_RANGE       = 0x0B22,
		GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23,
		GL_ALIASED_LINE_WIDTH_RANGE      = 0x846E,
	};

	inline void BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { ::__gleBlendColor(red, green, blue, alpha); }
	inline void BlendEquation(GLenum mode) { ::__gleBlendEquation(mode); }
	inline void DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices) { ::__gleDrawRangeElements(mode, start, end, count, type, indices); }
	inline void TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels); }
	inline void CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) { ::__gleCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height); }

}

#endif //_INT_GL_1_2_HPP

