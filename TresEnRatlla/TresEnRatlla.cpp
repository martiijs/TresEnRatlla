// TresEnRatlla.cpp

#include <iostream>
#include <cstdlib>

#include "alumne1.h"
#include "alumne2.h"

using namespace std;

// Codis de color ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// --------------------------
// Prototips de funcions
// --------------------------
void jugarPartida(char board[3][3]);
void switchPlayer(char& currentPlayer);


int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char resposta = 's';

    cout << CYAN << BOLD << "\n===== BENVINGUT A TRES EN RATLLA =====\n" << RESET;

    do {
        jugarPartida(board);

        cout << "\nVols jugar una altra partida? (s/n): ";
        cin >> resposta;
    } while (resposta == 's' || resposta == 'S');

    cout << GREEN << "\nGràcies per jugar!\n" << RESET;
}

void jugarPartida(char board[3][3]) {
    char currentPlayer = PLAYER_X; // Jugador que inicia
    bool gameOver = false;
    int turn = 0;
    bool vsComputer = gameMode();

    resetBoard(board);

    cout << BLUE << "\n--- Nova Partida ---" << RESET << endl;

    while (!gameOver) {
        drawBoard(board);

        cout << CYAN << "\nTorn del jugador " << BOLD
            << (currentPlayer == PLAYER_X ? GREEN "X" : RED "O")
            << RESET << CYAN << "\n" << RESET;

        if (currentPlayer == PLAYER_X) {
            makeMove(board, currentPlayer);
        }
        else {
            if (vsComputer) {
                cout << YELLOW << "Moviment de l'ordinador..." << RESET << endl;
                computerMove(board, currentPlayer);
            }
            else {
                makeMove(board, currentPlayer);
            }
        }

        turn++;

        // Comprova condicions de fi de partida
        if (checkVictory(board, currentPlayer)) {
            drawBoard(board);
            cout << GREEN << BOLD << "\nEl jugador "
                << (currentPlayer == PLAYER_X ? "X" : "O")
                << " ha guanyat!\n" << RESET;
            updateScore(currentPlayer);
            gameOver = true;
        }
        else if (checkDraw(board)) {
            drawBoard(board);
            cout << YELLOW << BOLD << "\nEmpat!\n" << RESET;
            updateScore(' ');
            gameOver = true;
        }
        else {
            switchPlayer(currentPlayer);
        }
    }

    // Pregunta si vol tornar a jugar
    if (!askPlayAgain()) {
        cout << GREEN << "\nGràcies per jugar!\n" << RESET;
        exit(0);
    }
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_Y : PLAYER_X;
}
