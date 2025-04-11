/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:33:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/13 14:33:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void print_hex(unsigned char byte);
void print_address(unsigned long addr);
void print_hex_line(unsigned char *buffer, int size, int offset);

void print_hex(unsigned char byte)
{
	char *hex = "0123456789abcdef";
	write(1, &hex[(byte >> 4) & 0xF], 1);
	write(1, &hex[byte & 0xF], 1);
}

void print_address(unsigned long addr)
{
	char *hex = "0123456789abcdef";
	int i;
	char address[8];

	for (i = 7; i >= 0; i--)
	{
		address[i] = hex[addr & 0xF];
		addr >>= 4;
	}
	write(1, address, 8);
}

void print_hex_line(unsigned char *buffer, int size, int offset)
{
	int i;

	// Print address
	print_address(offset);
	write(1, "  ", 2);

	// Print hex values
	for (i = 0; i < 16; i++)
	{
		if (i < size)
		{
			print_hex(buffer[i]);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	// Print ASCII values
	write(1, "|", 1);
	for (i = 0; i < size; i++)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			write(1, &buffer[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "|\n", 2);
}