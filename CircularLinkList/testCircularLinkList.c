#include"CircularLinkList.h"

int main()
{
	printf("��ʼ��!\n");
	ElementType dataarray[] = { {1,"��ʼ��"} ,{3,"������"} ,{5,"�Ƹ���"} ,{7,"�θ���"} };
	CircularLinkList cll;
	cll.length = 0;
	InitCLL(&cll, dataarray, sizeof(dataarray) / sizeof(dataarray[0]));
	PrintCLL(&cll);
	printf("����!\n");
	ElementType element = { 4,"�����" };
	InsertCLL(&cll, 3, element);
	PrintCLL(&cll);

	ElementType Delelement =  DeleteCLL(&cll, 2);
	printf("ɾ���Ľ�㣺%d\t%s\n",Delelement.id,Delelement.name);
	PrintCLL(&cll);

	ElementType elem;
	elem.id = 5;
	elem.name = "�Ƹ���";
	CircularNode* node = GetCLLNode(&cll, elem);
	printf("�Ӻ����濪ʼ����\n");
	PrintCLLbyNode(&cll, node);
}