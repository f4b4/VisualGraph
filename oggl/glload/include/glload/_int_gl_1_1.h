#ifndef _INT_GL_1_1_H
#define _INT_GL_1_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_REPEAT 0x2901
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
typedef void (GLE_FUNCPTR * PFNGLCULLFACEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLFRONTFACEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLHINTPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLLINEWIDTHPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOINTSIZEPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOLYGONMODEPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLSCISSORPROC)(GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE2DPROC)(GLenum , GLint , GLint , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLCLEARPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLCLEARCOLORPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCLEARSTENCILPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLCLEARDEPTHPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLSTENCILMASKPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLORMASKPROC)(GLboolean , GLboolean , GLboolean , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDEPTHMASKPROC)(GLboolean );
typedef void (GLE_FUNCPTR * PFNGLDISABLEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLENABLEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLFINISHPROC)();
typedef void (GLE_FUNCPTR * PFNGLFLUSHPROC)();
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLLOGICOPPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCPROC)(GLenum , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPPROC)(GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDEPTHFUNCPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLPIXELSTOREFPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELSTOREIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLREADBUFFERPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLREADPIXELSPROC)(GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANVPROC)(GLenum , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETDOUBLEVPROC)(GLenum , GLdouble *);
typedef GLenum (GLE_FUNCPTR * PFNGLGETERRORPROC)();
typedef void (GLE_FUNCPTR * PFNGLGETFLOATVPROC)(GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERVPROC)(GLenum , GLint *);
typedef const GLubyte * (GLE_FUNCPTR * PFNGLGETSTRINGPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETTEXIMAGEPROC)(GLenum , GLint , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum , GLint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum , GLint , GLenum , GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLDEPTHRANGEPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVIEWPORTPROC)(GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWARRAYSPROC)(GLenum , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLDRAWELEMENTSPROC)(GLenum , GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETPOINTERVPROC)(GLenum , GLvoid* *);
typedef void (GLE_FUNCPTR * PFNGLPOLYGONOFFSETPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE1DPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXIMAGE2DPROC)(GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE1DPROC)(GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXSUBIMAGE2DPROC)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLBINDTEXTUREPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETETEXTURESPROC)(GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGENTEXTURESPROC)(GLsizei , GLuint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISTEXTUREPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLINDEXUBPROC)(GLubyte );
typedef void (GLE_FUNCPTR * PFNGLINDEXUBVPROC)(const GLubyte *);

