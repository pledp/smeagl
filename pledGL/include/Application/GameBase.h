#ifndef GAME_BASE_H_
#define GAME_BASE_H_

#include <cstdint>
#include "Core/pledGL.h"

class GameBase {
public:
    /**
     * The game context.
    */    
    virtual void Run() = 0;
    virtual void End() = 0;

    virtual void SetFps(int newFps) = 0;

    GameTime GameTime;
};

#endif