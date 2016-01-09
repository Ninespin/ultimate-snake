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
		(*keyboard).reset();
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

	void graphics::Window::setKeyboard(Keyboard * keyboard)
	{
		this->keyboard = keyboard;
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
		Window* user = (Window*)glfwGetWindowUserPointer(window);
		if (user->keyboard != 0)
		{
			user->keyboard->pressKey(key, action);
		}
	}

	void Window::resize_callback(GLFWwindow* window, int width, int height)
	{
		Window* user = (Window*)glfwGetWindowUserPointer(window);

		glfwGetFramebufferSize(window, &((*user).width), &((*user).height));

		glViewport(0, 0, user->width, user->height);
	}
}