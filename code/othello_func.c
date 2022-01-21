#include <stdio.h>
#include <time.h>
#include "othello_func.h"

int linha,col;



//#######################################################
 // player esta função calcula o player atual em função do turn
 // Argumentos:
 // turn - turno da jogada , inteiro
 // valor de retorno:
 // simbolo do player atual, char
//#######################################################
char player(int turn){                  
                                        
    if (turn % 2 == 0) return 'x';     
    else return 'o';                   
}

//#######################################################
 // print_board esta função mostra o tabuleiro de jogo no encrã
 // Argumentos:
 // tboard - tabuleiro de jogo , array de char
 // valor de retorno:
 // Void
//#######################################################

void print_board(char tboard[9][9]){ 
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 9; c++){
            printf("%c  ", tboard[l][c]);
        }
        printf("\n");
    }
    printf("\n");
}

//#######################################################
 // init_board esta função inicializa o tabuleiro de jogo com as peças iniciais e as bordas do tabuleiro 
 // Argumentos:
 // tboard - tabuleiro de jogo , array de char
 // valor de retorno:
 // Void
//#######################################################

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

//#######################################################
 // p2 esta função calcula o char do player adversário
 // Argumentos:
 // player - jogador atual , char
 // valor de retorno:
 // caracter do adversário, char  
//#######################################################

char p2(char player){  
    if (player=='x') return 'o';
    else return 'x';
 }

//#######################################################
 // char_decod esta função converte um caracter de A a H, maiuscula e minuscula
 // maiuscula e minuscula, num número de 1 a 8
 // Argumentos:
 // coluna - letra da coluna , char
 // valor de retorno:
 // indice da coluna em inteiro, inteiro
//#######################################################

int char_decod(char coluna){               
    
    if (coluna >= 'a' && coluna <= 'h') 
        return coluna - 'a' + 1;
    else if(coluna >= 'A' && coluna <= 'H')
        return coluna - 'A' + 1;
    else
        return 0;                               

}

//#######################################################
 // int_decod esta função converte um número de 1 a 8 em caracter
 // de A a H
 // função feita para ser chamada pelo bot, que só irá chamar com valores entre 1 e 8
 // Argumentos:
 // coluna - indice da coluna , int
 // valor de retorno:
 // Letra da coluna, char
//#######################################################

char int_decod(int coluna){

    coluna+=16;
    return coluna +'0';  

}

//#######################################################
 // imput esta função recebe a jogada, linha e coluna, do jogador 
 // Argumentos:
 // *linha - linha da jogada, ponteiro para int
 // *col - coluna da jogada, ponteito para int
 // Variavéis:
 // coluna - caracter que o jogador intruduz para a coluna, char 
 // valor de retorno:
 // void; 
 // utiliza os ponteiros para devolver o valor da linha e coluna
//#######################################################

void input(int *linha,int *col){// lê o imput do jogador 
    char coluna;

    printf("Chose your move.For instance: 5F\n");
    scanf("%d",linha);
    scanf("%c",&coluna);
    while (!(*linha >= 1 && *linha <= 8 && coluna>='a' && coluna <= 'h' || coluna >= 'A' && coluna <= 'H')){
    printf("Invalid move!\nChose your move.For instance: 5F\n");
    scanf("%d",linha);
    scanf("%c",&coluna);
    }

    *col = char_decod(coluna);
}

//#######################################################
 // finput esta função recebe a jogada, linha e coluna, a partir de ficheiro .txt
 // Argumentos:
 // *col - coluna da jogada, ponteito para int
 // *linha - linha da jogada, ponteiro para int
 // *f - ficheiro das jogadas, FILE
 // Variavéis:
 // coluna - caracter que o file.txt intruduz para a coluna, char 
 // valor de retorno:
 // retorna 0 se chegar ao fim da file,int 
 // utiliza os ponteiros para devolver o valor da linha e coluna
//#######################################################

int finput(FILE *f,int *linha, int *col){     

    char coluna;

    if(fscanf(f," %d %c",linha,&coluna)!=EOF){  
        printf("\n");
        *col = char_decod(coluna);
    }                                            
    else return 0;
}

