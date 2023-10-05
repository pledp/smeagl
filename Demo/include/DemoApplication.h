#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Application\Game.h"

class DemoApplication : public Game {
    public:
        DemoApplication(); 
        ~DemoApplication();

        void Init() override;
        void Update() override;
        void Render() override;

    private: 
        Renderer* graphics = nullptr;
};

#endif