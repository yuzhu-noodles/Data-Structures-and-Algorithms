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
			cout << "��������";
			Creat(&(*tree)->LChild);
			cout << "��������";
			Creat(&(*tree)->RChild);
		}
	}
}
//ʹ�ö���ʵ��
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

//ʹ������ʵ��
void FloorPrint_Array(BiTree tree)
{
	int in = 0;
	int out = 0;
	BiTree temp[MAX_SIZE];
	temp[in++] = tree;  //������ڵ�
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
	cout << "������ڵ㣺";
	Creat(&tree);
	/*FloorPrint_Queue(tree);*/
	FloorPrint_Array(tree);
	system("pause");
	return 0;
}