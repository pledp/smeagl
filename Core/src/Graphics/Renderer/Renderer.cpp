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

void pledGL::Renderer::Init() {
    uint32_t maxIndices = 1024;

    m_Data.Program.CreateProgram(std::string("assets/shaders/vert.shader"), std::string("assets/shaders/frag.shader"));
    m_Data.Program.BindProgram();


    m_Data.TriVertPositions[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
    m_Data.TriVertPositions[1] = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
    m_Data.TriVertPositions[2] = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);

    m_Data.QuadVertPositions[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
    m_Data.QuadVertPositions[1] = glm::vec4(0.5f, -0.5f, 0.0f, 1.0f);
    m_Data.QuadVertPositions[2] = glm::vec4(0.5f, 0.5f, 0.0f, 1.0f);
    m_Data.QuadVertPositions[3] = glm::vec4(-0.5f, 0.5f, 0.0f, 1.0f);


    uint32_t triIndices[maxIndices];
    uint32_t offset = 0;
    for(uint32_t i = 0; i < maxIndices/2; i += 3) {
        triIndices[i + 0] = offset + 0;
        triIndices[i + 1] = offset + 1;
        triIndices[i + 2] = offset + 2;

        offset += 3;
    }
    
    uint32_t quadIndices[maxIndices];
    offset = 0;
    for(uint32_t i = 0; i < maxIndices/2; i += 6) {
        quadIndices[i + 0] = offset + 0;
        quadIndices[i + 1] = offset + 1;
        quadIndices[i + 2] = offset + 2;

        quadIndices[i + 3] = offset + 2;
        quadIndices[i + 4] = offset + 3;
        quadIndices[i + 5] = offset + 0;

        offset += 4;
    }
    
    glCreateVertexArrays(1, &m_Data.TriVertexArray);
    glBindVertexArray(m_Data.TriVertexArray);

    m_Data.TriVertexBufferBase = new Vertex[10000];
    m_Data.TriVertexBufferPtr = m_Data.TriVertexBufferBase;
    m_Data.TriVertexBuffer = std::make_shared<VertexBuffer>(10000);
    m_Data.TriVertexBuffer->Bind();

    glGenBuffers(1, &m_Data.TriIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Data.TriIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(uint32_t), triIndices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texIndex));



    glCreateVertexArrays(1, &m_Data.QuadVertexArray);
    glBindVertexArray(m_Data.QuadVertexArray);    

    m_Data.QuadVertexBufferBase = new Vertex[10000];
    m_Data.QuadVertexBufferPtr = m_Data.QuadVertexBufferBase;

    m_Data.QuadVertexBuffer = std::make_shared<VertexBuffer>(10000);
    m_Data.QuadVertexBuffer->Bind();

    glGenBuffers(1, &m_Data.QuadIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Data.QuadIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices*sizeof(uint32_t), quadIndices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texIndex));

    glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 projectionMatrix = glm::ortho(-1.0f, 1.0f, -0.75f, 0.75f, -1.0f, 1.0f);
    glm::mat4 vp = viewMatrix * projectionMatrix;
    m_Data.CameraBuffer.ViewProjection = vp;


    m_Data.CameraUniformBuffer.CreateBuffer(sizeof(RendererData::CameraData), 0);
    m_Data.CameraUniformBuffer.SetData(&m_Data.CameraBuffer, sizeof(m_Data.CameraBuffer), 0);
    
    auto loc = glGetUniformLocation(m_Data.Program.GetID(), "u_Textures");
    int samplers[2] = { 0, 1 };
    glUniform1iv(loc, 2, samplers);

    Texture2D texture("assets/pldpfp.png");
    Texture2D texture2("assets/clowddrip.png");
    
    texture.Bind(0);
    texture2.Bind(1);
}

void pledGL::Renderer::Exit() {
    delete[] m_Data.TriVertexBufferBase;
    delete[] m_Data.QuadVertexBufferBase;
}

void pledGL::Renderer::StartDraw(const glm::mat4 vp) {
    m_Data.TriVertexBufferPtr = m_Data.TriVertexBufferBase;
    m_Data.TriIndexCount = 0;

    m_Data.QuadVertexBufferPtr = m_Data.QuadVertexBufferBase;
    m_Data.QuadIndexCount = 0;

    m_Data.CameraBuffer.ViewProjection = vp;
    m_Data.CameraUniformBuffer.SetData(&m_Data.CameraBuffer, sizeof(m_Data.CameraBuffer), 0);
}

void pledGL::Renderer::EndDraw() {
    flush();
}

void pledGL::Renderer::flush() {
    if(m_Data.QuadIndexCount) {
        uint32_t dataSize = (uint32_t)((uint8_t*)m_Data.QuadVertexBufferPtr -(uint8_t*)m_Data.QuadVertexBufferBase);

        m_Data.QuadVertexBuffer->SetData(m_Data.QuadVertexBufferBase, dataSize);
        glBindVertexArray(m_Data.QuadVertexArray);


        glDrawElements(GL_TRIANGLES, m_Data.QuadIndexCount, GL_UNSIGNED_INT, nullptr);
    }

    if(m_Data.TriIndexCount) {
        uint32_t dataSize = (uint32_t)((uint8_t*)m_Data.TriVertexBufferPtr -(uint8_t*)m_Data.TriVertexBufferBase);

        m_Data.TriVertexBuffer->SetData(m_Data.TriVertexBufferBase, dataSize);
        glBindVertexArray(m_Data.TriVertexArray);

        glDrawElements(GL_TRIANGLES, m_Data.TriIndexCount, GL_UNSIGNED_INT, nullptr);

    }
}

void pledGL::Renderer::DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size) {
    DrawTri(pos, size, {1.0f, 1.0f, 1.0f});
}

void pledGL::Renderer::DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color) {
    constexpr size_t triVertCount = 3;
    constexpr glm::vec2 textureCoords[] = { {0.0f, 0.0f}, {1.0f, 0.0f}, {0.5f, 1.0f} };

    // Get transform (Scale, pos, etc)
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    for(int i = 0; i < triVertCount; i++) {
        m_Data.TriVertexBufferPtr->pos = transform * m_Data.TriVertPositions[i];
        m_Data.TriVertexBufferPtr->color = glm::vec3(color.x, color.y, color.z);
        m_Data.TriVertexBufferPtr->texCoords = textureCoords[i];
        m_Data.TriVertexBufferPtr->texIndex = 1.0f;
        m_Data.TriVertexBufferPtr++;
    }

    m_Data.TriIndexCount += 3;
}


void pledGL::Renderer::DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size) {
    DrawQuad(pos, size, {1.0f, 1.0f, 1.0f});
}

void pledGL::Renderer::DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color) {
    constexpr size_t quadVertCount = 4;
    constexpr glm::vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

    glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(pos.x, pos.y, pos.z)) * glm::scale(glm::mat4(1.0f), glm::vec3(size.x, size.y, size.z));

    for(int i = 0; i < quadVertCount; i++) {
        m_Data.QuadVertexBufferPtr->pos = transform * m_Data.QuadVertPositions[i];
        m_Data.QuadVertexBufferPtr->color = glm::vec3(color.x, color.y, color.z);
        m_Data.QuadVertexBufferPtr->texCoords = textureCoords[i];
        m_Data.QuadVertexBufferPtr->texIndex = 0.0f;
        m_Data.QuadVertexBufferPtr++;
    }

    m_Data.QuadIndexCount += 6;
}

void pledGL::Renderer::ClearScreen(const pledGL::Vector3& color) {
    glClearColor(color.x, color.y, color.z, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
