#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6
#define STATE_OK 1
#define STATE_FALLD -1
#define TURE 1
#define FALSE 0

typedef int State;  //给整形其别名，专门用来1表示状态

typedef struct
{
	int id;
	char* name;
}ElementType;
typedef struct
{
	ElementType data[MAX_SIZE];
	int front; //队头指针
	int rear;  //队尾指针
	int length;
}SeqQueue;
//初始化
void InitSeqQueue(SeqQueue* seqqueue);
//入队
State OfferSeqQueue(SeqQueue* seqqueue, ElementType element);
//出队
State PollSeqQueue(SeqQueue* seqqueue, ElementType* element);
//以TURE/FALSE的方式返回传入的队列是否为空
State IsSeqQueueEmpty(SeqQueue* seqqueue);

State IsSeqQueueFull(SeqQueue* seqqueue);
#endif
