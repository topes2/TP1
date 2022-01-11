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
    m_jogo=menu();

    if(m_jogo=1){ 
        gameloop(board,turn);
    }else if (m_jogo=2){
        //pfft dkdc
    }
/*
###############################################################################################
parcela do main se existir file jogadas.txt
###############################################################################################
*/
    if ((argv[1]!= NULL) && (f = fopen(argv[1],"r")) != NULL){
        
    while (fscanf(f,"%d %c",&linha,&coluna)!=EOF)
    {  
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        next(board,player(turn),1);
        printf("    Vez do jogador (%c)\n",player(turn)); 
        play(board,player(turn),linha,col); 
            if (board[linha][col]!= player(turn)){
                 printf(" Jogada invalida\n Jogue outra vez\n");
                 turn--;
            }
    };
        next(board,player(turn),0);
        fclose(f); //fechar o file
        gameloop(board,turn);
        return 0;
    }

}