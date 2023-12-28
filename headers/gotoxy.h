#include <windows.h>   
 //  header file for gotoxy
COORD coord= {0,0}; // this is global variable
//function to position the cursor
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}