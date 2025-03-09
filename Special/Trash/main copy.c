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

// Total 41 values
// 29 values one ~ hundred, 12 values thousand ~ undecillion
// index lookup: twenty = 20, hundred = 28


// REMEMBER THAT NUMBERS COULD BE 1234 = ONE-THOUSAND-TWO-HUNDRED-THIRTY-FOUR
// TO DO: 920831742653564475386297019018017016 : nine-hundred-twenty-...
// 1 110 220 330 440 550 660 770 880 990
// 1 001 001 010 111 212 313 414 515 616 717 818 919 (1-19, hundred-undecllion)
// 1102113124
// Write strdup function, is alpha function

// In one hundred, digits from 0 - 9 get inserted before the hundred denominator.
// This changes in a thousand that includes one ~ hundred thousand:
// 123 = one hundred and twenty three
// 987654 = nine hundred eighty seven thousand / six hundred and fifty four
// 987654321 = nine hundred eighty seven million / six hundred and fifty four thousand / three hundred and twenty one

// Counting to 999 correctly will solve this problem
// A function to parse the dictionary and search for the needed number

// REMEMBER THAT NUMBERS COULD BE 1234 = ONE-THOUSAND-TWO-HUNDRED-THIRTY-FOUR
// TO DO: 920831742653564475386297019018017016 : nine-hundred-twenty-...
// 1 110 220 330 440 550 660 770 880 990
// 1 001 001 010 111 212 313 414 515 616 717 818 919 (1-19, hundred-undecllion)

void	ft_printstr(char *str, int print_flag)
{
	char	c;

	while (*str != 0)
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
	if (print_flag == 1)
		write(1, "-", 1);
}

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


void	num2str(char d[4], char **unidict, char **decdict, char **magdict)
{
	char	*str;
	int		pflag;

	pflag = d[3] == 0;
	if (d[0] != 0)
	{
		ft_printstr(unidict[d[0]], 1);
		ft_printstr(magdict[0], 1);
		if (d[1] >= 2)
		{
			ft_printstr(decdict[d[1] - 2], 1);
			if (d[2] != 0)
				ft_printstr(unidict[d[2]], 1);
		}
		else
			if (!(d[2] == 0 && d[1] == 0))
				ft_printstr(unidict[d[1] * 10 + d[2]], 1);
	}
	else
	{
		if (d[1] >= 2)
		{
			ft_printstr(decdict[d[1] - 2], 1);
			if (d[2] != 0)
				ft_printstr(unidict[d[2]], 1);
		}
		else
				ft_printstr(unidict[d[1] * 10 + d[2]], 1);		
	}
	if (d[3] > 0)
		ft_printstr(magdict[d[3]], 1);
}

void	test(char *num)
{
	char *str1[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	char *str2[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *str3[] = {"hundred", "thousand", "million", "billion", "trillion"};

	char *dict[] = {
		"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
		"seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", 
		"sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million", 
		"billion", "trillion", "quadrillion", "quintillion", "sextillion", 
		"septillion", "octillion", "nonillion", "decillion", "undecillion"
	};
	char d[4];
	int n, mag, i, index;

	n = ft_strlen(num, 0);
	mag = (n / 3) - 1;

	i = 0;
	while (mag >= 0)
	{
		d[0] = num[i] - '0';
		d[1] = num[i + 1] - '0';
		d[2] = num[i + 2] - '0';
		d[3] = mag;
		i += 3;
		mag--;
		num2str(d, str1, str2, str3);
	}
	write(1, "\n", 1);
}

int main()
{
	int		totalsize;

	test("000");
	test("001");
	test("009");
	test("010");
	test("011");
	test("019");
	test("020");
	test("021");
	test("029");
	test("030");
	test("031");
	test("089");
	test("090");
	test("091");
	test("099");
	test("100");
	test("101");

	// totalsize = 0;
	// str = read_file(&totalsize, "numbers.dict");
}