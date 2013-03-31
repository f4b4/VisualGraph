#ifndef _INT_GL_1_1_REM_3_1_H
#define _INT_GL_1_1_REM_3_1_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_CURRENT_BIT 0x00000001
#define GL_POINT_BIT 0x00000002
#define GL_LINE_BIT 0x00000004
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_VIEWPORT_BIT 0x00000800
#define GL_TRANSFORM_BIT 0x00001000
#define GL_ENABLE_BIT 0x00002000
#define GL_HINT_BIT 0x00008000
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_LOGIC_OP 0x0BF1
#define GL_AUX_BUFFERS 0x0C00
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_COLOR_INDEX 0x1900
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_CLAMP 0x2900
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007
typedef void (GLE_FUNCPTR * PFNGLNEWLISTPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLENDLISTPROC)();
typedef void (GLE_FUNCPTR * PFNGLCALLLISTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLCALLLISTSPROC)(GLsizei , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDELETELISTSPROC)(GLuint , GLsizei );
typedef GLuint (GLE_FUNCPTR * PFNGLGENLISTSPROC)(GLsizei );
typedef void (GLE_FUNCPTR * PFNGLLISTBASEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLBEGINPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLBITMAPPROC)(GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3BPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3BVPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UBPROC)(GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UBVPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UIPROC)(GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3UIVPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR3USPROC)(GLushort , GLushort , GLushort );
typedef void (GLE_FUNCPTR * PFNGLCOLOR3USVPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4BPROC)(GLbyte , GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4BVPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4IPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4SPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBPROC)(GLubyte , GLubyte , GLubyte , GLubyte );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UBVPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UIPROC)(GLuint , GLuint , GLuint , GLuint );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4UIVPROC)(const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLCOLOR4USPROC)(GLushort , GLushort , GLushort , GLushort );
typedef void (GLE_FUNCPTR * PFNGLCOLOR4USVPROC)(const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPROC)(GLboolean );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGVPROC)(const GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLENDPROC)();
typedef void (GLE_FUNCPTR * PFNGLINDEXDPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLINDEXDVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLINDEXFPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLINDEXFVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLINDEXIPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLINDEXIVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLINDEXSPROC)(GLshort );
typedef void (GLE_FUNCPTR * PFNGLINDEXSVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3BPROC)(GLbyte , GLbyte , GLbyte );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3BVPROC)(const GLbyte *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLNORMAL3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLNORMAL3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2DPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2FPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2IPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2SPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS2SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4IPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4SPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLRASTERPOS4SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLRECTDPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLRECTDVPROC)(const GLdouble *, const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLRECTFPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLRECTFVPROC)(const GLfloat *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLRECTIPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLRECTIVPROC)(const GLint *, const GLint *);
typedef void (GLE_FUNCPTR * PFNGLRECTSPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLRECTSVPROC)(const GLshort *, const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1DPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1FPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1IPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1SPROC)(GLshort );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD1SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2DPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2IPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2SPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD2SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4IPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4SPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLTEXCOORD4SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX2DPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEX2DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX2FPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEX2FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX2IPROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEX2IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX2SPROC)(GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEX2SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX3DPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEX3DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX3FPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEX3FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX3IPROC)(GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEX3IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX3SPROC)(GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEX3SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX4DPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLVERTEX4DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX4FPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLVERTEX4FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX4IPROC)(GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLVERTEX4IVPROC)(const GLint *);
typedef void (GLE_FUNCPTR * PFNGLVERTEX4SPROC)(GLshort , GLshort , GLshort , GLshort );
typedef void (GLE_FUNCPTR * PFNGLVERTEX4SVPROC)(const GLshort *);
typedef void (GLE_FUNCPTR * PFNGLCLIPPLANEPROC)(GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLCOLORMATERIALPROC)(GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLFOGFPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLFOGFVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLFOGIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLFOGIVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLLIGHTFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLLIGHTFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLIGHTIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLLIGHTIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELFPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELFVPROC)(GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLLIGHTMODELIVPROC)(GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLLINESTIPPLEPROC)(GLint , GLushort );
typedef void (GLE_FUNCPTR * PFNGLMATERIALFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMATERIALFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMATERIALIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLMATERIALIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLSHADEMODELPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLTEXENVFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXENVFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXENVIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXENVIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLTEXGENDPROC)(GLenum , GLenum , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTEXGENDVPROC)(GLenum , GLenum , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLTEXGENFPROC)(GLenum , GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTEXGENFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLTEXGENIPROC)(GLenum , GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLTEXGENIVPROC)(GLenum , GLenum , const GLint *);
typedef void (GLE_FUNCPTR * PFNGLFEEDBACKBUFFERPROC)(GLsizei , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLSELECTBUFFERPROC)(GLsizei , GLuint *);
typedef GLint (GLE_FUNCPTR * PFNGLRENDERMODEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLINITNAMESPROC)();
typedef void (GLE_FUNCPTR * PFNGLLOADNAMEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLPASSTHROUGHPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOPNAMEPROC)();
typedef void (GLE_FUNCPTR * PFNGLPUSHNAMEPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLCLEARACCUMPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLCLEARINDEXPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLINDEXMASKPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLACCUMPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPOPATTRIBPROC)();
typedef void (GLE_FUNCPTR * PFNGLPUSHATTRIBPROC)(GLbitfield );
typedef void (GLE_FUNCPTR * PFNGLMAP1DPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAP1FPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMAP2DPROC)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMAP2FPROC)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMAPGRID1DPROC)(GLint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMAPGRID1FPROC)(GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLMAPGRID2DPROC)(GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLMAPGRID2FPROC)(GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1DPROC)(GLdouble );
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1FPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD1FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2DPROC)(GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2DVPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2FPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLEVALCOORD2FVPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLEVALMESH1PROC)(GLenum , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLEVALPOINT1PROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLEVALMESH2PROC)(GLenum , GLint , GLint , GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLEVALPOINT2PROC)(GLint , GLint );
typedef void (GLE_FUNCPTR * PFNGLALPHAFUNCPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELZOOMPROC)(GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFERFPROC)(GLenum , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLPIXELTRANSFERIPROC)(GLenum , GLint );
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPFVPROC)(GLenum , GLsizei , const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPUIVPROC)(GLenum , GLsizei , const GLuint *);
typedef void (GLE_FUNCPTR * PFNGLPIXELMAPUSVPROC)(GLenum , GLsizei , const GLushort *);
typedef void (GLE_FUNCPTR * PFNGLCOPYPIXELSPROC)(GLint , GLint , GLsizei , GLsizei , GLenum );
typedef void (GLE_FUNCPTR * PFNGLDRAWPIXELSPROC)(GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLGETCLIPPLANEPROC)(GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETLIGHTFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETLIGHTIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPDVPROC)(GLenum , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMAPIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETMATERIALFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETMATERIALIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPFVPROC)(GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPUIVPROC)(GLenum , GLuint *);
typedef void (GLE_FUNCPTR * PFNGLGETPIXELMAPUSVPROC)(GLenum , GLushort *);
typedef void (GLE_FUNCPTR * PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXENVFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXENVIVPROC)(GLenum , GLenum , GLint *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENDVPROC)(GLenum , GLenum , GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLGETTEXGENIVPROC)(GLenum , GLenum , GLint *);
typedef GLboolean (GLE_FUNCPTR * PFNGLISLISTPROC)(GLuint );
typedef void (GLE_FUNCPTR * PFNGLFRUSTUMPROC)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLLOADIDENTITYPROC)();
typedef void (GLE_FUNCPTR * PFNGLLOADMATRIXFPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLLOADMATRIXDPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLMATRIXMODEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLMULTMATRIXFPROC)(const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLMULTMATRIXDPROC)(const GLdouble *);
typedef void (GLE_FUNCPTR * PFNGLORTHOPROC)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLPOPMATRIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLPUSHMATRIXPROC)();
typedef void (GLE_FUNCPTR * PFNGLROTATEDPROC)(GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLROTATEFPROC)(GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLSCALEDPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLSCALEFPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLTRANSLATEDPROC)(GLdouble , GLdouble , GLdouble );
typedef void (GLE_FUNCPTR * PFNGLTRANSLATEFPROC)(GLfloat , GLfloat , GLfloat );
typedef void (GLE_FUNCPTR * PFNGLARRAYELEMENTPROC)(GLint );
typedef void (GLE_FUNCPTR * PFNGLCOLORPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLDISABLECLIENTSTATEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLEDGEFLAGPOINTERPROC)(GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLENABLECLIENTSTATEPROC)(GLenum );
typedef void (GLE_FUNCPTR * PFNGLINDEXPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLINTERLEAVEDARRAYSPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLNORMALPOINTERPROC)(GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLTEXCOORDPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
typedef void (GLE_FUNCPTR * PFNGLVERTEXPOINTERPROC)(GLint , GLenum , GLsizei , const GLvoid *);
typedef GLboolean (GLE_FUNCPTR * PFNGLARETEXTURESRESIDENTPROC)(GLsizei , const GLuint *, GLboolean *);
typedef void (GLE_FUNCPTR * PFNGLPRIORITIZETEXTURESPROC)(GLsizei , const GLuint *, const GLfloat *);
typedef void (GLE_FUNCPTR * PFNGLPOPCLIENTATTRIBPROC)();
typedef void (GLE_FUNCPTR * PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield );

extern PFNGLNEWLISTPROC __gleNewList;
#define glNewList __gleNewList
extern PFNGLENDLISTPROC __gleEndList;
#define glEndList __gleEndList
extern PFNGLCALLLISTPROC __gleCallList;
#define glCallList __gleCallList
extern PFNGLCALLLISTSPROC __gleCallLists;
#define glCallLists __gleCallLists
extern PFNGLDELETELISTSPROC __gleDeleteLists;
#define glDeleteLists __gleDeleteLists
extern PFNGLGENLISTSPROC __gleGenLists;
#define glGenLists __gleGenLists
extern PFNGLLISTBASEPROC __gleListBase;
#define glListBase __gleListBase
extern PFNGLBEGINPROC __gleBegin;
#define glBegin __gleBegin
extern PFNGLBITMAPPROC __gleBitmap;
#define glBitmap __gleBitmap
extern PFNGLCOLOR3BPROC __gleColor3b;
#define glColor3b __gleColor3b
extern PFNGLCOLOR3BVPROC __gleColor3bv;
#define glColor3bv __gleColor3bv
extern PFNGLCOLOR3DPROC __gleColor3d;
#define glColor3d __gleColor3d
extern PFNGLCOLOR3DVPROC __gleColor3dv;
#define glColor3dv __gleColor3dv
extern PFNGLCOLOR3FPROC __gleColor3f;
#define glColor3f __gleColor3f
extern PFNGLCOLOR3FVPROC __gleColor3fv;
#define glColor3fv __gleColor3fv
extern PFNGLCOLOR3IPROC __gleColor3i;
#define glColor3i __gleColor3i
extern PFNGLCOLOR3IVPROC __gleColor3iv;
#define glColor3iv __gleColor3iv
extern PFNGLCOLOR3SPROC __gleColor3s;
#define glColor3s __gleColor3s
extern PFNGLCOLOR3SVPROC __gleColor3sv;
#define glColor3sv __gleColor3sv
extern PFNGLCOLOR3UBPROC __gleColor3ub;
#define glColor3ub __gleColor3ub
extern PFNGLCOLOR3UBVPROC __gleColor3ubv;
#define glColor3ubv __gleColor3ubv
extern PFNGLCOLOR3UIPROC __gleColor3ui;
#define glColor3ui __gleColor3ui
extern PFNGLCOLOR3UIVPROC __gleColor3uiv;
#define glColor3uiv __gleColor3uiv
extern PFNGLCOLOR3USPROC __gleColor3us;
#define glColor3us __gleColor3us
extern PFNGLCOLOR3USVPROC __gleColor3usv;
#define glColor3usv __gleColor3usv
extern PFNGLCOLOR4BPROC __gleColor4b;
#define glColor4b __gleColor4b
extern PFNGLCOLOR4BVPROC __gleColor4bv;
#define glColor4bv __gleColor4bv
extern PFNGLCOLOR4DPROC __gleColor4d;
#define glColor4d __gleColor4d
extern PFNGLCOLOR4DVPROC __gleColor4dv;
#define glColor4dv __gleColor4dv
extern PFNGLCOLOR4FPROC __gleColor4f;
#define glColor4f __gleColor4f
extern PFNGLCOLOR4FVPROC __gleColor4fv;
#define glColor4fv __gleColor4fv
extern PFNGLCOLOR4IPROC __gleColor4i;
#define glColor4i __gleColor4i
extern PFNGLCOLOR4IVPROC __gleColor4iv;
#define glColor4iv __gleColor4iv
extern PFNGLCOLOR4SPROC __gleColor4s;
#define glColor4s __gleColor4s
extern PFNGLCOLOR4SVPROC __gleColor4sv;
#define glColor4sv __gleColor4sv
extern PFNGLCOLOR4UBPROC __gleColor4ub;
#define glColor4ub __gleColor4ub
extern PFNGLCOLOR4UBVPROC __gleColor4ubv;
#define glColor4ubv __gleColor4ubv
extern PFNGLCOLOR4UIPROC __gleColor4ui;
#define glColor4ui __gleColor4ui
extern PFNGLCOLOR4UIVPROC __gleColor4uiv;
#define glColor4uiv __gleColor4uiv
extern PFNGLCOLOR4USPROC __gleColor4us;
#define glColor4us __gleColor4us
extern PFNGLCOLOR4USVPROC __gleColor4usv;
#define glColor4usv __gleColor4usv
extern PFNGLEDGEFLAGPROC __gleEdgeFlag;
#define glEdgeFlag __gleEdgeFlag
extern PFNGLEDGEFLAGVPROC __gleEdgeFlagv;
#define glEdgeFlagv __gleEdgeFlagv
extern PFNGLENDPROC __gleEnd;
#define glEnd __gleEnd
extern PFNGLINDEXDPROC __gleIndexd;
#define glIndexd __gleIndexd
extern PFNGLINDEXDVPROC __gleIndexdv;
#define glIndexdv __gleIndexdv
extern PFNGLINDEXFPROC __gleIndexf;
#define glIndexf __gleIndexf
extern PFNGLINDEXFVPROC __gleIndexfv;
#define glIndexfv __gleIndexfv
extern PFNGLINDEXIPROC __gleIndexi;
#define glIndexi __gleIndexi
extern PFNGLINDEXIVPROC __gleIndexiv;
#define glIndexiv __gleIndexiv
extern PFNGLINDEXSPROC __gleIndexs;
#define glIndexs __gleIndexs
extern PFNGLINDEXSVPROC __gleIndexsv;
#define glIndexsv __gleIndexsv
extern PFNGLNORMAL3BPROC __gleNormal3b;
#define glNormal3b __gleNormal3b
extern PFNGLNORMAL3BVPROC __gleNormal3bv;
#define glNormal3bv __gleNormal3bv
extern PFNGLNORMAL3DPROC __gleNormal3d;
#define glNormal3d __gleNormal3d
extern PFNGLNORMAL3DVPROC __gleNormal3dv;
#define glNormal3dv __gleNormal3dv
extern PFNGLNORMAL3FPROC __gleNormal3f;
#define glNormal3f __gleNormal3f
extern PFNGLNORMAL3FVPROC __gleNormal3fv;
#define glNormal3fv __gleNormal3fv
extern PFNGLNORMAL3IPROC __gleNormal3i;
#define glNormal3i __gleNormal3i
extern PFNGLNORMAL3IVPROC __gleNormal3iv;
#define glNormal3iv __gleNormal3iv
extern PFNGLNORMAL3SPROC __gleNormal3s;
#define glNormal3s __gleNormal3s
extern PFNGLNORMAL3SVPROC __gleNormal3sv;
#define glNormal3sv __gleNormal3sv
extern PFNGLRASTERPOS2DPROC __gleRasterPos2d;
#define glRasterPos2d __gleRasterPos2d
extern PFNGLRASTERPOS2DVPROC __gleRasterPos2dv;
#define glRasterPos2dv __gleRasterPos2dv
extern PFNGLRASTERPOS2FPROC __gleRasterPos2f;
#define glRasterPos2f __gleRasterPos2f
extern PFNGLRASTERPOS2FVPROC __gleRasterPos2fv;
#define glRasterPos2fv __gleRasterPos2fv
extern PFNGLRASTERPOS2IPROC __gleRasterPos2i;
#define glRasterPos2i __gleRasterPos2i
extern PFNGLRASTERPOS2IVPROC __gleRasterPos2iv;
#define glRasterPos2iv __gleRasterPos2iv
extern PFNGLRASTERPOS2SPROC __gleRasterPos2s;
#define glRasterPos2s __gleRasterPos2s
extern PFNGLRASTERPOS2SVPROC __gleRasterPos2sv;
#define glRasterPos2sv __gleRasterPos2sv
extern PFNGLRASTERPOS3DPROC __gleRasterPos3d;
#define glRasterPos3d __gleRasterPos3d
extern PFNGLRASTERPOS3DVPROC __gleRasterPos3dv;
#define glRasterPos3dv __gleRasterPos3dv
extern PFNGLRASTERPOS3FPROC __gleRasterPos3f;
#define glRasterPos3f __gleRasterPos3f
extern PFNGLRASTERPOS3FVPROC __gleRasterPos3fv;
#define glRasterPos3fv __gleRasterPos3fv
extern PFNGLRASTERPOS3IPROC __gleRasterPos3i;
#define glRasterPos3i __gleRasterPos3i
extern PFNGLRASTERPOS3IVPROC __gleRasterPos3iv;
#define glRasterPos3iv __gleRasterPos3iv
extern PFNGLRASTERPOS3SPROC __gleRasterPos3s;
#define glRasterPos3s __gleRasterPos3s
extern PFNGLRASTERPOS3SVPROC __gleRasterPos3sv;
#define glRasterPos3sv __gleRasterPos3sv
extern PFNGLRASTERPOS4DPROC __gleRasterPos4d;
#define glRasterPos4d __gleRasterPos4d
extern PFNGLRASTERPOS4DVPROC __gleRasterPos4dv;
#define glRasterPos4dv __gleRasterPos4dv
extern PFNGLRASTERPOS4FPROC __gleRasterPos4f;
#define glRasterPos4f __gleRasterPos4f
extern PFNGLRASTERPOS4FVPROC __gleRasterPos4fv;
#define glRasterPos4fv __gleRasterPos4fv
extern PFNGLRASTERPOS4IPROC __gleRasterPos4i;
#define glRasterPos4i __gleRasterPos4i
extern PFNGLRASTERPOS4IVPROC __gleRasterPos4iv;
#define glRasterPos4iv __gleRasterPos4iv
extern PFNGLRASTERPOS4SPROC __gleRasterPos4s;
#define glRasterPos4s __gleRasterPos4s
extern PFNGLRASTERPOS4SVPROC __gleRasterPos4sv;
#define glRasterPos4sv __gleRasterPos4sv
extern PFNGLRECTDPROC __gleRectd;
#define glRectd __gleRectd
extern PFNGLRECTDVPROC __gleRectdv;
#define glRectdv __gleRectdv
extern PFNGLRECTFPROC __gleRectf;
#define glRectf __gleRectf
extern PFNGLRECTFVPROC __gleRectfv;
#define glRectfv __gleRectfv
extern PFNGLRECTIPROC __gleRecti;
#define glRecti __gleRecti
extern PFNGLRECTIVPROC __gleRectiv;
#define glRectiv __gleRectiv
extern PFNGLRECTSPROC __gleRects;
#define glRects __gleRects
extern PFNGLRECTSVPROC __gleRectsv;
#define glRectsv __gleRectsv
extern PFNGLTEXCOORD1DPROC __gleTexCoord1d;
#define glTexCoord1d __gleTexCoord1d
extern PFNGLTEXCOORD1DVPROC __gleTexCoord1dv;
#define glTexCoord1dv __gleTexCoord1dv
extern PFNGLTEXCOORD1FPROC __gleTexCoord1f;
#define glTexCoord1f __gleTexCoord1f
extern PFNGLTEXCOORD1FVPROC __gleTexCoord1fv;
#define glTexCoord1fv __gleTexCoord1fv
extern PFNGLTEXCOORD1IPROC __gleTexCoord1i;
#define glTexCoord1i __gleTexCoord1i
extern PFNGLTEXCOORD1IVPROC __gleTexCoord1iv;
#define glTexCoord1iv __gleTexCoord1iv
extern PFNGLTEXCOORD1SPROC __gleTexCoord1s;
#define glTexCoord1s __gleTexCoord1s
extern PFNGLTEXCOORD1SVPROC __gleTexCoord1sv;
#define glTexCoord1sv __gleTexCoord1sv
extern PFNGLTEXCOORD2DPROC __gleTexCoord2d;
#define glTexCoord2d __gleTexCoord2d
extern PFNGLTEXCOORD2DVPROC __gleTexCoord2dv;
#define glTexCoord2dv __gleTexCoord2dv
extern PFNGLTEXCOORD2FPROC __gleTexCoord2f;
#define glTexCoord2f __gleTexCoord2f
extern PFNGLTEXCOORD2FVPROC __gleTexCoord2fv;
#define glTexCoord2fv __gleTexCoord2fv
extern PFNGLTEXCOORD2IPROC __gleTexCoord2i;
#define glTexCoord2i __gleTexCoord2i
extern PFNGLTEXCOORD2IVPROC __gleTexCoord2iv;
#define glTexCoord2iv __gleTexCoord2iv
extern PFNGLTEXCOORD2SPROC __gleTexCoord2s;
#define glTexCoord2s __gleTexCoord2s
extern PFNGLTEXCOORD2SVPROC __gleTexCoord2sv;
#define glTexCoord2sv __gleTexCoord2sv
extern PFNGLTEXCOORD3DPROC __gleTexCoord3d;
#define glTexCoord3d __gleTexCoord3d
extern PFNGLTEXCOORD3DVPROC __gleTexCoord3dv;
#define glTexCoord3dv __gleTexCoord3dv
extern PFNGLTEXCOORD3FPROC __gleTexCoord3f;
#define glTexCoord3f __gleTexCoord3f
extern PFNGLTEXCOORD3FVPROC __gleTexCoord3fv;
#define glTexCoord3fv __gleTexCoord3fv
extern PFNGLTEXCOORD3IPROC __gleTexCoord3i;
#define glTexCoord3i __gleTexCoord3i
extern PFNGLTEXCOORD3IVPROC __gleTexCoord3iv;
#define glTexCoord3iv __gleTexCoord3iv
extern PFNGLTEXCOORD3SPROC __gleTexCoord3s;
#define glTexCoord3s __gleTexCoord3s
extern PFNGLTEXCOORD3SVPROC __gleTexCoord3sv;
#define glTexCoord3sv __gleTexCoord3sv
extern PFNGLTEXCOORD4DPROC __gleTexCoord4d;
#define glTexCoord4d __gleTexCoord4d
extern PFNGLTEXCOORD4DVPROC __gleTexCoord4dv;
#define glTexCoord4dv __gleTexCoord4dv
extern PFNGLTEXCOORD4FPROC __gleTexCoord4f;
#define glTexCoord4f __gleTexCoord4f
extern PFNGLTEXCOORD4FVPROC __gleTexCoord4fv;
#define glTexCoord4fv __gleTexCoord4fv
extern PFNGLTEXCOORD4IPROC __gleTexCoord4i;
#define glTexCoord4i __gleTexCoord4i
extern PFNGLTEXCOORD4IVPROC __gleTexCoord4iv;
#define glTexCoord4iv __gleTexCoord4iv
extern PFNGLTEXCOORD4SPROC __gleTexCoord4s;
#define glTexCoord4s __gleTexCoord4s
extern PFNGLTEXCOORD4SVPROC __gleTexCoord4sv;
#define glTexCoord4sv __gleTexCoord4sv
extern PFNGLVERTEX2DPROC __gleVertex2d;
#define glVertex2d __gleVertex2d
extern PFNGLVERTEX2DVPROC __gleVertex2dv;
#define glVertex2dv __gleVertex2dv
extern PFNGLVERTEX2FPROC __gleVertex2f;
#define glVertex2f __gleVertex2f
extern PFNGLVERTEX2FVPROC __gleVertex2fv;
#define glVertex2fv __gleVertex2fv
extern PFNGLVERTEX2IPROC __gleVertex2i;
#define glVertex2i __gleVertex2i
extern PFNGLVERTEX2IVPROC __gleVertex2iv;
#define glVertex2iv __gleVertex2iv
extern PFNGLVERTEX2SPROC __gleVertex2s;
#define glVertex2s __gleVertex2s
extern PFNGLVERTEX2SVPROC __gleVertex2sv;
#define glVertex2sv __gleVertex2sv
extern PFNGLVERTEX3DPROC __gleVertex3d;
#define glVertex3d __gleVertex3d
extern PFNGLVERTEX3DVPROC __gleVertex3dv;
#define glVertex3dv __gleVertex3dv
extern PFNGLVERTEX3FPROC __gleVertex3f;
#define glVertex3f __gleVertex3f
extern PFNGLVERTEX3FVPROC __gleVertex3fv;
#define glVertex3fv __gleVertex3fv
extern PFNGLVERTEX3IPROC __gleVertex3i;
#define glVertex3i __gleVertex3i
extern PFNGLVERTEX3IVPROC __gleVertex3iv;
#define glVertex3iv __gleVertex3iv
extern PFNGLVERTEX3SPROC __gleVertex3s;
#define glVertex3s __gleVertex3s
extern PFNGLVERTEX3SVPROC __gleVertex3sv;
#define glVertex3sv __gleVertex3sv
extern PFNGLVERTEX4DPROC __gleVertex4d;
#define glVertex4d __gleVertex4d
extern PFNGLVERTEX4DVPROC __gleVertex4dv;
#define glVertex4dv __gleVertex4dv
extern PFNGLVERTEX4FPROC __gleVertex4f;
#define glVertex4f __gleVertex4f
extern PFNGLVERTEX4FVPROC __gleVertex4fv;
#define glVertex4fv __gleVertex4fv
extern PFNGLVERTEX4IPROC __gleVertex4i;
#define glVertex4i __gleVertex4i
extern PFNGLVERTEX4IVPROC __gleVertex4iv;
#define glVertex4iv __gleVertex4iv
extern PFNGLVERTEX4SPROC __gleVertex4s;
#define glVertex4s __gleVertex4s
extern PFNGLVERTEX4SVPROC __gleVertex4sv;
#define glVertex4sv __gleVertex4sv
extern PFNGLCLIPPLANEPROC __gleClipPlane;
#define glClipPlane __gleClipPlane
extern PFNGLCOLORMATERIALPROC __gleColorMaterial;
#define glColorMaterial __gleColorMaterial
extern PFNGLFOGFPROC __gleFogf;
#define glFogf __gleFogf
extern PFNGLFOGFVPROC __gleFogfv;
#define glFogfv __gleFogfv
extern PFNGLFOGIPROC __gleFogi;
#define glFogi __gleFogi
extern PFNGLFOGIVPROC __gleFogiv;
#define glFogiv __gleFogiv
extern PFNGLLIGHTFPROC __gleLightf;
#define glLightf __gleLightf
extern PFNGLLIGHTFVPROC __gleLightfv;
#define glLightfv __gleLightfv
extern PFNGLLIGHTIPROC __gleLighti;
#define glLighti __gleLighti
extern PFNGLLIGHTIVPROC __gleLightiv;
#define glLightiv __gleLightiv
extern PFNGLLIGHTMODELFPROC __gleLightModelf;
#define glLightModelf __gleLightModelf
extern PFNGLLIGHTMODELFVPROC __gleLightModelfv;
#define glLightModelfv __gleLightModelfv
extern PFNGLLIGHTMODELIPROC __gleLightModeli;
#define glLightModeli __gleLightModeli
extern PFNGLLIGHTMODELIVPROC __gleLightModeliv;
#define glLightModeliv __gleLightModeliv
extern PFNGLLINESTIPPLEPROC __gleLineStipple;
#define glLineStipple __gleLineStipple
extern PFNGLMATERIALFPROC __gleMaterialf;
#define glMaterialf __gleMaterialf
extern PFNGLMATERIALFVPROC __gleMaterialfv;
#define glMaterialfv __gleMaterialfv
extern PFNGLMATERIALIPROC __gleMateriali;
#define glMateriali __gleMateriali
extern PFNGLMATERIALIVPROC __gleMaterialiv;
#define glMaterialiv __gleMaterialiv
extern PFNGLPOLYGONSTIPPLEPROC __glePolygonStipple;
#define glPolygonStipple __glePolygonStipple
extern PFNGLSHADEMODELPROC __gleShadeModel;
#define glShadeModel __gleShadeModel
extern PFNGLTEXENVFPROC __gleTexEnvf;
#define glTexEnvf __gleTexEnvf
extern PFNGLTEXENVFVPROC __gleTexEnvfv;
#define glTexEnvfv __gleTexEnvfv
extern PFNGLTEXENVIPROC __gleTexEnvi;
#define glTexEnvi __gleTexEnvi
extern PFNGLTEXENVIVPROC __gleTexEnviv;
#define glTexEnviv __gleTexEnviv
extern PFNGLTEXGENDPROC __gleTexGend;
#define glTexGend __gleTexGend
extern PFNGLTEXGENDVPROC __gleTexGendv;
#define glTexGendv __gleTexGendv
extern PFNGLTEXGENFPROC __gleTexGenf;
#define glTexGenf __gleTexGenf
extern PFNGLTEXGENFVPROC __gleTexGenfv;
#define glTexGenfv __gleTexGenfv
extern PFNGLTEXGENIPROC __gleTexGeni;
#define glTexGeni __gleTexGeni
extern PFNGLTEXGENIVPROC __gleTexGeniv;
#define glTexGeniv __gleTexGeniv
extern PFNGLFEEDBACKBUFFERPROC __gleFeedbackBuffer;
#define glFeedbackBuffer __gleFeedbackBuffer
extern PFNGLSELECTBUFFERPROC __gleSelectBuffer;
#define glSelectBuffer __gleSelectBuffer
extern PFNGLRENDERMODEPROC __gleRenderMode;
#define glRenderMode __gleRenderMode
extern PFNGLINITNAMESPROC __gleInitNames;
#define glInitNames __gleInitNames
extern PFNGLLOADNAMEPROC __gleLoadName;
#define glLoadName __gleLoadName
extern PFNGLPASSTHROUGHPROC __glePassThrough;
#define glPassThrough __glePassThrough
extern PFNGLPOPNAMEPROC __glePopName;
#define glPopName __glePopName
extern PFNGLPUSHNAMEPROC __glePushName;
#define glPushName __glePushName
extern PFNGLCLEARACCUMPROC __gleClearAccum;
#define glClearAccum __gleClearAccum
extern PFNGLCLEARINDEXPROC __gleClearIndex;
#define glClearIndex __gleClearIndex
extern PFNGLINDEXMASKPROC __gleIndexMask;
#define glIndexMask __gleIndexMask
extern PFNGLACCUMPROC __gleAccum;
#define glAccum __gleAccum
extern PFNGLPOPATTRIBPROC __glePopAttrib;
#define glPopAttrib __glePopAttrib
extern PFNGLPUSHATTRIBPROC __glePushAttrib;
#define glPushAttrib __glePushAttrib
extern PFNGLMAP1DPROC __gleMap1d;
#define glMap1d __gleMap1d
extern PFNGLMAP1FPROC __gleMap1f;
#define glMap1f __gleMap1f
extern PFNGLMAP2DPROC __gleMap2d;
#define glMap2d __gleMap2d
extern PFNGLMAP2FPROC __gleMap2f;
#define glMap2f __gleMap2f
extern PFNGLMAPGRID1DPROC __gleMapGrid1d;
#define glMapGrid1d __gleMapGrid1d
extern PFNGLMAPGRID1FPROC __gleMapGrid1f;
#define glMapGrid1f __gleMapGrid1f
extern PFNGLMAPGRID2DPROC __gleMapGrid2d;
#define glMapGrid2d __gleMapGrid2d
extern PFNGLMAPGRID2FPROC __gleMapGrid2f;
#define glMapGrid2f __gleMapGrid2f
extern PFNGLEVALCOORD1DPROC __gleEvalCoord1d;
#define glEvalCoord1d __gleEvalCoord1d
extern PFNGLEVALCOORD1DVPROC __gleEvalCoord1dv;
#define glEvalCoord1dv __gleEvalCoord1dv
extern PFNGLEVALCOORD1FPROC __gleEvalCoord1f;
#define glEvalCoord1f __gleEvalCoord1f
extern PFNGLEVALCOORD1FVPROC __gleEvalCoord1fv;
#define glEvalCoord1fv __gleEvalCoord1fv
extern PFNGLEVALCOORD2DPROC __gleEvalCoord2d;
#define glEvalCoord2d __gleEvalCoord2d
extern PFNGLEVALCOORD2DVPROC __gleEvalCoord2dv;
#define glEvalCoord2dv __gleEvalCoord2dv
extern PFNGLEVALCOORD2FPROC __gleEvalCoord2f;
#define glEvalCoord2f __gleEvalCoord2f
extern PFNGLEVALCOORD2FVPROC __gleEvalCoord2fv;
#define glEvalCoord2fv __gleEvalCoord2fv
extern PFNGLEVALMESH1PROC __gleEvalMesh1;
#define glEvalMesh1 __gleEvalMesh1
extern PFNGLEVALPOINT1PROC __gleEvalPoint1;
#define glEvalPoint1 __gleEvalPoint1
extern PFNGLEVALMESH2PROC __gleEvalMesh2;
#define glEvalMesh2 __gleEvalMesh2
extern PFNGLEVALPOINT2PROC __gleEvalPoint2;
#define glEvalPoint2 __gleEvalPoint2
extern PFNGLALPHAFUNCPROC __gleAlphaFunc;
#define glAlphaFunc __gleAlphaFunc
extern PFNGLPIXELZOOMPROC __glePixelZoom;
#define glPixelZoom __glePixelZoom
extern PFNGLPIXELTRANSFERFPROC __glePixelTransferf;
#define glPixelTransferf __glePixelTransferf
extern PFNGLPIXELTRANSFERIPROC __glePixelTransferi;
#define glPixelTransferi __glePixelTransferi
extern PFNGLPIXELMAPFVPROC __glePixelMapfv;
#define glPixelMapfv __glePixelMapfv
extern PFNGLPIXELMAPUIVPROC __glePixelMapuiv;
#define glPixelMapuiv __glePixelMapuiv
extern PFNGLPIXELMAPUSVPROC __glePixelMapusv;
#define glPixelMapusv __glePixelMapusv
extern PFNGLCOPYPIXELSPROC __gleCopyPixels;
#define glCopyPixels __gleCopyPixels
extern PFNGLDRAWPIXELSPROC __gleDrawPixels;
#define glDrawPixels __gleDrawPixels
extern PFNGLGETCLIPPLANEPROC __gleGetClipPlane;
#define glGetClipPlane __gleGetClipPlane
extern PFNGLGETLIGHTFVPROC __gleGetLightfv;
#define glGetLightfv __gleGetLightfv
extern PFNGLGETLIGHTIVPROC __gleGetLightiv;
#define glGetLightiv __gleGetLightiv
extern PFNGLGETMAPDVPROC __gleGetMapdv;
#define glGetMapdv __gleGetMapdv
extern PFNGLGETMAPFVPROC __gleGetMapfv;
#define glGetMapfv __gleGetMapfv
extern PFNGLGETMAPIVPROC __gleGetMapiv;
#define glGetMapiv __gleGetMapiv
extern PFNGLGETMATERIALFVPROC __gleGetMaterialfv;
#define glGetMaterialfv __gleGetMaterialfv
extern PFNGLGETMATERIALIVPROC __gleGetMaterialiv;
#define glGetMaterialiv __gleGetMaterialiv
extern PFNGLGETPIXELMAPFVPROC __gleGetPixelMapfv;
#define glGetPixelMapfv __gleGetPixelMapfv
extern PFNGLGETPIXELMAPUIVPROC __gleGetPixelMapuiv;
#define glGetPixelMapuiv __gleGetPixelMapuiv
extern PFNGLGETPIXELMAPUSVPROC __gleGetPixelMapusv;
#define glGetPixelMapusv __gleGetPixelMapusv
extern PFNGLGETPOLYGONSTIPPLEPROC __gleGetPolygonStipple;
#define glGetPolygonStipple __gleGetPolygonStipple
extern PFNGLGETTEXENVFVPROC __gleGetTexEnvfv;
#define glGetTexEnvfv __gleGetTexEnvfv
extern PFNGLGETTEXENVIVPROC __gleGetTexEnviv;
#define glGetTexEnviv __gleGetTexEnviv
extern PFNGLGETTEXGENDVPROC __gleGetTexGendv;
#define glGetTexGendv __gleGetTexGendv
extern PFNGLGETTEXGENFVPROC __gleGetTexGenfv;
#define glGetTexGenfv __gleGetTexGenfv
extern PFNGLGETTEXGENIVPROC __gleGetTexGeniv;
#define glGetTexGeniv __gleGetTexGeniv
extern PFNGLISLISTPROC __gleIsList;
#define glIsList __gleIsList
extern PFNGLFRUSTUMPROC __gleFrustum;
#define glFrustum __gleFrustum
extern PFNGLLOADIDENTITYPROC __gleLoadIdentity;
#define glLoadIdentity __gleLoadIdentity
extern PFNGLLOADMATRIXFPROC __gleLoadMatrixf;
#define glLoadMatrixf __gleLoadMatrixf
extern PFNGLLOADMATRIXDPROC __gleLoadMatrixd;
#define glLoadMatrixd __gleLoadMatrixd
extern PFNGLMATRIXMODEPROC __gleMatrixMode;
#define glMatrixMode __gleMatrixMode
extern PFNGLMULTMATRIXFPROC __gleMultMatrixf;
#define glMultMatrixf __gleMultMatrixf
extern PFNGLMULTMATRIXDPROC __gleMultMatrixd;
#define glMultMatrixd __gleMultMatrixd
extern PFNGLORTHOPROC __gleOrtho;
#define glOrtho __gleOrtho
extern PFNGLPOPMATRIXPROC __glePopMatrix;
#define glPopMatrix __glePopMatrix
extern PFNGLPUSHMATRIXPROC __glePushMatrix;
#define glPushMatrix __glePushMatrix
extern PFNGLROTATEDPROC __gleRotated;
#define glRotated __gleRotated
extern PFNGLROTATEFPROC __gleRotatef;
#define glRotatef __gleRotatef
extern PFNGLSCALEDPROC __gleScaled;
#define glScaled __gleScaled
extern PFNGLSCALEFPROC __gleScalef;
#define glScalef __gleScalef
extern PFNGLTRANSLATEDPROC __gleTranslated;
#define glTranslated __gleTranslated
extern PFNGLTRANSLATEFPROC __gleTranslatef;
#define glTranslatef __gleTranslatef
extern PFNGLARRAYELEMENTPROC __gleArrayElement;
#define glArrayElement __gleArrayElement
extern PFNGLCOLORPOINTERPROC __gleColorPointer;
#define glColorPointer __gleColorPointer
extern PFNGLDISABLECLIENTSTATEPROC __gleDisableClientState;
#define glDisableClientState __gleDisableClientState
extern PFNGLEDGEFLAGPOINTERPROC __gleEdgeFlagPointer;
#define glEdgeFlagPointer __gleEdgeFlagPointer
extern PFNGLENABLECLIENTSTATEPROC __gleEnableClientState;
#define glEnableClientState __gleEnableClientState
extern PFNGLINDEXPOINTERPROC __gleIndexPointer;
#define glIndexPointer __gleIndexPointer
extern PFNGLINTERLEAVEDARRAYSPROC __gleInterleavedArrays;
#define glInterleavedArrays __gleInterleavedArrays
extern PFNGLNORMALPOINTERPROC __gleNormalPointer;
#define glNormalPointer __gleNormalPointer
extern PFNGLTEXCOORDPOINTERPROC __gleTexCoordPointer;
#define glTexCoordPointer __gleTexCoordPointer
extern PFNGLVERTEXPOINTERPROC __gleVertexPointer;
#define glVertexPointer __gleVertexPointer
extern PFNGLARETEXTURESRESIDENTPROC __gleAreTexturesResident;
#define glAreTexturesResident __gleAreTexturesResident
extern PFNGLPRIORITIZETEXTURESPROC __glePrioritizeTextures;
#define glPrioritizeTextures __glePrioritizeTextures
extern PFNGLPOPCLIENTATTRIBPROC __glePopClientAttrib;
#define glPopClientAttrib __glePopClientAttrib
extern PFNGLPUSHCLIENTATTRIBPROC __glePushClientAttrib;
#define glPushClientAttrib __glePushClientAttrib


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_1_1_REM_3_1_H

