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
void switchPlayer(char& currentPlayer);

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
	bool vsComputer = gameMode();

	resetBoard(board);

	while (!gameOver) {
		drawBoard(board);

		if (currentPlayer == PLAYER_X) {
			makeMove(board, currentPlayer);
		}
		else {
			if (vsComputer) {
				cout << "Moviment de l'ordinador: ";

				computerMove(board, currentPlayer); // juga l'ordinador
			}
			else {
				makeMove(board, currentPlayer); // juga l'huma
			}
		}

		turn++;

		// TODO: Comprovar guanyador aqui
		if (turn == BOARD_SIZE * BOARD_SIZE) {
			gameOver = true;
		}
		else {
			switchPlayer(currentPlayer);
		}
	}

	drawBoard(board);
}

void switchPlayer(char &currentPlayer) {
	currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_Y : PLAYER_X;
}