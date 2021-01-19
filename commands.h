#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "data.h"
#include "ls.h"

//判断命令是否存在
int isCmdExist(const char* cmd);
//分解输入的命令
int splitCmds(char argv[]);
//判断命令的类型
int commandsType();
//调用简单函数
int callSimpleCmd();

/*
* 以下是简单的命令
* 通过单个函数的调用可以实现功能
*/

//切换工作路径
int cd();
//打印当前路径
int pwd();
//字符串输出
int echo();
//获取文件内容
int cat();
//调用ls命令
int call_ls();