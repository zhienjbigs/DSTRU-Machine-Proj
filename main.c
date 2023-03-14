#include <stdio.h>
#include "pegboard.h"

// will add comments latur or enxt update

int main() {
    int peg, location;

    while (1) {
        printf("Enter peg (1-9): ");
        scanf("%d", &peg);

        printf("Enter location (1-9): ");
        scanf("%d", &location);

        int row = (location - 1) / BOARD_SIZE;
        int col = (location - 1) % BOARD_SIZE;

        if (is_valid_location(row, col, peg)) {
             printf("Position is valid.");
            board[row][col] = peg + '0';
            print_board();
        } else {
            printf("Position is occupied\nOR\nInvalid Input\n");
            print_board();
        }
    }

    return 0;
}
