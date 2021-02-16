#include"SeqQueueh.h"



void InitSeqQueue(SeqQueue* seqqueue)
{
	if (seqqueue == NULL)
	{
		seqqueue = (SeqQueue*)malloc(sizeof(SeqQueue));
	}
		seqqueue->length = 0;
		seqqueue->front = 0;
		seqqueue->rear = 0;
}
//入队
State OfferSeqQueue(SeqQueue* seqqueue, ElementType element)
{
	if (IsSeqQueueFull(seqqueue))
	{
		return STATE_FALLD;//队列已满，入队失败
	}
	seqqueue->data[seqqueue->rear] = element;
	seqqueue->rear = (seqqueue->rear + 1) % MAX_SIZE;
	seqqueue->length++;
	return STATE_OK;
}
State PollSeqQueue(SeqQueue* seqqueue, ElementType* element)
{
	if (IsSeqQueueEmpty(seqqueue))
	{
		return STATE_FALLD;
	}
	*element = seqqueue->data[seqqueue->front];
	seqqueue->front = (seqqueue->front + 1) % MAX_SIZE;
	seqqueue->length--;
	return STATE_OK;
}
State IsSeqQueueEmpty(SeqQueue* seqqueue)
{
	//对头指针如果与队尾指针相同，队列为空
	return seqqueue->front == seqqueue->rear ? TURE : FALSE;
}
State IsSeqQueueFull(SeqQueue* seqqueue)
{
	if ((seqqueue->rear + 1) % MAX_SIZE == seqqueue->front)
	{
		return TURE;
	}
	return FALSE;
}