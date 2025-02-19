#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

#include <cstdint>

#include "Application/GameBase.h"

namespace pledGL {
    class GraphicsBase {
    public:
        virtual ~GraphicsBase() {};

        virtual void Init(bool createWindow) = 0;
        virtual void Exit() = 0;
        virtual void Flush() = 0;
        virtual void ProcessInput(GameBase& context) = 0;
        virtual void AddDelay(uint64_t delay) = 0;
    };
};

#endif