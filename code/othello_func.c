#include <stdio.h>
#include "othello_func.h"

    int turn = 0;
    int linha,col;

char player(int turn){
    turn++;
    if (turn % 2 == 0){
        return 'o';
    }else {
        return 'x';    
}
}

char print_board(char tboard[9][9]){
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
            printf("%c  ", tboard[l] [c]);
        }
        printf("\n");
        }
}
 
char* init_board(char tboard[9][9]){ // inserir as primerias peças para o jogo padrao
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
            if(l == 4 && c == 4 || l == 5 && c == 5)
                tboard[l][c] = 'o';
            else if(l== 4 && c == 5 || l == 5 && c == 4)
                tboard[l][c]= 'x';      
            }
        }
    return(tboard);
}

/*char* play(char board[9][9],int linha,int col,int color){
    if (check(board[9][9],linha,col,color) != 0){
        
    }
}
*/

int input(int *linha,int *col){
    char coluna;
    int linhatemp;
    printf("Insira a jogada ( separada por um espaço, coluna por linha)\n");
    scanf("%c ",&coluna);
    scanf("%x",&linhatemp);
    *col = (int) (decode(coluna));
    printf("%d \n %d",decode(coluna),linhatemp);
    *linha = linhatemp;
    return(linha,col);
}

int check(char board[9][9],int l,int c,int linha,linha col,char player){ //esta funçao serve para correr todas as peças ate encontrar ou uma peça do jogador ou um espaço em branco
    int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0; // numero de peças do outro jogador entre as peças do jogador nas 8 direçoes
    if (l == 0){  //vemos se ha e contamos as peças do outro jogador na direçao este
        if (c ==1){
            while(board[l][c] != player && board[l][c]!= '.'){
                i1++;
                c++;
                if (board[l][c] == player)
                    return i1;
            }
        }
    }
    if (c == 0){  //vemos se ha e contamos as peças do outro jogador na direçao norte
        if (l ==1){
            while(board[l][c] != player && board[l][c]!= '.'){ 
                i2++;
                l++;
                if (board[l][c] == player)
                    return i2;
            }
        }
    }
    if (l == 0){ //vemos se ha e contamos as peças do outro jogador na direçao oeste
        if(c == -1){
            while(board[l][c] != player && board[l][c]!= '.'){
                i3++;
                c--;
                if (board[l][c] == player)
                    return i3;
            }
        }
    }
    if (c == 0){ //vemos se ha e contamos as peças do outro jogador na direçao sul
        if(l == -1){
            while(board[l][c] != player && board[l][c]!= '.'){
                i4++;
                l--;
                if (board[l][c] == player)
                    return i4;
            }
        }
    }
        if (l == -1 && c == -1){ //vemos se ha e contamos as peças do outro jogador na direçao nordoeste
            while(board[l][c] != player && board[l][c]!= '.'){
                i5++;
                l--;
                c--;
                if (board[l][c] == player)
                    return i5;
            }
        }
        if (l == 1 && c == -1){  //vemos se ha e contamos as peças do outro jogador na direçao nordeste
            while(board[l][c] != player && board[l][c]!= '.'){
                i6++;
                l++;
                c--;
                if (board[l][c] == player)
                    return i6;
            }
        }
        if (l == 1 && c == 1){   //vemos se ha e contamos as peças do outro jogador na direçao sudeste
            while(board[l][c] != player && board[l][c]!= '.'){
                i7++;
                l++;
                c++;
                if (board[l][c] == player)
                    return i7;
            }
        }
        if (l == 1 && c == -1){  //vemos se ha e contamos as peças do outro jogador na direçao sudoeste
            while(board[l][c] != player && board[l][c]!= '.'){
                i8++;
                l++;
                c--;
                if (board[l][c] == player )
                    return i8;
            }
        }
    }

int direction(char board[9][9],int linha, int col,char player){
    int p=0; // quantidade de peças diferentes do jogador actual que esta a jogar
    for (int l=-1;l == -1 || l == 0|| l == 1;l++){
        for (int c = -1; c == -1 || c == 0 || c == 1;c++){
            if ( board[linha][col] == '.'){
                if (board[linha+l][col+c]!=player && board[linha+l][col+c]!='.' && linha+l < 9 && col+c < 9 && linha+l > 0 && col+c > 0){
                    if (check(board,l,c,linha+l,col+c,player) > p)
                        p = check(board,l,c,linha+l,col+c,player);
                }
            }
        }
    }
}

int decode(char letra){
    if ((letra == 'a') || (letra == 'A'))
        return (int) 1;
    else if ((letra == 'b') || (letra == 'B'))
        return (int) 2;
    else if ((letra == 'c') || (letra == 'C')) 
        return (int) 3;
    else if (letra == 'd' || letra == 'D')
        return (int) 4;
    else if (letra == 'e' || letra == 'E')
        return (int) 5;
    else if (letra == 'f' || letra == 'F')
        return (int) 6;
    else if (letra == 'g' || letra == 'G')
        return (int) 7;
    else if (letra == 'f' || letra == 'F')
        return (int) 8;
    else
        return (int) 0;
}

char* rewrite(char board[9][9]){
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
                board[l][c] = '.';
            }
        }
    return(board);
}