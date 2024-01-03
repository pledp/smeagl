#ifndef GAME_BASE_H_
#define GAME_BASE_H_

#include <cstdint>
#include "pledGL.h"

namespace pledGL {
    class GameBase {
    public:
        /**
         * The game context.
        */    
        virtual void Run() = 0;
        virtual void End() = 0;

        virtual void SetFps(const int newFps) = 0;

        pledGL::GameTime GameTime;
    };
};

#endif