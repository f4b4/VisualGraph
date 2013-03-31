#ifndef _INT_GL_1_1_HPP
#define _INT_GL_1_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleCullFace)(GLenum );
extern void (GLE_FUNCPTR *__gleFrontFace)(GLenum );
extern void (GLE_FUNCPTR *__gleHint)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleLineWidth)(GLfloat );
extern void (GLE_FUNCPTR *__glePointSize)(GLfloat );
extern void (GLE_FUNCPTR *__glePolygonMode)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleScissor)(GLint , GLint , GLsizei , GLsizei );
extern void (GLE_FUNCPTR *__gleTexParameterf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleTexParameterfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexParameteri)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleTexParameteriv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleTexImage1D)(GLenum , GLint , GLint , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleTexImage2D)(GLenum , GLint , GLint , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleDrawBuffer)(GLenum );
extern void (GLE_FUNCPTR *__gleClear)(GLbitfield );
extern void (GLE_FUNCPTR *__gleClearColor)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleClearStencil)(GLint );
extern void (GLE_FUNCPTR *__gleClearDepth)(GLdouble );
extern void (GLE_FUNCPTR *__gleStencilMask)(GLuint );
extern void (GLE_FUNCPTR *__gleColorMask)(GLboolean , GLboolean , GLboolean , GLboolean );
extern void (GLE_FUNCPTR *__gleDepthMask)(GLboolean );
extern void (GLE_FUNCPTR *__gleDisable)(GLenum );
extern void (GLE_FUNCPTR *__gleEnable)(GLenum );
extern void (GLE_FUNCPTR *__gleFinish)();
extern void (GLE_FUNCPTR *__gleFlush)();
extern void (GLE_FUNCPTR *__gleBlendFunc)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleLogicOp)(GLenum );
extern void (GLE_FUNCPTR *__gleStencilFunc)(GLenum , GLint , GLuint );
extern void (GLE_FUNCPTR *__gleStencilOp)(GLenum , GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleDepthFunc)(GLenum );
extern void (GLE_FUNCPTR *__glePixelStoref)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__glePixelStorei)(GLenum , GLint );
extern void (GLE_FUNCPTR *__gleReadBuffer)(GLenum );
extern void (GLE_FUNCPTR *__gleReadPixels)(GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetBooleanv)(GLenum , GLboolean *);
extern void (GLE_FUNCPTR *__gleGetDoublev)(GLenum , GLdouble *);
extern GLenum (GLE_FUNCPTR *__gleGetError)();
extern void (GLE_FUNCPTR *__gleGetFloatv)(GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetIntegerv)(GLenum , GLint *);
extern const GLubyte * (GLE_FUNCPTR *__gleGetString)(GLenum );
extern void (GLE_FUNCPTR *__gleGetTexImage)(GLenum , GLint , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetTexParameterfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetTexParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetTexLevelParameterfv)(GLenum , GLint , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetTexLevelParameteriv)(GLenum , GLint , GLenum , GLint *);
extern GLboolean (GLE_FUNCPTR *__gleIsEnabled)(GLenum );
extern void (GLE_FUNCPTR *__gleDepthRange)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleViewport)(GLint , GLint , GLsizei , GLsizei );
extern void (GLE_FUNCPTR *__gleDrawArrays)(GLenum , GLint , GLsizei );
extern void (GLE_FUNCPTR *__gleDrawElements)(GLenum , GLsizei , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetPointerv)(GLenum , GLvoid* *);
extern void (GLE_FUNCPTR *__glePolygonOffset)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleCopyTexImage1D)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
extern void (GLE_FUNCPTR *__gleCopyTexImage2D)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
extern void (GLE_FUNCPTR *__gleCopyTexSubImage1D)(GLenum , GLint , GLint , GLint , GLint , GLsizei );
extern void (GLE_FUNCPTR *__gleCopyTexSubImage2D)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
extern void (GLE_FUNCPTR *__gleTexSubImage1D)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleTexSubImage2D)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleBindTexture)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleDeleteTextures)(GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleGenTextures)(GLsizei , GLuint *);
extern GLboolean (GLE_FUNCPTR *__gleIsTexture)(GLuint );
extern void (GLE_FUNCPTR *__gleIndexub)(GLubyte );
extern void (GLE_FUNCPTR *__gleIndexubv)(const GLubyte *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_1
	{
		GL_DEPTH_BUFFER_BIT              = 0x00000100,
		GL_STENCIL_BUFFER_BIT            = 0x00000400,
		GL_COLOR_BUFFER_BIT              = 0x00004000,
		GL_FALSE                         = 0,
		GL_TRUE                          = 1,
		GL_POINTS                        = 0x0000,
		GL_LINES                         = 0x0001,
		GL_LINE_LOOP                     = 0x0002,
		GL_LINE_STRIP                    = 0x0003,
		GL_TRIANGLE_STRIP                = 0x0005,
		GL_TRIANGLE_FAN                  = 0x0006,
		GL_NEVER                         = 0x0200,
		GL_LESS                          = 0x0201,
		GL_LEQUAL                        = 0x0203,
		GL_GREATER                       = 0x0204,
		GL_NOTEQUAL                      = 0x0205,
		GL_GEQUAL                        = 0x0206,
		GL_ALWAYS                        = 0x0207,
		GL_ONE                           = 1,
		GL_SRC_COLOR                     = 0x0300,
		GL_ONE_MINUS_SRC_COLOR           = 0x0301,
		GL_SRC_ALPHA                     = 0x0302,
		GL_ONE_MINUS_SRC_ALPHA           = 0x0303,
		GL_DST_ALPHA                     = 0x0304,
		GL_ONE_MINUS_DST_ALPHA           = 0x0305,
		GL_DST_COLOR                     = 0x0306,
		GL_ONE_MINUS_DST_COLOR           = 0x0307,
		GL_SRC_ALPHA_SATURATE            = 0x0308,
		GL_FRONT_LEFT                    = 0x0400,
		GL_FRONT_RIGHT                   = 0x0401,
		GL_BACK_LEFT                     = 0x0402,
		GL_BACK_RIGHT                    = 0x0403,
		GL_FRONT                         = 0x0404,
		GL_BACK                          = 0x0405,
		GL_LEFT                          = 0x0406,
		GL_RIGHT                         = 0x0407,
		GL_FRONT_AND_BACK                = 0x0408,
		GL_INVALID_ENUM                  = 0x0500,
		GL_INVALID_VALUE                 = 0x0501,
		GL_INVALID_OPERATION             = 0x0502,
		GL_OUT_OF_MEMORY                 = 0x0505,
		GL_POINT_SIZE                    = 0x0B11,
		GL_POINT_SIZE_RANGE              = 0x0B12,
		GL_POINT_SIZE_GRANULARITY        = 0x0B13,
		GL_LINE_SMOOTH                   = 0x0B20,
		GL_LINE_WIDTH                    = 0x0B21,
		GL_LINE_WIDTH_RANGE              = 0x0B22,
		GL_LINE_WIDTH_GRANULARITY        = 0x0B23,
		GL_POLYGON_SMOOTH                = 0x0B41,
		GL_CULL_FACE                     = 0x0B44,
		GL_CULL_FACE_MODE                = 0x0B45,
		GL_FRONT_FACE                    = 0x0B46,
		GL_DEPTH_TEST                    = 0x0B71,
		GL_DEPTH_WRITEMASK               = 0x0B72,
		GL_DEPTH_CLEAR_VALUE             = 0x0B73,
		GL_DEPTH_FUNC                    = 0x0B74,
		GL_STENCIL_TEST                  = 0x0B90,
		GL_STENCIL_CLEAR_VALUE           = 0x0B91,
		GL_STENCIL_FUNC                  = 0x0B92,
		GL_STENCIL_VALUE_MASK            = 0x0B93,
		GL_STENCIL_FAIL                  = 0x0B94,
		GL_STENCIL_PASS_DEPTH_FAIL       = 0x0B95,
		GL_STENCIL_PASS_DEPTH_PASS       = 0x0B96,
		GL_STENCIL_REF                   = 0x0B97,
		GL_STENCIL_WRITEMASK             = 0x0B98,
		GL_DITHER                        = 0x0BD0,
		GL_BLEND_DST                     = 0x0BE0,
		GL_BLEND_SRC                     = 0x0BE1,
		GL_BLEND                         = 0x0BE2,
		GL_LOGIC_OP_MODE                 = 0x0BF0,
		GL_COLOR_LOGIC_OP                = 0x0BF2,
		GL_DRAW_BUFFER                   = 0x0C01,
		GL_READ_BUFFER                   = 0x0C02,
		GL_COLOR_CLEAR_VALUE             = 0x0C22,
		GL_COLOR_WRITEMASK               = 0x0C23,
		GL_DOUBLEBUFFER                  = 0x0C32,
		GL_STEREO                        = 0x0C33,
		GL_LINE_SMOOTH_HINT              = 0x0C52,
		GL_POLYGON_SMOOTH_HINT           = 0x0C53,
		GL_UNPACK_SWAP_BYTES             = 0x0CF0,
		GL_UNPACK_LSB_FIRST              = 0x0CF1,
		GL_UNPACK_ROW_LENGTH             = 0x0CF2,
		GL_UNPACK_SKIP_ROWS              = 0x0CF3,
		GL_UNPACK_SKIP_PIXELS            = 0x0CF4,
		GL_UNPACK_ALIGNMENT              = 0x0CF5,
		GL_PACK_SWAP_BYTES               = 0x0D00,
		GL_PACK_LSB_FIRST                = 0x0D01,
		GL_PACK_ROW_LENGTH               = 0x0D02,
		GL_PACK_SKIP_ROWS                = 0x0D03,
		GL_PACK_SKIP_PIXELS              = 0x0D04,
		GL_PACK_ALIGNMENT                = 0x0D05,
		GL_MAX_TEXTURE_SIZE              = 0x0D33,
		GL_MAX_VIEWPORT_DIMS             = 0x0D3A,
		GL_SUBPIXEL_BITS                 = 0x0D50,
		GL_POLYGON_OFFSET_UNITS          = 0x2A00,
		GL_POLYGON_OFFSET_POINT          = 0x2A01,
		GL_POLYGON_OFFSET_LINE           = 0x2A02,
		GL_POLYGON_OFFSET_FILL           = 0x8037,
		GL_POLYGON_OFFSET_FACTOR         = 0x8038,
		GL_TEXTURE_BINDING_1D            = 0x8068,
		GL_TEXTURE_BINDING_2D            = 0x8069,
		GL_TEXTURE_WIDTH                 = 0x1000,
		GL_TEXTURE_HEIGHT                = 0x1001,
		GL_TEXTURE_INTERNAL_FORMAT       = 0x1003,
		GL_TEXTURE_BORDER_COLOR          = 0x1004,
		GL_TEXTURE_RED_SIZE              = 0x805C,
		GL_TEXTURE_GREEN_SIZE            = 0x805D,
		GL_TEXTURE_BLUE_SIZE             = 0x805E,
		GL_TEXTURE_ALPHA_SIZE            = 0x805F,
		GL_DONT_CARE                     = 0x1100,
		GL_FASTEST                       = 0x1101,
		GL_NICEST                        = 0x1102,
		GL_BYTE                          = 0x1400,
		GL_UNSIGNED_BYTE                 = 0x1401,
		GL_SHORT                         = 0x1402,
		GL_UNSIGNED_SHORT                = 0x1403,
		GL_INT                           = 0x1404,
		GL_UNSIGNED_INT                  = 0x1405,
		GL_FLOAT                         = 0x1406,
		GL_CLEAR                         = 0x1500,
		GL_AND                           = 0x1501,
		GL_AND_REVERSE                   = 0x1502,
		GL_COPY                          = 0x1503,
		GL_AND_INVERTED                  = 0x1504,
		GL_NOOP                          = 0x1505,
		GL_XOR                           = 0x1506,
		GL_OR                            = 0x1507,
		GL_NOR                           = 0x1508,
		GL_EQUIV                         = 0x1509,
		GL_INVERT                        = 0x150A,
		GL_OR_REVERSE                    = 0x150B,
		GL_COPY_INVERTED                 = 0x150C,
		GL_OR_INVERTED                   = 0x150D,
		GL_NAND                          = 0x150E,
		GL_SET                           = 0x150F,
		GL_TEXTURE                       = 0x1702,
		GL_COLOR                         = 0x1800,
		GL_DEPTH                         = 0x1801,
		GL_STENCIL                       = 0x1802,
		GL_STENCIL_INDEX                 = 0x1901,
		GL_DEPTH_COMPONENT               = 0x1902,
		GL_RED                           = 0x1903,
		GL_GREEN                         = 0x1904,
		GL_BLUE                          = 0x1905,
		GL_ALPHA                         = 0x1906,
		GL_RGB                           = 0x1907,
		GL_RGBA                          = 0x1908,
		GL_POINT                         = 0x1B00,
		GL_LINE                          = 0x1B01,
		GL_FILL                          = 0x1B02,
		GL_KEEP                          = 0x1E00,
		GL_REPLACE                       = 0x1E01,
		GL_INCR                          = 0x1E02,
		GL_DECR                          = 0x1E03,
		GL_VENDOR                        = 0x1F00,
		GL_RENDERER                      = 0x1F01,
		GL_VERSION                       = 0x1F02,
		GL_EXTENSIONS                    = 0x1F03,
		GL_NEAREST                       = 0x2600,
		GL_LINEAR                        = 0x2601,
		GL_NEAREST_MIPMAP_NEAREST        = 0x2700,
		GL_LINEAR_MIPMAP_NEAREST         = 0x2701,
		GL_NEAREST_MIPMAP_LINEAR         = 0x2702,
		GL_LINEAR_MIPMAP_LINEAR          = 0x2703,
		GL_TEXTURE_MAG_FILTER            = 0x2800,
		GL_TEXTURE_MIN_FILTER            = 0x2801,
		GL_TEXTURE_WRAP_S                = 0x2802,
		GL_TEXTURE_WRAP_T                = 0x2803,
		GL_PROXY_TEXTURE_1D              = 0x8063,
		GL_PROXY_TEXTURE_2D              = 0x8064,
		GL_REPEAT                        = 0x2901,
		GL_R3_G3_B2                      = 0x2A10,
		GL_RGB4                          = 0x804F,
		GL_RGB5                          = 0x8050,
		GL_RGB8                          = 0x8051,
		GL_RGB10                         = 0x8052,
		GL_RGB12                         = 0x8053,
		GL_RGB16                         = 0x8054,
		GL_RGBA2                         = 0x8055,
		GL_RGBA4                         = 0x8056,
		GL_RGB5_A1                       = 0x8057,
		GL_RGBA8                         = 0x8058,
		GL_RGB10_A2                      = 0x8059,
		GL_RGBA12                        = 0x805A,
		GL_RGBA16                        = 0x805B,
	};

	inline void CullFace(GLenum mode) { ::__gleCullFace(mode); }
	inline void FrontFace(GLenum mode) { ::__gleFrontFace(mode); }
	inline void Hint(GLenum target, GLenum mode) { ::__gleHint(target, mode); }
	inline void LineWidth(GLfloat width) { ::__gleLineWidth(width); }
	inline void PointSize(GLfloat size) { ::__glePointSize(size); }
	inline void PolygonMode(GLenum face, GLenum mode) { ::__glePolygonMode(face, mode); }
	inline void Scissor(GLint x, GLint y, GLsizei width, GLsizei height) { ::__gleScissor(x, y, width, height); }
	inline void TexParameterf(GLenum target, GLenum pname, GLfloat param) { ::__gleTexParameterf(target, pname, param); }
	inline void TexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { ::__gleTexParameterfv(target, pname, params); }
	inline void TexParameteri(GLenum target, GLenum pname, GLint param) { ::__gleTexParameteri(target, pname, param); }
	inline void TexParameteriv(GLenum target, GLenum pname, const GLint *params) { ::__gleTexParameteriv(target, pname, params); }
	inline void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexImage1D(target, level, internalformat, width, border, format, type, pixels); }
	inline void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexImage2D(target, level, internalformat, width, height, border, format, type, pixels); }
	inline void DrawBuffer(GLenum mode) { ::__gleDrawBuffer(mode); }
	inline void Clear(GLbitfield mask) { ::__gleClear(mask); }
	inline void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { ::__gleClearColor(red, green, blue, alpha); }
	inline void ClearStencil(GLint s) { ::__gleClearStencil(s); }
	inline void ClearDepth(GLdouble depth) { ::__gleClearDepth(depth); }
	inline void StencilMask(GLuint mask) { ::__gleStencilMask(mask); }
	inline void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) { ::__gleColorMask(red, green, blue, alpha); }
	inline void DepthMask(GLboolean flag) { ::__gleDepthMask(flag); }
	inline void Disable(GLenum cap) { ::__gleDisable(cap); }
	inline void Enable(GLenum cap) { ::__gleEnable(cap); }
	inline void Finish() { ::__gleFinish(); }
	inline void Flush() { ::__gleFlush(); }
	inline void BlendFunc(GLenum sfactor, GLenum dfactor) { ::__gleBlendFunc(sfactor, dfactor); }
	inline void LogicOp(GLenum opcode) { ::__gleLogicOp(opcode); }
	inline void StencilFunc(GLenum func, GLint ref, GLuint mask) { ::__gleStencilFunc(func, ref, mask); }
	inline void StencilOp(GLenum fail, GLenum zfail, GLenum zpass) { ::__gleStencilOp(fail, zfail, zpass); }
	inline void DepthFunc(GLenum func) { ::__gleDepthFunc(func); }
	inline void PixelStoref(GLenum pname, GLfloat param) { ::__glePixelStoref(pname, param); }
	inline void PixelStorei(GLenum pname, GLint param) { ::__glePixelStorei(pname, param); }
	inline void ReadBuffer(GLenum mode) { ::__gleReadBuffer(mode); }
	inline void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels) { ::__gleReadPixels(x, y, width, height, format, type, pixels); }
	inline void GetBooleanv(GLenum pname, GLboolean *params) { ::__gleGetBooleanv(pname, params); }
	inline void GetDoublev(GLenum pname, GLdouble *params) { ::__gleGetDoublev(pname, params); }
	inline GLenum GetError() { return ::__gleGetError(); }
	inline void GetFloatv(GLenum pname, GLfloat *params) { ::__gleGetFloatv(pname, params); }
	inline void GetIntegerv(GLenum pname, GLint *params) { ::__gleGetIntegerv(pname, params); }
	inline const GLubyte * GetString(GLenum name) { return ::__gleGetString(name); }
	inline void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) { ::__gleGetTexImage(target, level, format, type, pixels); }
	inline void GetTexParameterfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetTexParameterfv(target, pname, params); }
	inline void GetTexParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetTexParameteriv(target, pname, params); }
	inline void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) { ::__gleGetTexLevelParameterfv(target, level, pname, params); }
	inline void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) { ::__gleGetTexLevelParameteriv(target, level, pname, params); }
	inline GLboolean IsEnabled(GLenum cap) { return ::__gleIsEnabled(cap); }
	inline void DepthRange(GLdouble ren_near, GLdouble ren_far) { ::__gleDepthRange(ren_near, ren_far); }
	inline void Viewport(GLint x, GLint y, GLsizei width, GLsizei height) { ::__gleViewport(x, y, width, height); }
	inline void DrawArrays(GLenum mode, GLint first, GLsizei count) { ::__gleDrawArrays(mode, first, count); }
	inline void DrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) { ::__gleDrawElements(mode, count, type, indices); }
	inline void GetPointerv(GLenum pname, GLvoid* *params) { ::__gleGetPointerv(pname, params); }
	inline void PolygonOffset(GLfloat factor, GLfloat units) { ::__glePolygonOffset(factor, units); }
	inline void CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) { ::__gleCopyTexImage1D(target, level, internalformat, x, y, width, border); }
	inline void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) { ::__gleCopyTexImage2D(target, level, internalformat, x, y, width, height, border); }
	inline void CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) { ::__gleCopyTexSubImage1D(target, level, xoffset, x, y, width); }
	inline void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) { ::__gleCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height); }
	inline void TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexSubImage1D(target, level, xoffset, width, format, type, pixels); }
	inline void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels); }
	inline void BindTexture(GLenum target, GLuint texture) { ::__gleBindTexture(target, texture); }
	inline void DeleteTextures(GLsizei n, const GLuint *textures) { ::__gleDeleteTextures(n, textures); }
	inline void GenTextures(GLsizei n, GLuint *textures) { ::__gleGenTextures(n, textures); }
	inline GLboolean IsTexture(GLuint texture) { return ::__gleIsTexture(texture); }
	inline void Indexub(GLubyte c) { ::__gleIndexub(c); }
	inline void Indexubv(const GLubyte *c) { ::__gleIndexubv(c); }

}

#endif //_INT_GL_1_1_HPP

