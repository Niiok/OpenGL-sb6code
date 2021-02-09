#pragma once

#include "sb6.h"

static const GLchar* Tevaluation_shader_source[] =
{
	"	#version 430 core																\n"
	"																					\n"
	"	layout (triangles, equal_spacing, cw) in;										\n"
	"																					\n"
	"	void main(void)																	\n"
	"	{																				\n"
	"		gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position) +						\n"
	"						(gl_TessCoord.y * gl_in[1].gl_Position) +					\n"
	"						(gl_TessCoord.z * gl_in[2].gl_Position);					\n"
	"	}																				\n"
};