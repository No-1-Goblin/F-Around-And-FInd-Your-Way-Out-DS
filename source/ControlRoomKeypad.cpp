#include "ControlRoomKeypad.h"


void ControlRoomKeypad::load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int startSoundId, int screen, Vector2f pos, int socket) {
    sprRamId = spriteRamId;
    plRamId = palRamId;
    sprVramId = spriteRamId;
    plVramId = palVramId;
    startSprId = startSpriteId;
    startSndId = startSoundId;
    screenId = screen;
    position = pos;
    sock = socket;
    NF_LoadSpriteGfx("sprite/keypad", sprRamId, 32, 32);
    NF_LoadSpritePal("sprite/keypad", plRamId);
    NF_VramSpriteGfx(screenId, sprRamId, sprVramId, false);
    NF_VramSpritePal(screenId, plRamId, plVramId);
    NF_CreateSprite(screenId, startSprId, sprVramId, plVramId, position.x + 32, position.y + 96);
    collisionBoxes.push_back(CollisionBox(Vector2f(position.x + 32, position.y + 96), Vector2f(32, 32)));
    for (int i = 1; i < 10; i++) {
        NF_CreateSprite(screenId, startSprId + i, sprVramId, plVramId, position.x + ((i - 1) % 3) * 32, position.y + ((i - 1) / 3) * 32);
        NF_SpriteFrame(screenId, startSprId + i, i);
        collisionBoxes.push_back(CollisionBox(Vector2f(position.x + ((i - 1) % 3) * 32, position.y + ((i - 1) / 3) * 32), Vector2f(32, 32)));
    }
    NF_CreateSprite(screenId, startSprId + 10, sprVramId, plVramId, position.x, position.y + 96);
    NF_SpriteFrame(screenId, startSprId + 10, 12);
    NF_CreateSprite(screenId, startSprId + 11, sprVramId, plVramId, position.x + 64, position.y + 96);
    NF_SpriteFrame(screenId, startSprId + 11, 13);
    for (int i = 0; i < 7; i++) {
        std::string fileName ="sound/KeypadBeep" + std::to_string(i + 1);
        NF_LoadRawSound(fileName.data(), startSndId + i, 11025, 0);
    }
}

void ControlRoomKeypad::handleInput(InputHandler &input) {
    if (input.getKeysPressed() & KEY_TOUCH) {
        touchPosition touch;
        touchRead(&touch);
        Vector2f pos = Vector2f(touch.px, touch.py);
        for (int i = 0; i < collisionBoxes.size(); i++) {
            if (collisionBoxes[i].checkCollision(pos)) {
                char sendByte = i + 100;
                //send(sock, &sendByte, sizeof(sendByte), NULL);
                int keypadSound = rand() % 7;
                NF_PlayRawSound(startSndId + keypadSound, 127, 64, false, 0);
            }
        }
    }
}

void ControlRoomKeypad::unload() {
    for (int i = startSprId; i < startSprId + collisionBoxes.size() + 2; i++) {
        NF_DeleteSprite(screenId, i);
    }
    collisionBoxes.clear();
    NF_UnloadSpriteGfx(sprRamId);
    NF_UnloadSpritePal(plRamId);
    NF_FreeSpriteGfx(screenId, sprVramId);
    for (int i = 0; i < 7; i++) {
        NF_UnloadRawSound(startSndId + i);
    }
}