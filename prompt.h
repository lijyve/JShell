#pragma once

#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "data.h"

//��ȡ�û���
void getUserName();
//��ȡ������
void getHostName();
//��ȡ��ʾ��
void getPromptSign();
//��ȡ��ʾ·��
void getPromptPath();
//��ӡ��ʾ
void printPrompt();