#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct ElementType
{
	int id;
	char* name;
}ElementType;

typedef struct Node
{
	ElementType data; //数据域
	struct Node* next;//指针域
}Node;
  /*
  头结点
  我们在定义链表时，习惯性的会定义头结点，以便统一链表结点的插入和删除操作
  */
typedef struct LinkList
{
	Node* next; //头指针(如果链表有头结点，next就指向头节点，没有就指向第一个节点)
	int length; //链表长度
}LinkList;

void InitLinkList(LinkList* linklist, ElementType* dataarray, int length);

void InsertLinkList(LinkList* linklist, int pos, ElementType element);

int IsLinkListEmpty(LinkList* linklist);

ElementType GetLinkListElem(LinkList* linklist, int pos);

ElementType DeleteLinkList(LinkList* linklist, int pos);

void ClearLinkList(LinkList* linklist);

void PrintLinkList(LinkList* linklist);
#endif