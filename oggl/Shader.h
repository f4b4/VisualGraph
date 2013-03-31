#pragma once

#include <oggl/Types.h>

namespace oggl {

class Shader
{
public:
	Shader() {};
	Shader(const char* vertexShader, const char* fragmentShader);
	~Shader(void);

	void Use(bool use);
	void Set(const char* uniform, const M4& matrix);
	void Set(const char* uniform, const V4& vector);

private:
	uint m_vShader, m_fShader;
	uint m_program;
};

}