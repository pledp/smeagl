#include "SDLRenderer.h"
#include "app2.h"
#include "Game.h"

int main(int argc, char *argv[]) {

    App* application = new app2();

    Game game(application);
    RendererBase* graphics = new SDLRenderer();

    game.SetGraphics(graphics);
    game.Run();

    delete graphics;
    return 0;
}