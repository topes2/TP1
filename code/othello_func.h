char print_board(char tboard[9][10]){
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 10; c++){
            printf("%c  ", tboard[l] [c]);
        }
        printf("\n");
        }
}
 
char* init_board(char tboard[9][10]){ // inserir as primerias peças para o jogo padrao
    for (int l= 0; l < 9; l++){
        for (int c = 0; c < 10; c++){
            if(l == 4 && c == 4 || l == 5 && c == 5)
                tboard[l][c] = 'o';
            else if(l== 4 && c == 5 || l == 5 && c == 4)
                tboard[l][c]= 'x';      
            }
        }
    return(tboard);
}

char check(char board[9][10]){
}
int play(char board[9][9],int lin,int col,char player)
{
    char p2;
    
    if( player == 'x')
        p2 = 'o';

    //escolher direção//
    if (board[lin][col] == '.')
    {
        if (board[lin][col+1] == p2)    //jogada possivel direção Este
            for (int j = col+1; j<9 ; j++){
                if(board[lin][j] == player)
                    break;
            board[lin][j] = player;
            }
            
        if (board[lin][col-1] == p2)   // jogada possivel direção Oeste
            dir[1] == 1;
        if (board[lin-1][col] == p2)   // jogada possivel direção Norte
            dir[2] == 1;
        if (board[lin+1][col] == p2)   // jogada possivel direção Sul
            dir[3] == 1;
        if (board[lin-1][col+1] == p2) // jogada possivel direção NordEste
            dir[4] == 1;
        if (board[lin-1][col-1] == p2) // jogada possivel direção NorOeste
            dir[5] == 1;
        if (board[lin+1][col+1] == p2) // jogada possivel direção SudEste
            dir[6] == 1;
        if (board[lin+1][col-1] == p2) // jogada possivel direção SuldOeste
            dir[7] == 1;
    }
    
    
    



}
int jogada(char board[9][9]){
    char col;
    int lin,coluna ,cor, i;


    printf("Insira a cordenada da jogada(separado por espaço) ");
    scanf(" %c %d",&col,&lin);

    coluna= decode(col);

    play(board, lin, col,cor);



}
int decode(char letra){
    if (letra == 'a' || letra == 'A')
        return 1;
    else if (letra == 'b' || letra == 'B')
        return 2;
    else if (letra == 'c' || letra == 'C') 
        return 3;
    else if (letra == 'd' || letra == 'D')
        return 4;
    else if (letra == 'e' || letra == 'E')
        return 5;
    else if (letra == 'f' || letra == 'F')
        return 6;
    else if (letra == 'g' || letra == 'G')
        return 7;
    else if (letra == 'f' || letra == 'F')
        return 8;
    else
        return 0;
}
