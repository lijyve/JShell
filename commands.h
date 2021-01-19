#pragma once

#include <stdio.h>
#include "data.h"

//�ж������Ƿ����
int isCmdExist(const char* cmd);
//�ֽ����������
int splitCmds(char argv[]);
//�ж����������Ƿ񲻺��ܵ����ض���
int isSimpleCmd();
//���ü򵥺���
int callSimpleCmd();

/*
* �����Ǽ򵥵�����
* ͨ�����������ĵ��ÿ���ʵ�ֹ���
*/

//�л�����·��
int cd(const char* path);
//��ӡ��ǰ·��
int pwd();
//�г�Ŀ¼�������ļ�����Ŀ¼
int ls();
//�ַ������
int echo(const char* str);
//��ȡ�ļ�����
int cat(const char* filename);
//�˳�JShell
int exit();