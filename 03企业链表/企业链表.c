#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"


typedef struct PERSON
{
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data)
{
	Person* p = (Person*)data;
	printf("Name:%s  Age:%d\n",p->name,p->age);
}
int main()
{
	//��������
	LinkList* list = Init_LinkList();
	//��������
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 10;
	p2.age = 20;
	p3.age = 30;
	p4.age = 40;
	p5.age = 50;
	//������������
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Insert_LinkList(list, 0, (LinkNode*)&p5);
	//��ӡ
	Print_LinkList(list, MyPrint);

	FreeSpace_LinkList(list);

	system("pause");
	return 0;
}