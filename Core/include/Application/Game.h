#ifndef GAME_H_
#define GAME_H_

#include <cstdint>

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/GraphicsBase.h"
#include "Application/GameBase.h"
#include "Graphics/Renderer/Renderer.h"
#include "Timer.h"

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

        void SetGraphics(const GraphicsAPI::API api);

        // Get singelton object
        static Game& GetGame() { return *s_instance; }

    private:
        // Singleton object
        static Game* s_instance;


        uint64_t frameStart, frameTime;
        uint64_t frameDelay;
        Timer frameTimer;

        Renderer* m_renderer = nullptr;
        GraphicsBase* m_graphics = nullptr;

        bool isPlaying = false;
        bool createWindow = false;

        int fps;

        void ProcessInput();
        void initRun();

        void StartLoop();
        void Loop();
        void EndLoop();

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render(Renderer m_renderer) = 0;
    };
};

#endif