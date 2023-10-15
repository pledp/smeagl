#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/GraphicsBase.h"
#include "Application/GameBase.h"
#include "Graphics/Renderer/Renderer.h"

class Game : public GameBase {
public:
    /**
     * The game context.
    */
    Game();
    ~Game();
    
    void Run() override;
    void End() override;

    void SetFps(int NewFps) override;

    void Loop();

    void SetGraphics(GraphicsAPI::API api);

    // Get singelton object
    static Game& GetGame() { return *s_Instance; }

private:
    // Singleton object
    static Game* s_Instance;

    Renderer* renderer = nullptr;
    GraphicsBase* graphics = nullptr;

    bool isPlaying = false;
    bool createWindow = false;

    int fps;

    void ProcessInput();
    void initRun();

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif