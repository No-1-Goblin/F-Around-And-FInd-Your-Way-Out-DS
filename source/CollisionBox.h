#pragma once

#include "Vector2f.h"

class CollisionBox {
    public:
        CollisionBox(Vector2f topLeftPos, Vector2f boxSize);
        ~CollisionBox();
        void setPosition(Vector2f newPos) {topLeft = newPos;};
        Vector2f getPosition() {return topLeft;};
        void setSize(Vector2f newSize) {size = newSize;};
        Vector2f getSize() {return size;};
        bool checkCollision(Vector2f point);
    protected:
        Vector2f topLeft;
        Vector2f size;
};