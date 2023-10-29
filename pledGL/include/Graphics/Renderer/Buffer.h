#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>

class VertexBuffer {
public:
    VertexBuffer(uint32_t size);
    ~VertexBuffer();

    void Bind();
    void SetData(const void* data, uint32_t size);

private:
    uint32_t m_RendererID;
};

#endif