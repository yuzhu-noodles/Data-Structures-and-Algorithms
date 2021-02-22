#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

//用来实现结点id的自增长
static int id = 0;

void InitBT(BinaryTree* tree)
{
	tree->root = NULL;
	tree->length = 0;
	tree->depth = 0;
	tree->diameter = 0;
}
//创建失败返回0，成功返回1
int CreatBT(TreeNode* root)
{
	//根结点为空，就退出
	if (!root)
		return 0;
	char inputName[NAME_SIZE];
	gets(inputName);
	//用户输入回车表示结束当前子树的创建
	if (strcmp(inputName, "\0") == 0)
		return 0;
	//创建当前结点
	root->data.id = ++id;
	strcpy(root->data.name, inputName);
	//为左右结点指针分配内存
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	//分别递归左子树和右子树
	printf("左结点：");
	if (CreatBT(root->left) == 0)
	{
		//不在创建这个结点，则销毁内存
		free(root->left);
		root->left = NULL;
	}
	printf("右结点：");
	if (CreatBT(root->right) == 0)
	{
		//不在创建这个结点，则销毁内存
		free(root->right);
		root->right = NULL;
	}
	return 1;
}

//模拟用户输入的顺序
char* nodeNames[] = { "A","B","D","#","#","E","#","#","C","F","#","#","G","#","#" };
//访问nodeNames数组中的下标
static int nodeNameIndex = 0;
//测试版的创建函数
int CreatBT_Test(TreeNode* root)
{
	//根结点为空，就退出
	if (!root)
		return 0;
	char inputName[NAME_SIZE];
	strcpy(inputName, nodeNames[nodeNameIndex++]);
	//用户输入回车表示结束当前子树的创建
	if (strcmp(inputName, "#") == 0)
		return 0;
	//创建当前结点
	root->data.id = ++id;
	strcpy(root->data.name, inputName);
	//为左右结点指针分配内存
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	//分别递归左子树和右子树
	/*printf("左结点：");*/
	if (CreatBT_Test(root->left) == 0)
	{
		//不在创建这个结点，则销毁内存
		free(root->left);
		root->left = NULL;
	}
	/*printf("右结点：");*/
	if (CreatBT_Test(root->right) == 0)
	{
		//不在创建这个结点，则销毁内存
		free(root->right);
		root->right = NULL;
	}
	return 1;
}

//前序遍历   根-左-右
void PreOrderTraverse(TreeNode* node)
{
	if (node)
	{
		printf("[%d,%s]-", node->data.id, node->data.name);
		PreOrderTraverse(node->left);
		PreOrderTraverse(node->right);
	}
}
//中序遍历  左-根-右
void InOrderTraverse(TreeNode* node)
{
	if (node)
	{
		InOrderTraverse(node->left);
		printf("[%d,%s]-", node->data.id, node->data.name);
		InOrderTraverse(node->right);
	}
}
//后序遍历 左-右-根
void PostOrderTraverse(TreeNode* node)
{
	if (node)
	{
		InOrderTraverse(node->left);
		InOrderTraverse(node->right);
		printf("[%d,%s]-", node->data.id, node->data.name);
	}
}