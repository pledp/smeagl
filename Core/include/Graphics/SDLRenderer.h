#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <SDL2/SDL.h>
#include "RendererBase.h"

class SDLRenderer : public RendererBase  {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int width;
    int height;

public:
    SDLRenderer();

    void Init() override;
    void Exit() override;
    void Render() override;
    void ProcessInput() override;
    void Loop() override;
};

#endif