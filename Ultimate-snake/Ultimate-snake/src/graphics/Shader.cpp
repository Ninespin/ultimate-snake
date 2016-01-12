#include "Shader.h"

namespace graphics {


	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		vertShader = glCreateShader(GL_VERTEX_SHADER);
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		unsigned long vertSourceLength;
		GLchar * vertShaderSource[1];
		int vertSourceFetchErr = loadShaderSource(vertPath, vertShaderSource, vertSourceLength);

		unsigned long fragSourceLength;
		GLchar * fragShaderSource[1];
		int fragSourceFetchErr = loadShaderSource(fragPath, fragShaderSource, fragSourceLength);

		error = (vertSourceFetchErr != 0) || (fragSourceFetchErr != 0);

		if (error)
		{
			errorLog = "ERROR while reading shader files";
			return;
		}

		glShaderSource(vertShader, 1, vertShaderSource, NULL);
		glShaderSource(fragShader, 1, fragShaderSource, NULL);

		glCompileShader(vertShader);
		error = !testCompileStatus(vertShader);
		if (error) return;

		glCompileShader(fragShader);
		error = !testCompileStatus(fragShader);
		if (error) return;
	}

	Shader::~Shader()
	{
		delete[] errorLog;
	}

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

	bool graphics::Shader::testCompileStatus(GLuint shader)
	{
		GLint success = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE)
		{
			GLint logLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
			errorLog = new char[logLength];

			glGetShaderInfoLog(shader, logLength, &logLength, errorLog);

			glDeleteShader(shader);
			return false;
		}
		return true;
	}
}