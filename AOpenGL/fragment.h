#include "sb6.h"

const GLchar* fragment_shader_source[] =
{
	"	#version 430 core						\n"
	"											\n"
	"	out vec4 color							\n"
	"											\n"
	"	void main(void)							\n"
	"	{										\n"
	"		color = vec4(0.0, 0.8, 1.0, 1.0);	\n"
	"	}										\n"
};