#ifndef TWOD_RENDERER_H_
#define TWOD_RENDERER_H_

#include "glad/glad.h"

class 2DRenderer {
private:
    void flush();

public:
    void Init();

    void StartScene();
    void EndScene();

    void DrawTri();
};

#endif