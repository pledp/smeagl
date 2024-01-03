#include "Graphics/Renderer/Buffer.h"
#include "glad/glad.h"

pledGL::VertexBuffer::VertexBuffer(const uint32_t size) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

pledGL::VertexBuffer::~VertexBuffer() {
    // Delete buffer data
    glDeleteBuffers(1, &m_RendererID);
}

void pledGL::VertexBuffer::Bind() {
    // Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void pledGL::VertexBuffer::SetData(const void* data, const uint32_t size) {
    // Set buffer data
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}