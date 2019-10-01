#pragma once
#include <iostream> 
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace odin { 
	namespace graphics {
		class Window
		{
			private: 
				int m_width, m_height;
				const char *m_title;
				GLFWwindow *m_window;

			public:
				Window(const char *title, int width, int height);
				~Window();
				void clear() const;
				void update();
				bool closed() const;

				inline int getWidth() const { return m_width; };
				inline int getHeight() const { return m_height; };

			private:
				bool init();
		};
	}
}