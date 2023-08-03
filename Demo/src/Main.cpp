#include "DemoApplication.h"

#include <iostream>

int main(int argc, char *argv[]) {
    App* application = new DemoApplication();

    delete application;
    std::cout << "ENDING!";

    return 0;
}