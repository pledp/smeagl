#include "DemoApplication.h"

#include "SDLRenderer.h"
#include "Game.h"

#include <iostream>

int main(int argc, char *argv[]) {
    Game* game = new Game();
    App* application = new DemoApplication();
    RendererBase* graphics = new SDLRenderer();

    game->SetApp(application);
    game->SetGraphics(graphics);

    game->CreateWindow();
    game->Run();

    delete application;
    delete graphics;
    delete game;

    std::cout << "ENDING!";
    return 0;
}