#pragma once

#include "GameObject.h"
#include "InputHandler.h"
#include "Animation.h"

enum class WalkAnimationState {
    IDLEUP,
    IDLEDOWN,
    IDLELEFT,
    IDLERIGHT,
    WALKUP,
    WALKDOWN,
    WALKRIGHT,
    WALKLEFT
};

class Player : public GameObject{
    public:
        void load() override;
        void unload() override;
        void handleInput(InputHandler &input);
        void update() override;
        void render(Camera& camera) override;
        bool movedThisFrame() {return moveDir.x != 0 || moveDir.y != 0;};
    protected:
        float moveSpeed = 1.5f;
        Vector2f moveDir;
        Vector2f velocity;
        int screenID;
        int spriteID;
        int palID;
        
        WalkAnimationState animationState = WalkAnimationState::IDLEDOWN;
        Animation* currentAnimation;
        Animation idleUp;
        Animation idleDown;
        Animation idleSide;
        Animation walkUp;
        Animation walkDown;
        Animation walkSide;

        void setupAnimations();
        void handleAnimation();
};