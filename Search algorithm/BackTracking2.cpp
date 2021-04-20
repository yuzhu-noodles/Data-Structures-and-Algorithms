#include<iostream>
#include<vector>
#include<string>
using namespace std;

//����һ��ֻ�������ֵ��ַ��������Ա�ʾһ�� IP ��ַ���������п��ܴ� s ��õ� ��Ч IP ��ַ ������԰��κ�˳�򷵻ش𰸡�
//��Ч IP ��ַ �������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0��������֮���� '.' �ָ���
//���磺"0.1.2.201" �� "192.168.1.1" �� ��Ч IP ��ַ������ "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" �� ��Ч IP ��ַ


class Solution {   //��ԭIP��ַ
private:
    vector<string> ret;
    bool isvalid(string& s, int begin, int end) //�Ϸ��ж�
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
        if (pointnum == 3) //��¼����
        {
            if (isvalid(s, startindex, s.size() - 1))  //�жϵ��Ķ��Ƿ�Ϸ�
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