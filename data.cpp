#include "data.h"
int cmdNum = 0; // �������
char commands[CMDSIZE][CMDSIZE] = { 0 }; // ����
char promptSign = '$'; // ��ʾ��
extern char promptPath[PATH_MAX] = "\0"; // ��ʾ·��
extern struct passwd* user_info = NULL; // �û���Ϣ
char curPath[PATH_MAX] = "\0"; // ����·��
char username[CMDSIZE] = "\0"; // �û���
char hostname[CMDSIZE] = "\0"; // ������