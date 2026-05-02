#include <iostream>                 // standard input output
#include <string>                   // names
#include <ctime>                    // random number generation for computer's first turn
using namespace std;

void TTTGame();                     // main game function declaration

class TicTacToe{                    // class for the game
    public:
     int T[9] = {1,2,3,4,5,6,7,8,9};                            // matrix for helping grid
     char P[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};         // matrix for main grid
     string name[2];                                            // names for singleplayer
     string namem[2];                                           // names for multiplayer

     void reset();                                              // clear the grid
     void player1();                                            // input from 1st player (single)
     void player2();                                            // input from 2nd player (single/multi)
     void planegrid();                                          // reference grid
     void player1(int key);                                     // input from 1st player (computer)
     void Grid();                                               // main grid
     void singleplayer(int begin, string pname);                // singleplayer loop and logic
     void multiplayer(string p1name, string p2name, int begin); // multiplayer loop and login
     bool wincondition();                                       // checking if anyone won
     bool gridfull();                                           // checking for tie
     int computer();                                            // making computer to decide
};

void TTTGame()                      // main game function definition
{
    int mode, begin;                // for options (switch)
    string pname, p1name, p2name;   // for names (single/multi)
    TicTacToe game;                 // object for class TicTacToe

    do{                     // main loop
        system("cls");

        {                   // main menu for tictactoe
        cout << "\n\n\t\t\t\t\t*********TICTACTOE*********\t\tPress 3 to go back\n";
        cout << "\n\n 1. Single player\n";
        cout << "\t\t\t\t\tComputer VS Player\n";
        game.planegrid();
        cout << "\n\n 2. Multiplayer\n";
        cout << "\t\t\t\t\tPlayer VS Player\n";
        game.planegrid();
        cout << "\n\n";
        cout << "Select your game mode: ";
        cin >> mode;
        }

        switch(mode)
        {
            case 1:         // singleplayer

                do{         // begin option loop

                    {       // singleplayer begining decision
                    cout << "\nDecide who begins first\n";
                    cout << "1. Computer\n";
                    cout << "2. You\n";
                    cout << "3. Go back\n\n";
                    cout << "Choice: ";
                    cin >> begin;
                    }

                    if(begin == 1 || begin == 2)                // game begining options
                    {
                        cout << "Enter your name: ";            // name input
                        cin >> pname;
                        
                        game.singleplayer(begin, pname);        // calling singleplayer loop/logic
                    }
                    else if(begin == 3)                         // go back option
                    {}
                    else                                        // any other option
                    {
                        cout << "Enter correct option\n";
                    }
                    pname = "";                                 // clearing name string

                }while(begin != 3);
                break;

            case 2:         // multiplayer

                cout << "Enter Player 1 name: ";        // names input
                cin >> p1name;
                cout << "Enter Player 2 name: ";
                cin >> p2name;

                game.multiplayer(p1name, p2name, 0);    // multiplayer main loop/logic

                p1name = p2name = "";                   // clear name strings

                break;

            case 3:                                     // go back option
                cout << "Going back\n";
                break;
            default:                                    // any other option
                cout << "Enter given options only\n";
        }
    }while(mode != 3);
}

void TicTacToe::reset()             // clearing the grid for another match
{
    P[0] = ' ';
    P[1] = ' ';
    P[2] = ' ';
    P[3] = ' ';
    P[4] = ' ';
    P[5] = ' ';
    P[6] = ' ';
    P[7] = ' ';
    P[8] = ' ';
}

void TicTacToe::planegrid()         // reference grid (main menu grids)
{
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t_____" << "|"<< "_____" << "|" << "_____\n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t_____" << "|"<< "_____" << "|" << "_____\n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "\t\t\t\t\t     " << "|"<< "     " << "|" << "     \n";
}

