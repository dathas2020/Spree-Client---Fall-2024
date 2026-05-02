#include <iostream>     //standard
#include <ctime>        //time for random number
#include <vector>       //dinamic arrays
#include <windows.h>    //delay in display
#include <string>       //name
#include <fstream>      //scores
using namespace std;

vector<int> key, input1;

void MEMGame();

class shapes{
    public:
        void square();
        void rhombus();
        void triangleup();
        void triangledown();
        void rectanglehorizontal();
        void rectanglevertical();
        void hexagon();
        void boat();
        void heart();
        void x();
}; 

class memorygame{
    public:
        void instructions();
        int generate();
        void Gloop();
        bool won(int level);
        void display(int shapenumber);
        void takeinput(int level);
};

class scores{
    public:
        void savescore(int score);
        void viewscore();
};

void MEMGame()
{
    shapes shape;
    memorygame mem;
    scores scr;
    int opt;
    system("cls");
    mem.instructions();
    char x;
    cout << "\nEnter any key to continue\n";
    cin >> x;
    do{
        system("cls");
        cout << "1. Start\n";
        cout << "2. View scores\n";
        cout << "3. Go back\n";
        cout << "Option: ";
        cin >> opt;

        switch(opt)
        {
            case 1:
                mem.Gloop();
                break;
            case 2:
                scr.viewscore();
                break;
            case 3:
                cout << "Going back\n";
                break;
            default:
                system("cls");
                cout << "Enter correct option\n";
        }

    }while(opt != 3);

}

void shapes::square()
{
    cout << "\n ______\n";
    cout << "|      |\n";
    cout << "|      |\n";
    cout << "|______|\n";
}

void shapes::rectanglehorizontal()
{
    cout << "\n ____________\n";
    cout << "|            |\n";
    cout << "|            |\n";
    cout << "|____________|\n";
}

void shapes::rectanglevertical()
{
    cout << "\n ______\n";
    cout << "|      |\n";
    cout << "|      |\n";
    cout << "|      |\n";
    cout << "|      |\n";
    cout << "|______|\n";
}

void shapes::triangleup()
{
    cout << "\n   /\\\n";
    cout << "  /  \\\n";
    cout << " /    \\\n";
    cout << "/______\\\n";
}

void shapes::triangledown()
{
    cout << "\n ______\n";
    cout << "\\      /\n";
    cout << " \\    /\n";
    cout << "  \\  /\n";
    cout << "   \\/\n";
}

void shapes::rhombus()
{
    cout << "\n   /\\\n";
    cout << "  /  \\\n";
    cout << " /    \\\n";
    cout << " \\    /\n";
    cout << "  \\  /\n";
    cout << "   \\/\n";
}

void shapes::hexagon()
{
    cout << "\n    ____\n";
    cout << "  /      \\\n";
    cout << " /        \\\n";
    cout << "|          |\n";
    cout << " \\        /\n";
    cout << "  \\ ____ /\n";
}

void shapes::boat()
{
    cout << "\n    /\\\n";
    cout << "___/  \\___\n";
    cout << "\\        /\n";
    cout << " \\______/\n";
}

void shapes::heart()
{
    cout << "\n   _    _\n";
    cout << "  / \\  / \\\n";
    cout << " /   \\/   \\\n";
    cout << "|          |\n";
    cout << " \\        /\n";
    cout << "  \\      /\n";
    cout << "   \\    /\n";
    cout << "    \\  /\n";
    cout << "     \\/\n";
}

void shapes::x()
{
    cout << "\n\\      /\n";
    cout << " \\    /\n";
    cout << "  \\  /\n";
    cout << "   \\/\n";
    cout << "   /\\\n";
    cout << "  /  \\\n";
    cout << " /    \\\n";
    cout << "/      \\\n";
}

void memorygame::instructions()
{
    cout << "---------------- MEMORY GAME --------------\n";
    cout << "Some shapes will be shown on the screen\n";
    cout << "Enter the shapes you have seen in the correct order\n";
    cout << "If you enter correctly, the number of shapes will increase\n";
    cout << "Number of levels you pass correctly is your score\n\n";
}

int memorygame::generate()
{
    int temp;
    srand(time(0));
    temp = (rand() % 10) + 1;
    return ((rand() % temp) + 1);
}

void memorygame::Gloop()
{
    int level = 0;
    scores myscore;
    do{
        level++;
        key.clear();
        input1.clear();
        for(int i=0; i<level; i++)
        {
            system("cls");
            cout << " ";

            Sleep(500);

            system("cls");
            key.push_back(generate());
            display(key[i]);

            Sleep(1000);
            system("cls");
        }

        takeinput(level);

    }while(won(level));

    cout << "Your score is: " << level-1 << "\n\n";
    myscore.savescore(level-1);
    system("cls");
}

bool memorygame::won(int level)
{
    for(int i=0; i<level; i++)
    {
        if((key[i]) != input1[i])
        {
            return false;
        }
    }
    return true;
}

void memorygame::display(int shapenumber)
{
    shapes shape;
    switch(shapenumber)
    {
        case 1:
            shape.x();
            break;
        case 2:
            shape.triangleup();
            break;
        case 3:
            shape.triangledown();
            break;
        case 4:
            shape.square();
            break;
        case 5:
            shape.rectanglehorizontal();
            break;
        case 6:
            shape.rectanglevertical();
            break;
        case 7:
            shape.rhombus();
            break;
        case 8:
            shape.hexagon();
            break;
        case 9:
            shape.boat();
            break;
        case 10:
            shape.heart();
            break;
    }
}

void memorygame::takeinput(int level)
{
    int temp;
    cout << "Enter the images you have seen in order\n";
    cout << "You can enter the numbers in a single row with spaces between the numbers\n";
    cout << "1. X\n";
    cout << "2. Triangel pointing up\n";
    cout << "3. Triangle pointing down\n";
    cout << "4. Square\n";
    cout << "5. Sleeping rectangle\n";
    cout << "6. Standing rectangle\n";
    cout << "7. Rhombus\n";
    cout << "8. hexagon\n";
    cout << "9. Boat\n";
    cout << "10. Heart\n";
    cout << "\nNumbers: ";

    for(int i=0; i<level; i++)
    {
        cin >> temp;
        input1.push_back(temp);
    }
}

void scores::savescore(int score)
{
    string name;
    cout << "Enter your name: ";
    cin >> name;

    fstream file;
    file.open("MemoryScore.txt", ios::app);
    if(file.is_open())
    {
        file << name << "\t" << score << "\n";
        file.close();
    }
}

void scores::viewscore()
{
    char x;
    fstream file;
    file.open("MemoryScore.txt", ios::in);
    if(file.is_open())
    {
        string str;
        cout << "\n";
        while(getline(file, str))
        {
            cout << str << endl;
        }
    }
    cout << "\nEnter any key to exit\n";
    cin >> x;
}