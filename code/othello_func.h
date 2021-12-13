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