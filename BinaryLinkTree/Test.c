#include"BinaryTree.h"

int main()
{
	BinaryTree tree;
	InitBT(&tree);
	//根结点需要事先分配内存
	tree.root = (TreeNode*)malloc(sizeof(TreeNode));
	printf("请输入根结点："
	);
	CreatBT(tree.root);
	free(tree.root);
	return 0;
}