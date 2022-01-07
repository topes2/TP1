#include <stdio.h>
#include <string.h>
#include "othello_func.h"

int main(int argc, char** argv){

    int linha,col,ordem,m_jogo;
    int turn=1;
    char coluna[10], board[9][9];
    FILE *f;
if (random() % 2 == 0)
        ordem = 1;
    else 
        ordem = 0;

    
    init_board(board);
/*
###############################################################################################
parcela do main se existir file jogadas.txt
###############################################################################################
*/
    if ((argv[1]!= NULL) && (f = fopen(argv[1],"r")) != NULL){
        
    while (fscanf(f,"%d %d",coluna,&linha)!=EOF)
    {  
        
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        print_board(board);
        printf("    Vez do jogador (%c)\n",player(turn));
        col=decode(coluna[0]);  
        play(board,player(turn),linha,col); 
            if (board[linha][col]!= player(turn)){
                 printf(" Jogada invalida\n Jogue outra vez\n");
                 turn--;
            }
    };
        print_board(board);
        return 0;
    }
/*
###############################################################################################
parcela do main se não existir file jogadas.txt
###############################################################################################
*/
    m_jogo=menu();

    if(m_jogo=1){
        int end = 0,temp=0;
        while (end != 1)
        { 
        turn++;
        if (next(board,player(turn),0) != 0){
        do
        {
            temp=0;  
            printf("             Pontuação\n");
            printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
            next(board,player(turn),1);
            printf("    Vez do jogador (%c)\n",player(turn));
            input(&linha,&col);  
            play(board,player(turn),linha,col); 
                if (board[linha][col]!= player(turn))
                     printf(" Jogada invalida\n Jogue outra vez\n");
                
        }while (board[linha][col]!= player(turn)); 
    }else if (next(board,player(turn),0) == 0){
        temp++;
        if (temp = 2)
        end++;
    }
    }
    
}
}