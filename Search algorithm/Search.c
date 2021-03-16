#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 255

typedef int KeyType;
typedef char* InfoType;

//��������
typedef struct
{
	KeyType key;
	InfoType value;
}ElementType;

typedef struct
{
	ElementType* data;
	int length;
}SeqList;

//��ʼ��
void InitSeqList(SeqList* seqlist)
{
	seqlist->data = (ElementType*)malloc(sizeof(ElementType)*MAX_SIZE);
	seqlist->length = 0;
}

//˳����ң�����Ԫ����˳����е�λ�ã�û���ҵ�����0
int SearchSeqList1(SeqList* seqlist,KeyType key)
{
	for (int i = 1; i < seqlist->length; i++)
	{
		if (seqlist->data[i].key == key)
			return i;
	}
	return 0;
}

//ԭ�㷨forѭ������һ���жϣ�ѭ������Ҳ��һ���ж�
//�Ľ���,ֻ���ж�һ��keyֵ�Ϳ�����
int SearchSeqList2(SeqList* seqlist, KeyType key)
{
	seqlist->data[0].key = key;
	int i;
	for (i = seqlist->length; seqlist->data[i].key != key; i--);
	return i;
}


//���ֲ��ҷ�   //������ʹ�õݹ飬Ч�ʸ���
int SearchSeqListBinary(SeqList* seqlist, KeyType key)
{
	int left = 0;
	int right = seqlist->length;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (seqlist->data[mid].key == key)
			return mid;
		else if (seqlist->data[mid].key < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}
//��ӡ
void PrintSeqList(SeqList* seqlist)
{
	printf("key\tvalue\n");
	for (int i = 1; i <= seqlist->length; i++)
	{
		printf("%d\t%s\n", seqlist->data[i].key, seqlist->data[i].value);
	}
	
}

//����
void Test()
{
	SeqList seqlist;
	InitSeqList(&seqlist);
	int  key[] = { 10,20,32,44,56,67 };
	char* value[] = { "aaa","bbb","ccc","ddd","eee","fff" };
	int len = sizeof(key) / sizeof(key[0]);
	for (int i = 1; i <= len; i++)
	{
		seqlist.data[i].key = key[i - 1];
		seqlist.data[i].value = (char*)malloc(sizeof(char) * 20);
		strcpy(seqlist.data[i].value, value[i - 1]);
		seqlist.length++;
	}
	PrintSeqList(&seqlist);

	printf("˳�����:");
	int SearchKey = 44;
	int pos1 = SearchSeqList2(&seqlist, SearchKey);
	printf("SearchKey = %d; pos = %d\n", SearchKey,pos1);
	printf("���ֲ���:");
	int pos2 = SearchSeqListBinary(&seqlist, SearchKey);
	printf("SearchKey = %d; pos = %d\n", SearchKey, pos2);
}




int main()
{
	Test();
	return 0;
}