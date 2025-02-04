/*
    Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.
    Caesar’s algorithm (i.e., cipher) encrypts messages by “rotating” each letter by 'k' positions. 

    Write a program that enables you to encrypt messages using Caesar’s cipher. 
    
    At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime. 
    We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
typedef enum { false, true } bool;
bool only_digits(const char *str);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    // Step 1: Validate Command-line Argument
    // The program should accept exactly one argument, which is the key (a positive integer).
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        // Return an error code
        return 1;
    }

    // Step 2: Check if the key contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");

        // Return an error code
        return 1;
    }

    // Step 3: Convert the key to an integer  // atoi converts string to int
    int key = atoi(argv[1]);

    // Step 4: Get the plaintext from the user
    // Assuming input size limit to 1000 characters
    char plaintext[1000];
    printf("plaintext:  ");

    // Read user input
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character if exists
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n')
    {
        plaintext[len - 1] = '\0';
    }

    // Step 5: Encrypt the plaintext using the Caesar cipher
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    // Successful execution
    return 0;
}

// Function to check if a string contains only digits (0-9)
bool only_digits(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        // Check if the character is not a digit
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by 'key' positions
char rotate(char c, int key)
{
    // Only modify alphabetical characters
    if (isalpha(c))
    {
        // Determine base ASCII value (A=65, a=97)
        char base = isupper(c) ? 'A' : 'a';
        // Shift character within the alphabet, using modulo to wrap around
        return (c - base + key) % 26 + base;
    }

    // Non-alphabetical characters remain unchanged
    return c;
}