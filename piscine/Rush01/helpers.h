#ifndef HELPERS_H
#define HELPERS_H

// Function declarations
int lValue(char *digits, int n);
int rValue(char *digits, int n);
int factorial(int n);
int lineValid(int lval, int rval, char *line);
int isUnique(char matrix[4][4], int n);
int isValid(char matrix[4][4], char constraints[4][4]);
char** getAllPermutations(int N, int *returnSize);

// Function definitions
int factorial(int n)
{
    if (n <= 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

int lineValid(int lval, int rval, char *line)
{
    return (lval == lValue(line, 4) && rval == rValue(line, 4));
}

int isUnique(char matrix[4][4], int n)
{
    int i, j, k = 0;
    while (k < n)
    {
        i = 0;
        while (i < n)
        {
            j = 0;
            while (j < n)
            {
                if (matrix[k][i] == matrix[k][j] && i != j)
                    return 0;
                j++;
            }
            i++;
        }
        k++;
    }
    return 1;
}

int isValid(char matrix[4][4], char constraints[4][4])
{
    int i, k;
    char horz[4], vert[4];

    k = 0;
    while (k < 4)
    {
        i = 0;
        while (i < 4)
        {
            horz[i] = matrix[k][i];
            vert[i] = matrix[i][k];
            i++;
        }

        if (!lineValid(constraints[0][k], constraints[1][k], vert))
            return 0;
        if (!lineValid(constraints[2][k], constraints[3][k], horz))
            return 0;
        k++;
    }
    return 1;
}

int lValue(char *digits, int n)
{
    int i = n - 1, j = 1;
    while (i > 0)
    {
        if (digits[i - 1] > digits[i])
            j++;
        else
            return (j);
        i--;
    }
    return (j);
}

int rValue(char *digits, int n)
{
    int i = 0, j = 1;
    while (i < n - 1)
    {
        if (digits[i] < digits[i + 1])
            j++;
        else
            return (j);
        i++;
    }
    return (j);
}

char** getAllPermutations(int N, int *returnSize)
{
    if (N < 1 || N > 9) {
        *returnSize = 0;
        return NULL;
    }

    int total = 1;
    for (int i = 1; i <= N; i++) {
        total *= i;
    }

    char **result = malloc(total * sizeof(char*));
    for (int i = 0; i < total; i++) {
        result[i] = malloc(N * sizeof(char));
    }

    char arr[9];
    for (int i = 0; i < N; i++) {
        arr[i] = (char)(i + 1);
    }

    for (int i = 0; i < N; i++) {
        result[0][i] = arr[i];
    }

    int count = 1;
    while (1) {
        int k = -1;
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                k = i;
            }
        }
        if (k == -1) break;

        int l = -1;
        for (int i = 0; i < N; i++) {
            if (arr[k] < arr[i]) {
                l = i;
            }
        }

        char temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;

        int start = k + 1;
        int end = N - 1;
        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        for (int i = 0; i < N; i++) {
            result[count][i] = arr[i];
        }
        count++;
    }

    *returnSize = count;
    return result;
}
#endif