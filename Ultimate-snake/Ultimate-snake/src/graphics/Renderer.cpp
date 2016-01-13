#include "Renderer.h"

namespace graphics {

	Renderer::Renderer(const Window &win)
		:snakeShader("src/graphics/Shaders/VertexShader.txt",
			"src/graphics/Shaders/FragShader.txt")
	{
		if (snakeShader.isError())
		{
			std::cerr << "Error creating shaders !" << std::endl << (snakeShader).getError() << std::endl;
			error = true;
			return;
		}

		GLint sizeLocation = glGetUniformLocation((snakeShader).getProgram(), "screenRes");
		glUseProgram((snakeShader).getProgram());
		glUniform2f(sizeLocation, win.getWidth(), win.getHeight());
		glUseProgram(0);
	}

	Renderer::~Renderer()
	{
		
	}

	void Renderer::render(Snake snake)
	{
		glUseProgram((snakeShader).getProgram());
		snake.draw();
		glUseProgram(0);
	}
}