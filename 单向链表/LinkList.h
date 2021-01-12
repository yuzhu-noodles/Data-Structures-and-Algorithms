#ifndef LINKLIST_H
#define LINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ڵ�
typedef struct LINKNODE
{
	void* data;//ָ���κ����͵�����
	struct LINKNODE* next;
}LinkNode;
//����ṹ��
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
	//��û����������
}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);

//��ʼ������
LinkList* init_LinkList();
//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data);
//ɾ��ָ��λ�õ�ֵ
void RemoveL_LinkList(LinkList* list, int pos);
//�������ĳ���
int Size_LinkList(LinkList*list);
//����
int Find_LinkList(LinkList* list, void* data);
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list);
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);


#endif
