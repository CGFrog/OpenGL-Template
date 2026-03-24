#include "Shader.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

Shader::Shader(const std::string &vertPath, const std::string &fragPath){
    std::string vertShader = importShader(vertPath);
    std::string fragShader = importShader(fragPath);
    compileShaders(vertShader, fragShader);
}

std::string Shader::importShader(const std::string &shaderPath){
    std::string shaderCode;
    std::ifstream shaderFile;

    shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try{
        shaderFile.open(shaderPath);
        std::stringstream shaderStream;

        shaderStream >> shaderFile.rdbuf();
        shaderFile.close();

        shaderCode = shaderStream.str();
    } catch(std::ifstream::failure e){
        std::cout << "ERROR::SHADER:::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    return shaderCode;
}


void Shader::compileShaders(const std::string &vertShader, const std::string &fragShader){
    const char *vertShaderCode = vertShader.c_str();

    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1,&vertShaderCode, NULL );
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char *fragShaderCode = fragShader.c_str();

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1,&fragShaderCode, NULL );
    glCompileShader(fragment);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    this->ID = glCreateProgram();
    glAttachShader(ID,vertex);
    glAttachShader(ID,fragment);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
  
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use(){ 
    glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value) const {         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}
void Shader::setInt(const std::string &name, int value) const { 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}
void Shader::setFloat(const std::string &name, float value) const { 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 