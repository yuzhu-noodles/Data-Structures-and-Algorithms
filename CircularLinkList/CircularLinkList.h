#ifndef CIRCLUARLINKLIST_H
#define VIRCULARLINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//循环链表
//特点：尾结点的指针域指向第一个结点
//优点：可以通过任意结点遍历整个链表结构

//数据类型
typedef struct ElementType
{
	int id;
	char* name;
}ElementType;
//循环链表结点
typedef struct CircularNode
{
	ElementType data;
	struct CircularNode* next;
}CircularNode;
//循环链表头结点
typedef struct CircularLinkList
{
	CircularNode* next;
	int length;
}CircularLinkList;
//初始化
void InitCLL(CircularLinkList* cll,ElementType* dataarray,int length);
//指定位置插入元素
void InsertCLL(CircularLinkList* cll, int pos,ElementType element);
//删除指定位置元素并返回
ElementType DeleteCLL(CircularLinkList* cll, int pos);

//根据元素内容返回对应的结点指针
CircularNode* GetCLLNode(CircularLinkList* cll,ElementType element);

//通过给定的结点，循环遍历出链表中的每个元素
void PrintCLLbyNode(CircularLinkList* cll,CircularNode* node);

void PrintCLL(CircularLinkList* cll);

#endif
