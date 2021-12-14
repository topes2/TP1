char print_board(char tboard[9][9]);

char* init_board(char tboard[9][9]);

char* direction(char board[9][9],int linha, int col,char player);

int decode(char letra);

char check(char board[9][9],int l,int c,char player);

char* play(char board[9][9],int linha, int col,int color);