#ifndef APP_H_
#define APP_H_

class App {
    public:
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void ProcessInput() = 0;
        virtual void Render() = 0;
};

#endif