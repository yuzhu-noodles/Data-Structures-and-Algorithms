#include"BinaryTree.h"

int main()
{
	BinaryTree tree;
	InitBT(&tree);
	//�������Ҫ���ȷ����ڴ�
	tree.root = (TreeNode*)malloc(sizeof(TreeNode));
	printf("���������㣺"
	);
	CreatBT(tree.root);
	free(tree.root);
	return 0;
}