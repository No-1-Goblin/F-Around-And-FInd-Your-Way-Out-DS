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

#include "InputHandler.h"
	
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	if(!Wifi_InitDefault(WFC_CONNECT)) {
        consoleDemoInit();
        iprintf("Failed to connect!");
        for (int i = 0; i < 64; i++) {
            swiWaitForVBlank();
            return 0;
        }
    }
    int sock;
    struct hostent* myhost = gethostbyname("192.168.162.8");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sain;
    sain.sin_family = AF_INET;
    sain.sin_port = htons(8080);
    sain.sin_addr.s_addr = *((unsigned long*)(myhost->h_addr_list[0]));
    connect(sock, (struct sockaddr*)&sain, sizeof(sain));
    char testbyte = 65;
    InputHandler inputHandler;
    while (true) {
        inputHandler.updateKeys();
        if (inputHandler.getKeysPressed() & KEY_A) {
            send(sock, &testbyte, sizeof(testbyte), NULL);
        }
        if (inputHandler.getKeysPressed() & KEY_START) {
            return 0;
        }
    }
}