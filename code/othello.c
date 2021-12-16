#include <stdio.h>
#include <string.h>
#include "othello_func.h"

void main(){
    int linha,col;
    char board[9][9]={
        {' ','A','B','C','D','E','F','G','H'},
        {'1','.','.','.','.','.','.','.','.'},
        {'2','.','.','.','.','.','.','.','.'},
        {'3','.','.','.','.','.','.','.','.'},
        {'4','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'}
    };        
    print_board(init_board(board));
    /* a certo ponto tenho de implementar uma maneira de fazer isto de uma maneria mais bonita mas por enquanto vai ser assim que vamos dar os valores para as
    variaveis de coluna e linha */
    input(&linha,&col);
    printf("linha %d \n coluna %d",linha,col);   
}