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
	struct CBNode* firstChild;  //长子结点
	struct CBNode* nextSibling;  //兄弟结点
}CBNode,* CBTree;

//初始化
void InitCBTree(CBTree* tree);  //二级指针
//构造树
void CreateCBTree(CBNode** node);

//前序遍历
void PreOrderCBTree(CBTree* tree);
#endif 
