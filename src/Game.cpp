#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "SDLRenderer.h"
#include "Game.h"

Game::Game() {
    this->FPS = 60;
}

void Game::Init() {
    graphics->init();
}

void Game::run() {
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

    graphics->exit();
}

void Game::Update() {
    std::cout << "New tick!";
}

void Game::Render() {
    graphics->render();
}

void Game::ProcessInput() {
    graphics->processInput();
}

void Game::end() {
    this->IsPlaying = false;
}

void Game::setGraphics(RendererBase* graphics) {
    this->graphics = graphics;
}

