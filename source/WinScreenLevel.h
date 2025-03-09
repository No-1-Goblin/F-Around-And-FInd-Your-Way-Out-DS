#pragma once

#include "Level.h"

class WinScreenLevel : public Level {
    public:
        WinScreenLevel(LevelHandler* levelHandler);
        ~WinScreenLevel();
        void load() override;
        void unload() override;
        void handleInput(InputHandler &input) override;
        void update() override;
        void render() override;
        void postRender() override;
        void handleNetwork() override;
    protected:
        int timer = 0;
};