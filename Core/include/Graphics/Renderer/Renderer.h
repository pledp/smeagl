#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include <memory>

#include "glm/gtc/matrix_transform.hpp"

#include "pledGL.h"
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Renderer/ShaderProgram.h"
#include "Graphics/Renderer/Buffer.h"
#include "Graphics/Renderer/Texture2D.h"
#include "Graphics/Renderer/UniformBuffer.h"

namespace pledGL {
    class Renderer {
    private:
        /**
         * Flushes the current batch. (Draws things on the screen.)
        */
        void flush();

        struct Vertex {
            glm::vec3 pos;
            glm::vec3 color;
            glm::vec2 texCoords;
            float texIndex;
        };

        struct RendererData {
            unsigned int TriVertexArray; 
            std::shared_ptr<pledGL::VertexBuffer> TriVertexBuffer; 
            unsigned int TriIndicesBuffer;
            uint32_t TriIndexCount = 0; 
            Vertex* TriVertexBufferBase;
            Vertex* TriVertexBufferPtr;

            glm::vec4 TriVertPositions[3];

            pledGL::ShaderProgram Program;
            
            unsigned int QuadVertexArray; 
            std::shared_ptr<pledGL::VertexBuffer> QuadVertexBuffer; 
            unsigned int QuadIndicesBuffer;
            Vertex* QuadVertexBufferBase;
            Vertex* QuadVertexBufferPtr;
            uint32_t QuadIndexCount = 0;

            glm::vec4 QuadVertPositions[4];

            float TextureIndex;

            struct CameraData {
                glm::mat4 ViewProjection;
            };
            CameraData CameraBuffer;
            pledGL::UniformBuffer CameraUniformBuffer;
        };

        RendererData m_Data;

    public:
        void Init();
        void Exit();

        /**
         * Start draw batch.
         * @param vp Set ViewProjection matrix. (Default set as 1.0f)
        */
        void StartDraw(const glm::mat4 vp = glm::mat4(1.0f));

        /**
         * Ends the current draw batch.
        */
        void EndDraw();

        /**
         * Draw a tri.
         * @param pos Posistion of the Tri.
         * @param size Size of the Tri.
         * @param color Color of the Tri.
        */
        void DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color);
        void DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size);


        /**
         * Draw a quad.
         * @param pos Posistion of the quad.
         * @param size Size of the quad.
         * @param color Color of the quad.
        */
        void DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color);
        void DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size);


        void ClearScreen(const pledGL::Vector3& col);
    };
};

#endif