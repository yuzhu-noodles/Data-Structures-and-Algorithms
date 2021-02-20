#ifndef SEQTREE_H
#define SEQTREE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//�������
#define MAX_SIZE 1024

//����˳��������
typedef char SeqTree[MAX_SIZE];
//��ʼ��
void InitSeqTree(SeqTree tree);
//������ȫ��������iΪ�����е��±�
void GreatSeqTree(SeqTree tree, int i);
//��ȡ���ĸ����Ԫ��
char GetSeqTreeRoot(SeqTree tree);
//��ȡ���Ľ������
int GetSeqTreeLength(SeqTree tree);
//��ȡ�������
int GetSeqTreeDepth(SeqTree tree);
#endif
