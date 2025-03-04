#include "InputHandler.h"

void InputHandler::updateKeys() {
    scanKeys();
    keysLastFrame = keysThisFrame;
    keysThisFrame = keysCurrent();
}

int InputHandler::getKeysLastFrame() {
    return keysLastFrame;
}

int InputHandler::getKeysThisFrame() {
    return keysThisFrame;
}

int InputHandler::getKeysPressed() {
    return keysThisFrame & ~keysLastFrame;
}