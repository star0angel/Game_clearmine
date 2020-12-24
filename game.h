#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//雷阵棋盘
#define ROW 11
#define COL 11
#define ROWS 9
#define COLS 9

#define MINENUM 10//雷的数量
int win ;

void initboard(char board[ROW][COL], int row, int col, char set);//初始化棋盘数组和雷数组  
void setmine(char board[ROW][COL], int row, int col);//设置雷的位置 用mineboard存储
void displayboard(char board[ROW][COL], int row, int col);//打印棋盘  更新信息
void playermove(char mineboard[ROW][COL], char board[ROW][COL], int row, int col);

void wipemin(char mineboard[ROW][COL], char board[ROW][COL], int row, int col,int x,int y, int mine);
//void wipe(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y,int mine);
int obtainmine(char mineboard[ROW][COL], char board[ROW][COL], int row, int col, int x, int y);//获取雷数量
