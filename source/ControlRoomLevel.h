#pragma once

#include "Level.h"
#include "ButtonGrid.h"
#include "ControlRoomKeypad.h"
#include "CodeDisplay.h"
#include "HealthDisplay.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>

class ControlRoomLevel : public Level {
    public:
        ControlRoomLevel(LevelHandler* levelHandler);
        ~ControlRoomLevel();
        void load() override;
        void unload() override;
        void handleInput(InputHandler &input) override;
        void update() override;
        void render() override;
        void postRender() override;
        void handleNetwork() override;
    protected:
        ButtonGrid buttonGrid;
        ControlRoomKeypad keypad;
        CodeDisplay codeDisplay;
        HealthDisplay healthDisplay;
        uint8 health = 100;
};