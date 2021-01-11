#ifndef DYNAMIC_ARRAY_H   //防止头文件被重复包含
#define DYNAMIC_ARRAY_H


//动态增长内存，策略，将存放数据的内存放到那？堆上
//动态数组 如果5个元素 ，申请内存  拷贝数据 释放内存 6 插入第七个？capacity
//容量capacity表示我的这块内存空间一共可以存放多少元素
//size概念  记录当前数组中具体的元素个数

typedef struct DYNAMICARRAY
{
	int* pAddr; //存放数据的地址
	int size;   //当前有多少个元素
	int capacity;//容量
}Dynamic_Array;

//写一系列相关对Dyanmic_Array结构体操作的函数
//初始化
Dynamic_Array* init_Array();
//插入
void Push_Back_Array(Dynamic_Array* arr, int value);
//根据位置删除
void RemoveByPos_Array(Dynamic_Array*arr,int pos);
//根据值删除
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//查找
int Find_Array(Dynamic_Array* arr,int value);
//打印
void Print_Array(Dynamic_Array* arr);
//释放动态数组内存
void FreeSpace_Array(Dynamic_Array* arr);
//清空数组
void Clear_Array(Dynamic_Array* arr);
//获得动态数组容量
int Capacity_Array(Dynamic_Array* arr);
//获得动态数组当前元素个数
int Size_Array(Dynamic_Array* arr);
//根据位置获得某个位置元素
int At_Array(Dynamic_Array* arr,int pos);


#endif
