#include "TestLevel.h"
#include <string>

void TestLevel::load() {
    levelSize.x = 512;
    levelSize.y = 256;
    NF_LoadTiledBg("bg/TestMap", "TestMap", levelSize.x, levelSize.y);
    NF_CreateTiledBg(0, 3, "TestMap");
    player.load();
    camera.setMinPosition(Vector2i(0, 0));
    camera.setMaxPosition(levelSize);
    camera.setTrackingObject(&player);
    NF_LoadSpriteGfx("sprite/ball", 1, 32, 32);
    NF_LoadSpritePal("sprite/ball", 1);
    NF_VramSpriteGfx(0, 1, 1, false);
    NF_VramSpritePal(0, 1, 1);
    NF_CreateSprite(0, 1, 1, 1, 300, 12);
    networkInit();
}

void TestLevel::unload() {
    NF_DeleteTiledBg(0, 3);
    player.unload();
}

void TestLevel::handleInput(InputHandler &input) {
    // if (input.getKeysThisFrame() & KEY_RIGHT) {
    //     bgScrollX++;
    // }
    // if (input.getKeysThisFrame() & KEY_LEFT) {
    //     bgScrollX--;
    // }
    // if (input.getKeysThisFrame() & KEY_UP) {
    //     bgScrollY--;
    // }
    // if (input.getKeysThisFrame() & KEY_DOWN) {
    //     bgScrollY++;
    // }
    // if (bgScrollX < 0) {
    //     bgScrollX = 0;
    // }
    // if (bgScrollY < 0) {
    //     bgScrollY = 0;
    // }
    // if (bgScrollX > levelSize.x - 256) {
    //     bgScrollX = levelSize.x - 256;
    // }
    // if (bgScrollY > levelSize.y - 192) {
    //     bgScrollY = levelSize.y - 192;
    // }
    player.handleInput(input);
}

void TestLevel::update() {
    player.update();
    camera.update();
    networkUpdate();
}

void TestLevel::render() {
    player.render(camera);
    camera.renderSprite(0, 1, Vector2f(300, 12), Vector2f(32, 32));
}

void TestLevel::postRender() {
    //NF_ScrollBg(0, 3, camera.getPosition().x, camera.getPosition().y);
    camera.renderBg(0, 3);
}

void TestLevel::networkInit() {
    struct hostent* myhost = gethostbyname("nds.no1gobl.in");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sain.sin_family = AF_INET;
    sain.sin_port = htons(8080);
    sain.sin_addr.s_addr = *((unsigned long*)(myhost->h_addr_list[0]));
    connect(sock, (struct sockaddr*)&sain, sizeof(sain));
    
}

void TestLevel::networkUpdate() {
    if (!player.movedThisFrame())
        return;
    char buffer[8] = {0};
    Vector2i pos = player.getScreenPosition();
    std::string x = std::to_string(pos.x);
    std::string y = std::to_string(pos.y);
    while (x.length() < 3) {
        x = "0" + x;
    }
    while (y.length() < 3) {
        y = "0" + y;
    }
    for (int i = 0; i < 3; i++) {
        buffer[i] = x[i];
        buffer[5 + i] = y[i];
    }
    buffer[3] = ',';
    buffer[4] = ' ';
    send(sock, buffer, sizeof(buffer), 0);
}