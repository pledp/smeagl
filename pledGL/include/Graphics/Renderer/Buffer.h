#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>

class VertexBuffer {
public:
    VertexBuffer(uint32_t size);
    ~VertexBuffer();

    void Bind();
    void SetData(const void* data, uint32_t size);

    uint32_t GetID() { return m_RendererID; };
private:
    uint32_t m_RendererID;
};

#endif