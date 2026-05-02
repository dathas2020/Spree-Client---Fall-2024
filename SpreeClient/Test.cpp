#include<iostream>
#include <stdlib.h>
#include <windows.h>
#include "Maze.h"
using namespace std;

int main()
{
    /*char a = 'a';
    int b;
    b = a;
    cout << a << endl;
    b++;
    a = b;
    cout << a << endl;*/

    for(int i=0; i<16; i++)
    {
        for(int j=0; j<16; j++)
        {
            cout << maze2[i][j] << " ";
        }cout << endl;
    }
}