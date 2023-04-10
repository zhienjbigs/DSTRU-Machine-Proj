#include <stdio.h>
#include <stdbool.h>
#include "pegboard.h"
#define BOARD_SIZE 3



//char board[BOARD_SIZE][BOARD_SIZE] = {
//    {'X', 'X', 'X'},
//    {'X', 'X', 'X'},
//    {'X', 'X', 'X'}
//};



//int AddAll() {
//    int sum = 0, i, j;
//    for (i = 0; i < 3; i++) {
//        for (j = 0; j < 3; j++) {
//            sum += board[i][j];
//        }
//    }
//    return sum;
//}
//void print_board(int turn) {
//	/*
//    It prints the board
//    
//    :param board: This is the board that we're going to print
//    */
//    printf("\n");
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            if (j == 2) {
//                if (board[i][j] == 'X') {
//                    printf("%c", board[i][j]);
//                } else if (board[i][j] == 'O') {
//                    printf("%c", board[i][j]);
//                } else {
//                    if (turn % 2 == 0) {
//                        printf("\033[1;32m%c\033[0m", board[i][j]);
//                    } else {
//                        printf("\033[1;33m%c\033[0m", board[i][j]);
//                    }
//                }
//            } else {
//                if (board[i][j] == 'X') {
//                    printf("%c | ", board[i][j]);
//                } else if (board[i][j] == 'O') {
//                    printf("%c | ", board[i][j]);
//                } else {
//                    if (turn % 2 == 0) {
//                        printf("\033[1;32m%c\033[0m | ", board[i][j]);
//                    } else {
//                        printf("\033[1;33m%c\033[0m | ", board[i][j]);
//                    }
//                }
//            }
//        }
//        printf("\n");
//        if (i < 2) {
//            printf("-----------\n");
//        }
//    }
//    printf("\n");
//}

//int is_valid_location(int row, int col, int peg) {
//    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
//        return 0;
//    }
//    if (board[row][col] != 'X') {
//        return 0;
//    }
//    if (peg < 1 || peg > 9) {
//        return 0;
//    }
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            if (board[i][j] == (peg + '0')) {
//            	
//                return 0;
//            }
//        }
//    }
//    goverctr++;
//    return 1;
//}


int main() {
int peg, location, turn = 0;
bool playerturn = true;
bool over = false;

int goverctr = 0;
ShowGuidelines();
while (!over) {
    if(playerturn){
        printf("Player A's turn\n");
    } else {
        printf("Player B's turn\n");
    }

    printf("Enter peg (1-9): ");
    scanf("%d", &peg);

    printf("Enter location (1-9): ");
    scanf("%d", &location);

    int row = (location - 1) / BOARD_SIZE;
    int col = (location - 1) % BOARD_SIZE;

    if (is_valid_location(goverctr,row, col, peg)) {
        printf("Position is valid.");
        board[row][col] = peg + '0';
        print_board(turn);
        
    } else {
        printf("Position is occupied\nOR\nInvalid Input\n");
        print_board(turn);
    }
	turn++;
    game_over();
    if(gover == 1){
        if(playerturn){
            printf("Player 1 win!!!\n");
            over = true;
        } else {
            printf("Player 2 win!!!\n");
            over = true;
        }
    }
    if(goverctr == 9){
        printf("Its a tie!!!\n");
        over = true;
    }

    playerturn = !playerturn;
}

return 0;
}
