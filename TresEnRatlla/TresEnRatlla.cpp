// TresEnRatlla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "alumne1.h"
#include "alumne2.h"

using namespace std;

// --------------------------
// Prototips de funcions
// --------------------------
void jugarPartida(char board[3][3]);

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
	char resposta = 's';

	do {
		jugarPartida(board);

		cout << "\nMarcador -> X: "
			<< " | O: "
			<< " | Empats: ";

		cout << "Jugar una altre partida: ";
		cin >> resposta;
	} while (resposta == 's' || resposta == 'S');
}

void jugarPartida(char board[3][3]) {
	char currentPlayer = PLAYER_X; // Jugador que comença
	char winner = ' ';
	bool gameOver = false;
	int turn = 0;

	while (!gameOver) {
		drawBoard(board);
		makeMove(board, currentPlayer);
		turn++;

		if (turn == BOARD_SIZE * BOARD_SIZE) {
			gameOver = true;
		}
		else {

		}
	}

	drawBoard(board);
}