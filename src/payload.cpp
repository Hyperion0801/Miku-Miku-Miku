/*

Copyright (C) 1995-2026 Hyperion0801.

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

void stillUsingThisPC()
{
  displayText("lol still using this PC?");
}

void CPsihTgnisUllits()
{
  displayText("\n?CP siht gnisu llits lol");
}

// This is for the previous dev, please explain what the code does
// even if it has not been implemented yet, so that other people can fix/implement it!

void loremIpsum()
{
  const char ipsumText[] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";
  // sizeof calculation here is sketchy, please update!
  // Hyperion here, no thanks I'm not experienced enough.'
  for (int i = 0; i < (sizeof(ipsumText) / sizeof(ipsumText[0] - 1)); i++) {
    std::cout << ipsumText[i] << std::flush;
    usleep(200000);
  }
}

int main()
{
  sleep(3);
  stillUsingThisPC();
  sleep(2);
  displayText("\nSystem Unstable!!");
  sleep(1);
  displayText("\nOh no! Kernel Panic incoming!!!");
  sleep(1);
  displayText("\n( i am lying :) )");
  sleep(2);
  CPsihTgnisUllits();
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
  loremIpsum();
  sleep(5);
  displayText("\nYo did you hear about the-\nHEADPHONE WARNING IN 5 SECONDS");
  system("mpv --no-video https://www.youtube.com/watch?v=vPlFkyXY6L0 > /dev/null");
  displayText("\nYou're a twerp for not liking Miku!\nWhat about the Kagamine's?");
  system("mpv --no-video https://www.youtube.com/watch?v=oEkGC2HV7rc > /dev/null");
  displayText("\nOkay how can I please you now?\n");
}
