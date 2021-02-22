#include"BinaryTree.h"	

int main()
{
	BinaryTree tree;
	InitBT(&tree);
	//根结点需要事先分配内存
	tree.root = (TreeNode*)malloc(sizeof(TreeNode));
	//printf("请输入根结点：");
	//CreatBT(tree.root);
	CreatBT_Test(tree.root);
	printf("前序遍历：\n");
	PreOrderTraverse(tree.root);
	printf("\n");
	printf("中序遍历：\n");
	InOrderTraverse(tree.root);
	printf("\n");
	printf("后序遍历：\n");
	PostOrderTraverse(tree.root);
	free(tree.root);
	return 0;
}