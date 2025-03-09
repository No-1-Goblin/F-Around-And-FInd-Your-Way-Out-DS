#include "HealthDisplay.h"

void HealthDisplay::load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos) {
    sprRamId = spriteRamId;
    plRamId = palRamId;
    sprVramId = spriteRamId;
    plVramId = palVramId;
    startSprId = startSpriteId;
    screenId = screen;
    position = pos;
    NF_LoadSpriteGfx("sprite/hpNums", sprRamId, 32, 32);
    NF_LoadSpritePal("sprite/hpNums", plRamId);
    NF_VramSpriteGfx(screenId, sprRamId, sprVramId, false);
    NF_VramSpritePal(screenId, plRamId, plVramId);
    for (int i = 0; i < 3; i++) {
        NF_CreateSprite(screenId, startSprId + i, sprVramId, plVramId, position.x + 32 + i * 32, position.y);
        NF_SpriteFrame(screenId, startSprId + i, 12);
    }
    NF_CreateSprite(screenId, startSprId + 3, sprVramId, plVramId, position.x, position.y);
    NF_SpriteFrame(screenId, startSprId + 3, 12);
}

void HealthDisplay::render(std::string health) {
    while (health.length() < 3) {
        health = "0" + health;
    }
    for (int i = 0; i < 4; i++) {
        NF_SpriteFrame(screenId, startSprId + i, 11);
    }
    if (health.length() <= 4 && health.length() > 0) {
        for (int i = 0; i < health.length(); i++) {
            char number = health[i];
            NF_SpriteFrame(screenId, startSprId + i, std::atoi(&number));
        }
    }
}

void HealthDisplay::unload() {
    for (int i = startSprId; i < startSprId + 4; i++) {
        NF_DeleteSprite(screenId, i);
    }
    NF_UnloadSpriteGfx(sprRamId);
    NF_UnloadSpritePal(plRamId);
    NF_FreeSpriteGfx(screenId, sprVramId);
}