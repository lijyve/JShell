#pragma once
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#define CMDSIZE 256

extern int cmdNum; // 命令个数
extern char commands[][CMDSIZE]; // 命令个数
extern char promptSign; // 提示符
extern char promptPath[]; // 提示路径
extern struct passwd* user_info; // 用户信息
extern char curPath[]; // 工作路径
extern char username[]; // 用户名
extern char hostname[]; // 主机名

extern const char CMD_CD[]; // cd
extern const char CMD_PWD[]; // pwd
extern const char CMD_LS[]; // ls
extern const char CMD_ECHO[]; // echo
extern const char CMD_CAT[]; // cat
extern const char CMD_EXIT[]; // exit
extern const char CMD_PIPE[]; // |
extern const char CMD_IN[]; // <
extern const char CMD_OUT[]; // >

//状态码
enum
{
	EXIT,
	RIGHT,
	ERROR_COMMAND,
	//ERROR_CD,
	//ERROR_PWD,
	//ERROR_LS,
	//ERROR_ECHO,
	//ERROR_CAT,
	//ERROR_EXIT,
	ERROR_WRONG_PARAMETER,
	ERROR_MISS_PARAMETER,
	ERROR_TOO_MANY_PARAMETER,
	SIMPLE,
	COMPLEX,
	ERROR_PATH,
};