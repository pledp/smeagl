#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Renderer/RendererAPI.h"
#include "Graphics/Renderer/Renderer.h"
#include "Application/GameBase.h"

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

    void SetRenderer(RendererAPI::API api);
    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    void ProcessInput();

    Renderer* renderer = nullptr;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif