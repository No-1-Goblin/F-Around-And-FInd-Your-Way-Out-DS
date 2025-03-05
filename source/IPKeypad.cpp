#include "IPKeypad.h"

void IPKeyPad::load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos) {
    sprRamId = spriteRamId;
    plRamId = palRamId;
    sprVramId = spriteRamId;
    plVramId = palVramId;
    startSprId = startSpriteId;
    position = pos;
    NF_LoadSpriteGfx("sprite/keypad", sprRamId, 32, 32);
    NF_LoadSpritePal("sprite/keypad", plRamId);
    NF_VramSpriteGfx(screenId, sprRamId, sprVramId, false);
    NF_VramSpritePal(screenId, plRamId, plVramId);
    NF_CreateSprite(screenId, startSprId, sprVramId, plVramId, position.x + 32, position.y + 64);
    for (int i = 1; i < 10; i++) {
        NF_CreateSprite(screenId, startSprId + i, sprVramId, plVramId, position.x + ((i - 1) % 3) * 32, position.y + ((i - 1) / 3) * 32);
    }
    NF_CreateSprite(screenId, startSprId + 10, sprVramId, plVramId, position.x, position.y + 64);
    NF_CreateSprite(screenId, startSprId + 11, sprVramId, plVramId, position.x + 64, position.y + 64);
}

void IPKeyPad::unload() {

}