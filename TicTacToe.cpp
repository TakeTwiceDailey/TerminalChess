#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>
#include "joshua.h"

extern int y, x;


	// drawBoard1: draws the tictactoe board and pieces 

void drawBoard1(char state[3][3]){

	y = 0;
	erase();

	regprint("\n\n\t\t  1     2     3\n\n\n\n");
	regprint("\t\t      |     |     \n");
	regprint("\t1\t  a  |  b  |  c  \n", state[0][0], state[0][1], state[0][2]);
	regprint("\t\t _____|_____|_____\n");
	regprint("\t\t      |     |     \n");
	regprint("\t2\t  a  |  b  |  c  \n", state[1][0], state[1][1], state[1][2]);
	regprint("\t\t _____|_____|_____\n");
	regprint("\t\t      |     |     \n");
	regprint("\t3\t  a  |  b  |  c  \n", state[2][0], state[2][1], state[2][2]);
	regprint("\t\t      |     |     \n\n\n");
	
}

int endState( char state[3][3], bool gameover ){

	if ( (state[0][0] == 'X' && state[0][1] == 'X' && state[0][2] == 'X') || (state[1][0] == 'X' && state[1][1] == 'X' && state[1][2] == 'X') || (state[2][0] == 'X' && state[2][1] == 'X' && state[2][2] == 'X') || (state[0][0] == 'X' && state[1][0] == 'X' && state[2][0] == 'X') || (state[0][1] == 'X' && state[1][1] == 'X' && state[2][1] == 'X') || (state[0][2] == 'X' && state[1][2] == 'X' && state[2][2] == 'X') || (state[0][0] == 'X' && state[1][1] == 'X' && state[2][2] == 'X') || (state[2][0] == 'X' && state[1][1] == 'X' && state[0][2] == 'X') ){
		return 1;
	}
	if ( (state[0][0] == 'O' && state[0][1] == 'O' && state[0][2] == 'O') || (state[1][0] == 'O' && state[1][1] == 'O' && state[1][2] == 'O') || (state[2][0] == 'O' && state[2][1] == 'O' && state[2][2] == 'O') || (state[0][0] == 'O' && state[1][0] == 'O' && state[2][0] == 'O') || (state[0][1] == 'O' && state[1][1] == 'O' && state[2][1] == 'O') || (state[0][2] == 'O' && state[1][2] == 'O' && state[2][2] == 'O') || (state[0][0] == 'O' && state[1][1] == 'O' && state[2][2] == 'O') || (state[2][0] == 'O' && state[1][1] == 'O' && state[0][2] == 'O') ){
		return 2;
	}
	if ( (! ( state[0][0] == ' ' || state[0][1] == ' ' || state[0][2] == ' ' || state[1][0] == ' ' || state[1][1] == ' ' || state[1][2] == ' ' || state[2][0] == ' ' || state[2][1] == ' ' || state[2][2] == ' ') ) && gameover == false ) {
		return 3;
	}
}

	// tictactoe: code for the game option tic tac toe

