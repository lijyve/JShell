#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/utsname.h>

#define CMD_MAX 256

using namespace std;

char last_path[PATH_MAX];
char input[CMD_MAX];

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
		// 显示提示
		printf("[JShell]%s@%s:%s%c ", user_info->pw_name, uname_data.nodename, path_prompt, prompt);
		fflush(stdout);
	}
}
void get_input()
{
	getchar();
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