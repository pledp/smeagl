#ifndef INPUT_KEYBOARD_H_
#define INPUT_KEYBOARD_H_

#include <array>

namespace pledGL {
    class Keyboard {
    public:
        static void Init();
        static void Update();

        /**
         * Get the state of a key.
         * @param key The key.
         * @return True if key is held down, false otherwise.
        */
        static bool GetKeyState(int key);

        /**
         * Check if key is pressed.
         * @param key The key.
         * @return True if the key is down AND if it's previous state was up, false otherwise.
        */
        static bool GetKeyPressed(int key);

    private:
        constexpr static const int s_KeyCount = 287;

        static std::array<bool, s_KeyCount> s_KeysDown;
        static std::array<bool, s_KeyCount> s_KeysUp;
        static std::array<bool, s_KeyCount> s_Keys;
        static std::array<bool, s_KeyCount> s_LastKeysState;

    };

    enum
    {
        pledGL_key_FIRST = 4,
        pledGL_key_A = pledGL_key_FIRST,
        pledGL_key_B = 5,
        pledGL_key_C = 6,
        pledGL_key_D = 7,
        pledGL_key_E = 8,
        pledGL_key_F = 9,
        pledGL_key_G = 10,
        pledGL_key_H = 11,
        pledGL_key_I = 12,
        pledGL_key_J = 13,
        pledGL_key_K = 14,
        pledGL_key_L = 15,
        pledGL_key_M = 16,
        pledGL_key_N = 17,
        pledGL_key_O = 18,
        pledGL_key_P = 19,
        pledGL_key_Q = 20,
        pledGL_key_R = 21,
        pledGL_key_S = 22,
        pledGL_key_T = 23,
        pledGL_key_U = 24,
        pledGL_key_V = 25,
        pledGL_key_W = 26,
        pledGL_key_X = 27,
        pledGL_key_Y = 28,
        pledGL_key_Z = 29,
        pledGL_key_1 = 30,
        pledGL_key_2 = 31,
        pledGL_key_3 = 32,
        pledGL_key_4 = 33,
        pledGL_key_5 = 34,
        pledGL_key_6 = 35,
        pledGL_key_7 = 36,
        pledGL_key_8 = 37,
        pledGL_key_9 = 38,
        pledGL_key_0 = 39,
        pledGL_key_RETURN = 40,
        pledGL_key_ESCAPE = 41,
        pledGL_key_BACKSPACE = 42,
        pledGL_key_TAB = 43,
        pledGL_key_SPACE = 44,
        pledGL_key_MINUS = 45,
        pledGL_key_EQUALS = 46,
        pledGL_key_LEFTBRACKET = 47,
        pledGL_key_RIGHTBRACKET = 48,
        pledGL_key_BACKSLASH = 49, 
        pledGL_key_NONUSHASH = 50,
        pledGL_key_SEMICOLON = 51,
        pledGL_key_APOSTROPHE = 52,
        pledGL_key_GRAVE = 53,
        pledGL_key_COMMA = 54,
        pledGL_key_PERIOD = 55,
        pledGL_key_SLASH = 56,
        pledGL_key_CAPSLOCK = 57,
        pledGL_key_F1 = 58,
        pledGL_key_F2 = 59,
        pledGL_key_F3 = 60,
        pledGL_key_F4 = 61,
        pledGL_key_F5 = 62,
        pledGL_key_F6 = 63,
        pledGL_key_F7 = 64,
        pledGL_key_F8 = 65,
        pledGL_key_F9 = 66,
        pledGL_key_F10 = 67,
        pledGL_key_F11 = 68,
        pledGL_key_F12 = 69,
        pledGL_key_PRINTSCREEN = 70,
        pledGL_key_SCROLLLOCK = 71,
        pledGL_key_PAUSE = 72,
        pledGL_key_INSERT = 73,
        pledGL_key_HOME = 74,
        pledGL_key_PAGEUP = 75,
        pledGL_key_DELETE = 76,
        pledGL_key_END = 77,
        pledGL_key_PAGEDOWN = 78,
        pledGL_key_RIGHT = 79,
        pledGL_key_LEFT = 80,
        pledGL_key_DOWN = 81,
        pledGL_key_UP = 82,
        pledGL_key_NUMLOCKCLEAR = 83,
        pledGL_key_KP_DIVIDE = 84,
        pledGL_key_KP_MULTIPLY = 85,
        pledGL_key_KP_MINUS = 86,
        pledGL_key_KP_PLUS = 87,
        pledGL_key_KP_ENTER = 88,
        pledGL_key_KP_1 = 89,
        pledGL_key_KP_2 = 90,
        pledGL_key_KP_3 = 91,
        pledGL_key_KP_4 = 92,
        pledGL_key_KP_5 = 93,
        pledGL_key_KP_6 = 94,
        pledGL_key_KP_7 = 95,
        pledGL_key_KP_8 = 96,
        pledGL_key_KP_9 = 97,
        pledGL_key_KP_0 = 98,
        pledGL_key_KP_PERIOD = 99,
        pledGL_key_NONUSBACKSLASH = 100, 
        pledGL_key_APPLICATION = 101,
        pledGL_key_POWER = 102,
        pledGL_key_KP_EQUALS = 103,
        pledGL_key_F13 = 104,
        pledGL_key_F14 = 105,
        pledGL_key_F15 = 106,
        pledGL_key_F16 = 107,
        pledGL_key_F17 = 108,
        pledGL_key_F18 = 109,
        pledGL_key_F19 = 110,
        pledGL_key_F20 = 111,
        pledGL_key_F21 = 112,
        pledGL_key_F22 = 113,
        pledGL_key_F23 = 114,
        pledGL_key_F24 = 115,
        pledGL_key_EXECUTE = 116,
        pledGL_key_HELP = 117,    
        pledGL_key_MENU = 118,  
        pledGL_key_SELECT = 119,
        pledGL_key_STOP = 120,   
        pledGL_key_AGAIN = 121,  
        pledGL_key_UNDO = 122,  
        pledGL_key_CUT = 123,    
        pledGL_key_COPY = 124,  
        pledGL_key_PASTE = 125, 
        pledGL_key_FIND = 126,   
        pledGL_key_MUTE = 127,
        pledGL_key_VOLUMEUP = 128,
        pledGL_key_VOLUMEDOWN = 129,
        pledGL_key_KP_COMMA = 133,
        pledGL_key_KP_EQUALSAS400 = 134,
        pledGL_key_INTERNATIONAL1 = 135,
        pledGL_key_INTERNATIONAL2 = 136,
        pledGL_key_INTERNATIONAL3 = 137, 
        pledGL_key_INTERNATIONAL4 = 138,
        pledGL_key_INTERNATIONAL5 = 139,
        pledGL_key_INTERNATIONAL6 = 140,
        pledGL_key_INTERNATIONAL7 = 141,
        pledGL_key_INTERNATIONAL8 = 142,
        pledGL_key_INTERNATIONAL9 = 143,
        pledGL_key_LANG1 = 144, 
        pledGL_key_LANG2 = 145, 
        pledGL_key_LANG3 = 146, 
        pledGL_key_LANG4 = 147, 
        pledGL_key_LANG5 = 148, 
        pledGL_key_LANG6 = 149, 
        pledGL_key_LANG7 = 150, 
        pledGL_key_LANG8 = 151, 
        pledGL_key_LANG9 = 152, 
        pledGL_key_ALTERASE = 153, 
        pledGL_key_SYSREQ = 154,
        pledGL_key_CANCEL = 155, 
        pledGL_key_CLEAR = 156,
        pledGL_key_PRIOR = 157,
        pledGL_key_RETURN2 = 158,
        pledGL_key_SEPARATOR = 159,
        pledGL_key_OUT = 160,
        pledGL_key_OPER = 161,
        pledGL_key_CLEARAGAIN = 162,
        pledGL_key_CRSEL = 163,
        pledGL_key_EXSEL = 164,
        pledGL_key_KP_00 = 176,
        pledGL_key_KP_000 = 177,
        pledGL_key_THOUSANDSSEPARATOR = 178,
        pledGL_key_DECIMALSEPARATOR = 179,
        pledGL_key_CURRENCYUNIT = 180,
        pledGL_key_CURRENCYSUBUNIT = 181,
        pledGL_key_KP_LEFTPAREN = 182,
        pledGL_key_KP_RIGHTPAREN = 183,
        pledGL_key_KP_LEFTBRACE = 184,
        pledGL_key_KP_RIGHTBRACE = 185,
        pledGL_key_KP_TAB = 186,
        pledGL_key_KP_BACKSPACE = 187,
        pledGL_key_KP_A = 188,
        pledGL_key_KP_B = 189,
        pledGL_key_KP_C = 190,
        pledGL_key_KP_D = 191,
        pledGL_key_KP_E = 192,
        pledGL_key_KP_F = 193,
        pledGL_key_KP_XOR = 194,
        pledGL_key_KP_POWER = 195,
        pledGL_key_KP_PERCENT = 196,
        pledGL_key_KP_LESS = 197,
        pledGL_key_KP_GREATER = 198,
        pledGL_key_KP_AMPERSAND = 199,
        pledGL_key_KP_DBLAMPERSAND = 200,
        pledGL_key_KP_VERTICALBAR = 201,
        pledGL_key_KP_DBLVERTICALBAR = 202,
        pledGL_key_KP_COLON = 203,
        pledGL_key_KP_HASH = 204,
        pledGL_key_KP_SPACE = 205,
        pledGL_key_KP_AT = 206,
        pledGL_key_KP_EXCLAM = 207,
        pledGL_key_KP_MEMSTORE = 208,
        pledGL_key_KP_MEMRECALL = 209,
        pledGL_key_KP_MEMCLEAR = 210,
        pledGL_key_KP_MEMADD = 211,
        pledGL_key_KP_MEMSUBTRACT = 212,
        pledGL_key_KP_MEMMULTIPLY = 213,
        pledGL_key_KP_MEMDIVIDE = 214,
        pledGL_key_KP_PLUSMINUS = 215,
        pledGL_key_KP_CLEAR = 216,
        pledGL_key_KP_CLEARENTRY = 217,
        pledGL_key_KP_BINARY = 218,
        pledGL_key_KP_OCTAL = 219,
        pledGL_key_KP_DECIMAL = 220,
        pledGL_key_KP_HEXADECIMAL = 221,
        pledGL_key_LCTRL = 224,
        pledGL_key_LSHIFT = 225,
        pledGL_key_LALT = 226,
        pledGL_key_LGUI = 227,
        pledGL_key_RCTRL = 228,
        pledGL_key_RSHIFT = 229,
        pledGL_key_RALT = 230,
        pledGL_key_RGUI = 231, 
        pledGL_key_MODE = 257,
        pledGL_key_AUDIONEXT = 258,
        pledGL_key_AUDIOPREV = 259,
        pledGL_key_AUDIOSTOP = 260,
        pledGL_key_AUDIOPLAY = 261,
        pledGL_key_AUDIOMUTE = 262,
        pledGL_key_MEDIASELECT = 263,
        pledGL_key_WWW = 264,       
        pledGL_key_MAIL = 265,
        pledGL_key_CALCULATOR = 266,  
        pledGL_key_COMPUTER = 267,
        pledGL_key_AC_SEARCH = 268,     
        pledGL_key_AC_HOME = 269,      
        pledGL_key_AC_BACK = 270,        
        pledGL_key_AC_FORWARD = 271,     
        pledGL_key_AC_STOP = 272,       
        pledGL_key_AC_REFRESH = 273,      
        pledGL_key_AC_BOOKMARKS = 274,   
        pledGL_key_BRIGHTNESSDOWN = 275,
        pledGL_key_BRIGHTNESSUP = 276,
        pledGL_key_DISPLAYSWITCH = 277, 
        pledGL_key_KBDILLUMTOGGLE = 278,
        pledGL_key_KBDILLUMDOWN = 279,
        pledGL_key_KBDILLUMUP = 280,
        pledGL_key_EJECT = 281,
        pledGL_key_SLEEP = 282,       
        pledGL_key_APP1 = 283,
        pledGL_key_APP2 = 284,
        pledGL_key_AUDIOREWIND = 285,
        pledGL_key_AUDIOFASTFORWARD = 286,
    };
};

#endif