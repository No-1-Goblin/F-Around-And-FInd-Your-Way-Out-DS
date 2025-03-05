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

#include "NFInitialisation.h"
#include "InputHandler.h"
#include "Level.h"
#include "TestLevel.h"

void getHttp(char* url);

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
    InputHandler inputHandler;
    Level* currentLevel = new TestLevel();
    currentLevel->load();
    while (1) {
        inputHandler.updateKeys();
        if (currentLevel) {
            currentLevel->handleInput(inputHandler);
            currentLevel->update();
            currentLevel->render();
        }
        NF_SpriteOamSet(0);
        NF_SpriteOamSet(1);
        swiWaitForVBlank();
        if (currentLevel) {
            currentLevel->postRender();
        }
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
        if (inputHandler.getKeysPressed() & KEY_START)
            break;
    }
	return 0;
}