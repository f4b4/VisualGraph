#include <oggl/Shader.h>

#include <string>
#include <sstream>

#include <glload/gl_3_3_comp.h>
#include <glload/gll.h>

namespace oggl {

GLuint BuildShader(GLenum eShaderType, const std::string &shaderText);

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
	GLuint vertShader = BuildShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = BuildShader(GL_FRAGMENT_SHADER, fragmentShader);

	m_program = glCreateProgram();
	glAttachShader(m_program, vertShader);
	glAttachShader(m_program, fragShader);	
	glLinkProgram(m_program);

	GLint status;
	glGetProgramiv (m_program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		if(!glext_ARB_debug_output)
		{
			GLint infoLogLength;
			glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			glGetProgramInfoLog(m_program, infoLogLength, NULL, strInfoLog);
			fprintf(stderr, "Linker failure: %s\n", strInfoLog);
			delete[] strInfoLog;
		}

		throw std::runtime_error("Shader could not be linked.");
	}
}


Shader::~Shader(void)
{
	glDeleteProgram(m_program);
}

void Shader::Use(bool use)
{
	glUseProgram(use ? m_program : 0);
}

void Shader::Set(const char* uniform, const M4& matrix)
{
	int offsetLocation = glGetUniformLocation(m_program, uniform);
	if (offsetLocation == -1) throw std::runtime_error("glGetUniformLocation failed.");
	glUniformMatrix4fv(offsetLocation, 1, false, matrix.Transpose().data());
}

void Shader::Set(const char* uniform, const V4& vector)
{
	int offsetLocation = glGetUniformLocation(m_program, uniform);
	if (offsetLocation == -1) throw std::runtime_error("glGetUniformLocation failed.");
	glUniform4fv(offsetLocation, 1, vector.data());
}

GLuint BuildShader(GLenum eShaderType, const std::string &shaderText)
{
	GLuint shader = glCreateShader(eShaderType);
	const char *strFileData = shaderText.c_str();
	glShaderSource(shader, 1, &strFileData, NULL);

	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch(eShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		std::stringstream ss;
		ss << "Compile failure in " << strShaderType << " shader:\n" << strInfoLog;

		delete[] strInfoLog;

		throw std::runtime_error(ss.str());
	}

	return shader;
}

}