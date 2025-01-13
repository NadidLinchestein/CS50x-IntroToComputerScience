/*
    Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks.
    Implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

    $ ./mario (compile program)
    Height: 4
       #  #
      ##  ##
     ###  ###
    ####  ####

    And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.
    Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.
    Here’s how the program might work if the user inputs 8 when prompted:

    $ ./mario
    Height: 8
           #  #
          ##  ##
         ###  ###
        ####  ####
       #####  #####
      ######  ######
     #######  #######
    ########  ########
*/

#include <stdio.h>

// Function to print a single row of the pyramid
void print_row(int spaces, int bricks);

int main(void)
{
    // Declare variables for height and spaces
    int height;

    // Prompt the user for the pyramid's height until a valid input is entered
    do 
    {
        printf("Height: ");
        scanf("%i", &height);
    } 
    while (height < 1); // Ensure height is at least 1

    // Loop through each level of the pyramid
    for (int row = 1; row <= height; row++) 
    {
        // Calculate the number of spaces for alignment
        int spaces = height - row; 
        
        // Print the current row
        print_row(spaces, row); 
    }

    return 0; 
}

// Function to print a single row of the pyramid
void print_row(int spaces, int bricks)
{
    // Print leading spaces for right-aligned pyramid
    for (int i = 0; i < spaces; i++) 
    {
        // Add a space for each iteration
        printf(" ");
    }

    // Print the bricks for the right-aligned pyramid
    for (int i = 0; i < bricks; i++) 
    {
        // Add a brick for each iteration
        printf("#");
    }

    // Print the gap between the two pyramids. Two spaces for separation.
    printf("  ");

    // Print the bricks for the left-aligned pyramid
    for (int i = 0; i < bricks; i++) 
    {
        // Add a brick for each iteration
        printf("#");
    }

    // Move to the next line to prepare for the next row. Newline after completing the current row.
    printf("\n");
}