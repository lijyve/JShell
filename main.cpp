#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/utsname.h>

#define CMD_MAX 128

using namespace std;

char last_path[PATH_MAX];
string commands[CMD_MAX]; // 分解后的命令
int cmds_count = 0; // 分解得到的命令个数

// 打印提示
void print_prompt()
{
	char path[PATH_MAX] = "\0"; // 当前工作目录
	char path_prompt[PATH_MAX] = "\0"; // 提示的当前工作目录
	char prompt = '$'; // 提示符
	uid_t uid; // user id
	struct passwd* user_info; // name, dir and etc.
	struct utsname uname_data; // nodename

	// 获得当前工作目录
	getcwd(path, PATH_MAX);
	strcpy(last_path, path);
	// 根据用户uid确定提示符
	uid = getuid();
	if (uid == 0)
	{
		prompt = '$';
	}
	// 获得当前用户的用户名、目录
	user_info = getpwuid(uid);
	// 修改要显示的工作目录,将绝对路径修改成有~的路径
	int pw_dir_len = strlen(user_info->pw_dir);
	if (strncmp(user_info->pw_dir, path, pw_dir_len))
	{
		strcpy(path_prompt, path);
	}
	else
	{
		path_prompt[0] = '~';
		strcpy(path_prompt + 1, path + pw_dir_len);
	}
	// 获取用户名和主机名
	if (uname(&uname_data) < 0)
	{
		perror("uname error: ");
	}
	else
	{
		// 显示彩色提示
		printf("\033[40;32m[JShell]%s@%s\033[0m", user_info->pw_name, uname_data.nodename);
		printf(":");
		printf("\033[40;34m%s\033[0m", path_prompt);
		printf("%c ", prompt);
		//显示普通提示
		//printf("[JShell]%s@%s:%s%c ", user_info->pw_name, uname_data.nodename, path_prompt, prompt);
		fflush(stdout);
	}
}
// 获得输入并处理
void get_input()
{
	cmds_count = 0;
	int cmd_len = 0;
	char cmd[CMD_MAX + 1] = "\0";
	char ch = '\0';
	while (1)
	{
		ch = getchar();
		if (ch == ' ')
		{
			cmd[cmd_len++] = '\0';
			if (cmd_len > CMD_MAX)
			{
				printf("[ERROR]: Command is too long\n");
				break;
			}
			commands[cmds_count++] = cmd;
			if (cmds_count > CMD_MAX)
			{
				printf("[ERROR]: Command is too long\n");
				break;
			}
			cmd_len = 0;
		}
		else if (ch == '\"')
		{
			while ((ch = getchar()) != '\"')
			{
				cmd[cmd_len++] = ch;
			}
		}
		else if (ch == '\n')
		{
			cmd[cmd_len++] = '\0';
			if (cmd_len > CMD_MAX)
			{
				printf("[ERROR]: Command is too long\n");
				break;
			}
			commands[cmds_count++] = cmd;
			if (cmds_count > CMD_MAX)
			{
				printf("[ERROR]: Command is too long\n");
				break;
			}
			break;
		}
		else
		{
			cmd[cmd_len++] = ch;
		}
	}
	fflush(stdin);
}
int main()
{
	while (1)
	{
		print_prompt();
		get_input();
	}
	return 0;
}