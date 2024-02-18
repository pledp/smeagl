#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include "pledGL.h"
#include "glm/gtc/matrix_transform.hpp"

namespace pledGL {
    class Renderer {
    private:
        /**
         * Flushes the current batch. (Draws things on the screen.)
        */
        void flush();

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
        void DrawTri(const Vector3& pos, const Vector3& size, const Vector3& color);
        void DrawTri(const Vector3& pos, const Vector3& size);


        /**
         * Draw a quad.
         * @param pos Posistion of the quad.
         * @param size Size of the quad.
         * @param color Color of the quad.
        */
        void DrawQuad(const Vector3& pos, const Vector3& size, const Vector3& color);
        void DrawQuad(const Vector3& pos, const Vector3& size);


        void ClearScreen(const Vector3& col);
    };
};

#endif