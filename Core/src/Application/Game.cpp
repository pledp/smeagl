#include <iostream>
#include <cmath>

#include "Application/Game.h"
#include "Graphics/Window/GraphicsAPI.h"
#include "Input/Keyboard.h"

namespace pledGL {
    Game* Game::s_instance = nullptr;
    Game::Game() {
        s_instance = this;
    }
    Game::~Game() {
        
    }

    void Game::Run() {
        initRun();

        Init();
        this->isPlaying = true;

        // Main loop
        while(this->isPlaying) {
            // Start the frame
            StartLoop();

            Loop();

            // End the frame and add delay if required
            EndLoop();
        }

        m_graphics->Exit();
        m_renderer->Exit();
    }

    void Game::StartLoop() {
        frameTimer.StartTimer();
        frameDelay = 1000.0f / target_fps;
        frameStart = frameTimer.CurrentTimeInMilliseconds<uint64_t>();
    }
    void Game::EndLoop() {
        frameTime = frameTimer.CurrentTimeInMilliseconds<uint64_t>() - frameStart;

        if(frameDelay > frameTime) {
            m_graphics->AddDelay(frameDelay-frameTime);
        }
        float time = frameTimer.CurrentTimeInSeconds<float>();

        game_time.DeltaTime = time;
        game_time.TotalTimeElapsedSeconds += time;
    }

    void Game::End() {
        isPlaying = false;
        std::cout << "YO!";
    }

    void Game::initRun() {
        createWindow = true;
        target_fps = 60;

        // If graphics isn't set, set it to SDL
        if(!m_graphics) {
            SetGraphics(GraphicsAPI::API::SDL);
        }
        m_graphics->Init(createWindow);

        Keyboard::Init();

        // Initialize 2D renderer
        m_renderer = std::make_unique<Renderer>();
        m_renderer->Init();

    }

    void Game::Loop() {
        ProcessInput();
        Keyboard::Update();
        Update(game_time);
        
        Render(game_time, *m_renderer);

        // Swap back and front buffer. (Display OpenGL image on window)
        m_graphics->Flush();
    }

    void Game::ProcessInput() {
        m_graphics->ProcessInput(*this);
    }

    void Game::SetGraphics(const GraphicsAPI::API api) {
        m_graphics = GraphicsAPI::SetRenderer(api);
    }

    void Game::SetTargetFps(const int new_fps) {
        target_fps = new_fps;
    }
}


