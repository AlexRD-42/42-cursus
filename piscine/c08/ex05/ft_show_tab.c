/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:24:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/13 11:24:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

typedef struct s_stock_str
{
int size;
char *str;
char *copy;
} t_stock_str;

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

void	ft_show_tab(struct s_stock_str *par)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (par[i].size != 0)
	{
		j = 0;
		while (par[i].str[j] != 0)
			write(1, &par[i].str[j++], 1);
		write(1, "\n", 1);
		c = par[i].size + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j] != 0)
			write(1, &par[i].copy[j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

int main()
{
	char *str[] = {"ABC", "DEF", "GHI"};
	t_stock_str *s_str;

	s_str = ft_strs_to_tab(3, str);
	ft_show_tab(s_str);
}