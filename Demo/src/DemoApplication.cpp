#include "DemoApplication.h"
#include <iostream>

DemoApplication::DemoApplication() {
    this->graphics = new SDLRenderer();

    this->SetRenderer(graphics);
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
