#include "ShaderS.h"

namespace ShaderS
{
	// read file
	std::string readFile(const char* filename) {
		std::ifstream file;
		std::stringstream buf;

		std::string ret = "";

		// open file
		file.open(filename);

		if (file.is_open()) {
			// read buffer
			buf << file.rdbuf();
			ret = buf.str();
		}
		else {
			std::cout << "Could not open " << filename << std::endl;
		}

		// close file
		file.close();

		return ret;
	}

	// generate shader
	int genShader(const char* filepath, GLenum type) {
		std::string shaderSrc = readFile(filepath);
		const GLchar* shader = shaderSrc.c_str();

		// build and compile shader
		int shaderObj = glCreateShader(type);
		glShaderSource(shaderObj, 1, &shader, NULL);
		glCompileShader(shaderObj);

		// check for errors
		int success;
		char infoLog[512];
		glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderObj, 512, NULL, infoLog);
			std::cout << "Error in shader compilation: " << infoLog << std::endl;
			return -1;
		}

		return shaderObj;
	}

	// generate shader program
	int genShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
		int shaderProgram = glCreateProgram();

		// compile shaders
		int vertexShader = genShader(vertexShaderPath, GL_VERTEX_SHADER);
		int fragmentShader = genShader(fragmentShaderPath, GL_FRAGMENT_SHADER);

		if (vertexShader == -1 || fragmentShader == -1) {
			return -1;
		}

		// link shaders
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		// check for errors
		int success;
		char infoLog[512];
		glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "Error in shader linking: " << infoLog << std::endl;
			return -1;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return shaderProgram;
	}

	// bind shader
	void bindShader(int shaderProgram) {
		glUseProgram(shaderProgram);
	}

	// set projection
	void setOrthographicProjection(int shaderProgram,
		float left, float right,
		float bottom, float top,
		float near, float far) {
		float mat[4][4] = {
			{ 2.0f / (right - left), 0.0f, 0.0f, 0.0f },
			{ 0.0f, 2.0f / (top - bottom), 0.0f, 0.0f },
			{ 0.0f, 0.0f, -2.0f / (far - near), 0.0f },
			{ -(right + left) / (right - left), -(top + bottom) / (top - bottom), -(far + near) / (far - near), 1.0f }
		};

		bindShader(shaderProgram);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, &mat[0][0]);
	}

	// delete shader
	void deleteShader(int shaderProgram) {
		glDeleteProgram(shaderProgram);
	}
}
