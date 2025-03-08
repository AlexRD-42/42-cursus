/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:24:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 00:24:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// In one hundred, digits from 0 - 9 get inserted before the hundred denominator.
// This changes in a thousand that includes one ~ hundred thousand:
// 123 = one hundred and twenty three
// 987654 = nine hundred eighty seven thousand / six hundred and fifty four
// 987654321 = nine hundred eighty seven million / six hundred and fifty four thousand / three hundred and twenty one

// Counting to 999 correctly will solve this problem
// A function to parse the dictionary and search for the needed number


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void ft_swap(void *a, void *b, int size) 
{
    char	*x;
    char	*y;
	char	temp;
	int		i;

	x = (char *)a;
	y = (char *)b;
	i = 0;
	if (size <= 0)
		return ;
	while (i < size)
	{
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
		i++;
	}
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	ft_power(int base, int exp)
{
	int	num;

	if (exp == 0)
		return (1);
	else if (exp < 0)
		return (0);
	num = base;
	while (exp > 1)
	{
		num = num * base;
		exp--;
	}
	return (num);
}

int	ft_strlen(char *str, int filter)
{
	int	i;

	i = 0;
	if (filter == 0)
		while (str[i] != 0)
		{
			i++;
		}
	else
	{
		while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
		{
			i++;
		}
	}
	return (i);
}

int	ft_numlen(int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

int	ft_char2int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (0);
}

char	*read_file(int *totalsize, char *filename)
{
	char	*buffer;
	char	*str;
	int		fd;
    int		bytesRead;

	*totalsize = 0;
	buffer = (char *) malloc(128);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && buffer != NULL)
		while ((bytesRead = read(fd, buffer, 128)) > 0)
			*totalsize += bytesRead;
	close(fd);
	free(buffer);
	str = (char *) malloc(*totalsize + 1);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && str != NULL)
	{
		bytesRead = read(fd, str, *totalsize);
		str[*totalsize] = 0;
	}
	close(fd);
	return (str);
}

// This function needs to return proper names for 0-999
// We need dictionary: 0-19, 20, 30, 40, 50, 60, 70, 80, 90, 100
// Then every 3 digits, from right to left, we append the kilodict index
// Example: 1003 = 3 and 1 thousand (right to left reading)
// 987654 = str[0] = six hundred fifty four; str[1] = nine hundred and eighty seven + append thousand
char	*num2str(char digits[3], char **unidict)
{
	int		num;
	char	*str;

	num = atoi(digits);
	if (num <= 19)
		str = unidict[num];
	// if (digits[2] != 0)
}

int main()
{
	int		totalsize;
	char	*str;

	totalsize = 0;
	str = read_file(&totalsize, "numbers.dict");
}