#include<iostream>
using namespace std;
#include<stack>
#include<vector>
//节点
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
}TreeNode, * BiTree;
//创建二叉树
void CreatBiTree(BiTree* root)
{
	int num;
	cin >> num;
	if (num == -1) *root = NULL;
	else
	{
		*root = new TreeNode(num);
		CreatBiTree(&(*root)->left);
		CreatBiTree(&(*root)->right);
	}
}
//前序遍历-递归法
void preorder1(BiTree root)
{
	if (!root) return;
	cout << root->val << "->";
	preorder1(root->left);
	preorder1(root->right);
}
//前序遍历 非递归
void preorder2(TreeNode* root)
{
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* temp = s.top();
		s.pop();
		if (temp != NULL)
		{
			cout << temp->val << "->";
		}
		else
		{
			continue;
		}
		s.push(temp->right);
		s.push(temp->left);
	}
}
//中序遍历  递归法
void inorder1(TreeNode* root)
{
	if (!root) return;
	inorder1(root->left);
	cout << root->val << "->";
	inorder1(root->right);
}
//非递归
void inorder2(TreeNode* root)
{
	stack<TreeNode*> s;
	TreeNode* cur = root;
	while (!s.empty() || cur != NULL)
	{
		if (cur != NULL)
		{
			s.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = s.top();
			s.pop();
			cout << cur->val << "->";
			cur = cur->right;
		}
	}
}
//后续遍历递归
void postorder1(TreeNode* root)
{
	if (!root) return;
	postorder1(root->left);
	postorder1(root->right);
	cout << root->val << "->";
}
//后续遍历非递归
void postorder2(TreeNode* root)
{
	vector<int> ret;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* temp = s.top();
		s.pop();
		if (temp != NULL)
		{
			ret.push_back(temp->val);
		}
		else
		{
			continue;
		}
		s.push(temp->left);
		s.push(temp->right);
	}
	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << "->";
	}
}
int main()
{
	BiTree root;
	cout << "请输入节点：";
	CreatBiTree(&root);
	cout << "前序遍历";
	preorder2(root);
	cout << endl;
	cout << "中序遍历";
	inorder2(root);
	cout << endl;
	cout << "后续遍历";
	postorder1(root);
	return 0;
}

