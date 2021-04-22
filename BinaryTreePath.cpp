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


//打印二叉树路径
class Solution {
public:
    //创建二叉树
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
    //回溯
    void backtracking(TreeNode* node, vector<int>& path, vector<string>& ret)
    {
        path.push_back(node->val);
        if (!node->left && !node->right) {  //截止条件
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
            backtracking(node->left, path, ret);  //递归
            path.pop_back();  //回溯
        }
        if (node->right) {
            backtracking(node->right, path, ret);  //递归
            path.pop_back();   //回溯
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
    cout << "请输入节点：";
    Solution S;
    S.CreatTree(&root);
    vector<string> ret = S.binaryTreePaths(root);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}