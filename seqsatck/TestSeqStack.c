#include"SeqStack.h"

int main()
{
	ELementType data[] = {
	{1,"�ν�"},
	{2,"����"},
	{3,"�ֳ�"},
	{4,"¬����"}
	};
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	InitSeqStack(stack);
	for (int i = 0; i < 4; i++)
	{
		PushSeqStack(stack, data[i]);
	}
	PrintSeqStack(stack);
	printf("-----------------------------------------------\n");
	//���Գ�ջ
	ELementType* element = (ELementType*)malloc(sizeof(ELementType));
	PopSeqStack(stack, element);
	printf("��ǰ��ջԪ�أ�%d\t%s\n", element->id, element->name);
	printf("-----------------------------------------------\n");
	PrintSeqStack(stack);
	printf("-----------------------------------------------\n");
	IsEmptySeqStack(stack);



}


