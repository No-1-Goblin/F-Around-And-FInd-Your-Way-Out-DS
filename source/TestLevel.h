#pragma once
#include "Level.h"
#include "Player.h"
#include "Camera.h"


#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdio.h>
#include <string.h>

class TestLevel : public Level {
    public:
        void load() override;
        void unload() override;
        void handleInput(InputHandler &input) override;
        void update() override;
        void render() override;
        void postRender() override;
    protected:
        // int bgScrollX = 0;
        // int bgScrollY = 0;
        Player player;
        Camera camera;

        void networkInit();
        void networkUpdate();
        int sock;
        struct sockaddr_in sain;
};