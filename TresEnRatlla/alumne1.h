//Alumne1.h
#pragma once
#include <iostream>
#include "constants.h"

// Prototips per a les funcions per a dibuixar el tauler, reiniciar-lo, fer els moviments del jugador i maquina i escollir el mode de joc
void drawBoard(const char board[BOARD_SIZE][BOARD_SIZE]);
void resetBoard(char board[3][3]);
void makeMove(char board[3][3], char player);
void computerMove(char board[BOARD_SIZE][BOARD_SIZE], char player);
bool gameMode();