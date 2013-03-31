#ifndef _INT_GL_1_4_REM_3_1_HPP
#define _INT_GL_1_4_REM_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleFogCoordf)(GLfloat );
extern void (GLE_FUNCPTR *__gleFogCoordfv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleFogCoordd)(GLdouble );
extern void (GLE_FUNCPTR *__gleFogCoorddv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleFogCoordPointer)(GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3b)(GLbyte , GLbyte , GLbyte );
extern void (GLE_FUNCPTR *__gleSecondaryColor3bv)(const GLbyte *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleSecondaryColor3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleSecondaryColor3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleSecondaryColor3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleSecondaryColor3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3ub)(GLubyte , GLubyte , GLubyte );
extern void (GLE_FUNCPTR *__gleSecondaryColor3ubv)(const GLubyte *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3ui)(GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleSecondaryColor3uiv)(const GLuint *);
extern void (GLE_FUNCPTR *__gleSecondaryColor3us)(GLushort , GLushort , GLushort );
extern void (GLE_FUNCPTR *__gleSecondaryColor3usv)(const GLushort *);
extern void (GLE_FUNCPTR *__gleSecondaryColorPointer)(GLint , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleWindowPos2d)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleWindowPos2dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleWindowPos2f)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleWindowPos2fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleWindowPos2i)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleWindowPos2iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleWindowPos2s)(GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleWindowPos2sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleWindowPos3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleWindowPos3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleWindowPos3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleWindowPos3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleWindowPos3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleWindowPos3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleWindowPos3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleWindowPos3sv)(const GLshort *);
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_4_rem_3_1
	{
		GL_POINT_SIZE_MIN                = 0x8126,
		GL_POINT_SIZE_MAX                = 0x8127,
		GL_POINT_DISTANCE_ATTENUATION    = 0x8129,
		GL_GENERATE_MIPMAP               = 0x8191,
		GL_GENERATE_MIPMAP_HINT          = 0x8192,
		GL_FOG_COORDINATE_SOURCE         = 0x8450,
		GL_FOG_COORDINATE                = 0x8451,
		GL_FRAGMENT_DEPTH                = 0x8452,
		GL_CURRENT_FOG_COORDINATE        = 0x8453,
		GL_FOG_COORDINATE_ARRAY_TYPE     = 0x8454,
		GL_FOG_COORDINATE_ARRAY_STRIDE   = 0x8455,
		GL_FOG_COORDINATE_ARRAY_POINTER  = 0x8456,
		GL_FOG_COORDINATE_ARRAY          = 0x8457,
		GL_COLOR_SUM                     = 0x8458,
		GL_CURRENT_SECONDARY_COLOR       = 0x8459,
		GL_SECONDARY_COLOR_ARRAY_SIZE    = 0x845A,
		GL_SECONDARY_COLOR_ARRAY_TYPE    = 0x845B,
		GL_SECONDARY_COLOR_ARRAY_STRIDE  = 0x845C,
		GL_SECONDARY_COLOR_ARRAY_POINTER = 0x845D,
		GL_SECONDARY_COLOR_ARRAY         = 0x845E,
		GL_TEXTURE_FILTER_CONTROL        = 0x8500,
		GL_DEPTH_TEXTURE_MODE            = 0x884B,
		GL_COMPARE_R_TO_TEXTURE          = 0x884E,
	};

	inline void FogCoordf(GLfloat coord) { ::__gleFogCoordf(coord); }
	inline void FogCoordfv(const GLfloat *coord) { ::__gleFogCoordfv(coord); }
	inline void FogCoordd(GLdouble coord) { ::__gleFogCoordd(coord); }
	inline void FogCoorddv(const GLdouble *coord) { ::__gleFogCoorddv(coord); }
	inline void FogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleFogCoordPointer(type, stride, pointer); }
	inline void SecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) { ::__gleSecondaryColor3b(red, green, blue); }
	inline void SecondaryColor3bv(const GLbyte *v) { ::__gleSecondaryColor3bv(v); }
	inline void SecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) { ::__gleSecondaryColor3d(red, green, blue); }
	inline void SecondaryColor3dv(const GLdouble *v) { ::__gleSecondaryColor3dv(v); }
	inline void SecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) { ::__gleSecondaryColor3f(red, green, blue); }
	inline void SecondaryColor3fv(const GLfloat *v) { ::__gleSecondaryColor3fv(v); }
	inline void SecondaryColor3i(GLint red, GLint green, GLint blue) { ::__gleSecondaryColor3i(red, green, blue); }
	inline void SecondaryColor3iv(const GLint *v) { ::__gleSecondaryColor3iv(v); }
	inline void SecondaryColor3s(GLshort red, GLshort green, GLshort blue) { ::__gleSecondaryColor3s(red, green, blue); }
	inline void SecondaryColor3sv(const GLshort *v) { ::__gleSecondaryColor3sv(v); }
	inline void SecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) { ::__gleSecondaryColor3ub(red, green, blue); }
	inline void SecondaryColor3ubv(const GLubyte *v) { ::__gleSecondaryColor3ubv(v); }
	inline void SecondaryColor3ui(GLuint red, GLuint green, GLuint blue) { ::__gleSecondaryColor3ui(red, green, blue); }
	inline void SecondaryColor3uiv(const GLuint *v) { ::__gleSecondaryColor3uiv(v); }
	inline void SecondaryColor3us(GLushort red, GLushort green, GLushort blue) { ::__gleSecondaryColor3us(red, green, blue); }
	inline void SecondaryColor3usv(const GLushort *v) { ::__gleSecondaryColor3usv(v); }
	inline void SecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleSecondaryColorPointer(size, type, stride, pointer); }
	inline void WindowPos2d(GLdouble x, GLdouble y) { ::__gleWindowPos2d(x, y); }
	inline void WindowPos2dv(const GLdouble *v) { ::__gleWindowPos2dv(v); }
	inline void WindowPos2f(GLfloat x, GLfloat y) { ::__gleWindowPos2f(x, y); }
	inline void WindowPos2fv(const GLfloat *v) { ::__gleWindowPos2fv(v); }
	inline void WindowPos2i(GLint x, GLint y) { ::__gleWindowPos2i(x, y); }
	inline void WindowPos2iv(const GLint *v) { ::__gleWindowPos2iv(v); }
	inline void WindowPos2s(GLshort x, GLshort y) { ::__gleWindowPos2s(x, y); }
	inline void WindowPos2sv(const GLshort *v) { ::__gleWindowPos2sv(v); }
	inline void WindowPos3d(GLdouble x, GLdouble y, GLdouble z) { ::__gleWindowPos3d(x, y, z); }
	inline void WindowPos3dv(const GLdouble *v) { ::__gleWindowPos3dv(v); }
	inline void WindowPos3f(GLfloat x, GLfloat y, GLfloat z) { ::__gleWindowPos3f(x, y, z); }
	inline void WindowPos3fv(const GLfloat *v) { ::__gleWindowPos3fv(v); }
	inline void WindowPos3i(GLint x, GLint y, GLint z) { ::__gleWindowPos3i(x, y, z); }
	inline void WindowPos3iv(const GLint *v) { ::__gleWindowPos3iv(v); }
	inline void WindowPos3s(GLshort x, GLshort y, GLshort z) { ::__gleWindowPos3s(x, y, z); }
	inline void WindowPos3sv(const GLshort *v) { ::__gleWindowPos3sv(v); }

}

#endif //_INT_GL_1_4_REM_3_1_HPP

