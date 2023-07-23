#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "SDLRenderer.h"
#include "Game.h"

Game::Game() {
    this->fps = 144;
}

void Game::Init() {
    graphics->Init(this->createWindow);
    application->Init();
}

void Game::Run() {
    this->Init();
    this->isPlaying = true;
    
    while(this->isPlaying) {
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

