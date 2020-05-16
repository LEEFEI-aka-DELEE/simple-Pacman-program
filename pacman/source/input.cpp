#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int getcha()
{

    char c = getch();
    if (c<0) c = getch();
    return c;

}


void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,fg+bg);
}
