#ifndef GAME_H_
#define GAME_H_

#include "RendererBase.h"

class RendererBase;

class Game {
private:
    RendererBase* graphics;
    int FPS;

    void Update();
    void Render();
    void Init();
    void ProcessInput();

    bool IsPlaying = false;

public:
    Game();
    void run();
    void end();
    void setGraphics(RendererBase* graphics);

};

#endif