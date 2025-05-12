#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define MAX_RESERVED 10

char seats[ROWS][COLS]; // Store seat status

// Initialize seats as '-' and randomly reserve 10 seats as '*'
void initializeSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    srand((unsigned int)time(NULL));
    int reserved = 0;
    while (reserved < MAX_RESERVED) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            reserved++;
        }
    }
}

// Confirm the suggested seats by changing '@' to '*'
void confirmSuggestedSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
}

// Clear all suggested seats '@'
void clearSuggestions() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = '-';
}

// Display the current seat map
void displaySeats() {
    printf("   ");
    for (int i = 1; i <= COLS; i++) {
        printf("%d", i);
    }
    printf("\n");

    for (int i = ROWS - 1; i >= 0; i--) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int password = 2025;
    int input;
    int attempts = 0;

    // Welcome screen
    printf("========================================\n");
    printf("=                  E3A59               =\n");
    printf("=                                      =\n");
    printf("=                  Yi-Lin Tsai         =\n");
    printf("=                                      =\n");
    printf("=                                      =\n");
    printf("=              /\\  /\\                =\n");
    printf("=             ( o  o )    /\\         =\n");
    printf("=              ||   || \\ // \\        =\n");
    printf("=              ||   || //              =\n");
    printf("=             ()----()/                =\n");
    printf("=     It's hard to tell, but it's a cat=\n");
    printf("========================================\n");
    printf("\n\n");

    // Password verification loop
    while (attempts < 3) {
        printf("Enter 4-digit password: ");

        if (scanf("%d", &input) != 1) {
            printf("Invalid input format. Please enter 4 digits.\n");
            while (getchar() != '\n');
            continue;
        }

        if (input == password) {
            printf("Password correct! Access granted.\n");
            break;
        } else {
            attempts++;
            if (attempts < 3) {
                printf("Incorrect password. Try again. Attempts: %d\n", attempts);
            } else {
                printf("Warning: Password incorrect three times. Exiting system.\n");
                return 0;
            }
        }
        while (getchar() != '\n');
    }

    initializeSeats(); // Initialize the seat map

    char choice;
    while (1) {
        // Menu options
        printf("\n----------[Booking System]----------\n");
        printf("|   a. View available seats        |\n");
        printf("|   b. Let system arrange for you  |\n");
        printf("|   c. Choose seats manually        |\n");
        printf("|   d. Exit                        |\n");
        printf("------------------------------------\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (tolower(choice)) {
            case 'a':
                displaySeats();
                printf("Press Enter to return to menu...\n");
                while (getchar() != '\n');
                getchar();
                break;
            case 'b': {
                int num;
                printf("Enter number of seats to book (1~4): ");
                scanf("%d", &num);

                if (num < 1 || num > 4) {
                    printf("Invalid number. Please enter between 1 and 4.\n");
                    break;
                }

                int found = 0;

                // Try to find seats in a single row
                for (int i = 0; i < ROWS && !found; i++) {
                    for (int j = 0; j <= COLS - num; j++) {
                        int ok = 1;
                        for (int k = 0; k < num; k++) {
                            if (seats[i][j + k] != '-') {
                                ok = 0;
                                break;
                            }
                        }
                        if (ok) {
                            for (int k = 0; k < num; k++) {
                                seats[i][j + k] = '@';
                            }
                            found = 1;
                            break;
                        }
                    }
                }

                // Special case: 4-person 2x2 block if row option fails
                if (num == 4 && !found) {
                    for (int i = 0; i < ROWS - 1 && !found; i++) {
                        for (int j = 0; j < COLS - 1; j++) {
                            if (seats[i][j] == '-' && seats[i][j + 1] == '-' &&
                                seats[i + 1][j] == '-' && seats[i + 1][j + 1] == '-') {
                                seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                                found = 1;
                                break;
                            }
                        }
                    }
                }

                if (!found) {
                    printf("No suitable seats found. Try other options.\n");
                    break;
                }

                displaySeats();
                char confirm;
                printf("Are you satisfied with the arrangement? (y/n): ");
                scanf(" %c", &confirm);

                if (tolower(confirm) == 'y') {
                    confirmSuggestedSeats();
                    printf("Booking confirmed. Press Enter to continue...\n");
                    while (getchar() != '\n');
                    getchar();
                } else {
                    clearSuggestions();
                    printf("Booking canceled. Press Enter to continue...\n");
                    while (getchar() != '\n');
                    getchar();
                }
                break;
            }
            case 'c': {
                char input[10];
                int row, col;

                printf("Enter seats to book in format row-col (e.g., 1-2). Type 'done' to finish.\n");
                while (1) {
                    printf("Enter seat: ");
                    scanf("%s", input);

                    if (strcmp(input, "done") == 0) break;

                    if (strlen(input) != 3 || input[1] != '-' || !isdigit(input[0]) || !isdigit(input[2])) {
                        printf("Invalid format. Use row-col format.\n");
                        continue;
                    }

                    row = input[0] - '0';
                    col = input[2] - '0';

                    if (row < 1 || row > 9 || col < 1 || col > 9) {
                        printf("Out of range. Use 1~9 for row and column.\n");
                        continue;
                    }

                    int i = 9 - row;
                    int j = col - 1;

                    if (seats[i][j] == '*') {
                        printf("Seat already reserved. Choose another.\n");
                    } else if (seats[i][j] == '@') {
                        printf("Seat already selected. Choose another.\n");
                    } else {
                        seats[i][j] = '@';
                        printf("Seat [%d-%d] selected.\n", row, col);
                    }
                }

                printf("\nSelected seats:\n");
                displaySeats();

                printf("If correct, press Enter to confirm...\n");
                while (getchar() != '\n');
                getchar();
                confirmSuggestedSeats();
                break;
            }
            case 'd':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

/*
==============================================
Discussion and Reflection:

In this assignment, I learned how to design a simple seat reservation system using C programming.
I practiced using 2D arrays to represent seat states and how to apply nested loops and conditional
statements to handle seat arrangement logic. I also dealt with string processing and input validation
(e.g., format check for row-col input) using functions like isdigit().

Implementing the auto-arrange and manual selection features helped me understand how to simulate
real-world systems with basic logic. Adding user prompts and validation improved the user experience.
Functions like confirmSuggestedSeats() and clearSuggestions() also helped me write modular code.

Although the logic was a bit tricky at times, I successfully managed to finish all functions with clear
feedback and control flow. Overall, this project improved my coding skills and confidence in C language.
==============================================
*/
