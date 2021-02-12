
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
	//ģ������
	for (int i = 0; i < 5; i++)
	{
		//��¼ÿ���������
		PushLinkStack(linkstack, chessarray[i]);
		//�������������޸�����
		if (chessarray[i].Colour == BLACK)
		{
			ChessBoard[chessarray[i].y - 1][chessarray[i].x - 1] = "��";
		}
		else
		{
			ChessBoard[chessarray[i].y - 1][chessarray[i].x - 1] = "��";
		}
	}
	printf("���Ӻ�\n");
	PrintChessBoard();

	//�Զ�����
	while (linkstack->top)
	{
		printf("����������壺\n");
		getchar();
		Chessman currchess;
		//��ջ�������ⲽ��
		PopLinkStack(linkstack, &currchess);
		ChessBoard[currchess.y - 1][currchess.x - 1] = "+";
		PrintChessBoard();
	}
	return 0;
}