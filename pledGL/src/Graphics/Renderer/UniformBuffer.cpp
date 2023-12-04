#include "Graphics/Renderer/UniformBuffer.h"

#include "glad/glad.h"

UniformBuffer::~UniformBuffer() {
    glDeleteBuffers(1, &m_BufferID);
}

void UniformBuffer::CreateBuffer(uint32_t size, uint32_t binding) {
    glCreateBuffers(1, &m_BufferID);
    glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
    glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_BufferID);
}

void UniformBuffer::SetData(const void* data, uint32_t size, uint32_t offset) {
    glBindBuffer(GL_UNIFORM_BUFFER, m_BufferID);
    glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
}

// TODO: Maybe remove bindings from shader, so can use OpenGL version 330?
