#include "game.h"

void initboard(char board[ROW][COL], int row, int col, char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col;j++)
		{
			board[i][j] = set;
		}
	}
}

void setmine(char board[ROW][COL], int row, int col)
{
	int minenum = MINENUM;
	int x, y;
	while (minenum)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			minenum--;
		}
	}
}

void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < col-1; i++)
		printf("%d ", i);//打印x坐标
	printf("\n");
	for (i = 1; i < row-1; i++)
	{
		printf("%d ", i);//打印y坐标
		for (j = 1; j < col-1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void playermove(char mineboard[ROW][COL], char board[ROW][COL], int row, int col)
{
	int x, y;//获取用户输入坐标
	while (win)
	{
		
		printf("请输入扫雷坐标：>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROWS && y > 0 && y <= COLS)
		{
			//踩到雷了
			if (mineboard[x][y] == '1')
			{
				system("cls");
				printf("您踩到雷了，游戏结束！\n\n");
				//board[x][y] = '@';
				displayboard(mineboard, ROW, COL);//显示雷棋盘
				break;
			}
		
			//判断坐标是否扫过
			else if (board[x][y] > '0' && board[x][y] < '9'|| board[x][y]==' ')
			{
				system("cls");
				printf("坐标重复，请重新输入\n");
			}
			//坐标无雷
			else 
			{
				system("cls");
				int minenum=0;
				minenum=obtainmine(mineboard, board, ROW, COL, x, y);//获取当前坐标周围雷的数量
				wipemin(mineboard, board, ROW, COL,x,y,minenum);
				
				
			}
			if (win <= 0)
			{
				printf("恭喜你，你赢了！\n");
			}
			displayboard(board, ROW, COL);//显示雷棋盘

		}
		else {
			printf("坐标非法，请重新输入\n");
		}
	}
}

void wipemin(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y,int mine)
{
	win--;
	mineboard[x][y] = '@';
	if (mine!=0)
	{
		board[x][y] = '0' + mine;
		
	} 
	else
	{
		board[x][y] = ' ';
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if ((i>0&&j>0&&i<row-1&&j<col-1)&&//判断是否越界
					mineboard[i][j]!='@'//判断是否扫描过
					&&!(i==x&&j==y)
					)
				{
					int minetoo;//判断周围其他坐标雷的个数
					minetoo= obtainmine(mineboard, board, ROW, COL, i, j);
					board[i][j] = ' ';//先置为空白  
					
					wipemin(mineboard, board, ROW, COL, i, j, minetoo);
					
					
				} 
				
			}
		}
	}
}

int obtainmine(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y)
{
	
	int mine = 0;//获取该坐标雷数
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i == x && y == j);
			else {
				if (mineboard[i][j] == '1')
					mine++;
			}
		}
	}
	return mine;
}

