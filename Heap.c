#include<stdio.h>
#include<stdlib.h>

#define swap(a,b){\
	typeof(a)temp = a;\
	a = b;\
	b = temp;}



typedef struct Heap
{
	int *data;//数据
	int size; //空间大小
	int count;//数据个数
}Heap;


//初始化
Heap* InitHeap(int n)
{
	Heap* H = (Heap*)malloc(sizeof(Heap));
	H->data = (int*)malloc(sizeof(int)*n);
	H->size = n;
	H->count = 0;
	return H;
}

//堆的扩容
int Expand(Heap* H)
{
	int *p = NULL;    //保存扩容后的地址
	int S = H->size;  //扩容空间
	while(S != 0)
	{
		p = (int*)realloc(H->data,sizeof(int)*(H->size+S));
		if(p != NULL)
			break;
		S /= 2;
	}
	if(p == NULL)
		return 0;
	H->data = p;
	H->size +=S;
	return 1;
}

void push(Heap *H,int num)
{
	if(H == NULL)
		return;
	if(H->count == H->size)
	{
		if(Expand(H) == 0)
			return;
	}
	//插入数据
	H->data[(H->count)++] = num;
	int ind = H->count -1;
	while((ind -1)/2 >=0 && H->data[ind]>H->data[(ind-1)/2])
	{
		swap(H->data[ind],H->data[(ind-1)/2]);
		ind  = (ind -1)/2;
	}
}

void pop(Heap* H)
{
	if(H == NULL)
		return;
	if(H->count == 0)
		return;
	H->data[0] = H->data[--(H->count)];
	int ind = 0;
	while(ind*2+1<H->count)
	{
		int temp = ind,left = ind*2+1,right = ind*2+2;
		if(H->data[left] > H->data[temp])
			temp = left;
		if(right < H->count && H->data[right] > H->data[temp])
			temp = right;
		if(temp == ind)
			break;
		swap(H->data[ind],H->data[temp]);
		ind =temp;
	}
}

int top(Heap *H)
{
	return H->data[0];
}

void PrintHeap(Heap *H)
{
	int i =0;
	for(i =0;i < H->count;i++)
	{
		printf("%d ",H->data[i]);
	}
}

int main()
{
	Heap *H = InitHeap(5);
	int arr[7] = {20,18,2,12,11,10,14};
	int i =0;
	for(i=0;i<7;i++)
	{
		push(H,arr[i]);
	}

	PrintHeap(H);
	return 0;
}

