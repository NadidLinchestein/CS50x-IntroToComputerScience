/*
    American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9).
    
    All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55; and all Visa numbers start with 4. 
    
    But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. 
    That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database.

    Luhn’s Algorithm
    So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
    
    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.
    
    For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:
    4003600000000014
    
    Okay, let’s multiply each of the underlined digits by 2:
    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
    
    That gives us:
    2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
    
    Now let’s add those products’ digits (i.e., not the products themselves) together:
    2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
    
    Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):
    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
    
    Yup, the last digit in that sum (20) is a 0, so David’s card is legit!
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number;

    // Initialize variables for the Luhn's algorithm
    long sumEvery = 0;
    long sumFirst = 0;

    // Get credit card number from the user
    number = get_long("Number: ");

    // Store the original value of 'number'
    long originalNumber = number;

    // Calculate the total number of digits in the credit card number
    int count = (number == 0) ? 1 : (log10(number) + 1);

    // Every second number from the input
    while (number > 0)
    {
        long lastNumber = number / 10;
        long everyOther = lastNumber % 10;
        number = number / 100;

        // Multiply every second number
        long multiply = everyOther * 2;

        // Add the digits of the product to the sum
        while (multiply > 0)
        {
            sumEvery = sumEvery + (multiply % 10);
            multiply = multiply / 10;
        }
    }

    // Restore the original value of 'number'
    number = originalNumber;

    // Every first number excluding every second number
    while (number > 0)
    {
        long everyFirst = number % 10;
        number = number / 100;

        // Add the digits to the sum
        sumFirst = sumFirst + everyFirst;
    }

    // Calculate the final sum
    long finalSum = sumEvery + sumFirst;

    // Check if the credit card number is valid according to Luhn's algorithm
    if (finalSum % 10 == 0)
    {
        // Check for card length & starting digits
        int test = originalNumber / pow(10, count - 2);
        string card;

        if ((count == 13 || count == 16) && test / 10 == 4)
        {
            card = "VISA";
        }
        else if ((count == 13 || count == 16) && test >= 51 && test <= 55)
        {
            card = "MASTERCARD";
        }
        else if (count == 15 && (test == 34 || test == 37))
        {
            card = "AMEX";
        }
        else
        {
            card = "INVALID";
        }

        printf("%s\n", card);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}