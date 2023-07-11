#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

#include "Game.h"
#include <SDL2/SDL.h>

class RendererBase {
protected:
    Game* game = nullptr;

public:
    virtual ~RendererBase() {};

    virtual void Init() = 0;
    virtual void Exit() = 0;
    virtual void Render() = 0;
    virtual void ProcessInput() = 0;

    // FPS cap things.
    virtual Uint64 Frequency() = 0;
    virtual Uint64 StartLoop() = 0;
    virtual Uint64 EndLoop(int FPS, Uint64 start, Uint64 frequency) = 0;
    virtual void DelayTime(Uint64 delay) = 0;
 
    void SetGame(Game* game);

};

#endif