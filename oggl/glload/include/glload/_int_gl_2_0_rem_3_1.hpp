#ifndef _INT_GL_2_0_REM_3_1_HPP
#define _INT_GL_2_0_REM_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleVertexAttrib1d)(GLuint , GLdouble );
extern void (GLE_FUNCPTR *__gleVertexAttrib1dv)(GLuint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertexAttrib1f)(GLuint , GLfloat );
extern void (GLE_FUNCPTR *__gleVertexAttrib1fv)(GLuint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertexAttrib1s)(GLuint , GLshort );
extern void (GLE_FUNCPTR *__gleVertexAttrib1sv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib2d)(GLuint , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertexAttrib2dv)(GLuint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertexAttrib2f)(GLuint , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertexAttrib2fv)(GLuint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertexAttrib2s)(GLuint , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertexAttrib2sv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib3d)(GLuint , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertexAttrib3dv)(GLuint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertexAttrib3f)(GLuint , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertexAttrib3fv)(GLuint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertexAttrib3s)(GLuint , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertexAttrib3sv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nbv)(GLuint , const GLbyte *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Niv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nsv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nub)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nubv)(GLuint , const GLubyte *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nuiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4Nusv)(GLuint , const GLushort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4bv)(GLuint , const GLbyte *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4d)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertexAttrib4dv)(GLuint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4f)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertexAttrib4fv)(GLuint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4iv)(GLuint , const GLint *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4s)(GLuint , GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertexAttrib4sv)(GLuint , const GLshort *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4ubv)(GLuint , const GLubyte *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4uiv)(GLuint , const GLuint *);
extern void (GLE_FUNCPTR *__gleVertexAttrib4usv)(GLuint , const GLushort *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_2_0_rem_3_1
	{
		GL_VERTEX_PROGRAM_TWO_SIDE       = 0x8643,
		GL_POINT_SPRITE                  = 0x8861,
		GL_COORD_REPLACE                 = 0x8862,
		GL_MAX_TEXTURE_COORDS            = 0x8871,
	};

	inline void VertexAttrib1d(GLuint index, GLdouble x) { ::__gleVertexAttrib1d(index, x); }
	inline void VertexAttrib1dv(GLuint index, const GLdouble *v) { ::__gleVertexAttrib1dv(index, v); }
	inline void VertexAttrib1f(GLuint index, GLfloat x) { ::__gleVertexAttrib1f(index, x); }
	inline void VertexAttrib1fv(GLuint index, const GLfloat *v) { ::__gleVertexAttrib1fv(index, v); }
	inline void VertexAttrib1s(GLuint index, GLshort x) { ::__gleVertexAttrib1s(index, x); }
	inline void VertexAttrib1sv(GLuint index, const GLshort *v) { ::__gleVertexAttrib1sv(index, v); }
	inline void VertexAttrib2d(GLuint index, GLdouble x, GLdouble y) { ::__gleVertexAttrib2d(index, x, y); }
	inline void VertexAttrib2dv(GLuint index, const GLdouble *v) { ::__gleVertexAttrib2dv(index, v); }
	inline void VertexAttrib2f(GLuint index, GLfloat x, GLfloat y) { ::__gleVertexAttrib2f(index, x, y); }
	inline void VertexAttrib2fv(GLuint index, const GLfloat *v) { ::__gleVertexAttrib2fv(index, v); }
	inline void VertexAttrib2s(GLuint index, GLshort x, GLshort y) { ::__gleVertexAttrib2s(index, x, y); }
	inline void VertexAttrib2sv(GLuint index, const GLshort *v) { ::__gleVertexAttrib2sv(index, v); }
	inline void VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) { ::__gleVertexAttrib3d(index, x, y, z); }
	inline void VertexAttrib3dv(GLuint index, const GLdouble *v) { ::__gleVertexAttrib3dv(index, v); }
	inline void VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) { ::__gleVertexAttrib3f(index, x, y, z); }
	inline void VertexAttrib3fv(GLuint index, const GLfloat *v) { ::__gleVertexAttrib3fv(index, v); }
	inline void VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) { ::__gleVertexAttrib3s(index, x, y, z); }
	inline void VertexAttrib3sv(GLuint index, const GLshort *v) { ::__gleVertexAttrib3sv(index, v); }
	inline void VertexAttrib4Nbv(GLuint index, const GLbyte *v) { ::__gleVertexAttrib4Nbv(index, v); }
	inline void VertexAttrib4Niv(GLuint index, const GLint *v) { ::__gleVertexAttrib4Niv(index, v); }
	inline void VertexAttrib4Nsv(GLuint index, const GLshort *v) { ::__gleVertexAttrib4Nsv(index, v); }
	inline void VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) { ::__gleVertexAttrib4Nub(index, x, y, z, w); }
	inline void VertexAttrib4Nubv(GLuint index, const GLubyte *v) { ::__gleVertexAttrib4Nubv(index, v); }
	inline void VertexAttrib4Nuiv(GLuint index, const GLuint *v) { ::__gleVertexAttrib4Nuiv(index, v); }
	inline void VertexAttrib4Nusv(GLuint index, const GLushort *v) { ::__gleVertexAttrib4Nusv(index, v); }
	inline void VertexAttrib4bv(GLuint index, const GLbyte *v) { ::__gleVertexAttrib4bv(index, v); }
	inline void VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ::__gleVertexAttrib4d(index, x, y, z, w); }
	inline void VertexAttrib4dv(GLuint index, const GLdouble *v) { ::__gleVertexAttrib4dv(index, v); }
	inline void VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) { ::__gleVertexAttrib4f(index, x, y, z, w); }
	inline void VertexAttrib4fv(GLuint index, const GLfloat *v) { ::__gleVertexAttrib4fv(index, v); }
	inline void VertexAttrib4iv(GLuint index, const GLint *v) { ::__gleVertexAttrib4iv(index, v); }
	inline void VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) { ::__gleVertexAttrib4s(index, x, y, z, w); }
	inline void VertexAttrib4sv(GLuint index, const GLshort *v) { ::__gleVertexAttrib4sv(index, v); }
	inline void VertexAttrib4ubv(GLuint index, const GLubyte *v) { ::__gleVertexAttrib4ubv(index, v); }
	inline void VertexAttrib4uiv(GLuint index, const GLuint *v) { ::__gleVertexAttrib4uiv(index, v); }
	inline void VertexAttrib4usv(GLuint index, const GLushort *v) { ::__gleVertexAttrib4usv(index, v); }

}

#endif //_INT_GL_2_0_REM_3_1_HPP

