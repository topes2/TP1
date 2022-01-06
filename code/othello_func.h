char print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

int direction(char board[9][9],int linha, int col,char player,int *p);

int decode(char letra);

int check(char board[9][9],int l,int c,int linha,int col,char player,int *p);

int checknext(char board[9][9],int l,int c,int linha,int col,char player);

void play(char board[9][9],char player, int linha, int coluna);

char player(int turn);

void input(int *linha,int *col);

int menu();

int random();

int flanked(int ppvirar[8]);

void printtest(int array[8]);

int pontos(char player,char board[9][9]);

int next(char board[9][9],char player);

char copy(char board[9][9]);