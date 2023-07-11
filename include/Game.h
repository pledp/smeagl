#ifndef GAME_H_
#define GAME_H_

#include "RendererBase.h"
#include "App.h"

class RendererBase;

class Game {
public:
    Game(App* application);
    
    void Run();
    void End();

    /**
     * Sets the graphics pipeline of the program.
     * 
     * @param graphics Pointer to a RendererBase object or object derived from RendererBase.
    */
    void SetGraphics(RendererBase* graphics);

private:
    RendererBase* graphics;

    App* application;

    int FPS;

    void Update();
    void Render();
    void Init();
    void ProcessInput();

    bool IsPlaying = false;
};

#endif