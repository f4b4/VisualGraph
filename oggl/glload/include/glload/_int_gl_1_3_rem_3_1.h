#ifndef _INT_GL_1_3_REM_3_1_H
#define _INT_GL_1_3_REM_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF
typedef void (GLE_FUNCPTR * PFNGLCLIENTACTIVETEXTUREPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DPROC)(GLenum , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1DVPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1FVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1IVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SPROC)(GLenum , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD1SVPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DPROC)(GLenum , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2DVPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FPROC)(GLenum , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2FVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IPROC)(GLenum , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2IVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SPROC)(GLenum , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD2SVPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3DVPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3FVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IPROC)(GLenum , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3IVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SPROC)(GLenum , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD3SVPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4DVPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4FVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IPROC)(GLenum , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4IVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SPROC)(GLenum , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLMULTITEXCOORD4SVPROC)(GLenum , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *);

extern PFNGLCLIENTACTIVETEXTUREPROC __gleClientActiveTexture;
#define glClientActiveTexture __gleClientActiveTexture
extern PFNGLMULTITEXCOORD1DPROC __gleMultiTexCoord1d;
#define glMultiTexCoord1d __gleMultiTexCoord1d
extern PFNGLMULTITEXCOORD1DVPROC __gleMultiTexCoord1dv;
#define glMultiTexCoord1dv __gleMultiTexCoord1dv
extern PFNGLMULTITEXCOORD1FPROC __gleMultiTexCoord1f;
#define glMultiTexCoord1f __gleMultiTexCoord1f
extern PFNGLMULTITEXCOORD1FVPROC __gleMultiTexCoord1fv;
#define glMultiTexCoord1fv __gleMultiTexCoord1fv
extern PFNGLMULTITEXCOORD1IPROC __gleMultiTexCoord1i;
#define glMultiTexCoord1i __gleMultiTexCoord1i
extern PFNGLMULTITEXCOORD1IVPROC __gleMultiTexCoord1iv;
#define glMultiTexCoord1iv __gleMultiTexCoord1iv
extern PFNGLMULTITEXCOORD1SPROC __gleMultiTexCoord1s;
#define glMultiTexCoord1s __gleMultiTexCoord1s
extern PFNGLMULTITEXCOORD1SVPROC __gleMultiTexCoord1sv;
#define glMultiTexCoord1sv __gleMultiTexCoord1sv
extern PFNGLMULTITEXCOORD2DPROC __gleMultiTexCoord2d;
#define glMultiTexCoord2d __gleMultiTexCoord2d
extern PFNGLMULTITEXCOORD2DVPROC __gleMultiTexCoord2dv;
#define glMultiTexCoord2dv __gleMultiTexCoord2dv
extern PFNGLMULTITEXCOORD2FPROC __gleMultiTexCoord2f;
#define glMultiTexCoord2f __gleMultiTexCoord2f
extern PFNGLMULTITEXCOORD2FVPROC __gleMultiTexCoord2fv;
#define glMultiTexCoord2fv __gleMultiTexCoord2fv
extern PFNGLMULTITEXCOORD2IPROC __gleMultiTexCoord2i;
#define glMultiTexCoord2i __gleMultiTexCoord2i
extern PFNGLMULTITEXCOORD2IVPROC __gleMultiTexCoord2iv;
#define glMultiTexCoord2iv __gleMultiTexCoord2iv
extern PFNGLMULTITEXCOORD2SPROC __gleMultiTexCoord2s;
#define glMultiTexCoord2s __gleMultiTexCoord2s
extern PFNGLMULTITEXCOORD2SVPROC __gleMultiTexCoord2sv;
#define glMultiTexCoord2sv __gleMultiTexCoord2sv
extern PFNGLMULTITEXCOORD3DPROC __gleMultiTexCoord3d;
#define glMultiTexCoord3d __gleMultiTexCoord3d
extern PFNGLMULTITEXCOORD3DVPROC __gleMultiTexCoord3dv;
#define glMultiTexCoord3dv __gleMultiTexCoord3dv
extern PFNGLMULTITEXCOORD3FPROC __gleMultiTexCoord3f;
#define glMultiTexCoord3f __gleMultiTexCoord3f
extern PFNGLMULTITEXCOORD3FVPROC __gleMultiTexCoord3fv;
#define glMultiTexCoord3fv __gleMultiTexCoord3fv
extern PFNGLMULTITEXCOORD3IPROC __gleMultiTexCoord3i;
#define glMultiTexCoord3i __gleMultiTexCoord3i
extern PFNGLMULTITEXCOORD3IVPROC __gleMultiTexCoord3iv;
#define glMultiTexCoord3iv __gleMultiTexCoord3iv
extern PFNGLMULTITEXCOORD3SPROC __gleMultiTexCoord3s;
#define glMultiTexCoord3s __gleMultiTexCoord3s
extern PFNGLMULTITEXCOORD3SVPROC __gleMultiTexCoord3sv;
#define glMultiTexCoord3sv __gleMultiTexCoord3sv
extern PFNGLMULTITEXCOORD4DPROC __gleMultiTexCoord4d;
#define glMultiTexCoord4d __gleMultiTexCoord4d
extern PFNGLMULTITEXCOORD4DVPROC __gleMultiTexCoord4dv;
#define glMultiTexCoord4dv __gleMultiTexCoord4dv
extern PFNGLMULTITEXCOORD4FPROC __gleMultiTexCoord4f;
#define glMultiTexCoord4f __gleMultiTexCoord4f
extern PFNGLMULTITEXCOORD4FVPROC __gleMultiTexCoord4fv;
#define glMultiTexCoord4fv __gleMultiTexCoord4fv
extern PFNGLMULTITEXCOORD4IPROC __gleMultiTexCoord4i;
#define glMultiTexCoord4i __gleMultiTexCoord4i
extern PFNGLMULTITEXCOORD4IVPROC __gleMultiTexCoord4iv;
#define glMultiTexCoord4iv __gleMultiTexCoord4iv
extern PFNGLMULTITEXCOORD4SPROC __gleMultiTexCoord4s;
#define glMultiTexCoord4s __gleMultiTexCoord4s
extern PFNGLMULTITEXCOORD4SVPROC __gleMultiTexCoord4sv;
#define glMultiTexCoord4sv __gleMultiTexCoord4sv
extern PFNGLLOADTRANSPOSEMATRIXFPROC __gleLoadTransposeMatrixf;
#define glLoadTransposeMatrixf __gleLoadTransposeMatrixf
extern PFNGLLOADTRANSPOSEMATRIXDPROC __gleLoadTransposeMatrixd;
#define glLoadTransposeMatrixd __gleLoadTransposeMatrixd
extern PFNGLMULTTRANSPOSEMATRIXFPROC __gleMultTransposeMatrixf;
#define glMultTransposeMatrixf __gleMultTransposeMatrixf
extern PFNGLMULTTRANSPOSEMATRIXDPROC __gleMultTransposeMatrixd;
#define glMultTransposeMatrixd __gleMultTransposeMatrixd


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_3_REM_3_1_H

