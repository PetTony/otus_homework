#pragma once

#include <ostream>
#include <cstdint>

struct Color
{
    Color(){}
    Color(uint8_t red, uint8_t green, uint8_t blue)
        : _red(red), _green(green), _blue(blue) {};

    void EditColor(uint8_t red, uint8_t green, uint8_t blue)
    {
        _red = red;
        _green = green;
        _blue = blue;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Color &color);
private:
    uint8_t _red{};
    uint8_t _green{};
    uint8_t _blue{};
};

std::ostream& operator<<(std::ostream& stream, const Color &color)
{
    stream << "Color{"
       << static_cast<int>(color._red) << ", "
       << static_cast<int>(color._green) << ", "
       << static_cast<int>(color._blue) << "}";

    return stream;
}