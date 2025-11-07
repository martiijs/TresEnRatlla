#pragma once

#include <iostream>

#include "constants.h"

void drawBoard(const char board[BOARD_SIZE][BOARD_SIZE]);
void resetBoard(char board[3][3]);
void makeMove(char board[3][3], char player);
void computerMove(char board[BOARD_SIZE][BOARD_SIZE], char player);
bool gameMode();