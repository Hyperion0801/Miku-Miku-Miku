#include <unistd.h>
#include "displayText.h"
#include "macOS.h"

short repeatLoop = 0;

void macOS()
{
    repeatLoop = 8;
    while(repeatLoop--)
    {
        // DOWNLOADING...
        displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1");
        usleep(666666);
        displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1.");
        usleep(666666);
        displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1..");
        usleep(666666);
        displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1...");
        usleep(666666);
    }

    // UNPACKING...
    displayText("\033[2J\033[1;1HUnpacking macOS 27 Beta 1");
    usleep(666666);
    displayText("\033[2J\033[1;1HUnpacking macOS 27 Beta 1.");
    usleep(666666);
    displayText("\033[2J\033[1;1HUnpacking macOS 27 Beta 1..");
    usleep(200000);

    repeatLoop = 3;
    while(repeatLoop--)
    {
        // INSTALLING...
        displayText("\033[2J\033[1;1HInstalling macOS 27 Beta 1");
        usleep(666666);
        displayText("\033[2J\033[1;1HInstalling macOS 27 Beta 1.");
        usleep(666666);
        displayText("\033[2J\033[1;1HInstalling macOS 27 Beta 1..");
        usleep(666666);
        displayText("\033[2J\033[1;1HInstalling macOS 27 Beta 1...");
        usleep(666666);
    }
    system("cat /dev/urandom > /miku/F59FEDE0");

}