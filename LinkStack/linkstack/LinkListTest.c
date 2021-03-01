#include"LinkList1.h"


LinkStack* push(LinkStack* linkstack, int n)
{
	LinkStack* node = (LinkStack*)malloc(sizeof(LinkStack));
	node->data = n;
	node->next = linkstack;
	linkstack = node;
	return linkstack;
}
LinkStack* pop(LinkStack* linkstack)
{
	if (linkstack)
	{
		LinkStack* p = linkstack;
		linkstack = linkstack->next;
		printf("出栈元素：%d ", p->data);
		if (linkstack)
		{
			printf("新栈顶元素：%d\n", linkstack->data);
		}
		else
		{
			printf("栈已空\n");
		}
		free(p);
	}
	else
	{
		printf("栈内没有元素\n");
		return linkstack;
	}
	return linkstack;
}

void test()
{
	LinkStack* linkstack = NULL;
	linkstack = push(linkstack, 4);
	linkstack = push(linkstack, 3);
	linkstack = push(linkstack, 2);

	linkstack = pop(linkstack);
	linkstack = pop(linkstack);
	linkstack = pop(linkstack);
	linkstack = pop(linkstack);
}
int main()
{
	test();
	return 0;
}