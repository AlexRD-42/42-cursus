/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:17:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 14:38:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	print_address(unsigned long long addr)
{
	int		i;
	char	hex[16];
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		hex[15 - i] = base[addr % 16];
		addr /= 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		ft_putchar(hex[i]);
		i++;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	print_hex_part(unsigned char *ptr, unsigned int n, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (n + i < size)
			ft_puthex(ptr[n + i]);
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	print_char_part(unsigned char *ptr, unsigned int n, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && n + i < size)
	{
		if (ptr[n + i] >= 32 && ptr[n + i] < 127)
			ft_putchar(ptr[n + i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)(ptr + i));
		print_hex_part(ptr, i, size);
		print_char_part(ptr, i, size);
		i += 16;
	}
	return (addr);
}

int main()
{
	
}