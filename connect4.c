/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

#define SEQ_LEN 4
#define TOKEN1 'X'
#define TOKEN2 'O'
#define FIXED '#'
#define SPACE '.'
#define BORDER '-'

/*
*** Please replace this comment with your name and ID number ***
This is the file that you will be submitting for marking
Complete the definitions of the functions in this file
DO NOT REMOVE ANY FUNCTION DEFINITIONS - they all must be present when you submit this file
*/

typedef struct Point {
	int row, col;
} Pt;

// Determines the second largest value of the three input values
int SecondPlacePrize(int prize1, int prize2, int prize3)
{

	// Suppress "nonstandard extension used : non-constant aggregate initializer"
	// as the array is using a constant value and is known to function when compiled
	#pragma warning( suppress : 4204 )  
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
	int ntwo = 1; // starts at 2^0

	while (binary) {
		decimal += (binary % 10) * ntwo;
		binary /= 10;
		ntwo *= 2;
	}

	return decimal;
}

// Compares a and b and returns:
// 1 if a > b
// 0 if a == b
// -1 if a < b
int comparator(const void *a, const void *b) {
	double diff = (*(double*)a - *(double*)b) ;
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
			break;
		default :
			return; // Invalid move so we do nothing

	}

	// Check if the move is invalid
	if (board[row][col] != 0) {
		*lastRow = -1;
		*lastCol = -1;
		return;
	}

	// Keep "moving" the piece until it hits something while ensuring 
	// we don't to read anything that's out of bounds
	while (row+rowVel >= 0 && col+colVel >= 0 && row+rowVel < size && col+colVel < size && board[row+rowVel][col+colVel] == 0) {
		row += rowVel;
		col += colVel;
	}
	
	board[row][col] = player;

	*lastRow = row;
	*lastCol = col;

}

// Clamps a given integer between the given min and max value (inclusive)
int clamp(int a, int min, int max) {
	if (a < min) {
		return min;
	} else if (a > max) {
		return max;
	} else {
		return a;
	}
}

// Clamps a given points x and y values between the given min and max (inclusive)
// while also adjusting them in unison
void ClampPoint(int *x, int *y, int min, int max) {

	while(*x < min || *y < min) {
		*x += 1;
		*y += 1;
	}

	while(*x > max || *y > max) {
		*x -= 1;
		*y -= 1;
	}
}

int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
	Pt i, start, stop; 
	int j, k, dir, seqLen;

	int offset = SEQ_LEN - 1;

	start.row = 0;
	start.col = 0;
	stop.row = 0;
	stop.col = 0;

	// Go through each of the search directions
	for (dir = 0; dir < 4; dir++) {
		
		// Set the start and stop positions for the search
		if (dir == 0) { // Search from mid-left to mid-right
			start.row = row;
			start.col = col - offset;
			stop.row = row;
			stop.col = col + offset;
		} else if (dir == 1) { // Search from mid-top to mid-bottom
			start.row = row - offset;
			start.col = col;
			stop.row = row + offset;
			stop.col = col;
		} else if (dir == 2) { // Search from top-left to bottom-right
			start.row = row - offset;
			start.col = col - offset;
			stop.row = row + offset;
			stop.col = col + offset;
		} else if (dir == 3) { // Search from bottom-left to top-right
			start.row = row + offset;
			start.col = col - offset;
			stop.row = row - offset;
			stop.col = col + offset;
		}
		
		// If any of the start or stop positions values are out of bounds
		// of the board array we move them so they are in bounds
		if (dir < 2) {
			start.row = clamp(start.row, 0, size-1);
			start.col = clamp(start.col, 0, size-1);
			stop.row = clamp(stop.row, 0, size-1);
			stop.col = clamp(stop.col, 0, size-1);
		} else  {
			ClampPoint(&start.row, &start.col, 0, size-1);
			ClampPoint(&stop.row, &stop.col, 0, size-1);
		}

		// i is used here for readability
		i.row = start.row;
		i.col = start.col;
		
		// We adjust i such that it moves away from our stop position
		// as our while loop will adjusts i at the start of each iteration
		i.row += (i.row < stop.row ? -1 : i.row > stop.row ? 1 : 0);
		i.col += (i.col < stop.col ? -1 : i.col > stop.col ? 1 : 0);

		seqLen = 0;

		// Since we don't know beforehand if our stop position is a lower and or higher index 
		// position than our start position, we can only stop looking when we're at the stop position
		while (i.row != stop.row || i.col != stop.col) {

			// We adjust i such that it moves towards our stop position.
			i.row += (i.row < stop.row ? 1 : i.row > stop.row ? -1 : 0);
			i.col += (i.col < stop.col ? 1 : i.col > stop.col ? -1 : 0);
			
			if (board[i.row][i.col] == player) {
				seqLen++;
			} else {
				seqLen = 0;
			}

			if (seqLen == SEQ_LEN) {
				return player;
			}

		}

	}

	// The other condition for the player's victory is if there are no more valid moves
	// This is equivalent to there being no empty spaces left on the edges of the board
	for (j = 0; j < size; j+=size-1) {
		for (k = 0; k < size; k++) {
			if (board[j][k] == 0 || board[k][j] == 0) {
				return 0;
			}
		}
	}

	return player;

}

void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
{
	int row, col, boardVal;
	char boardChar;
	int strPos = 0;

	for (row = 0; row < size + 4; row++) {
		for (col = 0; col < size + 5; col++) {

			if (col == size + 4) {
				boardChar = '\n';

			} else if (row < 2 || row > size + 1 || col < 2 || col > size + 1) {

				if (col >= 2 && col <= size + 1) {
					if (row == 0) {
						boardChar = 'N';
					} else if (row == size + 3) {
						boardChar = 'S';
					} else {
						boardChar = (char)(col-2) + '0';
					}

				} else if (row >= 2 && row <= size + 1) {
					if (col == 0) {
						boardChar = 'W';
					} else if (col == size + 3) {
						boardChar = 'E';
					} else {
						boardChar = (char)(row-2) + '0';
					}

				} else {
					boardChar = BORDER;
				}

			} else if (board[row-2][col-2] != 0) {

				boardVal = board[row-2][col-2];

				if (boardVal == 1) {
					boardChar = TOKEN1;
				} else if (boardVal == 2) {
					boardChar = TOKEN2;
				} else {
					boardChar = FIXED;
				}
				

			} else {
				boardChar = SPACE;
			}

			boardString[strPos] = boardChar;
			strPos++;
			
		}
	}

	boardString[strPos] = '\0';

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
