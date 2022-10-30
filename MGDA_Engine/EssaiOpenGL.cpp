#include "./Engine/Graphics/EngineGFX.h" 
#include "./Engine/Graphics/ShaderS.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
// settings
unsigned int scrWidth = 800;
unsigned int scrHeight = 600;
const char* title = "LearnOpenGL";
GLuint shaderProgram;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    EngineGFX::initGLFW(3, 3);

    // glfw window creation
    // --------------------
    GLFWwindow* window;
    EngineGFX::createWindow(window, title, scrWidth, scrHeight, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    EngineGFX::loadGlad();

    glViewport(0, 0, scrWidth, scrHeight);

    // build and compile our shader program
    // ------------------------------------
    shaderProgram = ShaderS::genShaderProgram("./Engine/Shaders/main.vs", "./Engine/Shaders/main.fs");
    ShaderS::setOrthographicProjection(shaderProgram, 0, scrWidth, 0, scrHeight, 0.0f, 1.0f);


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float vertices[] = {
    -0.5f, -0.5f, 0.0f, // left  
     0.5f, -0.5f, 0.0f, // right 
     0.0f,  0.5f, 0.0f  // top   
    };

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------

        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

        // render
        // ------
        EngineGFX::clearScreen();

        // draw our first triangle
        ShaderS::bindShader(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0); // no need to unbind it every time 

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        EngineGFX::newFrame(window);

    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    EngineGFX::cleanup();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
    scrWidth = width;
    scrHeight = height;

    // update projection matrix
    ShaderS::setOrthographicProjection(shaderProgram, 0, width, 0, height, 0.0f, 1.0f);
}