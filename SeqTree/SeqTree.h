#ifndef SEQTREE_H
#define SEQTREE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//最大结点数
#define MAX_SIZE 1024

//定义顺序树类型
typedef char SeqTree[MAX_SIZE];
//初始化
void InitSeqTree(SeqTree tree);
//创建完全二叉树，i为数组中的下标
void GreatSeqTree(SeqTree tree, int i);
//获取树的根结点元素
char GetSeqTreeRoot(SeqTree tree);
//获取树的结点总数
int GetSeqTreeLength(SeqTree tree);
//获取树的深度
int GetSeqTreeDepth(SeqTree tree);
#endif
