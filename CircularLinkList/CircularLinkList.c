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
	//����һ���ս��
	CircularNode* node = (CircularNode*)malloc(sizeof(CircularNode));
	node->data = element;
	node->next = NULL;
	if (pos == 1)
	{
		node->next = cll->next;
		if (cll->length == 0)  //��������������=0
		{
			node->next = node;
		}
		else
		{
			//������Ȳ�Ϊ0����Ҫ�ҵ���������һ����㲢�ı���ָ����
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
	//����Ĳ��ǵ�һ�����
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
			//�ҵ����һ����㣬�ı���ָ����ָ��
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
		printf("������Ϊ�գ�û�����ݿ��Դ�ӡ��\n");
		return;
	}
	//��¼�³�ʼ�Ľ��ָ��
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
		printf("������Ϊ�գ�û�����ݿ��Դ�ӡ��\n");
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
