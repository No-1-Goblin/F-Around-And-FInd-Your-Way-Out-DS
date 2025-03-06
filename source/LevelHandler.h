#pragma once

class Level;

class LevelHandler {
    public:
        Level* getCurrentLevel() {return currentLevel;};
        void setCurrentLevel(Level* newLevel) {currentLevel = newLevel;};
        void loadLevel(Level* newLevel) {levelToLoad = newLevel;};
        void handleLevelSwaps();
    protected:
        Level* currentLevel;
        Level* levelToLoad;
};