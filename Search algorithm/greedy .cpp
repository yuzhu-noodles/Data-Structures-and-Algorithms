#include<iostream>
using namespace std;
#include<vector>

//��ν̰�ģ����Ǿֲ������Ƴ�ȫ�����ţ������Ҳ������������˵Ļ���

//����һ���Ǹ��������� nums �������λ������� ��һ���±� ��
//�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//�ж����Ƿ��ܹ��������һ���±ꡣ
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        //̰��
        //ÿ�ζ�ȡ�����Ծ����ֱ����������>=nums�ķ�Χ
        if (nums.size() == 1) return true; //ֻ��һ������ʱ�򣬿϶����Ե���
        int maxjump = 0;
        for (int i = 0; i <= maxjump; i++)     
        {
            maxjump = max(nums[i] + i, maxjump);  //���������
            if (maxjump >= nums.size() - 1) return true;
        }
        return false;
    }
};

//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        //̰���㷨  O(n)
        if (nums.size() == 1) return nums[0];
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max) max = sum;  //����max
            if (sum <= 0)              //�������nums[i]С��=0����nums[i+1]�������
            {
                sum = 0;
                continue;
            }
        }
        return max;
    }
};
void test1()
{
    int a[5] = { 2,3,1,1,4 };
    vector<int> nums(a,a+5);
    Solution1 S1;
    cout << S1.canJump(nums) << endl;;
}
void test2()
{
    int a[9] = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> nums(a, a + 9);
    Solution2 S2;
    int max = S2.maxSubArray(nums);
    cout << "���ͣ�" << max << endl;
}
int main()
{
    test1();
    test2();
	return 0;
}