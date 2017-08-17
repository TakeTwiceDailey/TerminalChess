#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>
#include "joshua.h"

extern int time;
extern int x, y;

	// drawBoard2: draws the chess board and pieces

void drawBoard2(char cstate[8][8], char dead1[16], char dead2[16]){

	time = 500;
	erase();
	y = 0;
	
	char pawn[3][5] =
	{
		{' ',' ',' ',' ',' '},
		{' ','_','o','_',' '},
		{' ','[','_',']',' '},
	};
	
	char knight[3][5] =
	{
		{' ','_','^','^',' '},
		{'(','*','*','_','|'},
		{' ','[','_',']',' '},
	};
	
	char bishop[3][5] =
	{
		{' ',' ','o',' ',' '},
		{' ','(','-',')',' '},
		{' ','[','_',']',' '},
	};
	
	char rook[3][5] =
	{
		{' ',' ',' ',' ',' '},
		{'|','_','|','_','|'},
		{' ','[','_',']',' '},
	};
	
	char queen[3][5] =
	{
		{' ','_','O','_',' '},
		{' ','|','|','|',' '},
		{' ','[','_',']',' '},
	};
	
	char king[3][5] =
	{
		{' ','_','+','_',' '},
		{' ','|','|','|',' '},
		{'_','[','_',']','_'},
	};
	
	char realpieces[8][8][3][5];
	for( int i = 0; i < 8; i++ )
	{
		for( int j = 0; j < 8; j++ )
		{
			if ( cstate[i][j] == 'p' || cstate[i][j] == 'P' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = pawn[k][l];
					}
				}
			}
			else if ( cstate[i][j] == 'r' || cstate[i][j] == 'R' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = rook[k][l];
					}
				}
			}
			else if ( cstate[i][j] == 'n' || cstate[i][j] == 'N' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = knight[k][l];
					}
				}
			}
			else if ( cstate[i][j] == 'b' || cstate[i][j] == 'B' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = bishop[k][l];
					}
				}
			}
			else if ( cstate[i][j] == 'k' || cstate[i][j] == 'K' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = king[k][l];
					}
				}
			}
			else if ( cstate[i][j] == 'q' || cstate[i][j] == 'Q' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = queen[k][l];
					}
				}
			}
			else if ( cstate[i][j] == ' ' )
			{
				for( int k = 0; k < 3; k++ )
				{
					for( int l = 0; l < 5; l++ )
					{
						realpieces[i][j][k][l] = ' ';
					}
				}
			}
		}
	}
	
	regprint("\n\t\t  1       2       3       4       5       6       7       8\n\n");
	regprint("\t\t _________________________________________________________________\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[0][0], cstate[0][1], cstate[0][2], cstate[0][3], cstate[0][4], cstate[0][5], cstate[0][6], cstate[0][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t1\t|       |       |       |       |       |       |       |       |  a  b  c  d  e  f  g  h\n", dead1[0], dead1[1], dead1[2], dead1[3], dead1[4], dead1[5], dead1[6], dead1[7]);
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|  a  b  c  d  e  f  g  h\n", dead1[8], dead1[9], dead1[10], dead1[11], dead1[12], dead1[13], dead1[14], dead1[15]);
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[1][0], cstate[1][1], cstate[1][2], cstate[1][3], cstate[1][4], cstate[1][5], cstate[1][6], cstate[1][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t2\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[2][0], cstate[2][1], cstate[2][2], cstate[2][3], cstate[2][4], cstate[2][5], cstate[2][6], cstate[2][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t3\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[3][0], cstate[3][1], cstate[3][2], cstate[3][3], cstate[3][4], cstate[3][5], cstate[3][6], cstate[3][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t4\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[4][0], cstate[4][1], cstate[4][2], cstate[4][3], cstate[4][4], cstate[4][5], cstate[4][6], cstate[4][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t5\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[5][0], cstate[5][1], cstate[5][2], cstate[5][3], cstate[5][4], cstate[5][5], cstate[5][6], cstate[5][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t6\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[6][0], cstate[6][1], cstate[6][2], cstate[6][3], cstate[6][4], cstate[6][5], cstate[6][6], cstate[6][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |\n");
	regprint("\t7\t|       |       |       |       |       |       |       |       |\n");
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	regprint("\t\t |a      |b      |c      |d      |e      |f      |g      |h      |\n", cstate[7][0], cstate[7][1], cstate[7][2], cstate[7][3], cstate[7][4], cstate[7][5], cstate[7][6], cstate[7][7]);
	regprint("\t\t |       |       |       |       |       |       |       |       |  a  b  c  d  e  f  g  h\n", dead2[0], dead2[1], dead2[2], dead2[3], dead2[4], dead2[5], dead2[6], dead2[7]);
	regprint("\t8\t|       |       |       |       |       |       |       |       |  a  b  c  d  e  f  g  h\n", dead2[8], dead2[9], dead2[10], dead2[11], dead2[12], dead2[13], dead2[14], dead2[15]);
	regprint("\t\t |_______|_______|_______|_______|_______|_______|_______|_______|\n");
	
	y = 4;
	x = 11;
	move(y,x);
	
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	
	for ( int i = 0; i < 8; i++ )
	{
		x++;
		move(y,x);
		for ( int j = 0; j < 8; j++ )
		{
			if ( isupper( cstate[i][j] == 0 ))
			{
				attron(COLOR_PAIR(1));
			}
			for ( int k = 0; k < 3; k++ )
			{
				for ( int l = 0; l < 5; l++ )
				{
					addch( realpieces[i][j][k][l] );
					x++;
					move(y,x);
				}
				x-=5;
				y++;
				move(y,x);
			}
			if ( isupper( cstate[i][j] == 0 ))
			{
				attroff(COLOR_PAIR(1));
			}
			y-=3;
			x+=8;
			move(y,x);
		}
		x=11;
		y+=4;
		move(y,x);
	}
	refresh();
	
}

bool checkvalidmove( int player, char cstate[8][8], int a, int b, int c, int d ){

	char test[8][8];

	int i, j;

	for ( i = 0; i < 8; i++ ){
		for ( j = 0; j < 8; j++ ){
			test[i][j] = cstate[i][j];
		}
	}
	
	int state = checkScan( cstate );
	
	if ( state == player || state == 0 )
	{
		test[c][d] = test[a][b];
		test[a][b] = ' ';
		int tempState = checkScan( test );
		
		if ( tempState == player )
		{					
			return false;
		}
		else 
		{
			return true;
		}
	}
}
	// validmove: returns true if the move made in chess is valid

bool validmove( char cstate[8][8], int a, int b, int c, int d){

	int i, j, q, r;
	char e = cstate[a][b];
	char f = cstate[c][d];

	char tmp;

	// Can't take your own piece

	if ( isupper( e ) != 0 && isupper( f ) != 0 ){	
		return false;
	}

	if ( islower( e ) != 0 && islower( f ) != 0 ){
		return false;
	}

	// Can't move to the same space

	if ( a == c && b == d ){
		return false;
	}

	// Can't move nothing...

	if ( e == ' ' ){
		return false;
	}

	//king can only move one space in any direction

	if ( e == 'K' || e == 'k' ){
		if ( (sqrt((pow ((a-c),2) + pow ((b-d), 2)))) == sqrt(2) || (sqrt((pow ((a-c), 2) + pow ((b-d), 2)))) == 1 ){
			return true;		
		}
		return false;				
	}

	// Queen can move in any direction any number of spaces, but cannot jump pieces

	if ( e == 'Q' || e == 'q' ){
		if ( a == c ){
			if ( b < d ){
				for ( i = (b+1); i < d; i++){
					if ( cstate[a][i] != ' ' ){
						return false;
					}
				}
				return true;
			}
			if ( b > d ){
				for ( i = (d+1); i < b; i++){
					if ( cstate[a][i] != ' ' ){
						return false;
					}
				}
				return true;
			}
		}
		if ( b == d ){
			if ( a < c ){
				for ( i = (a+1); i < c; i++){					
						if ( cstate[i][b] != ' ' ){
						return false;
					}
				}
				return true;
			}
			if ( a > c ){
				for ( i = (c+1); i < a; i++){
					if ( cstate[i][b] != ' ' ){
						return false;
					}
				}
				return true;
			}
		}
		if ( abs(c-a) == abs(d-b) ){
			if ( a > c && b < d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a-i][b+i] != ' ' ){
						return false;
					}				
				} 			
			}
			if ( a > c && b > d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a-i][b-i] != ' ' ){
						return false;
					}				
				} 
			}
			if ( a < c && b > d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a+i][b-i] != ' ' ){
						return false;
					}				
				} 
			}
			if ( a < c && b < d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a+i][b+i] != ' ' ){
						return false;
					}				
				} 
			}
			return true;
		}
		return false;
	}

	// Bishop can move diagonally any number of spaces, but cannot jump pieces

	if ( e == 'B' || e == 'b' ){
		if ( abs(c-a) == abs(d-b) ){
			if ( a > c && b < d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a-i][b+i] != ' ' ){
						return false;
					}				
				} 			
			}
			if ( a > c && b > d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a-i][b-i] != ' ' ){
						return false;
					}				
				} 
			}
			if ( a < c && b > d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a+i][b-i] != ' ' ){
						return false;
					}				
				} 
			}
			if ( a < c && b < d ){
				for ( i = 1; i < abs(a-c); i++){
					if ( cstate[a+i][b+i] != ' ' ){
						return false;
					}				
				} 
			}
			return true;
		}
		return false;
	}

	// Knights can move in L shapes and can jump pieces

	if ( e == 'N' || e == 'n' ){
		if ( (sqrt((pow ((c-a),2) + pow ((d-b), 2)))) == sqrt(5) ){
			return true;
		}
		return false;
	}

	// Rooks can move vertically and horizontally any number of spaces, but cannot jump pieces

	if ( e == 'R' || e == 'r' ){
		if ( a == c ){
			if ( b < d ){
				for ( i = (b+1); i < d; i++){
					if ( cstate[a][i] != ' ' ){
						return false;
					}
				}
				return true;
			}
			if ( b > d ){
				for ( i = (d+1); i < b; i++){
					if ( cstate[a][i] != ' ' ){
						return false;
					}
				}
				return true;
			}
		}
		if ( b == d ){
			if ( a < c ){
				for ( i = (a+1); i < c; i++){					
						if ( cstate[i][b] != ' ' ){
						return false;
					}
				}
				return true;
			}
			if ( a > c ){
				for ( i = (c+1); i < a; i++){
					if ( cstate[i][b] != ' ' ){
						return false;
					}
				}
				return true;
			}
		}
		return false;
	}

	// Pawns can only move forward one space unless they haven't moved yet, then they can take 2 spaces, and they attack diagonally

	if ( e == 'P' ){
		if ( (a == 1) && (c == (a+2)) && (b == d) ){
			if ( cstate[c][d] == ' ' ){			
				return true;
			}
		}
		if ( c == (a+1) && (b == d) ){
			if ( cstate[c][d] == ' ' ){			
				return true;
			}
		}	
		if ( c == (a+1) && (b == (d-1) || b == (d+1))){
			if ( cstate[c][d] != ' ' ){
				return true;
			}
		} 
		return false;
	}

	if ( e == 'p' ){
		if ( a == 6 && c == (a-2) && b == d){
			if ( cstate[c][d] == ' ' ){			
				return true;
			}
		}
		if ( c == (a-1) && (b == d) ){
			if ( cstate[c][d] == ' ' ){			
				return true;
			}
		}	
		if ( c == (a-1) && (b == (d-1) || b == (d+1))){
			if ( cstate[c][d] != ' ' ){
				return true;
			}
		} 
		return false;
	}

	// the king can 'castle' with a rook

	//if ( ( e == 'K' && f == 'R') || ( e == 'k' && f == 'r' ) ){
	
	//}

	// the player must move their king out of check if it is in check

	
	
}

	// checkScan: returns 1 if first player's king is in check, returns 2 if second player's king is in check, returns 0 otherwise

