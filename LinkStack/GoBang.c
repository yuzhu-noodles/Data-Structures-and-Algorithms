#include"GoBang.h"

void InitChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			ChessBoard[i][j] = "+";
		}
	}
}
void PrintChessBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			printf("%s",ChessBoard[i][j]);
		}
		printf("\n");
	}
}