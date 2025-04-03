/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:22:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 11:22:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int (*f)(char*))
{
	int	count;

	count = 0;
	while (*tab != 0)
	{
		if (f(*tab) == 1)
			count++;
		tab++;
	}
	return (count);
}