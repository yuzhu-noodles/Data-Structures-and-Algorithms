#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"DynamicArray.h"

void test01()
{
    //��ʼ����̬����
	Dynamic_Array* myArray = init_Array();

	//��ӡ����
	printf("����������%d\n", Capacity_Array(myArray));
	printf("�����С��%d\n", Size_Array(myArray));
	//����Ԫ��
	for (int i = 0; i < 30; i++)
	{
		Push_Back_Array(myArray, i);
	}
	//��ӡ
	Print_Array(myArray);
	printf("����������%d\n", Capacity_Array(myArray));
	printf("�����С��%d\n", Size_Array(myArray));
	//����
	printf("5��λ�ã�%d\n",Find_Array(myArray, 5));
	//ɾ��
	RemoveByPos_Array(myArray, 1);
	RemoveByValue_Array(myArray, 19);
	Print_Array(myArray);
    //����
	FreeSpace_Array(myArray);


}
int main(void)
{
	test01();
	system("pause");
	return 0;
}