#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL));
	
	//opening
	printf("=============================================\n");
	printf("|               $ BINGO GAME $              |\n");
	printf("=============================================\n\n\n");
	
	//game
	bingo_init();
	//initialise bingo board
	bingo_print();
	bingo_inputNum(5);
	bingo_print();
	bingo_inputNum(12);
	bingo_print();
	
	/*
	while(game is not end) //줄 수가 N_BINGO보다 작음 
	{
		//bingo board print
		//print no. of completed line
		//select a number
		//update the board state
	}
	*/
	
	//ending
	printf("\n\n\n");
	printf("=============================================\n");
	printf("|       *^^*        BINGO!       *^^*       |\n");
	printf("|               CONGRATURATION!             |\n");
	printf("|       *^^*       YOU WIN!      *^^*       |\n");
	printf("=============================================\n\n\n");
	
	
	
	return 0;
}
