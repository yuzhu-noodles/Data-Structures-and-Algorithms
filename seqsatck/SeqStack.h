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

//����ջ��˳��洢ģʽ
typedef struct SeqStack
{
	ELementType elements[MAX_SIZE];  //˳��ջ�������������Ԫ�ص�����
	int top;           //ջ��(�����е��±�)�����Ϊ-1��֤��ջΪ��
	int length;        //��ǰջ��Ԫ�ظ���
}SeqStack;
//��ʼ��
void InitSeqStack(SeqStack* seqstack);
//ѹջ,����ѹ��Ľ����true/false��
int PushSeqStack(SeqStack* seqstack, ELementType element);
//��ջ,��ָ�뷽ʽ���س�ջ��Ԫ��
int PopSeqStack(SeqStack* seqstack, ELementType* element);
//���ջ
void ClearSeqStack(SeqStack* seqstack);
//ջ�Ƿ�Ϊ��  top==-1
void IsEmptySeqStack(SeqStack* seqstack);
//����ջ��Ԫ��
void TopSeqStack(SeqStack* seqstack, ELementType* element);
//��ӡջ��Ԫ��
void PrintSeqStack(SeqStack*seqstack);
#endif
