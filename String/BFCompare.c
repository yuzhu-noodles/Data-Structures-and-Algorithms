#include"SeqString.h"
int BFCompare(HString* parent, HString* child, int pos)
{
	int i = pos;  //i ���ڼ�¼����parent�е���ʼλ��
	int j = 1;    //�Ӵ�����ʼλ��
	while (i < parent->length && j <= child->length)
	{
		if (parent->ch[i - 1] == child->ch[j - 1])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;  //i���ݵ��ϴ�ƥ�����λ����һλ
			j = 1;          //j�ص��ִ��ĵ�һ��λ��
		}
	}
	if (j > child->length)
	{
		return i - child->length;
	}
	return 0;
}

//����BF�㷨
void testBF()
{
	HString parent;
	HString child;
	StrAssign_HeapString(&parent, "ABC ABD ABEDEFG");
	StrAssign_HeapString(&child, "ABE");
	printf("ƥ������%d", BFCompare(&parent, &child, 3));
}