//#######################################################
 // play esta função chama as funções que vão executar a jogada 
 // Argumentos:
 // col - coluna da jogada, int
 // linha - linha da jogada, int
 // player - simbolo do jogador atual , char
 // board - tabuleiro de jogo, array de char
 // valor de retorno:
 // void
//#######################################################

void play(char board[9][9],char player, int linha, int col){                                                           
    char player2=p2(player);                                                                                                                            

    for (int l =-1,t = 0;l<=1;l++,t = t+3){                                         
        for (int c = -1, g = 0; c<=1;c++,g++){                                      //loop para testar todas as direcões alterando o valor de c e l entre -1 e 1                
            if ( board[linha][col] == 'q' &&  board[linha+l][col+c] == player2){       
                if(check(board,l,c,linha,col,player)!= 0)                           //priemiro teste da direção, se encontrar uma peça do adversário na direção (l,c) passa á segunda parte 
                    flanked(board,l,c,linha,col,player);                            //caso a jogada seja valida, ececuta-a atravez da função flanked
            }
        }
    }
}

//#######################################################
 // fplayer_turn chama as funções nesseçárias para jogar a partir da FILE 
 // Argumentos:
 // turn - turno da jogada, int
 // *f - fijeiro com as jogadas, FILE
 // board - tabuleiro de jogo, array de char
 // valor de retorno:
 // void
//#######################################################

void fplayer_turn(FILE *f,char board[9][9],int turn){

    next(board,player(turn));                           
    print_board(board);                                 
    finput(f,&linha,&col);                                  
    play(board,player(turn),linha,col); 

    while (board[linha][col]!= player(turn)){          //enquanto a jogada for invalida repete o processo
        printf("Invalid move!\n");
        finput(f,&linha,&col);
        play(board,player(turn),linha,col);
    }

}

//#######################################################
 // player_turn chama as funções nesseçárias para o jogador executar a jogada
 // Argumentos:
 // turn - turno da jogada, int
 // board - tabuleiro de jogo, array de char
 // valor de retorno:
 // void
//#######################################################

void player_turn(char board[9][9],int turn){

    next(board,player(turn));
    print_board(board);
    input(&linha,&col);
    play(board,player(turn),linha,col); 

    while (board[linha][col]!= player(turn)){               //enquanto a jogada for invalida repete o processo
        printf("Invalid move!\n");
        input(&linha,&col);
        play(board,player(turn),linha,col);
    }

}

//#######################################################
 // bot_turn chama as funções nesseçárias para o bot executar a jogada
 //
 // Argumentos:
 // turn - turno da jogada, int
 // board - tabuleiro de jogo, array de char
 //
 // valor de retorno:
 // void
//#######################################################

void bot_turn(char board[9][9],int turn){

    next(board,player(turn));
    print_board(board);
    bot(board,player(turn));
}

//#######################################################
 // flanked função que vira as peças a partir da posição 
 // escolhida até uma peça já existente no tabuleiro
 // função só é evocada dps da posição e direção ser testada possivel
 //
 // Argumentos:
 // l - cordenada de direção entre linhas, int ente -1 e 1
 // c - cordenada de direção entre colunas , int ente -1 e 1
 // linha - linha da jogada - int
 // coluna - coluna da jogada - int
 // board - tabuleiro de jogo, array de char
 // player - simbolo do jogador atual - char
 //
 // valor de retorno:
 // void
 // altera diretamente o tabuleiro
//#######################################################

void flanked(char board[9][9],int l,int c,int linha,int coluna,char player){         //função que vira as peças a partir da posição escolhida pelo jogador até uma peça já existente no tabuleiro
    //                                                                               //função só é evocada dps da posição e direção ser testada possivel  
    char player2 = p2(player);
    int delta_c=1,delta_l=1;                                                  
    
    board[linha][coluna]= player;

    while(board[linha + l][coluna + c] == player2){
        board[linha + l][coluna + c]=player;
        delta_c++;
        delta_l++;
        l *=  delta_l;
        c *=  delta_c;        
        
    }
    
}

