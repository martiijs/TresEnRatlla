#pragma once

#include <iostream>

const int BOARD_SIZE = 3;
const char PLAYER_X = 'X';
const char PLAYER_Y = 'O';

void drawBoard(const char board[3][3]);
void resetBoard(char board[3][3]);
void makeMove(char board[3][3], char player);