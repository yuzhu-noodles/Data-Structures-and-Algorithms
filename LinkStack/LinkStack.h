#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define WHITE 1
#define BLACK 2
typedef struct Chessman
{
	int x;
	int y;
	int Colour; //WHITE/BLACK
}Chessman;

typedef struct StackNode
{
	Chessman data;
	struct StackNode* next;
}StackNode;
//��ջ�ṹ
typedef struct LinkStack
{
	StackNode* top;
	int length;
}LinkStack;

//��ʼ��
void InitLinkStack(LinkStack* linkstack);
//ѹջ
int PushLinkStack(LinkStack* linkstack, Chessman element);
//��ջ
int PopLinkStack(LinkStack* linkstack, Chessman* element);
//�����ջ,����ջ��ÿ��Ԫ�ز��ͷŽ��ռ�
void ClearLinkStack(LinkStack* linkstack);
//����
void DestroyLinkStack(LinkStack* linkstack);
#endif
