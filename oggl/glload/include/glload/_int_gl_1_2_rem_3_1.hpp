#ifndef _INT_GL_1_2_REM_3_1_HPP
#define _INT_GL_1_2_REM_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleTexImage3D)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleColorTable)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleColorTableParameterfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleColorTableParameteriv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleCopyColorTable)(GLenum , GLenum , GLint , GLint , GLsizei );
extern void (GLE_FUNCPTR *__gleGetColorTable)(GLenum , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetColorTableParameterfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetColorTableParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleColorSubTable)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleCopyColorSubTable)(GLenum , GLsizei , GLint , GLint , GLsizei );
extern void (GLE_FUNCPTR *__gleConvolutionFilter1D)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleConvolutionFilter2D)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleConvolutionParameterf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleConvolutionParameterfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleConvolutionParameteri)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleConvolutionParameteriv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleCopyConvolutionFilter1D)(GLenum , GLenum , GLint , GLint , GLsizei );
extern void (GLE_FUNCPTR *__gleCopyConvolutionFilter2D)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
extern void (GLE_FUNCPTR *__gleGetConvolutionFilter)(GLenum , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetConvolutionParameterfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetConvolutionParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetSeparableFilter)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
extern void (GLE_FUNCPTR *__gleSeparableFilter2D)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetHistogram)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetHistogramParameterfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetHistogramParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetMinmax)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
extern void (GLE_FUNCPTR *__gleGetMinmaxParameterfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetMinmaxParameteriv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleHistogram)(GLenum , GLsizei , GLenum , GLboolean );
extern void (GLE_FUNCPTR *__gleMinmax)(GLenum , GLenum , GLboolean );
extern void (GLE_FUNCPTR *__gleResetHistogram)(GLenum );
extern void (GLE_FUNCPTR *__gleResetMinmax)(GLenum );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_2_rem_3_1
	{
		GL_RESCALE_NORMAL                = 0x803A,
		GL_LIGHT_MODEL_COLOR_CONTROL     = 0x81F8,
		GL_SINGLE_COLOR                  = 0x81F9,
		GL_SEPARATE_SPECULAR_COLOR       = 0x81FA,
		GL_ALIASED_POINT_SIZE_RANGE      = 0x846D,
	};

	inline void TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels); }
	inline void ColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table) { ::__gleColorTable(target, internalformat, width, format, type, table); }
	inline void ColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params) { ::__gleColorTableParameterfv(target, pname, params); }
	inline void ColorTableParameteriv(GLenum target, GLenum pname, const GLint *params) { ::__gleColorTableParameteriv(target, pname, params); }
	inline void CopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) { ::__gleCopyColorTable(target, internalformat, x, y, width); }
	inline void GetColorTable(GLenum target, GLenum format, GLenum type, GLvoid *table) { ::__gleGetColorTable(target, format, type, table); }
	inline void GetColorTableParameterfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetColorTableParameterfv(target, pname, params); }
	inline void GetColorTableParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetColorTableParameteriv(target, pname, params); }
	inline void ColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data) { ::__gleColorSubTable(target, start, count, format, type, data); }
	inline void CopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) { ::__gleCopyColorSubTable(target, start, x, y, width); }
	inline void ConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image) { ::__gleConvolutionFilter1D(target, internalformat, width, format, type, image); }
	inline void ConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image) { ::__gleConvolutionFilter2D(target, internalformat, width, height, format, type, image); }
	inline void ConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) { ::__gleConvolutionParameterf(target, pname, params); }
	inline void ConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params) { ::__gleConvolutionParameterfv(target, pname, params); }
	inline void ConvolutionParameteri(GLenum target, GLenum pname, GLint params) { ::__gleConvolutionParameteri(target, pname, params); }
	inline void ConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params) { ::__gleConvolutionParameteriv(target, pname, params); }
	inline void CopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) { ::__gleCopyConvolutionFilter1D(target, internalformat, x, y, width); }
	inline void CopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) { ::__gleCopyConvolutionFilter2D(target, internalformat, x, y, width, height); }
	inline void GetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid *image) { ::__gleGetConvolutionFilter(target, format, type, image); }
	inline void GetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetConvolutionParameterfv(target, pname, params); }
	inline void GetConvolutionParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetConvolutionParameteriv(target, pname, params); }
	inline void GetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span) { ::__gleGetSeparableFilter(target, format, type, row, column, span); }
	inline void SeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column) { ::__gleSeparableFilter2D(target, internalformat, width, height, format, type, row, column); }
	inline void GetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values) { ::__gleGetHistogram(target, reset, format, type, values); }
	inline void GetHistogramParameterfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetHistogramParameterfv(target, pname, params); }
	inline void GetHistogramParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetHistogramParameteriv(target, pname, params); }
	inline void GetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values) { ::__gleGetMinmax(target, reset, format, type, values); }
	inline void GetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetMinmaxParameterfv(target, pname, params); }
	inline void GetMinmaxParameteriv(GLenum target, GLenum pname, GLint *params) { ::__gleGetMinmaxParameteriv(target, pname, params); }
	inline void Histogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) { ::__gleHistogram(target, width, internalformat, sink); }
	inline void Minmax(GLenum target, GLenum internalformat, GLboolean sink) { ::__gleMinmax(target, internalformat, sink); }
	inline void ResetHistogram(GLenum target) { ::__gleResetHistogram(target); }
	inline void ResetMinmax(GLenum target) { ::__gleResetMinmax(target); }

}

#endif //_INT_GL_1_2_REM_3_1_HPP

