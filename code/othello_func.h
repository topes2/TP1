typedef struct 
{
    int pontos;
    char seg_bboard[9][9];
    int seg_linha_bot,seg_coluna_bot;
}seg_bot;
typedef struct 
{
    int pontos;
    char bboard[9][9];
    int linha_bot,coluna_bot;
    seg_bot segbot[20];
} strk_bot;



char print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

int flanked(char board[9][9],int l,int c,int linha,int coluna,char player);

int check(char board[9][9],int l,int c,int linha,int col,char player,int mode);

int checknext(char board[9][9],int l,int c,int linha,int col,char player);

void play(char board[9][9],char player, int linha, int col,int mode);

char player(int turn);

void input(int *linha,int *col);

int menu();

int random();

void printtest(int array[8]);

int pontos(char player,char board[9][9]);

int next(char board[9][9],char player);

char copy(char board[9][9]);

int gameloop(char board[9][9],int turn); //faço ja isto aqui so para preparar o bot

void copy_board(char bboard[9][9],char board[9][9]);

int pont_bot(char   board[9][9],char player);

void bot(char board[9][9],char player);

int maior(strk_bot bot[64],int sz);

int maior_bot2(seg_bot[20],int sz);