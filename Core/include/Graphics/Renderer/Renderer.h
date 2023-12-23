#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include "pledGL.h"
#include "glm/gtc/matrix_transform.hpp"

class Renderer {
private:
    /**
     * Flushes the current batch. (Draws things on the screen.)
    */
    static void flush();

public:
    static void Init();
    static void Exit();

    /**
     * Start draw batch.
     * @param vp Set ViewProjection matrix. (Default set as 1.0f)
    */
    static void StartDraw(const glm::mat4 vp = glm::mat4(1.0f));

    /**
     * Ends the current draw batch.
    */
    static void EndDraw();

    /**
     * Draw a tri.
     * @param pos Posistion of the Tri.
     * @param size Size of the Tri.
     * @param color Color of the Tri.
    */
    static void DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color);
    static void DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size);


    /**
     * Draw a quad.
     * @param pos Posistion of the quad.
     * @param size Size of the quad.
     * @param color Color of the quad.
    */
    static void DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color);
    static void DrawQuad(const pledGL::Vector3& pos, const pledGL::Vector3& size);


    static void ClearScreen(pledGL::Vector3 col);
};

#endif