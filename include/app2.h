#ifndef APP2_H_
#define APP2_H_

#include "App.h"

class app2 : public App {
    public:
        void Init() override;
        void Update() override;
        void ProcessInput() override;
        void Render() override;
};

#endif