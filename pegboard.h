#include <stdio.h>
#define BOARD_SIZE 3


// System Variables
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'X', 'X', 'X'},
    {'X', 'X', 'X'},
    {'X', 'X', 'X'}
};
// Aesthetic purposes, doesn't affect the actual game but improves gameplay
	int turn = 1;
    char RED[]  = "\033[1;31m"; // Unoccupied
	char GREEN[] = "\033[1;32m"; // Player A
	char YELLOW[] = "\033[1;33m"; // Player B
	char RESET []= "\033[0m";  // Resets the text color to the default


int AddAll() {
    // function to add all the values of the board
    // assuming that the board is a 2D array of integers
    int sum = 0, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum += board[i][j];
        }
    }
    return sum;
}
void ShowGuidelines() {
    printf("Welcome to the Peg game!\n"
    
           "Before we start, here are a few guidelines for the game.\n"
           "1. Pegs can repeat. A player can repeat a peg despite it being placed on the board\n"
           "2. Both players are color-coded\n"
           "\t\033[1;31m - Unoccupied \033[1;31m\n"
           "\t\033[1;32m - Player A \033[1;32m\n"
           "\t\033[1;33m - Player B \033[1;33m\n"
           "\033[0m 3. For simplicity purposes, the game does not require you to input coordinates.\n"
           " Instead, you will be prompted to input the number of the location you want to go.\n"
		   "Please enter to continue...",
           'R', 'R', 'G', 'G', 'Y', 'Y');
    getchar();
    printf("Let's start!\n");
}

void print_board(int turn) {
	/*
    It prints the board
    
    :param board: This is the board that we're going to print
    */
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 2) {
                if (board[i][j] == 'X') {
                    printf("%c", board[i][j]);
                } else if (board[i][j] == 'O') {
                    printf("%c", board[i][j]);
                } else {
                    if (turn % 2 == 0) {
                        printf("\033[1;32m%c\033[0m", board[i][j]);
                    } else {
                        printf("\033[1;33m%c\033[0m", board[i][j]);
                    }
                }
            } else {
                if (board[i][j] == 'X') {
                    printf("%c | ", board[i][j]);
                } else if (board[i][j] == 'O') {
                    printf("%c | ", board[i][j]);
                } else {
                    if (turn % 2 == 0) {
                        printf("\033[1;32m%c\033[0m | ", board[i][j]);
                    } else {
                        printf("\033[1;33m%c\033[0m | ", board[i][j]);
                    }
                }
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}
int is_valid_location(int row, int col,int peg) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    if (board[row][col] != 'X') {
        return 0;
    }
    if(peg < 1 || peg > 9){
        return 0;
    }
    return 1;
}
