#include<iostream>
#include<vector>
#include<string>
using namespace std;

//给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。
//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址


class Solution {   //复原IP地址
private:
    vector<string> ret;
    bool isvalid(string& s, int begin, int end) //合法判断
    {
        if (begin > end) return false;
        if (s[begin] == '0' && begin != end) return false;
        int num = 0;
        for (int i = begin; i <= end; i++)
        {
            if (s[i] < '0' || s[i]>'9') return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) return false;
        }
        return true;
    }
    void backtracking(string& s, int startindex, int pointnum)
    {
        if (pointnum == 3) //记录点数
        {
            if (isvalid(s, startindex, s.size() - 1))  //判断第四段是否合法
            {
                ret.push_back(s);
            }
            return;
        }
        for (int i = startindex; i < s.size(); i++)
        {
            if (isvalid(s, startindex, i))
            {
                s.insert(s.begin() + i + 1, '.');
                pointnum++;
                backtracking(s, i + 2, pointnum);
                pointnum--;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12) return ret;
        backtracking(s, 0, 0);
        return ret;
    }
};

void test()
{
    Solution S;
    string s = "25525511135";
    vector<string> v = S.restoreIpAddresses(s);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
int main()
{
    test();
	return 0;
}