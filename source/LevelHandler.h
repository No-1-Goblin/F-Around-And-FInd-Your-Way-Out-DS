#pragma once

class Level;

class LevelHandler {
    public:
        Level* getCurrentLevel() {return currentLevel;};
        Level* setCurrentLevel(Level* newLevel) {currentLevel = newLevel;};
        Level* loadLevel(Level* newLevel) {levelToLoad = newLevel;};
        void handleLevelSwaps();
    protected:
        Level* currentLevel;
        Level* levelToLoad;
};