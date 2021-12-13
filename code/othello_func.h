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

/*char play( board, line, col, color ){
    int i=0;   
}
*/