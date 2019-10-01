#include "window.h"

namespace odin {
	namespace graphics {
		void Reshape(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			m_title = title;
			m_width = width;
			m_height = height;

			if (!init()) {
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			//delete
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_window) == 1;
		}

		bool Window::init()
		{
			// Init glfw
			if (!glfwInit()) {
				std::cout << "Failed to init glwf!" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window) {
				std::cout << "Failed to create glwf window!" << std::endl;
				fprintf(stderr, "Failed to create glwf window: %s\n", "glfwGetError(?)");
				return false;
			}

			glfwMakeContextCurrent(m_window); 

			// Init glew
			glewExperimental = GL_TRUE;
			GLenum err = glewInit();

			if (GLEW_OK != err)
			{
				/* Problem: glewInit failed, something is seriously wrong. */
				fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
				return false;
			}

			fprintf(stdout, "Status: Using OpenGL %s\n", glewGetString(GL_VERSION));
			fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

			glfwSetWindowSizeCallback(m_window, Reshape);
			return true;
		}

		void Reshape(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}

}