void TicTacToe::Grid()              // main grid (gameplay)
{
    cout << "     " << "|"<< "     " << "|" << "                                         " << "|"<< "     " << "|" << "\n";
    cout << "  "<<P[0]<<"  " << "|"<< "  "<<P[1]<<"  " << "|" << "  "<<P[2]<<"  \t\t\t\t  "<<T[0]<<"  " << "|"<< "  "<<T[1]<<"  " << "|" << "  "<<T[2]<<"  \n";
    cout << "_____" << "|"<< "_____" << "|" << "_____\t\t\t\t_____" << "|"<< "_____" << "|" << "_____\n";
    cout << "     " << "|"<< "     " << "|" << "     \t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "  "<<P[3]<<"  " << "|"<< "  "<<P[4]<<"  " << "|" << "  "<<P[5]<<" \t\t\t\t  "<<T[3]<<"  " << "|"<< "  "<<T[4]<<"  " << "|" << "  "<<T[5]<<" \n";
    cout << "_____" << "|"<< "_____" << "|" << "_____\t\t\t\t_____" << "|"<< "_____" << "|" << "_____\n";
    cout << "     " << "|"<< "     " << "|" << "     \t\t\t\t     " << "|"<< "     " << "|" << "     \n";
    cout << "  "<<P[6]<<"  " << "|"<< "  "<<P[7]<<"  " << "|" << "  "<<P[8]<<"  \t\t\t\t  "<<T[6]<<"  " << "|"<< "  "<<T[7]<<"  " << "|" << "  "<<T[8]<<"  \n";
    cout << "     " << "|"<< "     " << "|" << "     \t\t\t\t     " << "|"<< "     " << "|" << "     \n";
}

void TicTacToe::player1()           // player1 input (multiplayer)
{
    int key;                // position to place X
    cout << "Place: ";
    cin >> key;             // input
    if(P[key-1] == ' ')     // if input position is empty
    {
        do{                 // if input position is within the grid
            switch(key){    // placing X
                case 1:
                    P[0]='X';
                    break;
                case 2:
                    P[1]='X';
                    break;
                case 3:
                    P[2]='X';
                    break;
                case 4:
                    P[3]='X';
                    break;
                case 5:
                    P[4]='X';
                    break;
                case 6:
                    P[5]='X';
                    break;
                case 7:
                    P[6]='X';
                    break;
                case 8:
                    P[7]='X';
                    break;
                case 9:
                    P[8]='X';
                    break;
                default:
                    cout << "Enter right place \n";
        }}while((key<=0 && key >=9) && (P[key-1] == ' '));
    }
    else                    // if position is invalid
    {
        cout << "Enter right place\n";
        player1();          // calling the same function
    }
}

void TicTacToe::player2()           // player2 input (multiplayer)
{
    int key;                // position to place X
    cout << "Place: ";
    cin >> key;             // input
    if(P[key-1] == ' ')     // if input position is empty
    {
        do{                 // if input position is within the grid
            switch(key){    // placing X
                case 1:
                    P[0]='O';
                    break;
                case 2:
                    P[1]='O';
                    break;
                case 3:
                    P[2]='O';
                    break;
                case 4:
                    P[3]='O';
                    break;
                case 5:
                    P[4]='O';
                    break;
                case 6:
                    P[5]='O';
                    break;
                case 7:
                    P[6]='O';
                    break;
                case 8:
                    P[7]='O';
                    break;
                case 9:
                    P[8]='O';
                    break;
                default:
                    cout << "Enter right place \n";
        }}while((key<=0 && key >=9) && (P[key-1] == ' '));
    }
    else                    // if position is invalid
    {   
        cout << "Enter right place\n";
        player2();          // calling the same function
    }
}

void TicTacToe::player1(int key)    // player1 input computer (singleplayer)
{
    if(P[key-1] == ' ')             // input number already generated
    {                               // double check
        do{
            switch(key){            // placing X
                case 1:
                    P[0]='X';
                    break;
                case 2:
                    P[1]='X';
                    break;
                case 3:
                    P[2]='X';
                    break;
                case 4:
                    P[3]='X';
                    break;
                case 5:
                    P[4]='X';
                    break;
                case 6:
                    P[5]='X';
                    break;
                case 7:
                    P[6]='X';
                    break;
                case 8:
                    P[7]='X';
                    break;
                case 9:
                    P[8]='X';
                    break;
                default:
                    cout << "Enter right place \n";
        }}while((key<=0 && key >=9) && (P[key-1] == ' '));
    }
    else
    {
        player1(computer());        // recalling same function 
    }
}

