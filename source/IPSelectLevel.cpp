#include "IPSelectLevel.h"
#include "ControlRoomLevel.h"

IPSelectLevel::IPSelectLevel(LevelHandler* lvlHandler) : Level(lvlHandler) {

}

IPSelectLevel::~IPSelectLevel() {

}

void IPSelectLevel::load() {
    levelSize.x = 256;
    levelSize.y = 256;
    // Initialize text system
    NF_InitTextSys(0);

    // Load font file
    NF_LoadTextFont("fnt/default", "IP", 256, 256, 0);

    // Create text layer
    NF_CreateTextLayer(0, 0, 0, "IP");
    keypad.load(1, 1, 1, 1, 0, 1, Vector2f(80, 32));
}

void IPSelectLevel::handleInput(InputHandler& input) {
    keypad.handleInput(input);
    
    if (input.getKeysPressed() & KEY_START) {
        if (sock == -1) {
            //networkInit();
            Level* controlRoomLevel = new ControlRoomLevel(levelHandler);
            controlRoomLevel->passNetworkInfo(sock);
            levelHandler->loadLevel(controlRoomLevel);
        }
    }
}

void IPSelectLevel::update() {

}

void IPSelectLevel::render() {
    std::string text = "IP: ";
    text += keypad.getIP();
    while (text.length() < 20) {
        text += " ";
    }
    NF_WriteText(0, 0, 0, 12, text.data());
    NF_UpdateTextLayers();  

}

void IPSelectLevel::postRender() {

}

void IPSelectLevel::unload() {
    NF_DeleteTextLayer(0, 0);
    NF_UnloadTextFont("IP");
    keypad.unload();
    NF_ResetSpriteBuffers();
    // Might wanna remove this line
    NF_InitTiledBgSys(0);
}

void IPSelectLevel::networkInit() {
    struct hostent* myhost = gethostbyname(keypad.getIP().data());
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sain;
    sain.sin_family = AF_INET;
    sain.sin_port = htons(8080);
    sain.sin_addr.s_addr = *((unsigned long*)(myhost->h_addr_list[0]));
    connect(sock, (struct sockaddr*)&sain, sizeof(sain));
}