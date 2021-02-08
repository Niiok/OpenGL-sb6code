#pragma once

#include "shader/vertex.h"
#include "shader/fragment.h"
#include "shader/Tcontrol.h"
#include "shader/Tevaluation.h"
#include <vector>

void shader_check(GLuint shader);

GLuint compile_shaders(void)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint Tcontrol_shader;
	GLuint Tevaluation_shader;
	GLuint program;

	extern const GLchar* vertex_shader_source[];
	extern const GLchar* fragment_shader_source[];
	extern const GLchar* Tcontrol_shader_source[];
	extern const GLchar* Tevaluation_shader_source[];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	Tcontrol_shader = glCreateShader(GL_TESS_CONTROL_SHADER);
	glShaderSource(Tcontrol_shader, 1, Tcontrol_shader_source, NULL);
	glCompileShader(Tcontrol_shader);
	shader_check(Tcontrol_shader);

	Tevaluation_shader = glCreateShader(GL_TESS_EVALUATION_SHADER);
	glShaderSource(Tevaluation_shader, 1, Tevaluation_shader_source, NULL);
	glCompileShader(Tevaluation_shader);
	shader_check(Tevaluation_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glAttachShader(program, Tcontrol_shader);
	glAttachShader(program, Tevaluation_shader);
	glLinkProgram(program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	glDeleteShader(Tcontrol_shader);
	glDeleteShader(Tevaluation_shader);
	if (glGetError()) glfwTerminate();

	return program;
}

void shader_check(GLuint shader)
{
	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);

		FILE* logger = fopen("shader_log.txt", "r+");
		fprintf(logger, "%s", errorLog);
		fclose(logger);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(shader); // Don't leak the shader.
		return;
	}
}