#pragma once
#define h 3
#define l 3
#include<stdlib.h>
#include<time.h>

void init_board(char board[h][l], int x, int y);
void play_board(char board[h][l],int x , int y);
void playermove(char board[h][l], int x, int y);
void computermove(char board[h][l], int x, int y);
char jieguo(char board[h][l], int x, int y);
int pingju(char board[h][l], int x, int y);