/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:52:02 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/13 10:52:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	str = (char *) malloc (i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
		str[i] = src[i];
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str *s_str;

	s_str = malloc ((ac + 1) * sizeof(t_stock_str));
	i = -1;
	while (++i < ac)
	{
		s_str[i].str = ft_strdup(av[i]); // IF NULL?
		s_str[i].copy = s_str[i].str ; // CHECK
		s_str[i].size = ft_strlen(s_str[i].str);
	}
	s_str[i].str = NULL;
	s_str[i].copy = NULL;
	s_str[i].size = 0;
	return (s_str);
}

#include <stdio.h>
int main()
{
	char *str[] = {"ABC", "DEF", "GHI"};
	t_stock_str *s_str;

	s_str = ft_strs_to_tab(3, str);
	for (int i = 0; i < 3; i++)
	{
		printf("%s, ", s_str[i].str);
		printf("%s, ", s_str[i].copy);
		printf("%d\n", s_str[i].size);
	}
}