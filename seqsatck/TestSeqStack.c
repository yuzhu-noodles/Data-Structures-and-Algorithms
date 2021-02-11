#include"SeqStack.h"

int main()
{
	ELementType data[] = {
	{1,"宋江"},
	{2,"吴用"},
	{3,"林冲"},
	{4,"卢俊义"}
	};
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	InitSeqStack(stack);
	for (int i = 0; i < 4; i++)
	{
		PushSeqStack(stack, data[i]);
	}
	PrintSeqStack(stack);
	printf("-----------------------------------------------\n");
	//测试出栈
	ELementType* element = (ELementType*)malloc(sizeof(ELementType));
	PopSeqStack(stack, element);
	printf("当前出栈元素：%d\t%s\n", element->id, element->name);
	printf("-----------------------------------------------\n");
	PrintSeqStack(stack);
	printf("-----------------------------------------------\n");
	IsEmptySeqStack(stack);



}


