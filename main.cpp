#include <stdio.h>
#include <string.h>
#include "prompt.h"
#include "commands.h"

int main()
{
	char argv[BUFSIZ] = "\0";
	while (1)
	{
		printPrompt();
		//获取输入
		fgets(argv, BUFSIZ, stdin);
		argv[strlen(argv) - 1] = '\0';
		//清空输入缓冲区
		fflush(stdin);

		if (splitCmds(argv) == ERROR_COMMAND)
		{
			printf("\033[40;31m[ERROR] \033[0m");
			printf("error command\n");
		}
		else if (cmdNum > 0)
		{
			//for (int i = 0; i < cmdNum; i++)
			//{
			//	printf("%s\n", commands[i]);
			//}
			if (commandsType() == SIMPLE)
			{
				int result = callSimpleCmd();
				//退出JShell
				if (result == EXIT)
					return 0;
				//错误处理
				if (result != RIGHT)
				{
					printf("\033[40;31m[ERROR] \033[0m");
					switch (result)
					{
					case ERROR_WRONG_PARAMETER:
						printf("parameter error\n");
						break;
					case ERROR_MISS_PARAMETER:
						printf("miss parameter\n");
						break;
					case ERROR_TOO_MANY_PARAMETER:
						printf("too many parameter\n");
						break;
					case ERROR_PATH:
						printf("path is wrong\n");
						break;
					default:
						printf("unknown error\n");
						break;
					}
				}
			}
		}
	}
	return 0;
}