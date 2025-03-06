/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/06 15:54:48 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// 1 for upper, 2 for lower, 3 for other
	// TODO: remember taht numbers dont capitalize
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
		if (!((*str >= 'A' && *str <= 'Z') || 
			(*str >= 'a' && *str <= 'z') || 
			(*str >= '0' && *str <= '9')))
			cap = 1;
		else
			cap = 0;
		str++;
	}
	return (start);
}

// #include <unistd.h>
// int main(void)
// {
//     char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//     int flag;
//     ft_strcapitalize(a);
//     write(1, &a, sizeof(a));
//     printf("\n");
// }