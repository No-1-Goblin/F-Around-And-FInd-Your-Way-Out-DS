#pragma once

#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "CollisionBox.h"
#include "InputHandler.h"
#include <vector>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class ControlRoomKeypad {
    public:
    void load(int spriteRamId, int palRamId, int spriteVramId, int palVramId, int startSpriteId, int startSoundId, int screen, Vector2f pos, int socket);
    void handleInput(InputHandler& input);
    void unload();
    std::string getCode() {return code;};
    protected:
    Vector2f position;
    std::vector<CollisionBox> collisionBoxes;
    int sprRamId, plRamId, sprVramId, plVramId, startSprId, startSndId, screenId, sock;
    std::string code = "";
};