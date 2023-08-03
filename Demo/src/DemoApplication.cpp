#include "DemoApplication.h"
#include <iostream>

#include "Graphics/SDLRenderer.h"
#include "Game.h"

Game game;

DemoApplication::DemoApplication() {
    Game* game = new Game();
    RendererBase* graphics = new SDLRenderer();

    game->SetGraphics(graphics);
    game->CreateWindow();
    game->Run(this);

    delete graphics;
    delete game;
}

void DemoApplication::Init() {
    game = Game::GetGame();
}

void DemoApplication::Update() {
    
}

void DemoApplication::Render() {

}


