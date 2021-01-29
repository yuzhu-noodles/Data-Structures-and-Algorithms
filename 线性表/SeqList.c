#include"SeqList.h"

//初始化
void InitList(SeqList* seqlist, ElemType* elemArray, int length)
{
	if (length > MAXSIZE)
	{
		printf("超出了数组的最大容量，初始化失败！\n");
		return;
	}
	seqlist->length = 0;//记得在初始化顺序时，记得将length置0
	for (int i = 0; i < length; i++)
	{
		//每次循环都在下表为i的地方擦入一个元素
		InsertElement(seqlist, i, elemArray[i]);
	}
}
void InsertElement(SeqList* seqlist, int index, ElemType element)
{
	//1、验证插入后元素空间是否超过MAXSIZE
	//2、index的值是否合法[0，MAXSIZE-1]
	//3、插入的index应该在length之内
	//4、从第length-1个下标开始，前面一个元素赋值给后面一个元素
	if (seqlist->length + 1 >= MAXSIZE-1)
	{
		printf("数组已满，插入元素失败！\n");
		return;
	}
	if (index<0 || index>MAXSIZE - 1)
	{
		printf("只能在允许的范围内插入元素[0,%d]", MAXSIZE - 1);
		return;
	}
	if (index > seqlist->length)
	{
		printf("插入的下标超过了数组的最大长度，插入失败！\n");
		return;
	}
	for (int i = seqlist->length - 1; i >= index; i--)
	{
		seqlist->datas[i + 1] = seqlist->datas[i];
	}
	seqlist->datas[index] = element;
	//6、顺序表的总长度+1
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
		printf("下标越界，只能删除允许的范围内的元素");
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
		printf("下标越界，只能删除允许的范围内的元素");
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
