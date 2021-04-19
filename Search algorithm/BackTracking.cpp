#include<iostream>
#include<vector>
#include<string>
using namespace std;

//回溯问题
//算法模板
//void  backtracking(参数)
//{
//	if (终止条件)
//	{
//		存放结果;
//		return;
//	}
//	for (本层集合中的元素)
//	{
//		处理结点;
//		backtracking();递归
//	    回溯，撤销处理结果
//	}
//}

class Solution1  //返回1...n中有可能组成kg个数的组合
{
private:
	vector<vector<int> > ret; //储存全部结果
	vector<int> path;  //储存路径
	void backtracking(int n, int k, int startindex)
	{
		//终止条件
		if (path.size() == k)
		{
			ret.push_back(path);
			return;
		}
		for (int i = startindex; i <= n; i++)
		{
			path.push_back(i);
			backtracking(n, k, startindex + 1);//递归
			path.pop_back(); //回溯
		}
	}
public:
	vector<vector<int> > combine(int n, int k)
	{
		backtracking(n, k, 1);
		return ret;
	}
};

class Solution2  //电话号码的字母组合
{
private:
	const string lettermap[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz",
	};
	vector<string> ret;
	string s;
	void backtracking(const string &digits, int index)
	{
		if (digits.size() == index)
		{
			ret.push_back(s);
			return;
		}
		int digit = digits[index] - '0';  //将index指向字符转化为int
		string letter = lettermap[digit]; //取数字对应的字符集
		for (int i = 0; i < letter.size(); i++)
		{
			s.push_back(letter[i]);
			backtracking(digits, index + 1);//递归
			s.pop_back();               //回溯
		}

	}
public:
	vector<string> letterCominations(string digits)
	{
		if (digits.size() == 0) return ret;
		backtracking(digits, 0);
		return ret;
	}

};

void test1()
{
	Solution1 S1;
	vector<vector<int> > ret = S1.combine(4, 2);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}

void test2()
{
	Solution2 S2;
	string digits = "23";
	vector<string> ret = S2.letterCominations(digits);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
		cout << endl;
	}
}
int main()
{
	test1();
	test2();
	return 0;
}
