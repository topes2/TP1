#include <stdio.h>
#include <time.h>
#include "othello_func.h"

int linha,col;

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

int random(){
    srand(time(NULL));
    int r = rand();
    return r;
} //temos de tirar

char player(int turn){
    
    if (turn % 2 == 0) return 'x';
    else return 'o';    
}

char print_board(char tboard[9][9]){
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
            printf("%c  ", tboard[l][c]);
        }
        printf("\n");
    }
}

void init_board(char tboard[9][9]){
    for (int i = 1;i< 9;i++){
        for (int l=1;l< 9;l++){
            tboard[i][l] = '.';
        }
        tboard[i][0] = '0'+ i;
        tboard[0][i]= 'A' + i -1;
    }

    tboard[4][5] = tboard[5][4] = 'x';
    tboard[4][4] = tboard[5][5] = 'o';
    tboard[0][0] = ' ';
}

char p2(char player){
    if (player=='x') return 'o';
    else return 'x';
 }

void input(int *linha,int *col){
    char coluna;
    int linhatemp;
    printf("Insira a jogada (linha coluna)\n");
    scanf("%d",linha);
    scanf("%c",&coluna);
    while (!(*linha >= 1 && *linha <= 8 && coluna>='a' && coluna <= 'h' || coluna >= 'A' && coluna <= 'H')){
    printf("Insira um par de coordenadas validas ( linha colunas)\n");
    scanf("%d",linha);
    scanf("%c",&coluna);
    }

    if (coluna >= 'a' && coluna <= 'h')
        *col = coluna - 'a' + 1;
    else if(coluna >= 'A' && coluna <= 'H')
        *col = coluna - 'A' + 1;
    else
        *col = 0;
}

void play(char board[9][9],char player, int linha, int col){
    
    int ppvirar[9]={0,0,0,0,0,0,0,0,0};
    char player2=p2(player);
<<<<<<< HEAD
    int pecasviradas=0,lp=0;
    for (int l =-1,t = 0;l<=1;l++,t = t+3){
        for (int c = -1, g = 0; c<=1;c++,g++){
=======
    int pecasviradas=0;
    for (int l =-1,t = 0; l<= 1 ;l++,t = t+3){
        for (int c = -1, g = 0; c <= 1;c++,g++){
>>>>>>> 537f689d0e0f56ae351996e5b74bdc5516fa7143
            if ( board[linha][col] == '.'){
                if ( board[linha+l][col+c] == player2 && linha+l < 9 && col+c < 9 && linha+l > 0 && col+c > 0){
                    if(ppvirar[t + g] = (check(board,l,c,linha,col,player,0))!= 0){
                        flanked(board,l,c,linha,col,player);
                        lp++;
                    }
                }
            }
        }
    }
    if(lp != 0)
    board[linha][col]=player;
    for(int i = 0;i<=8;i++){
        pecasviradas = ppvirar[i] + pecasviradas;
    }
    printf("     %d peças viradas\n",pecasviradas);
   
}

int flanked(char board[9][9],int l,int c,int linha,int coluna,char player){
   
    char player2 = p2(player);
    int delta_c=1,delta_l=1,c1,l1;
    c1=c;
    l1=l;
    while(board[linha + l][coluna + c] == player2){
        board[linha + l][coluna + c]=player;
        delta_c++;
        delta_l++;
        l = l1 * delta_l;
        c = c1 * delta_c;        
        if(delta_c*c1 > 9 || delta_l*l1 > 9){
            break;
        }
    }
    print_board(board);
}

int check(char board[9][9],int l,int c,int linha,int col,char player,int mode){
    char player2 = p2(player);
    int delta_c=1,delta_l=1,c1,l1,points=0;
    c1=c;
    l1=l;
    
    
        while(board[linha + l][col + c] == player2){
        delta_c++;
        delta_l++;
        points++;
        l = l1 * delta_l;
        c = c1 * delta_c;        
        if(delta_c*c1 > 9 || delta_l*l1 > 9){
            break;
        }        
    }
        if(board[linha+l][col+c] == player){
            if (mode == 1)
                return points;
            else if (mode == 0)
                return 1;
        }else
            return 0;     
}

int next(char board[9][9],char player,int mode){
    int x = 0,y=0;
    char player2 = p2(player);
    char board2[9][9];
    for (int i1 = 1; i1 < 9; i1++)
        for ( int j1 = 1; j1 < 9; j1++){
            if (board[i1][j1]== '.')
                x++; 
        }
    if(x != 0){
        for (int i2 = 0; i2 < 9; i2++)
            for ( int j2 = 0; j2 < 9; j2++)
                board2[i2][j2] = board[i2][j2];
    }
    for (int i3 = 1; i3 < 9; i3++)
        for ( int j3 = 1; j3 < 9; j3++){
            if(board[i3][j3]== '.'){
                for (int l=-1;l == -1 || l == 0|| l == 1;l++)
                    for (int c = -1; c == -1 || c == 0 || c == 1;c++){
                        if(board[i3+l][j3+c] == player2){
                        if(check(board,l,c,i3,j3,player,0)==1){
                            board2[i3][j3] = 'q';
                            y++;
                        }
                        }
                    }                       
            }

        }
    if (mode == 1){
    print_board(board2);
    }
    return y;
}

int pontos(char player,char board[9][9]){
    int counter=0;
    for (int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
            if (board[i][j]== player) counter++;

    return counter;       
}

int gameloop(char board[9][9],int turn){
    int temp=0,end=0;
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