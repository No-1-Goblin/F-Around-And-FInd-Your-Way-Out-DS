#include "Player.h"

void Player::load() {
    size = Vector2f(64, 64);
    screenID = 0;
    spriteID = 0;
    palID = 0;
    NF_LoadSpriteGfx("sprite/player_walk_anims", spriteID, size.x, size.y);
    NF_LoadSpritePal("sprite/player_walk_anims", palID);
    NF_VramSpriteGfx(screenID, spriteID, spriteID, true);
    NF_VramSpritePal(screenID, palID, palID);
    NF_CreateSprite(screenID, spriteID, spriteID, palID, position.x, position.y);
    setupAnimations();
    currentAnimation = &idleDown;
    currentAnimation->reset();
}

void Player::unload() {
    NF_DeleteSprite(0, 0);
    NF_FreeSpriteGfx(0, 0);
    NF_UnloadSpritePal(0);
    NF_UnloadSpriteGfx(0);
}

void Player::handleInput(InputHandler &input) {
    moveDir = Vector2f(0, 0);
    if (input.getKeysThisFrame() & KEY_RIGHT) {
        moveDir.x++;
    }
    if (input.getKeysThisFrame() & KEY_LEFT) {
        moveDir.x--;
    }
    if (input.getKeysThisFrame() & KEY_UP) {
        moveDir.y--;
    }
    if (input.getKeysThisFrame() & KEY_DOWN) {
        moveDir.y++;
    }
    moveDir.normalise();
}

void Player::update() {
    velocity = moveDir * moveSpeed;
    position = position + velocity;
}

void Player::render(Camera& camera) {
    handleAnimation();
    camera.renderSprite(screenID, spriteID, position, size);
}

void Player::setupAnimations() {
    int animSpeed = 6;
    idleUp.setStartFrame(0);
    idleUp.reset();
    idleDown.setStartFrame(9);
    idleDown.reset();
    idleSide.setStartFrame(18);
    idleSide.reset();
    walkUp.setStartFrame(0);
    walkUp.setFrameCount(9);
    walkUp.setAnimationSpeed(animSpeed);
    walkUp.reset();
    walkDown.setStartFrame(9);
    walkDown.setFrameCount(9);
    walkDown.setAnimationSpeed(animSpeed);
    walkDown.reset();
    walkSide.setStartFrame(18);
    walkSide.setFrameCount(9);
    walkSide.setAnimationSpeed(animSpeed);
    walkSide.reset();

    idleUp.setSprite(screenID, spriteID);
    idleDown.setSprite(screenID, spriteID);
    idleSide.setSprite(screenID, spriteID);
    walkUp.setSprite(screenID, spriteID);
    walkDown.setSprite(screenID, spriteID);
    walkSide.setSprite(screenID, spriteID);
}

void Player::handleAnimation() {
    WalkAnimationState desiredState;
    if (moveDir.x == 0) {
        if (moveDir.y > 0) {
            desiredState = WalkAnimationState::WALKDOWN;
        } else if (moveDir.y < 0) {
            desiredState = WalkAnimationState::WALKUP;
        } else {
            switch(animationState) {
                case WalkAnimationState::WALKDOWN:
                    desiredState = WalkAnimationState::IDLEDOWN;
                    break;
                case WalkAnimationState::WALKUP:
                    desiredState = WalkAnimationState::IDLEUP;
                    break;
                case WalkAnimationState::WALKLEFT:
                    desiredState = WalkAnimationState::IDLELEFT;
                    break;
                case WalkAnimationState::WALKRIGHT:
                    desiredState = WalkAnimationState::IDLERIGHT;
                    break;
                default:
                    desiredState = animationState;
                    break;
            }
        }
    } else if (moveDir.x > 0) {
        desiredState = WalkAnimationState::WALKRIGHT;
    } else {
        desiredState = WalkAnimationState::WALKLEFT;
    }
    if (desiredState != animationState) {
        animationState = desiredState;
        switch (animationState) {
            case WalkAnimationState::IDLEUP:
                currentAnimation = &idleUp;
                NF_HflipSprite(screenID, spriteID, false);
                break;
            case WalkAnimationState::IDLEDOWN:
                currentAnimation = &idleDown;
                NF_HflipSprite(screenID, spriteID, false);
                break;
            case WalkAnimationState::IDLELEFT:
                currentAnimation = &idleSide;
                NF_HflipSprite(screenID, spriteID, true);
                break;
            case WalkAnimationState::IDLERIGHT:
                currentAnimation = &idleSide;
                NF_HflipSprite(screenID, spriteID, false);
                break;
            case WalkAnimationState::WALKUP:
                currentAnimation = &walkUp;
                NF_HflipSprite(screenID, spriteID, false);
                break;
            case WalkAnimationState::WALKDOWN:
                currentAnimation = &walkDown;
                NF_HflipSprite(screenID, spriteID, false);
                break;
            case WalkAnimationState::WALKLEFT:
                currentAnimation = &walkSide;
                NF_HflipSprite(screenID, spriteID, true);
                break;
            case WalkAnimationState::WALKRIGHT:
                currentAnimation = &walkSide;
                NF_HflipSprite(screenID, spriteID, false);
                break;
        }
        currentAnimation->reset();
    }
    currentAnimation->update();
}