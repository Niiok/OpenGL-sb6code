#pragma once

#include "sb6.h"

static const GLchar* vertex_shader_source[] =
{
	"	#version 430 core															\n"
	"																				\n"
	"	layout (location = 0) in vec4 offset;										\n"
	"	layout (location = 1) in vec4 color;										\n"
	"																				\n"
	"	out vec4 vs_color;															\n"
	"																				\n"
	"	void main(void)																\n"
	"	{																			\n"
	"		const vec4 vertices[3] = vec4[3] (vec4(0.25, -0.25, 0.5, 1.0), 			\n"
	"										 vec4(-0.25, -0.25, 0.5, 1.0),			\n"
	"										 vec4(0.25, 0.25, 0.5, 1.0));			\n"
	"																				\n"
	"		const vec4 colors[] = vec4[3]( vec4(1.0, 0.0, 0.0, 1.0),				\n"
	"										vec4(0.0, 1.0, 0.0, 1.0),				\n"
	"										vec4(0.0, 0.0, 1.0, 1.0));				\n"
	"																				\n"
	"		gl_Position = vertices[gl_VertexID] + offset;							\n"
	"																				\n"
	"		vs_color = colors[gl_VertexID];														\n"
	"	}																			\n"
};