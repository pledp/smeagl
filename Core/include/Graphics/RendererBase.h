#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

#include "Game.h"
#include <SDL2/SDL.h>

class Game;

class RendererBase {
protected:
    Game* game = nullptr;

public:
    virtual ~RendererBase() {};

    virtual void Init(bool createWindow) = 0;
    virtual void Exit() = 0;
    virtual void Render() = 0;
    virtual void ProcessInput() = 0;
    virtual void Loop() = 0;
 
    void SetGame(Game* game);

    // FPS cap time
    int t;
};

#endif