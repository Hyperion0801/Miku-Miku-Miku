#pragma once
#include <unistd.h>

int sock_fd;
pid_t serverPid;

int initializeIPCConnection();
int sendIPCMessage(const char* msg, char buffer[256]);
int watchPayload();
