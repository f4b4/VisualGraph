#ifndef _INT_GL_1_3_H
#define _INT_GL_1_3_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D
typedef void (GLE_FUNCPTR * PFNGLACTIVETEXTUREPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLSAMPLECOVERAGEPROC)(GLfloat , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXIMAGE1DPROC)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOMPRESSEDTEXIMAGEPROC)(GLenum , GLint , GLvoid *);

extern PFNGLACTIVETEXTUREPROC __gleActiveTexture;
#define glActiveTexture __gleActiveTexture
extern PFNGLSAMPLECOVERAGEPROC __gleSampleCoverage;
#define glSampleCoverage __gleSampleCoverage
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC __gleCompressedTexImage3D;
#define glCompressedTexImage3D __gleCompressedTexImage3D
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC __gleCompressedTexImage2D;
#define glCompressedTexImage2D __gleCompressedTexImage2D
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC __gleCompressedTexImage1D;
#define glCompressedTexImage1D __gleCompressedTexImage1D
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC __gleCompressedTexSubImage3D;
#define glCompressedTexSubImage3D __gleCompressedTexSubImage3D
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC __gleCompressedTexSubImage2D;
#define glCompressedTexSubImage2D __gleCompressedTexSubImage2D
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC __gleCompressedTexSubImage1D;
#define glCompressedTexSubImage1D __gleCompressedTexSubImage1D
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC __gleGetCompressedTexImage;
#define glGetCompressedTexImage __gleGetCompressedTexImage


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_3_H

