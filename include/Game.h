#ifndef GAME_H_
#define GAME_H_

#include "RendererBase.h"

class RendererBase;

class Game {
private:
    RendererBase* graphics;

    int FPS;

    void Update();
    void Render();
    void Init();
    void ProcessInput();

    bool IsPlaying = false;

public:
    Game();
    void run();
    void end();

    /**
     * Sets the graphics pipeline of the program.
     * 
     * @param graphics Pointer to a RendererBase object or object derived from RendererBase.
    */
    void setGraphics(RendererBase* graphics);

};

#endif