
void slowprint(const char* string);

void regprint(const char* string);
void regprint(const char* string, char a, char b, char c );
void regprint(const char* string, char a, char b, char c, char d, char e, char f, char g, char h );


int endState( char state[3][3], bool gameover );
void drawBoard1(char state[3][3]);
void tictactoe();

void drawBoard2(char cstate[8][8], char dead1[16], char dead2[16]);
bool validmove( char cstate[8][8], int a, int b, int c, int d);
int checkScan( char cstate[8][8] );
int checkmateScan( char cstate[8][8] );
bool endState( char cstate[8][8] );
void chess();

void drawBoard3();
void globalThermonuclearWar();





