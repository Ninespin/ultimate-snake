#include <iostream>
#include <ctime>

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
	Keyboard k(w);

	glfwSwapInterval(1);

	glClearColor(0, 0, 0, 1);

	Snake s;
	long double lastTimeMarkerMS = time(0)*1000, now;

	while (!w.shouldClose()) 
	{
		w.update();
		glClear(GL_COLOR_BUFFER_BIT);
		
		//movement
		now = time(0)*1000;
		if (now - lastTimeMarkerMS >= 500) {//each 500 ms
			s.move();
			lastTimeMarkerMS = now;
		}

		if (k.isKeyPressed(GLFW_KEY_W)) 
		{
			std::cout << "W WAS PRASSAD!" << std::endl;
		}

		//draw
		s.draw();

		w.postUpdate();
	}

	glfwTerminate();

	return 0;
}

void error_callback(int error, const char* description)
{
	std::cout << "GLFW error : <" << description << ">" << std::endl;
}