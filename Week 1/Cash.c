/*
    Problem to Solve
    Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). 
    You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy. 
    When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!). 
    
    In a file called cash.c in a folder called cash, implement a program in C that prints the minimum coins needed to make the given amount of change, in cents, as in the below:
    Change owed: 25
    1
    
    But prompt the user for an int greater than 0, so that the program works for any amount of change:
    Change owed: 70
    4
    
    Re-prompt the user, again and again as needed, if their input is not greater than or equal to 0 (or if their input isn’t an int at all!).
    quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
*/

#include <stdio.h>

int main() 
{
    int change;     // Amount of change owed in cents
    int coins = 0;  // Counter for the total number of coins used

    // Prompt the user for a valid amount of change. Repeat until a non-negative integer is provided.
    do 
    {
        printf("Change owed: ");

        // Validate that the input is an integer
        if (scanf("%i", &change) != 1) 
        {
            while (getchar() != '\n');  // Clear invalid input from the buffer
            change = -1;                // Set change to an invalid value to re-prompt
        }
    } 
    while (change < 0);

    // Calculate the minimum number of coins required
    while (change > 0)
    {
        if (change >= 25) // Use quarters (25¢)
        {
            change -= 25; // Deduct the value of one quarter
            coins++;      // Increment the coin counter
        }
        else if (change >= 10) // Use dimes (10¢)
        {
            change -= 10; // Deduct the value of one dime
            coins++;      // Increment the coin counter
        }
        else if (change >= 5) // Use nickels (5¢)
        {
            change -= 5;  // Deduct the value of one nickel
            coins++;      // Increment the coin counter
        }
        else // Use pennies (1¢)
        {
            change -= 1;  // Deduct the value of one penny
            coins++;      // Increment the coin counter
        }
    }

    // Print the total number of coins needed
    printf("%i\n", coins);
    
    return 0;
}