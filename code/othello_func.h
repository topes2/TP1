char print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

int direction(char board[9][9],int linha, int col,char player,int p[8]);

int decode(char letra);

int check(char board[9][9],int l,int c,int linha,int col,char player);

void play(char board[9][9],char player, int linha, char coluna);

void rewrite(char board[9][9]);

char player(int turn,int ordem);

void input(int *linha,int *col);

int menu();

int random();