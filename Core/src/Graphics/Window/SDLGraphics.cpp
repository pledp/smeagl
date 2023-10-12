#include "Graphics/Window/SDLGraphics.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

#include "glad/glad.h"
#include "Application/GameBase.h"
#include "Graphics/Renderer/Renderer.h"

SDL_GLContext context;

SDLGraphics::SDLGraphics() {

}

void SDLGraphics::Init(bool createWindow) {
    this->width = 1024;
    this->height = 768;

    SDL_Init(SDL_INIT_EVERYTHING);

    if(createWindow)
        window = SDL_CreateWindow("pledGL", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

    context = SDL_GL_CreateContext(window);
    renderer = SDL_CreateRenderer(window, -1, 0);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    SDL_Surface* surface = NULL;

    std::cout << "Window created!";
}

void SDLGraphics::Exit() {
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_Quit();

    window = NULL; 
    renderer = NULL;
}

void SDLGraphics::Flush() {
    SDL_GL_SwapWindow(window);
}

void SDLGraphics::ProcessInput(GameBase* context) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                context->End();
                break;
            case SDL_WINDOWEVENT:
                std::cout << "Moved window";
                break;
        }
    } 
}

void SDLGraphics::StartLoop(int fps) {
    frameDelay = 1000.0f / 60;
    frameStart = SDL_GetTicks64();
}
void SDLGraphics::EndLoop() {
    frameTime = SDL_GetTicks64() - frameStart;
    deltaTime = frameTime/1000.0f;

    if(frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }
}