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

int fintput(FILE *f,int *linha, int *col){
    char coluna;
    
    
    if(fscanf(f," %d %c",linha,&coluna)!=EOF){
        
        if (coluna >= 'a' && coluna <= 'h')
            *col = coluna - 'a' + 1;
        else if(coluna >= 'A' && coluna <= 'H')
            *col = coluna - 'A' + 1;
        else
            *col = 0;
    }
    else return 0;
}
void play(char board[9][9],char player, int linha, int col,int mode){
    
    int ppvirar[9]={0,0,0,0,0,0,0,0,0};
    char player2=p2(player);
    int pecasviradas=0,lp=0;
    for (int l =-1,t = 0;l<=1;l++,t = t+3){
        for (int c = -1, g = 0; c<=1;c++,g++){
            if ( board[linha][col] == 'q'){
                if ( board[linha+l][col+c] == player2 ){
                    if((ppvirar[t + g] = check(board,l,c,linha,col,player,0))== 1){
                        flanked(board,l,c,linha,col,player);
                    }
                }
            }
        }
    }
    for(int i = 0;i<=8;i++)
            pecasviradas = ppvirar[i] + pecasviradas;

    if(mode == 1)
        printf("     %d peças viradas\n",pecasviradas);
    else if (mode==2)
        printf("O computador virou %d peças\n",pecasviradas);
}

int flanked(char board[9][9],int l,int c,int linha,int coluna,char player){
   
    char player2 = p2(player);
    int delta_c=1,delta_l=1,c1,l1;
    c1=c;
    l1=l;
    board[linha][coluna]= player;
    while(board[linha + l][coluna + c] == player2){
        board[linha + l][coluna + c]=player;
        delta_c++;
        delta_l++;
        l = l1 * delta_l;
        c = c1 * delta_c;        
        
    }
    
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

int next(char board[9][9],char player){
    int y=0;
    char player2 = p2(player);
    
    for (int i1 = 1; i1 < 9; i1++)
        for ( int j1 = 1; j1 < 9; j1++){
            if (board[i1][j1]== 'q')
                board[i1][j1]='.'; 
        }
  
    for (int i3 = 1; i3 < 9; i3++)
        for ( int j3 = 1; j3 < 9; j3++){
            if(board[i3][j3]== '.'){
                for (int l=-1;l == -1 || l == 0|| l == 1;l++)
                    for (int c = -1; c == -1 || c == 0 || c == 1;c++){
                        if(board[i3+l][j3+c] == player2){
                        if(check(board,l,c,i3,j3,player,0)==1){
                            board[i3][j3] = 'q';
                            y++;
                        }
                        }
                    }                       
            }

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
        if (next(board,player(turn)) != 0){
        do
        {
            temp=0;
            printf("             Pontuação\n");
            printf(" Jogador1(x): %d    Jogador2(o): %d \n",pontos('x',board),pontos('o',board));
            next(board,player(turn));
            print_board(board);
            printf("    Vez do jogador (%c)\n",player(turn));
            input(&linha,&col);
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
    }
}

//######################################################################################
//BOT
//#######################################################################################
void copy_board(char bboard[9][9],char board[9][9]){

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            bboard[i][j]=board[i][j];
        }
        
}
int maior(strk_bot bot[32],int sz){

    int maior=bot[0].pontos;
    int indice_maior=0;
    for (int i = 0; i < sz; i++)
        if (maior < bot[i].pontos)
        {
            maior=bot[i].pontos;
            indice_maior=i;
        }
        
    return indice_maior;

}
int maior_bot2(seg_bot segundo_bot[20],int sz){
    
    int max=segundo_bot[0].pontos,indice=0;
    
    for (int i = 0; i < sz; i++)
        if (max < segundo_bot[i].pontos)
        {
            max = segundo_bot[i].pontos;
            indice = i;
        }
    return indice;     
}
int pont_bot(char   board[9][9],char player){
    char player2= p2(player);
    int pontos=0;
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++){
            if(board[i][j]==player){
                if ((i==1 && j==1)||(i==1 && j==8)||(i==8 && j==8)||(i==8 && j==1)) //verifica se há peças do bot nas casas dos cantos e atribui +10 pontos á jogada
                pontos+=10;
                else if(i==1 || i == 8 || j==1 || j==8 )//verifica se há peças do bot nas bordas do tabuleito e atribui +5 aos pontos
                pontos+=5;
                else // atribui +1 aos pontos por cada peça que encontrar que não esteja em cantos ou bordas
                pontos ++;
            }
            else if (board[i][j]==player2)
            {
                pontos--;
            }
        }

    return pontos;
}
    
void bot_segunda_jogada(strk_bot bot[32],int sz,char player)// função que simula todas as jogadas para a ronda seguinte a partir de cada jogada do bot 
{
    
    char player2 = p2(player);

    for (int l = 0,k = 0; k < sz; k++){// cada valor de k é uma possivel jogada do bot, vamos ver como o oponente pode responder
        next(bot[k].bboard,player2); // precessamos o board para mostrar as jogadas possiveis para o oponente do bot
        for (int i = 1; i < 9; i++){// loop para correr o board 
            for (int j = 1; j < 9; j++){
                if ( bot[k].bboard[i][j] == 'q')//encontra uma jogada possivel do oponente
                {
                    copy_board(bot[k].segbot[l].seg_bboard,bot[k].bboard); // copia o board para um board2 onde vai simular a jogada do oponenete
                    play(bot[k].segbot[l].seg_bboard,player2,i,j,0);// simula a jogada
                    bot[k].segbot[l].pontos = pont_bot(bot[k].segbot[l].seg_bboard,player);// avalia o tabuleiro e atruibui uma pontuação de acorod com o indicado na função pont_bot()
                    l++;
                }  
            }
        }
        bot[k].pontos = bot[k].segbot[maior_bot2(bot[k].segbot,l)].pontos;//copia o maior valor de pontos do array bot[k].segbot.pontos para bot[k].pontos assim guadamos o melhor outcome da jogada de indice k
    }
}
void bot(char board[9][9],char player){

    strk_bot bot[32]; /* variavel que vai guardar as informações para o bot poder escolher a melhor jogada */
    int k=0,melhor_jogada;
    
    
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++) // loop para correr o board 
        {
            if ( board[i][j]== 'q') //quando encontrar uma jogada possivel o bot simula a jogada, toda no mesmo indice do array bot[] para podermos analizar tudo a partir do indice
            {
                copy_board(bot[k].bboard,board);// 1º copia o board para um array de tamanho igual na posição k do array de strucks
                play(bot[k].bboard,player,i,j,0);// 2º simula a jogada nesse mesmo array para n alterar o tabuleiro de jogo
                bot[k].coluna_bot=j;//  guarda a coluna da jogada na struck
                bot[k].linha_bot=i;// guarda a linha da jogada na struck
                k++;
            }  
        }

    bot_segunda_jogada(bot,k,player);

    melhor_jogada = maior(bot,k);

    play(board,player,bot[melhor_jogada].linha_bot,bot[melhor_jogada].coluna_bot,2);//joga a jogada que obteve a melhor pontuação de tabuleiro
    

}