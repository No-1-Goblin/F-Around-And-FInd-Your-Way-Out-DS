#pragma once

#include "Vector2f.h"

class CollisionCircle {
    public:
        CollisionCircle(Vector2f centrePos, float radiusLength);
        ~CollisionCircle();
        void setCentre(Vector2f newCentre) {centre = newCentre;};
        Vector2f getCentre() {return centre;};
        void setRadius(float newRadius) {radius = newRadius;};
        float getRadius() {return radius;};
        bool checkCollision(Vector2f point);
    protected:
        Vector2f centre;
        float radius;
};