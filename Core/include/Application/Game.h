#ifndef GAME_H_
#define GAME_H_

#include <cstdint>
#include <memory>

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
        
        void SetGraphics(const GraphicsAPI::API api);

        // Get singelton object
        static Game& GetGame() { return *s_instance; }

    protected:
        void SetTargetFps(const int new_fps) override;
        int target_fps;


    private:
        // Singleton object
        static Game* s_instance;


        uint64_t frameStart, frameTime;
        uint64_t frameDelay;
        Timer frameTimer;

        std::unique_ptr<Renderer> m_renderer;
        std::unique_ptr<GraphicsBase> m_graphics;

        bool isPlaying = false;
        bool createWindow = false;

        GameTime game_time;

        void ProcessInput();
        void initRun();

        void StartLoop();
        void Loop();
        void EndLoop();

        virtual void Init() = 0;
        virtual void Update(const GameTime& game_time) = 0;
        virtual void Render(const GameTime& game_time, Renderer& m_renderer) = 0;
    };
};

#endif