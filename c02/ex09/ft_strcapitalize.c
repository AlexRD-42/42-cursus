/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 14:06:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	int	flag;

	flag = (c >= 'A') && (c <= 'Z');
	flag = flag || (c >= 'a') && (c <= 'z');
	flag = flag || (c >= '0') && (c <= '9');
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int		cap;
	char	*start;

	start = str;
	cap = 1;
	while (*str != 0)
	{
		if (cap == 1 && (*str >= 97 && *str <= 122))
		{
			*str = *str - 32;
			cap = 0;
		}
		else if (cap == 0 && (*str >= 65 && *str <= 90))
			*str = *str + 32;
		if (is_alphanumeric(*str))
			cap = 0;
		else
			cap = 1;
		str++;
	}
	return (start);
}

#include <unistd.h>
int main(void)
{
    char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    ft_strcapitalize(a);
    write(1, &a, sizeof(a));
}