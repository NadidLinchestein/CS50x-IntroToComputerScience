/*
    According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. 
    What does it mean, though, for a book to be at a particular reading level?

    Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. 
    But an algorithm could likely figure that out too!

    Implement a program that calculates the approximate grade level needed to comprehend some text. 
    Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. 
    If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. 
    If the grade level is less than 1, your program should output “Before Grade 1”.

    So what sorts of traits are characteristic of higher reading levels? 
    Well, longer words probably correlate with higher reading levels. 
    Likewise, longer sentences probably correlate with higher reading levels, too.

    A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. 
    One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. 
    
    The formula is:
    
    index = 0.0588 * L - 0.296 * S - 15.8

    L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    L is the average number of letters per 100 words in the text: that is, the number of letters divided by the number of words, all multiplied by 100.
    S is the average number of sentences per 100 words in the text: that is, the number of sentences divided by the number of words, all multiplied by 100.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function prototypes
int count_letters(const char* text);    // Counts the number of letters in the text
int count_words(const char* text);      // Counts the number of words in the text
int count_sentences(const char* text);  // Counts the number of sentences in the text

int main(void)
{
    // Declare a buffer to store the user input text
    char text[1000];

    // Prompt the user for text input
    printf("Text: ");
    fgets(text, sizeof(text), stdin); // Read input, including spaces, up to 999 characters

    // Remove the newline character if it exists
    text[strcspn(text, "\n")] = '\0';

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate the average number of letters per 100 words (L)
    float L = (letters / (float) words) * 100;

    // Calculate the average number of sentences per 100 words (S)
    float S = (sentences / (float) words) * 100;

    // Apply the Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level based on the index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index)); // Round to the nearest integer
    }

    return 0;
}

// Function to count the number of letters in the text
int count_letters(const char* text)
{
    int count = 0; // Initialize letter count to 0

    // Iterate over each character in the string
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the character is an alphabetic letter
        if (isalpha(text[i]))
        {
            count++; // Increment the letter count
        }
    }

    return count; // Return the total number of letters
}

// Function to count the number of words in the text
int count_words(const char* text)
{
    int count = 0;     // Initialize word count to 0
    int in_word = 0;   // Flag to track if we are inside a word

    // Iterate over each character in the string
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the character is a space or punctuation (end of a word)
        if (isspace(text[i]) || text[i] == '\0')
        {
            if (in_word) // If we were inside a word, count it
            {
                count++;
                in_word = 0; // Reset the flag
            }
        }
        else
        {
            in_word = 1; // Mark that we are inside a word
        }
    }

    // Count the last word if the text doesn't end with a space
    if (in_word)
    {
        count++;
    }

    return count; // Return the total number of words
}

// Function to count the number of sentences in the text
int count_sentences(const char* text)
{
    int count = 0; // Initialize sentence count to 0

    // Iterate over each character in the string
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Check if the character is a sentence-ending punctuation
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++; // Increment the sentence count
        }
    }

    return count; // Return the total number of sentences
}