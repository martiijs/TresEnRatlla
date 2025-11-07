#pragma once
#include "constants.h"

// Prototips per a les funcions per comprobar i preguntar
bool checkVictory(const char board[BOARD_SIZE][BOARD_SIZE], char player);
bool checkDraw(const char board[BOARD_SIZE][BOARD_SIZE]);
bool askPlayAgain();
void updateScore(char winner);
