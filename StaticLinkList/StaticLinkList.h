#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define OK 1
#define ERROR 0

typedef struct 
{
	int id;
	char* name;
}ElementType;

//静态数组就是一个结构体数组
typedef struct 
{
	ElementType data;
	int next;              //游标，如果为0表示无指向
}StaticLinkList[MAX_SIZE];

//初始化
void InitStaticLinkList(StaticLinkList sll);
//向指定位置插入元素
int InsertStaticLinkList(StaticLinkList sll, int pos, ElementType element);
//为静态链表分配一个空间内存，返回error表示分配失败
int mallocSLL(StaticLinkList sll);
//回收原始数组中指定位置的元素
void freeSLL(StaticLinkList sll, int index);
//求静态链表长度
int getLengthSLL(StaticLinkList sll);
//删除静态链表中指定位置的元素
int deleteSLL(StaticLinkList sll,int pos);
//打印
void PrintStaticLinkList(StaticLinkList sll);
#endif