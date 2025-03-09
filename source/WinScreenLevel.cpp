#include "WinScreenLevel.h"
#include "IPSelectLevel.h"

WinScreenLevel::WinScreenLevel(LevelHandler* lvlHandler) : Level(lvlHandler) {

}

WinScreenLevel::~WinScreenLevel() {

}

void WinScreenLevel::load() {
    levelSize.x = 256;
    levelSize.y = 256;
    NF_LoadTiledBg("bg/YouWinBG", "YouWinBG", levelSize.x, levelSize.y);
    NF_CreateTiledBg(0, 3, "YouWinBG");
    NF_LoadRawSound("sound/youWinGoodJob", 0, 11025, 0);
    NF_PlayRawSound(0, 127, 64, false, 0);
}

void WinScreenLevel::unload() {
    NF_DeleteTiledBg(0, 3);
    NF_UnloadTiledBg("YouWinBG");
    NF_UnloadRawSound(0);
}

void WinScreenLevel::handleInput(InputHandler& input) {

}

void WinScreenLevel::update() {
    if (timer < 120) {
        timer++;
    } else {
        Level* ipSelectLevel = new IPSelectLevel(levelHandler);
        levelHandler->loadLevel(ipSelectLevel);
    }
}

void WinScreenLevel::render() {

}

void WinScreenLevel::postRender() {

}

void WinScreenLevel::handleNetwork() {

}