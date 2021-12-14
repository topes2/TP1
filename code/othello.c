#include <stdio.h>
#include <string.h>
#include "othello_func.h"

void main(){
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
    
}