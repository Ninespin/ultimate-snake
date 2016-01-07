#pragma once

#include <GLFW\glfw3.h>


namespace graphics {

	/**
	 * Class used to manage a GLFW window
	*/
	class Window
	{
	private:
		GLFWwindow* window;
		int width, height;
		const char* title;
		bool isError = false;

	public:
		Window(int width, int height, const char* title);
		virtual ~Window();

		void update();
		void postUpdate();

		bool shouldClose() const;
		bool hasAnError() const;

	private:
		bool init();
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void resize_callback(GLFWwindow* window, int width, int height);
	};

}