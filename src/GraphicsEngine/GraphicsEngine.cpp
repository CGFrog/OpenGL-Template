#include "GraphicsEngine.hpp"
#include <iostream>

GraphicsEngine::GraphicsEngine(){}

GraphicsEngine::~GraphicsEngine(){
    glfwTerminate();
}

void GraphicsEngine::frameBufferSizeCallback(GLFWwindow* window, int width, int height){
    glViewport(0,0,width, height);
}

/*
TODO:
As it stands not if any part of the init process does not work, run is still called
need to prevent this from happening.
*/
void GraphicsEngine::initializeGLFW(){
    if (!glfwInit()){
        std::cout << "Failed to initialize GLFW." << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(800, 600, "OpenGL Template", NULL, NULL);

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

void GraphicsEngine::processInput(){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE == GLFW_PRESS)){
        glfwSetWindowShouldClose(window, true);
    }  
}

void GraphicsEngine::setup(){
    initializeGLFW();
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);  
    glViewport(0, 0, 800, 600);
}

/*
NOTE:
    Later on this loop function should probably be owned by an engine class when 
    things like audio and physics start getting involved that also need to be updated every frame. Since I am focusing on graphics right now, this is fine.
*/
void GraphicsEngine::run(){
    while (!glfwWindowShouldClose(window)) {
        processInput(); // Eventually make an input manager class, probably some sort of event driven thing.
        update();      
    }
}

void GraphicsEngine::update(){
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

