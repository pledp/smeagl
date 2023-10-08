#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/GraphicsBase.h"
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

    void SetRenderer(GraphicsAPI::API api);
    static Game& GetGame() { return *s_Instance; }

private:
    static Game* s_Instance;

    void ProcessInput();

    GraphicsBase* renderer = nullptr;

    bool isPlaying = false;
    bool createWindow = false;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif