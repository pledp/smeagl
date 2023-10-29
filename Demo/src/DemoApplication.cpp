#include "DemoApplication.h"
#include <iostream>
#include <cmath>

#include "Graphics/Renderer/Renderer.h"
#include "Core/Timer.h"

float indent = 0.0f;
float size = 0.0f;

DemoApplication::DemoApplication() {
    
}

void DemoApplication::Init() {
    Timer timer;
    timer.StartTimer();
    std::cout << timer.CurrentTimeInSeconds<float>();
}

void DemoApplication::Update() {
    size = sin(TotalTimeElapsedSeconds);
    //std::cout << TotalTimeElapsedSeconds << " ";
}

void DemoApplication::Render() {
    Renderer::ClearScreen({1.0f, 1.0f, 1.0f});

    Renderer::StartDraw();
    Renderer::DrawTri({0.0f, 0.0f, 0.0f}, {size, size, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawTri({0.0f, 0.0f, 0.0f}, {0.2f, 0.2f, 0.0f}, {0.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw();
    Renderer::DrawTri({0.5f, 0.0f, 0.0f}, {size * 0.5f, size * 0.5f, 0.0f}, {0.0f, 0.0f, 1.0f});
    Renderer::EndDraw();

}

DemoApplication::~DemoApplication() {
    delete graphics;
}
