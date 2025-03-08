#pragma once

#include "Level.h"
#include "IPKeypad.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>

class IPSelectLevel : public Level {
    public:
        IPSelectLevel(LevelHandler* levelHandler);
        ~IPSelectLevel();
        void load() override;
        void unload() override;
        void handleInput(InputHandler &input) override;
        void update() override;
        void render() override;
        void postRender() override;
        void handleNetwork() override;
    protected:
        void networkInit();
        void networkUpdate();
        void saveIP();
        IPKeyPad keypad;
};