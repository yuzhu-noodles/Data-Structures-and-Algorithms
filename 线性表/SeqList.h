#ifndef ELEMENTTYPE_H
#define ELEMENTTYPE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 255

typedef struct
{
	int id;
	char* name;
}ElemType;
typedef struct
{
	ElemType datas[MAXSIZE];
	int length;
}SeqList;
//��ʼ��
void InitList(SeqList* seqlist, ElemType* elemArray, int length);
//����
void InsertElement(SeqList* seqlist, int index, ElemType element);
//��ӡ
void PrintList(SeqList* seqlist);
//����
ElemType* FindElement(SeqList* seqlist, int index);
//ɾ��  ����ɾ����Ԫ��
ElemType* DeleteElement(SeqList* seqlist, int index);

#endif
