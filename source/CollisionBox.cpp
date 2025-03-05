#include "CollisionBox.h"

CollisionBox::CollisionBox(Vector2f topLeftPos, Vector2f boxSize) {
    topLeft = topLeftPos;
    size = boxSize;
}

CollisionBox::~CollisionBox() {

}

bool CollisionBox::checkCollision(Vector2f point) {
    if (point.x < topLeft.x)
        return false;
    if (point.y < topLeft.y)
        return false;
    if (point.x > topLeft.x + size.x)
        return false;
    if (point.y > topLeft.y + size.y)
        return false;
    return true;
}