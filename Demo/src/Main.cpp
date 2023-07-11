#include "SDLRenderer.h"
#include "DemoApplication.h"
#include "Game.h"

int main(int argc, char *argv[]) {

    App* application = new DemoApplication();

    Game game(application);
    RendererBase* graphics = new SDLRenderer();

    game.SetGraphics(graphics);
    game.Run();

    delete graphics;
    return 0;
}