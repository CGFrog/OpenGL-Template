#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GraphicsEngine{
public:
    GraphicsEngine();
    ~GraphicsEngine();
    
    void initializeGLFW();

    void loop();


    GLFWwindow* window;

private:
    void preprocessing();
};