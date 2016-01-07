#include <iostream>

#include "Snake.h"
#include "src\graphics\Window.h"

#include <GLFW\glfw3.h>

int testGlFW();
void error_callback(int error, const char* description);

int main(int argc, char** argv) {
	return testGlFW();
}

int testGlFW() 
{
	using namespace graphics;
	
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialyse!" << std::endl;
		return 1;
	}
	
	Window w(600, 600, "ULTIMATE SNAAAAAKE");

	glfwSwapInterval(1);

	glClearColor(0, 0, 0, 1);

	Snake s;

	while (!w.shouldClose()) 
	{
		glClear(GL_COLOR_BUFFER_BIT);

		s.draw();

		w.update();
	}

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	std::cout << "GLFW error : <" << description << ">" << std::endl;
}