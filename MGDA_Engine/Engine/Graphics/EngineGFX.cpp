#include "EngineGFX.h"

namespace EngineGFX
{

	// initialize GLFW
	void initGLFW(unsigned int versionMajor, unsigned int versionMinor) {
		glfwInit();

		// pass in window params
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// macos specific parameter
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	}

	// create window
	void createWindow(GLFWwindow*& window,
		const char* title, unsigned int width, unsigned int height,
		GLFWframebuffersizefun framebufferSizeCallback) {
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (!window) {
			return;
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	}

	// load GLAD library
	bool loadGlad() {
		return gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	/*
		Methods
	*/

	// clear screen
	void clearScreen() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	// new frame
	void newFrame(GLFWwindow* window) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/*
		cleanup methods
	*/

	// terminate glfw
	void cleanup() {
		glfwTerminate();
	}
}
