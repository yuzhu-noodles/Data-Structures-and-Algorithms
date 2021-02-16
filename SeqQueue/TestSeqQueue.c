#include"SeqQueueh.h"

int main()
{
	ElementType datas[] =
	{
		{1,"�����"},
		{2,"��˽�"},
		{3,"ɳ����"}
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
	//����
	ElementType* element = (ElementType*)malloc(sizeof(ElementType));
	PollSeqQueue(&sq, element);
	printf("��ǰ����Ԫ�أ�\n");
	printf("%d\t%s\n", element->id,element->name);
	printf("���Ӻ�Ķ��У�\n");
	for (int i = sq.front; i < sq.rear; i++)
	{
		printf("%d\t%s\n", sq.data[i].id, sq.data[i].name);
	}
	return 0;
}