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
    start_time = std::chrono::high_resolution_clock::now();
    frameDelay = 1000.0f / fps;
    frameStart = SDL_GetTicks64();
}
void SDLGraphics::EndLoop(GameBase* context) {
    frameTime = SDL_GetTicks64() - frameStart;
    deltaTime = frameTime/1000.0f;

    if(frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime);
    }

    // TODO: Move this shit to a proper class
    std::chrono::high_resolution_clock::time_point end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
    float time = static_cast<float>(elapsed_seconds.count());

    context->TotalTimeElapsedSeconds += time;
    std::cout << time;
}