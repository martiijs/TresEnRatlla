#include <iostream>

#include "alumne2.h"
#include "constants.h"

using namespace std;

// Comprova si el jugador ha guanyat
bool checkVictory(const char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Comprovacio de files
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    //Comprovacio de columnes
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    //Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

//Comprova si hi ha empat
bool checkDraw(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

//Pregunta si es vol tornar a jugar
bool askPlayAgain() {
    char resposta;
    cout << "\nVols jugar una altra partida? (s/n): ";
    cin >> resposta;
    return (resposta == 's' || resposta == 'S');
}

void updateScore(char winner) {
    int scoreX = 0;
    int scoreO = 0;
    int draws = 0;

    if (winner == PLAYER_X) {
        scoreX++;
    }
    else if (winner == PLAYER_Y) {
        scoreO++;
    }
    else {
        draws++;
    }

    cout << "Marcador actual:\n";
    cout << "   Jugador X: " << scoreX << "\n";
    cout << "   Jugador O: " << scoreO << "\n";
    cout << "   Empats:    " << draws << "\n";
}
