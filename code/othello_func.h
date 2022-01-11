char print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

//int direction(char board[9][9],int linha, int col,char player);

int flanked(char board[9][9],int l,int c,int linha,int coluna,char player);

int check(char board[9][9],int l,int c,int linha,int col,char player,int mode);

int checknext(char board[9][9],int l,int c,int linha,int col,char player);

void play(char board[9][9],char player, int linha, int col);

char player(int turn);

void input(int *linha,int *col);

int menu();

int random();

void printtest(int array[8]);

int pontos(char player,char board[9][9]);

int next(char board[9][9],char player,int mode);

char copy(char board[9][9]);