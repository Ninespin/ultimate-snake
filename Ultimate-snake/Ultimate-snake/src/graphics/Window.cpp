#include "Window.h"

namespace graphics {

	Window::Window(int width, int height, const char* title)
	{
		this->width = width;
		this->height = height;
		this->title = title;

		isError = init();
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}


	bool Window::init() 
	{
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window) 
		{
			return false;
		}

		glfwSetWindowUserPointer(window, this);

		glfwSetKeyCallback(window, key_callback);
		glfwSetWindowSizeCallback(window, resize_callback);

		glfwMakeContextCurrent(window);
		return true;
	}

	void Window::update()
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, 10, 0, 10, 1, -1);
	}

	void Window::postUpdate()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool Window::shouldClose() const
	{
		return glfwWindowShouldClose(window);
	}

	bool Window::hasAnError() const
	{
		return isError;
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}

	void Window::resize_callback(GLFWwindow* window, int width, int height)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);

		glfwGetFramebufferSize(window, &((*user).width), &((*user).height));

		glViewport(0, 0, user->width, user->height);
	}
}