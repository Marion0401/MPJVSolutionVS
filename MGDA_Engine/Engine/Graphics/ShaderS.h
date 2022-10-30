#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/*
	Static class to handle shader
*/

namespace ShaderS
{

		// read file
		std::string readFile(const char* filename);

		// generate shader
		int genShader(const char* filepath, GLenum type);

		// generate shader program
		int genShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);

		// bind shader
		void bindShader(int shaderProgram);

		// set projection
		void setOrthographicProjection(int shaderProgram,
			float left, float right,
			float bottom, float top,
			float near, float far);

		// delete shader
		void deleteShader(int shaderProgram);

};

