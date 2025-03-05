#pragma once

#include <nds.h>
#include <nf_lib.h>

class Animation {
    public:
        void setSprite(int screen, int sprite) {screenID = screen; spriteID = sprite;};
        void setStartFrame(int frameID) {startFrame = frameID;};
        void setFrameCount(int numberOfFrames) {frameCount = numberOfFrames;};
        void setAnimationSpeed(int framesBeforeSwitch) {animationSpeed = framesBeforeSwitch;};
        void update();
        void reset();
    protected:
        int startFrame = 0;
        int currentFrame = 0;
        int frameCount = 0;
        int animationSpeed = 0;
        int elapsedFrames = 0;
        int screenID = -1;
        int spriteID = -1;
};