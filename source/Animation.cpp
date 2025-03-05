#include "Animation.h"

void Animation::update() {
    if (frameCount <= 1 || animationSpeed == 0) {
        return;
    }
    elapsedFrames++;
    if (elapsedFrames >= animationSpeed) {
        elapsedFrames = 0;
        currentFrame++;
        if (currentFrame >= startFrame + frameCount) {
            currentFrame = startFrame;
        }
        if (screenID != -1 && spriteID != -1) {
            NF_SpriteFrame(screenID, spriteID, currentFrame);
        }
    }
}

void Animation::reset() {
    elapsedFrames = 0;
    currentFrame = startFrame;
    if (screenID != -1 && spriteID != -1) {
        NF_SpriteFrame(screenID, spriteID, currentFrame);
    }
}