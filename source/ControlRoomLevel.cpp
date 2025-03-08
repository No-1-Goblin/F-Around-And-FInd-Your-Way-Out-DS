#include "ControlRoomLevel.h"
#include "IPSelectLevel.h"

ControlRoomLevel::ControlRoomLevel(LevelHandler* lvlHandler) : Level(lvlHandler) {

}

ControlRoomLevel::~ControlRoomLevel() {

}

void ControlRoomLevel::load() {
    levelSize.x = 256;
    levelSize.y = 256;
    NF_LoadTiledBg("bg/TopScreenBG", "TopScreenBG", levelSize.x, levelSize.y);
    NF_CreateTiledBg(0, 3, "TopScreenBG");
    buttonGrid.load(0, 0, 0, 0, 0, 0, 1, Vector2f(0, 32), Vector2i(5, 4), sock);
    keypad.load(1, 1, 1, 1, 20, 1, 1, Vector2f(160, 32), sock);
    codeDisplay.load(2, 2, 2, 2, 32, 1, Vector2f(160, 8));
}

void ControlRoomLevel::handleInput(InputHandler &input) {
    // char testbyte = 65;
    // if (input.getKeysPressed() & KEY_UP) {
    //     testbyte = 0;
    //     if (sock != -1)
    //         send(sock, &testbyte, sizeof(testbyte), NULL);
    // }
    // if (input.getKeysPressed() & KEY_DOWN) {
    //     testbyte = 1;
    //     if (sock != -1)
    //         send(sock, &testbyte, sizeof(testbyte), NULL);
    // }
    // if (input.getKeysPressed() & KEY_LEFT) {
    //     testbyte = 2;
    //     if (sock != -1)
    //         send(sock, &testbyte, sizeof(testbyte), NULL);
    // }
    // if (input.getKeysPressed() & KEY_RIGHT) {
    //     testbyte = 3;
    //     if (sock != -1)
    //         send(sock, &testbyte, sizeof(testbyte), NULL);
    // }
    if (input.getKeysPressed() & KEY_SELECT) {
        Level* controlRoomLevel = new ControlRoomLevel(levelHandler);
        controlRoomLevel->passNetworkInfo(sock);
        levelHandler->loadLevel(controlRoomLevel);
    }
    buttonGrid.handleInput(input);
    keypad.handleInput(input);
}

void ControlRoomLevel::update() {

}

void ControlRoomLevel::render() {
    codeDisplay.render(keypad.getCode());
}

void ControlRoomLevel::postRender() {

}

void ControlRoomLevel::handleNetwork() {
    if (sock != -1) {
        int i = 1;
        ioctl(sock, FIONBIO, &i);
        char receivedData;
        while (recv(sock, &receivedData, 1, NULL) == 1) {
            switch (receivedData) {
                case char(255):
                    Level* ipSelectLevel = new IPSelectLevel(levelHandler);
                    levelHandler->loadLevel(ipSelectLevel);
                    break;
                case char(254):
                    Level* controlRoomLevel = new ControlRoomLevel(levelHandler);
                    controlRoomLevel->passNetworkInfo(sock);
                    levelHandler->loadLevel(controlRoomLevel);
                    break;
                default:
                    break;
            }
        }
        i = 0;
        ioctl(sock, FIONBIO, &i);
    }
}

void ControlRoomLevel::unload() {
    NF_DeleteTiledBg(0, 3);
    NF_UnloadTiledBg("TopScreenBG");
    buttonGrid.unload();
    keypad.unload();
    codeDisplay.unload();
}