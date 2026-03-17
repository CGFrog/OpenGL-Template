#include "GraphicsEngine.hpp"
#include <iostream>

GraphicsEngine::GraphicsEngine(){
    this->window = glfwCreateWindow(800, 600, "OpenGL Template", NULL, NULL);
}

GraphicsEngine::~GraphicsEngine(){
    glfwTerminate();
}


void GraphicsEngine::initializeGLFW(){
    if (!glfwInit()){
        std::cout << "Failed to initialize GLFW." << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

void GraphicsEngine::preprocessing(){
    glViewport(0, 0, 800, 600);
}

void GraphicsEngine::loop(){
    preprocessing();
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}