#pragma once

#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

void getUserName();
void getHostName();
void getPromptSign();
void getPromptPath();
void printPrompt();