#include "SDLRenderer.h"
#include "DemoApplication.h"
#include "Game.h"

#include <iostream>

int main(int argc, char *argv[]) {

    App* application = new DemoApplication();

    Game* game = new Game(application);
    RendererBase* graphics = new SDLRenderer();

    game->SetGraphics(graphics);
    graphics->SetGame(game);
    game->Run();

    delete application;
    delete graphics;
    delete game;

    std::cout << "ENDING!";
    return 0;
}