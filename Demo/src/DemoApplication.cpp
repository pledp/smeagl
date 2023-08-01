#include "DemoApplication.h"
#include <iostream>

#include "Game.h"

Game game;

void DemoApplication::Init() {
    std::cout << "Init";
    game = Game::GetGame();
}

void DemoApplication::Update() {
    std::cout << "New tick!";
    std::cout << game.fps;
}

void DemoApplication::Render() {
    std::cout << "Render";
}


