/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putstr_non_printable.c						  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adeimlin <adeimlin@student.42porto.com>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/27 13:19:53 by adeimlin		  #+#	#+#			 */
/*   Updated: 2025/03/05 20:06:14 by adeimlin		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	slash[2];
	char	hex[17];
	int		i;

	*hex = "0123456789abcdef";
	slash[0] = 92;
	slash[1] = 0;
	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] >= 32 && str[i] < 127))
			write(1, &str[i], 1);
		else
		{
			slash[1] = hex[str[i] % 16];
			write(1, &slash[0], 2);
		}
		i++;
	}
}

// #include <stdio.h>
// int main(void)
// {
//	 char a[] = "Coucou\ntu vas bien ?";
//	 ft_putstr_non_printable(a);
//	 printf("\n");
// }