#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "data.h"
#include "ls.h"

//�ж������Ƿ����
int isCmdExist(const char* cmd);
//�ֽ����������
int splitCmds(char argv[]);
//�ж����������
int commandsType();
//���ü򵥺���
int callSimpleCmd();

/*
* �����Ǽ򵥵�����
* ͨ�����������ĵ��ÿ���ʵ�ֹ���
*/

//�л�����·��
int cd();
//��ӡ��ǰ·��
int pwd();
//�ַ������
int echo();
//��ȡ�ļ�����
int cat();
//����ls����
int call_ls();