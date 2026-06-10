#include <iostream>
#include <filesystem>
#include <string>
#include <fcntl.h>
#include <unistd.h>

// Thank you, Stack Overflow!
unsigned short repeatLoop = 10;

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

void CPsihTgnisUllits()
{
  displayText("\n?CP siht gnisu llits LoL");
}

/* This will be added in later, right now it's broken.'
void loremIpsum()
{
  char ipsumText[]= "Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos."

  for(int i = 0; i < (sizeof(ipsumText) / sizeof(ipsumText[0])) {

  }

}
*/

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
  displayText("\nFun fact about AI: it sucks ass. So I'll fire up ChatGPT now to make you suffer.");
  while(repeatLoop--) {
    system("xdg-open https://chatgpt.com");
  }
  sleep(5);
  displayText("Is this too little AI for you?");
  sleep(5);
  displayText("\nYo did you hear about the-\nHEADPHONE WARNING IN 5 SECONDS");
  system("mpv --no-video https://www.youtube.com/watch?v=vPlFkyXY6L0 > /dev/null");
  displayText("\nYou're a twerp for not liking Miku!\nWhat about the Kagamine's?");
  system("mpv --no-video https://www.youtube.com/watch?v=oEkGC2HV7rc > /dev/null");
  displayText("\nOkay how can I please you now?\n");
}
