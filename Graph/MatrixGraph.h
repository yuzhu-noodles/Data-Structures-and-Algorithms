#include"GraphModel.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	VerTexType verTexs[MAX_VERTEX];    //��������
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];  //�ڽӾ���
	int verTexCount;             //ͼ�Ķ�����
	int arcCount;                //ͼ�ı�/����
	GraphType type;                //ͼ������
}MatrixGraph;

//��������ͼ
int CreatUDG(MatrixGraph* G);
//����ĳ�������ڶ��㼯���е��±�
int LocatVex(MatrixGraph* G, VerTexType vex);

void TestMatrixGraph();
