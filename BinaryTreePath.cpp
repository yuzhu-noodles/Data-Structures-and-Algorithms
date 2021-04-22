#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode, * BiTree;


//��ӡ������·��
class Solution {
public:
    //����������
    void CreatTree(BiTree* root)
    {
        int num = 0;
        cin >> num;
        if (num == -1) (*root) = NULL;
        else
        {
            *root = new TreeNode(num);
            CreatTree(&(*root)->left);
            CreatTree(&(*root)->right);
        }
    }
public:
    //����
    void backtracking(TreeNode* node, vector<int>& path, vector<string>& ret)
    {
        path.push_back(node->val);
        if (!node->left && !node->right) {  //��ֹ����
            string paths;
            int size = path.size();
            for (int i = 0; i < size - 1; i++) {
                paths += to_string(path[i]);
                paths += "->";
            }
            paths += to_string(path[size - 1]);
            ret.push_back(paths);
        }
        if (node->left) {
            backtracking(node->left, path, ret);  //�ݹ�
            path.pop_back();  //����
        }
        if (node->right) {
            backtracking(node->right, path, ret);  //�ݹ�
            path.pop_back();   //����
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ret;
        if (!root) return ret;
        backtracking(root, path, ret);
        return ret;
    }
};

int main()
{
    BiTree root = new TreeNode(0);
    cout << "������ڵ㣺";
    Solution S;
    S.CreatTree(&root);
    vector<string> ret = S.binaryTreePaths(root);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}