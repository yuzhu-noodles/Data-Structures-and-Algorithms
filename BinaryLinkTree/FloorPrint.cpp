#include<iostream>
using namespace std;
#include<queue>
#define MAX_SIZE 255

typedef struct TreeNode
{
	char data;
	struct TreeNode* LChild;
	struct TreeNode* RChild;

}TreeNode,*BiTree;

void InitTree(BiTree* tree)
{
	(*tree) = NULL;
}

void Creat(BiTree* tree)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		*tree = NULL;
	}
	else
	{
		*tree = (BiTree)malloc(sizeof(TreeNode));
		if (NULL == (*tree))
		{
			return;
		}
		else
		{
			(*tree)->data = ch;
			(*tree)->LChild = NULL;
			(*tree)->RChild = NULL;
			cout << "左子树：";
			Creat(&(*tree)->LChild);
			cout << "右子树：";
			Creat(&(*tree)->RChild);
		}
	}
}
//使用队列实现
void FloorPrint_Queue(BiTree &tree)
{
	queue<BiTree> q;
	if (tree != NULL)
	{
		q.push(tree);
	}
	while (q.empty() == false)
	{
		cout << q.front()->data << "->";
		if (q.front()->LChild != NULL)
		{
			q.push(q.front()->LChild);
		}
		if (q.front()->RChild != NULL)
		{
			q.push(q.front()->RChild);
		}
		q.pop();
	}
}

//使用数组实现
void FloorPrint_Array(BiTree tree)
{
	int in = 0;
	int out = 0;
	BiTree temp[MAX_SIZE];
	temp[in++] = tree;  //储存根节点
	while (in >out)
	{
		if (temp[out])
		{
			cout << temp[out]->data << "-->";
			temp[in++] = temp[out]->LChild;
			temp[in++] = temp[out]->RChild;
		}
		out++;
	}

}

int main()
{
	BiTree tree;
	InitTree(&tree);
	cout << "输入跟节点：";
	Creat(&tree);
	/*FloorPrint_Queue(tree);*/
	FloorPrint_Array(tree);
	system("pause");
	return 0;
}