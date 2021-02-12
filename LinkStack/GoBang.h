#ifndef GOBANG_H
#define GOBANG_H
#include"LinkStack.h"
#define BOARD_SIZE 15

//棋盘数组
char* ChessBoard[BOARD_SIZE][BOARD_SIZE];

//初始化棋盘
void InitChessBoard();
//打印棋盘
void PrintChessBoard();
#endif 
