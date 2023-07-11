#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "App.h"

class DemoApplication : public App {
    public:
        void Init() override;
        void Update() override;
        void ProcessInput() override;
        void Render() override;
};

#endif