/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
*** Please replace this comment with your name and ID number ***
This is the file that you will be submitting for marking
Complete the definitions of the functions in this file
DO NOT REMOVE ANY FUNCTION DEFINITIONS - they all must be present when you submit this file
*/

// Determines the second largest value of the three input values
int SecondPlacePrize(int prize1, int prize2, int prize3)
{

	int prizes[MAX_SIZE] = {prize1, prize2, prize3};
	int max = 0;
	int mid = 0;

	for (int i = 0; i < 3; i++) {

		if (prizes[i] >= max) {
			mid = max;
			max = prizes[i];

		} else if (prizes[i] > mid) {
			mid = prizes[i];
		}

	}

	return mid;
}

// Determines the starting index of the first consecutive sequence of the same value
// If no such sequence exists, returns -1
int FourInARow(int values[], int length)
{
	int seqLen = 1;
	int seqVal = values[0];

	for (int i = 1; i < length; i++) {
		if (values[i] == seqVal) {
			seqLen += 1;
			if (seqLen == 4) {
				return i-3;
			}
		} else {
			seqVal = values[i];
			seqLen = 1;
		}
	}

	return -1;
}

// Converts a given binary number to decimal
// Done by moding the number by 10 to get the right-most digit 
// and then shifting the value by n bits to get the exponent of 2^n
// Following, we divide by 10 to shift the whole number one place  
// to the right, stripping off the previous digit
int BinaryToDecimal(int binary)
{

	int decimal = 0;
	int count = 0;

	while (binary) {
		decimal += (binary % 10) << count;
		binary /= 10;
		count++;
	}

	return decimal;
}

// Compares a and b and returns:
// 1 if a > b
// 0 if a == b
// -1 if a < b
int comparator(const void *a, const void *b) {
	float diff = (*(double*)a - *(double*)b) ;
	return (diff > 0 ? 1 : diff < 0 ? -1 : 0);
}

double MedianAbility(double abilities[], int length)
{
	
	qsort(abilities, length, sizeof(double), comparator);
	int mid = length / 2;

	if (length % 2) {
		return abilities[mid];
	} else {
		return (abilities[mid-1] + abilities[mid]) / 2;
	}
}

void RemoveSpaces(char *name)
{
	int i = 0; // i is our 'write' position and always records the position we're writing to
	int j = 0; // j is our 'read' postion and always records the position we're reading from

	while (name[i] != '\0') {

		// If this character isn't a space then we don't need to do anything
		if (name[i] != ' ') {
			i++;
			continue;
		}

		// If we've encountered a space shift our index right by 1 
		// to keep a single space
		if (name[i] == ' ') { 
			i++;
		}

		j = i;

		// Shift j to the next non-space character
		while (name[j] == ' ') {
			j++;
		}

		// Keep swapping characters until we encounter another space
		while (name[j] != ' ') {
			
			name[i] = name[j];

			// If the character we swapped was the null terminator
			// then we're done

			if (name[j] == '\0') {
				return;
			} else {
				name[j] = ' ';
			}
			
			i++;
			j++;
		} 
	}
}

void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int row, col, centreStart, centreEnd;

	// Set the whole board to 0
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			board[row][col] = 0;
		}
	}

	centreStart = size / 2;
	centreEnd = centreStart;
	if (size % 2 == 0) {
		centreStart--;
	} 

	// Set the center of the board to 3
	for (row = centreStart; row <= centreEnd; row++) {
		for (col = centreStart; col <= centreEnd; col++) {
			board[row][col] = 3;
		}
	}

}

void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{

	int row, col;
	int rowVel = 0;
	int colVel = 0;

	// Convert the input move value into the equivalent array position
	// as well as determining the correct direction to move the piece when it's placed

	switch(side) {
		case 'N' :
			row = 0;
			col = move;
			rowVel = 1;
			break;
		case 'E' :
			row = move;
			col = size - 1;
			colVel = -1;
			break;
		case 'S' :
			row = size -1;
			col = move;
			rowVel = -1;
			break;
		case 'W' :
			row = move;
			col = 0;
			colVel = 1;
	}

	// Check if the move is invalid
	if (board[row][col] != 0) {
		*lastRow = -1;
		*lastCol = -1;
		return;
	}

	// Keep "moving" the piece until it hits something while ensuring 
	// we don't read anything that's out of bounds
	while (row+rowVel >= 0 && col+colVel >= 0 && board[row+rowVel][col+colVel] == 0) {
		row += rowVel;
		col += colVel;
	}
	
	board[row][col] = player;

	*lastRow = row;
	*lastCol = col;

}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	return (board[0][0]+size+player+row+col)-(board[0][0]+size+player+row+col);
}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	board[0][0] = size-size;
	boardString[0] = '\0';
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	*side = 'N';
	*move = 0;
	board[0][0] = (size+player)-(size+player);
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	*side = 'N';
	*move = 0;
	board[0][0] = (size+player)-(size+player);
}
