#include <stdio.h>
#include "bingoBoard.h"

#define BINGONUM_HOLE		-1

static int bingoBoard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE * N_SIZE];

int bingo_checkNum(int selNum)
{
	if (numberStatus[selNum-1] == BINGONUM_HOLE)
		return BINGO_NUMSTATUS_ABSENT;
		
	return BINGO_NUMSTATUS_PRESENT;
}

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
				printf("X\t ");
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
	int i, j;
	int cnt = 0;
	int checkBingo;
	
	//row
	for(i=0; i<N_SIZE; i++){
		checkBingo = 1;
		for(j=0; j<N_SIZE; j++){
			if(bingoBoard[i][j] > 0){
				checkBingo = 0;
				break;				
			}
		}
		if (checkBingo == 1)
			cnt++;
	}
	
	//col
	for(j=0; j< N_SIZE; j++ ){
		checkBingo = 1;
		for(i=0; i<N_SIZE; i++){
			if(bingoBoard[i][j] > 0){
				checkBingo = 0;
				break;				
			}
		}
		if (checkBingo == 1)
			cnt++;
	}
	
	//cross 1 (left to right)
	checkBingo = 1;
	for(i=0; i<N_SIZE; i++){
		if(bingoBoard[i][i] > 0){
			checkBingo = 0;
			break;				
		}
	}
	if (checkBingo == 1)
		cnt++;
	
	//cross 1 (right to left)
	for(i=0; i<N_SIZE; i++){
		checkBingo = 1;
		if(bingoBoard[i][N_SIZE-i-1] > 0){
			checkBingo = 0;
			break;				
		}
	}
	if (checkBingo == 1)
		cnt++;
		
	return cnt;
}
