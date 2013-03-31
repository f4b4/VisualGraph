#ifndef _INT_GL_3_0_HPP
#define _INT_GL_3_0_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleColorMaski)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
extern void (GLE_FUNCPTR *__gleGetBooleani_v)(GLenum , GLuint , GLboolean *);
extern void (GLE_FUNCPTR *__gleGetIntegeri_v)(GLenum , GLuint , GLint *);
extern void (GLE_FUNCPTR *__gleEnablei)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleDisablei)(GLenum , GLuint );
extern GLboolean (GLE_FUNCPTR *__gleIsEnabledi)(GLenum , GLuint );
extern void (GLE_FUNCPTR *__gleBeginTransformFeedback)(GLenum );
extern void (GLE_FUNCPTR *__gleEndTransformFeedback)();
extern void (GLE_FUNCPTR *__gleBindBufferRange)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
extern void (GLE_FUNCPTR *__gleBindBufferBase)(GLenum , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleTransformFeedbackVaryings)(GLuint , GLsizei , const GLchar* const *, GLenum );
extern void (GLE_FUNCPTR *__gleGetTransformFeedbackVarying)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);
extern void (GLE_FUNCPTR *__gleClampColor)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleBeginConditionalRender)(GLuint , GLenum );
extern void (GLE_FUNCPTR *__gleEndConditionalRender)();
extern void (GLE_FUNCPTR *__gleVertexAttribIPointer)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribIiv)(GLuint , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetVertexAttribIuiv)(GLuint , GLenum , GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI1i)(GLuint , GLint );
extern void (GLE_FUNCPTR *__gleVertexAttribI2i)(GLuint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertexAttribI3i)(GLuint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertexAttribI4i)(GLuint , GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertexAttribI1ui)(GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleVertexAttribI2ui)(GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleVertexAttribI3ui)(GLuint , GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleVertexAttribI4ui)(GLuint , GLuint , GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleVertexAttribI1iv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI2iv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI3iv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4iv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI1uiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI2uiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI3uiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4uiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4bv)(GLuint , const GLbyte *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4sv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4ubv)(GLuint , const GLubyte *);
extern void (GLE_FUNCPTR *__gleVertexAttribI4usv)(GLuint , const GLushort *);
extern void (GLE_FUNCPTR *__gleGetUniformuiv)(GLuint , GLint , GLuint *);
extern void (GLE_FUNCPTR *__gleBindFragDataLocation)(GLuint , GLuint , const GLchar *);
extern GLint (GLE_FUNCPTR *__gleGetFragDataLocation)(GLuint , const GLchar *);
extern void (GLE_FUNCPTR *__gleUniform1ui)(GLint , GLuint );
extern void (GLE_FUNCPTR *__gleUniform2ui)(GLint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleUniform3ui)(GLint , GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleUniform4ui)(GLint , GLuint , GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleUniform1uiv)(GLint , GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleUniform2uiv)(GLint , GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleUniform3uiv)(GLint , GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleUniform4uiv)(GLint , GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__gleTexParameterIiv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleTexParameterIuiv)(GLenum , GLenum , const GLuint *);
extern void (GLE_FUNCPTR *__gleGetTexParameterIiv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetTexParameterIuiv)(GLenum , GLenum , GLuint *);
extern void (GLE_FUNCPTR *__gleClearBufferiv)(GLenum , GLint , const GLint *);
extern void (GLE_FUNCPTR *__gleClearBufferuiv)(GLenum , GLint , const GLuint *);
extern void (GLE_FUNCPTR *__gleClearBufferfv)(GLenum , GLint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleClearBufferfi)(GLenum , GLint , GLfloat , GLint );
extern const GLubyte * (GLE_FUNCPTR *__gleGetStringi)(GLenum , GLuint );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_3_0
	{
		GL_COMPARE_REF_TO_TEXTURE        = 0x884E,
		GL_CLIP_DISTANCE0                = 0x3000,
		GL_CLIP_DISTANCE1                = 0x3001,
		GL_CLIP_DISTANCE2                = 0x3002,
		GL_CLIP_DISTANCE3                = 0x3003,
		GL_CLIP_DISTANCE4                = 0x3004,
		GL_CLIP_DISTANCE5                = 0x3005,
		GL_CLIP_DISTANCE6                = 0x3006,
		GL_CLIP_DISTANCE7                = 0x3007,
		GL_MAX_CLIP_DISTANCES            = 0x0D32,
		GL_MAJOR_VERSION                 = 0x821B,
		GL_MINOR_VERSION                 = 0x821C,
		GL_NUM_EXTENSIONS                = 0x821D,
		GL_CONTEXT_FLAGS                 = 0x821E,
		GL_COMPRESSED_RED                = 0x8225,
		GL_COMPRESSED_RG                 = 0x8226,
		GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x0001,
		GL_RGBA32F                       = 0x8814,
		GL_RGBA16F                       = 0x881A,
		GL_RGB16F                        = 0x881B,
		GL_VERTEX_ATTRIB_ARRAY_INTEGER   = 0x88FD,
		GL_MAX_ARRAY_TEXTURE_LAYERS      = 0x88FF,
		GL_MIN_PROGRAM_TEXEL_OFFSET      = 0x8904,
		GL_MAX_PROGRAM_TEXEL_OFFSET      = 0x8905,
		GL_CLAMP_READ_COLOR              = 0x891C,
		GL_FIXED_ONLY                    = 0x891D,
		GL_PROXY_TEXTURE_1D_ARRAY        = 0x8C19,
		GL_PROXY_TEXTURE_2D_ARRAY        = 0x8C1B,
		GL_TEXTURE_BINDING_1D_ARRAY      = 0x8C1C,
		GL_TEXTURE_BINDING_2D_ARRAY      = 0x8C1D,
		GL_R11F_G11F_B10F                = 0x8C3A,
		GL_UNSIGNED_INT_10F_11F_11F_REV  = 0x8C3B,
		GL_RGB9_E5                       = 0x8C3D,
		GL_UNSIGNED_INT_5_9_9_9_REV      = 0x8C3E,
		GL_TEXTURE_SHARED_SIZE           = 0x8C3F,
		GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76,
		GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F,
		GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
		GL_TRANSFORM_FEEDBACK_VARYINGS   = 0x8C83,
		GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
		GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
		GL_PRIMITIVES_GENERATED          = 0x8C87,
		GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
		GL_RASTERIZER_DISCARD            = 0x8C89,
		GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
		GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
		GL_INTERLEAVED_ATTRIBS           = 0x8C8C,
		GL_SEPARATE_ATTRIBS              = 0x8C8D,
		GL_TRANSFORM_FEEDBACK_BUFFER     = 0x8C8E,
		GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
		GL_RGBA32UI                      = 0x8D70,
		GL_RGBA16UI                      = 0x8D76,
		GL_RGB16UI                       = 0x8D77,
		GL_RGBA8UI                       = 0x8D7C,
		GL_RGB8UI                        = 0x8D7D,
		GL_RGBA32I                       = 0x8D82,
		GL_RGBA16I                       = 0x8D88,
		GL_RGB16I                        = 0x8D89,
		GL_RGBA8I                        = 0x8D8E,
		GL_RGB8I                         = 0x8D8F,
		GL_RED_INTEGER                   = 0x8D94,
		GL_GREEN_INTEGER                 = 0x8D95,
		GL_BLUE_INTEGER                  = 0x8D96,
		GL_RGB_INTEGER                   = 0x8D98,
		GL_RGBA_INTEGER                  = 0x8D99,
		GL_BGR_INTEGER                   = 0x8D9A,
		GL_BGRA_INTEGER                  = 0x8D9B,
		GL_SAMPLER_1D_ARRAY              = 0x8DC0,
		GL_SAMPLER_2D_ARRAY              = 0x8DC1,
		GL_SAMPLER_1D_ARRAY_SHADOW       = 0x8DC3,
		GL_SAMPLER_2D_ARRAY_SHADOW       = 0x8DC4,
		GL_SAMPLER_CUBE_SHADOW           = 0x8DC5,
		GL_UNSIGNED_INT_VEC2             = 0x8DC6,
		GL_UNSIGNED_INT_VEC3             = 0x8DC7,
		GL_UNSIGNED_INT_VEC4             = 0x8DC8,
		GL_INT_SAMPLER_1D                = 0x8DC9,
		GL_INT_SAMPLER_2D                = 0x8DCA,
		GL_INT_SAMPLER_3D                = 0x8DCB,
		GL_INT_SAMPLER_CUBE              = 0x8DCC,
		GL_INT_SAMPLER_1D_ARRAY          = 0x8DCE,
		GL_INT_SAMPLER_2D_ARRAY          = 0x8DCF,
		GL_UNSIGNED_INT_SAMPLER_1D       = 0x8DD1,
		GL_UNSIGNED_INT_SAMPLER_2D       = 0x8DD2,
		GL_UNSIGNED_INT_SAMPLER_3D       = 0x8DD3,
		GL_UNSIGNED_INT_SAMPLER_CUBE     = 0x8DD4,
		GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6,
		GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7,
		GL_QUERY_WAIT                    = 0x8E13,
		GL_QUERY_NO_WAIT                 = 0x8E14,
		GL_QUERY_BY_REGION_WAIT          = 0x8E15,
		GL_QUERY_BY_REGION_NO_WAIT       = 0x8E16,
		GL_BUFFER_ACCESS_FLAGS           = 0x911F,
		GL_BUFFER_MAP_LENGTH             = 0x9120,
		GL_BUFFER_MAP_OFFSET             = 0x9121,
	};

	inline void ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) { ::__gleColorMaski(index, r, g, b, a); }
	inline void GetBooleani_v(GLenum target, GLuint index, GLboolean *data) { ::__gleGetBooleani_v(target, index, data); }
	inline void GetIntegeri_v(GLenum target, GLuint index, GLint *data) { ::__gleGetIntegeri_v(target, index, data); }
	inline void Enablei(GLenum target, GLuint index) { ::__gleEnablei(target, index); }
	inline void Disablei(GLenum target, GLuint index) { ::__gleDisablei(target, index); }
	inline GLboolean IsEnabledi(GLenum target, GLuint index) { return ::__gleIsEnabledi(target, index); }
	inline void BeginTransformFeedback(GLenum primitiveMode) { ::__gleBeginTransformFeedback(primitiveMode); }
	inline void EndTransformFeedback() { ::__gleEndTransformFeedback(); }
	inline void BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) { ::__gleBindBufferRange(target, index, buffer, offset, size); }
	inline void BindBufferBase(GLenum target, GLuint index, GLuint buffer) { ::__gleBindBufferBase(target, index, buffer); }
	inline void TransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode) { ::__gleTransformFeedbackVaryings(program, count, varyings, bufferMode); }
	inline void GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) { ::__gleGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name); }
	inline void ClampColor(GLenum target, GLenum clamp) { ::__gleClampColor(target, clamp); }
	inline void BeginConditionalRender(GLuint id, GLenum mode) { ::__gleBeginConditionalRender(id, mode); }
	inline void EndConditionalRender() { ::__gleEndConditionalRender(); }
	inline void VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleVertexAttribIPointer(index, size, type, stride, pointer); }
	inline void GetVertexAttribIiv(GLuint index, GLenum pname, GLint *params) { ::__gleGetVertexAttribIiv(index, pname, params); }
	inline void GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params) { ::__gleGetVertexAttribIuiv(index, pname, params); }
	inline void VertexAttribI1i(GLuint index, GLint x) { ::__gleVertexAttribI1i(index, x); }
	inline void VertexAttribI2i(GLuint index, GLint x, GLint y) { ::__gleVertexAttribI2i(index, x, y); }
	inline void VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) { ::__gleVertexAttribI3i(index, x, y, z); }
	inline void VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) { ::__gleVertexAttribI4i(index, x, y, z, w); }
	inline void VertexAttribI1ui(GLuint index, GLuint x) { ::__gleVertexAttribI1ui(index, x); }
	inline void VertexAttribI2ui(GLuint index, GLuint x, GLuint y) { ::__gleVertexAttribI2ui(index, x, y); }
	inline void VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) { ::__gleVertexAttribI3ui(index, x, y, z); }
	inline void VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) { ::__gleVertexAttribI4ui(index, x, y, z, w); }
	inline void VertexAttribI1iv(GLuint index, const GLint *v) { ::__gleVertexAttribI1iv(index, v); }
	inline void VertexAttribI2iv(GLuint index, const GLint *v) { ::__gleVertexAttribI2iv(index, v); }
	inline void VertexAttribI3iv(GLuint index, const GLint *v) { ::__gleVertexAttribI3iv(index, v); }
	inline void VertexAttribI4iv(GLuint index, const GLint *v) { ::__gleVertexAttribI4iv(index, v); }
	inline void VertexAttribI1uiv(GLuint index, const GLuint *v) { ::__gleVertexAttribI1uiv(index, v); }
	inline void VertexAttribI2uiv(GLuint index, const GLuint *v) { ::__gleVertexAttribI2uiv(index, v); }
	inline void VertexAttribI3uiv(GLuint index, const GLuint *v) { ::__gleVertexAttribI3uiv(index, v); }
	inline void VertexAttribI4uiv(GLuint index, const GLuint *v) { ::__gleVertexAttribI4uiv(index, v); }
	inline void VertexAttribI4bv(GLuint index, const GLbyte *v) { ::__gleVertexAttribI4bv(index, v); }
	inline void VertexAttribI4sv(GLuint index, const GLshort *v) { ::__gleVertexAttribI4sv(index, v); }
	inline void VertexAttribI4ubv(GLuint index, const GLubyte *v) { ::__gleVertexAttribI4ubv(index, v); }
	inline void VertexAttribI4usv(GLuint index, const GLushort *v) { ::__gleVertexAttribI4usv(index, v); }
	inline void GetUniformuiv(GLuint program, GLint location, GLuint *params) { ::__gleGetUniformuiv(program, location, params); }
	inline void BindFragDataLocation(GLuint program, GLuint color, const GLchar *name) { ::__gleBindFragDataLocation(program, color, name); }
	inline GLint GetFragDataLocation(GLuint program, const GLchar *name) { return ::__gleGetFragDataLocation(program, name); }
	inline void Uniform1ui(GLint location, GLuint v0) { ::__gleUniform1ui(location, v0); }
	inline void Uniform2ui(GLint location, GLuint v0, GLuint v1) { ::__gleUniform2ui(location, v0, v1); }
	inline void Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) { ::__gleUniform3ui(location, v0, v1, v2); }
	inline void Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) { ::__gleUniform4ui(location, v0, v1, v2, v3); }
	inline void Uniform1uiv(GLint location, GLsizei count, const GLuint *value) { ::__gleUniform1uiv(location, count, value); }
	inline void Uniform2uiv(GLint location, GLsizei count, const GLuint *value) { ::__gleUniform2uiv(location, count, value); }
	inline void Uniform3uiv(GLint location, GLsizei count, const GLuint *value) { ::__gleUniform3uiv(location, count, value); }
	inline void Uniform4uiv(GLint location, GLsizei count, const GLuint *value) { ::__gleUniform4uiv(location, count, value); }
	inline void TexParameterIiv(GLenum target, GLenum pname, const GLint *params) { ::__gleTexParameterIiv(target, pname, params); }
	inline void TexParameterIuiv(GLenum target, GLenum pname, const GLuint *params) { ::__gleTexParameterIuiv(target, pname, params); }
	inline void GetTexParameterIiv(GLenum target, GLenum pname, GLint *params) { ::__gleGetTexParameterIiv(target, pname, params); }
	inline void GetTexParameterIuiv(GLenum target, GLenum pname, GLuint *params) { ::__gleGetTexParameterIuiv(target, pname, params); }
	inline void ClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value) { ::__gleClearBufferiv(buffer, drawbuffer, value); }
	inline void ClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value) { ::__gleClearBufferuiv(buffer, drawbuffer, value); }
	inline void ClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat *value) { ::__gleClearBufferfv(buffer, drawbuffer, value); }
	inline void ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) { ::__gleClearBufferfi(buffer, drawbuffer, depth, stencil); }
	inline const GLubyte * GetStringi(GLenum name, GLuint index) { return ::__gleGetStringi(name, index); }

}

#endif //_INT_GL_3_0_HPP

