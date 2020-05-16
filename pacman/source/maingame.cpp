#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"map.h"
#include"input.h"
#include"leader_boared.h"
#include<iostream>
#include<thread>
#include<windows.h>

using namespace std;

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    scrn.X = xpos;
    scrn.Y = ypos;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOuput,scrn);
}

void onep_game_ex()
{
    //constexpr int MazeSize = 6;

    int playerlive = 5,stopmin = 0,ghostmin = 0,stopmin1 = 0,ghostmin1 = 0,doublepoint = 0;
    int maze[21][21] =
    {

        {5,1,6,6,6,6,6,6,6,6,18,6,6,6,6,6,6,6,6,2,5},
        {5,7,15,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,15,7,5},
        {5,7,0,17,16,0,17,6,16,0,7,0,17,6,16,0,17,16,0,7,5},
        {5,7,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,7,5},
        {5,7,0,17,16,0,7,0,17,6,18,6,16,0,7,0,17,16,0,7,5},
        {5,7,0,0,0,0,7,0,0,0,7,0,0,0,7,0,0,0,0,7,5},
        {5,3,6,6,2,0,12,6,16,0,7,0,17,6,11,0,1,6,6,4,5},
        {5,5,5,5,7,0,7,0,0,0,0,0,0,0,7,0,7,5,5,5,5},
        {6,6,6,6,4,0,7,0,1,16,19,17,2,0,7,0,3,6,6,6,6},
        {5,5,5,5,5,0,0,0,7,5,5,5,7,0,0,0,5,5,5,5,5},
        {6,6,6,6,2,0,7,0,3,6,6,6,4,0,7,0,1,6,6,6,6},
        {5,5,5,5,7,0,7,0,0,0,0,0,0,0,7,0,7,5,5,5,5},
        {5,1,6,6,4,0,7,0,17,6,18,6,16,0,7,0,3,6,6,2,5},
        {5,7,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,7,5},
        {5,7,0,17,2,0,17,6,16,0,7,0,17,6,16,0,1,16,0,7,5},
        {5,7,0,0,7,0,0,0,0,0,15,0,0,0,0,0,7,0,0,7,5},
        {5,12,16,0,7,0,7,0,17,6,18,6,16,0,7,0,7,0,17,11,5},
        {5,7,0,0,0,0,7,0,0,0,7,0,0,0,7,0,0,0,0,7,5},
        {5,7,0,17,6,6,9,6,16,0,7,0,17,6,9,6,6,16,0,7,5},
        {5,7,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,7,5},
        {5,3,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,4,5}

    };

    constexpr int LEFT = 6, TOP = 4;
    for (int i=0; i<21; i+=1)
    {
        gotoxy(LEFT, TOP+i);
        for (int j=0; j<21; j+=1)
        {
            setcolor(fgBLUE);
            mapitem(maze[i][j]);
            setcolor(fgNORMAL);
        }
    }
    int gx = 7,gy = 9,gx1 = 7,gy1 = 11,despre = 0,despre1 = 0,des = 0,des0 = 0,des_ghost=0,des_ghost1=0;
    int x=11, y=10, score = 0,final_score = 0;
    bool stop = false;
    gotoxy(10,3);
    setcolor(fgYELLOW);
    for(int i = 0; i < 5; i ++)
    {

        printf(" ●");

    }
    gotoxy(50,3);
    setcolor(fgNORMAL);
    printf("score:");
    int live = 0;
    stopmin = 10;
    stopmin1 = 10;
    //system("pause");
    gotoxy(82,0);
    setcolor(fgNORMAL);
    printf("beta build forever");
    while (!stop)//---gameloop---
    {
        if(ghostmin%2 == 1)//---ghost 1 direction_consistence---
        {
            stopmin += 1;
            des_ghost = des;
            //des_ghost1 = des0;
            despre = des;
            //despre1 = des0;

        }
        else if(ghostmin%2 == 0 && ghostmin!=0)
        {
            despre = des_ghost;
            //despre1 = des_ghost1;
        }
        else if(ghostmin == 0)
        {
            despre = des;
            //despre1 = des0;
        }

        if(ghostmin1%2 == 1)//---ghost 2 direction_consistence---
        {
            stopmin1 += 1;
            //des_ghost = des;
            des_ghost1 = des0;
            //despre = des;
            despre1 = des0;

        }
        else if(ghostmin1%2 == 0 && ghostmin1!=0)
        {
            //despre = des_ghost;
            despre1 = des_ghost1;
        }
        else if(ghostmin1 == 0)
        {
            //despre = des;
            despre1 = des0;
        }
        //despre = des;
        //despre1 = des0;
        if(gy == 0) gy = 19;
        if(gy == 20) gy = 0;
        if(gy1 == 0) gy1 = 19;
        if(gy1 == 20) gy1 = 0;
        gotoxy(40,2);
        //printf("live : %2d",playerlive);
        //printf("                                                                                    beta build forever\n\n      score: %2d                                          live: %2d",score,playerlive);

        //---score print---
        gotoxy(58,3);
        printf("%d",final_score);

        //---player print---

        setcolor(fgYELLOW);
        gotoxy(LEFT+3*y, TOP+x);
        printf(" ●");

        //---ghost 1 print---

        if(ghostmin != 0 && ghostmin > 10)//---ghost 1 state_can_be_eaten_not_tran---
        {
            setcolor(fgBLUE);
            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" ▲");
        }
        else if(ghostmin != 0 && ghostmin < 11)//----ghost 1 state_can_be_eaten_ready_to_tran---
        {
            if(ghostmin%2 == 0)
            {
                setcolor(fgBLUE);
                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" ▲");
                //setcolor(fgGREEN);
            }
            if(ghostmin%2 == 1)
            {
                setcolor(fgWHITE);
                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" ▲");
            }
        }
        else if(ghostmin == 0)//---ghost 1 state_normal---
        {
            setcolor(fgRED);
            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" ▲");
        }

        //---ghost 2 print---

        if(ghostmin1 != 0 && ghostmin1 > 10)//---ghost 2 state_can_be_eaten_not_tran---
        {
            setcolor(fgBLUE);
            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf(" ▲");
        }
        else if(ghostmin1 != 0 && ghostmin1 < 11)//---ghost 2 state_can_be_eaten_ready_to_tran---
        {
            if(ghostmin1%2 == 0)
            {
                setcolor(fgBLUE);
                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf(" ▲");
                //setcolor(fgGREEN);
            }
            if(ghostmin1%2 == 1)
            {
                setcolor(fgWHITE);
                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf(" ▲");
            }
        }
        else if(ghostmin1 == 0)//---ghost 2 state_normal---
        {
            setcolor(fgGREEN);
            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf(" ▲");
        }

        setcolor(fgNORMAL);
        gotoxy(100,0);
        printf(" ");


        char c;
        if(maze[x][y] == 0)
        {

            score += 1;
            if(doublepoint != 0)final_score += 100;
            else final_score += 50;

        }
        if(maze[x][y] == 15)
        {
            ghostmin = 30;
            ghostmin1 = 30;
            doublepoint = 40;
            despre = 0;
            despre1 = 0;
        }
        if(gx1 == gx && gy1 == gy)
        {

            gx = 7;
            gy = 10;

        }

        if(((gx == x && gy == y)&& ghostmin == 0)||((gx1 == x && gy1 == y)&& ghostmin1 == 0))//if player get eaten by ghost
        {

            x = 11;
            y = 10;
            c = 0;
            stopmin += 10;
            stopmin1 += 10;
            ghostmin = 0;
            ghostmin1 = 0;
            gotoxy(23 - 3*live,3);
            printf("   ");
            live ++;
            if(maze[gx][gy] == 5)
            {

                gotoxy(LEFT+3*gy, TOP+gx);
                printf("   ");

            }
            else if(maze[gx][gy] == 15)
            {

                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" ◆");

            }
            else
            {

                //setcolor(fgNORMAL);
                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" · ");

            }

            if(maze[gx1][gy1] == 5)
            {

                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf("   ");

            }
            else if(maze[gx1][gy1] == 15)
            {

                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf("◆ ");

            }
            else
            {

                //setcolor(fgNORMAL);
                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf(" · ");

            }
            gx = 7;
            gy = 9;
            gx1 = 7;
            gy1 = 11;
            playerlive -= 1;

        }
        else if((gx == x && gy == y) && ghostmin != 0)
        {
            gx = 7;
            gy = 11;
            ghostmin = 0;
            stopmin = 10;
            if(ghostmin > 10)final_score+=100;//plus extra for leaderboared
            else final_score+=200;
        }
        else if((gx1 == x && gy1 == y) && ghostmin1 != 0)
        {
            gx1 = 7;
            gy1 = 9;
            ghostmin1 = 0;
            stopmin1 = 10;
            if(ghostmin1 > 10)final_score+=100;//plus extra for leaderboared
            else final_score+=200;
        }

        if(playerlive == 0) break;
        Sleep(120);
        //char c;
        //char c = getcha();

        //if(kbhit() != 0) c = getcha();

        //---doublepoint---

        if(doublepoint!=0)
        {
            setcolor(fgNORMAL);
            gotoxy(28,25);
            printf("---DOUBLE POINT %2d sec---",doublepoint/2);
            doublepoint--;
        }
        if(doublepoint == 1)
        {
            gotoxy(28,25);
            printf("                              ");
            doublepoint = 0;
        }


        maze[x][y] = 5;
        if(score == 171)
        {

            break;

        }

        int direct_x,direct_y,direct_x1,direct_y1;
        if(ghostmin == 0)
        {
            direct_x = x;
            direct_y = y;
        }
        else
        {
            direct_x = 9;
            direct_y = 10;
        }

        if(ghostmin1 == 0)
        {
            direct_x1 = x;
            direct_y1 = y;
        }
        else
        {
            direct_x1 = 9;
            direct_y1 = 10;
        }
        int mindis = -1,mindis1 = -1,xde = 0,yde = 0,des1 = 0,des2 = 0,des3 = 0,des4 = 0,des21 = 0,des22 = 0,des23 = 0,des24 = 0;
        des1 = ((gx-1)-direct_x)*((gx-1)-direct_x)+(gy-direct_y)*(gy-direct_y);// ghost 1
        des2 = ((gx+1)-direct_x)*((gx+1)-direct_x)+(gy-direct_y)*(gy-direct_y);
        des3 = (gx-direct_x)*(gx-direct_x)+((gy-1)-direct_y)*((gy-1)-direct_y);
        des4 = (gx-direct_x)*(gx-direct_x)+((gy+1)-direct_y)*((gy+1)-direct_y);
        des21 = ((gx1-1)-direct_x1)*((gx1-1)-direct_x1)+(gy1-direct_y1)*(gy1-direct_y1);// ghost 2
        des22 = ((gx1+1)-direct_x1)*((gx1+1)-direct_x1)+(gy1-direct_y1)*(gy1-direct_y1);
        des23 = (gx1-direct_x1)*(gx1-direct_x1)+((gy1-1)-direct_y1)*((gy1-1)-direct_y1);
        des24 = (gx1-direct_x1)*(gx1-direct_x1)+((gy1+1)-direct_y1)*((gy1+1)-direct_y1);
        des = 0;
        des0 = 0;
        if ((maze[gx-1][gy]==0 || maze[gx-1][gy]==5 || maze[gx-1][gy] == 15) && (gx-1 != gx1 || gy != gy1)) // ghost 1
        {

            if((mindis > des1 || mindis == -1) && despre != 2)
            {

                mindis = des1;
                des=1;

            }

        }
        if((maze[gx+1][gy]==0 || maze[gx+1][gy]==5 || maze[gx+1][gy]== 15) && (gx+1 != gx1 || gy != gy1))
        {

            if((mindis > des2 || mindis == -1) && despre != 1)
            {

                mindis = des2;
                des=2;

            }

        }
        if((maze[gx][gy-1]==0 || maze[gx][gy-1]==5 || maze[gx][gy-1]==15) && (gx != gx1 || gy-1 != gy1))
        {

            if((mindis > des3 || mindis == -1) && despre != 4)
            {

                mindis = des3;
                des=3;

            }

        }
        if((maze[gx][gy+1]==0 || maze[gx][gy+1]==5 || maze[gx][gy+1]==15) && (gx != gx1 || gy+1 != gy1))
        {

            if((mindis > des4 || mindis == -1) && despre != 3)
            {

                mindis = des4;
                des=4;

            }

        }

        if((maze[gx1+1][gy1]==0 || maze[gx1+1][gy1]==5 || maze[gx1+1][gy1]==15) && (gx1+1 != gx || gy1 != gy)) //ghost 2
        {

            if((mindis1 > des22 || mindis1 == -1) && despre1 != 1)
            {

                mindis1 = des22;
                des0=2;

            }

        }
        if((maze[gx1][gy1-1]==0 || maze[gx1][gy1-1]==5 || maze[gx1][gy1-1]==15) && (gx1 != gx || gy1-1 != gy))
        {

            if((mindis1 > des23 || mindis1 == -1) && despre1 != 4)
            {

                mindis1 = des23;
                des0=3;

            }

        }
        if ((maze[gx1-1][gy1]==0 || maze[gx1-1][gy1]==5 || maze[gx1-1][gy1]==15) && (gx1-1 != gx || gy1 != gy))
        {

            if((mindis1 > des21 || mindis1 == -1) && despre1 != 2)
            {

                mindis1 = des21;
                des0=1;

            }

        }
        if((maze[gx1][gy1+1]==0 || maze[gx1][gy1+1]==5 || maze[gx1][gy1+1]==15) && (gx1 != gx || gy1+1 != gy))
        {

            if((mindis1 > des24 || mindis1 == -1) && despre1 != 3)
            {

                mindis1 = des24;
                des0=4;

            }

        }

        gotoxy(LEFT+3*y, TOP+x);
        printf("   ");

        if(maze[gx][gy] == 5)
        {

            gotoxy(LEFT+3*gy, TOP+gx);
            printf("   ");

        }
        else if(maze[gx][gy] == 15)
        {

            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" ◆");

        }
        else
        {

            //setcolor(fgNORMAL);
            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" · ");

        }

        if(maze[gx1][gy1] == 5)
        {

            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf("   ");

        }
        else if(maze[gx1][gy1] == 15)
        {

            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf("◆ ");

        }
        else
        {

            //setcolor(fgNORMAL);
            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf(" · ");

        }

        //---for ghost_direction---

        for (int i = 0; i < 256; i++)
        {
            if (GetKeyState(i) & 0x8000)
            {

                switch (i)
                {
                case 38:
                    if (maze[x-1][y]==0 || maze[x-1][y]==5 || maze[x-1][y]==15) x-=1;
                    break;
                case 40:
                    if (maze[x+1][y]==0 || maze[x+1][y]==5 || maze[x+1][y]==15) x+=1;
                    break;
                case 37:
                    if (maze[x][y-1]==0 || maze[x][y-1]==5 || maze[x][y-1]==15) y-=1;
                    if(y == 0) y = 19;
                    break;
                case 39:
                    if (maze[x][y+1]==0 || maze[x][y+1]==5 || maze[x][y+1]==15) y+=1;
                    if(y == 20) y = 1;
                    break;
                case keyESC:
                    stop = true;
                    break;
                }
            }
        }
        //if((des == 1 && despre == 2)||(des == 2 && despre == 1)||(des == 4 && despre == 3)||(des == 3 && despre == 4)) des = despre;
        if(ghostmin != 0) ghostmin-=1;
        if(ghostmin1 != 0) ghostmin1-=1;
        if(stopmin == 0)
        {

            switch (des)
            {
            case 1:
                gx-=1;
                break;
            case 2:
                gx+=1;
                break;
            case 3:
                gy-=1;
                break;
            case 4:
                gy+=1;
                break;
            }
        }
        else stopmin -= 1;

        if(stopmin1 == 0)
        {

            switch (des0)
            {
            case 1:
                gx1-=1;
                break;
            case 2:
                gx1+=1;
                break;
            case 3:
                gy1-=1;
                break;
            case 4:
                gy1+=1;
                break;
            }
        }
        else stopmin1 -= 1;


    }

    //int final_score = 0;

    if(playerlive == 0)//---gameover---
    {

        system("cls");
        gotoxy(82,0);
        setcolor(fgNORMAL);
        printf("beta build forever");
        setcolor(fgRED);
        ///gotoxy(10,4);
        //printf("\n\n\n\n    ██　　██　██████　██　　██　　　██　　　　██████　█████　██████\n    ██　　██　██　　██　██　　██　　　██　　　　██　　██　██　　　　██\n    　████　　██　　██　██　　██　　　██　　　　██　　██　█████　██████\n    　　██　　　██　　██　██　　██　　　██　　　　██　　██　　　　██　██\n    　　██　　　██████　██████　　　█████　██████　█████　██████\n\n");
        printf("\n\n\n\n                        ██████　██████　██　　　██　██████\n                        ██	      ██　　██　███　███　██\n                        ██　███　██████　███████　██████\n                        ██    ██　██　　██　██　█　██　██\n                        ██████　██　　██　██　　　██　██████\n\n                        ██████　██　　　██　██████　██████\n                        ██　　██　██　　　██　██　　　　　██　　██\n                        ██　　██　██　　　██　██████　██████\n                        ██　　██　　██　██　　██　　　　　██　██\n                        ██████　　　███　　　██████　██　　██");
        setcolor(fgNORMAL);
        gotoxy(36,17);
        printf("- - - YOUR SCORE: %6d - - -",final_score);
        for(int ani = 0; ani < 70; ani ++)
        {

            gotoxy(70 - ani,30);
            //setcolor(fgYELLOW);
            //printf("● ");
            setcolor(fgRED);
            printf("▲");
            setcolor(fgGREEN);
            printf("▲");
            gotoxy(100,0);
            printf(" ");
            Sleep(30);
            printf("          ");

        }
        gotoxy(32,20);
        setcolor(fgNORMAL);
        printf("- - - press anything to continue - - -");
        setcolor(fgBLACK);
    }
    //Sleep(1000);
    else//---you win---
    {

        final_score = score*100+5000;
        system("cls");
        gotoxy(82,0);
        setcolor(fgNORMAL);
        printf("beta build forever");
        printf("\n\n\n\n          ██　　██　██████　██　　██　　　██　　　██　██　██　　██\n          ██　　██　██　　██　██　　██　　　██　█　██　██　███　██\n          　████　　██　　██　██　　██　　　███████　██　██████\n          　　██　　　██　　██　██　　██　　　███　███　██　██　███ \n          　　██　　　██████　██████　　　██　　　██　██　██　　██\n\n");
        gotoxy(0,30);
        for(int doc = 0; doc < 35; doc ++)
        {
            printf(" ·");
        }
        gotoxy(36,17);
        printf("- - - YOUR SCORE: %6d - - -",final_score);
        for(int ani = 0; ani < 70; ani ++)
        {

            gotoxy(70 - ani,30);
            setcolor(fgYELLOW);
            printf("●   ");
            setcolor(fgRED);
            printf("▲");
            setcolor(fgGREEN);
            printf("▲");
            gotoxy(100,0);
            printf(" ");
            Sleep(30);
            printf("          ");

        }
        gotoxy(32,30);
        setcolor(fgNORMAL);
        printf("- - - press anything to continue - - -");
        setcolor(fgBLACK);
        //Sleep(1000);

    }

    //---leaderboared---....have some weird problem....

    system("pause");
    system("cls");
    gotoxy(82,0);
    setcolor(fgNORMAL);
    printf("beta build forever");
    FILE *leaderboard = fopen("leaderboard.txt","r");
    //int final_score = 0;
    leaderboard_top10 player_display;
    if(leaderboard != 0)
    {
        //read_in_leaderboard(leaderboard,&player_display);
        gotoxy(20,2);
        setcolor(fgYELLOW);
        printf("- - -player name : ");
        char name[31] = {'\0'};
        //fgets(name,30,stdin);
        scanf("%s",name);
        setcolor(fgNORMAL);
        int on_boared = 0;
        for(int i = 0; !feof(leaderboard); i++)
        {
            fscanf(leaderboard,"%s %d",player_display.top10[i].play_name,&player_display.top10[i].score);
            player_display.top10[i].uesd = 1;
            player_display.player_on_board ++;
        }

        int finding = 0;
        for(int i = 0; i < player_display.player_on_board; i ++)
        {
            if(final_score >= player_display.top10[i].score)
            {
                //printf("%d\n",i);
                leaderboared_format tmp = player_display.top10[i];
                for(int j = player_display.player_on_board-1; j != i; j--)
                {
                    tmp = player_display.top10[j];
                    player_display.top10[j] = player_display.top10[j-1];
                    player_display.top10[j-1] = tmp;
                    //printf("%d\n",j);
                }
                strcpy(player_display.top10[i].play_name,name);
                player_display.top10[i].score = final_score;
                player_display.player_on_board++;
                finding = 1;
                break;
            }
        }
        if(finding == 0 && player_display.player_on_board < 10)
        {
            strcpy(player_display.top10[player_display.player_on_board].play_name,name);
            player_display.top10[player_display.player_on_board].score = final_score;
            player_display.player_on_board ++;
        }
        for(int i = 0; i < 10; i++)
        {
            if(player_display.top10[i].score != -1)
            {
                gotoxy(20,4 + 2*i);
                setcolor(fgNORMAL);
                if(player_display.top10[i].score == final_score)
                {
                    setcolor(fgYELLOW);
                }
                printf("- - - %2d. %30s %8d - - - \n",i+1,player_display.top10[i].play_name,player_display.top10[i].score);
            }
        }
    }
    else
    {
        gotoxy(20,2);
        printf("Did not open file sucessfully");
    }
    fclose(leaderboard);
    FILE *write = fopen("leaderboard.txt","w");
    for(int i = 0;i < 10;i++)
    {
        if(player_display.top10[i].score != -1)
        {
            fprintf(write,"%s %d\n",player_display.top10[i].play_name,player_display.top10[i].score);
        }
    }
    gotoxy(32,30);
    setcolor(fgNORMAL);
    printf("- - - press anything to continue - - -");
    setcolor(fgBLACK);
    fclose(write);

}




