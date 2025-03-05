#pragma once

#include <nds.h>
#include <nf_lib.h>
#include "Vector2f.h"
#include "Vector2i.h"

class GameObject;

class Camera {
    public:
        void setTrackingObject(GameObject* gameObject) {tracking = gameObject;};
        void setMinPosition(Vector2i min) {minPosition = min;};
        void setMaxPosition(Vector2i max) {maxPosition = max;};
        Vector2f getPosition() {return position;};
        void setPosition(Vector2f newPosition) {position = newPosition;};
        void update();
        void renderBg(int screenID, int layer);
        void renderSprite(int screenID, int spriteID, Vector2f spritePosition, Vector2f size);
    protected:
        GameObject* tracking;
        Vector2f position;
        Vector2i minPosition;
        Vector2i maxPosition;
};