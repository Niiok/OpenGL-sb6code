#pragma once

#include "sb6.h"

static const GLchar* Tcontrol_shader_source[] =
{
	"	#version 430 core																\n"
	"																					\n"
	"	layout (vertices = 3) out;														\n"
	"																					\n"
	"	void main(void)																	\n"
	"	{																				\n"
	"		if (gl_InvocationID == 0)													\n"
	"		{																			\n"
	"			gl_TessLevelInner[0] = 5.0;												\n"
	"			gl_TessLevelOuter[0] = 5.0;												\n"
	"			gl_TessLevelOuter[1] = 5.0;												\n"
	"			gl_TessLevelOuter[2] = 5.0;												\n"
	"		}																			\n"
	"		gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;	\n"
	"	}																				\n"
};