void twop_game_ex_player1_main()
{

    //thread mthread(twop_game_ex_player2);
    //mthread.detach();
    int twop1map[25][19] =
    {

        {1,6,6,6,6,10,6,6,6,6,6,6,6,10,6,6,6,6,2},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {7,0,1,16,0,7,0,17,6,6,6,16,0,7,0,17,2,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,7,0,17,16,0,1,16,5,17,2,0,17,16,0,7,0,7},
        {7,0,0,0,0,0,0,7,19,5,19,7,0,0,0,0,0,0,7},
        {7,0,7,0,17,16,0,3,6,6,6,4,0,17,16,0,7,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,3,16,0,7,0,17,6,6,6,16,0,7,0,17,4,0,7},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {3,6,6,6,6,9,6,6,6,6,6,6,6,9,6,6,6,6,4},
        {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
        {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
        {1,6,6,6,6,10,6,6,6,6,6,6,6,10,6,6,6,6,2},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {7,0,1,16,0,7,0,17,6,6,6,16,0,7,0,17,2,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,7,0,17,16,0,1,16,5,17,2,0,17,16,0,7,0,7},
        {7,0,0,0,0,0,0,7,19,5,19,7,0,0,0,0,0,0,7},
        {7,0,7,0,17,16,0,3,6,6,6,4,0,17,16,0,7,0,7},
        {7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,7},
        {7,0,3,16,0,7,0,17,6,6,6,16,0,7,0,17,4,0,7},
        {7,15,0,0,0,7,0,0,0,0,0,0,0,7,0,0,0,15,7},
        {3,6,6,6,6,9,6,6,6,6,6,6,6,9,6,6,6,6,4}


    };

    constexpr int LEFT = 6, TOP = 4;
    for (int i=0; i<25; i+=1)
    {
        gotoxy(LEFT, TOP+i);
        for (int j=0; j<19; j+=1)
        {
            mapitem(twop1map[i][j]);
        }
    }

    int gx = 5,gy = 9,gx1 = 19,gy1 = 9,des = 0,des0 = 0,despre = 0,despre1 = 0,playerlive1 = 3,playerlive2 = 3;
    int x=7, y=9, score = 0,score1 = 0,x1 = 21,y1 = 9,whowin = 0,stopmin1 = 8,stopplayer2 = 0,stopmin2 = 8,stopplayer1 = 0;
    int live1 = 0,live2 = 0;
    gotoxy(8,3);
    setcolor(fgYELLOW);
    printf("● ● ●");
    gotoxy(8,17);
    printf("● ● ●");
    bool stop = false;
    gotoxy(82,0);
    setcolor(fgNORMAL);
    printf("beta build forever");
    while (!stop)
    {
        //gotoxy(0,0);
        //printf("                                                                                    beta build forever\n\n      score: %d",score);
        despre = des;
        despre1 = des0;

        if(gx == 3 && gy == 9)
        {

            twop1map[4][9] = 6;
            twop1map[18][9] = 6;

        }

        setcolor(fgYELLOW);
        gotoxy(LEFT+3*y, TOP+x);
        printf(" ●");
        gotoxy(LEFT+3*y1, TOP+x1);
        printf(" ●");
        setcolor(fgRED);
        gotoxy(LEFT+3*gy, TOP+gx);
        printf(" ▲");
        setcolor(fgGREEN);
        gotoxy(LEFT+3*gy1, TOP+gx1);
        printf(" ▲");

        //setcolor(fgNORMAL);
        setcolor(fgNORMAL);

        gotoxy(25,16);
        if(score > score1) printf("player 1 is in the lead");
        else if(score < score1) printf("player 2 is in the lead");
        else printf("nobody is wining");

        gotoxy(100,0);
        printf(" ");

        if(twop1map[x][y] == 0 || twop1map[x][y]== 15)
        {

            score += 1;

        }
        if(twop1map[x1][y1] == 0 || twop1map[x1][y1]== 15)
        {

            score1 += 1;

        }
        if(twop1map[x][y] == 15)
        {

            stopmin1 = 20;
            //stopplayer2 = 10;

        }
        if(twop1map[x1][y1] == 15)
        {

            stopmin2 = 20;
            //stopplayer2 = 10;

        }
        Sleep(120);

        if(gx == x && gy == y)
        {

            x = 7;
            y = 9;
            //c = 0;
            stopmin1 += 10;
            gotoxy(14 - 3*live1,3);
            printf("   ");
            live1 ++;
            if(twop1map[gx][gy] == 5)
            {

                gotoxy(LEFT+3*gy, TOP+gx);
                printf("   ");

            }
            else if(twop1map[gx][gy] == 15)
            {

                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" ◆");

            }
            else
            {

                //setcolor(fgNORMAL);
                gotoxy(LEFT+3*gy, TOP+gx);
                printf(" · ");

            }
            gx = 3;
            gy = 9;
            playerlive1 -= 1;

        }
        if(gx1 == x1 && gy1 == y1)
        {

            x1 = 21;
            y1 = 9;
            //c = 0;
            stopmin2 += 10;
            gotoxy(14 - 3*live2,17);
            printf("   ");
            live2 ++;
            if(twop1map[gx1][gy1] == 5)
            {

                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf("   ");

            }
            else if(twop1map[gx1][gy1] == 15)
            {

                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf(" ◆");

            }
            else
            {

                //setcolor(fgNORMAL);
                gotoxy(LEFT+3*gy1, TOP+gx1);
                printf(" · ");

            }
            gx1 = 17;
            gy1 = 9;
            playerlive2 -= 1;

        }



        gotoxy(LEFT+3*y, TOP+x);
        printf("   ");
        gotoxy(LEFT+3*y1, TOP+x1);
        printf("   ");
        twop1map[x][y] = 5;
        twop1map[x1][y1] = 5;


        int mindis = -1,mindis1 = -1,xde = 0,yde = 0,des1 = 0,des2 = 0,des3 = 0,des4 = 0,des21 = 0,des22 = 0,des23 = 0,des24 = 0;
        des1 = ((gx-1)-x)*((gx-1)-x)+(gy-y)*(gy-y);// ghost 1
        des2 = ((gx+1)-x)*((gx+1)-x)+(gy-y)*(gy-y);
        des3 = (gx-x)*(gx-x)+((gy-1)-y)*((gy-1)-y);
        des4 = (gx-x)*(gx-x)+((gy+1)-y)*((gy+1)-y);
        des21 = ((gx1-1)-x1)*((gx1-1)-x1)+(gy1-y1)*(gy1-y1);// ghost 2
        des22 = ((gx1+1)-x1)*((gx1+1)-x1)+(gy1-y1)*(gy1-y1);
        des23 = (gx1-x1)*(gx1-x1)+((gy1-1)-y1)*((gy1-1)-y1);
        des24 = (gx1-x1)*(gx1-x1)+((gy1+1)-y1)*((gy1+1)-y1);
        //des = 0;
        //des0 = 0;
        if (twop1map[gx-1][gy]==0 || twop1map[gx-1][gy]==5 || twop1map[gx-1][gy] == 15) // ghost 1
        {

            if((mindis > des1 || mindis == -1) && despre != 2)
            {

                mindis = des1;
                des=1;

            }

        }
        if(twop1map[gx+1][gy]==0 || twop1map[gx+1][gy]==5 || twop1map[gx+1][gy]== 15)
        {

            if((mindis > des2 || mindis == -1) && despre != 1)
            {

                mindis = des2;
                des=2;

            }

        }
        if(twop1map[gx][gy-1]==0 || twop1map[gx][gy-1]==5 ||twop1map[gx][gy-1]==15)
        {

            if((mindis > des3 || mindis == -1) && despre != 4)
            {

                mindis = des3;
                des=3;

            }

        }
        if(twop1map[gx][gy+1]==0 || twop1map[gx][gy+1]==5 || twop1map[gx][gy+1]==15)
        {

            if((mindis > des4 || mindis == -1) && despre != 3)
            {

                mindis = des4;
                des=4;

            }

        }

        if(twop1map[gx1+1][gy1]==0 || twop1map[gx1+1][gy1]==5 || twop1map[gx1+1][gy1]==15) //ghost 2
        {

            if((mindis1 > des22 || mindis1 == -1) && despre1 != 1)
            {

                mindis1 = des22;
                des0=2;

            }

        }
        if(twop1map[gx1][gy1-1]==0 || twop1map[gx1][gy1-1]==5 || twop1map[gx1][gy1-1]==15)
        {

            if((mindis1 > des23 || mindis1 == -1) && despre1 != 4)
            {

                mindis1 = des23;
                des0=3;

            }

        }
        if (twop1map[gx1-1][gy1]==0 || twop1map[gx1-1][gy1]==5 || twop1map[gx1-1][gy1]==15)
        {

            if((mindis1 > des21 || mindis1 == -1) && despre1 != 2)
            {

                mindis1 = des21;
                des0=1;

            }

        }
        if(twop1map[gx1][gy1+1]==0 || twop1map[gx1][gy1+1]==5 || twop1map[gx1][gy1+1]==15)
        {

            if((mindis1 > des24 || mindis1 == -1) && despre1 != 3)
            {

                mindis1 = des24;
                des0=4;

            }

        }

        gotoxy(LEFT+3*y, TOP+x);
        printf("   ");

        if(twop1map[gx][gy] == 5)
        {

            gotoxy(LEFT+3*gy, TOP+gx);
            printf("   ");

        }
        else if(twop1map[gx][gy] == 15)
        {

            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" ◆");

        }
        else
        {

            //setcolor(fgNORMAL);
            gotoxy(LEFT+3*gy, TOP+gx);
            printf(" · ");

        }

        if(twop1map[gx1][gy1] == 5)
        {

            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf("   ");

        }
        else if(twop1map[gx1][gy1] == 15)
        {

            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf("◆ ");

        }
        else
        {

            //setcolor(fgNORMAL);
            gotoxy(LEFT+3*gy1, TOP+gx1);
            printf(" · ");

        }


        if(score == 96)
        {

            whowin = 1;
            break;

        }
        if(score1 == 96)
        {

            whowin = 2;
            break;

        }
        if(playerlive1 == 0)
        {

            whowin = 2;
            break;

        }
        if(playerlive2 == 0)
        {

            whowin = 1;
            break;

        }

        for (int i = 0; i < 256; i++)
        {
            if (GetKeyState(i) & 0x8000)
            {

                switch (i)
                {
                case 38:
                    if (twop1map[x-1][y]==0 || twop1map[x-1][y]==5 || twop1map[x-1][y]==15) x-=1;
                    break;
                case 40:
                    if (twop1map[x+1][y]==0 || twop1map[x+1][y]==5 || twop1map[x+1][y]==15) x+=1;
                    break;
                case 37:
                    if (twop1map[x][y-1]==0 || twop1map[x][y-1]==5 || twop1map[x][y-1]==15) y-=1;
                    if(y == 0) y = 19;
                    break;
                case 39:
                    if (twop1map[x][y+1]==0 || twop1map[x][y+1]==5 || twop1map[x][y+1]==15) y+=1;
                    if(y == 20) y = 1;
                    break;
                case 87:
                    if (twop1map[x1-1][y1]==0 || twop1map[x1-1][y1]==5 || twop1map[x1-1][y1]==15) x1-=1;
                    break;
                case 83:
                    if (twop1map[x1+1][y1]==0 || twop1map[x1+1][y1]==5 || twop1map[x1+1][y1]==15) x1+=1;
                    break;
                case 65:
                    if (twop1map[x1][y1-1]==0 || twop1map[x1][y1-1]==5 || twop1map[x1][y1-1]==15) y1-=1;
                    if(y == 0) y = 19;
                    break;
                case 68:
                    if (twop1map[x1][y1+1]==0 || twop1map[x1][y1+1]==5 || twop1map[x1][y1+1]==15) y1+=1;
                    if(y == 20) y = 1;
                    break;
                case keyESC:
                    stop = true;
                    break;
                }

            }
        }
        if(stopmin1 == 0)
        {

            switch (des)
            {
            case 1:
                gx-=1;
                break;
            case 2:
                gx+=1;
                break;
            case 3:
                gy-=1;
                break;
            case 4:
                gy+=1;
                break;
            }
        }
        else stopmin1 -= 1;
        if(stopmin2 == 0)
        {
            switch (des0)
            {
            case 1:
                gx1-=1;
                break;
            case 2:
                gx1+=1;
                break;
            case 3:
                gy1-=1;
                break;
            case 4:
                gy1+=1;
                break;
            }
        }
        else stopmin2 -= 1;
    }

    system("cls");
    if(whowin == 1)
    {

        //printf("player 1 win");
        gotoxy(82,0);
        setcolor(fgNORMAL);
        printf("beta build forever");
        printf("\n\n\n  ██████　██　　　　██████　██　　██　██████　██████　　　　　██\n  ██　　██　██　　　　██　　██　██　　██　██　　　　　██　　██　　　　　██\n  ██████　██　　　　██████　　████　　██████　██████　　　　　██\n  ██　　　　　██　　　　██　　██　　　██　　　██　　　　　██　██　　　　　　██\n  ██　　　　　█████　██　　██　　　██　　　██████　██　　██　　　　　██\n");
        printf("\n\n\n  ██　　　██　██　██　　██\n  ██　█　██　██　███　██\n  ███████　██　██████\n  ███　███　██　██　███\n  ██　　　██　██　██　　██\n\n\n\n");
        for(int doc = 0; doc < 35; doc ++)
        {
            printf(" ·");
        }
        for(int ani = 0; ani < 70; ani ++)
        {

            gotoxy(70 - ani,19);
            setcolor(fgYELLOW);
            printf("●   ");
            setcolor(fgRED);
            printf("▲");

            gotoxy(100,0);
            printf(" ");
            Sleep(30);
            printf("          ");

        }
        gotoxy(28,25);
        setcolor(fgNORMAL);
        printf("- - - press anything to back to main meun - - -");
        setcolor(fgBLACK);
        //Sleep(1000);

    }
    if(whowin == 2)
    {

        gotoxy(82,0);
        setcolor(fgNORMAL);
        printf("beta build forever");
        printf("\n\n\n  ██████　██　　　　██████　██　　██　██████　██████　　　██████\n  ██　　██　██　　　　██　　██　██　　██　██　　　　　██　　██　　　　　　　██\n  ██████　██　　　　██████　　████　　██████　██████　　　██████\n  ██　　　　　██　　　　██　　██　　　██　　　██　　　　　██　██　　　　██\n  ██　　　　　█████　██　　██　　　██　　　██████　██　　██　　　██████\n");
        printf("\n\n\n  ██　　　██　██　██　　██\n  ██　█　██　██　███　██\n  ███████　██　██████\n  ███　███　██　██　███\n  ██　　　██　██　██　　██\n\n\n\n");
        for(int doc = 0; doc < 35; doc ++)
        {
            printf(" ·");
        }
        for(int ani = 0; ani < 70; ani ++)
        {

            gotoxy(70 - ani,19);
            setcolor(fgYELLOW);
            printf("●   ");
            setcolor(fgGREEN);
            printf("▲");

            gotoxy(100,0);
            printf(" ");
            Sleep(30);
            printf("          ");

        }
        gotoxy(28,25);
        setcolor(fgNORMAL);
        printf("- - - press anything to back to main meun - - -");
        setcolor(fgBLACK);

    }
    //printf("\n\n\n\n    ██　　██　██████　██　　██　　　██　　　██　██　██　　██\n    ██　　██　██　　██　██　　██　　　██　█　██　██　███　██\n    　████　　██　　██　██　　██　　　███████　██　██████\n    　　██　　　██　　██　██　　██　　　███　███　██　██　███ \n    　　██　　　██████　██████　　　██　　　██　██　██　　██\n\n");
    //system("pause");
}





