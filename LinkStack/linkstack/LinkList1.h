#ifndef LINKLIST1_H
#define LINKLIST1_H
#include<stdio.h>
#include<stdlib.h>


typedef struct LinkStack
{
	int data;
	struct LinkStack* next;
}LinkStack;

void Init(LinkStack* linkstack);
LinkStack* push(LinkStack* linkstack,int n);
LinkStack* pop(LinkStack* link);
#endif
