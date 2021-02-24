#include"Brother.h"

int main()
{
	CBTree tree;
	InitCBTree(&tree);
	printf("根节点：");
	CreateCBTree(&tree);
	printf("先序遍历：\n");
	PreOrderCBTree(tree);

	return 0;
}