#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

/*
	Static class to handle grahics
*/

namespace EngineGFX
{
		/*
		initialization methods
		*/

		// initialize GLFW
		void initGLFW(unsigned int versionMajor, unsigned int versionMinor);

		// create window
		void createWindow(GLFWwindow*& window,
			const char* title, unsigned int width, unsigned int height,
			GLFWframebuffersizefun framebufferSizeCallback);

		// load GLAD library
		bool loadGlad();

		/*
			Methods
		*/

		// clear screen
		void clearScreen();

		// new frame
		void newFrame(GLFWwindow* window);

		/*
			cleanup methods
		*/

		// terminate glfw
		void cleanup();
};

