#include<iostream>
using namespace std;
#include<queue>

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
			exit(0);
		}
		else
		{
			(*tree)->data = ch;
			(*tree)->LChild = NULL;
			(*tree)->RChild = NULL;
			cout << "��������";
			Creat(&(*tree)->LChild);
			cout << "��������";
			Creat(&(*tree)->RChild);
		}
	}
}

void FloorPrint(BiTree &tree)
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



int main()
{
	BiTree tree;
	InitTree(&tree);
	cout << "������ڵ㣺";
	Creat(&tree);
	FloorPrint(tree);
	system("pause");
	return 0;
}