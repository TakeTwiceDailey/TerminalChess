#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <ncurses.h>
#include "joshua.h"

extern int x, y;

// drawBoard3: draws the Global Thermonuclear War board and peices

void gamedraw(){

	erase();

	regprint("\n   180   150W  120W  90W   60W   30W   000   30E   60E   90E   120E  150E  180\n");
	regprint("    |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	regprint("90N-+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-90N\n");
	regprint("    |           . _..::__:  ,----._        ||       ,     _,.__             |\n");
	regprint("    |   _.___ _ _<_>`!(._`.  -     /        _._     `_ ,_/  '  '-._.---.-.__|\n");
	regprint("    |>.{        `-==,',._\{   \\    /       / _   >_,-' `                    _|\n");
	regprint("60N-+  \\_.:--.       `._ )`^-.\\__/  ()      , [_/(        RUS        __,/-' +-60N\n");
	regprint("    | ' '     \\              _L        ()_,--'            ( )       /. (|   |\n");
	regprint("    |          |    USA    ,'          _( .   _<>                _,' /  '   |\n");
	regprint("    |          `.   ( )   /           [_/_':'' (                <'}  )      |\n");
	regprint("30N-+  ..       \\    .-. )           ,---`___\\..' `:._          _)  '       +-30N\n");
	regprint("    |    '        \\  (  `(          /          `:\\  > \\  ,--.  /' '         |\n");
	regprint("    |              `._,             |            \\`'   \\|   |_)  {\\         |\n");
	regprint("    |                 `=.---.        `._._       ,'      `  |' ,- '.        |\n");
	regprint("000-+                   |    `-._         |     /          `:`<_|---._      +-000\n");
	regprint("    |                   (         >       .     | ,          `|.__.__ \\     |\n");
	regprint("    |                    `.      /        |     |{|             ,--.,\\     .|\n");
	regprint("    |                     |     ,'         \\   / `'           ,:      |     |\n");
	regprint("30S-+                     |    /            |_'               |       /     +-30S\n");
	regprint("    |                     |  /'                                '-'''`-'   \\.|\n");
	regprint("    |                     | /                                        *    / |\n");
	regprint("    |                     \\.                                             '  |\n");
	regprint("60S-+                                                                       +-60S\n");
	regprint("    |                      ,/            ______._.--._ _..---.---------._   |\n");
	regprint("    |     ,-------..?----_/ )      __,-'*             *                  (  |\n");
	regprint("    |-.._(                  `-----'                                       `-|\n");
	regprint("90S-+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-90S\n");
	regprint("    |     |     |     |     |     |     |     |     |     |     |     |     |\n");
	regprint("   180   150W  120W  90W   60W   30W   000   30E   60E   90E   120E  150E  180\n\n");


}
void drawBoard3(){

	erase();
	
	y = 0;

	slowprint("\n\n\t                                         ,     _,.__             \n");
	slowprint("\t   _.___ _ _                              `_ ,_/  '  '-._.---.-.__\n");
	slowprint("\t>.{        `-==,_                       >_,-' `                    _\n");
	slowprint("\t  \\_.:--.       `._ )`^-.              /(                   __,/-' \n");
	slowprint("\t ' '     \\              _L            /                   /. (|   \n");
	slowprint("\t          |           ,'               |                _,' /  '   \n");
	slowprint("\t          `.         /                 /               <'}  )      \n");
	slowprint("\t  ..       \\    .-. )                  ' `:._          _)  '       \n");
	slowprint("\t    '        \\  (  `(                      > \\__,--.  /' '         \n");
	slowprint("\t              `._,                                                        \n");
	slowprint("\t                 `\n");
	slowprint("\t           UNITED STATES                      SOVIET UNION          \n\n");

}

	// globalThermonuclearWar: code for the game option of Global Thermonuclear War

void globalThermonuclearWar(){
	
	char moot[200];

	drawBoard3();	

	int uors, chessornot;

	slowprint("\tWHICH SIDE DO YOU WANT?\n\n");
	slowprint("\t\t1.    UNITED STATES\n");
	slowprint("\t\t2.    SOVIET UNION\n\n");
	slowprint("\tPLEASE CHOOSE ONE:  ");
	
	scanw( "%d", &uors);

	slowprint( "\n\n\tAWAITING FIRST STRIKE COMMAND");
	slowprint( "\n\t _____________________________\n");
	slowprint( "\n\t PLEASE LIST PRIMARY TARGETS BY");
	slowprint( "\n\t CITY AND/OR COUNTRY NAME:\n\n");

	move( y, 6 );
	getstr( moot );

	erase();

	y = 0;
	x = 0;	
	move(y,x);

	slowprint( "\n\nSTRANGE GAME. THE ONLY WINNING MOVE IS NOT TO PLAY.");
	sleep(4);
	slowprint( "\n\nHOW ABOUT A NICE GAME OF CHESS?");
	slowprint( "\n\n\t1. YES" );
	slowprint( "\n\t 2. NO\n\n" );

	scanw( "%d", chessornot );

	if ( chessornot == 1 ){
		chess();
	}

	if ( chessornot == 2 ){
		return;
	}
}
