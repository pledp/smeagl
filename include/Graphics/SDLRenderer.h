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
    void DelayTime(Uint64 delay) override;
    
    Uint64 Frequency() override;
    Uint64 StartLoop() override;
    Uint64 EndLoop(int FPS, Uint64 start, Uint64 frequency) override;
};

#endif