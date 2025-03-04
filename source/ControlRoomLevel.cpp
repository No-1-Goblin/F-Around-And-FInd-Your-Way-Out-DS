#include "ControlRoomLevel.h"

void ControlRoomLevel::load() {
    networkInit();
    NF_LoadSpriteGfx("sprite/ball", 0, 32, 32);
    NF_LoadSpritePal("sprite/ball", 0);
    NF_VramSpriteGfx(1, 0, 0, false);
    NF_VramSpritePal(1, 0, 0);
    NF_CreateSprite(1, 0, 0, 0, 64, 64);
}

void ControlRoomLevel::handleInput(InputHandler &input) {
    char testbyte = 65;
    if (input.getKeysPressed() & KEY_A) {
        send(sock, &testbyte, sizeof(testbyte), NULL);
    }
}

void ControlRoomLevel::update() {

}

void ControlRoomLevel::render() {

}

void ControlRoomLevel::postRender() {

}

void ControlRoomLevel::networkInit() {
    struct hostent* myhost = gethostbyname("192.168.162.8");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sain.sin_family = AF_INET;
    sain.sin_port = htons(8080);
    sain.sin_addr.s_addr = *((unsigned long*)(myhost->h_addr_list[0]));
    connect(sock, (struct sockaddr*)&sain, sizeof(sain));
}