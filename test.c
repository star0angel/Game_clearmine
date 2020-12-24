#include"game.h"



void menu()//游戏开场
{
	//system("cls");
	printf("************************\n");
	printf("******  1.play  ********\n");
	printf("******  0.exit  ********\n");
	printf("************************\n");
}
void gamestart()//开始载入游戏
{
	win = ROWS * COLS - MINENUM;
	//雷的信息存储
	char mineboard[ROW][COL];
	char board[ROW][COL];//用于显示的棋盘信息

	//初始化棋盘
	initboard(mineboard, ROW, COL, '0');//初始化棋盘
	initboard(board, ROW, COL, '*');

	////布置好雷的位置
	setmine(mineboard, ROW, COL);

	////打印棋盘
	displayboard(board, ROW, COL);
	//displayboard(mineboard, ROW, COL);

	////接收用户扫雷坐标 
	playermove(mineboard, board, ROW, COL);

}
int main()
{
	int input = 0;
	srand((long)(time(NULL)));//随机数种子
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("-------开始游戏！------\n\n");
			gamestart();//载入游戏；
			break;
		case 0:

			break;
		default:
			printf("输入选项非法，请重新输入。\n");
			break;
		}
	} while (input != 0);
	printf("退出游戏！\n");
	return 0;
}