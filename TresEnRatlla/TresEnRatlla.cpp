// TresEnRatlla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>  
using namespace std;

string pos1;
string pos2;
string pos3;
string pos4;
string pos5;
string pos6;
string pos7;
string pos8;
string pos9;
int torn;
int posicio;
string tipusFitxa;

bool agafada;
bool escollint;
bool jugant;
void Jugada();
void printTauler();

int main()
{
    torn = 1;
    jugant = true;
    while (jugant == true) {
        cout << "1";
        Jugada();
        //system("cls");
        printTauler();
    }
}

void printTauler() {

    cout << "____________" << endl;
    cout << pos1;
    cout << " | ";
    cout << pos2;
    cout << " | ";
    cout << pos3;
    cout << " | " << endl;
    cout << "____________" << endl;
    cout << pos4;
    cout << " | ";
    cout << pos5;
    cout << " | ";
    cout << pos6;
    cout << " | " << endl;
    cout << "____________" << endl;
    cout << pos7;
    cout << " | ";
    cout << pos8;
    cout << " | ";
    cout << pos9;
    cout << " | " << endl;
    cout << "____________" << endl;
}

void Jugada() {

    cout << "1.1";
    
    if (torn == 1) {
        tipusFitxa = "x";
        escollint = true;
    }

    if (torn == 2) {
        tipusFitxa = "o";
        escollint = true;
    }

    while (escollint == true) {
        cout << "Jugada: ";
        cin >> posicio;
        switch (posicio) {
        case 1: 
            if (agafada == false) { 
                pos1 = tipusFitxa;  
                escollint = false; 
                if (torn == 1) {
                    torn = 2;
                } 
                if (torn == 2) { 
                    torn = 1; 
                } 
            }
            else {
                cout << "escull una altre opció";
            }
            break;
        case 2: if (agafada == false) { pos2 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; } }
              else cout << "escull una altre opció"; break;
        case 3: if (agafada == false) { pos3 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció"; break;
        case 4: if (agafada == false) { pos4 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció"; break;
        case 5: if (agafada == false) { pos5 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció";  break;
        case 6: if (agafada == false) { pos6 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció";  break;
        case 7: if (agafada == false) { pos7 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció";  break;
        case 8: if (agafada == false) { pos8 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció";  break;
        case 9: if (agafada == false) { pos9 = tipusFitxa;  escollint = false; if (torn == 1) { torn = 2; } if (torn == 2) { torn = 1; }}
              else cout << "escull una altre opció";  break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
