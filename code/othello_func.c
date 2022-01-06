#include <stdio.h>
#include <time.h>
#include "othello_func.h"

int linha,col;
/*
###############################################################################################
Funçao menu
Simplesmente mostra um menu ao user de mode para fazer a escolha do modo que quer jogar
se for contra o pc ou contra outra pessoa
###############################################################################################
*/
int menu(){
    int mainmode;
    printf("Bem vindo a Othello por Andre e Diogo\n");
    printf("Que modo gostaria de jogar?\n \
    1-Modo pessoa vs pessoa\n \
    2-Modo pessoa vs computador\n");
    do
        scanf("%d",&mainmode);
    while (mainmode != 1 && mainmode != 2);
     

    return mainmode;
}
/*
###############################################################################################
Funçao para fazer um numero aleatorio para poder ter uma ordem de jogadores random
usa a lib time.h
###############################################################################################
*/
int random(){
    srand(time(NULL));
    int r = rand();
    return r;
}

/*
##############################################################################################################################################################################################
*/
char player(int turn){
    
    if (turn % 2 == 0) return 'o';
    else return 'x';    
}

/*
##############################################################################################################################################################################################
*/
char print_board(char tboard[9][9]){
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
            if (c != 0)
            printf("%c  ", tboard[l][c]);
            else if(c == 0 && l == 0)
            printf("  ");
            else
            printf("%d ",tboard[l][c]);
        }
        printf("\n");
        }
}

/*
###############################################################################################
##############################################################################################
*/ 
void init_board(char tboard[9][9]){
    for (int l = 0; l <= 9; l++){
        for (int c = 0; c <= 9; c++){
            tboard[l][c] = '.';
            if(l == 4 && c == 4 || l == 5 && c == 5)
                tboard[l][c] = 'o';
            else if(l== 4 && c == 5 || l == 5 && c == 4)
                tboard[l][c]= 'x';  
            if (l == 0 && c > 0)
                tboard[l][c] = (char) 64+c;
            if (c == 0 && l > 0)
                tboard[l][c] = l;

            }
        }
}

/*
###############################################################################################
##############################################################################################
*/
char p2(char player){
    if (player=='x') return 'o';
    else return 'x';
 }

/*
###############################################################################################
Funçao Input
###############################################################################################
*/
void input(int *linha,int *col){
    char coluna;
    int linhatemp;
    printf("Insira a jogada (coluna e linha)\n");
    scanf(" %c ",&coluna);
    scanf(" %d",linha);
    *col = decode(coluna);
    
}

/*
###############################################################################################
Funçao Play
###############################################################################################
*/
void play(char board[9][9],char player, int linha, int coluna){
    
    int ppvirar[8]={0,0,0,0,0,0,0,0};
    char player2;
    int *p;
    int pecasviradas=0;
    p=&ppvirar[0];
    
    direction(board,linha,coluna,player,p);

    for (int i = 0; i < 8; i++)
    {
        if (ppvirar[i] != 0 )
        { 
            if (i==0)// direção este
                for ( int j = coluna, viradas=0; viradas <= ppvirar[i] ; j++, viradas++ )
                    board[linha][j] = player;
             else if (i==1)// direção sul
                for ( int j = linha, viradas=0; viradas <=  ppvirar[i] ; j++, viradas++ )
                    board[j][coluna] = player;
            else if (i==2)// direção oeste
                for ( int j = coluna, viradas=0; viradas <=  ppvirar[i]; j--, viradas++ )
                    board[linha][j] = player;
            else if (i==3)// direção norte
                for ( int j = linha, viradas=0; viradas <=  ppvirar[i] ; j--, viradas++ )
                    board[j][coluna] = player;
            else if (i==4)// direção noroeste
                for ( int m = linha ,j = coluna, viradas=0; viradas <=  ppvirar[i] ;m-- , j--, viradas++ )
                    board[m][j] = player; 
            else if (i==5)// direção suldoeste
                for ( int m = linha ,j = coluna, viradas=0; viradas <=  ppvirar[i] ;m++ , j--, viradas++ )
                    board[m][j] = player;
            else if (i==6)// direção suldeste
                for ( int m = linha ,j = coluna, viradas=0; viradas <=  ppvirar[i] ;m++ , j++, viradas++ )
                    board[m][j] = player;     
            else if (i==7)// direção nordeste
                for ( int m = linha ,j = coluna, viradas=0; viradas <=  ppvirar[i] ;m-- , j++, viradas++ )
                    board[m][j] = player;            
        }
    }
    for ( int i = 0; i < 8; i++)
        pecasviradas=pecasviradas+ppvirar[i];

    
    printf("%d peças viradas\n",pecasviradas);
   
}

