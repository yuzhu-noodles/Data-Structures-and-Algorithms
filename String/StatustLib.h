#ifndef STATUSTLIB_H
#define STATUSTLIB_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//״̬��
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define EQ 0
#define GT 1  //great than
#define LT -1

#ifndef _STATUS_H_  //���ϵͳ���Ѿ���������״̬��Ķ��壬�Ͳ����ظ�����
    #define OVERFLOW -2  //��ջ����  �������ܱ�ʾ���������
    #define UNDERFLOW -3 //��ջ����  �������ܱ�ʾ����С����
#endif

typedef int Status;  //�Զ���һ��״̬��ʶ������
#endif
