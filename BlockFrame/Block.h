#pragma once

namespace BlockFrame {
    enum class Color {
        Black = 0,
        Blue = 1,
        Green = 2,
        Cyan = 3,
        Red = 4,
        Magenta = 5,
        Yellow = 6,
        White = 7,
        Gray = 8,
        LightBlue = 9,
        LightGreen = 10,
        LightCyan = 11,
        LightRed = 12,
        LightMagenta = 13,
        LightYellow = 14,
        BrightWhite = 15
    };

    class Block
    {
    public:
        char c;
        Color foreGround;
        Color backGounrd;
        Block(char c = ' ', Color foreGround = Color::White, Color backGounrd = Color::Black)
        : foreGround(foreGround), backGounrd(backGounrd){
            if (c < 0 || c > 0xff)
                throw "Block not a ASCII";
            this->c = c;
        }

        Block& operator=(const Block& other) {
            if (this != &other) {
                c = other.c;
            }
            return *this;
        }
    };
}