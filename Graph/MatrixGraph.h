#include"GraphModel.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	VerTexType verTexs[MAX_VERTEX];    //定点数组
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];  //邻接矩阵
	int verTexCount;             //图的顶点数
	int arcCount;                //图的边/弧数
	GraphType type;                //图的类型
}MatrixGraph;

//创建无向图
int CreatUDG(MatrixGraph* G);
//返回某个顶点在顶点集合中的下标
int LocatVex(MatrixGraph* G, VerTexType vex);

void TestMatrixGraph();
