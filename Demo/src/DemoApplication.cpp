#include "DemoApplication.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#include "Graphics/Renderer/Renderer.h"
#include "Timer.h"
#include "Input/Keyboard.h"
#include <glm/gtc/matrix_transform.hpp>

float indent = 0.0f;
float size = 0.0f;
float xPos = 0.0f;
float yPos = 0.0f;
float zoom = 1.0f;

glm::mat4 viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f)) * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
glm::mat4 projectionMatrix = glm::ortho(-1.0f, 1.0f, -0.75f, 0.75f, -1.0f, 1.0f);
glm::mat4 vp = viewMatrix * projectionMatrix;

DemoApplication::DemoApplication() {
    
}

void DemoApplication::Init() {
    Timer timer;
    timer.StartTimer();
    std::cout << timer.CurrentTimeInSeconds<float>();
}

void DemoApplication::Update() {
    size = sin(GameTime.TotalTimeElapsedSeconds);


    if(Keyboard::GetKeyState(pledGL_key_Q)) {
        zoom = std::max(0.0f, zoom - 0.5f * GameTime.DeltaTime);
    }
    if(Keyboard::GetKeyState(pledGL_key_E)) {
        zoom = std::max(0.0f, zoom + 0.5f * GameTime.DeltaTime);
    }

    if(Keyboard::GetKeyState(pledGL_key_W)) {
        yPos -= 1.0f * GameTime.DeltaTime;
    }
    if(Keyboard::GetKeyState(pledGL_key_S)) {
        yPos += 1.0f * GameTime.DeltaTime;
    }
    if(Keyboard::GetKeyState(pledGL_key_A)) {
        xPos += 1.0f * GameTime.DeltaTime;
    }
    if(Keyboard::GetKeyState(pledGL_key_D)) {
        xPos -= 1.0f * GameTime.DeltaTime;
    }

    viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xPos, yPos, 0.0f)) * glm::scale(glm::mat4(1.0f), glm::vec3(zoom, zoom, 1.0f));
    projectionMatrix = glm::ortho(-1.0f, 1.0f, -0.75f, 0.75f, -1.0f, 1.0f);
    vp = viewMatrix * projectionMatrix;
    //std::cout << TotalTimeElapsedSeconds << " ";

}

void DemoApplication::Render() {
    Renderer::ClearScreen({1.0f, 1.0f, 1.0f});

    Renderer::StartDraw(vp);

    Renderer::DrawQuad({0.0f + (std::abs(size) / 2), 0.2f + (1.0f / 2), 0.0f}, {std::abs(size), 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw(vp);
    Renderer::DrawQuad({xPos, 0.0f, 0.0f}, {size, size, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawQuad({0.5f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 0.0f});
    Renderer::DrawTri({0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 0.0f});
    Renderer::EndDraw();

    Renderer::StartDraw(vp);
    Renderer::DrawTri({0.2f, 0.2f, 0.0f}, {size * 0.5f, size * 0.5f, 0.0f}, {0.0f, 1.0f, 1.0f});
    Renderer::DrawQuad({0.5f, 1.0f, 0.0f}, {size * 0.3f, size * 0.8f, 0.0f}, {0.0f, 0.0f, 1.0f});
    Renderer::DrawTri({0.8f, size, 0.0f}, {size * 0.2f, size * 0.5f, 0.0f}, {1.0f, 0.0f, 1.0f});


    Renderer::EndDraw();
}

DemoApplication::~DemoApplication() {
    delete graphics;
}
