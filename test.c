#include"game.h"



void menu()//��Ϸ����
{
	//system("cls");
	printf("************************\n");
	printf("******  1.play  ********\n");
	printf("******  0.exit  ********\n");
	printf("************************\n");
}
void gamestart()//��ʼ������Ϸ
{
	win = ROWS * COLS - MINENUM;
	//�׵���Ϣ�洢
	char mineboard[ROW][COL];
	char board[ROW][COL];//������ʾ��������Ϣ

	//��ʼ������
	initboard(mineboard, ROW, COL, '0');//��ʼ������
	initboard(board, ROW, COL, '*');

	////���ú��׵�λ��
	setmine(mineboard, ROW, COL);

	////��ӡ����
	displayboard(board, ROW, COL);
	//displayboard(mineboard, ROW, COL);

	////�����û�ɨ������ 
	playermove(mineboard, board, ROW, COL);

}
int main()
{
	int input = 0;
	srand((long)(time(NULL)));//���������
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("-------��ʼ��Ϸ��------\n\n");
			gamestart();//������Ϸ��
			break;
		case 0:

			break;
		default:
			printf("����ѡ��Ƿ������������롣\n");
			break;
		}
	} while (input != 0);
	printf("�˳���Ϸ��\n");
	return 0;
}