//#######################################################
 // check função que testa uma direção e retorna 0 se não for possivel
 //
 // Argumentos:
 // l - cordenada de direção entre linhas, int ente -1 e 1
 // c - cordenada de direção entre colunas , int ente -1 e 1
 // linha - linha da jogada - int
 // col - coluna da jogada - int
 // board - tabuleiro de jogo, array de char
 // player - simbolo do jogador atual - char
 //
 // valor de retorno:
 // número de peças que vira na direção (c,l) a partir de board[linha][col], int
//#######################################################

int check(char board[9][9],int l,int c,int linha,int col,char player){
    char player2 = p2(player);
    int delta_c=1,delta_l=1,points=0;
    
        while(board[linha + l][col + c] == player2){
        delta_c++;
        delta_l++;
        points++;
        l *= delta_l;
        c *= delta_c;        
        if(c > 9 || l > 9){
            break;
        }        
    }
    if(board[linha+l][col+c] == player) 
        return points;
    else 
        return 0;     
}

//#######################################################
 // remove_q função que "limpa" os q's do tabuleiro para 
 // que não cause conflito na proxima jogada
 //
 // Argumentos:
 // board - tabuleiro de jogo, array de char
 //
 // valor de retorno:
 // void
 // altera diretamente o tabuleiro de jogo
//#######################################################

void remove_q(char board[9][9]){

  for (int i1 = 1; i1 < 9; i1++)
        for ( int j1 = 1; j1 < 9; j1++){
            if (board[i1][j1]== 'q')
                board[i1][j1]='.'; 
        }  

}

//#######################################################
 // next função que calcula o número de jogadas possiveis 
 // coloca um 'q' em casa de jogada possivel
 //
 // Argumentos:
 // board - tabuleiro de jogo, array de char
 // player - simbolo do jogador atual, char     
 //
 // valor de retorno:
 // númeoro de jogadas possiveis, int
//#######################################################

int next(char board[9][9],char player){
    int y=0;
    char player2 = p2(player);
    
    remove_q(board);
  
    for (int i3 = 1; i3 < 9; i3++)
        for ( int j3 = 1; j3 < 9; j3++){
            if(board[i3][j3]== '.'){
                for (int l=-1;l == -1 || l == 0|| l == 1;l++)
                    for (int c = -1; c == -1 || c == 0 || c == 1;c++){
                        if(board[i3+l][j3+c] == player2){
                        if(check(board,l,c,i3,j3,player)!=0){
                            board[i3][j3] = 'q';
                            y++;
                        }
                        }
                    }                       
            }

        }
    
    return y;
}

//#######################################################
 // pontos função conta o número de peças de um player no tabuleiro
 //
 // Argumentos:
 // board - tabuleiro de jogo, array de char
 // player - simbolo do jogador atual, char     
 //
 // valor de retorno:
 // númeoro de peças do player no tabuleiro, int
//#######################################################

int pontos(char player,char board[9][9]){
    int counter=0;
    for (int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
            if (board[i][j]== player) counter++;

    return counter;       
}

//#######################################################
 // end_game função que apresenta as mensagens finais ao jogador 
 //
 // Argumentos:
 // board - tabuleiro de jogo, array de char
 // player - simbolo do jogador humano/file, char     
 //
 //valor de retorno:
 //void
//#######################################################

void end_game(char board[9][9], char player){

    int pontos_b,pontos_p;
    char pc=p2(player);

    pontos_b=pontos('o',board);
    pontos_p=pontos('x',board); 

    printf("Game Over!\n Black: %d discs, White: %d discs\n",pontos_p,pontos_b);

    if ( pontos(player,board) < pontos(pc,board))
        printf("You lose!\n");
    else if( pontos(player,board) > pontos(pc,board))
        printf("You win!\n");
    else
        printf("It's a draw\n");

}

//######################################################################################
//BOT
//#######################################################################################


//#######################################################
 // copy_board função que copia um array[8][8] para outro array[8][8]
 //
 // Argumentos:
 // bboard - tabuleiro em branco, array de char
 // board - tabuleiro a ser copiado,array de char     
 //
 // valor de retorno:
 // void
//#######################################################

void copy_board(char bboard[9][9],char board[9][9]){

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            bboard[i][j]=board[i][j];
        }
        
}

//################################################################################################################################

