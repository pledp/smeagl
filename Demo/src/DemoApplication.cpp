#include "DemoApplication.h"
#include <iostream>

#include "Graphics/Renderer/RendererAPI.h"

DemoApplication::DemoApplication() {
    this->SetRenderer(RendererAPI::API::SDL);
}

void DemoApplication::Init() {

}

void DemoApplication::Update() {
    std::cout << "Update";
}

void DemoApplication::Render() {

}

DemoApplication::~DemoApplication() {
    delete graphics;
}
