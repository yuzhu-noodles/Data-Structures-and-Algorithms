#define _CRT_SECURE_NO_WARNINGS
#include"MatrixGraph.h"


//��������ͼ
int CreatUDG(MatrixGraph* G)
{
	G->type = UDG;   //��������Ϊ����ͼ
	printf("����������ͼ�Ķ�������");
	scanf("%d", &G->verTexCount);
	printf("����������ͼ�ı�����");
	scanf("%d", &G->arcCount);
	printf("�������붥����Ϣ\n");
	for (int i = 0; i < G->verTexCount; i++)
	{
		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
		printf("����%d:",i);
		scanf("%s", G->verTexs[i]);
	}
	//��ʼ���ڽӾ������бߵ�Ȩֵ=0
	for (int i = 0; i < G->verTexCount; i++)
	{
		for (int j = 0; j < G->verTexCount; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	printf("�����붥����ڽӶ�����Ϣ�������ڽӾ���\n");
	for (int i = 0; i < G->verTexCount; i++)
	{
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
		printf("���㣺");
		scanf("%s", vex1);
		printf("�ڽӵ㣺");
		scanf("%s", vex2);
		//�ֱ������������ڶ��������е�����
		int x = LocatVex(G, vex1);
		int y = LocatVex(G, vex2);
		if (x == -1 || y == -1)
		{
			return ERROR;
		}
		G->arcs[x][y] = 1;
		G->arcs[y][x] = 1;     //����ͼ�ڽӾ����ǶԳƵ�
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
		printf("����ʧ��\n");
		return;
	}
	printf("��ӡͼ���ڽӾ���\n");
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