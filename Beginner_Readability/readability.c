#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Collect Text Input
    string text = get_string("text: ");

    // Count Letters, Words, & Sentences in Text - FUNCT?
    // ---> Letters     =   text[i]? Check ctype.h
    // ---> Words       =   text[i] == ' '
    // ---> Sentence    =   text[i] == '.'  '!'  '?'

    int letterCount = count_letters(text);
    int wordCount = count_words(text);
    int sentenceCount = count_sentences(text);

    // Compute the Coleman-Liau index - FUNCT?
    float L = ((float) letterCount / wordCount) * 100;
    float S = ((float) sentenceCount / wordCount) * 100;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print Grade level
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
        printf("Grade %i\n", (int) index);
    }

    // printf("Your Letter count is: %i \n", letterCount);
    // printf("Your Word count is: %i \n", wordCount);
    // printf("Your Sentence count is: %i \n", sentenceCount);
    // printf("The Index count is: %f \n", index);
}

int count_letters(string text)
{
    // isalpha?
    // Return the number of LETTERS in text

    int letterCount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

int count_words(string text)
{
    // isblank? isspace?
    // Return the number of WORDS in text

    int wordCount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((i == 0 || isspace(text[i - 1])) && !isspace(text[i]))
        {
            wordCount++;
        }
    }
    return wordCount;
}

int count_sentences(string text)
{
    // ispunct?
    // Return the number of SENTENCES in text

    int sentenceCount = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}
