#include <iostream>
#include "window.h"

int main()
{
	using namespace odin;
	using namespace graphics;

	Window window("Odin", 800, 600);
	glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		window.update();
	}

	system("PAUSE");
	return EXIT_SUCCESS;
}