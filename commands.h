#pragma once

#include <stdio.h>
#include "data.h"

//判断命令是否存在
int isCmdExist(const char* cmd);
//分解输入的命令
int splitCmds(char argv[]);
//判断输入命令是否不含管道和重定向
int isSimpleCmd();
//调用简单函数
int callSimpleCmd();

/*
* 以下是简单的命令
* 通过单个函数的调用可以实现功能
*/

//切换工作路径
int cd(const char* path);
//打印当前路径
int pwd();
//列出目录下所有文件和子目录
int ls();
//字符串输出
int echo(const char* str);
//获取文件内容
int cat(const char* filename);
//退出JShell
int exit();