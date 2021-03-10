#ifndef GRAPHMODEL_H
#define GRAPHMODEL_H

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
//图的类型枚举
typedef enum
{
	DG,  //有向图
    UDG, //无向图
	DN,  //有向网
	UDN  //无向网
}GraphType;

//设置顶点数据类型为字符串类型，使用时要malloc
typedef char* VerTexType;
//设置权值类型为int
typedef int ArcType; 

#endif