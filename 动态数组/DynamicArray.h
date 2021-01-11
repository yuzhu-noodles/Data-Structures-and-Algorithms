#ifndef DYNAMIC_ARRAY_H   //��ֹͷ�ļ����ظ�����
#define DYNAMIC_ARRAY_H


//��̬�����ڴ棬���ԣ���������ݵ��ڴ�ŵ��ǣ�����
//��̬���� ���5��Ԫ�� �������ڴ�  �������� �ͷ��ڴ� 6 ������߸���capacity
//����capacity��ʾ�ҵ�����ڴ�ռ�һ�����Դ�Ŷ���Ԫ��
//size����  ��¼��ǰ�����о����Ԫ�ظ���

typedef struct DYNAMICARRAY
{
	int* pAddr; //������ݵĵ�ַ
	int size;   //��ǰ�ж��ٸ�Ԫ��
	int capacity;//����
}Dynamic_Array;

//дһϵ����ض�Dyanmic_Array�ṹ������ĺ���
//��ʼ��
Dynamic_Array* init_Array();
//����
void Push_Back_Array(Dynamic_Array* arr, int value);
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array*arr,int pos);
//����ֵɾ��
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//����
int Find_Array(Dynamic_Array* arr,int value);
//��ӡ
void Print_Array(Dynamic_Array* arr);
//�ͷŶ�̬�����ڴ�
void FreeSpace_Array(Dynamic_Array* arr);
//�������
void Clear_Array(Dynamic_Array* arr);
//��ö�̬��������
int Capacity_Array(Dynamic_Array* arr);
//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array* arr);
//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array* arr,int pos);


#endif
