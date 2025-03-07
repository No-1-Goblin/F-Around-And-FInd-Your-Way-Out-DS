#include "CodeDisplay.h"

void CodeDisplay::load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos) {
    sprRamId = spriteRamId;
    plRamId = palRamId;
    sprVramId = spriteRamId;
    plVramId = palVramId;
    startSprId = startSpriteId;
    screenId = screen;
    position = pos;
    NF_LoadSpriteGfx("sprite/numbers", sprRamId, 32, 32);
    NF_LoadSpritePal("sprite/numbers", plRamId);
    NF_VramSpriteGfx(screenId, sprRamId, sprVramId, false);
    NF_VramSpritePal(screenId, plRamId, plVramId);
    for (int i = 0; i < 4; i++) {
        NF_CreateSprite(screenId, startSprId + i, sprVramId, plVramId, position.x + i * 24, position.y);
        NF_SpriteFrame(screenId, startSprId + i, 12);
    }
}

void CodeDisplay::render(std::string code) {
    for (int i = 0; i < 4; i++) {
        NF_SpriteFrame(screenId, startSprId + i, 12);
    }
    if (code.length() <= 4 && code.length() > 0) {
        for (int i = 0; i < code.length(); i++) {
            char number = code[i];
            NF_SpriteFrame(screenId, startSprId + i, std::atoi(&number));
        }
    }
}

void CodeDisplay::unload() {
    for (int i = startSprId; i < startSprId + 4; i++) {
        NF_DeleteSprite(screenId, i);
    }
    NF_UnloadSpriteGfx(sprRamId);
    NF_UnloadSpritePal(plRamId);
    NF_FreeSpriteGfx(screenId, sprVramId);
}