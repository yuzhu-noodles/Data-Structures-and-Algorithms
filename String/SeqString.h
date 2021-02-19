#ifndef SEQSTRING_H
#define SEQSTRING_H

#include"StatustLib.h"

#define MAX_SIZE 1024

//typedef struct
//{
//	char ch[MAX_SIZE + 1];  //定长方式实现字符串的顺序结构-缺点浪费空间
//	int length;
//}SString;

//串的堆式顺序存储结构（Heap）
typedef struct
{
	char* ch;  //如果是非空串，那么就按照指定长度分配内存，否则ch就指向NULL；
	int length; 
}HString;

//初始化字符串
void InitString_HeapString(HString* str);
//赋值操作,值为字符串常量
Status StrAssign_HeapString(HString* str, char* chars);
//赋值
Status StrCopy_HeapString(HString* deststr, HString* srcstr);
//判断是否为空
Status IsEmpty_HeapString(HString* str);
//字符串比较
//str1 == str2   return 0
//str1 < str2    return 负数
//str1 > str2    return 正数
Status StrCompare_HeapString(HString* str1, HString* str2);
//字符串连接,结果以deststr返回
Status Concat_HeapString(HString* deststr, HString* str1, HString* str2);
//截取从pos位置处开始长度len的字符串
Status SubString_HeapString(HString* deststr, HString* str, int pos,int len);
//返回从pos位置开始的子串child在父串parent中的位置
int Index_HeapString(HString* parent, HString* child, int pos);
//从pos位置开始删除长度len
Status StrDelete_HeapString(HString* str, int pos, int len);
//插入
Status StrInsert_HeapString(HString* str, HString* insertstr, int pos);
//打印
void Print_HeapString(HString* str);
#endif
