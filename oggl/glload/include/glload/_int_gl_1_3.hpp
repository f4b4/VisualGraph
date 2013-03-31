#ifndef _INT_GL_1_3_HPP
#define _INT_GL_1_3_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleActiveTexture)(GLenum );
extern void (GLE_FUNCPTR *__gleSampleCoverage)(GLfloat , GLboolean );
extern void (GLE_FUNCPTR *__gleCompressedTexImage3D)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCompressedTexImage2D)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCompressedTexImage1D)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCompressedTexSubImage3D)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCompressedTexSubImage2D)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCompressedTexSubImage1D)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetCompressedTexImage)(GLenum , GLint , GLvoid *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_3
	{
		GL_TEXTURE0                      = 0x84C0,
		GL_TEXTURE1                      = 0x84C1,
		GL_TEXTURE2                      = 0x84C2,
		GL_TEXTURE3                      = 0x84C3,
		GL_TEXTURE4                      = 0x84C4,
		GL_TEXTURE5                      = 0x84C5,
		GL_TEXTURE6                      = 0x84C6,
		GL_TEXTURE7                      = 0x84C7,
		GL_TEXTURE8                      = 0x84C8,
		GL_TEXTURE9                      = 0x84C9,
		GL_TEXTURE10                     = 0x84CA,
		GL_TEXTURE11                     = 0x84CB,
		GL_TEXTURE12                     = 0x84CC,
		GL_TEXTURE13                     = 0x84CD,
		GL_TEXTURE14                     = 0x84CE,
		GL_TEXTURE15                     = 0x84CF,
		GL_TEXTURE16                     = 0x84D0,
		GL_TEXTURE17                     = 0x84D1,
		GL_TEXTURE18                     = 0x84D2,
		GL_TEXTURE19                     = 0x84D3,
		GL_TEXTURE20                     = 0x84D4,
		GL_TEXTURE21                     = 0x84D5,
		GL_TEXTURE22                     = 0x84D6,
		GL_TEXTURE23                     = 0x84D7,
		GL_TEXTURE24                     = 0x84D8,
		GL_TEXTURE25                     = 0x84D9,
		GL_TEXTURE26                     = 0x84DA,
		GL_TEXTURE27                     = 0x84DB,
		GL_TEXTURE28                     = 0x84DC,
		GL_TEXTURE29                     = 0x84DD,
		GL_TEXTURE30                     = 0x84DE,
		GL_TEXTURE31                     = 0x84DF,
		GL_ACTIVE_TEXTURE                = 0x84E0,
		GL_MULTISAMPLE                   = 0x809D,
		GL_SAMPLE_ALPHA_TO_COVERAGE      = 0x809E,
		GL_SAMPLE_ALPHA_TO_ONE           = 0x809F,
		GL_SAMPLE_COVERAGE               = 0x80A0,
		GL_SAMPLE_BUFFERS                = 0x80A8,
		GL_SAMPLE_COVERAGE_VALUE         = 0x80AA,
		GL_SAMPLE_COVERAGE_INVERT        = 0x80AB,
		GL_TEXTURE_BINDING_CUBE_MAP      = 0x8514,
		GL_TEXTURE_CUBE_MAP_POSITIVE_X   = 0x8515,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_X   = 0x8516,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Y   = 0x8517,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Y   = 0x8518,
		GL_TEXTURE_CUBE_MAP_POSITIVE_Z   = 0x8519,
		GL_TEXTURE_CUBE_MAP_NEGATIVE_Z   = 0x851A,
		GL_PROXY_TEXTURE_CUBE_MAP        = 0x851B,
		GL_MAX_CUBE_MAP_TEXTURE_SIZE     = 0x851C,
		GL_COMPRESSED_RGB                = 0x84ED,
		GL_COMPRESSED_RGBA               = 0x84EE,
		GL_TEXTURE_COMPRESSION_HINT      = 0x84EF,
		GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0,
		GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
		GL_COMPRESSED_TEXTURE_FORMATS    = 0x86A3,
		GL_CLAMP_TO_BORDER               = 0x812D,
	};

	inline void ActiveTexture(GLenum texture) { ::__gleActiveTexture(texture); }
	inline void SampleCoverage(GLfloat value, GLboolean invert) { ::__gleSampleCoverage(value, invert); }
	inline void CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data); }
	inline void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data); }
	inline void CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data); }
	inline void CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data); }
	inline void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data); }
	inline void CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) { ::__gleCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data); }
	inline void GetCompressedTexImage(GLenum target, GLint level, GLvoid *img) { ::__gleGetCompressedTexImage(target, level, img); }

}

#endif //_INT_GL_1_3_HPP

