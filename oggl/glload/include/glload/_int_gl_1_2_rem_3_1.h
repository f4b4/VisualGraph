#ifndef _INT_GL_1_2_REM_3_1_H
#define _INT_GL_1_2_REM_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D
typedef void (GLE_FUNCPTR * PFNGLTEXIMAGE3DPROC)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORTABLEPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOLORSUBTABLEPROC)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCOLORSUBTABLEPROC)(GLenum , GLsizei , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETSEPARABLEFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLSEPARABLEFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMINMAXPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLHISTOGRAMPROC)(GLenum , GLsizei , GLenum , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLMINMAXPROC)(GLenum , GLenum , GLboolean );
typedef void (GLE_FUNCPTR * PFNGLRESETHISTOGRAMPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLRESETMINMAXPROC)(GLenum );

extern PFNGLTEXIMAGE3DPROC __gleTexImage3D;
#define glTexImage3D __gleTexImage3D
extern PFNGLCOLORTABLEPROC __gleColorTable;
#define glColorTable __gleColorTable
extern PFNGLCOLORTABLEPARAMETERFVPROC __gleColorTableParameterfv;
#define glColorTableParameterfv __gleColorTableParameterfv
extern PFNGLCOLORTABLEPARAMETERIVPROC __gleColorTableParameteriv;
#define glColorTableParameteriv __gleColorTableParameteriv
extern PFNGLCOPYCOLORTABLEPROC __gleCopyColorTable;
#define glCopyColorTable __gleCopyColorTable
extern PFNGLGETCOLORTABLEPROC __gleGetColorTable;
#define glGetColorTable __gleGetColorTable
extern PFNGLGETCOLORTABLEPARAMETERFVPROC __gleGetColorTableParameterfv;
#define glGetColorTableParameterfv __gleGetColorTableParameterfv
extern PFNGLGETCOLORTABLEPARAMETERIVPROC __gleGetColorTableParameteriv;
#define glGetColorTableParameteriv __gleGetColorTableParameteriv
extern PFNGLCOLORSUBTABLEPROC __gleColorSubTable;
#define glColorSubTable __gleColorSubTable
extern PFNGLCOPYCOLORSUBTABLEPROC __gleCopyColorSubTable;
#define glCopyColorSubTable __gleCopyColorSubTable
extern PFNGLCONVOLUTIONFILTER1DPROC __gleConvolutionFilter1D;
#define glConvolutionFilter1D __gleConvolutionFilter1D
extern PFNGLCONVOLUTIONFILTER2DPROC __gleConvolutionFilter2D;
#define glConvolutionFilter2D __gleConvolutionFilter2D
extern PFNGLCONVOLUTIONPARAMETERFPROC __gleConvolutionParameterf;
#define glConvolutionParameterf __gleConvolutionParameterf
extern PFNGLCONVOLUTIONPARAMETERFVPROC __gleConvolutionParameterfv;
#define glConvolutionParameterfv __gleConvolutionParameterfv
extern PFNGLCONVOLUTIONPARAMETERIPROC __gleConvolutionParameteri;
#define glConvolutionParameteri __gleConvolutionParameteri
extern PFNGLCONVOLUTIONPARAMETERIVPROC __gleConvolutionParameteriv;
#define glConvolutionParameteriv __gleConvolutionParameteriv
extern PFNGLCOPYCONVOLUTIONFILTER1DPROC __gleCopyConvolutionFilter1D;
#define glCopyConvolutionFilter1D __gleCopyConvolutionFilter1D
extern PFNGLCOPYCONVOLUTIONFILTER2DPROC __gleCopyConvolutionFilter2D;
#define glCopyConvolutionFilter2D __gleCopyConvolutionFilter2D
extern PFNGLGETCONVOLUTIONFILTERPROC __gleGetConvolutionFilter;
#define glGetConvolutionFilter __gleGetConvolutionFilter
extern PFNGLGETCONVOLUTIONPARAMETERFVPROC __gleGetConvolutionParameterfv;
#define glGetConvolutionParameterfv __gleGetConvolutionParameterfv
extern PFNGLGETCONVOLUTIONPARAMETERIVPROC __gleGetConvolutionParameteriv;
#define glGetConvolutionParameteriv __gleGetConvolutionParameteriv
extern PFNGLGETSEPARABLEFILTERPROC __gleGetSeparableFilter;
#define glGetSeparableFilter __gleGetSeparableFilter
extern PFNGLSEPARABLEFILTER2DPROC __gleSeparableFilter2D;
#define glSeparableFilter2D __gleSeparableFilter2D
extern PFNGLGETHISTOGRAMPROC __gleGetHistogram;
#define glGetHistogram __gleGetHistogram
extern PFNGLGETHISTOGRAMPARAMETERFVPROC __gleGetHistogramParameterfv;
#define glGetHistogramParameterfv __gleGetHistogramParameterfv
extern PFNGLGETHISTOGRAMPARAMETERIVPROC __gleGetHistogramParameteriv;
#define glGetHistogramParameteriv __gleGetHistogramParameteriv
extern PFNGLGETMINMAXPROC __gleGetMinmax;
#define glGetMinmax __gleGetMinmax
extern PFNGLGETMINMAXPARAMETERFVPROC __gleGetMinmaxParameterfv;
#define glGetMinmaxParameterfv __gleGetMinmaxParameterfv
extern PFNGLGETMINMAXPARAMETERIVPROC __gleGetMinmaxParameteriv;
#define glGetMinmaxParameteriv __gleGetMinmaxParameteriv
extern PFNGLHISTOGRAMPROC __gleHistogram;
#define glHistogram __gleHistogram
extern PFNGLMINMAXPROC __gleMinmax;
#define glMinmax __gleMinmax
extern PFNGLRESETHISTOGRAMPROC __gleResetHistogram;
#define glResetHistogram __gleResetHistogram
extern PFNGLRESETMINMAXPROC __gleResetMinmax;
#define glResetMinmax __gleResetMinmax


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_2_REM_3_1_H

