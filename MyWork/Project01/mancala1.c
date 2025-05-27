// Omyaasree Balaji
// Project01
// Mancala.c
// this code has the code for both players playing mancala

#include <stdio.h>

void print_board(int board[]) { // Function to print the current state of the Mancala board
    printf("\n     ");
    for (int i = 12; i >= 7; i--) {
        printf("%3d ", i - 6);
    }
    printf("\n");

    printf("  B: ");
    for (int i = 12; i >= 7; i--) {
        printf("%3d ", board[i]);
    }
    printf("\n");

    printf("%3d                          %3d\n", board[13], board[6]);

    printf("     ");

    for (int i = 0; i <= 5; i++) {
        printf("%3d ", board[i]);
    }
    printf(" :A\n   ");

    printf("  ");

    for (int i = 1; i <= 6; i++) {
        printf("%3d ", i);
    }
    printf("\n\n");
}

int isValid(int board[], int index, int player) { // Function to check if the selected move is valid
    if (player == 1 && index >= 1 && index <= 6 && board[index - 1] != 0) {
        return 1; // for payer A valid move
    } else if (player == 2 && index >= 1 && index <= 6 && board[index + 6] != 0) {
        return 1; // for player B valid move
    }
    return 0; // return 0 if any of the move is invalid
}

void collectToBin(int board[], int index, int player) { // called when there is a steal chance for any of the players
    if (player == 1 && index >= 0 && index <= 5 && board[index] == 1) {
        printf("Going to bin for A: %d captured from %d and %d\n", board[index] + board[12 - index], index, 12 - index);
        board[6] += board[index] + board[12 - index]; // sum of the steal pons for player A
        board[index] = 0;
        board[12 - index] = 0;
    } else if (player == 2 && index >= 7 && index <= 12 && board[index] == 1) {
        printf("Going to bin for B: %d captured from %d and %d\n", board[index] + board[12 - index], index, 12 - index);
        board[13] += board[index] + board[12 - index]; // sum of the steal pons for player A
        board[index] = 0;
        board[12 - index] = 0;
    }
}

int end_game(int board[], int player) { // Function to check if the game has ended
    int n = 0;
    if (player == 1) {
        for (int i = 0; i < 6; i++) {
            if (board[i] != 0) {
                return n;  // The game is not over for player A
            }
        }
        return 1;  // The game is over for player A
    } else {
        for (int i = 7; i < 13; i++) {
            if (board[i] != 0) {
                return 0;  // The game is not over for player B
            }
        }
        return 2;  // The game is over for player B
    }
    return n;  // Default return value
}

void end_game_fo_real(int board[], int winab) { // Function to distribute the remaining stones when the game ends
    if (winab == 1) {
        for (int i = 7; i < 13; i++) {
            board[13] += board[i];
            board[i] = 0; // clear all the houses
        }
    } else if (winab == 2) {
        for (int i = 0; i < 6; i++) {
            board[6] += board[i];
            board[i] = 0; // clear all the houses
        }
    }
}

int move(int board[], int indexA, int player) { // Function to make a move in the game
    int numPons = board[indexA - 1];
    board[indexA - 1] = 0;
    int index = indexA - 1;

    while (numPons > 0) {
        index++;
        if (index == 14) {
            index = 0;
        }
        // Skip the opponent's bin
        if ((player == 1 && index == 13) || (player == 2 && index == 6)) {
            continue;
        }
        board[index]++;
        numPons--;
    }

    collectToBin(board, index, player);

    if (player == 1 && index == 6) {
        print_board(board);
        printf("BONUS MOVE\n");
        int new_index;
        do {
            printf("Player A, enter your index: ");
            scanf("%d", &new_index);
        } while (!isValid(board, new_index, 1));
        print_board(board);
        return move(board, new_index + 1, 1);
    }

    if (player == 2 && index == 13) {
        print_board(board);
        printf("BONUS\n");
        int new_index;
        do {
            printf("Player B, enter your index: ");
            scanf("%d", &new_index);
        } while (!isValid(board, new_index, 2));
        print_board(board);
        return move(board, new_index + 7, 2);
    }
    return index;
}

int get_valid_input(int board[], char garbage[], char player, int player_id) { // Function to get a valid move from the player
    int index = 0, r;

    do {
        printf("Player %c, enter your index: ", player);
        r = scanf("%d", &index);
        if (!r) {
            r = scanf("%s", garbage);
        }
    } while (!isValid(board, index, player_id)); // do while to reduce repeated code

    return index;
}

int main() {
    int board[14] = {5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 0}; // initial board array

    print_board(board);
    char garbage[1000]; // to store the bad inputs

    while (1) { // infinite loop until the game ends.... i could do (while(isValid)) but i dont want to change anything...i am scared
        for (int i = 0; i < 2; i++) {
            char player;
            int player_id;

            if(i ==0){
                player = 'A';
                player_id = 1; // player A s turn
            }else {
                player = 'B';
                player_id = 2; // player Bs turn
            }

            int index = get_valid_input(board, garbage, player, player_id);

            if (player == 'B') {
                index = move(board, index + 7, player_id); // adjust the index for player B because the puckets start from index 6 
            } else {
                index = move(board, index, player_id); // the player A puckets start from index 1 
            }

            print_board(board); // print the state of the board after the move
            int winner = end_game(board, player_id);

            if (winner == 1 || winner == 2) {
                end_game_fo_real(board, winner); // Distribute the remaining stones when the game ends
                print_board(board); // print the final state of the board when all the values in the puckets change to 0

                char player_win;
                if(board[6] > board[13]){
                    player_win = 'A';
                }else{
                    player_win = 'B';
                }

                printf("Game Over! Player %c wins.\n", player_win); // print the winner
                return 0; // end the game if winner is there
            }
        }
    }
    return 0;
}