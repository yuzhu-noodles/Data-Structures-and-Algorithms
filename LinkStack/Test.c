
#include"GoBang.h"

int main()
{
	Chessman chessarray[] = {
		{7,7,BLACK},
		{8,8,BLACK},
		{6,7,WHITE},
		{5,9,BLACK},
		{5,4,BLACK},
	};
	InitChessBoard();
	PrintChessBoard();
	LinkStack* linkstack = (LinkStack*)malloc(sizeof(LinkStack));
	//模拟落子
	for (int i = 0; i < 5; i++)
	{
		//记录每次落子情况
		PushLinkStack(linkstack, chessarray[i]);
		//根据棋子类型修改棋盘
		if (chessarray[i].Colour == BLACK)
		{
			ChessBoard[chessarray[i].y - 1][chessarray[i].x - 1] = "●";
		}
		else
		{
			ChessBoard[chessarray[i].y - 1][chessarray[i].x - 1] = "○";
		}
	}
	printf("落子后\n");
	PrintChessBoard();

	//自动悔棋
	while (linkstack->top)
	{
		printf("按任意键悔棋：\n");
		getchar();
		Chessman currchess;
		//出栈，返回这步棋
		PopLinkStack(linkstack, &currchess);
		ChessBoard[currchess.y - 1][currchess.x - 1] = "+";
		PrintChessBoard();
	}
	return 0;
}