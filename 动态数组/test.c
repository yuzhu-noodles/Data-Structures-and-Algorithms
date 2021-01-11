#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"DynamicArray.h"

void test01()
{
    //初始化动态数组
	Dynamic_Array* myArray = init_Array();

	//打印容量
	printf("数组容量：%d\n", Capacity_Array(myArray));
	printf("数组大小：%d\n", Size_Array(myArray));
	//插入元素
	for (int i = 0; i < 30; i++)
	{
		Push_Back_Array(myArray, i);
	}
	//打印
	Print_Array(myArray);
	printf("数组容量：%d\n", Capacity_Array(myArray));
	printf("数组大小：%d\n", Size_Array(myArray));
	//查找
	printf("5的位置：%d\n",Find_Array(myArray, 5));
	//删除
	RemoveByPos_Array(myArray, 1);
	RemoveByValue_Array(myArray, 19);
	Print_Array(myArray);
    //销毁
	FreeSpace_Array(myArray);


}
int main(void)
{
	test01();
	system("pause");
	return 0;
}