//################################################################################################################################

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

//################################################################################################################################

//################################################################################################################################

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

//################################################################################################################################

//################################################################################################################################

int pont_bot(char   board[9][9],char player){
    char player2= p2(player);
    int pontos=0;
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++){
            if(board[i][j]==player){
                if ((i==1 && j==1)||(i==1 && j==8)||(i==8 && j==8)||(i==8 && j==1)) //verifica se há peças do bot nas casas dos cantos e atribui +10 pontos á jogada
                pontos+=10;
                else if(i==1 || i == 8 || j==1 || j==8 )                            //verifica se há peças do bot nas bordas do tabuleito e atribui +5 aos pontos
                pontos+=5;
                else                                                                // atribui +1 aos pontos por cada peça que encontrar que não esteja em cantos ou bordas
                pontos ++;
            }
            else if (board[i][j]==player2)
            {
                pontos--;
            }
        }

    return pontos;
}

//################################################################################################################################

//################################################################################################################################

    
void bot_segunda_jogada(strk_bot bot[32],int sz,char player)// função que simula todas as jogadas para a ronda seguinte a partir de cada jogada do bot 
{
    
    char player2 = p2(player);

    for (int l = 0,k = 0; k < sz; k++){                     // cada valor de k é uma possivel jogada do bot, vamos ver como o oponente pode responder
        next(bot[k].bboard,player2);                        // precessamos o board para mostrar as jogadas possiveis para o oponente do bot
        for (int i = 1; i < 9; i++){                        // loop para correr o board 
            for (int j = 1; j < 9; j++){
                if ( bot[k].bboard[i][j] == 'q')            //encontra uma jogada possivel do oponente
                {
                    copy_board(bot[k].segbot[l].seg_bboard,bot[k].bboard);         // copia o board para um board2 onde vai simular a jogada do oponenete
                    play(bot[k].segbot[l].seg_bboard,player2,i,j);                 // simula a jogada
                    bot[k].segbot[l].pontos = pont_bot(bot[k].segbot[l].seg_bboard,player);         // avalia o tabuleiro e atruibui uma pontuação de acorod com o indicado na função pont_bot()
                    l++;
                }  
            }
        }
        bot[k].pontos = bot[k].segbot[maior_bot2(bot[k].segbot,l)].pontos;         //copia o maior valor de pontos do array bot[k].segbot.pontos para bot[k].pontos assim guadamos o melhor outcome da jogada de indice k
    }
}

//################################################################################################################################

//################################################################################################################################

int bot_primeira(char board[9][9], strk_bot bot[], int szmax,char player){

int k=0;

for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)               // loop para correr o board 
        {   
            if ( board[i][j]== 'q')               // quando encontrar uma jogada possivel o bot simula a jogada, toda no mesmo indice do array bot[] para podermos analizar tudo a partir do indice
            { 
                copy_board(bot[k].bboard,board);  // 1º copia o board para um array de tamanho igual na posição k do array de strucks
                play(bot[k].bboard,player,i,j);   // 2º simula a jogada nesse mesmo array para n alterar o tabuleiro de jogo
                bot[k].coluna_bot=j;              // guarda a coluna da jogada na struck
                bot[k].linha_bot=i;               // guarda a linha da jogada na struck
                k++;
                if(k>= szmax){
                    printf("O valor do k excedeu o valor maximo");
                    return k;
                }
            }  
        }

    return k;

}

//################################################################################################################################

//################################################################################################################################

void bot(char board[9][9],char player){

    strk_bot bot[32];   /* variavel que vai guardar as informações para o bot poder escolher a melhor jogada */
    int k=0,melhor_jogada;
    char coluna_bot;
    k = bot_primeira(board,bot,32,player);
    bot_segunda_jogada(bot,k,player);

    melhor_jogada = maior(bot,k);

    coluna_bot = int_decod(bot[melhor_jogada].coluna_bot);

    printf("My move: %d%c\n\n",bot[melhor_jogada].linha_bot,coluna_bot);
    
    play(board,player,bot[melhor_jogada].linha_bot,bot[melhor_jogada].coluna_bot);//joga a jogada que obteve a melhor pontuação de tabuleiro
    

}
