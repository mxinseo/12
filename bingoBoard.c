#include <stdio.h>
#include "bingoBoard.h"

#define BINGONUM_HOLE		-1

static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE * N_SIZE];

void bingo_init(void)
{
	int i, j;
	int cnt = 1;
	
	for(i = 0; i < N_SIZE; i++){
		for(j = 0; j < N_SIZE; j++){
				numberStatus[cnt-1] = i * N_SIZE + j;				
				bingoBoard[i][j] = cnt++;	
			}
	}
}

void bingo_print(void)
{
	int i, j;
	printf("-------------------------------------\n");
			
	for(i = 0; i < N_SIZE; i++){
		for(j = 0; j < N_SIZE; j++){
			if(bingoBoard[i][j] == BINGONUM_HOLE)
				printf("X\t");
			else 
				printf("%d\t ", bingoBoard[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
}

void bingo_inputNum(int sel)
{
	int row_index;
	row_index = numberStatus[sel-1] / N_SIZE;
	
	int col_index;
	col_index = numberStatus[sel-1] % N_SIZE;
	
	bingoBoard[row_index][col_index] = BINGONUM_HOLE;
	numberStatus[sel-1] = BINGONUM_HOLE;
}

int bingo_countCompletedLine(void)
{
	
}
