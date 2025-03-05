#include "ControlRoomLevel.h"

void ControlRoomLevel::load() {
    levelSize.x = 256;
    levelSize.y = 256;
    NF_LoadTiledBg("bg/TopScreenBG", "TopScreenBG", levelSize.x, levelSize.y);
    //NF_CreateTiledBg(0, 3, "TopScreenBG");
    // networkInit();
    // NF_LoadSpriteGfx("sprite/ball", 0, 32, 32);
    // NF_LoadSpritePal("sprite/ball", 0);
    // NF_VramSpriteGfx(1, 0, 0, false);
    // NF_VramSpritePal(1, 0, 0);
    //NF_CreateSprite(1, 0, 0, 0, 64, 64);
    // Initialize text system
    NF_InitTextSys(0);

    // Load font file
    NF_LoadTextFont("fnt/default", "IP", 256, 256, 0);

    // Create text layer
    NF_CreateTextLayer(0, 0, 0, "IP");
    keypad.load(1, 1, 1, 1, 0, 1, Vector2f(80, 32));
}

void ControlRoomLevel::handleInput(InputHandler &input) {
    keypad.handleInput(input);
    char testbyte = 65;
    if (input.getKeysPressed() & KEY_A) {
        if (sock != -1)
            send(sock, &testbyte, sizeof(testbyte), NULL);
    }
    if (input.getKeysPressed() & KEY_START) {
        if (sock == -1)
            networkInit();
    }
}

void ControlRoomLevel::update() {

}

void ControlRoomLevel::render() {
    char buffer[19] = {'A'};
    std::string text = "IP: ";
    text += keypad.getIP();
    for (int i = 0; i < text.length(); i++) {
        buffer[i] = text[i];
    }
    NF_WriteText(0, 0, 14, 12, buffer);
    NF_UpdateTextLayers();  
}

void ControlRoomLevel::postRender() {

}

void ControlRoomLevel::unload() {
    NF_DeleteTiledBg(0, 3);
    NF_UnloadTiledBg("TopScreenBG");
    NF_DeleteSprite(0, 0);
    NF_UnloadSpritePal(0);
    NF_UnloadSpriteGfx(0);
    keypad.unload();
}

void ControlRoomLevel::networkInit() {
    struct hostent* myhost = gethostbyname(keypad.getIP().data());
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sain.sin_family = AF_INET;
    sain.sin_port = htons(25565);
    sain.sin_addr.s_addr = *((unsigned long*)(myhost->h_addr_list[0]));
    connect(sock, (struct sockaddr*)&sain, sizeof(sain));
}