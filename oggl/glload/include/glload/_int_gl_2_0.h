#ifndef _INT_GL_2_0_H
#define _INT_GL_2_0_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDRAWBUFFERSPROC)(GLsizei , const GLenum *);
typedef void (GLE_FUNCPTR * PFNGLSTENCILOPSEPARATEPROC)(GLenum , GLenum , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLSTENCILFUNCSEPARATEPROC)(GLenum , GLenum , GLint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSTENCILMASKSEPARATEPROC)(GLenum , GLuint );
typedef void (GLE_FUNCPTR * PFNGLATTACHSHADERPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLBINDATTRIBLOCATIONPROC)(GLuint , GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLCOMPILESHADERPROC)(GLuint );
typedef GLuint (GLE_FUNCPTR * PFNGLCREATEPROGRAMPROC)();
typedef GLuint (GLE_FUNCPTR * PFNGLCREATESHADERPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLDELETEPROGRAMPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDELETESHADERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLDETACHSHADERPROC)(GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEATTRIBPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETACTIVEUNIFORMPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETATTACHEDSHADERSPROC)(GLuint , GLsizei , GLsizei *, GLuint *);
typedef GLint (GLE_FUNCPTR * PFNGLGETATTRIBLOCATIONPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPROGRAMINFOLOGPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETSHADERIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSHADERINFOLOGPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETSHADERSOURCEPROC)(GLuint , GLsizei , GLsizei *, GLchar *);
typedef GLint (GLE_FUNCPTR * PFNGLGETUNIFORMLOCATIONPROC)(GLuint , const GLchar *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMFVPROC)(GLuint , GLint , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETUNIFORMIVPROC)(GLuint , GLint , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBDVPROC)(GLuint , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBFVPROC)(GLuint , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBIVPROC)(GLuint , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint , GLenum , GLvoid* *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISPROGRAMPROC)(GLuint );
typedef GLboolean (GLE_FUNCPTR * PFNGLISSHADERPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLLINKPROGRAMPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLSHADERSOURCEPROC)(GLuint , GLsizei , const GLchar* const *, const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUSEPROGRAMPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FPROC)(GLint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FPROC)(GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FPROC)(GLint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FPROC)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IPROC)(GLint , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4FVPROC)(GLint , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM1IVPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM2IVPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM3IVPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORM4IVPROC)(GLint , GLsizei , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX2FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX3FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLUNIFORMMATRIX4FVPROC)(GLint , GLsizei , GLboolean , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVALIDATEPROGRAMPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIBPOINTERPROC)(GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *);

