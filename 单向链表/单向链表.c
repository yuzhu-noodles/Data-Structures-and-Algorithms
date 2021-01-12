#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

//自定义数据类型
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

//打印函数
void MyPrint(void*data)
{
	Person* p = (Person*)data;
	printf("Name:%s Age:%d Score:%d\n", p->name, p->age, p->score);
}
int main()
{
	LinkList* list = init_LinkList();
	Person p1 = { "aaa",20,60 };
	Person p2 = { "bbb",21,61 };
	Person p3 = { "ccc",22,62 };
	Person p4 = { "ddd",23,63 };
	Person p5 = { "eee",24,64 };

	//插入
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);

	//打印
	Print_LinkList(list,MyPrint);
	//删除位置2结点
	RemoveL_LinkList(list,2);
	//打印
	printf("--------------------\n");
	Print_LinkList(list, MyPrint);
	//返回第一个结点
	printf("第一个结点--------------\n");
	Person* ret=(Person*)Front_LinkList(list);
	printf("Name:%s Age:%d Score:%d\n", ret->name, ret->age, ret->score);

	//销毁链表
	FreeSpace_LinkList(list);
	system("pause");
	return 0;
}
