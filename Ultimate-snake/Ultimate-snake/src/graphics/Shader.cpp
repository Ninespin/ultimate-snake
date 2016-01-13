#include "Shader.h"

namespace graphics {


	Shader::Shader(const char* vertPath, const char* fragPath)
	{
		error = false;
		vertShader = glCreateShader(GL_VERTEX_SHADER);
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		unsigned long vertSourceLength = 0;
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

		program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		error = !testLinkStatus(program);
		if (error)return;

		glDetachShader(program, vertShader);
		glDetachShader(program, fragShader);

		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(program);
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

	bool Shader::testCompileStatus(GLuint shader)
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

	bool Shader::testLinkStatus(GLuint pogram)
	{
		GLint sucess = 0;
		glGetProgramiv(program, GL_LINK_STATUS, &sucess);
		if (sucess == GL_FALSE)
		{
			GLint logLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);

			errorLog = new char[logLength];
			glGetProgramInfoLog(program, logLength, &logLength, errorLog);

			glDeleteProgram(program);
			return false;
		}
		return true;
	}

	GLuint Shader::getProgram() const
	{
		if (!error) 
		{
			return program;
		}
		else
		{
			return 0;
		}
	}
}