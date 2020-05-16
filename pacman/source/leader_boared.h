#include<stdio.h>
#include<stdlib.h>

#ifndef LEADER__
#define LEADER__

struct leaderboared_format
{
    char play_name[30] = {};
    int score = -1,uesd = 0;
};
struct leaderboard_top10
{
    leaderboared_format top10[11];
    int player_on_board = 0;
};

#endif

void read_in_leaderboard(FILE *oldlea,leaderboard_top10 *leainfo);

void write_in_leaderboard(FILE *newlea,leaderboard_top10 leainfo);
