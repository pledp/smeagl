#include <iostream>
#include <cmath>

#include "Application/Game.h"
#include "Graphics/Window/GraphicsAPI.h"

Game* Game::s_Instance = nullptr;
Game::Game() {
    s_Instance = this;
}
Game::~Game() {
    delete graphics;
}

void Game::initRun() {
    createWindow = true;
    fps = 60;

    // If graphics isn't set, set it to SDL.
    if(!this->graphics) {
        this->SetGraphics(GraphicsAPI::API::SDL);
    }
    graphics->Init(this->createWindow);
    Renderer::Init();
}

void Game::Run() {
    initRun();

    Init();
    this->isPlaying = true;    
    while(this->isPlaying) {
        // Start the frame
        graphics->StartLoop(this->fps);
        this->Loop();

        // End the frame and add delay if required
        graphics->EndLoop();
    }
}
void Game::End() {
    this->isPlaying = false;
}

void Game::Loop() {
    ProcessInput();
    Update();
    Render();
    graphics->Flush();
}

void Game::ProcessInput() {
    this->graphics->ProcessInput(this);
}

void Game::SetGraphics(GraphicsAPI::API api) {
    this->graphics = GraphicsAPI::SetRenderer(api);
}