int checkScan( char cstate[8][8] ){
	
	int i, j, k, l, m, n, o, p;
	int value1 = 0; 
	int value2 = 0;

	for ( i = 0; i < 8; i++ ){
		for ( j = 0; j < 8; j++ ){
			if ( cstate[i][j] == 'K' ){
				for ( k = 0; k < 8; k++ ){
					for ( l = 0; l < 8; l++ ){
						if ( islower( cstate[k][l] ) != 0 ){
							if ( validmove( cstate, k, l, i, j ) == true ){								
								value1 = 1;
							}
						}		
					}
				}
			}
		}
	}

	for ( m = 0; m < 8; m++ ){
		for ( n = 0; n < 8; n++ ){
			if ( cstate[m][n] == 'k' ){
				for ( o = 0; o < 8; o++ ){
					for ( p = 0; p < 8; p++ ){
						if ( isupper( cstate[o][p] ) != 0 ){
							if ( validmove( cstate, o, p, m, n ) == true ){
								value2 = 2;
							}
						}	
					}
				}
			}
		}
	}
	return (value1 + value2);
}

	// checkmateScan: checks for a checkmate and returns that same values as checkScan if true

int checkmateScan( char cstate[8][8] ){ 

	int i, j, k, l, m, n, o, p, q, r; 
	
	int value1 = 0;
	int value2 = 0;
	
	char test[8][8];

	char tmp;

	for ( q = 0; q < 8; q++ ){
		for ( r = 0; r < 8; r++ ){
			test[q][r] = cstate[q][r];
		}
	}
	
	
	for ( i = 0; i < 8; i++ ){
		for ( j = 0; j < 8; j++ ){
			for ( k = 0; k < 8; k++ ){
				for ( l = 0; l < 8; l++ ){
					if ( isupper( test[i][j] ) != 0 ){
						if ( validmove( test, i, j, k, l ) == true ){
							tmp = test[k][l];							
							test[k][l] = test[i][j];
							test[i][j] = ' ';																	
							if ( checkScan(test) != 1 ){							
								goto check1;
							}
							test[i][j] = test[k][l];
							test[k][l] = tmp;
						}
					}
				}
			}
		}
	}
	value1 = 1;

	check1:
	
	for ( m = 0; m < 8; m++ ){
		for ( n = 0; n < 8; n++ ){
			for ( o = 0; o < 8; o++ ){
				for ( p = 0; p < 8; p++ ){
					if ( islower( test[m][n] ) != 0 ){
						if ( validmove( test, m, n, o, p ) == true ){
							tmp = test[o][p];							
							test[o][p] = test[m][n];
							test[m][n] = ' ';																	
							if ( checkScan(test) != 2 ){
								goto check2;
							}
							test[m][n] = test[o][p];
							test[o][p] = tmp;
						}
					}
				}
			}
		}
	}
	value2 = 2;

	check2:

	return (value1 + value2);
}