/*
###############################################################################################
Funçao Check
Esta funçao serve para nos vermos se a jogada e valida e se vira alguma peça
na direcao dada pela funçao direction.
###############################################################################################
*/
int check(char board[9][9],int l,int c,int linha,int col,char player,int *p){ //esta funçao serve para correr todas as peças ate encontrar ou uma peça do jogador ou um espaço em branco
    int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0; // numero de peças do outro jogador entre as peças do jogador nas 8 direçoes
    char player2;
    player2 = p2(player);
    

    
    //printf("\n");
    if (l == 0){  //vemos se ha e contamos as peças do outro jogador na direçao este
     //printf("1\n");
        if (c ==1){
            //printf("2\n");
            while(board[linha][col] == player2){
                //printf("3\n");
                i1++;
                col++;
                if (board[linha][col] == player)    
                    //printf("4\n");
                    //printf("%d\n",i1);
                    *p=i1;
                    
            }
        }
    }
    if (c == 0){  //vemos se ha e contamos as peças do outro jogador na direçao sul
        if (l ==1){
            while(board[linha][col] == player2){ 
                i2++;
                linha++;
                if (board[linha][col] == player)
                    *(p+1) = i2;
                    
            }
        }
    }
    if (l == 0){ //vemos se ha e contamos as peças do outro jogador na direçao oeste
        if(c == -1){
            while(board[linha][col] == player2){
                i3++;
                col--;
                if (board[linha][col] == player)
                    *(p+2)=i3;
            }
        }
    }
    if (c == 0){ //vemos se ha e contamos as peças do outro jogador na direçao norte
        if(l == -1){
            while(board[linha][col] == player2){
                i4++;
                linha--;
                if (board[linha][col] == player)
                    *(p+3)=i4;
            }
        }
    }
        if (l == -1 && c == -1){ //vemos se ha e contamos as peças do outro jogador na direçao noroeste
            while(board[linha][col] == player2){
                i5++;
                linha--;
                col--;
                if (board[linha][col] == player)
                    *(p+4)=i5;
            }
        }
        if (l == 1 && c == -1){  //vemos se ha e contamos as peças do outro jogador na direçao sudoeste
            while(board[linha][col] == player2){
                i6++;
                linha++;
                col--;
                if (board[linha][col] == player)
                    *(p+5)=i6;
            }
        }
        if (l == 1 && c == 1){   //vemos se ha e contamos as peças do outro jogador na direçao sudeste
            while(board[linha][col] == player2){
                i7++;
                linha++;
                col++;
                if (board[linha][col] == player)
                    *(p+6)=i7;
            }
        }
        if (l == -1 && c == 1){  //vemos se ha e contamos as peças do outro jogador na direçao nordeste
            while(board[linha][col] == player2){
                i8++;
                linha--;
                col++;
                if (board[linha][col] == player )
                    *(p+7)= i8;
            }
        }
    }

/*
###############################################################################################
Funçao Direction
Usamos esta funçao como a maneira de ter umas das 8 direçoes para usar depois na funcao de 
check, assim evitando algo mais messy. 
Aproveitamos e contamos as peças viradas
###############################################################################################
*/
int direction(char board[9][9],int linha, int col,char player,int *p){
    int pecas=0; // quantidade de peças diferentes do jogador actual que esta a jogar
    char player2=p2(player);
    int i=0;

    for (int l=-1;l == -1 || l == 0|| l == 1;l++){
        for (int c = -1; c == -1 || c == 0 || c == 1;c++,i++){
            if ( board[linha][col] == '.'){
                //printf("%d %d\n",l, c);
                if ( board[linha+l][col+c] == player2 && linha+l < 9 && col+c < 9 && linha+l > 0 && col+c > 0){
                    check(board,l,c,linha+l,col+c,player,p);    
                }
            }
        }
    }
}

/*
###############################################################################################
###############################################################################################
*/
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
    else if (letra == 'h' || letra == 'H')
        return (int) 8;
    else
        return (int) 0;
}
int pontos(char player,char board[9][9]){
    int counter=0;
    for (int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
            if (board[i][j]== player) counter++;

    return counter;       
}
