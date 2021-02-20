#include"SeqTree.h"


int main()
{
	SeqTree tree;
	InitSeqTree(tree);
	printf("请输入根结点内容：");
	GreatSeqTree(tree, 0);

	for (int i = 0; i < 5; i++)
	{
		printf("%d,", tree[i]);
	}
	printf("\n");
	printf("总结点数：%d\n", GetSeqTreeLength(tree));
	Printf("当前深度：%d\n", GetSeqTreeDepth(tree));
	return 0;
}