#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "othello_func.h"

int main(int argc, char** argv){

    int linha,col,ordem;
    int temp=0,end=0;
    int turn=1;
    char coluna[10], board[9][9];
    FILE *f;
    char p;
    init_board(board);
    
    printf("Othello Game\n \n");

    ordem=rand()%2+1;
    ordem=1;
    if ((argv[1]!= NULL) && (f = fopen(argv[1],"r")) != NULL){

        if(ordem==1){
        printf("Your discs are black.\n\n");
        
        while (end != 1)
            { 
            turn++;
            if (next(board,player(turn)) != 0){
                temp=0;

                fplayer_turn(f,board,turn);

                turn++;
                bot_turn(board,turn);
            
        }else if (next(board,player(turn)) == 0){
            temp++;
            if (temp = 2)
            end++;
        }
        }
        print_board(board);
        end_game(board,'x');
        }

        else
        {
            printf("Your discs are white.\n\n");
            
            while (end != 1)
                { 
                turn++;
                if (next(board,player(turn)) != 0){
                    temp=0;
                    turn++;

                    bot_turn(board,turn);

                    turn++;

                    fplayer_turn(f,board,turn);       
                    
            }else if (next(board,player(turn)) == 0){
                temp++;
                if (temp = 2)
                end++;
            }
            }
            print_board(board);
            end_game(board,'0');
        }
    }

    if(ordem==1){
        printf("Your discs are black.\n\n");
        
        while (end != 1)
            { 
            turn++;
            if (next(board,player(turn)) != 0){
                temp=0;

                player_turn(board,turn);

                turn++;
                bot_turn(board,turn);
            
        }else if (next(board,player(turn)) == 0){
            temp++;
            if (temp = 2)
            end++;
        }
        }
        print_board(board);
        end_game(board,'x');
    }

    else
    {
        printf("Your discs are white.\n\n");
        
        while (end != 1)
            { 
            turn++;
            if (next(board,player(turn)) != 0){
                temp=0;
                turn++;

                bot_turn(board,turn);

                turn++;

                player_turn(board,turn);       
                
        }else if (next(board,player(turn)) == 0){
            temp++;
            if (temp = 2)
            end++;
        }
        }
        print_board(board);
        end_game(board,'0');
    }

}