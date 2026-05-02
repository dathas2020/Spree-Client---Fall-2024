#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

const int ROWS = 16;
const int COLS = 16;
const int MZ = 8;
char maze[ROWS][COLS];

char maze0[ROWS][COLS] = 
{
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', 'E'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

char maze1[ROWS][COLS] =
{
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', 'S', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ', 'E'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

char maze2[ROWS][COLS] =
{
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', 'S', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', 'E', '#', '#', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#'},
    {'#', ' ', '#', '#', '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', '#', ' ', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}

};

int playerRow = 1;
int playerCol = 1;
int playerHP = 100;
char input;
int newRow, newCol;
int row, col; 
string name;
int score = 0;

void displayMaze();
void movePlayer(char direction);
bool hasWon();
void Msavescore();
void Mviewscore();
void Minstructions();
void Mloop();
void MGame();
int Mgen();
void selectmaze(int n);
void initial();

void MGame()
{
    int opt;
    do{
        Minstructions();
        cout << "1. Play\n2. View scores\n3. Go back\n\nOption: ";
        cin >> opt;
        switch(opt)
        {
            case 1:
                system("cls");
                cout << "Enter your name: ";
                cin >> name;
                selectmaze(Mgen());
                initial();
                Mloop();
                Msavescore();
                break;
            case 2:
                system("cls");
                Mviewscore();
                break;
            case 3:
                system("cls");
                cout << "Going back";
                break;
            default:
                cout << "Enter correct option\n";
        }
    }while(opt != 3);
}

void displayMaze() 
{
    system("cls");  

    for (row = 0; row < ROWS; row++) 
    {
        for (col = 0; col < COLS; col++) 
        {
            if (row == playerRow && col == playerCol) 
            {
                cout << 'P' << ' ';
            } 
            else 
            {
                cout << maze[row][col] << ' ';
            }
        }
        cout << '\n';
    }
    cout << "\nPlayer HP: " << playerHP << "\n\n";
}

void movePlayer(char direction) 
{
    newRow = playerRow;
    newCol = playerCol;

    if (direction == 'w') newRow--;
    else if (direction == 's') newRow++;
    else if (direction == 'a') newCol--;
    else if (direction == 'd') newCol++;

    if (maze[newRow][newCol] == '#') 
    {
        playerHP -= 20;
        cout << "\nYou hit a wall! You lost 20 HP.\n";
        if (playerHP <= 0) 
        {
            cout << "\nFATALITY (0 HP). Game Over!\n";
            MGame();
        }
    } 
    else 
    {
        playerRow = newRow;
        playerCol = newCol;
    }
}

bool hasWon() 
{
    return maze[playerRow][playerCol] == 'E';
}

void Msavescore()
{
    fstream file;
    file.open("MazeScore.txt",ios::app);
    if(file.is_open())
    {
        file << name << "\t\t" << score <<"\n";
        file.close();
    }
}

void Mviewscore()
{
    fstream file;
    file.open("Mazescore.txt",ios::in);
    if(file.is_open())
    {
        string str;
        while(getline(file,str))
        {
            cout << str << endl;
        }
    }
}

void Minstructions()
{
    cout << "\nWelcome to Maze Escape! Find your way to the exit (E) without losing all your HP or Just Die.\n\n";
    cout << "Use WASD keys to move (W=up, A=left, S=down, D=right).\n";
    cout << "Get least number of moves possible.\n\n";
}

void Mloop()
{
    while (true) 
    {
        displayMaze();

        if (hasWon()) 
        {
            cout << "\nCongratulations! You've escaped the maze!\n";
            cout << "Your score: " << score << "\n";
            break;
        }

        cout << "Enter move (WASD): ";
        cin >> input;
        score++;

        input = tolower(input);
        
        movePlayer(input);
    }
}

int Mgen()
{
    srand(time(0));
    return ((rand() % 2) + 0);
}

void selectmaze(int n)
{
    switch(n)
    {
        case 0:
            for(int i=0; i<16; i++)
            {
                for(int j=0; j<16; j++)
                {
                    maze[i][j] = maze0[i][j];
                }
            }
            break;
        case 1:
            for(int i=0; i<16; i++)
            {
                for(int j=0; j<16; j++)
                {
                    maze[i][j] = maze1[i][j];
                }
            }
            break;
        case 2:
            for(int i=0; i<16; i++)
            {
                for(int j=0; j<16; j++)
                {
                    maze[i][j] = maze2[i][j];
                }
            }
            break;
    }
}

void initial()
{
    for(int i=0; i<16; i++)
    {
        for(int j=0; j<16; j++)
        {
            if(maze[i][j] == 'S')
            {
                playerRow = i;
                playerCol = j;
            }
        }
    }
    playerHP = 100;
}