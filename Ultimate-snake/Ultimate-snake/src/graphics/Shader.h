#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <ios>
#include <fstream>

namespace graphics{
	class Shader
	{
	private:
		GLuint vertShader, fragShader;
		bool error;
		char* errorLog;
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();
	private:
		static unsigned long getFileLength(std::ifstream& in);
		int loadShaderSource(const char* fileName, GLchar** shaderSource, unsigned long& len);
		void unloadShaderSource(GLchar** shaderSource);
		bool testCompileStatus(GLuint shader);
	public:
		bool isError() const { return error; }
		const char* getError() const { return errorLog; }
	};
}