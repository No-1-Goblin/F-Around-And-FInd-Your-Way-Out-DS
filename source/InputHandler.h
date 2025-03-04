#pragma once
#include <nds.h>
#include <nf_lib.h>

class InputHandler {
    public:
        void updateKeys();
        int getKeysThisFrame();
        int getKeysLastFrame();
        int getKeysPressed();
    protected:
        int keysThisFrame = 0;
        int keysLastFrame = 0;
};