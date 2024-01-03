#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdint.h>

namespace pledGL {
    class VertexBuffer {
    public:
        VertexBuffer(const uint32_t size);
        ~VertexBuffer();

        void Bind();
        void SetData(const void* data, const uint32_t size);

        uint32_t GetID() { return m_RendererID; };
    private:
        uint32_t m_RendererID;
    };
};

#endif