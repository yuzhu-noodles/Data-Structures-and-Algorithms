#ifndef GOBANG_H
#define GOBANG_H
#include"LinkStack.h"
#define BOARD_SIZE 15

//��������
char* ChessBoard[BOARD_SIZE][BOARD_SIZE];

//��ʼ������
void InitChessBoard();
//��ӡ����
void PrintChessBoard();
#endif 
