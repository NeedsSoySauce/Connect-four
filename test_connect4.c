/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */
#include "connect4.h"

/*
This program is designed to let you TEST the functions you have written in connect4.c.
You can test one function at a time, or you can play a complete game of Connect Four,
in which case you will need to have completed all of the functions.  If you want to test
just one of your functions, you should write the appropriate test code in the
MyTestFunction() function.  Initially, this function contains all of the test code from
the project handout.
*/
void MyTestFunction(void);
void PlayConnectFour(void);
void CountNeighbours(int board[MAX_SIZE][MAX_SIZE], int size, int player, int x, int y, int dist,
					int *playerTokens, int *opponentTokens, int *emptySpaces);
void GetValidMoves(int board[MAX_SIZE][MAX_SIZE], int size, char sides[MAX_SIZE*4], int moves[MAX_SIZE*4], int *length);

/*
This function is where you can write your own test code, to test the functions that you
have written in the connect.c source file.  Currently, this function contains all of the
examples from the project handout document.  You can make any changes to this function
that you like.
*/

void PrintBoard(int board[MAX_SIZE][MAX_SIZE], int size) {
	char boardString[250];
	GetDisplayBoardString(board, size, boardString);
	printf("%s", boardString);
}

void CustomTest(void) {

	int board[MAX_SIZE][MAX_SIZE];
	int hasWon, size, move, rowPos, colPos;
	char side;

	// ---------------> Checking that the bot will pick a valid move when there's only one available (only S2 and S3 are available)
	printf("\n--------> Checking that the bot will pick a valid move when there's only one available (only S2 and S3 are available)\n");
	size = 4;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 1, 2, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
}

