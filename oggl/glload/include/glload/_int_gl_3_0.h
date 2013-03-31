#ifndef _INT_GL_3_0_H
#define _INT_GL_3_0_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_RGBA32F 0x8814
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
typedef void (GLE_FUNCPTR * PFNGLCOLORMASKIPROC)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLGETBOOLEANI_VPROC)(GLenum , GLuint , GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLGETINTEGERI_VPROC)(GLenum , GLuint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLENABLEIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEIPROC)(GLenum , GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISENABLEDIPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKPROC)();
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERRANGEPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
typedef void (GLE_FUNCPTR * PFNGLBINDBUFFERBASEPROC)(GLenum , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint , GLsizei , const GLchar* const *, GLenum );
typedef void (GLE_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLCLAMPCOLORPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBEGINCONDITIONALRENDERPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDCONDITIONALRENDERPROC)();
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IPROC)(GLuint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IPROC)(GLuint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IPROC)(GLuint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IPROC)(GLuint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIPROC)(GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIPROC)(GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1IVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2IVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3IVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4IVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI1UIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI2UIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI3UIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4BVPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4SVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4UBVPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBI4USVPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMUIVPROC)(GLuint , GLint , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLBINDFRAGDATALOCATIONPROC)(GLuint , GLuint , const GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETFRAGDATALOCATIONPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIPROC)(GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIPROC)(GLint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIPROC)(GLint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIPROC)(GLint , GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXPARAMETERIUIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXPARAMETERIUIVPROC)(GLenum , GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERIVPROC)(GLenum , GLint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERUIVPROC)(GLenum , GLint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERFVPROC)(GLenum , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCLEARBUFFERFIPROC)(GLenum , GLint , GLfloat , GLint );
typedef const GLubyte * (GLE_FUNCPTR * PFNGLGETSTRINGIPROC)(GLenum , GLuint );

