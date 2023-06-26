#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

#include "Game.h"

class RendererBase {
protected:
    Game* game = nullptr;

public:
    virtual ~RendererBase() {};

    virtual void init() = 0;
    virtual void exit() = 0;
    virtual void render() = 0;
    virtual void processInput() = 0;

    void setGame(Game* game);

};

#endif