void TestBot(void) {

	int board[MAX_SIZE][MAX_SIZE];
	int hasWon, size, move, rowPos, colPos;
	char side;

	int passes = 0;
	int tests = 0;

	// ---------------> Check Horizontal victory
	printf("\n--------> Check Horizontal victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Horizontal in-between victory
	printf("\n--------> Check Horizontal in-between victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Vertical victory
	printf("\n--------> Check Vertical victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Vertical in-between victory
	printf("\n--------> Check Vertical in-between victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check bottom-left to top-right diagonal victory
	printf("\n--------> Check bottom-left to top-right diagonal victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 1, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;
	

	// ---------------> Checking that the bot will take an in-between diagonal victory
	printf("\n--------> Checking that the bot will take an in-between diagonal victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 2, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 1, &rowPos, &colPos);
	
	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check top-left to bottom-right diagonal victory
	printf("\n--------> Check top-left to bottom-right diagonal victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check top-left to bottom-right in-between diagonal victory
	printf("\n--------> Check top-left to bottom-right in-between diagonal victory\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;
	

	// ---------------> Checking that the bot will take take a victory over a defend when it has both options
	printf("\n--------> Checking that the bot will take take a victory over a defend when it has both options\n");
	size = 10;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 2, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will pick a valid move when there's only one available (only S2 is available)
	printf("\n--------> Checking that the bot will pick a valid move when there's only one available (only S2 is available)\n");
	size = 4;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 1, 2, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will take a victory when it has multiple ways to win
	printf("\n--------> Checking that the bot will take a victory when it has multiple ways to win\n");
	size = 10;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will take a victory the opponent has multiple ways to win
	printf("\n--------> Checking that the bot will take a victory the opponent has multiple ways to win\n");
	size = 10;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'E', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 6, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 7, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 5, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 6, 2, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'W', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 5, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// -------------------------------------------------------
	// ---------- UNEVEN BOARD TESTS START HERE -------------- 
	// -------------------------------------------------------

	// ---------------> Check Horizontal victory
	printf("\n--------> Check Horizontal victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Horizontal in-between victory
	printf("\n--------> Check Horizontal in-between victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Vertical victory
	printf("\n--------> Check Vertical victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check Vertical in-between victory
	printf("\n--------> Check Vertical in-between victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check bottom-left to top-right diagonal victory
	printf("\n--------> Check bottom-left to top-right diagonal victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);


	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;
	

	// ---------------> Checking that the bot will take an in-between diagonal victory
	printf("\n--------> Checking that the bot will take an in-between diagonal victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);
	
	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check top-left to bottom-right diagonal victory
	printf("\n--------> Check top-left to bottom-right diagonal victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'S', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 2, 1, &rowPos, &colPos);


	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Check top-left to bottom-right in-between diagonal victory
	printf("\n--------> Check top-left to bottom-right in-between diagonal victory\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'S', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 3, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;
	

	// ---------------> Checking that the bot will take take a victory over a defend when it has both options
	printf("\n--------> Checking that the bot will take take a victory over a defend when it has both options\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);

	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will pick a valid move when there's only one available (only S3 is available)
	printf("\n--------> Checking that the bot will pick a valid move when there's only one available (only S3 is available)\n");
	size = 5;
	InitialiseBoard(board, size);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);


	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (side == 'S' && move == 3 ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will take a victory when it has multiple ways to win
	printf("\n--------> Checking that the bot will take a victory when it has multiple ways to win\n");
	size = 5;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 1, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board, size, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	passes += (hasWon == 1 ? 1 : 0);
	tests++;

	printf("------> Bot 1 passed %d/%d tests\n", passes, tests);
	
}

void TestBotExtended(void) {

	int board[MAX_SIZE][MAX_SIZE];
	int size, move, rowPos, colPos;
	char side;

	int passes = 0;
	int tests = 0;

	// ---------------> Checking that the bot will make a move on N
	printf("\n--------> Checking that the bot will make a mone on N\n");
	size = 5;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'N', 0, 1, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Result = %c%d\n", side, move);
	passes += ( (side == 'N' && move >= 1 && move <= 3) ? 1 : 0);
	tests++;

	// ---------------> Checking that the bot will make a move on E
	printf("\n--------> Checking that the bot will make a mone on E\n");
	size = 5;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 4, 2, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Result = %c%d\n", side, move);
	passes += ( (side == 'E' && move >= 1 && move <= 3) ? 1 : 0);
	tests++;	

	// ---------------> Checking that the bot will make a move on S
	printf("\n--------> Checking that the bot will make a mone on S\n");
	size = 5;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Result = %c%d\n", side, move);
	passes += ( (side == 'S' && move >= 1 && move <= 3) ? 1 : 0);
	tests++;	

	// ---------------> Checking that the bot will make a move on W
	printf("\n--------> Checking that the bot will make a mone on W\n");
	size = 5;
	InitialiseBoard(board, size);

	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'E', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'S', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 2, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 1, &rowPos, &colPos);
	AddMoveToBoard(board, size, 'W', 4, 2, &rowPos, &colPos);

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Result = %c%d\n", side, move);
	passes += ( (side == 'W' && move >= 1 && move <= 3) ? 1 : 0);
	tests++;	

	// ---------------> Checking that the bot will make a move on position 3
	printf("\n--------> Checking that the bot will make a move on position 3\n");
	size = 5;
	InitialiseBoard(board, size);

	board[0][0] = 1;
	board[0][1] = 2;
	board[0][2] = 1;
	board[4][0] = 1;
	board[4][1] = 2;
	board[4][2] = 1;
	board[0][4] = 1;
	board[1][4] = 2;
	board[2][4] = 1;
	board[1][0] = 1;
	board[2][0] = 2;
	board[4][4] = 1;

	GetMoveBot1(board, size, 1, &side, &move);
	AddMoveToBoard(board, size, side, move, 1, &rowPos, &colPos);
	
	PrintBoard(board, size);

	printf("   Result = %c%d\n", side, move);
	passes += ( move == 3 ? 1 : 0);
	tests++;	

	printf("------> Bot 1 passed %d/%d tests\n", passes, tests);


}

void TestValidMoves(void) {

	int board[MAX_SIZE][MAX_SIZE], i;
	int length, size, moves[MAX_SIZE*4], rowPos, colPos;
	char sides[MAX_SIZE*4];
	time_t t;

	int passes = 0;
	int tests = 0;

	printf("\n----- > Checking that all moves are valid for board sizes 4 - 10\n");
	for (size = 4; size <= 10; size++) {	
		passes = 0;
		tests = 0;	
		InitialiseBoard(board, size);
		GetValidMoves(board, size, sides, moves, &length);
		tests = length;
		for (i = 0; i < length; i++) {
			// printf("Playing %c%d\n", sides[i], moves[i]);
			AddMoveToBoard(board, size, sides[i], moves[i], 1, &rowPos, &colPos);
			passes += ((rowPos != -1 && colPos != -1) ? 1 : 0);
			// PrintBoard(board, size);
			board[rowPos][colPos] = 0;
		}
		printf("------> Valid Moves at size %d: %d/%d \t= %s\n", size, passes, tests, (passes == tests ? "PASS" : "FAIL"));
	}

	printf("\n----- > Checking that all board sizes can be filled until there are no valid moves without any errors\n");
	for (size = 4; size <= 10; size++) {	
		passes = 0;
		length = 100;
		InitialiseBoard(board, size);
		srand((unsigned) time(&t));
		while (length > 2) {
			GetValidMoves(board, size, sides, moves, &length);
			i = rand() % length;
			AddMoveToBoard(board, size, sides[i], moves[i], 1, &rowPos, &colPos);
			if (rowPos == -1 || colPos == -1) {
				printf("FAILED to fill size %d due to invalid move after %d moves\n", size, passes);
				break;
			}
			passes += ((rowPos != -1 && colPos != -1) ? 1 : 0);
		}
		printf("------> 'Filled' size %d after %d moves\n", size, passes);
	}
}

void MyTestFunction(void)
{
	// An example of code that you could use to test Task One.
	// You should write additional tests of your own
	// You can assume each of the three inputs is a positive integer, greater than zero
	printf("\nTESTING TASK ONE:\n");
	printf("=================\n");
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(200, 100, 200), 200);
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(45, 600, 590), 590);
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(2, 2, 2), 2); // All values equal
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(3, 3, 7), 3); // Second place same as third place (smallest first)
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(8, 2, 2), 2); // Second place same as third place (smallest last)
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(12, 12, 4), 12); // Second place same as first place (largest first)
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(3, 9, 9), 9); // Second place same as third place (largest last)
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(5, 2, 5), 5); // Outer values are second place (largest first)
	printf("   Prize = %d (expected %d)\n", SecondPlacePrize(1, 2, 1), 1); // Outer values are second place (smallest first)

	// An example of code that you could use to test Task Two.
	// You should write additional tests of your own
	printf("\nTESTING TASK TWO:\n");
	printf("=================\n");
	int valuesA[10] = {1,2,1,2,1,1,1,1,2,1};
	int valuesB[15] = {1,2,1,2,1,1,1,2,2,1,1,4,4,4,4};
	int valuesC[15] = {5,6,7,8,8,8,8,8,8,8,8,8,8,8,8};
	int result;
	result = FourInARow(valuesA, 10);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesB, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 15);
	printf("   Result = %d\n", result);
	result = FourInARow(valuesC, 6);
	printf("   Result = %d\n", result);

	// An example of code that you could use to test Task Three.
	// You should write additional tests of your own
	printf("\nTESTING TASK THREE:\n");
	printf("===================\n");
	printf("   Decimal = %d\n", BinaryToDecimal(101));
	printf("   Decimal = %d\n", BinaryToDecimal(1));
	printf("   Decimal = %d\n", BinaryToDecimal(11111111));
	printf("   Decimal = %d\n", BinaryToDecimal(100000000));
	printf("   Decimal = %d\n", BinaryToDecimal(1111111111)); // Maximum number of bits that can be held in an integer


	// An example of code that you could use to test Task Four.
	// You should write additional tests of your own
	printf("\nTESTING TASK FOUR:\n");
	printf("===================\n");
	double grpA[5]={4.3,2.1,6.7,5.0,1.2};
	double grpB[10]={4.3,2.1,6.7,5.0,1.2,9.9,7.0,3.0,6.6,6.5};
	double medianAbilityA, medianAbilityB;
	medianAbilityA = MedianAbility(grpA, 5);
	medianAbilityB = MedianAbility(grpB, 10);
	printf("   Median ability Group A = %.2f\n", medianAbilityA);
	printf("   Median ability Group B = %.2f\n", medianAbilityB);


	// An example of code that you could use to test Task Five.
	// You should write additional tests of your own
	printf("\nTESTING TASK FIVE:\n");
	printf("===================\n");
	char nameA[100] = "The       Champ";
	char nameB[100] = "     I    AM      THE     GREATEST    ";
	char nameC[100] = "Therearenospaceshereatall";
	char nameD[100] = "D";
	char nameE[100] = " ";
	char nameF[100] = "F                    ";
	char nameG[100] = "                    G";
	char nameH[100] = "                    H                    ";
	char nameI[100] = "                                       ";
	char nameJ[100] = " A B C D E F ";
	RemoveSpaces(nameA);
	RemoveSpaces(nameB);
	RemoveSpaces(nameC);
	RemoveSpaces(nameD);
	RemoveSpaces(nameE);
	RemoveSpaces(nameF);
	RemoveSpaces(nameG);
	RemoveSpaces(nameH);
	RemoveSpaces(nameI);
	RemoveSpaces(nameJ);
	printf("   Name A = [%s]\n", nameA);
	printf("   Name B = [%s]\n", nameB);
	printf("   Name C = [%s]\n", nameC);
	printf("   Name D = [%s]\n", nameD);
	printf("   Name E = [%s]\n", nameE);
	printf("   Name F = [%s]\n", nameF);
	printf("   Name G = [%s]\n", nameG);
	printf("   Name H = [%s]\n", nameH);
	printf("   Name I = [%s]\n", nameI);
	printf("   Name J = [%s]\n", nameJ);

	// An example of code that you could use to test Task Six.
	// You should write additional tests of your own
	printf("\nTESTING TASK SIX:\n");
	printf("===================\n");
	int board6[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			board6[i][j] = -1;
		}
	}
	printf("   Board of size 5x5:\n");
	InitialiseBoard(board6, 5);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}
	printf("   Board of size 8x8:\n");
	InitialiseBoard(board6, 8);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("   ");
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", board6[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Seven.
	// You should write additional tests of your own
	printf("\nTESTING TASK SEVEN:\n");
	printf("=====================\n");
	int board7[MAX_SIZE][MAX_SIZE];
	int rowPosition, colPosition;
	int size7 = 8;
	InitialiseBoard(board7, size7);
	AddMoveToBoard(board7, size7, 'N', 1, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'E', 4, 2, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'S', 5, 1, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	AddMoveToBoard(board7, size7, 'E', 2, 2, &rowPosition, &colPosition);
	printf("   Token position: row=%d, col=%d\n", rowPosition, colPosition);
	for (int i = 0; i < size7; i++) {
		printf("   ");
		for (int j = 0; j < size7; j++) {
			printf("%d ", board7[i][j]);
		}
		printf("\n");
	}

	// An example of code that you could use to test Task Eight.
	// You should write additional tests of your own
	printf("\nTESTING TASK EIGHT:\n");
	printf("=====================\n");
	int board8[MAX_SIZE][MAX_SIZE];
	int rowPos, colPos;
	int size8 = 5;
	int hasWon;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 2 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 2, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// -------------- > Check diagonal victory
	printf("\n--------> CHECKING FOR DIAGONAL VICTORY with last piece middle\n");
	size8 = 10;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);

	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);
	
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);
	
	// Check another diagonal victory format
	printf("\n--------> CHECKING FOR DIAGONAL VICTORY with last piece not middle\n");
	size8 = 10;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 0, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);

	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 1, &rowPos, &colPos);
	
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// Check bottom-left to top-right diagonal victory
	printf("\n--------> CHECKING FOR DIAGONAL VICTORY from bottom-left to top-right\n");
	size8 = 10;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);

	AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 3, 1, &rowPos, &colPos);
	
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	// Check bottom-left to top-right diagonal victory
	printf("\n--------> CHECKING FOR 1-off false-positive\n");
	size8 = 7;
	InitialiseBoard(board8, size8);

	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 2, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);

	AddMoveToBoard(board8, size8, 'W', 2, 2, &rowPos, &colPos);
	
	AddMoveToBoard(board8, size8, 'S', 5, 1, &rowPos, &colPos);

	
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	printf("   Checking for win for Player 1 in [%d, %d]\n", rowPos, colPos);
	hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
	printf("   Result = %d\n", hasWon);

	int checkBot = 0;

	if (checkBot) {
		// Check bottom-left to top-right diagonal victory
		printf("\n--------> CHECKING FOR bot counter diagonal\n");
		size8 = 10;
		InitialiseBoard(board8, size8);
		AddMoveToBoard(board8, size8, 'N', 1, 2, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 2, 2, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 3, 2, &rowPos, &colPos);

		AddMoveToBoard(board8, size8, 'N', 0, 1, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 1, 1, &rowPos, &colPos);
		AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);

		char side;
		int move;

		GetMoveBot1(board8, size8, 1, &side, &move);
		AddMoveToBoard(board8, size8, side, move, 1, &rowPos, &colPos);
		
		for (int i = 0; i < size8; i++) {
			printf("   ");
			for (int j = 0; j < size8; j++) {
				printf("%d ", board8[i][j]);
			}
			printf("\n");
		}
		printf("   Checking for win for Bot 1 in [%d, %d]\n", rowPos, colPos);
		hasWon = CheckGameOver(board8, size8, 1, rowPos, colPos);
		printf("   Result = %d\n", hasWon);
	}

	// Checking CountNeighbours
	printf("\n--------> CHECKING CountNeighbours\n");
	size8 = 10;
	InitialiseBoard(board8, size8);
	AddMoveToBoard(board8, size8, 'N', 1, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 6, 1, &rowPos, &colPos);
	AddMoveToBoard(board8, size8, 'N', 2, 1, &rowPos, &colPos);
	
	for (int i = 0; i < size8; i++) {
		printf("   ");
		for (int j = 0; j < size8; j++) {
			printf("%d ", board8[i][j]);
		}
		printf("\n");
	}
	int playerTokens, opponentTokens, emptySpaces;
	CountNeighbours(board8, size8, 1, rowPos, colPos, 1, &playerTokens, &opponentTokens, &emptySpaces);
	printf("Neighbours for (%d, %d):\n%d friendly\n%d opponent\n%d empty\n", rowPos, colPos, playerTokens, opponentTokens, emptySpaces);

	// An example of code that you could use to test Task Nine.
	// You should write additional tests of your own
	printf("\nTESTING TASK NINE:\n");
	printf("====================\n");
	int board9[MAX_SIZE][MAX_SIZE];
	int size9 = 4;
	char boardString[250];
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);
	size9 = 10;
	InitialiseBoard(board9, size9);
	GetDisplayBoardString(board9, size9, boardString);
	printf("   The length of the board string is: %d\n", strlen(boardString));
	printf("%s", boardString);

	// An example of code that you could use to test Task Ten.
	printf("\nTESTING TASK TEN:\n");
	printf("===================\n");
	printf("   You can test Task Ten by implementing the two Bot functions in connect.c.\n");
	printf("   If you then play a tournament, of many games, between the two bots, you \n");
	printf("   can see which one is performing the best.  This might help you to refine \n");
	printf("   the strategies that you are using. \n");

}

