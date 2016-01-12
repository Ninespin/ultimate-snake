#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <ios>
#include <fstream>

namespace graphics{
	class Shader
	{
	private:
		static unsigned long getFileLength(std::ifstream& in);
	public:
		int loadShaderSource(const char* fileName, GLchar** shaderSource, unsigned long& len);
		void unloadShaderSource(GLchar** shaderSource);
	public:
		
	};
}