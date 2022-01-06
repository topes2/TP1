#include <stdio.h>
#include <string.h>
#include "othello_func.h"

int main(){
    
    int linha,col,ordem,m_jogo;
    int turn=2;
    char coluna[10], board[9][9];
    FILE *f;

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
        col=decode(coluna[0]);
        printf("linha %d \ncoluna %d\n",linha,col);   
        play(board,player(turn),linha,col); 
            if (board[linha][col]!= player(turn))
                 printf(" Jogada invalida\n Jogue outra vez\n");
    };
        return 0;
    }
/*
###############################################################################################
parcela do main se existir file jogadas.txt
###############################################################################################
*/
    if (random() % 2 == 0)
        ordem = 1;
    else 
        ordem = 0;

    m_jogo=menu();
    init_board(board);
    if ((f = fopen("jogadas.txt","w")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    if(m_jogo=1)
        for (int i = 0; i < 9;)
        { turn++;
        do
        {  
            
            printf("             Pontuação\n");
            printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
            next(board,player);
            input(&linha,&col);
            fprintf(f,"%d %d",col,linha);
            printf("linha %d \ncoluna %d\n",linha,col);   
            play(board,player(turn),linha,col); 
                if (board[linha][col]!= player(turn))
                     printf(" Jogada invalida\n Jogue outra vez\n");
        }while (board[linha][col]!= player(turn)); 
    }
    fclose(f);
}