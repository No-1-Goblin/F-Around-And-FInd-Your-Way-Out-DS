#pragma once

#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "CollisionBox.h"
#include "InputHandler.h"
#include <vector>
#include <string>

class HealthDisplay {
    public:
        void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos);
        void render(std::string health);
        void unload();
    protected:
    Vector2f position;
    int sprRamId, plRamId, sprVramId, plVramId, startSprId, screenId;
};