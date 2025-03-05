@echo off
cls

set FILEPATH=%1
set FILEPATH=%FILEPATH:~0,-4%
echo %FILEPATH%

set FILENAME=%~nx1
set FILENAME=%FILENAME:~0,-4%
echo %FILENAME%

set GRIT="C:\Program Files\grit\grit.exe"
%GRIT% %1 -ftb -fh! -gT! -gt -gB8 -m!

ren %FILENAME%.img.bin %FILENAME%.img
ren %FILENAME%.pal.bin %FILENAME%.pal

move %FILENAME%.img ../../nitrofiles/sprite
move %FILENAME%.pal ../../nitrofiles/sprite

pause