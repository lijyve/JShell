#include "data.h"
int cmdNum = 0; // 命令个数
char commands[CMDSIZE][CMDSIZE] = { 0 }; // 命令
char promptSign = '$'; // 提示符
extern char promptPath[PATH_MAX] = "\0"; // 提示路径
extern struct passwd* user_info = NULL; // 用户信息
char curPath[PATH_MAX] = "\0"; // 工作路径
char username[CMDSIZE] = "\0"; // 用户名
char hostname[CMDSIZE] = "\0"; // 主机名