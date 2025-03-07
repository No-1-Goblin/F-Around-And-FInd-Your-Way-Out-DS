#pragma once

#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "CollisionCircle.h"
#include "InputHandler.h"
#include "Vector2i.h"
#include <vector>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


class ButtonGrid {
    public:
        void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int startSoundId, int screen, Vector2f pos, Vector2i gridSize, int socket);
        void handleInput(InputHandler& input);
        void unload();
    protected:
        Vector2f position;
        Vector2i size;
        std::vector<CollisionCircle> collisionCircles;
        std::vector<bool> buttonStates;
        int sprRamId, plRamId, sprVramId, plVramId, startSprId, startSndId, screenId, sock;
};