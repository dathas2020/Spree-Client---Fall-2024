#include "TicTacToe.h"
#include "Maze.h"
#include "GuessTheNumber.h"
#include "MemoryGame.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void Welcome();
void Games();

void Games()
{
    int opt,Game;
    do{
        Welcome();
        cout << "1. Play\n2. Exit\n\nOption: ";
        cin >> opt;

        if(opt == 1)
        {
            do{
                system("cls");
                cout << "\n1. Tictactoe\n2. Maze\n3. Guess the number\n4. Memory game\n5. Go back\n";
                cout << "\nGame option: ";
                cin >> Game;

                switch(Game)
                {
                    case 1:
                        TTTGame();
                        break;
                    case 2:
                        MGame();
                        break;
                    case 3:
                        GTNGame();
                        break;
                    case 4:
                        MEMGame();
                        break;
                    case 5:
                        cout << "Going back\n";
                        break;
                    default:
                        cout << "Select correct game option\n\n";
                }

            }while(Game != 5);
        }
        else if(opt == 2)
        {
            cout << "Exiting\n";
        }
        else
        {
            cout << "Enter correct option\n";
        }
    }while(opt != 2);
}

void Welcome()
{
    system("cls");
    cout << "------------------ WELCOME TO SPREE CLIENT --------------------\n\n";
    cout << "Play some games, have some fun\n";
    cout << "We have few games available right now.\n";
    cout << "Some games save your scores.\n";
    cout << "Enter the numbers you see before the option to select.\n";
    cout <<"\n\n\n";
}