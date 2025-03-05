#pragma once
#include <nds.h>
#include <nf_lib.h>
#include <filesystem.h>
#include "InputHandler.h"
#include "Vector2i.h"

class Level {
    public:
        virtual void load();
        virtual void handleInput(InputHandler &input);
        virtual void update();
        virtual void render();
        virtual void postRender();
        virtual void unload();
    protected:
        Vector2i levelSize;
};