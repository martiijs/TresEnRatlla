/*
	Gestio del tauler i interaccio
*/

//Alumne1.cpp
#include <ctime>
#include "alumne1.h"
#include "alumne2.h"

using namespace std;

// Funcio pera dibuixar el tauler
void drawBoard(const char board[BOARD_SIZE][BOARD_SIZE]) {
    cout << "\n";
    cout << "    1   2   3\n";
    // Iterem en base de la mida del tauler
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

// Funcio per a la neteja del tauler
void resetBoard(char board[3][3]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = ' '; // Emplenem amb espais en blanc
    }
}

// Funcio per als moviments dels jugadors
void makeMove(char board[3][3], char player) {
    
    // Variables per a les coordenades i validesa del moviment
    int row, col;
    bool validMove = false;

    // Mentre el moviment no sigui valid
    while (!validMove) {
        cout << "Jugador " << player << ", introdueix fila i columna (1-3): ";
        cin >> row >> col; // L'usuari introdueix la fila i la columna del moviment

        row--; col--; // Restem 1 perque contem desde 0

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if (board[row][col] == ' ') { // Mentre la posicio sigui buida
                board[row][col] = player; // Actualitzem la posicio
                validMove = true; // Declarem el moviment com a valid
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

// Funcio per als moviments de la maquina
void computerMove(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    
    srand(time(0)); // Iniciem el temps per a poder randomitzar el moviment
    int row, col;
    bool validMove = false; // Iniciem el moviment com a no valid

    while (!validMove) { // Mentre el moviment no sigui vàlid
        
        // Randomitzem les coordenades del moviment
        row = rand() % BOARD_SIZE; 
        col = rand() % BOARD_SIZE;

        if (board[row][col] == ' ') { // Mentre la posicio sigui buida
            // Declarem i validem el moviment
            board[row][col] = player;
            validMove = true;
        }
    }
}

// Funció per al mode de joc
bool gameMode() {
    char resposta;
    bool respostaValida = false;

    while (!respostaValida) { // Mentre la resposta no sigui vàlida
        cout << "Vols jugar contra l'ordinador? (s/n)";
        cin >> resposta;

        if (resposta == 's' || resposta == 'S') { 
            respostaValida = true; // Validem la resposta

            return true;
        }
        else if (resposta == 'n' || resposta == 'N') {
            respostaValida = false;

            return false;
        }
        else {
            cout << "Opcio no valida. Introdueix 's' o 'n'";
        }
    }
    return false;
}

