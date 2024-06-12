//
// Created by lyates27 on 7/05/2024.
//

#ifndef COLOR_H
#define COLOR_H

#include <Wire.h>

struct Color
{
    static constexpr Color red() { return {255, 0, 0}; }
    static constexpr Color green() { return {0, 255, 0}; }
    static constexpr Color blue() { return {0, 0, 255}; }
    static constexpr Color black() { return {0, 0, 0}; }
    static constexpr Color white() { return {255, 255, 255}; }

    constexpr Color(const int r, const int g, const int b)
        : r(r), g(g), b(b)
    {}

    explicit Color(const int rgb) : r((rgb >> 16) & 0xFF), g((rgb >> 8) & 0xFF), b(rgb & 0xFF) {}

    int r;
    int g;
    int b;

    Color()
        : r(0), g(0), b(0)
    {}

    void read()
    {
        r = Wire.read();
        g = Wire.read();
        b = Wire.read();
    }

    explicit operator int () const
    {
        return (r << 16) | (g << 8) | b;
    }

    explicit operator String () const
    {
        const String red = "R: " + String(r) + " ";
        const String green = "G: " + String(g) + " ";
        const String blue = "B: " + String(b);
        return red + green + blue;
    }
};

#endif //COLOR_H
