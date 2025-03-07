#pragma once

#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "CollisionBox.h"
#include "InputHandler.h"
#include <vector>
#include <string>

class IPKeyPad {
    public:
        void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int startSoundId, int screen, Vector2f pos);
        void handleInput(InputHandler& input);
        void unload();
        std::string getIP() {return ip;};
    protected:
        Vector2f position;
        std::vector<CollisionBox> collisionBoxes;
        int sprRamId, plRamId, sprVramId, plVramId, startSprId, startSndId, screenId;
        std::string ip = "";
};