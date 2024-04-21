#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdio.h>
#include<stdlib.h>
void init_board(char board[h][l], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void play_board(char board[h][l],int x, int y)
{
	int k = 0;
	for (k = 0; k < x; k++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf(" %c ", board[k][j]);
			if (j < y - 1)
				printf("|");
			
		}
		printf("\n");

		if (k < x - 1)
		{
			for (j = 0; j < y; j++)
			{
				printf("---");
				if (j < y - 1)
					printf("|");

			}
		}
		printf("\n");
	}

}

void playermove(char board[h][l], int x, int y)
{
	int j = 0;
	int k = 0;
	printf("玩家下棋\n");
	while (1)
	{
		printf("请输入坐标；\n");
		scanf_s("%d%d", &j, &k);
		if (j >= 1 && j <= x && k >= 1 && k <= y)
		{
			if (board[j - 1][k - 1] == ' ')
			{
				board[j - 1][k-1] = '*';
				break;
			}
			else
				printf("您输入的坐标已被占用");

		}
		else
			printf("您输入的坐标是非法坐标，请重新输入");

	}
}

void computermove(char board[h][l], int x, int y)
{
	int j = 0;
	int k = 0;
	printf("电脑走\n");
	while (1)
	{
		j = rand() % x;
		k = rand() % y;
		if (board[j][k] == ' ')
		{
			board[j][k] = '#';
			break;
		}
	}
	
	

}
int pingju(char board[h][l], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char jieguo(char board[h][l], int x, int y)
{
	int a = 0;
	int b = 0;
	int c = 0;
	for (a = 0; a < x; a++)
	{
		if (board[a][0] == board[a][1] && board[a][1] == board[a][2] && board[a][0] != ' ')
			return board[a][0];
		if (board[0][a] == board[1][a] && board[1][a] == board[2][a] && board[0][a] != ' ')
			return board[1][a];
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
			return board[0][0];
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][0] != ' ')
			return board[2][0];
	}
	b = pingju(board, x, y);
	if (b == 1)
		return 'Q';
	return 'C';
}