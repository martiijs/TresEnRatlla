
#include <iostream>
#include <cstdlib>
#include "alumne1.h"
#include "alumne2.h"

using namespace std;

// Codis de color ANSI per a les sortides de text
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
void jugarPartida(char board[3][3], Score &marcador);
void switchPlayer(char& currentPlayer);

// Funcio principal per al bucle de joc
int main()
{
    // Iniciem el marcador, el tauler i el caracter de resposta
    Score marcador = { 0, 0, 0 };
    char board[BOARD_SIZE][BOARD_SIZE] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char resposta = 's';

    cout << CYAN << BOLD << "\n===== BENVINGUT A TRES EN RATLLA =====\n" << RESET;

    // Mentre el jugador vulgui jugar
    do {
        // Iniciem la funcio de partida
        jugarPartida(board, marcador);
        
        // Quan s'acaba preguntem si es vol tornar a jugar
        cout << "\nVols jugar una altre partida? (s/n): ";
        cin >> resposta;
    } while (resposta == 's' || resposta == 'S');

    cout << GREEN << "\nGràcies per jugar!\n" << RESET;
}

// Funcio de joc
void jugarPartida(char board[3][3], Score &marcador) {

    // Iniciem el jugador actual, l'estat de la partida, el torn i el mode de joc
    char currentPlayer = PLAYER_X; 
    bool gameOver = false;
    int turn = 0;
    bool vsComputer = gameMode();
    // Asegurem que el tauler sigui nou
    resetBoard(board);

    cout << BLUE << "\n--- Nova Partida ---" << RESET << endl;

    // Mentre no hi hagi un perdedor
    while (!gameOver) {
        
        // Dibuixem tauler
        drawBoard(board);

        // Actualitzem i mostrem el torn
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
            updateScore(currentPlayer, marcador);
            gameOver = true;
        }
        else if (checkDraw(board)) { // Per als empats
            drawBoard(board);
            cout << YELLOW << BOLD << "\nEmpat!\n" << RESET;
            updateScore(' ', marcador);
            gameOver = true;
        }
        else {
            switchPlayer(currentPlayer);
        }
    }
}

// Canvia el jugador despres de cada tirada
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_Y : PLAYER_X;
}