extern PFNGLBLENDEQUATIONSEPARATEPROC __gleBlendEquationSeparate;
#define glBlendEquationSeparate __gleBlendEquationSeparate
extern PFNGLDRAWBUFFERSPROC __gleDrawBuffers;
#define glDrawBuffers __gleDrawBuffers
extern PFNGLSTENCILOPSEPARATEPROC __gleStencilOpSeparate;
#define glStencilOpSeparate __gleStencilOpSeparate
extern PFNGLSTENCILFUNCSEPARATEPROC __gleStencilFuncSeparate;
#define glStencilFuncSeparate __gleStencilFuncSeparate
extern PFNGLSTENCILMASKSEPARATEPROC __gleStencilMaskSeparate;
#define glStencilMaskSeparate __gleStencilMaskSeparate
extern PFNGLATTACHSHADERPROC __gleAttachShader;
#define glAttachShader __gleAttachShader
extern PFNGLBINDATTRIBLOCATIONPROC __gleBindAttribLocation;
#define glBindAttribLocation __gleBindAttribLocation
extern PFNGLCOMPILESHADERPROC __gleCompileShader;
#define glCompileShader __gleCompileShader
extern PFNGLCREATEPROGRAMPROC __gleCreateProgram;
#define glCreateProgram __gleCreateProgram
extern PFNGLCREATESHADERPROC __gleCreateShader;
#define glCreateShader __gleCreateShader
extern PFNGLDELETEPROGRAMPROC __gleDeleteProgram;
#define glDeleteProgram __gleDeleteProgram
extern PFNGLDELETESHADERPROC __gleDeleteShader;
#define glDeleteShader __gleDeleteShader
extern PFNGLDETACHSHADERPROC __gleDetachShader;
#define glDetachShader __gleDetachShader
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC __gleDisableVertexAttribArray;
#define glDisableVertexAttribArray __gleDisableVertexAttribArray
extern PFNGLENABLEVERTEXATTRIBARRAYPROC __gleEnableVertexAttribArray;
#define glEnableVertexAttribArray __gleEnableVertexAttribArray
extern PFNGLGETACTIVEATTRIBPROC __gleGetActiveAttrib;
#define glGetActiveAttrib __gleGetActiveAttrib
extern PFNGLGETACTIVEUNIFORMPROC __gleGetActiveUniform;
#define glGetActiveUniform __gleGetActiveUniform
extern PFNGLGETATTACHEDSHADERSPROC __gleGetAttachedShaders;
#define glGetAttachedShaders __gleGetAttachedShaders
extern PFNGLGETATTRIBLOCATIONPROC __gleGetAttribLocation;
#define glGetAttribLocation __gleGetAttribLocation
extern PFNGLGETPROGRAMIVPROC __gleGetProgramiv;
#define glGetProgramiv __gleGetProgramiv
extern PFNGLGETPROGRAMINFOLOGPROC __gleGetProgramInfoLog;
#define glGetProgramInfoLog __gleGetProgramInfoLog
extern PFNGLGETSHADERIVPROC __gleGetShaderiv;
#define glGetShaderiv __gleGetShaderiv
extern PFNGLGETSHADERINFOLOGPROC __gleGetShaderInfoLog;
#define glGetShaderInfoLog __gleGetShaderInfoLog
extern PFNGLGETSHADERSOURCEPROC __gleGetShaderSource;
#define glGetShaderSource __gleGetShaderSource
extern PFNGLGETUNIFORMLOCATIONPROC __gleGetUniformLocation;
#define glGetUniformLocation __gleGetUniformLocation
extern PFNGLGETUNIFORMFVPROC __gleGetUniformfv;
#define glGetUniformfv __gleGetUniformfv
extern PFNGLGETUNIFORMIVPROC __gleGetUniformiv;
#define glGetUniformiv __gleGetUniformiv
extern PFNGLGETVERTEXATTRIBDVPROC __gleGetVertexAttribdv;
#define glGetVertexAttribdv __gleGetVertexAttribdv
extern PFNGLGETVERTEXATTRIBFVPROC __gleGetVertexAttribfv;
#define glGetVertexAttribfv __gleGetVertexAttribfv
extern PFNGLGETVERTEXATTRIBIVPROC __gleGetVertexAttribiv;
#define glGetVertexAttribiv __gleGetVertexAttribiv
extern PFNGLGETVERTEXATTRIBPOINTERVPROC __gleGetVertexAttribPointerv;
#define glGetVertexAttribPointerv __gleGetVertexAttribPointerv
extern PFNGLISPROGRAMPROC __gleIsProgram;
#define glIsProgram __gleIsProgram
extern PFNGLISSHADERPROC __gleIsShader;
#define glIsShader __gleIsShader
extern PFNGLLINKPROGRAMPROC __gleLinkProgram;
#define glLinkProgram __gleLinkProgram
extern PFNGLSHADERSOURCEPROC __gleShaderSource;
#define glShaderSource __gleShaderSource
extern PFNGLUSEPROGRAMPROC __gleUseProgram;
#define glUseProgram __gleUseProgram
extern PFNGLUNIFORM1FPROC __gleUniform1f;
#define glUniform1f __gleUniform1f
extern PFNGLUNIFORM2FPROC __gleUniform2f;
#define glUniform2f __gleUniform2f
extern PFNGLUNIFORM3FPROC __gleUniform3f;
#define glUniform3f __gleUniform3f
extern PFNGLUNIFORM4FPROC __gleUniform4f;
#define glUniform4f __gleUniform4f
extern PFNGLUNIFORM1IPROC __gleUniform1i;
#define glUniform1i __gleUniform1i
extern PFNGLUNIFORM2IPROC __gleUniform2i;
#define glUniform2i __gleUniform2i
extern PFNGLUNIFORM3IPROC __gleUniform3i;
#define glUniform3i __gleUniform3i
extern PFNGLUNIFORM4IPROC __gleUniform4i;
#define glUniform4i __gleUniform4i
extern PFNGLUNIFORM1FVPROC __gleUniform1fv;
#define glUniform1fv __gleUniform1fv
extern PFNGLUNIFORM2FVPROC __gleUniform2fv;
#define glUniform2fv __gleUniform2fv
extern PFNGLUNIFORM3FVPROC __gleUniform3fv;
#define glUniform3fv __gleUniform3fv
extern PFNGLUNIFORM4FVPROC __gleUniform4fv;
#define glUniform4fv __gleUniform4fv
extern PFNGLUNIFORM1IVPROC __gleUniform1iv;
#define glUniform1iv __gleUniform1iv
extern PFNGLUNIFORM2IVPROC __gleUniform2iv;
#define glUniform2iv __gleUniform2iv
extern PFNGLUNIFORM3IVPROC __gleUniform3iv;
#define glUniform3iv __gleUniform3iv
extern PFNGLUNIFORM4IVPROC __gleUniform4iv;
#define glUniform4iv __gleUniform4iv
extern PFNGLUNIFORMMATRIX2FVPROC __gleUniformMatrix2fv;
#define glUniformMatrix2fv __gleUniformMatrix2fv
extern PFNGLUNIFORMMATRIX3FVPROC __gleUniformMatrix3fv;
#define glUniformMatrix3fv __gleUniformMatrix3fv
extern PFNGLUNIFORMMATRIX4FVPROC __gleUniformMatrix4fv;
#define glUniformMatrix4fv __gleUniformMatrix4fv
extern PFNGLVALIDATEPROGRAMPROC __gleValidateProgram;
#define glValidateProgram __gleValidateProgram
extern PFNGLVERTEXATTRIBPOINTERPROC __gleVertexAttribPointer;
#define glVertexAttribPointer __gleVertexAttribPointer


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_2_0_H

