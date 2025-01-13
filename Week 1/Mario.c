/*
    Toward the end of World 1-1 in Nintendo’s Super Mario Bros, Mario must ascend right-aligned pyramid of bricks.
    In a file called mario.c in a folder called mario-less, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

           #
          ##
         ###
        ####
       #####
      ######
     #######
    ########
    
    Re-prompt the user, again and again as needed, if their input is not greater than 0 or not an int altogether.
    But prompt the user for an int for the pyramid’s actual height, so that the program can also output shorter pyramids like the below:

      #
     ##
    ###
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
        printf("Enter pyramid height (positive integer): ");
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

// Function to print a single row with a specified number of spaces and bricks
void print_row(int spaces, int bricks)
{
    // Print leading spaces for alignment
    for (int i = 0; i < spaces; i++) 
    {
        printf(" ");
    }

    // Print the bricks for the current row
    for (int i = 0; i < bricks; i++) 
    {
        printf("#");
    }

    // Move to the next line after printing the row
    printf("\n");
}