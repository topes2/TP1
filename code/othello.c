#include <stdio.h>
#include <string.h>
#include "othello_func.h"

void main(){
    int linha,col,ordem;
    int turn=2;
    if (random() % 2 == 0)
        ordem = 1;
    else 
        ordem = 0;

    char board[9][9];
    init_board(board);        
    
    for (int i = 0; i < 9; i++)
        for ( int j = 0; i < 9; j++)
        {   
            print_board(board); 
            turn++;
            do
            {
                input(&linha,&col);
                printf("linha %d \n coluna %d\n",linha,col);   
                play(board,player(turn,0),linha,col); 
                if (board[linha][col]!= player(turn,0))
                    printf(" Jogada invalida\n Jogue outra vez\n");
            }while (board[linha][col]!= player(turn,0)); 
        }
}