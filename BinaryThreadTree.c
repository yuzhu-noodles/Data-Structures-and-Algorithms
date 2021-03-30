#include<stdio.h>
#include<stdlib.h>

//Link(0)，表示指向左右孩子的指针
//Thread(1),表示指向前驱后继的线索
typedef enum{Link,Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
    PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;

BiThrTree pre; //全局变量，保存上一个访问的结点

void Init(BiThrTree* tree)
{
	(*tree) = NULL;
}

//创建二叉树
void CreatBTT(BiThrTree* tree)
{
	char c;
	scanf("%c",&c);
	if(c == ' ')
		(*tree) = NULL;
	else
	{
		(*tree) = (BiThrTree)malloc(sizeof(BiThrNode));
		if(*tree == NULL)
			return;
		else
		{
			(*tree)->data = c;
			(*tree)->lchild = NULL;
			(*tree)->rchild = NULL;
			CreatBTT(&(*tree)->lchild);
			CreatBTT(&(*tree)->rchild);
		}
	}
}

//中序遍历线索化
void InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->lchild); //递归左孩子线索化

		if(!T->lchild)    //如果该结点没有左孩子，就把ltag设置为Thread,把lchild指向刚刚访问的结点；
		{
			T->ltag = Thread;
			T->lchild = pre;
		}
		if(!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

void InOrderThreading(BiThrTree* p,BiThrTree T)
{
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if(!T)
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}

}

void InOrderPrint(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;

	while(p != T)
	{
		while(p->ltag == Link)
		{
			p = p->lchild;
		}
		printf("%c",p->data);
		while(p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c",p->data);
		}
		p = p->rchild;
	}
}


int main()
{
	BiThrTree P,T = NULL ;
	CreatBTT(&T);
	InOrderThreading(&P,T);
    printf("中序遍历：");
    InOrderPrint(P);
	printf("\n");
	return 0;
}






