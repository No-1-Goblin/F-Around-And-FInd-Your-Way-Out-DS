#pragma once

#include <math.h>

class Vector2f {
    public:
        float x;
        float y;
        Vector2f() {x = 0; y = 0;};
        Vector2f(int newX, int newY) {x = newX; y = newY;};
        void normalise() {float magnitude = std::sqrtf(x * x + y * y); if(magnitude == 0) magnitude = 1; x /= magnitude; y /= magnitude;};
        Vector2f operator+(Vector2f const& obj) {return Vector2f(x + obj.x, y + obj.y);};
        Vector2f operator-(Vector2f const& obj) {return Vector2f(x - obj.x, y - obj.y);};
        Vector2f operator*(Vector2f const& obj) {return Vector2f(x * obj.x, y * obj.y);};
        Vector2f operator*(float const& obj) {return Vector2f(x * obj, y * obj);};
        Vector2f operator/(Vector2f const& obj) {return Vector2f(x / obj.x, y / obj.y);};
};