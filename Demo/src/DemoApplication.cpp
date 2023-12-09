#include "DemoApplication.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Graphics/Renderer/Renderer.h"
#include "Timer.h"
#include "Input/Keyboard.h"

float indent = 0.0f;
float size = 0.0f;
float xPos = 0.0f;

DemoApplication::DemoApplication() {
    
}

void DemoApplication::Init() {
    Timer timer;
    timer.StartTimer();
    std::cout << timer.CurrentTimeInSeconds<float>();
}

void DemoApplication::Update() {
    size = sin(GameTime.TotalTimeElapsedSeconds);
    if(Keyboard::GetKeyState(pledGL_key_LEFT)) {
        xPos = xPos - 2.0f * GameTime.DeltaTime;
    }
    if(Keyboard::GetKeyState(pledGL_key_RIGHT)) {
        xPos = xPos + 2.0f * GameTime.DeltaTime;
    }

    if(Keyboard::GetKeyPressed(pledGL_key_A)) {
        std::cout << "PRESSED!";
    }
    //std::cout << TotalTimeElapsedSeconds << " ";

}

void DemoApplication::Render() {
    Renderer::ClearScreen({1.0f, 1.0f, 1.0f});

    Renderer::StartDraw();

    Renderer::DrawQuad({0.0f + (std::abs(size) / 2), 0.2f + (1.0f / 2), 0.0f}, {std::abs(size), 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw();
    Renderer::DrawQuad({xPos, 0.0f, 0.0f}, {size, size, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawQuad({0.5f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawTri({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw();
    Renderer::DrawTri({0.2f, 0.2f, 0.0f}, {size * 0.5f, size * 0.5f, 0.0f}, {0.0f, 1.0f, 1.0f});
    Renderer::DrawQuad({0.5f, 1.0f, 0.0f}, {size * 0.3f, size * 0.8f, 0.0f}, {0.0f, 0.0f, 1.0f});
    Renderer::DrawTri({0.8f, size, 0.0f}, {size * 0.2f, size * 0.5f, 0.0f}, {1.0f, 0.0f, 1.0f});


    Renderer::EndDraw();
}

DemoApplication::~DemoApplication() {
    delete graphics;
}
