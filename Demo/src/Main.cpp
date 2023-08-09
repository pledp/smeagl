#include "DemoApplication.h"

#include <iostream>

int main(int argc, char *argv[]) {
    DemoApplication* application = new DemoApplication();

    delete application;
    std::cout << "ENDING!";

    return 0;
}