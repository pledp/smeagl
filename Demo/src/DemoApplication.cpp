#include "DemoApplication.h"
#include <iostream>

void DemoApplication::Init() {

}

void DemoApplication::Update() {
    std::cout << "New tick!";
}

void DemoApplication::ProcessInput() {
    std::cout << "Input";
}

void DemoApplication::Render() {
    std::cout << "Render";
}


