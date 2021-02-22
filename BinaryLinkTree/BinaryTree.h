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

typedef struct TreeNode  //树结点
{
	ElementType data;     //数据域
	struct TreeNode* left; //左子树
	struct TreeNode* right;//右子树
}TreeNode;

typedef struct
{
	TreeNode* root;   //根节点
	int length;        //结点总数
	int depth;        //深度
	int diameter;     //直径，从叶节点到叶结点的最长路径
}BinaryTree;

//初始化
void InitBT(BinaryTree* tree);
//构建二叉树，外部需要对结点分配内存
int CreatBT(TreeNode* root);
//测试版
int CreatBT_Test(TreeNode* root);

//前序遍历
void PreOrderTraverse(TreeNode* node);
//中序遍历
void InOrderTraverse(TreeNode* node);
//后续遍历
void PostOrderTraverse(TreeNode* node);
#endif
