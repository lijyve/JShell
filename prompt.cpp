#include "prompt.h"

//��ȡ�û���
void getUserName()
{
	user_info = getpwuid(getuid());
	strcpy(username, user_info->pw_name);
}
//��ȡ������
void getHostName()
{
	gethostname(hostname, CMDSIZE);
}
//��ȡ��ʾ��
void getPromptSign()
{
	//�޸�root�û�����ʾ��Ϊ'#'
	if (getuid() == 0)
		promptSign = '#';
}
//��ȡ��ʾ·��
void getPromptPath()
{
	getcwd(curPath, PATH_MAX);
	int pw_dir_len = strlen(user_info->pw_dir);
	if (strncmp(user_info->pw_dir, curPath, pw_dir_len))
		strcpy(promptPath, curPath);
	else
	{
		promptPath[0] = '~';
		strcpy(promptPath + 1, curPath + pw_dir_len);
	}
}
//��ӡ��ʾ
void printPrompt()
{
	getUserName();
	getHostName();
	getPromptSign();
	getPromptPath();

	printf("\033[40;32m[JShell]%s@%s\033[0m", username, hostname);
	printf(":");
	printf("\033[40;34m%s\033[0m", promptPath);
	printf("%c ", promptSign);
	fflush(stdout);
}