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

    void Loop();

    int fps;

    void SetGraphics(GraphicsAPI::API api);
    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    void ProcessInput();
    void initRun();

    Renderer* renderer = nullptr;
    GraphicsBase* graphics = nullptr;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif