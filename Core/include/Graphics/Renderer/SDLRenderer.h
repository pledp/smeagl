#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <SDL2/SDL.h>
#include "Graphics/Renderer/Renderer.h"

class SDLRenderer : public Renderer {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int width;
    int height;

    uint64_t frameStart, frameTime;
    int frameDelay;
    float deltaTime;

public:
    SDLRenderer();

    void Init(bool createWindow) override;
    void Exit() override;
    void Render() override;
    void ProcessInput() override;
    void StartLoop(int fps) override;
    void EndLoop() override;
};

#endif