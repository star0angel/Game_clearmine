#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
#define ROW 11
#define COL 11
#define ROWS 9
#define COLS 9

#define MINENUM 10//�׵�����
int win ;

void initboard(char board[ROW][COL], int row, int col, char set);//��ʼ�����������������  
void setmine(char board[ROW][COL], int row, int col);//�����׵�λ�� ��mineboard�洢
void displayboard(char board[ROW][COL], int row, int col);//��ӡ����  ������Ϣ
void playermove(char mineboard[ROW][COL], char board[ROW][COL], int row, int col);

void wipemin(char mineboard[ROW][COL], char board[ROW][COL], int row, int col,int x,int y, int mine);
//void wipe(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y,int mine);
int obtainmine(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y);//��ȡ������
