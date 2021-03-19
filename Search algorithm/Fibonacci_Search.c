#include<stdio.h>


int* Fibonacci()
{
	static int F[20];
	F[0] = 1;
	F[1] = 1;
	for (int i = 2; i < 20; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return F;
}

int InsertSearch(int* arr, int len ,int key)
{
	int* F = Fibonacci();
	int left = 0;
	int right = len - 1;
	int count = 0;
	while (len > F[count] - 1)   //计算len在F中的位置
		count++;
	int* temp;
	temp = (int*)malloc(sizeof(int) * (F[count] - 1));  //将数组arr扩展到F[count]-1的长度 
	memcpy(temp, arr, len * sizeof(int));
	for (int i = len; i < F[count] - 1; i++)
		temp[i] = arr[len - 1];
	while (left <= right)
	{
		int mid = left + F[count - 1] - 1;
		if (temp[mid] > key)
		{
			right = mid - 1;
			count = count - 1;
		}
		else if (temp[mid] < key)
		{
			left = mid + 1;
			count = count - 2;
		}
		else
		{
			if (mid >= len)
				return len - 1;
			else
				return mid;
		}
	}
	free(temp);
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int pos = InsertSearch(arr,len, 7);
	printf("%d ", pos);
}