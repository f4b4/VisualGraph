// ShaderCode.h
#pragma once

namespace oggl {

const char* g_defaultVertexShader =
{
	"#version 330\n"

	"layout(location = 0) in vec4 position;\n"
	"layout(location = 1) in vec4 color;\n"

	"out vec4 ex_Color;\n"

	"uniform mat4x4 projMatrix;\n"

	"void main()\n"
	"{\n"
	"   gl_Position = projMatrix * position;\n"
	"   ex_Color = color;\n"
	"}\n"
};

const char* g_nodesBorderVertexShader =
{
	"#version 330\n"

	"layout(location = 0) in vec4 position;\n"

	"out vec4 ex_Color;\n"

	"uniform mat4x4 projMatrix;\n"
	"uniform vec4 color;\n"

	"void main()\n"
	"{\n"
	"   gl_Position = projMatrix * position;\n"
	"   ex_Color = color;\n"
	"}\n"
};

const char* g_defaultFragmentShader =
{
	"#version 330\n"\

	"in vec4 ex_Color;\n"\
	"out vec4 out_Color;\n"\

	"void main(void)\n"\
	"{\n"\
	"	out_Color = ex_Color;\n"\
	"}\n"
};

}