#ifndef GAME_H_
#define GAME_H_

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/GraphicsBase.h"
#include "Application/GameBase.h"
#include "Graphics/Renderer/Renderer.h"
#include "Timer.h"

#include <cstdint>

namespace pledGL {
    class Game : public GameBase {
    public:
        /**
         * The game context.
        */
        Game();
        ~Game();
        
        void Run() override;
        void End() override;

        void SetFps(const int NewFps) override;

        void Loop();

        void SetGraphics(const GraphicsAPI::API api);

        // Get singelton object
        static Game& GetGame() { return *s_Instance; }

    private:
        // Singleton object
        static Game* s_Instance;


        uint64_t frameStart, frameTime;
        uint64_t frameDelay;
        Timer frameTimer;

        Renderer* renderer = nullptr;
        GraphicsBase* graphics = nullptr;

        bool isPlaying = false;
        bool createWindow = false;

        int fps;

        void ProcessInput();
        void initRun();
        void StartLoop();
        void EndLoop();

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    };
};

#endif