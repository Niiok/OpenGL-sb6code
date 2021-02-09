#pragma once

#include "sb6.h"

static const GLchar* geometry_shader_source[] =
{
	"	#version 430 core																\n"
	"																					\n"
	"	layout (triangles) in;															\n"
	"	layout (points, max_vertices = 3) out;											\n"
	"																					\n"
	"																					\n"
	"	void main(void)																	\n"
	"	{																				\n"
	"		int i;																		\n"
	"																					\n"
	"		for(i = 0; i < gl_in.length(); i++)											\n"
	"		{																			\n"
	"			gl_Position = gl_in[i].gl_Position;										\n"
	"			EmitVertex();															\n"
	"		}																			\n"
	"	}																				\n"
};