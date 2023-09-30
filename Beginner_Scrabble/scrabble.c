#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Scrabble Points
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get user 1 input
    string word1 = get_string("Player 1: ");
    // Get user 2 input
    string word2 = get_string("Player 2: ");

    // Loop that runs the length of WORD - FUNC?
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Compare INPUT1 vs INPUT2
    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int compute_score(string word)
{
    // Size of the word
    int score = 0;

    // Loop that runs the length of the word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // Check letter case
        if (isupper(word[i]))
        {
            // Check relative position
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
