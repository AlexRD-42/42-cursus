/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:58:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/06 14:36:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_helper(char *a, char *b, int flag) 
{
	char	i;
	char	letter;

	if (flag == 0)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			letter = a[i] + '0';
			write(1, &letter, 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

char is_valid(char col[10], char k)
{
    char 	i;

    while (k < 10)
    {
        i = 0;
        while (i < k)
        {
            if (k != i && (col[k] == col[i] || (col[k] - col[i] == k - i)))
                return (0);
			if (k != i && (col[k] - col[i] == i - k))
                return (0);
            i++;
        }
        k++;
    }
    return (1);
}

void	ft_permute(char col[10], char start, char end, int *counter)
{
	char	i;

    if (start == end) 
	{
        if (is_valid(col, 0))
		{
			ft_helper(col, 0, 1);
			*counter += 1;
		}
        return;
    }
	i = start;
	while (i <= end)
	{
        ft_helper(&col[start], &col[i], 0);
        ft_permute(col, start + 1, end, counter);
        ft_helper(&col[start], &col[i], 0);
		i++;
    }
}

int	ft_ten_queens_puzzle(void)
{
	char	i;
	char	col[10];
	int		counter;

	i = 0;
	counter = 0;
	while (i < 10)
	{
		col[i] = i;
		i++;
	}
	ft_permute(col, 0, 9, &counter);
	return (counter);
}

#include <stdio.h>
int main()
{
	int x;
	x = ft_ten_queens_puzzle();
	printf("\n%d\n", x);
}