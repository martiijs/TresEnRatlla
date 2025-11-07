/*
	Gestio del tauler i interaccio
*/

#include "alumne1.h"
#include "alumne2.h"

using namespace std;

void drawBoard(const char board[BOARD_SIZE][BOARD_SIZE]) {
    cout << "\n";
    cout << "    1   2   3\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "  +---+---+---+\n";
        cout << i + 1 << " |";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n";
    }
    cout << "  +---+---+---+\n\n";
}


void resetBoard(char board[3][3]) {
    for (int i = 0; i < BOARD_SIZE; i++) {

    }
}

void makeMove(char board[3][3], char player) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Jugador " << player << ", introdueix fila i columna (1-3): ";
        cin >> row >> col;

        row--; col--;

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (board[row][col] == ' ') {
                board[row][col] = player;
                validMove = true;
            }
            else {
                cout << "Casella ocupada, Torna-ho a provar.\n";
            }
        }
        else {
            cout << "Coordenades incorrectes! (1-3)\n";
        }
    }
}

