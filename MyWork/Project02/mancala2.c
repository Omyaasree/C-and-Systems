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

int steal_or_bonus_move(int board[]) {
    // First, computer tries to STEAL from player A
    for (int i = 7; i <= 12; i++) {
        int seeds = board[i];
        if (seeds == 0) continue;

        int finalIndex = (i + seeds) % 14;
        if (finalIndex >= 7 && finalIndex <= 12 && board[12 - finalIndex] > 0 && board[finalIndex] == 0) {
            return i - 6;
        }
    }

    // Then, computer tries to get its own BONUS move
    for (int i = 7; i <= 12; i++) {
        int seeds = board[i];
        if (seeds == 0) continue;

        if ((i + seeds) % 14 == 13) {  // Lands in B's bin
            return i - 6;
        }
    }

    return -1; // no steal or bonus move
}


int fill_user_empty_pocket(int board[]) {
    int bestMove = -1;
    int minPonGiven = 1000; // large number

    for (int i = 7; i <= 12; i++) {
        int seeds = board[i];
        if (seeds == 0) {
            continue;
        }

        int stones = seeds;
        int idx = i;
        int givenToUser = 0;
        int fillEmptyUserPit = 0;
        int stealSetup = 0;

        while (stones > 0) {
            idx = (idx + 1) % 14;

            if (idx == 6) {
                continue; // skip A's bin
            }

            board[idx]++;
            stones--;

            if (idx >= 0 && idx <= 5 && board[idx] == 1 && board[i] == seeds) {
                fillEmptyUserPit = 1;
            }

            if (idx >= 0 && idx <= 5) {
                givenToUser++;
            }

            if (idx >= 7 && idx <= 12 && board[idx] == 1 && board[12 - idx] > 0) {
                stealSetup = 1;
            }
        }

        // revert
        stones = seeds;
        idx = i;
        while (stones > 0) {
            idx = (idx + 1) % 14;
            if (idx == 6) continue;
            board[idx]--;
            stones--;
        }

        if (fillEmptyUserPit) {
            if (stealSetup) {
                return i - 6; // prefer immediate steal setup
            } else if (givenToUser < minPonGiven) {
                minPonGiven = givenToUser;
                bestMove = i;
            }
        }
    }

    if (bestMove != -1) {
        return bestMove - 6;
    }

    return -1; // no good move found
}

int defense_or_biggest_move(int board[]) {
    // Block user's steal
    for (int i = 0; i <= 5; i++) {
        int seeds = board[i];
        if (seeds == 0) continue;

        int finalIndex = (i + seeds) % 14;
        if (finalIndex >= 0 && finalIndex <= 5 && board[finalIndex] == 0 && board[12 - finalIndex] > 0) {
            int oppositeB = 12 - finalIndex;
            if (board[oppositeB] != 0) {
                return oppositeB - 6;
            }
        }
    }

    // Block user's bonus move
    for (int i = 0; i <= 5; i++) {
        int seeds = board[i];
        if (seeds == 0) continue;

        if ((i + seeds) == 6) {
            for (int j = 7; j <= 12; j++) {
                if (board[j] != 0) {
                    return j - 6;
                }
            }
        }
    }

    // Else play biggest pit
    int max = 0;
    int best = 7;
    for (int i = 7; i <= 12; i++) {
        if (board[i] > max) {
            max = board[i];
            best = i;
        }
    }

    return best - 6;
}

int computer_best_move(int board[]) {
    int move;

    move = steal_or_bonus_move(board);
    if (move != -1) return move;

    move = fill_user_empty_pocket(board);
    if (move != -1) return move;

    move = defense_or_biggest_move(board);
    return move;
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
        return move(board, new_index, 1);
    }

    if (player == 2 && index == 13) {
        print_board(board);
        printf("Computer (B) gets a BONUS move!\n");

        int new_index = computer_best_move(board); // CHANGED: get computer's best move automatically
        printf("Computer chose index: %d\n", new_index);

        print_board(board);
        return move(board, new_index + 7, 2); // proceed as before
    }

    return index;
}

int get_valid_input(int board[], char garbage[], char player, int player_id) {
    int index = 0;
    int valid;

    do {
        printf("Player %c, enter your index: ", player);
        valid = scanf("%d", &index);

        if (valid != 1) {
            scanf("%s", garbage); // clear bad input
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            continue; // go back and ask again
        }

        if (!isValid(board, index, player_id)) {
            printf("Invalid move! Please choose a non-empty valid pit.\n");
        }
    } while (!isValid(board, index, player_id));

    return index;
}

int main() {
    
    int board[14] = {5, 5, 5, 5, 5, 5, 0, 5, 5, 5, 5, 5, 5, 0}; // initial board array

    print_board(board);
    char garbage[1000]; // to store the bad inputs

    int currentPlayer = 1; // CHANGED: dynamic player control instead of fixed for loop

    while (1) {
        int last_index; // CHANGED: track where move() finishes

        if (currentPlayer == 1) { // CHANGED: Player A (user)
            int index = get_valid_input(board, garbage, 'A', 1);
            last_index = move(board, index, 1);
            print_board(board);
        } else { // CHANGED: Player B (computer)
            printf("Computer (B) is thinking...\n");
            int bestMove = computer_best_move(board);
            printf("Computer chose index: %d\n", bestMove);
            last_index = move(board, bestMove + 7, 2);
            print_board(board);
        }

        int winner = end_game(board, currentPlayer);
        if (winner == 1 || winner == 2) {
            end_game_fo_real(board, winner);
            print_board(board);

            char player_win;
            if (board[6] > board[13]) {
                player_win = 'A';
            } else {
                player_win = 'B';
            }

            printf("Game Over! Player %c wins.\n", player_win);
            return 0;
        }

        // CHANGED: check if last move ended in player's bin (bonus move)
        if (currentPlayer == 1 && last_index == 6) {
            printf("Player A gets a BONUS move!\n");
            continue; // stay on same player
        } else if (currentPlayer == 2 && last_index == 13) {
            printf("Player B gets a BONUS move!\n");
            continue; // stay on same player
        }


        // CHANGED: otherwise, switch players
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    return 0;
}
    