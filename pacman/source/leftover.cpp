#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"map.h"
#include"input.h"
#include<iostream>
#include<thread>
#include<windows.h>
//＊＊在編寫過程中被中斷或是淘汰的程式碼＊＊
void mainmeun()
{


    int game_mode = 0;
    char game_output[40][60],choose;
    while(true)
    {
        system("cls");
        while(true)
        {

            printf("                                                                                    beta build forever\n");
            printf("\n\n\n    ██████　██████　██████　　　　　██　　　██　██████　██　　██\n    ██　　██　██　　██　██　　　　　　　　　███　███　██　　██　███　██\n    ██████　██████　██　　　　　███　███████　██████　██████\n    ██　　　　　██　　██　██　　　　　　　　　██　█　██　██　　██　██　███\n    ██　　　　　██　　██　██████　　　　　██　　　██　██　　██　██　　██\n\n\n\n");
            printf("        choose gamemode :\n\n");
            if(game_mode == 0)
            {

                printf("        > ");

            }
            else
            {

                printf("          ");

            }
            printf("1P\n\n\n");
            if(game_mode == 1)
            {

                printf("        > ");

            }
            else
            {

                printf("          ");

            }
            printf("2P\n\n\n");
            if(game_mode == 2)
            {

                printf("        > ");

            }
            else
            {

                printf("          ");

            }
            printf("EXIT\n");
            choose = getcha();
            if(choose == keyUP)
            {

                game_mode -= 1;
                if(game_mode < 0)
                {

                    game_mode = 2;

                }

            }
            else if(choose == keyDOWN)
            {

                game_mode += 1;
                if(game_mode > 2)
                {

                    game_mode = 0;

                }

            }
            else if(choose == keyENTER)
            {

                break;

            }
        //basic_output();
            Sleep(200);
            system("cls");

        }
        system("cls");

        if(game_mode == 0)
        {

            char end_choose = 0;
            int de = 0;
            printf("                                                                                    beta build forever\n");
            printf("\n\n\n\n    control:\n\n             ┌───┐\n             │ ↑│\n             └───┘\n        ┌───┐┌───┐┌───┐\n        │ ←││ ↓││ →│\n        └───┘└───┘└───┘\n\n\n\n\n\n . . . ");
            system("pause");
            system("cls");
            //onep_game_ex();
            system("pause");
            system("pause");

        }
        else if(game_mode == 1)
        {

            printf("                                                                                    beta build forever\n");
            printf("\n\n\n\n    player1's control:\n\n             ┌───┐\n             │ ↑│\n             └───┘\n        ┌───┐┌───┐┌───┐\n        │ ←││ ↓││ →│\n        └───┘└───┘└───┘\n\n\n\n    player2's control:\n\n             ┌───┐\n             │ W │\n             └───┘\n        ┌───┐┌───┐┌───┐\n        │ A ││ S ││ D │\n        └───┘└───┘└───┘\n\n\n\n\n\n . . . ");
            system("pause");
            system("cls");
            //twop_game_ex_player1_main();
            system("pause");
            system("pause");

        }
        else if(game_mode == 2)
        {

            break;

        }

    }
        //return 0;

}


