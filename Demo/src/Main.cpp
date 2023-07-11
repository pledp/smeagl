#include "SDLRenderer.h"
#include "DemoApplication.h"
#include "Game.h"

#include <iostream>

int main(int argc, char *argv[]) {

    App* application = new DemoApplication();

    Game game(application);
    RendererBase* graphics = new SDLRenderer();

    game.SetGraphics(graphics);
    game.Run();

    delete application;
    delete graphics;

    std::cout << "ENDING!";
    return 0;
}