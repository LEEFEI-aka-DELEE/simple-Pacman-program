#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include"input.h"



void mapitem(int mapnum)
{

    setcolor(fgBLUE);
    switch(mapnum)
    {
    case 0:
        setcolor(fgNORMAL);
        printf(" · ");
        setcolor(fgBLUE);
        break;

    case 1:
        printf(" ┌─");
        break;

    case 2:
        printf("─┐ ");
        break;

    case 3:
        printf(" └─");
        break;

    case 4:
        printf("─┘ ");
        break;
    case 5:
        printf("   ");
        break;

    case 6:
        printf("───");
        break;

    case 7:
        printf(" │ ");
        break;

    case 8:
        printf("─┼─");
        break;

    case 9:
        printf("─┴─");
        break;

    case 10:
        printf("─┬─");
        break;

    case 11:
        printf("─┤ ");
        break;

    case 12:
        printf(" ├─");
        break;

    case 13:
        printf("● ");
        break;

    case 14:
        printf("▲ ");
        break;

    case 15:
        setcolor(fgNORMAL);
        printf(" ◆");
        setcolor(fgBLUE);
        break;

    case 16:
        printf("── ");
        break;

    case 17:
        printf(" ──");
        break;

    case 18:
        printf("─┬─");
        break;

    case 19:
        printf("   ");
        break;

    case 20:
        printf(" ☆");
        break;

    }

}
