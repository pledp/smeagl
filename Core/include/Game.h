#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Renderer/RendererAPI.h"
#include "Graphics/Renderer/Renderer.h"

class Game {
public:
    /**
     * The game context.
    */
    Game();
    ~Game();
    
    void Run();
    static void End();

    void Loop();

    int fps;

    /**
     * Sets the graphics pipeline of the program.
     * 
     * @param graphics Pointer to a Renderer object or object derived from Renderer.
    */
    void SetRenderer(RendererAPI::API graphics);

    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    void ProcessInput();

    Renderer* renderer;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Init() = 0;
};

#endif