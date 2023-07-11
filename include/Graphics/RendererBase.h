#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

#include "Game.h"

class RendererBase {
protected:
    Game* game = nullptr;

public:
    virtual ~RendererBase() {};

    virtual void Init() = 0;
    virtual void Exit() = 0;
    virtual void Render() = 0;
    virtual void ProcessInput() = 0;

    void SetGame(Game* game);

};

#endif