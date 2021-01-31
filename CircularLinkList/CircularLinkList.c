#include"CircularLinkList.h"

void InitCLL(CircularLinkList* cll, ElementType* dataarray, int length)
{
	for (int i = 0; i < length; i++)
	{
		InsertCLL(cll, i+1, dataarray[i]);
	}
}
void InsertCLL(CircularLinkList* cll, int pos, ElementType element)
{
	//创建一个空结点
	CircularNode* node = (CircularNode*)malloc(sizeof(CircularNode));
	node->data = element;
	node->next = NULL;
	if (pos == 1)
	{
		node->next = cll->next;
		if (cll->length == 0)  //如果插入的链表长度=0
		{
			node->next = node;
		}
		else
		{
			//如果长度不为0，就要找到链表的最后一个结点并改变其指针域
			CircularNode* lastnode = cll->next;
			for (int i = 1; i < cll->length; i++)
			{
				lastnode = lastnode->next;
			}
			lastnode->next = node;
		}
		cll->next = node;
		cll->length++;
		return;
	}
	//插入的不是第一个结点
	CircularNode* prenode = cll->next;
	for (int i = 1;prenode && i < pos-1; i++)
	{
		prenode = prenode->next;
	}
	if (prenode)
	{
		node->next = prenode->next;
		prenode->next = node;
		cll->length++;
		if (pos == cll->length)
		{
			node->next = cll->next;
		}
	}
}

ElementType DeleteCLL(CircularLinkList* cll, int pos)
{
	ElementType element;
	if (pos == 1)
	{
		CircularNode* node = cll->next;
		if (node)
		{
			element = node->data;
			//找到最后一个结点，改变其指针域指向
			CircularNode* lastnode = cll->next;
			for (int i = 1; i < cll->length; i++)
			{
				lastnode = lastnode->next;
			}
			cll->next = node->next;
			lastnode->next = cll->next;
			free(node);
			cll->length--;
		}
		return;
	}
	CircularNode* prenode = NULL;
	CircularNode* node = cll->next;
	for (int i = 1; node && i < pos; i++)
	{
		prenode = node;
		node = node->next;
	}
	if (node)
	{
		element = node->data;
		prenode->next = node->next;
		free(node);
		cll->length--;
	}
	return element;
}

CircularNode* GetCLLNode(CircularLinkList* cll, ElementType element)
{
	CircularNode* node = cll->next;
	if (!node)
	{
		return NULL;
	}
	do 
	{
		if (element.id = node->data.id && strcmp(element.name, node->data.name) == 0)
		{
			return node;
		}
		node = node->next;
	} while (node != cll->next);
	return NULL;
}
void PrintCLLbyNode(CircularLinkList* cll, CircularNode* node)
{
	if (!node || !cll->next)
	{
		printf("链表长度为空，没有内容可以打印！\n");
		return;
	}
	//记录下初始的结点指针
	CircularNode* orinode = node;
	do
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	} while (node != orinode);

}
void PrintCLL(CircularLinkList* cll)
{
	if (cll->length == 0 || !cll->next)
	{
		printf("链表长度为空，没有内容可以打印！\n");
		cll->length = 0;
		return;
	}
	CircularNode* node = cll->next;
	for (int i = 0; i < cll->length; i++)
	{
		printf("%d\t%s\n", node->data.id, node->data.name);
		node = node->next;
	}
}
