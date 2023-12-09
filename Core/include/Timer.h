#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;

public:
    void StartTimer() {
        startTime = std::chrono::high_resolution_clock::now();
    };

    template <typename T>
    T CurrentTimeInMilliseconds() {
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(endTime - startTime);
        T time = elapsedSeconds.count() * 1000;

        return time;
    };

    template <typename T>
    T CurrentTimeInSeconds() {
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedSeconds = std::chrono::duration_cast<std::chrono::duration<float>>(endTime - startTime);
        T time = elapsedSeconds.count();

        return time;
    };
};

#endif