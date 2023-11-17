#ifndef PLEDGL_H_
#define PLEDGL_H_

#include <cstdint>

struct GameTime {
    uint64_t TimeElapsedInMilliseconds = 0;
    float TotalTimeElapsedSeconds = 0;
    float DeltaTime = 0;
};

#endif