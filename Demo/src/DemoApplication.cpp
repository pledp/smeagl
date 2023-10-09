#include "DemoApplication.h"
#include <iostream>

#include "Graphics/Renderer/Renderer.h"

DemoApplication::DemoApplication() {
    
}

void DemoApplication::Init() {

}

void DemoApplication::Update() {
    std::cout << "Update";
}

void DemoApplication::Render() {
    Renderer::ClearScreen();
    Renderer::DrawTri({0.2f, 0.5f,0.0f});
    Renderer::DrawTri({0.2f, -0.5f,0.0f});
}

DemoApplication::~DemoApplication() {
    delete graphics;
}
