#include <string>
#include <iostream>
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
"void main() {"
"\n"
"   gl_Position = vec4(aPos, 1.0);"
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
    uint32_t TriIndexCount; 

    ShaderProgram Program;

    QuadVertex* TriVertexBufferBase = nullptr;
    QuadVertex* TriVertexBufferPtr = nullptr;
    unsigned int TriIndicesPosistions[3];

    glm::vec4 TriVertPositions[3];
};

static RendererData s_Data;

void Renderer::Init() {
    uint32_t maxIndices = 1024;
    s_Data.TriVertexBufferBase = new QuadVertex[1000];
    s_Data.Program.CreateProgram(vertexShaderSource, fragmentShaderSource);
    s_Data.Program.BindProgram();

    s_Data.TriVertexBufferPtr = s_Data.TriVertexBufferBase;

    glGenVertexArrays(1, &s_Data.TriVertexArray);
    glBindVertexArray(s_Data.TriVertexArray);
    

    s_Data.TriVertPositions[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.TriVertPositions[1] = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.TriVertPositions[2] = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);


    s_Data.TriIndicesPosistions[0] = 0;
    s_Data.TriIndicesPosistions[1] = 1;
    s_Data.TriIndicesPosistions[2] = 2;

    uint32_t triIndices[maxIndices];
    uint32_t offset = 0;
    for(uint32_t i = 0; i < maxIndices; i += 3) {
        triIndices[i + 0] = offset + 0;
        triIndices[i + 1] = offset + 1;
        triIndices[i + 2] = offset + 2;

        offset += 3;
    }
    
    glGenBuffers(1, &s_Data.TriVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, s_Data.TriVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, 1000, s_Data.TriVertexBufferBase, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &s_Data.TriIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.TriIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(uint32_t), triIndices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(QuadVertex), (void*)offsetof(QuadVertex, color));
    glEnableVertexAttribArray(1);
}

void Renderer::Exit() {
    delete[] s_Data.TriVertexBufferBase;
    s_Data.TriVertexBufferPtr = nullptr;
}

void Renderer::StartDraw() {
    s_Data.TriVertexBufferPtr = s_Data.TriVertexBufferBase;
    s_Data.TriIndexCount = 0;
}

void Renderer::EndDraw() {
    flush();
}

void Renderer::flush() {
    uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.TriVertexBufferPtr -(uint8_t*)s_Data.TriVertexBufferBase);
    glBindBuffer(GL_ARRAY_BUFFER, s_Data.TriVertexBuffer);
    glBufferSubData(GL_ARRAY_BUFFER, 0, dataSize, s_Data.TriVertexBufferBase);
    glDrawElements(GL_TRIANGLES, s_Data.TriIndexCount, GL_UNSIGNED_INT, nullptr);
    glGetError();
}

void Renderer::DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color) {
    constexpr size_t triVertCount = 3;
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    for(int i = 0; i < triVertCount; i++) {
        s_Data.TriVertexBufferPtr->pos = transform * s_Data.TriVertPositions[i];
        s_Data.TriVertexBufferPtr->color = glm::vec3(color.x, color.y, color.z);
        s_Data.TriVertexBufferPtr++;
    }

    s_Data.TriIndexCount += 3;
}

void Renderer::ClearScreen() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
