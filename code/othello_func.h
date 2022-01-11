char print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

int flanked(int ppvirar[9],char board[9][9],int linha,int coluna,char player);

int check(char board[9][9],int l,int c,int linha,int col,char player,int mode);

void play(char board[9][9],char player, int linha, int col);

char player(int turn);

void input(int *linha,int *col);

int menu();

int random();

void printtest(int array[8]);

int pontos(char player,char board[9][9]);

int next(char board[9][9],char player,int mode);

char copy(char board[9][9]);