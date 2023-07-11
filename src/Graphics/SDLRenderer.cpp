#include "SDLRenderer.h"
#include <SDL2/SDL.h>
#include <iostream>

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
    window = NULL; 
    renderer = NULL;

    SDL_Quit();
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
        if (e.type == SDL_QUIT) {
            this->Exit();
            game->End();
            return;
        }
    }
}