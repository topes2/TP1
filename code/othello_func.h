typedef struct 
{
    int pontos;
    char seg_bboard[9][9];
}seg_bot;
typedef struct 
{
    int pontos;
    char bboard[9][9];
    int linha_bot,coluna_bot;
    seg_bot segbot[32];
} strk_bot;

void print_board(char tboard[9][9]);

void init_board(char tboard[9][9]);

void flanked(char board[9][9],int l,int c,int linha,int coluna,char player);

int check(char board[9][9],int l,int c,int linha,int col,char player);

int checknext(char board[9][9],int l,int c,int linha,int col,char player);

void play(char board[9][9],char player, int linha, int col);

char player(int turn);

void input(int *linha,int *col);

int pontos(char player,char board[9][9]);

int next(char board[9][9],char player);

void copy_board(char bboard[9][9],char board[9][9]);

int pont_bot(char board[9][9],char player);

void bot(char board[9][9],char player);

int maior(strk_bot bot[64],int sz);

int maior_bot2(seg_bot[20],int sz);

int finput(FILE *f,int *linha, int *col);

int char_decod(char coluna);

int bot_primeira(char board[9][9], strk_bot bot[],char player);

void convert_board(char bboard[9][9],char board[9][9]);

char int_decod(int coluna);

void end_game(char board[9][9], char player);

void player_turn(char board[9][9],int turn);

void fplayer_turn(FILE *f,char board[9][9],int turn);

void bot_turn(char board[9][9],int turn);