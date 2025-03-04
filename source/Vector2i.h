#pragma once

class Vector2i {
    public:
        int x = 0;
        int y = 0;
        Vector2i() {x = 0; y = 0;};
        Vector2i(int newX, int newY) {x = newX; y = newY;};
        Vector2i operator+(Vector2i const& obj) {return Vector2i(x + obj.x, y + obj.y);};
        Vector2i operator-(Vector2i const& obj) {return Vector2i(x - obj.x, y - obj.y);};
        Vector2i operator*(Vector2i const& obj) {return Vector2i(x * obj.x, y * obj.y);};
        Vector2i operator/(Vector2i const& obj) {return Vector2i(x / obj.x, y / obj.y);};
};