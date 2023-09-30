#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Check for Height
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // iterate through pyramid (rows and col.)
    for (int i = 0; i < height; i++) // ROW or X
    {
        // Left Side: Spaces & Hash
        for (int j = i + 1; j < height; j++) // COL or Y1
        {
            printf(" ");
        }
        for (int k = height - i; k < height + 1; k++) // COL or Y2
        {
            printf("#");
        }

        // Right Side: Spaces & Hash
        for (int l = height - 2; l < height; l++) // COL or Y1
        {
            printf(" ");
        }
        for (int m = height - i; m < height + 1; m++) // COL or Y2
        {
            printf("#");
        }
        printf("\n");
    }
}
