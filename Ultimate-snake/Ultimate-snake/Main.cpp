#include <iostream>
#include <ctime>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "src\objects\Snake.h"
#include "src\graphics\Window.h"
#include "src\graphics\Shader.h"
#include "src\graphics\Renderer.h"
#include "src\objects\Orb.h"
#include "src\objects\Wall.h"

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

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cerr << "GLEW failed to initialyze!" << std::endl;
		return -2;
	}

	Renderer r(w);

	if (r.isError())
	{

	}

	glfwSwapInterval(1);

	glClearColor(0, 0, 0, 1);

	Snake s;
	Orb* testOrb = new Orb(10,10);
	Wall* testWall = new Wall(5,5);


	std::clock_t lastTimeMarkerMS = std::clock(), now;

	int h = 0;
	while (!w.shouldClose()) 
	{
		w.update();
		glClear(GL_COLOR_BUFFER_BIT);
		s.updateKeyboard(k);

		(*testOrb).update();
		(*testWall).update();

		//movement
		now = std::clock();
		double deltaT = (now - lastTimeMarkerMS) / (double)(CLOCKS_PER_SEC / 1000);
		if (deltaT >= s.getMoveDelayMS()) {
			if (s.isOverOrb(testOrb)) {
				s.addPart();
			}
			s.move();
			if (s.isOverWall(testWall)) {
				s.die();
			}
			
			lastTimeMarkerMS = now;
		}

		//draw
		r.render(s);


		w.postUpdate();
	}

	glfwTerminate();



	return 0;
}

void error_callback(int error, const char* description)
{
	std::cout << "GLFW error : <" << description << ">" << std::endl;
}