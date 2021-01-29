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
//初始化
void InitList(SeqList* seqlist, ElemType* elemArray, int length);
//插入
void InsertElement(SeqList* seqlist, int index, ElemType element);
//打印
void PrintList(SeqList* seqlist);
//查找
ElemType* FindElement(SeqList* seqlist, int index);
//删除  返回删除的元素
ElemType* DeleteElement(SeqList* seqlist, int index);

#endif
