#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include "Graphics/Window/GraphicsBase.h"
#include "Timer.h"

#include <SDL2/SDL.h>
#include <chrono>

class SDLGraphics : public GraphicsBase {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int width;
    int height;
public:
    SDLGraphics();

    void Init(bool createWindow) override;
    void Exit() override;
    void Flush() override;
    void ProcessInput(GameBase* context) override;
    void AddDelay(uint64_t delay) override;
};

#endif