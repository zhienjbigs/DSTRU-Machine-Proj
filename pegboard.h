#include <stdio.h>
#define BOARD_SIZE 3
char board[BOARD_SIZE][BOARD_SIZE] = {
    {'X', 'X', 'X'},
    {'X', 'X', 'X'},
    {'X', 'X', 'X'}
};
void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == 2) {
                if (board[i][j] == 'X') {
                    printf("%c", board[i][j]);
                } else if (board[i][j] == 'O') {
                    printf("%c", board[i][j]);
                } else {
                    if ((i + j) % 2 == 0) {
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
                    if ((i + j) % 2 == 0) {
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