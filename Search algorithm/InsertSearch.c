#include<stdio.h>
#include<stdlib.h>

//插值查找
//将二分查找的比例参数1/2改为自适应，使mid更接近key
//时间复杂度O(log2(log2n))
int InsertSearch(int* arr, int key,int left,int right)
{
	int mid = left + (right - left) * (key - arr[left]) / (arr[right] - arr[left]);
	if (arr[mid] == key)
		return mid;
	else if (arr[mid] < key)
		return InsertSearch(arr, key, mid + 1, right);
	else
		return InsertSearch(arr, key, left, mid - 1);
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int key = 4;
	int pos = InsertSearch(arr, key, 0, len - 1);
	printf("pos: %d\t key: %d\n", pos, arr[pos]);
	return 0;
}
