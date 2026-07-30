#pragma once
#include <unistd.h>

int initializeIPCConnection();
int sendIPCMessage(const char* msg, char buffer[256]);
int watchPayload();