struct AImove
{
	int AIfromX;
	int AIfromY;
	int AItoX;
	int AItoY;
};

AImove getAImove ( char cstate[8][8] )
{
	newAImove:
				
	int fromX = rand() % 8;
	int fromY = rand() % 8;
	int toX = rand() % 8;
	int toY = rand() % 8;
	
	if ( islower( cstate[fromX][fromY] ) == 0 )
	{ 
		goto newAImove;
	}
	else if ( !validmove( cstate, fromX, fromY, toX, toY ) )
	{
		goto newAImove;
	}
	else if ( !checkvalidmove(2, cstate, fromX, fromY, toX, toY) )
	{
		goto newAImove;
	}
	
	AImove move;
	
	move.AIfromX = fromX;
	move.AIfromY = fromY;
	move.AItoX = toX;
	move.AItoY = toY;
	
	return move;
}

bool endState( char cstate[8][8] ){

	if ( checkScan( cstate ) == 1 ){
		slowprint( "\nCHECK TO PLAYER ONE.\n\n");
	}
	
	if ( checkScan( cstate ) == 2){
		slowprint( "\nCHECK TO PLAYER TWO.\n\n");
	}

	if ( checkmateScan( cstate ) == 1 ){
		slowprint( "\nCHECKMATE ON PLAYER ONE. PLAYER TWO WINS.\n\n");
		sleep(5);
		return true;
	}
	
	if ( checkmateScan( cstate ) == 2 ){
		slowprint( "\nCHECKMATE ON PLAYER TWO. PLAYER ONE WINS.\n\n");
		sleep(5);
		return true;
	}
	return false;
}

	// chess: code for the game option chess

