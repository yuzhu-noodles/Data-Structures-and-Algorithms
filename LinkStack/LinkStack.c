#include"LinkStack.h"

void InitLinkStack(LinkStack* linkstack)
{
	linkstack->top = NULL;
	linkstack->length = 0;
}
int PushLinkStack(LinkStack* linkstack, Chessman element)
{
	StackNode* node=(StackNode*)malloc(sizeof(StackNode));
	node->data = element;
	node->next = linkstack->top;
	linkstack->top = node;
	linkstack->length++;
	return TRUE;
}
int PopLinkStack(LinkStack* linkstack, Chessman* element)
{
	if (linkstack->top == NULL)
	{
		printf("��ջ����ջʧ��\n");
		return FALSE;
	}
	//����ջ��Ԫ��
	*element = linkstack->top->data;
	//��¼��ջ����ǰ��ջ��ָ��
	StackNode* node = linkstack->top;
	//ջ��ָ������һλ
	linkstack->top = linkstack->top->next;
	free(node);
	linkstack->length--;
	return TRUE;
}
void ClearLinkStack(LinkStack* linkstack)
{
	StackNode* tempnode;
	while (linkstack->top)
	{
		tempnode = linkstack->top;
		linkstack->top = linkstack->top->next;
		free(tempnode);
		linkstack->length--;
	}
}
void DestroyLinkStack(LinkStack* linkstack)
{
	ClearLinkStack(linkstack);
	free(linkstack);
	linkstack = NULL;
}
