#include <string>
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Renderer/ShaderProgram.h"

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"

const std::string vertexShaderSource =
"#version 330 core\n"
"\n"
"layout(location = 0) in vec3 aPos;"
"\n"
"layout(location = 1) in vec3 aColor;"
"\n"
"out vec3 color;"
"\n"
"uniform mat4 model;"
"\n"
"void main() {"
"\n"
"   gl_Position = model * vec4(aPos, 1.0);"
"\n"
"   color = aColor;"
"\n"
"}\n";

const std::string fragmentShaderSource = 
"#version 330 core\n"
"\n"
"in vec3 color;"
"\n"
"layout(location = 0) out vec4 FragColor;"
"\n"
"void main() {"
"\n"
"   FragColor = vec4(color, 1.0);"
"\n"
"}\n";

struct QuadVertex {
    glm::vec3 pos;
    glm::vec3 color;
};

struct RendererData {
    unsigned int TriVertexArray; 
    unsigned int TriVertexBuffer; 
    unsigned int TriIndicesArray;
    unsigned int TriIndicesBuffer; 

    ShaderProgram Program;

    QuadVertex* TriVertexBufferBase = nullptr;
    QuadVertex* TriVertexBufferPtr = nullptr;
    unsigned int TriIndicesPosistions[3];
};

static RendererData s_Data;

void Renderer::Init() {
    s_Data.TriVertexBufferBase = new QuadVertex[3];
    s_Data.Program.CreateProgram(vertexShaderSource, fragmentShaderSource);
    s_Data.Program.BindProgram();

    s_Data.TriVertexBufferPtr = s_Data.TriVertexBufferBase;

    glGenVertexArrays(1, &s_Data.TriVertexArray);
    glBindVertexArray(s_Data.TriVertexArray);
    
    s_Data.TriVertexBufferPtr->pos = glm::vec3(-0.5f, -0.5f, 0.0f);
    s_Data.TriVertexBufferPtr->color = glm::vec3(1.0f, 0.0f, 0.0f);
    s_Data.TriVertexBufferPtr++;
    s_Data.TriVertexBufferPtr->pos = glm::vec3(0.5f, -0.5f, 0.0f);
    s_Data.TriVertexBufferPtr->color = glm::vec3(0.0f, 1.0f, 0.0f);
    s_Data.TriVertexBufferPtr++;
    s_Data.TriVertexBufferPtr->pos = glm::vec3(0.0f, 0.5f, 0.0f);
    s_Data.TriVertexBufferPtr->color = glm::vec3(0.0f, 0.0f, 1.0f);
    s_Data.TriVertexBufferPtr++;


    s_Data.TriIndicesPosistions[0] = 0;
    s_Data.TriIndicesPosistions[1] = 1;
    s_Data.TriIndicesPosistions[2] = 2;
    
    // Find the size of the buffer.
    uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.TriVertexBufferPtr -(uint8_t*)s_Data.TriVertexBufferBase);

    glGenBuffers(1, &s_Data.TriVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, s_Data.TriVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, dataSize, s_Data.TriVertexBufferBase, GL_STATIC_DRAW);

    glGenBuffers(1, &s_Data.TriIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.TriIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*sizeof(unsigned int), s_Data.TriIndicesPosistions, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void*)offsetof(QuadVertex, color));
    glEnableVertexAttribArray(1);
}

void Renderer::Exit() {
    delete[] s_Data.TriVertexBufferBase;
    s_Data.TriVertexBufferPtr = nullptr;
}

void Renderer::DrawTri(pledGL::Vector3 pos, pledGL::Vector3 size) {
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    s_Data.Program.UploadUniformMat4("model", transform);
    
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Renderer::ClearScreen() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::flush() {
    
}