int TicTacToe::computer()           // generating position number by computer
{
    int key;
    if((P[0] == ' ') && (P[1] == ' ') && (P[2] == ' ') &&      // Random
        (P[3] == ' ') && (P[4] == ' ') && (P[5] == ' ') && 
        (P[6] == ' ') && (P[7] == ' ') && (P[8] == ' '))
    {
	    srand(time(0));                                         // generating random number between 0-8 (index)
	    key = (rand() % 8) + 0;
    }
    else if((P[0] == ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // first
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 0;
    }
    else if((P[0] != ' ') && (P[1] == ' ') && (P[2] != ' ') &&      // second
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 1;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] == ' ') &&      // third
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 2;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // fourth
        (P[3] == ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 3;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // fifth
        (P[3] != ' ') && (P[4] == ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 4;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // sixth
        (P[3] != ' ') && (P[4] != ' ') && (P[5] == ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 5;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // seventh
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] == ' ') && (P[7] != ' ') && (P[8] != ' '))
    {
	    key = 6;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // eigth
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] == ' ') && (P[8] != ' '))
    {
	    key = 7;
    }
    else if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') &&      // ninth
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] == ' '))
    {
	    key = 8;
    }
    else if(P[4] == ' ')
    {
        key = 4;
    }
    else if((P[0] == ' ') && ((P[4] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 0;
    } //
    else if((P[2] == ' ') && ((P[4] == 'O') && (P[6] == 'O'))) // defend
    {
        key = 2;
    } //
    else if((P[6] == ' ') && ((P[4] == 'O') && (P[2] == 'O'))) // defend
    {
        key = 6;
    } //
    else if((P[8] == ' ') && ((P[0] == 'O') && (P[4] == 'O'))) // defend
    {
        key = 8;
    } //
    else if((P[1] == ' ') && ((P[4] == 'O') && (P[7] == 'O'))) // defend
    {
        key = 1;
    } //
    else if((P[3] == ' ') && ((P[4] == 'O') && (P[5] == 'O'))) // defend
    {
        key = 3;
    } //
    else if((P[5] == ' ') && ((P[4] == 'O') && (P[3] == 'O'))) // defend
    {
        key = 5;
    } //
    else if((P[7] == ' ') && ((P[4] == 'O') && (P[1] == 'O'))) // defend
    {
        key = 7;
    } //
    else if((P[0] == ' ') && ((P[1] == 'O') && (P[2] == 'O'))) // defend
    {
        key = 0;
    }
    else if((P[1] == ' ') && ((P[0] == 'O') && (P[2] == 'O'))) // defend
    {
        key = 1;
    }
    else if((P[2] == ' ') && ((P[1] == 'O') && (P[0] == 'O'))) // defend
    {
        key = 2;
    }
    else if((P[0] == ' ') && ((P[3] == 'O') && (P[6] == 'O'))) // defend
    {
        key = 0;
    }
    else if((P[3] == ' ') && ((P[0] == 'O') && (P[6] == 'O'))) // defend
    {
        key = 3;
    }
    else if((P[6] == ' ') && ((P[0] == 'O') && (P[3] == 'O'))) // defend
    {
        key = 6;
    }
    else if((P[6] == ' ') && ((P[7] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 6;
    }
    else if((P[7] == ' ') && ((P[6] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 7;
    }
    else if((P[8] == ' ') && ((P[7] == 'O') && (P[6] == 'O'))) // defend
    {
        key = 8;
    }
    else if((P[2] == ' ') && ((P[5] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 2;
    }
    else if((P[5] == ' ') && ((P[2] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 5;
    }
    else if((P[8] == ' ') && ((P[5] == 'O') && (P[2] != 'O'))) // defend
    {
        key = 8;
    }
    else if((P[4] == ' ') && ((P[0] == 'O') && (P[8] == 'O'))) // defend
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[2] == 'O') && (P[6] == 'O'))) // defend
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[1] == 'O') && (P[7] == 'O'))) // defend
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[3] == 'O') && (P[5] == 'O'))) // defend
    {
        key = 4;
    }
    else if((P[0] == ' ') && ((P[4] == 'X') && (P[8] == 'X'))) // win
    {
        key = 0;
    } //
    else if((P[2] == ' ') && ((P[4] == 'X') && (P[6] == 'X'))) // win
    {
        key = 2;
    } //
    else if((P[6] == ' ') && ((P[4] == 'X') && (P[2] == 'X'))) // win
    {
        key = 6;
    } //
    else if((P[8] == ' ') && ((P[0] == 'X') && (P[4] == 'X'))) // win
    {
        key = 8;
    } //
    else if((P[1] == ' ') && ((P[4] == 'X') && (P[7] == 'X'))) // win
    {
        key = 1;
    } //
    else if((P[3] == ' ') && ((P[4] == 'X') && (P[5] == 'X'))) // win
    {
        key = 3;
    } //
    else if((P[5] == ' ') && ((P[4] == 'X') && (P[3] == 'X'))) // win
    {
        key = 5;
    } //
    else if((P[7] == ' ') && ((P[4] == 'X') && (P[1] == 'X'))) // win
    {
        key = 7;
    } //
    else if((P[0] == ' ') && ((P[1] == 'X') && (P[2] == 'X'))) // win
    {
        key = 0;
    }
    else if((P[1] == ' ') && ((P[0] == 'X') && (P[2] == 'X'))) // win
    {
        key = 1;
    }
    else if((P[2] == ' ') && ((P[1] == 'X') && (P[0] == 'X'))) // win
    {
        key = 2;
    }
    else if((P[0] == ' ') && ((P[3] == 'X') && (P[6] == 'X'))) // win
    {
        key = 0;
    }
    else if((P[3] == ' ') && ((P[0] == 'X') && (P[6] == 'X'))) // win
    {
        key = 3;
    }
    else if((P[6] == ' ') && ((P[0] == 'X') && (P[3] == 'X'))) // win
    {
        key = 6;
    }
    else if((P[6] == ' ') && ((P[7] == 'X') && (P[8] == 'X'))) // win
    {
        key = 6;
    }
    else if((P[7] == ' ') && ((P[6] == 'X') && (P[8] == 'X'))) // win
    {
        key = 7;
    }
    else if((P[8] == ' ') && ((P[7] == 'X') && (P[6] == 'X'))) // win
    {
        key = 8;
    }
    else if((P[2] == ' ') && ((P[5] == 'X') && (P[8] == 'X'))) // win
    {
        key = 2;
    }
    else if((P[5] == ' ') && ((P[2] == 'X') && (P[8] == 'X'))) // win
    {
        key = 5;
    }
    else if((P[8] == ' ') && ((P[5] == 'X') && (P[2] != 'X'))) // win
    {
        key = 8;
    }
    else if((P[4] == ' ') && ((P[0] == 'X') && (P[8] == 'X'))) // win
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[2] == 'X') && (P[6] == 'X'))) // win
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[1] == 'X') && (P[7] == 'X'))) // win
    {
        key = 4;
    }
    else if((P[4] == ' ') && ((P[3] == 'X') && (P[5] == 'X'))) // win
    {
        key = 4;
    }
    else if(P[4] == 'X')
    {
        if((P[0] == ' ') && ((P[8] == ' ') || (P[8] == 'X'))) // win
        {
            key = 0;
        }
        else if((P[8] == ' ') && ((P[0] == ' ') || (P[0] == 'X'))) // win
        {
            key = 8;
        }
        else if((P[2] == ' ') && ((P[6] == ' ') || (P[6] == 'X'))) // win
        {
            key = 2;
        }
        else if((P[6] == ' ') && ((P[2] == ' ') || (P[2] == 'X'))) // win
        {
            key = 6;
        }
        else if((P[1] == ' ') && ((P[7] == ' ') || (P[7] == 'X'))) // win
        {
            key = 1;
        }
        else if((P[7] == ' ') && ((P[1] == ' ') || (P[1] == 'X'))) // win
        {
            key = 7;
        }
        else if((P[3] == ' ') && ((P[5] == ' ') || (P[5] == 'X'))) // win
        {
            key = 3;
        }
        else if((P[5] == ' ') && ((P[3] == ' ') || (P[3] == 'X'))) // win
        {
            key = 5;
        } 
    }
    else                                                    // end
    {
        if((P[0] == ' '))
        {
            key = 0;
        }
        else if((P[1] == ' '))
        {
            key = 1;
        }
        else if((P[2] == ' '))
        {
            key = 2;
        }
        else if((P[3] == ' '))
        {
            key = 3;
        }
        else if((P[5] == ' '))
        {
            key = 5;
        }
        else if((P[6] == ' '))
        {
            key = 6;
        }
        else if((P[7] == ' '))
        {
            key = 7;
        }
        else if((P[8] == ' '))
        {
            key = 8;
        }
        else
        {
            key = 4;
        }
    }

    return key+1;
}

