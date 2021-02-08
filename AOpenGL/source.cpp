#include "sb6.h"
#include <math.h>
//#include <assert.h>
#include "shader.h"

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

		GLfloat spin_speed = 1.0f;
		GLfloat attrib[] = {
			(float)sin(currentTime * spin_speed) * 0.5f,
			(float)cos(currentTime * spin_speed) * 0.5f,
			0.0f, 0.0f
		};
		glVertexAttrib4fv(0, attrib);


		GLfloat vs_color[] = {
			(float)0.5f,//tan(currentTime+0.5f) * 0.5f,
			(float)sin(currentTime+0.5f) * 0.5f,
			(float)cos(currentTime+0.5f) * 0.5f,
			0.0f
		};
		glVertexAttrib4fv(1, vs_color);


		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void startup() override
	{
		rendering_program = compile_shaders();
		glGenVertexArrays(1, &vertex_array_object);
		glBindVertexArray(vertex_array_object);
		glPointSize(50.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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
