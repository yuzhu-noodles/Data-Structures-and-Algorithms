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
	ElementType data; //������
	struct Node* next;//ָ����
}Node;
  /*
  ͷ���
  �����ڶ�������ʱ��ϰ���ԵĻᶨ��ͷ��㣬�Ա�ͳһ������Ĳ����ɾ������
  */
typedef struct LinkList
{
	Node* next; //ͷָ��(���������ͷ��㣬next��ָ��ͷ�ڵ㣬û�о�ָ���һ���ڵ�)
	int length; //������
}LinkList;

void InitLinkList(LinkList* linklist, ElementType* dataarray, int length);

void InsertLinkList(LinkList* linklist, int pos, ElementType element);

int IsLinkListEmpty(LinkList* linklist);

ElementType GetLinkListElem(LinkList* linklist, int pos);

ElementType DeleteLinkList(LinkList* linklist, int pos);

void ClearLinkList(LinkList* linklist);

void PrintLinkList(LinkList* linklist);
#endif