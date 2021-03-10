#define _CRT_SECURE_NO_WARNINGS
#include"MatrixGraph.h"


//创建无向图
int CreatUDG(MatrixGraph* G)
{
	G->type = UDG;   //设置类型为无向图
	printf("请输入无向图的顶点数：");
	scanf("%d", &G->verTexCount);
	printf("请输入无向图的边数：");
	scanf("%d", &G->arcCount);
	printf("依次输入顶点信息\n");
	for (int i = 0; i < G->verTexCount; i++)
	{
		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
		printf("顶点%d:",i);
		scanf("%s", G->verTexs[i]);
	}
	//初始化邻接矩阵，所有边的权值=0
	for (int i = 0; i < G->verTexCount; i++)
	{
		for (int j = 0; j < G->verTexCount; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	printf("请输入顶点和邻接顶点信息，构建邻接矩阵\n");
	for (int i = 0; i < G->verTexCount; i++)
	{
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
		printf("顶点：");
		scanf("%s", vex1);
		printf("邻接点：");
		scanf("%s", vex2);
		//分别获得两个顶点在顶点数组中的坐标
		int x = LocatVex(G, vex1);
		int y = LocatVex(G, vex2);
		if (x == -1 || y == -1)
		{
			return ERROR;
		}
		G->arcs[x][y] = 1;
		G->arcs[y][x] = 1;     //无向图邻接矩阵是对称的
		free(vex1);
		free(vex2);
	}
	return OK;
}

int LocatVex(MatrixGraph* G, VerTexType vex)
{
	int index = 0;
	while (index < G->verTexCount)
	{
		if (strcmp(G->verTexs[index], vex) == 0)
		{
			break;
		}
		index++;
	}
	return index == G->verTexCount ? -1 : index;
}

void TestMatrixGraph()
{
	MatrixGraph G;
	int status = CreatUDG(&G);
	if (status == ERROR)
	{
		printf("创建失败\n");
		return;
	}
	printf("打印图的邻接矩阵\n");
	printf("\t");
	for (int i = 0; i < G.verTexCount; i++)
	{
		printf("\t%s", G.verTexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G.verTexCount; i++)
	{
		printf("\t%s", G.verTexs[i]);
		for (int j = 0; j < G.verTexCount; j++)
		{
			printf("\t%d", G.arcs[i][j]);
		}
		printf("\n");

	}
}


int main()
{
	TestMatrixGraph();
	return 0;
}