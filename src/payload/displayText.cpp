#include <filesystem>
#include <unistd.h>
#include <string>
#include <fcntl.h>
#include "displayText.h"

#define IPSUMSIZE = 439

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

void loremIpsum()
{
  const char ipsumText[IPSUMSIZE] = "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.";

  // Sooooooooo, sorry flumpsi but I hardcoded this because it's simple.
  for(int i = 0; i < IPSUMSIZE; i++)
  {
    std::cout << ipsumText[i] << std::flush;
    usleep(33333);
  }
}
