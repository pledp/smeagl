#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "SDLRenderer.h"
#include "Game.h"

Game::Game(App* application) {
    this->fps = 144;
    this->application = application;
}

void Game::Init() {
    graphics->Init();
    application->Init();
}

void Game::Run() {
    this->Init();
    this->IsPlaying = true;
    
    while(this->IsPlaying) {
        ProcessInput();
        graphics->Loop();
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
    graphics->ProcessInput();
}

void Game::End() {
    this->IsPlaying = false;
}

void Game::SetGraphics(RendererBase* graphics) {
    this->graphics = graphics;
}

