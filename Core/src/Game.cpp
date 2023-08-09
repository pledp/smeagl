#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "Game.h"


Game* Game::s_Instance = nullptr;
Game::Game() {
    this->fps = 60;
    s_Instance = this;
}

void Game::Run() {
    graphics->Init(this->createWindow);


    this->Init();
    this->isPlaying = true;
    
    while(this->isPlaying) {
        graphics->Loop();
    }
}

void Game::Loop() {
    ProcessInput();
    Update();
    Render();
}

void Game::ProcessInput() {
    graphics->ProcessInput();
}

void Game::End() {
    this->isPlaying = false;
}

void Game::SetGraphics(RendererBase* graphics) {
    this->graphics = graphics;
    this->graphics->SetGame(this);
}

void Game::SetApp(App* app) {
    this->application = app;
}

void Game::CreateWindow() {
    this->createWindow = true;
}