void chess(){
	
	start_color();

	char cstate[8][8];
	char dead1[16];
	char dead2[16];	
	int fromX, fromY, toX, toY, i, j;
	int chessplayer = 1;
	bool gameover = false;
	bool AI = true;
	

	for ( i = 0; i < 16; i++ ){
			dead1[i] = ' ';
			dead2[i] = ' ';		
	}

	for ( i = 0; i < 8; i++ ){
		for ( j = 0; j < 8; j++ ){
			cstate[i][j] = ' ';		
		}
	}

	cstate[0][3] = 'K';
	cstate[0][4] = 'Q';
	cstate[0][5] = 'B';
	cstate[0][2] = 'B';
	cstate[0][1] = 'N';
	cstate[0][6] = 'N';
	cstate[0][0] = 'R';
	cstate[0][7] = 'R';
	cstate[1][0] = 'P';
	cstate[1][1] = 'P';
	cstate[1][2] = 'P';
	cstate[1][3] = 'P';
	cstate[1][4] = 'P';
	cstate[1][5] = 'P';
	cstate[1][6] = 'P';
	cstate[1][7] = 'P';
	cstate[7][3] = 'k';
	cstate[7][4] = 'q';
	cstate[7][5] = 'b';
	cstate[7][2] = 'b';
	cstate[7][1] = 'n';
	cstate[7][6] = 'n';
	cstate[7][0] = 'r';
	cstate[7][7] = 'r';
	cstate[6][0] = 'p';
	cstate[6][1] = 'p';
	cstate[6][2] = 'p';
	cstate[6][3] = 'p';
	cstate[6][4] = 'p';
	cstate[6][5] = 'p';
	cstate[6][6] = 'p';
	cstate[6][7] = 'p';
	
	system( "clear" );

	drawBoard2( cstate, dead1, dead2 );
	
	while ( gameover == false )
	{
		
		if ( chessplayer == 1 )
		{

			slowprint( "\nPLAYER ONE MAKE YOUR MOVE:  ");
	
			newPlayer1Input: 
			 
			scanw( "%d%d%d%d", &fromX, &fromY, &toX, &toY);
			
			fromX += -1;
			fromY += -1;
			toX += -1;
			toY += -1;
		
			if ( isupper( cstate[fromX][fromY] ) == 0 ){ 
				slowprint( "\nINVALID MOVE:  ");
				goto newPlayer1Input;
			}

			if ( validmove( cstate, fromX, fromY, toX, toY ) )
			{
				if ( checkvalidmove( 1, cstate, fromX, fromY, toX, toY ) )
				{
					if ( cstate[toX][toY] == ' ' )
					{
						cstate[toX][toY] = cstate[fromX][fromY];
						cstate[fromX][fromY] = ' ';
					}
					else
					{
						for ( i = 0; i < 16; i++)
						{
							if ( dead1[i] == ' ' )
							{
								dead1[i] = cstate[toX][toY];					
								cstate[toX][toY] = cstate[fromX][fromY];
								cstate[fromX][fromY] = ' ';
								break;
							}
						}		
					}
				}
				else
				{
					slowprint( "\nINVALID MOVE (MUST MOVE YOUR KING OUT OF CHECK):  ");
					goto newPlayer1Input;		
				}				
			}
			else
			{
				slowprint( "\nINVALID MOVE:  ");
				goto newPlayer1Input;
			}
			
			chessplayer = 2;
			drawBoard2(cstate, dead1, dead2);
			gameover = endState( cstate );
			if ( gameover ) { break; }
		}
		
		if ( chessplayer == 2 )
		{
			if (AI)
			{
				AImove move = getAImove( cstate );
				
				fromX = move.AIfromX;
				fromY = move.AIfromY;
				toX = move.AItoX;
				toY = move.AItoY;
				
			}
			else{
			
			slowprint( "\nPLAYER TWO MAKE YOUR MOVE:  ");
	
			newPlayer2Input: 
			scanw( "%d%d%d%d", &fromX, &fromY, &toX, &toY);
			
			fromX += -1;
			fromY += -1;
			toX += -1;
			toY += -1;
			}
			
			if ( islower( cstate[fromX][fromY]) == 0 )
			{ 
				slowprint( "\nINVALID MOVE (lower):  ");
				goto newPlayer2Input;
			}

			if ( validmove( cstate, fromX, fromY, toX, toY ) )
			{
				if ( checkvalidmove( 2, cstate, fromX, fromY, toX, toY ) )
				{
					if ( cstate[toX][toY] == ' ' )
					{
						cstate[toX][toY] = cstate[fromX][fromY];
						cstate[fromX][fromY] = ' ';
					}
					else
					{
						for ( i = 0; i < 16; i++)
						{
							if ( dead2[i] == ' ' )
							{
								dead2[i] = cstate[toX][toY];
								cstate[toX][toY] = cstate[fromX][fromY];
								cstate[fromX][fromY] = ' ';
								break;
							}
						}		
					}
				}
				else
				{
				slowprint( "\nINVALID MOVE (MUST MOVE YOUR KING OUT OF CHECK):  ");
				goto newPlayer2Input;		
				}	
			}
			else
			{
				slowprint( "\nINVALID MOVE (validmove) :  ");
				goto newPlayer2Input;
			}
			

			chessplayer = 1;
			system( "clear" );
			drawBoard2(cstate, dead1, dead2);
			gameover = endState( cstate );
			
		}
	}
}

