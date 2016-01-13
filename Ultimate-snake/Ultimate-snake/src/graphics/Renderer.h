#pragma once

#define GLEW_STATIC
#include <GL\glew.h>
#include <iostream>
#include "Window.h"
#include "../objects/Snake.h"
#include "Shader.h"
#include "../math/Vec2.h"

namespace graphics {
	
	//used to render stuff on the screen
	class Renderer
	{
	private:
		Shader snakeShader;
		bool error;
	public:
		Renderer(const Window &win);
		~Renderer();
		void render(Snake s);
		bool isError() const { return error; }
	};


}