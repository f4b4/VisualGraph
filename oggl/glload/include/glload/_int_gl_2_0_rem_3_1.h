#ifndef _INT_GL_2_0_REM_3_1_H
#define _INT_GL_2_0_REM_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_TEXTURE_COORDS 0x8871
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DPROC)(GLuint , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FPROC)(GLuint , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1FVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SPROC)(GLuint , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB1SVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DPROC)(GLuint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FPROC)(GLuint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2FVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SPROC)(GLuint , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB2SVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3FVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SPROC)(GLuint , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB3SVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NBVPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NIVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NSVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUBVPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4NUSVPROC)(GLuint , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4BVPROC)(GLuint , const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4DVPROC)(GLuint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4FVPROC)(GLuint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4IVPROC)(GLuint , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SPROC)(GLuint , GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4SVPROC)(GLuint , const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UBVPROC)(GLuint , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4UIVPROC)(GLuint , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXATTRIB4USVPROC)(GLuint , const GLushort *);

extern PFNGLVERTEXATTRIB1DPROC __gleVertexAttrib1d;
#define glVertexAttrib1d __gleVertexAttrib1d
extern PFNGLVERTEXATTRIB1DVPROC __gleVertexAttrib1dv;
#define glVertexAttrib1dv __gleVertexAttrib1dv
extern PFNGLVERTEXATTRIB1FPROC __gleVertexAttrib1f;
#define glVertexAttrib1f __gleVertexAttrib1f
extern PFNGLVERTEXATTRIB1FVPROC __gleVertexAttrib1fv;
#define glVertexAttrib1fv __gleVertexAttrib1fv
extern PFNGLVERTEXATTRIB1SPROC __gleVertexAttrib1s;
#define glVertexAttrib1s __gleVertexAttrib1s
extern PFNGLVERTEXATTRIB1SVPROC __gleVertexAttrib1sv;
#define glVertexAttrib1sv __gleVertexAttrib1sv
extern PFNGLVERTEXATTRIB2DPROC __gleVertexAttrib2d;
#define glVertexAttrib2d __gleVertexAttrib2d
extern PFNGLVERTEXATTRIB2DVPROC __gleVertexAttrib2dv;
#define glVertexAttrib2dv __gleVertexAttrib2dv
extern PFNGLVERTEXATTRIB2FPROC __gleVertexAttrib2f;
#define glVertexAttrib2f __gleVertexAttrib2f
extern PFNGLVERTEXATTRIB2FVPROC __gleVertexAttrib2fv;
#define glVertexAttrib2fv __gleVertexAttrib2fv
extern PFNGLVERTEXATTRIB2SPROC __gleVertexAttrib2s;
#define glVertexAttrib2s __gleVertexAttrib2s
extern PFNGLVERTEXATTRIB2SVPROC __gleVertexAttrib2sv;
#define glVertexAttrib2sv __gleVertexAttrib2sv
extern PFNGLVERTEXATTRIB3DPROC __gleVertexAttrib3d;
#define glVertexAttrib3d __gleVertexAttrib3d
extern PFNGLVERTEXATTRIB3DVPROC __gleVertexAttrib3dv;
#define glVertexAttrib3dv __gleVertexAttrib3dv
extern PFNGLVERTEXATTRIB3FPROC __gleVertexAttrib3f;
#define glVertexAttrib3f __gleVertexAttrib3f
extern PFNGLVERTEXATTRIB3FVPROC __gleVertexAttrib3fv;
#define glVertexAttrib3fv __gleVertexAttrib3fv
extern PFNGLVERTEXATTRIB3SPROC __gleVertexAttrib3s;
#define glVertexAttrib3s __gleVertexAttrib3s
extern PFNGLVERTEXATTRIB3SVPROC __gleVertexAttrib3sv;
#define glVertexAttrib3sv __gleVertexAttrib3sv
extern PFNGLVERTEXATTRIB4NBVPROC __gleVertexAttrib4Nbv;
#define glVertexAttrib4Nbv __gleVertexAttrib4Nbv
extern PFNGLVERTEXATTRIB4NIVPROC __gleVertexAttrib4Niv;
#define glVertexAttrib4Niv __gleVertexAttrib4Niv
extern PFNGLVERTEXATTRIB4NSVPROC __gleVertexAttrib4Nsv;
#define glVertexAttrib4Nsv __gleVertexAttrib4Nsv
extern PFNGLVERTEXATTRIB4NUBPROC __gleVertexAttrib4Nub;
#define glVertexAttrib4Nub __gleVertexAttrib4Nub
extern PFNGLVERTEXATTRIB4NUBVPROC __gleVertexAttrib4Nubv;
#define glVertexAttrib4Nubv __gleVertexAttrib4Nubv
extern PFNGLVERTEXATTRIB4NUIVPROC __gleVertexAttrib4Nuiv;
#define glVertexAttrib4Nuiv __gleVertexAttrib4Nuiv
extern PFNGLVERTEXATTRIB4NUSVPROC __gleVertexAttrib4Nusv;
#define glVertexAttrib4Nusv __gleVertexAttrib4Nusv
extern PFNGLVERTEXATTRIB4BVPROC __gleVertexAttrib4bv;
#define glVertexAttrib4bv __gleVertexAttrib4bv
extern PFNGLVERTEXATTRIB4DPROC __gleVertexAttrib4d;
#define glVertexAttrib4d __gleVertexAttrib4d
extern PFNGLVERTEXATTRIB4DVPROC __gleVertexAttrib4dv;
#define glVertexAttrib4dv __gleVertexAttrib4dv
extern PFNGLVERTEXATTRIB4FPROC __gleVertexAttrib4f;
#define glVertexAttrib4f __gleVertexAttrib4f
extern PFNGLVERTEXATTRIB4FVPROC __gleVertexAttrib4fv;
#define glVertexAttrib4fv __gleVertexAttrib4fv
extern PFNGLVERTEXATTRIB4IVPROC __gleVertexAttrib4iv;
#define glVertexAttrib4iv __gleVertexAttrib4iv
extern PFNGLVERTEXATTRIB4SPROC __gleVertexAttrib4s;
#define glVertexAttrib4s __gleVertexAttrib4s
extern PFNGLVERTEXATTRIB4SVPROC __gleVertexAttrib4sv;
#define glVertexAttrib4sv __gleVertexAttrib4sv
extern PFNGLVERTEXATTRIB4UBVPROC __gleVertexAttrib4ubv;
#define glVertexAttrib4ubv __gleVertexAttrib4ubv
extern PFNGLVERTEXATTRIB4UIVPROC __gleVertexAttrib4uiv;
#define glVertexAttrib4uiv __gleVertexAttrib4uiv
extern PFNGLVERTEXATTRIB4USVPROC __gleVertexAttrib4usv;
#define glVertexAttrib4usv __gleVertexAttrib4usv


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_2_0_REM_3_1_H

