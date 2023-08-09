#include "DemoApplication.h"
#include <iostream>

#include "Graphics/SDLRenderer.h"
#include "Game.h"

DemoApplication::DemoApplication() {
    RendererBase* graphics = new SDLRenderer();

    this->SetGraphics(graphics);
    this->CreateWindow();
    this->Run();

    delete graphics;
}

void DemoApplication::Init() {

}

void DemoApplication::Update() {
    std::cout << "Update";
}

void DemoApplication::Render() {

}