bool TicTacToe::wincondition()      // checking if anyone won the match
{
    // if any three continous place are not empty and all the three are same, someone won
    if((((P[0] == P[3]) && (P[0] == P[6])) && P[0] != ' ') || 
        (((P[1] == P[4]) && (P[1] == P[7])) && P[1] != ' ') || 
        (((P[2] == P[5]) && (P[2] == P[8])) && P[2] != ' ') || 
        (((P[0] == P[1]) && (P[0] == P[2])) && P[0] != ' ') || 
        (((P[3] == P[4]) && (P[3] == P[5])) && P[3] != ' ') || 
        (((P[6] == P[7]) && (P[6] == P[8])) && P[6] != ' ') || 
        (((P[0] == P[4]) && (P[0] == P[8])) && P[4] != ' ') || 
        (((P[2] == P[4]) && (P[2] == P[6])) && P[4] != ' '))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::gridfull()          // checking if its a tie
{
    // if the board is full and no one won, its a tie. cheking if all places are not empty
    if((P[0] != ' ') && (P[1] != ' ') && (P[2] != ' ') && 
        (P[3] != ' ') && (P[4] != ' ') && (P[5] != ' ') && 
        (P[6] != ' ') && (P[7] != ' ') && (P[8] != ' '))
        {
            return true;
        }
    else
    {
        return false;
    }
}

void TicTacToe::singleplayer(int begin, string pname)   // singleplayer loop
{
    bool won;                                       // checking if someone won
    bool tie;                                       // checking if its a tie
    int retry, player;                              // play again loop option and changing turns
    player = begin;                                 // storing who begun the game this round, 
                                                    // to swap for the next round
                                                    
    reset();                                        // clearing board
    name[0] = "Computer";                           // player1 name as computer
    name[1] = pname;                                // player2 is the user name

    do{                                             // singleplayer loop
        system("cls");                              // clearing board for clean experience, no previous places
        Grid();                                     // printing the grid
        cout << name[begin-1] <<"'s turn\n";        // letting user know who's turn it is
        if(begin == 1)                              // placing X or O
        {
            player1(computer());                    // player1 (computer) placing X
        }
        else
        {
            player2();                              // player2 (user) placing O
        }

        if(begin == 1)                              // Changing turns
        {
            begin = 2;                              // player1's turn to player2's turn
        }
        else
        {
            begin = 1;                              // player2's turn to player1's turn
        }

        won = wincondition();                       // checking if won
        tie = gridfull();                           // checking if tied
    }while((!won) && (!tie));                       // if tie and won are false, next iteration

    if(won)                                         // checking and printing who won
    {
        if(begin == 2)                              // if last played was player2, player2 won
        {
            cout << "\n" <<name[1] << " wins!\n\n";
        }
        else                                        // if last played was player1, player1 won
        {
            cout << "\n" <<name[0] << " wins!\n\n";
        }
    }
    else if(tie)                                    // checking and printing tie
    {
        cout << "\n" << name[0] << " and " << name[1] << " are tied!\n\n";  //tie
    }

    do{                                             // play again loop
        cout << "1. Play again\n2. Back to menu\n";
        cin >> retry;
        if(retry == 1)                          // Changing turns
        {
            if(player == 1)
            {
                begin = 2;
            }
            else
            {
                begin = 1;
            }
            singleplayer(begin, pname);
        }
        else if(retry == 2)                     // going back
        {
            break;
        }
    }while((retry != 1) || (retry != 2));
}

void TicTacToe::multiplayer(string p1name, string p2name, int begin)    // multiplayer loop
{                                   
                                    // almost same as singleplayer, player1 is also user instead of computer
    int retry, playernumber, player;
    bool won;
    bool tie;

    reset();
    namem[0] = p1name;
    namem[1] = p2name;
    playernumber = begin;
    player = playernumber;

    do{
        system("cls");
        Grid();
        cout << namem[playernumber] <<"'s turn\n";
        if(playernumber == 0)    // placing X or O
        {
            player1();
        }
        else
        {
            player2();
        }

        system("cls");
        Grid();
        cout << namem[playernumber] <<"'s turn\n";
        if(playernumber == 0)     // Changing turns
        {
            playernumber = 1;
        }
        else
        {
            playernumber = 0;
        }

        won = wincondition();
        tie = gridfull();
    }while((won == 0) && (tie == 0));

    if(won == 1)
    {
        if(playernumber == 0)
        {
            cout << "\n" <<name[1] << " wins!\n\n";
        }
        else
        {
            cout << "\n" <<name[0] << " wins!\n\n";
        }
    }
    else if(tie == 1)
    {
        cout << "\n" << name[0] << " and " << name[1] << " are tied!\n\n";
    }
    do{
        cout << "1. Play again\n2. Back to menu\n";
        cin >> retry;
        if(retry == 1)
        {
            if(player == 0)
            {
                multiplayer(p1name, p2name, 1);
            }
            else
            {
                multiplayer(p1name, p2name, 0);
            }
        }
        else if(retry == 2)
        {
            break;
        }
    }while((retry != 1) || (retry != 2));
}