void onep_game()
{

    char moving = 0;
    int score = 0;
    int onepmap[21][21] =
    {

        {5,1,6,6,6,6,6,6,6,6,18,6,6,6,6,6,6,6,6,2,5},
        {5,7,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,7,5},
        {5,7,0,17,16,0,17,6,16,0,7,0,17,6,16,0,17,16,0,7,5},
        {5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5},
        {5,7,0,17,16,0,7,0,17,6,18,6,16,0,7,0,17,16,0,7,5},
        {5,7,0,0,0,0,7,0,0,0,7,0,0,0,7,0,0,0,0,7,5},
        {5,3,6,6,2,0,12,6,16,0,7,0,17,6,11,0,1,6,6,4,5},
        {5,5,5,5,7,0,7,0,0,0,0,0,0,0,7,0,7,5,5,5,5},
        {6,6,6,6,4,0,7,0,1,16,5,17,2,0,7,0,3,6,6,6,6},
        {5,5,5,5,5,0,0,0,7,5,5,5,7,0,0,0,5,5,5,5,5},
        {6,6,6,6,2,0,7,0,3,6,6,6,4,0,7,0,1,6,6,6,6},
        {5,5,5,5,7,0,7,0,0,0,0,0,0,0,7,0,7,5,5,5,5},
        {5,1,6,6,4,0,7,0,17,6,18,6,16,0,7,0,3,6,6,2,5},
        {5,7,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,7,5},
        {5,7,0,17,2,0,17,6,16,0,7,0,17,6,16,0,1,16,0,7,5},
        {5,7,0,0,7,0,0,0,0,0,0,0,0,0,0,0,7,0,0,7,5},
        {5,12,16,0,7,0,7,0,17,6,18,6,16,0,7,0,7,0,17,11,5},
        {5,7,0,0,0,0,7,0,0,0,7,0,0,0,7,0,0,0,0,7,5},
        {5,7,0,17,6,6,9,6,16,0,7,0,17,6,9,6,6,16,0,7,5},
        {5,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,5},
        {5,3,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,4,5}

    };
    int ghostmap[21][21],pacx = 11,pacy = 10;
    while(true)
    {

        printf("                                                                                    beta build forever\n");
        printf("\n\n\n\n");
        printf("        score = %d\n      ",score);
        onepmap[pacx][pacy] = 13;
        for(int i = 0;i < 21;i += 1)
        {

            for(int j = 0;j < 21;j += 1)
            {

                mapitem(onepmap[i][j]);

            }
            printf("\n      ");


        }
        if(score == 176)
        {

            break;

        }
        moving = getcha();
        if(moving == keyUP && (onepmap[pacx - 1][pacy] == 0 || onepmap[pacx - 1][pacy] == 5))
        {

            onepmap[pacx][pacy] = 5;
            pacx -= 1;
            if(onepmap[pacx][pacy] == 0)
            {

                score += 1;

            }

        }
        if(moving == keyDOWN && (onepmap[pacx + 1][pacy] == 0 || onepmap[pacx + 1][pacy] == 5))
        {

            onepmap[pacx][pacy] = 5;
            pacx += 1;
            if(onepmap[pacx][pacy] == 0)
            {

                score += 1;

            }

        }
        if(moving == keyLEFT && (onepmap[pacx][pacy - 1] == 0 || onepmap[pacx][pacy - 1] == 5))
        {

            onepmap[pacx][pacy] = 5;
            pacy -= 1;
            if(onepmap[pacx][pacy] == 0)
            {

                score += 1;

            }

        }
        if(moving == keyRIGHT && (onepmap[pacx][pacy + 1] == 0 || onepmap[pacx][pacy + 1] == 5))
        {

            onepmap[pacx][pacy] = 5;
            pacy += 1;
            if(onepmap[pacx][pacy] == 0)
            {

                score += 1;

            }

        }
        system("cls");


    }
    system("cls");
    printf("\n\n\n\n    █　　　　█　██████　██　　██　　　██　　　██　██　██　　██\n    ██　　██　██　　██　██　　██　　　██　█　██　██　███　██\n    　████　　██　　██　██　　██　　　███████　██　██████\n    　　██　　　██　　██　██　　██　　　███　███　██　██　███ \n    　　██　　　██████　██████　　　██　　　██　██　██　　██");

}

void twop_game()
{

    char moving;
    int twop1map[11][19] =
    {

        {1,6,6,6,6,10,6,6,6,6,6,6,6,10,6,6,6,6,2},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {7,0,1,16,0,7,0,17,6,6,6,16,0,7,0,17,2,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,7,0,17,16,0,1,16,5,17,2,0,17,16,0,7,0,7},
        {7,0,0,0,0,0,0,7,5,5,5,7,0,0,0,0,0,0,7},
        {7,0,7,0,17,16,0,3,6,6,6,4,0,17,16,0,7,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,3,16,0,7,0,17,6,6,6,16,0,7,0,17,4,0,7},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {3,6,6,6,6,9,6,6,6,6,6,6,6,9,6,6,6,6,4}

    };
    int twop2map[11][19] =
    {

        {1,6,6,6,6,10,6,6,6,6,6,6,6,10,6,6,6,6,2},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {7,0,1,16,0,7,0,17,6,6,6,16,0,7,0,17,2,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,7,0,17,16,0,1,16,5,17,2,0,17,16,0,7,0,7},
        {7,0,0,0,0,0,0,7,5,5,5,7,0,0,0,0,0,0,7},
        {7,0,7,0,17,16,0,3,6,6,6,4,0,17,16,0,7,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,3,16,0,7,0,17,6,6,6,16,0,7,0,17,4,0,7},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {3,6,6,6,6,9,6,6,6,6,6,6,6,9,6,6,6,6,4}

    };
    while(true)
    {

        printf("                                                                                    beta build forever\n");
        printf("\n\n\n\n      ");
        for(int i = 0;i < 11;i += 1)
        {

            for(int j = 0;j < 19;j += 1)
            {

                mapitem(twop1map[i][j]);

            }
            printf("\n      ");

        }
        printf("\n\n\n\n      ");
        for(int a = 0;a < 11;a += 1)
        {

            for(int b = 0;b < 19;b += 1)
            {

                mapitem(twop1map[a][b]);

            }
            printf("\n      ");

        }
        moving = getcha();
        system("cls");

    }

}

