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

//��̬�������һ���ṹ������
typedef struct 
{
	ElementType data;
	int next;              //�α꣬���Ϊ0��ʾ��ָ��
}StaticLinkList[MAX_SIZE];

//��ʼ��
void InitStaticLinkList(StaticLinkList sll);
//��ָ��λ�ò���Ԫ��
int InsertStaticLinkList(StaticLinkList sll, int pos, ElementType element);
//Ϊ��̬�������һ���ռ��ڴ棬����error��ʾ����ʧ��
int mallocSLL(StaticLinkList sll);
//����ԭʼ������ָ��λ�õ�Ԫ��
void freeSLL(StaticLinkList sll, int index);
//��̬������
int getLengthSLL(StaticLinkList sll);
//ɾ����̬������ָ��λ�õ�Ԫ��
int deleteSLL(StaticLinkList sll,int pos);
//��ӡ
void PrintStaticLinkList(StaticLinkList sll);
#endif