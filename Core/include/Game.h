#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Renderer/RendererBase.h"
#include "Application/App.h"

class RendererBase;
class App;

class Game {
public:
    /**
     * The game context.
    */
    Game();
    
    void Run();
    void End();

    /**
     * Sets createWindow to true, which makes Run() open a window.
    */
    void Loop();
    void ProcessInput();

    int fps;

    /**
     * Sets the graphics pipeline of the program.
     * 
     * @param graphics Pointer to a RendererBase object or object derived from RendererBase.
    */
    void SetGraphics(RendererBase* graphics);
    void SetApp(App* app);

    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    RendererBase* graphics;
    App* application;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Init() = 0;
};

#endif