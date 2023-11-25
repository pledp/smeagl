#include <string>
#include <iostream>
#include <memory>

#include <stb/stb_image.h>
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Renderer/ShaderProgram.h"
#include "Graphics/Renderer/Buffer.h"
#include "Graphics/Renderer/Texture2D.h"

struct Vertex {
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texCoords;
    float texIndex;
};

struct RendererData {
    unsigned int TriVertexArray; 
    std::shared_ptr<VertexBuffer> TriVertexBuffer; 
    unsigned int TriIndicesBuffer;
    uint32_t TriIndexCount = 0; 
    Vertex* TriVertexBufferBase = nullptr;
    Vertex* TriVertexBufferPtr = nullptr;

    glm::vec4 TriVertPositions[3];

    ShaderProgram Program;


    unsigned int QuadVertexArray; 
    std::shared_ptr<VertexBuffer> QuadVertexBuffer; 
    unsigned int QuadIndicesBuffer;
    Vertex* QuadVertexBufferBase = nullptr;
    Vertex* QuadVertexBufferPtr = nullptr;
    uint32_t QuadIndexCount = 0;

    glm::vec4 QuadVertPositions[4];

    float TextureIndex;
};

static RendererData s_Data;

void Renderer::Init() {
    uint32_t maxIndices = 1024;

    s_Data.Program.CreateProgram(std::string("assets/shaders/vert.shader"), std::string("assets/shaders/frag.shader"));
    s_Data.Program.BindProgram();


    s_Data.TriVertPositions[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.TriVertPositions[1] = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.TriVertPositions[2] = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);

    s_Data.QuadVertPositions[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.QuadVertPositions[1] = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
    s_Data.QuadVertPositions[2] = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f);
    s_Data.QuadVertPositions[3] = glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f);


    uint32_t triIndices[maxIndices];
    uint32_t offset = 0;
    for(uint32_t i = 0; i < maxIndices; i += 3) {
        triIndices[i + 0] = offset + 0;
        triIndices[i + 1] = offset + 1;
        triIndices[i + 2] = offset + 2;

        offset += 3;
    }
    
    uint32_t quadIndices[maxIndices];
    offset = 0;
    for(uint32_t i = 0; i < maxIndices; i += 6) {
        quadIndices[i + 0] = offset + 0;
        quadIndices[i + 1] = offset + 1;
        quadIndices[i + 2] = offset + 2;

        quadIndices[i + 3] = offset + 2;
        quadIndices[i + 4] = offset + 3;
        quadIndices[i + 5] = offset + 0;

        offset += 4;
    }
    
    glCreateVertexArrays(1, &s_Data.TriVertexArray);
    glBindVertexArray(s_Data.TriVertexArray);

    s_Data.TriVertexBufferBase = new Vertex[10000];
    s_Data.TriVertexBufferPtr = s_Data.TriVertexBufferBase;
    s_Data.TriVertexBuffer = std::make_shared<VertexBuffer>(10000);
    s_Data.TriVertexBuffer->Bind();

    glGenBuffers(1, &s_Data.TriIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.TriIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(uint32_t), triIndices, GL_STATIC_DRAW);

    // Init shader parameters
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texIndex));



    glCreateVertexArrays(1, &s_Data.QuadVertexArray);
    glBindVertexArray(s_Data.QuadVertexArray);    

    s_Data.QuadVertexBufferBase = new Vertex[10000];
    s_Data.QuadVertexBufferPtr = s_Data.QuadVertexBufferBase;

    s_Data.QuadVertexBuffer = std::make_shared<VertexBuffer>(10000);
    s_Data.QuadVertexBuffer->Bind();

    glGenBuffers(1, &s_Data.QuadIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.QuadIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(uint32_t), quadIndices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texIndex));

    auto loc = glGetUniformLocation(s_Data.Program.GetID(), "u_Textures");
    int samplers[2] = { 0, 1 };
    glUniform1iv(loc, 2, samplers);

    Texture2D texture("assets/pldpfp.png");
    Texture2D texture2("assets/clowddrip.png");
    
    texture.Bind(0);
    texture2.Bind(1);
}

void Renderer::Exit() {
    delete[] s_Data.TriVertexBufferBase;
    s_Data.TriVertexBufferPtr = nullptr;

    delete[] s_Data.QuadVertexBufferBase;
    s_Data.QuadVertexBufferPtr = nullptr;
}

void Renderer::StartDraw() {
    s_Data.TriVertexBufferPtr = s_Data.TriVertexBufferBase;
    s_Data.TriIndexCount = 0;

    s_Data.QuadVertexBufferPtr = s_Data.QuadVertexBufferBase;
    s_Data.QuadIndexCount = 0;
}

void Renderer::EndDraw() {
    flush();
}

void Renderer::flush() {
    if(s_Data.QuadIndexCount) {
        uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.QuadVertexBufferPtr -(uint8_t*)s_Data.QuadVertexBufferBase);

        s_Data.QuadVertexBuffer->SetData(s_Data.QuadVertexBufferBase, dataSize);
        glBindVertexArray(s_Data.QuadVertexArray);


        glDrawElements(GL_TRIANGLES, s_Data.QuadIndexCount, GL_UNSIGNED_INT, nullptr);
    }

    if(s_Data.TriIndexCount) {
        uint32_t dataSize = (uint32_t)((uint8_t*)s_Data.TriVertexBufferPtr -(uint8_t*)s_Data.TriVertexBufferBase);

        s_Data.TriVertexBuffer->SetData(s_Data.TriVertexBufferBase, dataSize);
        glBindVertexArray(s_Data.TriVertexArray);

        glDrawElements(GL_TRIANGLES, s_Data.TriIndexCount, GL_UNSIGNED_INT, nullptr);

    }
}

void Renderer::DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color) {
    constexpr size_t triVertCount = 3;
    constexpr glm::vec2 textureCoords[] = { {0.0f, 0.0f}, {1.0f, 0.0f}, {0.5f, 1.0f} };

    // Get transform (Scale, pos, etc)
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    for(int i = 0; i < triVertCount; i++) {
        s_Data.TriVertexBufferPtr->pos = transform * s_Data.TriVertPositions[i];
        s_Data.TriVertexBufferPtr->color = glm::vec3(color.x, color.y, color.z);
        s_Data.TriVertexBufferPtr->texCoords = textureCoords[i];
        s_Data.TriVertexBufferPtr->texIndex = 1.0f;
        s_Data.TriVertexBufferPtr++;
    }

    s_Data.TriIndexCount += 3;
}

void Renderer::DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color) {
    constexpr size_t quadVertCount = 4;
    constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) * glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 1.0f));
    glm::mat4 projectionMatrix = glm::ortho(-1.0f, 1.0f, -0.75f, 0.75f, -1.0f, 1.0f);
    glm::mat4 vp = viewMatrix * projectionMatrix;


    for(int i = 0; i < quadVertCount; i++) {
        s_Data.QuadVertexBufferPtr->pos = vp * (transform * s_Data.QuadVertPositions[i]);
        s_Data.QuadVertexBufferPtr->color = glm::vec3(color.x, color.y, color.z);
        s_Data.QuadVertexBufferPtr->texCoords = textureCoords[i];
        s_Data.QuadVertexBufferPtr->texIndex = 0.0f;
        s_Data.QuadVertexBufferPtr++;
    }

    s_Data.QuadIndexCount += 6;
}

void Renderer::ClearScreen(pledGL::Vector3 color) {
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
