#include "DemoApplication.h"
#include <iostream>

void DemoApplication::Init() {
    std::cout << "Init";
}

void DemoApplication::Update() {
    std::cout << "New tick!";
}

void DemoApplication::Render() {
    std::cout << "Render";
}