extern PFNGLCULLFACEPROC __gleCullFace;
#define glCullFace __gleCullFace
extern PFNGLFRONTFACEPROC __gleFrontFace;
#define glFrontFace __gleFrontFace
extern PFNGLHINTPROC __gleHint;
#define glHint __gleHint
extern PFNGLLINEWIDTHPROC __gleLineWidth;
#define glLineWidth __gleLineWidth
extern PFNGLPOINTSIZEPROC __glePointSize;
#define glPointSize __glePointSize
extern PFNGLPOLYGONMODEPROC __glePolygonMode;
#define glPolygonMode __glePolygonMode
extern PFNGLSCISSORPROC __gleScissor;
#define glScissor __gleScissor
extern PFNGLTEXPARAMETERFPROC __gleTexParameterf;
#define glTexParameterf __gleTexParameterf
extern PFNGLTEXPARAMETERFVPROC __gleTexParameterfv;
#define glTexParameterfv __gleTexParameterfv
extern PFNGLTEXPARAMETERIPROC __gleTexParameteri;
#define glTexParameteri __gleTexParameteri
extern PFNGLTEXPARAMETERIVPROC __gleTexParameteriv;
#define glTexParameteriv __gleTexParameteriv
extern PFNGLTEXIMAGE1DPROC __gleTexImage1D;
#define glTexImage1D __gleTexImage1D
extern PFNGLTEXIMAGE2DPROC __gleTexImage2D;
#define glTexImage2D __gleTexImage2D
extern PFNGLDRAWBUFFERPROC __gleDrawBuffer;
#define glDrawBuffer __gleDrawBuffer
extern PFNGLCLEARPROC __gleClear;
#define glClear __gleClear
extern PFNGLCLEARCOLORPROC __gleClearColor;
#define glClearColor __gleClearColor
extern PFNGLCLEARSTENCILPROC __gleClearStencil;
#define glClearStencil __gleClearStencil
extern PFNGLCLEARDEPTHPROC __gleClearDepth;
#define glClearDepth __gleClearDepth
extern PFNGLSTENCILMASKPROC __gleStencilMask;
#define glStencilMask __gleStencilMask
extern PFNGLCOLORMASKPROC __gleColorMask;
#define glColorMask __gleColorMask
extern PFNGLDEPTHMASKPROC __gleDepthMask;
#define glDepthMask __gleDepthMask
extern PFNGLDISABLEPROC __gleDisable;
#define glDisable __gleDisable
extern PFNGLENABLEPROC __gleEnable;
#define glEnable __gleEnable
extern PFNGLFINISHPROC __gleFinish;
#define glFinish __gleFinish
extern PFNGLFLUSHPROC __gleFlush;
#define glFlush __gleFlush
extern PFNGLBLENDFUNCPROC __gleBlendFunc;
#define glBlendFunc __gleBlendFunc
extern PFNGLLOGICOPPROC __gleLogicOp;
#define glLogicOp __gleLogicOp
extern PFNGLSTENCILFUNCPROC __gleStencilFunc;
#define glStencilFunc __gleStencilFunc
extern PFNGLSTENCILOPPROC __gleStencilOp;
#define glStencilOp __gleStencilOp
extern PFNGLDEPTHFUNCPROC __gleDepthFunc;
#define glDepthFunc __gleDepthFunc
extern PFNGLPIXELSTOREFPROC __glePixelStoref;
#define glPixelStoref __glePixelStoref
extern PFNGLPIXELSTOREIPROC __glePixelStorei;
#define glPixelStorei __glePixelStorei
extern PFNGLREADBUFFERPROC __gleReadBuffer;
#define glReadBuffer __gleReadBuffer
extern PFNGLREADPIXELSPROC __gleReadPixels;
#define glReadPixels __gleReadPixels
extern PFNGLGETBOOLEANVPROC __gleGetBooleanv;
#define glGetBooleanv __gleGetBooleanv
extern PFNGLGETDOUBLEVPROC __gleGetDoublev;
#define glGetDoublev __gleGetDoublev
extern PFNGLGETERRORPROC __gleGetError;
#define glGetError __gleGetError
extern PFNGLGETFLOATVPROC __gleGetFloatv;
#define glGetFloatv __gleGetFloatv
extern PFNGLGETINTEGERVPROC __gleGetIntegerv;
#define glGetIntegerv __gleGetIntegerv
extern PFNGLGETSTRINGPROC __gleGetString;
#define glGetString __gleGetString
extern PFNGLGETTEXIMAGEPROC __gleGetTexImage;
#define glGetTexImage __gleGetTexImage
extern PFNGLGETTEXPARAMETERFVPROC __gleGetTexParameterfv;
#define glGetTexParameterfv __gleGetTexParameterfv
extern PFNGLGETTEXPARAMETERIVPROC __gleGetTexParameteriv;
#define glGetTexParameteriv __gleGetTexParameteriv
extern PFNGLGETTEXLEVELPARAMETERFVPROC __gleGetTexLevelParameterfv;
#define glGetTexLevelParameterfv __gleGetTexLevelParameterfv
extern PFNGLGETTEXLEVELPARAMETERIVPROC __gleGetTexLevelParameteriv;
#define glGetTexLevelParameteriv __gleGetTexLevelParameteriv
extern PFNGLISENABLEDPROC __gleIsEnabled;
#define glIsEnabled __gleIsEnabled
extern PFNGLDEPTHRANGEPROC __gleDepthRange;
#define glDepthRange __gleDepthRange
extern PFNGLVIEWPORTPROC __gleViewport;
#define glViewport __gleViewport
extern PFNGLDRAWARRAYSPROC __gleDrawArrays;
#define glDrawArrays __gleDrawArrays
extern PFNGLDRAWELEMENTSPROC __gleDrawElements;
#define glDrawElements __gleDrawElements
extern PFNGLGETPOINTERVPROC __gleGetPointerv;
#define glGetPointerv __gleGetPointerv
extern PFNGLPOLYGONOFFSETPROC __glePolygonOffset;
#define glPolygonOffset __glePolygonOffset
extern PFNGLCOPYTEXIMAGE1DPROC __gleCopyTexImage1D;
#define glCopyTexImage1D __gleCopyTexImage1D
extern PFNGLCOPYTEXIMAGE2DPROC __gleCopyTexImage2D;
#define glCopyTexImage2D __gleCopyTexImage2D
extern PFNGLCOPYTEXSUBIMAGE1DPROC __gleCopyTexSubImage1D;
#define glCopyTexSubImage1D __gleCopyTexSubImage1D
extern PFNGLCOPYTEXSUBIMAGE2DPROC __gleCopyTexSubImage2D;
#define glCopyTexSubImage2D __gleCopyTexSubImage2D
extern PFNGLTEXSUBIMAGE1DPROC __gleTexSubImage1D;
#define glTexSubImage1D __gleTexSubImage1D
extern PFNGLTEXSUBIMAGE2DPROC __gleTexSubImage2D;
#define glTexSubImage2D __gleTexSubImage2D
extern PFNGLBINDTEXTUREPROC __gleBindTexture;
#define glBindTexture __gleBindTexture
extern PFNGLDELETETEXTURESPROC __gleDeleteTextures;
#define glDeleteTextures __gleDeleteTextures
extern PFNGLGENTEXTURESPROC __gleGenTextures;
#define glGenTextures __gleGenTextures
extern PFNGLISTEXTUREPROC __gleIsTexture;
#define glIsTexture __gleIsTexture
extern PFNGLINDEXUBPROC __gleIndexub;
#define glIndexub __gleIndexub
extern PFNGLINDEXUBVPROC __gleIndexubv;
#define glIndexubv __gleIndexubv


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_1_H

