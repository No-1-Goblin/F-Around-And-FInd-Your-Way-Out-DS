#include "NFInitialisation.h"

void initGFX() {
    
    // NitroFS initialisation
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");

    // Initialise 2D engine
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);

    // Initialise sprite and background buffers
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
    NF_InitSpriteBuffers();
    NF_InitSpriteSys(0);
    NF_InitSpriteSys(1);
}