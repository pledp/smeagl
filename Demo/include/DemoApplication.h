#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Game.h"

class DemoApplication : public Game {
    public:
        DemoApplication(); 

        void Init() override;
        void Update() override;
        void Render() override;
};

#endif