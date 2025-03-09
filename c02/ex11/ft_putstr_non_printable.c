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
	unsigned char	*hex;
	unsigned char	c;

	hex = "0123456789abcdef";
	while (*str != 0)
	{
		c = (unsigned char) *str;
		if ((c >= 32 && c <= 126))
			write(1, &c, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[c / 16], 1);
			write(1, &hex[c % 16], 1);
		}
		str++;
	}
}

#include <stdio.h>
int main(void)
{
	 char a[] = "Coucou\ntu vas bien ?";
	 a[0] = -100;
	 a[1] = 18;
	 ft_putstr_non_printable(a);
	 printf("\n");
}