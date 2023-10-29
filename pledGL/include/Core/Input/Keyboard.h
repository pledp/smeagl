#ifndef INPUT_KEYBOARD_H_
#define INPUT_KEYBOARD_H_

#include <array>

class Keyboard {
public:
    static bool GetKeyState(Key key);

private:
    constexpr static const int s_KeyCount = 287;

    static std::array<bool, KeyCount> s_KeysDown;
}

enum class Key
{
    
};

#endif