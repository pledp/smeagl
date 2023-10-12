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
    Renderer::DrawTri({1.0f, 1.0f,1.0f});

}

DemoApplication::~DemoApplication() {
    delete graphics;
}
