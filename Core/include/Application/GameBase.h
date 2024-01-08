#ifndef GAME_BASE_H_
#define GAME_BASE_H_

#include <cstdint>

#include "pledGL.h"

namespace pledGL {
    class GameBase {
    public:
        virtual void Run() = 0;
        virtual void End() = 0;

    protected: 
        virtual void SetTargetFps(const int new_fps) = 0;
    };
};

#endif