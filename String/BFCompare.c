#include"SeqString.h"
int BFCompare(HString* parent, HString* child, int pos)
{
	int i = pos;  //i 用于记录主串parent中的起始位置
	int j = 1;    //子串的起始位置
	while (i < parent->length && j <= child->length)
	{
		if (parent->ch[i - 1] == child->ch[j - 1])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;  //i回溯到上次匹配的首位的下一位
			j = 1;          //j回到字串的第一个位置
		}
	}
	if (j > child->length)
	{
		return i - child->length;
	}
	return 0;
}

//测试BF算法
void testBF()
{
	HString parent;
	HString child;
	StrAssign_HeapString(&parent, "ABC ABD ABEDEFG");
	StrAssign_HeapString(&child, "ABE");
	printf("匹配结果：%d", BFCompare(&parent, &child, 3));
}