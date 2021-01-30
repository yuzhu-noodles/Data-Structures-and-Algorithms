#include"LinkList.h"
#define TURE 0
#define FALSE 1
void InitLinkList(LinkList* linklist, ElementType* dataarray, int length)
{
	for (int i = 0; i < length; i++)
	{
		InsertLinkList(linklist, i + 1, dataarray[i]);
	}
}
void InsertLinkList(LinkList* linklist, int pos, ElementType element)
{
	//�����ս�㲢Ϊ������ֵ
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;
	//�ҵ�����λ�õĽ��
	if (pos == 1)
	{
		linklist->next = node;
		linklist->length++;
		return;
	}
	//ͨ��ѭ���ҵ�Ҫ����Ľ��λ��
	Node* currNode = linklist->next;
	for (int i = 1; currNode && i < pos - 1; i++)
	{
		currNode = currNode->next;
	}
	if (currNode)
	{
		node->next = currNode->next;
		currNode->next = node;
		linklist->length++;
	}
	//�������벢�Խ�ǰ��Ľ��
}

int IsLinkListEmpty(LinkList* linklist)
{
	return linklist->length == 0 ? TURE : FALSE;
}

ElementType GetLinkListElem(LinkList* linklist, int pos)
{
	Node* node = linklist->next;
	for (int i = 1; node && i < pos; i++)
	{
		node = node->next;
	}
	return node->data;
}
ElementType DeleteLinkList(LinkList* linklist, int pos)
{
	ElementType element;  //��ɾ����Ԫ��
	element.id = -999;   //��һ�������ܵ�ֵ�������ж��Ƿ�ɾ���ɹ�
	Node* node = NULL;
	if (pos == 1)
	{
		node = linklist->next;
		if (node)
		{
			element = node->data;
			linklist->next = node->next;
			free(node);
			linklist->length--;
		}
		return element;
	}
	//�ҵ�Ҫɾ���Ľ���ǰ׺���
	//ɾ�����->next��ֵ��ǰ׺���->next
	//�ͷ�Ҫɾ���Ľ���ڴ�
	Node* preNode=NULL;
	node = linklist->next;
	for (int i = 0; node && i < pos-1; i++)
	{
		preNode = node;
		node = node->next;
	}
	if (node)
	{
		element = node->data;
		preNode->next = node->next;
		free(node);
		linklist->length--;
	}
	return element;
}
void ClearLinkList(LinkList* linklist)
{
	Node* node = linklist->next;
	Node* nextnode;
	while (node)
	{
		nextnode = node->next;
		free(node);
		node = nextnode;
	}
	linklist->next = NULL;
	linklist->length = 0;
}
void PrintLinkList(LinkList* linklist)
{
	Node* node = linklist->next;
	if (!node)
	{
		printf("����Ϊ��\n");
		linklist->length = 0;
		return;
	}
	for (int i = 0; i < linklist->length; i++)
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
}