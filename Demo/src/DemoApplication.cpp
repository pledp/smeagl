#include "DemoApplication.h"
#include <iostream>

#include "Graphics/GraphicsAPI.h"

DemoApplication::DemoApplication() {
    
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
