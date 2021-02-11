#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 255
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char* name;
}ELementType;

//定义栈的顺序存储模式
typedef struct SeqStack
{
	ELementType elements[MAX_SIZE];  //顺序栈中用来存放数据元素的数组
	int top;           //栈顶(数组中的下表)，如果为-1则证明栈为空
	int length;        //当前栈的元素个数
}SeqStack;
//初始化
void InitSeqStack(SeqStack* seqstack);
//压栈,返回压入的结果（true/false）
int PushSeqStack(SeqStack* seqstack, ELementType element);
//出栈,以指针方式返回出栈的元素
int PopSeqStack(SeqStack* seqstack, ELementType* element);
//清空栈
void ClearSeqStack(SeqStack* seqstack);
//栈是否为空  top==-1
void IsEmptySeqStack(SeqStack* seqstack);
//返回栈顶元素
void TopSeqStack(SeqStack* seqstack, ELementType* element);
//打印栈内元素
void PrintSeqStack(SeqStack*seqstack);
#endif
