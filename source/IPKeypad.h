#pragma once

#include "CollisionBox.h"
#include <vector>

class IPKeyPad {
    public:
        void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int screen, Vector2f pos);
        void unload();
    protected:
        Vector2f position;
        std::vector<CollisionBox> collisionBoxes;
};