void basic_output()
{

    char game_output[40][60];
    for(int i  = 0;i < 40;i += 1)
    {

        for(int j = 0;j < 60;j += 1)
        {

            if(i == 39 && (j == 0 || j == 59))
            {

                game_output[i][j] = '|';

            }
            else if(i == 0 || i == 39)
            {

                game_output[i][j] = '_';

            }
            else if(j == 0 || j == 59)
            {

                game_output[i][j] = '|';

            }
            else
            {

                game_output[i][j] = ' ';

            }
            printf("%c",game_output[i][j]);

        }
        printf("\n");

    }

}

void main_meun()
{

    int game_mode = 0;
    char choose;
    printf("                                                     beta build forever\n");
    printf("\n\n\n      |||||| |||||| ||||||     ||   || |||||| ||  ||\n      ||  || ||  || ||         ||| ||| ||  rr|| ||| ||\n      |||||| |||||| ||     ||| ||||||| |||||| ||||||\n      ||     ||  || ||         || | || ||  || || |||\n      ||     ||  || ||||||     ||   || ||  || ||  ||\n\n\n\n");
    printf("        choose gamemode :\n\n");
    if(game_mode == 0)
    {

        printf("        > ");

    }
    else
    {

        printf("          ");

    }
    printf("1P\n\n\n");
    if(game_mode == 1)
    {

        printf("        > ");

    }
    else
    {

        printf("          ");

    }
    printf("2P\n");
    choose = getch();
    if(choose == 'w')
    {

        game_mode = 0;

    }
    else if(choose == 's')
    {

        game_mode = 1;

    }
    //basic_output();
    system("cls");

}

//char map1pbase[30][30]

void map1p()
{

    char map1pbase[30][30];
    for(int i = 0;i < 30;i += 1)
    {

        for(int j = 0;j < 30;j += 1)
        {

            if(i == 0 || i == 29)
            {

                map1pbase[i][j] == '─';

            }
            else if(j == 0 || j == 29)
            {

                map1pbase[i][j] == '│';

            }
            else
            {

                map1pbase[i][j] = ' ';

            }
            map1pbase[0][0] = '┌';
            map1pbase[0][29] = '┐';
            map1pbase[29][0] = '└';
            map1pbase[29][29] = '┘';

        }

    }

}


void mapitem_ex(int mapnum)
{

    switch(mapnum)
    {
    case 0:
        putchar(' · ');
        break;

    case 1:
        putchar(' ┌─');
        break;

    case 2:
        putchar('─┐ ');
        break;

    case 3:
        putchar(' └─');
        break;

    case 4:
        putchar('─┘ ');
        break;
    case 5:
        putchar('   ');
        break;

    case 6:
        putchar('───');
        break;

    case 7:
        putchar(' │ ');
        break;

    case 8:
        putchar('─┼─');
        break;

    case 9:
        putchar('─┴─');
        break;

    case 10:
        putchar('─┬─');
        break;

    case 11:
        putchar('─┤ ');
        break;

    case 12:
        putchar(' ├─');
        break;

    case 13:
        putchar('● ');
        break;

    case 14:
        putchar('▲ ');
        break;

    case 15:
        putchar('◆ ');
        break;

    case 16:
        putchar('── ');
        break;

    case 17:
        putchar(' ──');
        break;

    case 18:
        putchar('─┬─');
        break;

    }

}




