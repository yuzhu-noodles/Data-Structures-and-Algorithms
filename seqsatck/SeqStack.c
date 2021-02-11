#include"SeqStack.h"

void InitSeqStack(SeqStack* seqstack)
{
	seqstack->top = -1;  //ջ��ָ��-1���±�
	seqstack->length = 0;
}

int PushSeqStack(SeqStack* seqstack, ELementType element)
{
	if (seqstack->top == MAX_SIZE - 1)
	{
		printf("��ջ��ѹջʧ��\n");
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
		printf("��ջ����ջʧ��\n");
		return FALSE;
	}
	//����ջ��ָ���Ԫ��
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
		printf("ջΪ��\n");
	}
	else
	{
		printf("ջ��Ϊ��\n");
	}
}
void TopSeqStack(SeqStack* seqstack, ELementType* element)
{
	if (seqstack->top == -1);
	{
		printf("��ջ��ջ��Ԫ��Ϊ��\n");
		element = NULL;
		return;
	}
	*element = seqstack->elements[seqstack->top];
}

void PrintSeqStack(SeqStack* seqstack)
{
	for (int i = 0; i < seqstack->length; i++)
	{
		printf("��ǰջ��Ԫ�أ�%d\t%s\n", seqstack->elements[i].id, seqstack->elements[i].name);
	}
}