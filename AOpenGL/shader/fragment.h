#pragma once

#include "sb6.h"

static const GLchar* fragment_shader_source[] =
{
	"	#version 430 core						\n"
	"											\n"
	"	//in vec4 vs_color;						\n"
	"											\n"
	"	out vec4 color;							\n"
	"											\n"
	"	void main(void)							\n"
	"	{										\n"
	"		color = vec4(sin(gl_FragCoord.x * 0.25) * 0.5 + 0.5,					\n"
	"					 cos(gl_FragCoord.y * 0.25) * 0.5 + 0.5,					\n"
	"					 sin(gl_FragCoord.x * 0.15) *  cos(gl_FragCoord.y * 0.15),	\n"
	"					 1.0);														\n"
	"	}										\n"
};