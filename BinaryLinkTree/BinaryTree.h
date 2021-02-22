#ifndef BINARYTREE_H
#define BINARYTREE_H
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

typedef struct TreeNode  //�����
{
	ElementType data;     //������
	struct TreeNode* left; //������
	struct TreeNode* right;//������
}TreeNode;

typedef struct
{
	TreeNode* root;   //���ڵ�
	int length;        //�������
	int depth;        //���
	int diameter;     //ֱ������Ҷ�ڵ㵽Ҷ�����·��
}BinaryTree;

//��ʼ��
void InitBT(BinaryTree* tree);
//�������������ⲿ��Ҫ�Խ������ڴ�
int CreatBT(TreeNode* root);
//���԰�
int CreatBT_Test(TreeNode* root);

//ǰ�����
void PreOrderTraverse(TreeNode* node);
//�������
void InOrderTraverse(TreeNode* node);
//��������
void PostOrderTraverse(TreeNode* node);
#endif
