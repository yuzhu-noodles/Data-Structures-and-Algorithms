#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6
#define STATE_OK 1
#define STATE_FALLD -1
#define TURE 1
#define FALSE 0

typedef int State;  //�������������ר������1��ʾ״̬

typedef struct
{
	int id;
	char* name;
}ElementType;
typedef struct
{
	ElementType data[MAX_SIZE];
	int front; //��ͷָ��
	int rear;  //��βָ��
	int length;
}SeqQueue;
//��ʼ��
void InitSeqQueue(SeqQueue* seqqueue);
//���
State OfferSeqQueue(SeqQueue* seqqueue, ElementType element);
//����
State PollSeqQueue(SeqQueue* seqqueue, ElementType* element);
//��TURE/FALSE�ķ�ʽ���ش���Ķ����Ƿ�Ϊ��
State IsSeqQueueEmpty(SeqQueue* seqqueue);

State IsSeqQueueFull(SeqQueue* seqqueue);
#endif
