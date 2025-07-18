#include "ControlRoomLevel.h"
#include "IPSelectLevel.h"
#include "WinScreenLevel.h"

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
    healthDisplay.load(3, 3, 3, 3, 36, 0, Vector2f(128, 160));
    NF_LoadRawSound("sound/Goodbye", 31, 11025, 0);
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
    // if (input.getKeysPressed() & KEY_SELECT) {
    //     Level* controlRoomLevel = new ControlRoomLevel(levelHandler);
    //     controlRoomLevel->passNetworkInfo(sock);
    //     levelHandler->loadLevel(controlRoomLevel);
    // }
    // if (input.getKeysPressed() & KEY_START) {
    //     Level* winScreenLevel = new WinScreenLevel(levelHandler);
    //     close(sock);
    //     levelHandler->loadLevel(winScreenLevel);
    // }
    buttonGrid.handleInput(input);
    keypad.handleInput(input);
}

void ControlRoomLevel::update() {

}

void ControlRoomLevel::render() {
    codeDisplay.render(keypad.getCode());
    healthDisplay.render(std::to_string(health));
}

void ControlRoomLevel::postRender() {

}

void ControlRoomLevel::handleNetwork() {
    if (sock != -1) {
        int i = 1;
        ioctl(sock, FIONBIO, &i);
        uint8 receivedData;
        while (recv(sock, &receivedData, 1, NULL) == 1) {
            switch (receivedData) {
                case 255: {
                    NF_PlayRawSound(31, 127, 64, false, 0);
                    for (int timer = 0; timer < 120; timer++) {
                        swiWaitForVBlank();
                    }
                    Level* ipSelectLevel = new IPSelectLevel(levelHandler);
                    levelHandler->loadLevel(ipSelectLevel);
                    break;
                }
                case 254: {
                    Level* controlRoomLevel = new ControlRoomLevel(levelHandler);
                    controlRoomLevel->passNetworkInfo(sock);
                    levelHandler->loadLevel(controlRoomLevel);
                    break;
                }
                case 253: {
                    Level* winScreenLevel = new WinScreenLevel(levelHandler);
                    close(sock);
                    levelHandler->loadLevel(winScreenLevel);
                    break;
                }
                default: {
                    if (receivedData <= 100) {
                        health = receivedData;
                    }
                }
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
    healthDisplay.unload();
    NF_UnloadRawSound(31);
}