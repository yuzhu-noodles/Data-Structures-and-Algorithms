#include"Brother.h"

int main()
{
	CBTree tree;
	InitCBTree(&tree);
	printf("���ڵ㣺");
	CreateCBTree(&tree);
	printf("���������\n");
	PreOrderCBTree(tree);

	return 0;
}