#include "DemoApplication.h"

#include <iostream>

int main(int argc, char *argv[]) {
    DemoApplication* application = new DemoApplication();
    application->Run();

    delete application;
    std::cout << "ENDING!";

    return 0;
}