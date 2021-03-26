#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *left,*right;
}TreeNode,*BiTree;

//指针f指向T的双亲，其初始值为NULL
//若查找成功，则指针p指向该元素结点，并返回true
//否则指针p指向查找路径上访问的最后一个结点，并返回false
bool SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
    {
		*p = f;
		return false;
	}
	else if(T->val == key)
	{
		*p = T;
		return true;
	}
	else if(T->val > key)
	{
		return SearchBST(T->left,key,T,p);
	}
	else
	{
		return SearchBST(T->right,key,T,p);
	}
}

//插入
bool InsertBST(BiTree *T, int key)
{
	BiTree p,s;
	if(!SearchBST(*T,key,NULL,&p))
	{
		s = (BiTree)malloc(sizeof(TreeNode));
		s->val = key;
		s->left = s->right = NULL;
		if(!p)
		{
			*T = s;
		}
		else if(key < p->val)
		{
			p->left = s;
		}
		else
		{
			p->right = s;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Delete(BiTree *p);
//删除
bool DeleteBST(BiTree *T,int key)
{
	if(!*T)
	{
		return false;
	}
	else
	{
		if((*T)->val == key)
		{
			return Delete(T);
		}
		else if(key < (*T)->val)
		{
			return DeleteBST(&(*T)->left,key);
		}
		else
		{
			return DeleteBST(&(*T)->right,key);
		}
	}
}

bool Delete(BiTree *p)
{
	BiTree q,s;
	if((*p)->right == NULL)
	{
		q =*p;
		*p = (*p)->left;
		free(q);
	}
	else if((*p)->left == NULL)
	{
		q =*p;
		*p = (*p)->right;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->left;
		while(s->right)
		{
			q = s;
			s = s->right;
		}
		(*p)->val = s->val;
		if(q != *p)
		{
			q->right = s->left;
		}
		else
		{
			q->left = s->left;
		}
		free(s);
	}
	return true;
}


//中序遍历
void OrderPrint(BiTree T)
{
	if(!T)
	{
		return;
	}
	OrderPrint(T->left);
	printf("%d ",T->val);
	OrderPrint(T->right);
}


int main()
{
	int num[5] = {3,4,2,5,8};
	BiTree T = NULL;
	int i =0;
	for(i = 0;i<5;i++)
	{
		InsertBST(&T,num[i]);
	}
	printf("中序遍历：");
	OrderPrint(T);
    printf("\n");
	printf("删除5之后：");
	DeleteBST(&T,5);
	OrderPrint(T);
	return 0;
}




