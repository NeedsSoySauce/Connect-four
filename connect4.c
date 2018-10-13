/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

#define SEQ_LEN 4
#define TOKEN1 'X'
#define TOKEN2 'O'
#define FIXED '#'
#define SPACE '.'
#define BORDER '-'

#define MAX_DEPTH 5

/*
Author: Feras Albaroudi
StudentID: 606316303
*/

typedef struct Point {
	int row, col;
} Pt;

// Determines the second largest value of the three input values
int SecondPlacePrize(int prize1, int prize2, int prize3)
{

	int max = prize1;
	int second = prize1;

	if (prize2 > max) {
		second = max;
		max = prize2;		
	} else if (prize2 > second) {
		second = prize2;
	}

	if (prize3 > max) {
		second = max;
		max = prize3;
	} else if (prize3 > second) {
		second = prize3;
	}

	return second;
}

// Determines the starting index of the first consecutive sequence of the same value
// If no such sequence exists, returns -1
int FourInARow(int values[], int length)
{
	int seqLen = 1;
	int seqVal = values[0];

	// Check each value in the sequence to see if it matches seqVal and, if so, increment
	// seqLen by 1 and return the start of the sequence if seqLen equals 4. If the value
	// did not equal seqVal, we set seqLen back to 1 and update seqVal to the current value
	// as this signals the end of the last sequence and the start of a new sequence. 
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
int BinaryToDecimal(int binary)
{

	int decimal = 0;
	int ntwo = 1; // starts at 2^0

	// Mod the binary number by 10 to get the right-most digit and 
	// add that digits place value in base ten to the decimal value.
	// We then perform integer division by 10 to strip off the right-most
	// digit and continue until we're out of non-zero digits
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

// Finds the median value from an array
double MedianAbility(double abilities[], int length)
{
	
	// Sort the array into ascending order
	qsort(abilities, length, sizeof(double), comparator);
	int mid = length / 2;

	// If the array is even the median value is the middle-most value in the array,
	// otherwise it's the average of the two middle-most values in the array
	if (length % 2) {
		return abilities[mid];
	} else {
		return (abilities[mid-1] + abilities[mid]) / 2;
	}
}

// Removes excess spaces in a string by reducing any sequence of spaces in a string 
// greater than 1 to a single space.
void RemoveSpaces(char *name)
{
	int i = 0; // i is our 'write' position and always records the position we're writing to
	int j = 0; // j is our 'swap' postion and always records the position wrapping a value to/from

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

	// centreStart is the row and col index of the center of the board.
	// For an even board centreStart is offset by 1 towards the topleft of the board
	// as the center will be a 2x2 "box" rather than a single position
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
			return; // Invalid side so we do nothing

	}

	// Check if the move is invalid
	if (board[row][col] != 0) {
		*lastRow = -1;
		*lastCol = -1;
		return;
	}

	// Keep "moving" the piece until it hits something while ensuring 
	// we don't read anything that's out of bounds of the array
	while (row+rowVel >= 0 && col+colVel >= 0 && row+rowVel < size && col+colVel < size && board[row+rowVel][col+colVel] == 0) {
		row += rowVel;
		col += colVel;
	}
	
	board[row][col] = player;

	*lastRow = row;
	*lastCol = col;

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

	// If the last move was invalid, that player couldn't possibly have won
	if (row == -1 && col == 1) {
		return 0;
	}

	// Go through each of the search directions
	for (dir = 0; dir < 4; dir++) {
		
		// Set the start and stop positions for the search
		if (dir == 0) { // Horizontal search from mid-left to mid-right
			start.row = row;
			start.col = col - offset;
			stop.row = row;
			stop.col = col + offset;
		} else if (dir == 1) { // Vertical search earch from mid-top to mid-bottom
			start.row = row - offset;
			start.col = col;
			stop.row = row + offset;
			stop.col = col;
		} else if (dir == 2) { // Diagonal search from top-left to bottom-right 
			start.row = row - offset;
			start.col = col - offset;
			stop.row = row + offset;
			stop.col = col + offset;
		} else { // Diagonal search from bottom-left to top-right
			start.row = row + offset;
			start.col = col - offset;
			stop.row = row - offset;
			stop.col = col + offset;
		}

		// i is used here for readability
		i.row = start.row;
		i.col = start.col;
		
		// We adjust i such that it moves away from our stop position
		// as our while loop adjusts i at the start of each iteration
		i.row += (i.row < stop.row ? -1 : i.row > stop.row ? 1 : 0);
		i.col += (i.col < stop.col ? -1 : i.col > stop.col ? 1 : 0);

		seqLen = 0;

		// Since we don't know beforehand if our stop position is a lower and or higher index 
		// position than our start position, we can only stop searching when we're at the stop position
		while (i.row != stop.row || i.col != stop.col) {

			// We adjust i such that it moves towards our stop position.
			i.row += (i.row < stop.row ? 1 : i.row > stop.row ? -1 : 0);
			i.col += (i.col < stop.col ? 1 : i.col > stop.col ? -1 : 0);
			
			// Ignore indexes that are out of array bounds
			if (i.row < 0 || i.row > size - 1 || i.col < 0 || i.col > size - 1) {
				continue;
			}

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

	// Loop through each position in the board with one additional column to represent
	// the newlines at the end of each row
	for (row = 0; row < size + 4; row++) {
		for (col = 0; col < size + 5; col++) {

			// If we're at the end of this row in the board we want the next row to
			// print below it
			if (col == size + 4) {
				boardChar = '\n';

			// The boards border is two characters wide. We use this to determine if
			// the current position is part of the boards border.
			} else if (row < 2 || row > size + 1 || col < 2 || col > size + 1) {

				if (col >= 2 && col <= size + 1) {
					if (row == 0) {
						boardChar = 'N';
					} else if (row == size + 3) {
						boardChar = 'S';
					} else {
						// This adds the row/col number to the board string, offset by 
						// 2 due to the board's border
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

				// The BORDER constant is the character that's printed in the corners of the board
				} else {
					boardChar = BORDER;
				}

			// Adds player tokens and the fixed pieces at the center of the board to the board's string
			} else if (board[row-2][col-2] != 0) {

				boardVal = board[row-2][col-2];

				if (boardVal == 1) {
					boardChar = TOKEN1;
				} else if (boardVal == 2) {
					boardChar = TOKEN2;
				} else {
					boardChar = FIXED;
				}
				
			// Finally anything else on the board must be an empty space on the board
			} else {
				boardChar = SPACE;
			}

			boardString[strPos] = boardChar;
			strPos++;
			
		}
	}

	boardString[strPos] = '\0';

}

// Fills two arrays with all valid moves based on the current board state for the given player
void GetValidMoves(int board[MAX_SIZE][MAX_SIZE], int size, char sides[MAX_SIZE*4], int moves[MAX_SIZE*4], int *length) {
	// A valid move is considered as any move that:
	// - Won't place a piece where one already exists on the edges of the board

	int i;
	int count = 0;

	// Go through each of the edge positions on the board
	for (i = 0; i < size; i++) {
		
		// Check the North row
		if (board[0][i] == 0) {
			sides[count] = 'N';
			moves[count] = i;
			count++;
		} 

		// Check the east col
		if (board[i][size-1] == 0) {
			sides[count] = 'E';
			moves[count] = i;
			count++;
		}

		// Check the south col
		if (board[size-1][i] == 0) {
			sides[count] = 'S';
			moves[count] = i;
			count++;
		}

		// Check the west col
		if (board[i][0] == 0) {
			sides[count] = 'W';
			moves[count] = i;
			count++;
		}

	}

	*length = count;

}

// Counts how many of the nearby pieces are from the given player's side
int CountNeighbours(int board[MAX_SIZE][MAX_SIZE], int size, int player, int x, int y) {

	int count = -1;

	for (int row = x-1; row <= x+1; row++) {

		if (row < 0 || row > size - 1) {
			continue;
		}

		for (int col = y-1; col <= y+1; col++) {
			if (col < 0 || col > size - 1) {
				continue;
			}

			if (board[row][col] == player) {
				count++;
			}
		}
	}

	return count;
}

int Minimax(int board[MAX_SIZE][MAX_SIZE], int size, int player, char side, int move, int depth, int rootPlayer) {
	
	int i, length, row, col, outcome;
	int rating = 0;
	int bestRating = 0;
	int moves[MAX_SIZE*4];
	char sides[MAX_SIZE*4];
	
	// Add the given move to the board and then check the game's state
	AddMoveToBoard(board, size, side, move, player, &row, &col);
	outcome = CheckGameOver(board, size, player, row, col);

	// We keep calling Minimax until there's a change in the games state or we reach the max tree depth
	if (outcome != 0) {
		rating = 10 + (MAX_DEPTH - depth);
		if (!rootPlayer) {
			rating *= -1;
		}
		board[row][col] = 0;
		return rating;
	} else if (depth >= MAX_DEPTH) { 
		rating = CountNeighbours(board, size, player, row, col);	
		if (!rootPlayer) {
			rating *= -1;
		}
		board[row][col] = 0;
		return rating;
	}

	GetValidMoves(board, size, sides, moves, &length);
	
	// Call Minimax for the other player for each valid move on the board
	for (i = 0; i < length; i++) {
		rating = Minimax(board, size, 3 - player, sides[i], moves[i], depth+1, !rootPlayer);
		if (rootPlayer) {
			if (rating < bestRating) {
				bestRating = rating;
			}
		} else {
			if (rating > bestRating) {
				bestRating = rating;
			}
		}
	}

	// Undo the changes we made to the board at this node
	board[row][col] = 0;

	return bestRating;
}

void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	int i, length;
	int depth = 0;
	int rating = 0;
	int max = 0;
	int pos = 0;
	int moves[MAX_SIZE*4];
	char sides[MAX_SIZE*4];
	
	printf("Bot%d move\n", player);

	// Initially we grab all the valid moves based on the board's current state
	GetValidMoves(board, size, sides, moves, &length);

	// Find the move with the highest rating for this player
	for (i = 0; i < length; i++) {
		rating = Minimax(board, size, player, sides[i], moves[i], depth+1, 1);
		if (rating >= max) {
			max = rating;
			pos = i;
		}
	}

	// The move we play will be the move with the highest rating. If there's
	// multiple options with the same score, we just pick the first one.
	*move = moves[pos];
	*side = sides[pos];

	printf("Bot%d max = %d\n", player, max);
	printf("Bot%d plays %c%d with rating %d\n", player, *side, *move, max);
}

void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
{
	GetMoveBot1(board, size, player, side, move);
}
