#pragma once

class Level;

class LevelHandler {
    public:
        Level* getCurrentLevel() {return currentLevel;};
        void setCurrentLevel(Level* newLevel) {currentLevel = newLevel;};
        void loadLevel(Level* newLevel) {levelToLoad = newLevel; swapLevel = true;};
        void handleLevelSwaps();
    protected:
        Level* currentLevel;
        Level* levelToLoad;
        bool swapLevel = false;
};