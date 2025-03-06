#pragma once

#include <math.h>

class Vector2f {
    public:
        float x;
        float y;
        Vector2f() {x = 0; y = 0;};
        Vector2f(float newX, float newY) {x = newX; y = newY;};
        void normalise() {float mag = magnitude(); if(mag == 0) mag = 1; x /= mag; y /= mag;};
        float magnitude() {return std::sqrtf(x * x + y * y);};
        Vector2f operator+(Vector2f const& obj) {return Vector2f(x + obj.x, y + obj.y);};
        Vector2f operator-(Vector2f const& obj) {return Vector2f(x - obj.x, y - obj.y);};
        Vector2f operator*(Vector2f const& obj) {return Vector2f(x * obj.x, y * obj.y);};
        Vector2f operator*(float const& obj) {return Vector2f(x * obj, y * obj);};
        Vector2f operator/(Vector2f const& obj) {return Vector2f(x / obj.x, y / obj.y);};
};