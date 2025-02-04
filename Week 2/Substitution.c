/*
    In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. 
    To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. 
    To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

    A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. 
    This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), 
    B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

    A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

    In a file called substitution.c in a folder called substitution, create a program that enables you to encrypt messages using a substitution cipher. 
    At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.
*/

#include <stdio.h>
#include <cs50.h> // to get plain text
#include <string.h> // for strlen()
#include <ctype.h> // for string operation upper, lower

void Do_substitute(); // for further substitute
void alpha_arr_val(char pos, string key);
// to get the alphabet array value of each plain text element (ex:plaintext = h|alphabet array = 8 {a=0, b=1 .....z=26})

int main(int argc, string argv[])
{
    if (argc == 2) // number of commands in terminal
    {
        if (strlen(argv[1]) == 26)
        {
            for (int i = 0; i < strlen(argv[1]) ; i++) // checking each element of string
            {

                if (! isalpha(argv[1][i])) // if contain non-alphabet
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                for (int j = i + 1 ; j < strlen(argv[1]) ; j++) // checking to the next element of arg[i]
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i])) // checking repeated element
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            Do_substitute(argv[1]);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

void Do_substitute(string key)
{
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(p); i++)
    {
        if (isalpha(p[i])) // checking p[i] is alphabet
        {
            char x = p[i];
            if (islower(p[i]))
            {
                alpha_arr_val(tolower(x), key); // passing p[i] in lower-case
            }
            else
            {
                alpha_arr_val(toupper(x), key); // passing p[i] in UPPER-CASE
            }
        }
        else
        {
            printf("%c", p[i]); // print the element as it is (such as space | , | special characters | ? | etc...)
        }
    }

    printf("\n");

}

void alpha_arr_val(char pos, string key) // passing p[i] and upper/lower(alpha array)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // alphabet array

    for (int i = 0; i < strlen(alpha); i++) // accessing each element in alpha array
    {
        if (islower(pos)) // p[i] is lower
        {
            if (pos == tolower(alpha[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else // for UPPERCASE // p[i] is upper
        {
            if (pos == toupper(alpha[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}