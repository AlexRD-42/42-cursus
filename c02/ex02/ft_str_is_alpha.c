/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:39:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 20:57:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	flag;

	flag = 1;
	while (*str != 0 && flag == 1)
	{
		if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
			flag = 0;
		str++;
	}
	return (flag);
}

// #include <stdio.h>
// int main(void)
// {
//     char a[] = "";
//     int flag; 
//     flag = ft_str_is_alpha(a);
//     printf("%d\n", flag);
// }