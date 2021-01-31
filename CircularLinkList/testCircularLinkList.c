#include"CircularLinkList.h"

int main()
{
	printf("初始化!\n");
	ElementType dataarray[] = { {1,"秦始皇"} ,{3,"汉高祖"} ,{5,"唐高祖"} ,{7,"宋高祖"} };
	CircularLinkList cll;
	cll.length = 0;
	InitCLL(&cll, dataarray, sizeof(dataarray) / sizeof(dataarray[0]));
	PrintCLL(&cll);
	printf("插入!\n");
	ElementType element = { 4,"汉武帝" };
	InsertCLL(&cll, 3, element);
	PrintCLL(&cll);

	ElementType Delelement =  DeleteCLL(&cll, 2);
	printf("删除的结点：%d\t%s\n",Delelement.id,Delelement.name);
	PrintCLL(&cll);

	ElementType elem;
	elem.id = 5;
	elem.name = "唐高祖";
	CircularNode* node = GetCLLNode(&cll, elem);
	printf("从汉高祖开始遍历\n");
	PrintCLLbyNode(&cll, node);
}