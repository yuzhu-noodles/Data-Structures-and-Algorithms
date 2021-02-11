#include"SeqStack.h"

void InitSeqStack(SeqStack* seqstack)
{
	seqstack->top = -1;  //栈顶指向-1的下表
	seqstack->length = 0;
}

int PushSeqStack(SeqStack* seqstack, ELementType element)
{
	if (seqstack->top == MAX_SIZE - 1)
	{
		printf("满栈，压栈失败\n");
		return FALSE;
	}
	seqstack->top++;
	seqstack->elements[seqstack->top] = element;
	seqstack->length++;
	return TRUE;
}
int PopSeqStack(SeqStack* seqstack, ELementType* element)
{
	if (seqstack->top == -1)
	{
		printf("空栈，出栈失败\n");
		return FALSE;
	}
	//返回栈顶指向的元素
	*element = seqstack->elements[seqstack->top];
	seqstack->top--;
	seqstack->length--;
	return TRUE;
}

void ClearSeqStack(SeqStack* seqstack)
{
	seqstack->top = -1;
	seqstack->length = 0;
}

void IsEmptySeqStack(SeqStack* seqstack)
{
	if (seqstack->top == -1)
	{
		printf("栈为空\n");
	}
	else
	{
		printf("栈不为空\n");
	}
}
void TopSeqStack(SeqStack* seqstack, ELementType* element)
{
	if (seqstack->top == -1);
	{
		printf("空栈，栈顶元素为空\n");
		element = NULL;
		return;
	}
	*element = seqstack->elements[seqstack->top];
}

void PrintSeqStack(SeqStack* seqstack)
{
	for (int i = 0; i < seqstack->length; i++)
	{
		printf("当前栈内元素：%d\t%s\n", seqstack->elements[i].id, seqstack->elements[i].name);
	}
}