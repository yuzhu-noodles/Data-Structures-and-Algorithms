#include"LinkList.h"

int main()
{   
	printf("��ʼ��!\n");
	ElementType dataarray[] = { {1,"��ʼ��"} ,{3,"������"} ,{5,"�Ƹ���"} ,{7,"�θ���"} };
	LinkList linklist;
	linklist.length = 0;
	InitLinkList(&linklist, dataarray, sizeof(dataarray) / sizeof(dataarray[0]));
	PrintLinkList(&linklist);

	printf("����!\n");
	ElementType element = { 4,"�����" };
	InsertLinkList(&linklist, 3, element);
	PrintLinkList(&linklist);

	printf("�ж��Ƿ�Ϊ������\n");
	if (IsLinkListEmpty(&linklist))
	{
		printf("������Ϊ��\n");
	}
	else
	{
		printf("������Ϊ��\n");
	}

	printf("�õ�����ĳһλ��Ԫ�أ�\n");
	ElementType poselement = GetLinkListElem(&linklist,1);
	printf("%d\t%s\n", poselement.id, poselement.name);

	printf("ɾ��ĳһλ��Ԫ�أ�\n");
	DeleteLinkList(&linklist, 2);
	PrintLinkList(&linklist);

	printf("�������\n");
	ClearLinkList(&linklist);
	PrintLinkList(&linklist);

}