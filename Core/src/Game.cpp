#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "Game.h"


Game* Game::s_Instance = nullptr;
Game::Game() {
    this->createWindow = true;
    this->fps = 60;
    s_Instance = this;
}

void Game::Run() {
    renderer->Init(this->createWindow);


    this->Init();
    this->isPlaying = true;
    
    while(this->isPlaying) {
        renderer->Loop();
    }
}

void Game::Loop() {
    ProcessInput();
    Update();
    Render();
}

void Game::ProcessInput() {
    renderer->ProcessInput();
}

void Game::End() {
    this->isPlaying = false;
}

void Game::SetRenderer(RendererBase* renderer) {
    this->renderer = renderer;
    this->renderer->SetGame(this);
}

