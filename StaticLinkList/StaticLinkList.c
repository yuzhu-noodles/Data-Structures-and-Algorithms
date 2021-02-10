#include"StaticLinkList.h"

void InitStaticLinkList(StaticLinkList sll)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		sll[i].data.id = -1; //-1表示没有赋值
		sll[i].data.name = NULL;
		sll[i].next = i + 1;
	}
	//将最后一个结点置空
	sll[MAX_SIZE - 1].next = 0;
	//将备用链表结点的尾结点置为空
	sll[MAX_SIZE - 2].next = 0;
}

int InsertStaticLinkList(StaticLinkList sll, int pos, ElementType element)
{
	if (pos<1 || pos>getLengthSLL(sll) + 1)
	{
		return ERROR;
	}
	int cursor = MAX_SIZE - 1;  //第一个元素的下表
	//需要判断cursor的范围是否合法
	//分配内存
	int newindex = mallocSLL(sll);
	if (newindex)
	{
		sll[newindex].data = element;
		//找到newindex的前缀结点
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
	sll[index].next = sll[0].next;  //将下标为index的空闲结点回收到备用结点
	sll[0].next = index;  //0号元素的next结点指向备用链表的第一个结点，表示index结点空闲
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
	//通过循环找到要删除位置的前缀结点
	for (int i = 1; i < pos - 1; i++)
	{
		cursor = sll[cursor].next;
	}
	int delindex = sll[cursor].next;
	sll[cursor].next = sll[delindex].next;
	//释放空间
	freeSLL(sll, delindex);
	return OK;
}
void PrintStaticLinkList(StaticLinkList sll)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("i：%d\tnext:%d\tid:%d\tname:%s\n", i, sll[i].next,sll[i].data.id,sll[i].data.name);
	}
}