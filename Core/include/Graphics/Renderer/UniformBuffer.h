#ifndef UNIFORM_BUFFER_
#define UNIFORM_BUFFER_

#include <stdint.h>

class UniformBuffer {
public:
    void CreateBuffer(uint32_t size, uint32_t binding);
    ~UniformBuffer();

    void SetData(const void* data, uint32_t size, uint32_t offset);

private:
    uint32_t m_BufferID;
};

#endif