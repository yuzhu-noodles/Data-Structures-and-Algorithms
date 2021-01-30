#include"LinkList.h"

int main()
{   
	printf("初始化!\n");
	ElementType dataarray[] = { {1,"秦始皇"} ,{3,"汉高祖"} ,{5,"唐高祖"} ,{7,"宋高祖"} };
	LinkList linklist;
	linklist.length = 0;
	InitLinkList(&linklist, dataarray, sizeof(dataarray) / sizeof(dataarray[0]));
	PrintLinkList(&linklist);

	printf("插入!\n");
	ElementType element = { 4,"汉武帝" };
	InsertLinkList(&linklist, 3, element);
	PrintLinkList(&linklist);

	printf("判断是否为空链表：\n");
	if (IsLinkListEmpty(&linklist))
	{
		printf("该链表不为空\n");
	}
	else
	{
		printf("该链表为空\n");
	}

	printf("得到链表某一位置元素：\n");
	ElementType poselement = GetLinkListElem(&linklist,1);
	printf("%d\t%s\n", poselement.id, poselement.name);

	printf("删除某一位置元素：\n");
	DeleteLinkList(&linklist, 2);
	PrintLinkList(&linklist);

	printf("清空链表：\n");
	ClearLinkList(&linklist);
	PrintLinkList(&linklist);

}