// John Rocha and Paul Dowling
// Prototypes
int validMove(char, char);
void moveLeft(int, int, int[100][100]);
void moveUp(int, int, int[100][100]);
void moveDown(int, int, int[100][100]);
void moveRight(int, int, int[100][100]);
void display_menu();
void startBoard(int, int, int, int, int, int, int);
int difficulty_menu(char, int);
void clear_board( int[100][100]);
void end_menu_p2(int, int, int);
void end_menu_p1(int, int, int);
char *num2str(int);
void scoreboard_p1(int, int);
void scoreboard_p2(int, int);
int is_tie(int, int, int, int);
char getFarthestMove(int,int,int,int,char,int[100][100]);
char findSpace(int,int,char,int[100][100]);
