#ifndef _INT_GL_2_0_HPP
#define _INT_GL_2_0_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleBlendEquationSeparate)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleDrawBuffers)(GLsizei , const GLenum *);
extern void (GLE_FUNCPTR *__gleStencilOpSeparate)(GLenum , GLenum , GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleStencilFuncSeparate)(GLenum , GLenum , GLint , GLuint );
extern void (GLE_FUNCPTR *__gleStencilMaskSeparate)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleAttachShader)(GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleBindAttribLocation)(GLuint , GLuint , const GLchar *);
extern void (GLE_FUNCPTR *__gleCompileShader)(GLuint );
extern GLuint (GLE_FUNCPTR *__gleCreateProgram)();
extern GLuint (GLE_FUNCPTR *__gleCreateShader)(GLenum );
extern void (GLE_FUNCPTR *__gleDeleteProgram)(GLuint );
extern void (GLE_FUNCPTR *__gleDeleteShader)(GLuint );
extern void (GLE_FUNCPTR *__gleDetachShader)(GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleDisableVertexAttribArray)(GLuint );
extern void (GLE_FUNCPTR *__gleEnableVertexAttribArray)(GLuint );
extern void (GLE_FUNCPTR *__gleGetActiveAttrib)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
extern void (GLE_FUNCPTR *__gleGetActiveUniform)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
extern void (GLE_FUNCPTR *__gleGetAttachedShaders)(GLuint , GLsizei , GLsizei *, GLuint *);
extern GLint (GLE_FUNCPTR *__gleGetAttribLocation)(GLuint , const GLchar *);
extern void (GLE_FUNCPTR *__gleGetProgramiv)(GLuint , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetProgramInfoLog)(GLuint , GLsizei , GLsizei *, GLchar *);
extern void (GLE_FUNCPTR *__gleGetShaderiv)(GLuint , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetShaderInfoLog)(GLuint , GLsizei , GLsizei *, GLchar *);
extern void (GLE_FUNCPTR *__gleGetShaderSource)(GLuint , GLsizei , GLsizei *, GLchar *);
extern GLint (GLE_FUNCPTR *__gleGetUniformLocation)(GLuint , const GLchar *);
extern void (GLE_FUNCPTR *__gleGetUniformfv)(GLuint , GLint , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetUniformiv)(GLuint , GLint , GLint *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribdv)(GLuint , GLenum , GLdouble *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribfv)(GLuint , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribiv)(GLuint , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribPointerv)(GLuint , GLenum , GLvoid* *);
extern GLboolean (GLE_FUNCPTR *__gleIsProgram)(GLuint );
extern GLboolean (GLE_FUNCPTR *__gleIsShader)(GLuint );
extern void (GLE_FUNCPTR *__gleLinkProgram)(GLuint );
extern void (GLE_FUNCPTR *__gleShaderSource)(GLuint , GLsizei , const GLchar* const *, const GLint *);
extern void (GLE_FUNCPTR *__gleUseProgram)(GLuint );
extern void (GLE_FUNCPTR *__gleUniform1f)(GLint , GLfloat );
extern void (GLE_FUNCPTR *__gleUniform2f)(GLint , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleUniform3f)(GLint , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleUniform4f)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleUniform1i)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleUniform2i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleUniform3i)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleUniform4i)(GLint , GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleUniform1fv)(GLint , GLsizei , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniform2fv)(GLint , GLsizei , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniform3fv)(GLint , GLsizei , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniform4fv)(GLint , GLsizei , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniform1iv)(GLint , GLsizei , const GLint *);
extern void (GLE_FUNCPTR *__gleUniform2iv)(GLint , GLsizei , const GLint *);
extern void (GLE_FUNCPTR *__gleUniform3iv)(GLint , GLsizei , const GLint *);
extern void (GLE_FUNCPTR *__gleUniform4iv)(GLint , GLsizei , const GLint *);
extern void (GLE_FUNCPTR *__gleUniformMatrix2fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix3fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleUniformMatrix4fv)(GLint , GLsizei , GLboolean , const GLfloat *);
extern void (GLE_FUNCPTR *__gleValidateProgram)(GLuint );
extern void (GLE_FUNCPTR *__gleVertexAttribPointer)(GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_2_0
	{
		GL_BLEND_EQUATION_RGB            = 0x8009,
		GL_VERTEX_ATTRIB_ARRAY_ENABLED   = 0x8622,
		GL_VERTEX_ATTRIB_ARRAY_SIZE      = 0x8623,
		GL_VERTEX_ATTRIB_ARRAY_STRIDE    = 0x8624,
		GL_VERTEX_ATTRIB_ARRAY_TYPE      = 0x8625,
		GL_CURRENT_VERTEX_ATTRIB         = 0x8626,
		GL_VERTEX_PROGRAM_POINT_SIZE     = 0x8642,
		GL_VERTEX_ATTRIB_ARRAY_POINTER   = 0x8645,
		GL_STENCIL_BACK_FUNC             = 0x8800,
		GL_STENCIL_BACK_FAIL             = 0x8801,
		GL_STENCIL_BACK_PASS_DEPTH_FAIL  = 0x8802,
		GL_STENCIL_BACK_PASS_DEPTH_PASS  = 0x8803,
		GL_MAX_DRAW_BUFFERS              = 0x8824,
		GL_DRAW_BUFFER0                  = 0x8825,
		GL_DRAW_BUFFER1                  = 0x8826,
		GL_DRAW_BUFFER2                  = 0x8827,
		GL_DRAW_BUFFER3                  = 0x8828,
		GL_DRAW_BUFFER4                  = 0x8829,
		GL_DRAW_BUFFER5                  = 0x882A,
		GL_DRAW_BUFFER6                  = 0x882B,
		GL_DRAW_BUFFER7                  = 0x882C,
		GL_DRAW_BUFFER8                  = 0x882D,
		GL_DRAW_BUFFER9                  = 0x882E,
		GL_DRAW_BUFFER10                 = 0x882F,
		GL_DRAW_BUFFER11                 = 0x8830,
		GL_DRAW_BUFFER12                 = 0x8831,
		GL_DRAW_BUFFER13                 = 0x8832,
		GL_DRAW_BUFFER14                 = 0x8833,
		GL_DRAW_BUFFER15                 = 0x8834,
		GL_BLEND_EQUATION_ALPHA          = 0x883D,
		GL_MAX_VERTEX_ATTRIBS            = 0x8869,
		GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
		GL_MAX_TEXTURE_IMAGE_UNITS       = 0x8872,
		GL_FRAGMENT_SHADER               = 0x8B30,
		GL_VERTEX_SHADER                 = 0x8B31,
		GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49,
		GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A,
		GL_MAX_VARYING_FLOATS            = 0x8B4B,
		GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
		GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
		GL_SHADER_TYPE                   = 0x8B4F,
		GL_FLOAT_VEC2                    = 0x8B50,
		GL_FLOAT_VEC3                    = 0x8B51,
		GL_FLOAT_VEC4                    = 0x8B52,
		GL_INT_VEC2                      = 0x8B53,
		GL_INT_VEC3                      = 0x8B54,
		GL_INT_VEC4                      = 0x8B55,
		GL_BOOL                          = 0x8B56,
		GL_BOOL_VEC2                     = 0x8B57,
		GL_BOOL_VEC3                     = 0x8B58,
		GL_BOOL_VEC4                     = 0x8B59,
		GL_FLOAT_MAT2                    = 0x8B5A,
		GL_FLOAT_MAT3                    = 0x8B5B,
		GL_FLOAT_MAT4                    = 0x8B5C,
		GL_SAMPLER_1D                    = 0x8B5D,
		GL_SAMPLER_2D                    = 0x8B5E,
		GL_SAMPLER_3D                    = 0x8B5F,
		GL_SAMPLER_CUBE                  = 0x8B60,
		GL_SAMPLER_1D_SHADOW             = 0x8B61,
		GL_SAMPLER_2D_SHADOW             = 0x8B62,
		GL_DELETE_STATUS                 = 0x8B80,
		GL_COMPILE_STATUS                = 0x8B81,
		GL_LINK_STATUS                   = 0x8B82,
		GL_VALIDATE_STATUS               = 0x8B83,
		GL_INFO_LOG_LENGTH               = 0x8B84,
		GL_ATTACHED_SHADERS              = 0x8B85,
		GL_ACTIVE_UNIFORMS               = 0x8B86,
		GL_ACTIVE_UNIFORM_MAX_LENGTH     = 0x8B87,
		GL_SHADER_SOURCE_LENGTH          = 0x8B88,
		GL_ACTIVE_ATTRIBUTES             = 0x8B89,
		GL_ACTIVE_ATTRIBUTE_MAX_LENGTH   = 0x8B8A,
		GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
		GL_SHADING_LANGUAGE_VERSION      = 0x8B8C,
		GL_CURRENT_PROGRAM               = 0x8B8D,
		GL_POINT_SPRITE_COORD_ORIGIN     = 0x8CA0,
		GL_LOWER_LEFT                    = 0x8CA1,
		GL_UPPER_LEFT                    = 0x8CA2,
		GL_STENCIL_BACK_REF              = 0x8CA3,
		GL_STENCIL_BACK_VALUE_MASK       = 0x8CA4,
		GL_STENCIL_BACK_WRITEMASK        = 0x8CA5,
	};

	inline void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) { ::__gleBlendEquationSeparate(modeRGB, modeAlpha); }
	inline void DrawBuffers(GLsizei n, const GLenum *bufs) { ::__gleDrawBuffers(n, bufs); }
	inline void StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) { ::__gleStencilOpSeparate(face, sfail, dpfail, dppass); }
	inline void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) { ::__gleStencilFuncSeparate(face, func, ref, mask); }
	inline void StencilMaskSeparate(GLenum face, GLuint mask) { ::__gleStencilMaskSeparate(face, mask); }
	inline void AttachShader(GLuint program, GLuint shader) { ::__gleAttachShader(program, shader); }
	inline void BindAttribLocation(GLuint program, GLuint index, const GLchar *name) { ::__gleBindAttribLocation(program, index, name); }
	inline void CompileShader(GLuint shader) { ::__gleCompileShader(shader); }
	inline GLuint CreateProgram() { return ::__gleCreateProgram(); }
	inline GLuint CreateShader(GLenum type) { return ::__gleCreateShader(type); }
	inline void DeleteProgram(GLuint program) { ::__gleDeleteProgram(program); }
	inline void DeleteShader(GLuint shader) { ::__gleDeleteShader(shader); }
	inline void DetachShader(GLuint program, GLuint shader) { ::__gleDetachShader(program, shader); }
	inline void DisableVertexAttribArray(GLuint index) { ::__gleDisableVertexAttribArray(index); }
	inline void EnableVertexAttribArray(GLuint index) { ::__gleEnableVertexAttribArray(index); }
	inline void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { ::__gleGetActiveAttrib(program, index, bufSize, length, size, type, name); }
	inline void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) { ::__gleGetActiveUniform(program, index, bufSize, length, size, type, name); }
	inline void GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj) { ::__gleGetAttachedShaders(program, maxCount, count, obj); }
	inline GLint GetAttribLocation(GLuint program, const GLchar *name) { return ::__gleGetAttribLocation(program, name); }
	inline void GetProgramiv(GLuint program, GLenum pname, GLint *params) { ::__gleGetProgramiv(program, pname, params); }
	inline void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { ::__gleGetProgramInfoLog(program, bufSize, length, infoLog); }
	inline void GetShaderiv(GLuint shader, GLenum pname, GLint *params) { ::__gleGetShaderiv(shader, pname, params); }
	inline void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { ::__gleGetShaderInfoLog(shader, bufSize, length, infoLog); }
	inline void GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) { ::__gleGetShaderSource(shader, bufSize, length, source); }
	inline GLint GetUniformLocation(GLuint program, const GLchar *name) { return ::__gleGetUniformLocation(program, name); }
	inline void GetUniformfv(GLuint program, GLint location, GLfloat *params) { ::__gleGetUniformfv(program, location, params); }
	inline void GetUniformiv(GLuint program, GLint location, GLint *params) { ::__gleGetUniformiv(program, location, params); }
	inline void GetVertexAttribdv(GLuint index, GLenum pname, GLdouble *params) { ::__gleGetVertexAttribdv(index, pname, params); }
	inline void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params) { ::__gleGetVertexAttribfv(index, pname, params); }
	inline void GetVertexAttribiv(GLuint index, GLenum pname, GLint *params) { ::__gleGetVertexAttribiv(index, pname, params); }
	inline void GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid* *pointer) { ::__gleGetVertexAttribPointerv(index, pname, pointer); }
	inline GLboolean IsProgram(GLuint program) { return ::__gleIsProgram(program); }
	inline GLboolean IsShader(GLuint shader) { return ::__gleIsShader(shader); }
	inline void LinkProgram(GLuint program) { ::__gleLinkProgram(program); }
	inline void ShaderSource(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length) { ::__gleShaderSource(shader, count, string, length); }
	inline void UseProgram(GLuint program) { ::__gleUseProgram(program); }
	inline void Uniform1f(GLint location, GLfloat v0) { ::__gleUniform1f(location, v0); }
	inline void Uniform2f(GLint location, GLfloat v0, GLfloat v1) { ::__gleUniform2f(location, v0, v1); }
	inline void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { ::__gleUniform3f(location, v0, v1, v2); }
	inline void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { ::__gleUniform4f(location, v0, v1, v2, v3); }
	inline void Uniform1i(GLint location, GLint v0) { ::__gleUniform1i(location, v0); }
	inline void Uniform2i(GLint location, GLint v0, GLint v1) { ::__gleUniform2i(location, v0, v1); }
	inline void Uniform3i(GLint location, GLint v0, GLint v1, GLint v2) { ::__gleUniform3i(location, v0, v1, v2); }
	inline void Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) { ::__gleUniform4i(location, v0, v1, v2, v3); }
	inline void Uniform1fv(GLint location, GLsizei count, const GLfloat *value) { ::__gleUniform1fv(location, count, value); }
	inline void Uniform2fv(GLint location, GLsizei count, const GLfloat *value) { ::__gleUniform2fv(location, count, value); }
	inline void Uniform3fv(GLint location, GLsizei count, const GLfloat *value) { ::__gleUniform3fv(location, count, value); }
	inline void Uniform4fv(GLint location, GLsizei count, const GLfloat *value) { ::__gleUniform4fv(location, count, value); }
	inline void Uniform1iv(GLint location, GLsizei count, const GLint *value) { ::__gleUniform1iv(location, count, value); }
	inline void Uniform2iv(GLint location, GLsizei count, const GLint *value) { ::__gleUniform2iv(location, count, value); }
	inline void Uniform3iv(GLint location, GLsizei count, const GLint *value) { ::__gleUniform3iv(location, count, value); }
	inline void Uniform4iv(GLint location, GLsizei count, const GLint *value) { ::__gleUniform4iv(location, count, value); }
	inline void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix2fv(location, count, transpose, value); }
	inline void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix3fv(location, count, transpose, value); }
	inline void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { ::__gleUniformMatrix4fv(location, count, transpose, value); }
	inline void ValidateProgram(GLuint program) { ::__gleValidateProgram(program); }
	inline void VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer) { ::__gleVertexAttribPointer(index, size, type, normalized, stride, pointer); }

}

#endif //_INT_GL_2_0_HPP