void tictactoe(){
	
	newgametictactoe:

	bool valid = false;
	int playernum;
	char state[3][3]; 

	for ( int i = 0; i < 3; i++ ){
		for ( int j = 0; j < 3; j++){
			state[i][j] = ' ';
		}
	}	

	slowprint( "\n\nNUMBER OF PLAYERS:  ");
	
	newscan2: scanw( "%d", &playernum );

	while ( valid == false ){
	
		if ( playernum == 0 || playernum == 1 || playernum == 2 ){
		
			valid = true;

			}
		else {
		
		slowprint( "\nPLAYER NUMBER INVALID. NUMBER OF PLAYERS:  \n"	);
		goto newscan2;

		valid = false;
			}		
	}
		
	if ( playernum == 0 ){

		newgame:

		for ( int i = 0; i < 3; i++ ){
			for ( int j = 0; j < 3; j++){
				state[i][j] = ' ';
			}
		}	

		system("clear");
		drawBoard1(state);

		bool gameover = false;
		bool playerstate = false;	
		int a, b;
		int time1 = 200000;

		while ( gameover == false ){
			if ( playerstate == false ){
		
				newrand1:

				a = rand() % 3 + 1;
				b = rand() % 3 + 1;

				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					goto newrand1;
				}
				state[a-1][b-1] = 'X';
				system("clear");
				drawBoard1(state);
				usleep(time1);
				playerstate = true; 
			}
			else{
		
				newrand2:

				a = rand() % 3 + 1;
				b = rand() % 3 + 1;
		
				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					goto newrand2;
				}
				state[a-1][b-1] = 'O';
				system( "clear" );
				drawBoard1(state);
				usleep(time1);
				playerstate = false;
			}
		
			if ( endState( state, gameover) == 1 ){
				gameover = true;
				slowprint("\nX WINS.\n\n");
			}
			if ( endState( state, gameover) == 2 ){
				gameover = true;
				slowprint("\nO WINS.\n\n");
			}
			if ( endState( state, gameover) == 3 ) {
				slowprint( "\nSTALEMATE.\n\n");
				time1 -= 5000;
				goto newgame;
			}
		}
	}

	if ( playernum == 1 ){

		system("clear");
		drawBoard1(state);

		bool gameover = false;
		bool playerstate = false;	
		int a;
		int b;


		while ( gameover == false ){
			if ( playerstate == false ){
				slowprint("\nMAKE YOUR MOVE (X):  ");
				newscan6: scanw("%d%d", &a, &b);
				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					slowprint( "\nINVALID INPUT:  ");
					goto newscan6;
				}
				state[a-1][b-1] = 'X';
				system("clear");
				drawBoard1(state);
				playerstate = true; 
			}
			else{
			
				newrand:

				a = rand() % 3 + 1;
				b = rand() % 3 + 1;
			
				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					goto newrand;
				}
				state[a-1][b-1] = 'O';
				drawBoard1(state);
				playerstate = false;
			}
			
			if ( endState( state, gameover) == 1 ){
				gameover = true;
				slowprint("\nPLAYER WINS.\n\n");
			}
			if ( endState( state, gameover) == 2 ){
				gameover = true;
				slowprint("\nI WIN.\n\n");
			}
			if ( endState( state, gameover) == 3 ) {
				gameover = true;
				slowprint( "\nSTALEMATE.\n\n");
			}
		}
	}

	if ( playernum == 2 ){


		system("clear");
		drawBoard1(state);

		bool gameover = false;
		bool playerstate = false;	
		int a;
		int b;


		while ( gameover == false ){
			if ( playerstate == false ){
				slowprint("\nFIRST PLAYER MAKE YOUR TURN (X):  ");
				newscan: scanw("%d%d", &a, &b);
				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					slowprint( "\nINVALID INPUT:  ");
					goto newscan;
				}
				state[a-1][b-1] = 'X';
				system("clear");
				drawBoard1(state);
				playerstate = true; 
			}
			else{
				slowprint("\nSECOND PLAYER MAKE YOUR TURN (O):  ");
				newscan1: scanw("%d%d", &a, &b);
				if ( state[a-1][b-1] == 'X' || state[a-1][b-1] == 'O' ){
					slowprint( "\nINVALID INPUT:  ");
					goto newscan1;
				}
				state[a-1][b-1] = 'O';
				system("clear");
				drawBoard1(state);
				playerstate = false;
			}
			
			if ( endState( state, gameover) == 1 ){
				gameover = true;
				slowprint("\nPLAYER ONE WINS.\n\n");
			}
			if ( endState( state, gameover) == 2 ){
				gameover = true;
				slowprint("\nPLAYER TWO WINS.\n\n");
			}
			if ( endState( state, gameover) == 3 ) {
				gameover = true;
				slowprint( "\nSTALEMATE.\n\n");
			}
		}
	}

	int ans;

	slowprint( "\tNEW GAME?\n");
	slowprint( "\n\t\t1. YES\n");
	slowprint( "\n\t\t2. NO\n\n");
	
	newscan4: scanw( "%d", &ans );

	if ( ! ( ans == 1 || ans == 2 ) ){

		slowprint( "\nNUMBER INVALID. NUMBER:  " );
		goto newscan4;
	}
	if ( ans == 1 ){
		goto newgametictactoe;
	}
	//if ( ans == 2 ){
		
	//}
}
