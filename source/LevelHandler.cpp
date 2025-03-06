#include "LevelHandler.h"
#include "Level.h"

void LevelHandler::handleLevelSwaps() {
    if (!levelToLoad)
        return;
    if (currentLevel) {
        currentLevel->unload();
        delete currentLevel;
    }
    currentLevel = levelToLoad;
    levelToLoad = nullptr;
    currentLevel->load();
}