/*
    Implement a program in C that prompts the user for their name and then says hello to that user.
    For instance, if the user’s name is Adele, your program should print hello, Adele\n!
*/

#include <stdio.h>

int main(void)
{
    // Declare a character array to hold the name
    char name[50];

    printf("What's your name? \n");

    // Use %49s to prevent buffer overflow (leaving space for null terminator)
    scanf("%49s", name);
    printf("hello, %s\n", name);

    return 0;
}