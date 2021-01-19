#pragma once
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#define CMDSIZE 256

extern int cmdNum; // �������
extern char commands[][CMDSIZE]; // �������
extern char promptSign; // ��ʾ��
extern char promptPath[]; // ��ʾ·��
extern struct passwd* user_info; // �û���Ϣ
extern char curPath[]; // ����·��
extern char username[]; // �û���
extern char hostname[]; // ������

extern const char CMD_CD[]; // cd
extern const char CMD_PWD[]; // pwd
extern const char CMD_LS[]; // ls
extern const char CMD_ECHO[]; // echo
extern const char CMD_CAT[]; // cat
extern const char CMD_EXIT[]; // exit
extern const char CMD_PIPE[]; // |
extern const char CMD_IN[]; // <
extern const char CMD_OUT[]; // >

//״̬��
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