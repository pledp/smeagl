#include "SDLRenderer.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

SDLRenderer::SDLRenderer() {

}

void SDLRenderer::Init() {
    this->width = 1024;
    this->height = 768;
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,680, 480,0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* surface = NULL;

    std::cout << "Window created!";
}

void SDLRenderer::Exit() {
    SDL_DestroyWindow(window);
    SDL_Quit();

    window = NULL; 
    renderer = NULL;
}

void SDLRenderer::Render() {
    // Set color to white
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);

    // Clear renderer 
    SDL_RenderClear(renderer);

    // Update screen with renderer
    SDL_RenderPresent(renderer);
}

void SDLRenderer::ProcessInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                Exit();
                game->End();
                break;
            case SDL_WINDOWEVENT:
                std::cout << "Moved window";
                break;
        }
    } 
}

Uint64 SDLRenderer::Frequency() {
    return SDL_GetPerformanceFrequency();
}

Uint64 SDLRenderer::StartLoop() {
    return SDL_GetPerformanceCounter();
}

Uint64 SDLRenderer::EndLoop(int FPS, Uint64 start, Uint64 frequency) {
    Uint64 end = SDL_GetPerformanceCounter();
    float elapsedTime = (end - start) / (float)frequency * 1000.0f;
    Uint32 delayTime = (Uint32)ceil((1000/FPS) - elapsedTime); 
    return delayTime;
}

void SDLRenderer::DelayTime(Uint64 delay) {
    SDL_Delay(delay);
}