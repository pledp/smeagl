#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include "pledGLbase.h"

class Renderer {
private:
    static void flush();

public:
    static void Init();
    static void Exit();

    static void StartScene();
    static void EndScene();

    static void DrawTri(pledGL::Vector3);
    static void DrawTri(pledGL::Vector3 pos, pledGL::Vector3 size);
    static void ClearScreen();
};

#endif