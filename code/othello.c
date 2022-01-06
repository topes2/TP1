#include <stdio.h>
#include <string.h>
#include "othello_func.h"

int main(){
    
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
    if ((f = fopen("jogadas.txt","r")) != NULL){
        
    while (fscanf(f,"%s %d",coluna,&linha)!=EOF)
    {  
        
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        print_board(board);
        printf("    Vez do jogador (%c)\n",player(turn));
        col=decode(coluna[0]);
        //printf("linha %d \ncoluna %d\n",linha,col);   
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
parcela do main se existir file jogadas.txt
###############################################################################################
*/
    m_jogo=menu();
    f = fopen("jogadas.txt","w");

    if(m_jogo=1)
        for (int i = 0; i < 9;)
        { turn++;
        do
        {  
            printf("             Pontuação\n");
            printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
            next(board,player(turn));
            printf("    Vez do jogador (%c)\n",player(turn));
            input(&linha,&col);
            fprintf(f,"%d %d\n",col,linha);  
            play(board,player(turn),linha,col); 
                if (board[linha][col]!= player(turn))
                     printf(" Jogada invalida\n Jogue outra vez\n");
                if(linha == 10){
                fclose(f);
                return 0;
                }
        }while (board[linha][col]!= player(turn)); 
    }
    fclose(f);
}