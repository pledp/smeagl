#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <SDL2/SDL.h>
#include "Graphics/Window/GraphicsBase.h"
#include <chrono>

class SDLGraphics : public GraphicsBase {
private:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    int width;
    int height;

    uint64_t frameStart, frameTime;
    int frameDelay;
    float deltaTime;
    int frame = 0;

    std::chrono::high_resolution_clock::time_point start_time;

public:
    SDLGraphics();

    void Init(bool createWindow) override;
    void Exit() override;
    void Flush() override;
    void ProcessInput(GameBase* context) override;
    void StartLoop(int fps) override;
    void EndLoop(GameBase* context) override;
};

#endif