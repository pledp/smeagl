#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <chrono>
#include <SDL2/SDL.h>

#include "Graphics/Window/GraphicsBase.h"
#include "Timer.h"

namespace pledGL {
    class SDLGraphics : public GraphicsBase {
    public:
        SDLGraphics();

        void Init(bool createWindow) override;
        void Exit() override;
        void Flush() override;
        void ProcessInput(pledGL::GameBase& context) override;
        void AddDelay(uint64_t delay) override;

    private:
        SDL_Window *window = nullptr;
        SDL_Renderer *renderer = nullptr;

        int width;
        int height;
    };
};

#endif