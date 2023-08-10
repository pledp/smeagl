#include "DemoApplication.h"
#include <iostream>

DemoApplication::DemoApplication() {
    this->graphics = new SDLRenderer();

    this->SetGraphics(graphics);
    this->CreateWindow();
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
