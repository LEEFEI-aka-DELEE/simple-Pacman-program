#include"leader_boared.h"


void read_in_leaderboard(FILE *oldlea,leaderboard_top10 *leainfo)
{
    int i = 0;
    while(!feof(oldlea))
    {
        fscanf(oldlea,"%s %d",leainfo->top10[i].play_name,&leainfo->top10[i].score);
        leainfo->top10[i].uesd = 1;
        leainfo->player_on_board ++;
        i ++;
    }
}

void write_in_leaderboard(FILE *newlea,leaderboard_top10 leainfo)
{
    for(int i = 0;i < leainfo.player_on_board;i ++)
    {
        fprintf(newlea,"%s %d\n",leainfo.top10[i].play_name,leainfo.top10[i].score);
    }

}
