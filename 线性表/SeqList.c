#include"SeqList.h"

//��ʼ��
void InitList(SeqList* seqlist, ElemType* elemArray, int length)
{
	if (length > MAXSIZE)
	{
		printf("����������������������ʼ��ʧ�ܣ�\n");
		return;
	}
	seqlist->length = 0;//�ǵ��ڳ�ʼ��˳��ʱ���ǵý�length��0
	for (int i = 0; i < length; i++)
	{
		//ÿ��ѭ�������±�Ϊi�ĵط�����һ��Ԫ��
		InsertElement(seqlist, i, elemArray[i]);
	}
}
void InsertElement(SeqList* seqlist, int index, ElemType element)
{
	//1����֤�����Ԫ�ؿռ��Ƿ񳬹�MAXSIZE
	//2��index��ֵ�Ƿ�Ϸ�[0��MAXSIZE-1]
	//3�������indexӦ����length֮��
	//4���ӵ�length-1���±꿪ʼ��ǰ��һ��Ԫ�ظ�ֵ������һ��Ԫ��
	if (seqlist->length + 1 >= MAXSIZE-1)
	{
		printf("��������������Ԫ��ʧ�ܣ�\n");
		return;
	}
	if (index<0 || index>MAXSIZE - 1)
	{
		printf("ֻ��������ķ�Χ�ڲ���Ԫ��[0,%d]", MAXSIZE - 1);
		return;
	}
	if (index > seqlist->length)
	{
		printf("������±곬�����������󳤶ȣ�����ʧ�ܣ�\n");
		return;
	}
	for (int i = seqlist->length - 1; i >= index; i--)
	{
		seqlist->datas[i + 1] = seqlist->datas[i];
	}
	seqlist->datas[index] = element;
	//6��˳�����ܳ���+1
	seqlist->length++;
}

void PrintList(SeqList* seqlist)
{
	for (int i = 0; i < seqlist->length; i++)
	{
		printf("%d %s\n", seqlist->datas[i].id, seqlist->datas[i].name);
	}
}
ElemType* FindElement(SeqList* seqlist, int index)
{
	if (index<0 || index>MAXSIZE - 1)
	{
		printf("�±�Խ�磬ֻ��ɾ������ķ�Χ�ڵ�Ԫ��");
		return;
	}
	ElemType* element;
	element = &seqlist->datas[index];
	return element;
}
ElemType* DeleteElement(SeqList* seqlist, int index)
{
	if (index<0 || index>MAXSIZE - 1)
	{
		printf("�±�Խ�磬ֻ��ɾ������ķ�Χ�ڵ�Ԫ��");
		return;
	}
	ElemType* deletement = (ElemType*)malloc(sizeof(ElemType));
	*deletement = *FindElement(seqlist, index);
	for (int i = index; i < seqlist->length; i++)
	{
		seqlist->datas[i] = seqlist->datas[i + 1];
	}
	seqlist->length--;
	return deletement;
}
int GetLength(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return 0;
	}
	return seqlist->length;
}
void Clear(SeqList* seqlist)
{
	if (seqlist == NULL)
	{
		return;
	}
	seqlist->length = 0;
}
