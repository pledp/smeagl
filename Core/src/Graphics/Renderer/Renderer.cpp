#include "Graphics/Renderer/Renderer.h"
#include "glad/glad.h"
#include <iostream>
#include <memory>

const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
void main() {
    gl_Position = vec4(aPos, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red color
}
)";

struct RendererData {
    unsigned int TriVertexArray; 
    unsigned int TriVertexBuffer; 
    unsigned int TriIndicesArray;
    unsigned int TriIndicesBuffer; 


    unsigned int TriVertShader;
    unsigned int TriFragShader;

    unsigned int ShaderProgram;
};

static RendererData s_Data;

void Renderer::Init() {
    s_Data.TriVertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(s_Data.TriVertShader, 1, &vertexShaderSource, NULL);
    glCompileShader(s_Data.TriVertShader);

    s_Data.TriFragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(s_Data.TriFragShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(s_Data.TriFragShader);

    s_Data.ShaderProgram = glCreateProgram();
    glAttachShader(s_Data.ShaderProgram, s_Data.TriVertShader);
    glAttachShader(s_Data.ShaderProgram, s_Data.TriFragShader);
    glLinkProgram(s_Data.ShaderProgram);
    glUseProgram(s_Data.ShaderProgram);

    glGenVertexArrays(1, &s_Data.TriVertexArray);
    glBindVertexArray(s_Data.TriVertexArray);

    glGenBuffers(1, &s_Data.TriVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, s_Data.TriVertexBuffer);

    float triVertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    }
    
}