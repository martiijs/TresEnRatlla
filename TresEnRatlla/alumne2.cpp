#include <iostream>

#include "alumne2.h"
#include "constants.h"

using namespace std;

// Codis de color ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Variables globals per mantenir el marcador entre partides. TODO: buscar una alternativa millor a variables globals
int scoreX = 0;
int scoreO = 0;
int draws = 0;


bool checkVictory(const char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Files
    for (int i = 0; i < BOARD_SIZE; ++i)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // Columnes
    for (int j = 0; j < BOARD_SIZE; ++j)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}


bool checkDraw(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i)
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}


bool askPlayAgain() {
    char resposta;
    cout << CYAN << "\nVols jugar una altra partida? (s/n): " << RESET;
    cin >> resposta;
    return (resposta == 's' || resposta == 'S');
}


void updateScore(char winner) {
    if (winner == PLAYER_X) {
        scoreX++;
    }
    else if (winner == PLAYER_Y) {
        scoreO++;
    }
    else {
        draws++;
    }

    cout << "\n" << YELLOW << BOLD << "Marcador actual:" << RESET << "\n";
    cout << "   " << GREEN << "Jugador X: " << BOLD << scoreX << RESET << "\n";
    cout << "   " << RED << "Jugador O: " << BOLD << scoreO << RESET << "\n";
    cout << "   " << CYAN << "Empats:    " << BOLD << draws << RESET << "\n";
}
