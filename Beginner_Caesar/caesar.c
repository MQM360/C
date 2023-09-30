#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check 1x command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit, greater than 1 - FUNCT?
    string s = argv[1];
    if (only_digits(s) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int` - atoi(argv[1])?
    int key = atoi(argv[1]);

    // Get plain text
    string text = get_string("Plaintext: ");

    // Encipher: Call rotate() on text[i]
    int len = strlen(text);
    char *cipherText = malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        cipherText[i] = rotate(text[i], key);
    }
    cipherText[len] = '\0';

    // Print Ciphertext
    printf("Ciphertext: %s\n", cipherText);

    free(cipherText);
}

bool only_digits(string s)
{
    // Check strlen(argv[1])
    // Make sure digits are 0-9?
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Keep case, Keep punctuation, Rotate the character if it's a letter
char rotate(char c, int n)
{
    // text[i] - To access every character
    // 'A' = 65     'Z' = 90 AND 'a' = 97     'z' = 122

    char rotated;

    if (isupper(c))
    {
        rotated = c - 'A'; // Index value
        c = ((rotated + n) % 26) + 'A';
    }
    else if (islower(c))
    {
        rotated = c - 'a';
        c = ((rotated + n) % 26) + 'a';
    }
    else if (!isalpha(c))
    {
        return c;
    }

    return c;
}
