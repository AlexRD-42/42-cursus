/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:58:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 10:18:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_printstr(int *a)
{
	char	letter;
	int		i;

	i = 0;
	while (i < 10)
	{
		letter = a[i] + '0';
		write(1, &letter, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid(int col[10], int k)
{
	int	i;

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

void	ft_permute(int col[10], int start, int end, int *counter)
{
	int	i;

	if (start == end)
	{
		if (is_valid(col, 0))
		{
			ft_printstr(col);
			*counter += 1;
		}
		return ;
	}
	i = start;
	while (i <= end)
	{
		ft_swap(&col[start], &col[i]);
		ft_permute(col, start + 1, end, counter);
		ft_swap(&col[start], &col[i]);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	col[10];
	int	counter;

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
	int	x;
	x = ft_ten_queens_puzzle();
	printf("===========\nThere were %d solutions\n", x);
}