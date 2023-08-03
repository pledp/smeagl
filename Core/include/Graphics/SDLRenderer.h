#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <SDL2/SDL.h>
#include "Graphics/RendererBase.h"

class SDLRenderer : public RendererBase  {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int width;
    int height;

    uint64_t frameStart, frameTime;
    float deltaTime;

public:
    SDLRenderer();

    void Init(bool createWindow) override;
    void Exit() override;
    void Render() override;
    void ProcessInput() override;
    void Loop() override;
};

#endif