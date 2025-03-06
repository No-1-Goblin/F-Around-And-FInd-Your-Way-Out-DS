#include "LevelHandler.h"
#include "Level.h"

void LevelHandler::handleLevelSwaps() {
    if (!swapLevel)
        return;
    if (currentLevel != nullptr) {
        currentLevel->unload();
        delete currentLevel;
    }
    currentLevel = levelToLoad;
    levelToLoad = nullptr;
    currentLevel->load();
    swapLevel = false;
}