// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: NightFox & Co., 2009-2011
//
// NightFox's Lib Template
// http://www.nightfoxandco.com

#include <stdio.h>

#include <nds.h>
#include <dswifi9.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>

#include <nf_lib.h>
#include <fat.h>

#include "NFInitialisation.h"
#include "InputHandler.h"
#include "Level.h"
#include "LevelHandler.h"
#include "IPSelectLevel.h"
#include "ControlRoomLevel.h"

int main(void) {
    if(!Wifi_InitDefault(WFC_CONNECT)) {
        consoleDemoInit();
        iprintf("Failed to connect!");
        for (int i = 0; i < 64; i++) {
            swiWaitForVBlank();
            return 0;
        }
    }
	initGFX();
    soundEnable();
    NF_InitRawSoundBuffers();
    InputHandler inputHandler;
    LevelHandler levelHandler;
    levelHandler.setCurrentLevel(new IPSelectLevel(&levelHandler));
    levelHandler.getCurrentLevel()->load();
    while (1) {
        inputHandler.updateKeys();
        if (levelHandler.getCurrentLevel()) {
            levelHandler.getCurrentLevel()->handleInput(inputHandler);
            levelHandler.getCurrentLevel()->update();
            levelHandler.getCurrentLevel()->render();
        }
        NF_SpriteOamSet(0);
        NF_SpriteOamSet(1);
        swiWaitForVBlank();
        if (levelHandler.getCurrentLevel()) {
            levelHandler.getCurrentLevel()->postRender();
        }
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
        if (inputHandler.getKeysThisFrame() & KEY_SELECT && inputHandler.getKeysThisFrame() & KEY_L && inputHandler.getKeysThisFrame() & KEY_R)
            return 0;
        levelHandler.handleLevelSwaps();
    }
	return 0;
}