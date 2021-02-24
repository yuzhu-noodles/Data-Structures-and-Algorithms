#ifndef BROTHER_H
#define BROTHER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1024
#define NAME_SIZE 255

typedef struct ElementType
{
	int id;
	char name[NAME_SIZE];
}ElementType;

typedef struct CBNode
{
	ElementType data;
	struct CBNode* firstChild;  //���ӽ��
	struct CBNode* nextSibling;  //�ֵܽ��
}CBNode,* CBTree;

//��ʼ��
void InitCBTree(CBTree* tree);  //����ָ��
//������
void CreateCBTree(CBNode** node);

//ǰ�����
void PreOrderCBTree(CBTree* tree);
#endif 
