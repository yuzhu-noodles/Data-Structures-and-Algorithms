#include"SeqTree.h"

void InitSeqTree(SeqTree tree)
{
	//���ַ�������ÿ��Ԫ�ض����óɿ��ַ�
	for (int i = 0; i < MAX_SIZE; i++)
	{
		tree[i] = '\0';
	}
}

void GreatSeqTree(SeqTree tree, int i)
{
	char ch;
	fflush(stdin);
	ch = getchar();
	fflush(stdin);
	if (ch == '^') {
		tree[i] = '\0';
		return;
	}
	tree[i] = ch;
	printf("���ӽ�㣺");
	GreatSeqTree(tree, 2 * i + 1);
	printf("�Һ��ӽ�㣺");
	GreatSeqTree(tree, 2 * (i + 1));
}
char GetSeqTreeRoot(SeqTree tree)
{
	return tree[0];
}

int GetSeqTreeLength(SeqTree tree)
{
	int len = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (tree[i] == '\0')
			continue;
		len++;
	}
	return len;
}
int GetSeqTreeDepth(SeqTree tree)
{
	//���ΪK�Ķ����������2^k-1�����
	int depth = 0;
	int len = GetSeqTreeLength(tree);
	while ((int)pow(2, depth) - 1 < len)
	{
		depth++;
	}
	return depth;
}