#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����С���
typedef struct LINKNODE
{
	struct LINKNODE* next;
}LinkNode;

//������
typedef struct LINKLIST
{
	LinkNode head;
	int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);

//��ʼ������
LinkList* Init_LinkList();
//����
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);
//ɾ��
void Remove_Linklist(LinkList*list,int pos);
//����
int Find_LinkList(LinkList*list,LinkNode*data);
//���������С
int Size_LinkList(LinkList* list);
//��ӡ
void Print_LinkList(LinkList* list, PRINTNODE print);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList*list);

#endif
