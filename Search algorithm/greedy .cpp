#include<iostream>
using namespace std;
#include<vector>

//所谓贪心，就是局部最优推出全局最优，并且找不出反例（别人的话）

//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标。
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        //贪心
        //每次都取最大跳跃数，直到可以跳出>=nums的范围
        if (nums.size() == 1) return true; //只有一个数的时候，肯定可以到达
        int maxjump = 0;
        for (int i = 0; i <= maxjump; i++)     
        {
            maxjump = max(nums[i] + i, maxjump);  //更新最大跳
            if (maxjump >= nums.size() - 1) return true;
        }
        return false;
    }
};

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        //贪心算法  O(n)
        if (nums.size() == 1) return nums[0];
        int max = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max) max = sum;  //更新max
            if (sum <= 0)              //如果加上nums[i]小于=0，从nums[i+1]重新求和
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
    cout << "最大和：" << max << endl;
}
int main()
{
    test1();
    test2();
	return 0;
}