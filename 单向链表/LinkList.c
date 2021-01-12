#include"LinkList.h"

//��ʼ������
LinkList* init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	
	//ͷ��� �ǲ�����������Ϣ��
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = 0;
	list->head->next = NULL;

	return list;
}
//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	//�Ѻô���posԽ��
	if (pos<0 || pos > list->size)
	{
		pos = list->size;
	}
	//�����µĽڵ�
	LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�ҽ��
	//����ָ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//�½ڵ�������
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	list->size++;
}
//ɾ��ָ��λ�õ�ֵ
void RemoveL_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	if (pos<0 || pos >= list->size)
	{
		return;
	}
	//����ɾ������ǰһ�����
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	//����ɾ���Ľ��
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	//�ͷ�ɾ�������ڴ�
	free(pDel);

	list->size--;

}
//�������ĳ���
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//����
int Find_LinkList(LinkList* list, void* data)
{
	if (list == NULL)
		return -1;
	if(data == NULL)
		return -1;
	//����
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			break;
		}
		i++;
		pCurrent = pCurrent->next;
	}
	return i;
}
//���ص�һ���ڵ�
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}
//��ӡ����ڵ�
void Print_LinkList(LinkList* list, PRINTLINKNODE print)
{
	if (list == NULL)
		return;
	LinkNode* pCurrent = list->head->next;
	while (pCurrent!=NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
		return;
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL)
	{
		//������һ�����
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	//�ͷ������ڴ�
	free(list);
}