/*********************************************************************************/
/*
The main function for the test program.  The user is asked whether they want to test their
functions or play a game of connect four.  Based on the user's input, the appropriate function
is called.
*/
int main(void)
{
	int input;
	printf("ENGGEN131 Project - Semester Two - 2018\n");
	printf("                                 _      __                 \n");
	printf("                                | |    / _|                \n");
	printf("  ___ ___  _ __  _ __   ___  ___| |_  | |_ ___  _   _ _ __ \n");
	printf(" / __/ _ \\| '_ \\| '_ \\ / _ \\/ __| __| |  _/ _ \\| | | | '__|\n");
	printf("| (_| (_) | | | | | | |  __/ (__| |_  | || (_) | |_| | |   \n");
	printf(" \\___\\___/|_| |_|_| |_|\\___|\\___|\\__| |_| \\___/ \\__,_|_|   \n");
	printf("\nWould you like to:\n\n");
	printf("  0 = Test individual functions in connect.c\n");
	printf("      [you should write your own test code for this in MyTestFunction()]\n");
	printf("  1 = Play Connect Four\n");
	printf("      [this will only work if you to have completed all of the functions)]\n");
	printf("  2 = Custom test\n");
	printf("      [User defined test]\n");
	printf("  3 = Test Bot\n");
	printf("      [Test Bot 1 to verify it's making the expected move in different scenarios]\n");
	printf("  4 = Test Valid Moves\n");
	printf("      [Test that all moves for a given board size are valid]\n");
	printf("  5 = Extended Bot Tests\n");
	printf("      [Test the bot using test cases similar to those shown during lectures]\n");
	printf("\nPlease enter your choice:  ");
	scanf("%d", &input);
	if (input == 0) {
		MyTestFunction();
	} else if (input == 1) {
		PlayConnectFour();
	} else if (input == 2) {
		CustomTest();
	} else if (input == 3) { 
		TestBot();
	} else if (input == 4) { 
		TestValidMoves();
	} else if (input == 5) { 
		TestBotExtended();
	}

	return 0;
}

