#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node* next;
}LinkList;

LinkList* Creat()
{
	int num;
	printf("请输入头结点：");
	scanf("%d", &num);
	LinkList* head = (LinkList*)malloc(sizeof(LinkList));
	head->val = num;
	head->next = NULL;
	LinkList* p = head;
	int n = 0;
	while (1)
	{
		printf("请输入结点：");
		scanf("%d", &n);
		if (n == -1)
			break;
		LinkList* temp = (LinkList*)malloc(sizeof(LinkList));
		temp->val = n;
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	//到此已经创建好单项链表
	p->next = head;
	return head;
}

void Print(LinkList* head)
{
	if (!head)
		return;
	int n = 0;
	while (n < 20)
	{
		printf("%d->", head->val);
		head = head->next;
		n++;
	}
}
//判断链表是否有环
int hasCycle(LinkList* head)
{
	if (!head)
		return 0;
	LinkList* fast = head;
	LinkList* slow = head;
	do
	{
		if (!fast || !fast->next)
			return 0;
		fast = fast->next->next;
		slow = slow->next;

	} while (fast != slow);
	return 1;
}

int main()
{
	LinkList* head = Creat();
	/*Print(head);*/
	int n = hasCycle(head);
	if (n == 0)
	{
		printf("该链表没有环");
	}
	else
	{
		printf("该链表有环");
	}
	return 0;
}
