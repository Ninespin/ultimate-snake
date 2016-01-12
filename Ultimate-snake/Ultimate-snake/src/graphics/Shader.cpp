#include "Shader.h"

namespace graphics {


	unsigned long Shader::getFileLength(std::ifstream& in)
	{
		if (!in.good()) return 0;

		in.seekg(0, in.end);
		unsigned long length = in.tellg();
		in.seekg(0, in.beg);

		return length;
	}

	int Shader::loadShaderSource(const char* fileName, GLchar** shaderSource, unsigned long& len)
	{
		std::ifstream file;
		file.open(fileName, std::ios::in);
		if (!file)return -1;

		(len) = getFileLength(file);

		if (len == 0) return -2;

		*shaderSource = new char[len + 1];
		if (*shaderSource == 0) return -3;

		(*shaderSource)[len] = 0;

		unsigned i = 0;
		while (file.good())
		{
			(*shaderSource)[i] = file.get();       // get character from file.
			if (!file.eof())
				i++;
		}

		(*shaderSource)[i] = 0;//line terminator

		file.close();

		return 0;
	}

	void Shader::unloadShaderSource(GLchar** shaderSource)
	{
		if (*shaderSource != 0)
			delete[] * shaderSource;
		*shaderSource = 0;
	}
}