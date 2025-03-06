#pragma once
#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "InputHandler.h"
#include "Vector2i.h"
#include "LevelHandler.h"

class Level {
    public:
        Level(LevelHandler* levelHandler);
        ~Level();
        virtual void load();
        virtual void handleInput(InputHandler &input);
        virtual void update();
        virtual void render();
        virtual void postRender();
        virtual void unload();
        void passNetworkInfo(int socket) {sock = socket;};
    protected:
        Vector2i levelSize;
        int sock = -1;
        LevelHandler* levelHandler;
};