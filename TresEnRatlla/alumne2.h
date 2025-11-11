//Alumne2.h

#pragma once
#include "constants.h"

// Estructura amb les variables per guardar els marcadors entre partides
struct Score {
	int x;
	int o;
	int draws;
};

// Prototips per a les funcions per comprobar la victoria, l'empat i el tauler
bool checkVictory(const char board[BOARD_SIZE][BOARD_SIZE], char player);
bool checkDraw(const char board[BOARD_SIZE][BOARD_SIZE]);
void updateScore(char winner, Score &marcador);
