#include <iostream>
#include <filesystem>
#include <string>
#include <fcntl.h>
#include <unistd.h>

void displayText(std::string msg)
{
  for (const auto e : std::filesystem::directory_iterator("/dev")) {
    std::string name = e.path();
    if (!(!name.rfind("tty", 0))) {
      continue;
    }

    int fd = open(e.path().c_str(), O_WRONLY | O_NONBLOCK);
    write(fd, msg.c_str(), msg.size());
    close(fd);
  }

  for (const auto e : std::filesystem::directory_iterator("/dev/pts")) {
    std::string name = e.path().filename().string();
    if (name == "ptmx") {
      continue;
    }
    int fd = open(e.path().c_str(), O_WRONLY | O_NONBLOCK);

    write(fd, msg.c_str(), msg.size());
    close(fd);
  }
}

void stillUsingThisPC()
{
  displayText("LoL still using this PC?");
}

void CPsihTgnisUllits() {
  displayText("?CP siht gnisu llits LoL");
}

int main()
{
  sleep(3);
  stillUsingThisPC();
  sleep(20);
  displayText("System Unstable!!");
  sleep(15);
  displayText("Oh no! Kernel Panic incoming!!!");
  sleep(1);
  displayText("( i am lying :) )");
}
