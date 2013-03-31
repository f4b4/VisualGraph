#ifndef _INT_GL_3_3_HPP
#define _INT_GL_3_3_HPP



#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


extern void (GLE_FUNCPTR *__gleVertexAttribDivisor)(GLuint , GLuint );
#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_3_3
	{
		GL_VERTEX_ATTRIB_ARRAY_DIVISOR   = 0x88FE,
	};

	inline void VertexAttribDivisor(GLuint index, GLuint divisor) { ::__gleVertexAttribDivisor(index, divisor); }

}

#endif //_INT_GL_3_3_HPP

