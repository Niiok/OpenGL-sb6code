#include "sb6.h"
#include <math.h>
#include "vertex.h"
#include "fragment.h"

GLuint compile_shaders(void);

class my_application : public sb6::application
{
public:
	void render(double currentTime) override
	{
		const GLfloat color[] = {
			(float)sin(currentTime) * 0.5f,
			(float)cos(currentTime) * 0.5f,
			(float)tan(currentTime) * 0.5f,
			1.0f
		};
		glClearBufferfv(GL_COLOR, 0, color);

		glUseProgram(rendering_program);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void startup() override
	{
		rendering_program = compile_shaders();
		glGenVertexArrays(1, &vertex_array_object);
		glBindVertexArray(vertex_array_object);
		glPointSize(50.0f);
	}

	void shutdown() override
	{
		glDeleteVertexArrays(1, &vertex_array_object);
		glDeleteProgram(rendering_program);
	}

private:
	GLuint rendering_program;
	GLuint vertex_array_object;

};

GLuint compile_shaders(void)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;

	extern const GLchar *vertex_shader_source[];
	extern const GLchar *fragment_shader_source[];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);
	
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	return program;
}



	/*
	int shader_to_arr(FILE* fp, GLchar* arr[])
	{
		int c;
		int count = 0;
		GLchar out[1000];
		while ((c = getc(fp)) != EOF)
		{
			putc(c, stdin);
			fscanf(fp, "%s", out);
			fprintf(stdin, "%s", out);
			scanf("%s", *arr[count]);
			count++;
		}
		return 0;
	}
	*/

	DECLARE_MAIN(my_application);
