#include <stdio.h>
#include "pegboard.h"
#include <stdbool.h>



int main() {

    int peg, location, turn = 0;
	ShowGuidelines();
	bool playerturn = true;
  	bool over = false;
    
    while (!over) {
    	if(playerturn){
    		printf("\033[1;32m Player A's turn \033[0m\n");
		}else{
			printf("\033[1;33m Player B's turn \033[0m\n");
		}
        printf("Enter peg (1-9): ");
        scanf("%d", &peg);
        

        printf("Enter location (1-9): ");
        scanf("%d", &location);

        int row = (location - 1) / BOARD_SIZE;
        int col = (location - 1) % BOARD_SIZE;

        if (is_valid_location(row, col, peg)) {
             printf("Position is valid.");
            board[row][col] = peg + '0';
            print_board(turn);
            turn++;
        } else {
            printf("Position is occupied\nOR\nInvalid Input\n");
            print_board(turn);
        }
    	playerturn = !playerturn;
    }

    return 0;
}
