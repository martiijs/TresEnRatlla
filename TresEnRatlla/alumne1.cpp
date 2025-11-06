/*
	Gestio del tauler i interaccio
*/

#include "alumne1.h"

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

}

void makeMove(char board[3][3], char player) {

}