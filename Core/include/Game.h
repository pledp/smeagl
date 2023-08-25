#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Renderer/RendererBase.h"

class RendererBase;

class Game {
public:
    /**
     * The game context.
    */
    Game();
    
    void Run();
    void End();

    void Loop();

    int fps;

    /**
     * Sets the graphics pipeline of the program.
     * 
     * @param graphics Pointer to a RendererBase object or object derived from RendererBase.
    */
    void SetRenderer(RendererBase* graphics);

    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    void ProcessInput();

    RendererBase* renderer;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Init() = 0;
};

#endif