#include "ControlRoomLevel.h"

ControlRoomLevel::ControlRoomLevel(LevelHandler* lvlHandler) : Level(lvlHandler) {

}

ControlRoomLevel::~ControlRoomLevel() {

}

void ControlRoomLevel::load() {
    levelSize.x = 256;
    levelSize.y = 256;
    NF_LoadTiledBg("bg/TopScreenBG", "TopScreenBG", levelSize.x, levelSize.y);
    NF_CreateTiledBg(0, 3, "TopScreenBG");
}

void ControlRoomLevel::handleInput(InputHandler &input) {
    char testbyte = 65;
    if (input.getKeysPressed() & KEY_UP) {
        testbyte = 0;
        if (sock != -1)
            send(sock, &testbyte, sizeof(testbyte), NULL);
    }
    if (input.getKeysPressed() & KEY_DOWN) {
        testbyte = 1;
        if (sock != -1)
            send(sock, &testbyte, sizeof(testbyte), NULL);
    }
    if (input.getKeysPressed() & KEY_LEFT) {
        testbyte = 2;
        if (sock != -1)
            send(sock, &testbyte, sizeof(testbyte), NULL);
    }
    if (input.getKeysPressed() & KEY_RIGHT) {
        testbyte = 3;
        if (sock != -1)
            send(sock, &testbyte, sizeof(testbyte), NULL);
    }
}

void ControlRoomLevel::update() {

}

void ControlRoomLevel::render() {
    
}

void ControlRoomLevel::postRender() {

}

void ControlRoomLevel::unload() {
    NF_DeleteTiledBg(0, 3);
    NF_UnloadTiledBg("TopScreenBG");
}