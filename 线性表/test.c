#include"SeqList.h"

int main()
{
	ElemType dataArray[] = { {1,"�����"} ,{2,"ɳɮ"} ,{3,"��˽�"} ,{4,"��ɮ"} };
	SeqList seqlist;
	InitList(&seqlist, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
	PrintList(&seqlist);
	
	ElemType* deletement;
	deletement =  DeleteElement(&seqlist, 1);
	printf("ɾ����\n");
	PrintList(&seqlist);
	printf("��ɾ����Ԫ�أ�\n");
	printf("%d  %s \n", deletement->id, deletement->name);
}