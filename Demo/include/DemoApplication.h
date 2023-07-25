#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Application/App.h"

class DemoApplication : public App {
    public:
        void Init() override;
        void Update() override;
        void Render() override;
};

#endif