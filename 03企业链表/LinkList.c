#include"LinkList.h"

//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	return list;
}
//����
void Insert_LinkList(LinkList* list, int pos, LinkNode* data)
{
	if (list == NULL)
		return;
	if (data == NULL)
		return;
	if (pos<0 || pos>list->size)
	{
		pos = list->size;
	}

	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < list->size; i++)
	{
		pCurrent = pCurrent->next;
	}
	//�����½ڵ�
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
}
//ɾ��
void Remove_Linklist(LinkList* list, int pos)
{
	if (list == NULL)
		return;
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < list->size; i++)
	{
		pCurrent = pCurrent->next;
	}

}
//����
int Find_LinkList(LinkList* list, LinkNode* data);
//���������С
int Size_LinkList(LinkList* list);
//��ӡ
void Print_LinkList(LinkList * list, PRINTNODE print)
{
	if (list == NULL)
		return;

	//����ָ��
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL)
	{
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if (list == NULL)
		return;
	free(list);
}