/*********************************************************************************/
/*
This function is called when a human player is asked to enter their move.  The character
(representing the side of the board) and the digit (representing the row/column) are
returned via the pointers *side and *move.
*/
void GetMoveHuman(char *side, int *move, int player)
{
	char a = ' ';
	char b = ' ';
	printf("Player %d: enter move [side/position]: ", player);
	while (!(a == 'N' || a == 'W' || a == 'E' || a == 'S')) {
		scanf("%c", &a);
	}
	while (!(b >= '0' && b <= '9')) {
		scanf("%c", &b);
	}
	*side = a;
	*move = (int)(b - '0');
}

/*********************************************************************************/
/*
This function plays one game of Connect Four.  The starting player (either 1 or 2) is provided
as input.  This function returns the player who won the game.
*/
int PlayOneGame(int startingPlayer, int size, int gameType)
{
	int board[MAX_SIZE][MAX_SIZE];
	char displayBoardString[(MAX_SIZE+5)*(MAX_SIZE+5)];
	int player, gameOver, move, lastRow, lastCol;
	char side;

	player = startingPlayer;
	gameOver = 0;

	// Initialise the board, and display it if a human is involved in this game
	InitialiseBoard(board, size);
	if (gameType != 3) {
		GetDisplayBoardString(board, size, displayBoardString);
		printf("%s", displayBoardString);
	}

	// Play one move at a time, displaying the board if necessary, until the game is over
	while (!gameOver) {
		if (gameType == 1) {
			GetMoveHuman(&side, &move, player);
		} else if (gameType == 2) {
			if (player == 1) {
				GetMoveHuman(&side, &move, player);
			} else {
				GetMoveBot1(board, size, player, &side, &move);
			}
		} else {
			if (player == 1) {
				GetMoveBot1(board, size, player, &side, &move);
			} else {
				GetMoveBot2(board, size, player, &side, &move);
			}
		}
		AddMoveToBoard(board, size, side, move, player, &lastRow, &lastCol);
		gameOver = CheckGameOver(board, size, player, lastRow, lastCol);
		if (gameType != 3) {
			GetDisplayBoardString(board, size, displayBoardString);
			printf("%s", displayBoardString);
		}
		if (!gameOver) {
			player = 3 - player;
		}
	}
	PrintBoard(board, size);
	return player;
}

