#ifndef _INT_GL_1_1_REM_3_1_HPP
#define _INT_GL_1_1_REM_3_1_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleNewList)(GLuint , GLenum );
extern void (GLE_FUNCPTR *__gleEndList)();
extern void (GLE_FUNCPTR *__gleCallList)(GLuint );
extern void (GLE_FUNCPTR *__gleCallLists)(GLsizei , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleDeleteLists)(GLuint , GLsizei );
extern GLuint (GLE_FUNCPTR *__gleGenLists)(GLsizei );
extern void (GLE_FUNCPTR *__gleListBase)(GLuint );
extern void (GLE_FUNCPTR *__gleBegin)(GLenum );
extern void (GLE_FUNCPTR *__gleBitmap)(GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *);
extern void (GLE_FUNCPTR *__gleColor3b)(GLbyte , GLbyte , GLbyte );
extern void (GLE_FUNCPTR *__gleColor3bv)(const GLbyte *);
extern void (GLE_FUNCPTR *__gleColor3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleColor3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleColor3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleColor3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleColor3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleColor3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleColor3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleColor3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleColor3ub)(GLubyte , GLubyte , GLubyte );
extern void (GLE_FUNCPTR *__gleColor3ubv)(const GLubyte *);
extern void (GLE_FUNCPTR *__gleColor3ui)(GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleColor3uiv)(const GLuint *);
extern void (GLE_FUNCPTR *__gleColor3us)(GLushort , GLushort , GLushort );
extern void (GLE_FUNCPTR *__gleColor3usv)(const GLushort *);
extern void (GLE_FUNCPTR *__gleColor4b)(GLbyte , GLbyte , GLbyte , GLbyte );
extern void (GLE_FUNCPTR *__gleColor4bv)(const GLbyte *);
extern void (GLE_FUNCPTR *__gleColor4d)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleColor4dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleColor4f)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleColor4fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleColor4i)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleColor4iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleColor4s)(GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleColor4sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleColor4ub)(GLubyte , GLubyte , GLubyte , GLubyte );
extern void (GLE_FUNCPTR *__gleColor4ubv)(const GLubyte *);
extern void (GLE_FUNCPTR *__gleColor4ui)(GLuint , GLuint , GLuint , GLuint );
extern void (GLE_FUNCPTR *__gleColor4uiv)(const GLuint *);
extern void (GLE_FUNCPTR *__gleColor4us)(GLushort , GLushort , GLushort , GLushort );
extern void (GLE_FUNCPTR *__gleColor4usv)(const GLushort *);
extern void (GLE_FUNCPTR *__gleEdgeFlag)(GLboolean );
extern void (GLE_FUNCPTR *__gleEdgeFlagv)(const GLboolean *);
extern void (GLE_FUNCPTR *__gleEnd)();
extern void (GLE_FUNCPTR *__gleIndexd)(GLdouble );
extern void (GLE_FUNCPTR *__gleIndexdv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleIndexf)(GLfloat );
extern void (GLE_FUNCPTR *__gleIndexfv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleIndexi)(GLint );
extern void (GLE_FUNCPTR *__gleIndexiv)(const GLint *);
extern void (GLE_FUNCPTR *__gleIndexs)(GLshort );
extern void (GLE_FUNCPTR *__gleIndexsv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleNormal3b)(GLbyte , GLbyte , GLbyte );
extern void (GLE_FUNCPTR *__gleNormal3bv)(const GLbyte *);
extern void (GLE_FUNCPTR *__gleNormal3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleNormal3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleNormal3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleNormal3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleNormal3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleNormal3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleNormal3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleNormal3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleRasterPos2d)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleRasterPos2dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleRasterPos2f)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleRasterPos2fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleRasterPos2i)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleRasterPos2iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleRasterPos2s)(GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleRasterPos2sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleRasterPos3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleRasterPos3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleRasterPos3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleRasterPos3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleRasterPos3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleRasterPos3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleRasterPos3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleRasterPos3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleRasterPos4d)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleRasterPos4dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleRasterPos4f)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleRasterPos4fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleRasterPos4i)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleRasterPos4iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleRasterPos4s)(GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleRasterPos4sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleRectd)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleRectdv)(const GLdouble *, const GLdouble *);
extern void (GLE_FUNCPTR *__gleRectf)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleRectfv)(const GLfloat *, const GLfloat *);
extern void (GLE_FUNCPTR *__gleRecti)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleRectiv)(const GLint *, const GLint *);
extern void (GLE_FUNCPTR *__gleRects)(GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleRectsv)(const GLshort *, const GLshort *);
extern void (GLE_FUNCPTR *__gleTexCoord1d)(GLdouble );
extern void (GLE_FUNCPTR *__gleTexCoord1dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleTexCoord1f)(GLfloat );
extern void (GLE_FUNCPTR *__gleTexCoord1fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexCoord1i)(GLint );
extern void (GLE_FUNCPTR *__gleTexCoord1iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleTexCoord1s)(GLshort );
extern void (GLE_FUNCPTR *__gleTexCoord1sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleTexCoord2d)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleTexCoord2dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleTexCoord2f)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleTexCoord2fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexCoord2i)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleTexCoord2iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleTexCoord2s)(GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleTexCoord2sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleTexCoord3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleTexCoord3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleTexCoord3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleTexCoord3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexCoord3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleTexCoord3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleTexCoord3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleTexCoord3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleTexCoord4d)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleTexCoord4dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleTexCoord4f)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleTexCoord4fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexCoord4i)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleTexCoord4iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleTexCoord4s)(GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleTexCoord4sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleVertex2d)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertex2dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertex2f)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertex2fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertex2i)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertex2iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleVertex2s)(GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertex2sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleVertex3d)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertex3dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertex3f)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertex3fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertex3i)(GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertex3iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleVertex3s)(GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertex3sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleVertex4d)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleVertex4dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleVertex4f)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleVertex4fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleVertex4i)(GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleVertex4iv)(const GLint *);
extern void (GLE_FUNCPTR *__gleVertex4s)(GLshort , GLshort , GLshort , GLshort );
extern void (GLE_FUNCPTR *__gleVertex4sv)(const GLshort *);
extern void (GLE_FUNCPTR *__gleClipPlane)(GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleColorMaterial)(GLenum , GLenum );
extern void (GLE_FUNCPTR *__gleFogf)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleFogfv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleFogi)(GLenum , GLint );
extern void (GLE_FUNCPTR *__gleFogiv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleLightf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleLightfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleLighti)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleLightiv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleLightModelf)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleLightModelfv)(GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleLightModeli)(GLenum , GLint );
extern void (GLE_FUNCPTR *__gleLightModeliv)(GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleLineStipple)(GLint , GLushort );
extern void (GLE_FUNCPTR *__gleMaterialf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleMaterialfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMateriali)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleMaterialiv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__glePolygonStipple)(const GLubyte *);
extern void (GLE_FUNCPTR *__gleShadeModel)(GLenum );
extern void (GLE_FUNCPTR *__gleTexEnvf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleTexEnvfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexEnvi)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleTexEnviv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleTexGend)(GLenum , GLenum , GLdouble );
extern void (GLE_FUNCPTR *__gleTexGendv)(GLenum , GLenum , const GLdouble *);
extern void (GLE_FUNCPTR *__gleTexGenf)(GLenum , GLenum , GLfloat );
extern void (GLE_FUNCPTR *__gleTexGenfv)(GLenum , GLenum , const GLfloat *);
extern void (GLE_FUNCPTR *__gleTexGeni)(GLenum , GLenum , GLint );
extern void (GLE_FUNCPTR *__gleTexGeniv)(GLenum , GLenum , const GLint *);
extern void (GLE_FUNCPTR *__gleFeedbackBuffer)(GLsizei , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleSelectBuffer)(GLsizei , GLuint *);
extern GLint (GLE_FUNCPTR *__gleRenderMode)(GLenum );
extern void (GLE_FUNCPTR *__gleInitNames)();
extern void (GLE_FUNCPTR *__gleLoadName)(GLuint );
extern void (GLE_FUNCPTR *__glePassThrough)(GLfloat );
extern void (GLE_FUNCPTR *__glePopName)();
extern void (GLE_FUNCPTR *__glePushName)(GLuint );
extern void (GLE_FUNCPTR *__gleClearAccum)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleClearIndex)(GLfloat );
extern void (GLE_FUNCPTR *__gleIndexMask)(GLuint );
extern void (GLE_FUNCPTR *__gleAccum)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__glePopAttrib)();
extern void (GLE_FUNCPTR *__glePushAttrib)(GLbitfield );
extern void (GLE_FUNCPTR *__gleMap1d)(GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMap1f)(GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMap2d)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
extern void (GLE_FUNCPTR *__gleMap2f)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
extern void (GLE_FUNCPTR *__gleMapGrid1d)(GLint , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleMapGrid1f)(GLint , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleMapGrid2d)(GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleMapGrid2f)(GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleEvalCoord1d)(GLdouble );
extern void (GLE_FUNCPTR *__gleEvalCoord1dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleEvalCoord1f)(GLfloat );
extern void (GLE_FUNCPTR *__gleEvalCoord1fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleEvalCoord2d)(GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleEvalCoord2dv)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleEvalCoord2f)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleEvalCoord2fv)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleEvalMesh1)(GLenum , GLint , GLint );
extern void (GLE_FUNCPTR *__gleEvalPoint1)(GLint );
extern void (GLE_FUNCPTR *__gleEvalMesh2)(GLenum , GLint , GLint , GLint , GLint );
extern void (GLE_FUNCPTR *__gleEvalPoint2)(GLint , GLint );
extern void (GLE_FUNCPTR *__gleAlphaFunc)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__glePixelZoom)(GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__glePixelTransferf)(GLenum , GLfloat );
extern void (GLE_FUNCPTR *__glePixelTransferi)(GLenum , GLint );
extern void (GLE_FUNCPTR *__glePixelMapfv)(GLenum , GLsizei , const GLfloat *);
extern void (GLE_FUNCPTR *__glePixelMapuiv)(GLenum , GLsizei , const GLuint *);
extern void (GLE_FUNCPTR *__glePixelMapusv)(GLenum , GLsizei , const GLushort *);
extern void (GLE_FUNCPTR *__gleCopyPixels)(GLint , GLint , GLsizei , GLsizei , GLenum );
extern void (GLE_FUNCPTR *__gleDrawPixels)(GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
extern void (GLE_FUNCPTR *__gleGetClipPlane)(GLenum , GLdouble *);
extern void (GLE_FUNCPTR *__gleGetLightfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetLightiv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetMapdv)(GLenum , GLenum , GLdouble *);
extern void (GLE_FUNCPTR *__gleGetMapfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetMapiv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetMaterialfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetMaterialiv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetPixelMapfv)(GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetPixelMapuiv)(GLenum , GLuint *);
extern void (GLE_FUNCPTR *__gleGetPixelMapusv)(GLenum , GLushort *);
extern void (GLE_FUNCPTR *__gleGetPolygonStipple)(GLubyte *);
extern void (GLE_FUNCPTR *__gleGetTexEnvfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetTexEnviv)(GLenum , GLenum , GLint *);
extern void (GLE_FUNCPTR *__gleGetTexGendv)(GLenum , GLenum , GLdouble *);
extern void (GLE_FUNCPTR *__gleGetTexGenfv)(GLenum , GLenum , GLfloat *);
extern void (GLE_FUNCPTR *__gleGetTexGeniv)(GLenum , GLenum , GLint *);
extern GLboolean (GLE_FUNCPTR *__gleIsList)(GLuint );
extern void (GLE_FUNCPTR *__gleFrustum)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleLoadIdentity)();
extern void (GLE_FUNCPTR *__gleLoadMatrixf)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleLoadMatrixd)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleMatrixMode)(GLenum );
extern void (GLE_FUNCPTR *__gleMultMatrixf)(const GLfloat *);
extern void (GLE_FUNCPTR *__gleMultMatrixd)(const GLdouble *);
extern void (GLE_FUNCPTR *__gleOrtho)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__glePopMatrix)();
extern void (GLE_FUNCPTR *__glePushMatrix)();
extern void (GLE_FUNCPTR *__gleRotated)(GLdouble , GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleRotatef)(GLfloat , GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleScaled)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleScalef)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleTranslated)(GLdouble , GLdouble , GLdouble );
extern void (GLE_FUNCPTR *__gleTranslatef)(GLfloat , GLfloat , GLfloat );
extern void (GLE_FUNCPTR *__gleArrayElement)(GLint );
extern void (GLE_FUNCPTR *__gleColorPointer)(GLint , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleDisableClientState)(GLenum );
extern void (GLE_FUNCPTR *__gleEdgeFlagPointer)(GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleEnableClientState)(GLenum );
extern void (GLE_FUNCPTR *__gleIndexPointer)(GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleInterleavedArrays)(GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleNormalPointer)(GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleTexCoordPointer)(GLint , GLenum , GLsizei , const GLvoid *);
extern void (GLE_FUNCPTR *__gleVertexPointer)(GLint , GLenum , GLsizei , const GLvoid *);
extern GLboolean (GLE_FUNCPTR *__gleAreTexturesResident)(GLsizei , const GLuint *, GLboolean *);
extern void (GLE_FUNCPTR *__glePrioritizeTextures)(GLsizei , const GLuint *, const GLfloat *);
extern void (GLE_FUNCPTR *__glePopClientAttrib)();
extern void (GLE_FUNCPTR *__glePushClientAttrib)(GLbitfield );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_1_1_rem_3_1
	{
		GL_CURRENT_BIT                   = 0x00000001,
		GL_POINT_BIT                     = 0x00000002,
		GL_LINE_BIT                      = 0x00000004,
		GL_POLYGON_BIT                   = 0x00000008,
		GL_POLYGON_STIPPLE_BIT           = 0x00000010,
		GL_PIXEL_MODE_BIT                = 0x00000020,
		GL_LIGHTING_BIT                  = 0x00000040,
		GL_FOG_BIT                       = 0x00000080,
		GL_ACCUM_BUFFER_BIT              = 0x00000200,
		GL_VIEWPORT_BIT                  = 0x00000800,
		GL_TRANSFORM_BIT                 = 0x00001000,
		GL_ENABLE_BIT                    = 0x00002000,
		GL_HINT_BIT                      = 0x00008000,
		GL_EVAL_BIT                      = 0x00010000,
		GL_LIST_BIT                      = 0x00020000,
		GL_TEXTURE_BIT                   = 0x00040000,
		GL_SCISSOR_BIT                   = 0x00080000,
		GL_ALL_ATTRIB_BITS               = 0xFFFFFFFF,
		GL_CLIENT_PIXEL_STORE_BIT        = 0x00000001,
		GL_CLIENT_VERTEX_ARRAY_BIT       = 0x00000002,
		GL_CLIENT_ALL_ATTRIB_BITS        = 0xFFFFFFFF,
		GL_QUAD_STRIP                    = 0x0008,
		GL_POLYGON                       = 0x0009,
		GL_ACCUM                         = 0x0100,
		GL_LOAD                          = 0x0101,
		GL_RETURN                        = 0x0102,
		GL_MULT                          = 0x0103,
		GL_ADD                           = 0x0104,
		GL_AUX0                          = 0x0409,
		GL_AUX1                          = 0x040A,
		GL_AUX2                          = 0x040B,
		GL_AUX3                          = 0x040C,
		GL_2D                            = 0x0600,
		GL_3D                            = 0x0601,
		GL_3D_COLOR                      = 0x0602,
		GL_3D_COLOR_TEXTURE              = 0x0603,
		GL_4D_COLOR_TEXTURE              = 0x0604,
		GL_PASS_THROUGH_TOKEN            = 0x0700,
		GL_POINT_TOKEN                   = 0x0701,
		GL_LINE_TOKEN                    = 0x0702,
		GL_POLYGON_TOKEN                 = 0x0703,
		GL_BITMAP_TOKEN                  = 0x0704,
		GL_DRAW_PIXEL_TOKEN              = 0x0705,
		GL_COPY_PIXEL_TOKEN              = 0x0706,
		GL_LINE_RESET_TOKEN              = 0x0707,
		GL_EXP                           = 0x0800,
		GL_EXP2                          = 0x0801,
		GL_COEFF                         = 0x0A00,
		GL_ORDER                         = 0x0A01,
		GL_DOMAIN                        = 0x0A02,
		GL_PIXEL_MAP_I_TO_I              = 0x0C70,
		GL_PIXEL_MAP_S_TO_S              = 0x0C71,
		GL_PIXEL_MAP_I_TO_R              = 0x0C72,
		GL_PIXEL_MAP_I_TO_G              = 0x0C73,
		GL_PIXEL_MAP_I_TO_B              = 0x0C74,
		GL_PIXEL_MAP_I_TO_A              = 0x0C75,
		GL_PIXEL_MAP_R_TO_R              = 0x0C76,
		GL_PIXEL_MAP_G_TO_G              = 0x0C77,
		GL_PIXEL_MAP_B_TO_B              = 0x0C78,
		GL_PIXEL_MAP_A_TO_A              = 0x0C79,
		GL_VERTEX_ARRAY_POINTER          = 0x808E,
		GL_NORMAL_ARRAY_POINTER          = 0x808F,
		GL_COLOR_ARRAY_POINTER           = 0x8090,
		GL_INDEX_ARRAY_POINTER           = 0x8091,
		GL_TEXTURE_COORD_ARRAY_POINTER   = 0x8092,
		GL_EDGE_FLAG_ARRAY_POINTER       = 0x8093,
		GL_FEEDBACK_BUFFER_POINTER       = 0x0DF0,
		GL_SELECTION_BUFFER_POINTER      = 0x0DF3,
		GL_CURRENT_COLOR                 = 0x0B00,
		GL_CURRENT_INDEX                 = 0x0B01,
		GL_CURRENT_NORMAL                = 0x0B02,
		GL_CURRENT_TEXTURE_COORDS        = 0x0B03,
		GL_CURRENT_RASTER_COLOR          = 0x0B04,
		GL_CURRENT_RASTER_INDEX          = 0x0B05,
		GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0B06,
		GL_CURRENT_RASTER_POSITION       = 0x0B07,
		GL_CURRENT_RASTER_POSITION_VALID = 0x0B08,
		GL_CURRENT_RASTER_DISTANCE       = 0x0B09,
		GL_POINT_SMOOTH                  = 0x0B10,
		GL_LINE_STIPPLE                  = 0x0B24,
		GL_LINE_STIPPLE_PATTERN          = 0x0B25,
		GL_LINE_STIPPLE_REPEAT           = 0x0B26,
		GL_LIST_MODE                     = 0x0B30,
		GL_MAX_LIST_NESTING              = 0x0B31,
		GL_LIST_BASE                     = 0x0B32,
		GL_LIST_INDEX                    = 0x0B33,
		GL_POLYGON_MODE                  = 0x0B40,
		GL_POLYGON_STIPPLE               = 0x0B42,
		GL_EDGE_FLAG                     = 0x0B43,
		GL_LIGHTING                      = 0x0B50,
		GL_LIGHT_MODEL_LOCAL_VIEWER      = 0x0B51,
		GL_LIGHT_MODEL_TWO_SIDE          = 0x0B52,
		GL_LIGHT_MODEL_AMBIENT           = 0x0B53,
		GL_SHADE_MODEL                   = 0x0B54,
		GL_COLOR_MATERIAL_FACE           = 0x0B55,
		GL_COLOR_MATERIAL_PARAMETER      = 0x0B56,
		GL_COLOR_MATERIAL                = 0x0B57,
		GL_FOG_INDEX                     = 0x0B61,
		GL_FOG_DENSITY                   = 0x0B62,
		GL_FOG_START                     = 0x0B63,
		GL_FOG_END                       = 0x0B64,
		GL_FOG_MODE                      = 0x0B65,
		GL_FOG_COLOR                     = 0x0B66,
		GL_ACCUM_CLEAR_VALUE             = 0x0B80,
		GL_MATRIX_MODE                   = 0x0BA0,
		GL_NORMALIZE                     = 0x0BA1,
		GL_MODELVIEW_STACK_DEPTH         = 0x0BA3,
		GL_PROJECTION_STACK_DEPTH        = 0x0BA4,
		GL_TEXTURE_STACK_DEPTH           = 0x0BA5,
		GL_MODELVIEW_MATRIX              = 0x0BA6,
		GL_PROJECTION_MATRIX             = 0x0BA7,
		GL_TEXTURE_MATRIX                = 0x0BA8,
		GL_ATTRIB_STACK_DEPTH            = 0x0BB0,
		GL_CLIENT_ATTRIB_STACK_DEPTH     = 0x0BB1,
		GL_ALPHA_TEST                    = 0x0BC0,
		GL_ALPHA_TEST_FUNC               = 0x0BC1,
		GL_ALPHA_TEST_REF                = 0x0BC2,
		GL_INDEX_LOGIC_OP                = 0x0BF1,
		GL_LOGIC_OP                      = 0x0BF1,
		GL_AUX_BUFFERS                   = 0x0C00,
		GL_INDEX_CLEAR_VALUE             = 0x0C20,
		GL_INDEX_WRITEMASK               = 0x0C21,
		GL_INDEX_MODE                    = 0x0C30,
		GL_RGBA_MODE                     = 0x0C31,
		GL_RENDER_MODE                   = 0x0C40,
		GL_PERSPECTIVE_CORRECTION_HINT   = 0x0C50,
		GL_POINT_SMOOTH_HINT             = 0x0C51,
		GL_FOG_HINT                      = 0x0C54,
		GL_TEXTURE_GEN_S                 = 0x0C60,
		GL_TEXTURE_GEN_T                 = 0x0C61,
		GL_TEXTURE_GEN_R                 = 0x0C62,
		GL_TEXTURE_GEN_Q                 = 0x0C63,
		GL_PIXEL_MAP_I_TO_I_SIZE         = 0x0CB0,
		GL_PIXEL_MAP_S_TO_S_SIZE         = 0x0CB1,
		GL_PIXEL_MAP_I_TO_R_SIZE         = 0x0CB2,
		GL_PIXEL_MAP_I_TO_G_SIZE         = 0x0CB3,
		GL_PIXEL_MAP_I_TO_B_SIZE         = 0x0CB4,
		GL_PIXEL_MAP_I_TO_A_SIZE         = 0x0CB5,
		GL_PIXEL_MAP_R_TO_R_SIZE         = 0x0CB6,
		GL_PIXEL_MAP_G_TO_G_SIZE         = 0x0CB7,
		GL_PIXEL_MAP_B_TO_B_SIZE         = 0x0CB8,
		GL_PIXEL_MAP_A_TO_A_SIZE         = 0x0CB9,
		GL_MAP_COLOR                     = 0x0D10,
		GL_MAP_STENCIL                   = 0x0D11,
		GL_INDEX_SHIFT                   = 0x0D12,
		GL_INDEX_OFFSET                  = 0x0D13,
		GL_RED_SCALE                     = 0x0D14,
		GL_RED_BIAS                      = 0x0D15,
		GL_ZOOM_X                        = 0x0D16,
		GL_ZOOM_Y                        = 0x0D17,
		GL_GREEN_SCALE                   = 0x0D18,
		GL_GREEN_BIAS                    = 0x0D19,
		GL_BLUE_SCALE                    = 0x0D1A,
		GL_BLUE_BIAS                     = 0x0D1B,
		GL_ALPHA_SCALE                   = 0x0D1C,
		GL_ALPHA_BIAS                    = 0x0D1D,
		GL_DEPTH_SCALE                   = 0x0D1E,
		GL_DEPTH_BIAS                    = 0x0D1F,
		GL_MAX_EVAL_ORDER                = 0x0D30,
		GL_MAX_LIGHTS                    = 0x0D31,
		GL_MAX_CLIP_PLANES               = 0x0D32,
		GL_MAX_PIXEL_MAP_TABLE           = 0x0D34,
		GL_MAX_ATTRIB_STACK_DEPTH        = 0x0D35,
		GL_MAX_MODELVIEW_STACK_DEPTH     = 0x0D36,
		GL_MAX_NAME_STACK_DEPTH          = 0x0D37,
		GL_MAX_PROJECTION_STACK_DEPTH    = 0x0D38,
		GL_MAX_TEXTURE_STACK_DEPTH       = 0x0D39,
		GL_MAX_CLIENT_ATTRIB_STACK_DEPTH = 0x0D3B,
		GL_INDEX_BITS                    = 0x0D51,
		GL_RED_BITS                      = 0x0D52,
		GL_GREEN_BITS                    = 0x0D53,
		GL_BLUE_BITS                     = 0x0D54,
		GL_ALPHA_BITS                    = 0x0D55,
		GL_DEPTH_BITS                    = 0x0D56,
		GL_STENCIL_BITS                  = 0x0D57,
		GL_ACCUM_RED_BITS                = 0x0D58,
		GL_ACCUM_GREEN_BITS              = 0x0D59,
		GL_ACCUM_BLUE_BITS               = 0x0D5A,
		GL_ACCUM_ALPHA_BITS              = 0x0D5B,
		GL_NAME_STACK_DEPTH              = 0x0D70,
		GL_AUTO_NORMAL                   = 0x0D80,
		GL_MAP1_COLOR_4                  = 0x0D90,
		GL_MAP1_INDEX                    = 0x0D91,
		GL_MAP1_NORMAL                   = 0x0D92,
		GL_MAP1_TEXTURE_COORD_1          = 0x0D93,
		GL_MAP1_TEXTURE_COORD_2          = 0x0D94,
		GL_MAP1_TEXTURE_COORD_3          = 0x0D95,
		GL_MAP1_TEXTURE_COORD_4          = 0x0D96,
		GL_MAP1_VERTEX_3                 = 0x0D97,
		GL_MAP1_VERTEX_4                 = 0x0D98,
		GL_MAP2_COLOR_4                  = 0x0DB0,
		GL_MAP2_INDEX                    = 0x0DB1,
		GL_MAP2_NORMAL                   = 0x0DB2,
		GL_MAP2_TEXTURE_COORD_1          = 0x0DB3,
		GL_MAP2_TEXTURE_COORD_2          = 0x0DB4,
		GL_MAP2_TEXTURE_COORD_3          = 0x0DB5,
		GL_MAP2_TEXTURE_COORD_4          = 0x0DB6,
		GL_MAP2_VERTEX_3                 = 0x0DB7,
		GL_MAP2_VERTEX_4                 = 0x0DB8,
		GL_MAP1_GRID_DOMAIN              = 0x0DD0,
		GL_MAP1_GRID_SEGMENTS            = 0x0DD1,
		GL_MAP2_GRID_DOMAIN              = 0x0DD2,
		GL_MAP2_GRID_SEGMENTS            = 0x0DD3,
		GL_FEEDBACK_BUFFER_SIZE          = 0x0DF1,
		GL_FEEDBACK_BUFFER_TYPE          = 0x0DF2,
		GL_SELECTION_BUFFER_SIZE         = 0x0DF4,
		GL_NORMAL_ARRAY                  = 0x8075,
		GL_COLOR_ARRAY                   = 0x8076,
		GL_INDEX_ARRAY                   = 0x8077,
		GL_TEXTURE_COORD_ARRAY           = 0x8078,
		GL_EDGE_FLAG_ARRAY               = 0x8079,
		GL_VERTEX_ARRAY_SIZE             = 0x807A,
		GL_VERTEX_ARRAY_TYPE             = 0x807B,
		GL_VERTEX_ARRAY_STRIDE           = 0x807C,
		GL_NORMAL_ARRAY_TYPE             = 0x807E,
		GL_NORMAL_ARRAY_STRIDE           = 0x807F,
		GL_COLOR_ARRAY_SIZE              = 0x8081,
		GL_COLOR_ARRAY_TYPE              = 0x8082,
		GL_COLOR_ARRAY_STRIDE            = 0x8083,
		GL_INDEX_ARRAY_TYPE              = 0x8085,
		GL_INDEX_ARRAY_STRIDE            = 0x8086,
		GL_TEXTURE_COORD_ARRAY_SIZE      = 0x8088,
		GL_TEXTURE_COORD_ARRAY_TYPE      = 0x8089,
		GL_TEXTURE_COORD_ARRAY_STRIDE    = 0x808A,
		GL_EDGE_FLAG_ARRAY_STRIDE        = 0x808C,
		GL_TEXTURE_COMPONENTS            = 0x1003,
		GL_TEXTURE_BORDER                = 0x1005,
		GL_TEXTURE_LUMINANCE_SIZE        = 0x8060,
		GL_TEXTURE_INTENSITY_SIZE        = 0x8061,
		GL_TEXTURE_PRIORITY              = 0x8066,
		GL_TEXTURE_RESIDENT              = 0x8067,
		GL_AMBIENT                       = 0x1200,
		GL_DIFFUSE                       = 0x1201,
		GL_SPECULAR                      = 0x1202,
		GL_POSITION                      = 0x1203,
		GL_SPOT_DIRECTION                = 0x1204,
		GL_SPOT_EXPONENT                 = 0x1205,
		GL_SPOT_CUTOFF                   = 0x1206,
		GL_CONSTANT_ATTENUATION          = 0x1207,
		GL_LINEAR_ATTENUATION            = 0x1208,
		GL_QUADRATIC_ATTENUATION         = 0x1209,
		GL_COMPILE                       = 0x1300,
		GL_COMPILE_AND_EXECUTE           = 0x1301,
		GL_2_BYTES                       = 0x1407,
		GL_3_BYTES                       = 0x1408,
		GL_4_BYTES                       = 0x1409,
		GL_EMISSION                      = 0x1600,
		GL_SHININESS                     = 0x1601,
		GL_AMBIENT_AND_DIFFUSE           = 0x1602,
		GL_COLOR_INDEXES                 = 0x1603,
		GL_MODELVIEW                     = 0x1700,
		GL_PROJECTION                    = 0x1701,
		GL_COLOR_INDEX                   = 0x1900,
		GL_LUMINANCE                     = 0x1909,
		GL_LUMINANCE_ALPHA               = 0x190A,
		GL_BITMAP                        = 0x1A00,
		GL_RENDER                        = 0x1C00,
		GL_FEEDBACK                      = 0x1C01,
		GL_SELECT                        = 0x1C02,
		GL_FLAT                          = 0x1D00,
		GL_SMOOTH                        = 0x1D01,
		GL_S                             = 0x2000,
		GL_T                             = 0x2001,
		GL_R                             = 0x2002,
		GL_Q                             = 0x2003,
		GL_MODULATE                      = 0x2100,
		GL_DECAL                         = 0x2101,
		GL_TEXTURE_ENV_MODE              = 0x2200,
		GL_TEXTURE_ENV_COLOR             = 0x2201,
		GL_TEXTURE_ENV                   = 0x2300,
		GL_EYE_LINEAR                    = 0x2400,
		GL_OBJECT_LINEAR                 = 0x2401,
		GL_SPHERE_MAP                    = 0x2402,
		GL_TEXTURE_GEN_MODE              = 0x2500,
		GL_OBJECT_PLANE                  = 0x2501,
		GL_CLAMP                         = 0x2900,
		GL_ALPHA4                        = 0x803B,
		GL_ALPHA8                        = 0x803C,
		GL_ALPHA12                       = 0x803D,
		GL_ALPHA16                       = 0x803E,
		GL_LUMINANCE4                    = 0x803F,
		GL_LUMINANCE8                    = 0x8040,
		GL_LUMINANCE12                   = 0x8041,
		GL_LUMINANCE16                   = 0x8042,
		GL_LUMINANCE4_ALPHA4             = 0x8043,
		GL_LUMINANCE6_ALPHA2             = 0x8044,
		GL_LUMINANCE8_ALPHA8             = 0x8045,
		GL_LUMINANCE12_ALPHA4            = 0x8046,
		GL_LUMINANCE12_ALPHA12           = 0x8047,
		GL_LUMINANCE16_ALPHA16           = 0x8048,
		GL_INTENSITY                     = 0x8049,
		GL_INTENSITY4                    = 0x804A,
		GL_INTENSITY8                    = 0x804B,
		GL_INTENSITY12                   = 0x804C,
		GL_INTENSITY16                   = 0x804D,
		GL_V2F                           = 0x2A20,
		GL_V3F                           = 0x2A21,
		GL_C4UB_V2F                      = 0x2A22,
		GL_C4UB_V3F                      = 0x2A23,
		GL_C3F_V3F                       = 0x2A24,
		GL_N3F_V3F                       = 0x2A25,
		GL_C4F_N3F_V3F                   = 0x2A26,
		GL_T2F_V3F                       = 0x2A27,
		GL_T4F_V4F                       = 0x2A28,
		GL_T2F_C4UB_V3F                  = 0x2A29,
		GL_T2F_C3F_V3F                   = 0x2A2A,
		GL_T2F_N3F_V3F                   = 0x2A2B,
		GL_T2F_C4F_N3F_V3F               = 0x2A2C,
		GL_T4F_C4F_N3F_V4F               = 0x2A2D,
		GL_CLIP_PLANE0                   = 0x3000,
		GL_CLIP_PLANE1                   = 0x3001,
		GL_CLIP_PLANE2                   = 0x3002,
		GL_CLIP_PLANE3                   = 0x3003,
		GL_CLIP_PLANE4                   = 0x3004,
		GL_CLIP_PLANE5                   = 0x3005,
		GL_LIGHT0                        = 0x4000,
		GL_LIGHT1                        = 0x4001,
		GL_LIGHT2                        = 0x4002,
		GL_LIGHT3                        = 0x4003,
		GL_LIGHT4                        = 0x4004,
		GL_LIGHT5                        = 0x4005,
		GL_LIGHT6                        = 0x4006,
		GL_LIGHT7                        = 0x4007,
	};

	inline void NewList(GLuint list, GLenum mode) { ::__gleNewList(list, mode); }
	inline void EndList() { ::__gleEndList(); }
	inline void CallList(GLuint list) { ::__gleCallList(list); }
	inline void CallLists(GLsizei n, GLenum type, const GLvoid *lists) { ::__gleCallLists(n, type, lists); }
	inline void DeleteLists(GLuint list, GLsizei range) { ::__gleDeleteLists(list, range); }
	inline GLuint GenLists(GLsizei range) { return ::__gleGenLists(range); }
	inline void ListBase(GLuint base) { ::__gleListBase(base); }
	inline void Begin(GLenum mode) { ::__gleBegin(mode); }
	inline void Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) { ::__gleBitmap(width, height, xorig, yorig, xmove, ymove, bitmap); }
	inline void Color3b(GLbyte red, GLbyte green, GLbyte blue) { ::__gleColor3b(red, green, blue); }
	inline void Color3bv(const GLbyte *v) { ::__gleColor3bv(v); }
	inline void Color3d(GLdouble red, GLdouble green, GLdouble blue) { ::__gleColor3d(red, green, blue); }
	inline void Color3dv(const GLdouble *v) { ::__gleColor3dv(v); }
	inline void Color3f(GLfloat red, GLfloat green, GLfloat blue) { ::__gleColor3f(red, green, blue); }
	inline void Color3fv(const GLfloat *v) { ::__gleColor3fv(v); }
	inline void Color3i(GLint red, GLint green, GLint blue) { ::__gleColor3i(red, green, blue); }
	inline void Color3iv(const GLint *v) { ::__gleColor3iv(v); }
	inline void Color3s(GLshort red, GLshort green, GLshort blue) { ::__gleColor3s(red, green, blue); }
	inline void Color3sv(const GLshort *v) { ::__gleColor3sv(v); }
	inline void Color3ub(GLubyte red, GLubyte green, GLubyte blue) { ::__gleColor3ub(red, green, blue); }
	inline void Color3ubv(const GLubyte *v) { ::__gleColor3ubv(v); }
	inline void Color3ui(GLuint red, GLuint green, GLuint blue) { ::__gleColor3ui(red, green, blue); }
	inline void Color3uiv(const GLuint *v) { ::__gleColor3uiv(v); }
	inline void Color3us(GLushort red, GLushort green, GLushort blue) { ::__gleColor3us(red, green, blue); }
	inline void Color3usv(const GLushort *v) { ::__gleColor3usv(v); }
	inline void Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) { ::__gleColor4b(red, green, blue, alpha); }
	inline void Color4bv(const GLbyte *v) { ::__gleColor4bv(v); }
	inline void Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) { ::__gleColor4d(red, green, blue, alpha); }
	inline void Color4dv(const GLdouble *v) { ::__gleColor4dv(v); }
	inline void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { ::__gleColor4f(red, green, blue, alpha); }
	inline void Color4fv(const GLfloat *v) { ::__gleColor4fv(v); }
	inline void Color4i(GLint red, GLint green, GLint blue, GLint alpha) { ::__gleColor4i(red, green, blue, alpha); }
	inline void Color4iv(const GLint *v) { ::__gleColor4iv(v); }
	inline void Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) { ::__gleColor4s(red, green, blue, alpha); }
	inline void Color4sv(const GLshort *v) { ::__gleColor4sv(v); }
	inline void Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) { ::__gleColor4ub(red, green, blue, alpha); }
	inline void Color4ubv(const GLubyte *v) { ::__gleColor4ubv(v); }
	inline void Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) { ::__gleColor4ui(red, green, blue, alpha); }
	inline void Color4uiv(const GLuint *v) { ::__gleColor4uiv(v); }
	inline void Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) { ::__gleColor4us(red, green, blue, alpha); }
	inline void Color4usv(const GLushort *v) { ::__gleColor4usv(v); }
	inline void EdgeFlag(GLboolean flag) { ::__gleEdgeFlag(flag); }
	inline void EdgeFlagv(const GLboolean *flag) { ::__gleEdgeFlagv(flag); }
	inline void End() { ::__gleEnd(); }
	inline void Indexd(GLdouble c) { ::__gleIndexd(c); }
	inline void Indexdv(const GLdouble *c) { ::__gleIndexdv(c); }
	inline void Indexf(GLfloat c) { ::__gleIndexf(c); }
	inline void Indexfv(const GLfloat *c) { ::__gleIndexfv(c); }
	inline void Indexi(GLint c) { ::__gleIndexi(c); }
	inline void Indexiv(const GLint *c) { ::__gleIndexiv(c); }
	inline void Indexs(GLshort c) { ::__gleIndexs(c); }
	inline void Indexsv(const GLshort *c) { ::__gleIndexsv(c); }
	inline void Normal3b(GLbyte nx, GLbyte ny, GLbyte nz) { ::__gleNormal3b(nx, ny, nz); }
	inline void Normal3bv(const GLbyte *v) { ::__gleNormal3bv(v); }
	inline void Normal3d(GLdouble nx, GLdouble ny, GLdouble nz) { ::__gleNormal3d(nx, ny, nz); }
	inline void Normal3dv(const GLdouble *v) { ::__gleNormal3dv(v); }
	inline void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz) { ::__gleNormal3f(nx, ny, nz); }
	inline void Normal3fv(const GLfloat *v) { ::__gleNormal3fv(v); }
	inline void Normal3i(GLint nx, GLint ny, GLint nz) { ::__gleNormal3i(nx, ny, nz); }
	inline void Normal3iv(const GLint *v) { ::__gleNormal3iv(v); }
	inline void Normal3s(GLshort nx, GLshort ny, GLshort nz) { ::__gleNormal3s(nx, ny, nz); }
	inline void Normal3sv(const GLshort *v) { ::__gleNormal3sv(v); }
	inline void RasterPos2d(GLdouble x, GLdouble y) { ::__gleRasterPos2d(x, y); }
	inline void RasterPos2dv(const GLdouble *v) { ::__gleRasterPos2dv(v); }
	inline void RasterPos2f(GLfloat x, GLfloat y) { ::__gleRasterPos2f(x, y); }
	inline void RasterPos2fv(const GLfloat *v) { ::__gleRasterPos2fv(v); }
	inline void RasterPos2i(GLint x, GLint y) { ::__gleRasterPos2i(x, y); }
	inline void RasterPos2iv(const GLint *v) { ::__gleRasterPos2iv(v); }
	inline void RasterPos2s(GLshort x, GLshort y) { ::__gleRasterPos2s(x, y); }
	inline void RasterPos2sv(const GLshort *v) { ::__gleRasterPos2sv(v); }
	inline void RasterPos3d(GLdouble x, GLdouble y, GLdouble z) { ::__gleRasterPos3d(x, y, z); }
	inline void RasterPos3dv(const GLdouble *v) { ::__gleRasterPos3dv(v); }
	inline void RasterPos3f(GLfloat x, GLfloat y, GLfloat z) { ::__gleRasterPos3f(x, y, z); }
	inline void RasterPos3fv(const GLfloat *v) { ::__gleRasterPos3fv(v); }
	inline void RasterPos3i(GLint x, GLint y, GLint z) { ::__gleRasterPos3i(x, y, z); }
	inline void RasterPos3iv(const GLint *v) { ::__gleRasterPos3iv(v); }
	inline void RasterPos3s(GLshort x, GLshort y, GLshort z) { ::__gleRasterPos3s(x, y, z); }
	inline void RasterPos3sv(const GLshort *v) { ::__gleRasterPos3sv(v); }
	inline void RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ::__gleRasterPos4d(x, y, z, w); }
	inline void RasterPos4dv(const GLdouble *v) { ::__gleRasterPos4dv(v); }
	inline void RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { ::__gleRasterPos4f(x, y, z, w); }
	inline void RasterPos4fv(const GLfloat *v) { ::__gleRasterPos4fv(v); }
	inline void RasterPos4i(GLint x, GLint y, GLint z, GLint w) { ::__gleRasterPos4i(x, y, z, w); }
	inline void RasterPos4iv(const GLint *v) { ::__gleRasterPos4iv(v); }
	inline void RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) { ::__gleRasterPos4s(x, y, z, w); }
	inline void RasterPos4sv(const GLshort *v) { ::__gleRasterPos4sv(v); }
	inline void Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) { ::__gleRectd(x1, y1, x2, y2); }
	inline void Rectdv(const GLdouble *v1, const GLdouble *v2) { ::__gleRectdv(v1, v2); }
	inline void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) { ::__gleRectf(x1, y1, x2, y2); }
	inline void Rectfv(const GLfloat *v1, const GLfloat *v2) { ::__gleRectfv(v1, v2); }
	inline void Recti(GLint x1, GLint y1, GLint x2, GLint y2) { ::__gleRecti(x1, y1, x2, y2); }
	inline void Rectiv(const GLint *v1, const GLint *v2) { ::__gleRectiv(v1, v2); }
	inline void Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) { ::__gleRects(x1, y1, x2, y2); }
	inline void Rectsv(const GLshort *v1, const GLshort *v2) { ::__gleRectsv(v1, v2); }
	inline void TexCoord1d(GLdouble s) { ::__gleTexCoord1d(s); }
	inline void TexCoord1dv(const GLdouble *v) { ::__gleTexCoord1dv(v); }
	inline void TexCoord1f(GLfloat s) { ::__gleTexCoord1f(s); }
	inline void TexCoord1fv(const GLfloat *v) { ::__gleTexCoord1fv(v); }
	inline void TexCoord1i(GLint s) { ::__gleTexCoord1i(s); }
	inline void TexCoord1iv(const GLint *v) { ::__gleTexCoord1iv(v); }
	inline void TexCoord1s(GLshort s) { ::__gleTexCoord1s(s); }
	inline void TexCoord1sv(const GLshort *v) { ::__gleTexCoord1sv(v); }
	inline void TexCoord2d(GLdouble s, GLdouble t) { ::__gleTexCoord2d(s, t); }
	inline void TexCoord2dv(const GLdouble *v) { ::__gleTexCoord2dv(v); }
	inline void TexCoord2f(GLfloat s, GLfloat t) { ::__gleTexCoord2f(s, t); }
	inline void TexCoord2fv(const GLfloat *v) { ::__gleTexCoord2fv(v); }
	inline void TexCoord2i(GLint s, GLint t) { ::__gleTexCoord2i(s, t); }
	inline void TexCoord2iv(const GLint *v) { ::__gleTexCoord2iv(v); }
	inline void TexCoord2s(GLshort s, GLshort t) { ::__gleTexCoord2s(s, t); }
	inline void TexCoord2sv(const GLshort *v) { ::__gleTexCoord2sv(v); }
	inline void TexCoord3d(GLdouble s, GLdouble t, GLdouble r) { ::__gleTexCoord3d(s, t, r); }
	inline void TexCoord3dv(const GLdouble *v) { ::__gleTexCoord3dv(v); }
	inline void TexCoord3f(GLfloat s, GLfloat t, GLfloat r) { ::__gleTexCoord3f(s, t, r); }
	inline void TexCoord3fv(const GLfloat *v) { ::__gleTexCoord3fv(v); }
	inline void TexCoord3i(GLint s, GLint t, GLint r) { ::__gleTexCoord3i(s, t, r); }
	inline void TexCoord3iv(const GLint *v) { ::__gleTexCoord3iv(v); }
	inline void TexCoord3s(GLshort s, GLshort t, GLshort r) { ::__gleTexCoord3s(s, t, r); }
	inline void TexCoord3sv(const GLshort *v) { ::__gleTexCoord3sv(v); }
	inline void TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) { ::__gleTexCoord4d(s, t, r, q); }
	inline void TexCoord4dv(const GLdouble *v) { ::__gleTexCoord4dv(v); }
	inline void TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) { ::__gleTexCoord4f(s, t, r, q); }
	inline void TexCoord4fv(const GLfloat *v) { ::__gleTexCoord4fv(v); }
	inline void TexCoord4i(GLint s, GLint t, GLint r, GLint q) { ::__gleTexCoord4i(s, t, r, q); }
	inline void TexCoord4iv(const GLint *v) { ::__gleTexCoord4iv(v); }
	inline void TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) { ::__gleTexCoord4s(s, t, r, q); }
	inline void TexCoord4sv(const GLshort *v) { ::__gleTexCoord4sv(v); }
	inline void Vertex2d(GLdouble x, GLdouble y) { ::__gleVertex2d(x, y); }
	inline void Vertex2dv(const GLdouble *v) { ::__gleVertex2dv(v); }
	inline void Vertex2f(GLfloat x, GLfloat y) { ::__gleVertex2f(x, y); }
	inline void Vertex2fv(const GLfloat *v) { ::__gleVertex2fv(v); }
	inline void Vertex2i(GLint x, GLint y) { ::__gleVertex2i(x, y); }
	inline void Vertex2iv(const GLint *v) { ::__gleVertex2iv(v); }
	inline void Vertex2s(GLshort x, GLshort y) { ::__gleVertex2s(x, y); }
	inline void Vertex2sv(const GLshort *v) { ::__gleVertex2sv(v); }
	inline void Vertex3d(GLdouble x, GLdouble y, GLdouble z) { ::__gleVertex3d(x, y, z); }
	inline void Vertex3dv(const GLdouble *v) { ::__gleVertex3dv(v); }
	inline void Vertex3f(GLfloat x, GLfloat y, GLfloat z) { ::__gleVertex3f(x, y, z); }
	inline void Vertex3fv(const GLfloat *v) { ::__gleVertex3fv(v); }
	inline void Vertex3i(GLint x, GLint y, GLint z) { ::__gleVertex3i(x, y, z); }
	inline void Vertex3iv(const GLint *v) { ::__gleVertex3iv(v); }
	inline void Vertex3s(GLshort x, GLshort y, GLshort z) { ::__gleVertex3s(x, y, z); }
	inline void Vertex3sv(const GLshort *v) { ::__gleVertex3sv(v); }
	inline void Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { ::__gleVertex4d(x, y, z, w); }
	inline void Vertex4dv(const GLdouble *v) { ::__gleVertex4dv(v); }
	inline void Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { ::__gleVertex4f(x, y, z, w); }
	inline void Vertex4fv(const GLfloat *v) { ::__gleVertex4fv(v); }
	inline void Vertex4i(GLint x, GLint y, GLint z, GLint w) { ::__gleVertex4i(x, y, z, w); }
	inline void Vertex4iv(const GLint *v) { ::__gleVertex4iv(v); }
	inline void Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w) { ::__gleVertex4s(x, y, z, w); }
	inline void Vertex4sv(const GLshort *v) { ::__gleVertex4sv(v); }
	inline void ClipPlane(GLenum plane, const GLdouble *equation) { ::__gleClipPlane(plane, equation); }
	inline void ColorMaterial(GLenum face, GLenum mode) { ::__gleColorMaterial(face, mode); }
	inline void Fogf(GLenum pname, GLfloat param) { ::__gleFogf(pname, param); }
	inline void Fogfv(GLenum pname, const GLfloat *params) { ::__gleFogfv(pname, params); }
	inline void Fogi(GLenum pname, GLint param) { ::__gleFogi(pname, param); }
	inline void Fogiv(GLenum pname, const GLint *params) { ::__gleFogiv(pname, params); }
	inline void Lightf(GLenum light, GLenum pname, GLfloat param) { ::__gleLightf(light, pname, param); }
	inline void Lightfv(GLenum light, GLenum pname, const GLfloat *params) { ::__gleLightfv(light, pname, params); }
	inline void Lighti(GLenum light, GLenum pname, GLint param) { ::__gleLighti(light, pname, param); }
	inline void Lightiv(GLenum light, GLenum pname, const GLint *params) { ::__gleLightiv(light, pname, params); }
	inline void LightModelf(GLenum pname, GLfloat param) { ::__gleLightModelf(pname, param); }
	inline void LightModelfv(GLenum pname, const GLfloat *params) { ::__gleLightModelfv(pname, params); }
	inline void LightModeli(GLenum pname, GLint param) { ::__gleLightModeli(pname, param); }
	inline void LightModeliv(GLenum pname, const GLint *params) { ::__gleLightModeliv(pname, params); }
	inline void LineStipple(GLint factor, GLushort pattern) { ::__gleLineStipple(factor, pattern); }
	inline void Materialf(GLenum face, GLenum pname, GLfloat param) { ::__gleMaterialf(face, pname, param); }
	inline void Materialfv(GLenum face, GLenum pname, const GLfloat *params) { ::__gleMaterialfv(face, pname, params); }
	inline void Materiali(GLenum face, GLenum pname, GLint param) { ::__gleMateriali(face, pname, param); }
	inline void Materialiv(GLenum face, GLenum pname, const GLint *params) { ::__gleMaterialiv(face, pname, params); }
	inline void PolygonStipple(const GLubyte *mask) { ::__glePolygonStipple(mask); }
	inline void ShadeModel(GLenum mode) { ::__gleShadeModel(mode); }
	inline void TexEnvf(GLenum target, GLenum pname, GLfloat param) { ::__gleTexEnvf(target, pname, param); }
	inline void TexEnvfv(GLenum target, GLenum pname, const GLfloat *params) { ::__gleTexEnvfv(target, pname, params); }
	inline void TexEnvi(GLenum target, GLenum pname, GLint param) { ::__gleTexEnvi(target, pname, param); }
	inline void TexEnviv(GLenum target, GLenum pname, const GLint *params) { ::__gleTexEnviv(target, pname, params); }
	inline void TexGend(GLenum coord, GLenum pname, GLdouble param) { ::__gleTexGend(coord, pname, param); }
	inline void TexGendv(GLenum coord, GLenum pname, const GLdouble *params) { ::__gleTexGendv(coord, pname, params); }
	inline void TexGenf(GLenum coord, GLenum pname, GLfloat param) { ::__gleTexGenf(coord, pname, param); }
	inline void TexGenfv(GLenum coord, GLenum pname, const GLfloat *params) { ::__gleTexGenfv(coord, pname, params); }
	inline void TexGeni(GLenum coord, GLenum pname, GLint param) { ::__gleTexGeni(coord, pname, param); }
	inline void TexGeniv(GLenum coord, GLenum pname, const GLint *params) { ::__gleTexGeniv(coord, pname, params); }
	inline void FeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer) { ::__gleFeedbackBuffer(size, type, buffer); }
	inline void SelectBuffer(GLsizei size, GLuint *buffer) { ::__gleSelectBuffer(size, buffer); }
	inline GLint RenderMode(GLenum mode) { return ::__gleRenderMode(mode); }
	inline void InitNames() { ::__gleInitNames(); }
	inline void LoadName(GLuint name) { ::__gleLoadName(name); }
	inline void PassThrough(GLfloat token) { ::__glePassThrough(token); }
	inline void PopName() { ::__glePopName(); }
	inline void PushName(GLuint name) { ::__glePushName(name); }
	inline void ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) { ::__gleClearAccum(red, green, blue, alpha); }
	inline void ClearIndex(GLfloat c) { ::__gleClearIndex(c); }
	inline void IndexMask(GLuint mask) { ::__gleIndexMask(mask); }
	inline void Accum(GLenum op, GLfloat value) { ::__gleAccum(op, value); }
	inline void PopAttrib() { ::__glePopAttrib(); }
	inline void PushAttrib(GLbitfield mask) { ::__glePushAttrib(mask); }
	inline void Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) { ::__gleMap1d(target, u1, u2, stride, order, points); }
	inline void Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) { ::__gleMap1f(target, u1, u2, stride, order, points); }
	inline void Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) { ::__gleMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
	inline void Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) { ::__gleMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points); }
	inline void MapGrid1d(GLint un, GLdouble u1, GLdouble u2) { ::__gleMapGrid1d(un, u1, u2); }
	inline void MapGrid1f(GLint un, GLfloat u1, GLfloat u2) { ::__gleMapGrid1f(un, u1, u2); }
	inline void MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) { ::__gleMapGrid2d(un, u1, u2, vn, v1, v2); }
	inline void MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) { ::__gleMapGrid2f(un, u1, u2, vn, v1, v2); }
	inline void EvalCoord1d(GLdouble u) { ::__gleEvalCoord1d(u); }
	inline void EvalCoord1dv(const GLdouble *u) { ::__gleEvalCoord1dv(u); }
	inline void EvalCoord1f(GLfloat u) { ::__gleEvalCoord1f(u); }
	inline void EvalCoord1fv(const GLfloat *u) { ::__gleEvalCoord1fv(u); }
	inline void EvalCoord2d(GLdouble u, GLdouble v) { ::__gleEvalCoord2d(u, v); }
	inline void EvalCoord2dv(const GLdouble *u) { ::__gleEvalCoord2dv(u); }
	inline void EvalCoord2f(GLfloat u, GLfloat v) { ::__gleEvalCoord2f(u, v); }
	inline void EvalCoord2fv(const GLfloat *u) { ::__gleEvalCoord2fv(u); }
	inline void EvalMesh1(GLenum mode, GLint i1, GLint i2) { ::__gleEvalMesh1(mode, i1, i2); }
	inline void EvalPoint1(GLint i) { ::__gleEvalPoint1(i); }
	inline void EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) { ::__gleEvalMesh2(mode, i1, i2, j1, j2); }
	inline void EvalPoint2(GLint i, GLint j) { ::__gleEvalPoint2(i, j); }
	inline void AlphaFunc(GLenum func, GLfloat ref) { ::__gleAlphaFunc(func, ref); }
	inline void PixelZoom(GLfloat xfactor, GLfloat yfactor) { ::__glePixelZoom(xfactor, yfactor); }
	inline void PixelTransferf(GLenum pname, GLfloat param) { ::__glePixelTransferf(pname, param); }
	inline void PixelTransferi(GLenum pname, GLint param) { ::__glePixelTransferi(pname, param); }
	inline void PixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values) { ::__glePixelMapfv(map, mapsize, values); }
	inline void PixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values) { ::__glePixelMapuiv(map, mapsize, values); }
	inline void PixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values) { ::__glePixelMapusv(map, mapsize, values); }
	inline void CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) { ::__gleCopyPixels(x, y, width, height, type); }
	inline void DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) { ::__gleDrawPixels(width, height, format, type, pixels); }
	inline void GetClipPlane(GLenum plane, GLdouble *equation) { ::__gleGetClipPlane(plane, equation); }
	inline void GetLightfv(GLenum light, GLenum pname, GLfloat *params) { ::__gleGetLightfv(light, pname, params); }
	inline void GetLightiv(GLenum light, GLenum pname, GLint *params) { ::__gleGetLightiv(light, pname, params); }
	inline void GetMapdv(GLenum target, GLenum query, GLdouble *v) { ::__gleGetMapdv(target, query, v); }
	inline void GetMapfv(GLenum target, GLenum query, GLfloat *v) { ::__gleGetMapfv(target, query, v); }
	inline void GetMapiv(GLenum target, GLenum query, GLint *v) { ::__gleGetMapiv(target, query, v); }
	inline void GetMaterialfv(GLenum face, GLenum pname, GLfloat *params) { ::__gleGetMaterialfv(face, pname, params); }
	inline void GetMaterialiv(GLenum face, GLenum pname, GLint *params) { ::__gleGetMaterialiv(face, pname, params); }
	inline void GetPixelMapfv(GLenum map, GLfloat *values) { ::__gleGetPixelMapfv(map, values); }
	inline void GetPixelMapuiv(GLenum map, GLuint *values) { ::__gleGetPixelMapuiv(map, values); }
	inline void GetPixelMapusv(GLenum map, GLushort *values) { ::__gleGetPixelMapusv(map, values); }
	inline void GetPolygonStipple(GLubyte *mask) { ::__gleGetPolygonStipple(mask); }
	inline void GetTexEnvfv(GLenum target, GLenum pname, GLfloat *params) { ::__gleGetTexEnvfv(target, pname, params); }
	inline void GetTexEnviv(GLenum target, GLenum pname, GLint *params) { ::__gleGetTexEnviv(target, pname, params); }
	inline void GetTexGendv(GLenum coord, GLenum pname, GLdouble *params) { ::__gleGetTexGendv(coord, pname, params); }
	inline void GetTexGenfv(GLenum coord, GLenum pname, GLfloat *params) { ::__gleGetTexGenfv(coord, pname, params); }
	inline void GetTexGeniv(GLenum coord, GLenum pname, GLint *params) { ::__gleGetTexGeniv(coord, pname, params); }
	inline GLboolean IsList(GLuint list) { return ::__gleIsList(list); }
	inline void Frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { ::__gleFrustum(left, right, bottom, top, zNear, zFar); }
	inline void LoadIdentity() { ::__gleLoadIdentity(); }
	inline void LoadMatrixf(const GLfloat *m) { ::__gleLoadMatrixf(m); }
	inline void LoadMatrixd(const GLdouble *m) { ::__gleLoadMatrixd(m); }
	inline void MatrixMode(GLenum mode) { ::__gleMatrixMode(mode); }
	inline void MultMatrixf(const GLfloat *m) { ::__gleMultMatrixf(m); }
	inline void MultMatrixd(const GLdouble *m) { ::__gleMultMatrixd(m); }
	inline void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) { ::__gleOrtho(left, right, bottom, top, zNear, zFar); }
	inline void PopMatrix() { ::__glePopMatrix(); }
	inline void PushMatrix() { ::__glePushMatrix(); }
	inline void Rotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) { ::__gleRotated(angle, x, y, z); }
	inline void Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) { ::__gleRotatef(angle, x, y, z); }
	inline void Scaled(GLdouble x, GLdouble y, GLdouble z) { ::__gleScaled(x, y, z); }
	inline void Scalef(GLfloat x, GLfloat y, GLfloat z) { ::__gleScalef(x, y, z); }
	inline void Translated(GLdouble x, GLdouble y, GLdouble z) { ::__gleTranslated(x, y, z); }
	inline void Translatef(GLfloat x, GLfloat y, GLfloat z) { ::__gleTranslatef(x, y, z); }
	inline void ArrayElement(GLint i) { ::__gleArrayElement(i); }
	inline void ColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleColorPointer(size, type, stride, pointer); }
	inline void DisableClientState(GLenum ren_array) { ::__gleDisableClientState(ren_array); }
	inline void EdgeFlagPointer(GLsizei stride, const GLvoid *pointer) { ::__gleEdgeFlagPointer(stride, pointer); }
	inline void EnableClientState(GLenum ren_array) { ::__gleEnableClientState(ren_array); }
	inline void IndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleIndexPointer(type, stride, pointer); }
	inline void InterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer) { ::__gleInterleavedArrays(format, stride, pointer); }
	inline void NormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleNormalPointer(type, stride, pointer); }
	inline void TexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleTexCoordPointer(size, type, stride, pointer); }
	inline void VertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) { ::__gleVertexPointer(size, type, stride, pointer); }
	inline GLboolean AreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) { return ::__gleAreTexturesResident(n, textures, residences); }
	inline void PrioritizeTextures(GLsizei n, const GLuint *textures, const GLfloat *priorities) { ::__glePrioritizeTextures(n, textures, priorities); }
	inline void PopClientAttrib() { ::__glePopClientAttrib(); }
	inline void PushClientAttrib(GLbitfield mask) { ::__glePushClientAttrib(mask); }

}

#endif //_INT_GL_1_1_REM_3_1_HPP

