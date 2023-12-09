#include <iostream>
#include <cmath>

#include "Application/Game.h"
#include "Graphics/Window/GraphicsAPI.h"
#include "Input/Keyboard.h"

Game* Game::s_Instance = nullptr;
Game::Game() {
    s_Instance = this;
}
Game::~Game() {
    delete graphics;
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
}

void Game::StartLoop() {
    frameTimer.StartTimer();
    frameDelay = 1000.0f / fps;
    frameStart = frameTimer.CurrentTimeInMilliseconds<uint64_t>();
}
void Game::EndLoop() {
    frameTime = frameTimer.CurrentTimeInMilliseconds<uint64_t>() - frameStart;

    if(frameDelay > frameTime) {
        graphics->AddDelay(frameDelay-frameTime);
    }
    float time = frameTimer.CurrentTimeInSeconds<float>();

    GameTime.DeltaTime = time;
    GameTime.TotalTimeElapsedSeconds += time;
}

void Game::End() {
    isPlaying = false;
    graphics->Exit();
    Renderer::Exit();
}

void Game::SetGraphics(GraphicsAPI::API api) {
    graphics = GraphicsAPI::SetRenderer(api);
}

void Game::SetFps(int newFps) {
    fps = newFps;
}

void Game::initRun() {
    createWindow = true;
    fps = 60;

    // If graphics isn't set, set it to SDL.
    if(!graphics) {
        SetGraphics(GraphicsAPI::API::SDL);
    }
    graphics->Init(createWindow);

    Keyboard::Init();
    Renderer::Init();
}

void Game::Loop() {
    ProcessInput();
    Keyboard::Update();
    Update();
    Render();
    graphics->Flush();
}

void Game::ProcessInput() {
    graphics->ProcessInput(this);
}


