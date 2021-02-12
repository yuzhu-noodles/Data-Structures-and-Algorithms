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
//链栈结构
typedef struct LinkStack
{
	StackNode* top;
	int length;
}LinkStack;

//初始化
void InitLinkStack(LinkStack* linkstack);
//压栈
int PushLinkStack(LinkStack* linkstack, Chessman element);
//出栈
int PopLinkStack(LinkStack* linkstack, Chessman* element);
//清空链栈,遍历栈中每个元素并释放结点空间
void ClearLinkStack(LinkStack* linkstack);
//销毁
void DestroyLinkStack(LinkStack* linkstack);
#endif
