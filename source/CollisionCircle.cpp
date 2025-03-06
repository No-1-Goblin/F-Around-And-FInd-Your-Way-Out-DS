#include "CollisionCircle.h"

CollisionCircle::CollisionCircle(Vector2f centrePoint, float radiusLength) {
    centre = centrePoint;
    radius = radiusLength;
}

CollisionCircle::~CollisionCircle() {

}

bool CollisionCircle::checkCollision(Vector2f point) {
    Vector2f displacement = point - centre;
    float distance = displacement.magnitude();
    if (distance > radius)
        return false;
    return true;
}