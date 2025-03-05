/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:58:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 15:58:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// For a queen to reach in one move, there are three checks (x, y)
// Assume Queen 0 is at (3, 2), then no other queen can be at: 
// Row 3 and (3, 2) diagonal movement respecting 1 >= num <= 10
// (3, :), (:, 2), (2, 1) ~ (10, 9)

// Function receives WIP solution and validates it checking until index
char ft_abs(char num)
{
    if (num >= 0)
        return (num);
    else
        return (-num);
}

int is_valid(char col[10])
{
    char i;
    char k;

    k = 0;
    while (k < 10)
    {
        i = 0;
        while (i < 10)
        {
            if (k != i)
                if (col[k] == col[i])
                    return (0);
                else if (ft_abs(col[k] - col[i]) == ft_abs(k - i))
                    return (0);
            i++;
        }
        k++;
    }
    i = 0;
    while (i < 10)
    {
        col[i] += '0';
        write(1, &col[i], 1);
        i++;
    }
    return (1);
}


// int solve_puzzle(int n)
// {
//     if (n == -1)
//         return (-1);

// }

// int ft_ten_queens_puzzle(void)
// {
//     if ()
// }

int main()
{
    char sol1[10] = {4,6,0,9,5,8,2,7,3,1};
    char sol2[10] = {0,2,5,7,9,4,8,1,3,6};
    char sol3[10] = {0,2,5,8,6,9,3,1,4,7};
    char sol4[10] = {4,6,0,5,7,1,3,8,2,9};
    char sol5[10] = {9,7,4,2,0,5,1,8,6,3};

    is_valid(sol1);
    // printf("%d, %d, %d, %d, %d\n", is_valid(sol1), is_valid(sol2), is_valid(sol3), is_valid(sol4), is_valid(sol5));
}