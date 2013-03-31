#ifndef _INT_GL_1_4_REM_3_1_H
#define _INT_GL_1_4_REM_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_POINT_SIZE_MIN 0x8126
#define GL_POINT_SIZE_MAX 0x8127
#define GL_POINT_DISTANCE_ATTENUATION 0x8129
#define GL_GENERATE_MIPMAP 0x8191
#define GL_GENERATE_MIPMAP_HINT 0x8192
#define GL_FOG_COORDINATE_SOURCE 0x8450
#define GL_FOG_COORDINATE 0x8451
#define GL_FRAGMENT_DEPTH 0x8452
#define GL_CURRENT_FOG_COORDINATE 0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define GL_FOG_COORDINATE_ARRAY 0x8457
#define GL_COLOR_SUM 0x8458
#define GL_CURRENT_SECONDARY_COLOR 0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define GL_SECONDARY_COLOR_ARRAY 0x845E
#define GL_TEXTURE_FILTER_CONTROL 0x8500
#define GL_DEPTH_TEXTURE_MODE 0x884B
#define GL_COMPARE_R_TO_TEXTURE 0x884E
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDFVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDDVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLFOGCOORDPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3BVPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBPROC)(GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UBVPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3UIVPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USPROC)(GLushort , GLushort , GLushort );
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLOR3USVPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLSECONDARYCOLORPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS2SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLWINDOWPOS3SVPROC)(const GLshort *);

extern PFNGLFOGCOORDFPROC __gleFogCoordf;
#define glFogCoordf __gleFogCoordf
extern PFNGLFOGCOORDFVPROC __gleFogCoordfv;
#define glFogCoordfv __gleFogCoordfv
extern PFNGLFOGCOORDDPROC __gleFogCoordd;
#define glFogCoordd __gleFogCoordd
extern PFNGLFOGCOORDDVPROC __gleFogCoorddv;
#define glFogCoorddv __gleFogCoorddv
extern PFNGLFOGCOORDPOINTERPROC __gleFogCoordPointer;
#define glFogCoordPointer __gleFogCoordPointer
extern PFNGLSECONDARYCOLOR3BPROC __gleSecondaryColor3b;
#define glSecondaryColor3b __gleSecondaryColor3b
extern PFNGLSECONDARYCOLOR3BVPROC __gleSecondaryColor3bv;
#define glSecondaryColor3bv __gleSecondaryColor3bv
extern PFNGLSECONDARYCOLOR3DPROC __gleSecondaryColor3d;
#define glSecondaryColor3d __gleSecondaryColor3d
extern PFNGLSECONDARYCOLOR3DVPROC __gleSecondaryColor3dv;
#define glSecondaryColor3dv __gleSecondaryColor3dv
extern PFNGLSECONDARYCOLOR3FPROC __gleSecondaryColor3f;
#define glSecondaryColor3f __gleSecondaryColor3f
extern PFNGLSECONDARYCOLOR3FVPROC __gleSecondaryColor3fv;
#define glSecondaryColor3fv __gleSecondaryColor3fv
extern PFNGLSECONDARYCOLOR3IPROC __gleSecondaryColor3i;
#define glSecondaryColor3i __gleSecondaryColor3i
extern PFNGLSECONDARYCOLOR3IVPROC __gleSecondaryColor3iv;
#define glSecondaryColor3iv __gleSecondaryColor3iv
extern PFNGLSECONDARYCOLOR3SPROC __gleSecondaryColor3s;
#define glSecondaryColor3s __gleSecondaryColor3s
extern PFNGLSECONDARYCOLOR3SVPROC __gleSecondaryColor3sv;
#define glSecondaryColor3sv __gleSecondaryColor3sv
extern PFNGLSECONDARYCOLOR3UBPROC __gleSecondaryColor3ub;
#define glSecondaryColor3ub __gleSecondaryColor3ub
extern PFNGLSECONDARYCOLOR3UBVPROC __gleSecondaryColor3ubv;
#define glSecondaryColor3ubv __gleSecondaryColor3ubv
extern PFNGLSECONDARYCOLOR3UIPROC __gleSecondaryColor3ui;
#define glSecondaryColor3ui __gleSecondaryColor3ui
extern PFNGLSECONDARYCOLOR3UIVPROC __gleSecondaryColor3uiv;
#define glSecondaryColor3uiv __gleSecondaryColor3uiv
extern PFNGLSECONDARYCOLOR3USPROC __gleSecondaryColor3us;
#define glSecondaryColor3us __gleSecondaryColor3us
extern PFNGLSECONDARYCOLOR3USVPROC __gleSecondaryColor3usv;
#define glSecondaryColor3usv __gleSecondaryColor3usv
extern PFNGLSECONDARYCOLORPOINTERPROC __gleSecondaryColorPointer;
#define glSecondaryColorPointer __gleSecondaryColorPointer
extern PFNGLWINDOWPOS2DPROC __gleWindowPos2d;
#define glWindowPos2d __gleWindowPos2d
extern PFNGLWINDOWPOS2DVPROC __gleWindowPos2dv;
#define glWindowPos2dv __gleWindowPos2dv
extern PFNGLWINDOWPOS2FPROC __gleWindowPos2f;
#define glWindowPos2f __gleWindowPos2f
extern PFNGLWINDOWPOS2FVPROC __gleWindowPos2fv;
#define glWindowPos2fv __gleWindowPos2fv
extern PFNGLWINDOWPOS2IPROC __gleWindowPos2i;
#define glWindowPos2i __gleWindowPos2i
extern PFNGLWINDOWPOS2IVPROC __gleWindowPos2iv;
#define glWindowPos2iv __gleWindowPos2iv
extern PFNGLWINDOWPOS2SPROC __gleWindowPos2s;
#define glWindowPos2s __gleWindowPos2s
extern PFNGLWINDOWPOS2SVPROC __gleWindowPos2sv;
#define glWindowPos2sv __gleWindowPos2sv
extern PFNGLWINDOWPOS3DPROC __gleWindowPos3d;
#define glWindowPos3d __gleWindowPos3d
extern PFNGLWINDOWPOS3DVPROC __gleWindowPos3dv;
#define glWindowPos3dv __gleWindowPos3dv
extern PFNGLWINDOWPOS3FPROC __gleWindowPos3f;
#define glWindowPos3f __gleWindowPos3f
extern PFNGLWINDOWPOS3FVPROC __gleWindowPos3fv;
#define glWindowPos3fv __gleWindowPos3fv
extern PFNGLWINDOWPOS3IPROC __gleWindowPos3i;
#define glWindowPos3i __gleWindowPos3i
extern PFNGLWINDOWPOS3IVPROC __gleWindowPos3iv;
#define glWindowPos3iv __gleWindowPos3iv
extern PFNGLWINDOWPOS3SPROC __gleWindowPos3s;
#define glWindowPos3s __gleWindowPos3s
extern PFNGLWINDOWPOS3SVPROC __gleWindowPos3sv;
#define glWindowPos3sv __gleWindowPos3sv


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_4_REM_3_1_H

