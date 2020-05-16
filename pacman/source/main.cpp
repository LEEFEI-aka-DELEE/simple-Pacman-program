#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
//#include"output.h"
#include"input.h"
#include"map.h"
#include"maingame.h"

//#include<string>
//#include<ctype.h>
//******請盡量使用預設大小******
//僅限WINDOWS 10可正常運行
//WINDOW 7 容易發生排版錯誤

//本遊戲使用老師提供之ntnuplay中的遊戲引擎所開發

//FILE *fork = fopen("完蛋.tcc","w");
//fclose(fork);



int main()
{
    system("mode con cols=102 lines=40");

    SetConsoleTitle("PAC - MAN");
    FILE *halo = fopen("leaderboard.txt","r");
    if(halo == 0)
    {
        FILE *infinite = fopen("leaderboard.txt","w");
        fclose(infinite);
    }
    fclose(halo);
    //SetConsoleWindowSize(100,50);
    while(true)
    {

        //constexpr int MazeSize = 6;

        //setconsolesi
        int game_mode = 0;

        constexpr int LEFT = 8, TOP = 17;
        gotoxy(82,0);
        setcolor(fgNORMAL);
        printf("beta build forever");
        gotoxy(6,4);
        setcolor(fgYELLOW);
        printf("\n\n\n    ██████　██████　██████　　　　　██　　　██　██████　██　　██\n    ██　　██　██　　██　██　　　　　　　　　███　███　██　　██　███　██\n    ██████　██████　██　　　　　███　███████　██████　██████\n    ██　　　　　██　　██　██　　　　　　　　　██　█　██　██　　██　██　███\n    ██　　　　　██　　██　██████　　　　　██　　　██　██　　██　██　　██");
        setcolor(fgNORMAL);
        printf("\n\n\n\n        choose gamemode:\n\n          1p\n\n          2p\n\n          Exit");
        //gotoxy(8,20);
        //printf("choose gamemode:");

        //gotoxy(10,22);
        //printf("1p");

        //gotoxy(10,24);
        //printf("2p");

        //gotoxy(10,26);
        //printf("EXIT");

        int x=0, y=0;
        bool stop = false;
        while (!stop)
        {

            gotoxy(LEFT,TOP+2*x);
            printf(">");

            char c = getcha();

            gotoxy(LEFT,TOP+2*x);
            printf(" ");

            Sleep(100);

            if(c == keyENTER)
            {

                break;

            }
            switch (c)
            {
            case keyUP:
                x -= 1;
                if(x < 0) x = 2;

                break;
            case keyDOWN:
                x += 1;
                if(x > 2) x = 0;
                break;

            }
            game_mode = x;

        }
        system("cls");
        if(game_mode == 0)
        {

            gotoxy(82,0);
            setcolor(fgNORMAL);
            printf("beta build forever");
            printf("\n\n\n\n                                       control:\n\n                                                ┌───┐\n                                                │ ↑│\n                                                └───┘\n                                           ┌───┐┌───┐┌───┐\n                                           │ ←││ ↓││ →│\n                                           └───┘└───┘└───┘\n ");
            gotoxy(28,25);
            setcolor(fgNORMAL);
            printf("- - - press anything to start the game - - -");
            setcolor(fgBLACK);
            system("pause");
            system("cls");
            setcolor(fgNORMAL);
            onep_game_ex();
            system("pause");
            system("cls");

        }
        if(game_mode == 1)
        {

            gotoxy(82,0);
            setcolor(fgNORMAL);
            printf("beta build forever");
            printf("\n\n\n\n                                       player1's control:\n\n                                                ┌───┐\n                                                │ ↑│\n                                                └───┘\n                                           ┌───┐┌───┐┌───┐\n                                           │ ←││ ↓││ →│\n                                           └───┘└───┘└───┘\n\n\n\n                                       player2's control:\n\n                                                ┌───┐\n                                                │ W │\n                                                └───┘\n                                           ┌───┐┌───┐┌───┐\n                                           │ A ││ S ││ D │\n                                           └───┘└───┘└───┘\n");
            gotoxy(28,25);
            setcolor(fgNORMAL);
            printf("- - - press anything to start the game - - -");
            setcolor(fgBLACK);
            system("pause");
            system("cls");
            setcolor(fgNORMAL);
            //printf("the two player mode is not ready yet, maybe some day in the future will update it\n(thread is so complgate)");
            //system("pause");
            system("cls");
            twop_game_ex_player1_main();
            system("pause");
            system("cls");

        }
        if(game_mode == 2)
        {

            break;

        }


    }
//printf("\n\n - - - thanks for playing - - - \n\n\n");
gotoxy(82,0);
setcolor(fgNORMAL);
printf("beta build forever");
setcolor(fgYELLOW);
printf("\n\n\n   ██████　██　　██　██████　██　　██　██　　██　█████\n   　　██　　　██　　██　██　　██　███　██　██　███　██\n   　　██　　　██████　██████　██████　████　　　█████\n   　　██　　　██　　██　██　　██　██　███　██　███　　　　██\n   　　██　　　██　　██　██　　██　██　　██　██　　██　█████\n");
printf("\n\n\n   ██████　██████　██████\n   ██　　　　　██　　██　██　　██\n   ██████　██　　██　██████\n   ██　　　　　██　　██　██　██\n   ██　　　　　██████　██　　██");
setcolor(fgNORMAL);
printf(" ·  ·  ·  ·  ·  ·  · ");
setcolor(fgYELLOW);
printf("●     ");
setcolor(fgRED);
printf("▲");
setcolor(fgGREEN);
printf("▲\n");
setcolor(fgYELLOW);
printf("\n\n\n   ██████　██　　　　██████　██　　██　██　██　　██　██████\n   ██　　██　██　　　　██　　██　██　　██　██　███　██　██\n   ██████　██　　　　██████　　████　　██　██████　██　███\n   ██　　　　　██　　　　██　　██　　　██　　　██　██　███　██　　██\n   ██　　　　　█████　██　　██　　　██　　　██　██　　██　██████\n");
setcolor(fgNORMAL);
gotoxy(25,30);
printf("- - - press anything to end the game - - -");
setcolor(fgBLACK);
system("pause");
}

