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
//���
State OfferSeqQueue(SeqQueue* seqqueue, ElementType element)
{
	if (IsSeqQueueFull(seqqueue))
	{
		return STATE_FALLD;//�������������ʧ��
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
	//��ͷָ��������βָ����ͬ������Ϊ��
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