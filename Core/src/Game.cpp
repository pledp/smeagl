#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

#include "Game.h"
#include "Graphics/Renderer/SDLRenderer.h"

Game* Game::s_Instance = nullptr;
Game::Game() {
    this->createWindow = true;
    this->fps = 60;
    s_Instance = this;
}
Game::~Game() {
    delete renderer;
}

void Game::Run() {
    renderer->Init(this->createWindow);


    this->Init();
    this->isPlaying = true;
    
    while(this->isPlaying) {
        // Start the frame
        renderer->StartLoop(this->fps);
        this->Loop();

        // End the frame and add delay if required
        renderer->EndLoop();
    }
}
void Game::End() {
    this->isPlaying = false;
}

void Game::Loop() {
    ProcessInput();
    Update();
    Render();
}

void Game::ProcessInput() {
    renderer->ProcessInput();
}

//TODO: Move this function to different class so Game doesn't have any direct dependency to SDLRenderer, only to Renderer
void Game::SetRenderer(RendererAPI::API api) {
    switch(api) {
        case RendererAPI::API::SDL: this->renderer = new SDLRenderer();
    }
}



