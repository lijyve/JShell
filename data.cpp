#include "data.h"
int cmdNum = 0; // �������
char commands[CMDSIZE][CMDSIZE] = { 0 }; // �������
char promptSign = '$'; // ��ʾ��
extern char promptPath[PATH_MAX] = "\0"; // ��ʾ·��
extern struct passwd* user_info = NULL; // �û���Ϣ
char curPath[PATH_MAX] = "\0"; // ����·��
char username[CMDSIZE] = "\0"; // �û���
char hostname[CMDSIZE] = "\0"; // ������

const char CMD_CD[] = "cd"; // cd
const char CMD_PWD[] = "pwd"; // pwd
const char CMD_LS[] = "ls"; // ls
const char CMD_ECHO[] = "echo"; // echo
const char CMD_CAT[] = "cat"; // cat
const char CMD_EXIT[] = "exit"; // exit
const char CMD_PIPE[] = "|"; // |
const char CMD_IN[] = "<"; // <
const char CMD_OUT[] = ">"; // >