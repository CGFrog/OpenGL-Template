#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GraphicsEngine{
private:
    GLFWwindow* window;
    void initializeGLFW();
    void update();
    void static frameBufferSizeCallback(GLFWwindow*, int, int);
    void processInput();
        
public:
    GraphicsEngine();
    ~GraphicsEngine();
    
    void run();
    void setup();
};