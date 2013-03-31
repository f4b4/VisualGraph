#ifndef _INT_GL_4_0_H
#define _INT_GL_4_0_H



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
typedef void (GLE_FUNCPTR * PFNGLMINSAMPLESHADINGPROC)(GLfloat );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONIPROC)(GLuint , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCIPROC)(GLuint , GLenum , GLenum );
typedef void (GLE_FUNCPTR * PFNGLBLENDFUNCSEPARATEIPROC)(GLuint , GLenum , GLenum , GLenum , GLenum );

extern PFNGLMINSAMPLESHADINGPROC __gleMinSampleShading;
#define glMinSampleShading __gleMinSampleShading
extern PFNGLBLENDEQUATIONIPROC __gleBlendEquationi;
#define glBlendEquationi __gleBlendEquationi
extern PFNGLBLENDEQUATIONSEPARATEIPROC __gleBlendEquationSeparatei;
#define glBlendEquationSeparatei __gleBlendEquationSeparatei
extern PFNGLBLENDFUNCIPROC __gleBlendFunci;
#define glBlendFunci __gleBlendFunci
extern PFNGLBLENDFUNCSEPARATEIPROC __gleBlendFuncSeparatei;
#define glBlendFuncSeparatei __gleBlendFuncSeparatei


#ifdef __cplusplus
}
#endif //__cplusplus


#endif //_INT_GL_4_0_H

