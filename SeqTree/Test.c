#include"SeqTree.h"


int main()
{
	SeqTree tree;
	InitSeqTree(tree);
	printf("�������������ݣ�");
	GreatSeqTree(tree, 0);

	for (int i = 0; i < 5; i++)
	{
		printf("%d,", tree[i]);
	}
	printf("\n");
	printf("�ܽ������%d\n", GetSeqTreeLength(tree));
	Printf("��ǰ��ȣ�%d\n", GetSeqTreeDepth(tree));
	return 0;
}