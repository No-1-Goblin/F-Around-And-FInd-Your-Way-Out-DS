@echo off
cls

set FILEPATH=%1
set FILEPATH=%FILEPATH:~0,-4%
echo %FILEPATH%

set FILENAME=%~nx1
set FILENAME=%FILENAME:~0,-4%
echo %FILENAME%

set GRIT="C:\Program Files\grit\grit.exe"
%GRIT% %1 -g -gTFF00FF -gB8 -m -mRtf -mLs -p -ftb -fh!

ren %FILENAME%.img.bin %FILENAME%.img
ren %FILENAME%.map.bin %FILENAME%.map
ren %FILENAME%.pal.bin %FILENAME%.pal

move %FILENAME%.img ../../nitrofiles/bg
move %FILENAME%.map ../../nitrofiles/bg
move %FILENAME%.pal ../../nitrofiles/bg

pause