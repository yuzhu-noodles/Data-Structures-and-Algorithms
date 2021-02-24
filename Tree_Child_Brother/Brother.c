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
	//判断用户输入的是否是回车键
	if (strcmp(inputName,"\0") == 0)
		return;
	if (*node == NULL)
	{
        *node = (CBNode*)malloc(sizeof(CBNode));
		(*node)->firstChild = NULL;
		(*node)->nextSibling = NULL;
	}
	//为结点赋值
	(*node)->data.id = ++id;
	strcpy((*node)->data.name, inputName);
	//分别遍历输入长子结点和兄弟结点
	printf("请输入长子结点：");
	CreateCBTree(&((*node)->firstChild));
	printf("请输入兄弟结点：");
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