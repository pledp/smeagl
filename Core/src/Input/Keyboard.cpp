#include "Input/Keyboard.h"
#include <SDL2/SDL_keyboard.h>

std::array<bool, Keyboard::s_KeyCount> Keyboard::s_KeysDown;
std::array<bool, Keyboard::s_KeyCount> Keyboard::s_KeysUp;
std::array<bool, Keyboard::s_KeyCount> Keyboard::s_Keys;
std::array<bool, Keyboard::s_KeyCount> Keyboard::s_LastKeysState;

void Keyboard::Init() {
    std::fill(s_KeysDown.begin(), s_KeysDown.end(), false);
    std::fill(s_KeysUp.begin(), s_KeysUp.end(), false);
    std::fill(s_Keys.begin(), s_Keys.end(), false);
    std::fill(s_LastKeysState.begin(), s_LastKeysState.end(), false);

}

void Keyboard::Update() {
    std::fill(s_KeysDown.begin(), s_KeysDown.end(), false);
    std::fill(s_KeysUp.begin(), s_KeysUp.end(), false);

    const Uint8* state = SDL_GetKeyboardState(nullptr);
    s_LastKeysState = s_Keys;
    for(int i = 0; i < s_KeyCount; i++) {
        bool wasDown = s_Keys[i];
        s_Keys[i] = state[i];
        bool isDown = s_Keys[i];

        if(isDown) {
            s_KeysDown[i] = true;
        }
        else if(!isDown) {
            s_KeysUp[i] = true;
        }
    }
}

bool Keyboard::GetKeyState(int key) {
    return s_Keys[key];
}

bool Keyboard::GetKeyPressed(int key) {
    return !s_LastKeysState[key] && s_Keys[key];
}