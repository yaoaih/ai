#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"


void menu()
{
	printf("************************************");
	printf("*******������Ϸ��1  �˳���Ϸ��0*******");
	printf("************************************");
}
//��Ϸ���д���
void game()
{
	char ret = 0;
	//��������
	char board[h][l] = {'0'};
	//��ʼ������
	init_board(board, h, l);
	//��Ϸ����
	play_board(board, h,l);
	//����
	while (1)
	{
		//�������
		playermove(board, h, l);
		play_board(board, h, l);
		ret = jieguo(board, h, l);
		if (ret != 'C')
			break;
		//��������
		computermove(board, h, l);
		play_board(board, h, l);
		ret = jieguo(board, h, l);
		if (ret != 'C')
			break;
		if (ret == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		//�ж��Ƿ���
		if (ret == 'Q')
		{
			printf("ƽ��");
			break;
		}
		if (ret == '*')
		{
			printf("���Ӯ");
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
		printf("����������ѡ��");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (a);
}


int main()
{
	text();
	return 0;

}
