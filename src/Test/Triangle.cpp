#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Triangle(){
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    // Setting aside an ID for our vertex buffer on the GPU.
    unsigned int VBO;
    glGenBuffers(1, &VBO);  

    // Bind our buffer to the GPU
    // Note we can bind several buffers at once so long as they are different kinds.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // Sends the vertex data to our buffer on GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Note that if the vertex position were to be dynamic, we would use GL_DYNAMIC_DRAW

    
}