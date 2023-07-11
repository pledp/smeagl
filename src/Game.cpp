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
    
    auto frequency = graphics->Frequency();

    while(this->IsPlaying) {
        this->ProcessInput();

        auto start = graphics->StartLoop();

        this->Update();
        this->Render();

        auto delayTime = graphics->EndLoop(FPS, start, frequency);

        if(delayTime > 0) {
            graphics->DelayTime(delayTime);
        }
    }
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

