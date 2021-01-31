#ifndef CIRCLUARLINKLIST_H
#define VIRCULARLINKLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ѭ������
//�ص㣺β����ָ����ָ���һ�����
//�ŵ㣺����ͨ�������������������ṹ

//��������
typedef struct ElementType
{
	int id;
	char* name;
}ElementType;
//ѭ��������
typedef struct CircularNode
{
	ElementType data;
	struct CircularNode* next;
}CircularNode;
//ѭ������ͷ���
typedef struct CircularLinkList
{
	CircularNode* next;
	int length;
}CircularLinkList;
//��ʼ��
void InitCLL(CircularLinkList* cll,ElementType* dataarray,int length);
//ָ��λ�ò���Ԫ��
void InsertCLL(CircularLinkList* cll, int pos,ElementType element);
//ɾ��ָ��λ��Ԫ�ز�����
ElementType DeleteCLL(CircularLinkList* cll, int pos);

//����Ԫ�����ݷ��ض�Ӧ�Ľ��ָ��
CircularNode* GetCLLNode(CircularLinkList* cll,ElementType element);

//ͨ�������Ľ�㣬ѭ�������������е�ÿ��Ԫ��
void PrintCLLbyNode(CircularLinkList* cll,CircularNode* node);

void PrintCLL(CircularLinkList* cll);

#endif
