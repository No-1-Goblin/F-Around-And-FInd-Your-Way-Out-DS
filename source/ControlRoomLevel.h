#pragma once

#include "Level.h"
#include "IPKeypad.h"

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
    protected:
    
};