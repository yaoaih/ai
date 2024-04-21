#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"


void menu()
{
	printf("************************************");
	printf("*******进入游戏：1  退出游戏：0*******");
	printf("************************************");
}
//游戏运行代码
void game()
{
	char ret = 0;
	//设置数组
	char board[h][l] = {'0'};
	//初始化数组
	init_board(board, h, l);
	//游戏背景
	play_board(board, h,l);
	//下棋
	while (1)
	{
		//玩家下棋
		playermove(board, h, l);
		play_board(board, h, l);
		ret = jieguo(board, h, l);
		if (ret != 'C')
			break;
		//电脑下棋
		computermove(board, h, l);
		play_board(board, h, l);
		ret = jieguo(board, h, l);
		if (ret != 'C')
			break;
		if (ret == '#')
		{
			printf("电脑赢\n");
			break;
		}
		//判断是否结果
		if (ret == 'Q')
		{
			printf("平局");
			break;
		}
		if (ret == '*')
		{
			printf("玩家赢");
			break;
		}

	}
}

void text()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入您的选择");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (a);
}


int main()
{
	text();
	return 0;

}
