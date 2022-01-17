#include <stdio.h>
#include <string.h>
#include "othello_func.h"

int main(int argc, char** argv){

    int linha,col,ordem,m_jogo;
    int turn=1;
    char coluna[10], board[9][9];
    FILE *f;
    init_board(board);
    
    /*if ((argv[1]!= NULL) && (f = fopen(argv[1],"r")) != NULL){
    int temp=0,end=0;
        while (end != 1)
        { 
        turn++;
        if (next(board,player(turn)) != 0){
        do
        {
            temp=0;
            printf("             Pontuação\n");
            printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
            next(board,player(turn));
            print_board(board);
            printf("    Vez do jogador (%c)\n",player(turn));
            if(fintput(f,&linha,&col)==0) break;

            play(board,player(turn),linha,col,1); 
                if (board[linha][col]!= player(turn))
                     printf(" Jogada invalida\n Jogue outra vez\n");    
        }while (board[linha][col]!= player(turn));

        turn++;
        next(board,player(turn));
        print_board(board);
        bot(board,player(turn));
        
    }else if (next(board,player(turn)) == 0){
        temp++;
        if (temp = 2)
        end++;
    }
    printf("acabou");
    }
    }
    */
    m_jogo=menu();

    if(m_jogo=1){ 
        gameloop(board,turn);
    }else if (m_jogo=2){
        //pfft dkdc
    }

//###############################################################################################
//parcela do main se existir file jogadas.txt
//###############################################################################################

 /*   if ((argv[1]!= NULL) && (f = fopen(argv[1],"r")) != NULL){
        
    while (fscanf(f,"%d %c",&linha,&coluna)!=EOF)
    {  
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        next(board,player(turn));
        printf("    Vez do jogador (%c)\n",player(turn)); 
        play(board,player(turn),linha,col); 
            if (board[linha][col]!= player(turn)){
                 printf(" Jogada invalida\n Jogue outra vez\n");
                 turn--;
            }
    };
        next(board,player(turn));
        fclose(f); //fechar o file
        gameloop(board,turn);
        return 0;
    }
*/
}