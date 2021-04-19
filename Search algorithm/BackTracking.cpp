#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��������
//�㷨ģ��
//void  backtracking(����)
//{
//	if (��ֹ����)
//	{
//		��Ž��;
//		return;
//	}
//	for (���㼯���е�Ԫ��)
//	{
//		������;
//		backtracking();�ݹ�
//	    ���ݣ�����������
//	}
//}

class Solution1  //����1...n���п������kg���������
{
private:
	vector<vector<int> > ret; //����ȫ�����
	vector<int> path;  //����·��
	void backtracking(int n, int k, int startindex)
	{
		//��ֹ����
		if (path.size() == k)
		{
			ret.push_back(path);
			return;
		}
		for (int i = startindex; i <= n; i++)
		{
			path.push_back(i);
			backtracking(n, k, startindex + 1);//�ݹ�
			path.pop_back(); //����
		}
	}
public:
	vector<vector<int> > combine(int n, int k)
	{
		backtracking(n, k, 1);
		return ret;
	}
};

class Solution2  //�绰�������ĸ���
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
		int digit = digits[index] - '0';  //��indexָ���ַ�ת��Ϊint
		string letter = lettermap[digit]; //ȡ���ֶ�Ӧ���ַ���
		for (int i = 0; i < letter.size(); i++)
		{
			s.push_back(letter[i]);
			backtracking(digits, index + 1);//�ݹ�
			s.pop_back();               //����
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
