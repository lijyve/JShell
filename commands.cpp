#include "commands.h"

int isCmdExist(const char* cmd)
{

}
int splitCmds(char argv[])
{
	cmdNum = 0;
	int argv_len = strlen(argv);
	int cmd_len = 0;
	for (int i = 0, j = 0; i < argv_len;)
	{
		if (argv[i] == '\"') // 双引号之间的内容一个命令或参数
		{
			do
			{
				j++;
			} while (argv[j] != '\"' && argv[j] != '\0');
			if (argv[j] == '\0')
				return ERROR_COMMAND;
			strncpy(commands[cmdNum], argv + i + 1, j - i - 1);
			commands[cmdNum][j - i - 1] = '\0';
			cmdNum++;
			j++;
			if (argv[j] != ' ' && argv[j] != '\0')
				return ERROR_COMMAND;
			while (argv[j] == ' ' && argv[j] != '\0')
				j++;
			i = j;
		}
		else if (argv[j] == ' ' || argv[j] == '\0') // 以空格分割命令和参数
		{
			strncpy(commands[cmdNum], argv + i, j - i);
			commands[cmdNum][j - i] = '\0';
			cmdNum++;
			while (argv[j] == ' ' && argv[j] != '\0')
				j++;
			i = j;
		}
		else
			j++;
	}
	return RIGHT;
}
int commandsType()
{
	for (int i = 0; i < cmdNum; i++)
	{
		//有管道符或重定向
		if (!strcmp(commands[i], CMD_PIPE) || !strcmp(commands[i], CMD_IN) || !strcmp(commands[i], CMD_OUT))
			return COMPLEX;
	}
	return SIMPLE;
}
int callSimpleCmd()
{
	if (strcmp(commands[0], CMD_CD) == 0)
		return cd();
	else if (strcmp(commands[0], CMD_PWD) == 0)
		return pwd();
	else if (strcmp(commands[0], CMD_LS) == 0)
		return call_ls();
	else if (strcmp(commands[0], CMD_ECHO) == 0)
		return echo();
	else if (strcmp(commands[0], CMD_EXIT) == 0)
		return EXIT;
}
int cd()
{
	if (cmdNum > 2)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else if (!strcmp(commands[1], "-h") || !strcmp(commands[1], "--help"))
	{
		printf("\033[40;31m[Usage]\033[0m\n");
		printf("\t\033[40;32m cd [path]\033[0m");
		printf("\tswitch directory to [path].\n");
	}
	else
	{
		if (chdir(commands[1]))
			return ERROR_PATH;
		getcwd(curPath, PATH_MAX);
	}
	return RIGHT;
}
int pwd()
{
	if (cmdNum > 1)
		return ERROR_TOO_MANY_PARAMETER;
	printf("%s\n", curPath);
	return RIGHT;
}
int call_ls()
{
	return ls();
}
int echo()
{
	if (cmdNum > 2)
		return ERROR_TOO_MANY_PARAMETER;
	else if (cmdNum < 2)
		return ERROR_MISS_PARAMETER;
	else
	{
		printf("%s\n", commands[1]);
		return RIGHT;
	}
}
int cat(const char* filename)
{

}