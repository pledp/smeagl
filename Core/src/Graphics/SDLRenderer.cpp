#include "Graphics/SDLRenderer.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

SDLRenderer::SDLRenderer() {

}

void SDLRenderer::Init(bool createWindow) {
    this->width = 1024;
    this->height = 768;

    SDL_Init(SDL_INIT_EVERYTHING);

    if(createWindow)
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

void SDLRenderer::Loop() {
    t = SDL_GetTicks();
    
    game->Update();
    game->Render();

    t = SDL_GetTicks() - t;

    if(t < 1000 / game->fps) {
        SDL_Delay((1000/game->fps) - t);
    }
}