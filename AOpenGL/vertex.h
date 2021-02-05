#include "sb6.h"

static const GLchar* vertex_shader_source[] =
{
	"	#version 430 core															\n"
	"																				\n"
	"	void main(void)																\n"
	"	{																			\n"
	"		const vec4 vertices[3] = vec4[3] (vec4(0.25, -0.25, 0.5, 1.0), 			\n"
	"										 vec4(-0.25, -0.25, 0.5, 1.0),			\n"
	"										 vec4(0.25, 0.25, 0.5, 1.0));			\n"
	"																				\n"
	"		gl_Position = vertices[gl_VertexID];									\n"
	"	}																			\n"
};