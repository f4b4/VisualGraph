#ifndef _INT_GL_1_3_REM_3_1_HPP
#define _INT_GL_1_3_REM_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleClientActiveTexture)(GLenum );
extern void (GLE_FUNCPTR *__gleMultiTexCoord1d)(GLenum , GLdouble );
extern void (GLE_FUNCPTR *__gleMultiTexCoord1dv)(GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord1f)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleMultiTexCoord1fv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord1i)(GLenum , GLint );
extern void (GLE_FUNCPTR *__gleMultiTexCoord1iv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord1s)(GLenum , GLshort );
extern void (GLE_FUNCPTR *__gleMultiTexCoord1sv)(GLenum , const GLshort *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord2d)(GLenum , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleMultiTexCoord2dv)(GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord2f)(GLenum , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleMultiTexCoord2fv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord2i)(GLenum , GLint , GLint );
extern void (GLE_FUNCPTR *__gleMultiTexCoord2iv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord2s)(GLenum , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleMultiTexCoord2sv)(GLenum , const GLshort *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord3d)(GLenum , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleMultiTexCoord3dv)(GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord3f)(GLenum , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleMultiTexCoord3fv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord3i)(GLenum , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleMultiTexCoord3iv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord3s)(GLenum , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleMultiTexCoord3sv)(GLenum , const GLshort *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord4d)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleMultiTexCoord4dv)(GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord4f)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleMultiTexCoord4fv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord4i)(GLenum , GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleMultiTexCoord4iv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleMultiTexCoord4s)(GLenum , GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleMultiTexCoord4sv)(GLenum , const GLshort *);
extern void (GLE_FUNCPTR *__gleLoadTransposeMatrixf)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleLoadTransposeMatrixd)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleMultTransposeMatrixf)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultTransposeMatrixd)(const GLdouble *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_3_rem_3_1
	{
		GL_CLIENT_ACTIVE_TEXTURE         = 0x84E1,
		GL_MAX_TEXTURE_UNITS             = 0x84E2,
		GL_TRANSPOSE_MODELVIEW_MATRIX    = 0x84E3,
		GL_TRANSPOSE_PROJECTION_MATRIX   = 0x84E4,
		GL_TRANSPOSE_TEXTURE_MATRIX      = 0x84E5,
		GL_TRANSPOSE_COLOR_MATRIX        = 0x84E6,
		GL_MULTISAMPLE_BIT               = 0x20000000,
		GL_NORMAL_MAP                    = 0x8511,
		GL_REFLECTION_MAP                = 0x8512,
		GL_COMPRESSED_ALPHA              = 0x84E9,
		GL_COMPRESSED_LUMINANCE          = 0x84EA,
		GL_COMPRESSED_LUMINANCE_ALPHA    = 0x84EB,
		GL_COMPRESSED_INTENSITY          = 0x84EC,
		GL_COMBINE                       = 0x8570,
		GL_COMBINE_RGB                   = 0x8571,
		GL_COMBINE_ALPHA                 = 0x8572,
		GL_SOURCE0_RGB                   = 0x8580,
		GL_SOURCE1_RGB                   = 0x8581,
		GL_SOURCE2_RGB                   = 0x8582,
		GL_SOURCE0_ALPHA                 = 0x8588,
		GL_SOURCE1_ALPHA                 = 0x8589,
		GL_SOURCE2_ALPHA                 = 0x858A,
		GL_OPERAND0_RGB                  = 0x8590,
		GL_OPERAND1_RGB                  = 0x8591,
		GL_OPERAND2_RGB                  = 0x8592,
		GL_OPERAND0_ALPHA                = 0x8598,
		GL_OPERAND1_ALPHA                = 0x8599,
		GL_OPERAND2_ALPHA                = 0x859A,
		GL_RGB_SCALE                     = 0x8573,
		GL_ADD_SIGNED                    = 0x8574,
		GL_INTERPOLATE                   = 0x8575,
		GL_SUBTRACT                      = 0x84E7,
		GL_CONSTANT                      = 0x8576,
		GL_PRIMARY_COLOR                 = 0x8577,
		GL_PREVIOUS                      = 0x8578,
		GL_DOT3_RGB                      = 0x86AE,
		GL_DOT3_RGBA                     = 0x86AF,
	};

	inline void ClientActiveTexture(GLenum texture) { ::__gleClientActiveTexture(texture); }
	inline void MultiTexCoord1d(GLenum target, GLdouble s) { ::__gleMultiTexCoord1d(target, s); }
	inline void MultiTexCoord1dv(GLenum target, const GLdouble *v) { ::__gleMultiTexCoord1dv(target, v); }
	inline void MultiTexCoord1f(GLenum target, GLfloat s) { ::__gleMultiTexCoord1f(target, s); }
	inline void MultiTexCoord1fv(GLenum target, const GLfloat *v) { ::__gleMultiTexCoord1fv(target, v); }
	inline void MultiTexCoord1i(GLenum target, GLint s) { ::__gleMultiTexCoord1i(target, s); }
	inline void MultiTexCoord1iv(GLenum target, const GLint *v) { ::__gleMultiTexCoord1iv(target, v); }
	inline void MultiTexCoord1s(GLenum target, GLshort s) { ::__gleMultiTexCoord1s(target, s); }
	inline void MultiTexCoord1sv(GLenum target, const GLshort *v) { ::__gleMultiTexCoord1sv(target, v); }
	inline void MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) { ::__gleMultiTexCoord2d(target, s, t); }
	inline void MultiTexCoord2dv(GLenum target, const GLdouble *v) { ::__gleMultiTexCoord2dv(target, v); }
	inline void MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) { ::__gleMultiTexCoord2f(target, s, t); }
	inline void MultiTexCoord2fv(GLenum target, const GLfloat *v) { ::__gleMultiTexCoord2fv(target, v); }
	inline void MultiTexCoord2i(GLenum target, GLint s, GLint t) { ::__gleMultiTexCoord2i(target, s, t); }
	inline void MultiTexCoord2iv(GLenum target, const GLint *v) { ::__gleMultiTexCoord2iv(target, v); }
	inline void MultiTexCoord2s(GLenum target, GLshort s, GLshort t) { ::__gleMultiTexCoord2s(target, s, t); }
	inline void MultiTexCoord2sv(GLenum target, const GLshort *v) { ::__gleMultiTexCoord2sv(target, v); }
	inline void MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) { ::__gleMultiTexCoord3d(target, s, t, r); }
	inline void MultiTexCoord3dv(GLenum target, const GLdouble *v) { ::__gleMultiTexCoord3dv(target, v); }
	inline void MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) { ::__gleMultiTexCoord3f(target, s, t, r); }
	inline void MultiTexCoord3fv(GLenum target, const GLfloat *v) { ::__gleMultiTexCoord3fv(target, v); }
	inline void MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) { ::__gleMultiTexCoord3i(target, s, t, r); }
	inline void MultiTexCoord3iv(GLenum target, const GLint *v) { ::__gleMultiTexCoord3iv(target, v); }
	inline void MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) { ::__gleMultiTexCoord3s(target, s, t, r); }
	inline void MultiTexCoord3sv(GLenum target, const GLshort *v) { ::__gleMultiTexCoord3sv(target, v); }
	inline void MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) { ::__gleMultiTexCoord4d(target, s, t, r, q); }
	inline void MultiTexCoord4dv(GLenum target, const GLdouble *v) { ::__gleMultiTexCoord4dv(target, v); }
	inline void MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) { ::__gleMultiTexCoord4f(target, s, t, r, q); }
	inline void MultiTexCoord4fv(GLenum target, const GLfloat *v) { ::__gleMultiTexCoord4fv(target, v); }
	inline void MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) { ::__gleMultiTexCoord4i(target, s, t, r, q); }
	inline void MultiTexCoord4iv(GLenum target, const GLint *v) { ::__gleMultiTexCoord4iv(target, v); }
	inline void MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) { ::__gleMultiTexCoord4s(target, s, t, r, q); }
	inline void MultiTexCoord4sv(GLenum target, const GLshort *v) { ::__gleMultiTexCoord4sv(target, v); }
	inline void LoadTransposeMatrixf(const GLfloat *m) { ::__gleLoadTransposeMatrixf(m); }
	inline void LoadTransposeMatrixd(const GLdouble *m) { ::__gleLoadTransposeMatrixd(m); }
	inline void MultTransposeMatrixf(const GLfloat *m) { ::__gleMultTransposeMatrixf(m); }
	inline void MultTransposeMatrixd(const GLdouble *m) { ::__gleMultTransposeMatrixd(m); }

}

#endif //_INT_GL_1_3_REM_3_1_HPP

