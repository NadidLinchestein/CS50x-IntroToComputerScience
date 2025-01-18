/*
    In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.

    Letter  Value
    ----------------
    A       1
    B       3
    C       3
    D       2
    E       1
    F       4
    G       2
    H       4
    I       1
    J       8
    K       5
    L       1
    M       3
    N       1
    O       1
    P       3
    Q       10
    R       1
    S       1
    T       1
    U       1
    V       4
    W       4
    X       8
    Y       4
    Z       10

    For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. 
    Summing these, we get that “CODE” is worth 7 points.

    Implement a program in C that determines the winner of a short Scrabble-like game. 
    Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. 
    Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to calculate the Scrabble score of a word
int calculate_score(char *word) {
    // Array to hold the score values of each letter
    // Index 0 corresponds to 'A', index 1 to 'B', ..., index 25 to 'Z'
    int letter_values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    
    int score = 0;
    
    // Loop through each character of the word
    for (int i = 0; i < strlen(word); i++) {
        // Convert the character to uppercase
        char c = toupper(word[i]);
        
        // Check if the character is a letter (A-Z)
        if (c >= 'A' && c <= 'Z') {
            // Calculate the score for this letter by finding its index. 'A' is at index 0, 'B' is at index 1, ..., 'Z' is at index 25
            int index = c - 'A';

            // Add the letter's score to the total
            score += letter_values[index];
        }
    }
    
    // Return the total score of the word
    return score;
}

int main() {
    char player1_word[100], player2_word[100];
    
    // Prompt for Player 1's word
    printf("Player 1: ");
    fgets(player1_word, sizeof(player1_word), stdin);

    // Remove the newline character if present
    player1_word[strcspn(player1_word, "\n")] = '\0';
    
    // Prompt for Player 2's word
    printf("Player 2: ");
    fgets(player2_word, sizeof(player2_word), stdin);

    // Remove the newline character if present
    player2_word[strcspn(player2_word, "\n")] = '\0'; 
    
    // Calculate the scores for both players
    int player1_score = calculate_score(player1_word);
    int player2_score = calculate_score(player2_word);
    
    // Determine the winner based on the scores
    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}