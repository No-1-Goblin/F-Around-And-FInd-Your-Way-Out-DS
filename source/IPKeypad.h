#pragma once

#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "CollisionBox.h"
#include <vector>

class IPKeyPad {
    public:
        void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos);
        void unload();
    protected:
        Vector2f position;
        std::vector<CollisionBox> collisionBoxes;
        int sprRamId, plRamId, sprVramId, plVramId, startSprId, screenId;
};