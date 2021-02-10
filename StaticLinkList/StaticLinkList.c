#include"StaticLinkList.h"

void InitStaticLinkList(StaticLinkList sll)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		sll[i].data.id = -1; //-1��ʾû�и�ֵ
		sll[i].data.name = NULL;
		sll[i].next = i + 1;
	}
	//�����һ������ÿ�
	sll[MAX_SIZE - 1].next = 0;
	//�������������β�����Ϊ��
	sll[MAX_SIZE - 2].next = 0;
}

int InsertStaticLinkList(StaticLinkList sll, int pos, ElementType element)
{
	if (pos<1 || pos>getLengthSLL(sll) + 1)
	{
		return ERROR;
	}
	int cursor = MAX_SIZE - 1;  //��һ��Ԫ�ص��±�
	//��Ҫ�ж�cursor�ķ�Χ�Ƿ�Ϸ�
	//�����ڴ�
	int newindex = mallocSLL(sll);
	if (newindex)
	{
		sll[newindex].data = element;
		//�ҵ�newindex��ǰ׺���
		for (int i = 1; i <= pos - 1; i++)
		{
			cursor = sll[cursor].next;
		}
		sll[newindex].next = sll[cursor].next;
		sll[cursor].next = newindex;
		return OK;
	}
	return ERROR;

}

int mallocSLL(StaticLinkList sll)
{
	int cursor = sll[0].next;
	if (cursor)
	{
		sll[0].next = sll[cursor].next;
	}
	return cursor;
}

void freeSLL(StaticLinkList sll, int index)
{
	sll[index].next = sll[0].next;  //���±�Ϊindex�Ŀ��н����յ����ý��
	sll[0].next = index;  //0��Ԫ�ص�next���ָ��������ĵ�һ����㣬��ʾindex������
}
int getLengthSLL(StaticLinkList sll)
{
	int count = 0;
	int cursor = sll[MAX_SIZE - 1].next;
	while (cursor)
	{
		cursor = sll[cursor].next;
		count++;
	}
	return count;
}

int deleteSLL(StaticLinkList sll, int pos)
{
	if (pos<1 || pos>getLengthSLL(sll))
	{
		return ERROR;
	}
	int cursor = MAX_SIZE - 1;
	//ͨ��ѭ���ҵ�Ҫɾ��λ�õ�ǰ׺���
	for (int i = 1; i < pos - 1; i++)
	{
		cursor = sll[cursor].next;
	}
	int delindex = sll[cursor].next;
	sll[cursor].next = sll[delindex].next;
	//�ͷſռ�
	freeSLL(sll, delindex);
	return OK;
}
void PrintStaticLinkList(StaticLinkList sll)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("i��%d\tnext:%d\tid:%d\tname:%s\n", i, sll[i].next,sll[i].data.id,sll[i].data.name);
	}
}