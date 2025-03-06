#include "ButtonGrid.h"

void ButtonGrid::load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int screen, Vector2f pos, Vector2i gridSize, int socket) {
    sprRamId = spriteRamId;
    plRamId = palRamId;
    sprVramId = spriteRamId;
    plVramId = palVramId;
    startSprId = startSpriteId;
    screenId = screen;
    position = pos;
    size = gridSize;
    sock = socket;
    NF_LoadSpriteGfx("sprite/Buttons", sprRamId, 32, 32);
    NF_LoadSpritePal("sprite/Buttons", plRamId);
    NF_VramSpriteGfx(screenId, sprRamId, sprVramId, false);
    NF_VramSpritePal(screenId, plRamId, plVramId);
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            NF_CreateSprite(screen, startSprId + i * size.x + j, sprVramId, plVramId, position.x + j * 32, position.y + i * 32);
            collisionCircles.push_back(CollisionCircle(Vector2f(position.x + j * 32 + 16, position.y + i * 32 + 16), 14));
            buttonStates.push_back(false);
        }
    }
}

void ButtonGrid::handleInput(InputHandler& input) {
    if (input.getKeysPressed() & KEY_TOUCH) {
        touchPosition touch;
        touchRead(&touch);
        Vector2f pos = Vector2f(touch.px, touch.py);
        for (int i = 0; i < collisionCircles.size(); i++) {
            if (collisionCircles[i].checkCollision(pos)) {
                buttonStates[i] = !buttonStates[i];
                NF_SpriteFrame(screenId, startSprId + i, buttonStates[i] ? 1 : 0);
                char sendByte = i;
                send(sock, &sendByte, sizeof(sendByte), NULL);
            }
        }
    }
}

void ButtonGrid::unload() {
    for (int i = startSprId; i < startSprId + collisionCircles.size(); i++) {
        NF_DeleteSprite(screenId, i);
    }
    collisionCircles.clear();
    buttonStates.clear();
    NF_UnloadSpriteGfx(sprRamId);
    NF_UnloadSpritePal(plRamId);
    NF_FreeSpriteGfx(screenId, sprVramId);
}