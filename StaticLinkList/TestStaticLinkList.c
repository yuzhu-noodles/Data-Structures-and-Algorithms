#include"StaticLinkList.h"

int main()
{
	StaticLinkList sll;
	InitStaticLinkList(sll);
	PrintStaticLinkList(sll);
	ElementType element1;
	element1.id = 123;
	element1.name = "�����";
	InsertStaticLinkList(sll, 1, element1);
	ElementType element2;
	element2.id = 456;
	element2.name = "ɳ����";
	InsertStaticLinkList(sll, 1, element2);
	ElementType element3;
	element3.id = 789;
	element3.name = "��˽�";
	InsertStaticLinkList(sll, 1, element3);
	printf("����Ԫ�غ�\n");
	PrintStaticLinkList(sll);
	printf("ɾ��2��Ԫ�أ�\n");
	deleteSLL(sll,2);
	PrintStaticLinkList(sll);
	return 0;
}