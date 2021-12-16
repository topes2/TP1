char print_board(char tboard[9][9]);

char* init_board(char tboard[9][9]);

int direction(char board[9][9],int linha, int col,char player);

int decode(char letra);

int check(char board[9][9],int l,int c,int linha,int col,char player);

char* play(char board[9][9],int linha, int col,int color);

char* rewrite(char board[9][9]);

char player(int turn);

int input(int *linha,int *col);