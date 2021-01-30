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
	//创建空结点并为数据域赋值
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = element;
	node->next = NULL;
	//找到插入位置的结点
	if (pos == 1)
	{
		linklist->next = node;
		linklist->length++;
		return;
	}
	//通过循环找到要插入的结点位置
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
	//将结点插入并对接前面的结点
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
	ElementType element;  //被删除的元素
	element.id = -999;   //赋一个不可能的值，用来判断是否删除成功
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
	//找到要删除的结点和前缀结点
	//删除结点->next赋值给前缀结点->next
	//释放要删除的结点内存
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
		printf("链表为空\n");
		linklist->length = 0;
		return;
	}
	for (int i = 0; i < linklist->length; i++)
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
}