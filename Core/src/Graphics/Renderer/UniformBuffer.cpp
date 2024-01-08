#include "Graphics/Renderer/UniformBuffer.h"

#include "glad/glad.h"

pledGL::UniformBuffer::~UniformBuffer() {
    glDeleteBuffers(1, &m_buffer_id);
}

void pledGL::UniformBuffer::CreateBuffer(const uint32_t size, const uint32_t binding) {
    glCreateBuffers(1, &m_buffer_id);
    glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_id);
    glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, binding, m_buffer_id);
}

void pledGL::UniformBuffer::SetData(const void* data, const uint32_t size, const uint32_t offset) {
    glBindBuffer(GL_UNIFORM_BUFFER, m_buffer_id);
    glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
}

// TODO: Maybe remove bindings from shader, so can use OpenGL version 330?
