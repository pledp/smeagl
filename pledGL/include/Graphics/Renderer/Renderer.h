#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include "pledGLbase.h"

class Renderer {
private:
    static void flush();

public:
    static void Init();
    static void Exit();

    static void StartDraw();
    static void EndDraw();

    static void DrawTri(pledGL::Vector3);
    static void DrawTri(const pledGL::Vector3& pos, const pledGL::Vector3& size, const pledGL::Vector3& color);
    static void ClearScreen();
};

#endif