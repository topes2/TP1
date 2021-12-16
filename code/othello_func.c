#include <stdio.h>
#include "othello_func.h"

    int turn = 0;
    int linha,col;

int menu(){
    int mainmode,segmode;
    printf("Bem vindo a Othello por Andre e Diogo\n");
    printf("Que modo gostaria de jogar?\n \
    1-Modo Classico onde 4 peças ja estao colocadas no tabuleiro\n \
    2-Modo Custom onde pode escolher onde inserir as peças inciais\n");
    scanf("%d",&mainmode);
    if (mainmode == 1){
        printf("\
         1-Pessoa V Pessoa\n \
        2-Pessoa V Bot\n");
        scanf("%d",&segmode);
        if (segmode == 1){
            return(segmode);
        }else
            return (segmode);
    }else
        printf("\
         1-Pessoa V Pessoa\n \
        2-Pessoa V Bot\n");
        scanf("%d",&segmode);
        if (segmode == 1){
            return(segmode);
        }else
            return (segmode);
} 

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
 
<<<<<<< HEAD
char* init_board(char tboard[9][9]){ // inserir as primerias peças para o jogo padrao 
    for (int l= 0; l < 9; l++){  // todo simpleficar e por bonito 
=======
void init_board(char tboard[9][9]){ // inserir as primerias peças para o jogo padrao
    for (int l= 0; l < 9; l++){
>>>>>>> main
        for (int c = 0; c < 9; c++){
            if(l == 4 && c == 4 || l == 5 && c == 5)
                tboard[l][c] = 'o';
            else if(l== 4 && c == 5 || l == 5 && c == 4)
                tboard[l][c]= 'x';      
            }
        }
}

/*char* play(char board[9][9],int linha,int col,int color){
    if (check(board[9][9],linha,col,color) != 0){
        
    }
}
*/
char p2(char player){
    if (player=='x') return 'o';
    else return 'x';
 }
 
void input(int *linha,int *col){
    char coluna;
    int linhatemp;
    printf("Insira a jogada ( separada por um espaço, coluna por linha)\n");
    scanf(" %c ",&coluna);
    scanf(" %d",&linhatemp);
    *col = (int) (decode(coluna));
    *linha = linhatemp;
    return(linha,col);
}
void play(char board[9][9],char player, int linha, char coluna){
    int col;
    int ppvirar[8]={0,0,0,0,0,0,0,0};
    int maior;
    char player2;

    
    col = decode(coluna);
    direction(board,linha,col,player,ppvirar);
    maior = ppvirar[0];
    for (int i = 0; i < 8; i++)
    {
        if (maior < ppvirar[i])
            maior = ppvirar[i];
    }

    for (int i = 0; i < 8; i++)
    {
        if (ppvirar[i] == maior)
        { 
            if (i==0)// direção este
                for ( int j = col+1, viradas=0; viradas < maior ; j++, viradas++ )
                    board[linha][j] = player;
             else if (i==1)// direção sul
                for ( int j = linha+1, viradas=0; viradas < maior ; j++, viradas++ )
                    board[j][col] = player;
            else if (i==2)// direção oeste
                for ( int j = col-1, viradas=0; viradas < maior ; j--, viradas++ )
                    board[linha][j] = player;
            else if (i==3)// direção norte
                for ( int j = linha-1, viradas=0; viradas < maior ; j--, viradas++ )
                    board[j][col] = player;
            else if (i==4)// direção noroeste
                for ( int m = linha-1 ,j = col-1, viradas=0; viradas < maior ;m-- , j--, viradas++ )
                    board[m][j] = player;        
            else if (i==5)// direção suldoeste
                for ( int m = linha++ ,j = col--, viradas=0; viradas < maior ;m++ , j--, viradas++ )
                    board[m][j] = player;     
            else if (i==6)// direção suldeste
                for ( int m = linha++ ,j = col++, viradas=0; viradas < maior ;m++ , j++, viradas++ )
                    board[m][j] = player;         
            else if (i==7)// direção nordeste
                for ( int m = linha-- ,j = col++, viradas=0; viradas < maior ;m-- , j++, viradas++ )
                    board[m][j] = player;  
        }
        
    }
    
    




}
int check(char board[9][9],int l,int c,int linha,int col,char player){ //esta funçao serve para correr todas as peças ate encontrar ou uma peça do jogador ou um espaço em branco
    int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0; // numero de peças do outro jogador entre as peças do jogador nas 8 direçoes
    char player2;
    
    

    player2 = p2(player);
    
    if (l == 0){  //vemos se ha e contamos as peças do outro jogador na direçao este
        if (c ==1){
            while(board[linha][col] == player2){
                i1++;
                col++;
                if (board[l][c] == player)    
                    return i1;
            }
        }
    }
    if (c == 0){  //vemos se ha e contamos as peças do outro jogador na direçao sul
        if (l ==1){
            while(board[linha][col] == player2){ 
                i2++;
                linha++;
                if (board[l][c] == player)
                    return i2;
            }
        }
    }
    if (l == 0){ //vemos se ha e contamos as peças do outro jogador na direçao oeste
        if(c == -1){
            while(board[linha][col] == player2){
                i3++;
                col--;
                if (board[l][c] == player)
                    return i3;
            }
        }
    }
    if (c == 0){ //vemos se ha e contamos as peças do outro jogador na direçao norte
        if(l == -1){
            while(board[linha][col] == player2){
                i4++;
                linha--;
                if (board[l][c] == player)
                    return i4;
            }
        }
    }
        if (l == -1 && c == -1){ //vemos se ha e contamos as peças do outro jogador na direçao nordoeste
            while(board[linha][col] == player2){
                i5++;
                linha--;
                col--;
                if (board[l][c] == player)
                    return i5;
            }
        }
        if (l == 1 && c == -1){  //vemos se ha e contamos as peças do outro jogador na direçao sudoeste
            while(board[linha][col] == player2){
                i6++;
                linha++;
                col--;
                if (board[l][c] == player)
                    return i6;
            }
        }
        if (l == 1 && c == 1){   //vemos se ha e contamos as peças do outro jogador na direçao sudeste
            while(board[linha][col] == player2){
                i7++;
                linha++;
                col++;
                if (board[l][c] == player)
                    return i7;
            }
        }
        if (l == -1 && c == 1){  //vemos se ha e contamos as peças do outro jogador na direçao nordeste
            while(board[linha][col] == player2){
                i8++;
                linha--;
                col++;
                if (board[l][c] == player )
                    return i8;
            }
        }
    }

void direction(char board[9][9],int linha, int col,char player,int p[8]){
    
    int p=0; // quantidade de peças diferentes do jogador actual que esta a jogar
    for (int i=0 ,l=-1;l == -1 || l == 0|| l == 1;l++){
        for (int c = -1; c == -1 || c == 0 || c == 1;c++,i++){
            if ( board[linha][col] == '.'){
                if (board[linha+l][col+c]!=player && board[linha+l][col+c]!='.' && linha+l < 9 && col+c < 9 && linha+l > 0 && col+c > 0){
                    p[i]= check(board,l,c,linha+l,col+c,player);    
                }
            }
        }
    }
}

int decode(char letra){ //alterar para uma função n merda
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