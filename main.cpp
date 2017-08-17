#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>
#include "joshua.h"

int time = 15000;
int y = 2;
int x = 0;


int main() {

	int choice;
	char moot[200];
	initscr();
	start_color();
	chess();
	
	// move( y, 0 );
	// slowprint( "\nGREETINGS PROFESSOR FALKEN.\n\n");
	// move( y, 0);	
	// getstr(moot);
	// y++;
	// slowprint( "\nHOW ARE YOU FEELING TODAY?\n\n" );
	// move( y, 0);	
	// getstr(moot);
	// y++;
	// slowprint( "\nEXCELLENT\n" );
	// slowprint( "\nSHALL WE PLAY A GAME?\n" );
	// slowprint( "\nGAME LIST:\n" );
	// slowprint( "\n1. TICTACTOE" );
	// slowprint( "\n2. CHESS" );
	// slowprint( "\n3. GLOBAL THERMONUCLEAR WAR\n\n" );

	// newscan3: 
	// x = 0;
	// move(y,x);
	// scanw( "%d", &choice );

	// if ( ! ( choice == 1 || choice == 2 || choice == 3 ) ){
		// regprint( "\nGAME NUMBER INVALID. GAME NUMBER:  " );
		// goto newscan3;
	// }

	// if ( choice == 1 ){
		// tictactoe();
	// }

	// if ( choice == 2 ){
		// chess();
	// }

	// if ( choice == 3 ){
		// slowprint( "\n\nWOULDN'T YOU PREFER A NICE GAME OF CHESS?\n\n" );	
		// move( y, 0);	
		// getstr(moot);
		// globalThermonuclearWar();
	// }

	endwin();

	return 0;
}

void slowprint(const char* string){

	char letter;

	x = 0;

	for ( int i = 0; i < strlen(string); i++){
		letter = string[i]; 
		if ( letter == '\n' ){ 
			y++;
		}
		if ( letter == '\t' ){
			x += 4;
		}
		addch( letter );
		refresh();
		move( y , x+i );
		usleep(time);
	}
}

void regprint( const char* string ){

	char letter;

	x = 0;

	for ( int i = 0; i < strlen(string); i++){
		letter = string[i]; 
		if ( letter == '\n' ){ 
			y++;
		}
		if ( letter == '\t' ){
			x += 4;
		}
		addch( letter );
		refresh();
		move( y , x+i );
	}
}

void regprint(const char* string, char a, char b, char c ){

	char letter;

	x = 0;

	for ( int i = 0; i < strlen(string); i++){
		letter = string[i]; 
		if ( letter == 'a' ){
			letter = a;				
		}
		if ( letter == 'b' ){
			letter = b;
		}		
		if ( letter == 'c' ){
			letter = c;
		}	
		if ( letter == '\n' ){ 
			y++;
		}
		if ( letter == '\t' ){
			x += 4;
		}
		addch( letter );
		refresh();
		move( y , x+i );
	}

}

void regprint(const char* string, char a, char b, char c, char d, char e, char f, char g, char h ){

	char letter;
	x = 0;

	for ( int i = 0; i < strlen(string); i++){
		letter = string[i]; 
		if ( letter == 'a' ){
			letter = a;				
		}
		if ( letter == 'b' ){
			letter = b;
		}		
		if ( letter == 'c' ){
			letter = c;
		}	
		if ( letter == 'd' ){
			letter = d;				
		}
		if ( letter == 'e' ){
			letter = e;
		}		
		if ( letter == 'f' ){
			letter = f;
		}	
		if ( letter == 'g' ){
			letter = g;
		}		
		if ( letter == 'h' ){
			letter = h;
		}	
		if ( letter == '\n' ){ 
			y++;
		}
		if ( letter == '\t' ){
			x += 4;
		}
		addch( letter );
		refresh();
		move( y , x+i );
	}
}  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
