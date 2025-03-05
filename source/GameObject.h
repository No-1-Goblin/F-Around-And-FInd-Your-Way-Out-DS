#pragma once

#include "Vector2f.h"
#include "Vector2i.h"
#include "Camera.h"

class GameObject {
    public:
        virtual void load();
        virtual void unload();
        virtual void update();
        virtual void render(Camera &camera);
        void setPosition(Vector2f pos) {position = pos;};
        Vector2f getPosition() {return position;};
        Vector2i getScreenPosition() {return Vector2i(position.x, position.y);};
        Vector2f getCentre() {return Vector2f(position.x + size.x / 2.f, position.y + size.y / 2.f);};
    protected:
        Vector2f position;
        Vector2f size;
};