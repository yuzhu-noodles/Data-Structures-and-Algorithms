#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

//����ʵ�ֽ��id��������
static int id = 0;

void InitBT(BinaryTree* tree)
{
	tree->root = NULL;
	tree->length = 0;
	tree->depth = 0;
	tree->diameter = 0;
}
//����ʧ�ܷ���0���ɹ�����1
int CreatBT(TreeNode* root)
{
	//�����Ϊ�գ����˳�
	if (!root)
		return 0;
	char inputName[NAME_SIZE];
	gets(inputName);
	//�û�����س���ʾ������ǰ�����Ĵ���
	if (strcmp(inputName, "\0") == 0)
		return 0;
	//������ǰ���
	root->data.id = ++id;
	strcpy(root->data.name, inputName);
	//Ϊ���ҽ��ָ������ڴ�
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	//�ֱ�ݹ���������������
	printf("���㣺");
	if (CreatBT(root->left) == 0)
	{
		//���ڴ��������㣬�������ڴ�
		free(root->left);
		root->left = NULL;
	}
	printf("�ҽ�㣺");
	if (CreatBT(root->right) == 0)
	{
		//���ڴ��������㣬�������ڴ�
		free(root->right);
		root->right = NULL;
	}
	return 1;
}

//ģ���û������˳��
char* nodeNames[] = { "A","B","D","#","#","E","#","#","C","F","#","#","G","#","#" };
//����nodeNames�����е��±�
static int nodeNameIndex = 0;
//���԰�Ĵ�������
int CreatBT_Test(TreeNode* root)
{
	//�����Ϊ�գ����˳�
	if (!root)
		return 0;
	char inputName[NAME_SIZE];
	strcpy(inputName, nodeNames[nodeNameIndex++]);
	//�û�����س���ʾ������ǰ�����Ĵ���
	if (strcmp(inputName, "#") == 0)
		return 0;
	//������ǰ���
	root->data.id = ++id;
	strcpy(root->data.name, inputName);
	//Ϊ���ҽ��ָ������ڴ�
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	//�ֱ�ݹ���������������
	/*printf("���㣺");*/
	if (CreatBT_Test(root->left) == 0)
	{
		//���ڴ��������㣬�������ڴ�
		free(root->left);
		root->left = NULL;
	}
	/*printf("�ҽ�㣺");*/
	if (CreatBT_Test(root->right) == 0)
	{
		//���ڴ��������㣬�������ڴ�
		free(root->right);
		root->right = NULL;
	}
	return 1;
}

//ǰ�����   ��-��-��
void PreOrderTraverse(TreeNode* node)
{
	if (node)
	{
		printf("[%d,%s]-", node->data.id, node->data.name);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}
//�������  ��-��-��
void InOrderTraverse(TreeNode* node)
{
	if (node)
	{
		InOrderTraverse(node->left);
		printf("[%d,%s]-", node->data.id, node->data.name);
		InOrderTraverse(node->right);
	}
}
//������� ��-��-��
void PostOrderTraverse(TreeNode* node)
{
	if (node)
	{
		InOrderTraverse(node->left);
		InOrderTraverse(node->right);
		printf("[%d,%s]-", node->data.id, node->data.name);
	}
}