extern PFNGLCOLORMASKIPROC __gleColorMaski;
#define glColorMaski __gleColorMaski
extern PFNGLGETBOOLEANI_VPROC __gleGetBooleani_v;
#define glGetBooleani_v __gleGetBooleani_v
extern PFNGLGETINTEGERI_VPROC __gleGetIntegeri_v;
#define glGetIntegeri_v __gleGetIntegeri_v
extern PFNGLENABLEIPROC __gleEnablei;
#define glEnablei __gleEnablei
extern PFNGLDISABLEIPROC __gleDisablei;
#define glDisablei __gleDisablei
extern PFNGLISENABLEDIPROC __gleIsEnabledi;
#define glIsEnabledi __gleIsEnabledi
extern PFNGLBEGINTRANSFORMFEEDBACKPROC __gleBeginTransformFeedback;
#define glBeginTransformFeedback __gleBeginTransformFeedback
extern PFNGLENDTRANSFORMFEEDBACKPROC __gleEndTransformFeedback;
#define glEndTransformFeedback __gleEndTransformFeedback
extern PFNGLBINDBUFFERRANGEPROC __gleBindBufferRange;
#define glBindBufferRange __gleBindBufferRange
extern PFNGLBINDBUFFERBASEPROC __gleBindBufferBase;
#define glBindBufferBase __gleBindBufferBase
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC __gleTransformFeedbackVaryings;
#define glTransformFeedbackVaryings __gleTransformFeedbackVaryings
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC __gleGetTransformFeedbackVarying;
#define glGetTransformFeedbackVarying __gleGetTransformFeedbackVarying
extern PFNGLCLAMPCOLORPROC __gleClampColor;
#define glClampColor __gleClampColor
extern PFNGLBEGINCONDITIONALRENDERPROC __gleBeginConditionalRender;
#define glBeginConditionalRender __gleBeginConditionalRender
extern PFNGLENDCONDITIONALRENDERPROC __gleEndConditionalRender;
#define glEndConditionalRender __gleEndConditionalRender
extern PFNGLVERTEXATTRIBIPOINTERPROC __gleVertexAttribIPointer;
#define glVertexAttribIPointer __gleVertexAttribIPointer
extern PFNGLGETVERTEXATTRIBIIVPROC __gleGetVertexAttribIiv;
#define glGetVertexAttribIiv __gleGetVertexAttribIiv
extern PFNGLGETVERTEXATTRIBIUIVPROC __gleGetVertexAttribIuiv;
#define glGetVertexAttribIuiv __gleGetVertexAttribIuiv
extern PFNGLVERTEXATTRIBI1IPROC __gleVertexAttribI1i;
#define glVertexAttribI1i __gleVertexAttribI1i
extern PFNGLVERTEXATTRIBI2IPROC __gleVertexAttribI2i;
#define glVertexAttribI2i __gleVertexAttribI2i
extern PFNGLVERTEXATTRIBI3IPROC __gleVertexAttribI3i;
#define glVertexAttribI3i __gleVertexAttribI3i
extern PFNGLVERTEXATTRIBI4IPROC __gleVertexAttribI4i;
#define glVertexAttribI4i __gleVertexAttribI4i
extern PFNGLVERTEXATTRIBI1UIPROC __gleVertexAttribI1ui;
#define glVertexAttribI1ui __gleVertexAttribI1ui
extern PFNGLVERTEXATTRIBI2UIPROC __gleVertexAttribI2ui;
#define glVertexAttribI2ui __gleVertexAttribI2ui
extern PFNGLVERTEXATTRIBI3UIPROC __gleVertexAttribI3ui;
#define glVertexAttribI3ui __gleVertexAttribI3ui
extern PFNGLVERTEXATTRIBI4UIPROC __gleVertexAttribI4ui;
#define glVertexAttribI4ui __gleVertexAttribI4ui
extern PFNGLVERTEXATTRIBI1IVPROC __gleVertexAttribI1iv;
#define glVertexAttribI1iv __gleVertexAttribI1iv
extern PFNGLVERTEXATTRIBI2IVPROC __gleVertexAttribI2iv;
#define glVertexAttribI2iv __gleVertexAttribI2iv
extern PFNGLVERTEXATTRIBI3IVPROC __gleVertexAttribI3iv;
#define glVertexAttribI3iv __gleVertexAttribI3iv
extern PFNGLVERTEXATTRIBI4IVPROC __gleVertexAttribI4iv;
#define glVertexAttribI4iv __gleVertexAttribI4iv
extern PFNGLVERTEXATTRIBI1UIVPROC __gleVertexAttribI1uiv;
#define glVertexAttribI1uiv __gleVertexAttribI1uiv
extern PFNGLVERTEXATTRIBI2UIVPROC __gleVertexAttribI2uiv;
#define glVertexAttribI2uiv __gleVertexAttribI2uiv
extern PFNGLVERTEXATTRIBI3UIVPROC __gleVertexAttribI3uiv;
#define glVertexAttribI3uiv __gleVertexAttribI3uiv
extern PFNGLVERTEXATTRIBI4UIVPROC __gleVertexAttribI4uiv;
#define glVertexAttribI4uiv __gleVertexAttribI4uiv
extern PFNGLVERTEXATTRIBI4BVPROC __gleVertexAttribI4bv;
#define glVertexAttribI4bv __gleVertexAttribI4bv
extern PFNGLVERTEXATTRIBI4SVPROC __gleVertexAttribI4sv;
#define glVertexAttribI4sv __gleVertexAttribI4sv
extern PFNGLVERTEXATTRIBI4UBVPROC __gleVertexAttribI4ubv;
#define glVertexAttribI4ubv __gleVertexAttribI4ubv
extern PFNGLVERTEXATTRIBI4USVPROC __gleVertexAttribI4usv;
#define glVertexAttribI4usv __gleVertexAttribI4usv
extern PFNGLGETUNIFORMUIVPROC __gleGetUniformuiv;
#define glGetUniformuiv __gleGetUniformuiv
extern PFNGLBINDFRAGDATALOCATIONPROC __gleBindFragDataLocation;
#define glBindFragDataLocation __gleBindFragDataLocation
extern PFNGLGETFRAGDATALOCATIONPROC __gleGetFragDataLocation;
#define glGetFragDataLocation __gleGetFragDataLocation
extern PFNGLUNIFORM1UIPROC __gleUniform1ui;
#define glUniform1ui __gleUniform1ui
extern PFNGLUNIFORM2UIPROC __gleUniform2ui;
#define glUniform2ui __gleUniform2ui
extern PFNGLUNIFORM3UIPROC __gleUniform3ui;
#define glUniform3ui __gleUniform3ui
extern PFNGLUNIFORM4UIPROC __gleUniform4ui;
#define glUniform4ui __gleUniform4ui
extern PFNGLUNIFORM1UIVPROC __gleUniform1uiv;
#define glUniform1uiv __gleUniform1uiv
extern PFNGLUNIFORM2UIVPROC __gleUniform2uiv;
#define glUniform2uiv __gleUniform2uiv
extern PFNGLUNIFORM3UIVPROC __gleUniform3uiv;
#define glUniform3uiv __gleUniform3uiv
extern PFNGLUNIFORM4UIVPROC __gleUniform4uiv;
#define glUniform4uiv __gleUniform4uiv
extern PFNGLTEXPARAMETERIIVPROC __gleTexParameterIiv;
#define glTexParameterIiv __gleTexParameterIiv
extern PFNGLTEXPARAMETERIUIVPROC __gleTexParameterIuiv;
#define glTexParameterIuiv __gleTexParameterIuiv
extern PFNGLGETTEXPARAMETERIIVPROC __gleGetTexParameterIiv;
#define glGetTexParameterIiv __gleGetTexParameterIiv
extern PFNGLGETTEXPARAMETERIUIVPROC __gleGetTexParameterIuiv;
#define glGetTexParameterIuiv __gleGetTexParameterIuiv
extern PFNGLCLEARBUFFERIVPROC __gleClearBufferiv;
#define glClearBufferiv __gleClearBufferiv
extern PFNGLCLEARBUFFERUIVPROC __gleClearBufferuiv;
#define glClearBufferuiv __gleClearBufferuiv
extern PFNGLCLEARBUFFERFVPROC __gleClearBufferfv;
#define glClearBufferfv __gleClearBufferfv
extern PFNGLCLEARBUFFERFIPROC __gleClearBufferfi;
#define glClearBufferfi __gleClearBufferfi
extern PFNGLGETSTRINGIPROC __gleGetStringi;
#define glGetStringi __gleGetStringi


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_3_0_H

