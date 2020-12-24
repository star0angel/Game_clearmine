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
		printf("%d ", i);//��ӡx����
	printf("\n");
	for (i = 1; i < row-1; i++)
	{
		printf("%d ", i);//��ӡy����
		for (j = 1; j < col-1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void playermove(char mineboard[ROW][COL], char board[ROW][COL], int row, int col)
{
	int x, y;//��ȡ�û���������
	while (win)
	{
		
		printf("������ɨ�����꣺>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROWS && y > 0 && y <= COLS)
		{
			//�ȵ�����
			if (mineboard[x][y] == '1')
			{
				system("cls");
				printf("���ȵ����ˣ���Ϸ������\n\n");
				//board[x][y] = '@';
				displayboard(mineboard, ROW, COL);//��ʾ������
				break;
			}
		
			//�ж������Ƿ�ɨ��
			else if (board[x][y] > '0' && board[x][y] < '9'|| board[x][y]==' ')
			{
				system("cls");
				printf("�����ظ�������������\n");
			}
			//��������
			else 
			{
				system("cls");
				int minenum=0;
				minenum=obtainmine(mineboard, board, ROW, COL, x, y);//��ȡ��ǰ������Χ�׵�����
				wipemin(mineboard, board, ROW, COL,x,y,minenum);
				
				
			}
			if (win <= 0)
			{
				printf("��ϲ�㣬��Ӯ�ˣ�\n");
			}
			displayboard(board, ROW, COL);//��ʾ������

		}
		else {
			printf("����Ƿ�������������\n");
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
				if ((i>0&&j>0&&i<row-1&&j<col-1)&&//�ж��Ƿ�Խ��
					mineboard[i][j]!='@'//�ж��Ƿ�ɨ���
					&&!(i==x&&j==y)
					)
				{
					int minetoo;//�ж���Χ���������׵ĸ���
					minetoo= obtainmine(mineboard, board, ROW, COL, i, j);
					board[i][j] = ' ';//����Ϊ�հ�  
					
					wipemin(mineboard, board, ROW, COL, i, j, minetoo);
					
					
				} 
				
			}
		}
	}
}

int obtainmine(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y)
{
	
	int mine = 0;//��ȡ����������
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