/*********************************************************************************/
/*
This function plays Connect Four.  The user can choose the size of the board, who the
players will be (human or bot) and how many games will be played (if the bots are competing).
*/
void PlayConnectFour(void)
{
	int size, gameType, numberOfGames, result;
	int i, wins1, wins2, player;

	// Initialise the seed for the random number generator
	srand((unsigned int)time(NULL));

	// Prompt the user for the board size
	printf("\n\n==================");
	printf("\nEnter board size: ");
	scanf("%d", &size);

	// Get play options:
	printf("Options:\n");
	printf(" [1] = Human vs. Human\n");
	printf(" [2] = Human vs. Bot1\n");
	printf(" [3] = Bot1 vs. Bot2\n");
	printf("Choose game type: ");
	scanf("%d", &gameType);
	numberOfGames = 1;
	result = 0;
	// If two bots are playing a tournament, let the user choose how many games
	if (gameType == 3) {
		printf("Number of games: ");
		scanf("%d", &numberOfGames);
	}

	wins1 = 0;
	wins2 = 0;

	// Player 1 will always start the first game
	// If a tournament is played (between two bots), the starting player alternates
	player = 1;

	clock_t begin = clock();

	/* here, do your time-consuming job */
	for (i = 0; i < numberOfGames; i++) {
		result = PlayOneGame(player, size, gameType);
		if (result == 1) {
			wins1++;
		} else {
			wins2++;
		}
		// Switch the starting player for the next game
		player = 3 - player;
	}
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time to complete %d games = %.1f seconds\n", numberOfGames, time_spent);

	// If a single game was played, show the result of the game, otherwise report the result of the tournament:
	if (numberOfGames == 1) {
		printf("\nGame over! Congratulations! Winner is Player %d\n\n", result);
	} else {
		printf("\nTournament over! Games played = %d\nPlayer 1 wins = %d / Player 2 wins = %d\n\n", numberOfGames, wins1, wins2);
	}
}
