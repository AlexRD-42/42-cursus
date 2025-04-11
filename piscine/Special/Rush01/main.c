#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int solve(char constraints[4][4])
{
    int size;
    char **perms = getAllPermutations(4, &size);

}

int main(void)
{
    int n = 4, size;
    int i, j = 0, k = 0;
    char *input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    char constraints[4][4];
    
    i = 0;
    k = 0;
    
    while (*input != 0)
    {
        if (*input >= 48 && *input <= 57)
        {
            if (i == n)
            {
                i = 0;
                k++;
            }
            constraints[k][i] = *input;
            i++;
        }
        input++;
    }

    printf("%s", constraints);
}