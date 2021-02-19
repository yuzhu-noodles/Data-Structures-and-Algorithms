#include"SeqString.h"

void testSeqString()
{
	HString* str1 = (HString*)malloc(sizeof(HString));
	StrAssign_HeapString(str1, "abcdde");
	Print_HeapString(str1);

	//复制
	HString* str2 = (HString*)malloc(sizeof(HString));
	StrCopy_HeapString(str2, str1);
	printf("复制后的str2：\n");
	Print_HeapString(str2);

	//比较
	printf("%d\n", StrCompare_HeapString(str1, str2));

	HString* str3 = (HString*)malloc(sizeof(HString));
	Concat_HeapString(str3, str1, str2);
	printf("连接操作：\n");
	Print_HeapString(str3);

	HString* str4 = (HString*)malloc(sizeof(HString));
	SubString_HeapString(str4, str1, 2, 3);
	printf("截取的子串：\n");
	Print_HeapString(str4);

	printf("str4在父串中的位置：%d\n",Index_HeapString(str3,str4,2));

	printf("删除后的str1：\n");
	StrDelete_HeapString(str1, 2, 3);
	Print_HeapString(str1);

	StrInsert_HeapString(str2, str1, 2);
	Print_HeapString(str2);
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}


int main()
{
	testSeqString();
	return 0;
}