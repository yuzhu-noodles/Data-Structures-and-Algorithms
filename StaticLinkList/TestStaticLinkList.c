#include"StaticLinkList.h"

int main()
{
	StaticLinkList sll;
	InitStaticLinkList(sll);
	PrintStaticLinkList(sll);
	ElementType element1;
	element1.id = 123;
	element1.name = "ËïÎò¿Õ";
	InsertStaticLinkList(sll, 1, element1);
	ElementType element2;
	element2.id = 456;
	element2.name = "É³ºÍÉĞ";
	InsertStaticLinkList(sll, 1, element2);
	ElementType element3;
	element3.id = 789;
	element3.name = "Öí°Ë½ä";
	InsertStaticLinkList(sll, 1, element3);
	printf("²åÈëÔªËØºó£º\n");
	PrintStaticLinkList(sll);
	printf("É¾³ı2ºÅÔªËØ£º\n");
	deleteSLL(sll,2);
	PrintStaticLinkList(sll);
	return 0;
}