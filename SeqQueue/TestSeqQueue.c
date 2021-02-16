#include"SeqQueueh.h"

int main()
{
	ElementType datas[] =
	{
		{1,"孙悟空"},
		{2,"猪八戒"},
		{3,"沙和尚"}
	};
	SeqQueue sq;
	InitSeqQueue(&sq);
	OfferSeqQueue(&sq, datas[0]);
	OfferSeqQueue(&sq, datas[1]);
	OfferSeqQueue(&sq, datas[2]);
	for (int i = 0; i < sq.length; i++)
	{
		printf("%d\t%s\n", sq.data[i].id, sq.data[i].name);
	}
	//出队
	ElementType* element = (ElementType*)malloc(sizeof(ElementType));
	PollSeqQueue(&sq, element);
	printf("当前出队元素：\n");
	printf("%d\t%s\n", element->id,element->name);
	printf("出队后的队列：\n");
	for (int i = sq.front; i < sq.rear; i++)
	{
		printf("%d\t%s\n", sq.data[i].id, sq.data[i].name);
	}
	return 0;
}