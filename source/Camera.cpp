#include "Camera.h"
#include "GameObject.h"

void Camera::update() {
    if (tracking != nullptr) {
        position = tracking->getCentre() - Vector2f(128, 96);
        if (position.x < minPosition.x) {
            position.x = minPosition.x;
        } else if (position.x > maxPosition.x - 256) {
            position.x = maxPosition.x - 256;
        }
        if (position.y < minPosition.y) {
            position.y = minPosition.y;
        } else if (position.y > maxPosition.y - 192) {
            position.y = maxPosition.y - 192;
        }
    }
}

void Camera::renderBg(int screenID, int layer) {
    NF_ScrollBg(screenID, layer, position.x, position.y);
}

void Camera::renderSprite(int screenID, int spriteID, Vector2f spritePosition, Vector2f size) {
    bool isVisible = false;
    // Top Left
    if (spritePosition.x >= position.x && spritePosition.x <= position.x + 256 && spritePosition.y >= position.y && spritePosition.y <= position.y + 192) {
        isVisible = true;
    }
    // Top Right
    else if (spritePosition.x + size.x >= position.x && spritePosition.x + size.x <= position.x + 256 && spritePosition.y >= position.y && spritePosition.y <= position.y + 192) {
        isVisible = true;
    }
    // Bottom Left
    else if (spritePosition.x >= position.x && spritePosition.x <= position.x + 256 && spritePosition.y + size.y >= position.y && spritePosition.y + size.y <= position.y + 192) {
        isVisible = true;
    }
    // Bottom Right
    else if (spritePosition.x + size.x >= position.x && spritePosition.x + size.x <= position.x + 256 && spritePosition.y + size.y >= position.y && spritePosition.y + size.y <= position.y + 192) {
        isVisible = true;
    }
    if (isVisible) {
        NF_ShowSprite(screenID, spriteID, true);
        NF_MoveSprite(screenID, spriteID, spritePosition.x - position.x, spritePosition.y - position.y);
    } else {
        NF_ShowSprite(screenID, spriteID, false);
    }
}