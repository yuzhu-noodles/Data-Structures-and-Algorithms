#include"BinaryTree.h"	

int main()
{
	BinaryTree tree;
	InitBT(&tree);
	//�������Ҫ���ȷ����ڴ�
	tree.root = (TreeNode*)malloc(sizeof(TreeNode));
	//printf("���������㣺");
	//CreatBT(tree.root);
	CreatBT_Test(tree.root);
	printf("ǰ�������\n");
	PreOrderTraverse(tree.root);
	printf("\n");
	printf("���������\n");
	InOrderTraverse(tree.root);
	printf("\n");
	printf("���������\n");
	PostOrderTraverse(tree.root);
	free(tree.root);
	return 0;
}