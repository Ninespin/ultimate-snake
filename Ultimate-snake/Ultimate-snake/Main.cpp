#include <iostream>

#include <GLFW\glfw3.h>

int testGlFW();
void error_callback(int error, const char* description);

int main(int argc, char** argv) {
	return testGlFW();
}

int testGlFW() 
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialyse!" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(600, 600, "Ultimate Snake", NULL, NULL);

	if (!window) 
	{
		glfwTerminate();
		return 2;
		//comment
	}

	
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

#if 1
	glClearColor(1, 0, 0, 1);
#endif
	while (!glfwWindowShouldClose(window)) 
	{
#if 1
		glClear(GL_COLOR_BUFFER_BIT);
#endif
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description)
{
	std::cout << "GLFW error : <" << description << ">" << std::endl;
}