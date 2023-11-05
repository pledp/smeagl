#include "DemoApplication.h"
#include <iostream>
#include <cmath>

#include "Graphics/Renderer/Renderer.h"
#include "Core/Timer.h"
#include "Core/Input/Keyboard.h"

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

void DemoApplication::Update(float deltaTime) {
    size = sin(TotalTimeElapsedSeconds);
    if(Keyboard::GetKeyState(pledGL_key_LEFT)) {
        xPos = xPos - 2.0f * deltaTime;
    }
    if(Keyboard::GetKeyState(pledGL_key_RIGHT)) {
        xPos = xPos + 2.0f * deltaTime;
    }
    //std::cout << TotalTimeElapsedSeconds << " ";

}

void DemoApplication::Render(float deltaTime) {
    Renderer::ClearScreen({1.0f, 1.0f, 1.0f});
    
    Renderer::StartDraw();
    Renderer::DrawTri({xPos, 0.0f, 0.0f}, {size, size, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawTri({0.0f, 0.0f, 0.0f}, {0.2f, 0.2f, 0.0f}, {0.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw();
    Renderer::DrawTri({0.5f, 0.0f, 0.0f}, {size * 0.5f, size * 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f});
    Renderer::EndDraw();

}

DemoApplication::~DemoApplication() {
    delete graphics;
}
