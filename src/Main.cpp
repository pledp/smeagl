#include "SDLRenderer.h"
#include "Game.h"

int main(int argc, char *argv[]) {
    Game game;
    RendererBase* graphics = new SDLRenderer();

    game.setGraphics(graphics);
    game.run();

    delete graphics;
    return 0;
}