#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    float words = 0;
    int n = 0;
    float letters = 0;
    float sentences = 0;
    char text[1000];

    printf("Enter the content [1000 words only]: \n");
    scanf("%s",text);
    while (text[n] != '\0')
    {
        if (text[n] == '!' || text[n] == '?' || text[n] == '.')
        {
            sentences++;
            n++;
        }
        else if ((text[n]) == ' ')
        {
            words++;
            n++;
        }
        else if ((ispunct(text[n])))
        {
            n++;
        }
        else
        {
            letters++;
            n++;
        }
    }
    words++;
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}
