#include "DemoApplication.h"

#include "Graphics/SDLRenderer.h"
#include "Game.h"

#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[]) {
    Game* game = new Game();
    App* application = new DemoApplication();
    RendererBase* graphics = new SDLRenderer();

    glfwInit();

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