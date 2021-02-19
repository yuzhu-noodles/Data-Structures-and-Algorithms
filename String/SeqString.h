#ifndef SEQSTRING_H
#define SEQSTRING_H

#include"StatustLib.h"

#define MAX_SIZE 1024

//typedef struct
//{
//	char ch[MAX_SIZE + 1];  //������ʽʵ���ַ�����˳��ṹ-ȱ���˷ѿռ�
//	int length;
//}SString;

//���Ķ�ʽ˳��洢�ṹ��Heap��
typedef struct
{
	char* ch;  //����Ƿǿմ�����ô�Ͱ���ָ�����ȷ����ڴ棬����ch��ָ��NULL��
	int length; 
}HString;

//��ʼ���ַ���
void InitString_HeapString(HString* str);
//��ֵ����,ֵΪ�ַ�������
Status StrAssign_HeapString(HString* str, char* chars);
//��ֵ
Status StrCopy_HeapString(HString* deststr, HString* srcstr);
//�ж��Ƿ�Ϊ��
Status IsEmpty_HeapString(HString* str);
//�ַ����Ƚ�
//str1 == str2   return 0
//str1 < str2    return ����
//str1 > str2    return ����
Status StrCompare_HeapString(HString* str1, HString* str2);
//�ַ�������,�����deststr����
Status Concat_HeapString(HString* deststr, HString* str1, HString* str2);
//��ȡ��posλ�ô���ʼ����len���ַ���
Status SubString_HeapString(HString* deststr, HString* str, int pos,int len);
//���ش�posλ�ÿ�ʼ���Ӵ�child�ڸ���parent�е�λ��
int Index_HeapString(HString* parent, HString* child, int pos);
//��posλ�ÿ�ʼɾ������len
Status StrDelete_HeapString(HString* str, int pos, int len);
//����
Status StrInsert_HeapString(HString* str, HString* insertstr, int pos);
//��ӡ
void Print_HeapString(HString* str);
#endif
