#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "Game.h"


Game* Game::s_Instance = nullptr;
Game::Game() {
    this->fps = 60;
    s_Instance = this;
}

void Game::Init() {
    graphics->Init(this->createWindow);
    application->Init();
}

void Game::Run(App* app) {
    SetApp(app);

    this->Init();
    this->isPlaying = true;
    
    while(this->isPlaying) {
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

