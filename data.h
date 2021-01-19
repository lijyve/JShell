#pragma once
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#define CMDSIZE 256

extern int cmdNum;
extern char commands[][CMDSIZE];
extern char promptSign;
extern char promptPath[];
extern struct passwd* user_info;
extern char curPath[];
extern char username[];
extern char hostname[];