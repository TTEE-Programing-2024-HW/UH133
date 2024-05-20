//write Booking System choose a and b  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for seat arrangement
#define ROWS 9
#define COLS 9
#define MAX_SEATS 4
void display_screen() {
printf("888888888888888888888888888888888888888888888888888888888888888888888888888\n");
printf("888888888888888888888888888888888888   888888888888888888888888888888888888\n");
printf("88888888888    888888888888888888888   888888888888888888888888888888888888\n");
printf("88888888888    888888888888888888888    88888888888888888888888888888888888\n");
printf("88888888888    888888888888                     8888888   888            88\n");
printf("88888888888    888888888888                     8888888   88888888888    88\n");
printf("88888888888    888888888888   888888888888888   888888    8888888888    888\n");
printf("88888888888    888888888888   888888888888888   888           88888    8888\n");
printf("88                      888                     888888   88   888     88888\n");
printf("88                      88888888888    888888888888888   8    8888   888888\n");
printf("88888888888    8888888888888888888    88888   8888888    8   88888   888888\n");
printf("88888888888    88888888888888888      88888    888888   88   88888   888888\n");
printf("8888888888     88888888888888          88      888888   88                8\n");
printf("8888888888      8888888888       88         88888888    8                 8\n");
printf("888888888        8888888888    88           88888888        888888   888888\n");
printf("888888888    8   88888888888888     8       8888888888      888888   888888\n");
printf("88888888    88    88888888888     88         8888888888    8888888   888888\n");
printf("8888888    8888    8888888       8       8    888888888     888888   888888\n");
printf("888888    888888    8888888    88    8   88    8888888       88888   888888\n");
printf("88888     8888888    8888888888    888   88     88888    8    8888   888888\n");
printf("888     8888888888     88888      8888   888     888    888    888   888888\n");
printf("8      888888888888     88      88       88888  888    88888888      888888\n");
printf("88   888888888888888   8888   88888     888888888888  888888888     8888888\n");
printf("88888888888888888888888888888888888  88888888888888888888888888888888888888\n");
printf("888888888888888888888888888888888888888888888888888888888888888888888888888\n");
}
// Function to display the seating chart
void displaySeats(char seats[ROWS][COLS]) {
    printf("\n");
    // Loop through each row
    for (int i = 0; i < ROWS; ++i) {
        // Loop through each column in the current row
        for (int j = 0; j < COLS; ++j) {
            // Print the current seat status
            printf("%c ", seats[i][j]);
        }
        // Move to the next line after printing all seats in the current row
        printf("\n");
    }
}
// Function to randomly reserve seats
void reserveRandomSeats(char seats[ROWS][COLS], int numSeats) {
    int reserved = 0;
    // Keep reserving seats until the required number of seats have been reserved
    while (reserved < numSeats) {
        // Generate a random row and column number
        int row = rand() % ROWS;
        int col = rand() % COLS;
        // If the seat at the generated position is available, reserve it
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            ++reserved;
        }
    }
}

// Function to arrange seats for the user
void arrangeSeats(char seats[ROWS][COLS], int numSeats) {
    // Reserve consecutive seats in the same row
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j <= COLS - numSeats; ++j) {
            int consecutive = 1;
            // Check if the next 'numSeats' seats are available
            for (int k = 0; k < numSeats; ++k) {
                if (seats[i][j + k] != '-') {
                    consecutive = 0;
                    break;
                }
            }
            // If 'numSeats' consecutive seats are available, reserve them
            if (consecutive) {
                for (int k = 0; k < numSeats; ++k) {
                    seats[i][j + k] = '@';
                }
                return;
            }
        }
    }
// If consecutive seats not available, arrange in adjacent rows
    for (int i = 0; i < ROWS - 1; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // If seats in two consecutive rows at the same column are available, reserve them
            if (seats[i][j] == '-' && seats[i + 1][j] == '-') {
                seats[i][j] = '@';
                seats[i + 1][j] = '@';
                return;
            }
        }
    }
}
// Function to choose seats by the user
void chooseSeats(char seats[ROWS][COLS]) {
    int numSeats;
    printf("Enter the number of seats (1-4): ");
    scanf("%d", &numSeats);
    // Check if the entered number of seats is valid
    if (numSeats < 1 || numSeats > MAX_SEATS) {
        printf("Invalid number of seats. Please choose 1 to 4 seats.\n");
        return;
    }
    printf("Enter seat choices (e.g., 1-2, 2-9):\n");
    for (int i = 0; i < numSeats; ++i) {
        int row, col;
        // Read the row and column number for the seat choice
        scanf("%d-%d", &row, &col);
        // Check if the chosen seat is valid and available
        if (row < 1 || row > ROWS || col < 1 || col > COLS || seats[row - 1][col - 1] != '-') {
            printf("Invalid seat choice. Please re-enter.\n");
            return;
        }
        // Reserve the chosen seat
        seats[row - 1][col - 1] = '@';
    }
}
int main() {
    char seats[ROWS][COLS];
    // Initialize all seats as available
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            seats[i][j] = '-';
        }
    }
    srand(time(NULL));
    // Reserve 10 random seats initially
    reserveRandomSeats(seats, 10);

    char choice;
    int attempts = 0;
    int password = 2024;
    do {
        printf("Enter the password: ");
        int input;
        scanf("%d", &input);
        // Check if the entered password is correct
        if (input == password) {
            printf("Welcome!\n");
            break;
        } else {
            ++attempts;
            // Exit the program after 3 incorrect password attempts
            if (attempts >= 3) {
                printf("Warning: Three consecutive incorrect attempts. Exiting program.\n");
                return 0;
            }
            printf("Incorrect password. Try again.\n");
        }
    }
while (1);

    do {
        printf("\n----------[Booking System]----------\n");
        printf("| a. Available seats               |\n");
        printf("| b. Arrange for you               |\n");
        printf("| c. Choose by yourself            |\n");
        printf("| d. Exit                          |\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        // Perform the action based on the user's choice
        switch (choice) {
            case 'a':
                // Display the seating chart
                displaySeats(seats);
                getchar(); // To capture the Enter key
                printf("Press any key to return to the main menu.\n");
                getchar();
                system("cls"); // Clear the screen
                break;
            case 'b':
                printf("How many seats do you need (1-4)? ");
                int numSeats;
                scanf("%d", &numSeats);
                // Check if the entered number of seats is valid
                if (numSeats >= 1 && numSeats <= MAX_SEATS) {
                    // Arrange seats for the user
                    arrangeSeats(seats, numSeats);
                    // Display the seating chart
                    displaySeats(seats);
                    printf("Are you satisfied with these seats? (y/n): ");
                    char satisfied;
                    scanf(" %c", &satisfied);
                    // If the user is satisfied with the arranged seats, confirm the reservation
                    if (satisfied == 'y') {
                        for (int i = 0; i < ROWS; ++i) {
                            for (int j = 0; j < COLS; ++j) {
                                if (seats[i][j] == '@') {
                                    seats[i][j] = '*'; // Confirm the reservation
                                }
                            }
                        }
                    }
                    system("cls"); // Clear the screen
                } else {
                    printf("Invalid number of seats. Please choose between 1 to 4.\n");
                }
                break;
