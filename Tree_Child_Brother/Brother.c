#define _CRT_SECURE_NO_WARNINGS
#include"Brother.h"

static int id = 0;

void InitCBTree(CBTree* tree)
{
	*tree = (CBTree)malloc(sizeof(CBNode));
	(*tree)->firstChild = NULL;
	(*tree)->nextSibling = NULL;
}

void CreateCBTree(CBNode ** node)
{
	char inputName[NAME_SIZE];
	gets(inputName);
	//�ж��û�������Ƿ��ǻس���
	if (strcmp(inputName,"\0") == 0)
		return;
	if (*node == NULL)
	{
        *node = (CBNode*)malloc(sizeof(CBNode));
		(*node)->firstChild = NULL;
		(*node)->nextSibling = NULL;
	}
	//Ϊ��㸳ֵ
	(*node)->data.id = ++id;
	strcpy((*node)->data.name, inputName);
	//�ֱ�������볤�ӽ����ֵܽ��
	printf("�����볤�ӽ�㣺");
	CreateCBTree(&((*node)->firstChild));
	printf("�������ֵܽ�㣺");
	CreateCBTree(&((*node)->nextSibling));
}

void PreOrderCBTree(CBNode* node)
{
	if (node != NULL)
	{
		printf("[%d,%s] ", node->data.id, node->data.name);
		CBNode* p = node->firstChild;
		PreOrderCBTree(p);
		while (p)
		{
			p = p->nextSibling;
			PreOrderCBTree(p);
		}
	}
}