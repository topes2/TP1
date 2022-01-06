#include <stdio.h>
#include <string.h>
#include "othello_func.h"

int main(){
    
    int linha,col,ordem;
    int turn=2;
    char coluna[10];
    

    FILE *f;
    if (random() % 2 == 0)
        ordem = 1;
    else 
        ordem = 0;

    char board[9][9];
    
    menu();
    init_board(board);
    print_board(board);

    if ((f = fopen("jogadas.txt","r")) != NULL){
        
    while (fscanf(f,"%s %d",coluna,&linha)!=EOF)
    {  
        
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        print_board(board);
        col=decode(coluna[0]);
        printf("linha %d \ncoluna %d\n",linha,col);   
        play(board,player(turn,0),linha,col); 
            if (board[linha][col]!= player(turn,0))
                 printf(" Jogada invalida\n Jogue outra vez\n");
    };
        return 0;
}
   

      
    for (int i = 0; i < 9;)
    { 
    
    do
    {  
        turn++;
        printf("             Pontuação\n");
        printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
        next(board,player);
        input(&linha,&col);
        printf("linha %d \ncoluna %d\n",linha,col);   
        play(board,player(turn,0),linha,col); 
            if (board[linha][col]!= player(turn,0))
                 printf(" Jogada invalida\n Jogue outra vez\n");
    }while (board[linha][col]!= player(turn,0)); 
    }
}