//Alumne2.cpp
#include <iostream>
#include "alumne2.h"
#include "constants.h"

using namespace std;

// Codis de color ANSI per a les sortides de text
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

// Funcio per a comprobar les condicions de victoria 
bool checkVictory(const char board[BOARD_SIZE][BOARD_SIZE], char player) {
    
    // Comprobem si hi ha una fila completa amb les fitxes del mateix jugador
    for (int i = 0; i < BOARD_SIZE; ++i)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;

    // Comprobem si hi ha una columna  completa amb les fitxes del mateix jugador
    for (int j = 0; j < BOARD_SIZE; ++j)
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;

    // Comprobem si hi ha una diagonal completa amb les fitxes del mateix jugador
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Funcio per comprobar si el tauler es ple i no hi ha guanyador
bool checkDraw(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) // Iterem per totes les caselles
        for (int j = 0; j < BOARD_SIZE; ++j)
            if (board[i][j] == ' ') // Comprobem que no siguin buides
                return false;
    return true;
}

// Funció per al marcador
void updateScore(char winner, Score &marcador) {
    
    // En base al guanyador
    if (winner == PLAYER_X) {
        marcador.x++; // augmentem el nombre de victories y
    }
    else if (winner == PLAYER_Y) {
        marcador.o++; // augmentem el nombre de victories x
    }
    else {
        marcador.draws++; // augmentem el nombre d'empats
    }

    // Imprimim el marcador
    cout << "\n" << YELLOW << BOLD << "Marcador actual:" << RESET << "\n";
    cout << "   " << GREEN << "Jugador X: " << BOLD << marcador.x << RESET << "\n";
    cout << "   " << RED << "Jugador O: " << BOLD << marcador.o << RESET << "\n";
    cout << "   " << CYAN << "Empats:    " << BOLD << marcador.draws << RESET << "\n";
}
