#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "SDLRenderer.h"
#include "Game.h"

Game::Game(App* application) {
    this->FPS = 60;
    this->application = application;
}

void Game::Init() {
    graphics->Init();
    application->Init();
}

void Game::Run() {
    this->Init();
    this->IsPlaying = true;
    
    const Uint64 frequency = SDL_GetPerformanceFrequency();

    while(this->IsPlaying) {
        Uint64 start = SDL_GetPerformanceCounter();

        this->ProcessInput();
        this->Update();
        this->Render();

        // Cap FPS
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedTime = (end - start) / (float)frequency * 1000.0f;
        Uint32 delayTime = (Uint32)ceil((1000/FPS) - elapsedTime); 

        if(delayTime > 0) {
            SDL_Delay(delayTime);
        }
    }

    graphics->Exit();
}

void Game::Update() {
    application->Update();
}

void Game::Render() {
    application->Render();
    graphics->Render();
}

void Game::ProcessInput() {
    application->ProcessInput();
    graphics->ProcessInput();
}

void Game::End() {
    this->IsPlaying = false;
}

void Game::SetGraphics(RendererBase* graphics) {
    this->graphics = graphics;
}

