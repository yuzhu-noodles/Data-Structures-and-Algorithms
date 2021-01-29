#include"SeqList.h"

int main()
{
	ElemType dataArray[] = { {1,"ËïÎò¿Õ"} ,{2,"É³É®"} ,{3,"Öí°Ë½ä"} ,{4,"ÌÆÉ®"} };
	SeqList seqlist;
	InitList(&seqlist, dataArray, sizeof(dataArray)/sizeof(dataArray[0]));
	PrintList(&seqlist);
	
	ElemType* deletement;
	deletement =  DeleteElement(&seqlist, 1);
	printf("É¾³ýºó£º\n");
	PrintList(&seqlist);
	printf("±»É¾³ýµÄÔªËØ£º\n");
	printf("%d  %s \n", deletement->id, deletement->name);
}